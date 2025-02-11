#include "CustomDrones.h"
#include "CustomCrew.h"
#include "CustomOptions.h"
#include "CustomWeapons.h"
#include "Drones.h"
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <cfloat>

bool g_DefenseDroneFix = false;
float g_DefenseDroneFix_BoxRange[2] = {150.f, 150.f};
float g_DefenseDroneFix_EllipseRange[2] = {50.f, 50.f};

//bool g_dronesCanTeleport = false;

CustomDroneManager CustomDroneManager::_instance = CustomDroneManager();

void CustomDroneManager::ParseDroneNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto droneNode = node->first_node(); droneNode; droneNode = droneNode->next_sibling())
        {
            if (strcmp(droneNode->name(), "drone") == 0)
            {
                CustomDroneDefinition* def = new CustomDroneDefinition();

                def->name = droneNode->first_attribute("name")->value();

                for (auto child = droneNode->first_node(); child; child = child->next_sibling())
                {
                    std::string name = child->name();
                    std::string val = child->value();

                    if (name == "crewBlueprint")
                    {
                        def->crewBlueprint = val;
                    }
                    if (name == "tooltipName")
                    {
                        def->tooltipName = val;
                    }
                    if (name == "ability")
                    {
                        def->hasAbility = true;

                        DroneAbilityDefinition::AIType ai;
                        if (child->first_attribute("ai"))
                        {
                            std::string aiString = child->first_attribute("ai")->value();

                            if (aiString == "systems")
                            {
                                ai = DroneAbilityDefinition::AIType::SYSTEMS;
                            }
                            if (aiString == "systems_power")
                            {
                                ai = DroneAbilityDefinition::AIType::SYSTEMS_POWER;
                            }
                            if (aiString == "heal")
                            {
                                ai = DroneAbilityDefinition::AIType::CREW_HEAL;
                            }
                            if (aiString == "enemies")
                            {
                                ai = DroneAbilityDefinition::AIType::ENEMIES;
                            }
                        }

                        def->ability.ai = ai;
                    }
                }

                droneDefs.push_back(def);
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <drones> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <drones> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <drones> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <drones> in hyperspace.xml\n");
    }
}

HOOK_METHOD(BlueprintManager, ProcessDroneBlueprint, (rapidxml::xml_node<char>* node) -> DroneBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::ProcessDroneBlueprint -> Begin (CustomDrones.cpp)\n")
    DroneBlueprint ret = super(node);

    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (strcmp(child->name(), "target") == 0)
            {
                if (strcmp(child->value(), "ASTEROIDS") == 0)
                {
                    ret.targetType = 2;
                }
                else if (strcmp(child->value(), "SOLID") == 0)
                {
                    ret.targetType = 5;
                }
                else if (strcmp(child->value(), "ALL") == 0)
                {
                    ret.targetType = 6;
                }
            }
        }

        return ret;
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <droneBlueprint>\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <droneBlueprint>\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <droneBlueprint>\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <droneBlueprint>\n");
    }

    return ret;
}

HOOK_STATIC(DroneSystem, StringToDrone, (std::string &name) ->  int)
{
    LOG_HOOK("HOOK_STATIC -> DroneSystem::StringToDrone -> Begin (CustomDrones.cpp)\n")
    int ret = super(name);

    if (ret == -1 && name == "HACKING") ret = 6; // give HackingDrone a specific drone id type so other code can use the drone type to downcast

    return ret;
}

//====================================================

HOOK_METHOD(CrewMemberFactory, CreateBoarderDrone, (int shipId, DroneBlueprint *bp) -> BoarderDrone*)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::CreateBoarderDrone -> Begin (CustomDrones.cpp)\n")
    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinition(bp->name);

    if (customDrone)
    {
        if (customDrone->hasAbility)
        {
            AbilityDrone* drone = new AbilityDrone(customDrone->crewBlueprint, customDrone->tooltipName, shipId, bp, customDrone->ability);

            crewMembers.push_back(drone);

            return (BoarderDrone*)drone;
        }
    }

    return super(shipId, bp);
}

HOOK_METHOD(DroneBlueprint, RenderIcon, (float scale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneBlueprint::RenderIcon -> Begin (CustomDrones.cpp)\n")
    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinition(name);
    if ((type == 2 || type == 3 || type == 4) && customDrone)
    {
        std::string race = customDrone->crewBlueprint;

        CustomCrewManager* customCrew = CustomCrewManager::GetInstance();

        if (customCrew->IsRace(race))
        {
            auto def = customCrew->GetDefinition(race);
            if (!def->animSheet[1].empty())
            {
                race = def->animSheet[1];
            }
        }

        CSurface::GL_PushMatrix();
        Animation walkDown = G_->GetAnimationControl()->GetAnimation(race + "_walk_down");
        auto base = G_->GetResources()->GetImageId("people/" + race + "_base.png");
        auto layer = G_->GetResources()->GetImageId("people/" + race + "_layer1.png");

        CSurface::GL_Translate(std::floor(std::floor((-scale * walkDown.info.frameWidth)) / 2.f) + 1, std::floor(std::floor((-scale * walkDown.info.frameHeight)) / 2.f) + 1);

        walkDown.SetCurrentFrame(0);
        walkDown.SetAnimationId(base);
        walkDown.OnRender(1.f, COLOR_WHITE, false);
        walkDown.SetAnimationId(layer);
        walkDown.OnRender(1.f, GL_Color(128.f / 255.f, 255.f / 255.f, 141.f / 255.f, 1.f), false);

        CSurface::GL_PopMatrix();
        return;
    }

    super(scale);
}

HOOK_METHOD(CrewAnimation, OnInit, (const std::string& name, Pointf position, bool enemy) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnInit -> Begin (CustomDrones.cpp)\n")
    super(name, position, enemy);

    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinitionByRace(race);
    if (customDrone)
    {
        bDrone = true;
    }
}

HOOK_METHOD(CrewDrone, constructor, (const std::string& droneType, const std::string& name, int shipId, const DroneBlueprint* blueprint, CrewAnimation *anim) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewDrone::constructor -> Begin (CustomDrones.cpp)\n")
    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinition(blueprint->name);

    if (customDrone)
    {
        super(customDrone->crewBlueprint, customDrone->tooltipName.empty() ? name : customDrone->tooltipName, shipId, blueprint, nullptr);

        if (!customDrone->tooltipName.empty())
        {
            TextString textName = TextString();

            textName.data = customDrone->tooltipName;
            textName.isLiteral = true;

            SetName(&textName, true);
        }
    }
    else
    {
        super(droneType, name, shipId, blueprint, anim);
    }

    // check if drone is custom race using animSheet
    auto *def = CustomCrewManager::GetInstance()->GetDroneRaceDefinition(this);
    if (def && !def->animSheet[1].empty())
    {
        // update baseLayer and lightLayer (to do - have this functionality for when a drone uses transformRace)
        baseLayer = G_->GetResources()->GetImageId("people/" + def->animSheet[1] + "_base.png");
        lightLayer = G_->GetResources()->GetImageId("people/" + def->animSheet[1] + "_layer1.png");
    }
}

static bool blockControllableAI;

HOOK_METHOD_PRIORITY(ShipManager, CommandCrewMoveRoom, -100, (CrewMember* crew, int room) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::CommandCrewMoveRoom -> Begin (CustomDrones.cpp)\n")
    if (blockControllableAI)
    {
        auto custom = CustomCrewManager::GetInstance();
        if (crew->GetControllable() || (!crew->intruder && custom->IsRace(crew->species) && custom->GetDefinition(crew->species)->droneAI.hasCustomAI)) return false;
    }

    return super(crew, room);
}

HOOK_METHOD(CrewMember, SetTask, (CrewTask task) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SetTask -> Begin (CustomDrones.cpp)\n")
    if (blockControllableAI)
    {
        auto custom = CustomCrewManager::GetInstance();
        if (GetControllable() || (!intruder && custom->IsRace(species) && custom->GetDefinition(species)->droneAI.hasCustomAI)) return;
    }

    super(task);
}

HOOK_METHOD(CrewAI, UpdateDrones, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::UpdateDrones -> Begin (CustomDrones.cpp)\n")
    blockControllableAI = true;
    super();
    blockControllableAI = false;

    bool hasDrone = false;

    for (auto i : crewList)
    {
        if (i->IsDrone() && !i->intruder)
        {
            hasDrone = true;
            break;
        }
    }

    if (!hasDrone) return;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    for (int crewIndex=0; crewIndex<crewList.size(); ++crewIndex)
    {
        CrewMember *crew = crewList[crewIndex];

        if (crew->IsDrone() && !crew->intruder && custom->IsRace(crew->species))
        {
            auto def = custom->GetDefinition(crew->species);
            if (def->droneAI.hasCustomAI && !crew->GetControllable() && !crew->IsDead() && crew->Functional() && crew->crewAnim->status != 3)
            {
                std::vector<CrewTask> taskList(desiredTaskList);
                taskList.insert(taskList.end(), bonusTaskList.begin(), bonusTaskList.end());

                if (taskList.empty())
                {
                    AssignCrewmembers();
                    return;
                }

                if (crew->CanFight())
                {
                    if (def->droneAI.fightAI)
                    {
                        CrewTask closestTask;
                        float closestDist = FLT_MAX;
                        int newTaskId = 4;

                        for (auto task : taskList)
                        {
                            if (task.taskId == 7)
                            {
                                if (!ship->ship.FullRoom(task.room, false))
                                {
                                    float dist = ship->GetRoomCenter(task.room).RelativeDistance(Pointf(crew->x, crew->y));

                                    if (dist < closestDist)
                                    {
                                        closestDist = dist;
                                        closestTask = task;
                                        newTaskId = task.taskId;
                                    }
                                }
                            }
                        }

                        if (newTaskId != 4)
                        {
                            if (!ship->ship.RoomLocked(closestTask.room))
                            {
                                if (ship->CommandCrewMoveRoom(crew, closestTask.room))
                                {
                                    crew->SetTask(closestTask);
                                }
                            }
                        }
                    }
                }
                if (!crew->IsBusy() && crew->CanRepair())
                {
                    if (def->droneAI.repairAI)
                    {
                        crew->ClearTask();

                        for (auto task : taskList)
                        {
                            if (task.taskId <= 3 && task.taskId > 0)
                            {
                                if (PrioritizeTask(task, crewIndex) < PrioritizeTask(crew->task, crewIndex))
                                {
                                    if (!ship->ship.RoomLocked(task.room) && (ship->CommandCrewMoveRoom(crew, task.room) || task.room == crew->currentSlot.roomId))
                                    {
                                        crew->SetTask(task);
                                    }
                                }
                            }
                        }
                    }
                }

                if (!crew->IsBusy() && crew->CanMan())
                {
                    if (def->droneAI.manAI)
                    {
                        for (auto task : taskList)
                        {
                            if (task.taskId == 0 && task.system != SYS_MEDBAY && task.system != SYS_OXYGEN && task.system != SYS_PILOT)
                            {
                                if (PrioritizeTask(task, crewIndex) < PrioritizeTask(crew->task, crewIndex))
                                {
                                    if (!ship->ship.RoomLocked(task.room) && (ship->CommandCrewMoveRoom(crew, task.room) || task.room == crew->currentSlot.roomId))
                                    {
                                        crew->SetTask(task);
                                    }
                                }
                            }
                        }
                    }
                }

                if (!crew->IsBusy() && crew->task.taskId != 0)
                {
                    bool idle = true;

                    if (def->droneAI.batteryAI)
                    {
                        if (def->providesPower || def->bonusPower > 0)
                        {
                            idle = false;

                            int maxPowerDiff = 0;
                            int targetRoom = -1;

                            for (auto i : ship->vSystemList)
                            {
                                int powerDiff = i->powerState.second - i->powerState.first;

                                if (i->iSystemType == 3)
                                {
                                    int maxPower = 0;
                                    for (auto wep : ship->GetWeaponList())
                                    {
                                        maxPower += wep->requiredPower;
                                    }

                                    powerDiff = maxPower - i->powerState.first;
                                }

                                if (powerDiff > maxPowerDiff && powerDiff > 0 && !ShipSystem::IsSubsystem(i->iSystemType) && i->iSystemType != 4 && i->iSystemType != 5)
                                {
                                    maxPowerDiff = powerDiff;
                                    targetRoom = i->roomId;
                                    if (targetRoom != -1 && !ship->ship.RoomLocked(targetRoom) && (ship->CommandCrewMoveRoom(crew, targetRoom) || targetRoom == crew->currentSlot.roomId))
                                    {
                                        CrewTask task = CrewTask();
                                        task.room = targetRoom;
                                        task.taskId = 4;
                                        task.system = -1;

                                        crew->SetTask(task);
                                    }
                                    else
                                    {
                                        targetRoom = -1;
                                    }
                                }
                            }

                            if (targetRoom == -1)
                            {
                                int priorityList[7] = { 3, 0, 13, 1, 11, 10, 15 };

                                for (auto i : priorityList)
                                {
                                    if (i == 3)
                                    {
                                        int maxPower = 0;
                                        for (auto wep : ship->GetWeaponList())
                                        {
                                            maxPower += wep->requiredPower;
                                        }
                                        if (maxPower == 0) continue;
                                    }

                                    targetRoom = ship->GetSystemRoom(i);
                                    if (targetRoom != -1 && !ship->ship.RoomLocked(targetRoom) && (ship->CommandCrewMoveRoom(crew, targetRoom) || targetRoom == crew->currentSlot.roomId))
                                    {
                                        CrewTask task = CrewTask();
                                        task.room = targetRoom;
                                        task.taskId = 4;
                                        task.system = -1;

                                        crew->SetTask(task);

                                        break;
                                    }
                                    else
                                    {
                                        targetRoom = -1;
                                    }
                                }
                            }

                            if (targetRoom == -1)
                            {
                                idle = true;
                            }
                        }
                    }

                    if (idle)
                    {
                        if (def->droneAI.returnToDroneRoom)
                        {
                            int droneRoom = ship->GetSystemRoom(4);
                            if (!ship->ship.RoomLocked(droneRoom))
                            {
                                if (ship->CommandCrewMoveRoom(crew, droneRoom) || droneRoom == crew->currentSlot.roomId)
                                {
                                    CrewTask task = CrewTask();
                                    task.room = droneRoom;
                                    task.taskId = 4;
                                    task.system = -1;

                                    crew->SetTask(task);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

HOOK_METHOD(ShipManager, CreateSpaceDrone, (const DroneBlueprint *bp) -> SpaceDrone*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CreateSpaceDrone -> Begin (CustomDrones.cpp)\n")
    if (bp->type == 4)
    {
        for (auto i: myBlueprint.systemInfo)
        {
            if (i.second.systemId == SYS_DRONES)
            {
                return super(bp);
            }
        }

        BoarderPodDrone *ret = new BoarderPodDrone(iShipId, Globals::GetNextSpaceId(), *bp);
        ret->powerRequired = bp->power;
        spaceDrones.push_back(ret);
        droneTrash.push_back(ret);
        newDroneArrivals.push_back(ret);
        return ret;
    }

    return super(bp);
}

HOOK_METHOD(ShipManager, CreateSpaceDrone, (const DroneBlueprint *bp) -> SpaceDrone*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CreateSpaceDrone -> Begin (CustomDrones.cpp)\n")
    SpaceDrone* ret = super(bp);

    if (ret)
    {
        if (current_target)
        {
            if (ret->Drone::type == 1)
            {
                // combat

                ((CombatDrone*)ret)->SetMovementTarget(&current_target->_targetable);
                ((CombatDrone*)ret)->SetWeaponTarget(&current_target->_targetable);

            }
            else if (ret->Drone::type == 4)
            {
                // boarder

                BoarderPodDrone *drone = ((BoarderPodDrone*)ret);

                drone->SetMovementTarget(&current_target->_targetable);

                if (drone->boarderDrone)
                {
                    drone->boarderDrone->SetCurrentShip(current_target->iShipId);
                    drone->boarderDrone->ship = &current_target->ship;
                    drone->boarderDrone->SetRoom(-1);
                    current_target->vCrewList.push_back(drone->boarderDrone);
                    drone->boarderDrone->EmptySlot();
                }
            }
        }
    }

    return ret;
}


static std::vector<Projectile*> spaceDroneQueuedProjectiles = std::vector<Projectile*>();
HOOK_METHOD(SpaceDrone, GetNextProjectile, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD -> SpaceDrone::GetNextProjectile -> Begin (CustomDrones.cpp)\n")
    Projectile* ret;
    if (weaponBlueprint->type == 4) // flak
    {
        if (spaceDroneQueuedProjectiles.empty())
        {
            ret = super();
            if (ret)
            {
                Pointf lastTargetLocation = ret->target;

                float radius = CustomWeaponManager::instance->GetWeaponDefinition(weaponBlueprint->name)->angularRadius;
                if (radius == -1.f)
                {
                    radius = weaponBlueprint->radius;
                }
                else
                {
                    radius = radius * sqrt(lastTargetLocation.RelativeDistance(ret->position)) * 0.01745329f;
                }

                delete ret;

                for (auto &k : weaponBlueprint->miniProjectiles)
                {
                    float r = sqrt(random32()/2147483648.f) * radius;
                    float theta = random32()%360 * 0.01745329f;
                    Pointf ppos = {static_cast<float>(lastTargetLocation.x + r*cos(theta)), static_cast<float>(lastTargetLocation.y + r*sin(theta))};
                    LaserBlast *projectile = new LaserBlast(currentLocation,currentSpace,currentSpace,ppos);
                    projectile->heading = -1.0;
                    projectile->OnInit();
                    projectile->Initialize(*weaponBlueprint);
                    projectile->ownerId = iShipId;

                    projectile->flight_animation = G_->GetAnimationControl()->GetAnimation(k.image);

                    if (k.fake)
                    {
                        projectile->damage.iDamage = 0;
                        projectile->damage.iShieldPiercing = 0;
                        projectile->damage.fireChance = 0;
                        projectile->damage.breachChance = 0;
                        projectile->damage.stunChance = 0;
                        projectile->damage.iIonDamage = 0;
                        projectile->damage.iSystemDamage = 0;
                        projectile->damage.iPersDamage = 0;
                        projectile->damage.bHullBuster = false;
                        projectile->damage.ownerId = -1;
                        projectile->damage.selfId = -1;
                        projectile->damage.bLockdown = false;
                        projectile->damage.crystalShard = false;
                        projectile->damage.bFriendlyFire = true;
                        projectile->damage.iStun = 0;
                        projectile->death_animation.fScale = 0.25;
                    }
                    else
                    {
                        projectile->bBroadcastTarget = Drone::type == 1 && iShipId == 0;
                    }

                    CustomWeaponManager::ProcessMiniProjectile(projectile, weaponBlueprint);

                    spaceDroneQueuedProjectiles.push_back(projectile);
                }
            }
        }
        if (!spaceDroneQueuedProjectiles.empty())
        {
            ret = spaceDroneQueuedProjectiles.back();
            spaceDroneQueuedProjectiles.pop_back();
            return ret;
        }
        return nullptr;
    }

    ret = super();
    if (ret && weaponBlueprint->type == 3) // bomb
    {
        ret->flight_animation.tracker.loop = false;
        ((BombProjectile*)ret)->superShieldBypass = ((ShipObject*)this)->HasEquipment("ZOLTAN_BYPASS");
    }
    return ret;
}

HOOK_METHOD(DroneSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::OnLoop -> Begin (CustomDrones.cpp)\n")
    if (!loadingGame)
    {
        for (Drone* iDrone : drones)
        {
            if (iDrone->type == 4) // check that this is a boarding drone
            {
                BoarderPodDrone* drone = (BoarderPodDrone*) iDrone;
                if (drone->movementTarget == nullptr && drone->deployed)
                {
                    if (!drone->bDead && (!drone->bDeliveredDrone || !drone->boarderDrone->CrewDrone::CrewMember::bDead))
                    {
                        if (_shipObj.HasAugmentation("BOARDER_RECOVERY"))
                        {
                            drone_count += 1;
                            drone->SetDeployed(false);
                            if (drone->GetPowered())
                            {
                                DePowerDrone(drone, false);
                            }
                        }
                    }
                }
            }
        }
    }
    super();
}
/*
HOOK_METHOD(BoarderPodDrone, CanBeDeployed, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> BoarderPodDrone::CanBeDeployed -> Begin (CustomDrones.cpp)\n")
    bool ret = super();
    if (!ret && !bDead && bDeliveredDrone && boarderDrone->currentShipId == boarderDrone->iShipId)
    {
        return true;
    }
    return ret;
}

// Doesn't quite work; drone appears in wrong room
HOOK_METHOD(BoarderPodDrone, SetDeployed, (bool _deployed) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BoarderPodDrone::SetDeployed -> Begin (CustomDrones.cpp)\n")
    if (_deployed && boarderDrone && boarderDrone->currentShipId == boarderDrone->iShipId)
    {
        CompleteShip *enemyShip = G_->GetWorld()->playerShip->enemyShip;
        if (enemyShip)
        {
            boarderDrone->EmptySlot();
            enemyShip->AddCrewMember2(boarderDrone,-1);
        }
    }
    super(_deployed);
}
*/

HOOK_METHOD(DefenseDrone, PickTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DefenseDrone::PickTarget -> Begin (CustomDrones.cpp)\n")
    if (!g_defenseDroneFix) return super();

    if (!bDisrupted || !powered)
    {
        if (HasTarget())
        {
            Pointf relPos = {targetLocation.x - currentLocation.x, targetLocation.y - currentLocation.y};
            float speedFactor = G_->GetCFPS()->GetSpeedFactor();
            float aimAhead = Globals::AimAhead(relPos, targetSpeed, ((weaponBlueprint->speed > 0.f) ? weaponBlueprint->speed : 60.f) * speedFactor);
            if (aimAhead > 0.f)
            {
                targetLocation = {aimAhead*targetSpeed.x + targetLocation.x, aimAhead*targetSpeed.y + targetLocation.y};
            }
            if (*(int*)(&targetLocation.x) == 0xff7fffff || *(int*)(&targetLocation.y) == 0xff7fffff)
            {
                desiredAimingAngle = aimingAngle;
            }
            else
            {
                relPos = Pointf(targetLocation.x - currentLocation.x, targetLocation.y - currentLocation.y);
                desiredAimingAngle = atan2f(relPos.y, relPos.x) * 180.f / 3.141592654f;
                if (desiredAimingAngle < 0.f) desiredAimingAngle += 360.f;

                float swivelSpeed;
                float swivelDirection;
                bool bSwivelDir;

                if ((aimingAngle <= desiredAimingAngle || (aimingAngle - desiredAimingAngle) >= 180.f) && (desiredAimingAngle <= aimingAngle || (desiredAimingAngle - aimingAngle) >= 180.f))
                {
                    swivelSpeed = 30.f;
                    swivelDirection = 1.f;
                    bSwivelDir = true;
                }
                else
                {
                    swivelSpeed = -30.f;
                    swivelDirection = -1.f;
                    bSwivelDir = false;
                }

                aimingAngle += swivelSpeed * speedFactor;
                if (aimingAngle < 0.f) aimingAngle += 360.f;
                if (aimingAngle > 360.f) aimingAngle -= 360.f;

                if ((desiredAimingAngle < aimingAngle &&  bSwivelDir && aimingAngle - desiredAimingAngle < 180.f) ||
                    (aimingAngle < desiredAimingAngle && !bSwivelDir && desiredAimingAngle - aimingAngle < 180.f))
                {
                    aimingAngle = desiredAimingAngle;
                }

                if (aimingAngle == desiredAimingAngle)
                {
                    float x0;
                    float x1;
                    float y0;
                    float y1;

                    if (weaponTarget && weaponTarget->type == 3) // combat drone
                    {
                        x0 = -10000.f;
                        x1 = 10000.f;
                        y0 = -10000.f;
                        y1 = 10000.f;
                    }
                    else
                    {
                        ShipGraph *graph = ShipGraph::GetShipInfo(currentSpace);
                        if (graph)
                        {
                            x0 = graph->shipBox.x - g_defenseDroneFix_BoxRange[iShipId];
                            y0 = graph->shipBox.y - g_defenseDroneFix_BoxRange[iShipId];
                            x1 = graph->shipBox.x + graph->shipBox.w + g_defenseDroneFix_BoxRange[iShipId];
                            y1 = graph->shipBox.y + graph->shipBox.h + g_defenseDroneFix_BoxRange[iShipId];
                        }
                        else
                        {
                            x0 = -150.f;
                            x1 = 450.f;
                            y0 = -150.f;
                            y1 = 450.f;
                        }
                    }

                    if (targetLocation.x > x0 && targetLocation.y > y0 && targetLocation.x < x1 && targetLocation.y < y1)
                    {
                        shotAtTargetId = currentTargetId;
                        return;
                    }

                    if (movementTarget)
                    {
                        Globals::Ellipse shield = movementTarget->GetShieldShape();
                        shield.a += g_defenseDroneFix_EllipseRange[iShipId];
                        shield.b += g_defenseDroneFix_EllipseRange[iShipId];

                        float relX = targetLocation.x - shield.center.x;
                        float relY = targetLocation.y - shield.center.y;

                        if ((relX*relX)/(shield.a*shield.a) + (relY*relY)/(shield.b*shield.b) < 1.f) // shoot anything near the ellipse
                        {
                            shotAtTargetId = currentTargetId;
                            return;
                        }
                    }
                }
            }
            *(int*)(&targetLocation.x) = 0xff7fffff;
            *(int*)(&targetLocation.x) = 0xff7fffff;
            return;
        }
    }
    else
    {
        if (desiredAimingAngle == aimingAngle || desiredAimingAngle < 0.f)
        {
            desiredAimingAngle = random32() % 360;
            if (*(int*)(&targetLocation.x) == 0xff7fffff || *(int*)(&targetLocation.y) == 0xff7fffff || desiredAimingAngle >= 0.f)
            {
                float speedFactor = G_->GetCFPS()->GetSpeedFactor();

                if (desiredAimingAngle <= 0.f)
                {
                    Pointf relPos = Pointf(targetLocation.x - currentLocation.x, targetLocation.y - currentLocation.y);
                    desiredAimingAngle = atan2f(relPos.y, relPos.x) * 180.f / 3.141592654f;
                    if (desiredAimingAngle < 0.f) desiredAimingAngle += 360.f;
                }

                float swivelSpeed;
                float swivelDirection;
                bool bSwivelDir;

                if ((aimingAngle <= desiredAimingAngle || (aimingAngle - desiredAimingAngle) >= 180.f) && (desiredAimingAngle <= aimingAngle || (desiredAimingAngle - aimingAngle) >= 180.f))
                {
                    swivelSpeed = 30.f;
                    swivelDirection = 1.f;
                    bSwivelDir = true;
                }
                else
                {
                    swivelSpeed = -30.f;
                    swivelDirection = -1.f;
                    bSwivelDir = false;
                }

                aimingAngle += swivelSpeed * speedFactor;
                if (aimingAngle < 0.f) aimingAngle += 360.f;
                if (aimingAngle > 360.f) aimingAngle -= 360.f;

                if ((desiredAimingAngle < aimingAngle &&  bSwivelDir && aimingAngle - desiredAimingAngle < 180.f) ||
                    (aimingAngle < desiredAimingAngle && !bSwivelDir && desiredAimingAngle - aimingAngle < 180.f))
                {
                    aimingAngle = desiredAimingAngle;
                }
            }
        }
    }
}

/*
Defense drone types:
1 - MISSILES (vanilla)
2 - ASTEROIDS
3 - DRONES (vanilla)
4 - LASERS (vanilla)
5 - SOLID
6 - ALL

Target types:
0 - Ship
1 - Missile
2 - Asteroid
3 - Drone
4 - Laser
5 - ???
6 - Hacking/boarding drone
*/

HOOK_METHOD(DefenseDrone, ValidTargetObject, (Targetable *target) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> DefenseDrone::ValidTargetObject -> Begin (CustomDrones.cpp)\n")
    if (target == nullptr) return false;

    switch (blueprint->targetType)
    {
    case 2:
        if (target->type != 2) return false;
        break;
    case 5:
        if (target->type == 4) return false;
    case 6:
        if (target->type == 0 || target->type == 5) return false;
        break;
    default:
        return super(target);
    }

    return (powered && target->GetOwnerId() != iShipId && target->ValidTarget() && currentSpace == target->GetSpaceId());
}

HOOK_METHOD(DefenseDrone, SetWeaponTarget, (Targetable *target) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DefenseDrone::SetWeaponTarget -> Begin (CustomDrones.cpp)\n")
    if (!ValidTargetObject(target)) return;

    int targetId = target->GetSelfId();

    if (targetId == shotAtTargetId && blueprint->targetType != 3 && target->type != 3) return; // don't shoot at the same target twice, except for anti-drone

    if (currentTargetType == 1)
    {
        if (target->type != 1) return; // don't switch from missile to non-missile
    }
    else if (currentTargetType == 2)
    {
        if (((unsigned int)target->type) - 1U > 1) return; // don't switch from asteroid to non-asteroid/missile
    }

    if (targetId != currentTargetId)
    {
        if (aimingAngle > 180.f)
        {
            aimingAngle -= 360.f;
        }
        else if (aimingAngle < -180.f)
        {
            aimingAngle += 360.f;
        }
    }

    weaponTarget = nullptr; // this is from vanilla
    targetLocation = target->GetWorldCenterPoint();
    targetSpeed = target->GetSpeed();
    currentTargetId = targetId;
    currentTargetType = target->type;
}

HOOK_METHOD(DefenseDrone, GetTooltip, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> DefenseDrone::GetTooltip -> Begin (CustomDrones.cpp)\n")
    std::string tooltipText;

    switch (this->blueprint->targetType)
    {
    case 2:
        tooltipText = "defense_asteroid_";
        break;
    case 5:
        tooltipText = "defense_solid_";
        break;
    case 6:
        tooltipText = "defense_all_";
        break;
    default:
        return super();
    }

    if (this->iShipId == 0)
    {
        tooltipText = tooltipText + "friendly";
    }
    else
    {
        tooltipText = tooltipText + "enemy";
    }

    return G_->GetTextLibrary()->GetText(tooltipText, G_->GetTextLibrary()->currentLanguage);
}

HOOK_METHOD(SuperShieldDrone, constructor, (int iShipId, int selfId, DroneBlueprint *blueprint) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SuperShieldDrone::constructor -> Begin (CustomDrones.cpp)\n")
    super(iShipId, selfId, blueprint);

    drone_image_on = CachedImage("ship/drones/" + blueprint->droneImage + "_charged.png", CachedImage::Centered::CENTERED);
    drone_image_off = CachedImage("ship/drones/" + blueprint->droneImage + "_off.png", CachedImage::Centered::CENTERED);
    drone_image_glow = CachedImage("ship/drones/" + blueprint->droneImage + "_glow.png", CachedImage::Centered::CENTERED);
}

HOOK_METHOD_PRIORITY(SuperShieldDrone, OnLoop, 9999, () -> void)
{  
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SuperShieldDrone::OnLoop -> Begin (CustomDrones.cpp)\n")
    this->DefenseDrone::OnLoop();
    if (!GetPowered()) 
    {
        weaponCooldown = GetWeaponCooldown();
        glowAnimation = -1.0;
        return;
    }
    else 
    {
        if (GetDeployed()) 
        {
            currentSpeed = (float) blueprint->speed;
            if (weaponCooldown < 1.5 && glowAnimation <= 0.0) 
            {
                glowAnimation = 3.0;
                G_->GetSoundControl()->PlaySoundMix("shieldDroneCharge", -1.0, false);
            }
            if (weaponCooldown < 2.5) 
            {
                currentSpeed = std::max(weaponCooldown - 1.5, 0.0) * currentSpeed;
            }
            if (0.0 < glowAnimation) 
            {
                currentSpeed = 0.0;
            }
            glowAnimation -= G_->GetCFPS()->GetSpeedFactor() * 0.0625f;
            if (glowAnimation < 0.0) 
            {
                glowAnimation = -1.0;
            }

            if (!bFire) return;

            bFire = false;

            // Prevent vanilla crash when shieldSystem is null (occurs when not defined in the shipBlueprint)
            if (shieldSystem)
            {
                shieldSystem->AddSuperShield(Point(currentLocation.x, currentLocation.y));
            }

            G_->GetSoundControl()->PlaySoundMix("shieldDroneActivate", -1.0, false);
            weaponCooldown = GetWeaponCooldown();
            return;
        }
        weaponCooldown = GetWeaponCooldown();
        glowAnimation = -1.0;
        return;
    }
}


HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewDrone::OnLoop -> Begin (CustomDrones.cpp)\n")
    if (CustomCrewManager::GetInstance()->IsRace(species) && CustomCrewManager::GetInstance()->GetDefinition(species)->droneMoveFromManningSlot)
    {
        SetFrozen(Drone::deployed && !Drone::powered);

        ShipGraph *shipGraph = ShipGraph::GetShipInfo(currentShipId);

        if (currentSlot.slotId != -1 && currentSlot.roomId != -1 && !intruder)
        {
            if (Drone::deployed && !Drone::powered && shipGraph->rooms[currentSlot.roomId]->primarySlot == currentSlot.slotId)
            {
                bFrozenLocation = false;
            }

            if (!bFrozenLocation)
            {
                int closestSlot = -1;
                int closestRoom = -1;
                float closestDist = HUGE_VAL;

                Room *currentRoom = shipGraph->rooms[currentSlot.roomId];

                if (currentRoom->primarySlot != currentSlot.slotId)
                {
                    bFrozenLocation = true;
                    return super();
                }

                for (auto room : shipGraph->rooms)
                {
                    std::vector<int> emptySlots = std::vector<int>();

                    for (int slot = 0; slot < room->slots[intruder].size(); slot++)
                    {
                        if (slot != room->primarySlot && room->slots[intruder][slot] == false)
                        {
                            emptySlots.push_back(slot);
                        }
                    }

                    for (auto slot : emptySlots)
                    {
                        Path path = shipGraph->FindPath({(int)x, (int)y}, shipGraph->GetSlotWorldPosition(slot, room->iRoomId), currentShipId);

                        if (path.distance != -1.f && path.distance < closestDist)
                        {
                            closestSlot = slot;
                            closestRoom = room->iRoomId;
                            closestDist = path.distance;
                        }
                    }
                }



                bFrozenLocation = true;

                if (closestRoom != -1)
                {
                    MoveToRoom(closestRoom, closestSlot, true);
                }

            }
        }
    }

    super();
}

HOOK_METHOD(BoarderPodDrone, constructor, (int _iShipId, int _selfId, const DroneBlueprint& _bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BoarderPodDrone::constructor -> Begin (CustomDrones.cpp)\n")
    super(_iShipId, _selfId, _bp);

    CustomDroneManager* customDrone = CustomDroneManager::GetInstance();

    if (customDrone->GetDefinition(_bp.name))
    {
        std::string race = customDrone->GetDefinition(_bp.name)->crewBlueprint;

        CustomCrewManager* customCrew = CustomCrewManager::GetInstance();

        if (customCrew->IsRace(race))
        {
            auto def = customCrew->GetDefinition(race);
            if (!def->animSheet[1].empty())
            {
                race = def->animSheet[1];
            }
        }

        baseSheet = G_->GetResources()->GetImageId("people/" + race + "_base.png");
        colorSheet = G_->GetResources()->GetImageId("people/" + race + "_layer1.png");
        droneImage = G_->GetAnimationControl()->GetAnimation(race + "_fly");
    }
}


HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewDrone::OnLoop -> Begin (CustomDrones.cpp)\n")
    super();

    if (CM_EX(this)->isAbilityDrone)
    {
        ((AbilityDrone*)this)->new_OnLoop();
    }
}

HOOK_METHOD(CrewAnimation, OnRender, (float scale, int selectedState, bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnRender -> Begin (CustomDrones.cpp)\n")
    if (CMA_EX(this)->isAbilityDrone)
    {
        if (((AbilityDroneAnimation*)this)->new_OnRender(scale, selectedState, outlineOnly)) return;
    }

    super(scale, selectedState, outlineOnly);

}


HOOK_METHOD(CrewAnimation, OnInit, (const std::string& _race, Pointf position, bool enemy) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnInit -> Begin (CustomDrones.cpp)\n")
    super(_race, position, enemy);

    CustomDroneDefinition *customDrone = CustomDroneManager::GetInstance()->GetDefinitionByRace(_race);

    if (customDrone && customDrone->hasAbility)
    {
        ((AbilityDroneAnimation*)this)->new_OnInit(_race, position, enemy);
    }
}

// Fixes time advancement when powering a drone (it can call UpdateCrewmembers if the drone needs a room)

HOOK_METHOD(ShipManager, PowerDrone, (Drone *drone, int roomId, bool userDriven, bool force) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::PowerDrone -> Begin (CustomDrones.cpp)\n")
    CFPS *cFPS = G_->GetCFPS();
    float speed = cFPS->SpeedFactor;
    cFPS->SpeedFactor = 0.f;

    super(drone, roomId, userDriven, force);

    cFPS->SpeedFactor = speed;
}

//SpaceDrone table member
HOOK_METHOD(SpaceDrone, constructor, (int iShipId, int selfId, DroneBlueprint *blueprint) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceDrone::constructor -> Begin (CustomDrones.cpp)\n")
    super(iShipId, selfId, blueprint);
    HS_MAKE_TABLE(this)
    
    //Push base class data only, to avoid garbage data (Derived class constructor not yet called)
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSpaceDrone, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_SPACEDRONE, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(SpaceDrone, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceDrone::destructor -> Begin (CustomDrones.cpp)\n")
    HS_BREAK_TABLE(this)
    super();   
}

//Select crewdrones with drone selection hotkeys if setting is enabled.
HOOK_METHOD(DroneControl, SelectArmament, (unsigned int i) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneControl::SelectArmament -> Begin (CustomDrones.cpp)\n")
    super(i);
    if (CustomOptionsManager::GetInstance()->droneSelectHotkeys.currentValue)
    {
        DroneBox* box = static_cast<DroneBox*>(boxes[i]);
        Drone* drone = box->pDrone;
       
        if (box->Powered())
        {
            CrewDrone* crewDrone = nullptr;
            if (drone->type == DRONE_REPAIR || drone->type == DRONE_BATTLE) //If drone is a CrewDrone*
            {
                //Simple casting methods don't work as CrewDrone and Drone are not related by inheritence
                //TODO: Correct casting when multiple inheritence is properly represented in FTLGame headers
                ptrdiff_t droneBaseOffset = offsetof(CrewDrone, _drone);
                uintptr_t droneAddr = reinterpret_cast<uintptr_t>(drone);
                uintptr_t crewDroneAddr = droneAddr - droneBaseOffset;
                crewDrone = reinterpret_cast<CrewDrone*>(crewDroneAddr);
            }
            else if (drone->type == DRONE_BOARDER) //If drone is a BoarderPodDrone*
            {
                BoarderPodDrone* boarderPod = static_cast<BoarderPodDrone*>(drone);
                crewDrone = boarderPod->boarderDrone;
            }

            if (crewDrone != nullptr)
            {
                G_->GetCApp()->gui->crewControl.SelectPotentialCrew(crewDrone, false); 
                G_->GetCApp()->gui->crewControl.SelectCrew(false);
            }   
        }
    }   
}

//Add drones to return of GetCrewPortraitList call within functions handling saved positions if setting is enabled.
static bool forceIncludeDrones = false;
HOOK_METHOD(ShipManager, RestoreCrewPositions, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RestoreCrewPositions -> Begin (CustomDrones.cpp)\n")
    forceIncludeDrones = true;
    bool ret = super();
    forceIncludeDrones = false;
    return ret;
}
HOOK_METHOD(ShipManager, SaveCrewPositions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SaveCrewPositions -> Begin (CustomDrones.cpp)\n")
    forceIncludeDrones = true;
    super();
    forceIncludeDrones = false;
}
HOOK_METHOD(CrewMemberFactory, GetCrewPortraitList, (std::vector<CrewMember*>* vec, int teamId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::GetCrewPortraitList -> Begin (CustomDrones.cpp)\n")
    super(vec, teamId);
    if (forceIncludeDrones && CustomOptionsManager::GetInstance()->droneSaveStations.currentValue)
    {
        std::vector<CrewMember*> crewList;
        GetCrewList(&crewList, teamId, true);
        for (auto crew : crewList)
        {
            if (crew->IsDrone() && crew->currentShipId == teamId)
            {
                vec->push_back(crew);
            }
        }
    }
}
