cmake_minimum_required(VERSION 3.16)
project(Hyperspace CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Boost REQUIRED) # From vcpkg
find_package(Lua REQUIRED) # From vcpkg

if(UNIX)
    find_package(SDL2 REQUIRED) # From system
elseif(WIN32)
    find_package(OpenGL REQUIRED)
endif()

# pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# SWIG
find_package(SWIG REQUIRED COMPONENTS lua)
include(UseSWIG)

# Setup SWIG *.i files
set(
    swigfiles
        lua/modules/defines.i
        lua/modules/graphics.i
        lua/modules/hyperspace.i
        lua/modules/rapidxml.i
)
set_property(SOURCE ${swigfiles} PROPERTY USE_TARGET_INCLUDE_DIRECTORIES TRUE)
set_property(SOURCE ${swigfiles} PROPERTY CPLUSPLUS ON)

# Name the binary as Hyperspace.dll instead of libHyperspace.dll
set(CMAKE_SHARED_LIBRARY_PREFIX_CXX "")

swig_add_library(
    Hyperspace
    TYPE SHARED
    LANGUAGE lua
    SOURCES ${swigfiles}
)
target_compile_features(Hyperspace PRIVATE cxx_std_11)
target_include_directories(
    Hyperspace PRIVATE

    ${Boost_INCLUDE_DIRS}
    ${LUA_INCLUDE_DIR}

    # Note: Don't vcpkg-fy rapidxml. It's already more than a decade old and we've customized the code to avoid its bug
    #       that leads to a compilation failure. See https://sourceforge.net/p/rapidxml/bugs/16/ for more info.
    rapidxml

    # Internal directories
    lua
    lua/objects

    # Workaround for SWIG (add source directory itself to the include directory)
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
    Hyperspace PRIVATE
    ${LUA_LIBRARIES}
    Threads::Threads
)

target_sources(
    Hyperspace PRIVATE
    AbilityDrone.cpp
    AbilityDrone.h
    AdditionalWeaponSlots.cpp
    AlternateOxygenRendering.cpp
    AlternateOxygenRendering.h
    ArtilleryBarFix.cpp
    ArtillerySystem.cpp
    AugmentValues.cpp
    Augments.cpp
    Balance.cpp
    Balance.h
    BeamFixes.cpp
    Blueprint_Extend.cpp
    Blueprint_Extend.h
    Colors.cpp
    Colors.h
    CommandConsole.cpp
    CommandConsole.h
    Constants.h
    CooldownNumbers.cpp
    CooldownNumbers.h
    Credits.cpp
    CrewAbilities.cpp
    CrewBox_Extend.cpp
    CrewBox_Extend.h
    CrewManifestVTable.cpp
    CrewMember_Extend.cpp
    CrewMember_Extend.h
    CrewNames.cpp
    CrewNames.h
    CrewSpawn.cpp
    CrewSpawn.h
    CrewVTable.cpp
    CustomAchievements.cpp
    CustomAchievements.h
    CustomAugments.cpp
    CustomAugments.h
    CustomBackgroundObject.cpp
    CustomBackgroundObject.h
    CustomBoss.cpp
    CustomBoss.h
    CustomColors.cpp
    CustomColors.h
    CustomCommandGui.cpp
    CustomCommandGui.h
    CustomCrew.cpp
    CustomCrew.h
    CustomCrewCommon.h
    CustomCrewManifest.cpp
    CustomCrewManifest.h
    CustomCrystalShard.cpp
    CustomCrystalShard.h
    CustomDamage.cpp
    CustomDamage.h
    CustomDrones.cpp
    CustomDrones.h
    CustomEquipment.cpp
    CustomEquipment.h
    CustomEvents.cpp
    CustomEvents.h
    CustomFleetShips.cpp
    CustomFleetShips.h
    CustomHotkeys.cpp
    CustomHotkeys.h
    CustomLocalization.cpp
    CustomLocalization.h
    CustomMap.cpp
    CustomOptions.cpp
    CustomOptions.h
    CustomReactor.cpp
    CustomReactor.h
    CustomRewards.cpp
    CustomRewards.h
    CustomScoreKeeper.cpp
    CustomScoreKeeper.h
    CustomSectors.cpp
    CustomSectors.h
    CustomShipGenerator.cpp
    CustomShipGenerator.h
    CustomShipSelect.cpp
    CustomShipSelect.h
    CustomShips.cpp
    CustomShips.h
    CustomStore.cpp
    CustomStore.h
    CustomStoreBox.cpp
    CustomSuperShield.cpp
    CustomSystems.cpp
    CustomSystems.h
    CustomUpgrades.cpp
    CustomUpgrades.h
    CustomWeapons.cpp
    CustomWeapons.h
    Debugging.cpp
    DroneVTable.cpp
    EnemyShipIcons.cpp
    EnemyShipIcons.h
    EnumClassHash.h
    Equipment_Extend.cpp
    Equipment_Extend.h
    ErosionEffect.cpp
    EventButtons.cpp
    EventButtons.h
    EventTooltip.cpp
    EventTooltip.h
    FTLGame.cpp
    FTLGame.h
    # FTLGameELF32.cpp
    FTLGameELF32.h
    # FTLGameELF64.cpp
    FTLGameELF64.h
    # FTLGameWin32.cpp
    FTLGameWin32.h
    Global.cpp
    Global.h
    HackingSystem.cpp
    HSVersion.h
    HullNumbers.cpp
    HullNumbers.h
    Infinite.cpp
    Infinite.h
    InfiniteTeleport.cpp
    Input.cpp
    MainMenu.cpp
    MainMenu.h
    Misc.cpp
    Misc.h
    MoreInfoButton.cpp
    MoreInfoButton.h
    NeutralTeleporterFix.cpp
    OverclockerSystem.cpp
    OverclockerSystem.h
    PALMemoryProtection.h
    ProjectileVTable.cpp
    Projectile_Extend.cpp
    Projectile_Extend.h
    RedesignedTooltips.cpp
    RedesignedTooltips.h
    RenderReactorBar.cpp
    RenderReactorBar.h
    Renderer.cpp
    Resources.cpp
    Resources.h
    ReturnHacks.cpp
    Room_Extend.cpp
    Room_Extend.h
    SaveFile.cpp
    SaveFile.h
    ScrollingChoiceBox.cpp
    ScrollingChoiceBox.h
    Seeds.cpp
    Seeds.h
    Shaders.cpp
    ShipEditor.cpp
    ShipEditor.h
    ShipManager_Extend.cpp
    ShipManager_Extend.h
    ShipTypeC.cpp
    ShipUnlocks.cpp
    ShipUnlocks.h
    ShipZoom.cpp
    ShipZoom.h
    SigScan.cpp
    SigScan.h
    SpaceId.cpp
    StarMap.cpp
    StatBoost.cpp
    StatBoost.h
    Store_Extend.cpp
    Store_Extend.h
    SystemDescriptionFixes.cpp
    System_Extend.cpp
    System_Extend.h
    Systems.h
    TemporalBoxVTable.cpp
    TemporalSystem.cpp
    TemporalSystem.h
    TemporalSystemVTable.cpp
    TileBasedCrewMovement.cpp
    TileBasedCrewMovement.h
    TimerHelper.cpp
    ToggleValue.h
    TriggeredEvents.cpp
    Wormhole.cpp
    detours.h
    hde.cpp
    hde.h
    main.cpp
    main.h
    palWindowsGeneric.h
    rapidxml_interface.h
    zhl.cpp
    zhl.h
    zhl_internal.h
    zhl_private.h
    lua/InternalEvents.h
    lua/LuaLibScript.h
    lua/LuaScriptInit.cpp
    lua/LuaScriptInit.h
    lua/RenderEvents.h
    lua/linit.c
    lua/luaDefines.h
    lua/luaGlobal.h
    lua/luaInclude.h
    lua/luaLibBase.h

    # Generated by the script
    Version.autogen.hpp
	lua/swigluarun.h
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/lua/swigluarun.h.temp1 ${CMAKE_CURRENT_SOURCE_DIR}/lua/swigluarun.h
	COMMAND swig -c++ -lua -external-runtime lua/swigluarun.h.temp1
	COMMAND bash ./processSwigRuntime.sh
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# TODO: https://stackoverflow.com/a/61814218/3567518
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/Version.autogen.hpp.temp ${CMAKE_CURRENT_SOURCE_DIR}/Version.autogen.hpp
    COMMAND bash ./generateVersion.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(
    Hyperspace PRIVATE

    # Enable SSE2
    -msse -msse2 -mfpmath=sse

    # Error on narrowing conversion
    -Werror=narrowing

    # Explicit C++11 mode
    -std=c++11

    # Warn everything
    # TODO: Check if it's meaningful (original .cbp defined it)
    # -Wall
)

target_compile_definitions(Hyperspace PRIVATE _REENTRANT)
if(UNIX)
    # SDL2
    target_include_directories(Hyperspace PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(Hyperspace PRIVATE ${SDL2_LIBRARIES})

    # Disable Discord integration by default
    set(USE_DISCORD_DEFAULT OFF)

    # Naming the binary
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(name_suffix "amd64")
    else()
        set(name_suffix "x86")
    endif()

    if(STEAM_1_6_13_BUILD)
        target_compile_definitions(Hyperspace PRIVATE STEAM_1_6_13_BUILD)
        set_target_properties(Hyperspace PROPERTIES OUTPUT_NAME "Hyperspace.1.6.13.${name_suffix}")
    else()
        set_target_properties(Hyperspace PROPERTIES OUTPUT_NAME "Hyperspace.1.6.12.${name_suffix}")
    endif()
elseif(WIN32)
    # Enable the Discord integration on Windows by default
    set(USE_DISCORD_DEFAULT ON)

    # OpenGL, just raw OpenGL goodness
    target_link_libraries(Hyperspace PRIVATE OpenGL::GL)

    target_compile_definitions(Hyperspace PRIVATE BUILD_DLL)
endif()

option(USE_DISCORD "Enable the Discord Rich Presence integration" ${USE_DISCORD_DEFAULT})

if(USE_DISCORD)
    find_package(DiscordRpc REQUIRED) # From vcpkg & our custom find module

    target_sources(Hyperspace PRIVATE DiscordIntegration.h DiscordIntegration.cpp)
    target_compile_definitions(Hyperspace PRIVATE USE_DISCORD)
    target_link_libraries(Hyperspace PRIVATE DiscordRpc::DiscordRpc)
endif()
