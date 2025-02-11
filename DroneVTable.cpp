#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "CustomDrones.h"
#include "CustomCrew.h"
#include <algorithm>
#include "PALMemoryProtection.h"

static std::string boarderIonName = "boarder_ion";
inline std::string& CrewDrone::GetRace()
{
    return Drone::blueprint->name == "BOARDER_ION" ? boarderIonName : species;
}

CrewDefinition* CustomCrewManager::GetDroneRaceDefinition(CrewDrone *drone)
{
    if (drone->Drone::blueprint->name == "BOARDER_ION")
    {
        if (IsRace("boarder_ion"))
        {
            return GetDefinition("boarder_ion");
        }
    }
    if (IsRace(drone->species))
    {
        return GetDefinition(drone->species);
    }
    return nullptr;
}

bool CrewDrone::_HS_ValidTarget(int shipId)
{
    if (this->CrewMember::bDead || crewAnim->status == 3 || currentShipId != shipId) return false;

    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDroneRaceDefinition(this);
    if (!def) return true;
    bool ret;
    ex->CalculateStat(CrewStat::VALID_TARGET, def, &ret);
    return ret;
}

bool CrewDrone::_HS_GetControllable()
{
    if (this->CrewMember::bDead || !this->CrewMember::Functional()) return false;

    bool ret = this->CrewMember::iShipId == 0;// && !this->CrewMember::bMindControlled;
    /*
    if (!ret && this->CrewMember::iShipId == 1 && this->CrewMember::bMindControlled)
    {
        ShipManager *ship = G_->GetShipManager(0);
        if (ship) ret = ship->HasAugmentation("MIND_ORDER");
    }
    */
    CrewDefinition *def = nullptr;
    CrewMember_Extend *ex;

    if (ret)
    {
        def = CustomCrewManager::GetInstance()->GetDroneRaceDefinition(this);
        ex = CM_EX(this);
        if (!def) return false;

        ex->CalculateStat(CrewStat::CONTROLLABLE, def, &ret);
        if (ret)
        {
            if (requiresFullControl == 1)
            {
                ex->CalculateStat(CrewStat::CAN_MOVE, def, &ret);
                return ret;
            }
        }
        else if (!requiresFullControl)
        {
            ret = def->selectable;
        }
    }

    if (!ret && requiresFullControl == -1) // for AI with NO_AI, make AI think crew is player-controlled to prevent AI from controlling
    {
        if (!def)
        {
            def = CustomCrewManager::GetInstance()->GetDroneRaceDefinition(this);
            ex = CM_EX(this);
            if (!def) return false;
        }
        ex->CalculateStat(CrewStat::NO_AI, def, &ret);
        if (!ret)
        {
            ex->CalculateStat(CrewStat::CAN_MOVE, def, &ret);
            return !ret;
        }
    }

    return ret;
}

bool CrewDrone::_HS_CanFight()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (this->Drone::blueprint->name == "BOARDER_ION") {
        if (custom->IsRace("boarder_ion"))
        {
            auto ex = CM_EX(this);
            auto def = custom->GetDefinition("boarder_ion");
            bool ret = false;
            ex->CalculateStat(CrewStat::CAN_FIGHT, def, &ret);
            return ret;
        }
        return false;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_FIGHT, def, &ret);
        return ret;
    }

    if (this->Drone::blueprint->typeName == "BOARDER")
    {
        return true;
    }
    else if (this->Drone::blueprint->typeName == "BOARDER_ION")
    {
        return false;
    }
    else if (this->Drone::blueprint->typeName == "REPAIR")
    {
        return false;
    }
    else if (this->Drone::blueprint->typeName == "BATTLE")
    {
        return true;
    }
}

bool CrewDrone::_HS_CanRepair()
{
    bool req = this->Drone::powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_REPAIR"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_REPAIR");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_REPAIR, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_REPAIR, def, &ret);
        return ret && req;
    }

    if (this->Drone::blueprint->typeName == "BOARDER")
    {
        return false;
    }
    else if (this->Drone::blueprint->typeName == "BOARDER_ION")
    {
        return false;
    }
    else if (this->Drone::blueprint->typeName == "REPAIR")
    {
        return req;
    }
    else if (this->Drone::blueprint->typeName == "BATTLE")
    {
        return false;
    }
}

bool CrewDrone::_HS_CanSabotage()
{
    bool req = this->intruder;
    if (!req)
    {
        return false;
    }
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_SABOTAGE"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_SABOTAGE");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SABOTAGE, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SABOTAGE, def, &ret);
        return ret && req;
    }

    if (this->Drone::blueprint->typeName == "BOARDER")
    {
        return true;
    }
    else if (this->Drone::blueprint->typeName == "BOARDER_ION")
    {
        return true;
    }
    else if (this->Drone::blueprint->typeName == "REPAIR")
    {
        return false;
    }
    else if (this->Drone::blueprint->typeName == "BATTLE")
    {
        return false;
    }
}

bool CrewDrone::_HS_CanMan()
{
    bool req = !this->intruder && this->fStunTime == 0.f && this->crewAnim->status != 3;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_MAN"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_MAN");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_MAN, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_MAN, def, &ret);
        return ret && req;
    }

    return false;
}

/*
bool CrewDrone::_HS_CanTeleport()
{
    bool ret = this->CrewMember::CanTeleport(); // vanilla CanTeleport
    if (!ret) return false;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        ret = false;
        ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &ret);
        return ret;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        ret = false;
        ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &ret);
        return ret;
    }

    return false;
}
*/

bool CrewDrone::_HS_CanSuffocate()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_SUFFOCATE"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_SUFFOCATE");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SUFFOCATE, def, &ret);
        return ret;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_SUFFOCATE, def, &ret);
        return ret;
    }

    return false;
}

bool CrewDrone::_HS_CanBurn()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_BURN"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_BURN");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_BURN, def, &ret);
        return ret;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::CAN_BURN, def, &ret);
        return ret;
    }

    return false;
}

float CrewDrone::_HS_GetMoveSpeedMultiplier()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(this)->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER, def);
    }
    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);
        return CM_EX(this)->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER, def);
    }

    return 0.5f;
}

float CrewDrone::_HS_GetRepairSpeed()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(this)->CalculateStat(CrewStat::REPAIR_SPEED_MULTIPLIER, def);
    }
    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);
        return CM_EX(this)->CalculateStat(CrewStat::REPAIR_SPEED_MULTIPLIER, def);
    }

    return 2.f;
}

int CrewDrone::_HS_GetMaxHealth()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(this)->CalculateMaxHealth(def);
    }
    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);
        return CM_EX(this)->CalculateMaxHealth(def);
    }

    if (this->Drone::blueprint->typeName == "BOARDER")
    {
        return this->Drone::blueprint->name == "BOARDER_ION" ? 125 : 150;
    }
    else if (this->Drone::blueprint->typeName == "BOARDER_ION")
    {
        return 125;
    }
    else if (this->Drone::blueprint->typeName == "REPAIR")
    {
        return 25;
    }
    else if (this->Drone::blueprint->typeName == "BATTLE")
    {
        return 150;
    }
}

float CrewDrone::_HS_GetDamageMultiplier()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(this)->CalculateStat(CrewStat::DAMAGE_MULTIPLIER, def);
    }
    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);
        return CM_EX(this)->CalculateStat(CrewStat::DAMAGE_MULTIPLIER, def);
    }

    if (this->Drone::blueprint->typeName == "BOARDER")
    {
        return 1.2f;
    }
    else if (this->Drone::blueprint->typeName == "BOARDER_ION")
    {
        return 1.f;
    }
    else if (this->Drone::blueprint->typeName == "REPAIR")
    {
        return 1.f;
    }
    else if (this->Drone::blueprint->typeName == "BATTLE")
    {
        return 1.2f;
    }
}

bool CrewDrone::_HS_ProvidesPower()
{
    bool req = this->Drone::powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        return custom->GetDefinition("boarder_ion")->providesPower && req;
    }
    if (custom->IsRace(this->species))
    {
        return custom->GetDefinition(this->species)->providesPower && req;
    }

    return false;
}

float CrewDrone::_HS_GetFireRepairMultiplier()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(this)->CalculateStat(CrewStat::FIRE_REPAIR_MULTIPLIER, def);
    }
    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);
        return CM_EX(this)->CalculateStat(CrewStat::FIRE_REPAIR_MULTIPLIER, def);
    }

    return 1.2f;
}

bool CrewDrone::_HS_IsTelepathic()
{
    bool ret;
    bool req = this->Drone::powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_TELEPATHIC"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_TELEPATHIC");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        ex->CalculateStat(CrewStat::IS_TELEPATHIC, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        ex->CalculateStat(CrewStat::IS_TELEPATHIC, def, &ret);
        return ret && req;
    }

    return false;
}

float CrewDrone::_HS_GetSuffocationModifier()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto def = custom->GetDefinition("boarder_ion");
        return CM_EX(this)->CalculateStat(CrewStat::SUFFOCATION_MODIFIER, def);
    }
    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);
        return CM_EX(this)->CalculateStat(CrewStat::SUFFOCATION_MODIFIER, def);
    }

    return 0.f;
}

bool CrewDrone::_HS_IsAnaerobic()
{
    bool req = this->Drone::powered;
    if (!req)
    {
        return false;
    }

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

//    if (this->GetShipObject()->HasAugmentation("ALL_DRONE_CREW_ANAEROBIC"))
//    {
//        return (bool)this->GetShipObject()->GetAugmentationValue("ALL_DRONE_CREW_ANAEROBIC");
//    }
    if (this->Drone::blueprint->name == "BOARDER_ION" && custom->IsRace("boarder_ion"))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition("boarder_ion");
        bool ret = false;
        ex->CalculateStat(CrewStat::IS_ANAEROBIC, def, &ret);
        return ret && req;
    }

    if (custom->IsRace(this->species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);
        bool ret = false;
        ex->CalculateStat(CrewStat::IS_ANAEROBIC, def, &ret);
        return ret && req;
    }

    return false;
}

int CrewDrone::_HS_BlockRoom()
{
    if (CM_EX(this)->isAbilityDrone)
        return ((AbilityDrone*)this)->new_BlockRoom();
    else if (CM_EX(this)->isIonDrone)
        return ((IonDrone*)this)->lastRoom;

    return -1;
}

void SetupVTable(CrewDrone *crew)
{
    void** vtable = *(void***)crew;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);
    {
        auto fptr = &CrewDrone::_HS_ValidTarget;
        vtable[7] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetControllable;
        vtable[23] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_CanFight;
        vtable[25] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_CanRepair;
        vtable[26] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_CanSabotage;
        vtable[27] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_CanMan;
        vtable[28] = reinterpret_cast<void *&>(fptr);
    }
    //{
        //auto fptr = &CrewDrone::_HS_CanTeleport;
        //if (g_dronesCanTeleport) vtable[29] = reinterpret_cast<void *&>(fptr);
    //}
    {
        auto fptr = &CrewDrone::_HS_CanSuffocate;
        vtable[31] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_CanBurn;
        vtable[32] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetMaxHealth;
        vtable[33] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetMoveSpeedMultiplier;
        vtable[40] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetRepairSpeed;
        vtable[41] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetDamageMultiplier;
        vtable[42] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_ProvidesPower;
        vtable[43] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetFireRepairMultiplier;
        vtable[45] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_IsTelepathic;
        vtable[46] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_GetSuffocationModifier;
        vtable[52] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_BlockRoom;
        vtable[53] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewDrone::_HS_IsAnaerobic;
        vtable[55] = reinterpret_cast<void *&>(fptr);
    }
    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);
}

HOOK_METHOD(CrewMemberFactory, CreateRepairDrone, (int shipId, DroneBlueprint* bp) -> RepairDrone*)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::CreateRepairDrone -> Begin (DroneVTable.cpp)\n")
    RepairDrone* drone = super(shipId, bp);

    SetupVTable(drone);

    return drone;
}



HOOK_METHOD(CrewMemberFactory, CreateBattleDrone, (int shipId, DroneBlueprint* bp) -> BattleDrone*)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::CreateBattleDrone -> Begin (DroneVTable.cpp)\n")
    BattleDrone* drone = super(shipId, bp);

    SetupVTable(drone);

    return drone;
}

HOOK_METHOD_PRIORITY(CrewMemberFactory, CreateBoarderDrone, -900, (int shipId, DroneBlueprint* bp) -> BoarderDrone*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMemberFactory::CreateBoarderDrone -> Begin (DroneVTable.cpp)\n")
    BoarderDrone* drone = super(shipId, bp);

    SetupVTable(drone);

    return drone;
}

#pragma GCC pop_options
