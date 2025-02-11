#include "Global.h"
#include <limits>

bool g_hackingDroneFix = true;
bool g_repairDroneRecoveryFix = true;
bool g_controllableIonDroneFix = false;
float g_controllableIonDroneFix_Delay = 6.0;
float g_controllableIonDroneFix_DelayInitial = 6.0;
bool g_hackingIonFix = false;

// hacking drone explodes on depower -- makes you unable to get past defense drones by powering + depowering

HOOK_METHOD(HackingSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> HackingSystem::OnLoop -> Begin (Balance.cpp)\n")
    super();

    if (g_hackingDroneFix)
    {
        if (!this->drone.arrived && !this->Powered())
        {
            this->BlowHackingDrone();
        }
    }
}

// Jumping away while a repair drone is active with a repair arm will collect the drone part -- this removes it before the collection

HOOK_METHOD(DroneSystem, Jump, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::Jump -> Begin (Balance.cpp)\n")

    if (g_repairDroneRecoveryFix)
    {
        for (auto drone : drones)
        {
            // type == 5 are SHIP_REPAIR
            if (drone->deployed && drone->type == 5)
            {
                drone->SetDestroyed(true, false);
                drone->deployed = false;
            }
        }
    }
    super();
}

// Attacking a door with the ion boarder would cause it to instantly charge its next ion burst, 
// which is problematic with the added possibility to control boarder drone -- the timer is now internally managed and it will now respect its delay

HOOK_METHOD(IonDrone, constructor, (int iShipId, DroneBlueprint *blueprint) -> void)
{
    LOG_HOOK("HOOK_METHOD -> IonDrone::constructor -> Begin (Balance.cpp)\n")
    super(iShipId, blueprint);
    
    if (g_controllableIonDroneFix && this->CrewMember::iShipId == 0)
    {
        int delay = g_controllableIonDroneFix_Delay*1000;
        auto ex = CMA_EX(crewAnim);
        ex->ionTimer = TimerHelper(true);
        ex->ionTimer.ResetMinMax(delay, delay);
        ex->ionTimer.loop = true;
        ex->ionTimer.Start(-1);
    }
}

HOOK_METHOD(BoarderPodDrone, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> BoarderPodDrone::OnLoop -> Begin (Balance.cpp)\n")
    super();
    
    CrewAnimation_Extend* ex;
    if (g_controllableIonDroneFix && !bDeliveredDrone && boarderDrone && boarderDrone->CrewMember::iShipId == 0 && (ex = CMA_EX(boarderDrone->crewAnim), ex->isIonDrone))
    {   // Initialize timer if the drone hasn't yet reached the ship
        ex->ionTimer.currTime = std::max(0.f, g_controllableIonDroneFix_Delay - g_controllableIonDroneFix_DelayInitial);
    }
}

HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewDrone::OnLoop -> Begin (Balance.cpp)\n")
    super();

    CrewAnimation_Extend* ex;
    if (g_controllableIonDroneFix && this->CrewMember::iShipId == 0 && (ex = CMA_EX(crewAnim), ex->isIonDrone))
    {
        IonDroneAnimation* ionAnim = (IonDroneAnimation*)crewAnim;
        if (!ionAnim->ionAnimation.tracker.running)
        {   // Increment timer while not triggering
            ex->ionTimer.Update();
        }
        if (std::abs(x - goal_x) > 0.01 || std::abs(y - goal_y) > 0.01)
        {   // Reset glow progress if ordered to move
            ionAnim->ionEffect = 0.f;
        }
        if (!Functional())
        {   // Reset timer fully if turned off
            ex->ionTimer.currTime = 0.f;
            ionAnim->ionAnimation.tracker.running = false;
            ionAnim->ionEffect = 0.f;
        }
    }
}

HOOK_METHOD(IonDroneAnimation, UpdateShooting, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> IonDroneAnimation::UpdateShooting -> Begin (Balance.cpp)\n")

    CrewAnimation_Extend* ex;
    if (g_controllableIonDroneFix && (ex = CMA_EX(this), ex->crew->iShipId == 0))
    {
        if (!bDoorTarget && ex->ionTimer.Done())
        {
            ionAnimation.Start(true);
            ionEffect = 0.f;
            G_->GetSoundControl()->PlaySoundMix("ionBoarderCharge", -1.f, false);
        }

        float ionEffectCurrent = ionEffect;
        bool ionAnimRunningCurrent = ionAnimation.tracker.running;

        shootTimer.running = false;
        super();

        // Undo the secondary trigger that happens at the end of the function
        if (status != 7 || bDoorTarget)
        {
            ionEffect = ionEffectCurrent;
            ionAnimation.tracker.running = ionAnimRunningCurrent;
        }

        return;
    }

    super();
}

// Ionising the hacking system before the end of the hack will cause it to have a shorter cooldown disregarding the regular cooldown duration, this will add to the cooldown
HOOK_METHOD(ShipSystem, IonDamage, (int amount) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::IonDamage -> Begin (Balance.cpp)\n")

    if (GetId() == SYS_HACKING && g_hackingIonFix && amount > 0 && amount < 4)
    {
        HackingSystem* hacking = G_->GetShipManager(_shipObj.iShipId)->hackingSystem;
        if (hacking->bHacking) hacking->LockSystem(4 - amount);
    }

    super(amount);
}

/*
HOOK_METHOD(DefenseDrone, PickTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DefenseDrone::PickTarget -> Begin (Balance.cpp)\n")
    if (bDisrupted && powered)
    {
        if (aimingAngle == desiredAimingAngle)
        {
            desiredAimingAngle = rand() % 360;
        }
        //UpdateAimingAngle(currentLocation, )
    }
    else if (powered)
    {
        Pointf diff = Pointf(targetLocation.x - currentLocation.x, targetLocation.y - currentLocation.y);
        float projSpeed = weaponBlueprint->speed;
        float aimAhead = Globals::AimAhead(diff, targetSpeed, projSpeed * G_->GetCFPS()->GetSpeedFactor());

        if (aimAhead > 0.f)
        {
            targetLocation = Pointf(aimAhead * targetSpeed.x + targetLocation.x, aimAhead * targetSpeed.y + targetLocation.y);
        }

        if (targetLocation == currentLocation)
        {
            desiredAimingAngle = aimingAngle;
        }
        else
        {

        }
    }
}*/
