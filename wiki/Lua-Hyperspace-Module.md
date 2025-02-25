## Available calls

All calls are under `Hyperspace`

-----
- `:Name` indicates it is a member method and must be called with the colon, for example `Hyperspace.ships.player:GetRandomRoomCenter()`
- `.Name` indicates it is a static method or field value and must be called with the period, for example `Hyperspace.ships.enemy.shipId`
-----

- `.ships.player` (See [`ShipManager`](#shipmanager) below)
- `.ships.enemy` (See [`ShipManager`](#shipmanager) below)

## Templates
Templates cannot be instantiated from the lua side. Specific instantiations of templates are treated as individual classes with similar usage, and are defined in [hyperspace.i](../lua/modules/hyperspace.i#L114) in the form `%template(template_name) template<parameters>`. Static methods of a template are accessed via `Hyperspace.template_name`

---

### std::vector\<T\>

### Methods
#### Constructor overloads
To construct a vector named `template_name`:
```lua
local instance = Hyperspace.template_name(args)
```
- `std::vector<T>` `constructor()`

Constructs a `std::vector<T>` of size 0.
- `std::vector<T>` `constructor(unsigned int size)`

Constructs a `std::vector<T>` with a size given by `size`. Elements are default-constructed.
- `std::vector<T>` `constructor(std::vector<T> other)`

Makes a copy of `other`.

- `std::vector<T>` `constructor(unsigned int size, T value)`

Constructs a vector of size `size` where each element is equal to `value`.

#### Member methods
- `T :back()`

Accesses the last element of the vector. 

WARNING: Undefined behavior (crash) if used on an empty vector!
- `void :clear()`

Empties the vector and sets its size to 0.

- `bool :empty()` 

Returns a boolean indicating if the vector is empty.

- `T :front()`

Accesses the first element of the vector. 

WARNING: Undefined behavior (crash) if used on an empty vector!

- `unsigned int :max_size()`

The maximum size of the vector.
- `void :pop_back()`

Removes an element from the end and decreases the vector's size by 1.

- `void :push_back(T elem)`

Adds `elem` to the vector and increases its size by 1.

- `unsigned int :size()`

The size of the vector.

- `T& operator[](unsigned int index)`

Access the element at position `index`.

NOTE: C vectors are 0-indexed, while lua tables are 1-indexed.

## Global

### Methods
- `Global .GetInstance()`
   - Returns the main instance of [`Global`](#Global). Always use this to access any members and methods belonging to this class. `Hyperspace.Global.GetInstance()`
- `ShipManager :GetShipManager(int iShipId)`
   - Returns the instance of [`ShipManager`](#ShipManager) associated with the given ID (can be 0 or 1). If a ship does not exist for the given ID, returns `nil`.
- `CApp :GetCApp()` 
   - Returns the main instance of [`CApp`](#CApp). Always use this to access any members and methods belonging to the [`CApp`](#CApp) class, or the shortcut `Hyperspace.App`.
- `ShipInfo :GetShipInfo(bool enemy)`
   - Returns [`ShipInfo`](#ShipInfo) for the player ship if `enemy` is `false`, or for the enemy ship if `enemy` is `true`.
- `BlueprintManager :GetBlueprints()`
   - Returns the main instance of [`BlueprintManager`](#BlueprintManager). Always use this to access any members and methods belonging to the [`BlueprintManager`](#BlueprintManager) class, or the shortcut `Hyperspace.Blueprints`.
- `SoundControl :GetSoundControl()`
   - Returns the main instance of [`SoundControl`](#SoundControl). Always use this to access any members and methods belonging to the [`SoundControl`](#SoundControl) class, or the shortcut `Hyperspace.Sounds`.
- `AnimationControl :GetAnimationControl()`
   - Returns the main instance of [`AnimationControl`](#AnimationControl). Always use this to access any members and methods belonging to the [`AnimationControl`](#AnimationControl) class, or the shortcut `Hyperspace.Animations`.
- `ScoreKeeper :GetScoreKeeper()`
   - Returns the main instance of [`ScoreKeeper`](#ScoreKeeper). Always use this to access any members and methods belonging to the [`ScoreKeeper`](#ScoreKeeper) class, or the shortcut `Hyperspace.Score`.
- `CrewMemberFactory :GetCrewFactory()`
   - Returns the main instance of [`CrewMemberFactory`](#CrewMemberFactory). Always use this to access any members and methods belonging to the [`CrewMemberFactory`](#CrewMemberFactory) class, or the shortcut `Hyperspace.CrewFactory`.
- `TutorialManager :GetTutorialManager()`
   - Returns the main instance of [`TutorialManager`](#TutorialManager). Always use this to access any members and methods belonging to the [`TutorialManager`](#TutorialManager) class, or the shortcut `Hyperspace.Tutorial`.
- `MouseControl :GetMouseControl()`
   - Returns the main instance of [`MouseControl`](#MouseControl). Always use this to access any members and methods belonging to the [`MouseControl`](#MouseControl) class, or the shortcut `Hyperspace.Mouse`.
- `TextLibrary :GetTextLibrary()`
   - Returns the main instance of [`TextLibrary`](#TextLibrary). Always use this to access any members and methods belonging to the [`TextLibrary`](#TextLibrary) class, or the shortcut `Hyperspace.Text`.
- `EventGenerator :GetEventGenerator()`
   - Returns the main instance of [`EventGenerator`](#EventGenerator). Always use this to access any members and methods belonging to the [`EventGenerator`](#EventGenerator) class, or the shortcut `Hyperspace.Event`.

### Fields
- `int` `.currentSeed`
   - **Read-only**
   - The seed for the run.

## CApp

### Methods

- `void :OnExit()`
   - Close game, autosave profile and settings but not current run (current run will be on previous autosave).
- `void :OnRequestExit()`
   - Close game, autosave run, profile, and settings.

### Fields

- [`CommandGui`](#CommandGui) `.gui`
- [`WorldManager`](#WorldManager) `.world`
- `MainMenu` `.menu`
   - **Read-only**

## EventGenerator

### Methods

- [`LocationEvent`](#LocationEvent) `CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique)`
- [`LocationEvent`](#LocationEvent) `GetBaseEvent(const std::string &name, int worldLevel, bool ignoreUnique, int seed)`

## ShipInfo

### Fields

- `std::map<std::string, int>` `.augList`

## WorldManager

### Methods

- `bool :AddBoarders(BoardingEvent boardingEvent)`
- `void :ClearLocation()`

`SwitchShip` and `SwitchShipTransfer` cause a crash on Linux. They will be exposed once the root cause is identified and the crash is fixed.
- ~~`bool :SwitchShip(std::string shipName)`~~
   - This method will change the player ship to the one specified by `shipName`, default hangar equipments for the ship are applied
   - This method will run `:ClearLocation()` at the beacon, effectively removing any hazard and ship
- ~~`bool :SwitchShipTransfer(std::string shipName, int overrideSystem)`~~
   - This method will change the player ship to the one specified by `shipName`, crew/systems/weapons/drones/augments will be transfered to the new ship
   - This method will run `:ClearLocation()` at the beacon, effectively removing any hazard and ship
   - `overrideSystem`: 
      - 0: keep systems & power from the old ship, adding them to the new ship systems
      - 1: keep systems & power from the old ship, replacing the new ship systems
      - 2: No transfer of systems & power to the new ship, diclaimer: if the new ship does not contain a drone/weapon system, weapon/drone will be moved to cargo
	
### Fields

- `SpaceManager` `.space`
   - **Read-only**
- `int` `.currentDifficulty`
   - **Read-only**
- [`StarMap`](#StarMap) `.starMap`
   - **Read-only**
- `bool` `.bStartedGame`
   - **Read-only**
- `bool` `.bLoadingGame`
   - **Read-only**

## SpaceManager

### Methods

- [`LaserBlast`](#LaserBlast) `:CreateLaserBlast(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)`
- [`Asteroid`](#Asteroid) `:CreateAsteroid(Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)`
- [`Missile`](#Missile) `:CreateMissile(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)`
- [`BombProjectile`](#BombProjectile) `:CreateBomb(WeaponBlueprint *weapon, int ownerId, Pointf target, int targetSpace)`
- [`BeamWeapon`](#BeamWeapon) `:CreateBeam(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target1, Pointf target2, int targetSpace, int length, float heading)`
- [`LaserBlast`](#LaserBlast) `:CreateBurstProjectile(WeaponBlueprint *weapon, std::string image, bool fake, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)`
- [`PDSFire`](#PDSFire) `:CreatePDSFire(WeaponBlueprint *weapon, Point position, Pointf target, int targetSpace, bool smoke)`
#
- `bool :DangerousEnvironment()`
- [`ImageDesc`](#ImageDesc) `:SwitchBackground(std::string name)`
- [`ImageDesc`](#ImageDesc) `:SwitchPlanet(std::string name)`
- `void :UpdatePlanetImage()`
- `void :UpdateProjectile(Projectile *proj)`
	
### Fields

- [`Projectile*[]`](#Projectile) `.projectiles`
   - **Read-only**
- [`SpaceDrone*[]`](#SpaceDrone) `.drones`
   - **Read-only**
- [`GL_Texture`](#GL_Texture) `.currentBack`
- `bool` `.gamePaused`
   - **Read-only**
   # 
   ### Hazards

   - [`AsteroidGenerator`](#AsteroidGenerator) `.asteroidGenerator`
      - `.asteroidGenerator.bRunning` will indicate if the current space has an asteroid hazard, similar to the variables below
      - **Read-only**
   - `bool` `.sunLevel`
      - **Read-only**
   - `bool` `.pulsarLevel`
      - **Read-only**
   - `bool` `.bPDS`
      - **Read-only**
   - `int` `.envTarget`
      - Dictate the current target of the PDS (0: player, 1: enemy, 2: both)
   - `bool` `.bNebula`
      - **Read-only**
   - `bool` `.bStorm`
      - **Read-only**

## WindowFrame

### Static methods

- `Hyperspace.WindowFrame(int x, int y, int w, int h)` Constructor

### Methods

- `void` `:Draw(int x, int y)`
- `void` `:DrawMask(int stencilBits)`

### Fields

- [`Globals::Rect`](#Globals) `.rect`
- [`GL_Primitive*`](#GL_Primitive) `.outline`
- [`GL_Primitive*`](#GL_Primitive) `.mask`
- [`GL_Primitive*`](#GL_Primitive) `.pattern`

## AsteroidGenerator
	
### Fields

- `bool` `.bRunning`
   - **Read-only**

## MouseControl

### Methods

- `void :InstantTooltip()`
- `Point :MeasureTooltip(int width)`
- `void :OnLoop()`
- `void :OnRender()`
- `void :QueueStaticTooltip(Point pos)`
- `void :RenderTooltip(Point tooltipPoint, bool staticPos)`
- `void :Reset()`
- `void :ResetArmed()`
- `void :SetDoor(int state)`
- `void :SetTooltip(std::string tooltip)`
- `void :SetTooltipTitle(std::string tooltip)`
	
### Fields

- [`Point`](#Point) `.position`
- [`Point`](#Point) `.lastPosition`
- `int` `.aiming_required`
- `int` `.iTeleporting`
- `int` `.iMindControlling`
- `bool` `.bSellingStuff`
- `bool` `.valid`
- `bool` `.newHover`
- `bool` `.lastValid`
- `int` `.animateDoor`
- [`GL_Texture*`](#GL_Texture) `.validPointer`
- [`GL_Texture*`](#GL_Texture) `.invalidPointer`
- [`GL_Texture*`](#GL_Texture) `.selling`
- `Animation` `.openDoor`
- `std::string` `.tooltip`
- `float` `.tooltipTimer`
- `bool` `.bMoving`
- `bool` `.bHideMouse`
- [`GL_Texture*`](#GL_Texture) `.lastIcon`
- [`GL_Texture*`](#GL_Texture) `.lastAddition`
- `bool` `.bForceTooltip`
- `std::string` `.tooltipTitle`
- `std::string` `.lastTooltipText`
- `int` `.iHacking`
- `int` `.overrideTooltipWidth`
- [`Point`](#Point) `.staticTooltip`



## PrintHelper
The members held by this class determine how the `print` function displays messages.

### Methods
- `PrintHelper .GetInstance()`
   - Returns the main instance of `PrintHelper`. Always use this to access any members belonging to this class.

### Fields
- `int` `.x`
   - The x coordinate of messages. Default is 100.
- `int` `.y`
   - The y coordinate of messages. Default is 100.
- `int` `.font`
   - The size of the font used. Default is 10.
- `int` `.lineLength`
   - Width (in pixels) before automatic newline. Default is 400.
- `int` `.messageLimit`
   - How many messages may be displayed at once. Default is 10.
- `int` `.duration`
   - How long (in seconds) each message lasts. Default is 5.
- `bool` `.useSpeed`
   - Whether the speed at which messages are cleared scales with game speed. Default is `false`.

## ShipObject

### Methods
- `void :AddAugmentation(string augmentName)`
   - Adds the specified augment to the ship. Works properly with hidden augments.
- `void :RemoveAugmentation(string augmentName)`
   - Removes the specified augment from the ship. Does nothing if the augment isn't present. Works properly with hidden augments.
- `void :ClearShipInfo()`
- `int :GetAugmentationCount()`
   - Returns the number of augments on the ship.
- `string[] :GetAugmentationList()`
   - Returns a `std::vector<std::string>` of augments, in Lua you can handle this as if it was an array of strings.
- `float :GetAugmentationValue(string augmentName)`
   - Returns the value of the augment, this corresponds to the value defined in blueprints.xml. If the ship has multiple, their values are added together.
- `int :HasAugmentation(string augmentName)`
   - Returns the number of the given augment you have, NOT a bool.
- ~~`void :AddEquipment(string equipmentName)`~~
- ~~`void :RemoveEquipment(string equipmentName, bool completely)`~~
- `bool :HasEquipment(string equipmentName)`
   - Returns a bool indicating whether you have the blue options for the specified equipment.

## ShipManager

**Extends [ShipObject](#Shipobject)**

As ShipManager extends ShipObject, the methods of ShipObject can be called from ShipManager.

### Methods
- `Pointf :GetRandomRoomCenter()`
   - Chooses a random room on the ship and returns the center point of that room
- `Pointf :GetRoomCenter(int roomId)`
   - Gets the room center point of a specific room id.
- `std::pair<int, int> :GetAvailablePower()`
   - First element of the pair is the maximum reactor power, the second element is the available reactor power.
- `CrewMember* :AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder)`
- `CrewMember* :AddCrewMemberFromString(std::string name, std::string race, bool intruder, int roomId, bool init, bool male)`
- ~~`:AddDrone`~~
- ~~`:AddEquipmentFromList`~~
- ~~`:AddInitialCrew`~~
- `int :AddSystem(int systemId)`
- ~~`int :AddWeapon(WeaponBlueprint weapon, int slot)`~~
- `bool :CanFitSubsystem(int systemId)`
- `bool :CanFitSystem(int systemId)`
- `int :CanUpgrade(int systemId, int amount)`
- `void :ClearStatusAll()`
- `void :ClearStatusSystem(int system)`
- ~~`CollisionResponse :CollisionMoving(Pointf start, Pointf finish, DamageParameter damage, bool raytrace)`~~ (Not yet available, CollisionResponse is not exposed yet)
- ~~`bool :CommandCrewMoveRoom(CrewMember *crew, int roomId)`~~
- `int :CountCrew(bool boarders)`
   - return count of crew on this ship, true for boarders false for regular crewmembers.
- `int :CountCrewShipId(int roomId, int shipId)`
   - Counts crew in a room. shipId corresponds to which ship owns the crewmembers, 0 being the player and 1 being the enemy.
- ~~`CrewDrone* :CreateCrewDrone(DroneBlueprint *bp)`~~ Use Events
- `SpaceDrone* :CreateSpaceDrone(DroneBlueprint *bp)`
- `bool :DamageArea(Pointf location, DamageParameter dmg, bool force)`
   - I think this causes damage to a area like when a projectile hits but it's not tested yet, could possibly be used for bursts?
   - `force` ignores room resistances.
- `bool :DamageBeam(Pointf location1, Pointf location2, DamageParameter dmg)`
   - I think this cuts a beam across the ship but not sure if it renders a beam or not, could possibly be used for bursts?
###### Example
```lua
local damage = Hyperspace.Damage()
damage.iDamage = 1
Hyperspace.ships.player:DamageBeam(Hyperspace.ships.player:GetRandomRoomCenter(), Hyperspace.ships.player:GetRandomRoomCenter(), damage)
```
- ~~`bool :DamageCrew(CrewMember *crew, DamageParameter dmg)`~~
- `int :DamageHull(int amount, bool force)`
   - It directly damages the hull? What's more to say, I think negative numbers heal the hull. Could be cool for some random lifesaving or lifetaking mechanics that run mid-battle instead of during an event. Imagine if you could dump all power into hull integrity or something and lose 10% power for the rest of the fight but gain 10% hull, could be fun!
   - `force` ignores whether or not the ship is jumping. If it is false and the ship is jumping, the damage will not be applied.
- `void :DamageSystem(int systemId, DamageParameter damage)`
- `bool :DoSensorsProvide(int vision)`
   - `vision` is the sensor level.
- `bool :DoorsFunction()`
   - Do the doors work or not
- ~~`CrewMember* :FindCrew(CrewBlueprint *bp)`~~ Not currently available, might choose never to make available because it might be better to lookup crew by name or something rather than their full CrewBlueprint
- `bool :ForceDecreaseSystemPower(int systemId)`
- `CrewMember* :GetCrewmember(int slot, bool present)`
- `int :GetDodgeFactor()`
- `bool :GetDodged()`
   - Calculates whether a projectile should be dodged or not.
   - Note: 5 calls of this method that return false while the player has fully upgraded, fully powered engines will unlock the achievement 'Astronomically Low Odds'.
- `int :GetDroneCount()`
   - Returns the number of drone parts the ship has.
- [`Drone*[]`](#drone) `:GetDroneList()`
   - Returns the list of Drones for this ship, the `std::vector` it returns can be accessed like an array in Lua
- `int :GetFireCount(int roomId)` Get number of fires in a room, could be quite useful for computing damage of multiple fires
- ~~`std::vector<CrewMember*> :GetLeavingCrew(bool intruders)`~~
- `int :GetOxygenPercentage()` Ship's overall oxygen percentage (not per-room)
- `CrewMember* :GetSelectedCrewPoint(int x, int y, bool intruder)`
- `ShieldPower :GetShieldPower()`
- [`ShipSystem*`](#shipsystem) `:GetSystem(int systemId)`
   - You can also just access the system directly with fields below if it's one of the vanilla systems like `oxygenSystem` `medbaySystem` etc... but custom systems like Temporal currently need to be accessed by id.
- [`ShipSystem*`](#shipsystem) `:GetSystemInRoom(int roomId)`
   - Returns the system in a specific room id. If there is no system in the room, returns 0.
- `int :GetSystemPower(int systemId)`
   - How much power is assigned to this system
- `int :GetSystemPowerMax(int systemId)`
   - What is the max power level of this system, functionally this is the same as the system's "level"
- `int :GetSystemRoom(int systemId)`
   - Find what roomId a system is in, could be useful for AI targeting mechanics or some cheesy player weapon that can only attack one system or something.
- `string :GetTooltip(int x, int y)`
- `ProjectileFactory*[] :GetWeaponList()`
   - Return a vector of weapons on this ship, can be treated like an array in Lua.
- `bool :HasSystem(int systemId)`
   - Does the ship have a specific system, true/false
- `void :InstantPowerShields()`
- `bool :IsCrewFull()`
- `bool :IsCrewOverFull()`
- `int :IsSystemHacked(int systemId)`
   - Returns the "hacking level" of the system. 0 means there is no hacking drone on the system, 1 means there is a hacking drone attached but is not currently being hacked, 2 means there is a hacking drone and the system is being hacked.
- `void :ModifyDroneCount(int drones)`
- `void :ModifyMissileCount(int missiles)`
- `void :ModifyScrapCount(int scrap, bool income)`
   - `income` determines whether or not augments should be activated (e.g. Scrap Recovery Arm and Repair Arm).
- `void :PrepareSuperBarrage()`
   - I do not know if this is safe to call
- `void :PrepareSuperDrones()`
   - I do not know if this is safe to call
- `void :RemoveItem(string name)`
   - Remove an item by name (equivalent to removing via an event).
- `void :ResetScrapLevel()`
- `bool :RestoreCrewPositions()`
   - Same as hitting the button to return crew to their original positions.
- `CrewBlueprint :SelectRandomCrew(int seed, string racePreference)`
   - Select random crew from the ship *for ~~execution~~ selection of your diabolical plans*.
   - Not sure why there is a seed option, not sure if you should give it a fixed number or call `Hyperspace.random32()` for a nice random number.
- `void :SetDestroyed()`
   - *Blow up the damn ship Jean-Luc!*
- `void :SetSystemPowerLoss(int systemId, int powerLoss)`
   - Sets a power loss level, like from an event except can be done at any time regardless of an event.
- `void :StartFire(int roomId)`
   - Yeah, it does *exactly what you think it does* [you monster](https://gfycat.com/complexcarefulant).
- `bool :SystemFunctions(int systemId)`
   - Returns whether the system has any power assigned to it.
- `CrewMember*[] :TeleportCrew(int roomId, bool intruders)`
   - Teleport crew & get back the list of CrewMembers.
   - I think there might be something more you need to do to give them a destination so they don't simply get teleport-ed to space, *unless you know... that was the intention*.

### Fields
- [`Targetable`](#targetable) `._targetable`
   - **Read-only**
- `int` `.iShipId`
   - **Read-only**
   - The ship's ID (0 is player, 1 is enemy)
- [`ShipSystem*[]`](#shipsystem) `.vSystemList`
   - **Read-only** currently, however we might need to explore if this would be a safe way to remove a system
   - Fields under this object may still be mutable (see their docs).
   - Holds a vector (array in lua) of ship systems that you can iterate over
- [`OxygenSystem*`](#oxygensystem) `.oxygenSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`TeleportSystem*`](#teleportsystem) `.teleportSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`CloakingSystem*`](#cloakingsystem) `.cloakSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`BatterySystem*`](#batterysystem) `.batterySystem` Backup Battery System
   - Field is **read-only** but fields under this object may still be mutable.
- [`MindSystem*`](#mindsystem) `.mindSystem` Mind Control System
   - Field is **read-only** but fields under this object may still be mutable.
- [`CloneSystem*`](#clonesystem) `.cloneSystem` Clonebay System
   - **Note:** shares system with Medbay system and both cannot exist at the same time
   - Field is **read-only** but fields under this object may still be mutable.
- [`HackingSystem*`](#hackingsystem) `.hackingSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`Shields*`](#shields) `.shieldSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`WeaponSystem*`](#weaponsystem) `.weaponSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`DroneSystem*`](#dronesystem) `.droneSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`EngineSystem*`](#enginesystem) `.engineSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`MedbaySystem*`](#medbaysystem) `.medbaySystem`
   - **Note:** shares system with Clonebay system and both cannot exist at the same time
   - Field is **read-only** but fields under this object may still be mutable.
- [`ArtillerySystem*[]`](#artillerysystem) `.artillerySystems`
   - Array (vector) of artillery systems on this ship, you will need to check for length
   - **Note:** Unlike Lua arrays, because this is a C vector internally it will start at index `0` not index `1` so `.artillerySystems[0]` is the first artillery system.
   - Field is **read-only** but fields under this object may still be mutable.
- ~~`bool` `.showNetwork`~~
   - No clue what this does
- ~~`bool` `.addedSystem`~~
   - No clue what this does
- [`CrewMember*[]`](#crewmember) `.vCrewList`
   - Array (vector) of crew members on this ship
   - **Note:** Vectors are 0 indexed unlike lua's normal arrays
   - Field is **read-only** but fields under this object may still be mutable.
- ~~`Spreader_Fire` `.fireSpreader`~~
- `Ship` `.ship`
   - Field is **read-only** but fields under this object may still be mutable.
- ~~`char` `.statusMessages[80]`~~
- ~~`bool` `.bGameOver`~~
- ~~`ShipManager*` `.current_target`~~ Just use `Hyperspace.ships.enemy` or `Hyperspace.ships.player` depending on the ship you're currently looking at instead.
- `std::pair<float, float>` `.jump_timer`
   - **read-only** (not sure if it's safe to make this editable)
- `int` `.fuel_count`
   - Unlike other resources, fuel is mutable and should be modified directly instead of with a modify method
- ~~`bool` `.hostile_ship`~~
- `bool` `.bDestroyed`
   - **Since 1.4.0**
- `int` `.iLastDamage`
   - **read-only** (not sure if it's safe to make this editable)
- ~~`AnimationTracker` `.jumpAnimation`~~
- ~~`DamageMessage*[]` `.damMessages`~~
   - Is a vector, indexed at 0.
- ~~`int[]` `.systemKey`~~
- `int` `.currentScrap`
   - **read-only** use the modify method if you really want to change this
- `bool` `.bJumping`
   - **read-only**
- `bool` `.bAutomated`
   - **read-only**
- `int` `.shipLevel`
   - **read-only**
- `ShipBlueprint` `.myBlueprint`
   - **read-only**
- `bool` `.lastEngineStatus`
   - **read-only**
- `bool` `.lastJumpReady`
   - **read-only**
- `bool` `.bContainsPlayerCrew`
   - **read-only**
- `int` `.iIntruderCount`
   - **read-only**
- `int[][]` `.crewCounts`
   - Note: Double vector, both indices start at 0
   - Field is **read-only** but fields under this object may still be mutable.
- `int` `.tempDroneCount`
   - **read-only**
- `int` `.tempMissileCount`
   - **read-only**
- ~~`Animation[]` `.explosions`~~
- `bool[]` `.tempVision`
   - **read-only**
   - Note: Vectors start at index 0, unlike normal arrays in Lua
- ~~[`Drone*[]`](#drone) `.droneTrash`~~
- ~~`SpaceDrone*[]` `.spaceDrones`~~
- ~~`SpaceDrone*[]` `.newDroneArrivals`~~
- ~~`int` `.bpCount`~~
- `int` `.iCustomizeMode`
   - **read-only**
   - 2 while in the hangar, 0 while in a run
- `bool` `.bShowRoom`
- `Projectile*[]` `.superBarrage`
   - Note: Vectors start at index 0, unlike normal arrays in Lua
- `bool` `.bInvincible`
- `SpaceDrone*[]` `.superDrones`
   - Note: Vectors start at index 0, unlike normal arrays in Lua
- ~~`GL_Primitive*` `.highlight`~~
- `int` `.failedDodgeCounter`
- ~~`float[]` `.hitByBeam`~~
- `bool` `.enemyDamagedUncloaked`
- `int` `.damageCloaked`
- ~~`std::map<int, int>` `.killedByBeam`~~
- ~~`int` `.minBeaconHealth`~~
- ~~`ParticleEmitter*[]` `.fireExtinguishers`~~
- ~~`bool` `.bWasSafe`~~
- `ShipManager_Extend` `.extend`
  - **Since 1.4.0**
- LUA table `.table`
  - **Since 1.4.0**
  - A modifiable table of arbitrary data which exists as long as the object it belongs to

## ShipManager_Extend
Accessed via `ShipManager`'s `.extend` field

## Targetable

### Methods
- `Pointf :GetWorldCenterPoint()`
- `Pointf :GetRandomTargettingPoint(bool unk)`
- `std::vector<Pointf> :GetAllTargettingPoints()`
- [`Ellipse`](#Ellipse) `:GetShieldShape()`
- `ShieldPower :GetShieldPower()`
- `int :GetSpaceId()`
- `Pointf :GetSpeed()`
- `int :GetOwnerId()`
- `int :GetSelfId()`
- `bool :IsCloaked()`
- `void :DamageTarget(Pointf pos, DamageParameter damage)`
- `bool :GetIsDying()`
- `bool :GetIsJumping()`
- `bool :ValidTarget()`
- [`Rect`](#Rect) `:GetShape()`

### Fields
- `int` `.type`
- `bool` `.hostile`
- `bool` `.targeted`

## Slot

### Fields
- `int` `.roomId`
   - **Read-only**
- `int` `.slotId`
   - **Read-only**
- [`Point`](#Point) `.worldLocation`
   - Field is **read-only** but fields under this object may still be mutable.

## Ship

**Extends [ShipObject](#Shipobject)**

### Methods
-  [`std::vector<LockdownShard*>`](#LockdownShard) `:GetShards()`
-  `bool :BreachRandomHull(int roomId)`
   -  Breaches a random tile in the room with `roomId` as its id. This can select an already breached tile, in which case nothing will happen.
-  `bool :BreachSpecificHull(int grid_x, int grid_y)`
   -  Breaches a tile at the specified grid coordinates.
-  `int :EmptySlots(int roomId)`
   -  Returns the number of tiles within the room (Equivalent to the area of the room). I think this marks all tiles in the room as empty, so you can use this to fit more crew than you should in a given room.
-  `bool :FullRoom(int roomId, bool intruder)`
   -  Returns true if the room cannot fit any more crew of the allegiance specifies by the `intruder` arg. If `intruder` is false, counts player crew when on the player ship, and enemy crew when on the enemy ship. If `intruder` is true, counts enemy crew when on the player ship, and player crew when on the enemy ship.
-  `int :GetAvailableRoomSlot(int roomId, bool intruder)`
-  [`Ellipse`](#Ellipse) `:GetBaseEllipse()`
   -  Return `baseEllipse` member by value.
- `std::vector<Repairable*> :GetHullBreaches(bool onlyDamaged)`
- `int GetSelectedRoomId(int x, int y, bool bIncludeWalls)`
   -  Returns the id of the room at the selected point, or -1 if no valid room would be selected at that point. bIncludeWalls specifies that walls count as part of the room.
-  `void LockdownRoom(int roomId, Pointf pos)` 
   -  Locks down the room, and spawns the crystal animation at `pos`. Does not play the lockdown sound. Note: For a "normal" animation, `pos` can be set to the room's center, but it can be set outside of the room as well.
-  `bool RoomLocked(int roomId)`
   -  Returns true if the room is locked down.
-  `void SetRoomBlackout(int roomId, bool blackout)`
   -  When `blackout` is true, hide the room's interior (As if sensors were disabled). When it is false, show the room's interior. Note: This must be done every tick to have an effect.
-  `void SetSelectedRoom(int roomId)`
   -  Sets the room to be selected (Yellow outline). Note: Must be done every tick to have an effect.

### Fields
-  `int` `.iShipId` 
-  `std::vector<Room*>` `.vRoomList`
-  `std::vector<Door*>` `.vDoorList`
-  [`std::vector<OuterHull*>`](#OuterHull) `.vOuterWalls`
-  [`std::vector<OuterHull*>`](#OuterHull) `.vOuterWalls`
-  `std::vector<Door*>` `.vOuterAirlocks`
-  `std::pair<int, int>` `.hullIntegrity`
-  `std::vector<WeaponMount>` `.weaponMounts`
-  `std::string` `.floorImageName`
-  [`ImageDesc`](#ImageDesc) `.shipFloor`
-  [`GL_Primitive*`](#GL_Primitive) `.floorPrimitive`
-  `std::string` `.shipImageName`
-  [`ImageDesc`](#ImageDesc) `.shipImage`
-  [`Point`](#Point) `.glowOffset`
-  [`GL_Primitive*`](#GL_Primitive) `.shipImagePrimitive`
-  `std::string` `.cloakImageName`
-  [`ImageDesc`](#ImageDesc) `.shipImageCloak`
-  [`GL_Primitive*`](#GL_Primitive) `.cloakPrimitive`
-  [`GL_Primitive*`](#GL_Primitive) `.gridPrimitive`
-  [`GL_Primitive*`](#GL_Primitive) `.wallsPrimitive`
-  [`GL_Primitive*`](#GL_Primitive) `.doorsPrimitive`
-  `std::vector<DoorState>` `.doorState`
-  `bool` `.lastDoorControlMode`
-  [`GL_Texture*`](#GL_Texture) `.thrustersImage`
-  [`GL_Texture*`](#GL_Texture) `.jumpGlare`
-  `int` `.vertical_shift`
-  `int` `.horizontal_shift`
-  `std::string` `.shipName`
-  ~~`ExplosionAnimation` `.explosion`~~
-  `bool` `.bDestroyed`
-  [`Ellipse`](#Ellipse) `.baseEllipse`
-  `Animation[2]` `.engineAnim`
-  `AnimationTracker` `.cloakingTracker`
-  `bool` `.bCloaked`
-  `bool` `.bExperiment`
-  `bool` `.bShowEngines`
-  [`std::vector<LockdownShard>`](#LockdownShard) `.lockdowns`
   - Does not give a pointer to the LockdownShard, so any changes to the LockdownShard will not be reflected. Use GetShards() instead.

### Hyperspace Fields
-  `std::vector<std::pair<Animation, int8_t>>` 
`extraEngineAnim`
   -  Engine animations defined in Hyperspace for the ship. The first member of the pair is the animation. The second member of the pair is an integer indicating rotation of the animation. 
   
   |Value | Rotation                     |
   | ---: | :--------------------------- |
   | -1   | 90 Degrees Clockwise         |
   |  0   | No Rotation                  |
   |  1   | 90 Degrees Counterclockwise  |

   Note: Pairs are returned by value, and not by reference.

## LockdownShard

### Methods
- `void` `:Update()`

### Fields
- [`Animation`](#Animation) `.shard`
- [`Pointf`](#Pointf) `.position`
- [`Pointf`](#Pointf) `.goal`
- `float` `.speed`
- `bool` `.bArrived`
- `bool` `.bDone`
- `float` `.lifeTime`
- `bool` `.superFreeze`
- `int` `.lockingRoom`

## ShipSystem

### Static methods
These are called either under `Hyperspace.ShipSystem` or an existing object (for example you could call `Hyperspace.ShipSystem.GetLevelDescription()` or `Hyperspace.ships.player.oxygenSystem.GetLevelDescription()`) with the same effect (although constructors probably don't make any sense to call in the second manner)
- `Hyperspace.ShipSystem.ShipSystem()` Default Constructor
- ~~`Hyperspace.ShipSystem.ShipSystem(int systemId, int roomId, int shipId, int startingPower)` Constructor~~
- `string .GetLevelDescription(int systemId, int level, bool tooltip)`
- `bool .IsSubsystem(int systemType)`
- `int .NameToSystemId(string name)`
- `string .SystemIdToName(int systemId)`

### Methods
- `void :SetSelected(int selectedState)`
- `int :GetSelected()`
- `bool :CompletelyDestroyed()`
- `string* :GetName()`
- `void :SetName(string name)`
- `void :Repair()`
   - Not sure if this is a function called every tick to cause repairs or what, probably not useful to lua
- `bool :PartialRepair(float speed, bool autoRepair)`
   - Cause a partial repair of a system (opposite of partialDamage) must be called every tick or else you will not see any change
- `bool :PartialDamage(float amount)`
   - Must be called every tick or else you will not see any change
- `bool :NeedsRepairing()`
- `bool :Functioning()`
- `bool :CanBeSabotaged()`
- `float :GetDamage()`
- ~~`Location* :GetLocation()`~~
- ~~`Location* :GetGridLocation()`~~
- `void :SetDamage(float damage)`
- `void :SetMaxDamage(float maxDamage)`
- `void :SetLocation(Point position)`
- `int :GetId()`
- `bool :IsRoomBased()`
- `int :GetRoomId()`
- `bool :Ioned()`
- `void :SetRoomId()`
- `void :SetHackingLevel(int level)`
- `void :ForceBatteryPower(int power)`
- `void :RemoveBatteryPower()`
- ~~`WeaponBlueprint* :GetWeaponInfo()`~~
- ~~`string* :GetOverrideTooltip()`~~
- `void :CheckMaxPower()`
- `void :CheckForRepower()`
  - **Since 1.4.0**
- `void :SetBonusPower(int amount, int permanentPower)`
- `void :AddDamage(int amount)`
- `bool :ForceDecreasePower(int powerLoss)`
- `bool :ForceIncreasePower(int power)`
- `void :StopHacking()`
- `bool :GetNeedsPower()`
- `bool :Clickable()`
- `bool :Powered()`
- ~~`void :ShipDestroyed()`~~
- `void :AddLock(int lock)`
- `void :ClearStatus()`
- `bool :DamageOverTime(float damageIncrement)`
- `bool :DecreasePower(bool force)`
- `int :GetEffectivePower()`
- `bool :GetLocked()`
- `int :GetMaxPower()`
- `int :GetPowerCap()`
- `bool :IncreasePower(int amount, bool force)`
- ~~`bool :Ioned(int num)`~~
- `int :IsMannedBoost()`
- `void :LockSystem(int lock)`
- `void SetPowerCap(int cap)`
- `int SetPowerLoss(int power)`
- `bool UpgradeSystem(int amount)`
   - Upgrading a system is basically the same as changing the max power of a system although I think max power might reset after a jump? Not sure haven't tested.
   - I think negative upgrades (downgrades) are allowed, please report if they are not.

### Fields

- ~~`int` `.selectedState`~~
- [`ShipObject`](#ShipObject) `._shipObj`
- `float` `.fDamage`
- [`Point`](#Point) `.pLoc`
- `float` `.fMaxDamage`
- `string` `.name`
- `int` `.roomId`
- `int` `.iRepairCount`
- `int` `.iSystemType`
- `bool` `.bNeedsManned`
   - If the system requires manning to function.
- `bool` `.bManned`
- `int` `.iActiveManned`
- `bool` `.bBoostable`
   - If the system can be manned by a crewmember.
- `std::pair<int, int>` `.powerState`
- `int` `.iRequiredPower`
- ~~`GL_Texture*` `.imageIcon`~~
- ~~`GL_Primitive*` `.iconPrimitive`~~
- ~~`GL_Primitive*` `.iconBorderPrimitive`~~
- ~~`GL_Primitive*` `.iconPrimitives[20]`~~
- ~~`CachedRect` `.partialDamageRect`~~
- ~~`CachedRectOutline` `.lockOutline`~~
- ~~`Globals::Rect` `.roomShape`~~
- `bool` `.bOnFire`
- `bool` `.bBreached`
- `std::pair<int, int>` `.healthState`
- `float` `.fDamageOverTime`
- `float` `.fRepairOverTime`
- `bool` `.damagedLastFrame`
   - I don't know if this can be set to true per-frame to hold the damage over time progression counter, it might be able to freeze the graphic so it doesn't count down.
- `bool` `.repairedLastFrame`
   - I don't know if this can be set to true per-frame to hold the repair over time progression counter, it might be able to freeze the graphic so it doesn't count down.
- `int` `.originalPower`
- `bool` `.bNeedsPower`
   - True for regular systems, false for subsystems.
- `int` `.iTempPowerCap`
- `int` `.iTempPowerLoss`
- `int` `.iTempDividePower`
- `int` `.iLockCount`
- [`TimerHelper`](#timerhelper) `.lockTimer`
- `bool` `.bExploded`
- `bool` `.bOccupied`
- `bool` `.bFriendlies`
- `string` `.interiorImageName`
- [`GL_Primitive*`](#GL_Primitive) `.interiorImage`
- [`GL_Primitive*`](#GL_Primitive) `.interiorImageOn`
- [`GL_Primitive*`](#GL_Primitive) `.interiorImageManned`
- [`GL_Primitive*`](#GL_Primitive) `.interiorImageMannedFancy`
- `int` `.lastUserPower`
- `int` `.iBonusPower`
- `int` `.iLastBonusPower`
- [`Pointf`](#Pointf) `.location`
- `int` `.bpCost`
- [`AnimationTracker`](#animationtracker) `.flashTracker`
- `int` `.maxLevel`
- `int` `.iBatteryPower`
- `int` `.iHackEffect`
- `bool` `.bUnderAttack`
- `bool` `.bLevelBoostable`
   - If the system is given an additional level when manned by a crewmember (e.g. doors, sensors).
- `bool` `.bTriggerIon`
- ~~`std::vector<Animation>` `.damagingEffects`~~
- `int` `.computerLevel`
- [`ShipSystem_Extend`](#ShipSystem_Extend) `.extend`
  - **Since 1.4.0**
- LUA table `.table`
  - **Since 1.4.0**
  - A modifiable table of arbitrary data which exists as long as the object it belongs to

## ShipSystem_Extend
Accessed via `ShipSystem`'s `.extend` field

### Fields
- `int` `additionalPowerLoss`

## OxygenSystem

**Extends [ShipSystem](#ShipSystem)**

### Methods
- `void :EmptyOxygen(int roomId)`
- `float :GetRefillSpeed()`
- `void :ModifyRoomOxygen(int roomId, float value)`

### Fields
- `float` `.max_oxygen`
- `std::vector<float>` `.oxygenLevels`
- `float` `.fTotalOxygen`
- `bool` `.bLeakingO2`

## TeleportSystem

**Extends [ShipSystem](#ShipSystem)**

### Methods
- `bool :CanReceive()`
- `bool :CanSend()`
- `bool :Charged()`
- `void :ForceReady()`
- `float :GetChargedPercent()`
- `void :InitiateTeleport()`
- `void :SetArmed(int armed)`
- `void :SetHackingLevel(int hackingLevel)`

### Fields
- `float` `.chargeLevel`
- `bool` `.bCanSend`
- `bool` `.bCanReceive`
- `int` `.iArmed`
- `std::vector<bool>` `.crewSlots`
- `int` `.iPreparedCrew`
- `int` `.iNumSlots`
- `bool` `.bSuperShields`

## CloakingSystem

**Extends [ShipSystem](#ShipSystem)**

### Fields
- `bool` `.bTurnedOn`
- [`TimerHelper`](#TimerHelper) `.timer`
- `std::string` `.soundeffect`

## BatterySystem

**Extends [ShipSystem](#ShipSystem)**

### Fields
- `bool` `.bTurnedOn`
- [`TimerHelper`](#TimerHelper) `.timer`
- `std::string` `.soundeffect`

## MindSystem

**Extends [ShipSystem](#ShipSystem)**

### Methods
- `void :SetArmed(int armed)`
- `void :SetHackingLevel(int hackingLevel)`

### Fields
- `std::pair<float, float>` `.controlTimer`
- `bool` `.bCanUse`
- `int` `.iArmed`
- [`std::vector<CrewMember*>`](#CrewMember) `.controlledCrew`
- `bool` `.bSuperShields`
- `bool` `.bBlocked`
- `int` `.iQueuedTarget`
- `int` `.iQueuedShip`
- [`std::vector<CrewMember*>`](#CrewMember) `.queuedCrew`

## HackingSystem

**Extends [ShipSystem](#ShipSystem)**

### Methods
- `void :BlowHackingDrone()`

### Fields
- `bool` `.bHacking`
- [`HackingDrone`](#HackingDrone) `.drone`
- `bool` `.bBlocked`
- `bool` `.bArmed`
- [`ShipSystem*`](#ShipSystem) `.currentSystem`
   - The current system it is targeting
- `std::pair<float, float>` `.effectTimer`
- `bool` `.bCanHack`
- [`ShipSystem*`](#ShipSystem) `.queuedSystem`
- `int` `.spendDrone`

## Shields

**Extends [ShipSystem](#ShipSystem)**

### Methods
- `void :AddSuperShield(Point pos)`
- [`CollisionResponse`](#CollisionResponse) `:CollisionReal(float x, float y, Damage damage, bool force)`
- [`CollisionResponse`](#CollisionResponse) `:CollisionReal(float x, float y, Damage damage)`
- `void :InstantCharge()`
- `void :SetBaseEllipse(Globals::Ellipse ellipse)`
- `void :SetHackingLevel(int hackingLevel)`

### Fields
- `float` `.ellipseRatio`
- [`Point`](#Point) `.center`
- [`Globals::Ellipse`](#Globals) `.baseShield`
- `int` `.iHighlightedSide`
- [`Shield`](#Shield) `.shields`
- `bool` `.shields_shutdown`
- [`std::vector<ShieldAnimation>`](#ShieldAnimation) `.shieldHits`
- [`AnimationTracker`](#AnimationTracker) `.shieldsDown`
- `bool` `.superShieldDown`
- [`Pointf`](#Pointf) `.shieldsDownPoint`
- [`AnimationTracker`](#AnimationTracker) `.shieldsUp`
- [`GL_Texture*`](#GL_Texture) `.shieldImage`
- [`GL_Primitive*`](#GL_Primitive) `.shieldPrimitive`
- `std::string` `.shieldImageName`
- `bool` `.bEnemyPresent`
- `bool` `.bBarrierMode`
- `float` `.lastHitTimer`
- `float` `.chargeTime`
- `int` `.lastHitShieldLevel`
- [`AnimationTracker`](#AnimationTracker) `.superShieldUp`
- [`Point`](#Point) `.superUpLoc`
- `bool` `.bExcessChargeHack`

## Shield

**Internal struct of [`Shields`](#Shields)**

### Fields
- `float` `.charger`
- [`ShieldPower`](#ShieldPower) `.power`
- `float` `.superTimer`

## WeaponSystem

**Extends [ShipSystem](#ShipSystem)**

### Methods
- `ProjectileFactory* :RemoveWeapon(int slot)`
- `void :SetBonusPower(int amount, int permanentPower)`

### Fields
- [`Pointf`](#Pointf) `.target`
- [`std::vector<ProjectileFactory*>`](#ProjectileFactory) `.weapons`
- [`std::vector<ProjectileFactory*>`](#ProjectileFactory) `.weaponsTrashList`
- `float` `.shot_timer`
- `int` `.shot_count`
- `int` `.missile_count`
- `int` `.missile_start`
- `std::vector<bool>` `.userPowered`
- `int` `.slot_count`
- `int` `.iStartingBatteryPower`
- `std::vector<bool>` `.repowerList`

## ArtillerySystem

**Extends [`ShipSystem`](#shipsystem)**

### Fields
- [`ProjectileFactory*`](#projectilefactory) `.projectileFactory`
- [`Targetable*`](#targetable) `.target`
- `bool` `.bCloaked`

## EngineSystem

**Extends [`ShipSystem`](#shipsystem)**
No additional items over base `ShipSystem`

## MedbaySystem

**Extends [`ShipSystem`](#shipsystem)**
No additional items over base `ShipSystem`

## CloneSystem

**Extends [`ShipSystem`](#shipsystem)**

### Fields
- `float` `.fTimeToClone`
- [`CrewMember*`](#crewmember) `.clone`
- `float` `.fTimeGoal`
- `float` `.fDeathTime`
- [`GL_Texture*`](#GL_Texture) `.bottom`
- [`GL_Texture*`](#GL_Texture) `.top`
- [`GL_Texture*`](#GL_Texture) `.gas`
- `int` `.slot`

## DroneSystem

**Extends [`ShipSystem`](#shipsystem)**

### Methods
- `bool :DePowerDrone(Drone* drone, bool unknown)`
- `void :RemoveDrone(int slot)`
- `void :SetBonusPower(int amount, int permanentPower)`

### Fields
- [`Drone*[]`](#drone) `.drones`
   - Vector starts at index 0 not 1.
- `int` `.drone_count`
- `int` `.drone_start`
- [`Targetable*`](#targetable) `.targetShip`
- `bool[]` `.userPowered`
   - Vector starts at index 0 not 1.
- `int` `.slot_count`
- `int` `.iStartingBatteryPower`
- `bool[]` `.repowerList`
   - Vector starts at index 0 not 1.

## SystemBox
The class representing the UI of a ShipSystem, where power is controlled and buttons are pressed.

### Methods
No methods are exposed currently.

### Fields
- [`ShipSystem`](#shipsystem) `.pSystem`
   - The ShipSystem managed by this SystemBox.
- [`Point`](#point) `.location`
   - The location of the SystemBox.
- `bool` `.bPlayerUI`
- [`SystemBox_Extend`](#systembox_extend) `.extend`
   - **Read-only**
   - The SystemBox_Extend associated with this SystemBox.
- LUA table `.table`
   - A modifiable table of arbitrary data which exists as long as the object it belongs to.

## SystemBox_Extend
The class holding additional SystemBox data members that are not a part of FTL's native SystemBox strucure.

### Methods
No methods are exposed currently.

### Fields
- [`SystemBox`](#systembox) `.orig`
   - **Read-only**
   - The SystemBox associated with this SystemBox_Extend.
- `int` `.xOffset`
   - The offset from this SystemBox to the next in the UI.

## Drone

### Methods
- `void OnInit()`
- `void OnLoop()`
- `void OnDestroy()`
- `void SetPowered(bool _powered)`
- `void SetInstantPowered()`
- `bool GetPowered()`
- `void SetCurrentShip(int shipId)`
- `void SetDeployed(bool _deployed)`
- `void SetDestroyed(bool dead, bool setTimer)`
- `void SetHacked(int level)`
- `bool GetDeployed()`
- `bool NeedsRoom()`
- `void SetSlot(int room, int slot)`
- `bool Destroyed()`
- `Point GetWorldLocation()`
- `void SetWorldLocation(Point point)`
- `Slot *GetDroneSlot(Drone *drone)`
- `int GetDroneHealth()`
- `int GetRequiredPower()`
- `void RenderIcon()`
- `std::string *GetName(Drone *drone)`
- `bool CanBeDeployed()`
- `bool RecallOnJump()`
- `bool CanBeRecovered()`
- `void SaveState(int fh)`
- `void LoadState(int fh)`
- `void BlowUp(bool silent)`
- `bool GetStunned()`

### Fields
- `int` `.iShipId`
   - **Read-only**
- `int` `.selfId`
- `bool` `.powered`
- `int` `.powerRequired`
- `bool` `.deployed`
- `int` `.type`
- [`DroneBlueprint`](#droneblueprint) `.blueprint`
   - **Read-only**
- `bool` `.bDead`
- `int` `.iBonusPower`
- `bool` `.poweredAtLocation`
- `float` `.destroyedTimer`
- `int` `.iHackLevel`
- `float` `.hackTime`

## SpaceDrone

**Extends [`Drone`](#drone)**

### Methods
- `void PickDestination()`
- `void PickTarget()`
- `bool HasTarget()`
- `bool ValidTarget()`
- `float GetWeaponCooldown()`
- `void RandomizeStartingPosition()`
- `bool HideUnderOwner()`
- `Projectile *GetNextProjectile()`
- `void SetMovementTarget(Targetable *target)`
- `void SetWeaponTarget(Targetable *target)`
- `bool ValidTargetObject(Targetable *target)`
- `void OnRender(int space)`
- `void RenderDrone()`
- `std::string *GetTooltip(SpaceDrone *drone)`
- `Pointf GetWorldCenterPoint()`
- `void SetCurrentLocation(Pointf pos)`
- `void MouseMove(int mX, int mY)`
- `Pointf GetRandomTargettingPoint(bool unk)`
- [`Ellipse`](#Ellipse) `*GetShieldShape(SpaceDrone *drone)`
- `int GetSpaceId()`
- `Pointf GetSpeed()`
- `int GetOwnerId()`
- `int GetSelfId()`
- `CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)`
- `bool DamageBeam(Pointf pos1, Pointf pos2, Damage damage)`
- `bool DamageArea(Pointf pos, Damage damage, bool unk)`
- `BoarderDrone *GetBoardingDrone()`
- `void SetDeployed(bool deployed)`
- `float UpdateAimingAngle(Pointf location, float percentage, float forceDesired)`

### Fields
- [`Targetable`](#targetable) `._targetable`
- `Collideable` `._collideable`
- `int` `.currentSpace`
- `int` `.destinationSpace`
- [`Pointf`](#Pointf) `.currentLocation`
- [`Pointf`](#Pointf) `.lastLocation`
- [`Pointf`](#Pointf) `.destinationLocation`
- [`Pointf`](#Pointf) `.pointTarget`
- `Animation` `.explosion`
- [`Targetable`](#targetable) `.*weaponTarget`
- [`Pointf`](#Pointf) `.targetLocation`
- [`Pointf`](#Pointf) `.targetSpeed`
- [`Targetable`](#targetable) `.*movementTarget`
- [`Pointf`](#Pointf) `.speedVector`
- `bool` `.poweredLastFrame`
- `bool` `.deployedLastFrame`
- `bool` `.bFire`
- `float` `.pause`
- `float` `.additionalPause`
- `float` `.weaponCooldown`
- `float` `.current_angle`
- `float` `.aimingAngle`
- `float` `.lastAimingAngle`
- `float` `.desiredAimingAngle`
- `DamageMessage` `.message`
- `Animation` `.weapon_animation`
- `WeaponBlueprint` `.weaponBlueprint`
   - **Read-only**
- `int` `.lifespan`
- `bool` `.bLoadedPosition`
- `bool` `.bDisrupted`
- `float` `.hackAngle`
- `float` `.ionStun`
- [`Pointf`](#Pointf) `.beamCurrentTarget`
- [`Pointf`](#Pointf) `.beamFinalTarget`
- `float` `.beamSpeed`
- `Animation` `.hackSparks`

## DefenseDrone

**Extends [`SpaceDrone`](#SpaceDrone)**

### Methods
- `std::string :GetTooltip()`
- `void :PickTarget()`
- `void :SetWeaponTarget(Targetable *target)`
- `bool :ValidTargetObject(Targetable *target)`

### Fields
- `int` `.currentTargetId`
- `int` `.shotAtTargetId`
- `float` `.currentSpeed`
- [`CachedImage`](#CachedImage) `.drone_image`
- [`CachedImage`](#CachedImage) `.gun_image_off`
- [`CachedImage`](#CachedImage) `.gun_image_charging`
- [`CachedImage`](#CachedImage) `.gun_image_on`
- [`CachedImage`](#CachedImage) `.engine_image`
- `int` `.currentTargetType`

## CombatDrone

**Extends [`SpaceDrone`](#SpaceDrone)**

### Methods
- `void :SetWeaponTarget(Targetable *target)`

### Fields
- [`Pointf`](#Pointf) `.lastDestination`
- `float` `.progressToDestination`
- `float` `.heading`
- `float` `.oldHeading`
- [`CachedImage`](#CachedImage) `.drone_image_off`
- [`CachedImage`](#CachedImage) `.drone_image_charging`
- [`CachedImage`](#CachedImage) `.drone_image_on`
- [`CachedImage`](#CachedImage) `.engine_image`

## BoarderPodDrone

**Extends [`SpaceDrone`](#SpaceDrone)**

### Methods
- `bool :CanBeDeployed()`
- [`CollisionResponse`](#CollisionResponse) `:CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)`
- `void :SetDeployed(bool _deployed)`
- `void :SetMovementTarget(Targetable *target)`

### Fields
- [`GL_Texture*`](#GL_Texture) `.baseSheet`
- [`GL_Texture*`](#GL_Texture) `.colorSheet`
- [`Pointf`](#Pointf) `.startingPosition`
- [`Animation`](#Animation) `.droneImage`
- [`CachedImage`](#CachedImage) `.flame`
- [`BoarderDrone*`](#BoarderDrone) `.boarderDrone`
- `bool` `.bDeliveredDrone`
- `bool` `.diedInSpace`

## HackingDrone

**Extends [`SpaceDrone`](#SpaceDrone)**

### Methods
- [`CollisionResponse`](#CollisionResponse) `:CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)`
- `void :OnLoop()`
- `void :SetMovementTarget(Targetable *target)`

### Fields
- [`Pointf`](#Pointf) `.startingPosition`
- [`GL_Texture*`](#GL_Texture) `.droneImage_on`
- [`GL_Texture*`](#GL_Texture) `.droneImage_off`
- [`GL_Texture*`](#GL_Texture) `.lightImage`
- [`Pointf`](#Pointf) `.finalDestination`
- `bool` `.arrived`
- `bool` `.finishedSetup`
- [`AnimationTracker`](#AnimationTracker) `.flashTracker`
- [`Animation`](#Animation) `.flying`
- [`Animation`](#Animation) `.extending`
- [`Animation`](#Animation) `.explosion`
- `int` `.prefRoom`

## SuperShieldDrone

**Extends [`DefenseDrone`](#DefenseDrone)**

### Fields
- [`Shields*`](#Shields) `.shieldSystem`
- [`CachedImage`](#CachedImage) `.drone_image_on`
- [`CachedImage`](#CachedImage) `.drone_image_off`
- [`CachedImage`](#CachedImage) `.drone_image_glow`
- `float` `.glowAnimation`

## DroneBlueprint

**Extends [`Blueprint`](#blueprint)**

### Fields
**All fields are read-only**
- `std::string` `.typeName`
- `int` `.level`
- `int` `.targetType`
- `int` `.power`
- `float` `.cooldown`
- `int` `.speed`
- `int` `.dodge`
- `std::string` `.weaponBlueprint`
- `std::string` `.droneImage`
- `std::string` `.combatIcon`

## Room

### Fields
- `bool` `.bBlackedOut`
- [`Globals::Rect`](#Globals) `.rect`
   - **Read-only**
- `int` `.iRoomId`
   - **Read-only**
- [`GL_Primitive*`](#GL_Primitive) `.highlightPrimitive`
- [`GL_Primitive*`](#GL_Primitive) `.highlightPrimitive2`
- [`Room_Extend`](#room_extend) `.extend`
   - **Read-only**

## Room_Extend
Accessed via `Room`'s `.extend` field

### Fields
- `float` `.sysDamageResistChance`
- `float` `.ionDamageResistChance`
- `float` `.hullDamageResistChance`
- `int` `.timeDilation`

## RoomDefinition

### Fields
- `int` `.roomId`
- `bool` `.sensorBlind`
- `float` `.sysDamageResistChance`
- `float` `.ionDamageResistChance`
- `float` `.hullDamageResistChance`

## TemporalSystemParser

### Methods
- `float .GetDilationStrength(int effectStrength)`
   - Gets the temporal modifier for a given time dilation value.

## CrewStat

### Fields
- `int` `.MAX_HEALTH`
- `int` `.STUN_MULTIPLIER`
- `int` `.MOVE_SPEED_MULTIPLIER`
- `int` `.REPAIR_SPEED_MULTIPLIER`
- `int` `.DAMAGE_MULTIPLIER`
- `int` `.RANGED_DAMAGE_MULTIPLIER`
- `int` `.DOOR_DAMAGE_MULTIPLIER`
- `int` `.FIRE_REPAIR_MULTIPLIER`
- `int` `.SUFFOCATION_MODIFIER`
- `int` `.FIRE_DAMAGE_MULTIPLIER`
- `int` `.OXYGEN_CHANGE_SPEED`
- `int` `.DAMAGE_TAKEN_MULTIPLIER`
- `int` `.CLONE_SPEED_MULTIPLIER`
- `int` `.PASSIVE_HEAL_AMOUNT`
- `int` `.TRUE_PASSIVE_HEAL_AMOUNT`
- `int` `.TRUE_HEAL_AMOUNT`
- `int` `.PASSIVE_HEAL_DELAY`
- `int` `.ACTIVE_HEAL_AMOUNT`
- `int` `.SABOTAGE_SPEED_MULTIPLIER`
- `int` `.ALL_DAMAGE_TAKEN_MULTIPLIER`
- `int` `.HEAL_SPEED_MULTIPLIER`
- `int` `.HEAL_CREW_AMOUNT`
- `int` `.DAMAGE_ENEMIES_AMOUNT`
- `int` `.BONUS_POWER`
- `int` `.POWER_DRAIN`
- `int` `.ESSENTIAL`
- `int` `.CAN_FIGHT`
- `int` `.CAN_REPAIR`
- `int` `.CAN_SABOTAGE`
- `int` `.CAN_MAN`
- `int` `.CAN_TELEPORT`
- `int` `.CAN_SUFFOCATE`
- `int` `.CONTROLLABLE`
- `int` `.CAN_BURN`
- `int` `.IS_TELEPATHIC`
- `int` `.RESISTS_MIND_CONTROL`
- `int` `.IS_ANAEROBIC`
- `int` `.CAN_PHASE_THROUGH_DOORS`
- `int` `.DETECTS_LIFEFORMS`
- `int` `.CLONE_LOSE_SKILLS`
- `int` `.POWER_DRAIN_FRIENDLY`
- `int` `.DEFAULT_SKILL_LEVEL`
- `int` `.POWER_RECHARGE_MULTIPLIER`
- `int` `.HACK_DOORS`
- `int` `.NO_CLONE`
- `int` `.NO_SLOT`
- `int` `.NO_AI`
- `int` `.VALID_TARGET`
- `int` `.CAN_MOVE`
- `int` `.TELEPORT_MOVE`
- `int` `.TELEPORT_MOVE_OTHER_SHIP`
- `int` `.SILENCED`
- `int` `.LOW_HEALTH_THRESHOLD`
- `int` `.NO_WARNING`
- `int` `.CREW_SLOTS`
- `int` `.ACTIVATE_WHEN_READY`
- `int` `.STAT_BOOST`
- `int` `.DEATH_EFFECT`
- `int` `.POWER_EFFECT`
- `int` `.POWER_MAX_CHARGES`
- `int` `.POWER_CHARGES_PER_JUMP`
- `int` `.POWER_COOLDOWN`
- `int` `.TRANSFORM_RACE`

## StatBoostDefinition

### Fields
- `CrewStat` `.stat`
- `float` `.amount`
- `BoostType` `.boostType`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.BoostType.MULT`
        - `Hyperspace.StatBoostDefinition.BoostType.FLAT`
        - `Hyperspace.StatBoostDefinition.BoostType.ADD`
        - `Hyperspace.StatBoostDefinition.BoostType.SET`
        - `Hyperspace.StatBoostDefinition.BoostType.FLIP`
        - `Hyperspace.StatBoostDefinition.BoostType.SET_VALUE`
        - `Hyperspace.StatBoostDefinition.BoostType.MIN`
        - `Hyperspace.StatBoostDefinition.BoostType.MAX`
        - `Hyperspace.StatBoostDefinition.BoostType.REPLACE_GROUP`
        - `Hyperspace.StatBoostDefinition.BoostType.REPLACE_POWER`
- `BoostSource` `.boostSource`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.BoostSource.CREW`
        - `Hyperspace.StatBoostDefinition.BoostSource.AUGMENT`
- `ShipTarget` `.shipTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.ShipTarget.PLAYER_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ENEMY_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.CURRENT_ALL`
        - `Hyperspace.StatBoostDefinition.ShipTarget.CURRENT_ROOM`
        - `Hyperspace.StatBoostDefinition.ShipTarget.OTHER_ALL`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ORIGINAL_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ORIGINAL_OTHER_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.CREW_TARGET`
        - `Hyperspace.StatBoostDefinition.ShipTarget.TARGETS_ME`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ALL`
- `SystemRoomTarget` `.systemRoomTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.SystemRoomTarget.ALL`
        - `Hyperspace.StatBoostDefinition.SystemRoomTarget.NONE`
- `CrewTarget` `.crewTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.CrewTarget.ALLIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ENEMIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.SELF`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ALL`
        - `Hyperspace.StatBoostDefinition.CrewTarget.CURRENT_ALLIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.CURRENT_ENEMIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ORIGINAL_ALLIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ORIGINAL_ENEMIES`
- `DroneTarget` `.droneTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.DroneTarget.DRONES`
        - `Hyperspace.StatBoostDefinition.DroneTarget.CREW`
        - `Hyperspace.StatBoostDefinition.DroneTarget.ALL`
- `bool` `.value`
- `std::string` `.stringValue`
- `bool` `.isBool`
- `int` `.priority`
- `float` `.duration`
- `bool` `.jumpClear`
- `bool` `.cloneClear`
- `std::string` `.boostAnim`
- `RoomAnimDef` `.roomAnim`
- `bool` `.affectsSelf`
- `std::vector<std::string>` `.whiteList`
- `std::vector<std::string>` `.blackList`
- `std::vector<std::string>` `.systemRoomReqs`
- `std::vector<std::string>` `.systemList`
- `std::vector<StatBoostDefinition*>` `.providedStatBoosts`
- `ActivatedPowerDefinition` `.powerChange`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerWhitelist`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerBlacklist`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerResourceWhitelist`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerResourceBlacklist`
- `std::unordered_set<unsigned int>` `.powerGroupWhitelist`
- `std::unordered_set<unsigned int>` `.powerGroupBlacklist`
- `bool` `.hasPowerList`
- `ExplosionDefinition*` `.deathEffectChange`
- `std::vector<float>` `.powerScaling`
- `float` `.powerScalingNoSys`
- `float` `.powerScalingHackedSys`
- `std::vector<int>` `.systemPowerScaling`
- `std::vector<std::pair<CrewExtraCondition, bool>>` `.extraConditions`
- `std::vector<std::pair<CrewExtraCondition, bool>>` `.extraOrConditions`
- `bool` `.extraConditionsReq`
- `bool` `.systemRoomReq`
- `bool` `.isRoomBased`
- `bool` `.functionalTarget`
- `std::pair<float, float>` `.healthReq`
- `std::pair<float, float>` `.healthFractionReq`
- `std::pair<float, float>` `.oxygenReq`
- `std::pair<int, int>` `.fireCount`
- `float` `.dangerRating`
- `int` `.realBoostId`
- `int` `.stackId`
- `int` `.maxStacks`
- `static` `std::vector<StatBoostDefinition*>` `.statBoostDefs`
- `static` `std::unordered_map<std::string, StatBoostDefinition*>` `.savedStatBoostDefs`

## StatBoostManager

### Methods
- `StatBoostManager .GetInstance()`
    - Returns the main instance of `StatBoostManager`. Always use this to access any members and methods belonging to this class.
- `void :CreateTimedAugmentBoost(StatBoost, CrewMember)`
    - Apply a stat boost to a crew member.
###### Example
```lua
-- Function to apply a 10 second health boost to every crew member on a ship
local def = Hyperspace.StatBoostDefinition()
def.stat = Hyperspace.CrewStat.MAX_HEALTH
def.amount = 100
def.boostType = Hyperspace.StatBoostDefinition.BoostType.FLAT
def.boostSource = Hyperspace.StatBoostDefinition.BoostSource.AUGMENT
def.shipTarget = Hyperspace.StatBoostDefinition.ShipTarget.ALL
def.crewTarget = Hyperspace.StatBoostDefinition.CrewTarget.ALL
def.duration = 10
def.realBoostId = Hyperspace.StatBoostDefinition.statBoostDefs:size()
Hyperspace.StatBoostDefinition.statBoostDefs:push_back(def)
function player_crew_health_boost()
	local crewList = Hyperspace.ships.player.vCrewList
	for i = 0, crewList:size() - 1 do
		local crew = crewList[i]
		Hyperspace.StatBoostManager.GetInstance():CreateTimedAugmentBoost(Hyperspace.StatBoost(def), crew)
	end
end
```

## CrewMemberFactory

### Methods
- `void :GetCloneReadyList(std::vector<CrewMember*> vec, bool player)`
- `void :GetCloneReadyList(bool player)`

### Fields
- [`std::vector<CrewMember*>`](#CrewMember) `.crewMembers`

## CrewMember
Accessed via [`ShipManager`](#ShipManager)'s `.vCrewList` field or by using the Internal Event `CREW_LOOP`

### Methods
- `Point :GetPosition()`
- `float :PositionShift()`
- `bool :InsideRoom(int roomId)`
- `bool :ApplyDamage(float damage)`
- `int :GetPriority`
- `bool :ValidTarget(int unk)`
- `bool :MultiShots()`
- `bool :ExactTarget()`
- `bool :IsCrew()`
- `bool :IsCloned()`
- `bool :IsDrone()`
- `void :Jump()`
- `bool :GetIntruder()`
- `void :SaveState(int fileHelper)`
- `void :LoadState(int fileHelper)`
- `void :OnLoop()`
- `void :OnRender(bool outlineOnly)`
- `bool :OutOfGame()`
- `void :SetOutOfGame()`
- `bool :Functional()`
- `bool :CountForVictory()`
- `bool :GetControllable()`
- `bool :ReadyToFight()`
- `bool :CanFight()`
- `bool :CanRepair()`
- `bool :CanSabotage()`
- `bool :CanMan()`
- `bool :CanTeleport()`
- `bool :CanHeal()`
- `bool :CanSuffocate()`
- `bool :CanBurn()`
- `int :GetMaxHealth()`
- `bool :IsDead()`
- `bool :PermanentDeath()`
- `bool :ShipDamage(float damage)`
- `bool :FireFightingSoundEffect()`
- `std::string :GetUniqueRepairing()`
- `bool :ProvidesVision()`
- `float :GetMoveSpeedMultiplier()`
- `float :GetRepairSpeed()`
- `float :GetDamageMultiplier()`
- `bool :ProvidesPower()`
- `std::string :GetSpecies()`
- `float :GetFireRepairMultiplier()`
- `bool :IsTelepathic()`
- `std::pair<float, float> :GetPowerCooldown()`
- `bool :PowerReady()`
- `void :ActivatePower()`
- `bool :HasSpecialPower()`
- `void :ResetPower()`
- `float :GetSuffocationMultiplier()`
- `int :BlockRoom()`
- [`Damage`](#Damage) `:GetRoomDamage()`
- `bool :IsAnaerobic()`
- `void :UpdateRepair()`
- `bool :CanStim()`
- `bool :AtFinalGoal()`
- `bool :AtGoal()`
- `bool :BadAtCombat()`
- `void :CheckFighting()`
- `void :CheckForTeleport()`
- `bool :CheckRoomPath(int roomId)`
- `void :CheckSkills()`
- `void :Cleanup()`
- `void :ClearPath()`
- `void :ClearPosition()`
- `void :ClearTask()`
- `void :Clone()`
- `void :CloseDoorBehind(Door *door)`
- `bool :ContainsPoint(int x, int y)`
- `void :CycleColorLayer(int unk)`
- `bool :DirectModifyHealth(float health)`
- `void :EmptySlot()`
- [`Slot`](#Slot) `:FindSlot(int roomId, int slotId, bool closeEnough)`
- `void :ForceMindControl(bool force)`
- [`Point`](#Point) `:GetFinalGoal()`
- `int :GetIntegerHealth()`
- [`Point`](#Point) `:GetLocation()`
- `std::string :GetLongName()`
- `float :GetMoveSpeed()`
- `std::string :GetName()`
- `bool :GetNewGoal()`
- [`Point`](#Point) `:GetNextGoal()`
- `int :GetRepairingId()`
- `bool :GetResisted()`
- [`Slot`](#Slot) `:GetSavedPosition()`
- `int :GetSkillFromSystem(int systemId)`
- `int :GetSkillLevel(int skillId)`
- `float :GetSkillModifier(int skillId)`
- `int` `:GetSkillProgress(int skillId)`
- `std::string :GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen)`
- `std::string :GetTooltip()`
- `void :IncreaseSkill(int skillId)`
- `void :InitializeSkills()`
- `bool :IsBusy()`
- `bool :IsManningArtillery()`
- `void :Kill(bool noClone)`
- `void :MasterSkill(int skillId)`
- `void :ModifyHealth(float health)`
- `bool :MoveToRoom(int roomId, int slotId, bool forceMove)`
- `bool :NeedFrozenLocation()`
- `bool :NeedsSlot()`
- `bool :OnInit()`
- `void :OnRenderHealth()`
- `void :OnRenderPath()`
- `void :RenderSkillUpAnimation(Point pos)`
- `bool :Repairing()`
- `bool :RepairingFire()`
- `bool :RepairingSystem()`
- `void :Restart()`
- `bool :RestorePosition()`
- `bool :Sabotaging()`
- `void :SavePosition()`
- [`Pointf`](#Pointf) `:SelectSabotageTarget()`
- `void :SetCloneReady(bool cloneReady)`
- `void :SetCurrentShip(int shipId)`
- `void :SetCurrentSystem(ShipSystem *sys)`
- `void :SetCurrentTarget(CrewTarget *target, bool unk)`
- `void :SetDamageBoost(float damageBoost)`
- `void :SetDeathNumber(int deathNum)`
- `void :SetFrozen(bool frozen)`
- `void :SetFrozenLocation(bool frozenLocation)`
- `void :SetHealthBoost(int healthBoost)`
- `void :SetMedbay(float health)`
- `void :SetMindControl(bool controlled)`
- `void :SetName(TextString *name, bool force)`
- `bool :SetPath(Path *path)`
- `void :SetPosition(Point pos)`
- `void :SetResisted(bool resisted)`
- `void :SetRoom(int roomId)`
- `void :SetRoomPath(int slotId, int roomId)`
- `void :SetSavePosition(Slot position)`
- `void :SetSex(bool male)`
- `void :SetSkillProgress(int skillId, int skillLevel)`
- `void :SetTask(CrewTask task)`
- `void :StartRepair(Repairable *toRepair)`
- `void :StartTeleport()`
- `void :StartTeleportArrive()`
- `void :StopRepairing()`
- `void :UpdateHealth()`
- `void :UpdateMovement()`
- `bool :WithinRect(int x, int y, int w, int h)`
- `void :constructor(CrewBlueprint blueprint, int shipId, bool intruder, CrewAnimation *animation)`

### Fields
- `int` `.iShipId`
- `float` `.x`
   - **read-only**
- `float` `.y`
   - **read-only**
- `float` `.size`
- `float` `.scale`
- `float` `.goal_x`
- `float` `.goal_y`
- `int` `.width`
- `int` `.height`
- `std::pair<float, float> `.health`
- `float` `.speed_x`
- `float` `.speed_y`
- [`Path`](#Path) `.path`
- `bool` `.new_path`
- `float` `.x_destination`
- `float` `.y_destination`
- [`Door*`](#Door) `.last_door`
- [`Repairable*`](#Repairable) `.currentRepair`
- `bool` `.bSuffocating`
- `int` `.moveGoal`
- `int` `.selectionState`
- `int` `.iRoomId`
- `int` `.iManningId`
- `int` `.iRepairId`
- `int` `.iStackId`
- [`Slot`](#Slot) `.currentSlot`
- `bool` `.intruder`
- `bool` `.bFighting`
- `bool` `.bSharedSpot`
- [`CrewAnimation*`](#CrewAnimation) `.crewAnim`
- [`GL_Texture*`](#GL_Texture) `.selectionImage`
- [`CachedImage`](#CachedImage) `.healthBox`
- [`CachedImage`](#CachedImage) `.healthBoxRed`
- [`CachedRect`](#CachedRect) `.healthBar`
- `float` `.fMedbay`
- `float` `.lastDamageTimer`
- `float` `.lastHealthChange`
- `int` `.currentShipId`
- [`AnimationTracker`](#AnimationTracker) `.flashHealthTracker`
- [`Pointf`](#Pointf) `.currentTarget`
- [`CrewTarget*`](#CrewTarget) `.crewTarget`
- [`BoardingGoal`](#BoardingGoal) `.boardingGoal`
- `bool` `.bFrozen`
- `bool` `.bFrozenLocation`
- [`CrewTask`](#CrewTask) `.task`
- `std::string` `.type`
- [`Ship*`](#Ship) `.ship`
- [`Slot`](#Slot) `.finalGoal`
- [`Door*`](#Door) `.blockingDoor`
- `bool` `.bOutOfGame`
- `std::string` `.species`
- `bool` `.bDead`
- `int` `.iOnFire`
- `bool` `.bActiveManning`
- [`ShipSystem*`](#ShipSystem) `.currentSystem`
- `int` `.usingSkill`
- [`CrewBlueprint`](#CrewBlueprint) `.blueprint`
- [`Animation`](#Animation) `.healing`
- [`Animation`](#Animation) `.stunned`
- [`AnimationTracker`](#AnimationTracker) `.levelUp`
- `int` `.lastLevelUp`
- [`SCrewStats`](#SCrewStats) `.stats`
- `std::vector<bool>>` `.skillsEarned`
- `bool` `.clone_ready`
- `bool` `.bMindControlled`
- `int` `.iDeathNumber`
- [`Animation`](#Animation) `.mindControlled`
- [`Animation`](#Animation) `.stunIcon`
- [`std::vector<std::vector<AnimationTracker>>`](#AnimationTracker) `.skillUp`
- `int` `.healthBoost`
- `float` `.fMindDamageBoost`
- `float` `.fCloneDying`
- `bool` `.bResisted`
- [`Slot`](#Slot) `.savedPosition`
- `float` `.fStunTime`
- [`CachedImage`](#CachedImage) `.movementTarget`
- `bool` `.bCloned`
- [`CrewMember_Extend`](#CrewMember_Extend) `.extend`

## SCrewStats
Accessed via [`CrewMember`](#CrewMember)'s `.stats` field

### Fields
- `std::vector<int>` `.stat`
   - Has 5 values. `[0]` is the number of repairs, `[1]` is the number of crew combat kills, `[2]` is piloted evasions, `[3]` is jumps survived, `[4]` is skills mastered.
- `std::string` `.species`
- `std::string` `.name`
- `bool` `.male`

## CrewMember_Extend
Accessed via [`CrewMember`](#CrewMember)'s `.extend` field

### Methods
- `void :InitiateTeleport(int shipId, int roomId=-1, int slotId=-1)`
- [`CrewDefinition`](#CrewDefinition) `:*GetDefinition()`
- `float :CalculateStat(CrewStat stat, bool* boolValue=nullptr)`
   - Returns the current `float` and `bool` value for the given `CrewStat`.

### Fields
- [`CrewMember*`](#CrewMember) `.orig`
   - **read-only**
- `int` `.selfId`
   - **read-only**
- `bool` `.canPhaseThroughDoors`
- `bool` `.isHealing`
- [`TimerHelper*`](#TimerHelper) `.passiveHealTimer`
- [`TimerHelper*`](#TimerHelper) `.deathTimer`
- `int` `.lastRoom`
- `int` `.lastShipId`
- `bool` `.exploded`
- `bool` `.triggerExplosion`
- [`std::vector<ActivatedPower*>`](#ActivatedPower) `.crewPowers`
   - **read-only**
- `bool` `.hasSpecialPower`
- [`std::vector<ActivatedPowerResource*>`](#ActivatedPowerResource) `.powerResources`
   - **read-only**
- [`std::unordered_map<unsigned int,ActivatedPowerResource*>`](#ActivatedPowerResource) `.powerResourceMap`
   - **read-only**
- [`std::vector<ActivatedPowerDefinition*>`](#ActivatedPowerDefinition) `.powerChange`
- [`CustomTeleport`](#CustomTeleport) `.customTele`

###### Example
```lua
local crew = Hyperspace.ships.player.vCrewList[0]
local maxHealth, _ = crew.extend:CalculateStat(Hyperspace.CrewStat.MAX_HEALTH)
-- This will return maxHealth, false. As this CrewStat is numerical, the value false is discarded.
local _, canMove = crew.extend:CalculateStat(Hyperspace.CrewStat.CAN_MOVE)
-- This will return 0, canMove. Since this is a boolean stat, the value 0 is discarded.
```
- `CrewDefinition* :GetDefinition()`
    - Returns the CrewMember's [`CrewDefinition`](#CrewDefinition)

## CustomTeleport

**Internal struct of [CrewMember_Extend](#CrewMember_Extend)**

### Fields
- `bool` `.teleporting`
- `int` `.shipId`
- `int` `.roomId`
- `int` `.slotId`

## CrewAnimation

### Methods

- `void :OnRender(float scale, int selectedState, bool outlineOnly)`
- `void :OnRenderProps()`
- `void :OnUpdateEffects()`
- `void :UpdateFiring()`
- `void :UpdateShooting()`
- `bool :FireShot()`
- `int :GetFiringFrame()`
- `std::string :GetShootingSound()`
- `std::string :GetDeathSound()`
- `void :Restart()`
- `bool :CustomDeath()`
- `void :OnInit(std::string name, Pointf position, bool enemy)`
- `void :OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire)`
- `void :RenderIcon(bool border)`
- `void :SetupStrips()`

### Fields
- `int` `.iShipId`
- [`std::vector<std::vector<Animation>>`](#Animation) `.anims`
- [`GL_Texture*`](#GL_Texture) `.baseStrip`
- [`GL_Texture*`](#GL_Texture) `.colorStrip`
- [`std::vector<GL_Texture*>`](#GL_Texture) `.layerStrips`
- [`Pointf`](#Pointf) `.lastPosition`
- `int` `.direction`
- `int` `.sub_direction`
- `int` `.status`
- `int` `.moveDirection`
- [`ParticleEmitter`](#ParticleEmitter) `.smokeEmitter`
- `bool` `.bSharedSpot`
- [`TimerHelper`](#TimerHelper) `.shootTimer`
- [`TimerHelper`](#TimerHelper) `.punchTimer`
- [`Pointf`](#Pointf) `.target`
- `float` `.fDamageDone`
- `bool` `.bPlayer`
- `bool` `.bFrozen`
- `bool` `.bDrone`
- `bool` `.bGhost`
- `bool` `.bExactShooting`
- [`Animation`](#Animation) `.projectile`
- `bool` `.bTyping`
- `std::string` `.race`
- `int` `.currentShip`
- `bool` `.bMale`
- `bool` `.colorblind`
- [`std::vector<GL_Color>`](#GL_Color) `.layerColors`
- `int` `.forcedAnimation`
- `int` `.forcedDirection`
- [`GL_Color`](#GL_Color) `.projectileColor`
- `bool` `.bStunned`
- `bool` `.bDoorTarget`
- `bool` `.uniqueBool1`
- `bool` `.uniqueBool2`
   
## CrewDefinition
   
### Fields
   NOTE: All fields under this object are immutable.
- `std::string` `.race`
- `std::vector<std::string>` `.deathSounds`
- `std::vector<std::string>` `.deathSoundsFemale`
- `std::vector<std::string>` `.shootingSounds`
- `std::vector<std::string>` `.repairSounds`
- `int` `.repairSoundFrame`
- `bool` `.canFight`
- `bool` `.canRepair`
- `bool` `.canSabotage`
- `bool` `.canMan`
- `bool` `.canTeleport`
- `bool` `.canSuffocate`
- `bool` `.controllable`
- `bool` `.selectable`
- `bool` `.canBurn`
- `int` `.maxHealth`
- `float` `.stunMultiplier`
- `float` `.moveSpeedMultiplier`
- `float` `.repairSpeed`
- `float` `.damageMultiplier`
- `float` `.cloneSpeedMultiplier`
- `float` `.rangedDamageMultiplier`
- `float` `.doorDamageMultiplier`
- `bool` `.providesPower`
- `int` `.bonusPower`
- `float` `.fireRepairMultiplier`
- `float` `.suffocationModifier`
- `bool` `.isTelepathic`
- `bool` `.resistsMindControl`
- `bool` `.isAnaerobic`
- `float` `.fireDamageMultiplier`
- `bool` `.canPhaseThroughDoors`
- `float` `.oxygenChangeSpeed`
- `float` `.damageTakenMultiplier`
- `float` `.passiveHealAmount`
- `float` `.truePassiveHealAmount`
- `float` `.healAmount`
- `float` `.trueHealAmount`
- `int` `.passiveHealDelay`
- `bool` `.detectsLifeforms`
- `bool` `.hasCustomDeathAnimation`
- `bool` `.hasDeathExplosion`
- `std::string` `.animBase`
- `std::string` `.animSheet[2]`
- `float` `.sabotageSpeedMultiplier`
- `float` `.allDamageTakenMultiplier`
- `int` `.defaultSkillLevel`
- `float` `.healSpeed`
- `bool` `.cloneLoseSkills`
- `float` `.healCrewAmount`
- `DroneAI` `.droneAI`
- `bool` `.droneMoveFromManningSlot`
- `int` `.powerDrain`
- `bool` `.powerDrainFriendly`
- `float` `.damageEnemiesAmount`
- `bool` `.hackDoors`
- `float` `.powerRechargeMultiplier`
- `float` `.crewSlots`
- `bool` `.noSlot`
- `bool` `.noClone`
- `bool` `.noAI`
- `bool` `.validTarget`
- `ToggleValue<bool>` `.canPunch`
- `bool` `.canMove`
- `bool` `.snapToSlot`
- `bool` `.teleportMove`
- `bool` `.teleportMoveOtherShip`
- `float` `.essential`
- `bool` `.silenced`
- `float` `.lowHealthThreshold`
- `float` `.lowHealthThresholdPercentage`
- `bool` `.noWarning`
- `std::pair<int,int>` `.shootTimer`
- `std::pair<int,int>` `.punchTimer`
- `ExplosionDefinition` `.explosionDef`
- `std::vector<ActivatedPowerDefinition*>` `.powerDefs`
- `std::vector<StatBoostDefinition*>` `.passiveStatBoosts`
- `std::vector<std::string>` `.nameRace`
- `std::vector<std::string>` `.transformName`
- `bool` `.changeIfSame`
- `SkillsDefinition` `.skillsDef`

## ActivatedPower

### Methods
- [`PowerReadyState`](#PowerReadyState) `:PowerReq(ActivatedPowerRequirements *req)`
- [`PowerReadyState`](#PowerReadyState) `:PowerReady()`
- [`Damage`](#Damage) `:GetPowerDamage()`
- `void :ActivateTemporaryPower()`
- `void :TemporaryPowerFinished()`
- `void :PrepareAnimation()`
- `void :PrepareTemporaryAnimation()`
- `void :PreparePower()`
- `void :ActivatePower()`
- `void :CancelPower(bool clearAnim)`
- `void :OnUpdate()`
- `void :ChangePowerDef(ActivatedPowerDefinition *newDef)`
- `void :EnablePower()`
- `void :DisablePower()`
- `void :EnableInit()`
- `int :GetCrewBoxResourceWidth(int mode)`

### Fields
- [`ActivatedPowerDefinition*`](#ActivatedPowerDefinition) `.def`
   - **read-only**
- [`CrewMember*`](#CrewMember) `.crew`
   - **read-only**
- [`CrewMember_Extend*`](#CrewMember_Extend) `.crew_ex`
   - **read-only**
- `bool` `.enabled`
- `float` `.modifiedPowerCharges`
- `float` `.modifiedChargesPerJump`
- `std::pair<float, float>` `.powerCooldown`
- `std::pair<float, float>` `.temporaryPowerDuration`
- `std::pair<int, int>` `.powerCharges`
- [`std::vector<ActivatedPowerResource*>`](#ActivatedPowerResource) `.powerResources`
- `int` `.powerRoom`
- `int` `.powerShip`
- `bool` `.powerActivated`
- `bool` `.temporaryPowerActive`
- `bool` `.powerDone`
- `bool` `.temporaryPowerDone`
- [`unique_ptr<Animation>`](#Animation) `.effectAnim`
- [`unique_ptr<Animation>`](#Animation) `.tempEffectAnim`
- [`unique_ptr<Animation>`](#Animation) `.effectFinishAnim`
- [`std::vector<Animation>`](#Animation) `.extraAnims`
- [`Pointf`](#Pointf) `.effectPos`
- [`Pointf`](#Pointf) `.effectWorldPos`

## ActivatedPowerResource

### Methods
- `void :GetLinkedPowers()`
- [`PowerReadyState`](#PowerReadyState) `:PowerReq(ActivatedPowerRequirements *req)`
- `void :OnUpdate()`
- `void :EnablePower()`
- `void :DisablePower()`
- `void :EnableInit()`
- `int :GetCrewBoxResourceWidth(int mode)`

### Fields
- [`PowerResourceDefinition*`](#PowerResourceDefinition) `.def`
   - **read-only**
- [`CrewMember*`](#CrewMember) `.crew`
   - **read-only**
- [`CrewMember_Extend*`](#CrewMember_Extend) `.crew_ex`
   - **read-only**
- `bool` `.lastEnabled`
- `float` `.modifiedPowerCharges`
- `float` `.modifiedChargesPerJump`
- `std::pair<float, float>` `.powerCooldown`
- `std::pair<int, int>``.powerCharges`

## ActivatedPowerDefinition

### Methods
- `void :AssignIndex()`
- `void :AssignName(std::string name)`
- `void :AssignActivateGroup(std::string name)`
- `void :AssignReplaceGroup(std::string name)`
- `void :AssignGroup(std::string name)`
- `static` [`ActivatedPowerDefinition`](#ActivatedPowerDefinition) `.GetPowerByName(std::string name)`
- `static` [`ActivatedPowerDefinition`](#ActivatedPowerDefinition) `.AddNamedDefinition(std::string name, ActivatedPowerDefinition* copyDef)`

### Fields
- `std::string` `.name`
   - **read-only**
- `int` `.activateGroupIndex`
   - **read-only**
- `int` `.replaceGroupIndex`
   - **read-only**
- `int` `.sortOrder`
- [`Damage`](#Damage) `.damage`
- `float` `.cooldown`
- `bool` `.shipFriendlyFire`
- `bool` `.hasSpecialPower`
- `bool` `.hasTemporaryPower`
- `int` `.jumpCooldown`
- `int` `.disabledCooldown`
- `float` `.initialCooldownFraction`
- `int` `.onDeath`
- `int` `.onHotkey`
- `int` `.powerCharges`
- `int` `.initialCharges`
- `int` `.chargesPerJump`
- `int` `.respawnCharges`
- `int` `.disabledCharges`
- `bool` `.hideCooldown`
- `bool` `.hideCharges`
- `bool` `.hideButton`
- [`std::vector<PowerResourceDefinition*>`](#PowerResourceDefinition) `.powerResources`
- `std::vector<std::string>` `.sounds`
- `std::vector<std::string>` `.effectSounds`
- `bool` `.soundsEnemy`
- `bool` `.effectSoundsEnemy`
- [`TextString`](#TextString) `.buttonLabel`
- [`GL_Color`](#GL_Color) `.cooldownColor`
- [`TextString`](#TextString) `.tooltip`
- `std::string` `.effectAnim`
- `std::string` `.effectPostAnim`
- [`ActivatedPowerRequirements`](#ActivatedPowerRequirements) `.playerReq`
- [`ActivatedPowerRequirements`](#ActivatedPowerRequirements) `.enemyReq`
- [`ActivatedPowerRequirements*`](#ActivatedPowerRequirements) `.chargeReq`
- `bool` `.win`
- `float` `.crewHealth`
- `float` `.enemyHealth`
- `float` `.selfHealth`
- `int` `.animFrame`
- `bool` `.followCrew`
- `bool` `.activateWhenReady`
- `bool` `.activateReadyEnemies`
- `std::string` `.transformRace`
- [`std::vector<CrewSpawn*>`](#CrewSpawn) `.crewSpawns`
- [`std::vector<StatBoostDefinition*>`](#StatBoostDefinition) `.statBoosts`
- [`std::vector<StatBoostDefinition*>`](#StatBoostDefinition) `.roomStatBoosts`
- `std::array<std::string, 2>` `.event`
- [`TemporaryPowerDefinition`](#TemporaryPowerDefinition) `.tempPower`

## PowerResourceDefinition

### Methods
- `void :AssignIndex()`
- `void :AssignName(std::string name)`
- `void :AssignGroup(std::string name)`
- `static` [`PowerResourceDefinition`](#PowerResourceDefinition) `.GetByName(std::string name)`
- `static` [`PowerResourceDefinition`](#PowerResourceDefinition) `.AddNamedDefinition(std::string name, PowerResourceDefinition* copyDef);`

### Fields
- `std::string` `.name`
   - **read-only**
- `int` `.groupIndex`
   - **read-only**
- `int` `.sortOrder`
- `float` `.cooldown`
- `int` `.jumpCooldown`
- `int` `.disabledCooldown`
- `float` `.initialCooldownFraction`
- `int` `.onDeath`
- `int` `.powerCharges`
- `int` `.initialCharges`
- `int` `.chargesPerJump`
- `int` `.respawnCharges`
- `int` `.disabledCharges`
- `bool` `.hideCooldown`
- `bool` `.hideCharges`
- `bool` `.showTemporaryBars`
- `bool` `.showLinkedCooldowns`
- `bool` `.showLinkedCharges`
- [`GL_Color`](#GL_Color) `.cooldownColor`
- [`ActivatedPowerRequirements*`](#ActivatedPowerRequirements) `.chargeReq`

## ActivatedPowerRequirements

### Fields
- [`Type`](#Type) `.Type`
    - Valid values:
        - `Hyperspace.ActivatedPowerRequirements.Type_PLAYER`
        - `Hyperspace.ActivatedPowerRequirements.Type_ENEMY`
        - `Hyperspace.ActivatedPowerRequirements.Type_CHARGE`
        - `Hyperspace.ActivatedPowerRequirements.Type_UNKNOWN`
- `bool` `.playerShip`
- `bool` `.enemyShip`
- `bool` `.checkRoomCrew`
- `bool` `.enemyInRoom`
- `bool` `.friendlyInRoom`
- `std::vector<std::string>` `.whiteList`
- `std::vector<std::string>` `.friendlyWhiteList`
- `std::vector<std::string>` `.friendlyBlackList`
- `std::vector<std::string>` `.enemyWhiteList`
- `std::vector<std::string>` `.enemyBlackList`
- `bool` `.systemInRoom`
- `bool` `.systemDamaged`
- `bool` `.hasClonebay`
- `bool` `.aiDisabled`
- `bool` `.outOfCombat`
- `bool` `.inCombat`
- `int` `.requiredSystem`
- `bool` `.requiredSystemFunctional`
- `ToggleValue<int>` `.minHealth`
- `ToggleValue<int>` `.maxHealth`
- `std::vector<std::pair<CrewExtraCondition,bool>>` `.extraConditions`
- `std::vector<std::pair<CrewExtraCondition,bool>>` `.extraOrConditions`
- [`TextString`](#TextString) `.extraOrConditionsTooltip`

## TemporaryPowerDefinition

### Methods

### Fields
- `float` `.duration`
- `std::string` `.effectAnim`
- `std::string` `.effectFinishAnim`
- `std::string` `.animSheet`
- `bool` `.baseVisible`
- `bool` `.soundsEnemy`
- `std::vector<std::string>` `.sounds`
- `ToggleValue<int>` `.maxHealth`
- `ToggleValue<float>` `.stunMultiplier`
- `ToggleValue<float>` `.moveSpeedMultiplier`
- `ToggleValue<float>` `.damageMultiplier`
- `ToggleValue<float>` `.rangedDamageMultiplier`
- `ToggleValue<float>` `.doorDamageMultiplier`
- `ToggleValue<float>` `.repairSpeed`
- `ToggleValue<float>` `.fireRepairMultiplier`
- `ToggleValue<bool>` `.controllable`
- `ToggleValue<bool>` `.canFight`
- `ToggleValue<bool>` `.canRepair`
- `ToggleValue<bool>` `.canSabotage`
- `ToggleValue<bool>` `.canMan`
- `ToggleValue<bool>` `.canTeleport`
- `ToggleValue<bool>` `.canSuffocate`
- `ToggleValue<bool>` `.canBurn`
- `ToggleValue<float>` `.oxygenChangeSpeed`
- `ToggleValue<bool>` `.canPhaseThroughDoors`
- `ToggleValue<float>` `.fireDamageMultiplier`
- `ToggleValue<bool>` `.isTelepathic`
- `ToggleValue<bool>` `.resistsMindControl`
- `ToggleValue<bool>` `.isAnaerobic`
- `ToggleValue<bool>` `.detectsLifeforms`
- `ToggleValue<float>` `.damageTakenMultiplier`
- `ToggleValue<float>` `.cloneSpeedMultiplier`
- `ToggleValue<float>` `.passiveHealAmount`
- `ToggleValue<float>` `.truePassiveHealAmount`
- `ToggleValue<float>` `.healAmount`
- `ToggleValue<float>` `.trueHealAmount`
- `ToggleValue<int>` `.passiveHealDelay`
- `ToggleValue<float>` `.sabotageSpeedMultiplier`
- `ToggleValue<float>` `.allDamageTakenMultiplier`
- `ToggleValue<float>` `.healSpeed`
- `ToggleValue<float>` `.suffocationModifier`
- `ToggleValue<float>` `.healCrewAmount`
- `ToggleValue<int>` `.powerDrain`
- `ToggleValue<bool>` `.powerDrainFriendly`
- `ToggleValue<int>` `.bonusPower`
- `ToggleValue<float>` `.damageEnemiesAmount`
- `ToggleValue<bool>` `.hackDoors`
- `ToggleValue<float>` `.powerRechargeMultiplier`
- `ToggleValue<bool>` `.noClone`
- `ToggleValue<bool>` `.noAI`
- `ToggleValue<bool>` `.validTarget`
- `ToggleValue<bool>` `.canMove`
- `ToggleValue<bool>` `.teleportMove`
- `ToggleValue<bool>` `.teleportMoveOtherShip`
- `ToggleValue<bool>` `.silenced`
- `ToggleValue<float>` `.lowHealthThreshold`
- [`std::vector<StatBoostDefinition*>`](#StatBoostDefinition) `.statBoosts`
- `bool` `.invulnerable`
- `int` `.animFrame`
- [`GL_Color`](#GL_Color) `.cooldownColor`

## GenericButton

### Methods

- `void :Reset()` 
- `void :SetLocation(Point pos)`
- `void :SetHitBox(Globals::Rect rect)`
- `void :SetActive(bool active)`
- `void :OnLoop()`
- `void :OnRender()`
- `void :MouseMove(int x, int y, bool silent)`
- `void :OnClick()`
- `void :OnRightClick()`
- `void :OnTouch()`
- `void :ResetPrimitives()`

### Fields

- [`Point`](#Point) `.position`
   - Field is **read-only** but fields under this object may still be mutable.
- [`Globals::Rect`](#Globals) `.hitbox` 
   - Field is **read-only** but fields under this object may still be mutable.
- `bool` `.allowAnyTouch`
- `bool` `.touchSelectable`
- `bool` `.bRenderOff`
- `bool` `.bRenderSelected`
- `bool` `.bFlashing`
- `AnimationTracker` `.flashing`
- `bool` `.bActive`
- `bool` `.bHover`
- `bool` `.bActivated`
- `bool` `.bSelected`
- `int` `.activeTouch`

## Button

**Extends [`GenericButton`](#GenericButton)**

### Methods

- `void :OnInit(std::string img, Point pos)`
- `void :OnRender()`
- `void :SetActiveImage(GL_Texture *texture)`
- `void :SetImageBase(std::string imageBase)`
- `void :SetInactiveImage(GL_Texture *texture)`
- `void :SetLocation(Point pos)`

### Fields
- `GL_Texture*[3]` `.images`
- `GL_Primitive*[3]` `.primitives`
- [`Point`](#Point) `.imageSize`
- `bool` `.bMirror`

## EffectsBlueprint

### Fields
- `std::vector<std::string>` `.launchSounds`
- `std::vector<std::string>` `.hitShipSounds`
- `std::vector<std::string>` `.hitShieldSounds`
- `std::vector<std::string>` `.missSounds`
- `string` `.image`

## CommandGui

### Fields
- [`ShipStatus`](#ShipStatus) `.shipStatus`
- [`CrewControl`](#CrewControl) `.crewControl`
- [`SystemControl`](#SystemControl) `.sysControl`
- [`CombatControl`](#CombatControl) `.combatControl`
- [`FTLButton`](#FTLButton) `.ftlButton`
- [`SpaceStatus`](#SpaceStatus) `.spaceStatus`
- ~~`StarMap` `.starMap`~~
   - Access via `WorldManager` instead.
- ~~`ShipComplete` `.shipComplete`~~
- [`Point`](#Point) `.pauseTextLoc`
- [`Point`](#Point) `.shipPosition`
- ~~`string` `.locationText`~~
- ~~`string` `.loadEvent`~~
- ~~`int` `.loadSector`~~
- `bool` `.outOfFuel`
   - **Read-only**
- `bool` `.bPaused`
   - Only true for spacebar pauses, NOT event pauses or ESC menu pauses.
   - Modifying this variable during event pauses and ESC menu pauses does not unfreeze the game; it will only change whether or not the game remains paused when the event or ESC menu closes.
- `bool` `.bAutoPaused`
   - **Read-only**
   - Maybe true for event pauses and ESC menu pauses? Not sure.
- `bool` `.menu_pause`
   - **Read-only**
   - Probably true for ESC menu pauses.
- `bool` `.event_pause`
   - **Read-only**
   - True for event pauses.
- `Button` `.upgradeButton`
   - Field is **read-only** but fields under this object may still be mutable.
- `bool` `.dangerLocation`
   - **Read-only**
- `Equipment` `.equipScreen`
   - Field is **read-only** but fields under this object may still be mutable.
- `bool` `.bHideUI`
- `bool` `.jumpComplete`
   - **Read-only**
- `int` `.mapId`
   - **Read-only**
- `bool` `.secretSector`
   - **Read-only**
- `bool` `.choiceBoxOpen`
   - **Read-only**

## Equipment

### Methods
- `void :AddAugment(AugmentBlueprint *bp, bool free, bool forceCargo)`
- `void :AddDrone(DroneBlueprint *bp, bool free, bool forceCargo)`
- `void :AddToCargo(std::string name)`
- `void :AddWeapon(WeaponBlueprint *bp, bool free, bool forceCargo)`
- `std::vector<std::string> :GetCargoHold()`

## CombatControl

### Fields
- [`Point`](#Point) `.playerShipPosition`
- [`WeaponControl`](#WeaponControl) `weapControl`
- [`Point`](#Point) `.position`
- `int` `.selectedRoom`
- `int` `.selectedSelfRoom`
- [`Point`](#Point) `.targetPosition`
- `bool` `.open`
- [`Pointf`](#Pointf) `.potentialAiming`
- [`std::vector<Pointf*>`](#Pointf) `.aimingPoints`
- `bool` `.mouseDown`
- `bool` `.isAimingTouch`
- `bool` `.movingBeam`
- [`Point`](#Point) `.beamMoveLast`
- `bool` `.invalidBeamTouch`
- `bool` `.boss_visual`
   - **Read-only**

## WeaponControl
**Extends [`ArmamentControl`](#ArmamentControl)**
### Fields
- [`ProjectileFactory`](#ProjectileFactory) `.armedWeapon`
- `bool` `.autoFiring`
   - **Read-only**
- `int` `.armedSlot`

## LocationEvent

### Methods
- [`std::vector<Choice*>`](#Choice) `:GetChoices()`
- `void :AddChoice(LocationEvent *event, std::string text, ChoiceReq req, bool hiddenReward)`
- `bool :RemoveChoice(int index)`

### Fields
- [`TextString`](#TextString) `.text`
- [`ResourceEvent`](#ResourceEvent) `.stuff`
- `int` `.environment`
- `int` `.environmentTarget`
- `bool` `.store`
- `bool` `.gap_ex_cleared`
- `int` `.fleetPosition`
- `bool` `.beacon`
- `bool` `.reveal_map`
- `bool` `.distressBeacon`
- `bool` `.repair`
- `int` `.modifyPursuit`
- `std::string` `.quest`
- `std::string` `.spaceImage`
- `std::string` `.planetImage`
- `std::string` `.eventName`
- [`ResourceEvent`](#ResourceEvent) `.reward`
- [`BoardingEvent`](#BoardingEvent) `.boarders`
- `int` `.unlockShip`
- [`TextString`](#TextString) `.unlockShipText`
- `bool` `.secretSector`
- [`std::vector<Choice>`](#Choice) `.choices`
   - If you want to modify the current `Choice` values please refer to `:GetChoices()` instead

###### Example
```lua
-- Adds to every event choice a new choice with the text "new text" leading to the event "FUEL_FLEET_DELAY"
script.on_internal_event(Defines.InternalEvents.PRE_CREATE_CHOICEBOX, function(event)
   local locEvent = Hyperspace.Event:GetBaseEvent("FUEL_FLEET_DELAY", Hyperspace.App.world.starMap.worldLevel, false, Hyperspace.Global.currentSeed);
   local req = Hyperspace.ChoiceReq()
   req.object = ""
   req.min_level = 0
   req.max_level = 0
   req.max_group = 0
   req.blue = true

   event:AddChoice(locEvent, "choice text", req, false)
end)
```

## Choice

**Internal Struct Of [`LocationEvent`](#LocationEvent)**

### Fields
- [`LocationEvent`](#LocationEvent) `.event`
- [`TextString`](#TextString) `.text`
- [`ChoiceReq`](#ChoiceReq) `.requirement`
- `bool` `.hiddenReward`

## ChoiceReq

### Fields
- `std::string` `.object`
- `int` `.min_level`
- `int` `.max_level`
- `int` `.max_group`
- `bool` `.blue`

## FocusWindow

### Fields
- `bool` `.bOpen`
- `bool` `.bFullFocus`
- `bool` `.bCloseButtonSelected`

## ChoiceBox

**Extends [`FocusWindow`](#FocusWindow)**

### Methods
- [`std::vector<ChoiceText*>`](#ChoiceText) `:GetChoices()`

### Fields
- `std::string` `.mainText`
- [`std::vector<ChoiceText>`](#ChoiceText) `.choices`
   - If you want to modify the current `ChoiceText` values please refer to `:GetChoices()` instead
- `int` `.columnSize`
- [`std::vector<Globals::Rect>`](#Globals) `.choiceBoxes`
- `int` `.potentialChoice`
- `int` `.selectedChoice`
- `int` `.fontSize`
- `bool` `.centered`
- `int` `.gap_size`
- `float` `.openTime`
- [`ResourceEvent`](#ResourceEvent) `.reward`
- [`GL_Color`](#GL_Color) `.currentTextColor`
- [`Pointf`](#Pointf) `.lastChoice`

## ChoiceText

### Fields
- `int` `.type`
- `std::string` `.text`
- [`ResourceEvent`](#ResourceEvent) `.reward`

## ResourceEvent

### Fields
- `int` `.missiles`
- `int` `.fuel`
- `int` `.drones`
- `int` `.scrap`
- `int` `.crew`
- `bool` `.traitor`
- `bool` `.cloneable`
-[ `TextString`](#textstring) `.cloneText`
- `std::string` `.crewType`
- [`WeaponBlueprint`](#weaponblueprint) `.*weapon`
- [`DroneBlueprint`](#droneblueprint) `.*drone`
- [`AugmentBlueprint`](#droneblueprint) `.*augment`
- [`CrewBlueprint`](#crewblueprint) `.crewBlue`
- `int` `.systemId`
- `int` `.weaponCount`
- `int` `.droneCount`
- `bool` `.steal`
- `bool` `.intruders`
- `int` `.fleetDelay`
- `int` `.hullDamage`
- `int` `.upgradeAmount`
- `int` `.upgradeId`
- `int` `.upgradeSuccessFlag`
- `std::string` `.removeItem`

## ScoreKeeper

### Fields
- [`TopScore`](#TopScore) `.currentScore`
   - Field is **read-only** but fields under this object may still be mutable.

## TopScore

### Fields
- `int` `.sector`
- `int` `.score`

## StarMap

### Methods

- `void :ModifyPursuit(int amount)` 
- `Point :PointToGrid(float x, float y)`
- `void :ForceWaitMessage(GL_Primitive waitMessage)`
   - Disables the ability to jump and enables the wait/distress menu. Replaces the "NO FUEL" message shown on the sector map with a primitive of your own.
   - NOTE: The primitive should be a local or global variable. If it is garbage collected while in use this will lead to a crash.
   - If no argument is passed, then the jump menu is re-enabled and the "NO FUEL" message is restored.
   
[[/img/lua-hyperspace-module/map_fuel_text_nofuel.png]]



### Fields

- `std::vector<Location>` `.locations`
   - **Read-only**
- [`Location`](#Location) `.currentLoc`
- [`std::vector<Sector*>`](#sector) `.sectors`
- [`Sector`](#Sector) `.currentSector`
- `bool` `.bChoosingNewSector`
- `bool` `.bSecretSector`
- `int` `.pursuitDelay`
- `GL_Primitive` `.ship`
   - The map icon that rotates around the current location representing the player ship.
- `GL_Primitive` `.shipNoFuel`
   - The no fuel variant of the `ship` icon.
- `int` `.worldLevel`
   - **Read-only**
- `bool` `.bTutorialGenerated`

## Location

### Fields

- [`Pointf`](#Pointf) `.loc`
- [`std::vector<Location>`](#Location) `.connectedLocations`
- `bool` `.beacon`
- `bool` `.known`
- `int` `.visited`
- `bool` `.dangerZone`
- `bool` `.nebula`
   - Grant the fleet delay of nebula, no changes to the event itself
- `bool` `.boss`
   - Final boss event overrides the beacon, no visual indication.
- [`LocationEvent`](#LocationEvent) `.event`
- [`ImageDesc`](#ImageDesc) `.planet`
- [`ImageDesc`](#ImageDesc) `.space`
- `bool` `.fleetChanging`
- `std::string` `.planetImage`
- `std::string` `.spaceImage`

## Sector

### Fields
- `bool` `.visited`
- `int` `.level`
- [`SectorDescription`](#SectorDescription) `.description`
   - Field is **read-only** but fields under this object may still be mutable.

## SectorDescription

### Fields
- [`TextString`](#TextString) `.name`
- [`TextString`](#TextString) `.shortName`
- `std::string` `.type`

## TextLibrary

### Methods

- `std::string :GetText(std::string name)`
   - Retrieve the corresponding text string from the `text_` xml files in the current language.

## TextString

### Methods

- `std::string :GetText()`
   - If `.isLiteral` is true, this gets the value of `.data`, otherwise it gets the text referring to the text id from the value of `.data`.

### Fields

- `std::string` `.data`
   - You can change the text by setting this value.
   - If `.isLiteral` is true, this stores the text itself, otherwise it stores the text id.
- `bool` `.isLiteral`
   - If true, the game will display the value of `.data`, otherwise it will refer to the text id from the value of `.data`.
###### Example
```lua
-- Set the texts of all choices in an event to 'new text'
script.on_internal_event(Defines.InternalEvents.PRE_CREATE_CHOICEBOX, function(event)
   local choices = event:GetChoices()
   for i = 0, choices:size() - 1 do
      local choice = choices[i]
      choice.text.isLiteral = true
      choice.text.data = 'new text'
   end
end)
```

## Description

### Fields

- [`TextString`](#TextString) `.title`
- [`TextString`](#TextString) `.shortTitle`
- [`TextString`](#TextString) `.description`
- `int` `.cost`
- `int` `.rarity`
- `int` `.baseRarity`
- `int` `.bp`
- `bool` `.locked`
- [`TextString`](#TextString) `.tooltip`
- `std::string` `.tip`

## CrewDesc

### Fields

- `std::string` `.type`
- `float` `.prop`
- `int` `.amount`

## Globals

### Methods
- `float :AimAhead(Pointf delta, Pointf vr, float muzzleV)`
- [`Pointf`](#Pointf) `:GetNextPoint(Pointf current, float mag_speed, float heading)`
- [`Pointf`](#Pointf) `:GetNextPoint(Pointf current, float mag_speed, Pointf dest)`
- `int :GetNextSpaceId()`

## Ellipse

**Internal struct of [`Globals`](#Globals)**

### Fields
- [`Point`](#Point) `.center`
- `float` `.a`
- `float` `.b`

## Rect

**Internal struct of [`Globals`](#Globals)**

### Fields
- `int` `.x`
- `int` `.y`
- `int` `.w`
- `int` `.h`

## ImageDesc

### Fields
- [`GL_Texture`](#GL_Texture) `.tex`
- `float` `.resId`
- `float` `.w`
- `float` `.h`
- `float` `.x`
- `float` `.y`
- `float` `.rot`

## BoardingEvent

### Fields
- `std::string` `.type`
- `int` `.min`
- `int` `.max`
- `int` `.amount`
- `bool` `.breach`

## CustomShipUnlocks

Accessed via `Hyperspace.CustomShipUnlocks.instance`

### Methods
- `void :UnlockShip(std::string shipBlueprint, bool silent, bool checkMultiUnlocks=true, bool isEvent=false)`
- `bool :GetCustomShipUnlocked(std::string name, int variant = 0)`
   - 0 being ship variant A, 1 is ship variant B and 2 is ship variant C

### Fields
- `static` [`CustomShipUnlocks`](#CustomShipUnlocks) `.instance`

## Selectable

### Fields
- `int` `.selectedState`

## Repairable

**Extends [Selectable](#Selectable)**

### Fields
- [`ShipObject`](#ShipObject) `.shipObj`
- `float` `.fDamage`
- [`Point`](#Point) `.pLoc`
- `float` `.fMaxDamage`
- `std::string` `.name`
- `int` `.roomId`
- `int` `.iRepairCount`

## Spreadable

**Extends [Repairable](#Repairable)**

### Fields
- `std::string` `.soundName`

## Fire

**Extends [Spreadable](#Spreadable)**

### Methods
- `void :OnLoop()`
- `void :UpdateDeathTimer(int connectedFires)`
- `void :UpdateStartTimer(int doorLevel)`

### Fields
- `float` `.fDeathTimer`
- `float` `.fStartTimer`
- `float` `.fOxygen`
- [`Animation`](#Animation) `.fireAnimation`
- [`Animation`](#Animation) `.smokeAnimation`
- `bool` `.bWasOnFire`

## Spreader_Fire

**Extends [ShipObject](#Shipobject)**

### Fields
- `int` `.count`
- `std::vector<int>` `.roomCount`
- [`std::vector<std::vector<Fire>>`](#Fire) `.grid`

## OuterHull

**Extends [Repairable](#Repairable)**

### Fields
- [`Animation`](#Animation) `.breach`
- [`Animation`](#Animation) `.heal`

## PowerManager

### Methods
- `int :GetAvailablePower()`
- `int :GetMaxPower()`
- `static` [`PowerManager`](#PowerManager) `.GetPowerManager(int iShipId)`

### Fields
- `std::pair<int, int>` `.currentPower`
- `int` `.over_powered`
- `float` `.fFuel`
- `bool` `.failedPowerup`
- `int` `.iTempPowerCap`
- `int` `.iTempPowerLoss`
- `int` `.iTempDividePower`
- `int` `.iHacked`
- `std::pair<int, int>` `.batteryPower`

## CustomAugmentManager

Accessed via `Hyperspace.CustomAugmentManager.GetInstance()`

### Methods
- `static` [`CustomAugmentManager*`](#CustomAugmentManager) `.GetInstance()`
- [`AugmentDefinition*`](#AugmentDefinition) `CustomAugmentManager::GetAugmentDefinition(const std::string &name)`

## AugmentFunction

### Methods
- `bool :Functional(int iShipId)`

### Fields
**All fields are read-only**
- `float` `.value`
- `bool` `.preferHigher`
- `bool` `.useForReqs`
- `bool` `.warning`
- `int` `.sys`
- `bool` `.modifyChoiceTextScrap`

## AugmentSuperShield

### Fields
**All fields are read-only**
- `int` `.value`
- `int` `.add`
- `bool` `.customRender`
- `bool` `.present`
- `std::string[2]` `.shieldTexture`
- [`GL_Color`](#GL_Color) `.shieldColor`

## AugmentCrystalShard

### Fields
**All fields are read-only**
- `std::string` `.weapon`
- `float` `.chance`
- `int` `.stacking`

## AugmentDefinition

### Fields
**All fields are read-only**
- `std::string` `.name`
- [`std::unordered_multimap<std::string, AugmentFunction>`](#AugmentFunction) `.functions`
- [`AugmentSuperShield`](#AugmentSuperShield) `.superShield`
- [`std::vector<AugmentCrystalShard>`](#AugmentCrystalShard) `.crystalShard`
- `bool` `.locked`
- [`std::vector<StatBoostDefinition*>`](#StatBoostDefinition) `.statBoosts`
- `std::string` `.icon`
- `int` `.iconShipId`

## ProjectileFactory

**Extends [ShipObject](#ShipObject)**

### Methods
- `void :Fire(std::vector<Pointf> points, int target)`
- `bool :FireNextShot()`
- `void :ForceCoolup()`
- [`Projectile*`](#Projectile) `:GetProjectile()`
- `bool :IsChargedGoal()`
- `int :NumTargetsRequired()`
- `void :SetCooldownModifier(float mod)`
- `void :SetCurrentShip(Targetable *ship)`
- `void :SetHacked(int hacked)`

### Fields
- `std::pair<float, float>` `.cooldown`
- `std::pair<float, float>` `.subCooldown`
- `float` `.baseCooldown`
- [`WeaponBlueprint*`](#WeaponBlueprint) `.blueprint`
- [`Point`](#Point) `.localPosition`
- [`Animation`](#Animation) `.flight_animation`
- `bool` `.autoFiring`
- `bool` `.fireWhenReady`
- `bool` `.powered`
- `int` `.requiredPower`
- [`std::vector<Pointf>`](#Pointf) `.targets`
- [`std::vector<Pointf>`](#Pointf) `.lastTargets`
- `int` `.targetId`
- `int` `.iAmmo`
- `std::string` `.name`
- `int` `.numShots`
- `float` `.currentFiringAngle`
- `float` `.currentEntryAngle`
- [`Targetable*`](#Targetable) `.currentShipTarget`
- [`CloakingSystem*`](#CloakingSystem) `.cloakingSystem`
- [`WeaponAnimation`](#WeaponAnimation) `.weaponVisual`
- [`WeaponMount`](#WeaponMount) `.mount`
- [`std::vector<Projectile*>`](#Projectile) `.queuedProjectiles`
- `int` `.iBonusPower`
- `bool` `.bFiredOnce`
- `int` `.iSpendMissile`
- `float` `.cooldownModifier`
- `int` `.shotsFiredAtTarget`
- `int` `.radius`
- `int` `.boostLevel`
- `int` `.lastProjectileId`
- `int` `.chargeLevel`
- `int` `.iHackLevel`
- `int` `.goalChargeLevel`
- `bool` `.isArtillery`

## WeaponMount

### Fields
- [`PowerManager`](#PowerManager) `.position`
- `bool` `.mirror`
- `bool` `.rotate`
- `int` `.slide`
- `int` `.gib`

## AnimationControl

### Methods
- [`Animation`](#Animation) `:GetAnimation(std::string animName)`

## AnimationDescriptor

### Fields
- `int` `.numFrames`
- `int` `.imageWidth`
- `int` `.imageHeight`
- `int` `.stripStartY`
- `int` `.stripStartX`
- `int` `.frameWidth`
- `int` `.frameHeight`

## WeaponAnimation

### Methods
- [`Pointf`](#Pointf) `:GetSlide()`
- `void :SetFireTime(float time)`

### Fields

- `Animation` `.anim;`
- `bool` `.bFireShot;`
- `bool` `.bFiring;`
- `float` `.fChargeLevel;`
- `int` `.iChargedFrame;`
- `int` `.iFireFrame;`
- `bool` `.bMirrored;`
- `bool` `.bRotation;`
- [`Point`](#Point) `.fireLocation;`
- `bool` `.bPowered;`
- [`Point`](#Point) `.mountPoint;`
- [`Point`](#Point) `.renderPoint;`
- [`Point`](#Point) `.fireMountVector;`
- [`AnimationTracker`](#AnimationTracker) `.slideTracker;`
- `int` `.slideDirection;`
- [`Animation`](#Animation) `.explosionAnim;`
- [`WeaponMount`](#WeaponMount) `.mount;`
- `float` `.fDelayChargeTime;`
- [`Animation`](#Animation) `.boostAnim;`
- `int` `.boostLevel;`
- `bool` `.bShowCharge;`
- `float` `.fActualChargeLevel;`
- `int` `.iChargeOffset;`
- `int` `.iChargeLevels;`
- `int` `.currentOffset;`
- `int` `.iHackLevel;`
- [`Animation`](#Animation) `.hackSparks;`
- `bool` `.playerShip;`

## Animation

### Methods
- `void :AddSoundQueue(int frame, std::string sound)`
- `bool :Done()`
- `void :LoadState(int fd)`
- `void :OnRender(float opacity, GL_Color color, bool mirror)`
- `int :RandomStart()`
- `void :SaveState(int fd)`
- `void :SetAnimationId(GL_Texture *tex)`
- `void :SetCurrentFrame(int frame)`
- [`GL_Texture`](#GL_Texture) `:SetProgress(float progress)`
- `void :Start(bool reset)`
- `void :StartReverse(bool reset)`
- `void :Update()`

### Fields
- [`GL_Texture*`](#GL_Texture) `.animationStrip`
- [`AnimationDescriptor`](#AnimationDescriptor) `.info`
- [`AnimationTracker`](#AnimationTracker) `.tracker`
- [`Pointf`](#Pointf) `.position`
- `std::string` `.soundForward`
- `std::string` `.soundReverse`
- `bool` `.randomizeFrames`
- `float` `.fScale`
- `float` `.fYStretch`
- `int` `.currentFrame`
- `bool` `.bAlwaysMirror`
- `std::vector<std::vector<std::string>>` `.soundQueue`
- `float` `.fadeOut`
- `float` `.startFadeOut`
- `std::string` `.animName`
- `int` `.mask_x_pos`
- `int` `.mask_x_size`
- `int` `.mask_y_pos`
- `int` `.mask_y_size`
- [`GL_Primitive*`](#GL_Primitive) `.primitive`
- [`GL_Primitive*`](#GL_Primitive) `.mirroredPrimitive`

## Door

**Extends [CrewTarget](#CrewTarget)**

### Methods
- `bool :ApplyDamage(float amount)`

### Fields
- `int` `.iRoom1`
- `int` `.iRoom2`
- `bool` `.bOpen`
- `int` `.iBlast`
- `bool` `.bFakeOpen`
- `int` `.width`
   - **read-only**
- `int` `.height`
   - **read-only**
- [`GL_Primitive*`](#GL_Primitive) `.outlinePrimitive`
- [`GL_Primitive*`](#GL_Primitive) `.highlightPrimitive`
- [`Animation`](#Animation) `.doorAnim`
- [`Animation`](#Animation) `.doorAnimLarge`
- `int` `.iDoorId`
   - **read-only**
- `int` `.baseHealth`
- `int` `.health`
- [`AnimationTracker`](#AnimationTracker) `.forcedOpen`
- [`AnimationTracker`](#AnimationTracker) `.gotHit`
- `int` `.doorLevel`
- `bool` `.bIoned`
- `float` `.fakeOpenTimer`
- [`AnimationTracker`](#AnimationTracker) `.lockedDown`
- `float` `.lastbase`
- `int` `.iHacked`
- `int` `.x`
   - **read-only**
- `int` `.y`
   - **read-only**
- `bool` `.bVertical`
   - **read-only**

## BlueprintManager

### Methods
- [`AugmentBlueprint`](#AugmentBlueprint) `:*GetAugmentBlueprint(std::string name)`
- [`CrewBlueprint`](#CrewBlueprint) `:GetCrewBlueprint(std::string name)`
- [`DroneBlueprint`](#DroneBlueprint) `:*GetDroneBlueprint(std::string name)`
- [`ShipBlueprint`](#ShipBlueprint) `:*GetShipBlueprint(std::string name, int sector)`
- [`WeaponBlueprint`](#WeaponBlueprint) `:*GetWeaponBlueprint(std::string name)`
- `std::vector<std::string> :GetBlueprintList(std::string name)`

## AugmentBlueprint

**Extends [Blueprint](#Blueprint)**

### Fields
- `float` `.value`
- `bool` `.stacking`

## WeaponBlueprint

**Extends [Blueprint](#Blueprint)**

### Fields
- `std::string` `.typeName`
- [`Damage`](#Damage) `.damage`
- `int` `.shots`
- `int` `.missiles`
- `float` `.cooldown`
- `int` `.power`
- `int` `.length`
- `float` `.speed`
- `int` `.miniCount`
- [`EffectsBlueprint`](#EffectsBlueprint) `.effects`
- `std::string` `.weaponArt`
- `std::string` `.combatIcon`
- `std::string` `.explosion`
- `int` `.radius`
- [`std::vector<WeaponBlueprint::MiniProjectile>`](#WeaponBlueprint) `.miniProjectiles`
- [`WeaponBlueprint::BoostPower`](#WeaponBlueprint) `.boostPower`
- `int` `.drone_targetable`
- `int` `.spin`
- `int` `.chargeLevels`
- [`TextString`](#TextString) `.flavorType`
- [`GL_Color`](#GL_Color) `.color`

## BoostPower

**Internal struct of [`WeaponBlueprint`](#WeaponBlueprint)**

### Fields

- `int` `.type`
- `float` `.amount`
- `int` `.count`

## MiniProjectile

**Internal struct of [`WeaponBlueprint`](#WeaponBlueprint)**

### Fields

- `std::string` `.image`
- `bool` `.fake`

## ShipBlueprint

### Fields
- [`Description`](#Description) `.desc`
- `std::string` `.blueprintName`
- [`TextString`](#TextString) `.name`
- [`TextString`](#TextString) `.shipClass`
- `std::string` `.layoutFile`
- `std::string` `.imgFile`
- `std::string` `.cloakFile`
- `std::string` `.shieldFile`
- `std::string` `.floorFile`
- [`map<int, SystemTemplate>`](#SystemTemplate) `.systemInfo`
- `std::vector<int>` `.systems`
- `int` `.droneCount`
- `int` `.originalDroneCount`
- `int` `.droneSlots`
- `std::string` `.loadDrones`
- `std::vector<std::string>` `.drones`
- `std::vector<std::string>` `.augments`
- `int` `.weaponCount`
- `int` `.originalWeaponCount`
- `int` `.weaponSlots`
- `std::string` `.loadWeapons`
- `std::vector<std::string>` `.weapons`
- `int` `.missiles`
- `int` `.drone_count`
- `int` `.health`
- `int` `.originalCrewCount`
- `std::vector<std::string>` `.defaultCrew`
- [`std::vector<CrewBlueprint>`](#CrewBlueprint) `.customCrew`
- `int` `.maxPower`
- `int` `.boardingAI`
- `int` `.bp_count`
- `int` `.maxCrew`
- `int` `.maxSector`
- `int` `.minSector`
- [`TextString`](#TextString) `.unlock`

## SystemTemplate

**Internal struct of [`ShipBlueprint`](#ShipBlueprint)**

### Fields

- `int` `systemId`
- `int` `powerLevel`
- `std::vector<int>` `location`
- `int` `bp`
- `int` `maxPower`
- `std::string` `image`
- `int` `slot`
- `int` `direction`
- `std::vector<std::string>` `weapon`

## CustomShipDefinition

### Methods

### Fields
- `std::string` `.name`
- `std::map<std::string, int>` `.hiddenAugs`
- [`std::vector<CrewPlacementDefinition>`](#CrewPlacementDefinition) `.crewList`
- `bool` `.noJump`
- `bool` `.noFuelStalemate`
- `int` `.hpCap`
- `int` `.startingFuel`
- `int` `.startingScrap`
- [`std::unordered_map<int, RoomDefinition*>`](#RoomDefinition) `.roomDefs`
- `std::vector<std::string>` `.shipIcons`
- `bool` `.forceAutomated`
- `int` `.crewLimit`
- `int` `.systemLimit`
- `int` `.subsystemLimit`
- `std::vector<int>` `.reactorPrices`
- `int` `.reactorPriceIncrement`
- `int` `.maxReactorLevel`
- `std::string` `.shipGenerator`

## CrewPlacementDefinition

### Fields
- `std::string` `.species`
- `int` `.roomId`
- `std::string` `.name`
- `bool` `.isList`

## CrewBlueprint

**Extends [Blueprint](#Blueprint)**

### Methods
- [`GL_Color`](#GL_Color) `:GetCurrentSkillColor(int skill)`
- `std::string :GetNameShort()`
- `void :RandomSkills(int worldLevel)`
- `void :RenderIcon(float opacity)`
- `void :RenderSkill(int x, int y, int length, int height, int skill)`

### Fields
- [`TextString`](#TextString) `.crewNameLong`
- [`std::vector<TextString>`](#TextString) `.powers`
- `bool` `.male`
- `std::vector<std_pair_int_int>` `.skillLevel`
- `std::vector<GL_Color>>` `.colorLayers`
- `std::vector<int>` `.colorChoices`

## Blueprint

### Methods
- `std::string :GetNameLong()`
- `std::string :GetNameShort()`
- `int :GetType()`

### Fields
- `std::string` `.name`
- [`Description`](#Description) `.desc`
- `int` `.type`

## ShipGraph

Accessed via `Hyperspace.ShipGraph.GetShipInfo(int shipId)`

### Methods
- [`Point`](#Point) `:TranslateFromGrid(int xx, int yy)`
- [`Point`](#Point) `:TranslateToGrid(int xx, int yy)`
- [`Point`](#Point) `:GetIntoRoom(int roomId, Point pos)`
- [`Pointf`](#Pointf) `:GetRoomCenter(int roomId)`
- `void :ComputeCenter()`
- `int :ConnectedGridSquares(int x1, int y1, int x2, int y2)`
- `int :ConnectedGridSquaresPoint(Point p1, Point p2)`
- [`Door`](#Door) `:*ConnectingDoor(int x1, int y1, int x2, int y2)`
- [`Door`](#Door) `:*ConnectingDoor(Point p1, Point p2)`
- `bool :ContainsPoint(int x, int y)`
- `float :ConvertToLocalAngle(float ang)`
- [`Pointf`](#Pointf) `:ConvertToLocalPosition(Pointf world, bool past)`
- `float :ConvertToWorldAngle(float ang)`
- [`Pointf`](#Pointf) `:ConvertToWorldPosition(Pointf local)`
- [`Path`](#Path) `:Dijkstra(Point start, Point goal, int shipId)`
- `int :DoorCount(int roomId)`
- [`Path`](#Path) `:FindPath(Point p1, Point p2, int shipId)`
- [`Slot`](#Slot) `:GetClosestSlot(Point pos, int shipId, bool intruder)`
- [`std::vector<Door*>`](#Door) `:GetDoors(int roomId)`
- `int :GetNumSlots(int room)`
- `bool :GetRoomBlackedOut(int room)`
- `float :GetRoomOxygen(int room)`
- [`Rect`](#Rect) `:GetRoomShape(int room)`
- `int :GetSelectedRoom(int x, int y, bool unk)`
- `static` [`ShipGraph`](#ShipGraph) `.GetShipInfo(int shipId)`
- [`Point`](#Point) `:GetSlotWorldPosition(int slotId, int roomId)`
- `bool :IsRoomConnected(int room1, int room2)`
- `int :PopClosestDoor(std::vector<int> doors, std::vector<float> distances)`
- `int :RoomCount()`

### Fields
- [`std::vector<Room*>`](#Room) `.rooms`
- [`std::vector<Door*>`](#Door) `.doors`
- `std::vector<int>` `.doorCounts`
- [`Point`](#Point) `.center`
- [`Pointf`](#Pointf) `.worldPosition`
- `float` `.worldHeading`
- [`Pointf`](#Pointf) `.lastWorldPosition`
- `float` `.lastWorldHeading`
- [`Rect`](#Rect) `.shipBox`
- `std::string` `.shipName`

## ShieldPower

### Fields
- `int` `.first`
- `int` `.second`
- `std::pair<int, int>` `.super`

## Damage

### Fields
- `int` `.iDamage`
- `int` `.iShieldPiercing`
- `int` `.fireChance`
- `int` `.breachChance`
- `int` `.stunChance`
- `int` `.iIonDamage`
- `int` `.iSystemDamage`
- `int` `.iPersDamage`
- `bool` `.bHullBuster`
- `int` `.ownerId`
- `int` `.selfId`
- `bool` `.bLockdown`
- `bool` `.crystalShard`
- `bool` `.bFriendlyFire`
- `int` `.iStun`

## Collideable

### Methods
- [`CollisionResponse`](#CollisionResponse) `:CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)`
- `bool :DamageBeam(Pointf current, Pointf last, Damage damage)`
- `bool :DamageArea(Pointf location, Damage damage, bool forceHit)`
- `bool :DamageShield(Pointf location, Damage damage, bool forceHit)`
- `bool :GetDodged()`
- [`Pointf`](#Pointf) `:GetSuperShield()`
- `void :SetTempVision(Pointf location)`
- `int :GetSpaceId()`
- `int :GetSelfId()`
- `int :GetOwnerId()`
- `bool :ValidTargetLocation(Pointf location)`

## CollisionResponse

### Fields
- `int` `.collision_type`
- [`Pointf`](#Pointf) `.point`
- `int` `.damage`
- `int` `.superDamage`

## Projectile

**Extends [Collideable](#Collideable)**

### Methods
- `void :SetWeaponAnimation(WeaponAnimation animation)`
- `void :OnRenderSpecific(int spaceId)`
- `void :CollisionCheck(Collideable *other)`
- `void :OnUpdate()`
- [`Pointf`](#Pointf) `:GetWorldCenterPoint()`
- [`Pointf`](#Pointf) `:GetRandomTargettingPoint(bool valuable)`
- `void :ComputeHeading()`
- `void :SetDestinationSpace(int space)`
- `void :EnterDestinationSpace()`
- `bool :Dead()`
- `bool :ValidTarget()`
- `void :Kill()`
- [`Pointf`](#Pointf) `:GetSpeed()`
- `void :SetDamage(Damage damage)`
- `int :ForceRenderLayer()`
- `void :SetSpin(float spin)`
- `void :SaveProjectile(int fd)`
- `void :LoadProjectile(int fd)`
- `int :GetType()`
- `void :SetMovingTarget(Targetable *target)`
- [`CollisionResponse`](#CollisionResponse) `:CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)`
- `void :Initialize(WeaponBlueprint bp)`
- `static` [`Pointf`](#Pointf) `.RandomSidePoint(int side)`
- `void :constructor(Pointf position, int ownerId, int targetId, Pointf target)`

### Fields
- [`Targetable`](#Targetable) `._targetable`
- [`Pointf`](#Pointf) `.position`
- [`Pointf`](#Pointf) `.last_position`
- `float` `.speed_magnitude`
- [`Pointf`](#Pointf) `.target`
- `float` `.heading`
- `int` `.ownerId`
- `int` `.selfId`
   - **read-only**
- [`Damage`](#Damage) `.damage`
- `float` `.lifespan`
- `int` `.destinationSpace`
- `int` `.currentSpace`
- `int` `.targetId`
- `bool` `.dead`
- [`Animation`](#Animation) `.death_animation`
- [`Animation`](#Animation) `.flight_animation`
- [`Pointf`](#Pointf) `.speed`
- `bool` `.missed`
- `bool` `.hitTarget`
- `std::string` `.hitSolidSound`
- `std::string` `.hitShieldSound`
- `std::string` `.missSound`
- `float` `.entryAngle`
- `bool` `.startedDeath`
- `bool` `.passedTarget`
- `bool` `.bBroadcastTarget`
- [`AnimationTracker`](#AnimationTracker) `.flashTracker`
- [`GL_Color`](#GL_Color) `.color`
- [`Projectile_Extend`](#Projectile_Extend) `.extend`
   - **read-only**

## Projectile_Extend

Accessed via `Projectile`'s `.extend` field 

### Fields
- [`Projectile*`](#Projectile) `.orig`
- `std::string` `.name`
- [`CustomDamage`](#CustomDamage) `.customDamage`
- `std::vector<int>` `.missedDrones`

## CustomDamage

### Methods
- `void :Clear()`

### Fields
- [`CustomDamageDefinition*`](#CustomDamageDefinition) `.def`
- `int` `.sourceShipId`
- `int` `.accuracyMod`
- `int` `.droneAccuracyMod`

## CustomDamageDefinition

### Methods
- `void :GiveId()`

### Fields
- `int` `.idx`
   - **read-only**
- `int` `.accuracyMod`
- `int` `.droneAccuracyMod`
- `bool` `.noSysDamage`
- `bool` `.noPersDamage`
- `bool` `.ionBeamFix`
- `int` `.statBoostChance`
- `int` `.roomStatBoostChance`
- [`std::vector<StatBoostDefinition*>`](#StatBoostDefinition) `.statBoosts`
   - **read-only**
- [`std::vector<StatBoostDefinition*>`](#StatBoostDefinition) `.roomStatBoosts`
   - **read-only**
- `int` `.erosionChance`
- [`ErosionEffect`](#ErosionEffect) `.erosionEffect`
- `int` `.crewSpawnChance`
- [`std::vector<CrewSpawn*>`](#CrewSpawn) `.crewSpawns`
   - **read-only**

## LaserBlast

**Extends [Collideable](#Collideable)**

### Fields
- [`Targetable*`](#Targetable) `.movingTarget`
- `float` `.spinAngle`
- `float` `.spinSpeed`

## Asteroid

**Extends [Projectile](#Projectile)**

## Methods
- `static` [`Asteroid*`](#Asteroid) `.Asteroid(Pointf pos, int destinationSpace)`

### Fields
- [`GL_Texture*`](#GL_Texture) `.imageId`
- `float` `.angle`

## Missile

**Extends [Projectile](#Projectile)**

## Methods
- `static` [`Missile*`](#Missile) `.Missile(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)`

## BombProjectile

**Extends [Projectile](#Projectile)**

## Methods
- `static` [`BombProjectile*`](#BombProjectile) `.BombProjectile(Pointf _position, int _ownerId, int _targetId, Pointf _target)`

### Fields
- `bool` `.bMissed`
- [`DamageMessage*`](#DamageMessage) `.missMessage`
- `float` `.explosiveDelay`
- `bool` `.bSuperShield`
- `bool` `.superShieldBypass`

## BeamWeapon

**Extends [Projectile](#Projectile)**

### Methods
- [`BeamWeapon`](#BeamWeapon) `:BeamWeapon(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float _heading = 0.0f)`

### Fields
- [`Pointf`](#Pointf) `.sub_end`
- [`Pointf`](#Pointf) `.sub_start`
- [`Pointf`](#Pointf) `.shield_end`
- [`Pointf`](#Pointf) `.final_end`
- [`Pointf`](#Pointf) `.target2`
- [`Pointf`](#Pointf) `.target1`
- `float` `.lifespan`
- `float` `.length`
- `float` `.dh`
- [`CollisionResponse`](#CollisionResponse) `.last_collision`
- `int` `.soundChannel`
- [`std::vector<Animation>`](#Animation) `.contactAnimations`
- `float` `.animationTimer`
- `int` `.lastDamage`
- [`Targetable*`](#Targetable) `.movingTarget`
- `float` `.start_heading`
- `float` `.timer`
- [`WeaponAnimation*`](#WeaponAnimation) `.weapAnimation`
- `bool` `.piercedShield`
- `bool` `.oneSpace`
- `bool` `.bDamageSuperShield`
- `int` `.movingTargetId`
- `bool` `.checkedCollision`
- [`std::vector<Animation>`](Animation) `.smokeAnims`
- [`Pointf`](#Pointf) `.lastSmokeAnim`

## PDSFire

**Extends [LaserBlast](#LaserBlast)**

### Methods
- [`PDSFire`](#PDSFire) `:PDSFire(Point pos, int destinationSpace, Pointf destination) : LaserBlast(Pointf(pos.x, pos.y), 0, destinationSpace, destination)`

### Fields
- [`Pointf`](#Pointf) `.startPoint`
- `bool` `.passedTarget`
- `float` `.currentScale`
- `bool` `.missed`
- [`Animation`](#Animation) `.explosionAnimation`

## ShipGenerator

### Methods
- `std::vector<int> :GenerateSystemMaxes(ShipBlueprint ship, int level)`
- [`std::vector<CrewBlueprint>`](#CrewBlueprint) `:GetPossibleCrewList(ShipManager *ship, std::string crewList, unsigned int flags)`
- [`std::vector<DroneBlueprint*>`](#DroneBlueprint) `:GetPossibleDroneList(ShipManager *ship, std::string droneList, int scrap, unsigned int flags, bool repeat)`
- `std::vector<int> :GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> systemMaxes, int scrap, int type)`
- [`std::vector<WeaponBlueprint*>`](#WeaponBlueprint) `:GetPossibleWeaponList(ShipManager *ship, std::string weaponList, int scrap, unsigned int flags)`
- `bool :UpgradeSystem(ShipManager *ship, std::vector<int> systemMaxes, unsigned int sysId)`

## CustomShipGenerator

### Methods

- [`ShipManager`](#ShipManager) `:CreateShip(ShipBlueprint *shipBlueprint, int sector, ShipEvent event)`

## AnimationTracker

### Methods
- `float :GetAlphaLevel(bool reverse)`
- `float :Progress(float speed)`
- `void :SetLoop(bool loop, float loopDelay)`
- `void :SetProgress(float time)`
- `void :Start(float time)`
- `void :StartReverse(float time)`
- `void :Stop(bool resetTime)`

### Fields
- `float` `.time`
- `bool` `.loop`
- `float` `.current_time`
- `bool` `.running`
- `bool` `.reverse`
- `bool` `.done`
- `float` `.loopDelay`
- `float` `.currentDelay`

## TimerHelper

### Methods
- `static` [`TimerHelper`](#TimerHelper) `.TimerHelper(bool isLoop=false)`
- `void :Start(float goal)`
- `bool :Done()`
- `void :ResetMinMax(int min, int max)`
- `bool :Running()`
- `void :SetMaxTime(float max)`
- `void :Start(int goal)`
- `void :Stop()`
- `void :Update()`

### Fields
- `int` `.maxTime`
- `int` `.minTime`
- `float` `.currTime`
- `float` `.currGoal`
- `bool` `.loop`
- `bool` `.running`

## SoundControl

### Methods
- `int :PlaySoundMix(std::string soundName, float volume, bool loop)`
- `void :StopChannel(int channel, float fade)`
   - The channel value is given by `PlaySoundMix`
   - `fade` is counted in milliseconds

## SettingValues

### Fields
**All fields are read-only**
- `int` `.fullscreen`
- `int` `.currentFullscreen`
- `int` `.lastFullscreen`
- `int` `.sound`
- `int` `.music`
- `int` `.difficulty`
- `bool` `.commandConsole`
- `bool` `.altPause`
- `bool` `.touchAutoPause`
- `bool` `.lowend`
- `bool` `.fbError`
- `std::string` `.language`
- `bool` `.languageSet`
- [`Point`](#Point) `.screenResolution`
- `int` `.dialogKeys`
- `bool` `.logging`
- `bool` `.bShowChangelog`
- `int` `.loadingSaveVersion`
- `bool` `.achPopups`
- `bool` `.vsync`
- `bool` `.frameLimit`
- `bool` `.manualResolution`
- `bool` `.manualWindowed`
- `bool` `.manualStretched`
- `bool` `.showPaths`
- `bool` `.swapTextureType`
- `bool` `.colorblind`
- [`std::array<std::vector<HotkeyDesc>, 4>`](#HotkeyDesc) `.hotkeys`
- `bool` `.holdingModifier`
- `bool` `.bDlcEnabled`
- `int` `.openedList`
- `bool` `.beamTutorial`

## ResourceControl

### Methods
- [`GL_Primitive`](#GL_Primitive) `:*CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror)`
- [`GL_Primitive`](#GL_Primitive) `:*CreateImagePrimitiveString(std::string tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)`
- [`freetype::font_data`](#font_data) `:GetFontData(int size, bool ignoreLanguage)`
- [`GL_Texture`](#GL_Texture) `:*GetImageId(std::string dir)`
- `bool :ImageExists(std::string name)`
- `int :RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)`
- `int :RenderImageString(std::string tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)`

## Point

### Methods
- `static` [`Point`](#Point) `.Point(int x, int y)`
- `int :Distance(Point other)`
- `int :RelativeDistance(Point other)`

### Fields
- `int` `.x`
- `int` `.y`

## Pointf

### Methods
- `static` [`Pointf`](#Pointf) `.Pointf()`
- `static` [`Pointf`](#Pointf) `.Pointf(int x, int y)`
- [`Pointf`](#Pointf) `:Normalize()`
- `float :RelativeDistance(Pointf other)`

### Fields
- `float` `.x`
- `float` `.y`

## CustomAchievementTracker

Accessed via `Hyperspace.CustomAchievementTracker.instance`

### Methods
- `void :UpdateVariableAchievements(std::string varName, int varValue, bool inGame=true)`
- `int :GetAchievementStatus(std::string name)`
- `void :SetAchievement(std::string name, bool noPopup)`

### Fields
- `static` [CustomAchievementTracker*](#CustomAchievementTracker) `.instance`

## CustomEventsParser

Accessed via `Hyperspace.CustomEventsParser.GetInstance()`

### Methods

- `static` [CustomEventsParser*](#CustomEventsParser) `.GetInstance()`

- `void :LoadEvent(WorldManager *world, EventLoadList *eventList, int seed, CustomEvent *parentEvent = nullptr)`
- `void :LoadEvent(WorldManager *world, std::string eventName, bool ignoreUnique, int seed, CustomEvent *parentEvent = nullptr)`
- [`CustomEvent*`](#CustomEvent) `CustomEventsParser::GetCustomEvent(std::string eventName)`
- [`CustomEvent*`](#CustomEvent) `CustomEventsParser::GetCustomEvent(Location *loc)`

## CustomEvent

### Fields
- `std::string` `unlockShip`
- `std::vector<unsigned int>` `triggeredEvents`
   - **read-only**

## TriggeredEventDefinition

### Fields
- `static` [`std::vector<TriggeredEventDefinition>`](#TriggeredEventDefinition) `defs`
- `std::string` `name`
- `std::string` `event`

## MainMenu

### Fields
- `bool` `bOpen`
   - **read-only**
- [ShipBuilder](#ShipBuilder) `shipBuilder`
   - **read-only**

## TabbedWindow

**Extends [`FocusWindow`](#FocusWindow)**

### Fields
- `bool` `bBlockClose`
- `bool` `bTutorialMode`
   - If true, player cannot access anything other than Upgrades screen.
- `bool` `bWindowLock`

## TutorialManager

### Fields
- [`ShipManager`](#ShipManager) `.playerShip`
   - **read-only**
- [`CommandGui`](#CommandGui) `.gui`
   - **read-only**
- [`StarMap`](#StarMap) `.starMap`
   - **Read-only**
- [`CombatControl`](#CombatControl) `.combatControl`
   - **Read-only**
- [`TabbedWindow`](#TabbedWindow) `.shipInfo`
   - **Read-only**
- [`AnimationTracker`](#animationtracker) `.tracker`
   - **Read-only**
- `bool` `.bRunning`
- `bool` `.bGamePaused`
- `bool` `.bQuitTutorial`
   - Setting this to true ends the tutorial.
- `bool` `.bAllowJumping`
   - If true, plyer can open the star map.
- `bool` `.bAllowUpgrades`
   - If true, player can open Upgrades screen.

## TutorialArrow

### Static methods
- `Hyperspace.TutorialArrow(Pointf position, float rotation)` Constructor

### Methods
- `void` `:OnRender()`

### Fields
- [`GL_Texture`](#GL_Texture) `.arrow`
- [`GL_Texture`](#GL_Texture) `.arrow2`
- [`Pointf`](#Pointf) `.position`
- [`Pointf`](#Pointf) `.blitSize`
- `float` `.rotation`
- [`GL_Color`](#GL_Color) `.arrow_color`
- [`GL_Color`](#GL_Color) `.arrow2_color`

## ShipBuilder

### Fields
- `bool` `bOpen`
   - **read-only**

## CustomShipSelect

Accessed via `Hyperspace.CustomShipSelect.GetInstance()`

### Methods
- `static` [CustomShipSelect*](#CustomShipSelect) `.GetInstance()`
- [CustomShipDefinition](#CustomShipDefinition) `:GetDefinition(std::string name)`

## TextButton

**Extends [GenericButton](#GenericButton)**

### Methods
- `void` `:OnInit(Point pos, Point size, int cornerInset, TextString *buttonLabel, int font);`
- `void` `:OnRender()`

## TextButton0

**Extends [GenericButton](#GenericButton)**

## FTLButton

**Extends [TextButton0](#TextButton0)**
