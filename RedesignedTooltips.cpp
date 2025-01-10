#include "RedesignedTooltips.h"
#include "CustomOptions.h"
#include "CustomWeapons.h"
#include "CustomAugments.h"
#include "CustomDrones.h"
#include "CustomCrew.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <boost/algorithm/string/predicate.hpp>

std::string GetWeaponStatsString(const WeaponBlueprint* bp, bool drone = false, int dronePower = 0, int droneSpeed = 0)
{
    auto tLib = G_->GetTextLibrary();
    std::string descText = "";
    if (drone)
    {
        descText += "\n\n" + tLib->GetText("description_stats") + "\n";
    }
    std::string currentText = "";

    if (drone)
    {
        currentText = G_->GetTextLibrary()->GetText("required_power");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(dronePower)) + "\n";
        descText += G_->GetTextLibrary()->GetText("drone_required") + "\n\n";
        currentText = tLib->GetText("drone_speed");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(droneSpeed)) + "\n\n";
    }

    auto weaponDef = CustomWeaponManager::instance->GetWeaponDefinition(bp->name);

    if (!drone)
    {
        if (bp->power > 0)
        {
            currentText = tLib->GetText("required_power");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->power)) + "\n";
        }
        else if (bp->power == 0)
        {
            if (bp->cooldown >= 0)
            {
                currentText = tLib->GetText("requires_no_power");
                descText += currentText + "\n";
            }
            else
            {
                currentText = tLib->GetText("cannot_fire");
                descText += currentText + "\n";
            }
        }
        else
        {
            currentText = tLib->GetText("provides_bonus_power");
            descText += currentText + ": " + std::to_string(bp->power * -1) + "\n";
        }

        if (bp->cooldown >= 0)
        {
            currentText = tLib->GetText("charge_time");

            std::stringstream cooldownString;
            cooldownString << bp->cooldown;

            descText += boost::algorithm::replace_all_copy(currentText, "\\1", cooldownString.str()) + "\n";
        }
        else
        {
            if (bp->power != 0)
            {
                currentText = tLib->GetText("cannot_fire");
                descText += currentText + "\n";
            }
        }
    }

    if (bp->cooldown >= 0)
    {
        if (bp->missiles > 0)
        {
            currentText = tLib->GetText("ammo_consumption");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->missiles)) + "\n";
        }

        if (weaponDef->freeMissileChance > 0)
        {
            currentText = tLib->GetText("free_missile_chance");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->freeMissileChance)) + "\n";
        }

        if (weaponDef->customDamage->accuracyMod != 0)
        {
            currentText = tLib->GetText("accuracy_modifier");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->customDamage->accuracyMod)) + "\n";
        }

        if (bp->boostPower.count > 0)
        {
            std::string boostType = "";

            if (bp->boostPower.type == 2)
            {
                if (bp->boostPower.amount > 0)
                {
                    currentText = tLib->GetText("redesigned_boost_power_damage_positive");
                    std::stringstream stream;
                    stream << std::setprecision(2) << bp->boostPower.amount;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                    int dmg = bp->damage.iIonDamage;
                    if (dmg <= 0)
                    {
                        dmg = bp->damage.iDamage;
                    }

                    std::stringstream damageCapString;
                    damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

                    currentText = tLib->GetText("redesigned_damage_cap");
                    currentText = boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str());
                    stream.str("");
                    stream.clear();
                    stream << std::setprecision(2) << bp->boostPower.count;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                }
                else
                {
                    currentText = tLib->GetText("redesigned_boost_power_damage_negative");
                    std::stringstream stream;
                    stream << std::setprecision(2) << bp->boostPower.amount;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                    int dmg = bp->damage.iIonDamage;
                    if (dmg <= 0)
                    {
                        dmg = bp->damage.iDamage;
                    }

                    std::stringstream damageCapString;
                    damageCapString << (bp->boostPower.count * bp->boostPower.amount + dmg);

                    currentText = tLib->GetText("redesigned_damage_cap");
                    currentText = boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str());
                    stream.str("");
                    stream.clear();
                    stream << std::setprecision(2) << bp->boostPower.count;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                }
            }
            else
            {
                if (bp->boostPower.amount > 0)
                {
                    currentText = tLib->GetText("redesigned_boost_power_speed_positive");
                    std::stringstream stream;
                    stream << std::setprecision(4) << bp->boostPower.amount;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                    int speedCap = bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);
                    if (speedCap >= 0)
                    {
                        std::stringstream speedCapString;
                        speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

                        currentText = tLib->GetText("redesigned_speed_cap");
                        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str());
                        stream.str("");
                        stream.clear();
                        stream << std::setprecision(4) << bp->boostPower.count;
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                    }
                    else
                    {
                        std::stringstream maxShotCount;
                        maxShotCount << std::ceil((bp->cooldown / bp->boostPower.amount));

                        currentText = tLib->GetText("max_shots");
                        boostType += boost::algorithm::replace_all_copy(currentText, "\\1", maxShotCount.str());
                    }
                }
                else
                {
                    currentText = tLib->GetText("redesigned_boost_power_speed_negative");
                    std::stringstream stream;
                    stream << std::setprecision(4) << bp->boostPower.amount;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                    std::stringstream speedCapString;
                    speedCapString << bp->cooldown - (bp->boostPower.count * bp->boostPower.amount);

                    currentText = tLib->GetText("redesigned_speed_cap");
                    currentText = boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str());
                    stream.str("");
                    stream.clear();
                    stream << std::setprecision(4) << bp->boostPower.count;
                    boostType += boost::algorithm::replace_all_copy(currentText, "\\2", stream.str()) + "\n";
                }
            }

            descText += boostType;
        }

        // space
        boost::trim_right(descText);
        descText += "\n\n";

        if (weaponDef->angularRadius != -1.f) // for drones?
        {
            std::stringstream stream;
            currentText = tLib->GetText("shot_radius_angular");
            stream << std::fixed << std::setprecision(2) << weaponDef->angularRadius;
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
        }
        else if(bp->radius > 0)
        {
            currentText = tLib->GetText("shot_radius");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->radius)) + "\n";
        }

        if (bp->type == 0 || bp->type == 1 || bp->type == 3 || bp->type == 4)
        {
            if (!drone)
            {
                if (bp->type == 0 || bp->type == 1 || (bp->shots == 1 && bp->type != 4))
                {
                    currentText = tLib->GetText("shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
                }
                else if (bp->type == 3)
                {
                    currentText = tLib->GetText("bomb_shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->shots)) + "\n";
                }
                else
                {
                    currentText = tLib->GetText("shots");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->miniCount * bp->shots)) + "\n";
                }
            }
        }

        if (bp->chargeLevels > 1)
        {
            currentText = tLib->GetText("charge");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->chargeLevels)) + "\n";
        }

        if (bp->type == 2)
        {
            currentText = tLib->GetText("beam_length");
            if (bp->length > 1)
            {
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->length)) + "\n";
            }
            else
            {
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", tLib->GetText("pinpoint")) + "\n";
            }
            currentText = tLib->GetText("swipe_speed");
            if (bp->speed != 0)
            {
                std::stringstream stream;
                stream << std::fixed <<std::setprecision(0) << bp->speed;
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
            }
            else
            {
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(5)) + "\n";
            }
        }

        // space
        boost::trim_right(descText);
        descText += "\n\n";

//            if (bp->drone_targetable != 0)
//            {
//                descText += tLib->GetText("weapon_not_drone_targetable") + "\n";
//            }
//            else
//            {
//                descText += tLib->GetText("weapon_drone_targetable") + "\n";
//            }

        if (bp->damage.bHullBuster)
        {
            descText += tLib->GetText("redesigned_double_damage") + "\n";
        }

//            if (bp->damage.iPersDamage == 0 && bp->damage.iSystemDamage == 0)
//            {
//                if (bp->damage.iDamage != 0)
//                {
//                    if (bp->type == 2)
//                    {
//                        currentText = tLib->GetText("redesigned_damage_room");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                    else
//                    {
//                        currentText = tLib->GetText("redesigned_damage_shot");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                }
//            }
//            else
//            {
//                if (bp->type == 2)
//                {
                if (bp->damage.iDamage > 0)
                {
                    currentText = tLib->GetText("hull_damage");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
                }
                else if (bp->damage.iDamage < 0)
                {
                    currentText = tLib->GetText("hull_damage_negative");
                    descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage * -1)) + "\n";
                }

                if (bp->damage.iDamage >= 0)
                {
                    int sysDamage = bp->damage.iSystemDamage;
                    int persDamage = bp->damage.iPersDamage;
                    if (!weaponDef->customDamage->noSysDamage) sysDamage += bp->damage.iDamage;
                    if (!weaponDef->customDamage->noPersDamage) persDamage += bp->damage.iDamage;

                    if (sysDamage > 0)
                    {
                        currentText = tLib->GetText("system_damage");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(sysDamage)) + "\n";
                    }
                    else if (sysDamage < 0)
                    {
                        currentText = tLib->GetText("system_damage_negative");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((sysDamage) * -1)) + "\n";
                    }
                    if (persDamage > 0)
                    {
                        currentText = tLib->GetText("personnel_damage");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((persDamage) * 15)) + "\n";
                    }
                    else if (persDamage < 0)
                    {
                        currentText = tLib->GetText("personnel_damage_negative");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(((persDamage) * -1) * 15)) + "\n";
                    }

                }
                else
                {
                    if (bp->damage.iSystemDamage > 0)
                    {
                        currentText = tLib->GetText("system_damage");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage)) + "\n";
                    }
                    else if (bp->damage.iSystemDamage < 0)
                    {
                        currentText = tLib->GetText("system_damage_negative");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iSystemDamage) * -1)) + "\n";
                    }
                    if (bp->damage.iPersDamage > 0)
                    {
                        currentText = tLib->GetText("personnel_damage");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iPersDamage) * 15)) + "\n";
                    }
                    else if (bp->damage.iPersDamage < 0)
                    {
                        currentText = tLib->GetText("personnel_damage_negative");
                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(((bp->damage.iPersDamage) * -1) * 15)) + "\n";
                    }
                }
//                }
//                else
//                {
//                    if (bp->damage.iDamage != 0)
//                    {
//                        currentText = tLib->GetText("hull_damage");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iDamage)) + "\n";
//                    }
//                    if (bp->damage.iSystemDamage + bp->damage.iDamage != 0)
//                    {
//                        currentText = tLib->GetText("system_damage");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iSystemDamage + bp->damage.iDamage)) + "\n";
//                    }
//                    if (bp->damage.iPersDamage + bp->damage.iDamage != 0)
//                    {
//                        currentText = tLib->GetText("personnel_damage");
//                        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string((bp->damage.iDamage + bp->damage.iPersDamage) * 15)) + "\n";
//                    }
//                }
//            }

        if (bp->damage.iIonDamage != 0)
        {
            currentText = tLib->GetText("ion_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iIonDamage)) + "\n";
        }

        if (bp->damage.iShieldPiercing != 0)
        {
            currentText = tLib->GetText("shield_piercing");
            if (bp->type != 2 || bp->damage.iDamage > 0)
            {
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing)) + "\n";
            }
            else if (bp->damage.iDamage == 0 && bp->damage.iShieldPiercing - 1 > 0)
            {
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing - 1)) + "\n";
            }
            else
            {
                descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->damage.iShieldPiercing + bp->damage.iDamage - 1)) + "\n";
            }
        }

        // space
        boost::trim_right(descText);
        descText += "\n\n";


        if (bp->damage.bLockdown)
        {
            currentText = tLib->GetText("weapon_lockdown");
            descText += currentText + "\n";
        }
        if (bp->damage.fireChance > 0)
        {
            currentText = tLib->GetText("fire_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.fireChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (bp->damage.fireChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (bp->damage.fireChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";

        }
        if (bp->damage.breachChance > 0)
        {
            currentText = tLib->GetText("breach_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.breachChance * 10));
            boost::algorithm::replace_all(currentText, "\\2", std::to_string(bp->damage.breachChance * 10 - bp->damage.fireChance * bp->damage.breachChance));

            std::string level = tLib->GetText("chance_low");
            if (bp->damage.breachChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (bp->damage.breachChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\3", level);

            descText += currentText + "\n";
        }
        if (bp->damage.iStun > 0 && Settings::GetDlcEnabled())
        {
            currentText = tLib->GetText("stun_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(100));
            descText += currentText + " (" + std::to_string(bp->damage.iStun) + " " + tLib->GetText("stun_length") + ")\n";
        }
        else if (bp->damage.stunChance > 0 && Settings::GetDlcEnabled())
        {
            currentText = tLib->GetText("stun_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(bp->damage.stunChance * 10));
            currentText += " (3 " + tLib->GetText("stun_length") + ")";

            std::string level = tLib->GetText("chance_low") + " (3 " + tLib->GetText("stun_length");
            if (bp->damage.stunChance >= 7)
            {
                level = tLib->GetText("chance_high") + " (3 " + tLib->GetText("stun_length");
            }
            else if (bp->damage.stunChance >= 4)
            {
                level = tLib->GetText("chance_medium") + " (3 " + tLib->GetText("stun_length");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->erosionChance > 0)
        {
            currentText = tLib->GetText("erosion_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->erosionChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->erosionChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->erosionChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";

            currentText = tLib->GetText("erosion_effect");

            std::stringstream stream;
            stream << std::setprecision(2) << weaponDef->customDamage->erosionEffect.erosionSpeed * weaponDef->customDamage->erosionEffect.erosionTime * 0.16f;
            boost::algorithm::replace_all(currentText, "\\1", stream.str());

            stream.str("");
            stream << std::setprecision(2) << weaponDef->customDamage->erosionEffect.erosionTime;
            boost::algorithm::replace_all(currentText, "\\2", stream.str());

            stream.str("");
            stream << std::setprecision(2) << weaponDef->customDamage->erosionEffect.erosionSpeed;
            boost::algorithm::replace_all(currentText, "\\3", stream.str());

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->statBoostChance > 0)
        {
            currentText = tLib->GetText("crew_statboost_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->statBoostChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->statBoostChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->statBoostChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->roomStatBoostChance > 0)
        {
            currentText = tLib->GetText("room_statboost_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->roomStatBoostChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->roomStatBoostChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->roomStatBoostChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->crewSpawnChance > 0)
        {
            currentText = tLib->GetText("crew_spawn_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->crewSpawnChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->crewSpawnChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->crewSpawnChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
    }

    boost::trim_right(descText);

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), bp, context->getLibScript()->types.pWeaponBlueprint, 0);
    lua_pushstring(context->GetLua(), descText.c_str());
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::WEAPON_STATBOX, 2, 1);
    if (preempt) return "";
    if (lua_isstring(context->GetLua(), -1)) descText = lua_tostring(context->GetLua(), -1);
    lua_pop(context->GetLua(), 2);
    
    return descText;
}

HOOK_METHOD(WeaponBox, GenerateTooltip, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> WeaponBox::GenerateTooltip -> Begin (RedesignedTooltips.cpp)\n")
    std::string ret = super();

    auto tLib = G_->GetTextLibrary();
    std::string descText = "";
    std::string currentText = "";
    auto bp = this->pWeapon->blueprint;

    auto weaponDef = CustomWeaponManager::instance->GetWeaponDefinition(bp->name);

    if (CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue && !weaponDef->advancedTooltipOverride.data.empty())
    {
        std::string newDesc = weaponDef->advancedTooltipOverride.GetText();

        ret.assign(boost::algorithm::replace_all_copy(newDesc, "\\n", "\n"));
        return ret;
    }
    else if (!weaponDef->tooltipOverride.data.empty())
    {
        std::string newDesc = weaponDef->tooltipOverride.GetText();

        ret.assign(boost::algorithm::replace_all_copy(newDesc, "\\n", "\n"));
        return ret;
    }
    else if (CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue == true)
    {
        ret.assign(GetWeaponStatsString(bp));
    }

    return ret;
}

HOOK_METHOD(WeaponBlueprint, GetDescription, (bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> WeaponBlueprint::GetDescription -> Begin (RedesignedTooltips.cpp)\n")
    if (tooltip || this->name.empty()) return super(tooltip);
    std::string ret = super(tooltip);

    auto tLib = G_->GetTextLibrary();
    std::string descText = "";
    std::string currentText = "";

    auto weaponDef = CustomWeaponManager::instance->GetWeaponDefinition(this->name);

    if (CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue && !weaponDef->advancedDescriptionOverride.data.empty())
    {
        std::string newDesc = weaponDef->advancedDescriptionOverride.GetText();

        ret.assign(boost::algorithm::replace_all_copy(newDesc, "\\n", "\n"));
    }
    else if (!weaponDef->descriptionOverride.data.empty())
    {
        std::string newDesc = weaponDef->descriptionOverride.GetText();

        ret.assign(boost::algorithm::replace_all_copy(newDesc, "\\n", "\n"));
    }
    else if (CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue)
    {
        descText += this->desc.description.GetText() + "\n\n";
        descText += tLib->GetText("description_stats") + "\n";
        descText += GetWeaponStatsString(this);
        descText += "\n\n";
        currentText = G_->GetTextLibrary()->GetText("scrap_value");
        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->desc.cost));
        descText += boost::algorithm::replace_all_copy(currentText, "\\2", std::to_string(this->desc.cost / 2));
        descText += "\n";
        ret.assign(descText);
    }
    else
    {
        descText += this->desc.description.GetText() + "\n\n";

        currentText = tLib->GetText("required_power");
        descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->power)) + "\n";

        currentText = tLib->GetText("charge_time");

        std::stringstream cooldownString;
        cooldownString << this->cooldown;


        descText += boost::algorithm::replace_all_copy(currentText, "\\1", cooldownString.str()) + "\n";

        if (this->boostPower.count > 1)
        {
            std::string boostType = "";

            if (this->boostPower.type == 2)
            {
                boostType += tLib->GetText("boost_power_damage") + "\n";

                int dmg = this->damage.iIonDamage;
                if (dmg <= 0)
                {
                    dmg = this->damage.iDamage;
                }

                std::stringstream damageCapString;
                damageCapString << (this->boostPower.count * this->boostPower.amount + dmg);

                currentText = tLib->GetText("damage_cap");
                boostType += boost::algorithm::replace_all_copy(currentText, "\\1", damageCapString.str()) + "\n";
            }
            else
            {
                boostType += tLib->GetText("boost_power_speed") + "\n";

                currentText = tLib->GetText("speed_cap");

                std::stringstream speedCapString;
                speedCapString << this->cooldown - (this->boostPower.count * this->boostPower.amount);

                boostType += boost::algorithm::replace_all_copy(currentText, "\\1", speedCapString.str()) + "\n";
            }

            descText += boostType;
        }

        if (this->missiles > 0)
        {
            descText += tLib->GetText("requires_missiles") + "\n";
        }

        if ((this->type == 0 || this->type == 1) && this->shots > 0)
        {
            currentText = tLib->GetText("shots");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->shots)) + "\n";
        }

        if (this->type == 4)
        {
            currentText = tLib->GetText("shots");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->miniCount)) + "\n";
        }

        if (this->chargeLevels > 1)
        {
            currentText = tLib->GetText("charge");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->chargeLevels)) + "\n";
        }

        if (this->type == 2)
        {
            currentText = tLib->GetText("damage_room");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->damage.iDamage)) + "\n";
        }
        else
        {
            currentText = tLib->GetText("damage_shot");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->damage.iDamage)) + "\n";
        }

        if (this->damage.iShieldPiercing != 0)
        {
            currentText = tLib->GetText("shield_piercing");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->damage.iShieldPiercing)) + "\n";
        }

        if (this->damage.fireChance > 0)
        {
            currentText = tLib->GetText("fire_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(this->damage.fireChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (this->damage.fireChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (this->damage.fireChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";

        }
        if (this->damage.breachChance > 0)
        {
            currentText = tLib->GetText("breach_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(this->damage.breachChance * 10));
            boost::algorithm::replace_all(currentText, "\\2", std::to_string(this->damage.breachChance * 10 - this->damage.fireChance * this->damage.breachChance));

            std::string level = tLib->GetText("chance_low");
            if (this->damage.breachChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (this->damage.breachChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\3", level);

            descText += currentText + "\n";
        }

        if (this->damage.iIonDamage != 0)
        {
            currentText = tLib->GetText("ion_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->damage.iIonDamage)) + "\n";
        }
        if (this->damage.iStun > 0 && Settings::GetDlcEnabled())
        {
            currentText = tLib->GetText("stun_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(this->damage.iStun)) + "\n";
        }
        else if (this->damage.stunChance > 0 && Settings::GetDlcEnabled())
        {
            currentText = tLib->GetText("stun_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(this->damage.stunChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (this->damage.stunChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (this->damage.stunChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->erosionChance > 0)
        {
            currentText = tLib->GetText("erosion_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->erosionChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->erosionChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->erosionChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";

            currentText = tLib->GetText("erosion_effect");

            std::stringstream stream;
            stream << std::setprecision(2) << weaponDef->customDamage->erosionEffect.erosionSpeed * weaponDef->customDamage->erosionEffect.erosionTime * 0.16f;
            boost::algorithm::replace_all(currentText, "\\1", stream.str());

            stream.str("");
            stream << std::setprecision(2) << weaponDef->customDamage->erosionEffect.erosionTime;
            boost::algorithm::replace_all(currentText, "\\2", stream.str());

            stream.str("");
            stream << std::setprecision(2) << weaponDef->customDamage->erosionEffect.erosionSpeed;
            boost::algorithm::replace_all(currentText, "\\3", stream.str());

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->statBoostChance > 0)
        {
            currentText = tLib->GetText("crew_statboost_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->statBoostChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->statBoostChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->statBoostChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->roomStatBoostChance > 0)
        {
            currentText = tLib->GetText("room_statboost_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->roomStatBoostChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->roomStatBoostChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->roomStatBoostChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        if (weaponDef->customDamage->crewSpawnChance > 0)
        {
            currentText = tLib->GetText("crew_spawn_chance");
            boost::algorithm::replace_all(currentText, "\\1", std::to_string(weaponDef->customDamage->crewSpawnChance * 10));

            std::string level = tLib->GetText("chance_low");
            if (weaponDef->customDamage->crewSpawnChance >= 7)
            {
                level = tLib->GetText("chance_high");
            }
            else if (weaponDef->customDamage->crewSpawnChance >= 4)
            {
                level = tLib->GetText("chance_medium");
            }

            boost::algorithm::replace_all(currentText, "\\2", level);

            descText += currentText + "\n";
        }
        int persDamage = this->damage.iPersDamage;
        if (weaponDef->customDamage->noPersDamage) persDamage -= this->damage.iDamage;
        if (persDamage != 0)
        {
            currentText = tLib->GetText("personnel_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(persDamage * 15)) + "\n";
        }
        int sysDamage = this->damage.iSystemDamage;
        if (weaponDef->customDamage->noSysDamage) sysDamage -= this->damage.iDamage;
        if (sysDamage != 0)
        {
            currentText = tLib->GetText("system_damage");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(sysDamage)) + "\n";
        }
        if (this->damage.bHullBuster)
        {
            descText += tLib->GetText("double_damage") + "\n";
        }
        if (weaponDef->freeMissileChance > 0)
        {
            currentText = tLib->GetText("free_missile_chance");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->freeMissileChance)) + "\n";
        }
        if (weaponDef->customDamage->accuracyMod != 0)
        {
            currentText = tLib->GetText("accuracy_modifier");
            descText += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->customDamage->accuracyMod)) + "\n";
        }
        ret.assign(descText);
    }

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pWeaponBlueprint, 0);
    lua_pushstring(context->GetLua(), ret.c_str());
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::WEAPON_DESCBOX, 2, 1);
    if (preempt) return "";
    if (lua_isstring(context->GetLua(), -1)) ret = lua_tostring(context->GetLua(), -1);
    lua_pop(context->GetLua(), 2);

    return ret;
}

// Make augment box scale with text

HOOK_METHOD(InfoBox, SetBlueprintAugment, (const AugmentBlueprint* bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintAugment -> Begin (RedesignedTooltips.cpp)\n")
    desc.title.data.assign(bp->desc.title.data);
    desc.title.isLiteral = bp->desc.title.isLiteral;

    desc.shortTitle.data.assign(bp->desc.shortTitle.data);
    desc.shortTitle.isLiteral = bp->desc.shortTitle.isLiteral;

    std::string newDesc;
    if (!bp->desc.description.isLiteral)
    {
        newDesc = G_->GetTextLibrary()->GetText(bp->desc.description.data);
    }
    else
    {
        newDesc = bp->desc.description.data;
    }
    newDesc += "\n\n";
    std::string currentText = G_->GetTextLibrary()->GetText("scrap_value");
    currentText = boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->desc.cost));
    newDesc += boost::algorithm::replace_all_copy(currentText, "\\2", std::to_string(bp->desc.cost / 2));

    if (CustomOptionsManager::GetInstance()->redesignedAugmentTooltips.currentValue)
    {
        desc.description.data.assign(newDesc);
        desc.description.isLiteral = true;
    }
    else
    {
        desc.description.data.assign(bp->desc.description.data);
        desc.description.isLiteral = bp->desc.description.isLiteral;
    }

    desc.cost = bp->desc.cost;
    desc.rarity = bp->desc.rarity;
    desc.baseRarity = bp->desc.baseRarity;
    desc.bp = bp->desc.bp;
    desc.locked = bp->desc.locked;

    descBoxSize.x = 305;
    descBoxSize.y = 266;
    primaryBoxOffset = 67;

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    if (customAug->IsAugment(bp->name))
    {
        std::string warn = G_->GetTextLibrary()->GetText("augment_no_effect");
        warn.append("\n");

        BlueprintManager* blueprints = G_->GetBlueprints();
        int counter = 0;
        std::string lastWarnAugment = "";
        for (auto const &x: customAug->GetAugmentDefinition(bp->name)->functions)
        {
            if (!x.second.warning)
                continue;
            if (x.first == lastWarnAugment)
                continue;

            auto bp = blueprints->GetAugmentBlueprint(x.first);

            if (((x.second.preferHigher && bp->value <= x.second.value) || (!x.second.preferHigher && bp->value >= x.second.value)) && !bp->stacking)
            {
                lastWarnAugment = x.first;
                warn += bp->desc.title.GetText() + "\n";
                counter++;
            }
        }

        if (counter > 0)
            warning.assign(warn);
    }
    Pointf s;
    if (CustomOptionsManager::GetInstance()->redesignedAugmentTooltips.currentValue)
    {
        s = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, warning + "\n" + newDesc);
    }
    else
    {
        s = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, warning + "\n" + desc.description.GetText());
    }
    descBoxSize.y = s.y;

    delete primaryBox;
    primaryBox = new WindowFrame(7, 7, 323, s.y + 58);

    bDetailed = false;
}

static bool windowFrameCheck = false;
static int windowFrameHeight = 0;

HOOK_METHOD(WindowFrame, constructor, (int x, int y, int w, int h) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WindowFrame::constructor -> Begin (RedesignedTooltips.cpp)\n")
    if (windowFrameCheck)
    {
        h = windowFrameHeight;
        windowFrameCheck = false;
    }

    super(x, y, w, h);
}

HOOK_METHOD(InfoBox, SetBlueprintCrew, (const CrewBlueprint& bp, int yShift, bool detailedCrew) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintCrew -> Begin (RedesignedTooltips.cpp)\n")
//    if (CustomOptionsManager::GetInstance()->redesignedCrewTooltips.currentValue)
//    {
//        std::string newDesc = bp.desc.description.data;
//        newDesc += "\n\n";
//        std::string currentText = G_->GetTextLibrary()->GetText("crew_scrap_value");
//        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp.desc.cost));
//        newDesc += currentText;
//
//        CrewBlueprint newBp;
//        newBp = bp;
//        newBp.desc.description.data.assign(newDesc);
//
//        Pointf titleSize = freetype::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
//        Pointf descSize = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, newDesc);
//
//        Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
//        boxSize.y = std::max(boxSize.y, 183.f);
//
//
//        windowFrameCheck = true;
//        windowFrameHeight = boxSize.y;
//
//        super(newBp, yShift, detailedCrew);
//
//        windowFrameCheck = false;
//        descBoxSize.y = boxSize.y;
//    }
//    else
//    {
    super(bp, yShift, detailedCrew);

    Pointf titleSize = freetype::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
    Pointf descSize = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, desc.description.GetText());

    Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
    boxSize.y = std::max(boxSize.y, 183.f);


    windowFrameCheck = true;
    windowFrameHeight = boxSize.y;

    super(bp, yShift, detailedCrew);

    windowFrameCheck = false;
    descBoxSize.y = boxSize.y;
}


HOOK_METHOD(InfoBox, SetBlueprintDrone, (const DroneBlueprint* bp, int status, bool hasDroneSystem, int yShift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintDrone -> Begin (RedesignedTooltips.cpp)\n")
    if (hasDroneSystem && status == 1)
    {
        return super(bp, 2, hasDroneSystem, yShift);
    }

    super(bp, 2, hasDroneSystem, yShift);
}

static bool g_emptyDroneStatText = false;
HOOK_METHOD(TextLibrary, GetText, (const std::string& name, const std::string& lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (RedesignedTooltips.cpp)\n")

    if (g_emptyDroneStatText && (name == "required_power" || name == "drone_required"))
    {
        return "";
    }
    return super(name, lang);
}

HOOK_METHOD(InfoBox, SetBlueprintDrone, (const DroneBlueprint* bp, int status, bool hasDroneSystem, int yShift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintDrone -> Begin (RedesignedTooltips.cpp)\n")
    std::string newDesc;
    if (bp->desc.description.isLiteral)
    {
        newDesc = bp->desc.description.data;
    }
    else
    {
        newDesc = G_->GetTextLibrary()->GetText(bp->desc.description.data);
    }
    std::string currentText = "";

    if(CustomOptionsManager::GetInstance()->redesignedDroneTooltips.currentValue)
    {
        if (!bp->weaponBlueprint.empty() && CustomOptionsManager::GetInstance()->redesignedWeaponTooltips.currentValue)
        {
            auto droneBp = G_->GetBlueprints()->GetWeaponBlueprint(bp->weaponBlueprint);
            auto weaponDef = CustomWeaponManager::instance->GetWeaponDefinition(droneBp->name);
            auto tLib = G_->GetTextLibrary();

            if (bp->typeName == "COMBAT")
            {
                newDesc += GetWeaponStatsString(droneBp, true, bp->power, bp->speed);
            }
            else
            {
                newDesc += "\n\n";
                newDesc += tLib->GetText("description_stats") + "\n";
                currentText = G_->GetTextLibrary()->GetText("required_power");
                newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->power)) + "\n";
                newDesc += G_->GetTextLibrary()->GetText("drone_required") + "\n\n";
                switch (bp->targetType)
                {
                case 1:
                    currentText = tLib->GetText("defense_drone_projectile_target_solid");
                    break;
                case 2:
                    currentText = tLib->GetText("defense_drone_projectile_target_asteroid");
                    break;
                case 3:
                    currentText = tLib->GetText("defense_drone_drone_target_all");
                    break;
                case 4:
                    currentText = tLib->GetText("defense_drone_projectile_target_all");
                    break;
                case 5:
                    currentText = tLib->GetText("defense_drone_drone_target_solid_projectiles");
                    break;
                case 6:
                    currentText = tLib->GetText("defense_drone_drone_target_all_projectiles");
                    break;
                default:
                    currentText = tLib->GetText("defense_drone_projectile_target_unknown");
                }
                newDesc += currentText + "\n";
                currentText = tLib->GetText("defense_drone_reload_speed");
                std::stringstream stream;
                stream << std::fixed << std::setprecision(0) << bp->cooldown * 1000;
                newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";

                stream.str("");
                currentText = tLib->GetText("defense_drone_projectile_speed");
                if (droneBp->speed != 0)
                {
                    stream << std::fixed << std::setprecision(0) << droneBp->speed;
                    newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
                }
                else
                {
                    stream << std::fixed << std::setprecision(0) << 60;
                    newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
                }

                if ((bp->targetType == 3) &&
                    weaponDef->customDamage->droneAccuracyMod != 0)
                {
                    currentText = tLib->GetText("accuracy_modifier");
                    newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(weaponDef->customDamage->droneAccuracyMod)) + "\n";
                }

                stream.str("");
                currentText = tLib->GetText("defense_drone_orbit_speed");
                stream << std::fixed << std::setprecision(0) << bp->speed;
                newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str());
                if (droneBp->type == 4)
                {
                    newDesc += "\n\n";
                    if (weaponDef->angularRadius != -1.f)
                    {
                        stream.str("");
                        currentText = tLib->GetText("shot_radius_angular");
                        stream << std::fixed << std::setprecision(2) << weaponDef->angularRadius;
                        newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", stream.str()) + "\n";
                    }
                    else if (droneBp->radius > 0)
                    {
                        currentText = tLib->GetText("shot_radius");
                        newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(droneBp->radius)) + "\n";
                    }
                    currentText = tLib->GetText("shots");
                    newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(droneBp->miniCount));
                }
            }
        }
        else
        {
            newDesc += "\n\n";
            newDesc += G_->GetTextLibrary()->GetText("description_stats") + "\n";
            currentText = G_->GetTextLibrary()->GetText("required_power");
            newDesc += boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->power)) + "\n";
            newDesc += G_->GetTextLibrary()->GetText("drone_required");
        }

        newDesc += "\n\n";
        currentText = G_->GetTextLibrary()->GetText("scrap_value");
        currentText = boost::algorithm::replace_all_copy(currentText, "\\1", std::to_string(bp->desc.cost));
        newDesc += boost::algorithm::replace_all_copy(currentText, "\\2", std::to_string(bp->desc.cost / 2));

        DroneBlueprint newBp = *bp;
        newBp.desc.description.data.assign(newDesc);
        newBp.desc.description.isLiteral = true;

        g_emptyDroneStatText = true;
        super(&newBp, status, hasDroneSystem, yShift);
        g_emptyDroneStatText = false;

        Pointf titleSize = freetype::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
        Pointf descSize = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, newDesc);

        Pointf boxSize = titleSize + descSize + Pointf(0, 45.f);
        boxSize.y = std::max(boxSize.y, 162.f);

        delete primaryBox;
        primaryBox = new WindowFrame(7, 7, 323, boxSize.y);

        descBoxSize.y = boxSize.y + 14.f;
    }
    else
    {
        super(bp, status, hasDroneSystem, yShift);

        Pointf titleSize = freetype::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
        Pointf descSize = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, desc.description.GetText());

        Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
        boxSize.y = std::max(boxSize.y, 162.f);

        delete primaryBox;
        primaryBox = new WindowFrame(7, 7, 323, boxSize.y);

        descBoxSize.y = boxSize.y + 14.f;
    }
}


// scrolling tooltip

GL_Primitive *ScrollingTooltip::scrollUpArrow = nullptr;
GL_Primitive *ScrollingTooltip::scrollDownArrow = nullptr;
std::string ScrollingTooltip::tooltip = "";
float ScrollingTooltip::scrollAmount = 0.f;
float ScrollingTooltip::maxScroll = 0.f;

bool ScrollingTooltip::OnScrollWheel(float direction)
{
    std::string last_tooltip = G_->GetMouseControl()->lastTooltipText;
    if (last_tooltip.empty() || last_tooltip != tooltip) return false;

    scrollAmount += 50.f * direction;
    scrollAmount = std::max(0.f, std::min(scrollAmount, maxScroll));
    return true;
}

HOOK_METHOD(MouseControl, RenderTooltip, (Point tooltipPoint, bool staticPos) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::RenderTooltip -> Begin (RedesignedTooltips.cpp)\n")
    // Rewrite vanilla code + add some fix + scrolling tooltip

    int width = overrideTooltipWidth < 1 ? (tooltipTitle.empty() ? 275 : 350) : overrideTooltipWidth;
    Point tooltipSize = MeasureTooltip(width);
    float rect_w = tooltipSize.x + 27.f;
    float rect_h = tooltipSize.y + (tooltipTitle.empty() ? 18.f : 23.f);
    if (!staticPos)
    {
        if (iHacking != 0 || iMindControlling != 0)
        {
            tooltipPoint.y += 10;
        }
        if (position.y + rect_h > 670.f)
        {
            tooltipPoint.x += 16;
            tooltipPoint.y -= position.y + rect_h - 670.f;
            if (position.y < tooltipPoint.y + rect_h)
            {
                tooltipPoint.y = std::max(50.f, position.y - rect_h - 10.f); // prevent the top of tooltip from being outside the screen
            }
        }
        if (1260.f < position.x + rect_w)
        {
            tooltipPoint.x -= position.x + rect_w - 1240.f;
        }
    }

    bool scrolling = rect_h > 620.f;
    float rect_visual_h = scrolling ? 670.f - tooltipPoint.y : rect_h;
    CSurface::GL_DrawRect(tooltipPoint.x, tooltipPoint.y, rect_w, rect_visual_h, GL_Color(0.f, 0.f, 0.f, 0.95f));
    CSurface::GL_DrawRectOutline(tooltipPoint.x, tooltipPoint.y, rect_w, rect_visual_h, COLOR_WHITE, 2.f);
    CSurface::GL_SetColor(COLOR_WHITE);
    float text_x = tooltipPoint.x + 15.f;
    float mainText_yOffset = tooltipTitle.empty() ? 0 : freetype::easy_measurePrintLines(13, text_x, tooltipPoint.y + 13, width, tooltipTitle).y + 5.f;
    float scrollAmount = 0.f;
    if (scrolling)
    {
        if (tooltip == ScrollingTooltip::tooltip)
        {
            scrollAmount = ScrollingTooltip::scrollAmount;
        }
        else
        {
            ScrollingTooltip::tooltip = tooltip;
            ScrollingTooltip::scrollAmount = 0.f;
            ScrollingTooltip::maxScroll = rect_h - 580.f;
        }
        
        tooltipPoint.y += 20;
        CSurface::GL_SetStencilMode(STENCIL_SET, 0x80, 0x80);
        CSurface::GL_DrawRect(tooltipPoint.x, tooltipPoint.y, rect_w, rect_visual_h - 40, COLOR_WHITE);
        CSurface::GL_SetStencilMode(STENCIL_USE, 0x80, 0x80);
    }
    if (scrollAmount != 0.f) CSurface::GL_Translate(0.f, -scrollAmount);
    if (!tooltipTitle.empty()) freetype::easy_printAutoNewlines(13, text_x, tooltipPoint.y + 13, width, tooltipTitle);
#ifdef _WIN32
    freetype::easy_printAutoNewlines(tooltipFont, text_x, tooltipPoint.y + 11.f + mainText_yOffset, width, tooltip);
#else
    freetype::easy_printAutoNewlines(G_->GetTextLibrary()->currentLanguage == "ja" ? 12 : 10, text_x, tooltipPoint.y + 11.f + mainText_yOffset, width, tooltip);
#endif // _WIN32
    if (scrollAmount != 0.f) CSurface::GL_Translate(0.f, scrollAmount);
    if (scrolling)
    {
        CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);

        if (!ScrollingTooltip::scrollUpArrow)
        {
            auto tex = G_->GetResources()->GetImageId("statusUI/button_crew_up_on.png");
            ScrollingTooltip::scrollUpArrow = CSurface::GL_CreateImagePrimitive(tex, 0.f, 54.f, tex->width_, tex->height_, 0.f, COLOR_WHITE);
        }
        if (!ScrollingTooltip::scrollDownArrow)
        {
            auto tex = G_->GetResources()->GetImageId("statusUI/button_crew_down_on.png");
            ScrollingTooltip::scrollDownArrow = CSurface::GL_CreateImagePrimitive(tex, 0.f, 652.f, tex->width_, tex->height_, 0.f, COLOR_WHITE);
        }

        CSurface::GL_Translate(tooltipPoint.x + rect_w / 2.f - 6.f, 0.f);
        if (scrollAmount != 0.f)
        {
            CSurface::GL_RenderPrimitive(ScrollingTooltip::scrollUpArrow);
        }
        if (scrollAmount != ScrollingTooltip::maxScroll)
        {
            CSurface::GL_RenderPrimitive(ScrollingTooltip::scrollDownArrow);
        }
        CSurface::GL_Translate(-(tooltipPoint.x + rect_w / 2.f - 6.f), 0.f);
    }
}
