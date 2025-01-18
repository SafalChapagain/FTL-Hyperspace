#include "FTLGameMacOSAMD64.h"
#include "zhl_internal.h"

#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
#elif defined(__linux__) || defined(__APPLE__)
    #if __clang__
    #elif __GNUC__ < 8
        #error "GCC version too old, must be at least version 8"
    #endif
    #define FUNC_NAKED __attribute__((naked))
#endif

using namespace ZHL;

namespace _func0
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::OnLanguageChange", typeid(void (AchievementTracker::*)()), "554889e54157415641554154534881ec8801000048", nullptr, 0, 0, &func);
}

void AchievementTracker::OnLanguageChange()
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func0::func;
	return execfunc(this);
}

namespace _func1
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(void (AchievementTracker::*)()), ".554889e54157415641554154534881ec780201", nullptr, 0, 0, &func);
}

void AchievementTracker::LoadAchievementDescriptions()
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1::func;
	return execfunc(this);
}

namespace _func2
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(std::vector<CAchievement*> (AchievementTracker::*)(const std::string &)), ".554889e54157415641554154534883ec584889d0", nullptr, 0, 0, &func);
}

std::vector<CAchievement*> AchievementTracker::GetShipAchievements(const std::string &ship)
{
	typedef std::vector<CAchievement*> (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func2::func;
	return execfunc(this, ship);
}

namespace _func3
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::SaveProfile", typeid(void (AchievementTracker::*)(int )), ".554889e54157415641554154534883ec184189f7488b", nullptr, 0, 0, &func);
}

void AchievementTracker::SaveProfile(int file)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func3::func;
	return execfunc(this, file);
}

namespace _func4
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::LoadProfile", typeid(void (AchievementTracker::*)(int , int )), ".554889e54157415641554154534883ec688955", nullptr, 0, 0, &func);
}

void AchievementTracker::LoadProfile(int file, int version)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int file_arg, int version_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func4::func;
	return execfunc(this, file, version);
}

namespace _func5
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(void (AchievementTracker::*)()), ".554889e5415741564154534881ec??0100004989ff0f", nullptr, 0, 0, &func);
}

void AchievementTracker::SetSectorEight()
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func5::func;
	return execfunc(this);
}

namespace _func6
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(void (AchievementTracker::*)(const std::string &, bool , bool )), ".554889e541574156415541545348", nullptr, 0, 0, &func);
}

void AchievementTracker::SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &achievement_arg, bool noPopup_arg, bool sendToServer_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func6::func;
	return execfunc(this, achievement, noPopup, sendToServer);
}

namespace _func7
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::GetFlag", typeid(bool (AchievementTracker::*)(const std::string &)), ".554889e5415741564155415453504989f44989fe4d8d7e484c89ffe8????0000498d4e504839c8746a488d75d04c89ff4c89e2e8????00004989c5498b5d004885db7563bf40000000e8????2a004889c3488d7b204c89e6e8????2a00c7433800000000488b45d048c743080000000048c703000000004889431049895d00498b07488b004885c0740d498907498b7500eb0731c0eb17", nullptr, 0, 0, &func);
}

bool AchievementTracker::GetFlag(const std::string &flagName)
{
	typedef bool (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func7::func;
	return execfunc(this, flagName);
}

namespace _func8
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::GetShipMarker", typeid(int (AchievementTracker::*)(const std::string &, const std::string &)), ".554889e54157415641554154534883ec284989d64989f5", nullptr, 0, 0, &func);
}

int AchievementTracker::GetShipMarker(const std::string &baseName, const std::string &thisName)
{
	typedef int (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &baseName_arg, const std::string &thisName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func8::func;
	return execfunc(this, baseName, thisName);
}

namespace _func9
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::CheckShipAchievements", typeid(void (AchievementTracker::*)(int , bool )), ".554889e54157415641554154534883ec784189d7", nullptr, 0, 0, &func);
}

void AchievementTracker::CheckShipAchievements(int shipId, bool hidePopups)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int shipId_arg, bool hidePopups_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func9::func;
	return execfunc(this, shipId, hidePopups);
}

namespace _func10
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::SetTooltip", typeid(void (AchievementTracker::*)(CAchievement *)), ".554889e54157415641554154534881ec180100004989f7", nullptr, 0, 0, &func);
}

void AchievementTracker::SetTooltip(CAchievement *ach)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, CAchievement *ach_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func10::func;
	return execfunc(this, ach);
}

namespace _func11
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(void (AchievementTracker::*)()), ".554889e54157415641554154534883ec384989fe4d8d", nullptr, 0, 0, &func);
}

void AchievementTracker::SetVictoryAchievement()
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func11::func;
	return execfunc(this);
}

namespace _func12
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::UnlockShip", typeid(void (AchievementTracker::*)(int , int )), "!.554889e54157415641554154534883ec184989fd83", nullptr, 0, 0, &func);
}

void AchievementTracker::UnlockShip(int shipId, int shipType)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int shipId_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func12::func;
	return execfunc(this, shipId, shipType);
}

namespace _func13
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::ResetFlags", typeid(void (AchievementTracker::*)()), ".554889e54156534889fb488d7b", nullptr, 0, 0, &func);
}

void AchievementTracker::ResetFlags()
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func13::func;
	return execfunc(this);
}

namespace _func14
{
	static void *func = 0;
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(void (AchievementTracker::*)(const std::string &)), ".554889e54157415641554154534883ec184989f54989fe498d5e48", nullptr, 0, 0, &func);
}

void AchievementTracker::SetFlag(const std::string &flagName)
{
	typedef void (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func14::func;
	return execfunc(this, flagName);
}

AchievementTracker *Global_AchievementTracker_Tracker;

namespace _var15
{
	static VariableDefinition varObj("Global_AchievementTracker_Tracker", "!.0089dfe8????1200488d3d(???????\?)", &Global_AchievementTracker_Tracker, true, true);
}

namespace _func16
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::destructor", typeid(void (Animation::*)()), "554889e5415741564155415453504889fbf6", nullptr, 0, 0, &func);
}

void Animation::destructor()
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func16::func;
	return execfunc(this);
}

namespace _func17
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::constructor", typeid(void (Animation::*)(const std::string &, int , float , Pointf , int , int , int , int )), "!.554889e54157415641554154534883ec3844894d", nullptr, 0, 0, &func);
}

void Animation::constructor(const std::string &image, int length, float time, Pointf position, int imageWidth, int imageHeight, int stripStartX, int numFrames)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, const std::string &image_arg, int length_arg, float time_arg, Pointf position_arg, int imageWidth_arg, int imageHeight_arg, int stripStartX_arg, int numFrames_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func17::func;
	return execfunc(this, image, length, time, position, imageWidth, imageHeight, stripStartX, numFrames);
}

namespace _func18
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::SaveState", typeid(void (Animation::*)(int )), "!.554889e54156534189f64889fb0fb673", nullptr, 0, 0, &func);
}

void Animation::SaveState(int fd)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func18::func;
	return execfunc(this, fd);
}

namespace _func19
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::LoadState", typeid(void (Animation::*)(int )), ".554889e54156534189f64889fb4489f7e81b", nullptr, 0, 0, &func);
}

void Animation::LoadState(int fd)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func19::func;
	return execfunc(this, fd);
}

namespace _func20
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::Start", typeid(void (Animation::*)(bool )), ".554889e553504889fb0f57c040", nullptr, 0, 0, &func);
}

void Animation::Start(bool reset)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func20::func;
	return execfunc(this, reset);
}

namespace _func21
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::SetProgress", typeid(void (Animation::*)(float )), ".554889e5f30f1057", nullptr, 0, 0, &func);
}

void Animation::SetProgress(float progress)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func21::func;
	return execfunc(this, progress);
}

namespace _func22
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::SetCurrentFrame", typeid(void (Animation::*)(int )), ".554889e58b47088d", nullptr, 0, 0, &func);
}

void Animation::SetCurrentFrame(int frame)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func22::func;
	return execfunc(this, frame);
}

namespace _func23
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::Done", typeid(bool (Animation::*)()), ".554889e5807f3e", nullptr, 0, 0, &func);
}

bool Animation::Done()
{
	typedef bool (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func23::func;
	return execfunc(this);
}

namespace _func24
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::Update", typeid(void (Animation::*)()), ".554889e54157415641554154534883ec184989fd418b", nullptr, 0, 0, &func);
}

void Animation::Update()
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func24::func;
	return execfunc(this);
}

namespace _func25
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::RandomStart", typeid(int (Animation::*)()), ".554889e553504889fb488d05??????008038007407e8??????00eb05e8????0c", nullptr, 0, 0, &func);
}

int Animation::RandomStart()
{
	typedef int (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func25::func;
	return execfunc(this);
}

namespace _func26
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::SetAnimationId", typeid(void (Animation::*)(GL_Texture *)), ".554889e5483937", nullptr, 0, 0, &func);
}

void Animation::SetAnimationId(GL_Texture *tex)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, GL_Texture *tex_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func26::func;
	return execfunc(this, tex);
}

namespace _func27
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::OnRender", typeid(void (Animation::*)(float , GL_Color , bool )), "!.554889e5415741564154534883ec504889fb41", nullptr, 0, 0, &func);
}

void Animation::OnRender(float opacity, GL_Color color, bool mirror)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func27::func;
	return execfunc(this, opacity, color, mirror);
}

namespace _func28
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::AddSoundQueue", typeid(void (Animation::*)(int , const std::string &)), "!.85f6784f", nullptr, 0, 0, &func);
}

void Animation::AddSoundQueue(int frame, const std::string &sound)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func28::func;
	return execfunc(this, frame, sound);
}

namespace _func29
{
	static void *func = 0;
	static FunctionDefinition funcObj("Animation::StartReverse", typeid(void (Animation::*)(bool )), ".554889e553504889fb4084f67422", nullptr, 0, 0, &func);
}

void Animation::StartReverse(bool reset)
{
	typedef void (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func29::func;
	return execfunc(this, reset);
}

AnimationControl *Global_AnimationControl_Animations;

namespace _var30
{
	static VariableDefinition varObj("Global_AnimationControl_Animations", "!69488945??c745??786d6c00488d3d(???????\?)", &Global_AnimationControl_Animations, true, true);
}

namespace _func31
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationControl::GetAnimation", typeid(Animation (AnimationControl::*)(const std::string &)), ".554889e54157415641554154534883ec384989d6", nullptr, 0, 0, &func);
}

Animation AnimationControl::GetAnimation(const std::string &animName)
{
	typedef Animation (*custom_arg_funcptr_t)(AnimationControl *this_arg, const std::string &animName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func31::func;
	return execfunc(this, animName);
}

namespace _func32
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::Progress", typeid(float (AnimationTracker::*)(float )), "554889e50f28c880", nullptr, 0, 0, &func);
}

float AnimationTracker::Progress(float speed)
{
	typedef float (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float speed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func32::func;
	return execfunc(this, speed);
}

namespace _func33
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::SetLoop", typeid(void (AnimationTracker::*)(bool , float )), ".554889e54088770c", nullptr, 0, 0, &func);
}

void AnimationTracker::SetLoop(bool loop, float loopDelay)
{
	typedef void (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool loop_arg, float loopDelay_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func33::func;
	return execfunc(this, loop, loopDelay);
}

namespace _func34
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::SetProgress", typeid(void (AnimationTracker::*)(float )), ".554889e5f30f59", nullptr, 0, 0, &func);
}

void AnimationTracker::SetProgress(float time)
{
	typedef void (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func34::func;
	return execfunc(this, time);
}

namespace _func35
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::Update", typeid(void (AnimationTracker::*)()), ".554889e5415741564154534889fb807b", nullptr, 0, 0, &func);
}

void AnimationTracker::Update()
{
	typedef void (*custom_arg_funcptr_t)(AnimationTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func35::func;
	return execfunc(this);
}

namespace _func36
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::Start", typeid(void (AnimationTracker::*)(float )), ".554889e5c647160066", nullptr, 0, 0, &func);
}

void AnimationTracker::Start(float time)
{
	typedef void (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func36::func;
	return execfunc(this, time);
}

namespace _func37
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::StartReverse", typeid(void (AnimationTracker::*)(float )), ".554889e5c6471600c6", nullptr, 0, 0, &func);
}

void AnimationTracker::StartReverse(float time)
{
	typedef void (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func37::func;
	return execfunc(this, time);
}

namespace _func38
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::Stop", typeid(void (AnimationTracker::*)(bool )), ".554889e5c64714", nullptr, 0, 0, &func);
}

void AnimationTracker::Stop(bool resetTime)
{
	typedef void (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool resetTime_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func38::func;
	return execfunc(this, resetTime);
}

namespace _func39
{
	static void *func = 0;
	static FunctionDefinition funcObj("AnimationTracker::GetAlphaLevel", typeid(float (AnimationTracker::*)(bool )), ".554889e5f30f104f08f30f10", nullptr, 0, 0, &func);
}

float AnimationTracker::GetAlphaLevel(bool reverse)
{
	typedef float (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool reverse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func39::func;
	return execfunc(this, reverse);
}

namespace _func40
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArmamentControl::CreateHolderTab", typeid(void (ArmamentControl::*)()), "554889e5415741564154534883ec604989ff", nullptr, 0, 0, &func);
}

void ArmamentControl::CreateHolderTab()
{
	typedef void (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func40::func;
	return execfunc(this);
}

namespace _func41
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArmamentControl::Dragging", typeid(bool (ArmamentControl::*)()), ".554889e553504889fb83bb", nullptr, 0, 0, &func);
}

bool ArmamentControl::Dragging()
{
	typedef bool (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func41::func;
	return execfunc(this);
}

namespace _func42
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArmamentControl::KeyDown", typeid(bool (ArmamentControl::*)(SDLKey )), ".554889e54157415653504189f74989fe49", nullptr, 0, 0, &func);
}

bool ArmamentControl::KeyDown(SDLKey key)
{
	typedef bool (*custom_arg_funcptr_t)(ArmamentControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func42::func;
	return execfunc(this, key);
}

namespace _func43
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArmamentControl::LinkShip", typeid(void (ArmamentControl::*)(ShipManager *)), ".554889e54157415641554154534883ec484989fd4989", nullptr, 0, 0, &func);
}

void ArmamentControl::LinkShip(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(ArmamentControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func43::func;
	return execfunc(this, ship);
}

namespace _func44
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArmamentControl::SetPosition", typeid(void (ArmamentControl::*)(Point )), ".554889e54156534989fe4139", nullptr, 0, 0, &func);
}

void ArmamentControl::SetPosition(Point loc)
{
	typedef void (*custom_arg_funcptr_t)(ArmamentControl *this_arg, Point loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func44::func;
	return execfunc(this, loc);
}

namespace _func45
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArtilleryBox::constructor", typeid(void (ArtilleryBox::*)(Point , ArtillerySystem *)), "!.554889e54156534989d64889fbb901000000e8a9", nullptr, 0, 0, &func);
}

void ArtilleryBox::constructor(Point _position, ArtillerySystem *_system)
{
	typedef void (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, Point _position_arg, ArtillerySystem *_system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func45::func;
	return execfunc(this, _position, _system);
}

namespace _func46
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArtilleryBox::OnRender", typeid(void (ArtilleryBox::*)(bool )), ".554889e541574156534883ec784989ff40", nullptr, 0, 0, &func);
}

void ArtilleryBox::OnRender(bool ignoreStatus)
{
	typedef void (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func46::func;
	return execfunc(this, ignoreStatus);
}

namespace _func47
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArtillerySystem::OnLoop", typeid(void (ArtillerySystem::*)()), ".554889e54157415641554154534881ec980000004889fbe8", nullptr, 0, 0, &func);
}

void ArtillerySystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ArtillerySystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func47::func;
	return execfunc(this);
}

namespace _func48
{
	static void *func = 0;
	static FunctionDefinition funcObj("ArtillerySystem::Jump", typeid(void (ArtillerySystem::*)()), ".554889e5488b8768020000c7", nullptr, 0, 0, &func);
}

void ArtillerySystem::Jump()
{
	typedef void (*custom_arg_funcptr_t)(ArtillerySystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func48::func;
	return execfunc(this);
}

namespace _func49
{
	static void *func = 0;
	static FunctionDefinition funcObj("Asteroid::constructor", typeid(void (Asteroid::*)(Pointf , int )), "554889e541574156534881ec68", nullptr, 0, 0, &func);
}

void Asteroid::constructor(Pointf _position, int _destinationSpace)
{
	typedef void (*custom_arg_funcptr_t)(Asteroid *this_arg, Pointf _position_arg, int _destinationSpace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func49::func;
	return execfunc(this, _position, _destinationSpace);
}

namespace _func50
{
	static void *func = 0;
	static FunctionDefinition funcObj("Asteroid::OnUpdate", typeid(void (Asteroid::*)()), ".554889e553504889fbe812fcff", nullptr, 0, 0, &func);
}

void Asteroid::OnUpdate()
{
	typedef void (*custom_arg_funcptr_t)(Asteroid *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func50::func;
	return execfunc(this);
}

namespace _func51
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::constructor", typeid(void (AsteroidGenerator::*)()), "554889e548c74730", nullptr, 0, 0, &func);
}

void AsteroidGenerator::constructor()
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func51::func;
	return execfunc(this);
}

namespace _func52
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), ".554889e54157415653504889fb89", nullptr, 0, 0, &func);
}

float AsteroidGenerator::Initialize(int numberOfShips, int shieldCount, bool defense)
{
	typedef float (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int numberOfShips_arg, int shieldCount_arg, bool defense_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func52::func;
	return execfunc(this, numberOfShips, shieldCount, defense);
}

namespace _func53
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextState", typeid(void (AsteroidGenerator::*)()), ".554889e553504889fb31c9", nullptr, 0, 0, &func);
}

void AsteroidGenerator::GetNextState()
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func53::func;
	return execfunc(this);
}

namespace _func54
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::SetNumShips", typeid(void (AsteroidGenerator::*)(int )), ".554889e58977785dc3", nullptr, 0, 0, &func);
}

void AsteroidGenerator::SetNumShips(int ships)
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int ships_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func54::func;
	return execfunc(this, ships);
}

namespace _func55
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextAsteroid", typeid(Projectile *(AsteroidGenerator::*)()), ".554889e541574156534883ec784889fb488b4b", nullptr, 0, 0, &func);
}

Projectile *AsteroidGenerator::GetNextAsteroid()
{
	typedef Projectile *(*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func55::func;
	return execfunc(this);
}

namespace _func56
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::OnLoop", typeid(void (AsteroidGenerator::*)()), ".554889e541574156534883ec184889fb80bb90", nullptr, 0, 0, &func);
}

void AsteroidGenerator::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func56::func;
	return execfunc(this);
}

namespace _func57
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::UpdateState", typeid(void (AsteroidGenerator::*)()), ".554889e553504889fb488d3d20", nullptr, 0, 0, &func);
}

void AsteroidGenerator::UpdateState()
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func57::func;
	return execfunc(this);
}

namespace _func58
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::SaveAsteroids", typeid(void (AsteroidGenerator::*)(int )), "!.554889e54156534189f64889fbf30f108388", nullptr, 0, 0, &func);
}

void AsteroidGenerator::SaveAsteroids(int fd)
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func58::func;
	return execfunc(this, fd);
}

namespace _func59
{
	static void *func = 0;
	static FunctionDefinition funcObj("AsteroidGenerator::LoadAsteroids", typeid(void (AsteroidGenerator::*)(int )), ".554889e541565389f34989fe89dfe8????13", nullptr, 0, 0, &func);
}

void AsteroidGenerator::LoadAsteroids(int fd)
{
	typedef void (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func59::func;
	return execfunc(this, fd);
}

namespace _func60
{
	static void *func = 0;
	static FunctionDefinition funcObj("AugmentEquipBox::RenderIcon", typeid(void (AugmentEquipBox::*)()), "!.554889e553504889fbe8????06", nullptr, 0, 0, &func);
}

void AugmentEquipBox::RenderIcon()
{
	typedef void (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func60::func;
	return execfunc(this);
}

namespace _func61
{
	static void *func = 0;
	static FunctionDefinition funcObj("AugmentEquipBox::RemoveItem", typeid(void (AugmentEquipBox::*)()), ".554889e541574156534883ec184889fb4c", nullptr, 0, 0, &func);
}

void AugmentEquipBox::RemoveItem()
{
	typedef void (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func61::func;
	return execfunc(this);
}

namespace _func62
{
	static void *func = 0;
	static FunctionDefinition funcObj("AugmentEquipBox::CheckContents", typeid(void (AugmentEquipBox::*)()), ".554889e54156534883ec304889fb488bb3", nullptr, 0, 0, &func);
}

void AugmentEquipBox::CheckContents()
{
	typedef void (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func62::func;
	return execfunc(this);
}

namespace _func63
{
	static void *func = 0;
	static FunctionDefinition funcObj("AugmentStoreBox::constructor", typeid(void (AugmentStoreBox::*)(ShipManager *, const AugmentBlueprint *)), "!.554889e54156534883ec204989d64889f04889fb0f57c00f2945d048c745e000000000c645d02a48b95f776561706f6e7348894dde48b973746f72655f776548894dd948b973746f726555492f48894dd1c645e600488d75d031c94889c2e84df2", nullptr, 0, 0, &func);
}

void AugmentStoreBox::constructor(ShipManager *_ship, const AugmentBlueprint *_augment)
{
	typedef void (*custom_arg_funcptr_t)(AugmentStoreBox *this_arg, ShipManager *_ship_arg, const AugmentBlueprint *_augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func63::func;
	return execfunc(this, _ship, _augment);
}

namespace _func64
{
	static void *func = 0;
	static FunctionDefinition funcObj("BatteryBox::constructor", typeid(void (BatteryBox::*)(Point , BatterySystem *)), "554889e5415741564154534883ec404889d3", nullptr, 0, 0, &func);
}

void BatteryBox::constructor(Point position, BatterySystem *_system)
{
	typedef void (*custom_arg_funcptr_t)(BatteryBox *this_arg, Point position_arg, BatterySystem *_system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func64::func;
	return execfunc(this, position, _system);
}

namespace _func65
{
	static void *func = 0;
	static FunctionDefinition funcObj("BeamWeapon::constructor", typeid(void (BeamWeapon::*)(Pointf , int , int , Pointf , Pointf , int , Targetable *, float )), "554889e54157415641554154534883ec28f30f115d", nullptr, 0, 0, &func);
}

void BeamWeapon::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading)
{
	typedef void (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, Pointf _target2_arg, int _length_arg, Targetable *_targetable_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func65::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _target2, _length, _targetable, heading);
}

namespace _func66
{
	static void *func = 0;
	static FunctionDefinition funcObj("BeamWeapon::OnUpdate", typeid(void (BeamWeapon::*)()), ".554889e54157415641554154534883ec284989fe4180be", nullptr, 0, 0, &func);
}

void BeamWeapon::OnUpdate()
{
	typedef void (*custom_arg_funcptr_t)(BeamWeapon *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func66::func;
	return execfunc(this);
}

namespace _func67
{
	static void *func = 0;
	static FunctionDefinition funcObj("BeamWeapon::CollisionCheck", typeid(void (BeamWeapon::*)(Collideable *)), ".554889e54157415641554154534881ec780200", nullptr, 0, 0, &func);
}

void BeamWeapon::CollisionCheck(Collideable *other)
{
	typedef void (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func67::func;
	return execfunc(this, other);
}

namespace _func68
{
	static void *func = 0;
	static FunctionDefinition funcObj("BeamWeapon::OnRenderSpecific", typeid(void (BeamWeapon::*)(int )), ".554889e54157415641554154534883ec284189f649", nullptr, 0, 0, &func);
}

void BeamWeapon::OnRenderSpecific(int spaceId)
{
	typedef void (*custom_arg_funcptr_t)(BeamWeapon *this_arg, int spaceId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func68::func;
	return execfunc(this, spaceId);
}

namespace _func69
{
	static void *func = 0;
	static FunctionDefinition funcObj("Blueprint::GetNameShort", typeid(std::string (Blueprint::*)()), "554889e553504889fb807e58", nullptr, 0, 0, &func);
}

std::string Blueprint::GetNameShort()
{
	typedef std::string (*custom_arg_funcptr_t)(Blueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func69::func;
	return execfunc(this);
}

namespace _func70
{
	static void *func = 0;
	static FunctionDefinition funcObj("Blueprint::destructor", typeid(void (Blueprint::*)()), "!.554889e553504889fb488d05????33", nullptr, 0, 0, &func);
}

void Blueprint::destructor()
{
	typedef void (*custom_arg_funcptr_t)(Blueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func70::func;
	return execfunc(this);
}

BlueprintManager *Global_BlueprintManager_Blueprints;

namespace _var71
{
	static VariableDefinition varObj("Global_BlueprintManager_Blueprints", "!0b0000488d3d(???????\?)", &Global_BlueprintManager_Blueprints, true, true);
}

namespace _func72
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetSkillIcon", typeid(GL_Texture *(*)(int , bool )), ".554889e5415741564154534883ec7048", nullptr, 0, 0, &func);
}

GL_Texture *BlueprintManager::GetSkillIcon(int skill, bool outline)
{
	typedef GL_Texture *(*custom_arg_funcptr_t)(int skill_arg, bool outline_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func72::func;
	return execfunc(skill, outline);
}

namespace _func73
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::ProcessWeaponBlueprint", typeid(WeaponBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), ".554889e54157415641554154534881ec680100004989d7", nullptr, 0, 0, &func);
}

WeaponBlueprint BlueprintManager::ProcessWeaponBlueprint(rapidxml::xml_node<char> *node)
{
	typedef WeaponBlueprint (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func73::func;
	return execfunc(this, node);
}

namespace _func74
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::ProcessShipBlueprint", typeid(ShipBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), ".554889e54157415641554154534881ec780100004989d4", nullptr, 0, 0, &func);
}

ShipBlueprint BlueprintManager::ProcessShipBlueprint(rapidxml::xml_node<char> *node)
{
	typedef ShipBlueprint (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func74::func;
	return execfunc(this, node);
}

namespace _func75
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::ProcessDroneBlueprint", typeid(DroneBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), ".554889e54157415641554154534881ec180100004989fc", nullptr, 0, 0, &func);
}

DroneBlueprint BlueprintManager::ProcessDroneBlueprint(rapidxml::xml_node<char> *node)
{
	typedef DroneBlueprint (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func75::func;
	return execfunc(this, node);
}

namespace _func76
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetBlueprintList", typeid(std::vector<std::string> (BlueprintManager::*)(const std::string &)), ".554889e54157415641554154534883ec484889d349", nullptr, 0, 0, &func);
}

std::vector<std::string> BlueprintManager::GetBlueprintList(const std::string &name)
{
	typedef std::vector<std::string> (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func76::func;
	return execfunc(this, name);
}

namespace _func77
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetCrewName", typeid(std::string (BlueprintManager::*)(bool *)), ".554889e5415741564154534883ec204989d648", nullptr, 0, 0, &func);
}

std::string BlueprintManager::GetCrewName(bool *isMale_ret)
{
	typedef std::string (*custom_arg_funcptr_t)(BlueprintManager *this_arg, bool *isMale_ret_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func77::func;
	return execfunc(this, isMale_ret);
}

namespace _func78
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::ProcessDescription", typeid(Description (BlueprintManager::*)(rapidxml::xml_node<char> *)), ".554889e54157415641554154534881eca80000004989fe49", nullptr, 0, 0, &func);
}

Description BlueprintManager::ProcessDescription(rapidxml::xml_node<char> *node)
{
	typedef Description (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func78::func;
	return execfunc(this, node);
}

namespace _func79
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::ProcessEffectsBlueprint", typeid(EffectsBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), ".554889e54157415641554154534883ec684889fb48c7", nullptr, 0, 0, &func);
}

EffectsBlueprint BlueprintManager::ProcessEffectsBlueprint(rapidxml::xml_node<char> *node)
{
	typedef EffectsBlueprint (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func79::func;
	return execfunc(this, node);
}

namespace _func80
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(const std::string &, int )), ".554889e54157415641554154534881ec980000004189d44989f6", nullptr, 0, 0, &func);
}

ShipBlueprint *BlueprintManager::GetShipBlueprint(const std::string &name, int sector)
{
	typedef ShipBlueprint *(*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func80::func;
	return execfunc(this, name, sector);
}

namespace _func81
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetDroneBlueprint", typeid(DroneBlueprint *(BlueprintManager::*)(const std::string &)), ".554889e54157415641554154534883ec484989f54989fe4d8da6f80000000f57c00f2945a048c745b0000000004c89e7e84bab", nullptr, 0, 0, &func);
}

DroneBlueprint *BlueprintManager::GetDroneBlueprint(const std::string &name)
{
	typedef DroneBlueprint *(*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func81::func;
	return execfunc(this, name);
}

namespace _func82
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetWeaponBlueprint", typeid(WeaponBlueprint *(BlueprintManager::*)(const std::string &)), ".554889e54157415641554154534883ec484989f54989fe4d8da6f80000000f57c00f2945a048c745b0000000004c89e7e86b", nullptr, 0, 0, &func);
}

WeaponBlueprint *BlueprintManager::GetWeaponBlueprint(const std::string &name)
{
	typedef WeaponBlueprint *(*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func82::func;
	return execfunc(this, name);
}

namespace _func83
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetCrewBlueprint", typeid(CrewBlueprint (BlueprintManager::*)(const std::string &)), ".554889e54157415641554154534883ec484989d44989f5", nullptr, 0, 0, &func);
}

CrewBlueprint BlueprintManager::GetCrewBlueprint(const std::string &name)
{
	typedef CrewBlueprint (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func83::func;
	return execfunc(this, name);
}

namespace _func84
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetUnusedCrewName", typeid(std::string (BlueprintManager::*)(bool *)), ".554889e54157415641554154534883ec58488955", nullptr, 0, 0, &func);
}

std::string BlueprintManager::GetUnusedCrewName(bool *isMale_ret)
{
	typedef std::string (*custom_arg_funcptr_t)(BlueprintManager *this_arg, bool *isMale_ret_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func84::func;
	return execfunc(this, isMale_ret);
}

namespace _func85
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentValue", typeid(float (BlueprintManager::*)(const std::string &)), ".554889e541574156534883ec184989f74889fb4c8d73", nullptr, 0, 0, &func);
}

float BlueprintManager::GetAugmentValue(const std::string &name)
{
	typedef float (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func85::func;
	return execfunc(this, name);
}

namespace _func86
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentBlueprint", typeid(AugmentBlueprint *(BlueprintManager::*)(const std::string &)), ".554889e54157415641554154534883ec484989f54989fe4d8da6f80000000f57c00f2945a048c745b0000000004c89e7e84b93", nullptr, 0, 0, &func);
}

AugmentBlueprint *BlueprintManager::GetAugmentBlueprint(const std::string &name)
{
	typedef AugmentBlueprint *(*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func86::func;
	return execfunc(this, name);
}

namespace _func87
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetItemBlueprint", typeid(ItemBlueprint *(BlueprintManager::*)(const std::string &)), ".554889e541574156534883ec184989f74889fb4c8db3c8", nullptr, 0, 0, &func);
}

ItemBlueprint *BlueprintManager::GetItemBlueprint(const std::string &name)
{
	typedef ItemBlueprint *(*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func87::func;
	return execfunc(this, name);
}

namespace _func88
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetRandomWeapon", typeid(std::vector<WeaponBlueprint*> (BlueprintManager::*)(int , bool )), ".554889e5535089d04889fb440fb6c1488d5620", nullptr, 0, 0, &func);
}

std::vector<WeaponBlueprint*> BlueprintManager::GetRandomWeapon(int count, bool demo_lock)
{
	typedef std::vector<WeaponBlueprint*> (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func88::func;
	return execfunc(this, count, demo_lock);
}

namespace _func89
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetRandomAugment", typeid(std::vector<AugmentBlueprint*> (BlueprintManager::*)(int , bool )), ".554889e5535089d04889fb440fb6c1488d5650", nullptr, 0, 0, &func);
}

std::vector<AugmentBlueprint*> BlueprintManager::GetRandomAugment(int count, bool demo_lock)
{
	typedef std::vector<AugmentBlueprint*> (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func89::func;
	return execfunc(this, count, demo_lock);
}

namespace _func90
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetRandomDrone", typeid(std::vector<DroneBlueprint*> (BlueprintManager::*)(int , bool )), ".554889e5535089d04889fb440fb6c1488d5638", nullptr, 0, 0, &func);
}

std::vector<DroneBlueprint*> BlueprintManager::GetRandomDrone(int count, bool demo_lock)
{
	typedef std::vector<DroneBlueprint*> (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func90::func;
	return execfunc(this, count, demo_lock);
}

namespace _func91
{
	static void *func = 0;
	static FunctionDefinition funcObj("BlueprintManager::GetSystemBlueprint", typeid(SystemBlueprint *(BlueprintManager::*)(const std::string &)), ".554889e541574156534883ec184989f74889fb4c8db3e0", nullptr, 0, 0, &func);
}

SystemBlueprint *BlueprintManager::GetSystemBlueprint(const std::string &name)
{
	typedef SystemBlueprint *(*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func91::func;
	return execfunc(this, name);
}

namespace _func92
{
	static void *func = 0;
	static FunctionDefinition funcObj("BoarderPodDrone::constructor", typeid(void (BoarderPodDrone::*)(int , int , const DroneBlueprint &)), "554889e54157415641554154534881ec680100004989ce", nullptr, 0, 0, &func);
}

void BoarderPodDrone::constructor(int _iShipId, int _selfId, const DroneBlueprint &_blueprint)
{
	typedef void (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, int _iShipId_arg, int _selfId_arg, const DroneBlueprint &_blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func92::func;
	return execfunc(this, _iShipId, _selfId, _blueprint);
}

namespace _func93
{
	static void *func = 0;
	static FunctionDefinition funcObj("BoarderPodDrone::SetMovementTarget", typeid(void (BoarderPodDrone::*)(Targetable *)), ".554889e553504889fb4885f6", nullptr, 0, 0, &func);
}

void BoarderPodDrone::SetMovementTarget(Targetable *target)
{
	typedef void (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func93::func;
	return execfunc(this, target);
}

namespace _func94
{
	static void *func = 0;
	static FunctionDefinition funcObj("BoarderPodDrone::CollisionMoving", typeid(CollisionResponse (BoarderPodDrone::*)(Pointf , Pointf , Damage , bool )), ".554889e5534883ec384889fb80be", nullptr, 0, 0, &func);
}

CollisionResponse BoarderPodDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func94::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func95
{
	static void *func = 0;
	static FunctionDefinition funcObj("BoarderPodDrone::CanBeDeployed", typeid(bool (BoarderPodDrone::*)()), ".554889e553504889fb488bbb88010", nullptr, 0, 0, &func);
}

bool BoarderPodDrone::CanBeDeployed()
{
	typedef bool (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func95::func;
	return execfunc(this);
}

namespace _func96
{
	static void *func = 0;
	static FunctionDefinition funcObj("BoarderPodDrone::SetDeployed", typeid(void (BoarderPodDrone::*)(bool )), ".554889e54156534189f64889fb807b18", nullptr, 0, 0, &func);
}

void BoarderPodDrone::SetDeployed(bool deployed)
{
	typedef void (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, bool deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func96::func;
	return execfunc(this, deployed);
}

namespace _func97
{
	static void *func = 0;
	static FunctionDefinition funcObj("BombProjectile::constructor", typeid(void (BombProjectile::*)(Pointf , int , int , Pointf )), "554889e54156534881ec100100004889fbe81a", nullptr, 0, 0, &func);
}

void BombProjectile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
	typedef void (*custom_arg_funcptr_t)(BombProjectile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func97::func;
	return execfunc(this, _position, _ownerId, _targetId, _target);
}

namespace _func98
{
	static void *func = 0;
	static FunctionDefinition funcObj("BombProjectile::CollisionCheck", typeid(void (BombProjectile::*)(Collideable *)), ".554889e541574156534881ecd8", nullptr, 0, 0, &func);
}

void BombProjectile::CollisionCheck(Collideable *other)
{
	typedef void (*custom_arg_funcptr_t)(BombProjectile *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func98::func;
	return execfunc(this, other);
}

namespace _func99
{
	static void *func = 0;
	static FunctionDefinition funcObj("BombProjectile::OnUpdate", typeid(void (BombProjectile::*)()), ".554889e54157415653504989ff498d9f", nullptr, 0, 0, &func);
}

void BombProjectile::OnUpdate()
{
	typedef void (*custom_arg_funcptr_t)(BombProjectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func99::func;
	return execfunc(this);
}

namespace _func100
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (BossShip::*)()), "!554889e553504889fb31d2b9", nullptr, 0, 0, &func);
}

namespace _func101
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::constructor", typeid(void (BossShip::*)(SpaceManager *)), "!.554889e553504889fb31d2b9", nullptr, 0, 0, &func);
}

void BossShip::constructor(SpaceManager *_space)
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg, SpaceManager *_space_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func101::func;
	return execfunc(this, _space);
}

namespace _func102
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::SaveBoss", typeid(void (BossShip::*)(int )), ".554889e54157415653504189f64989ff418b", nullptr, 0, 0, &func);
}

void BossShip::SaveBoss(int fd)
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func102::func;
	return execfunc(this, fd);
}

namespace _func103
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(void (BossShip::*)(int )), ".554889e54157415641554154534883ec284189f54889fb44", nullptr, 0, 0, &func);
}

void BossShip::LoadBoss(int fd)
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func103::func;
	return execfunc(this, fd);
}

namespace _func104
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(LocationEvent *(BossShip::*)()), ".554889e5534883ec38488d", nullptr, 0, 0, &func);
}

LocationEvent *BossShip::GetEvent()
{
	typedef LocationEvent *(*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func104::func;
	return execfunc(this);
}

namespace _func105
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::ClearLocation", typeid(void (BossShip::*)()), ".554889e553504889fb488b7b104885ff740e", nullptr, 0, 0, &func);
}

void BossShip::ClearLocation()
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func105::func;
	return execfunc(this);
}

namespace _func106
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::Defeated", typeid(bool (BossShip::*)()), "!.554889e583bfec", nullptr, 0, 0, &func);
}

bool BossShip::Defeated()
{
	typedef bool (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func106::func;
	return execfunc(this);
}

namespace _func107
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(LocationEvent *(BossShip::*)()), ".554889e54156534883ec404989fee8", nullptr, 0, 0, &func);
}

LocationEvent *BossShip::GetSubEvent()
{
	typedef LocationEvent *(*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func107::func;
	return execfunc(this);
}

namespace _func108
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(void (BossShip::*)()), ".554889e54157415641554154534881ec880000004989fc41", nullptr, 0, 0, &func);
}

void BossShip::StartStage()
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func108::func;
	return execfunc(this);
}

namespace _func109
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::Restart", typeid(void (BossShip::*)()), ".554889e5c787ec", nullptr, 0, 0, &func);
}

void BossShip::Restart()
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func109::func;
	return execfunc(this);
}

namespace _func110
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::IncomingFire", typeid(bool (BossShip::*)()), ".554889e5f30f1087fc", nullptr, 0, 0, &func);
}

bool BossShip::IncomingFire()
{
	typedef bool (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func110::func;
	return execfunc(this);
}

namespace _func111
{
	static void *func = 0;
	static FunctionDefinition funcObj("BossShip::OnLoop", typeid(void (BossShip::*)()), "!.554889e5415741564154534883ec504989fc", nullptr, 0, 0, &func);
}

void BossShip::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func111::func;
	return execfunc(this);
}

namespace _func112
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::constructor", typeid(void (Button::*)()), ".554889e54156534889fb488d052f??28", nullptr, 0, 0, &func);
}

void Button::constructor()
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func112::func;
	return execfunc(this);
}

namespace _func113
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(const std::string &, Point )), ".554889e54157415641554154534883ec184989d64989f74889fb488d", nullptr, 0, 0, &func);
}

void Button::OnInit(const std::string &img, Point position)
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg, const std::string &img_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func113::func;
	return execfunc(this, img, position);
}

namespace _func114
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::SetImageBase", typeid(void (Button::*)(const std::string &)), ".554889e541574156534883ec184989f64889fb488d15", nullptr, 0, 0, &func);
}

void Button::SetImageBase(const std::string &imageBase)
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg, const std::string &imageBase_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func114::func;
	return execfunc(this, imageBase);
}

namespace _func115
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::SetInactiveImage", typeid(void (Button::*)(GL_Texture *)), ".554889e548397750", nullptr, 0, 0, &func);
}

void Button::SetInactiveImage(GL_Texture *texture)
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg, GL_Texture *texture_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func115::func;
	return execfunc(this, texture);
}

namespace _func116
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::SetActiveImage", typeid(void (Button::*)(GL_Texture *)), ".554889e548397758", nullptr, 0, 0, &func);
}

void Button::SetActiveImage(GL_Texture *texture)
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg, GL_Texture *texture_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func116::func;
	return execfunc(this, texture);
}

namespace _func117
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::OnRender", typeid(void (Button::*)()), "!.554889e553504889fb48837b68", nullptr, 0, 0, &func);
}

void Button::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func117::func;
	return execfunc(this);
}

namespace _func118
{
	static void *func = 0;
	static FunctionDefinition funcObj("Button::SetLocation", typeid(void (Button::*)(const Point )), "!.554889e54889f048c1e8208b57", nullptr, 0, 0, &func);
}

void Button::SetLocation(const Point position)
{
	typedef void (*custom_arg_funcptr_t)(Button *this_arg, const Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func118::func;
	return execfunc(this, position);
}

namespace _func119
{
	static void *func = 0;
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(void (CAchievement::*)()), "554889e5415741564154534883ec204889fb48c7", nullptr, 0, 0, &func);
}

void CAchievement::constructor()
{
	typedef void (*custom_arg_funcptr_t)(CAchievement *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func119::func;
	return execfunc(this);
}

namespace _func120
{
	static void *func = 0;
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(void (CAchievement::*)(Point , int , bool )), ".554889e54157415641554154534883ec584189cf41", nullptr, 0, 0, &func);
}

void CAchievement::OnRender(Point position, int selected, bool showNew)
{
	typedef void (*custom_arg_funcptr_t)(CAchievement *this_arg, Point position_arg, int selected_arg, bool showNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func120::func;
	return execfunc(this, position, selected, showNew);
}

namespace _func121
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (CApp::*)()), "554889e553504889fbe8??????00488d05????32", nullptr, 0, 0, &func);
}

namespace _func122
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::constructor", typeid(void (CApp::*)()), ".554889e553504889fbe8??????00488d05????32", nullptr, 0, 0, &func);
}

void CApp::constructor()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func122::func;
	return execfunc(this);
}

namespace _func123
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnInputFocus", typeid(void (CApp::*)()), ".554889e553504889fb80bb????000000752e", nullptr, 0, 0, &func);
}

void CApp::OnInputFocus()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func123::func;
	return execfunc(this);
}

namespace _func124
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnInputBlur", typeid(void (CApp::*)()), ".554889e54156534889fbc683????00000048", nullptr, 0, 0, &func);
}

void CApp::OnInputBlur()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func124::func;
	return execfunc(this);
}

namespace _func125
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(int (CApp::*)()), "!.554889e54157415641554154534881ecb80000004889fb488d3d", nullptr, 0, 0, &func);
}

int CApp::OnExecute()
{
	typedef int (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func125::func;
	return execfunc(this);
}

CFPS *Global_CFPS_FPSControl;

namespace _var126
{
	static VariableDefinition varObj("Global_CFPS_FPSControl", "!.304c8d2d(???????\?)", &Global_CFPS_FPSControl, true, true);
}

namespace _func127
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), ".554889e541574156534883ec384989fe31", nullptr, 0, 0, &func);
}

int CApp::OnInit()
{
	typedef int (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func127::func;
	return execfunc(this);
}

namespace _func128
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::GenInputEvents", typeid(void (CApp::*)()), ".554889e54156534989fee8????1f", nullptr, 0, 0, &func);
}

void CApp::GenInputEvents()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func128::func;
	return execfunc(this);
}

namespace _func129
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(void (CApp::*)()), "!.554889e5415741564154534883ec304989fc48", nullptr, 0, 0, &func);
}

void CApp::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func129::func;
	return execfunc(this);
}

namespace _func130
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnRender", typeid(void (CApp::*)()), ".554889e54156534883ec404889fbe86d", nullptr, 0, 0, &func);
}

void CApp::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func130::func;
	return execfunc(this);
}

namespace _func131
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::UpdateFullScreen", typeid(void (CApp::*)()), ".554889e5415741564155415453504989fe488d1d", nullptr, 0, 0, &func);
}

void CApp::UpdateFullScreen()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func131::func;
	return execfunc(this);
}

namespace _func132
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::UpdateWindowSettings", typeid(void (CApp::*)()), ".554889e548c787????00000000000048c787????00000000000048b8", nullptr, 0, 0, &func);
}

void CApp::UpdateWindowSettings()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func132::func;
	return execfunc(this);
}

namespace _func133
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(int (CApp::*)()), ".554889e54157415653504889fb488d3d", nullptr, 0, 0, &func);
}

int CApp::SetupWindow()
{
	typedef int (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func133::func;
	return execfunc(this);
}

namespace _func134
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnCleanup", typeid(void (CApp::*)()), "!.554889e54156534889fb488b7b18", nullptr, 0, 0, &func);
}

void CApp::OnCleanup()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func134::func;
	return execfunc(this);
}

namespace _func135
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnSuspend", typeid(void (CApp::*)()), "!.554889e553504889fbe8????1600488b7b10", nullptr, 0, 0, &func);
}

void CApp::OnSuspend()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func135::func;
	return execfunc(this);
}

namespace _func136
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnResume", typeid(void (CApp::*)()), "!.554889e553504889fb80bb????0000007513", nullptr, 0, 0, &func);
}

void CApp::OnResume()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func136::func;
	return execfunc(this);
}

namespace _func137
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnRequestExit", typeid(void (CApp::*)()), "!.554889e553504889fb488b7b104885ff7450", nullptr, 0, 0, &func);
}

void CApp::OnRequestExit()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func137::func;
	return execfunc(this);
}

namespace _func138
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnExit", typeid(void (CApp::*)()), ".554889e553504889fbe8????1600488d", nullptr, 0, 0, &func);
}

void CApp::OnExit()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func138::func;
	return execfunc(this);
}

namespace _func139
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::TranslateMouse", typeid(Point (CApp::*)(int , int )), ".554889e54883ec102b", nullptr, 0, 0, &func);
}

Point CApp::TranslateMouse(int mX, int mY)
{
	typedef Point (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func139::func;
	return execfunc(this, mX, mY);
}

namespace _func140
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnMButtonDown", typeid(void (CApp::*)(int , int )), "!.554889e580bf????0000007506", nullptr, 0, 0, &func);
}

void CApp::OnMButtonDown(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func140::func;
	return execfunc(this, mX, mY);
}

namespace _func141
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnLButtonUp", typeid(void (CApp::*)(int , int )), ".554889e553504889fb2b", nullptr, 0, 0, &func);
}

void CApp::OnLButtonUp(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func141::func;
	return execfunc(this, mX, mY);
}

namespace _func142
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnLButtonDown", typeid(void (CApp::*)(int , int )), ".554889e553504889fb2b", nullptr, 0, 0, &func);
}

void CApp::OnLButtonDown(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func142::func;
	return execfunc(this, mX, mY);
}

namespace _func143
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnMouseMove", typeid(void (CApp::*)(int , int , int , int , bool , bool , bool )), ".554889e54157415653504889fb2b", nullptr, 0, 0, &func);
}

void CApp::OnMouseMove(int mX, int mY, int relX, int relY, bool holdingLeft, bool holdingRight, bool holdingMiddle)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg, int relX_arg, int relY_arg, bool holdingLeft_arg, bool holdingRight_arg, bool holdingMiddle_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func143::func;
	return execfunc(this, mX, mY, relX, relY, holdingLeft, holdingRight, holdingMiddle);
}

namespace _func144
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnRButtonDown", typeid(void (CApp::*)(int , int )), ".554889e553504889fb2b", nullptr, 0, 0, &func);
}

void CApp::OnRButtonDown(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func144::func;
	return execfunc(this, mX, mY);
}

namespace _func145
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnRButtonUp", typeid(void (CApp::*)(int , int )), ".554889e553504889fb2b", nullptr, 0, 0, &func);
}

void CApp::OnRButtonUp(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func145::func;
	return execfunc(this, mX, mY);
}

namespace _func146
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnKeyUp", typeid(void (CApp::*)(SDLKey )), ".554889e541574156534883ec384189f7", nullptr, 0, 0, &func);
}

void CApp::OnKeyUp(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func146::func;
	return execfunc(this, key);
}

namespace _func147
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnKeyDown", typeid(void (CApp::*)(SDLKey )), ".554889e541574156534883ec584189f7", nullptr, 0, 0, &func);
}

void CApp::OnKeyDown(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func147::func;
	return execfunc(this, key);
}

namespace _func148
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnTextInput", typeid(void (CApp::*)(SDLKey )), "!.554889e580bf????00000074025dc3807f", nullptr, 0, 0, &func);
}

void CApp::OnTextInput(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func148::func;
	return execfunc(this, key);
}

namespace _func149
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnTextEvent", typeid(void (CApp::*)(CEvent::TextEvent )), "!.554889e580bf????00000074025dc3807f", nullptr, 0, 0, &func);
}

void CApp::OnTextEvent(CEvent::TextEvent textEvent)
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg, CEvent::TextEvent textEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func149::func;
	return execfunc(this, textEvent);
}

namespace _func150
{
	static void *func = 0;
	static FunctionDefinition funcObj("CApp::OnLanguageChange", typeid(void (CApp::*)()), ".554889e5415741564154534883ec304989fc4c", nullptr, 0, 0, &func);
}

void CApp::OnLanguageChange()
{
	typedef void (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func150::func;
	return execfunc(this);
}

namespace _func151
{
	static void *func = 0;
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "!.554889e54157415641554154534883ec284889f34989fe488b", nullptr, 0, 0, &func);
}

void CEvent::OnEvent(const InputEvent *event)
{
	typedef void (*custom_arg_funcptr_t)(CEvent *this_arg, const InputEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func151::func;
	return execfunc(this, event);
}

namespace _func152
{
	static void *func = 0;
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), ".554889e5534883ec184889fbf20f1043", nullptr, 0, 0, &func);
}

void CFPS::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func152::func;
	return execfunc(this);
}

namespace _func153
{
	static void *func = 0;
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), ".554889e5f30f1047185d", nullptr, 0, 0, &func);
}

float CFPS::GetSpeedFactor()
{
	typedef float (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func153::func;
	return execfunc(this);
}

namespace _func154
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::FinishFrame", typeid(void (*)()), "!554889e55de9????0b00", nullptr, 0, 0, &func);
}

void CSurface::FinishFrame()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func154::func;
	return execfunc();
}

namespace _func155
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_ClearAll", typeid(void (*)()), "!.554889e5f30f1025????16000f57c00f", nullptr, 0, 0, &func);
}

void CSurface::GL_ClearAll()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func155::func;
	return execfunc();
}

namespace _func156
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_ClearColor", typeid(void (*)()), "!.554889e50f57c00f57c90f57", nullptr, 0, 0, &func);
}

void CSurface::GL_ClearColor()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func156::func;
	return execfunc();
}

namespace _func157
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::SetViewPort", typeid(int (*)(int , int , int , int )), ".554889e5e8????????b0", nullptr, 0, 0, &func);
}

int CSurface::SetViewPort(int left, int bottom, int h, int w)
{
	typedef int (*custom_arg_funcptr_t)(int left_arg, int bottom_arg, int h_arg, int w_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func157::func;
	return execfunc(left, bottom, h, w);
}

namespace _func158
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_PopScissor", typeid(void (*)()), "!.554889e5488b05??????00488b35", nullptr, 0, 0, &func);
}

void CSurface::GL_PopScissor()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func158::func;
	return execfunc();
}

namespace _func159
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(void (*)(GL_StencilMode , int , int )), "!.554889e54156534189d689f3893d", nullptr, 0, 0, &func);
}

void CSurface::GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask)
{
	typedef void (*custom_arg_funcptr_t)(GL_StencilMode stencilMode_arg, int ref_arg, int mask_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func159::func;
	return execfunc(stencilMode, ref, mask);
}

namespace _func160
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_PushStencilMode", typeid(void (*)()), "!.554889e541574156415541545350488b1d", nullptr, 0, 0, &func);
}

void CSurface::GL_PushStencilMode()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func160::func;
	return execfunc();
}

namespace _func161
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_PopStencilMode", typeid(void (*)()), "!.554889e5488b05??????00488b0d", nullptr, 0, 0, &func);
}

void CSurface::GL_PopStencilMode()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func161::func;
	return execfunc();
}

namespace _func162
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), "!.554889e55de9????0b00", nullptr, 0, 0, &func);
}

int CSurface::GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)
{
	typedef int (*custom_arg_funcptr_t)(float mx1_arg, float mx2_arg, float mx3_arg, float mx4_arg, float mx5_arg, float mx6_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func162::func;
	return execfunc(mx1, mx2, mx3, mx4, mx5, mx6);
}

namespace _func163
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_LoadIdentity", typeid(int (*)()), "!.554889e5488d05????17000f10000f1048100f1050200f105830", nullptr, 0, 0, &func);
}

int CSurface::GL_LoadIdentity()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func163::func;
	return execfunc();
}

namespace _func164
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), ".8b05??????004883", nullptr, 0, 0, &func);
}

int CSurface::GL_PushMatrix()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func164::func;
	return execfunc();
}

namespace _func165
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_PopMatrix", typeid(int (*)()), "!.554889e58b05??????0085c0742effc8", nullptr, 0, 0, &func);
}

int CSurface::GL_PopMatrix()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func165::func;
	return execfunc();
}

namespace _func166
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), ".0f57e40f", nullptr, 0, 0, &func);
}

void CSurface::GL_Rotate(float angle, float x, float y, float z)
{
	typedef void (*custom_arg_funcptr_t)(float angle_arg, float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func166::func;
	return execfunc(angle, x, y, z);
}

namespace _func167
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(void (*)(float , float , float )), "!.554889e50f2e05", nullptr, 0, 0, &func);
}

void CSurface::GL_Scale(float x, float y, float z)
{
	typedef void (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func167::func;
	return execfunc(x, y, z);
}

namespace _func168
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(bool (*)(float , float , float )), "!.554889e50f57e40f", nullptr, 0, 0, &func);
}

bool CSurface::GL_Translate(float x, float y, float z)
{
	typedef bool (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func168::func;
	return execfunc(x, y, z);
}

namespace _func169
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(GL_Color )), ".554889e54883ec10f30f16d0", nullptr, 0, 0, &func);
}

int CSurface::GL_SetColor(GL_Color color)
{
	typedef int (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func169::func;
	return execfunc(color);
}

namespace _func170
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_GetColor", typeid(GL_Color (*)()), ".554889e50f2805??????00f2", nullptr, 0, 0, &func);
}

GL_Color CSurface::GL_GetColor()
{
	typedef GL_Color (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func170::func;
	return execfunc();
}

namespace _func171
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(GL_Color )), ".554889e54883ec100f1345f0", nullptr, 0, 0, &func);
}

void CSurface::GL_SetColorTint(GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func171::func;
	return execfunc(color);
}

namespace _func172
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), ".554889e5488b05??????00483905??????00740b", nullptr, 0, 0, &func);
}

void CSurface::GL_RemoveColorTint()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func172::func;
	return execfunc();
}

namespace _func173
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color (*)()), ".554889e5488b05??????00483905??????00740c", nullptr, 0, 0, &func);
}

GL_Color CSurface::GetColorTint()
{
	typedef GL_Color (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func173::func;
	return execfunc();
}

namespace _func174
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(bool (*)()), "!.554889e5bf01000000be0300", nullptr, 0, 0, &func);
}

bool CSurface::GL_EnableBlend()
{
	typedef bool (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func174::func;
	return execfunc();
}

namespace _func175
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DisableBlend", typeid(bool (*)()), "!.554889e5bf01000000be0100000031d25d", nullptr, 0, 0, &func);
}

bool CSurface::GL_DisableBlend()
{
	typedef bool (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func175::func;
	return execfunc();
}

namespace _func176
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_ForceAntialias", typeid(void (*)(bool )), ".554889e540883d", nullptr, 0, 0, &func);
}

void CSurface::GL_ForceAntialias(bool on)
{
	typedef void (*custom_arg_funcptr_t)(bool on_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func176::func;
	return execfunc(on);
}

namespace _func177
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DrawLine", typeid(bool (*)(float , float , float , float , float , GL_Color )), "!.554889e54881ec80000000488b05????1e00488b00", nullptr, 0, 0, &func);
}

bool CSurface::GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color)
{
	typedef bool (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, float lineWidth_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func177::func;
	return execfunc(x1, y1, x2, y2, lineWidth, color);
}

namespace _func178
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DrawTriangle", typeid(bool (*)(Point , Point , Point , GL_Color )), "!.554889e54883ec60", nullptr, 0, 0, &func);
}

bool CSurface::GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)
{
	typedef bool (*custom_arg_funcptr_t)(Point vertex1_arg, Point vertex2_arg, Point vertex3_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func178::func;
	return execfunc(vertex1, vertex2, vertex3, color);
}

namespace _func179
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , GL_Color )), "!.554889e54881ec80000000488b05????1e00488b00", nullptr, 0, 0, &func);
}

bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)
{
	typedef bool (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func179::func;
	return execfunc(x1, y1, x2, y2, color);
}

namespace _func180
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(int , int , int , int , GL_Color , float )), "!.554889e54881eca0", nullptr, 0, 0, &func);
}

bool CSurface::GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)
{
	typedef bool (*custom_arg_funcptr_t)(int x1_arg, int y1_arg, int x2_arg, int y2_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func180::func;
	return execfunc(x1, y1, x2, y2, color, lineWidth);
}

namespace _func181
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DrawCircle", typeid(bool (*)(int , int , float , GL_Color )), ".554889e541574156534883ec38660f28d9660f14", nullptr, 0, 0, &func);
}

bool CSurface::GL_DrawCircle(int x, int y, float radius, GL_Color color)
{
	typedef bool (*custom_arg_funcptr_t)(int x_arg, int y_arg, float radius_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func181::func;
	return execfunc(x, y, radius, color);
}

namespace _func182
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DrawShield", typeid(bool (*)(int , int , float , float , int , int , GL_Color , float )), ".554889e5415741564154534881eca00000004189ce89d3c7", nullptr, 0, 0, &func);
}

bool CSurface::GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness)
{
	typedef bool (*custom_arg_funcptr_t)(int x_arg, int y_arg, float a1_arg, float b1_arg, int angle1_arg, int angle2_arg, GL_Color color_arg, float thickness_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func182::func;
	return execfunc(x, y, a1, b1, angle1, angle2, color, thickness);
}

namespace _func183
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_BlitImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), "!.554889e5400fb6d6", nullptr, 0, 0, &func);
}

bool CSurface::GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	typedef bool (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float x2_arg, float y2_arg, float rotation_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func183::func;
	return execfunc(tex, x, y, x2, y2, rotation, color, mirror);
}

namespace _func184
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".554889e50fb605??????0040", nullptr, 0, 0, &func);
}

bool CSurface::GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	typedef bool (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float x2_arg, float y2_arg, float rotation_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func184::func;
	return execfunc(tex, x, y, x2, y2, rotation, color, mirror);
}

namespace _func185
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), ".4084f644", nullptr, 0, 0, &func);
}

bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
{
	typedef bool (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float start_x_arg, float end_x_arg, float start_y_arg, float end_y_arg, float alpha_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func185::func;
	return execfunc(tex, x, y, size_x, size_y, start_x, end_x, start_y, end_y, alpha, color, mirror);
}

namespace _func186
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImageWide", typeid(bool (*)(GL_Texture *, float , float , int , int , float , GL_Color , bool )), ".554889e54157415641554154534881ec880000000f295d90", nullptr, 0, 0, &func);
}

bool CSurface::GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror)
{
	typedef bool (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, int x2_arg, int y2_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func186::func;
	return execfunc(tex, x, y, x2, y2, opacity, color, mirror);
}

namespace _func187
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiImage", typeid(void (*)(GL_Texture *, const std::vector<GL_TexVertex> &, bool )), "!.554889e54157415641554154534883ec584989ff488b05??????00483905??????008955", nullptr, 0, 0, &func);
}

void CSurface::GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias)
{
	typedef void (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_TexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func187::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func188
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiColorImage", typeid(void (*)(GL_Texture *, const std::vector<GL_ColorTexVertex> &, bool )), "!.554889e54157415641554154534883ec584989ff488b05??????00483905??????00740c", nullptr, 0, 0, &func);
}

void CSurface::GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias)
{
	typedef void (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_ColorTexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func188::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func189
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitive", typeid(void (*)(GL_Primitive *)), "!.554889e50f2805????16000f28c85d", nullptr, 0, 0, &func);
}

void CSurface::GL_RenderPrimitive(GL_Primitive *primitive)
{
	typedef void (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func189::func;
	return execfunc(primitive);
}

namespace _func190
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithAlpha", typeid(void (*)(GL_Primitive *, float )), "!.554889e5f30f100d????1600", nullptr, 0, 0, &func);
}

void CSurface::GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha)
{
	typedef void (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func190::func;
	return execfunc(primitive, alpha);
}

namespace _func191
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(void (*)(GL_Primitive *, GL_Color )), ".554889e54156534883ec104889fb4885", nullptr, 0, 0, &func);
}

void CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func191::func;
	return execfunc(primitive, color);
}

namespace _func192
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), "!.554889e553504889fb4885db74168b7b", nullptr, 0, 0, &func);
}

void CSurface::GL_DestroyPrimitive(GL_Primitive *primitive)
{
	typedef void (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func192::func;
	return execfunc(primitive);
}

namespace _func193
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , GL_Color )), "!.554889e5534883ec480f296d", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(float x_arg, float y_arg, float w_arg, float h_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func193::func;
	return execfunc(x, y, w, h, color);
}

namespace _func194
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiRectPrimitive", typeid(GL_Primitive *(*)(std::vector<Globals::Rect> &, GL_Color )), ".554889e5415741564154534883ec200f294dc00f2945d0488b1f4c8b", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(std::vector<Globals::Rect> &vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func194::func;
	return execfunc(vec, color);
}

namespace _func195
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreateRectOutlinePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , GL_Color , float )), "!.554889e5534881eca8000000", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(int x_arg, int y_arg, int w_arg, int h_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func195::func;
	return execfunc(x, y, w, h, color, lineWidth);
}

namespace _func196
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiLinePrimitive", typeid(GL_Primitive *(*)(std::vector<GL_Line> &, GL_Color , float )), ".554889e5415741564154534883ec30488b1f4c8b", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(std::vector<GL_Line> &vec_arg, GL_Color color_arg, float thickness_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func196::func;
	return execfunc(vec, color, thickness);
}

namespace _func197
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreatePiePartialPrimitive", typeid(GL_Primitive *(*)(int , int , float , float , float , float , GL_Color )), "!.554889e541574156534881ecb8020000", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreatePiePartialPrimitive(int x, int y, float radius, float deg1, float deg2, float thickness, GL_Color color)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(int x_arg, int y_arg, float radius_arg, float deg1_arg, float deg2_arg, float thickness_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func197::func;
	return execfunc(x, y, radius, deg1, deg2, thickness, color);
}

namespace _func198
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color )), ".0f2e2d????????7716f30f16fd0f2e3d????????77090f2e35", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float rotate_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func198::func;
	return execfunc(tex, x, y, size_x, size_y, rotate, color);
}

namespace _func199
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreatePixelImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".0f2e2d????????7716f30f16fd0f2e3d????????77090f2e35", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool mirrored)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float rotate_arg, GL_Color color_arg, bool mirrored_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func199::func;
	return execfunc(tex, x, y, size_x, size_y, rotate, color, mirrored);
}

namespace _func200
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, std::vector<GL_TexVertex> *, GL_Color )), "!.4889f0488b08488b", nullptr, 0, 0, &func);
}

GL_Primitive *CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(GL_Texture *tex_arg, std::vector<GL_TexVertex> *vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func200::func;
	return execfunc(tex, vec, color);
}

namespace _func201
{
	static void *func = 0;
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(void (*)(std::vector<GL_TexVertex> *, float , float , float , float , float , float , float , float )), ".554889e54156534883ec204989fe498b06498b5e", nullptr, 0, 0, &func);
}

void CSurface::AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)
{
	typedef void (*custom_arg_funcptr_t)(std::vector<GL_TexVertex> *vec_arg, float x1_arg, float y1_arg, float u1_arg, float v1_arg, float x2_arg, float y2_arg, float u2_arg, float v2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func201::func;
	return execfunc(vec, x1, y1, u1, v1, x2, y2, u2, v2);
}

namespace _func202
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::DO_NOT_HOOK_FALSE_CONSTRUCTOR_1", typeid(void (CachedImage::*)()), ".554889e54157415653504189ce4189d74889fb48", nullptr, 0, 0, &func);
}

namespace _func203
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::constructor1", typeid(void (CachedImage::*)(const std::string &, int , int )), ".554889e54157415653504189ce4189d74889fb48", nullptr, 0, 0, &func);
}

void CachedImage::constructor1(const std::string &_path, int _x, int _y)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &_path_arg, int _x_arg, int _y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func203::func;
	return execfunc(this, _path, _x, _y);
}

namespace _func204
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::DO_NOT_HOOK_FALSE_CONSTRUCTOR_2", typeid(void (CachedImage::*)()), ".554889e553504889fb48c7430800000000488d", nullptr, 0, 0, &func);
}

namespace _func205
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::constructor2", typeid(void (CachedImage::*)(const std::string &, CachedImage::Centered )), ".554889e553504889fb48c7430800000000488d", nullptr, 0, 0, &func);
}

void CachedImage::constructor2(const std::string &_path, CachedImage::Centered _centered)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &_path_arg, CachedImage::Centered _centered_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func205::func;
	return execfunc(this, _path, _centered);
}

namespace _func206
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::DO_NOT_HOOK_FALSE_CONSTRUCTOR_3", typeid(void (CachedImage::*)()), ".554889e54156534989f64889fb48c7", nullptr, 0, 0, &func);
}

namespace _func207
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::constructor_copy", typeid(void (CachedImage::*)(const CachedImage &)), ".554889e54156534989f64889fb48c7", nullptr, 0, 0, &func);
}

void CachedImage::constructor_copy(const CachedImage &_source)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, const CachedImage &_source_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func207::func;
	return execfunc(this, _source);
}

namespace _func208
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::CreatePrimitive", typeid(void (CachedImage::*)()), ".554889e5415741564154534883ec504989fe4d", nullptr, 0, 0, &func);
}

void CachedImage::CreatePrimitive()
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func208::func;
	return execfunc(this);
}

namespace _func209
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), ".554889e54156534889fb488d3d????1f", nullptr, 0, 0, &func);
}

void CachedImage::SetImagePath(const std::string &imagePath)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &imagePath_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func209::func;
	return execfunc(this, imagePath);
}

namespace _func210
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::SetPosition", typeid(void (CachedImage::*)(int , int )), ".554889e54157415653504189d64189f74889fb44397b30", nullptr, 0, 0, &func);
}

void CachedImage::SetPosition(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func210::func;
	return execfunc(this, x, y);
}

namespace _func211
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::SetScale", typeid(void (CachedImage::*)(float , float )), ".554889e553504889fb0f2e4338", nullptr, 0, 0, &func);
}

void CachedImage::SetScale(float wScale, float hScale)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, float wScale_arg, float hScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func211::func;
	return execfunc(this, wScale, hScale);
}

namespace _func212
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::SetRotation", typeid(void (CachedImage::*)(float )), ".554889e553504889fb0f2e4350", nullptr, 0, 0, &func);
}

void CachedImage::SetRotation(float rotation)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, float rotation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func212::func;
	return execfunc(this, rotation);
}

namespace _func213
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::SetMirrored", typeid(void (CachedImage::*)(bool )), ".554889e54156534189f64889fb410f", nullptr, 0, 0, &func);
}

void CachedImage::SetMirrored(bool mirrored)
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg, bool mirrored_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func213::func;
	return execfunc(this, mirrored);
}

namespace _func214
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedImage::destructor", typeid(void (CachedImage::*)()), "!.554889e553504889fb488d05????1e00488903f6", nullptr, 0, 0, &func);
}

void CachedImage::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CachedImage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func214::func;
	return execfunc(this);
}

namespace _func215
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedPrimitive::destructor", typeid(void (CachedPrimitive::*)()), "!.554889e5488d05????1e00488907488b7f085de918", nullptr, 0, 0, &func);
}

void CachedPrimitive::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CachedPrimitive *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func215::func;
	return execfunc(this);
}

namespace _func216
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedPrimitive::OnRender", typeid(void (CachedPrimitive::*)(const GL_Color &)), "!.554889e54156534989f64889fb488b7b", nullptr, 0, 0, &func);
}

void CachedPrimitive::OnRender(const GL_Color &color)
{
	typedef void (*custom_arg_funcptr_t)(CachedPrimitive *this_arg, const GL_Color &color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func216::func;
	return execfunc(this, color);
}

namespace _func217
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedRect::SetPosition", typeid(void (CachedRect::*)(int , int )), "!.554889e54157415653504189d64189f74889fb44397b107506443973147419488b7b08e8c8", nullptr, 0, 0, &func);
}

void CachedRect::SetPosition(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(CachedRect *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func217::func;
	return execfunc(this, x, y);
}

namespace _func218
{
	static void *func = 0;
	static FunctionDefinition funcObj("CachedRect::SetSize", typeid(void (CachedRect::*)(int , int )), "!.554889e54157415653504189d64189f74889fb44397b1875064439731c7419488b7b08e878", nullptr, 0, 0, &func);
}

void CachedRect::SetSize(int w, int h)
{
	typedef void (*custom_arg_funcptr_t)(CachedRect *this_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func218::func;
	return execfunc(this, w, h);
}

namespace _func219
{
	static void *func = 0;
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "!554889e54157415641554154534881ec9809", nullptr, 0, 0, &func);
}

void ChoiceBox::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ChoiceBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func219::func;
	return execfunc(this);
}

namespace _func220
{
	static void *func = 0;
	static FunctionDefinition funcObj("ChoiceBox::MouseMove", typeid(void (ChoiceBox::*)(int , int )), "!.554889e541574156535089d341", nullptr, 0, 0, &func);
}

void ChoiceBox::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func220::func;
	return execfunc(this, mX, mY);
}

namespace _func221
{
	static void *func = 0;
	static FunctionDefinition funcObj("ChoiceBox::MouseClick", typeid(void (ChoiceBox::*)(int , int )), "!.554889e5488d0525", nullptr, 0, 0, &func);
}

void ChoiceBox::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func221::func;
	return execfunc(this, mX, mY);
}

namespace _func222
{
	static void *func = 0;
	static FunctionDefinition funcObj("CloakingBox::constructor", typeid(void (CloakingBox::*)(Point , CloakingSystem *)), ".554889e54157415641554154534883ec684889d34989fd31", nullptr, 0, 0, &func);
}

void CloakingBox::constructor(Point _position, CloakingSystem *_system)
{
	typedef void (*custom_arg_funcptr_t)(CloakingBox *this_arg, Point _position_arg, CloakingSystem *_system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func222::func;
	return execfunc(this, _position, _system);
}

namespace _func223
{
	static void *func = 0;
	static FunctionDefinition funcObj("CloakingSystem::FiredWeapon", typeid(void (CloakingSystem::*)()), ".554889e54156534883ec204989fe498d", nullptr, 0, 0, &func);
}

void CloakingSystem::FiredWeapon()
{
	typedef void (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func223::func;
	return execfunc(this);
}

namespace _func224
{
	static void *func = 0;
	static FunctionDefinition funcObj("CloakingSystem::OnLoop", typeid(void (CloakingSystem::*)()), ".554889e54156534889fbe8d1", nullptr, 0, 0, &func);
}

void CloakingSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func224::func;
	return execfunc(this);
}

namespace _func225
{
	static void *func = 0;
	static FunctionDefinition funcObj("CloneBox::constructor", typeid(void (CloneBox::*)(Point , CloneSystem *)), "554889e553504889fb488d0500??24", nullptr, 0, 0, &func);
}

void CloneBox::constructor(Point _position, CloneSystem *_cloneSystem)
{
	typedef void (*custom_arg_funcptr_t)(CloneBox *this_arg, Point _position_arg, CloneSystem *_cloneSystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func225::func;
	return execfunc(this, _position, _cloneSystem);
}

namespace _func226
{
	static void *func = 0;
	static FunctionDefinition funcObj("CloneSystem::OnLoop", typeid(void (CloneSystem::*)()), ".554889e54157415641554154534881eca80100004989fc", nullptr, 0, 0, &func);
}

void CloneSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func226::func;
	return execfunc(this);
}

namespace _func227
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatAI::UpdateMindControl", typeid(void (CombatAI::*)(bool )), "!554889e54157415641554154534883ec584989fc498b44", nullptr, 0, 0, &func);
}

void CombatAI::UpdateMindControl(bool hostile)
{
	typedef void (*custom_arg_funcptr_t)(CombatAI *this_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func227::func;
	return execfunc(this, hostile);
}

namespace _func228
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatAI::OnLoop", typeid(void (CombatAI::*)()), "!.554889e5415741564154534989ffe80d", nullptr, 0, 0, &func);
}

void CombatAI::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CombatAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func228::func;
	return execfunc(this);
}

namespace _func229
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::constructor", typeid(void (CombatControl::*)()), "554889e54157415641554154534881eca80000004889fb", nullptr, 0, 0, &func);
}

void CombatControl::constructor()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func229::func;
	return execfunc(this);
}

namespace _func230
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::GetCurrentTarget", typeid(ShipManager *(CombatControl::*)()), ".554889e5488b87100900004885c07406", nullptr, 0, 0, &func);
}

ShipManager *CombatControl::GetCurrentTarget()
{
	typedef ShipManager *(*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func230::func;
	return execfunc(this);
}

namespace _func231
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::CurrentTargetIsBoss", typeid(char (CombatControl::*)()), ".554889e5488bbf10", nullptr, 0, 0, &func);
}

char CombatControl::CurrentTargetIsBoss()
{
	typedef char (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func231::func;
	return execfunc(this);
}

namespace _func232
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::DrawHostileBox", typeid(void (CombatControl::*)(GL_Color , int )), ".554889e54157415641554154534883ec484189f4", nullptr, 0, 0, &func);
}

void CombatControl::DrawHostileBox(GL_Color color, int stencilBit)
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg, GL_Color color_arg, int stencilBit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func232::func;
	return execfunc(this, color, stencilBit);
}

namespace _func233
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::OnRenderCombat", typeid(void (CombatControl::*)()), ".554889e54156534883ec304889fb80", nullptr, 0, 0, &func);
}

void CombatControl::OnRenderCombat()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func233::func;
	return execfunc(this);
}

namespace _func234
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::RenderTarget", typeid(void (CombatControl::*)()), ".554889e54157415641554154534881ec680100004989fd48", nullptr, 0, 0, &func);
}

void CombatControl::RenderTarget()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func234::func;
	return execfunc(this);
}

namespace _func235
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::SetMouseCursor", typeid(void (CombatControl::*)()), ".554889e54156534889fb4883", nullptr, 0, 0, &func);
}

void CombatControl::SetMouseCursor()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func235::func;
	return execfunc(this);
}

namespace _func236
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::OnRenderSelfAiming", typeid(void (CombatControl::*)()), ".554889e5534883ec184889fb488d7b20", nullptr, 0, 0, &func);
}

void CombatControl::OnRenderSelfAiming()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func236::func;
	return execfunc(this);
}

namespace _func237
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::RenderShipStatus", typeid(void (CombatControl::*)(Pointf , GL_Color )), "!.554889e54157415641554154534881ecb80000000f2955", nullptr, 0, 0, &func);
}

void CombatControl::RenderShipStatus(Pointf position, GL_Color boxColor)
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg, Pointf position_arg, GL_Color boxColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func237::func;
	return execfunc(this, position, boxColor);
}

namespace _func238
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::OnInit", typeid(void (CombatControl::*)(Point )), ".554889e54156534883ec104889fb4889b3", nullptr, 0, 0, &func);
}

void CombatControl::OnInit(Point position)
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func238::func;
	return execfunc(this, position);
}

namespace _func239
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::OnLoop", typeid(void (CombatControl::*)()), ".554889e5415741564154534883ec104989fc49", nullptr, 0, 0, &func);
}

void CombatControl::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func239::func;
	return execfunc(this);
}

namespace _func240
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::DisarmTeleporter", typeid(void (CombatControl::*)()), "!.554889e54156534889fb488b7b08be09000000e808", nullptr, 0, 0, &func);
}

void CombatControl::DisarmTeleporter()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func240::func;
	return execfunc(this);
}

namespace _func241
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::AddEnemyShip", typeid(void (CombatControl::*)(CompleteShip *)), ".554889e541574156534883ec284989ff49", nullptr, 0, 0, &func);
}

void CombatControl::AddEnemyShip(CompleteShip *enemy)
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg, CompleteShip *enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func241::func;
	return execfunc(this, enemy);
}

namespace _func242
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::Clear", typeid(void (CombatControl::*)()), ".554889e54156534989fe49c7", nullptr, 0, 0, &func);
}

void CombatControl::Clear()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func242::func;
	return execfunc(this);
}

namespace _func243
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::GetTeleportationCommand", typeid(std::pair<int, int> (CombatControl::*)()), ".554889e5415741564154534889fb41", nullptr, 0, 0, &func);
}

std::pair<int, int> CombatControl::GetTeleportationCommand()
{
	typedef std::pair<int, int> (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func243::func;
	return execfunc(this);
}

namespace _func244
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(char (CombatControl::*)()), ".554889e54156534881ec800000004889fb48", nullptr, 0, 0, &func);
}

char CombatControl::CanTargetSelf()
{
	typedef char (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func244::func;
	return execfunc(this);
}

namespace _func245
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::UpdateAiming", typeid(void (CombatControl::*)()), "!.554889e54156534883ec404889fb83", nullptr, 0, 0, &func);
}

void CombatControl::UpdateAiming()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func245::func;
	return execfunc(this);
}

namespace _func246
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::GetCrewTooltip", typeid(std::string (CombatControl::*)(int , int )), ".554889e553504889fb488b86100900004885c07426", nullptr, 0, 0, &func);
}

std::string CombatControl::GetCrewTooltip(int mX, int mY)
{
	typedef std::string (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func246::func;
	return execfunc(this, mX, mY);
}

namespace _func247
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::MouseMove", typeid(bool (CombatControl::*)(int , int )), "!.554889e5415741564154534189d64189f74989fc49c7", nullptr, 0, 0, &func);
}

bool CombatControl::MouseMove(int mX, int mY)
{
	typedef bool (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func247::func;
	return execfunc(this, mX, mY);
}

namespace _func248
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::UpdateTarget", typeid(bool (CombatControl::*)()), ".554889e5415741564154534881ec000100004989fc", nullptr, 0, 0, &func);
}

bool CombatControl::UpdateTarget()
{
	typedef bool (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func248::func;
	return execfunc(this);
}

namespace _func249
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::WeaponsArmed", typeid(bool (CombatControl::*)()), ".554889e54156534889fb488b7b08be09000000e888", nullptr, 0, 0, &func);
}

bool CombatControl::WeaponsArmed()
{
	typedef bool (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func249::func;
	return execfunc(this);
}

namespace _func250
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::SelectTarget", typeid(bool (CombatControl::*)()), ".554889e54157415641554154534881eca80000004989fc498b7c", nullptr, 0, 0, &func);
}

bool CombatControl::SelectTarget()
{
	typedef bool (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func250::func;
	return execfunc(this);
}

namespace _func251
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::DisarmAll", typeid(void (CombatControl::*)()), "!.554889e553504889fb4883bb1009", nullptr, 0, 0, &func);
}

void CombatControl::DisarmAll()
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func251::func;
	return execfunc(this);
}

namespace _func252
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::MouseRClick", typeid(bool (CombatControl::*)(int , int )), ".554889e5415741564155415453504189d64189f74889fb4c", nullptr, 0, 0, &func);
}

bool CombatControl::MouseRClick(int mX, int mY)
{
	typedef bool (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func252::func;
	return execfunc(this, mX, mY);
}

namespace _func253
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::KeyDown", typeid(void (CombatControl::*)(SDLKey )), "!.554889e54156534189f64889fb488d7b", nullptr, 0, 0, &func);
}

void CombatControl::KeyDown(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func253::func;
	return execfunc(this, key);
}

namespace _func254
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatControl::MouseClick", typeid(void (CombatControl::*)(int , int , bool )), "!.554889e54157415653504189d64189f74889fbc683b811000001", nullptr, 0, 0, &func);
}

void CombatControl::MouseClick(int mX, int mY, bool shift)
{
	typedef void (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func254::func;
	return execfunc(this, mX, mY, shift);
}

namespace _func255
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatDrone::constructor", typeid(void (CombatDrone::*)(int , int , const DroneBlueprint *)), "554889e5415741564154534883ec404989ce48", nullptr, 0, 0, &func);
}

void CombatDrone::constructor(int _iShipId, int _selfId, const DroneBlueprint *_blueprint)
{
	typedef void (*custom_arg_funcptr_t)(CombatDrone *this_arg, int _iShipId_arg, int _selfId_arg, const DroneBlueprint *_blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func255::func;
	return execfunc(this, _iShipId, _selfId, _blueprint);
}

namespace _func256
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatDrone::SetWeaponTarget", typeid(void (CombatDrone::*)(Targetable *)), ".554889e54156534989f64889fb4d85f675", nullptr, 0, 0, &func);
}

void CombatDrone::SetWeaponTarget(Targetable *target)
{
	typedef void (*custom_arg_funcptr_t)(CombatDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func256::func;
	return execfunc(this, target);
}

namespace _func257
{
	static void *func = 0;
	static FunctionDefinition funcObj("CombatDrone::PickTarget", typeid(void (CombatDrone::*)()), ".554889e553504889fb488b03ff9000", nullptr, 0, 0, &func);
}

void CombatDrone::PickTarget()
{
	typedef void (*custom_arg_funcptr_t)(CombatDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func257::func;
	return execfunc(this);
}

namespace _func258
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::constructor", typeid(void (CommandGui::*)()), ".554889e54157415641554154534881ece80000004889fbe8", nullptr, 0, 0, &func);
}

void CommandGui::constructor()
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func258::func;
	return execfunc(this);
}

namespace _func259
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::NewLocation", typeid(void (CommandGui::*)(const std::string &, std::vector<ChoiceText> *, ResourceEvent &, bool )), ".554889e54157415641554154534881ec9802", nullptr, 0, 0, &func);
}

void CommandGui::NewLocation(const std::string &mainText, std::vector<ChoiceText> *choices, ResourceEvent &resources, bool testingEvents)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, const std::string &mainText_arg, std::vector<ChoiceText> *choices_arg, ResourceEvent &resources_arg, bool testingEvents_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func259::func;
	return execfunc(this, mainText, choices, resources, testingEvents);
}

namespace _func260
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::CreateNewStore", typeid(Store *(CommandGui::*)(int )), ".554889e54157415641554154534883ec184189f74889fbbf", nullptr, 0, 0, &func);
}

Store *CommandGui::CreateNewStore(int sectorNumber)
{
	typedef Store *(*custom_arg_funcptr_t)(CommandGui *this_arg, int sectorNumber_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func260::func;
	return execfunc(this, sectorNumber);
}

namespace _func261
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(void (CommandGui::*)(std::string &)), ".554889e54157415641554154534881ec??010000??89??48897d", nullptr, 0, 0, &func);
}

void CommandGui::RunCommand(std::string &command)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, std::string &command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func261::func;
	return execfunc(this, command);
}

namespace _func262
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::Victory", typeid(void (CommandGui::*)()), ".554889e5415741564154534881eca000000049", nullptr, 0, 0, &func);
}

void CommandGui::Victory()
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func262::func;
	return execfunc(this);
}

namespace _func263
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::CheckGameover", typeid(void (CommandGui::*)()), ".554889e541574156534881ecb80000004989ff", nullptr, 0, 0, &func);
}

void CommandGui::CheckGameover()
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func263::func;
	return execfunc(this);
}

namespace _func264
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::IsGameOver", typeid(bool (CommandGui::*)()), ".554889e54156534989fe488d052f", nullptr, 0, 0, &func);
}

bool CommandGui::IsGameOver()
{
	typedef bool (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func264::func;
	return execfunc(this);
}

namespace _func265
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::KeyDown", typeid(void (CommandGui::*)(SDLKey , bool )), ".554889e54157415641554154534881ecc80100004189d7", nullptr, 0, 0, &func);
}

void CommandGui::KeyDown(SDLKey key, bool shiftHeld)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, SDLKey key_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func265::func;
	return execfunc(this, key, shiftHeld);
}

namespace _func266
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::OnLoop", typeid(void (CommandGui::*)()), ".554889e54157415641554154534883ec384889fb80bb????0000007447", nullptr, 0, 0, &func);
}

void CommandGui::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func266::func;
	return execfunc(this);
}

namespace _func267
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::MouseMove", typeid(void (CommandGui::*)(int , int )), ".554889e54157415641554154534881ec1801000041", nullptr, 0, 0, &func);
}

void CommandGui::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func267::func;
	return execfunc(this, mX, mY);
}

namespace _func268
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::OnInit", typeid(void (CommandGui::*)()), ".554889e5415741564154534881ecb000000049", nullptr, 0, 0, &func);
}

void CommandGui::OnInit()
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func268::func;
	return execfunc(this);
}

namespace _func269
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::AddEnemyShip", typeid(void (CommandGui::*)(CompleteShip *)), ".554889e541574156534883ec384989f648", nullptr, 0, 0, &func);
}

void CommandGui::AddEnemyShip(CompleteShip *ship)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func269::func;
	return execfunc(this, ship);
}

namespace _func270
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(void (CommandGui::*)()), ".554889e54157415641554154534883ec384989fc80", nullptr, 0, 0, &func);
}

void CommandGui::RenderStatic()
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func270::func;
	return execfunc(this);
}

namespace _func271
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::RenderPlayerShip", typeid(void (CommandGui::*)(Point &, float )), ".554889e541574156534883ec18f30f1145dc", nullptr, 0, 0, &func);
}

void CommandGui::RenderPlayerShip(Point &shipCenter, float jumpScale)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, Point &shipCenter_arg, float jumpScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func271::func;
	return execfunc(this, shipCenter, jumpScale);
}

namespace _func272
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::GetWorldCoordinates", typeid(Point (CommandGui::*)(Point , bool )), ".554889e5415741564154534883ec104189d74989f4", nullptr, 0, 0, &func);
}

Point CommandGui::GetWorldCoordinates(Point point, bool fromTarget)
{
	typedef Point (*custom_arg_funcptr_t)(CommandGui *this_arg, Point point_arg, bool fromTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func272::func;
	return execfunc(this, point, fromTarget);
}

namespace _func273
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::LButtonDown", typeid(void (CommandGui::*)(int , int , bool )), "!.554889e54157415641554154534883ec284189cd", nullptr, 0, 0, &func);
}

void CommandGui::LButtonDown(int mX, int mY, bool shiftHeld)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func273::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func274
{
	static void *func = 0;
	static FunctionDefinition funcObj("CommandGui::LButtonUp", typeid(void (CommandGui::*)(int , int , bool )), "!.554889e54157415653504189d64189f74889fb80bb", nullptr, 0, 0, &func);
}

void CommandGui::LButtonUp(int mX, int mY, bool shiftHeld)
{
	typedef void (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func274::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func275
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (CompleteShip::*)()), "554889e553504889fb488d05????320048890389", nullptr, 0, 0, &func);
}

namespace _func276
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(void (CompleteShip::*)(SpaceManager *, bool , int )), ".554889e553504889fb488d05????320048890389", nullptr, 0, 0, &func);
}

void CompleteShip::constructor(SpaceManager *_space, bool _bPlayerShip, int _iShipId)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, SpaceManager *_space_arg, bool _bPlayerShip_arg, int _iShipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func276::func;
	return execfunc(this, _space, _bPlayerShip, _iShipId);
}

namespace _func277
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(void (CompleteShip::*)(ShipManager *)), "!.554889e548897710", nullptr, 0, 0, &func);
}

void CompleteShip::SetShip(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func277::func;
	return execfunc(this, ship);
}

namespace _func278
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(void (CompleteShip::*)(const ShipBlueprint *, int )), "!.554889e5415741564154534189d64989f74889fbbf", nullptr, 0, 0, &func);
}

void CompleteShip::OnInit(const ShipBlueprint *blueprint, int level)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, const ShipBlueprint *blueprint_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func278::func;
	return execfunc(this, blueprint, level);
}

namespace _func279
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , const std::string &, bool )), ".554889e54157415641554154534881ec880000004189cf", nullptr, 0, 0, &func);
}

void CompleteShip::AddBoarders(int amount, const std::string &race, bool breach)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, int amount_arg, const std::string &race_arg, bool breach_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func279::func;
	return execfunc(this, amount, race, breach);
}

namespace _func280
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(CrewMember *(CompleteShip::*)(const CrewBlueprint *, bool )), ".554889e54157415641554154534881ecc80100004189d5", nullptr, 0, 0, &func);
}

CrewMember *CompleteShip::AddCrewMember(const CrewBlueprint *blueprint, bool hostile)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(CompleteShip *this_arg, const CrewBlueprint *blueprint_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func280::func;
	return execfunc(this, blueprint, hostile);
}

namespace _func281
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(const std::string &, const std::string &, bool )), ".554889e54157415641554154534883ec78894d", nullptr, 0, 0, &func);
}

CrewMember *CompleteShip::AddCrewMember1(const std::string &race, const std::string &name, bool hostile)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(CompleteShip *this_arg, const std::string &race_arg, const std::string &name_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func281::func;
	return execfunc(this, race, name, hostile);
}

namespace _func282
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::AddDrone", typeid(Drone *(CompleteShip::*)(const DroneBlueprint *, int )), "!.554889e5488b7f105de9????07", nullptr, 0, 0, &func);
}

Drone *CompleteShip::AddDrone(const DroneBlueprint *blueprint, int slot)
{
	typedef Drone *(*custom_arg_funcptr_t)(CompleteShip *this_arg, const DroneBlueprint *blueprint_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func282::func;
	return execfunc(this, blueprint, slot);
}

namespace _func283
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember2", typeid(CrewMember *(CompleteShip::*)(CrewMember *, int )), "!.554889e54157415653504189d64889f34989ff48", nullptr, 0, 0, &func);
}

CrewMember *CompleteShip::AddCrewMember2(CrewMember *crew, int roomId)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(CompleteShip *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func283::func;
	return execfunc(this, crew, roomId);
}

namespace _func284
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(void (CompleteShip::*)(int )), "!.554889e58b87e801000089", nullptr, 0, 0, &func);
}

void CompleteShip::SaveState(int fd)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func284::func;
	return execfunc(this, fd);
}

namespace _func285
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(void (CompleteShip::*)(int )), ".554889e54156534883ec204889fb89f7", nullptr, 0, 0, &func);
}

void CompleteShip::LoadState(int fd)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func285::func;
	return execfunc(this, fd);
}

namespace _func286
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(void (CompleteShip::*)(int , int )), ".554889e5415741564154534883ec604189d64189f74989fc49", nullptr, 0, 0, &func);
}

void CompleteShip::InitiateTeleport(int targetRoom, int command)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, int targetRoom_arg, int command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func286::func;
	return execfunc(this, targetRoom, command);
}

namespace _func287
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::TeleportCrew", typeid(std::vector<CrewMember*> (CompleteShip::*)(int , bool )), ".554889e553504889fb488b76", nullptr, 0, 0, &func);
}

std::vector<CrewMember*> CompleteShip::TeleportCrew(int roomId, bool intruders)
{
	typedef std::vector<CrewMember*> (*custom_arg_funcptr_t)(CompleteShip *this_arg, int roomId_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func287::func;
	return execfunc(this, roomId, intruders);
}

namespace _func288
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::GetTeleportingParty", typeid(std::vector<CrewMember*> (CompleteShip::*)()), ".554889e5415741564155415453504989fe4c", nullptr, 0, 0, &func);
}

std::vector<CrewMember*> CompleteShip::GetTeleportingParty()
{
	typedef std::vector<CrewMember*> (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func288::func;
	return execfunc(this);
}

namespace _func289
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::KillRandomCrew", typeid(void (CompleteShip::*)()), "!.554889e5488b7f105de9????08", nullptr, 0, 0, &func);
}

void CompleteShip::KillRandomCrew()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func289::func;
	return execfunc(this);
}

namespace _func290
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::CountCrew", typeid(int (CompleteShip::*)(bool )), "!.554889e5488b7f1040", nullptr, 0, 0, &func);
}

int CompleteShip::CountCrew(bool boarders)
{
	typedef int (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool boarders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func290::func;
	return execfunc(this, boarders);
}

namespace _func291
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(void (CompleteShip::*)()), ".554889e5488b87b8", nullptr, 0, 0, &func);
}

void CompleteShip::Jump()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func291::func;
	return execfunc(this);
}

namespace _func292
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::SetEnemyShip", typeid(void (CompleteShip::*)(CompleteShip *)), "!.554889e5488977204883", nullptr, 0, 0, &func);
}

void CompleteShip::SetEnemyShip(CompleteShip *other)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, CompleteShip *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func292::func;
	return execfunc(this, other);
}

namespace _func293
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), ".554889e54156534889fb31", nullptr, 0, 0, &func);
}

bool CompleteShip::DeadCrew()
{
	typedef bool (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func293::func;
	return execfunc(this);
}

namespace _func294
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(void (CompleteShip::*)()), "!.554889e5415741564155415453504989fc498b7c", nullptr, 0, 0, &func);
}

void CompleteShip::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func294::func;
	return execfunc(this);
}

namespace _func295
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(void (CompleteShip::*)()), "!.554889e5488b7f105de9", nullptr, 0, 0, &func);
}

void CompleteShip::PauseLoop()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func295::func;
	return execfunc(this);
}

namespace _func296
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::OnRender", typeid(void (CompleteShip::*)()), "!.554889e553504889fb488b7b188b", nullptr, 0, 0, &func);
}

void CompleteShip::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func296::func;
	return execfunc(this);
}

namespace _func297
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(void (CompleteShip::*)(bool , bool )), "!.554889e54157415653504189d64189f74889fb488b7b", nullptr, 0, 0, &func);
}

void CompleteShip::OnRenderShip(bool showInterior, bool doorControlMode)
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool showInterior_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func297::func;
	return execfunc(this, showInterior, doorControlMode);
}

namespace _func298
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::OnRenderSpace", typeid(void (CompleteShip::*)()), "!.554889e5488b7f18f3", nullptr, 0, 0, &func);
}

void CompleteShip::OnRenderSpace()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func298::func;
	return execfunc(this);
}

namespace _func299
{
	static void *func = 0;
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(void (CompleteShip::*)()), "!.554889e553504889fb488b7b10e8????08", nullptr, 0, 0, &func);
}

void CompleteShip::Restart()
{
	typedef void (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func299::func;
	return execfunc(this);
}

namespace _func300
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::constructor", typeid(void (ConfirmWindow::*)()), "!.554889e553504889fbe8a298", nullptr, 0, 0, &func);
}

void ConfirmWindow::constructor()
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func300::func;
	return execfunc(this);
}

namespace _func301
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::SetText", typeid(void (ConfirmWindow::*)(const TextString &, int , bool , const TextString &, const TextString &)), ".554889e54157415641554154534883ec584c", nullptr, 0, 0, &func);
}

void ConfirmWindow::SetText(const TextString &text, int minWidth, bool autoCenter, const TextString &yesText, const TextString &noText)
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, const TextString &text_arg, int minWidth_arg, bool autoCenter_arg, const TextString &yesText_arg, const TextString &noText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func301::func;
	return execfunc(this, text, minWidth, autoCenter, yesText, noText);
}

namespace _func302
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::SetPosition", typeid(void (ConfirmWindow::*)(Point )), ".554889e54157415641554154534883ec184989fde8", nullptr, 0, 0, &func);
}

void ConfirmWindow::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func302::func;
	return execfunc(this, position);
}

namespace _func303
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::Open", typeid(void (ConfirmWindow::*)()), ".554889e54157415641554154534883ec284989fde8", nullptr, 0, 0, &func);
}

void ConfirmWindow::Open()
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func303::func;
	return execfunc(this);
}

namespace _func304
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::Close", typeid(void (ConfirmWindow::*)()), "!.554889e553504889fb488bbba0", nullptr, 0, 0, &func);
}

void ConfirmWindow::Close()
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func304::func;
	return execfunc(this);
}

namespace _func305
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::OnRender", typeid(void (ConfirmWindow::*)()), ".554889e54157415641554154534883ec784989fd498bbd", nullptr, 0, 0, &func);
}

void ConfirmWindow::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func305::func;
	return execfunc(this);
}

namespace _func306
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::MouseMove", typeid(void (ConfirmWindow::*)(int , int )), "!.554889e54157415653504189d64189f74889fb807b", nullptr, 0, 0, &func);
}

void ConfirmWindow::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func306::func;
	return execfunc(this, mX, mY);
}

namespace _func307
{
	static void *func = 0;
	static FunctionDefinition funcObj("ConfirmWindow::MouseClick", typeid(void (ConfirmWindow::*)(int , int )), ".554889e5807f08", nullptr, 0, 0, &func);
}

void ConfirmWindow::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func307::func;
	return execfunc(this, mX, mY);
}

namespace _func308
{
	static void *func = 0;
	static FunctionDefinition funcObj("ControlButton::OnRender", typeid(void (ControlButton::*)()), ".554889e5534883ec684889fb8b", nullptr, 0, 0, &func);
}

void ControlButton::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ControlButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func308::func;
	return execfunc(this);
}

namespace _func309
{
	static void *func = 0;
	static FunctionDefinition funcObj("ControlsScreen::OnInit", typeid(void (ControlsScreen::*)()), "554889e54157415641554154534881ec680100004989fd4983", nullptr, 0, 0, &func);
}

void ControlsScreen::OnInit()
{
	typedef void (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func309::func;
	return execfunc(this);
}

namespace _func310
{
	static void *func = 0;
	static FunctionDefinition funcObj("ControlsScreen::OnLoop", typeid(void (ControlsScreen::*)()), ".554889e54157415653504989fe496386", nullptr, 0, 0, &func);
}

void ControlsScreen::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func310::func;
	return execfunc(this);
}

namespace _func311
{
	static void *func = 0;
	static FunctionDefinition funcObj("ControlsScreen::OnRender", typeid(void (ControlsScreen::*)()), ".554889e54157415641554154534881ece80000004989fe", nullptr, 0, 0, &func);
}

void ControlsScreen::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func311::func;
	return execfunc(this);
}

namespace _func312
{
	static void *func = 0;
	static FunctionDefinition funcObj("CooldownSystemBox::constructor", typeid(void (CooldownSystemBox::*)(Point , ShipSystem *, bool )), ".554889e54157415641554154534883ec584189cf49", nullptr, 0, 0, &func);
}

void CooldownSystemBox::constructor(Point _position, ShipSystem *_system, bool _roundDown)
{
	typedef void (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, Point _position_arg, ShipSystem *_system_arg, bool _roundDown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func312::func;
	return execfunc(this, _position, _system, _roundDown);
}

namespace _func313
{
	static void *func = 0;
	static FunctionDefinition funcObj("CooldownSystemBox::OnRender", typeid(void (CooldownSystemBox::*)(bool )), ".554889e541574156534883ec384989fe40", nullptr, 0, 0, &func);
}

void CooldownSystemBox::OnRender(bool ignoreStatus)
{
	typedef void (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func313::func;
	return execfunc(this, ignoreStatus);
}

namespace _func314
{
	static void *func = 0;
	static FunctionDefinition funcObj("CreditScreen::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (CreditScreen::*)()), "554889e5c74738", nullptr, 0, 0, &func);
}

namespace _func315
{
	static void *func = 0;
	static FunctionDefinition funcObj("CreditScreen::constructor", typeid(void (CreditScreen::*)()), ".554889e5c74738", nullptr, 0, 0, &func);
}

void CreditScreen::constructor()
{
	typedef void (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func315::func;
	return execfunc(this);
}

namespace _func316
{
	static void *func = 0;
	static FunctionDefinition funcObj("CreditScreen::Start", typeid(void (CreditScreen::*)(const std::string &, const std::vector<std::string> &)), ".554889e54157415641554154534881ec9801000049", nullptr, 0, 0, &func);
}

void CreditScreen::Start(const std::string &shipName, const std::vector<std::string> &crewNames)
{
	typedef void (*custom_arg_funcptr_t)(CreditScreen *this_arg, const std::string &shipName_arg, const std::vector<std::string> &crewNames_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func316::func;
	return execfunc(this, shipName, crewNames);
}

namespace _func317
{
	static void *func = 0;
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), ".554889e54156534889fb488b43", nullptr, 0, 0, &func);
}

bool CreditScreen::Done()
{
	typedef bool (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func317::func;
	return execfunc(this);
}

namespace _func318
{
	static void *func = 0;
	static FunctionDefinition funcObj("CreditScreen::OnRender", typeid(void (CreditScreen::*)()), ".554889e54157415641554154534883ec684989ffe8????15", nullptr, 0, 0, &func);
}

void CreditScreen::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func318::func;
	return execfunc(this);
}

namespace _func319
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::OnLoop", typeid(void (CrewAI::*)()), ".554889e54157415641554154534883ec584989fd49", nullptr, 0, 0, &func);
}

void CrewAI::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func319::func;
	return execfunc(this);
}

namespace _func320
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::CheckForProblems", typeid(void (CrewAI::*)()), ".554889e54157415641554154534883ec684989ff41", nullptr, 0, 0, &func);
}

void CrewAI::CheckForProblems()
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func320::func;
	return execfunc(this);
}

namespace _func321
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::UpdateCrewMember", typeid(void (CrewAI::*)(int )), "!.554889e54157415641554154534883ec384863", nullptr, 0, 0, &func);
}

void CrewAI::UpdateCrewMember(int crewId)
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func321::func;
	return execfunc(this, crewId);
}

namespace _func322
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::UpdateDrones", typeid(void (CrewAI::*)()), ".554889e54157415641554154534883ec584989fe498b46", nullptr, 0, 0, &func);
}

void CrewAI::UpdateDrones()
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func322::func;
	return execfunc(this);
}

namespace _func323
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::AssignCrewmembers", typeid(void (CrewAI::*)()), ".554889e5415741564154534989fe498b46", nullptr, 0, 0, &func);
}

void CrewAI::AssignCrewmembers()
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func323::func;
	return execfunc(this);
}

namespace _func324
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::CheckForHealing", typeid(void (CrewAI::*)()), ".554889e5415741564155415453504989fd41", nullptr, 0, 0, &func);
}

void CrewAI::CheckForHealing()
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func324::func;
	return execfunc(this);
}

namespace _func325
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::UpdateIntruders", typeid(void (CrewAI::*)()), ".554889e5415741564155415453504989ff498b47", nullptr, 0, 0, &func);
}

void CrewAI::UpdateIntruders()
{
	typedef void (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func325::func;
	return execfunc(this);
}

namespace _func326
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::PrioritizeTask", typeid(int (CrewAI::*)(CrewTask , int )), ".554889e5415741564155415453504189cd4189d4", nullptr, 0, 0, &func);
}

int CrewAI::PrioritizeTask(CrewTask task, int crewId)
{
	typedef int (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewTask task_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func326::func;
	return execfunc(this, task, crewId);
}

namespace _func327
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::PrioritizeIntruderRoom", typeid(int (CrewAI::*)(CrewMember *, int , int )), ".554889e54157415641554154534883ec18894dc8", nullptr, 0, 0, &func);
}

int CrewAI::PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target)
{
	typedef int (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewMember *crew_arg, int roomId_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func327::func;
	return execfunc(this, crew, roomId, target);
}

namespace _func328
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAI::DangerRating", typeid(int (CrewAI::*)(int , int )), ".554889e54157415641554154534883ec484189f7", nullptr, 0, 0, &func);
}

int CrewAI::DangerRating(int roomId, int crewId)
{
	typedef int (*custom_arg_funcptr_t)(CrewAI *this_arg, int roomId_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func328::func;
	return execfunc(this, roomId, crewId);
}

namespace _func329
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::destructor", typeid(void (CrewAnimation::*)()), "!554889e5415741564155415453504989fe488d05", nullptr, 0, 0, &func);
}

void CrewAnimation::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func329::func;
	return execfunc(this);
}

namespace _func330
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::SetupStrips", typeid(void (CrewAnimation::*)()), ".554889e54157415641554154534881ecd80100004989fd49", nullptr, 0, 0, &func);
}

void CrewAnimation::SetupStrips()
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func330::func;
	return execfunc(this);
}

namespace _func331
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::OnUpdate", typeid(void (CrewAnimation::*)(Pointf , bool , bool , bool , bool , bool )), ".554889e54156534881ec900000000f", nullptr, 0, 0, &func);
}

void CrewAnimation::OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire)
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg, Pointf position_arg, bool moving_arg, bool fighting_arg, bool repairing_arg, bool dying_arg, bool onFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func331::func;
	return execfunc(this, position, moving, fighting, repairing, dying, onFire);
}

namespace _func332
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::OnInit", typeid(void (CrewAnimation::*)(const std::string &, Pointf , bool )), ".554889e54157415641554154534881ecc80300000f", nullptr, 0, 0, &func);
}

void CrewAnimation::OnInit(const std::string &name, Pointf position, bool enemy)
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg, const std::string &name_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func332::func;
	return execfunc(this, name, position, enemy);
}

namespace _func333
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::OnRenderProps", typeid(void (CrewAnimation::*)()), "!.554889e54157415653504989fee8????0e", nullptr, 0, 0, &func);
}

void CrewAnimation::OnRenderProps()
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func333::func;
	return execfunc(this);
}

namespace _func334
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::GetFiringFrame", typeid(int (CrewAnimation::*)()), ".554889e58b4f5c", nullptr, 0, 0, &func);
}

int CrewAnimation::GetFiringFrame()
{
	typedef int (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func334::func;
	return execfunc(this);
}

namespace _func335
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::RenderIcon", typeid(void (CrewAnimation::*)(bool )), ".554889e5415741564154534881ec000100004989ff", nullptr, 0, 0, &func);
}

void CrewAnimation::RenderIcon(bool border)
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg, bool border_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func335::func;
	return execfunc(this, border);
}

namespace _func336
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::OnRender", typeid(void (CrewAnimation::*)(float , int , bool )), ".554889e5415741564154534883ec604189d64189f74989fc41", nullptr, 0, 0, &func);
}

void CrewAnimation::OnRender(float scale, int selectedState, bool outlineOnly)
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg, float scale_arg, int selectedState_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func336::func;
	return execfunc(this, scale, selectedState, outlineOnly);
}

namespace _func337
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::constructor", typeid(void (CrewAnimation::*)(int , const std::string &, Pointf , bool )), ".554889e54157415641554154534881eca800000089", nullptr, 0, 0, &func);
}

void CrewAnimation::constructor(int _shipId, const std::string &_race, Pointf _position, bool _enemy)
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg, int _shipId_arg, const std::string &_race_arg, Pointf _position_arg, bool _enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func337::func;
	return execfunc(this, _shipId, _race, _position, _enemy);
}

namespace _func338
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::GetDeathSound", typeid(std::string (CrewAnimation::*)()), ".554889e54156534883ec204889fb80be", nullptr, 0, 0, &func);
}

std::string CrewAnimation::GetDeathSound()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func338::func;
	return execfunc(this);
}

namespace _func339
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::GetShootingSound", typeid(std::string (CrewAnimation::*)()), ".554889e54156534883ec204889fb488d051b", nullptr, 0, 0, &func);
}

std::string CrewAnimation::GetShootingSound()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func339::func;
	return execfunc(this);
}

namespace _func340
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::FireShot", typeid(bool (CrewAnimation::*)()), "!.554889e553504889fb4881c3d8", nullptr, 0, 0, &func);
}

bool CrewAnimation::FireShot()
{
	typedef bool (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func340::func;
	return execfunc(this);
}

namespace _func341
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewAnimation::OnUpdateEffects", typeid(void (CrewAnimation::*)()), ".554889e5415741564155415453504989fe498d", nullptr, 0, 0, &func);
}

void CrewAnimation::OnUpdateEffects()
{
	typedef void (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func341::func;
	return execfunc(this);
}

namespace _func342
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBlueprint::destructor", typeid(void (CrewBlueprint::*)()), "!554889e54157415653504989fe488d05????32", nullptr, 0, 0, &func);
}

void CrewBlueprint::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func342::func;
	return execfunc(this);
}

namespace _func343
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBlueprint::RandomSkills", typeid(void (CrewBlueprint::*)(int )), ".554889e54157415641554154534883ec4848897d90", nullptr, 0, 0, &func);
}

void CrewBlueprint::RandomSkills(int worldLevel)
{
	typedef void (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func343::func;
	return execfunc(this, worldLevel);
}

namespace _func344
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBlueprint::RenderIcon", typeid(void (CrewBlueprint::*)(float )), ".554889e54157415641554154534881ece8010000f3", nullptr, 0, 0, &func);
}

void CrewBlueprint::RenderIcon(float opacity)
{
	typedef void (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, float opacity_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func344::func;
	return execfunc(this, opacity);
}

namespace _func345
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBlueprint::GetCurrentSkillColor", typeid(GL_Color (CrewBlueprint::*)(int )), ".554889e54863c6488b8f38", nullptr, 0, 0, &func);
}

GL_Color CrewBlueprint::GetCurrentSkillColor(int skill)
{
	typedef GL_Color (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func345::func;
	return execfunc(this, skill);
}

namespace _func346
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBlueprint::RenderSkill", typeid(void (CrewBlueprint::*)(int , int , int , int , int )), "!.554889e54157415641554154534883ec184589c74189ce", nullptr, 0, 0, &func);
}

void CrewBlueprint::RenderSkill(int x, int y, int length, int height, int skill)
{
	typedef void (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int x_arg, int y_arg, int length_arg, int height_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func346::func;
	return execfunc(this, x, y, length, height, skill);
}

namespace _func347
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBlueprint::GetNameShort", typeid(std::string (CrewBlueprint::*)()), ".554889e5415741564154534883ec204989f4", nullptr, 0, 0, &func);
}

std::string CrewBlueprint::GetNameShort()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func347::func;
	return execfunc(this);
}

namespace _func348
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::constructor", typeid(void (CrewBox::*)(Point , CrewMember *, int )), "554889e54157415641554154534881ec980000004189cf", nullptr, 0, 0, &func);
}

void CrewBox::constructor(Point _position, CrewMember *_crew, int _number)
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg, Point _position_arg, CrewMember *_crew_arg, int _number_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func348::func;
	return execfunc(this, _position, _crew, _number);
}

namespace _func349
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::destructor", typeid(void (CrewBox::*)()), "!.554889e54156534889fb488bbb", nullptr, 0, 0, &func);
}

void CrewBox::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func349::func;
	return execfunc(this);
}

namespace _func350
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::OnLoop", typeid(void (CrewBox::*)(bool )), "!.554889e54156534189f64889fb488b7b20", nullptr, 0, 0, &func);
}

void CrewBox::OnLoop(bool selected)
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg, bool selected_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func350::func;
	return execfunc(this, selected);
}

namespace _func351
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::MouseClick", typeid(bool (CrewBox::*)()), ".807f780074", nullptr, 0, 0, &func);
}

bool CrewBox::MouseClick()
{
	typedef bool (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func351::func;
	return execfunc(this);
}

namespace _func352
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::GetSelected", typeid(CrewMember *(CrewBox::*)(int , int )), ".554889e54157415641554154534881ec180100004189d7", nullptr, 0, 0, &func);
}

CrewMember *CrewBox::GetSelected(int mX, int mY)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(CrewBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func352::func;
	return execfunc(this, mX, mY);
}

namespace _func353
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::OnRenderSkillLevel", typeid(void (CrewBox::*)()), ".554889e54156534883ec204889fb80bb5c", nullptr, 0, 0, &func);
}

void CrewBox::OnRenderSkillLevel()
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func353::func;
	return execfunc(this);
}

namespace _func354
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::OnRender", typeid(void (CrewBox::*)()), ".554889e54157415641554154534883ec584989ff49", nullptr, 0, 0, &func);
}

void CrewBox::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func354::func;
	return execfunc(this);
}

namespace _func355
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::RenderIcon", typeid(void (CrewBox::*)()), "!.554889e54156534889fb488b7b20", nullptr, 0, 0, &func);
}

void CrewBox::RenderIcon()
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func355::func;
	return execfunc(this);
}

namespace _func356
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::RenderLabels", typeid(void (CrewBox::*)()), ".554889e54156534883ec204889fb488b73", nullptr, 0, 0, &func);
}

void CrewBox::RenderLabels()
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func356::func;
	return execfunc(this);
}

namespace _func357
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewBox::RenderCloneDying", typeid(void (CrewBox::*)()), ".80bf4401000000754f", nullptr, 0, 0, &func);
}

void CrewBox::RenderCloneDying()
{
	typedef void (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func357::func;
	return execfunc(this);
}

namespace _func358
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::destructor", typeid(void (CrewControl::*)()), "!.554889e54157415653504989fe498b4660", nullptr, 0, 0, &func);
}

void CrewControl::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func358::func;
	return execfunc(this);
}

namespace _func359
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::ClearCrewBoxes", typeid(void (CrewControl::*)()), ".554889e54157415653504989fe498b4660", nullptr, 0, 0, &func);
}

void CrewControl::ClearCrewBoxes()
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func359::func;
	return execfunc(this);
}

namespace _func360
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::UpdateCrewBoxes", typeid(void (CrewControl::*)()), ".554889e54157415641554154534883ec484989fd0f", nullptr, 0, 0, &func);
}

void CrewControl::UpdateCrewBoxes()
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func360::func;
	return execfunc(this);
}

namespace _func361
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::LinkShip", typeid(void (CrewControl::*)(ShipManager *)), ".554889e553504889fb488933", nullptr, 0, 0, &func);
}

void CrewControl::LinkShip(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func361::func;
	return execfunc(this, ship);
}

namespace _func362
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::OnLoop", typeid(void (CrewControl::*)()), ".554889e5415741564154534883ec504989fe498d", nullptr, 0, 0, &func);
}

void CrewControl::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func362::func;
	return execfunc(this);
}

namespace _func363
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::ClearDeadCrew", typeid(void (CrewControl::*)(std::vector<CrewMember*> *)), ".554889e5415741564154534989f6498b", nullptr, 0, 0, &func);
}

void CrewControl::ClearDeadCrew(std::vector<CrewMember*> *crew)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, std::vector<CrewMember*> *crew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func363::func;
	return execfunc(this, crew);
}

namespace _func364
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::SelectPotentialCrew", typeid(void (CrewControl::*)(CrewMember *, bool )), "!.554889e54157415641554154534883ec184189d748", nullptr, 0, 0, &func);
}

void CrewControl::SelectPotentialCrew(CrewMember *crew, bool allowTeleportLeaving)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, CrewMember *crew_arg, bool allowTeleportLeaving_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func364::func;
	return execfunc(this, crew, allowTeleportLeaving);
}

namespace _func365
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::OnRender", typeid(void (CrewControl::*)()), ".554889e54157415641554154534883ec484989fd498b45", nullptr, 0, 0, &func);
}

void CrewControl::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func365::func;
	return execfunc(this);
}

namespace _func366
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::LButton", typeid(void (CrewControl::*)(int , int , int , int , bool )), ".554889e54157415641554154534883ec684589c4", nullptr, 0, 0, &func);
}

void CrewControl::LButton(int mX, int mY, int wX, int wY, bool shiftHeld)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, int wX_arg, int wY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func366::func;
	return execfunc(this, mX, mY, wX, wY, shiftHeld);
}

namespace _func367
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::SelectCrew", typeid(void (CrewControl::*)(bool )), ".554889e54157415641554154534883ec284989fd40", nullptr, 0, 0, &func);
}

void CrewControl::SelectCrew(bool keep_current)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, bool keep_current_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func367::func;
	return execfunc(this, keep_current);
}

namespace _func368
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::RButton", typeid(void (CrewControl::*)(int , int , bool )), ".554889e54157415653504989ff4180", nullptr, 0, 0, &func);
}

void CrewControl::RButton(int mX, int mY, bool shiftHeld)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func368::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func369
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::MouseMove", typeid(void (CrewControl::*)(int , int , int , int )), ".554889e54157415641554154534881ec2801000045", nullptr, 0, 0, &func);
}

void CrewControl::MouseMove(int mX, int mY, int wX, int wY)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, int wX_arg, int wY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func369::func;
	return execfunc(this, mX, mY, wX, wY);
}

namespace _func370
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewControl::KeyDown", typeid(void (CrewControl::*)(SDLKey )), ".554889e54157415641554154534881ec980000008975", nullptr, 0, 0, &func);
}

void CrewControl::KeyDown(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CrewControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func370::func;
	return execfunc(this, key);
}

namespace _func371
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewCustomizeBox::CheckContents", typeid(void (CrewCustomizeBox::*)()), ".554889e54156534883ec204889fb80bbd8", nullptr, 0, 0, &func);
}

void CrewCustomizeBox::CheckContents()
{
	typedef void (*custom_arg_funcptr_t)(CrewCustomizeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func371::func;
	return execfunc(this);
}

namespace _func372
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewDrone::constructor", typeid(void (CrewDrone::*)(const std::string &, const std::string &, int , const DroneBlueprint *, CrewAnimation *)), "554889e54157415641554154534881ec180200004c", nullptr, 0, 0, &func);
}

void CrewDrone::constructor(const std::string &_type, const std::string &_name, int _iShipId, const DroneBlueprint *_blueprint, CrewAnimation *_animation)
{
	typedef void (*custom_arg_funcptr_t)(CrewDrone *this_arg, const std::string &_type_arg, const std::string &_name_arg, int _iShipId_arg, const DroneBlueprint *_blueprint_arg, CrewAnimation *_animation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func372::func;
	return execfunc(this, _type, _name, _iShipId, _blueprint, _animation);
}

namespace _func373
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewDrone::OnLoop", typeid(void (CrewDrone::*)()), "!.554889e5415741564155415453504889fb4c", nullptr, 0, 0, &func);
}

void CrewDrone::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func373::func;
	return execfunc(this);
}

namespace _func374
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewDrone::destructor", typeid(void (CrewDrone::*)()), "!.554889e553504889fb488d0520????00488903488d0556", nullptr, 0, 0, &func);
}

void CrewDrone::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func374::func;
	return execfunc(this);
}

namespace _func375
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewDrone::ProvidesVision", typeid(bool (CrewDrone::*)()), "!.554889e5837f08007409", nullptr, 0, 0, &func);
}

bool CrewDrone::ProvidesVision()
{
	typedef bool (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func375::func;
	return execfunc(this);
}

namespace _func376
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewDrone::SetCurrentShip", typeid(void (CrewDrone::*)(int )), "!.554889e55de9269d", nullptr, 0, 0, &func);
}

void CrewDrone::SetCurrentShip(int shipId)
{
	typedef void (*custom_arg_funcptr_t)(CrewDrone *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func376::func;
	return execfunc(this, shipId);
}

namespace _func377
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::constructor", typeid(void (CrewEquipBox::*)(Point , ShipManager *, int )), ".554889e54157415641554154534881ec880000004189ce", nullptr, 0, 0, &func);
}

void CrewEquipBox::constructor(Point _position, ShipManager *_shipManager, int _slot)
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, Point _position_arg, ShipManager *_shipManager_arg, int _slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func377::func;
	return execfunc(this, _position, _shipManager, _slot);
}

namespace _func378
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::RemoveItem", typeid(void (CrewEquipBox::*)()), ".554889e553504889fb488bbb9000000048", nullptr, 0, 0, &func);
}

void CrewEquipBox::RemoveItem()
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func378::func;
	return execfunc(this);
}

namespace _func379
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::GetConfirmDelete", typeid(bool (CrewEquipBox::*)()), ".554889e58a8770", nullptr, 0, 0, &func);
}

bool CrewEquipBox::GetConfirmDelete()
{
	typedef bool (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func379::func;
	return execfunc(this);
}

namespace _func380
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::CloseRename", typeid(void (CrewEquipBox::*)()), "!.554889e580bfea", nullptr, 0, 0, &func);
}

void CrewEquipBox::CloseRename()
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func380::func;
	return execfunc(this);
}

namespace _func381
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::OnRender", typeid(void (CrewEquipBox::*)(bool )), ".554889e54157415641554154534883ec484189f64989fc4d", nullptr, 0, 0, &func);
}

void CrewEquipBox::OnRender(bool dragging)
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, bool dragging_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func381::func;
	return execfunc(this, dragging);
}

namespace _func382
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::RenderLabels", typeid(void (CrewEquipBox::*)(bool , bool )), ".554889e54156534883ec504889fb48", nullptr, 0, 0, &func);
}

void CrewEquipBox::RenderLabels(bool dragging, bool isNew)
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, bool dragging_arg, bool isNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func382::func;
	return execfunc(this, dragging, isNew);
}

namespace _func383
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::MouseClick", typeid(void (CrewEquipBox::*)()), "!.554889e541574156534883ec384889fb4883", nullptr, 0, 0, &func);
}

void CrewEquipBox::MouseClick()
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func383::func;
	return execfunc(this);
}

namespace _func384
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::OnTextInput", typeid(void (CrewEquipBox::*)(SDLKey )), "!.554889e54156534189f64889fb4881", nullptr, 0, 0, &func);
}

void CrewEquipBox::OnTextInput(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func384::func;
	return execfunc(this, key);
}

namespace _func385
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewEquipBox::OnTextEvent", typeid(void (CrewEquipBox::*)(CEvent::TextEvent )), "!.554889e54156534189f64889fb4881", nullptr, 0, 0, &func);
}

void CrewEquipBox::OnTextEvent(CEvent::TextEvent event)
{
	typedef void (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func385::func;
	return execfunc(this, event);
}

namespace _func386
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::constructor", typeid(void (CrewManifest::*)()), "!554889e5415741564154534881ecb000000048", nullptr, 0, 0, &func);
}

void CrewManifest::constructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func386::func;
	return execfunc(this);
}

namespace _func387
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::OnInit", typeid(void (CrewManifest::*)(ShipManager *)), ".554889e54157415641554154534883ec484989f4", nullptr, 0, 0, &func);
}

void CrewManifest::OnInit(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func387::func;
	return execfunc(this, ship);
}

namespace _func388
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::Close", typeid(void (CrewManifest::*)()), "!.554889e54157415653504989fe498b8608", nullptr, 0, 0, &func);
}

void CrewManifest::Close()
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func388::func;
	return execfunc(this);
}

namespace _func389
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::MouseClick", typeid(void (CrewManifest::*)(int , int )), "!.554889e54156534989fe4183be88", nullptr, 0, 0, &func);
}

void CrewManifest::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func389::func;
	return execfunc(this, mX, mY);
}

namespace _func390
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::Update", typeid(void (CrewManifest::*)()), ".554889e541574156534883ec584989fe0f", nullptr, 0, 0, &func);
}

void CrewManifest::Update()
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func390::func;
	return execfunc(this);
}

namespace _func391
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::OnKeyDown", typeid(void (CrewManifest::*)(SDLKey )), ".554889e5415741564154534189f64989ff498b870801000049398710010000744ebb010000004531e40f1f80000000004a8b3ce0e87789", nullptr, 0, 0, &func);
}

void CrewManifest::OnKeyDown(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func391::func;
	return execfunc(this, key);
}

namespace _func392
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::OnKeyUp", typeid(void (CrewManifest::*)(SDLKey )), ".554889e5415741564154534189f64989ff498b870801000049398710010000744ebb010000004531e40f1f80000000004a8b3ce0e8f788", nullptr, 0, 0, &func);
}

void CrewManifest::OnKeyUp(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func392::func;
	return execfunc(this, key);
}

namespace _func393
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::OnTextInput", typeid(void (CrewManifest::*)(SDLKey )), ".554889e5415741564154534189f64989ff498b870801000049398710010000744ebb010000004531e40f1f80000000004a8b3ce0e87788", nullptr, 0, 0, &func);
}

void CrewManifest::OnTextInput(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func393::func;
	return execfunc(this, key);
}

namespace _func394
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::OnTextEvent", typeid(void (CrewManifest::*)(CEvent::TextEvent )), ".554889e5415741564154534189f64989ff498b870801000049398710010000744ebb010000004531e40f1f80000000004a8b3ce0e8f787", nullptr, 0, 0, &func);
}

void CrewManifest::OnTextEvent(CEvent::TextEvent event)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func394::func;
	return execfunc(this, event);
}

namespace _func395
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::OnRender", typeid(void (CrewManifest::*)()), ".554889e54157415641554154534881ec980000004989ffe8", nullptr, 0, 0, &func);
}

void CrewManifest::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func395::func;
	return execfunc(this);
}

namespace _func396
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewManifest::MouseMove", typeid(void (CrewManifest::*)(int , int )), ".554889e5415741564155415453504189d64189f74989fd", nullptr, 0, 0, &func);
}

void CrewManifest::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CrewManifest *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func396::func;
	return execfunc(this, mX, mY);
}

namespace _func397
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::InsideRoom", typeid(bool (CrewMember::*)(int )), "554889e539b79c", nullptr, 0, 0, &func);
}

bool CrewMember::InsideRoom(int roomId)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func397::func;
	return execfunc(this, roomId);
}

namespace _func398
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetUniqueRepairing", typeid(std::string (CrewMember::*)()), ".554889e548c747100000000048c7470800000000c6070c66c7470569", nullptr, 0, 0, &func);
}

std::string CrewMember::GetUniqueRepairing()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func398::func;
	return execfunc(this);
}

namespace _func399
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetRoomDamage", typeid(Damage (CrewMember::*)()), ".554889e5c647200048", nullptr, 0, 0, &func);
}

Damage CrewMember::GetRoomDamage()
{
	typedef Damage (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func399::func;
	return execfunc(this);
}

namespace _func400
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(void (CrewMember::*)(CrewBlueprint &, int , bool , CrewAnimation *)), ".554889e54157415641554154534881ec280100004d89c6", nullptr, 0, 0, &func);
}

void CrewMember::constructor(CrewBlueprint &_blueprint, int _shipId, bool _intruder, CrewAnimation *_animation)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewBlueprint &_blueprint_arg, int _shipId_arg, bool _intruder_arg, CrewAnimation *_animation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func400::func;
	return execfunc(this, _blueprint, _shipId, _intruder, _animation);
}

namespace _func401
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(void (CrewMember::*)(TextString *, bool )), ".554889e541574156534883ec584189d7", nullptr, 0, 0, &func);
}

void CrewMember::SetName(TextString *name, bool force)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, TextString *name_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func401::func;
	return execfunc(this, name, force);
}

namespace _func402
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(void (CrewMember::*)(bool )), ".554889e54156534189f64889fb488bbbc0", nullptr, 0, 0, &func);
}

void CrewMember::SetSex(bool male)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func402::func;
	return execfunc(this, male);
}

namespace _func403
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(void (CrewMember::*)()), ".554889e58b879c", nullptr, 0, 0, &func);
}

void CrewMember::ClearTask()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func403::func;
	return execfunc(this);
}

namespace _func404
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::OnInit", typeid(bool (CrewMember::*)()), ".554889e5c747241e", nullptr, 0, 0, &func);
}

bool CrewMember::OnInit()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func404::func;
	return execfunc(this);
}

namespace _func405
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), "!.554889e541565389f34989fef3", nullptr, 0, 0, &func);
}

void CrewMember::SaveState(int fileHelper)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func405::func;
	return execfunc(this, fileHelper);
}

namespace _func406
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), ".554889e541574156535089f34989fe89dfe8????0f", nullptr, 0, 0, &func);
}

void CrewMember::LoadState(int fileHelper)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func406::func;
	return execfunc(this, fileHelper);
}

namespace _func407
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CycleColorLayer", typeid(void (CrewMember::*)(int )), ".554889e54157415641554154534883ec484189f64989fc0f", nullptr, 0, 0, &func);
}

void CrewMember::CycleColorLayer(int dir)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func407::func;
	return execfunc(this, dir);
}

namespace _func408
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CanTeleport", typeid(bool (CrewMember::*)()), ".554889e553504889fb488b83c0", nullptr, 0, 0, &func);
}

bool CrewMember::CanTeleport()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func408::func;
	return execfunc(this);
}

namespace _func409
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), ".554889e5f30f10470cf30f2a8fb4000000f30f5cc10f5405????26", nullptr, 0, 0, &func);
}

bool CrewMember::AtFinalGoal()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func409::func;
	return execfunc(this);
}

namespace _func410
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetSkillTooltip", typeid(std::string (*)(int , int , std::pair<int, int> , bool )), ".554889e54157415641554154534881ec6801000045", nullptr, 0, 0, &func);
}

std::string CrewMember::GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen)
{
	typedef std::string (*custom_arg_funcptr_t)(int skillId_arg, int skillLevel_arg, std::pair<int, int> progress_arg, bool infoScreen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func410::func;
	return execfunc(skillId, skillLevel, progress, infoScreen);
}

namespace _func411
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(void (CrewMember::*)(ShipSystem *)), ".554889e54157415653504889f34989ff41c6", nullptr, 0, 0, &func);
}

void CrewMember::SetCurrentSystem(ShipSystem *sys)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, ShipSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func411::func;
	return execfunc(this, sys);
}

namespace _func412
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::IsBusy", typeid(bool (CrewMember::*)()), ".554889e5b00148", nullptr, 0, 0, &func);
}

bool CrewMember::IsBusy()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func412::func;
	return execfunc(this);
}

namespace _func413
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), ".554889e5b80100000083", nullptr, 0, 0, &func);
}

int CrewMember::GetSkillLevel(int skillId)
{
	typedef int (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func413::func;
	return execfunc(this, skillId);
}

namespace _func414
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetSkillFromSystem", typeid(int (*)(int )), ".554889e583ff06", nullptr, 0, 0, &func);
}

int CrewMember::GetSkillFromSystem(int systemId)
{
	typedef int (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func414::func;
	return execfunc(systemId);
}

namespace _func415
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::IsManningArtillery", typeid(bool (CrewMember::*)()), ".554889e583bfa000", nullptr, 0, 0, &func);
}

bool CrewMember::IsManningArtillery()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func415::func;
	return execfunc(this);
}

namespace _func416
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(void (CrewMember::*)()), ".554889e54156534989fe498bbe", nullptr, 0, 0, &func);
}

void CrewMember::CheckSkills()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func416::func;
	return execfunc(this);
}

namespace _func417
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), ".554889e54883bf88000000000f", nullptr, 0, 0, &func);
}

bool CrewMember::Repairing()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func417::func;
	return execfunc(this);
}

namespace _func418
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::IncreaseSkill", typeid(void (CrewMember::*)(int )), ".554889e5415741564154534883ec204189f64889fb", nullptr, 0, 0, &func);
}

void CrewMember::IncreaseSkill(int skillId)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func418::func;
	return execfunc(this, skillId);
}

namespace _func419
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::MasterSkill", typeid(void (CrewMember::*)(int )), ".554889e54863c6488b8fb80300008b", nullptr, 0, 0, &func);
}

void CrewMember::MasterSkill(int skillId)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func419::func;
	return execfunc(this, skillId);
}

namespace _func420
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(void (CrewMember::*)(bool )), ".554889e54088b77c", nullptr, 0, 0, &func);
}

void CrewMember::SetResisted(bool resisted)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool resisted_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func420::func;
	return execfunc(this, resisted);
}

namespace _func421
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(bool (CrewMember::*)()), ".554889e58a877c", nullptr, 0, 0, &func);
}

bool CrewMember::GetResisted()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func421::func;
	return execfunc(this);
}

namespace _func422
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(void (CrewMember::*)(int , int )), ".554889e54863c6488b8fb803000089", nullptr, 0, 0, &func);
}

void CrewMember::SetSkillProgress(int skillId, int skillLevel)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg, int skillLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func422::func;
	return execfunc(this, skillId, skillLevel);
}

namespace _func423
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(std::pair<int, int> (CrewMember::*)(int )), ".554889e54863ce48", nullptr, 0, 0, &func);
}

std::pair<int, int> CrewMember::GetSkillProgress(int skillId)
{
	typedef std::pair<int, int> (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func423::func;
	return execfunc(this, skillId);
}

namespace _func424
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetSkillModifier", typeid(float (CrewMember::*)(int )), "!.554889e5b80100000083", nullptr, 0, 0, &func);
}

float CrewMember::GetSkillModifier(int skillId)
{
	typedef float (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func424::func;
	return execfunc(this, skillId);
}

namespace _func425
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::BadAtCombat", typeid(bool (CrewMember::*)()), ".554889e553504889fb488b03ff9050", nullptr, 0, 0, &func);
}

bool CrewMember::BadAtCombat()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func425::func;
	return execfunc(this);
}

namespace _func426
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::destructor", typeid(void (CrewMember::*)()), ".554889e54157415641554154534883ec184989ff488d05", nullptr, 0, 0, &func);
}

void CrewMember::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func426::func;
	return execfunc(this);
}

namespace _func427
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Cleanup", typeid(void (CrewMember::*)()), "!.554889e553504889fbe812fd", nullptr, 0, 0, &func);
}

void CrewMember::Cleanup()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func427::func;
	return execfunc(this);
}

namespace _func428
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), ".8b97ac00000085d27878", nullptr, 0, 0, &func);
}

void CrewMember::EmptySlot()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func428::func;
	return execfunc(this);
}

namespace _func429
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::NeedsSlot", typeid(bool (CrewMember::*)()), "!.554889e580bf600200000075", nullptr, 0, 0, &func);
}

bool CrewMember::NeedsSlot()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func429::func;
	return execfunc(this);
}

namespace _func430
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::UpdateRepair", typeid(void (CrewMember::*)()), ".554889e54156534883ec304889fb488bbb88", nullptr, 0, 0, &func);
}

void CrewMember::UpdateRepair()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func430::func;
	return execfunc(this);
}

namespace _func431
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), ".554889e553504889fb488bbb8800", nullptr, 0, 0, &func);
}

bool CrewMember::Sabotaging()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func431::func;
	return execfunc(this);
}

namespace _func432
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(Pointf (CrewMember::*)()), ".554889e5534883ec184889fb488bbb88", nullptr, 0, 0, &func);
}

Pointf CrewMember::SelectSabotageTarget()
{
	typedef Pointf (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func432::func;
	return execfunc(this);
}

namespace _func433
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::RepairingFire", typeid(bool (CrewMember::*)()), ".554889e54883bf880000000074", nullptr, 0, 0, &func);
}

bool CrewMember::RepairingFire()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func433::func;
	return execfunc(this);
}

namespace _func434
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::StopRepairing", typeid(void (CrewMember::*)()), ".554889e553504889fb4883bb8800000000742548", nullptr, 0, 0, &func);
}

void CrewMember::StopRepairing()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func434::func;
	return execfunc(this);
}

namespace _func435
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)()), "!.554889e5488b870806", nullptr, 0, 0, &func);
}

void CrewMember::Jump()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func435::func;
	return execfunc(this);
}

namespace _func436
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(void (CrewMember::*)(float )), "!.554889e55350f30f1145f44889fb48", nullptr, 0, 0, &func);
}

void CrewMember::ModifyHealth(float health)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func436::func;
	return execfunc(this, health);
}

namespace _func437
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(bool (CrewMember::*)(float )), ".554889e541574156534883ec384889fbf3", nullptr, 0, 0, &func);
}

bool CrewMember::DirectModifyHealth(float health)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func437::func;
	return execfunc(this, health);
}

namespace _func438
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::RepairingSystem", typeid(bool (CrewMember::*)()), ".554889e553504889fb4883bb8800000000742583", nullptr, 0, 0, &func);
}

bool CrewMember::RepairingSystem()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func438::func;
	return execfunc(this);
}

namespace _func439
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(void (CrewMember::*)(Repairable *)), ".554889e54156534883ec104989f64889fbf30f10", nullptr, 0, 0, &func);
}

void CrewMember::StartRepair(Repairable *toRepair)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, Repairable *toRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func439::func;
	return execfunc(this, toRepair);
}

namespace _func440
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), ".554889e5488b87ac000000488b8f", nullptr, 0, 0, &func);
}

void CrewMember::SavePosition()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func440::func;
	return execfunc(this);
}

namespace _func441
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), ".554889e548c78780", nullptr, 0, 0, &func);
}

void CrewMember::ClearPosition()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func441::func;
	return execfunc(this);
}

namespace _func442
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(Slot (CrewMember::*)()), ".554889e5488b878008", nullptr, 0, 0, &func);
}

Slot CrewMember::GetSavedPosition()
{
	typedef Slot (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func442::func;
	return execfunc(this);
}

namespace _func443
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::RestorePosition", typeid(bool (CrewMember::*)()), "!.554889e58bb7", nullptr, 0, 0, &func);
}

bool CrewMember::RestorePosition()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func443::func;
	return execfunc(this);
}

namespace _func444
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), "!.554889e54157415641554154534883ec484189cd", nullptr, 0, 0, &func);
}

bool CrewMember::MoveToRoom(int roomId, int slotId, bool forceMove)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool forceMove_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func444::func;
	return execfunc(this, roomId, slotId, forceMove);
}

namespace _func445
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(Slot )), ".554889e54889b78008", nullptr, 0, 0, &func);
}

void CrewMember::SetSavePosition(Slot position)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, Slot position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func445::func;
	return execfunc(this, position);
}

namespace _func446
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetFrozen", typeid(void (CrewMember::*)(bool )), ".554889e58a87f401", nullptr, 0, 0, &func);
}

void CrewMember::SetFrozen(bool frozen)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func446::func;
	return execfunc(this, frozen);
}

namespace _func447
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(void (CrewMember::*)(bool )), ".554889e54088b7f5", nullptr, 0, 0, &func);
}

void CrewMember::SetFrozenLocation(bool frozenLocation)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozenLocation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func447::func;
	return execfunc(this, frozenLocation);
}

namespace _func448
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(CrewTask )), ".554889e54889b7f8", nullptr, 0, 0, &func);
}

void CrewMember::SetTask(CrewTask task)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTask task_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func448::func;
	return execfunc(this, task);
}

namespace _func449
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::FindSlot", typeid(Slot (CrewMember::*)(int , int , bool )), ".554889e5415741564154534883ec204189cc", nullptr, 0, 0, &func);
}

Slot CrewMember::FindSlot(int roomId, int slotId, bool closeEnough)
{
	typedef Slot (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool closeEnough_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func449::func;
	return execfunc(this, roomId, slotId, closeEnough);
}

namespace _func450
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CheckRoomPath", typeid(bool (CrewMember::*)(int )), ".554889e5415741564154534883ec3041", nullptr, 0, 0, &func);
}

bool CrewMember::CheckRoomPath(int roomId)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func450::func;
	return execfunc(this, roomId);
}

namespace _func451
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(void (CrewMember::*)(CrewTarget *, bool )), ".554889e54157415653504189d74989f64889fb488b", nullptr, 0, 0, &func);
}

void CrewMember::SetCurrentTarget(CrewTarget *target, bool force)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTarget *target_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func451::func;
	return execfunc(this, target, force);
}

namespace _func452
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetRoomPath", typeid(void (CrewMember::*)(int , int )), ".554889e541574156534883ec384189d6", nullptr, 0, 0, &func);
}

void CrewMember::SetRoomPath(int slotId, int roomId)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func452::func;
	return execfunc(this, slotId, roomId);
}

namespace _func453
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetIntruder", typeid(bool (CrewMember::*)()), ".554889e58b87ac0100003b", nullptr, 0, 0, &func);
}

bool CrewMember::GetIntruder()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func453::func;
	return execfunc(this);
}

namespace _func454
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetPosition", typeid(void (CrewMember::*)(Point )), ".554889e54156534883ec104889fb4889f248c1ea20f3", nullptr, 0, 0, &func);
}

void CrewMember::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func454::func;
	return execfunc(this, position);
}

namespace _func455
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetPath", typeid(bool (CrewMember::*)(Path *)), ".554889e5415741564154534883ec104889f3", nullptr, 0, 0, &func);
}

bool CrewMember::SetPath(Path *path)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, Path *path_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func455::func;
	return execfunc(this, path);
}

namespace _func456
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetRoom", typeid(void (CrewMember::*)(int )), ".554889e54157415641554154534883ec384189f648", nullptr, 0, 0, &func);
}

void CrewMember::SetRoom(int roomId)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func456::func;
	return execfunc(this, roomId);
}

namespace _func457
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ClearPath", typeid(void (CrewMember::*)()), ".554889e541574156534883ec384889fb8b", nullptr, 0, 0, &func);
}

void CrewMember::ClearPath()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func457::func;
	return execfunc(this);
}

namespace _func458
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetFinalGoal", typeid(Point (CrewMember::*)()), ".554889e54883ec10f30f10", nullptr, 0, 0, &func);
}

Point CrewMember::GetFinalGoal()
{
	typedef Point (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func458::func;
	return execfunc(this);
}

namespace _func459
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetNextGoal", typeid(Point (CrewMember::*)()), ".554889e5534883ec18f30f10471c", nullptr, 0, 0, &func);
}

Point CrewMember::GetNextGoal()
{
	typedef Point (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func459::func;
	return execfunc(this);
}

namespace _func460
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CloseDoorBehind", typeid(void (CrewMember::*)(Door *)), ".554889e54889b78000", nullptr, 0, 0, &func);
}

void CrewMember::CloseDoorBehind(Door *door)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, Door *door_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func460::func;
	return execfunc(this, door);
}

namespace _func461
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(float (CrewMember::*)()), ".554889e541574156534881ec880000004889fb0f", nullptr, 0, 0, &func);
}

float CrewMember::GetMoveSpeed()
{
	typedef float (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func461::func;
	return execfunc(this);
}

namespace _func462
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(bool (CrewMember::*)()), ".554889e54157415641554154534883ec184889fb488bbb", nullptr, 0, 0, &func);
}

bool CrewMember::GetNewGoal()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func462::func;
	return execfunc(this);
}

namespace _func463
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::AtGoal", typeid(bool (CrewMember::*)()), ".554889e5f30f104f0cf30f10", nullptr, 0, 0, &func);
}

bool CrewMember::AtGoal()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func463::func;
	return execfunc(this);
}

namespace _func464
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::UpdateMovement", typeid(void (CrewMember::*)()), ".554889e54156534883ec304889fb488b83", nullptr, 0, 0, &func);
}

void CrewMember::UpdateMovement()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func464::func;
	return execfunc(this);
}

namespace _func465
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Restart", typeid(void (CrewMember::*)()), ".554889e5415741564154534883ec104989fe498b06", nullptr, 0, 0, &func);
}

void CrewMember::Restart()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func465::func;
	return execfunc(this);
}

namespace _func466
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), ".554889e5f30f118774", nullptr, 0, 0, &func);
}

void CrewMember::SetDamageBoost(float damageBoost)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, float damageBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func466::func;
	return execfunc(this, damageBoost);
}

namespace _func467
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetHealthBoost", typeid(void (CrewMember::*)(int )), ".554889e553504889fb8b8370", nullptr, 0, 0, &func);
}

void CrewMember::SetHealthBoost(int healthBoost)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int healthBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func467::func;
	return execfunc(this, healthBoost);
}

namespace _func468
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), "!.554889e553504889fb488b8b", nullptr, 0, 0, &func);
}

void CrewMember::InitializeSkills()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func468::func;
	return execfunc(this);
}

namespace _func469
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetCloneReady", typeid(void (CrewMember::*)(bool )), ".554889e54156534883ec204889fb40", nullptr, 0, 0, &func);
}

void CrewMember::SetCloneReady(bool cloneReady)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool cloneReady_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func469::func;
	return execfunc(this, cloneReady);
}

namespace _func470
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Kill", typeid(void (CrewMember::*)(bool )), ".554889e541574156534883ec284189f64889fbc7", nullptr, 0, 0, &func);
}

void CrewMember::Kill(bool noClone)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool noClone_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func470::func;
	return execfunc(this, noClone);
}

namespace _func471
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), ".554889e580bff4", nullptr, 0, 0, &func);
}

bool CrewMember::NeedFrozenLocation()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func471::func;
	return execfunc(this);
}

namespace _func472
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), ".554889e541574156534883ec184989ff498b9f", nullptr, 0, 0, &func);
}

void CrewMember::CheckForTeleport()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func472::func;
	return execfunc(this);
}

namespace _func473
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), ".554889e54157415641554154534881ec280100004989fc", nullptr, 0, 0, &func);
}

void CrewMember::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func473::func;
	return execfunc(this);
}

namespace _func474
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), ".554889e54156534883ec604889fb83", nullptr, 0, 0, &func);
}

void CrewMember::UpdateHealth()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func474::func;
	return execfunc(this);
}

namespace _func475
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetLongName", typeid(std::string (CrewMember::*)()), ".554889e553504889fb80be90", nullptr, 0, 0, &func);
}

std::string CrewMember::GetLongName()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func475::func;
	return execfunc(this);
}

namespace _func476
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(void (CrewMember::*)(int )), ".554889e589b7ac010000", nullptr, 0, 0, &func);
}

void CrewMember::SetCurrentShip(int shipId)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func476::func;
	return execfunc(this, shipId);
}

namespace _func477
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), ".554889e54883bfd8", nullptr, 0, 0, &func);
}

void CrewMember::CheckFighting()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func477::func;
	return execfunc(this);
}

namespace _func478
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ApplyDamage", typeid(bool (CrewMember::*)(float )), ".554889e553504889fbf30f104b", nullptr, 0, 0, &func);
}

bool CrewMember::ApplyDamage(float damage)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, float damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func478::func;
	return execfunc(this, damage);
}

namespace _func479
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetOutOfGame", typeid(void (CrewMember::*)()), ".554889e5c68740", nullptr, 0, 0, &func);
}

void CrewMember::SetOutOfGame()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func479::func;
	return execfunc(this);
}

namespace _func480
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetDeathNumber", typeid(void (CrewMember::*)(int )), ".554889e589b774", nullptr, 0, 0, &func);
}

void CrewMember::SetDeathNumber(int deathNum)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, int deathNum_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func480::func;
	return execfunc(this, deathNum);
}

namespace _func481
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetMindControl", typeid(void (CrewMember::*)(bool )), ".554889e541574156534883ec184189f64889fb0f", nullptr, 0, 0, &func);
}

void CrewMember::SetMindControl(bool controlled)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool controlled_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func481::func;
	return execfunc(this, controlled);
}

namespace _func482
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(void (CrewMember::*)(bool )), ".554889e54088b771", nullptr, 0, 0, &func);
}

void CrewMember::ForceMindControl(bool force)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func482::func;
	return execfunc(this, force);
}

namespace _func483
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::RenderSkillUpAnimation", typeid(void (CrewMember::*)(Point )), ".554889e54157415641554154534883ec484989ff49", nullptr, 0, 0, &func);
}

void CrewMember::RenderSkillUpAnimation(Point position)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func483::func;
	return execfunc(this, position);
}

namespace _func484
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Clone", typeid(void (CrewMember::*)()), ".554889e541574156534883ec184989fe41", nullptr, 0, 0, &func);
}

void CrewMember::Clone()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func484::func;
	return execfunc(this);
}

namespace _func485
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(void (CrewMember::*)()), "!.554889e54156534c8bb7", nullptr, 0, 0, &func);
}

void CrewMember::StartTeleportArrive()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func485::func;
	return execfunc(this);
}

namespace _func486
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), ".554889e5534883ec184889fb837b", nullptr, 0, 0, &func);
}

void CrewMember::OnRenderPath()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func486::func;
	return execfunc(this);
}

namespace _func487
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetLocation", typeid(Point (CrewMember::*)()), ".554889e5534883ec18f30f10470c", nullptr, 0, 0, &func);
}

Point CrewMember::GetLocation()
{
	typedef Point (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func487::func;
	return execfunc(this);
}

namespace _func488
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::PositionShift", typeid(float (CrewMember::*)()), ".554889e5f30f104f0cf30f2a87", nullptr, 0, 0, &func);
}

float CrewMember::PositionShift()
{
	typedef float (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func488::func;
	return execfunc(this);
}

namespace _func489
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), ".554889e54156534883ec104189f64889fb80", nullptr, 0, 0, &func);
}

void CrewMember::OnRender(bool outlineOnly)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func489::func;
	return execfunc(this, outlineOnly);
}

namespace _func490
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::OnRenderHealth", typeid(void (CrewMember::*)()), ".554889e54157415641554154534881ec980000004989fc", nullptr, 0, 0, &func);
}

void CrewMember::OnRenderHealth()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func490::func;
	return execfunc(this);
}

namespace _func491
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), ".554889e531c080bf60", nullptr, 0, 0, &func);
}

int CrewMember::GetIntegerHealth()
{
	typedef int (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func491::func;
	return execfunc(this);
}

namespace _func492
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetTooltip", typeid(std::string (CrewMember::*)()), ".554889e54157415641554154534883ec484989f7", nullptr, 0, 0, &func);
}

std::string CrewMember::GetTooltip()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func492::func;
	return execfunc(this);
}

namespace _func493
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetRepairingId", typeid(int (CrewMember::*)()), ".554889e5488bbf88", nullptr, 0, 0, &func);
}

int CrewMember::GetRepairingId()
{
	typedef int (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func493::func;
	return execfunc(this);
}

namespace _func494
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::WithinRect", typeid(bool (CrewMember::*)(int , int , int , int )), ".554889e54589", nullptr, 0, 0, &func);
}

bool CrewMember::WithinRect(int x, int y, int w, int h)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func494::func;
	return execfunc(this, x, y, w, h);
}

namespace _func495
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetName", typeid(std::string (CrewMember::*)()), ".554889e553504889fb80be70", nullptr, 0, 0, &func);
}

std::string CrewMember::GetName()
{
	typedef std::string (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func495::func;
	return execfunc(this);
}

namespace _func496
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CanHeal", typeid(bool (CrewMember::*)()), ".554889e54156534889fbf30f1043", nullptr, 0, 0, &func);
}

bool CrewMember::CanHeal()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func496::func;
	return execfunc(this);
}

namespace _func497
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int )), ".554889e5f30f10470cf30f10", nullptr, 0, 0, &func);
}

bool CrewMember::ContainsPoint(int x, int y)
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func497::func;
	return execfunc(this, x, y);
}

namespace _func498
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), ".554889e5534883ec180f29", nullptr, 0, 0, &func);
}

void CrewMember::SetMedbay(float health)
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func498::func;
	return execfunc(this, health);
}

namespace _func499
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(void (CrewMember::*)()), "!.554889e55350488b9fc0", nullptr, 0, 0, &func);
}

void CrewMember::StartTeleport()
{
	typedef void (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func499::func;
	return execfunc(this);
}

namespace _func500
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::Functional", typeid(bool (CrewMember::*)()), ".554889e5488b07ff9010", nullptr, 0, 0, &func);
}

bool CrewMember::Functional()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func500::func;
	return execfunc(this);
}

namespace _func501
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CountForVictory", typeid(bool (CrewMember::*)()), ".554889e553504889fb488b03ff9010", nullptr, 0, 0, &func);
}

bool CrewMember::CountForVictory()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func501::func;
	return execfunc(this);
}

namespace _func502
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::GetControllable", typeid(bool (CrewMember::*)()), ".554889e553504889fb837b08", nullptr, 0, 0, &func);
}

bool CrewMember::GetControllable()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func502::func;
	return execfunc(this);
}

namespace _func503
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CanRepair", typeid(bool (CrewMember::*)()), ".554889e553504889fb80bbbc", nullptr, 0, 0, &func);
}

bool CrewMember::CanRepair()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func503::func;
	return execfunc(this);
}

namespace _func504
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CanSabotage", typeid(bool (CrewMember::*)()), ".554889e58a87bc", nullptr, 0, 0, &func);
}

bool CrewMember::CanSabotage()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func504::func;
	return execfunc(this);
}

namespace _func505
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMember::CanMan", typeid(bool (CrewMember::*)()), ".554889e580bfbc00", nullptr, 0, 0, &func);
}

bool CrewMember::CanMan()
{
	typedef bool (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func505::func;
	return execfunc(this);
}

namespace _func506
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::destructor", typeid(void (CrewMemberFactory::*)()), "!.554889e54156534989fe498b7e10498b4e184839f975054889ca99999999", nullptr, 0, 0, &func);
}

void CrewMemberFactory::destructor()
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func506::func;
	return execfunc(this);
}

namespace _func507
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::Restart", typeid(void (CrewMemberFactory::*)()), ".554889e54157415653504989fe498b4610498b56", nullptr, 0, 0, &func);
}

void CrewMemberFactory::Restart()
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func507::func;
	return execfunc(this);
}

namespace _func508
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::RemoveExcessCrew", typeid(void (CrewMemberFactory::*)()), "!.554889e5415741564154534989ff498b47104939", nullptr, 0, 0, &func);
}

void CrewMemberFactory::RemoveExcessCrew()
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func508::func;
	return execfunc(this);
}

namespace _func509
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::OnLoop", typeid(void (CrewMemberFactory::*)()), ".554889e54157415641554154534881ec880000004889fb48c7030000", nullptr, 0, 0, &func);
}

void CrewMemberFactory::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func509::func;
	return execfunc(this);
}

namespace _func510
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetRandomFriendlyName", typeid(std::pair<std::string, bool> (CrewMemberFactory::*)(const std::string &)), ".554889e54157415641554154534881ec980000004989d548", nullptr, 0, 0, &func);
}

std::pair<std::string, bool> CrewMemberFactory::GetRandomFriendlyName(const std::string &race)
{
	typedef std::pair<std::string, bool> (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, const std::string &race_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func510::func;
	return execfunc(this, race);
}

namespace _func511
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewNames", typeid(std::vector<std::string> (CrewMemberFactory::*)()), ".554889e54157415641554154534883ec184989f44989fe49c7461000", nullptr, 0, 0, &func);
}

std::vector<std::string> CrewMemberFactory::GetCrewNames()
{
	typedef std::vector<std::string> (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func511::func;
	return execfunc(this);
}

namespace _func512
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetCloneReadyList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, bool )), "!.554889e54157415641554154534883ec284189d74989f649", nullptr, 0, 0, &func);
}

void CrewMemberFactory::GetCloneReadyList(std::vector<CrewMember*> &vec, bool player)
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> &vec_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func512::func;
	return execfunc(this, vec, player);
}

namespace _func513
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::CountCloneReadyCrew", typeid(int (CrewMemberFactory::*)(bool )), ".554889e5415741564155415453504189f64989fc498b4424104531ff", nullptr, 0, 0, &func);
}

int CrewMemberFactory::CountCloneReadyCrew(bool player)
{
	typedef int (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func513::func;
	return execfunc(this, player);
}

namespace _func514
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewPortraitList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int )), "!.554889e54157415641554154534883ec2889d348", nullptr, 0, 0, &func);
}

void CrewMemberFactory::GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId)
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int teamId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func514::func;
	return execfunc(this, vec, teamId);
}

namespace _func515
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int , bool )), "!.554889e54157415641554154534883ec288955d44989f548", nullptr, 0, 0, &func);
}

void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> *vec, int player, bool drones)
{
	typedef void (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int player_arg, bool drones_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func515::func;
	return execfunc(this, vec, player, drones);
}

namespace _func516
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetPlayerCrewCount", typeid(int (CrewMemberFactory::*)()), ".554889e58b075d", nullptr, 0, 0, &func);
}

int CrewMemberFactory::GetPlayerCrewCount()
{
	typedef int (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func516::func;
	return execfunc(this);
}

namespace _func517
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCloneCount", typeid(int (CrewMemberFactory::*)()), ".554889e58b47085dc3", nullptr, 0, 0, &func);
}

int CrewMemberFactory::GetEnemyCloneCount()
{
	typedef int (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func517::func;
	return execfunc(this);
}

namespace _func518
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewCount", typeid(int (CrewMemberFactory::*)(bool )), ".554889e5488d4704", nullptr, 0, 0, &func);
}

int CrewMemberFactory::GetCrewCount(bool enemy)
{
	typedef int (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func518::func;
	return execfunc(this, enemy);
}

namespace _func519
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCrewCount", typeid(int (CrewMemberFactory::*)()), ".554889e58b47045d", nullptr, 0, 0, &func);
}

int CrewMemberFactory::GetEnemyCrewCount()
{
	typedef int (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func519::func;
	return execfunc(this);
}

namespace _func520
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(const std::string &)), ".554889e54156534889fb488d35????26", nullptr, 0, 0, &func);
}

bool CrewMemberFactory::IsRace(const std::string &species)
{
	typedef bool (*custom_arg_funcptr_t)(const std::string &species_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func520::func;
	return execfunc(species);
}

namespace _func521
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::CreateCrewMember", typeid(CrewMember *(CrewMemberFactory::*)(CrewBlueprint *, int , bool )), "!.554889e54157415641554154534881ecb80100004189cd41", nullptr, 0, 0, &func);
}

CrewMember *CrewMemberFactory::CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, CrewBlueprint *bp_arg, int shipId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func521::func;
	return execfunc(this, bp, shipId, intruder);
}

namespace _func522
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBoarderDrone", typeid(BoarderDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), "!.554889e54157415641554154534883ec184989d64189f749", nullptr, 0, 0, &func);
}

BoarderDrone *CrewMemberFactory::CreateBoarderDrone(int shipId, const DroneBlueprint *bp)
{
	typedef BoarderDrone *(*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func522::func;
	return execfunc(this, shipId, bp);
}

namespace _func523
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::CreateRepairDrone", typeid(RepairDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), "!.554889e54157415641554154534883ec384989d74189f549", nullptr, 0, 0, &func);
}

RepairDrone *CrewMemberFactory::CreateRepairDrone(int shipId, const DroneBlueprint *bp)
{
	typedef RepairDrone *(*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func523::func;
	return execfunc(this, shipId, bp);
}

namespace _func524
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBattleDrone", typeid(BattleDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), "!.554889e54157415641554154534883ec184989d74189f649", nullptr, 0, 0, &func);
}

BattleDrone *CrewMemberFactory::CreateBattleDrone(int shipId, const DroneBlueprint *bp)
{
	typedef BattleDrone *(*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func524::func;
	return execfunc(this, shipId, bp);
}

CrewMemberFactory *Global_CrewMemberFactory_Factory;

namespace _var525
{
	static VariableDefinition varObj("Global_CrewMemberFactory_Factory", "!807b2800400f94c6488d3d(???????\?)e8????????4189c6807b2800", &Global_CrewMemberFactory_Factory, true, true);
}

namespace _func526
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewStoreBox::constructor", typeid(void (CrewStoreBox::*)(ShipManager *, int , const std::string &)), ".554889e54157415641554154534881ec????????4989cc4189d6", nullptr, 0, 0, &func);
}

void CrewStoreBox::constructor(ShipManager *_ship, int _worldLevel, const std::string &_type)
{
	typedef void (*custom_arg_funcptr_t)(CrewStoreBox *this_arg, ShipManager *_ship_arg, int _worldLevel_arg, const std::string &_type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func526::func;
	return execfunc(this, _ship, _worldLevel, _type);
}

namespace _func527
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewStoreBox::CanHold", typeid(bool (CrewStoreBox::*)()), ".488bbf78", nullptr, 0, 0, &func);
}

bool CrewStoreBox::CanHold()
{
	typedef bool (*custom_arg_funcptr_t)(CrewStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func527::func;
	return execfunc(this);
}

namespace _func528
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewStoreBox::MouseMove", typeid(void (CrewStoreBox::*)(int , int )), ".554889e5534883ec384889fb488d7b2831c9e8????f8ff80", nullptr, 0, 0, &func);
}

void CrewStoreBox::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(CrewStoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func528::func;
	return execfunc(this, mX, mY);
}

namespace _func529
{
	static void *func = 0;
	static FunctionDefinition funcObj("CrewStoreBox::Purchase", typeid(void (CrewStoreBox::*)()), ".554889e541574156534881ec88010000", nullptr, 0, 0, &func);
}

void CrewStoreBox::Purchase()
{
	typedef void (*custom_arg_funcptr_t)(CrewStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func529::func;
	return execfunc(this);
}

namespace _func530
{
	static void *func = 0;
	static FunctionDefinition funcObj("DamageMessage::constructor2", typeid(void (DamageMessage::*)(float , int , Pointf , bool )), "!554889e54157415641554154534881ec????????4189f54989fc", nullptr, 0, 0, &func);
}

void DamageMessage::constructor2(float _length, int _amount, Pointf _position, bool _symbol)
{
	typedef void (*custom_arg_funcptr_t)(DamageMessage *this_arg, float _length_arg, int _amount_arg, Pointf _position_arg, bool _symbol_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func530::func;
	return execfunc(this, _length, _amount, _position, _symbol);
}

namespace _func531
{
	static void *func = 0;
	static FunctionDefinition funcObj("DamageMessage::constructor", typeid(void (DamageMessage::*)(float , Pointf , DamageMessage::MessageType )), "!.554889e54157415641554154534883ec284889fb488d05", nullptr, 0, 0, &func);
}

void DamageMessage::constructor(float _length, Pointf _position, DamageMessage::MessageType _type)
{
	typedef void (*custom_arg_funcptr_t)(DamageMessage *this_arg, float _length_arg, Pointf _position_arg, DamageMessage::MessageType _type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func531::func;
	return execfunc(this, _length, _position, _type);
}

namespace _func532
{
	static void *func = 0;
	static FunctionDefinition funcObj("DefenseDrone::GetTooltip", typeid(std::string (DefenseDrone::*)()), "554889e54156534883ec404889f34989fe0f57c0", nullptr, 0, 0, &func);
}

std::string DefenseDrone::GetTooltip()
{
	typedef std::string (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func532::func;
	return execfunc(this);
}

namespace _func533
{
	static void *func = 0;
	static FunctionDefinition funcObj("DefenseDrone::PickTarget", typeid(void (DefenseDrone::*)()), "!.554889e5534883ec384889fb80bbbd02", nullptr, 0, 0, &func);
}

void DefenseDrone::PickTarget()
{
	typedef void (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func533::func;
	return execfunc(this);
}

namespace _func534
{
	static void *func = 0;
	static FunctionDefinition funcObj("DefenseDrone::ValidTargetObject", typeid(bool (DefenseDrone::*)(Targetable *)), ".554889e54156534889f34989fe4885db0f848800", nullptr, 0, 0, &func);
}

bool DefenseDrone::ValidTargetObject(Targetable *target)
{
	typedef bool (*custom_arg_funcptr_t)(DefenseDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func534::func;
	return execfunc(this, target);
}

namespace _func535
{
	static void *func = 0;
	static FunctionDefinition funcObj("DefenseDrone::SetWeaponTarget", typeid(void (DefenseDrone::*)(Targetable *)), ".554889e54157415653504989f64889fb488b03ff", nullptr, 0, 0, &func);
}

void DefenseDrone::SetWeaponTarget(Targetable *target)
{
	typedef void (*custom_arg_funcptr_t)(DefenseDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func535::func;
	return execfunc(this, target);
}

namespace _func536
{
	static void *func = 0;
	static FunctionDefinition funcObj("DefenseDrone::OnLoop", typeid(void (DefenseDrone::*)()), "!.554889e541574156534883ec284989ffe8", nullptr, 0, 0, &func);
}

void DefenseDrone::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func536::func;
	return execfunc(this);
}

namespace _func537
{
	static void *func = 0;
	static FunctionDefinition funcObj("Door::FakeOpen", typeid(void (Door::*)()), "!.554889e5c6472c01", nullptr, 0, 0, &func);
}

void Door::FakeOpen()
{
	typedef void (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func537::func;
	return execfunc(this);
}

namespace _func538
{
	static void *func = 0;
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), "!.554889e5c6472c00", nullptr, 0, 0, &func);
}

void Door::FakeClose()
{
	typedef void (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func538::func;
	return execfunc(this);
}

namespace _func539
{
	static void *func = 0;
	static FunctionDefinition funcObj("Door::IsSealed", typeid(bool (Door::*)(int )), ".554889e58b4f0831", nullptr, 0, 0, &func);
}

bool Door::IsSealed(int shipId)
{
	typedef bool (*custom_arg_funcptr_t)(Door *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func539::func;
	return execfunc(this, shipId);
}

namespace _func540
{
	static void *func = 0;
	static FunctionDefinition funcObj("Door::OnLoop", typeid(void (Door::*)()), "!.554889e54156534889fb8b83", nullptr, 0, 0, &func);
}

void Door::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func540::func;
	return execfunc(this);
}

namespace _func541
{
	static void *func = 0;
	static FunctionDefinition funcObj("Door::ApplyDamage", typeid(bool (Door::*)(float )), ".554889e553504889fb80bb4c02000000", nullptr, 0, 0, &func);
}

bool Door::ApplyDamage(float amount)
{
	typedef bool (*custom_arg_funcptr_t)(Door *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func541::func;
	return execfunc(this, amount);
}

namespace _func542
{
	static void *func = 0;
	static FunctionDefinition funcObj("Door::GetPosition", typeid(Point (Door::*)()), ".554889e54883ec108bb7b00200008b97b4020000488d7df0", nullptr, 0, 0, &func);
}

Point Door::GetPosition()
{
	typedef Point (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func542::func;
	return execfunc(this);
}

namespace _func543
{
	static void *func = 0;
	static FunctionDefinition funcObj("DoorBox::constructor", typeid(void (DoorBox::*)(Point , ShipSystem *, ShipManager *)), ".554889e54157415641554154534883ec??4989cc4889fb", nullptr, 0, 0, &func);
}

void DoorBox::constructor(Point _position, ShipSystem *_system, ShipManager *_ship)
{
	typedef void (*custom_arg_funcptr_t)(DoorBox *this_arg, Point _position_arg, ShipSystem *_system_arg, ShipManager *_ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func543::func;
	return execfunc(this, _position, _system, _ship);
}

namespace _func544
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneBlueprint::RenderIcon", typeid(void (DroneBlueprint::*)(float )), ".554889e54157415641554154534881ec580100004889fbe8", nullptr, 0, 0, &func);
}

void DroneBlueprint::RenderIcon(float scale)
{
	typedef void (*custom_arg_funcptr_t)(DroneBlueprint *this_arg, float scale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func544::func;
	return execfunc(this, scale);
}

namespace _func545
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneControl::OnLoop", typeid(void (DroneControl::*)()), "554889e5415741564154534883ec204989ff498b", nullptr, 0, 0, &func);
}

void DroneControl::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func545::func;
	return execfunc(this);
}

namespace _func546
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneControl::HolderLabel", typeid(TextString (DroneControl::*)()), ".554889e5534883ec184889fb0f57c00f2945e048c745f000000000c645e01848", nullptr, 0, 0, &func);
}

TextString DroneControl::HolderLabel()
{
	typedef TextString (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func546::func;
	return execfunc(this);
}

namespace _func547
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneControl::ArmamentHotkey", typeid(SDLKey (DroneControl::*)(unsigned int )), ".554889e5534883ec38ffc68975f4488d5dc0488d75f44889dfe822", nullptr, 0, 0, &func);
}

SDLKey DroneControl::ArmamentHotkey(unsigned int i)
{
	typedef SDLKey (*custom_arg_funcptr_t)(DroneControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func547::func;
	return execfunc(this, i);
}

namespace _func548
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneStoreBox::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (DroneStoreBox::*)()), ".554889e5415741564154534883ec204989ce4989d74989f44889fbbf", nullptr, 0, 0, &func);
}

namespace _func549
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneStoreBox::constructor", typeid(void (DroneStoreBox::*)(ShipManager *, Equipment *, const DroneBlueprint *)), ".554889e5415741564154534883ec204989ce4989d74989f44889fbbf", nullptr, 0, 0, &func);
}

void DroneStoreBox::constructor(ShipManager *_ship, Equipment *_equipScreen, const DroneBlueprint *_blueprint)
{
	typedef void (*custom_arg_funcptr_t)(DroneStoreBox *this_arg, ShipManager *_ship_arg, Equipment *_equipScreen_arg, const DroneBlueprint *_blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func549::func;
	return execfunc(this, _ship, _equipScreen, _blueprint);
}

namespace _func550
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneSystem::StringToDrone", typeid(int (*)(std::string &)), ".554889e553504889fb488d35????0e00", nullptr, 0, 0, &func);
}

int DroneSystem::StringToDrone(std::string &name)
{
	typedef int (*custom_arg_funcptr_t)(std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func550::func;
	return execfunc(name);
}

namespace _func551
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneSystem::DePowerDrone", typeid(bool (DroneSystem::*)(Drone *, bool )), ".554889e541574156535089d34989f74989fe498b", nullptr, 0, 0, &func);
}

bool DroneSystem::DePowerDrone(Drone *drone, bool userDriven)
{
	typedef bool (*custom_arg_funcptr_t)(DroneSystem *this_arg, Drone *drone_arg, bool userDriven_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func551::func;
	return execfunc(this, drone, userDriven);
}

namespace _func552
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneSystem::RemoveDrone", typeid(void (DroneSystem::*)(int )), ".554889e5415741564154534889fb85f6", nullptr, 0, 0, &func);
}

void DroneSystem::RemoveDrone(int slot)
{
	typedef void (*custom_arg_funcptr_t)(DroneSystem *this_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func552::func;
	return execfunc(this, slot);
}

namespace _func553
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneSystem::OnLoop", typeid(void (DroneSystem::*)()), ".554889e54157415641554154534883ec284989fee807cf00", nullptr, 0, 0, &func);
}

void DroneSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func553::func;
	return execfunc(this);
}

namespace _func554
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneSystem::UpdateBonusPower", typeid(void (DroneSystem::*)()), ".554889e5415741564155415453504989fc498b84", nullptr, 0, 0, &func);
}

void DroneSystem::UpdateBonusPower()
{
	typedef void (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func554::func;
	return execfunc(this);
}

namespace _func555
{
	static void *func = 0;
	static FunctionDefinition funcObj("DroneSystem::SetBonusPower", typeid(void (DroneSystem::*)(int , int )), "!.554889e54156534189f64889fbe86eac", nullptr, 0, 0, &func);
}

void DroneSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void (*custom_arg_funcptr_t)(DroneSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func555::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func556
{
	static void *func = 0;
	static FunctionDefinition funcObj("DropBox::GetHeight", typeid(int (DropBox::*)()), "554889e5488b47104889c148", nullptr, 0, 0, &func);
}

int DropBox::GetHeight()
{
	typedef int (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func556::func;
	return execfunc(this);
}

namespace _func557
{
	static void *func = 0;
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), ".554889e54157415641554154534881ecc80000004989fde8", nullptr, 0, 0, &func);
}

void DropBox::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func557::func;
	return execfunc(this);
}

namespace _func558
{
	static void *func = 0;
	static FunctionDefinition funcObj("EnergyAlien::OnLoop", typeid(void (EnergyAlien::*)()), "554889e553504889fbe80274", nullptr, 0, 0, &func);
}

void EnergyAlien::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(EnergyAlien *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func558::func;
	return execfunc(this);
}

namespace _func559
{
	static void *func = 0;
	static FunctionDefinition funcObj("EnergyAlien::GetRoomDamage", typeid(Damage (EnergyAlien::*)()), ".554889e580bef108", nullptr, 0, 0, &func);
}

Damage EnergyAlien::GetRoomDamage()
{
	typedef Damage (*custom_arg_funcptr_t)(EnergyAlien *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func559::func;
	return execfunc(this);
}

namespace _func560
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::OnInit", typeid(void (Equipment::*)(ShipManager *)), "!.554889e54157415641554154534881ec280100004989f649", nullptr, 0, 0, &func);
}

void Equipment::OnInit(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func560::func;
	return execfunc(this, ship);
}

namespace _func561
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::OnLoop", typeid(void (Equipment::*)()), ".554889e5415741564154534989fc498b8424c802", nullptr, 0, 0, &func);
}

void Equipment::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func561::func;
	return execfunc(this);
}

namespace _func562
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::GetCargoHold", typeid(std::vector<std::string> (Equipment::*)()), ".554889e5415741564154534989f74989fe49c746", nullptr, 0, 0, &func);
}

std::vector<std::string> Equipment::GetCargoHold()
{
	typedef std::vector<std::string> (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func562::func;
	return execfunc(this);
}

namespace _func563
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::AddToCargo", typeid(void (Equipment::*)(std::string &)), ".554889e541574156534883ec484989f7", nullptr, 0, 0, &func);
}

void Equipment::AddToCargo(std::string &name)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func563::func;
	return execfunc(this, name);
}

namespace _func564
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::AddWeapon", typeid(void (Equipment::*)(WeaponBlueprint *, bool , bool )), "!.554889e54157415641554154534881ec9800000089cb4989", nullptr, 0, 0, &func);
}

void Equipment::AddWeapon(WeaponBlueprint *bp, bool free, bool forceCargo)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, WeaponBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func564::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func565
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::AddDrone", typeid(void (Equipment::*)(DroneBlueprint *, bool , bool )), ".554889e5415741564154534883ec704189cf4989", nullptr, 0, 0, &func);
}

void Equipment::AddDrone(DroneBlueprint *bp, bool free, bool forceCargo)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, DroneBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func565::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func566
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::AddAugment", typeid(void (Equipment::*)(AugmentBlueprint *, bool , bool )), ".554889e54157415641554154534883ec684989f64989fd4d", nullptr, 0, 0, &func);
}

void Equipment::AddAugment(AugmentBlueprint *bp, bool free, bool forceCargo)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, AugmentBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func566::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func567
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::Open", typeid(void (Equipment::*)()), ".554889e54157415653504989fee8ee84", nullptr, 0, 0, &func);
}

void Equipment::Open()
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func567::func;
	return execfunc(this);
}

namespace _func568
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::MouseClick", typeid(void (Equipment::*)(int , int )), ".554889e553504889fbe81281", nullptr, 0, 0, &func);
}

void Equipment::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func568::func;
	return execfunc(this, mX, mY);
}

namespace _func569
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::MouseUp", typeid(void (Equipment::*)(int , int )), ".554889e5534883ec684889fb80bb1403", nullptr, 0, 0, &func);
}

void Equipment::MouseUp(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func569::func;
	return execfunc(this, mX, mY);
}

namespace _func570
{
	static void *func = 0;
	static FunctionDefinition funcObj("Equipment::Close", typeid(void (Equipment::*)()), "!.554889e5c64708??5d", nullptr, 0, 0, &func);
}

void Equipment::Close()
{
	typedef void (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func570::func;
	return execfunc(this);
}

namespace _func571
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::constructor", typeid(void (EquipmentBox::*)(Point , int )), "554889e5534883ec184889fb4889f048c1e820488d0d", nullptr, 0, 0, &func);
}

void EquipmentBox::constructor(Point _position, int _slot)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Point _position_arg, int _slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func571::func;
	return execfunc(this, _position, _slot);
}

namespace _func572
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::destructor", typeid(void (EquipmentBox::*)()), "!.554889e553504889fb488d05????????488903488b7b38", nullptr, 0, 0, &func);
}

void EquipmentBox::destructor()
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func572::func;
	return execfunc(this);
}

namespace _func573
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::SetPosition", typeid(void (EquipmentBox::*)(Point )), ".554889e54889f048c1e82089", nullptr, 0, 0, &func);
}

void EquipmentBox::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func573::func;
	return execfunc(this, position);
}

namespace _func574
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::OnRender", typeid(void (EquipmentBox::*)(bool )), "!.554889e541574156534883ec284189f64889fbe8", nullptr, 0, 0, &func);
}

void EquipmentBox::OnRender(bool isEmpty)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool isEmpty_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func574::func;
	return execfunc(this, isEmpty);
}

namespace _func575
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::RenderLabels", typeid(void (EquipmentBox::*)(bool )), ".554889e54156534883ec504989fe0f57", nullptr, 0, 0, &func);
}

void EquipmentBox::RenderLabels(bool dragging)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool dragging_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func575::func;
	return execfunc(this, dragging);
}

namespace _func576
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::MouseMove", typeid(void (EquipmentBox::*)(int , int )), ".554889e58b477039", nullptr, 0, 0, &func);
}

void EquipmentBox::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func576::func;
	return execfunc(this, x, y);
}

namespace _func577
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::UpdateBoxImage", typeid(void (EquipmentBox::*)(bool )), ".554889e5415741564154534883ec504989ff0f57", nullptr, 0, 0, &func);
}

void EquipmentBox::UpdateBoxImage(bool dragging)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool dragging_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func577::func;
	return execfunc(this, dragging);
}

namespace _func578
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::GetItemValue", typeid(int (EquipmentBox::*)()), ".554889e5488b87800000004885c0750c", nullptr, 0, 0, &func);
}

int EquipmentBox::GetItemValue()
{
	typedef int (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func578::func;
	return execfunc(this);
}

namespace _func579
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::SetBlueprint", typeid(void (EquipmentBox::*)(InfoBox *, bool )), "!.554889e54157415653504189d64989f74889fb31", nullptr, 0, 0, &func);
}

void EquipmentBox::SetBlueprint(InfoBox *infoBox, bool detailedBox)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, InfoBox *infoBox_arg, bool detailedBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func579::func;
	return execfunc(this, infoBox, detailedBox);
}

namespace _func580
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::GetBlueprint", typeid(Blueprint *(EquipmentBox::*)()), ".554889e5488b878800000048", nullptr, 0, 0, &func);
}

Blueprint *EquipmentBox::GetBlueprint()
{
	typedef Blueprint *(*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func580::func;
	return execfunc(this);
}

namespace _func581
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::Restart", typeid(void (EquipmentBox::*)()), ".554889e548c78798000000", nullptr, 0, 0, &func);
}

void EquipmentBox::Restart()
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func581::func;
	return execfunc(this);
}

namespace _func582
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::AddItem", typeid(void (EquipmentBox::*)(EquipmentBoxItem )), ".554889e5488b4528", nullptr, 0, 0, &func);
}

void EquipmentBox::AddItem(EquipmentBoxItem item)
{
	typedef void (*custom_arg_funcptr_t)(EquipmentBox *this_arg, EquipmentBoxItem item_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func582::func;
	return execfunc(this, item);
}

namespace _func583
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::CanHoldWeapon", typeid(bool (EquipmentBox::*)()), ".554889e5488b87800000004885c0750a", nullptr, 0, 0, &func);
}

bool EquipmentBox::CanHoldWeapon()
{
	typedef bool (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func583::func;
	return execfunc(this);
}

namespace _func584
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::CanHoldDrone", typeid(bool (EquipmentBox::*)()), ".554889e54883bf8000000000488b8788", nullptr, 0, 0, &func);
}

bool EquipmentBox::CanHoldDrone()
{
	typedef bool (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func584::func;
	return execfunc(this);
}

namespace _func585
{
	static void *func = 0;
	static FunctionDefinition funcObj("EquipmentBox::GetType", typeid(int (EquipmentBox::*)()), ".554889e5488b8f800000004885c9750a", nullptr, 0, 0, &func);
}

int EquipmentBox::GetType()
{
	typedef int (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func585::func;
	return execfunc(this);
}

EventGenerator *Global_EventGenerator_Generator;

namespace _var586
{
	static VariableDefinition varObj("Global_EventGenerator_Generator", "!48c740080000000048c70000000000488d3d(???????\?)488d75e031d231c9", &Global_EventGenerator_Generator, true, true);
}

namespace _func587
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventGenerator::CreateEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool )), "!.554889e54157415641554154534881ec48050000", nullptr, 0, 0, &func);
}

LocationEvent *EventGenerator::CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique)
{
	typedef LocationEvent *(*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, bool ignoreUnique_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func587::func;
	return execfunc(this, name, worldLevel, ignoreUnique);
}

namespace _func588
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventGenerator::GetImageFromList", typeid(std::string (EventGenerator::*)(const std::string &)), ".554889e5415741564155415453504989d74889f34989fe48", nullptr, 0, 0, &func);
}

std::string EventGenerator::GetImageFromList(const std::string &listName)
{
	typedef std::string (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func588::func;
	return execfunc(this, listName);
}

namespace _func589
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventGenerator::GetBaseEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , char , int )), "!.554889e5415741564154534189cf4189d64989f4", nullptr, 0, 0, &func);
}

LocationEvent *EventGenerator::GetBaseEvent(const std::string &name, int worldLevel, char ignoreUnique, int seed)
{
	typedef LocationEvent *(*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, char ignoreUnique_arg, int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func589::func;
	return execfunc(this, name, worldLevel, ignoreUnique, seed);
}

namespace _func590
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventGenerator::GetShipEvent", typeid(ShipEvent (EventGenerator::*)(const std::string &)), ".554889e54157415653504989d74889f34989fe4881c35801", nullptr, 0, 0, &func);
}

ShipEvent EventGenerator::GetShipEvent(const std::string &event)
{
	typedef ShipEvent (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func590::func;
	return execfunc(this, event);
}

namespace _func591
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventGenerator::GetSpecificSector", typeid(SectorDescription (EventGenerator::*)(const std::string &)), ".554889e541574156534883ec184889d3", nullptr, 0, 0, &func);
}

SectorDescription EventGenerator::GetSpecificSector(const std::string &name)
{
	typedef SectorDescription (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func591::func;
	return execfunc(this, name);
}

namespace _func592
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventGenerator::GetSectorDescription", typeid(SectorDescription (EventGenerator::*)(const std::string &, int )), "!.554889e54157415641554154534883ec58894dac", nullptr, 0, 0, &func);
}

SectorDescription EventGenerator::GetSectorDescription(const std::string &type, int level)
{
	typedef SectorDescription (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &type_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func592::func;
	return execfunc(this, type, level);
}

EventSystem *Global_EventSystem_EventManager;

namespace _var593
{
	static VariableDefinition varObj("Global_EventSystem_EventManager", "!4889dfe8????????488d3d(???????\?)e8", &Global_EventSystem_EventManager, true, true);
}

namespace _func594
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventSystem::PollEvent", typeid(bool (EventSystem::*)(int )), ".554889e531c085f67818488b", nullptr, 0, 0, &func);
}

bool EventSystem::PollEvent(int id)
{
	typedef bool (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func594::func;
	return execfunc(this, id);
}

namespace _func595
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), ".554889e585f67819", nullptr, 0, 0, &func);
}

void EventSystem::AddEvent(int id)
{
	typedef void (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func595::func;
	return execfunc(this, id);
}

EventsParser *Global_EventsParser_Parser;

namespace _var596
{
	static VariableDefinition varObj("Global_EventsParser_Parser", "!31c0e8??????00488d3d(???????\?)e8????1a00", &Global_EventsParser_Parser, true, true);
}

namespace _func597
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::AddAllEvents", typeid(void (EventsParser::*)()), ".554889e54157415641554154534883ec4848897d98488d3d", nullptr, 0, 0, &func);
}

void EventsParser::AddAllEvents()
{
	typedef void (*custom_arg_funcptr_t)(EventsParser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func597::func;
	return execfunc(this);
}

namespace _func598
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::AddEvents", typeid(void (EventsParser::*)(EventGenerator &, char *, const std::string &)), "!.554889e54157415641554154534881ecf8000100", nullptr, 0, 0, &func);
}

void EventsParser::AddEvents(EventGenerator &generator, char *file, const std::string &fileName)
{
	typedef void (*custom_arg_funcptr_t)(EventsParser *this_arg, EventGenerator &generator_arg, char *file_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func598::func;
	return execfunc(this, generator, file, fileName);
}

namespace _func599
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::ProcessBaseNode", typeid(void (EventsParser::*)(rapidxml::xml_node<char> *, EventGenerator &)), "!.554889e54157415641554154534881ec2802000048899578", nullptr, 0, 0, &func);
}

void EventsParser::ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator)
{
	typedef void (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, EventGenerator &generator_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func599::func;
	return execfunc(this, node, generator);
}

namespace _func600
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(std::string (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "!.554889e54157415641554154534881ec98030000", nullptr, 0, 0, &func);
}

std::string EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName)
{
	typedef std::string (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &eventName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func600::func;
	return execfunc(this, node, eventName);
}

namespace _func601
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::ProcessEventList", typeid(std::vector<std::string> (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "!.554889e54157415641554154534883ec384989ce4989f749", nullptr, 0, 0, &func);
}

std::vector<std::string> EventsParser::ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName)
{
	typedef std::vector<std::string> (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func601::func;
	return execfunc(this, node, listName);
}

namespace _func602
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::ProcessShipEvent", typeid(ShipTemplate (EventsParser::*)(rapidxml::xml_node<char> *)), "!.554889e54157415641554154534881ec480600004989d648", nullptr, 0, 0, &func);
}

ShipTemplate EventsParser::ProcessShipEvent(rapidxml::xml_node<char> *node)
{
	typedef ShipTemplate (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func602::func;
	return execfunc(this, node);
}

namespace _func603
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "!.554889e54157415641554154534883ec684989d5", nullptr, 0, 0, &func);
}

RandomAmount EventsParser::PullMinMax(rapidxml::xml_node<char> *node, const std::string &name)
{
	typedef RandomAmount (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func603::func;
	return execfunc(this, node, name);
}

namespace _func604
{
	static void *func = 0;
	static FunctionDefinition funcObj("EventsParser::ProcessModifyItem", typeid(ResourcesTemplate (EventsParser::*)(ResourcesTemplate &, rapidxml::xml_node<char> *, const std::string &)), "!.554889e54157415641554154534881ecb80000004989cf48", nullptr, 0, 0, &func);
}

ResourcesTemplate EventsParser::ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &origin)
{
	typedef ResourcesTemplate (*custom_arg_funcptr_t)(EventsParser *this_arg, ResourcesTemplate &resources_arg, rapidxml::xml_node<char> *node_arg, const std::string &origin_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func604::func;
	return execfunc(this, resources, node, origin);
}

namespace _func605
{
	static void *func = 0;
	static FunctionDefinition funcObj("ExplosionAnimation::OnInit", typeid(void (ExplosionAnimation::*)(rapidxml::xml_node<char> *, const std::string &, Point )), "!554889e54157415641554154534881ec080100004989ce48", nullptr, 0, 0, &func);
}

void ExplosionAnimation::OnInit(rapidxml::xml_node<char> *node, const std::string &name, Point glowOffset)
{
	typedef void (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg, Point glowOffset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func605::func;
	return execfunc(this, node, name, glowOffset);
}

namespace _func606
{
	static void *func = 0;
	static FunctionDefinition funcObj("FTLButton::OnRender", typeid(void (FTLButton::*)()), "554889e54157415641554154534881ec680100004989fd498bbd2001", nullptr, 0, 0, &func);
}

void FTLButton::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(FTLButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func606::func;
	return execfunc(this);
}

namespace _func607
{
	static void *func = 0;
	static FunctionDefinition funcObj("FTLButton::MouseMove", typeid(void (FTLButton::*)(int , int , bool )), "!.554889e5415741564155415453504189cf4189d6", nullptr, 0, 0, &func);
}

void FTLButton::MouseMove(int mX, int mY, bool silent)
{
	typedef void (*custom_arg_funcptr_t)(FTLButton *this_arg, int mX_arg, int mY_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func607::func;
	return execfunc(this, mX, mY, silent);
}

namespace _func608
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::deleteFile", typeid(void (*)(const std::string &)), "!.554889e54156534889fb4c8d7301f60301488b7b10490f44fe31f6e8????160085c07405", nullptr, 0, 0, &func);
}

void FileHelper::deleteFile(const std::string &fileName)
{
	typedef void (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func608::func;
	return execfunc(fileName);
}

namespace _func609
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::getResourceFile", typeid(std::string (*)()), "!.554889e54157415641554154534883ec??4989ffe8????????4989c6", nullptr, 0, 0, &func);
}

std::string FileHelper::getResourceFile()
{
	typedef std::string (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func609::func;
	return execfunc();
}

namespace _func610
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::getUserFolder", typeid(std::string (*)()), "!.554889e5415741564155415453504989ffe8", nullptr, 0, 0, &func);
}

std::string FileHelper::getUserFolder()
{
	typedef std::string (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func610::func;
	return execfunc();
}

namespace _func611
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::getSaveFile", typeid(std::string (*)()), "!.554889e54157415641554154534883ec184989ffe8????0c", nullptr, 0, 0, &func);
}

std::string FileHelper::getSaveFile()
{
	typedef std::string (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func611::func;
	return execfunc();
}

namespace _func612
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::initFileHelper", typeid(void (*)()), "!.554889e54157415641554154534883ec18e8", nullptr, 0, 0, &func);
}

void FileHelper::initFileHelper()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func612::func;
	return execfunc();
}

namespace _func613
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::fileExists", typeid(bool (*)(const std::string &)), ".554889e5488d4701f60701480f45471031f64889", nullptr, 0, 0, &func);
}

bool FileHelper::fileExists(const std::string &fileName)
{
	typedef bool (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func613::func;
	return execfunc(fileName);
}

namespace _func614
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::renameFile", typeid(void (*)(const std::string &, const std::string &)), "!.554889e5488d4701f60701480f454710488d4e01", nullptr, 0, 0, &func);
}

void FileHelper::renameFile(const std::string &fileName, const std::string &newName)
{
	typedef void (*custom_arg_funcptr_t)(const std::string &fileName_arg, const std::string &newName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func614::func;
	return execfunc(fileName, newName);
}

namespace _func615
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::createBinaryFile", typeid(int (*)(const std::string &)), "!.554889e54156534889fb4c8d7301f60301488b7b10490f44fe31f6e8????160085c07510", nullptr, 0, 0, &func);
}

int FileHelper::createBinaryFile(const std::string &fileName)
{
	typedef int (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func615::func;
	return execfunc(fileName);
}

namespace _func616
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::saveFileExists", typeid(bool (*)()), ".554889e55350e825", nullptr, 0, 0, &func);
}

bool FileHelper::saveFileExists()
{
	typedef bool (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func616::func;
	return execfunc();
}

namespace _func617
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readSaveFile", typeid(int (*)()), ".554889e5534883ec18488d3d????1800488d75e8", nullptr, 0, 0, &func);
}

int FileHelper::readSaveFile()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func617::func;
	return execfunc();
}

namespace _func618
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::closeBinaryFile", typeid(void (*)(int )), "!.89f981f9", nullptr, 0, 0, &func);
}

void FileHelper::closeBinaryFile(int file)
{
	typedef void (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func618::func;
	return execfunc(file);
}

namespace _func619
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readStatsFile", typeid(int (*)()), ".554889e5534883ec18488d3d????1800488d75e8", nullptr, 0, 0, &func);
}

int FileHelper::readStatsFile()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func619::func;
	return execfunc();
}

namespace _func620
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::createSaveFile", typeid(int (*)()), ".554889e5488b05????1f00488905????1f00b801", nullptr, 0, 0, &func);
}

int FileHelper::createSaveFile()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func620::func;
	return execfunc();
}

namespace _func621
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::createStatsFile", typeid(int (*)()), ".554889e5488b05????1f00488905????1f00b803", nullptr, 0, 0, &func);
}

int FileHelper::createStatsFile()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func621::func;
	return execfunc();
}

namespace _func622
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::deleteSaveFile", typeid(void (*)()), "!.554889e55350488d3d????18", nullptr, 0, 0, &func);
}

void FileHelper::deleteSaveFile()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func622::func;
	return execfunc();
}

namespace _func623
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::deleteAllSaveFiles", typeid(void (*)()), ".554889e541574156534883ec18488d7d", nullptr, 0, 0, &func);
}

void FileHelper::deleteAllSaveFiles()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func623::func;
	return execfunc();
}

namespace _func624
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::getPosition", typeid(int (*)(int )), ".554889e58b05????1f005d", nullptr, 0, 0, &func);
}

int FileHelper::getPosition(int file)
{
	typedef int (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func624::func;
	return execfunc(file);
}

namespace _func625
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readBinaryFile", typeid(int (*)(const std::string &)), ".554889e5488d4f01", nullptr, 0, 0, &func);
}

int FileHelper::readBinaryFile(const std::string &fileName)
{
	typedef int (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func625::func;
	return execfunc(fileName);
}

namespace _func626
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::writeString", typeid(bool (*)(int , const std::string &)), ".554889e5415741564155415453504189fd4c8d7e", nullptr, 0, 0, &func);
}

bool FileHelper::writeString(int file, const std::string &data)
{
	typedef bool (*custom_arg_funcptr_t)(int file_arg, const std::string &data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func626::func;
	return execfunc(file, data);
}

namespace _func627
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::writeInt", typeid(bool (*)(int , int )), ".554889e54157415653504189f789f944", nullptr, 0, 0, &func);
}

bool FileHelper::writeInt(int file, int data)
{
	typedef bool (*custom_arg_funcptr_t)(int file_arg, int data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func627::func;
	return execfunc(file, data);
}

namespace _func628
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::writeData", typeid(bool (*)(int , void *, int )), ".554889e5415741564154534189d44989", nullptr, 0, 0, &func);
}

bool FileHelper::writeData(int file, void *data, int len)
{
	typedef bool (*custom_arg_funcptr_t)(int file_arg, void *data_arg, int len_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func628::func;
	return execfunc(file, data, len);
}

namespace _func629
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::writeFloat", typeid(bool (*)(int , float )), ".554889e541574156535089f9", nullptr, 0, 0, &func);
}

bool FileHelper::writeFloat(int file, float data)
{
	typedef bool (*custom_arg_funcptr_t)(int file_arg, float data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func629::func;
	return execfunc(file, data);
}

namespace _func630
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readString", typeid(std::string (*)(int )), "!.554889e54157415641554154534883ec284189f44989fe41", nullptr, 0, 0, &func);
}

std::string FileHelper::readString(int file)
{
	typedef std::string (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func630::func;
	return execfunc(file);
}

namespace _func631
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readInteger", typeid(int (*)(int )), ".554889e5415741564154534883ec10", nullptr, 0, 0, &func);
}

int FileHelper::readInteger(int file)
{
	typedef int (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func631::func;
	return execfunc(file);
}

namespace _func632
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readData", typeid(void (*)(int , void *, int )), "!.554889e5415741564155415453504189d74989f64189fc41", nullptr, 0, 0, &func);
}

void FileHelper::readData(int file, void *data, int len)
{
	typedef void (*custom_arg_funcptr_t)(int file_arg, void *data_arg, int len_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func632::func;
	return execfunc(file, data, len);
}

namespace _func633
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readFloat", typeid(float (*)(int )), ".554889e5415741564154534883ec10", nullptr, 0, 0, &func);
}

float FileHelper::readFloat(int file)
{
	typedef float (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func633::func;
	return execfunc(file);
}

namespace _func634
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::seekPosition", typeid(bool (*)(int , int )), ".554889e58935", nullptr, 0, 0, &func);
}

bool FileHelper::seekPosition(int file, int position)
{
	typedef bool (*custom_arg_funcptr_t)(int file_arg, int position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func634::func;
	return execfunc(file, position);
}

namespace _func635
{
	static void *func = 0;
	static FunctionDefinition funcObj("FileHelper::readBuffer", typeid(char *(*)(int , int , bool )), ".554889e54157415641554154534883ec1889d341", nullptr, 0, 0, &func);
}

char *FileHelper::readBuffer(int file, int len, bool nullTerminate)
{
	typedef char *(*custom_arg_funcptr_t)(int file_arg, int len_arg, bool nullTerminate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func635::func;
	return execfunc(file, len, nullTerminate);
}

namespace _func636
{
	static void *func = 0;
	static FunctionDefinition funcObj("Fire::UpdateDeathTimer", typeid(void (Fire::*)(int )), "554889e54156534883ec104189f64889fb488b03", nullptr, 0, 0, &func);
}

void Fire::UpdateDeathTimer(int connectedFires)
{
	typedef void (*custom_arg_funcptr_t)(Fire *this_arg, int connectedFires_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func636::func;
	return execfunc(this, connectedFires);
}

namespace _func637
{
	static void *func = 0;
	static FunctionDefinition funcObj("Fire::OnLoop", typeid(void (Fire::*)()), "!.554889e54156534889fb80bb58020000", nullptr, 0, 0, &func);
}

void Fire::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(Fire *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func637::func;
	return execfunc(this);
}

namespace _func638
{
	static void *func = 0;
	static FunctionDefinition funcObj("Fire::UpdateStartTimer", typeid(void (Fire::*)(int )), ".554889e54156534883ec104189f64889fb488b03", nullptr, 0, 0, &func);
}

void Fire::UpdateStartTimer(int doorLevel)
{
	typedef void (*custom_arg_funcptr_t)(Fire *this_arg, int doorLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func638::func;
	return execfunc(this, doorLevel);
}

namespace _func639
{
	static void *func = 0;
	static FunctionDefinition funcObj("FocusWindow::MouseMove", typeid(void (FocusWindow::*)(int , int )), "!.554889e58b4f0c83", nullptr, 0, 0, &func);
}

void FocusWindow::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func639::func;
	return execfunc(this, x, y);
}

namespace _func640
{
	static void *func = 0;
	static FunctionDefinition funcObj("FocusWindow::MouseClick", typeid(void (FocusWindow::*)(int , int )), ".554889e5807f1400", nullptr, 0, 0, &func);
}

void FocusWindow::MouseClick(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func640::func;
	return execfunc(this, x, y);
}

namespace _func641
{
	static void *func = 0;
	static FunctionDefinition funcObj("GameOver::OnLoop", typeid(void (GameOver::*)()), ".554889e541574156534883ec384989fe488d3d59", nullptr, 0, 0, &func);
}

void GameOver::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func641::func;
	return execfunc(this);
}

namespace _func642
{
	static void *func = 0;
	static FunctionDefinition funcObj("GameOver::OnRender", typeid(void (GameOver::*)()), ".554889e54157415641554154534883ec684989fd4180bd08", nullptr, 0, 0, &func);
}

void GameOver::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func642::func;
	return execfunc(this);
}

namespace _func643
{
	static void *func = 0;
	static FunctionDefinition funcObj("GameOver::OpenText", typeid(void (GameOver::*)(const std::string &)), "!.554889e54157415641554154534881ec280100004989ff41", nullptr, 0, 0, &func);
}

void GameOver::OpenText(const std::string &text)
{
	typedef void (*custom_arg_funcptr_t)(GameOver *this_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func643::func;
	return execfunc(this, text);
}

namespace _func644
{
	static void *func = 0;
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void (GenericButton::*)(Point )), "!554889e54889f048c1e8208b5708", nullptr, 0, 0, &func);
}

void GenericButton::SetLocation(Point position)
{
	typedef void (*custom_arg_funcptr_t)(GenericButton *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func644::func;
	return execfunc(this, position);
}

namespace _func645
{
	static void *func = 0;
	static FunctionDefinition funcObj("GenericButton::SetActive", typeid(void (GenericButton::*)(bool )), ".554889e540887748", nullptr, 0, 0, &func);
}

void GenericButton::SetActive(bool active)
{
	typedef void (*custom_arg_funcptr_t)(GenericButton *this_arg, bool active_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func645::func;
	return execfunc(this, active);
}

namespace _func646
{
	static void *func = 0;
	static FunctionDefinition funcObj("GenericButton::MouseMove", typeid(void (GenericButton::*)(int , int , bool )), "!.554889e58b471039", nullptr, 0, 0, &func);
}

void GenericButton::MouseMove(int x, int y, bool silent)
{
	typedef void (*custom_arg_funcptr_t)(GenericButton *this_arg, int x_arg, int y_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func646::func;
	return execfunc(this, x, y, silent);
}

namespace _func647
{
	static void *func = 0;
	static FunctionDefinition funcObj("getSkillBonus", typeid(float (*)(int , int )), "554889e583ff0577??89f8488d0d", nullptr, 0, 0, &func);
}

float __stdcall getSkillBonus(int skill, int level)
{
	typedef float (*custom_arg_funcptr_t)(int skill_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func647::func;
	return execfunc(skill, level);
}

namespace _func648
{
	static void *func = 0;
	static FunctionDefinition funcObj("GetValue", typeid(void (*)(ResourceEvent &, const std::string &, int , int )), ".554889e5415741564154534883ec104189cc", nullptr, 0, 0, &func);
}

void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel)
{
	typedef void (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, const std::string &type_arg, int level_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func648::func;
	return execfunc(ref, type, level, worldLevel);
}

namespace _func649
{
	static void *func = 0;
	static FunctionDefinition funcObj("GenerateReward", typeid(void (*)(ResourceEvent &, RewardDesc &, int )), ".554889e54157415641554154534881ecb8040000", nullptr, 0, 0, &func);
}

void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel)
{
	typedef void (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, RewardDesc &reward_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func649::func;
	return execfunc(ref, reward, worldLevel);
}

namespace _func650
{
	static void *func = 0;
	static FunctionDefinition funcObj("font_text_width", typeid(float (*)(freetype::font_data &, const char *, float )), ".0f28c885ff0f57c07e??393d", nullptr, 0, 0, &func);
}

float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size)
{
	typedef float (*custom_arg_funcptr_t)(freetype::font_data &fontData_arg, const char *str_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func650::func;
	return execfunc(fontData, str, size);
}

namespace _func651
{
	static void *func = 0;
	static FunctionDefinition funcObj("graphics_clear", typeid(void (*)(float , float , float , float , float , unsigned int )), ".554889e54883ec2089f8", nullptr, 0, 0, &func);
}

void __stdcall graphics_clear(float r, float g, float b, float a, float depth, unsigned int stencil)
{
	typedef void (*custom_arg_funcptr_t)(float r_arg, float g_arg, float b_arg, float a_arg, float depth_arg, unsigned int stencil_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func651::func;
	return execfunc(r, g, b, a, depth, stencil);
}

namespace _func652
{
	static void *func = 0;
	static FunctionDefinition funcObj("random32", typeid(int (*)()), ".554889e548b82d7f954c2df45158", nullptr, 0, 0, &func);
}

int __stdcall random32()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func652::func;
	return execfunc();
}

namespace _func653
{
	static void *func = 0;
	static FunctionDefinition funcObj("srandom32", typeid(void (*)(unsigned int )), ".554889e589f8488905", nullptr, 0, 0, &func);
}

void __stdcall srandom32(unsigned int seed)
{
	typedef void (*custom_arg_funcptr_t)(unsigned int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func653::func;
	return execfunc(seed);
}

namespace _func654
{
	static void *func = 0;
	static FunctionDefinition funcObj("sys_graphics_set_window_title", typeid(void (*)(char *)), "!.554889e553504889fb488b3d", nullptr, 0, 0, &func);
}

void __stdcall sys_graphics_set_window_title(char *title)
{
	typedef void (*custom_arg_funcptr_t)(char *title_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func654::func;
	return execfunc(title);
}

int *Globals_GetNextSpaceId_id;

namespace _var655
{
	static VariableDefinition varObj("Globals_GetNextSpaceId_id", "!554889e58b05(???????\?)85c075", &Globals_GetNextSpaceId_id, true, true);
}

TextLibrary *Global_Globals_Library;

namespace _var656
{
	static VariableDefinition varObj("Global_Globals_Library", "!c6401700458ba6????0000458bbe????0000488d1d(???????\?)", &Global_Globals_Library, true, true);
}

bool *Globals_RNG;

namespace _var657
{
	static VariableDefinition varObj("Globals_RNG", "!.e8????????488d0d(???????\?)80390074", &Globals_RNG, true, true);
}

FILE *ftl_log_logfile;

namespace _var658
{
	static VariableDefinition varObj("ftl_log_logfile", "!.74??488d35????????488dbdc0fbffffe8????????4889c748893d(???????\?)", &ftl_log_logfile, true, true);
}

namespace _func659
{
	static void *func = 0;
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , Pointf )), ".554889e54883ec400f294d??0f2945", nullptr, 0, 0, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, Pointf dest)
{
	typedef Pointf (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, Pointf dest_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func659::func;
	return execfunc(current, mag_speed, dest);
}

namespace _func660
{
	static void *func = 0;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), ".554889e58b05????????85c0750fc705????????64000000", nullptr, 0, 0, &func);
}

int Globals::GetNextSpaceId()
{
	typedef int (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func660::func;
	return execfunc();
}

namespace _func661
{
	static void *func = 0;
	static FunctionDefinition funcObj("Globals::AimAhead", typeid(float (*)(Pointf , Pointf , float )), ".554889e5f30f16d9", nullptr, 0, 0, &func);
}

float Globals::AimAhead(Pointf delta, Pointf vr, float muzzleV)
{
	typedef float (*custom_arg_funcptr_t)(Pointf delta_arg, Pointf vr_arg, float muzzleV_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func661::func;
	return execfunc(delta, vr, muzzleV);
}

namespace _func662
{
	static void *func = 0;
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , float )), ".554889e54883ec40f30f114d??0f2945", nullptr, 0, 0, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, float heading)
{
	typedef Pointf (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func662::func;
	return execfunc(current, mag_speed, heading);
}

namespace _func663
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackBox::constructor", typeid(void (HackBox::*)(Point , HackingSystem *, ShipManager *)), "!554889e54157415641554154534883ec??4989cc4889d34989fe", nullptr, 0, 0, &func);
}

void HackBox::constructor(Point _position, HackingSystem *_system, ShipManager *_ship)
{
	typedef void (*custom_arg_funcptr_t)(HackBox *this_arg, Point _position_arg, HackingSystem *_system_arg, ShipManager *_ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func663::func;
	return execfunc(this, _position, _system, _ship);
}

namespace _func664
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackingDrone::SetMovementTarget", typeid(void (HackingDrone::*)(Targetable *)), "554889e54156534883ec104989f64889fb4d85f6", nullptr, 0, 0, &func);
}

void HackingDrone::SetMovementTarget(Targetable *target)
{
	typedef void (*custom_arg_funcptr_t)(HackingDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func664::func;
	return execfunc(this, target);
}

namespace _func665
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackingDrone::CollisionMoving", typeid(CollisionResponse (HackingDrone::*)(Pointf , Pointf , Damage , bool )), ".554889e541574156534883ec584989f64889fb41807e1800", nullptr, 0, 0, &func);
}

CollisionResponse HackingDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(HackingDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func665::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func666
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackingDrone::OnLoop", typeid(void (HackingDrone::*)()), ".554889e5415741564154534883ec404989fce8a9", nullptr, 0, 0, &func);
}

void HackingDrone::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(HackingDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func666::func;
	return execfunc(this);
}

namespace _func667
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackingSystem::SoundLoop", typeid(bool (HackingSystem::*)()), ".554889e553504889fb80bb6402000000740d4889", nullptr, 0, 0, &func);
}

bool HackingSystem::SoundLoop()
{
	typedef bool (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func667::func;
	return execfunc(this);
}

namespace _func668
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackingSystem::OnLoop", typeid(void (HackingSystem::*)()), ".554889e54156534883ec204889fbe84db500004c", nullptr, 0, 0, &func);
}

void HackingSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func668::func;
	return execfunc(this);
}

namespace _func669
{
	static void *func = 0;
	static FunctionDefinition funcObj("HackingSystem::BlowHackingDrone", typeid(void (HackingSystem::*)()), "!.554889e580bf8002", nullptr, 0, 0, &func);
}

void HackingSystem::BlowHackingDrone()
{
	typedef void (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func669::func;
	return execfunc(this);
}

namespace _func670
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (InfoBox::*)()), "554889e553504889fb31f631d2e8", nullptr, 0, 0, &func);
}

namespace _func671
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::constructor", typeid(void (InfoBox::*)()), ".554889e553504889fb31f631d2e8", nullptr, 0, 0, &func);
}

void InfoBox::constructor()
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func671::func;
	return execfunc(this);
}

namespace _func672
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetSystem", typeid(void (InfoBox::*)(ShipSystem *, int , int , int )), ".554889e54157415641554154534883ec284589c5", nullptr, 0, 0, &func);
}

void InfoBox::SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, ShipSystem *system_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func672::func;
	return execfunc(this, system, upgrade, yShift, forceSystemWidth);
}

namespace _func673
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetSystemId", typeid(void (InfoBox::*)(int , int , int , int , int , int )), ".554889e54157415641554154534883ec484589ce", nullptr, 0, 0, &func);
}

void InfoBox::SetSystemId(int systemId, int maxPower, int currentLevel, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, int systemId_arg, int maxPower_arg, int currentLevel_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func673::func;
	return execfunc(this, systemId, maxPower, currentLevel, upgrade, yShift, forceSystemWidth);
}

namespace _func674
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::CalcBoxHeight", typeid(int (InfoBox::*)()), ".554889e54157415641554154534881ecb80000004889fb83", nullptr, 0, 0, &func);
}

int InfoBox::CalcBoxHeight()
{
	typedef int (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func674::func;
	return execfunc(this);
}

namespace _func675
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetBlueprintWeapon", typeid(void (InfoBox::*)(const WeaponBlueprint *, int , bool , int )), ".554889e54157415641554154534883ec78448945ac", nullptr, 0, 0, &func);
}

void InfoBox::SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, const WeaponBlueprint *bp_arg, int status_arg, bool hasWeaponSystem_arg, int yShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func675::func;
	return execfunc(this, bp, status, hasWeaponSystem, yShift);
}

namespace _func676
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetBlueprintDrone", typeid(void (InfoBox::*)(const DroneBlueprint *, int , bool , int )), ".554889e54157415641554154534881ec8800000044898574ffffff", nullptr, 0, 0, &func);
}

void InfoBox::SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, const DroneBlueprint *bp_arg, int status_arg, bool hasDroneSystem_arg, int yShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func676::func;
	return execfunc(this, bp, status, hasDroneSystem, yShift);
}

namespace _func677
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetBlueprint", typeid(void (InfoBox::*)(const ItemBlueprint *)), "!.554889e54157415653504889f34989fe498d7e10488d7320", nullptr, 0, 0, &func);
}

void InfoBox::SetBlueprint(const ItemBlueprint *bp)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, const ItemBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func677::func;
	return execfunc(this, bp);
}

namespace _func678
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetBlueprintCrew", typeid(void (InfoBox::*)(const CrewBlueprint *, int , bool )), ".554889e54157415641554154534881ec????????4189cf4889f3", nullptr, 0, 0, &func);
}

void InfoBox::SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, const CrewBlueprint *bp_arg, int yShift_arg, bool detailedCrew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func678::func;
	return execfunc(this, bp, yShift, detailedCrew);
}

namespace _func679
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetBlueprintAugment", typeid(void (InfoBox::*)(const AugmentBlueprint *)), ".554889e54157415653504889f3", nullptr, 0, 0, &func);
}

void InfoBox::SetBlueprintAugment(const AugmentBlueprint *bp)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, const AugmentBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func679::func;
	return execfunc(this, bp);
}

namespace _func680
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(void (InfoBox::*)(Description *, int , int , InfoBox::ExpandDir )), ".554889e5415741564155415453504589c74189cc4189d648", nullptr, 0, 0, &func);
}

void InfoBox::SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, Description *desc_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func680::func;
	return execfunc(this, desc, width, height, dir);
}

namespace _func681
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::SetText", typeid(void (InfoBox::*)(const std::string &, const std::string &, int , int , InfoBox::ExpandDir )), ".554889e54157415641554154534881ecb800000044894dd0", nullptr, 0, 0, &func);
}

void InfoBox::SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg, const std::string &title_arg, const std::string &text_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func681::func;
	return execfunc(this, title, text, width, height, dir);
}

namespace _func682
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::Clear", typeid(void (InfoBox::*)()), "!.554889e541574156534883ec184889fb48c783e0", nullptr, 0, 0, &func);
}

void InfoBox::Clear()
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func682::func;
	return execfunc(this);
}

namespace _func683
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::IsEmpty", typeid(bool (InfoBox::*)()), ".554889e54156534883ec204889fb83bbcc000000", nullptr, 0, 0, &func);
}

bool InfoBox::IsEmpty()
{
	typedef bool (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func683::func;
	return execfunc(this);
}

namespace _func684
{
	static void *func = 0;
	static FunctionDefinition funcObj("InfoBox::OnRender", typeid(void (InfoBox::*)()), ".554889e54157415641554154534881ec080100004889fb44", nullptr, 0, 0, &func);
}

void InfoBox::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func684::func;
	return execfunc(this);
}

GL_Color *Global_InfoBox_detailsBarOff;

namespace _var685
{
	static VariableDefinition varObj("Global_InfoBox_detailsBarOff", "!8b75904489fae8????????488b????????ff4939dc488d05(???????\?)488d0d(???????\?)480f4dc1", &Global_InfoBox_detailsBarOff, true, true);
}

GL_Color *Global_InfoBox_detailsBarOn;

namespace _var686
{
	static VariableDefinition varObj("Global_InfoBox_detailsBarOn", "", &Global_InfoBox_detailsBarOn, true, true);
}

namespace _func687
{
	static void *func = 0;
	static FunctionDefinition funcObj("InputBox::TextEvent", typeid(void (InputBox::*)(CEvent::TextEvent )), "!.554889e54157415653504989fe83fe03", nullptr, 0, 0, &func);
}

void InputBox::TextEvent(CEvent::TextEvent event)
{
	typedef void (*custom_arg_funcptr_t)(InputBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func687::func;
	return execfunc(this, event);
}

namespace _func688
{
	static void *func = 0;
	static FunctionDefinition funcObj("InputBox::StartInput", typeid(void (InputBox::*)()), ".554889e5534883ec184889fb488d7b48", nullptr, 0, 0, &func);
}

void InputBox::StartInput()
{
	typedef void (*custom_arg_funcptr_t)(InputBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func688::func;
	return execfunc(this);
}

namespace _func689
{
	static void *func = 0;
	static FunctionDefinition funcObj("IonDrone::GetRoomDamage", typeid(Damage (IonDrone::*)()), "554889e54156534989f64889fbc64320", nullptr, 0, 0, &func);
}

Damage IonDrone::GetRoomDamage()
{
	typedef Damage (*custom_arg_funcptr_t)(IonDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func689::func;
	return execfunc(this);
}

namespace _func690
{
	static void *func = 0;
	static FunctionDefinition funcObj("IonDroneAnimation::constructor", typeid(void (IonDroneAnimation::*)(int , Pointf , bool )), "!.554889e54157415641554154534881ecd80100004889fb0f", nullptr, 0, 0, &func);
}

void IonDroneAnimation::constructor(int _iShipId, Pointf _position, bool _enemy)
{
	typedef void (*custom_arg_funcptr_t)(IonDroneAnimation *this_arg, int _iShipId_arg, Pointf _position_arg, bool _enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func690::func;
	return execfunc(this, _iShipId, _position, _enemy);
}

namespace _func691
{
	static void *func = 0;
	static FunctionDefinition funcObj("ItemStoreBox::constructor", typeid(void (ItemStoreBox::*)(ShipManager *, const std::string &)), ".554889e5415741564154534883ec??4989d64989f74889fb488d35", nullptr, 0, 0, &func);
}

void ItemStoreBox::constructor(ShipManager *_ship, const std::string &_resourceName)
{
	typedef void (*custom_arg_funcptr_t)(ItemStoreBox *this_arg, ShipManager *_ship_arg, const std::string &_resourceName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func691::func;
	return execfunc(this, _ship, _resourceName);
}

std::vector<std::string> *Global_OptionsScreen_languageList;

namespace _var692
{
	static VariableDefinition varObj("Global_OptionsScreen_languageList", "!488b4320483b43280f85????????488b05????????482b05(???????\?)", &Global_OptionsScreen_languageList, true, true);
}

namespace _func693
{
	static void *func = 0;
	static FunctionDefinition funcObj("LanguageChooser::OnRender", typeid(void (LanguageChooser::*)()), ".554889e54157415641554154534883ec484889fb488b05", nullptr, 0, 0, &func);
}

void LanguageChooser::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(LanguageChooser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func693::func;
	return execfunc(this);
}

namespace _func694
{
	static void *func = 0;
	static FunctionDefinition funcObj("LaserBlast::OnUpdate", typeid(void (LaserBlast::*)()), "554889e553504889fbe8b2f9", nullptr, 0, 0, &func);
}

void LaserBlast::OnUpdate()
{
	typedef void (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func694::func;
	return execfunc(this);
}

namespace _func695
{
	static void *func = 0;
	static FunctionDefinition funcObj("LaserBlast::OnInit", typeid(void (LaserBlast::*)()), ".554889e553504889fbc74340", nullptr, 0, 0, &func);
}

void LaserBlast::OnInit()
{
	typedef void (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func695::func;
	return execfunc(this);
}

void **VTable_LaserBlast;

namespace _var696
{
	static VariableDefinition varObj("VTable_LaserBlast", "!.0f288d????????e8????????488d05(???????\?)4889c1488d81(???????\?)66480f6ec0488d41", &VTable_LaserBlast, true, true);
}

void **VTable_Targetable_LaserBlast;

namespace _var697
{
	static VariableDefinition varObj("VTable_Targetable_LaserBlast", "", &VTable_Targetable_LaserBlast, true, true);
}

namespace _func698
{
	static void *func = 0;
	static FunctionDefinition funcObj("LocationEvent::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (LocationEvent::*)()), ".554889e553504889fb48c74310", nullptr, 0, 0, &func);
}

namespace _func699
{
	static void *func = 0;
	static FunctionDefinition funcObj("LocationEvent::constructor", typeid(void (LocationEvent::*)()), ".554889e553504889fb48c74310", nullptr, 0, 0, &func);
}

void LocationEvent::constructor()
{
	typedef void (*custom_arg_funcptr_t)(LocationEvent *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func699::func;
	return execfunc(this);
}

namespace _func700
{
	static void *func = 0;
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), ".554889e5415741564154534883ec204989ff4183", nullptr, 0, 0, &func);
}

void LocationEvent::ClearEvent(bool force)
{
	typedef void (*custom_arg_funcptr_t)(LocationEvent *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func700::func;
	return execfunc(this, force);
}

namespace _func701
{
	static void *func = 0;
	static FunctionDefinition funcObj("LockdownShard::Update", typeid(void (LockdownShard::*)()), "!554889e553504889fb488d3d70??2d00e8????0d00f30f5905????2400f30f5883080100", nullptr, 0, 0, &func);
}

void LockdownShard::Update()
{
	typedef void (*custom_arg_funcptr_t)(LockdownShard *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func701::func;
	return execfunc(this);
}

namespace _func702
{
	static void *func = 0;
	static FunctionDefinition funcObj("MainMenu::constructor", typeid(void (MainMenu::*)()), "!.554889e54157415641554154534883ec??4889fb49be", nullptr, 0, 0, &func);
}

void MainMenu::constructor()
{
	typedef void (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func702::func;
	return execfunc(this);
}

namespace _func703
{
	static void *func = 0;
	static FunctionDefinition funcObj("MainMenu::OnRender", typeid(void (MainMenu::*)()), "!.554889e54157415641554154534881ec????00004989??4180", nullptr, 0, 0, &func);
}

void MainMenu::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func703::func;
	return execfunc(this);
}

namespace _func704
{
	static void *func = 0;
	static FunctionDefinition funcObj("MainMenu::Open", typeid(bool (MainMenu::*)()), ".554889e54157415641554154534881ec38040000", nullptr, 0, 0, &func);
}

bool MainMenu::Open()
{
	typedef bool (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func704::func;
	return execfunc(this);
}

namespace _func705
{
	static void *func = 0;
	static FunctionDefinition funcObj("MainMenu::OnLoop", typeid(void (MainMenu::*)()), "!.554889e54157415641554154534881ec????00004989??4180", nullptr, 0, 0, &func);
}

void MainMenu::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func705::func;
	return execfunc(this);
}

namespace _func706
{
	static void *func = 0;
	static FunctionDefinition funcObj("MainMenu::MouseMove", typeid(void (MainMenu::*)(int , int )), "!.554889e5415741564154534883ec604189d64189f74889fb", nullptr, 0, 0, &func);
}

void MainMenu::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(MainMenu *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func706::func;
	return execfunc(this, x, y);
}

namespace _func707
{
	static void *func = 0;
	static FunctionDefinition funcObj("MainMenu::MouseClick", typeid(void (MainMenu::*)(int , int )), "!.554889e541574156534883ec584889fb80bb", nullptr, 0, 0, &func);
}

void MainMenu::MouseClick(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(MainMenu *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func707::func;
	return execfunc(this, x, y);
}

namespace _func708
{
	static void *func = 0;
	static FunctionDefinition funcObj("MantisAnimation::GetDeathSound", typeid(std::string (MantisAnimation::*)()), "554889e548c7070000000048c747080000000048c7471000000000c6071648b86d616e74", nullptr, 0, 0, &func);
}

std::string MantisAnimation::GetDeathSound()
{
	typedef std::string (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func708::func;
	return execfunc(this);
}

namespace _func709
{
	static void *func = 0;
	static FunctionDefinition funcObj("MantisAnimation::GetShootingSound", typeid(std::string (MantisAnimation::*)()), ".554889e54156", nullptr, 0, 0, &func);
}

std::string MantisAnimation::GetShootingSound()
{
	typedef std::string (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func709::func;
	return execfunc(this);
}

namespace _func710
{
	static void *func = 0;
	static FunctionDefinition funcObj("MantisAnimation::DO_NOT_HOOK_ROCK_FireShot", typeid(void (MantisAnimation::*)()), ".554889e54157415653504889fb488b431041be900600004c8b384d01f74863", nullptr, 0, 0, &func);
}

namespace _func711
{
	static void *func = 0;
	static FunctionDefinition funcObj("MantisAnimation::FireShot", typeid(bool (MantisAnimation::*)()), ".554889e54157415653504889fb488b431041be900600004c8b384d01f74863", nullptr, 0, 0, &func);
}

bool MantisAnimation::FireShot()
{
	typedef bool (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func711::func;
	return execfunc(this);
}

namespace _func712
{
	static void *func = 0;
	static FunctionDefinition funcObj("MenuScreen::constructor", typeid(void (MenuScreen::*)()), "!.554889e54157415641554154534881ec????????4989fce8????????488d05????????4989042449c7442428", nullptr, 0, 0, &func);
}

void MenuScreen::constructor()
{
	typedef void (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func712::func;
	return execfunc(this);
}

namespace _func713
{
	static void *func = 0;
	static FunctionDefinition funcObj("MenuScreen::OnLanguageChange", typeid(void (MenuScreen::*)()), ".554889e54157415641554154534881ec????????4989ff498b4720", nullptr, 0, 0, &func);
}

void MenuScreen::OnLanguageChange()
{
	typedef void (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func713::func;
	return execfunc(this);
}

namespace _func714
{
	static void *func = 0;
	static FunctionDefinition funcObj("MenuScreen::OnRender", typeid(void (MenuScreen::*)()), "!.554889e54157415641554154534881ecb80000004989ff4180bf5803", nullptr, 0, 0, &func);
}

void MenuScreen::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func714::func;
	return execfunc(this);
}

namespace _func715
{
	static void *func = 0;
	static FunctionDefinition funcObj("MenuScreen::Open", typeid(void (MenuScreen::*)()), "!.554889e54157415641554154534883ec684889fbc6430801", nullptr, 0, 0, &func);
}

void MenuScreen::Open()
{
	typedef void (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func715::func;
	return execfunc(this);
}

namespace _func716
{
	static void *func = 0;
	static FunctionDefinition funcObj("MindBox::constructor", typeid(void (MindBox::*)(Point , MindSystem *)), ".554889e54156534883ec604989d64889fb31c9e8????0300488d05????????488903", nullptr, 0, 0, &func);
}

void MindBox::constructor(Point _position, MindSystem *_system)
{
	typedef void (*custom_arg_funcptr_t)(MindBox *this_arg, Point _position_arg, MindSystem *_system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func716::func;
	return execfunc(this, _position, _system);
}

namespace _func717
{
	static void *func = 0;
	static FunctionDefinition funcObj("MindSystem::OnLoop", typeid(void (MindSystem::*)()), ".554889e54157415641554154534883ec284989ffe807a800", nullptr, 0, 0, &func);
}

void MindSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func717::func;
	return execfunc(this);
}

namespace _func718
{
	static void *func = 0;
	static FunctionDefinition funcObj("MindSystem::InitiateMindControl", typeid(void (MindSystem::*)()), "!.554889e54157415641554154534881ec8800000048b8ffff", nullptr, 0, 0, &func);
}

void MindSystem::InitiateMindControl()
{
	typedef void (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func718::func;
	return execfunc(this);
}

namespace _func719
{
	static void *func = 0;
	static FunctionDefinition funcObj("MindSystem::SetArmed", typeid(void (MindSystem::*)(int )), ".554889e553504889fb83fe01", nullptr, 0, 0, &func);
}

void MindSystem::SetArmed(int armed)
{
	typedef void (*custom_arg_funcptr_t)(MindSystem *this_arg, int armed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func719::func;
	return execfunc(this, armed);
}

namespace _func720
{
	static void *func = 0;
	static FunctionDefinition funcObj("Missile::constructor", typeid(void (Missile::*)(Pointf , int , int , Pointf , float )), "554889e541574156534881ec18010000f30f1155e4", nullptr, 0, 0, &func);
}

void Missile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)
{
	typedef void (*custom_arg_funcptr_t)(Missile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, float _heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func720::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _heading);
}

MouseControl *Global_MouseControl_Mouse;

namespace _var721
{
	static VariableDefinition varObj("Global_MouseControl_Mouse", "!4c8b75??49895e18488d3d(???????\?)e8????????488d3d", &Global_MouseControl_Mouse, true, true);
}

namespace _func722
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::OnLoop", typeid(void (MouseControl::*)()), ".554889e553504889fb80bb4c01000000", nullptr, 0, 0, &func);
}

void MouseControl::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func722::func;
	return execfunc(this);
}

namespace _func723
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::InstantTooltip", typeid(void (MouseControl::*)()), ".554889e5c6876001", nullptr, 0, 0, &func);
}

void MouseControl::InstantTooltip()
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func723::func;
	return execfunc(this);
}

namespace _func724
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::OnRender", typeid(void (MouseControl::*)()), "!.554889e54157415641554154534883ec784989fd488b05", nullptr, 0, 0, &func);
}

void MouseControl::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func724::func;
	return execfunc(this);
}

namespace _func725
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::RenderTooltip", typeid(void (MouseControl::*)(Point , bool )), ".554889e54157415641554154534883ec684989f64989fc41", nullptr, 0, 0, &func);
}

void MouseControl::RenderTooltip(Point tooltipPoint, bool staticPos)
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg, Point tooltipPoint_arg, bool staticPos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func725::func;
	return execfunc(this, tooltipPoint, staticPos);
}

namespace _func726
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::ResetArmed", typeid(void (MouseControl::*)()), ".554889e548c7471000000000c7471800", nullptr, 0, 0, &func);
}

void MouseControl::ResetArmed()
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func726::func;
	return execfunc(this);
}

namespace _func727
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::SetDoor", typeid(void (MouseControl::*)(int )), ".554889e541565389f34989fe83fb0274", nullptr, 0, 0, &func);
}

void MouseControl::SetDoor(int state)
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg, int state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func727::func;
	return execfunc(this, state);
}

namespace _func728
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::MeasureTooltip", typeid(Point (MouseControl::*)(int )), ".554889e541574156534883ec384189f64989ff48", nullptr, 0, 0, &func);
}

Point MouseControl::MeasureTooltip(int width)
{
	typedef Point (*custom_arg_funcptr_t)(MouseControl *this_arg, int width_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func728::func;
	return execfunc(this, width);
}

namespace _func729
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::QueueStaticTooltip", typeid(void (MouseControl::*)(Point )), ".554889e54889b7a00100005d", nullptr, 0, 0, &func);
}

void MouseControl::QueueStaticTooltip(Point position)
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func729::func;
	return execfunc(this, position);
}

namespace _func730
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::Reset", typeid(void (MouseControl::*)()), ".554889e54156534883ec104889fb66c7", nullptr, 0, 0, &func);
}

void MouseControl::Reset()
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func730::func;
	return execfunc(this);
}

namespace _func731
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::LoadTooltip", typeid(void (MouseControl::*)(const std::string &)), ".554889e5415741564154534883ec304889f04989ff", nullptr, 0, 0, &func);
}

void MouseControl::LoadTooltip(const std::string &tooltipName)
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltipName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func731::func;
	return execfunc(this, tooltipName);
}

namespace _func732
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::SetTooltip", typeid(void (MouseControl::*)(const std::string &)), ".554889e5415741564154534989f74989fe418a07", nullptr, 0, 0, &func);
}

void MouseControl::SetTooltip(const std::string &tooltip)
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func732::func;
	return execfunc(this, tooltip);
}

namespace _func733
{
	static void *func = 0;
	static FunctionDefinition funcObj("MouseControl::SetTooltipTitle", typeid(void (MouseControl::*)(const std::string &)), ".0fb68768", nullptr, 0, 0, &func);
}

void MouseControl::SetTooltipTitle(const std::string &tooltip)
{
	typedef void (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func733::func;
	return execfunc(this, tooltip);
}

namespace _func734
{
	static void *func = 0;
	static FunctionDefinition funcObj("OptionsScreen::DO_NOT_HOOK_1", typeid(void (OptionsScreen::*)()), ".554889e553504889fb48c74358", nullptr, 0, 0, &func);
}

namespace _func735
{
	static void *func = 0;
	static FunctionDefinition funcObj("OptionsScreen::OnInit", typeid(void (OptionsScreen::*)()), ".554889e54157415641", nullptr, 0, 0, &func);
}

void OptionsScreen::OnInit()
{
	typedef void (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func735::func;
	return execfunc(this);
}

namespace _func736
{
	static void *func = 0;
	static FunctionDefinition funcObj("OptionsScreen::Open", typeid(void (OptionsScreen::*)(bool )), ".554889e54157415641554154534881ecf8070000", nullptr, 0, 0, &func);
}

void OptionsScreen::Open(bool mainMenu)
{
	typedef void (*custom_arg_funcptr_t)(OptionsScreen *this_arg, bool mainMenu_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func736::func;
	return execfunc(this, mainMenu);
}

namespace _func737
{
	static void *func = 0;
	static FunctionDefinition funcObj("OptionsScreen::OnLoop", typeid(void (OptionsScreen::*)()), ".554889e5415741564154534989fc", nullptr, 0, 0, &func);
}

void OptionsScreen::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func737::func;
	return execfunc(this);
}

void **VTable_OuterHull;

namespace _var738
{
	static VariableDefinition varObj("VTable_OuterHull", "!.4881ec400100004889fbe8????????488d05(???????\?)488903488d05????????48894310", &VTable_OuterHull, true, true);
}

namespace _func739
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (OxygenSystem::*)()), "!554889e5415741564154534189f64989ffbe0200", nullptr, 0, 0, &func);
}

namespace _func740
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::constructor", typeid(void (OxygenSystem::*)(int , int , int , int )), "!.554889e5415741564154534189f64989ffbe0200", nullptr, 0, 0, &func);
}

void OxygenSystem::constructor(int _numRooms, int _roomId, int _shipId, int _startingPower)
{
	typedef void (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int _numRooms_arg, int _roomId_arg, int _shipId_arg, int _startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func740::func;
	return execfunc(this, _numRooms, _roomId, _shipId, _startingPower);
}

namespace _func741
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::GetRefillSpeed", typeid(float (OxygenSystem::*)()), ".554889e553504889fb80bb44", nullptr, 0, 0, &func);
}

float OxygenSystem::GetRefillSpeed()
{
	typedef float (*custom_arg_funcptr_t)(OxygenSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func741::func;
	return execfunc(this);
}

namespace _func742
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(void (OxygenSystem::*)(int , float )), ".554889e54863c6488b8f68020000f30f580481f3", nullptr, 0, 0, &func);
}

void OxygenSystem::ModifyRoomOxygen(int roomId, float value)
{
	typedef void (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func742::func;
	return execfunc(this, roomId, value);
}

namespace _func743
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(void (OxygenSystem::*)(int , int , bool )), "!.554889e585d27e15", nullptr, 0, 0, &func);
}

void OxygenSystem::UpdateBreach(int roomId, int hasBreach, bool silent)
{
	typedef void (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int hasBreach_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func743::func;
	return execfunc(this, roomId, hasBreach, silent);
}

namespace _func744
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(void (OxygenSystem::*)(int , float , bool )), ".554889e54157415641554154534883ec288955d4f30f1145", nullptr, 0, 0, &func);
}

void OxygenSystem::ComputeAirLoss(int roomId, float value, bool silent)
{
	typedef void (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func744::func;
	return execfunc(this, roomId, value, silent);
}

namespace _func745
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(void (OxygenSystem::*)(int , int )), ".554889e541574156534883ec1889d341", nullptr, 0, 0, &func);
}

void OxygenSystem::UpdateAirlock(int roomId, int count)
{
	typedef void (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int count_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func745::func;
	return execfunc(this, roomId, count);
}

namespace _func746
{
	static void *func = 0;
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(void (OxygenSystem::*)(int )), ".554889e54863c6488b8f68020000c704", nullptr, 0, 0, &func);
}

void OxygenSystem::EmptyOxygen(int roomId)
{
	typedef void (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func746::func;
	return execfunc(this, roomId);
}

namespace _func747
{
	static void *func = 0;
	static FunctionDefinition funcObj("PDSFire::constructor", typeid(void (PDSFire::*)(Point , int , Pointf )), "554889e54157415641554154534881ec????????0f2945a0", nullptr, 0, 0, &func);
}

void PDSFire::constructor(Point _position, int _destinationSpace, Pointf _destination)
{
	typedef void (*custom_arg_funcptr_t)(PDSFire *this_arg, Point _position_arg, int _destinationSpace_arg, Pointf _destination_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func747::func;
	return execfunc(this, _position, _destinationSpace, _destination);
}

namespace _func748
{
	static void *func = 0;
	static FunctionDefinition funcObj("PDSFire::OnUpdate", typeid(void (PDSFire::*)()), "!.554889e54156534883ec104889fbe82d", nullptr, 0, 0, &func);
}

void PDSFire::OnUpdate()
{
	typedef void (*custom_arg_funcptr_t)(PDSFire *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func748::func;
	return execfunc(this);
}

namespace _func749
{
	static void *func = 0;
	static FunctionDefinition funcObj("PDSFire::CollisionCheck", typeid(void (PDSFire::*)(Collideable *)), ".554889e54156534881ec800000004889f34989fe", nullptr, 0, 0, &func);
}

void PDSFire::CollisionCheck(Collideable *other)
{
	typedef void (*custom_arg_funcptr_t)(PDSFire *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func749::func;
	return execfunc(this, other);
}

namespace _func750
{
	static void *func = 0;
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), ".554889e58b0f29f1", nullptr, 0, 0, &func);
}

int Point::RelativeDistance(Point other)
{
	typedef int (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func750::func;
	return execfunc(this, other);
}

namespace _func751
{
	static void *func = 0;
	static FunctionDefinition funcObj("Point::Distance", typeid(int (Point::*)(Point )), ".554889e58b0729f0", nullptr, 0, 0, &func);
}

int Point::Distance(Point other)
{
	typedef int (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func751::func;
	return execfunc(this, other);
}

namespace _func752
{
	static void *func = 0;
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), ".554889e5f30f1107", nullptr, 0, 0, &func);
}

void Pointf::constructor(float _x, float _y)
{
	typedef void (*custom_arg_funcptr_t)(Pointf *this_arg, float _x_arg, float _y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func752::func;
	return execfunc(this, _x, _y);
}

namespace _func753
{
	static void *func = 0;
	static FunctionDefinition funcObj("Pointf::RelativeDistance", typeid(float (Pointf::*)(Pointf )), ".554889e5f20f100f0f5cc80f59c9f30f16c1f30f", nullptr, 0, 0, &func);
}

float Pointf::RelativeDistance(Pointf other)
{
	typedef float (*custom_arg_funcptr_t)(Pointf *this_arg, Pointf other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func753::func;
	return execfunc(this, other);
}

namespace _func754
{
	static void *func = 0;
	static FunctionDefinition funcObj("Pointf::Normalize", typeid(Pointf (Pointf::*)()), ".554889e5f30f7e0f", nullptr, 0, 0, &func);
}

Pointf Pointf::Normalize()
{
	typedef Pointf (*custom_arg_funcptr_t)(Pointf *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func754::func;
	return execfunc(this);
}

namespace _func755
{
	static void *func = 0;
	static FunctionDefinition funcObj("PowerManager::GetPowerManager", typeid(PowerManager *(*)(int )), "!.554889e54157415641554154534883ec184189fe", nullptr, 0, 0, &func);
}

PowerManager *PowerManager::GetPowerManager(int iShipId)
{
	typedef PowerManager *(*custom_arg_funcptr_t)(int iShipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func755::func;
	return execfunc(iShipId);
}

namespace _func756
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::ValidTarget", typeid(bool (Projectile::*)()), "554889e580bfc4020000000f94c05dc3", nullptr, 0, 0, &func);
}

bool Projectile::ValidTarget()
{
	typedef bool (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func756::func;
	return execfunc(this);
}

namespace _func757
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::ForceRenderLayer", typeid(int (Projectile::*)()), ".554889e5b8ffffffff5d", nullptr, 0, 0, &func);
}

int Projectile::ForceRenderLayer()
{
	typedef int (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func757::func;
	return execfunc(this);
}

namespace _func758
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::constructor", typeid(void (Projectile::*)(Pointf , int , int , Pointf )), ".554889e54157415641554154534881ec????????4889fbc74310????????66c74314", nullptr, 0, 0, &func);
}

void Projectile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
	typedef void (*custom_arg_funcptr_t)(Projectile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func758::func;
	return execfunc(this, _position, _ownerId, _targetId, _target);
}

namespace _func759
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::CollisionCheck", typeid(void (Projectile::*)(Collideable *)), ".554889e54157415641554154534881ecc80000004989f549", nullptr, 0, 0, &func);
}

void Projectile::CollisionCheck(Collideable *other)
{
	typedef void (*custom_arg_funcptr_t)(Projectile *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func759::func;
	return execfunc(this, other);
}

namespace _func760
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::Initialize", typeid(void (Projectile::*)(const WeaponBlueprint &)), ".554889e5415741564154534881ec700100004989f6", nullptr, 0, 0, &func);
}

void Projectile::Initialize(const WeaponBlueprint &bp)
{
	typedef void (*custom_arg_funcptr_t)(Projectile *this_arg, const WeaponBlueprint &bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func760::func;
	return execfunc(this, bp);
}

namespace _func761
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::CollisionMoving", typeid(CollisionResponse (Projectile::*)(Pointf , Pointf , Damage , bool )), ".554889e54156534883ec104989f64889fb0f134d", nullptr, 0, 0, &func);
}

CollisionResponse Projectile::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(Projectile *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func761::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func762
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::OnUpdate", typeid(void (Projectile::*)()), ".554889e5534883ec284889fb80bbc400", nullptr, 0, 0, &func);
}

void Projectile::OnUpdate()
{
	typedef void (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func762::func;
	return execfunc(this);
}

namespace _func763
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::RandomSidePoint", typeid(Pointf (*)(int )), ".554889e5535089fb488d7df0", nullptr, 0, 0, &func);
}

Pointf Projectile::RandomSidePoint(int side)
{
	typedef Pointf (*custom_arg_funcptr_t)(int side_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func763::func;
	return execfunc(side);
}

namespace _func764
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::DO_NOT_HOOK_FALSE_DESTRUCTOR", typeid(void (Projectile::*)()), "!.554889e553504889fb488d05????????66480f6ec0", nullptr, 0, 0, &func);
}

namespace _func765
{
	static void *func = 0;
	static FunctionDefinition funcObj("Projectile::destructor", typeid(void (Projectile::*)()), "!.554889e553504889fb488d05????????66480f6ec0", nullptr, 0, 0, &func);
}

void Projectile::destructor()
{
	typedef void (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func765::func;
	return execfunc(this);
}

namespace _func766
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::constructor", typeid(void (ProjectileFactory::*)(const WeaponBlueprint *, int )), "554889e54157415641554154534881ec????????4989f64889fb", nullptr, 0, 0, &func);
}

void ProjectileFactory::constructor(const WeaponBlueprint *_blueprint, int _ownerId)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, const WeaponBlueprint *_blueprint_arg, int _ownerId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func766::func;
	return execfunc(this, _blueprint, _ownerId);
}

namespace _func767
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(void (ProjectileFactory::*)()), ".554889e553504889fb488d05e0????0080380074", nullptr, 0, 0, &func);
}

void ProjectileFactory::SelectChargeGoal()
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func767::func;
	return execfunc(this);
}

namespace _func768
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::IsChargedGoal", typeid(bool (ProjectileFactory::*)()), ".554889e5488b472083b834020000007e", nullptr, 0, 0, &func);
}

bool ProjectileFactory::IsChargedGoal()
{
	typedef bool (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func768::func;
	return execfunc(this);
}

namespace _func769
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::SetHacked", typeid(void (ProjectileFactory::*)(int )), "!.554889e589b75407", nullptr, 0, 0, &func);
}

void ProjectileFactory::SetHacked(int hacked)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, int hacked_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func769::func;
	return execfunc(this, hacked);
}

namespace _func770
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::SetCurrentShip", typeid(void (ProjectileFactory::*)(Targetable *)), ".554889e54885f674154839b7", nullptr, 0, 0, &func);
}

void ProjectileFactory::SetCurrentShip(Targetable *ship)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, Targetable *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func770::func;
	return execfunc(this, ship);
}

namespace _func771
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), ".554889e5f30f104f0cf30f5e", nullptr, 0, 0, &func);
}

void ProjectileFactory::SetCooldownModifier(float mod)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float mod_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func771::func;
	return execfunc(this, mod);
}

namespace _func772
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(void (ProjectileFactory::*)()), ".554889e553504889fb80bb22", nullptr, 0, 0, &func);
}

void ProjectileFactory::ForceCoolup()
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func772::func;
	return execfunc(this);
}

namespace _func773
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(void (ProjectileFactory::*)(float )), "!.554889e54881c798", nullptr, 0, 0, &func);
}

void ProjectileFactory::RenderChargeBar(float alpha)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func773::func;
	return execfunc(this, alpha);
}

namespace _func774
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::OnRender", typeid(void (ProjectileFactory::*)(float , bool )), "!.554889e553504889fb4881c398010000", nullptr, 0, 0, &func);
}

void ProjectileFactory::OnRender(float alpha, bool forceVisual)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float alpha_arg, bool forceVisual_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func774::func;
	return execfunc(this, alpha, forceVisual);
}

namespace _func775
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::Fire", typeid(void (ProjectileFactory::*)(std::vector<Pointf> &, int )), ".554889e54157415653504189d64989f74889fb48", nullptr, 0, 0, &func);
}

void ProjectileFactory::Fire(std::vector<Pointf> &points, int target)
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, std::vector<Pointf> &points_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func775::func;
	return execfunc(this, points, target);
}

namespace _func776
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), ".554889e5488b472083b834020000027c", nullptr, 0, 0, &func);
}

int ProjectileFactory::NumTargetsRequired()
{
	typedef int (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func776::func;
	return execfunc(this);
}

namespace _func777
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::ClearAiming", typeid(void (ProjectileFactory::*)()), ".554889e5488b8728010000488b8f3001", nullptr, 0, 0, &func);
}

void ProjectileFactory::ClearAiming()
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func777::func;
	return execfunc(this);
}

namespace _func778
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::ClearProjectiles", typeid(void (ProjectileFactory::*)()), ".554889e5488b87180700004889872007", nullptr, 0, 0, &func);
}

void ProjectileFactory::ClearProjectiles()
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func778::func;
	return execfunc(this);
}

namespace _func779
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::FireNextShot", typeid(bool (ProjectileFactory::*)()), ".554889e583bf50070000007e1f80bf22", nullptr, 0, 0, &func);
}

bool ProjectileFactory::FireNextShot()
{
	typedef bool (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func779::func;
	return execfunc(this);
}

namespace _func780
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(const std::string &)), ".554889e553504889fb488d35????2a00", nullptr, 0, 0, &func);
}

int ProjectileFactory::StringToWeapon(const std::string &str)
{
	typedef int (*custom_arg_funcptr_t)(const std::string &str_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func780::func;
	return execfunc(str);
}

namespace _func781
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::GetProjectile", typeid(Projectile *(ProjectileFactory::*)()), ".554889e541574156534883ec384889fb488dbb98", nullptr, 0, 0, &func);
}

Projectile *ProjectileFactory::GetProjectile()
{
	typedef Projectile *(*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func781::func;
	return execfunc(this);
}

namespace _func782
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::SpendMissiles", typeid(int (ProjectileFactory::*)()), ".554889e54156534883ec204889fb83bb38070000", nullptr, 0, 0, &func);
}

int ProjectileFactory::SpendMissiles()
{
	typedef int (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func782::func;
	return execfunc(this);
}

namespace _func783
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::Update", typeid(void (ProjectileFactory::*)()), "!.554889e54157415641554154534881ecf8010000", nullptr, 0, 0, &func);
}

void ProjectileFactory::Update()
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func783::func;
	return execfunc(this);
}

namespace _func784
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::SaveProjectile", typeid(void (*)(Projectile *, int )), ".554889e54156534189f64889fb488b03ff90f800", nullptr, 0, 0, &func);
}

void ProjectileFactory::SaveProjectile(Projectile *p, int fd)
{
	typedef void (*custom_arg_funcptr_t)(Projectile *p_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func784::func;
	return execfunc(p, fd);
}

namespace _func785
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::LoadProjectile", typeid(Projectile *(*)(int )), ".554889e54156534883ec604189fee8", nullptr, 0, 0, &func);
}

Projectile *ProjectileFactory::LoadProjectile(int fd)
{
	typedef Projectile *(*custom_arg_funcptr_t)(int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func785::func;
	return execfunc(fd);
}

namespace _func786
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::DO_NOT_HOOK_FALSE_DESTRUCTOR", typeid(void (ProjectileFactory::*)()), "!.554889e553504889fb488d05????310048890348", nullptr, 0, 0, &func);
}

namespace _func787
{
	static void *func = 0;
	static FunctionDefinition funcObj("ProjectileFactory::destructor", typeid(void (ProjectileFactory::*)()), "!.554889e553504889fb488d05????310048890348", nullptr, 0, 0, &func);
}

void ProjectileFactory::destructor()
{
	typedef void (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func787::func;
	return execfunc(this);
}

namespace _func788
{
	static void *func = 0;
	static FunctionDefinition funcObj("ReactorButton::Accept", typeid(void (ReactorButton::*)()), ".554889e54156534883ec204989fe4183", nullptr, 0, 0, &func);
}

void ReactorButton::Accept()
{
	typedef void (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func788::func;
	return execfunc(this);
}

namespace _func789
{
	static void *func = 0;
	static FunctionDefinition funcObj("ReactorButton::OnRender", typeid(void (ReactorButton::*)()), ".554889e54157415641554154534881ecb80000004989fee8", nullptr, 0, 0, &func);
}

void ReactorButton::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func789::func;
	return execfunc(this);
}

namespace _func790
{
	static void *func = 0;
	static FunctionDefinition funcObj("ReactorButton::OnClick", typeid(void (ReactorButton::*)()), ".554889e541574156534883ec184989ff498bbf90", nullptr, 0, 0, &func);
}

void ReactorButton::OnClick()
{
	typedef void (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func790::func;
	return execfunc(this);
}

namespace _func791
{
	static void *func = 0;
	static FunctionDefinition funcObj("ReactorButton::OnRightClick", typeid(void (ReactorButton::*)()), ".554889e54156534883ec204889fb83bb8c000000", nullptr, 0, 0, &func);
}

void ReactorButton::OnRightClick()
{
	typedef void (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func791::func;
	return execfunc(this);
}

void **VTable_RepairAnimation;

namespace _var792
{
	static VariableDefinition varObj("VTable_RepairAnimation", "!4489eee87c91fffff645b0017409488b7dc0e8????????488d05(???????\?)4883c010488903", &VTable_RepairAnimation, true, true);
}

namespace _func793
{
	static void *func = 0;
	static FunctionDefinition funcObj("RepairStoreBox::constructor", typeid(void (RepairStoreBox::*)(ShipManager *, bool , int )), ".554889e54157415641554154534881ec????????89cb4189d7", nullptr, 0, 0, &func);
}

void RepairStoreBox::constructor(ShipManager *_ship, bool _repairAll, int _price)
{
	typedef void (*custom_arg_funcptr_t)(RepairStoreBox *this_arg, ShipManager *_ship_arg, bool _repairAll_arg, int _price_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func793::func;
	return execfunc(this, _ship, _repairAll, _price);
}

ResourceControl *Global_ResourceControl_GlobalResources;

namespace _var794
{
	static VariableDefinition varObj("Global_ResourceControl_GlobalResources", "!4881ecb80000004889fb488d3d(???????\?)31f6e8", &Global_ResourceControl_GlobalResources, true, true);
}

namespace _func795
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (ResourceControl::*)()), ".554889e548c747180000000048c747100000000048c747080000000048c70700000000c7", nullptr, 0, 0, &func);
}

namespace _func796
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::constructor", typeid(void (ResourceControl::*)()), ".554889e548c747180000000048c747100000000048c747080000000048c70700000000c7", nullptr, 0, 0, &func);
}

void ResourceControl::constructor()
{
	typedef void (*custom_arg_funcptr_t)(ResourceControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func796::func;
	return execfunc(this);
}

namespace _func797
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(freetype::font_data &(ResourceControl::*)(int , bool )), ".554889e541574156534883ec284189f7", nullptr, 0, 0, &func);
}

freetype::font_data &ResourceControl::GetFontData(int fontType, bool ignoreLangauge)
{
	typedef freetype::font_data &(*custom_arg_funcptr_t)(ResourceControl *this_arg, int fontType_arg, bool ignoreLangauge_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func797::func;
	return execfunc(this, fontType, ignoreLangauge);
}

namespace _func798
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(GL_Texture *(ResourceControl::*)(const std::string &)), ".554889e5415741564154534883ec704989f44989", nullptr, 0, 0, &func);
}

GL_Texture *ResourceControl::GetImageId(const std::string &dir)
{
	typedef GL_Texture *(*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func798::func;
	return execfunc(this, dir);
}

namespace _func799
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::GetImageData", typeid(ImageDesc (ResourceControl::*)(GL_Texture *)), ".554889e54156534883ec104889f34989fe488955", nullptr, 0, 0, &func);
}

ImageDesc ResourceControl::GetImageData(GL_Texture *tex)
{
	typedef ImageDesc (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func799::func;
	return execfunc(this, tex);
}

namespace _func800
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::ImageExists", typeid(bool (ResourceControl::*)(const std::string &)), ".554889e54156534883ec204889f04889", nullptr, 0, 0, &func);
}

bool ResourceControl::ImageExists(const std::string &name)
{
	typedef bool (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func800::func;
	return execfunc(this, name);
}

namespace _func801
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::RenderImage", typeid(int (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), ".0f28f20f", nullptr, 0, 0, &func);
}

int ResourceControl::RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func801::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func802
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::RenderImageString", typeid(int (ResourceControl::*)(std::string &, int , int , int , GL_Color , float , bool )), ".554889e5415741564154534883ec", nullptr, 0, 0, &func);
}

int ResourceControl::RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int (*custom_arg_funcptr_t)(ResourceControl *this_arg, std::string &tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func802::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func803
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitive", typeid(GL_Primitive *(ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "!.554889e50f28f20f", nullptr, 0, 0, &func);
}

GL_Primitive *ResourceControl::CreateImagePrimitive(GL_Texture *image, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *image_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float alpha_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func803::func;
	return execfunc(this, image, x, y, rotation, color, alpha, mirror);
}

namespace _func804
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitiveString", typeid(GL_Primitive *(ResourceControl::*)(const std::string &, int , int , int , GL_Color , float , bool )), "!.554889e5415741564154534883ec", nullptr, 0, 0, &func);
}

GL_Primitive *ResourceControl::CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)
{
	typedef GL_Primitive *(*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float alpha_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func804::func;
	return execfunc(this, tex, x, y, rotation, color, alpha, mirror);
}

namespace _func805
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::PreloadResources", typeid(bool (ResourceControl::*)(bool )), "!.554889e54157415641554154534881ecc800000089b530ff", nullptr, 0, 0, &func);
}

bool ResourceControl::PreloadResources(bool preloadPlayerShips)
{
	typedef bool (*custom_arg_funcptr_t)(ResourceControl *this_arg, bool preloadPlayerShips_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func805::func;
	return execfunc(this, preloadPlayerShips);
}

namespace _func806
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::OnInit", typeid(void (ResourceControl::*)(int )), "!.554889e553504889fb89b398", nullptr, 0, 0, &func);
}

void ResourceControl::OnInit(int imageSwappingMode)
{
	typedef void (*custom_arg_funcptr_t)(ResourceControl *this_arg, int imageSwappingMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func806::func;
	return execfunc(this, imageSwappingMode);
}

namespace _func807
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::RenderLoadingBar", typeid(void (ResourceControl::*)(float , float )), ".554889e54156534883ec504989fe4983", nullptr, 0, 0, &func);
}

void ResourceControl::RenderLoadingBar(float initialProgress, float finalProgress)
{
	typedef void (*custom_arg_funcptr_t)(ResourceControl *this_arg, float initialProgress_arg, float finalProgress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func807::func;
	return execfunc(this, initialProgress, finalProgress);
}

namespace _func808
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::LoadFile", typeid(char *(ResourceControl::*)(const std::string &)), ".554889e54883ec10488d55fc", nullptr, 0, 0, &func);
}

char *ResourceControl::LoadFile(const std::string &fileName)
{
	typedef char *(*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func808::func;
	return execfunc(this, fileName);
}

namespace _func809
{
	static void *func = 0;
	static FunctionDefinition funcObj("ResourceControl::LoadFromResourceFile", typeid(char *(ResourceControl::*)(const std::string &, std::size_t &, const std::string *)), ".554889e5415741564155415453504989d74989fc", nullptr, 0, 0, &func);
}

char *ResourceControl::LoadFromResourceFile(const std::string &fileName, std::size_t &fileSize, const std::string *unused_resourceFile)
{
	typedef char *(*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &fileName_arg, std::size_t &fileSize_arg, const std::string *unused_resourceFile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func809::func;
	return execfunc(this, fileName, fileSize, unused_resourceFile);
}

namespace _func810
{
	static void *func = 0;
	static FunctionDefinition funcObj("RockAnimation::constructor", typeid(void (RockAnimation::*)(const std::string &, int , Pointf , bool )), "554889e54157415641554154534883ec??89cb0f294590", nullptr, 0, 0, &func);
}

void RockAnimation::constructor(const std::string &_subRace, int _iShipId, Pointf _position, bool _enemy)
{
	typedef void (*custom_arg_funcptr_t)(RockAnimation *this_arg, const std::string &_subRace_arg, int _iShipId_arg, Pointf _position_arg, bool _enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func810::func;
	return execfunc(this, _subRace, _iShipId, _position, _enemy);
}

namespace _func811
{
	static void *func = 0;
	static FunctionDefinition funcObj("RockAnimation::GetDeathSound", typeid(std::string (RockAnimation::*)()), ".554889e548c7070000000048c747080000000048c7471000000000c6071248b8726f636b", nullptr, 0, 0, &func);
}

std::string RockAnimation::GetDeathSound()
{
	typedef std::string (*custom_arg_funcptr_t)(RockAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func811::func;
	return execfunc(this);
}

namespace _func812
{
	static void *func = 0;
	static FunctionDefinition funcObj("RockAnimation::GetShootingSound", typeid(std::string (RockAnimation::*)()), ".554889e54156534883", nullptr, 0, 0, &func);
}

std::string RockAnimation::GetShootingSound()
{
	typedef std::string (*custom_arg_funcptr_t)(RockAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func812::func;
	return execfunc(this);
}

namespace _func813
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::constructor", typeid(void (Room::*)(int , int , int , int , int , int )), "!.554889e54157415641554154534881ec????????4489cb4589c6", nullptr, 0, 0, &func);
}

void Room::constructor(int _iShipId, int _x, int _y, int _w, int _h, int _roomId)
{
	typedef void (*custom_arg_funcptr_t)(Room *this_arg, int _iShipId_arg, int _x_arg, int _y_arg, int _w_arg, int _h_arg, int _roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func813::func;
	return execfunc(this, _iShipId, _x, _y, _w, _h, _roomId);
}

namespace _func814
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::destructor", typeid(void (Room::*)()), "!.554889e54157415653504989fe488d05????????498906488d05????????49894610498bbec0000000", nullptr, 0, 0, &func);
}

void Room::destructor()
{
	typedef void (*custom_arg_funcptr_t)(Room *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func814::func;
	return execfunc(this);
}

namespace _func815
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::GetEmptySlots", typeid(int (Room::*)(bool )), ".554889e5400fb6ce", nullptr, 0, 0, &func);
}

int Room::GetEmptySlots(bool intruder)
{
	typedef int (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func815::func;
	return execfunc(this, intruder);
}

namespace _func816
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::Full", typeid(bool (Room::*)(bool )), ".554889e5400fb6c6488b4f38488b5750", nullptr, 0, 0, &func);
}

bool Room::Full(bool intruder)
{
	typedef bool (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func816::func;
	return execfunc(this, intruder);
}

namespace _func817
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::GetEmptySlot", typeid(int (Room::*)(bool )), ".554889e54084f67525486387", nullptr, 0, 0, &func);
}

int Room::GetEmptySlot(bool intruder)
{
	typedef int (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func817::func;
	return execfunc(this, intruder);
}

namespace _func818
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::FillSlot", typeid(void (Room::*)(int , bool )), ".554889e5440fb6c2488b47504863ce4b8d14404c8b0cd04889ce48c1ee06b80100000048d3e080e13f498b14f10fb6c9480fa3ca73025dc3", nullptr, 0, 0, &func);
}

void Room::FillSlot(int slot, bool intruder)
{
	typedef void (*custom_arg_funcptr_t)(Room *this_arg, int slot_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func818::func;
	return execfunc(this, slot, intruder);
}

namespace _func819
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::OnRenderFloor", typeid(void (Room::*)(float , bool )), "!.554889e5f30f100d????2400", nullptr, 0, 0, &func);
}

void Room::OnRenderFloor(float alpha, bool experimental)
{
	typedef void (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg, bool experimental_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func819::func;
	return execfunc(this, alpha, experimental);
}

namespace _func820
{
	static void *func = 0;
	static FunctionDefinition funcObj("Room::OnRenderWalls", typeid(void (Room::*)(float )), "!.554889e553504889fb807b68", nullptr, 0, 0, &func);
}

void Room::OnRenderWalls(float alpha)
{
	typedef void (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func820::func;
	return execfunc(this, alpha);
}

ScoreKeeper *Global_ScoreKeeper_Keeper;

namespace _var821
{
	static VariableDefinition varObj("Global_ScoreKeeper_Keeper", "!4889fbe8????????488b7b10e8????????0fb6f0488d3d(???????\?)", &Global_ScoreKeeper_Keeper, true, true);
}

namespace _func822
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::constructor", typeid(void (ScoreKeeper::*)()), ".554889e54157415641554154534883ec284889fb48c70300", nullptr, 0, 0, &func);
}

void ScoreKeeper::constructor()
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func822::func;
	return execfunc(this);
}

namespace _func823
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::WipeProfile", typeid(void (ScoreKeeper::*)(bool )), "!.554889e54157415641554154534883ec188975c4", nullptr, 0, 0, &func);
}

void ScoreKeeper::WipeProfile(bool permanent)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool permanent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func823::func;
	return execfunc(this, permanent);
}

namespace _func824
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::Save", typeid(void (ScoreKeeper::*)(bool )), ".554889e5415741564154534881eca000000089f3", nullptr, 0, 0, &func);
}

void ScoreKeeper::Save(bool newHighScore)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool newHighScore_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func824::func;
	return execfunc(this, newHighScore);
}

namespace _func825
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::GetShipId", typeid(std::pair<int, int> (ScoreKeeper::*)(const std::string &)), ".554889e54157415641554154534883ec384889f1", nullptr, 0, 0, &func);
}

std::pair<int, int> ScoreKeeper::GetShipId(const std::string &blueprintName)
{
	typedef std::pair<int, int> (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::string &blueprintName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func825::func;
	return execfunc(this, blueprintName);
}

namespace _func826
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::GetShipBlueprint", typeid(std::string (ScoreKeeper::*)(int )), ".554889e553504889fb4863c2488d0440", nullptr, 0, 0, &func);
}

std::string ScoreKeeper::GetShipBlueprint(int index)
{
	typedef std::string (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int index_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func826::func;
	return execfunc(this, index);
}

namespace _func827
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::SaveGame", typeid(void (ScoreKeeper::*)(int )), "!.554889e541565389f34989fe488d057d", nullptr, 0, 0, &func);
}

void ScoreKeeper::SaveGame(int fd)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func827::func;
	return execfunc(this, fd);
}

namespace _func828
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::LoadGame", typeid(void (ScoreKeeper::*)(int )), ".554889e5415741564154534881ec8001", nullptr, 0, 0, &func);
}

void ScoreKeeper::LoadGame(int fd)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func828::func;
	return execfunc(this, fd);
}

namespace _func829
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::RenderTopScores", typeid(void (ScoreKeeper::*)(const std::vector<TopScore> &, Point , int )), ".554889e54157415641554154534881ece8000000898d04ff", nullptr, 0, 0, &func);
}

void ScoreKeeper::RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::vector<TopScore> &topScoreList_arg, Point position_arg, int newHighScore_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func829::func;
	return execfunc(this, topScoreList, position, newHighScore);
}

namespace _func830
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::CheckTypes", typeid(void (ScoreKeeper::*)()), ".554889e5415741564154534883ec304889fb8bb3f00d0000", nullptr, 0, 0, &func);
}

void ScoreKeeper::CheckTypes()
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func830::func;
	return execfunc(this);
}

namespace _func831
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::GetShipUnlocked", typeid(bool (ScoreKeeper::*)(int , int )), "!.554889e54157415641554154534883ec684189d44189f648", nullptr, 0, 0, &func);
}

bool ScoreKeeper::GetShipUnlocked(int shipId, int shipVariant)
{
	typedef bool (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipId_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func831::func;
	return execfunc(this, shipId, shipVariant);
}

namespace _func832
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::SetupTopShip", typeid(void (ScoreKeeper::*)(int )), ".554889e54157415641554154534883ec484189f64989fd49", nullptr, 0, 0, &func);
}

void ScoreKeeper::SetupTopShip(int variant)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func832::func;
	return execfunc(this, variant);
}

namespace _func833
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::OnRender", typeid(void (ScoreKeeper::*)(bool )), "!.554889e54157415641554154534881ecd8020000", nullptr, 0, 0, &func);
}

void ScoreKeeper::OnRender(bool lastPlaythrough)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool lastPlaythrough_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func833::func;
	return execfunc(this, lastPlaythrough);
}

namespace _func834
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(void (ScoreKeeper::*)(int , int , bool , bool )), ".554889e54157415641554154534883ec4889cb41", nullptr, 0, 0, &func);
}

void ScoreKeeper::UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipType_arg, int shipVariant_arg, bool save_arg, bool hidePopup_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func834::func;
	return execfunc(this, shipType, shipVariant, save, hidePopup);
}

namespace _func835
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreType", typeid(void (ScoreKeeper::*)(TopScore &, int )), ".554889e54157415641554154534881ec080200004189d449", nullptr, 0, 0, &func);
}

void ScoreKeeper::AddTopScoreType(TopScore &topScore, int type)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, TopScore &topScore_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func835::func;
	return execfunc(this, topScore, type);
}

namespace _func836
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::CycleLeft", typeid(void (ScoreKeeper::*)()), "!.554889e54156534889fb41be", nullptr, 0, 0, &func);
}

void ScoreKeeper::CycleLeft()
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func836::func;
	return execfunc(this);
}

namespace _func837
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::CycleRight", typeid(void (ScoreKeeper::*)()), "!.554889e54156534889fb4531f60f1f00", nullptr, 0, 0, &func);
}

void ScoreKeeper::CycleRight()
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func837::func;
	return execfunc(this);
}

namespace _func838
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::MouseMove", typeid(void (ScoreKeeper::*)(int , int )), ".554889e5415741564155415453504189d74189f64989fd41", nullptr, 0, 0, &func);
}

void ScoreKeeper::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func838::func;
	return execfunc(this, mX, mY);
}

namespace _func839
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::MouseClick", typeid(void (ScoreKeeper::*)(int , int )), "!.554889e54156534889fb4c8db3000e00", nullptr, 0, 0, &func);
}

void ScoreKeeper::MouseClick(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func839::func;
	return execfunc(this, x, y);
}

namespace _func840
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::KeyDown", typeid(bool (ScoreKeeper::*)(SDLKey )), ".554889e54157415653504189f64889fb80bb580e", nullptr, 0, 0, &func);
}

bool ScoreKeeper::KeyDown(SDLKey key)
{
	typedef bool (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func840::func;
	return execfunc(this, key);
}

namespace _func841
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::Open", typeid(void (ScoreKeeper::*)(bool )), "!.554889e54157415641554154534881ec480200004989fd48", nullptr, 0, 0, &func);
}

void ScoreKeeper::Open(bool fromGameOver)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool fromGameOver_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func841::func;
	return execfunc(this, fromGameOver);
}

namespace _func842
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::OnInit", typeid(void (ScoreKeeper::*)()), "!.554889e54157415641554154534881ec380100004989fc48", nullptr, 0, 0, &func);
}

void ScoreKeeper::OnInit()
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func842::func;
	return execfunc(this);
}

namespace _func843
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::LoadVersionFour", typeid(void (ScoreKeeper::*)(int , int )), ".554889e54157415641554154534881ece800000089d34189", nullptr, 0, 0, &func);
}

void ScoreKeeper::LoadVersionFour(int file, int version)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int file_arg, int version_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func843::func;
	return execfunc(this, file, version);
}

namespace _func844
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreList", typeid(int (ScoreKeeper::*)(TopScore &, std::vector<TopScore> &)), ".554889e5415741564155415453504989d64989f7498b364d", nullptr, 0, 0, &func);
}

int ScoreKeeper::AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList)
{
	typedef int (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, TopScore &score_arg, std::vector<TopScore> &topScoreList_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func844::func;
	return execfunc(this, score, topScoreList);
}

namespace _func845
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::SetSector", typeid(void (ScoreKeeper::*)(int )), ".554889e5c7472800", nullptr, 0, 0, &func);
}

void ScoreKeeper::SetSector(int sector)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func845::func;
	return execfunc(this, sector);
}

namespace _func846
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::SetVictory", typeid(void (ScoreKeeper::*)(bool )), ".554889e54088b7e8", nullptr, 0, 0, &func);
}

void ScoreKeeper::SetVictory(bool victory)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool victory_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func846::func;
	return execfunc(this, victory);
}

namespace _func847
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::AddScrapCollected", typeid(void (ScoreKeeper::*)(int )), ".554889e54156534883ec204189f64889fb488d3d", nullptr, 0, 0, &func);
}

void ScoreKeeper::AddScrapCollected(int scrap)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int scrap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func847::func;
	return execfunc(this, scrap);
}

namespace _func848
{
	static void *func = 0;
	static FunctionDefinition funcObj("ScoreKeeper::SaveScores", typeid(void (ScoreKeeper::*)(int , std::vector<TopScore> &)), ".554889e54157415641554154534883ec584189f5", nullptr, 0, 0, &func);
}

void ScoreKeeper::SaveScores(int file, std::vector<TopScore> &topScores)
{
	typedef void (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int file_arg, std::vector<TopScore> &topScores_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func848::func;
	return execfunc(this, file, topScores);
}

SettingValues *Global_Settings_Settings;

namespace _var849
{
	static VariableDefinition varObj("Global_Settings_Settings", "!.31d283f8020f4ed18915(???????\?)", &Global_Settings_Settings, true, true);
}

namespace _func850
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::GetDlcEnabled", typeid(bool (*)()), "803d??????0000741455", nullptr, 0, 0, &func);
}

bool Settings::GetDlcEnabled()
{
	typedef bool (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func850::func;
	return execfunc();
}

namespace _func851
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::ResetHotkeys", typeid(void (*)()), ".554889e54156534881ec8009", nullptr, 0, 0, &func);
}

void Settings::ResetHotkeys()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func851::func;
	return execfunc();
}

namespace _func852
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::GetHotkeyName", typeid(std::string (*)(const std::string &)), ".554889e54157415641554154534883ec684989ff488d9d78", nullptr, 0, 0, &func);
}

std::string Settings::GetHotkeyName(const std::string &name)
{
	typedef std::string (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func852::func;
	return execfunc(name);
}

namespace _func853
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::GetHotkey", typeid(SDLKey (*)(const std::string &)), ".554889e54157415641554154534883ec2848897db8488d47", nullptr, 0, 0, &func);
}

SDLKey Settings::GetHotkey(const std::string &hotkeyName)
{
	typedef SDLKey (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func853::func;
	return execfunc(hotkeyName);
}

namespace _func854
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::SetHotkey", typeid(void (*)(const std::string &, SDLKey )), ".554889e54157415641554154534883ec684189f5", nullptr, 0, 0, &func);
}

void Settings::SetHotkey(const std::string &hotkeyName, SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func854::func;
	return execfunc(hotkeyName, key);
}

namespace _func855
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::SaveSettings", typeid(void (*)()), ".554889e54157415641554154534881ec58010000488dbdf0", nullptr, 0, 0, &func);
}

void Settings::SaveSettings()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func855::func;
	return execfunc();
}

namespace _func856
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(char (*)()), ".554889e58a05????????5d", nullptr, 0, 0, &func);
}

char Settings::GetCommandConsole()
{
	typedef char (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func856::func;
	return execfunc();
}

namespace _func857
{
	static void *func = 0;
	static FunctionDefinition funcObj("Settings::LoadSettings", typeid(void (*)()), "!.554889e54157415641554154534881ec18020000488b05", nullptr, 0, 0, &func);
}

void Settings::LoadSettings()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func857::func;
	return execfunc();
}

namespace _func858
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::constructor", typeid(void (Shields::*)(int , int , int , const std::string &)), ".554889e5415741564154534883ec??4d89c6", nullptr, 0, 0, &func);
}

void Shields::constructor(int _roomId, int _shipId, int _startingPower, const std::string &_shieldFile)
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg, int _roomId_arg, int _shipId_arg, int _startingPower_arg, const std::string &_shieldFile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func858::func;
	return execfunc(this, _roomId, _shipId, _startingPower, _shieldFile);
}

namespace _func859
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::AddSuperShield", typeid(void (Shields::*)(Point )), ".554889e54157415653504989f64889fb8b839802", nullptr, 0, 0, &func);
}

void Shields::AddSuperShield(Point position)
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func859::func;
	return execfunc(this, position);
}

namespace _func860
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::Jump", typeid(void (Shields::*)()), ".554889e54156534883ec204889fbe83d", nullptr, 0, 0, &func);
}

void Shields::Jump()
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func860::func;
	return execfunc(this);
}

namespace _func861
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::SetBaseEllipse", typeid(void (Shields::*)(Globals::Ellipse )), ".554889e5f30f118778020000", nullptr, 0, 0, &func);
}

void Shields::SetBaseEllipse(Globals::Ellipse ellipse)
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg, Globals::Ellipse ellipse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func861::func;
	return execfunc(this, ellipse);
}

namespace _func862
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::InstantCharge", typeid(void (Shields::*)()), ".554889e541574156534883ec184989ffe8cb5d00", nullptr, 0, 0, &func);
}

void Shields::InstantCharge()
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func862::func;
	return execfunc(this);
}

namespace _func863
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::CollisionReal", typeid(CollisionResponse (Shields::*)(float , float , Damage , bool )), ".554889e5534883ec384889fb8b454089", nullptr, 0, 0, &func);
}

CollisionResponse Shields::CollisionReal(float x, float y, Damage damage, bool force)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(Shields *this_arg, float x_arg, float y_arg, Damage damage_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func863::func;
	return execfunc(this, x, y, damage, force);
}

namespace _func864
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::CollisionTest", typeid(CollisionResponse (Shields::*)(float , float , Damage )), ".554889e54156534883ec10f30f114de8", nullptr, 0, 0, &func);
}

CollisionResponse Shields::CollisionTest(float x, float y, Damage damage)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(Shields *this_arg, float x_arg, float y_arg, Damage damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func864::func;
	return execfunc(this, x, y, damage);
}

namespace _func865
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::OnLoop", typeid(void (Shields::*)()), ".554889e54157415641554154534883ec684989fde8776500", nullptr, 0, 0, &func);
}

void Shields::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func865::func;
	return execfunc(this);
}

namespace _func866
{
	static void *func = 0;
	static FunctionDefinition funcObj("Shields::RenderBase", typeid(void (Shields::*)(float , float )), "!.554889e54156534883ec300f294dc048", nullptr, 0, 0, &func);
}

void Shields::RenderBase(float alpha, float superShieldOverwrite)
{
	typedef void (*custom_arg_funcptr_t)(Shields *this_arg, float alpha_arg, float superShieldOverwrite_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func866::func;
	return execfunc(this, alpha, superShieldOverwrite);
}

namespace _func867
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnInit", typeid(void (Ship::*)(ShipBlueprint *)), "!554889e54157415641554154534881ec88030100", nullptr, 0, 0, &func);
}

void Ship::OnInit(ShipBlueprint *bp)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, ShipBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func867::func;
	return execfunc(this, bp);
}

namespace _noop868
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_1", "!.39cf4c89cb7f04(c6041301)");
}

namespace _noop869
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_2", "!.39c7488d9da6fdfeff7f04(c6041301)");
}

namespace _noop870
{
	static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_3", "!.39c7488d9da6fdfeff7f04(c6041301)");
}

namespace _func871
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnLoop", typeid(void (Ship::*)(std::vector<float> &)), ".554889e54157415641554154534883ec284989f64989ff498d9ff004", nullptr, 0, 0, &func);
}

void Ship::OnLoop(std::vector<float> &oxygenLevels)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, std::vector<float> &oxygenLevels_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func871::func;
	return execfunc(this, oxygenLevels);
}

namespace _func872
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::RoomLocked", typeid(bool (Ship::*)(int )), ".554889e5488b871805000048", nullptr, 0, 0, &func);
}

bool Ship::RoomLocked(int roomId)
{
	typedef bool (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func872::func;
	return execfunc(this, roomId);
}

namespace _func873
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::LockdownRoom", typeid(void (Ship::*)(int , Pointf )), ".554889e54157415641554154534881ec980100000f294580", nullptr, 0, 0, &func);
}

void Ship::LockdownRoom(int roomId, Pointf position)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, Pointf position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func873::func;
	return execfunc(this, roomId, position);
}

namespace _func874
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnRenderJump", typeid(void (Ship::*)(float )), "!.554889e541574156534883ec18f30f1145e44889", nullptr, 0, 0, &func);
}

void Ship::OnRenderJump(float progress)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func874::func;
	return execfunc(this, progress);
}

namespace _func875
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnRenderBase", typeid(void (Ship::*)(bool )), "!.554889e5415741564155415453504189f64889fb", nullptr, 0, 0, &func);
}

void Ship::OnRenderBase(bool engineWorking)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, bool engineWorking_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func875::func;
	return execfunc(this, engineWorking);
}

namespace _func876
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnRenderFloor", typeid(void (Ship::*)(bool )), "!.554889e54157415653504189f64989ff4180bf10", nullptr, 0, 0, &func);
}

void Ship::OnRenderFloor(bool forceView)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, bool forceView_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func876::func;
	return execfunc(this, forceView);
}

namespace _func877
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnRenderSparks", typeid(void (Ship::*)()), ".554889e54156534989fe498b461049394618742dbb0100000031c90f1f440000488b3cc8e83715ff", nullptr, 0, 0, &func);
}

void Ship::OnRenderSparks()
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func877::func;
	return execfunc(this);
}

namespace _func878
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnRenderBreaches", typeid(void (Ship::*)()), ".554889e54157415653504989fe498b464049394648744cbb", nullptr, 0, 0, &func);
}

void Ship::OnRenderBreaches()
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func878::func;
	return execfunc(this);
}

namespace _func879
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::OnRenderWalls", typeid(void (Ship::*)(bool , bool )), ".554889e54157415641554154534883ec184189d78975d449", nullptr, 0, 0, &func);
}

void Ship::OnRenderWalls(bool forceView, bool doorControlMode)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, bool forceView_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func879::func;
	return execfunc(this, forceView, doorControlMode);
}

namespace _func880
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::BreachSpecificHull", typeid(void (Ship::*)(int , int )), ".554889e54157415641554154534883ec284189d74189f44889fb", nullptr, 0, 0, &func);
}

void Ship::BreachSpecificHull(int grid_x, int grid_y)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, int grid_x_arg, int grid_y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func880::func;
	return execfunc(this, grid_x, grid_y);
}

namespace _func881
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::_GetSelectedRoomId_DO_NOT_CALL", typeid(int (Ship::*)(Point , bool )), "!.554889e54157415653504189d64989f74c89fb48c1eb208b7f08", nullptr, 0, 0, &func);
}

int Ship::_GetSelectedRoomId_DO_NOT_CALL(Point _position, bool _bIncludeWalls)
{
	typedef int (*custom_arg_funcptr_t)(Ship *this_arg, Point _position_arg, bool _bIncludeWalls_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func881::func;
	return execfunc(this, _position, _bIncludeWalls);
}

namespace _func882
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::BreachRandomHull", typeid(void (Ship::*)(int )), "!.554889e54157415641554154534883ec688975cc", nullptr, 0, 0, &func);
}

void Ship::BreachRandomHull(int roomId)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func882::func;
	return execfunc(this, roomId);
}

namespace _func883
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::GetHullBreaches", typeid(std::vector<Repairable*> (Ship::*)(bool )), "!.554889e54157415641554154534883ec184989f74989fd49", nullptr, 0, 0, &func);
}

std::vector<Repairable*> Ship::GetHullBreaches(bool onlyDamaged)
{
	typedef std::vector<Repairable*> (*custom_arg_funcptr_t)(Ship *this_arg, bool onlyDamaged_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func883::func;
	return execfunc(this, onlyDamaged);
}

namespace _func884
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::SetSelectedRoom", typeid(void (Ship::*)(int )), ".554889e54157415653504189f64989ff498b4710", nullptr, 0, 0, &func);
}

void Ship::SetSelectedRoom(int roomId)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func884::func;
	return execfunc(this, roomId);
}

namespace _func885
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::SetRoomBlackout", typeid(void (Ship::*)(int , bool )), "!.554889e54863c6488b4f10488b3cc10fb6f2", nullptr, 0, 0, &func);
}

void Ship::SetRoomBlackout(int roomId, bool blackout)
{
	typedef void (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool blackout_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func885::func;
	return execfunc(this, roomId, blackout);
}

namespace _func886
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::GetAvailableRoomSlot", typeid(int (Ship::*)(int , bool )), "!.554889e54863c6488b4f10488b3cc10fb6f2", nullptr, 0, 0, &func);
}

int Ship::GetAvailableRoomSlot(int roomId, bool intruder)
{
	typedef int (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func886::func;
	return execfunc(this, roomId, intruder);
}

namespace _func887
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::EmptySlots", typeid(int (Ship::*)(int )), ".554889e54157415653504989fe4c63fe", nullptr, 0, 0, &func);
}

int Ship::EmptySlots(int roomId)
{
	typedef int (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func887::func;
	return execfunc(this, roomId);
}

namespace _func888
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::FullRoom", typeid(bool (Ship::*)(int , bool )), "!.554889e585f67823", nullptr, 0, 0, &func);
}

bool Ship::FullRoom(int roomId, bool intruder)
{
	typedef bool (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func888::func;
	return execfunc(this, roomId, intruder);
}

namespace _func889
{
	static void *func = 0;
	static FunctionDefinition funcObj("Ship::GetAvailableRoom", typeid(int (Ship::*)(int , bool )), "!.554889e54157415641554154534883ec2889d341", nullptr, 0, 0, &func);
}

int Ship::GetAvailableRoom(int preferred, bool intruder)
{
	typedef int (*custom_arg_funcptr_t)(Ship *this_arg, int preferred_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func889::func;
	return execfunc(this, preferred, intruder);
}

namespace _func890
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipAI::constructor", typeid(void (ShipAI::*)(bool )), ".554889e54156534189f64889fb48c74308", nullptr, 0, 0, &func);
}

void ShipAI::constructor(bool _player)
{
	typedef void (*custom_arg_funcptr_t)(ShipAI *this_arg, bool _player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func890::func;
	return execfunc(this, _player);
}

namespace _func891
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), ".554889e54084f6741280bf70", nullptr, 0, 0, &func);
}

void ShipAI::SetStalemate(bool stalemate)
{
	typedef void (*custom_arg_funcptr_t)(ShipAI *this_arg, bool stalemate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func891::func;
	return execfunc(this, stalemate);
}

namespace _func892
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipAI::GetTeleportCommand", typeid(std::pair<int, int> (ShipAI::*)()), ".554889e54156534889fb49be", nullptr, 0, 0, &func);
}

std::pair<int, int> ShipAI::GetTeleportCommand()
{
	typedef std::pair<int, int> (*custom_arg_funcptr_t)(ShipAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func892::func;
	return execfunc(this);
}

namespace _func893
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipAI::OnLoop", typeid(void (ShipAI::*)(bool )), "!.554889e541574156534883ec2889f349", nullptr, 0, 0, &func);
}

void ShipAI::OnLoop(bool hostile)
{
	typedef void (*custom_arg_funcptr_t)(ShipAI *this_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func893::func;
	return execfunc(this, hostile);
}

namespace _func894
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBlueprint::destructor", typeid(void (ShipBlueprint::*)()), "!554889e54157415653504989fe488d05????????49890641f686", nullptr, 0, 0, &func);
}

void ShipBlueprint::destructor()
{
	typedef void (*custom_arg_funcptr_t)(ShipBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func894::func;
	return execfunc(this);
}

namespace _func895
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::constructor", typeid(void (ShipBuilder::*)()), ".554889e54156534883ec204889fb488d7b", nullptr, 0, 0, &func);
}

void ShipBuilder::constructor()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func895::func;
	return execfunc(this);
}

namespace _func896
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::OnRender", typeid(void (ShipBuilder::*)()), ".554889e54157415641554154534883ec584989fe4180be08", nullptr, 0, 0, &func);
}

void ShipBuilder::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func896::func;
	return execfunc(this);
}

namespace _func897
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::OnLoop", typeid(void (ShipBuilder::*)()), ".554889e5415741564154534883ec604989fc488d", nullptr, 0, 0, &func);
}

void ShipBuilder::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func897::func;
	return execfunc(this);
}

namespace _func898
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(void (ShipBuilder::*)()), "!.554889e54157415641554154534881ec08060000", nullptr, 0, 0, &func);
}

void ShipBuilder::Open()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func898::func;
	return execfunc(this);
}

namespace _func899
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(void (ShipBuilder::*)()), ".554889e5415741564154534883ec304889fb8bb380140000", nullptr, 0, 0, &func);
}

void ShipBuilder::CheckTypes()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func899::func;
	return execfunc(this);
}

namespace _func900
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::CreateEquipmentBoxes", typeid(void (ShipBuilder::*)()), "!.554889e54157415641554154534883ec684989fe498d86e8", nullptr, 0, 0, &func);
}

void ShipBuilder::CreateEquipmentBoxes()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func900::func;
	return execfunc(this);
}

namespace _func901
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::CreateSystemBoxes", typeid(void (ShipBuilder::*)()), "!.554889e54157415641554154534883ec284989ff498b8768", nullptr, 0, 0, &func);
}

void ShipBuilder::CreateSystemBoxes()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func901::func;
	return execfunc(this);
}

namespace _func902
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::SetupShipAchievements", typeid(void (ShipBuilder::*)()), "!.554889e54157415641554154534883ec684889fb488b8308", nullptr, 0, 0, &func);
}

void ShipBuilder::SetupShipAchievements()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func902::func;
	return execfunc(this);
}

namespace _func903
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::MouseMove", typeid(void (ShipBuilder::*)(int , int )), ".554889e54157415641554154534881ec98040000", nullptr, 0, 0, &func);
}

void ShipBuilder::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func903::func;
	return execfunc(this, mX, mY);
}

namespace _func904
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::MouseClick", typeid(void (ShipBuilder::*)(int , int )), "!.554889e54157415641554154534883ec384989fd4180bdb0", nullptr, 0, 0, &func);
}

void ShipBuilder::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func904::func;
	return execfunc(this, mX, mY);
}

namespace _func905
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(void (ShipBuilder::*)(int , int )), ".554889e5415741564154534883ec204189d44189", nullptr, 0, 0, &func);
}

void ShipBuilder::SwitchShip(int shipType, int shipVariant)
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int shipType_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func905::func;
	return execfunc(this, shipType, shipVariant);
}

namespace _func906
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::CycleShipPrevious", typeid(void (ShipBuilder::*)()), "!.554889e553504889fb488b3b4885ff7406488b07ff50084889dfe811", nullptr, 0, 0, &func);
}

void ShipBuilder::CycleShipPrevious()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func906::func;
	return execfunc(this);
}

namespace _func907
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::CycleShipNext", typeid(void (ShipBuilder::*)()), "!.554889e553504889fb488b3b4885ff7406488b07ff50084889dfe841", nullptr, 0, 0, &func);
}

void ShipBuilder::CycleShipNext()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func907::func;
	return execfunc(this);
}

namespace _func908
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(void (ShipBuilder::*)(int )), "!.554889e54156534189f64889fb488b3b4885ff74", nullptr, 0, 0, &func);
}

void ShipBuilder::SwapType(int variant)
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func908::func;
	return execfunc(this, variant);
}

namespace _func909
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::OnKeyDown", typeid(void (ShipBuilder::*)(SDLKey )), "!.554889e54157415641554154535089f34989fe41", nullptr, 0, 0, &func);
}

void ShipBuilder::OnKeyDown(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func909::func;
	return execfunc(this, key);
}

namespace _func910
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipBuilder::ClearShipAchievements", typeid(void (ShipBuilder::*)()), ".554889e5488b870822000048", nullptr, 0, 0, &func);
}

void ShipBuilder::ClearShipAchievements()
{
	typedef void (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func910::func;
	return execfunc(this);
}

namespace _func911
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipButton::constructor", typeid(void (ShipButton::*)(int , int )), "554889e54157415641554154534883ec??89d34189f6", nullptr, 0, 0, &func);
}

void ShipButton::constructor(int _shipId, int _type)
{
	typedef void (*custom_arg_funcptr_t)(ShipButton *this_arg, int _shipId_arg, int _type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func911::func;
	return execfunc(this, _shipId, _type);
}

namespace _func912
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipButton::OnInit", typeid(void (ShipButton::*)(const std::string &, Point )), ".554889e553504889fb4889d0", nullptr, 0, 0, &func);
}

void ShipButton::OnInit(const std::string &imgName, Point position)
{
	typedef void (*custom_arg_funcptr_t)(ShipButton *this_arg, const std::string &imgName_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func912::func;
	return execfunc(this, imgName, position);
}

namespace _func913
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipButton::MouseMove", typeid(void (ShipButton::*)(int , int )), "!.554889e5415741564155415453504189f64989fd41c785b8", nullptr, 0, 0, &func);
}

void ShipButton::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(ShipButton *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func913::func;
	return execfunc(this, x, y);
}

namespace _func914
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipButton::OnRender", typeid(void (ShipButton::*)()), ".554889e541574156534883ec384989ff4180bf98", nullptr, 0, 0, &func);
}

void ShipButton::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ShipButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func914::func;
	return execfunc(this);
}

namespace _func915
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipEvent::constructor", typeid(void (ShipEvent::*)(const ShipEvent &)), "!.554889e5415741564155415453504989f64989ff418a06", nullptr, 0, 0, &func);
}

void ShipEvent::constructor(const ShipEvent &_event)
{
	typedef void (*custom_arg_funcptr_t)(ShipEvent *this_arg, const ShipEvent &_event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func915::func;
	return execfunc(this, _event);
}

namespace _func916
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::CreateShip", typeid(ShipManager *(*)(const std::string &, int , ShipEvent &)), "!.554889e54157415641554154534881ec88070000", nullptr, 0, 0, &func);
}

ShipManager *ShipGenerator::CreateShip(const std::string &name, int sector, ShipEvent &event)
{
	typedef ShipManager *(*custom_arg_funcptr_t)(const std::string &name_arg, int sector_arg, ShipEvent &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func916::func;
	return execfunc(name, sector, event);
}

namespace _func917
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::GenerateSystemMaxes", typeid(std::vector<int> (*)(const ShipBlueprint &, int )), "!.554889e54157415641554154534883ec284989f64989fc49", nullptr, 0, 0, &func);
}

std::vector<int> ShipGenerator::GenerateSystemMaxes(const ShipBlueprint &ship, int level)
{
	typedef std::vector<int> (*custom_arg_funcptr_t)(const ShipBlueprint &ship_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func917::func;
	return execfunc(ship, level);
}

namespace _func918
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::UpgradeSystem", typeid(bool (*)(ShipManager *, std::vector<int> &, unsigned int )), "!.554889e54157415641554154534883ec5889d348", nullptr, 0, 0, &func);
}

bool ShipGenerator::UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, unsigned int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func918::func;
	return execfunc(ship, systemMaxes, sysId);
}

namespace _func919
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "!.554889e54157415641554154534881ec9800000048895590", nullptr, 0, 0, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func919::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func920
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleWeaponList", typeid(std::vector<WeaponBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int )), "!.554889e54157415641554154534881ec880000004589c649", nullptr, 0, 0, &func);
}

std::vector<WeaponBlueprint*> ShipGenerator::GetPossibleWeaponList(ShipManager *ship, const std::string &weaponList, int scrap, unsigned int flags)
{
	typedef std::vector<WeaponBlueprint*> (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &weaponList_arg, int scrap_arg, unsigned int flags_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func920::func;
	return execfunc(ship, weaponList, scrap, flags);
}

namespace _func921
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleDroneList", typeid(std::vector<DroneBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int , bool )), "!.554889e54157415641554154534881ecb80000004589cc44", nullptr, 0, 0, &func);
}

std::vector<DroneBlueprint*> ShipGenerator::GetPossibleDroneList(ShipManager *ship, const std::string &droneList, int scrap, unsigned int flags, bool repeat)
{
	typedef std::vector<DroneBlueprint*> (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &droneList_arg, int scrap_arg, unsigned int flags_arg, bool repeat_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func921::func;
	return execfunc(ship, droneList, scrap, flags, repeat);
}

namespace _func922
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleCrewList", typeid(std::vector<CrewBlueprint> (*)(ShipManager *, const std::string &, unsigned int )), ".554889e54157415641554154534881ecc80100004989d649", nullptr, 0, 0, &func);
}

std::vector<CrewBlueprint> ShipGenerator::GetPossibleCrewList(ShipManager *ship, const std::string &crewList, unsigned int flags)
{
	typedef std::vector<CrewBlueprint> (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &crewList_arg, unsigned int flags_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func922::func;
	return execfunc(ship, crewList, flags);
}

namespace _func923
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetShipInfo", typeid(ShipGraph *(*)(int )), "554889e541574156534881ec9800000089fb488b", nullptr, 0, 0, &func);
}

ShipGraph *ShipGraph::GetShipInfo(int shipId)
{
	typedef ShipGraph *(*custom_arg_funcptr_t)(int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func923::func;
	return execfunc(shipId);
}

namespace _func924
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetSlotWorldPosition", typeid(Point (ShipGraph::*)(int , int )), ".554889e5534883ec1889f348", nullptr, 0, 0, &func);
}

Point ShipGraph::GetSlotWorldPosition(int slotId, int roomId)
{
	typedef Point (*custom_arg_funcptr_t)(ShipGraph *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func924::func;
	return execfunc(this, slotId, roomId);
}

namespace _func925
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetSlotRenderPosition", typeid(Point (ShipGraph::*)(int , int , bool )), ".554889e5415741564154534883ec204189ce4189f74889fb", nullptr, 0, 0, &func);
}

Point ShipGraph::GetSlotRenderPosition(int slotId, int roomId, bool intruder)
{
	typedef Point (*custom_arg_funcptr_t)(ShipGraph *this_arg, int slotId_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func925::func;
	return execfunc(this, slotId, roomId, intruder);
}

namespace _func926
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(int , int , int , int )), ".554889e54157415641554154534883ec??4589c6", nullptr, 0, 0, &func);
}

int ShipGraph::ConnectedGridSquares(int x1, int y1, int x2, int y2)
{
	typedef int (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x1_arg, int y1_arg, int x2_arg, int y2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func926::func;
	return execfunc(this, x1, y1, x2, y2);
}

namespace _func927
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), ".554889e5415741564155415453508955d44189f4", nullptr, 0, 0, &func);
}

int ShipGraph::GetSelectedRoom(int x, int y, bool bIncludeWalls)
{
	typedef int (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg, bool bIncludeWalls_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func927::func;
	return execfunc(this, x, y, bIncludeWalls);
}

namespace _func928
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(int , int , int , int )), ".554889e54157415641554154534883ec??4589c44189cd4189d6", nullptr, 0, 0, &func);
}

Door *ShipGraph::ConnectingDoor(int x1, int y1, int x2, int y2)
{
	typedef Door *(*custom_arg_funcptr_t)(ShipGraph *this_arg, int x1_arg, int y1_arg, int x2_arg, int y2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func928::func;
	return execfunc(this, x1, y1, x2, y2);
}

namespace _func929
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::IsRoomConnected", typeid(bool (ShipGraph::*)(int , int )), ".554889e5415741564154534883ec204189d64189f44889f8", nullptr, 0, 0, &func);
}

bool ShipGraph::IsRoomConnected(int room1, int room2)
{
	typedef bool (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room1_arg, int room2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func929::func;
	return execfunc(this, room1, room2);
}

namespace _func930
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(std::vector<Door*> (ShipGraph::*)(int )), "!.554889e54157415641554154534883ec284189d54889f34989fe49c7", nullptr, 0, 0, &func);
}

std::vector<Door*> ShipGraph::GetDoors(int roomId)
{
	typedef std::vector<Door*> (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func930::func;
	return execfunc(this, roomId);
}

namespace _func931
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), ".554889e531c085f67819488b", nullptr, 0, 0, &func);
}

int ShipGraph::DoorCount(int roomId)
{
	typedef int (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func931::func;
	return execfunc(this, roomId);
}

namespace _func932
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), ".554889e54863c6488b0f488b", nullptr, 0, 0, &func);
}

int ShipGraph::GetNumSlots(int room)
{
	typedef int (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func932::func;
	return execfunc(this, room);
}

namespace _func933
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetClosestSlot", typeid(Slot (ShipGraph::*)(Point , int , bool )), ".554889e54157415641554154534881ec880000004189cc89", nullptr, 0, 0, &func);
}

Slot ShipGraph::GetClosestSlot(Point position, int shipId, bool intruder)
{
	typedef Slot (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point position_arg, int shipId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func933::func;
	return execfunc(this, position, shipId, intruder);
}

namespace _func934
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(Path (ShipGraph::*)(Point , Point , int )), ".554889e54157415641554154534883ec584589c4", nullptr, 0, 0, &func);
}

Path ShipGraph::FindPath(Point p1, Point p2, int shipId)
{
	typedef Path (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func934::func;
	return execfunc(this, p1, p2, shipId);
}

namespace _func935
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::Dijkstra", typeid(Path (ShipGraph::*)(Point , Point , int )), "!.554889e54157415641554154534881ec38010000448945b0", nullptr, 0, 0, &func);
}

Path ShipGraph::Dijkstra(Point start, Point goal, int shipId)
{
	typedef Path (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point start_arg, Point goal_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func935::func;
	return execfunc(this, start, goal, shipId);
}

namespace _func936
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::PopClosestDoor", typeid(int (ShipGraph::*)(std::vector<int> &, std::vector<float> &)), ".554889e5415741564155415453504889d04989f6", nullptr, 0, 0, &func);
}

int ShipGraph::PopClosestDoor(std::vector<int> &doors, std::vector<float> &distances)
{
	typedef int (*custom_arg_funcptr_t)(ShipGraph *this_arg, std::vector<int> &doors_arg, std::vector<float> &distances_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func936::func;
	return execfunc(this, doors, distances);
}

namespace _func937
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldAngle", typeid(float (ShipGraph::*)(float )), ".554889e5f30f5847", nullptr, 0, 0, &func);
}

float ShipGraph::ConvertToWorldAngle(float ang)
{
	typedef float (*custom_arg_funcptr_t)(ShipGraph *this_arg, float ang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func937::func;
	return execfunc(this, ang);
}

namespace _func938
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalAngle", typeid(float (ShipGraph::*)(float )), ".554889e5f30f5c47", nullptr, 0, 0, &func);
}

float ShipGraph::ConvertToLocalAngle(float ang)
{
	typedef float (*custom_arg_funcptr_t)(ShipGraph *this_arg, float ang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func938::func;
	return execfunc(this, ang);
}

namespace _func939
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldPosition", typeid(Pointf (ShipGraph::*)(Pointf )), ".554889e553504889fb0f1345", nullptr, 0, 0, &func);
}

Pointf ShipGraph::ConvertToWorldPosition(Pointf local)
{
	typedef Pointf (*custom_arg_funcptr_t)(ShipGraph *this_arg, Pointf local_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func939::func;
	return execfunc(this, local);
}

namespace _func940
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalPosition", typeid(Pointf (ShipGraph::*)(Pointf , bool )), ".554889e54883ec104c8d4f50", nullptr, 0, 0, &func);
}

Pointf ShipGraph::ConvertToLocalPosition(Pointf world, bool past)
{
	typedef Pointf (*custom_arg_funcptr_t)(ShipGraph *this_arg, Pointf world_arg, bool past_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func940::func;
	return execfunc(this, world, past);
}

namespace _func941
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(void (ShipGraph::*)()), ".554889e54157415641554154534883ec28488b07", nullptr, 0, 0, &func);
}

void ShipGraph::ComputeCenter()
{
	typedef void (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func941::func;
	return execfunc(this);
}

namespace _func942
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::ContainsPoint", typeid(bool (ShipGraph::*)(int , int )), ".554889e58b476839", nullptr, 0, 0, &func);
}

bool ShipGraph::ContainsPoint(int x, int y)
{
	typedef bool (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func942::func;
	return execfunc(this, x, y);
}

namespace _func943
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), ".554889e5488b4708482b0748", nullptr, 0, 0, &func);
}

int ShipGraph::RoomCount()
{
	typedef int (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func943::func;
	return execfunc(this);
}

namespace _func944
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetRoomOxygen", typeid(float (ShipGraph::*)(int )), ".554889e50f57c085f67821488b07488b", nullptr, 0, 0, &func);
}

float ShipGraph::GetRoomOxygen(int room)
{
	typedef float (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func944::func;
	return execfunc(this, room);
}

namespace _func945
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), ".554889e5b00185f6", nullptr, 0, 0, &func);
}

bool ShipGraph::GetRoomBlackedOut(int room)
{
	typedef bool (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func945::func;
	return execfunc(this, room);
}

namespace _func946
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), ".554889e5415741564154534883ec104989f74989", nullptr, 0, 0, &func);
}

bool ShipInfo::HasAugmentation(const std::string &augId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func946::func;
	return execfunc(this, augId);
}

namespace _func947
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), ".554889e54157415641554154534883ec284989f64989fc41", nullptr, 0, 0, &func);
}

bool ShipInfo::AddAugmentation(const std::string &augId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func947::func;
	return execfunc(this, augId);
}

namespace _func948
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipInfo::GetAugmentationValue", typeid(float (ShipInfo::*)(const std::string &)), ".554889e541574156534883ec584989f7", nullptr, 0, 0, &func);
}

float ShipInfo::GetAugmentationValue(const std::string &augId)
{
	typedef float (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func948::func;
	return execfunc(this, augId);
}

namespace _func949
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::constructor", typeid(int (ShipManager::*)(int )), "554889e54156534883ec204189f64889fb44897308", nullptr, 0, 0, &func);
}

int ShipManager::constructor(int _shipId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int _shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func949::func;
	return execfunc(this, _shipId);
}

namespace _func950
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::destructor", typeid(void (ShipManager::*)()), "!.554889e5415741564155415453504989fd488d05", nullptr, 0, 0, &func);
}

void ShipManager::destructor()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func950::func;
	return execfunc(this);
}

namespace _func951
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(bool (ShipManager::*)(int )), ".554889e5b00183fe", nullptr, 0, 0, &func);
}

bool ShipManager::HasSystem(int systemId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func951::func;
	return execfunc(this, systemId);
}

namespace _func952
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::RestoreCrewPositions", typeid(bool (ShipManager::*)()), "!.554889e54157415641554154534883ec580f57c0", nullptr, 0, 0, &func);
}

bool ShipManager::RestoreCrewPositions()
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func952::func;
	return execfunc(this);
}

namespace _func953
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddSystem", typeid(int (ShipManager::*)(int )), "!.554889e54157415641554154534881eca801000089f34c8b", nullptr, 0, 0, &func);
}

int ShipManager::AddSystem(int systemId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func953::func;
	return execfunc(this, systemId);
}

namespace _func954
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::InstantPowerShields", typeid(void (ShipManager::*)()), "!.554889e553504889fb488b83d80600008b0083f8", nullptr, 0, 0, &func);
}

void ShipManager::InstantPowerShields()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func954::func;
	return execfunc(this);
}

namespace _func955
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(int (ShipManager::*)()), ".554889e54157415641554154534883ec184989fc498b9c24", nullptr, 0, 0, &func);
}

int ShipManager::CreateSystems()
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func955::func;
	return execfunc(this);
}

namespace _func956
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddWeapon", typeid(int (ShipManager::*)(const WeaponBlueprint *, int )), "!.554889e5488b87d806000083780cff740d488bbf880000005de9????170031c0", nullptr, 0, 0, &func);
}

int ShipManager::AddWeapon(const WeaponBlueprint *bp, int slot)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, const WeaponBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func956::func;
	return execfunc(this, bp, slot);
}

namespace _func957
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(Drone *(ShipManager::*)(const DroneBlueprint *, int )), ".554889e5415741564154534189d64989f44989ff", nullptr, 0, 0, &func);
}

Drone *ShipManager::AddDrone(const DroneBlueprint *bp, int slot)
{
	typedef Drone *(*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func957::func;
	return execfunc(this, bp, slot);
}

namespace _func958
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CanFitSystem", typeid(bool (ShipManager::*)(int )), ".554889e54157415653504989fe83fe0d", nullptr, 0, 0, &func);
}

bool ShipManager::CanFitSystem(int systemId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func958::func;
	return execfunc(this, systemId);
}

namespace _func959
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CanFitSubsystem", typeid(bool (ShipManager::*)(int )), ".554889e54157415653504989fe498b4e", nullptr, 0, 0, &func);
}

bool ShipManager::CanFitSubsystem(int systemId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func959::func;
	return execfunc(this, systemId);
}

namespace _func960
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddInitialCrew", typeid(void (ShipManager::*)(std::vector<CrewBlueprint> &)), "!.554889e54157415641554154534881ec680300004889f349", nullptr, 0, 0, &func);
}

void ShipManager::AddInitialCrew(std::vector<CrewBlueprint> &blueprints)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, std::vector<CrewBlueprint> &blueprints_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func960::func;
	return execfunc(this, blueprints);
}

namespace _func961
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetSystemRoom", typeid(int (ShipManager::*)(int )), ".554889e583feff742b4863c6", nullptr, 0, 0, &func);
}

int ShipManager::GetSystemRoom(int sysId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func961::func;
	return execfunc(this, sysId);
}

namespace _func962
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromBlueprint", typeid(CrewMember *(ShipManager::*)(CrewBlueprint *, int , bool , int , bool )), "!.554889e54157415641554154534881ec????????44894dd0", nullptr, 0, 0, &func);
}

CrewMember *ShipManager::AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(ShipManager *this_arg, CrewBlueprint *bp_arg, int slot_arg, bool init_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func962::func;
	return execfunc(this, bp, slot, init, roomId, intruder);
}

namespace _func963
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::OnInit", typeid(int (ShipManager::*)(ShipBlueprint *, int )), "!.554889e54157415641554154534883ec6889d349", nullptr, 0, 0, &func);
}

int ShipManager::OnInit(ShipBlueprint *bp, int shipLevel)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, ShipBlueprint *bp_arg, int shipLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func963::func;
	return execfunc(this, bp, shipLevel);
}

namespace _func964
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(void (ShipManager::*)()), ".554889e5c787f006", nullptr, 0, 0, &func);
}

void ShipManager::ResetScrapLevel()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func964::func;
	return execfunc(this);
}

namespace _func965
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(void (ShipManager::*)()), "!.554889e54157415641554154534881ec88030000", nullptr, 0, 0, &func);
}

void ShipManager::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func965::func;
	return execfunc(this);
}

namespace _func966
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(void (ShipManager::*)(CrewMember *, int )), "!.554889e54157415641554154534883ec184189d74989f6", nullptr, 0, 0, &func);
}

void ShipManager::AddCrewMember(CrewMember *crew, int roomId)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func966::func;
	return execfunc(this, crew, roomId);
}

namespace _func967
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DamageHull", typeid(int (ShipManager::*)(int , bool )), ".554889e54157415653504189d74189f64889fb488b03ff90", nullptr, 0, 0, &func);
}

int ShipManager::DamageHull(int dmg, bool force)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int dmg_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func967::func;
	return execfunc(this, dmg, force);
}

namespace _func968
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(void (ShipManager::*)(int , bool )), ".554889e541574156534883ec6889f349", nullptr, 0, 0, &func);
}

void ShipManager::ModifyScrapCount(int scrap, bool income)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int scrap_arg, bool income_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func968::func;
	return execfunc(this, scrap, income);
}

namespace _func969
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::IsCloaked", typeid(bool (ShipManager::*)()), ".554889e5488b87d8060000837828ff7410488b47", nullptr, 0, 0, &func);
}

bool ShipManager::IsCloaked()
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func969::func;
	return execfunc(this);
}

namespace _func970
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetLeavingCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(bool )), "!.554889e54157415641554154534883ec284189d54889f34989ff49c7", nullptr, 0, 0, &func);
}

std::vector<CrewMember*> ShipManager::GetLeavingCrew(bool intruders)
{
	typedef std::vector<CrewMember*> (*custom_arg_funcptr_t)(ShipManager *this_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func970::func;
	return execfunc(this, intruders);
}

namespace _func971
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(int , bool )), "!.554889e54157415641554154534883ec384189ce", nullptr, 0, 0, &func);
}

std::vector<CrewMember*> ShipManager::TeleportCrew(int roomId, bool intruders)
{
	typedef std::vector<CrewMember*> (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func971::func;
	return execfunc(this, roomId, intruders);
}

namespace _func972
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetCrewmember", typeid(CrewMember *(ShipManager::*)(int , bool )), ".554889e5415741564155415453504189f74989fc", nullptr, 0, 0, &func);
}

CrewMember *ShipManager::GetCrewmember(int slot, bool present)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(ShipManager *this_arg, int slot_arg, bool present_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func972::func;
	return execfunc(this, slot, present);
}

namespace _func973
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromString", typeid(CrewMember *(ShipManager::*)(const std::string &, const std::string &, bool , int , bool , bool )), ".554889e54157415641554154534881ec????????44894dcc", nullptr, 0, 0, &func);
}

CrewMember *ShipManager::AddCrewMemberFromString(const std::string &name, const std::string &race, bool intruder, int roomId, bool init, bool male)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(ShipManager *this_arg, const std::string &name_arg, const std::string &race_arg, bool intruder_arg, int roomId_arg, bool init_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func973::func;
	return execfunc(this, name, race, intruder, roomId, init, male);
}

namespace _func974
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::SelectRandomCrew", typeid(CrewBlueprint (ShipManager::*)(int , const std::string &)), "!.554889e54157415641554154534883ec784989ce", nullptr, 0, 0, &func);
}

CrewBlueprint ShipManager::SelectRandomCrew(int seed, const std::string &racePref)
{
	typedef CrewBlueprint (*custom_arg_funcptr_t)(ShipManager *this_arg, int seed_arg, const std::string &racePref_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func974::func;
	return execfunc(this, seed, racePref);
}

namespace _func975
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::FindCrew", typeid(CrewMember *(ShipManager::*)(const CrewBlueprint *)), ".554889e54157415641554154534883ec484889f30f57c00f", nullptr, 0, 0, &func);
}

CrewMember *ShipManager::FindCrew(const CrewBlueprint *bp)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(ShipManager *this_arg, const CrewBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func975::func;
	return execfunc(this, bp);
}

namespace _func976
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::UpdateCrewMembers", typeid(void (ShipManager::*)()), "!.554889e54157415641554154534881ec????????4989fe498b", nullptr, 0, 0, &func);
}

void ShipManager::UpdateCrewMembers()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func976::func;
	return execfunc(this);
}

namespace _func977
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::Restart", typeid(void (ShipManager::*)()), ".554889e54157415641554154534883ec384989fc41837c24", nullptr, 0, 0, &func);
}

void ShipManager::Restart()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func977::func;
	return execfunc(this);
}

namespace _func978
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CountPlayerCrew", typeid(int (ShipManager::*)()), ".554889e5415741564154534989fe498b86c00000004531ff", nullptr, 0, 0, &func);
}

int ShipManager::CountPlayerCrew()
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func978::func;
	return execfunc(this);
}

namespace _func979
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(bool )), ".554889e5415741564155415453504189f64989ff498b87c000000045", nullptr, 0, 0, &func);
}

int ShipManager::CountCrew(bool boarders)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, bool boarders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func979::func;
	return execfunc(this, boarders);
}

namespace _func980
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CountCrewShipId", typeid(int (ShipManager::*)(int , int )), ".554889e5415741564155415453504189d74989fc", nullptr, 0, 0, &func);
}

int ShipManager::CountCrewShipId(int roomId, int shipId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func980::func;
	return execfunc(this, roomId, shipId);
}

namespace _func981
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), ".554889e553504889fb31f6837b0800400f95c6488d3df6", nullptr, 0, 0, &func);
}

bool ShipManager::IsCrewOverFull()
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func981::func;
	return execfunc(this);
}

namespace _func982
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), ".554889e553504889fb31f6837b0800400f95c6488d3db6", nullptr, 0, 0, &func);
}

bool ShipManager::IsCrewFull()
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func982::func;
	return execfunc(this);
}

namespace _func983
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetFireCount", typeid(int (ShipManager::*)(int )), "!.554889e54881c7????????5de9", nullptr, 0, 0, &func);
}

int ShipManager::GetFireCount(int roomId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func983::func;
	return execfunc(this, roomId);
}

namespace _func984
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ModifyDroneCount", typeid(void (ShipManager::*)(int )), "!.554889e5488b87d8060000837810ff740d488bbf900000005de9????150031c003b7b80a", nullptr, 0, 0, &func);
}

void ShipManager::ModifyDroneCount(int drones)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int drones_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func984::func;
	return execfunc(this, drones);
}

namespace _func985
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), ".554889e54863c6488b8fd8060000486304814883f8ff740e488b4f28488b3cc15de9????1600b8ff", nullptr, 0, 0, &func);
}

int ShipManager::GetSystemPower(int systemId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func985::func;
	return execfunc(this, systemId);
}

namespace _func986
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), ".554889e583feff741e4863c6", nullptr, 0, 0, &func);
}

ShipSystem *ShipManager::GetSystem(int systemId)
{
	typedef ShipSystem *(*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func986::func;
	return execfunc(this, systemId);
}

namespace _func987
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), ".554889e54157415653504989ff498b8f", nullptr, 0, 0, &func);
}

int ShipManager::GetDodgeFactor()
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func987::func;
	return execfunc(this);
}

namespace _func988
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DoSensorsProvide", typeid(bool (ShipManager::*)(int )), ".554889e5488b87d806000048", nullptr, 0, 0, &func);
}

bool ShipManager::DoSensorsProvide(int vision)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, int vision_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func988::func;
	return execfunc(this, vision);
}

namespace _func989
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(void (ShipManager::*)()), ".554889e54157415641554154534881ec880000004989fc49", nullptr, 0, 0, &func);
}

void ShipManager::UpdateEnvironment()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func989::func;
	return execfunc(this);
}

namespace _func990
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CheckSpreadDamage", typeid(void (ShipManager::*)()), ".554889e54157415641554154534883ec384989fd498b4528", nullptr, 0, 0, &func);
}

void ShipManager::CheckSpreadDamage()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func990::func;
	return execfunc(this);
}

namespace _func991
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CheckVision", typeid(void (ShipManager::*)()), ".554889e54157415641554154534883ec284989ff498b87d8", nullptr, 0, 0, &func);
}

void ShipManager::CheckVision()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func991::func;
	return execfunc(this);
}

namespace _func992
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked", typeid(int (ShipManager::*)(int )), ".554889e583fe1175", nullptr, 0, 0, &func);
}

int ShipManager::IsSystemHacked(int systemId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func992::func;
	return execfunc(this, systemId);
}

namespace _func993
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DamageSystem", typeid(void (ShipManager::*)(int , Damage )), "!.554889e54157415641554154534883ec784189f44989fd8b", nullptr, 0, 0, &func);
}

void ShipManager::DamageSystem(int systemId, Damage damage)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, Damage damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func993::func;
	return execfunc(this, systemId, damage);
}

namespace _func994
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::SetDestroyed", typeid(void (ShipManager::*)()), "!.554889e54156534989fe41c6", nullptr, 0, 0, &func);
}

void ShipManager::SetDestroyed()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func994::func;
	return execfunc(this);
}

namespace _func995
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::JumpLeave", typeid(void (ShipManager::*)()), ".554889e5415741564154534883ec204989fe418b", nullptr, 0, 0, &func);
}

void ShipManager::JumpLeave()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func995::func;
	return execfunc(this);
}

namespace _func996
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::Wait", typeid(void (ShipManager::*)()), ".554889e5415741564154534883ec104989fe498b", nullptr, 0, 0, &func);
}

void ShipManager::Wait()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func996::func;
	return execfunc(this);
}

namespace _func997
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::JumpArrive", typeid(void (ShipManager::*)()), ".554889e541574156534883ec284989fe498b86c0", nullptr, 0, 0, &func);
}

void ShipManager::JumpArrive()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func997::func;
	return execfunc(this);
}

namespace _func998
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::SystemFunctions", typeid(bool (ShipManager::*)(int )), ".554889e54863c6488b8fd8060000486304814883f8ff740f", nullptr, 0, 0, &func);
}

bool ShipManager::SystemFunctions(int systemId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func998::func;
	return execfunc(this, systemId);
}

namespace _func999
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetDodged", typeid(bool (ShipManager::*)()), ".554889e541574156534883ec184989ff41b60141", nullptr, 0, 0, &func);
}

bool ShipManager::GetDodged()
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func999::func;
	return execfunc(this);
}

namespace _func1000
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DoorsFunction", typeid(bool (ShipManager::*)()), ".554889e553504889fb488b83d806000048634020", nullptr, 0, 0, &func);
}

bool ShipManager::DoorsFunction()
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1000::func;
	return execfunc(this);
}

namespace _func1001
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DamageArea", typeid(bool (ShipManager::*)(Pointf , Damage , bool )), "!.554889e54157415641554154534881ec080100004189f649", nullptr, 0, 0, &func);
}

bool ShipManager::DamageArea(Pointf location, Damage dmg, bool forceHit)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf location_arg, Damage dmg_arg, bool forceHit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1001::func;
	return execfunc(this, location, dmg, forceHit);
}

namespace _func1002
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(bool (ShipManager::*)(CrewMember *, Damage )), ".554889e5415741564155415453504989f7488d4d", nullptr, 0, 0, &func);
}

bool ShipManager::DamageCrew(CrewMember *crew, Damage dmg)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1002::func;
	return execfunc(this, crew, dmg);
}

namespace _func1003
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), ".554889e5415741564155415453504189f74989fc498b442428", nullptr, 0, 0, &func);
}

ShipSystem *ShipManager::GetSystemInRoom(int roomId)
{
	typedef ShipSystem *(*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1003::func;
	return execfunc(this, roomId);
}

namespace _func1004
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CheckCrystalAugment", typeid(void (ShipManager::*)(Pointf )), "!.554889e54157415641554154534881ec980000000f298560", nullptr, 0, 0, &func);
}

void ShipManager::CheckCrystalAugment(Pointf position)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1004::func;
	return execfunc(this, position);
}

namespace _func1005
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::StartFire", typeid(void (ShipManager::*)(int )), "!.554889e54881c7d8000000ba", nullptr, 0, 0, &func);
}

void ShipManager::StartFire(int roomId)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1005::func;
	return execfunc(this, roomId);
}

namespace _func1006
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DamageBeam", typeid(bool (ShipManager::*)(Pointf , Pointf , Damage )), "!.554889e54157415641554154534881ec580100004889fb80", nullptr, 0, 0, &func);
}

bool ShipManager::DamageBeam(Pointf location1, Pointf location2, Damage dmg)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf location1_arg, Pointf location2_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1006::func;
	return execfunc(this, location1, location2, dmg);
}

namespace _func1007
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CollisionMoving", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), ".554889e54157415641554154534881ec180100004189d50f", nullptr, 0, 0, &func);
}

CollisionResponse ShipManager::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1007::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1008
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CollisionShield", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), "!.554889e54157415641554154534881ecd80000004189d70f", nullptr, 0, 0, &func);
}

CollisionResponse ShipManager::CollisionShield(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1008::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1009
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(void (ShipManager::*)()), "!.554889e54157415641554154534883ec584989fe498b8670", nullptr, 0, 0, &func);
}

void ShipManager::PrepareSuperDrones()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1009::func;
	return execfunc(this);
}

namespace _func1010
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::PrepareSuperBarrage", typeid(void (ShipManager::*)()), "!.554889e54157415641554154534881ec980000004989fe49", nullptr, 0, 0, &func);
}

void ShipManager::PrepareSuperBarrage()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1010::func;
	return execfunc(this);
}

namespace _func1011
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::RenderWeapons", typeid(void (ShipManager::*)()), "!.554889e54157415641554154534883ec684889fb4c8db318", nullptr, 0, 0, &func);
}

void ShipManager::RenderWeapons()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1011::func;
	return execfunc(this);
}

namespace _func1012
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::RenderChargeBars", typeid(void (ShipManager::*)()), "!.554889e54157415641554154534883ec384889fb837b0800", nullptr, 0, 0, &func);
}

void ShipManager::RenderChargeBars()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1012::func;
	return execfunc(this);
}

namespace _func1013
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(void (ShipManager::*)(bool , bool )), "!.554889e54157415641554154534881ecd80000004189d589", nullptr, 0, 0, &func);
}

void ShipManager::OnRender(bool showInterior, bool doorControlMode)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, bool showInterior_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1013::func;
	return execfunc(this, showInterior, doorControlMode);
}

namespace _func1014
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ClearStatusAll", typeid(void (ShipManager::*)()), "!.554889e54156534989fe498b46284939463074", nullptr, 0, 0, &func);
}

void ShipManager::ClearStatusAll()
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1014::func;
	return execfunc(this);
}

namespace _func1015
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ClearStatusSystem", typeid(void (ShipManager::*)(int )), "!.83fe??74??83fe??75??554889e5", nullptr, 0, 0, &func);
}

void ShipManager::ClearStatusSystem(int system)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1015::func;
	return execfunc(this, system);
}

namespace _func1016
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::DO_NOT_HOOK_SetSystemPowerLimit", typeid(void (ShipManager::*)()), "!.554889e5535089d3", nullptr, 0, 0, &func);
}

namespace _func1017
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLoss", typeid(void (ShipManager::*)(int , int )), "!.554889e5535089d3", nullptr, 0, 0, &func);
}

void ShipManager::SetSystemPowerLoss(int systemId, int powerLoss)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int powerLoss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1017::func;
	return execfunc(this, systemId, powerLoss);
}

namespace _func1018
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ForceDecreaseSystemPower", typeid(bool (ShipManager::*)(int )), "!.554889e583fe??74??4863c6488b8fd8060000", nullptr, 0, 0, &func);
}

bool ShipManager::ForceDecreaseSystemPower(int sys)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, int sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1018::func;
	return execfunc(this, sys);
}

namespace _func1019
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetShieldPower", typeid(ShieldPower (ShipManager::*)()), ".554889e5488b8f800000004885c97410", nullptr, 0, 0, &func);
}

ShieldPower ShipManager::GetShieldPower()
{
	typedef ShieldPower (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1019::func;
	return execfunc(this);
}

namespace _func1020
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetOxygenPercentage", typeid(int (ShipManager::*)()), ".488b87d8060000837808ff74", nullptr, 0, 0, &func);
}

int ShipManager::GetOxygenPercentage()
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1020::func;
	return execfunc(this);
}

namespace _func1021
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerMax", typeid(int (ShipManager::*)(int )), ".554889e54863c6488b8fd8060000486304814883f8ff740d", nullptr, 0, 0, &func);
}

int ShipManager::GetSystemPowerMax(int systemId)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1021::func;
	return execfunc(this, systemId);
}

namespace _func1022
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::UpgradeSystem", typeid(void (ShipManager::*)(int , int )), "!.554889e54157415653504189d789f34989fe83fb", nullptr, 0, 0, &func);
}

void ShipManager::UpgradeSystem(int id, int amount)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int id_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1022::func;
	return execfunc(this, id, amount);
}

namespace _func1023
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CanUpgrade", typeid(int (ShipManager::*)(int , int )), ".554889e5535089d383fe1175", nullptr, 0, 0, &func);
}

int ShipManager::CanUpgrade(int systemId, int amount)
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1023::func;
	return execfunc(this, systemId, amount);
}

namespace _func1024
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (ShipManager::*)(CrewMember *, int )), "!.554889e589d0baff", nullptr, 0, 0, &func);
}

bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int roomId)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1024::func;
	return execfunc(this, crew, roomId);
}

namespace _func1025
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrewPoint", typeid(CrewMember *(ShipManager::*)(int , int , bool )), ".554889e54157415641554154534883ec??894dc44189d7", nullptr, 0, 0, &func);
}

CrewMember *ShipManager::GetSelectedCrewPoint(int x, int y, bool intruder)
{
	typedef CrewMember *(*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1025::func;
	return execfunc(this, x, y, intruder);
}

namespace _func1026
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetTooltip", typeid(std::string (ShipManager::*)(int , int )), ".554889e54157415641554154534883ec584189cd", nullptr, 0, 0, &func);
}

std::string ShipManager::GetTooltip(int x, int y)
{
	typedef std::string (*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1026::func;
	return execfunc(this, x, y);
}

namespace _func1027
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(std::vector<ProjectileFactory*> (ShipManager::*)()), "!.554889e5415741564154534889fb488b86d80600", nullptr, 0, 0, &func);
}

std::vector<ProjectileFactory*> ShipManager::GetWeaponList()
{
	typedef std::vector<ProjectileFactory*> (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1027::func;
	return execfunc(this);
}

namespace _func1028
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetMissileCount", typeid(int (ShipManager::*)()), ".554889e5488b87d806000083780c??74??b8", nullptr, 0, 0, &func);
}

int ShipManager::GetMissileCount()
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1028::func;
	return execfunc(this);
}

namespace _func1029
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetDroneCount", typeid(int (ShipManager::*)()), ".554889e5488b87d8060000837810ff7410b88002", nullptr, 0, 0, &func);
}

int ShipManager::GetDroneCount()
{
	typedef int (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1029::func;
	return execfunc(this);
}

namespace _func1030
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ModifyMissileCount", typeid(void (ShipManager::*)(int )), "!.554889e5488b87d806000083780cff740d488bbf880000005de9????160031c003b7bc0a", nullptr, 0, 0, &func);
}

void ShipManager::ModifyMissileCount(int missiles)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int missiles_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1030::func;
	return execfunc(this, missiles);
}

namespace _func1031
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::RemoveItem", typeid(void (ShipManager::*)(const std::string &)), "!.554889e54157415641554154534883ec784989f64989fd48", nullptr, 0, 0, &func);
}

void ShipManager::RemoveItem(const std::string &name)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1031::func;
	return execfunc(this, name);
}

namespace _func1032
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(SpaceDrone *(ShipManager::*)(const DroneBlueprint *)), "!.554889e54157415641554154534883ec??4889f34989ff31c08b", nullptr, 0, 0, &func);
}

SpaceDrone *ShipManager::CreateSpaceDrone(const DroneBlueprint *bp)
{
	typedef SpaceDrone *(*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1032::func;
	return execfunc(this, bp);
}

namespace _func1033
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(CrewDrone *(ShipManager::*)(const DroneBlueprint *)), "!.554889e54157415641554154534883ec??4889f04889fb8b", nullptr, 0, 0, &func);
}

CrewDrone *ShipManager::CreateCrewDrone(const DroneBlueprint *bp)
{
	typedef CrewDrone *(*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1033::func;
	return execfunc(this, bp);
}

namespace _func1034
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::GetDroneList", typeid(std::vector<Drone*> (ShipManager::*)()), "!.554889e5415741564155415453504889fb488b86d8060000837810ff", nullptr, 0, 0, &func);
}

std::vector<Drone*> ShipManager::GetDroneList()
{
	typedef std::vector<Drone*> (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1034::func;
	return execfunc(this);
}

namespace _func1035
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::PowerDrone", typeid(bool (ShipManager::*)(Drone *, int , bool , bool )), ".554889e5415741564155415453504589c74189cc4889f349", nullptr, 0, 0, &func);
}

bool ShipManager::PowerDrone(Drone *drone, int roomId, bool userDriven, bool force)
{
	typedef bool (*custom_arg_funcptr_t)(ShipManager *this_arg, Drone *drone_arg, int roomId_arg, bool userDriven_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1035::func;
	return execfunc(this, drone, roomId, userDriven, force);
}

namespace _func1036
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::SaveToBlueprint", typeid(ShipBlueprint (ShipManager::*)(bool )), "!.554889e54157415641554154534883ec7889559c", nullptr, 0, 0, &func);
}

ShipBlueprint ShipManager::SaveToBlueprint(bool overwrite)
{
	typedef ShipBlueprint (*custom_arg_funcptr_t)(ShipManager *this_arg, bool overwrite_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1036::func;
	return execfunc(this, overwrite);
}

namespace _func1037
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ExportBattleState", typeid(void (ShipManager::*)(int )), "!.554889e54157415641554154534883ec284189f44989fe49", nullptr, 0, 0, &func);
}

void ShipManager::ExportBattleState(int file)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1037::func;
	return execfunc(this, file);
}

namespace _func1038
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ImportBattleState", typeid(void (ShipManager::*)(int )), "!.554889e54157415641554154534883ec384189f64989fc498b8424d8", nullptr, 0, 0, &func);
}

void ShipManager::ImportBattleState(int file)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1038::func;
	return execfunc(this, file);
}

namespace _func1039
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ExportShip", typeid(void (ShipManager::*)(int )), "!.554889e54157415641554154534881ec080200004189f649", nullptr, 0, 0, &func);
}

void ShipManager::ExportShip(int file)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1039::func;
	return execfunc(this, file);
}

namespace _func1040
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::ImportShip", typeid(void (ShipManager::*)(int )), "!.554889e54157415641554154534881ec88060000", nullptr, 0, 0, &func);
}

void ShipManager::ImportShip(int file)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1040::func;
	return execfunc(this, file);
}

namespace _func1041
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipManager::AddEquipmentFromList", typeid(void (ShipManager::*)(std::vector<std::string> *)), ".554889e54157415641554154534883ec684989f44989fe49", nullptr, 0, 0, &func);
}

void ShipManager::AddEquipmentFromList(std::vector<std::string> *equipmentList)
{
	typedef void (*custom_arg_funcptr_t)(ShipManager *this_arg, std::vector<std::string> *equipmentList_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1041::func;
	return execfunc(this, equipmentList);
}

namespace _func1042
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(const std::string &)), ".554889e54156534883ec2031c0837f08000f94c0", nullptr, 0, 0, &func);
}

int ShipObject::HasAugmentation(const std::string &augment)
{
	typedef int (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1042::func;
	return execfunc(this, augment);
}

namespace _func1043
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::AddAugmentation", typeid(bool (ShipObject::*)(const std::string &)), ".554889e54156534883ec2031c0837f08000f94c0", nullptr, 0, 0, &func);
}

bool ShipObject::AddAugmentation(const std::string &augment)
{
	typedef bool (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1043::func;
	return execfunc(this, augment);
}

namespace _func1044
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::RemoveAugmentation", typeid(void (ShipObject::*)(const std::string &)), ".554889e54156534883ec2031c0837f08000f94c0", nullptr, 0, 0, &func);
}

void ShipObject::RemoveAugmentation(const std::string &augment)
{
	typedef void (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1044::func;
	return execfunc(this, augment);
}

namespace _func1045
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), ".554889e531c0837f08000f94", nullptr, 0, 0, &func);
}

int ShipObject::GetAugmentationCount()
{
	typedef int (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1045::func;
	return execfunc(this);
}

namespace _func1046
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(const std::string &)), ".554889e54156534883ec2031c0837f08000f94c0", nullptr, 0, 0, &func);
}

float ShipObject::GetAugmentationValue(const std::string &augment)
{
	typedef float (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1046::func;
	return execfunc(this, augment);
}

namespace _func1047
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::GetAugmentationList", typeid(std::vector<std::string> (ShipObject::*)()), ".554889e5415741564155415453504989fc31c083", nullptr, 0, 0, &func);
}

std::vector<std::string> ShipObject::GetAugmentationList()
{
	typedef std::vector<std::string> (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1047::func;
	return execfunc(this);
}

namespace _func1048
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::ClearShipInfo", typeid(void (ShipObject::*)()), ".554889e541574156535031c0", nullptr, 0, 0, &func);
}

void ShipObject::ClearShipInfo()
{
	typedef void (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1048::func;
	return execfunc(this);
}

namespace _func1049
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipObject::HasEquipment", typeid(int (ShipObject::*)(const std::string &)), ".554889e54157415641554154534883ec684989f74989fe48", nullptr, 0, 0, &func);
}

int ShipObject::HasEquipment(const std::string &equip)
{
	typedef int (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1049::func;
	return execfunc(this, equip);
}

ShipInfo **Global_ShipObject_ShipInfoList;

namespace _var1050
{
	static VariableDefinition varObj("Global_ShipObject_ShipInfoList", "!.488905????????488d35(???????\?)488d4870", &Global_ShipObject_ShipInfoList, true, true);
}

namespace _func1051
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::constructor", typeid(void (ShipSelect::*)()), ".554889e553504889fbbe", nullptr, 0, 0, &func);
}

void ShipSelect::constructor()
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1051::func;
	return execfunc(this);
}

namespace _func1052
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::ClearShipButtons", typeid(void (ShipSelect::*)()), ".554889e54156534989fe498b4628", nullptr, 0, 0, &func);
}

void ShipSelect::ClearShipButtons()
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1052::func;
	return execfunc(this);
}

namespace _func1053
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::MouseMove", typeid(void (ShipSelect::*)(int , int )), "!.554889e54157415641554154534881ec980000004189f548", nullptr, 0, 0, &func);
}

void ShipSelect::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1053::func;
	return execfunc(this, mX, mY);
}

namespace _func1054
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::OnLoop", typeid(void (ShipSelect::*)()), "!.554889e5415741564154534881ec800000004889fb80bb20", nullptr, 0, 0, &func);
}

void ShipSelect::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1054::func;
	return execfunc(this);
}

namespace _func1055
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::KeyDown", typeid(int (ShipSelect::*)(SDLKey )), "!.554889e54881c7180600005d", nullptr, 0, 0, &func);
}

int ShipSelect::KeyDown(SDLKey key)
{
	typedef int (*custom_arg_funcptr_t)(ShipSelect *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1055::func;
	return execfunc(this, key);
}

namespace _func1056
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::MouseClick", typeid(void (ShipSelect::*)()), "!.554889e553504889fb80bb20", nullptr, 0, 0, &func);
}

void ShipSelect::MouseClick()
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1056::func;
	return execfunc(this);
}

namespace _func1057
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::Close", typeid(void (ShipSelect::*)()), "!.554889e5c6475800", nullptr, 0, 0, &func);
}

void ShipSelect::Close()
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1057::func;
	return execfunc(this);
}

namespace _func1058
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::GetSelectedShip", typeid(int (ShipSelect::*)()), ".554889e58b475c", nullptr, 0, 0, &func);
}

int ShipSelect::GetSelectedShip()
{
	typedef int (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1058::func;
	return execfunc(this);
}

namespace _func1059
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::OnRender", typeid(void (ShipSelect::*)()), ".554889e54157415641554154534883ec384989fc4180bc24", nullptr, 0, 0, &func);
}

void ShipSelect::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1059::func;
	return execfunc(this);
}

namespace _func1060
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSelect::Open", typeid(void (ShipSelect::*)(int , int )), "!.554889e54157415641554154534881ec280200004989fe41", nullptr, 0, 0, &func);
}

void ShipSelect::Open(int currentId, int currentType)
{
	typedef void (*custom_arg_funcptr_t)(ShipSelect *this_arg, int currentId_arg, int currentType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1060::func;
	return execfunc(this, currentId, currentType);
}

namespace _func1061
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), ".554889e54157415641554154534881ec880100004989fef3", nullptr, 0, 0, &func);
}

void ShipStatus::OnInit(Point location, float size)
{
	typedef void (*custom_arg_funcptr_t)(ShipStatus *this_arg, Point location_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1061::func;
	return execfunc(this, location, size);
}

namespace _func1062
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipStatus::OnLoop", typeid(void (ShipStatus::*)()), ".554889e5415741564154534881ec6001", nullptr, 0, 0, &func);
}

void ShipStatus::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1062::func;
	return execfunc(this);
}

namespace _func1063
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(void (ShipStatus::*)()), "!.554889e553504889fbe87208", nullptr, 0, 0, &func);
}

void ShipStatus::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1063::func;
	return execfunc(this);
}

namespace _func1064
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), ".554889e5415741564154534881ecc000", nullptr, 0, 0, &func);
}

void ShipStatus::RenderHealth(bool renderText)
{
	typedef void (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1064::func;
	return execfunc(this, renderText);
}

namespace _func1065
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipStatus::RenderShields", typeid(void (ShipStatus::*)(bool )), "!.554889e5415741564155415453504989fe4084f6", nullptr, 0, 0, &func);
}

void ShipStatus::RenderShields(bool renderText)
{
	typedef void (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1065::func;
	return execfunc(this, renderText);
}

namespace _func1066
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), ".554889e5415741564154534883ec504889fb4084", nullptr, 0, 0, &func);
}

void ShipStatus::RenderEvadeOxygen(bool renderText)
{
	typedef void (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1066::func;
	return execfunc(this, renderText);
}

namespace _func1067
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::DO_NOT_HOOK", typeid(void (ShipSystem::*)()), "554889e553504889fb8b7650e8", nullptr, 0, 0, &func);
}

namespace _func1068
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::PartialDamage", typeid(bool (ShipSystem::*)(float )), "!.554889e5", nullptr, 0, 0, &func);
}

bool ShipSystem::PartialDamage(float amount)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1068::func;
	return execfunc(this, amount);
}

namespace _func1069
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::SaveState", typeid(void (ShipSystem::*)(int )), "!.554889e54156534189f64889fb8bb3", nullptr, 0, 0, &func);
}

void ShipSystem::SaveState(int file)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1069::func;
	return execfunc(this, file);
}

namespace _func1070
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::LoadState", typeid(void (ShipSystem::*)(int )), ".554889e541565389f34989fe89dfe8????f5ff41", nullptr, 0, 0, &func);
}

void ShipSystem::LoadState(int file)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1070::func;
	return execfunc(this, file);
}

namespace _func1071
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::constructor", typeid(void (ShipSystem::*)(int , int , int , int )), "!.554889e54157415641554154534881ec????????4589c74189d6", nullptr, 0, 0, &func);
}

void ShipSystem::constructor(int _systemId, int _roomId, int _shipId, int _startingPower)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int _systemId_arg, int _roomId_arg, int _shipId_arg, int _startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1071::func;
	return execfunc(this, _systemId, _roomId, _shipId, _startingPower);
}

GL_Primitive **ShipSystem__glowWhite;

namespace _var1072
{
	static VariableDefinition varObj("ShipSystem__glowWhite", "!.4889c70f28f5e8????????488905(???????\?)", &ShipSystem__glowWhite, true, true);
}

GL_Primitive **ShipSystem__glowBlue;

namespace _var1073
{
	static VariableDefinition varObj("ShipSystem__glowBlue", "!.4889c70f28f5e8????????488905(???????\?)", &ShipSystem__glowBlue, true, true);
}

GL_Primitive **ShipSystem__glowRed;

namespace _var1074
{
	static VariableDefinition varObj("ShipSystem__glowRed", "!.4889c70f28f5e8????????488905(???????\?)", &ShipSystem__glowRed, true, true);
}

GL_Primitive **ShipSystem__manningOutline;

namespace _var1075
{
	static VariableDefinition varObj("ShipSystem__manningOutline", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__manningOutline, true, true);
}

GL_Primitive **ShipSystem__manningWhite;

namespace _var1076
{
	static VariableDefinition varObj("ShipSystem__manningWhite", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__manningWhite, true, true);
}

GL_Primitive **ShipSystem__manningGreen;

namespace _var1077
{
	static VariableDefinition varObj("ShipSystem__manningGreen", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__manningGreen, true, true);
}

GL_Primitive **ShipSystem__manningYellow;

namespace _var1078
{
	static VariableDefinition varObj("ShipSystem__manningYellow", "!.4889de0f28c8e8????????488905(???????\?)", &ShipSystem__manningYellow, true, true);
}

GL_Primitive **ShipSystem__manningBarOff;

namespace _var1079
{
	static VariableDefinition varObj("ShipSystem__manningBarOff", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__manningBarOff, true, true);
}

GL_Primitive **ShipSystem__manningBarOn;

namespace _var1080
{
	static VariableDefinition varObj("ShipSystem__manningBarOn", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__manningBarOn, true, true);
}

GL_Primitive **ShipSystem__manningBarIon;

namespace _var1081
{
	static VariableDefinition varObj("ShipSystem__manningBarIon", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__manningBarIon, true, true);
}

GL_Primitive **ShipSystem__lockBlue;

namespace _var1082
{
	static VariableDefinition varObj("ShipSystem__lockBlue", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__lockBlue, true, true);
}

GL_Primitive **ShipSystem__lockWhite;

namespace _var1083
{
	static VariableDefinition varObj("ShipSystem__lockWhite", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__lockWhite, true, true);
}

GL_Primitive **ShipSystem__lockHack;

namespace _var1084
{
	static VariableDefinition varObj("ShipSystem__lockHack", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__lockHack, true, true);
}

GL_Primitive **ShipSystem__sabotageImage;

namespace _var1085
{
	static VariableDefinition varObj("ShipSystem__sabotageImage", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__sabotageImage, true, true);
}

GL_Primitive **ShipSystem__fireImage;

namespace _var1086
{
	static VariableDefinition varObj("ShipSystem__fireImage", "!.4531c90f28c8e8????????488905(???????\?)", &ShipSystem__fireImage, true, true);
}

namespace _func1087
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(std::string (*)(int )), ".554889e583fe110f", nullptr, 0, 0, &func);
}

std::string ShipSystem::SystemIdToName(int systemId)
{
	typedef std::string (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1087::func;
	return execfunc(systemId);
}

namespace _func1088
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::destructor", typeid(void (ShipSystem::*)()), "!.554889e54157415653504989fe488d05????????498906488d05????????49894610498b7e78", nullptr, 0, 0, &func);
}

void ShipSystem::destructor()
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1088::func;
	return execfunc(this);
}

namespace _func1089
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), ".554889e531c0837f58007e1b", nullptr, 0, 0, &func);
}

int ShipSystem::GetEffectivePower()
{
	typedef int (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1089::func;
	return execfunc(this);
}

namespace _func1090
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), ".554889e58b4f5885", nullptr, 0, 0, &func);
}

int ShipSystem::IsMannedBoost()
{
	typedef int (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1090::func;
	return execfunc(this);
}

namespace _func1091
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), ".554889e58b8fa001", nullptr, 0, 0, &func);
}

int ShipSystem::GetPowerCap()
{
	typedef int (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1091::func;
	return execfunc(this);
}

namespace _func1092
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::BlockedBoosted", typeid(bool (ShipSystem::*)(bool )), ".554889e54156534889fb4084f674238b", nullptr, 0, 0, &func);
}

bool ShipSystem::BlockedBoosted(bool countLimit)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool countLimit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1092::func;
	return execfunc(this, countLimit);
}

namespace _func1093
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::GetLocked", typeid(bool (ShipSystem::*)()), ".554889e58b8fac01", nullptr, 0, 0, &func);
}

bool ShipSystem::GetLocked()
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1093::func;
	return execfunc(this);
}

namespace _func1094
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::GetLockTimer", typeid(TimerHelper (ShipSystem::*)()), ".554889e58b86c0010000894710488b", nullptr, 0, 0, &func);
}

TimerHelper ShipSystem::GetLockTimer()
{
	typedef TimerHelper (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1094::func;
	return execfunc(this);
}

namespace _func1095
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::LockSystem", typeid(void (ShipSystem::*)(int )), "!.554889e585f6741a", nullptr, 0, 0, &func);
}

void ShipSystem::LockSystem(int lock)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1095::func;
	return execfunc(this, lock);
}

namespace _func1096
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::CheckForRepower", typeid(void (ShipSystem::*)()), ".554889e54156534889fb8b435083c0fd", nullptr, 0, 0, &func);
}

void ShipSystem::CheckForRepower()
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1096::func;
	return execfunc(this);
}

namespace _func1097
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::StopHacking", typeid(void (ShipSystem::*)()), "!.554889e5c68744020000??488b07488b80c800000031f65dffe0", nullptr, 0, 0, &func);
}

void ShipSystem::StopHacking()
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1097::func;
	return execfunc(this);
}

namespace _func1098
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::AddLock", typeid(void (ShipSystem::*)(int )), "!.554889e58b87ac01000085c07e0983bf", nullptr, 0, 0, &func);
}

void ShipSystem::AddLock(int lock)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1098::func;
	return execfunc(this, lock);
}

namespace _func1099
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::UpgradeSystem", typeid(bool (ShipSystem::*)(int )), ".554889e54156534189f64889fb488b03ff502044", nullptr, 0, 0, &func);
}

bool ShipSystem::UpgradeSystem(int amount)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1099::func;
	return execfunc(this, amount);
}

namespace _func1100
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::IncreasePower", typeid(bool (ShipSystem::*)(int , bool )), ".554889e54156534189d64889fb8b8bac", nullptr, 0, 0, &func);
}

bool ShipSystem::IncreasePower(int amount, bool force)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1100::func;
	return execfunc(this, amount, force);
}

namespace _func1101
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::GetMaxPower", typeid(int (ShipSystem::*)()), ".554889e58b47648b8fa00100", nullptr, 0, 0, &func);
}

int ShipSystem::GetMaxPower()
{
	typedef int (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1101::func;
	return execfunc(this);
}

namespace _func1102
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::RenderSystemSymbol", typeid(void (ShipSystem::*)(bool , int )), ".554889e541574156534883ec1889d3", nullptr, 0, 0, &func);
}

void ShipSystem::RenderSystemSymbol(bool forPowerUI, int forceColor)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool forPowerUI_arg, int forceColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1102::func;
	return execfunc(this, forPowerUI, forceColor);
}

namespace _func1103
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxesPlain", typeid(int (*)(int , int , int , int , int , int , int , int )), ".554889e5415741564155415453504589cc4589c7", nullptr, 0, 0, &func);
}

int ShipSystem::RenderPowerBoxesPlain(int x, int y, int width, int height, int gap, int current, int temp, int max)
{
	typedef int (*custom_arg_funcptr_t)(int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int current_arg, int temp_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1103::func;
	return execfunc(x, y, width, height, gap, current, temp, max);
}

namespace _func1104
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::Ioned", typeid(bool (ShipSystem::*)(int )), ".554889e58b87ac01000085c07f0e83f8", nullptr, 0, 0, &func);
}

bool ShipSystem::Ioned(int num)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, int num_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1104::func;
	return execfunc(this, num);
}

namespace _func1105
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::IsSubsystem", typeid(bool (*)(int )), ".554889e583c7fa83", nullptr, 0, 0, &func);
}

bool ShipSystem::IsSubsystem(int systemType)
{
	typedef bool (*custom_arg_funcptr_t)(int systemType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1105::func;
	return execfunc(systemType);
}

namespace _func1106
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxes", typeid(int (ShipSystem::*)(int , int , int , int , int , int , bool )), ".554889e54157415641554154534881ecb80000004589cd4c", nullptr, 0, 0, &func);
}

int ShipSystem::RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash)
{
	typedef int (*custom_arg_funcptr_t)(ShipSystem *this_arg, int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int heightMod_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1106::func;
	return execfunc(this, x, y, width, height, gap, heightMod, flash);
}

namespace _func1107
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::ClearStatus", typeid(void (ShipSystem::*)()), "!.554889e583bfa001", nullptr, 0, 0, &func);
}

void ShipSystem::ClearStatus()
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1107::func;
	return execfunc(this);
}

namespace _func1108
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::SetPowerCap", typeid(void (ShipSystem::*)(int )), "!.554889e553504889fb89b3a0", nullptr, 0, 0, &func);
}

void ShipSystem::SetPowerCap(int cap)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int cap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1108::func;
	return execfunc(this, cap);
}

namespace _func1109
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::SetPowerLoss", typeid(int (ShipSystem::*)(int )), "!.554889e553504889fb89b3a4", nullptr, 0, 0, &func);
}

int ShipSystem::SetPowerLoss(int power)
{
	typedef int (*custom_arg_funcptr_t)(ShipSystem *this_arg, int power_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1109::func;
	return execfunc(this, power);
}

namespace _func1110
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(void (ShipSystem::*)()), ".554889e54157415653504989ff4183bf", nullptr, 0, 0, &func);
}

void ShipSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1110::func;
	return execfunc(this);
}

namespace _func1111
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::CheckMaxPower", typeid(void (ShipSystem::*)()), ".554889e5415741564154534889fb80bb", nullptr, 0, 0, &func);
}

void ShipSystem::CheckMaxPower()
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1111::func;
	return execfunc(this);
}

namespace _func1112
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::ForceDecreasePower", typeid(bool (ShipSystem::*)(int )), ".554889e54157415641545389f34989fe", nullptr, 0, 0, &func);
}

bool ShipSystem::ForceDecreasePower(int powerLoss)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, int powerLoss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1112::func;
	return execfunc(this, powerLoss);
}

namespace _func1113
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::SetBonusPower", typeid(void (ShipSystem::*)(int , int )), ".80bf9c01", nullptr, 0, 0, &func);
}

void ShipSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1113::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func1114
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::DecreasePower", typeid(bool (ShipSystem::*)(bool )), ".554889e54156534189f64889fb80bb9c", nullptr, 0, 0, &func);
}

bool ShipSystem::DecreasePower(bool force)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1114::func;
	return execfunc(this, force);
}

namespace _func1115
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::GetLevelDescription", typeid(std::string (*)(int , int , bool )), ".554889e54157415641554154534881ec9800000089d34989", nullptr, 0, 0, &func);
}

std::string ShipSystem::GetLevelDescription(int systemId, int level, bool tooltip)
{
	typedef std::string (*custom_arg_funcptr_t)(int systemId_arg, int level_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1115::func;
	return execfunc(systemId, level, tooltip);
}

namespace _func1116
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::AddDamage", typeid(void (ShipSystem::*)(int )), ".554889e58b47648b8f840100", nullptr, 0, 0, &func);
}

void ShipSystem::AddDamage(int amount)
{
	typedef void (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1116::func;
	return execfunc(this, amount);
}

namespace _func1117
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::DamageOverTime", typeid(bool (ShipSystem::*)(float )), ".554889e54156534883ec10f30f1145ec", nullptr, 0, 0, &func);
}

bool ShipSystem::DamageOverTime(float amount)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1117::func;
	return execfunc(this, amount);
}

namespace _func1118
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::PartialRepair", typeid(bool (ShipSystem::*)(float , bool )), ".554889e54156534883ec104189f64889fb8b8384", nullptr, 0, 0, &func);
}

bool ShipSystem::PartialRepair(float speed, bool autoRepair)
{
	typedef bool (*custom_arg_funcptr_t)(ShipSystem *this_arg, float speed_arg, bool autoRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1118::func;
	return execfunc(this, speed, autoRepair);
}

namespace _func1119
{
	static void *func = 0;
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(const std::string &)), ".554889e553504889fb488d35????0d00e8????0b", nullptr, 0, 0, &func);
}

int ShipSystem::NameToSystemId(const std::string &name)
{
	typedef int (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1119::func;
	return execfunc(name);
}

SoundControl *Global_SoundControl_Sounds;

namespace _var1120
{
	static VariableDefinition varObj("Global_SoundControl_Sounds", "!41c684242002000001488d1d(???????\?)be64000000", &Global_SoundControl_Sounds, true, true);
}

namespace _func1121
{
	static void *func = 0;
	static FunctionDefinition funcObj("SoundControl::StartPlaylist", typeid(void (SoundControl::*)(std::vector<std::string> &)), ".554889e54157415641554154534883ec48488975c848897d", nullptr, 0, 0, &func);
}

void SoundControl::StartPlaylist(std::vector<std::string> &playlist)
{
	typedef void (*custom_arg_funcptr_t)(SoundControl *this_arg, std::vector<std::string> &playlist_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1121::func;
	return execfunc(this, playlist);
}

namespace _func1122
{
	static void *func = 0;
	static FunctionDefinition funcObj("SoundControl::StopPlaylist", typeid(void (SoundControl::*)(int )), ".554889e541574156534883ec284189f64989ff41", nullptr, 0, 0, &func);
}

void SoundControl::StopPlaylist(int fadeOut)
{
	typedef void (*custom_arg_funcptr_t)(SoundControl *this_arg, int fadeOut_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1122::func;
	return execfunc(this, fadeOut);
}

namespace _func1123
{
	static void *func = 0;
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(const std::string &, float , bool )), ".554889e54157415641554154534883ec284189d74989f54989fe31db", nullptr, 0, 0, &func);
}

int SoundControl::PlaySoundMix(const std::string &soundName, float volume, bool loop)
{
	typedef int (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &soundName_arg, float volume_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1123::func;
	return execfunc(this, soundName, volume, loop);
}

namespace _func1124
{
	static void *func = 0;
	static FunctionDefinition funcObj("SoundControl::UpdateSoundLoop", typeid(void (SoundControl::*)(const std::string &, float )), "!.554889e54157415641554154534883ec284889f34989fe41", nullptr, 0, 0, &func);
}

void SoundControl::UpdateSoundLoop(const std::string &loopId, float count)
{
	typedef void (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &loopId_arg, float count_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1124::func;
	return execfunc(this, loopId, count);
}

namespace _func1125
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::constructor", typeid(void (SpaceDrone::*)(int , int , DroneBlueprint *)), "554889e54157415641554154534881ec580100004989ce????????7308", nullptr, 0, 0, &func);
}

void SpaceDrone::constructor(int _iShipId, int _selfId, DroneBlueprint *_blueprint)
{
	typedef void (*custom_arg_funcptr_t)(SpaceDrone *this_arg, int _iShipId_arg, int _selfId_arg, DroneBlueprint *_blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1125::func;
	return execfunc(this, _iShipId, _selfId, _blueprint);
}

namespace _func1126
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::destructor", typeid(void (SpaceDrone::*)()), "!.554889e553504889fb488d05????????488903488d05????????48894340", nullptr, 0, 0, &func);
}

void SpaceDrone::destructor()
{
	typedef void (*custom_arg_funcptr_t)(SpaceDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1126::func;
	return execfunc(this);
}

namespace _func1127
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::SetDeployed", typeid(void (SpaceDrone::*)(bool )), "!.554889e54157415653504189f64889fb488b03ff50604589f74180f7??75??84c075", nullptr, 0, 0, &func);
}

void SpaceDrone::SetDeployed(bool deployed)
{
	typedef void (*custom_arg_funcptr_t)(SpaceDrone *this_arg, bool deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1127::func;
	return execfunc(this, deployed);
}

namespace _func1128
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::SetMovementTarget", typeid(void (SpaceDrone::*)(Targetable *)), ".554889e54156534989f64889fb4d85f674??498b06", nullptr, 0, 0, &func);
}

void SpaceDrone::SetMovementTarget(Targetable *target)
{
	typedef void (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1128::func;
	return execfunc(this, target);
}

namespace _func1129
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::UpdateAimingAngle", typeid(float (SpaceDrone::*)(Pointf , float , float )), ".554889e54156534883ec300f28e10f28", nullptr, 0, 0, &func);
}

float SpaceDrone::UpdateAimingAngle(Pointf location, float percentage, float forceDesired)
{
	typedef float (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Pointf location_arg, float percentage_arg, float forceDesired_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1129::func;
	return execfunc(this, location, percentage, forceDesired);
}

namespace _func1130
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::GetNextProjectile", typeid(Projectile *(SpaceDrone::*)()), ".554889e5415741564154534883ec??4889fb488b03", nullptr, 0, 0, &func);
}

Projectile *SpaceDrone::GetNextProjectile()
{
	typedef Projectile *(*custom_arg_funcptr_t)(SpaceDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1130::func;
	return execfunc(this);
}

namespace _func1131
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceDrone::CollisionMoving", typeid(CollisionResponse (SpaceDrone::*)(Pointf , Pointf , Damage , bool )), ".554889e54157415653504989f64889fb0f134de0", nullptr, 0, 0, &func);
}

CollisionResponse SpaceDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1131::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1132
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::constructor", typeid(void (SpaceManager::*)()), "!.554889e54157415641554154534883ec184889fb48c74310", nullptr, 0, 0, &func);
}

void SpaceManager::constructor()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1132::func;
	return execfunc(this);
}

namespace _func1133
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(int (SpaceManager::*)()), ".554889e58a87a0040000c687a0040000005dc3", nullptr, 0, 0, &func);
}

int SpaceManager::GetScreenShake()
{
	typedef int (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1133::func;
	return execfunc(this);
}

namespace _func1134
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(void (SpaceManager::*)(int )), ".554889e5415741564154534189f64989fc410fb6", nullptr, 0, 0, &func);
}

void SpaceManager::SaveSpace(int fileHelper)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1134::func;
	return execfunc(this, fileHelper);
}

namespace _func1135
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(void (SpaceManager::*)(int )), "!.554889e54157415641554154534883ec384189f74989fd44", nullptr, 0, 0, &func);
}

void SpaceManager::LoadSpace(int fileHelper)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1135::func;
	return execfunc(this, fileHelper);
}

namespace _func1136
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(void (SpaceManager::*)(bool )), ".554889e541574156534883ec384989fe4188b640", nullptr, 0, 0, &func);
}

void SpaceManager::SetFireLevel(bool state)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1136::func;
	return execfunc(this, state);
}

namespace _func1137
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(void (SpaceManager::*)(bool )), ".554889e54156534883ec404989fe4188", nullptr, 0, 0, &func);
}

void SpaceManager::SetPulsarLevel(bool pulsarLevel)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool pulsarLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1137::func;
	return execfunc(this, pulsarLevel);
}

namespace _func1138
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), ".554889e541574156534883ec484189f64989ff41", nullptr, 0, 0, &func);
}

void SpaceManager::SetPlanetaryDefense(char state, int target)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, char state_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1138::func;
	return execfunc(this, state, target);
}

namespace _func1139
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SwitchBeacon", typeid(ImageDesc (SpaceManager::*)()), ".554889e5488b86e0", nullptr, 0, 0, &func);
}

ImageDesc SpaceManager::SwitchBeacon()
{
	typedef ImageDesc (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1139::func;
	return execfunc(this);
}

namespace _func1140
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(ImageDesc (SpaceManager::*)(const std::string &)), ".554889e54157415641554154534883ec484989d44989f748", nullptr, 0, 0, &func);
}

ImageDesc SpaceManager::SwitchPlanet(const std::string &name)
{
	typedef ImageDesc (*custom_arg_funcptr_t)(SpaceManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1140::func;
	return execfunc(this, name);
}

namespace _func1141
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::UpdatePlanetImage", typeid(void (SpaceManager::*)()), ".554889e54156534883ec604889fb488b", nullptr, 0, 0, &func);
}

void SpaceManager::UpdatePlanetImage()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1141::func;
	return execfunc(this);
}

namespace _func1142
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SwitchImages", typeid(void (SpaceManager::*)(ImageDesc , ImageDesc , ImageDesc )), "!.554889e5488b4530", nullptr, 0, 0, &func);
}

void SpaceManager::SwitchImages(ImageDesc planet, ImageDesc back, ImageDesc beacon)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, ImageDesc planet_arg, ImageDesc back_arg, ImageDesc beacon_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1142::func;
	return execfunc(this, planet, back, beacon);
}

namespace _func1143
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(ImageDesc (SpaceManager::*)(const std::string &)), ".554889e54157415641554154534883ec384989d74989f648", nullptr, 0, 0, &func);
}

ImageDesc SpaceManager::SwitchBackground(const std::string &name)
{
	typedef ImageDesc (*custom_arg_funcptr_t)(SpaceManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1143::func;
	return execfunc(this, name);
}

namespace _func1144
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(void (SpaceManager::*)(int , bool )), ".554889e54883ec2089f0488b", nullptr, 0, 0, &func);
}

void SpaceManager::StartAsteroids(int shieldCount, bool defense)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int shieldCount_arg, bool defense_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1144::func;
	return execfunc(this, shieldCount, defense);
}

namespace _func1145
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)(bool )), ".554889e54883ec20c6872a04", nullptr, 0, 0, &func);
}

void SpaceManager::SetStorm(bool state)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1145::func;
	return execfunc(this, state);
}

namespace _func1146
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)(bool )), "!.554889e54157415641554154534881eca80000004989fe41", nullptr, 0, 0, &func);
}

void SpaceManager::SetNebula(bool state)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1146::func;
	return execfunc(this, state);
}

namespace _func1147
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::DangerousEnvironment", typeid(bool (SpaceManager::*)()), ".554889e58a876003", nullptr, 0, 0, &func);
}

bool SpaceManager::DangerousEnvironment()
{
	typedef bool (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1147::func;
	return execfunc(this);
}

namespace _func1148
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::UpdatePDS", typeid(void (SpaceManager::*)()), "!.554889e54157415641554154534881ec780100004989ff4d", nullptr, 0, 0, &func);
}

void SpaceManager::UpdatePDS()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1148::func;
	return execfunc(this);
}

namespace _func1149
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(void (SpaceManager::*)()), "!.554889e54157415641554154534883ec484989fe498dbe08", nullptr, 0, 0, &func);
}

void SpaceManager::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1149::func;
	return execfunc(this);
}

namespace _func1150
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnLoopNebulas", typeid(void (SpaceManager::*)()), ".554889e54157415641554154534883ec584989fc498bbc24", nullptr, 0, 0, &func);
}

void SpaceManager::OnLoopNebulas()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1150::func;
	return execfunc(this);
}

namespace _func1151
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::TransferProjectile", typeid(void (SpaceManager::*)(Projectile *)), "!.554889e54156534889f3448b", nullptr, 0, 0, &func);
}

void SpaceManager::TransferProjectile(Projectile *proj)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1151::func;
	return execfunc(this, proj);
}

namespace _func1152
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::UpdateProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".554889e5415741564155415453504989f44989fe498b0424", nullptr, 0, 0, &func);
}

void SpaceManager::UpdateProjectile(Projectile *proj)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1152::func;
	return execfunc(this, proj);
}

namespace _func1153
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::MouseMove", typeid(void (SpaceManager::*)(int , int , int )), ".554889e5415741564155415453504189cc8955d4", nullptr, 0, 0, &func);
}

void SpaceManager::MouseMove(int mX, int mY, int spaceId)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int mX_arg, int mY_arg, int spaceId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1153::func;
	return execfunc(this, mX, mY, spaceId);
}

namespace _func1154
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::GetSelectedDrone", typeid(SpaceDrone *(SpaceManager::*)(int , int , int )), ".554889e5415741564155415453504189cc4189f5", nullptr, 0, 0, &func);
}

SpaceDrone *SpaceManager::GetSelectedDrone(int mX, int mY, int spaceId)
{
	typedef SpaceDrone *(*custom_arg_funcptr_t)(SpaceManager *this_arg, int mX_arg, int mY_arg, int spaceId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1154::func;
	return execfunc(this, mX, mY, spaceId);
}

namespace _func1155
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), ".554889e553504889fb0f57c080bbbc03", nullptr, 0, 0, &func);
}

float SpaceManager::GetFlashOpacity()
{
	typedef float (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1155::func;
	return execfunc(this);
}

namespace _func1156
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(void (SpaceManager::*)()), ".554889e5415741564154534883ec504889fb80bb", nullptr, 0, 0, &func);
}

void SpaceManager::OnRenderForeground()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1156::func;
	return execfunc(this);
}

namespace _func1157
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::GetColorTint", typeid(GL_Color (SpaceManager::*)()), ".554889e580bf6c04", nullptr, 0, 0, &func);
}

GL_Color SpaceManager::GetColorTint()
{
	typedef GL_Color (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1157::func;
	return execfunc(this);
}

namespace _func1158
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnRenderFleet", typeid(void (SpaceManager::*)()), "!.554889e541574156534883ec284889fb80bb6c04", nullptr, 0, 0, &func);
}

void SpaceManager::OnRenderFleet()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1158::func;
	return execfunc(this);
}

namespace _func1159
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnRenderBackground", typeid(void (SpaceManager::*)()), ".554889e541574156534883ec284989ff4180bf6c", nullptr, 0, 0, &func);
}

void SpaceManager::OnRenderBackground()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1159::func;
	return execfunc(this);
}

namespace _func1160
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(void (SpaceManager::*)(int )), ".554889e54157415641554154534883ec288975cc", nullptr, 0, 0, &func);
}

void SpaceManager::SetDangerZone(int fleetType)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fleetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1160::func;
	return execfunc(this, fleetType);
}

namespace _func1161
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnRenderAsteroids", typeid(void (SpaceManager::*)(int , float )), "!.554889e541574156535089f34989fe41", nullptr, 0, 0, &func);
}

void SpaceManager::OnRenderAsteroids(int fieldLayers, float alpha)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fieldLayers_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1161::func;
	return execfunc(this, fieldLayers, alpha);
}

namespace _func1162
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnRenderProjectiles", typeid(void (SpaceManager::*)(int , int )), ".554889e5415741564155415453508955d04989fd", nullptr, 0, 0, &func);
}

void SpaceManager::OnRenderProjectiles(int iShipId, int layerCommand)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, int iShipId_arg, int layerCommand_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1162::func;
	return execfunc(this, iShipId, layerCommand);
}

namespace _func1163
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::AddProjectile", typeid(void (SpaceManager::*)(Projectile *)), "!.554889e54157415641554154534883ec184889f04889fb4c", nullptr, 0, 0, &func);
}

void SpaceManager::AddProjectile(Projectile *proj)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1163::func;
	return execfunc(this, proj);
}

namespace _func1164
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(void (SpaceManager::*)()), ".554889e54157415641554154534883ec484989ffbf200000", nullptr, 0, 0, &func);
}

void SpaceManager::OnInit()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1164::func;
	return execfunc(this);
}

namespace _func1165
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::Restart", typeid(void (SpaceManager::*)()), "!.554889e54157415653504989fe498b0e498b4608", nullptr, 0, 0, &func);
}

void SpaceManager::Restart()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1165::func;
	return execfunc(this);
}

namespace _func1166
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), ".554889e566c78740", nullptr, 0, 0, &func);
}

void SpaceManager::ClearEnvironment()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1166::func;
	return execfunc(this);
}

namespace _func1167
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::Clear", typeid(void (SpaceManager::*)()), "!.554889e54157415653504989fe498b86b0000000", nullptr, 0, 0, &func);
}

void SpaceManager::Clear()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1167::func;
	return execfunc(this);
}

namespace _func1168
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::ClearProjectiles", typeid(void (SpaceManager::*)()), ".554889e54157415653504989fe498b0e498b4608", nullptr, 0, 0, &func);
}

void SpaceManager::ClearProjectiles()
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1168::func;
	return execfunc(this);
}

namespace _func1169
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceManager::AddShip", typeid(void (SpaceManager::*)(ShipManager *)), "!.554889e54157415641554154534883ec384989f44989fe4d", nullptr, 0, 0, &func);
}

void SpaceManager::AddShip(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(SpaceManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1169::func;
	return execfunc(this, ship);
}

namespace _func1170
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceStatus::OnInit", typeid(void (SpaceStatus::*)(SpaceManager *, Point )), ".554889e5415741564154534883ec504889fb48899390000000", nullptr, 0, 0, &func);
}

void SpaceStatus::OnInit(SpaceManager *space, Point position)
{
	typedef void (*custom_arg_funcptr_t)(SpaceStatus *this_arg, SpaceManager *space_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1170::func;
	return execfunc(this, space, position);
}

namespace _func1171
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceStatus::RenderWarningText", typeid(void (SpaceStatus::*)(int , int )), ".554889e541574156534881ec9800000089f3", nullptr, 0, 0, &func);
}

void SpaceStatus::RenderWarningText(int effect, int textOffset)
{
	typedef void (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int effect_arg, int textOffset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1171::func;
	return execfunc(this, effect, textOffset);
}

namespace _func1172
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceStatus::OnRender", typeid(void (SpaceStatus::*)()), ".554889e54157415641554154534883ec184889fb488b7b58e8", nullptr, 0, 0, &func);
}

void SpaceStatus::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(SpaceStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1172::func;
	return execfunc(this);
}

namespace _func1173
{
	static void *func = 0;
	static FunctionDefinition funcObj("SpaceStatus::MouseMove", typeid(void (SpaceStatus::*)(int , int )), ".554889e541574156534881ec????????4189d6", nullptr, 0, 0, &func);
}

void SpaceStatus::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1173::func;
	return execfunc(this, mX, mY);
}

namespace _func1174
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::constructor", typeid(void (StarMap::*)()), ".554889e54157415641554154534881ec????????4989fce8????????488d05????????4989042441c7442420", nullptr, 0, 0, &func);
}

void StarMap::constructor()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1174::func;
	return execfunc(this);
}

namespace _func1175
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::InitMapTitle", typeid(void (StarMap::*)()), ".554889e54157415641554154534883ec584889fb488bbb80", nullptr, 0, 0, &func);
}

void StarMap::InitMapTitle()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1175::func;
	return execfunc(this);
}

namespace _func1176
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::InitNoFuelText", typeid(void (StarMap::*)()), ".554889e54157415641554154534883ec184989fe498bbec8", nullptr, 0, 0, &func);
}

void StarMap::InitNoFuelText()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1176::func;
	return execfunc(this);
}

namespace _func1177
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::InitBossMessageBox", typeid(void (StarMap::*)()), ".554889e541574156534883ec284989fe498b9ed0", nullptr, 0, 0, &func);
}

void StarMap::InitBossMessageBox()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1177::func;
	return execfunc(this);
}

namespace _func1178
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::OnLanguageChange", typeid(void (StarMap::*)()), "!.554889e553504889fbe862f3", nullptr, 0, 0, &func);
}

void StarMap::OnLanguageChange()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1178::func;
	return execfunc(this);
}

namespace _func1179
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::SetPosition", typeid(void (StarMap::*)(Point )), ".554889e54889b788", nullptr, 0, 0, &func);
}

void StarMap::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1179::func;
	return execfunc(this, position);
}

namespace _func1180
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GetRandomSectorChoice", typeid(int (StarMap::*)()), ".554889e5488d05??????0080", nullptr, 0, 0, &func);
}

int StarMap::GetRandomSectorChoice()
{
	typedef int (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1180::func;
	return execfunc(this);
}

namespace _func1181
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::AddSectorColumn", typeid(void (StarMap::*)()), "!.554889e54157415641554154534881ec980100004c8db7f8", nullptr, 0, 0, &func);
}

void StarMap::AddSectorColumn()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1181::func;
	return execfunc(this);
}

namespace _func1182
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::NeighboringSector", typeid(void (StarMap::*)(int )), ".554889e585f6781d", nullptr, 0, 0, &func);
}

void StarMap::NeighboringSector(int potentialSector)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int potentialSector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1182::func;
	return execfunc(this, potentialSector);
}

namespace _func1183
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GetSelectedSector", typeid(void (StarMap::*)(int , int , int )), ".554889e5415741564155415453504189cf4989fe", nullptr, 0, 0, &func);
}

void StarMap::GetSelectedSector(int mX, int mY, int maxDist)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int mX_arg, int mY_arg, int maxDist_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1183::func;
	return execfunc(this, mX, mY, maxDist);
}

namespace _func1184
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GenerateSectorMap", typeid(void (StarMap::*)()), "!.554889e54157415641554154534881ec580100004989fd49", nullptr, 0, 0, &func);
}

void StarMap::GenerateSectorMap()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1184::func;
	return execfunc(this);
}

namespace _func1185
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::UpdateSectorMap", typeid(void (StarMap::*)(Sector *)), "!.554889e54885f675", nullptr, 0, 0, &func);
}

void StarMap::UpdateSectorMap(Sector *fakeCurrent)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *fakeCurrent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1185::func;
	return execfunc(this, fakeCurrent);
}

namespace _func1186
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::StartSecretSector", typeid(void (StarMap::*)()), ".554889e54883ec20488b8708", nullptr, 0, 0, &func);
}

void StarMap::StartSecretSector()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1186::func;
	return execfunc(this);
}

namespace _func1187
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::SelectNewSector", typeid(void (StarMap::*)(int )), "!.554889e54156534889fb488b83e80800", nullptr, 0, 0, &func);
}

void StarMap::SelectNewSector(int choice)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int choice_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1187::func;
	return execfunc(this, choice);
}

namespace _func1188
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::PushSectorColumn", typeid(void (StarMap::*)()), "!.554889e5415741564155415453504989fe498b86", nullptr, 0, 0, &func);
}

void StarMap::PushSectorColumn()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1188::func;
	return execfunc(this);
}

namespace _func1189
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ReachSector", typeid(void (StarMap::*)(Sector *)), ".554889e54157415653504989f74989fe41c64705", nullptr, 0, 0, &func);
}

void StarMap::ReachSector(Sector *sector)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1189::func;
	return execfunc(this, sector);
}

namespace _func1190
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::RenderSectorName", typeid(void (StarMap::*)(Sector *, GL_Color )), "!.554889e54157415641554154534881ecb80000000f298d30", nullptr, 0, 0, &func);
}

void StarMap::RenderSectorName(Sector *sector, GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *sector_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1190::func;
	return execfunc(this, sector, color);
}

namespace _func1191
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::KeyDown", typeid(void (StarMap::*)(SDLKey )), ".554889e580bf1009000000747183fe32", nullptr, 0, 0, &func);
}

void StarMap::KeyDown(SDLKey key)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1191::func;
	return execfunc(this, key);
}

namespace _func1192
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::AddQuest", typeid(bool (StarMap::*)(const std::string &, bool )), "!.554889e54157415641554154534883ec684189d44989f648", nullptr, 0, 0, &func);
}

bool StarMap::AddQuest(const std::string &questEvent, bool force)
{
	typedef bool (*custom_arg_funcptr_t)(StarMap *this_arg, const std::string &questEvent_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1192::func;
	return execfunc(this, questEvent, force);
}

namespace _func1193
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::Dijkstra", typeid(std::vector<Location*> (StarMap::*)(Location *, Location *, bool )), "!.554889e54157415641554154534881eca8000000448945a0", nullptr, 0, 0, &func);
}

std::vector<Location*> StarMap::Dijkstra(Location *start, Location *finish, bool include_unknown)
{
	typedef std::vector<Location*> (*custom_arg_funcptr_t)(StarMap *this_arg, Location *start_arg, Location *finish_arg, bool include_unknown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1193::func;
	return execfunc(this, start, finish, include_unknown);
}

namespace _func1194
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::DeleteMap", typeid(void (StarMap::*)()), ".554889e54157415653504989fe4d8bbe680c0000", nullptr, 0, 0, &func);
}

void StarMap::DeleteMap()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1194::func;
	return execfunc(this);
}

namespace _func1195
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::SaveGame", typeid(void (StarMap::*)(int )), ".554889e54157415641554154534883ec184189f64989fd498b8d0009", nullptr, 0, 0, &func);
}

void StarMap::SaveGame(int file)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1195::func;
	return execfunc(this, file);
}

namespace _func1196
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GetNextDangerMove", typeid(int (StarMap::*)()), ".554889e531c083bfac000000", nullptr, 0, 0, &func);
}

int StarMap::GetNextDangerMove()
{
	typedef int (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1196::func;
	return execfunc(this);
}

namespace _func1197
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::LoadGame", typeid(Location *(StarMap::*)(int )), "!.554889e54157415641554154534881ec98050000", nullptr, 0, 0, &func);
}

Location *StarMap::LoadGame(int fileHelper)
{
	typedef Location *(*custom_arg_funcptr_t)(StarMap *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1197::func;
	return execfunc(this, fileHelper);
}

namespace _func1198
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GenerateMap", typeid(Location *(StarMap::*)(bool , bool )), "!.554889e54157415641554154534881ecc801000089758c48", nullptr, 0, 0, &func);
}

Location *StarMap::GenerateMap(bool tutorial, bool seed)
{
	typedef Location *(*custom_arg_funcptr_t)(StarMap *this_arg, bool tutorial_arg, bool seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1198::func;
	return execfunc(this, tutorial, seed);
}

namespace _func1199
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ReverseBossPath", typeid(void (StarMap::*)()), ".554889e580b7a80a", nullptr, 0, 0, &func);
}

void StarMap::ReverseBossPath()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1199::func;
	return execfunc(this);
}

namespace _func1200
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::TurnIntoFleetLocation", typeid(void (StarMap::*)(Location *)), ".554889e54156534883ec304889f34989fec64328", nullptr, 0, 0, &func);
}

void StarMap::TurnIntoFleetLocation(Location *location)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1200::func;
	return execfunc(this, location);
}

namespace _func1201
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::SetupNoFuel", typeid(void (StarMap::*)(int , const std::string &)), ".554889e54157415641554154534881ecc80000004989d649", nullptr, 0, 0, &func);
}

void StarMap::SetupNoFuel(int seed, const std::string &forceEscape)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int seed_arg, const std::string &forceEscape_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1201::func;
	return execfunc(this, seed, forceEscape);
}

namespace _func1202
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::NewGame", typeid(Location *(StarMap::*)(bool )), ".554889e5415741564154534883ec704189f64989", nullptr, 0, 0, &func);
}

Location *StarMap::NewGame(bool tutorial)
{
	typedef Location *(*custom_arg_funcptr_t)(StarMap *this_arg, bool tutorial_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1202::func;
	return execfunc(this, tutorial);
}

namespace _func1203
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::MapConnected", typeid(void (StarMap::*)()), ".554889e54156534889fb488dbbb80c00", nullptr, 0, 0, &func);
}

void StarMap::MapConnected()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1203::func;
	return execfunc(this);
}

namespace _func1204
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::AddConnections", typeid(void (StarMap::*)(Location *)), ".554889e5415741564155415453504989f54c8da7", nullptr, 0, 0, &func);
}

void StarMap::AddConnections(Location *location)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1204::func;
	return execfunc(this, location);
}

namespace _func1205
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::PopulateGrid", typeid(void (StarMap::*)(Point )), "!.554889e54157415641554154534883ec384989f64d89f749", nullptr, 0, 0, &func);
}

void StarMap::PopulateGrid(Point grid)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Point grid_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1205::func;
	return execfunc(this, grid);
}

namespace _func1206
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GenerateEvents", typeid(void (StarMap::*)(bool )), "!.554889e54157415641554154534881ec980100004189f549", nullptr, 0, 0, &func);
}

void StarMap::GenerateEvents(bool bTutorial)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, bool bTutorial_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1206::func;
	return execfunc(this, bTutorial);
}

namespace _func1207
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::TravelToLocation", typeid(void (StarMap::*)(Location *)), ".554889e548897770", nullptr, 0, 0, &func);
}

void StarMap::TravelToLocation(Location *location)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1207::func;
	return execfunc(this, location);
}

namespace _func1208
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GenerateNebulas", typeid(void (StarMap::*)(const std::vector<std::string> &)), "!.554889e54157415641554154534881ecb80000004989f448", nullptr, 0, 0, &func);
}

void StarMap::GenerateNebulas(const std::vector<std::string> &names)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, const std::vector<std::string> &names_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1208::func;
	return execfunc(this, names);
}

namespace _func1209
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ConnectLocations", typeid(void (StarMap::*)(Point , Point )), "!.554889e54157415641554154534883ec684989d7", nullptr, 0, 0, &func);
}

void StarMap::ConnectLocations(Point grid1, Point grid2)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Point grid1_arg, Point grid2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1209::func;
	return execfunc(this, grid1, grid2);
}

namespace _func1210
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::MouseClick", typeid(void (StarMap::*)(int , int )), "!.554889e54157415641554154534883ec384889fb80bb0807", nullptr, 0, 0, &func);
}

void StarMap::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1210::func;
	return execfunc(this, mX, mY);
}

namespace _func1211
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::AdvanceWorldLevel", typeid(void (StarMap::*)()), ".554889e541574156534881ecc8010000", nullptr, 0, 0, &func);
}

void StarMap::AdvanceWorldLevel()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1211::func;
	return execfunc(this);
}

namespace _func1212
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::OnTouch", typeid(void (StarMap::*)(TouchAction , int , int , int , int , int )), "!.554889e54157415641554154534881ec880000004589cf41", nullptr, 0, 0, &func);
}

void StarMap::OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, TouchAction action_arg, int id_arg, int x_arg, int y_arg, int initialX_arg, int initialY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1212::func;
	return execfunc(this, action, id, x, y, initialX, initialY);
}

namespace _func1213
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::PointToGrid", typeid(Point (StarMap::*)(float , float )), ".554889e54883ec10f30f1145f4f30f10", nullptr, 0, 0, &func);
}

Point StarMap::PointToGrid(float x, float y)
{
	typedef Point (*custom_arg_funcptr_t)(StarMap *this_arg, float x_arg, float y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1213::func;
	return execfunc(this, x, y);
}

namespace _func1214
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ModifyPursuit", typeid(void (StarMap::*)(int )), ".554889e501b75005", nullptr, 0, 0, &func);
}

void StarMap::ModifyPursuit(int amount)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1214::func;
	return execfunc(this, amount);
}

namespace _func1215
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::UpdateBoss", typeid(void (StarMap::*)()), "!.554889e54157415641554154534883ec384889fb80bbc80a", nullptr, 0, 0, &func);
}

void StarMap::UpdateBoss()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1215::func;
	return execfunc(this);
}

namespace _func1216
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::UpdateDangerZone", typeid(void (StarMap::*)()), ".554889e541574156534883ec484989ff4180bf94", nullptr, 0, 0, &func);
}

void StarMap::UpdateDangerZone()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1216::func;
	return execfunc(this);
}

namespace _func1217
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::AtBeacon", typeid(void (StarMap::*)()), ".554889e5488b47708a40205d", nullptr, 0, 0, &func);
}

void StarMap::AtBeacon()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1217::func;
	return execfunc(this);
}

namespace _func1218
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GetWaitLocation", typeid(void (StarMap::*)()), ".554889e580bfa800", nullptr, 0, 0, &func);
}

void StarMap::GetWaitLocation()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1218::func;
	return execfunc(this);
}

namespace _func1219
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GetNewLocation", typeid(Location *(StarMap::*)()), ".554889e553504889fb80bba8", nullptr, 0, 0, &func);
}

Location *StarMap::GetNewLocation()
{
	typedef Location *(*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1219::func;
	return execfunc(this);
}

namespace _func1220
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::StartBeacon", typeid(void (StarMap::*)()), ".554889e583bf4805", nullptr, 0, 0, &func);
}

void StarMap::StartBeacon()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1220::func;
	return execfunc(this);
}

namespace _func1221
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::LocationsConnected", typeid(bool (StarMap::*)(Location *, Location *)), ".554889e5488b4608", nullptr, 0, 0, &func);
}

bool StarMap::LocationsConnected(Location *location1, Location *location2)
{
	typedef bool (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location1_arg, Location *location2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1221::func;
	return execfunc(this, location1, location2);
}

namespace _func1222
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ForceExitBeacon", typeid(void (StarMap::*)()), ".554889e5488b4770c6402001", nullptr, 0, 0, &func);
}

void StarMap::ForceExitBeacon()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1222::func;
	return execfunc(this);
}

namespace _func1223
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::MouseMove", typeid(void (StarMap::*)(int , int )), "!.554889e54157415641554154534881ec980000004189d441", nullptr, 0, 0, &func);
}

void StarMap::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1223::func;
	return execfunc(this, mX, mY);
}

namespace _func1224
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::Open", typeid(void (StarMap::*)()), ".554889e54156534889fb807b08000f85", nullptr, 0, 0, &func);
}

void StarMap::Open()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1224::func;
	return execfunc(this);
}

namespace _func1225
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::Close", typeid(void (StarMap::*)()), ".554889e5534883ec184889fb80bb9408", nullptr, 0, 0, &func);
}

void StarMap::Close()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1225::func;
	return execfunc(this);
}

namespace _func1226
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::SetOpen", typeid(void (StarMap::*)(bool )), "!.554889e5488b074084f6", nullptr, 0, 0, &func);
}

void StarMap::SetOpen(bool open)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, bool open_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1226::func;
	return execfunc(this, open);
}

namespace _func1227
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::LocationHasBoss", typeid(void (StarMap::*)(Location *)), ".554889e5486387a0", nullptr, 0, 0, &func);
}

void StarMap::LocationHasBoss(Location *location)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1227::func;
	return execfunc(this, location);
}

namespace _func1228
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::LocationHasStore", typeid(void (StarMap::*)(Location *)), ".554889e5488b46304885c074224883b8", nullptr, 0, 0, &func);
}

void StarMap::LocationHasStore(Location *location)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1228::func;
	return execfunc(this, location);
}

namespace _func1229
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::LocationHasShip", typeid(void (StarMap::*)(Location *)), ".554889e5488b46304885c07409807820", nullptr, 0, 0, &func);
}

void StarMap::LocationHasShip(Location *location)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1229::func;
	return execfunc(this, location);
}

namespace _func1230
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::OnLoop", typeid(void (StarMap::*)()), ".554889e541574156534883ec784989ff41807f08", nullptr, 0, 0, &func);
}

void StarMap::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1230::func;
	return execfunc(this);
}

namespace _func1231
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::GetLocationText", typeid(std::string (StarMap::*)(const Location *)), ".554889e5415741564154534881ec800000004989", nullptr, 0, 0, &func);
}

std::string StarMap::GetLocationText(const Location *location)
{
	typedef std::string (*custom_arg_funcptr_t)(StarMap *this_arg, const Location *location_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1231::func;
	return execfunc(this, location);
}

namespace _func1232
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ForceBossJump", typeid(void (StarMap::*)()), ".554889e5c687a90a", nullptr, 0, 0, &func);
}

void StarMap::ForceBossJump()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1232::func;
	return execfunc(this);
}

namespace _func1233
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::ClearBoss", typeid(void (StarMap::*)()), ".554889e54157415653504989fe41c686", nullptr, 0, 0, &func);
}

void StarMap::ClearBoss()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1233::func;
	return execfunc(this);
}

namespace _func1234
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), ".554889e589b7800c", nullptr, 0, 0, &func);
}

void StarMap::SetBossStage(int stage)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, int stage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1234::func;
	return execfunc(this, stage);
}

namespace _func1235
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::CheckGameOver", typeid(void (StarMap::*)()), ".554889e583bfa40a", nullptr, 0, 0, &func);
}

void StarMap::CheckGameOver()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1235::func;
	return execfunc(this);
}

namespace _func1236
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::DrawConnection", typeid(void (StarMap::*)(const Pointf &, const Pointf &, const GL_Color *)), ".554889e54157415641554154534881ec080100004989cd48", nullptr, 0, 0, &func);
}

void StarMap::DrawConnection(const Pointf &position1, const Pointf &position2, const GL_Color *color)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, const Pointf &position1_arg, const Pointf &position2_arg, const GL_Color *color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1236::func;
	return execfunc(this, position1, position2, color);
}

namespace _func1237
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::OnRender", typeid(void (StarMap::*)()), ".554889e54157415641554154534881ece80100004989fd41", nullptr, 0, 0, &func);
}

void StarMap::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1237::func;
	return execfunc(this);
}

namespace _func1238
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::RenderDistressButtons", typeid(void (StarMap::*)()), ".554889e541574156534881ec280100004889fb0f", nullptr, 0, 0, &func);
}

void StarMap::RenderDistressButtons()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1238::func;
	return execfunc(this);
}

namespace _func1239
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::RenderLeftInsetButton", typeid(void (StarMap::*)(float , float , bool )), ".554889e54157415641554154534881ec880000004189f6f3", nullptr, 0, 0, &func);
}

void StarMap::RenderLeftInsetButton(float rightX, float y, bool isWait)
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg, float rightX_arg, float y_arg, bool isWait_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1239::func;
	return execfunc(this, rightX, y, isWait);
}

namespace _func1240
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::RenderLabels", typeid(void (StarMap::*)()), ".554889e54157415641554154534881ecd80000004989fce8", nullptr, 0, 0, &func);
}

void StarMap::RenderLabels()
{
	typedef void (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1240::func;
	return execfunc(this);
}

namespace _func1241
{
	static void *func = 0;
	static FunctionDefinition funcObj("StarMap::PopClosestLoc", typeid(Location *(StarMap::*)(std::vector<Location*> &, std::map<Location*, int> &)), ".554889e54157415641554154534883ec284989f0", nullptr, 0, 0, &func);
}

Location *StarMap::PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map)
{
	typedef Location *(*custom_arg_funcptr_t)(StarMap *this_arg, std::vector<Location*> &vec_arg, std::map<Location*, int> &map_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1241::func;
	return execfunc(this, vec, map);
}

namespace _func1242
{
	static void *func = 0;
	static FunctionDefinition funcObj("StatusEffect::DO_NOT_HOOK_GetStormEffect", typeid(void (StatusEffect::*)()), "554889e58a05??????0084c0", nullptr, 0, 0, &func);
}

namespace _func1243
{
	static void *func = 0;
	static FunctionDefinition funcObj("StatusEffect::GetNebulaEffect", typeid(StatusEffect (*)()), ".554889e58a05??????0084c0", nullptr, 0, 0, &func);
}

StatusEffect StatusEffect::GetNebulaEffect()
{
	typedef StatusEffect (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1243::func;
	return execfunc();
}

namespace _func1244
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::constructor", typeid(void (Store::*)()), "554889e553504889fbe8????????488d05????????48890348c74338????????48c74330????????48c74328????????c64340", nullptr, 0, 0, &func);
}

void Store::constructor()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1244::func;
	return execfunc(this);
}

namespace _func1245
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::SaveStore", typeid(void (Store::*)(int )), ".554889e5415741564155415453504189f64989fc418bb424", nullptr, 0, 0, &func);
}

void Store::SaveStore(int file)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1245::func;
	return execfunc(this, file);
}

namespace _func1246
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::LoadStore", typeid(void (Store::*)(int , int )), "!.554889e54157415641554154534881ec180100008955a089", nullptr, 0, 0, &func);
}

void Store::LoadStore(int file, int worldLevel)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, int file_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1246::func;
	return execfunc(this, file, worldLevel);
}

namespace _func1247
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::Clear", typeid(void (Store::*)()), ".554889e54156534989fe498b8668050000498b8e", nullptr, 0, 0, &func);
}

void Store::Clear()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1247::func;
	return execfunc(this);
}

namespace _func1248
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::SetPositions", typeid(void (Store::*)()), "!.554889e54157415641554154534881ecd80000004889fbc6", nullptr, 0, 0, &func);
}

void Store::SetPositions()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1248::func;
	return execfunc(this);
}

namespace _func1249
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::RelinkShip", typeid(void (Store::*)(ShipManager *, Equipment *)), ".554889e5415741564154534989d64989f74989fc4d89bc24", nullptr, 0, 0, &func);
}

void Store::RelinkShip(ShipManager *ship, Equipment *equip)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *ship_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1249::func;
	return execfunc(this, ship, equip);
}

namespace _func1250
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::HasType", typeid(bool (Store::*)(int )), ".554889e539b7b007", nullptr, 0, 0, &func);
}

bool Store::HasType(int type)
{
	typedef bool (*custom_arg_funcptr_t)(Store *this_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1250::func;
	return execfunc(this, type);
}

namespace _func1251
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::OnInit", typeid(void (Store::*)(ShipManager *, Equipment *, int )), "!.554889e5415741564155415453504189cf488955", nullptr, 0, 0, &func);
}

void Store::OnInit(ShipManager *shopper, Equipment *equip, int worldLevel)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *shopper_arg, Equipment *equip_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1251::func;
	return execfunc(this, shopper, equip, worldLevel);
}

namespace _func1252
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::CreateStoreBoxes", typeid(void (Store::*)(int , Equipment *)), "!.554889e54157415641554154534881ece80000004989d489", nullptr, 0, 0, &func);
}

void Store::CreateStoreBoxes(int type, Equipment *equip)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, int type_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1252::func;
	return execfunc(this, type, equip);
}

namespace _func1253
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::SetPosition", typeid(void (Store::*)(Point )), "!.554889e553504889fbe8", nullptr, 0, 0, &func);
}

void Store::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1253::func;
	return execfunc(this, position);
}

namespace _func1254
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::InitHeading", typeid(void (Store::*)(int , Point )), ".554889e541574156534883ec584989fe4c63fe0f", nullptr, 0, 0, &func);
}

void Store::InitHeading(int index, Point position)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, int index_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1254::func;
	return execfunc(this, index, position);
}

namespace _func1255
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::Close", typeid(void (Store::*)()), "!.554889e553504889fbc64308", nullptr, 0, 0, &func);
}

void Store::Close()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1255::func;
	return execfunc(this);
}

namespace _func1256
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::KeyDown", typeid(bool (Store::*)(SDLKey )), ".554889e54156534889fb83bbac070000", nullptr, 0, 0, &func);
}

bool Store::KeyDown(SDLKey key)
{
	typedef bool (*custom_arg_funcptr_t)(Store *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1256::func;
	return execfunc(this, key);
}

namespace _func1257
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::MouseMove", typeid(void (Store::*)(int , int )), "!.554889e54157415641554154534883ec584189d74189f449", nullptr, 0, 0, &func);
}

void Store::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1257::func;
	return execfunc(this, x, y);
}

namespace _func1258
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::MouseClick", typeid(void (Store::*)(int , int )), ".554889e54157415641554154534883ec684189d6", nullptr, 0, 0, &func);
}

void Store::MouseClick(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1258::func;
	return execfunc(this, x, y);
}

namespace _func1259
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::OnLoop", typeid(void (Store::*)()), ".554889e54156534989fe498b8668050000493986", nullptr, 0, 0, &func);
}

void Store::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1259::func;
	return execfunc(this);
}

namespace _func1260
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::DrawBuySellTabText", typeid(void (*)()), ".554889e541574156534883ec580f57c0", nullptr, 0, 0, &func);
}

void Store::DrawBuySellTabText()
{
	typedef void (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1260::func;
	return execfunc();
}

namespace _func1261
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::OnRender", typeid(void (Store::*)()), ".554889e54157415641554154534883ec684989ffe8c78e02", nullptr, 0, 0, &func);
}

void Store::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1261::func;
	return execfunc(this);
}

namespace _func1262
{
	static void *func = 0;
	static FunctionDefinition funcObj("Store::destructor", typeid(void (Store::*)()), "!.554889e54156534989fe488d05????????498906498b8668050000", nullptr, 0, 0, &func);
}

void Store::destructor()
{
	typedef void (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1262::func;
	return execfunc(this);
}

namespace _func1263
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::constructor", typeid(void (StoreBox::*)(const std::string &, ShipManager *, Equipment *)), ".554889e54157415641554154534883ec??48894da8", nullptr, 0, 0, &func);
}

void StoreBox::constructor(const std::string &_buttonImage, ShipManager *_shopper, Equipment *_equip)
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg, const std::string &_buttonImage_arg, ShipManager *_shopper_arg, Equipment *_equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1263::func;
	return execfunc(this, _buttonImage, _shopper, _equip);
}

namespace _func1264
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::SetPosition", typeid(void (StoreBox::*)(Point )), ".554889e54156534883ec104889fb4889f248c1ea20488b43", nullptr, 0, 0, &func);
}

void StoreBox::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1264::func;
	return execfunc(this, position);
}

namespace _func1265
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::InitBlueprint", typeid(void (StoreBox::*)(Blueprint *)), ".554889e541574156534883ec184989f64889fb41", nullptr, 0, 0, &func);
}

void StoreBox::InitBlueprint(Blueprint *bp)
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg, Blueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1265::func;
	return execfunc(this, bp);
}

namespace _func1266
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::OnLoop", typeid(void (StoreBox::*)()), "!.554889e55350488d5f2883bf", nullptr, 0, 0, &func);
}

void StoreBox::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1266::func;
	return execfunc(this);
}

namespace _func1267
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::OnRender", typeid(void (StoreBox::*)()), ".554889e541574156534883ec284989ff418a9f90", nullptr, 0, 0, &func);
}

void StoreBox::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1267::func;
	return execfunc(this);
}

namespace _func1268
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::MouseClick", typeid(void (StoreBox::*)(int , int )), ".554889e5807f7000", nullptr, 0, 0, &func);
}

void StoreBox::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1268::func;
	return execfunc(this, mX, mY);
}

namespace _func1269
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::Activate", typeid(void (StoreBox::*)()), "!.488b8778", nullptr, 0, 0, &func);
}

void StoreBox::Activate()
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1269::func;
	return execfunc(this);
}

namespace _func1270
{
	static void *func = 0;
	static FunctionDefinition funcObj("StoreBox::Purchase", typeid(void (StoreBox::*)()), ".554889e5534883ec384889fb0f57c00f", nullptr, 0, 0, &func);
}

void StoreBox::Purchase()
{
	typedef void (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1270::func;
	return execfunc(this);
}

namespace _func1271
{
	static void *func = 0;
	static FunctionDefinition funcObj("SuperShieldDrone::constructor", typeid(void (SuperShieldDrone::*)(int , int , DroneBlueprint *)), "554889e54157415641554154534883ec??4889fbe8????????488d05", nullptr, 0, 0, &func);
}

void SuperShieldDrone::constructor(int _iShipId, int _selfId, DroneBlueprint *_blueprint)
{
	typedef void (*custom_arg_funcptr_t)(SuperShieldDrone *this_arg, int _iShipId_arg, int _selfId_arg, DroneBlueprint *_blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1271::func;
	return execfunc(this, _iShipId, _selfId, _blueprint);
}

namespace _func1272
{
	static void *func = 0;
	static FunctionDefinition funcObj("SuperShieldDrone::OnLoop", typeid(void (SuperShieldDrone::*)()), ".554889e54156534883ec304889fbe8", nullptr, 0, 0, &func);
}

void SuperShieldDrone::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(SuperShieldDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1272::func;
	return execfunc(this);
}

namespace _func1273
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemBox::constructor", typeid(void (SystemBox::*)(Point , ShipSystem *, bool )), "!.554889e54157415641554154534881ec????????4189cf4889fb", nullptr, 0, 0, &func);
}

void SystemBox::constructor(Point _position, ShipSystem *_system, bool _playerUI)
{
	typedef void (*custom_arg_funcptr_t)(SystemBox *this_arg, Point _position_arg, ShipSystem *_system_arg, bool _playerUI_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1273::func;
	return execfunc(this, _position, _system, _playerUI);
}

namespace _func1274
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemBox::MouseMove", typeid(void (SystemBox::*)(int , int )), ".554889e54157415641554154534883ec184189d64189f748", nullptr, 0, 0, &func);
}

void SystemBox::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(SystemBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1274::func;
	return execfunc(this, x, y);
}

namespace _func1275
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemBox::MouseClick", typeid(bool (SystemBox::*)(bool )), ".554889e54156534883ec2089f34989fe", nullptr, 0, 0, &func);
}

bool SystemBox::MouseClick(bool shift)
{
	typedef bool (*custom_arg_funcptr_t)(SystemBox *this_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1275::func;
	return execfunc(this, shift);
}

namespace _func1276
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemBox::KeyDown", typeid(void (SystemBox::*)(SDLKey , bool )), ".554889e54157415653504189d74189f64889fbbe", nullptr, 0, 0, &func);
}

void SystemBox::KeyDown(SDLKey key, bool shift)
{
	typedef void (*custom_arg_funcptr_t)(SystemBox *this_arg, SDLKey key_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1276::func;
	return execfunc(this, key, shift);
}

namespace _func1277
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemBox::OnRender", typeid(void (SystemBox::*)(bool )), ".554889e54157415641554154534883ec284189f64889fb48", nullptr, 0, 0, &func);
}

void SystemBox::OnRender(bool ignoreStatus)
{
	typedef void (*custom_arg_funcptr_t)(SystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1277::func;
	return execfunc(this, ignoreStatus);
}

namespace _func1278
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemControl::GetPowerBars", typeid(SystemControl::PowerBars *(*)(int , int , int , bool )), ".554889e54157415641554154534881eca80000004189cc89", nullptr, 0, 0, &func);
}

SystemControl::PowerBars *SystemControl::GetPowerBars(int width, int height, int gap, bool useShieldGap)
{
	typedef SystemControl::PowerBars *(*custom_arg_funcptr_t)(int width_arg, int height_arg, int gap_arg, bool useShieldGap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1278::func;
	return execfunc(width, height, gap, useShieldGap);
}

namespace _func1279
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemControl::CreateSystemBoxes", typeid(void (SystemControl::*)()), "!.554889e54157415641554154534881ecb80000004889fb", nullptr, 0, 0, &func);
}

void SystemControl::CreateSystemBoxes()
{
	typedef void (*custom_arg_funcptr_t)(SystemControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1279::func;
	return execfunc(this);
}

Point *Global_SystemControl_weapon_position;

namespace _var1280
{
	static VariableDefinition varObj("Global_SystemControl_weapon_position", "!.488b45c0488905(???????\?)488d7dc031f631d2e8????????488b45c0488905(???????\?)", &Global_SystemControl_weapon_position, true, true);
}

Point *Global_SystemControl_drone_position;

namespace _var1281
{
	static VariableDefinition varObj("Global_SystemControl_drone_position", "", &Global_SystemControl_drone_position, true, true);
}

namespace _func1282
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemControl::GetSystemBox", typeid(SystemBox *(SystemControl::*)(int )), ".554889e5415741564155415453504189f74989fc498b442410493944", nullptr, 0, 0, &func);
}

SystemBox *SystemControl::GetSystemBox(int systemId)
{
	typedef SystemBox *(*custom_arg_funcptr_t)(SystemControl *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1282::func;
	return execfunc(this, systemId);
}

namespace _func1283
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemControl::RenderPowerBar", typeid(void (SystemControl::*)()), "!.554889e54157415641554154534883ec384989ff498b3fe8", nullptr, 0, 0, &func);
}

void SystemControl::RenderPowerBar()
{
	typedef void (*custom_arg_funcptr_t)(SystemControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1283::func;
	return execfunc(this);
}

namespace _func1284
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemCustomBox::constructor", typeid(void (SystemCustomBox::*)(Point , ShipSystem *, ShipManager *)), "554889e5415741564154534883ec404989ce4989f4", nullptr, 0, 0, &func);
}

void SystemCustomBox::constructor(Point _position, ShipSystem *_system, ShipManager *_ship)
{
	typedef void (*custom_arg_funcptr_t)(SystemCustomBox *this_arg, Point _position_arg, ShipSystem *_system_arg, ShipManager *_ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1284::func;
	return execfunc(this, _position, _system, _ship);
}

namespace _func1285
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemStoreBox::constructor", typeid(void (SystemStoreBox::*)(ShipManager *, Equipment *, int )), "554889e54157415641554154534881eca80000004189ce4889fb418d46fa", nullptr, 0, 0, &func);
}

void SystemStoreBox::constructor(ShipManager *_ship, Equipment *_equip, int _system)
{
	typedef void (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, ShipManager *_ship_arg, Equipment *_equip_arg, int _system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1285::func;
	return execfunc(this, _ship, _equip, _system);
}

namespace _func1286
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemStoreBox::SetExtraData", typeid(void (SystemStoreBox::*)(int )), ".554889e541574156534883ec184889fb89b3e001", nullptr, 0, 0, &func);
}

void SystemStoreBox::SetExtraData(int droneChoice)
{
	typedef void (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, int droneChoice_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1286::func;
	return execfunc(this, droneChoice);
}

namespace _func1287
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemStoreBox::CanHold", typeid(bool (SystemStoreBox::*)()), "!.554889e553504889fb4883bb78010000", nullptr, 0, 0, &func);
}

bool SystemStoreBox::CanHold()
{
	typedef bool (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1287::func;
	return execfunc(this);
}

namespace _func1288
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemStoreBox::MouseMove", typeid(void (SystemStoreBox::*)(int , int )), ".554889e5415741564154534883ec404189d64189", nullptr, 0, 0, &func);
}

void SystemStoreBox::MouseMove(int mouseX, int mouseY)
{
	typedef void (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1288::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func1289
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemStoreBox::Activate", typeid(void (SystemStoreBox::*)()), "!.554889e5534883ec184889fb488bbb78", nullptr, 0, 0, &func);
}

void SystemStoreBox::Activate()
{
	typedef void (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1289::func;
	return execfunc(this);
}

namespace _func1290
{
	static void *func = 0;
	static FunctionDefinition funcObj("SystemStoreBox::Purchase", typeid(void (SystemStoreBox::*)()), ".554889e54156534883ec404889fbe83d", nullptr, 0, 0, &func);
}

void SystemStoreBox::Purchase()
{
	typedef void (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1290::func;
	return execfunc(this);
}

namespace _func1291
{
	static void *func = 0;
	static FunctionDefinition funcObj("TabbedWindow::Close", typeid(void (TabbedWindow::*)()), "!.554889e553504889fb8b4368", nullptr, 0, 0, &func);
}

void TabbedWindow::Close()
{
	typedef void (*custom_arg_funcptr_t)(TabbedWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1291::func;
	return execfunc(this);
}

namespace _func1292
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportBox::constructor", typeid(void (TeleportBox::*)(Point , TeleportSystem *)), "554889e54157415641554154534883ec??4889d34989fdb9", nullptr, 0, 0, &func);
}

void TeleportBox::constructor(Point _position, TeleportSystem *_system)
{
	typedef void (*custom_arg_funcptr_t)(TeleportBox *this_arg, Point _position_arg, TeleportSystem *_system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1292::func;
	return execfunc(this, _position, _system);
}

namespace _func1293
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (TeleportSystem::*)()), ".554889e54156534189d64889fbe8", nullptr, 0, 0, &func);
}

namespace _func1294
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::constructor", typeid(void (TeleportSystem::*)(int , int , int , int )), ".554889e54156534189d64889fbe8", nullptr, 0, 0, &func);
}

void TeleportSystem::constructor(int _systemId, int _roomId, int _shipId, int _startingPower)
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int _systemId_arg, int _roomId_arg, int _shipId_arg, int _startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1294::func;
	return execfunc(this, _systemId, _roomId, _shipId, _startingPower);
}

namespace _func1295
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::OnLoop", typeid(void (TeleportSystem::*)()), ".554889e54156534883ec204889fbe84dd0ffff48", nullptr, 0, 0, &func);
}

void TeleportSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1295::func;
	return execfunc(this);
}

namespace _func1296
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::SetArmed", typeid(void (TeleportSystem::*)(int )), ".554889e54156534889fb4531f683fe02", nullptr, 0, 0, &func);
}

void TeleportSystem::SetArmed(int armed)
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int armed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1296::func;
	return execfunc(this, armed);
}

namespace _func1297
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::SetHackingLevel", typeid(void (TeleportSystem::*)(int )), ".554889e54156534189f64889fb4183fe027c1d83", nullptr, 0, 0, &func);
}

void TeleportSystem::SetHackingLevel(int hackingLevel)
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1297::func;
	return execfunc(this, hackingLevel);
}

namespace _func1298
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::ForceReady", typeid(void (TeleportSystem::*)()), "!.554889e5c7876402", nullptr, 0, 0, &func);
}

void TeleportSystem::ForceReady()
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1298::func;
	return execfunc(this);
}

namespace _func1299
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::GetChargedPercent", typeid(float (TeleportSystem::*)()), ".554889e5f30f108764020000f30f5905", nullptr, 0, 0, &func);
}

float TeleportSystem::GetChargedPercent()
{
	typedef float (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1299::func;
	return execfunc(this);
}

namespace _func1300
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::Charged", typeid(bool (TeleportSystem::*)()), "!.554889e553504889fbe8c2b6", nullptr, 0, 0, &func);
}

bool TeleportSystem::Charged()
{
	typedef bool (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1300::func;
	return execfunc(this);
}

namespace _func1301
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::ClearCrewLocations", typeid(void (TeleportSystem::*)()), "!.554889e54157415641554154534883ec184989fe41c78688", nullptr, 0, 0, &func);
}

void TeleportSystem::ClearCrewLocations()
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1301::func;
	return execfunc(this);
}

namespace _func1302
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::UpdateCrewLocation", typeid(void (TeleportSystem::*)(int )), ".554889e54863ce4c", nullptr, 0, 0, &func);
}

void TeleportSystem::UpdateCrewLocation(int slotId)
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int slotId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1302::func;
	return execfunc(this, slotId);
}

namespace _func1303
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::Jump", typeid(void (TeleportSystem::*)()), ".554889e553504889fbe802ca", nullptr, 0, 0, &func);
}

void TeleportSystem::Jump()
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1303::func;
	return execfunc(this);
}

namespace _func1304
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::CanSend", typeid(bool (TeleportSystem::*)()), ".554889e54156534883ec204889fb837b", nullptr, 0, 0, &func);
}

bool TeleportSystem::CanSend()
{
	typedef bool (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1304::func;
	return execfunc(this);
}

namespace _func1305
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::CanReceive", typeid(bool (TeleportSystem::*)()), ".554889e54156534189f64889fb80bb69", nullptr, 0, 0, &func);
}

bool TeleportSystem::CanReceive()
{
	typedef bool (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1305::func;
	return execfunc(this);
}

namespace _func1306
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::OnRenderFloor", typeid(void (TeleportSystem::*)()), ".554889e54157415641554154534883ec284989fe8a05", nullptr, 0, 0, &func);
}

void TeleportSystem::OnRenderFloor()
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1306::func;
	return execfunc(this);
}

namespace _func1307
{
	static void *func = 0;
	static FunctionDefinition funcObj("TeleportSystem::InitiateTeleport", typeid(void (TeleportSystem::*)()), ".554889e5534883ec184889fbe8bfaeff", nullptr, 0, 0, &func);
}

void TeleportSystem::InitiateTeleport()
{
	typedef void (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1307::func;
	return execfunc(this);
}

namespace _func1308
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::constructor", typeid(void (TextButton::*)()), "554889e54156534889fb488d055f??2800488903488d7b08e8????0a000f28??????20000f114310", nullptr, 0, 0, &func);
}

void TextButton::constructor()
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1308::func;
	return execfunc(this);
}

namespace _func1309
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "!.554889e553504889fb488d05", nullptr, 0, 0, &func);
}

void TextButton::destructor()
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1309::func;
	return execfunc(this);
}

namespace _func1310
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::SetInactiveColor", typeid(void (TextButton::*)(GL_Color )), "!.554889e580bf800000000075??c6878000000001488b05", nullptr, 0, 0, &func);
}

void TextButton::SetInactiveColor(GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1310::func;
	return execfunc(this, color);
}

namespace _func1311
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::SetActiveColor", typeid(void (TextButton::*)(GL_Color )), "!.554889e580bf800000000075??c6878000000001488b05", nullptr, 0, 0, &func);
}

void TextButton::SetActiveColor(GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1311::func;
	return execfunc(this, color);
}

namespace _func1312
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::SetSelectedColor", typeid(void (TextButton::*)(GL_Color )), "!.554889e580bf800000000075??c6878000000001488b05", nullptr, 0, 0, &func);
}

void TextButton::SetSelectedColor(GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1312::func;
	return execfunc(this, color);
}

namespace _func1313
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::SetTextColor", typeid(void (TextButton::*)(GL_Color )), ".554889e580bf800000000074", nullptr, 0, 0, &func);
}

void TextButton::SetTextColor(GL_Color color)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1313::func;
	return execfunc(this, color);
}

namespace _func1314
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::ResetPrimitives", typeid(void (TextButton::*)()), ".554889e553504889fb488b7b50e8", nullptr, 0, 0, &func);
}

void TextButton::ResetPrimitives()
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1314::func;
	return execfunc(this);
}

namespace _func1315
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::InitPrimitives", typeid(void (TextButton::*)()), "!.554889e54157415641554154534881ec8800000080bf8000", nullptr, 0, 0, &func);
}

void TextButton::InitPrimitives()
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1315::func;
	return execfunc(this);
}

namespace _func1316
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::OnInit", typeid(void (TextButton::*)(Point , Point , int , TextString *, int )), ".554889e54157415641554154534883ec??44894dd44d89c4", nullptr, 0, 0, &func);
}

void TextButton::OnInit(Point position, Point size, int cornerInset, TextString *buttonLabel, int font)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, Point position_arg, Point size_arg, int cornerInset_arg, TextString *buttonLabel_arg, int font_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1316::func;
	return execfunc(this, position, size, cornerInset, buttonLabel, font);
}

namespace _func1317
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::OnInitRect", typeid(void (TextButton::*)(Globals::Rect &, int , TextString &, int )), ".554889e54157415641554154534883ec??448945d04989cf", nullptr, 0, 0, &func);
}

void TextButton::OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, Globals::Rect &rect_arg, int cornerInset_arg, TextString &buttonLabel_arg, int font_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1317::func;
	return execfunc(this, rect, cornerInset, buttonLabel, font);
}

namespace _func1318
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::SetAutoWidth", typeid(void (TextButton::*)(bool , bool , int , int )), ".554889e54088b7d0", nullptr, 0, 0, &func);
}

void TextButton::SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, bool autoWidth_arg, bool autoRightAlign_arg, int margin_arg, int min_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1318::func;
	return execfunc(this, autoWidth, autoRightAlign, margin, min);
}

namespace _func1319
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::UpdateAutoWidth", typeid(void (TextButton::*)()), ".554889e541574156534883ec184889fb80bbd000", nullptr, 0, 0, &func);
}

void TextButton::UpdateAutoWidth()
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1319::func;
	return execfunc(this);
}

namespace _func1320
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), ".554889e5534883ec188b9f00", nullptr, 0, 0, &func);
}

int TextButton::GetIdealButtonWidth()
{
	typedef int (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1320::func;
	return execfunc(this);
}

namespace _func1321
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::GetSize", typeid(Point (TextButton::*)()), ".554889e553504889fbe8b2feffff488b", nullptr, 0, 0, &func);
}

Point TextButton::GetSize()
{
	typedef Point (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1321::func;
	return execfunc(this);
}

namespace _func1322
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::SetBaseImage", typeid(void (TextButton::*)(const std::string &, Point , int )), "!.554889e54157415653504189ce4989d7", nullptr, 0, 0, &func);
}

void TextButton::SetBaseImage(const std::string &name, Point position, int autoWidthMin)
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg, const std::string &name_arg, Point position_arg, int autoWidthMin_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1322::func;
	return execfunc(this, name, position, autoWidthMin);
}

namespace _func1323
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), ".554889e54157415641554154534883ec484989fde8c7fdff", nullptr, 0, 0, &func);
}

void TextButton::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1323::func;
	return execfunc(this);
}

namespace _func1324
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (TextInput::*)()), "!.554889e54157415653504189d74189f64889fb4889cee8", nullptr, 0, 0, &func);
}

namespace _func1325
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::constructor", typeid(void (TextInput::*)(int , TextInput::AllowedCharType , const std::string &)), "!.554889e54157415653504189d74189f64889fb4889cee8", nullptr, 0, 0, &func);
}

void TextInput::constructor(int _maxChars, TextInput::AllowedCharType _allowedCharType, const std::string &_prompt)
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg, int _maxChars_arg, TextInput::AllowedCharType _allowedCharType_arg, const std::string &_prompt_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1325::func;
	return execfunc(this, _maxChars, _allowedCharType, _prompt);
}

namespace _func1326
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::OnRender", typeid(void (TextInput::*)(int , Point )), "!.554889e54157415641554154534881ec980000004889d341", nullptr, 0, 0, &func);
}

void TextInput::OnRender(int font, Point position)
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg, int font_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1326::func;
	return execfunc(this, font, position);
}

namespace _func1327
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::OnLoop", typeid(void (TextInput::*)()), "!.554889e553504889fb8b4348", nullptr, 0, 0, &func);
}

void TextInput::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1327::func;
	return execfunc(this);
}

namespace _func1328
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::OnTextInput", typeid(void (TextInput::*)(int )), ".554889e54157415641554154534883ec284189f64889fb44", nullptr, 0, 0, &func);
}

void TextInput::OnTextInput(int asciiChar)
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg, int asciiChar_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1328::func;
	return execfunc(this, asciiChar);
}

namespace _func1329
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::OnTextEvent", typeid(void (TextInput::*)(CEvent::TextEvent )), ".554889e54157415653504889fb807b50", nullptr, 0, 0, &func);
}

void TextInput::OnTextEvent(CEvent::TextEvent event)
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1329::func;
	return execfunc(this, event);
}

namespace _func1330
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::Stop", typeid(void (TextInput::*)()), "!.554889e5c6475000", nullptr, 0, 0, &func);
}

void TextInput::Stop()
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1330::func;
	return execfunc(this);
}

namespace _func1331
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::GetActive", typeid(bool (TextInput::*)()), ".554889e58a47505d", nullptr, 0, 0, &func);
}

bool TextInput::GetActive()
{
	typedef bool (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1331::func;
	return execfunc(this);
}

namespace _func1332
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::GetText", typeid(std::string (TextInput::*)()), ".554889e553504889fb31d2b9ffffffff", nullptr, 0, 0, &func);
}

std::string TextInput::GetText()
{
	typedef std::string (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1332::func;
	return execfunc(this);
}

namespace _func1333
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::SetText", typeid(int (TextInput::*)(const std::string &)), "!.554889e54157415641554154534883ec184989ff498b4718", nullptr, 0, 0, &func);
}

int TextInput::SetText(const std::string &text)
{
	typedef int (*custom_arg_funcptr_t)(TextInput *this_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1333::func;
	return execfunc(this, text);
}

namespace _func1334
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextInput::Start", typeid(void (TextInput::*)()), ".554889e5534883ec184889fbc6435001", nullptr, 0, 0, &func);
}

void TextInput::Start()
{
	typedef void (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1334::func;
	return execfunc(this);
}

namespace _func1335
{
	static void *func = 0;
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string (TextLibrary::*)(const std::string &, const std::string &)), ".554889e54157415641554154534883ec184989d74889f349", nullptr, 0, 0, &func);
}

std::string TextLibrary::GetText(const std::string &name, const std::string &lang)
{
	typedef std::string (*custom_arg_funcptr_t)(TextLibrary *this_arg, const std::string &name_arg, const std::string &lang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1335::func;
	return execfunc(this, name, lang);
}

namespace _func1336
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(void (TimerHelper::*)(int )), ".554889e553504889fbc64311", nullptr, 0, 0, &func);
}

void TimerHelper::Start(int goal)
{
	typedef void (*custom_arg_funcptr_t)(TimerHelper *this_arg, int goal_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1336::func;
	return execfunc(this, goal);
}

namespace _func1337
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), ".554889e58a47115d", nullptr, 0, 0, &func);
}

bool TimerHelper::Running()
{
	typedef bool (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1337::func;
	return execfunc(this);
}

namespace _func1338
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), ".554889e589178977", nullptr, 0, 0, &func);
}

void TimerHelper::ResetMinMax(int min, int max)
{
	typedef void (*custom_arg_funcptr_t)(TimerHelper *this_arg, int min_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1338::func;
	return execfunc(this, min, max);
}

namespace _func1339
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), ".554889e5f30f104f08f30f5e", nullptr, 0, 0, &func);
}

void TimerHelper::SetMaxTime(float max)
{
	typedef void (*custom_arg_funcptr_t)(TimerHelper *this_arg, float max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1339::func;
	return execfunc(this, max);
}

namespace _func1340
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::Stop", typeid(void (TimerHelper::*)()), ".554889e5c64711??5dc3", nullptr, 0, 0, &func);
}

void TimerHelper::Stop()
{
	typedef void (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1340::func;
	return execfunc(this);
}

namespace _func1341
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), ".554889e553504889fb807b1100741e48", nullptr, 0, 0, &func);
}

void TimerHelper::Update()
{
	typedef void (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1341::func;
	return execfunc(this);
}

namespace _func1342
{
	static void *func = 0;
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), ".554889e553504889fb807b11007433f3", nullptr, 0, 0, &func);
}

bool TimerHelper::Done()
{
	typedef bool (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1342::func;
	return execfunc(this);
}

namespace _func1343
{
	static void *func = 0;
	static FunctionDefinition funcObj("TutorialManager::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (TutorialManager::*)()), "!554889e54156534889fbc60300488d7b08e8", nullptr, 0, 0, &func);
}

namespace _func1344
{
	static void *func = 0;
	static FunctionDefinition funcObj("TutorialManager::constructor", typeid(void (TutorialManager::*)()), "!.554889e54156534889fbc60300488d7b08e8", nullptr, 0, 0, &func);
}

void TutorialManager::constructor()
{
	typedef void (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1344::func;
	return execfunc(this);
}

namespace _func1345
{
	static void *func = 0;
	static FunctionDefinition funcObj("TutorialManager::Running", typeid(bool (TutorialManager::*)()), ".554889e58a075d", nullptr, 0, 0, &func);
}

bool TutorialManager::Running()
{
	typedef bool (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1345::func;
	return execfunc(this);
}

namespace _func1346
{
	static void *func = 0;
	static FunctionDefinition funcObj("TutorialManager::OnInit", typeid(void (TutorialManager::*)(ShipManager *, CommandGui *, CrewControl *, Upgrades *, CombatControl *, SystemControl *, TabbedWindow *)), ".554889e5415741564154534883ec604889fb488b4510488b", nullptr, 0, 0, &func);
}

void TutorialManager::OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *tabbed)
{
	typedef void (*custom_arg_funcptr_t)(TutorialManager *this_arg, ShipManager *ship_arg, CommandGui *gui_arg, CrewControl *crewControl_arg, Upgrades *upgradesScreen_arg, CombatControl *combatControl_arg, SystemControl *sysControl_arg, TabbedWindow *tabbed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1346::func;
	return execfunc(this, ship, gui, crewControl, upgradesScreen, combatControl, sysControl, tabbed);
}

TutorialManager *Global_TutorialManager_Tutorial;

namespace _var1347
{
	static VariableDefinition varObj("Global_TutorialManager_Tutorial", "!41807e200075??488d3d(???????\?)e8????????84c0", &Global_TutorialManager_Tutorial, true, true);
}

namespace _func1348
{
	static void *func = 0;
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), ".554889e54157415641554154534883ec??4989f64889fb4d89f7", nullptr, 0, 0, &func);
}

void UnlockArrow::constructor(Point _position, int _status, int _direction)
{
	typedef void (*custom_arg_funcptr_t)(UnlockArrow *this_arg, Point _position_arg, int _status_arg, int _direction_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1348::func;
	return execfunc(this, _position, _status, _direction);
}

namespace _func1349
{
	static void *func = 0;
	static FunctionDefinition funcObj("UnlockArrow::MouseMove", typeid(bool (UnlockArrow::*)(int , int )), ".554889e5837f0403", nullptr, 0, 0, &func);
}

bool UnlockArrow::MouseMove(int mouseX, int mouseY)
{
	typedef bool (*custom_arg_funcptr_t)(UnlockArrow *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1349::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func1350
{
	static void *func = 0;
	static FunctionDefinition funcObj("UnlockArrow::OnRender", typeid(void (UnlockArrow::*)()), ".554889e54156534883ec204889fb8b03", nullptr, 0, 0, &func);
}

void UnlockArrow::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(UnlockArrow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1350::func;
	return execfunc(this);
}

namespace _func1351
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::destructor", typeid(void (UpgradeBox::*)()), "!.554889e553504889fb488bbb????????e8????????488dbb", nullptr, 0, 0, &func);
}

void UpgradeBox::destructor()
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1351::func;
	return execfunc(this);
}

namespace _func1352
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::Accept", typeid(void (UpgradeBox::*)()), ".554889e5534883ec384889fb488b3b48", nullptr, 0, 0, &func);
}

void UpgradeBox::Accept()
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1352::func;
	return execfunc(this);
}

namespace _func1353
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::OnRender", typeid(void (UpgradeBox::*)()), "!.554889e54157415641554154534883ec484989fe4180be69", nullptr, 0, 0, &func);
}

void UpgradeBox::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1353::func;
	return execfunc(this);
}

namespace _func1354
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::MouseMove", typeid(void (UpgradeBox::*)(int , int )), ".554889e548833f00", nullptr, 0, 0, &func);
}

void UpgradeBox::MouseMove(int mouseX, int mouseY)
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1354::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func1355
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::MouseClick", typeid(void (UpgradeBox::*)(int , int )), ".554889e5534883ec184889fb488b0b48", nullptr, 0, 0, &func);
}

void UpgradeBox::MouseClick(int mouseX, int mouseY)
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1355::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func1356
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::MouseRightClick", typeid(void (UpgradeBox::*)(int , int )), ".554889e5534883ec184889fb488b0348", nullptr, 0, 0, &func);
}

void UpgradeBox::MouseRightClick(int mouseX, int mouseY)
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1356::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func1357
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::Undo", typeid(void (UpgradeBox::*)()), ".554889e553504889fb8b4320", nullptr, 0, 0, &func);
}

void UpgradeBox::Undo()
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1357::func;
	return execfunc(this);
}

namespace _func1358
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::constructorEmpty", typeid(void (UpgradeBox::*)(Point , bool )), ".554889e5415741564154534883ec204189d44989f6", nullptr, 0, 0, &func);
}

void UpgradeBox::constructorEmpty(Point _position, bool _isSubsystem)
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg, Point _position_arg, bool _isSubsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1358::func;
	return execfunc(this, _position, _isSubsystem);
}

namespace _func1359
{
	static void *func = 0;
	static FunctionDefinition funcObj("UpgradeBox::constructorSystem", typeid(void (UpgradeBox::*)(ShipManager *, ShipSystem *, Point , bool )), ".554889e54157415641554154534883ec684589c6", nullptr, 0, 0, &func);
}

void UpgradeBox::constructorSystem(ShipManager *_ship, ShipSystem *_system, Point _position, bool _isSubsystem)
{
	typedef void (*custom_arg_funcptr_t)(UpgradeBox *this_arg, ShipManager *_ship_arg, ShipSystem *_system_arg, Point _position_arg, bool _isSubsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1359::func;
	return execfunc(this, _ship, _system, _position, _isSubsystem);
}

namespace _func1360
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::ClearUpgradeBoxes", typeid(void (Upgrades::*)()), "554889e54157415653504989fe498b4628498b4e304889ca", nullptr, 0, 0, &func);
}

void Upgrades::ClearUpgradeBoxes()
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1360::func;
	return execfunc(this);
}

namespace _func1361
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::OnInit", typeid(void (Upgrades::*)(ShipManager *)), "!.554889e54157415641554154534881ecc80000004889fbc6", nullptr, 0, 0, &func);
}

void Upgrades::OnInit(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1361::func;
	return execfunc(this, ship);
}

namespace _func1362
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::Close", typeid(void (Upgrades::*)()), "!.554889e553504889fb807b0800745e48", nullptr, 0, 0, &func);
}

void Upgrades::Close()
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1362::func;
	return execfunc(this);
}

namespace _func1363
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::ConfirmUpgrades", typeid(void (Upgrades::*)()), ".554889e541574156534883ec184989ff498b4728", nullptr, 0, 0, &func);
}

void Upgrades::ConfirmUpgrades()
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1363::func;
	return execfunc(this);
}

namespace _func1364
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::MouseMove", typeid(void (Upgrades::*)(int , int )), "!.554889e5415741564154534189d64189f74989fce8????fa", nullptr, 0, 0, &func);
}

void Upgrades::MouseMove(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1364::func;
	return execfunc(this, mX, mY);
}

namespace _func1365
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::OnLoop", typeid(void (Upgrades::*)()), ".554889e54157415641554154534881ec980000004989ff41", nullptr, 0, 0, &func);
}

void Upgrades::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1365::func;
	return execfunc(this);
}

namespace _func1366
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::MouseClick", typeid(void (Upgrades::*)(int , int )), ".554889e5415741564154534883ec204989fee8", nullptr, 0, 0, &func);
}

void Upgrades::MouseClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1366::func;
	return execfunc(this, mX, mY);
}

namespace _func1367
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::MouseRightClick", typeid(void (Upgrades::*)(int , int )), "!.554889e54156534989fe498b462849394630742dbb0100000031c90f1f440000488b3cc8e857f2ff", nullptr, 0, 0, &func);
}

void Upgrades::MouseRightClick(int mX, int mY)
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1367::func;
	return execfunc(this, mX, mY);
}

namespace _func1368
{
	static void *func = 0;
	static FunctionDefinition funcObj("Upgrades::OnRender", typeid(void (Upgrades::*)()), ".554889e54157415641554154534883ec484989fd498b7d20", nullptr, 0, 0, &func);
}

void Upgrades::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1368::func;
	return execfunc(this);
}

namespace _func1369
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (WarningMessage::*)()), "!.554889e54157415653504889fb488d05????????66480f6ec0", nullptr, 0, 0, &func);
}

namespace _func1370
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::constructor", typeid(void (WarningMessage::*)()), "!.554889e54157415653504889fb488d05????????66480f6ec0", nullptr, 0, 0, &func);
}

void WarningMessage::constructor()
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1370::func;
	return execfunc(this);
}

namespace _func1371
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::InitImage", typeid(void (WarningMessage::*)(const std::string &, Point , float , bool )), ".554889e54157415641554154534883ec18894dd0", nullptr, 0, 0, &func);
}

void WarningMessage::InitImage(const std::string &imageName, Point position, float time, bool flash)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &imageName_arg, Point position_arg, float time_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1371::func;
	return execfunc(this, imageName, position, time, flash);
}

namespace _func1372
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::InitText", typeid(void (WarningMessage::*)(const TextString &, Point , float , GL_Color , bool , bool )), ".554889e5415741564154534883ec304589c64189", nullptr, 0, 0, &func);
}

void WarningMessage::InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, Point position_arg, float time_arg, GL_Color textColor_arg, bool centerText_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1372::func;
	return execfunc(this, text, position, time, textColor, centerText, flash);
}

namespace _func1373
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::OnLoop", typeid(void (WarningMessage::*)()), "!.554889e54156534889fb4c8d73084c89", nullptr, 0, 0, &func);
}

void WarningMessage::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1373::func;
	return execfunc(this);
}

namespace _func1374
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::OnRender", typeid(void (WarningMessage::*)()), ".554889e553504889fb807b1e", nullptr, 0, 0, &func);
}

void WarningMessage::OnRender()
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1374::func;
	return execfunc(this);
}

namespace _func1375
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::RenderWithAlpha", typeid(void (WarningMessage::*)(float )), ".554889e54157415641554154534883ec480f2945", nullptr, 0, 0, &func);
}

void WarningMessage::RenderWithAlpha(float alpha)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1375::func;
	return execfunc(this, alpha);
}

namespace _func1376
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::SetImage", typeid(void (WarningMessage::*)(const std::string &)), "!.554889e5415741564155415453504989f64989fc41807c24", nullptr, 0, 0, &func);
}

void WarningMessage::SetImage(const std::string &imageName)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &imageName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1376::func;
	return execfunc(this, imageName);
}

namespace _func1377
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &)), ".554889e5415741564155415453504989f64889fb807b3000", nullptr, 0, 0, &func);
}

void WarningMessage::SetText(const TextString &text)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1377::func;
	return execfunc(this, text);
}

namespace _func1378
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &, GL_Color )), ".554889e54157415641554154534883ec284989f64889fb80", nullptr, 0, 0, &func);
}

void WarningMessage::SetText(const TextString &text, GL_Color textColor)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, GL_Color textColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1378::func;
	return execfunc(this, text, textColor);
}

namespace _func1379
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::SetPosition", typeid(void (WarningMessage::*)(Point )), "!.554889e54889f248", nullptr, 0, 0, &func);
}

void WarningMessage::SetPosition(Point position)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1379::func;
	return execfunc(this, position);
}

namespace _func1380
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::SetLoop", typeid(void (WarningMessage::*)(bool )), "!.554889e54883c708400fb6f6", nullptr, 0, 0, &func);
}

void WarningMessage::SetLoop(bool loop)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1380::func;
	return execfunc(this, loop);
}

namespace _func1381
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::SetSound", typeid(void (WarningMessage::*)(const std::string &)), "!.554889e54881c7????????5de9", nullptr, 0, 0, &func);
}

void WarningMessage::SetSound(const std::string &sound)
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1381::func;
	return execfunc(this, sound);
}

namespace _func1382
{
	static void *func = 0;
	static FunctionDefinition funcObj("WarningMessage::Start", typeid(void (WarningMessage::*)()), "!.554889e54156534889fb807b1c007405", nullptr, 0, 0, &func);
}

void WarningMessage::Start()
{
	typedef void (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1382::func;
	return execfunc(this);
}

namespace _func1383
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponAnimation::SetFireTime", typeid(void (WeaponAnimation::*)(float )), "554889e58b4708f30f2ac82b", nullptr, 0, 0, &func);
}

void WeaponAnimation::SetFireTime(float time)
{
	typedef void (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1383::func;
	return execfunc(this, time);
}

namespace _func1384
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponAnimation::GetSlide", typeid(Pointf (WeaponAnimation::*)()), "!.554889e5534883ec??4889fb488dbb28010000", nullptr, 0, 0, &func);
}

Pointf WeaponAnimation::GetSlide()
{
	typedef Pointf (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1384::func;
	return execfunc(this);
}

namespace _func1385
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponAnimation::StartFire", typeid(bool (WeaponAnimation::*)()), ".554889e553504889fb80bbf1", nullptr, 0, 0, &func);
}

bool WeaponAnimation::StartFire()
{
	typedef bool (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1385::func;
	return execfunc(this);
}

namespace _func1386
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponAnimation::Update", typeid(void (WeaponAnimation::*)()), ".554889e54157415653504889fb448bb3", nullptr, 0, 0, &func);
}

void WeaponAnimation::Update()
{
	typedef void (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1386::func;
	return execfunc(this);
}

namespace _func1387
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponBlueprint::GetDescription", typeid(std::string (WeaponBlueprint::*)(bool )), "!.554889e54157415641554154534881ec????????8995????????4889f3", nullptr, 0, 0, &func);
}

std::string WeaponBlueprint::GetDescription(bool tooltip)
{
	typedef std::string (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1387::func;
	return execfunc(this, tooltip);
}

namespace _func1388
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponBlueprint::RenderIcon", typeid(void (WeaponBlueprint::*)(float )), "!.554889e5488db7b8", nullptr, 0, 0, &func);
}

void WeaponBlueprint::RenderIcon(float scale)
{
	typedef void (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg, float scale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1388::func;
	return execfunc(this, scale);
}

namespace _func1389
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponBlueprint::destructor", typeid(void (WeaponBlueprint::*)()), "!.554889e54157415653504989fe488d05????????49890641f686", nullptr, 0, 0, &func);
}

void WeaponBlueprint::destructor()
{
	typedef void (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1389::func;
	return execfunc(this);
}

namespace _func1390
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponBox::GenerateTooltip", typeid(std::string (WeaponBox::*)()), "554889e541574156534883ec384889f34989fe48", nullptr, 0, 0, &func);
}

std::string WeaponBox::GenerateTooltip()
{
	typedef std::string (*custom_arg_funcptr_t)(WeaponBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1390::func;
	return execfunc(this);
}

namespace _func1391
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponBox::RenderBox", typeid(void (WeaponBox::*)(bool , bool )), "!.554889e54157415641554154534881ec980000004989fe40", nullptr, 0, 0, &func);
}

void WeaponBox::RenderBox(bool dragging, bool flashPowerBox)
{
	typedef void (*custom_arg_funcptr_t)(WeaponBox *this_arg, bool dragging_arg, bool flashPowerBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1391::func;
	return execfunc(this, dragging, flashPowerBox);
}

namespace _func1392
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::constructor", typeid(void (WeaponControl::*)()), ".554889e54157415641554154534883ec684989febe", nullptr, 0, 0, &func);
}

void WeaponControl::constructor()
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1392::func;
	return execfunc(this);
}

namespace _func1393
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::OnLanguageChange", typeid(void (WeaponControl::*)()), ".554889e54157415641554154534883ec684989fce8????f6", nullptr, 0, 0, &func);
}

void WeaponControl::OnLanguageChange()
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1393::func;
	return execfunc(this);
}

namespace _func1394
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::OnRender", typeid(void (WeaponControl::*)(bool )), "!.554889e54157415653504189f64989ff498b7f18", nullptr, 0, 0, &func);
}

void WeaponControl::OnRender(bool front)
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool front_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1394::func;
	return execfunc(this, front);
}

namespace _func1395
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::RenderBeamAiming", typeid(void (*)(Pointf , Pointf , bool )), ".554889e541574156534883ec584189fe", nullptr, 0, 0, &func);
}

void WeaponControl::RenderBeamAiming(Pointf one, Pointf two, bool bAutoFire)
{
	typedef void (*custom_arg_funcptr_t)(Pointf one_arg, Pointf two_arg, bool bAutoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1395::func;
	return execfunc(one, two, bAutoFire);
}

namespace _func1396
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::RenderAiming", typeid(void (WeaponControl::*)()), "!.554889e54157415641554154534883ec48488b77", nullptr, 0, 0, &func);
}

void WeaponControl::RenderAiming()
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1396::func;
	return execfunc(this);
}

namespace _func1397
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::RenderSelfAiming", typeid(void (WeaponControl::*)()), "!.554889e54157415641554154534883ec58488b77", nullptr, 0, 0, &func);
}

void WeaponControl::RenderSelfAiming()
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1397::func;
	return execfunc(this);
}

namespace _func1398
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::LButton", typeid(bool (WeaponControl::*)(int , int , bool )), "!.80bf3001000000742580bf31010000", nullptr, 0, 0, &func);
}

bool WeaponControl::LButton(int x, int y, bool holdingShift)
{
	typedef bool (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg, bool holdingShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1398::func;
	return execfunc(this, x, y, holdingShift);
}

namespace _func1399
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::SetAutofiring", typeid(void (WeaponControl::*)(bool , bool )), ".554889e5415741564154534883ec604189d64989", nullptr, 0, 0, &func);
}

void WeaponControl::SetAutofiring(bool on, bool simple)
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool on_arg, bool simple_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1399::func;
	return execfunc(this, on, simple);
}

namespace _func1400
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::MouseMove", typeid(void (WeaponControl::*)(int , int )), "!.554889e54157415653504189d64189f74889fbe8????f6ff", nullptr, 0, 0, &func);
}

void WeaponControl::MouseMove(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1400::func;
	return execfunc(this, x, y);
}

namespace _func1401
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::KeyDown", typeid(bool (WeaponControl::*)(SDLKey )), ".554889e541574156534883ec184189f7", nullptr, 0, 0, &func);
}

bool WeaponControl::KeyDown(SDLKey key)
{
	typedef bool (*custom_arg_funcptr_t)(WeaponControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1401::func;
	return execfunc(this, key);
}

namespace _func1402
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::LinkShip", typeid(void (WeaponControl::*)(ShipManager *)), "!.554889e5534883ec484889fbe8????f6", nullptr, 0, 0, &func);
}

void WeaponControl::LinkShip(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1402::func;
	return execfunc(this, ship);
}

namespace _func1403
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::HolderLabel", typeid(TextString (WeaponControl::*)()), ".554889e5534883ec184889fb0f57c00f2945e048c745f000000000c645e01a48b86e735f", nullptr, 0, 0, &func);
}

TextString WeaponControl::HolderLabel()
{
	typedef TextString (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1403::func;
	return execfunc(this);
}

namespace _func1404
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::ArmamentHotkey", typeid(SDLKey (WeaponControl::*)(unsigned int )), ".554889e5534883ec38ffc68975f4488d5dc0488d75f44889dfe8????efff488d", nullptr, 0, 0, &func);
}

SDLKey WeaponControl::ArmamentHotkey(unsigned int i)
{
	typedef SDLKey (*custom_arg_funcptr_t)(WeaponControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1404::func;
	return execfunc(this, i);
}

namespace _func1405
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponControl::Fire", typeid(void (WeaponControl::*)(std::vector<Pointf> &, int , bool )), "!.554889e54157415641554154534883ec384889f34989fc498bbc24d8", nullptr, 0, 0, &func);
}

void WeaponControl::Fire(std::vector<Pointf> &points, int target, bool autoFire)
{
	typedef void (*custom_arg_funcptr_t)(WeaponControl *this_arg, std::vector<Pointf> &points_arg, int target_arg, bool autoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1405::func;
	return execfunc(this, points, target, autoFire);
}

namespace _func1406
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponStoreBox::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (WeaponStoreBox::*)()), "554889e5534883ec184889fbbf20000000e8????1900488945f00f2805????19000f2945e048b9795f776561", nullptr, 0, 0, &func);
}

namespace _func1407
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponStoreBox::constructor", typeid(void (WeaponStoreBox::*)(ShipManager *, Equipment *, const WeaponBlueprint *)), ".554889e5534883ec184889fbbf20000000e8????1900488945f00f2805????19000f2945e048b9795f776561", nullptr, 0, 0, &func);
}

void WeaponStoreBox::constructor(ShipManager *_ship, Equipment *_equipScreen, const WeaponBlueprint *_weaponBp)
{
	typedef void (*custom_arg_funcptr_t)(WeaponStoreBox *this_arg, ShipManager *_ship_arg, Equipment *_equipScreen_arg, const WeaponBlueprint *_weaponBp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1407::func;
	return execfunc(this, _ship, _equipScreen, _weaponBp);
}

namespace _func1408
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponSystem::RemoveWeapon", typeid(void (WeaponSystem::*)(int )), ".554889e54157415641554154534883ec184989fc85f60f88", nullptr, 0, 0, &func);
}

void WeaponSystem::RemoveWeapon(int slot)
{
	typedef void (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1408::func;
	return execfunc(this, slot);
}

namespace _func1409
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponSystem::SetBonusPower", typeid(void (WeaponSystem::*)(int , int )), "!.554889e54156534189f64889fbe82e9f", nullptr, 0, 0, &func);
}

void WeaponSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1409::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func1410
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponSystem::OnLoop", typeid(void (WeaponSystem::*)()), ".554889e54157415641554154534883ec184989fee857aeff", nullptr, 0, 0, &func);
}

void WeaponSystem::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(WeaponSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1410::func;
	return execfunc(this);
}

namespace _func1411
{
	static void *func = 0;
	static FunctionDefinition funcObj("WeaponSystemBox::constructor", typeid(void (WeaponSystemBox::*)(Point , ShipSystem *, WeaponControl *)), "!554889e54156534889fb488d05????????4889034c8bb3????????4d85f6", nullptr, 0, 0, &func);
}

void WeaponSystemBox::constructor(Point _position, ShipSystem *_system, WeaponControl *_weapCtrl)
{
	typedef void (*custom_arg_funcptr_t)(WeaponSystemBox *this_arg, Point _position_arg, ShipSystem *_system_arg, WeaponControl *_weapCtrl_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1411::func;
	return execfunc(this, _position, _system, _weapCtrl);
}

namespace _func1412
{
	static void *func = 0;
	static FunctionDefinition funcObj("WindowFrame::constructor", typeid(void (WindowFrame::*)(int , int , int , int )), ".554889e54157415641554154534881ec????????4189cd4189f7", nullptr, 0, 0, &func);
}

void WindowFrame::constructor(int _x, int _y, int _w, int _h)
{
	typedef void (*custom_arg_funcptr_t)(WindowFrame *this_arg, int _x_arg, int _y_arg, int _w_arg, int _h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1412::func;
	return execfunc(this, _x, _y, _w, _h);
}

namespace _func1413
{
	static void *func = 0;
	static FunctionDefinition funcObj("WindowFrame::DO_NOT_HOOK_FALSE_DESTRUCTOR", typeid(void (WindowFrame::*)()), "!.554889e553504889fb488b7b10", nullptr, 0, 0, &func);
}

namespace _func1414
{
	static void *func = 0;
	static FunctionDefinition funcObj("WindowFrame::destructor", typeid(void (WindowFrame::*)()), "!.554889e553504889fb488b7b10", nullptr, 0, 0, &func);
}

void WindowFrame::destructor()
{
	typedef void (*custom_arg_funcptr_t)(WindowFrame *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1414::func;
	return execfunc(this);
}

namespace _func1415
{
	static void *func = 0;
	static FunctionDefinition funcObj("WindowFrame::Draw", typeid(void (WindowFrame::*)(int , int )), "!.554889e54157415653504189d789f34989fee8", nullptr, 0, 0, &func);
}

void WindowFrame::Draw(int x, int y)
{
	typedef void (*custom_arg_funcptr_t)(WindowFrame *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1415::func;
	return execfunc(this, x, y);
}

namespace _func1416
{
	static void *func = 0;
	static FunctionDefinition funcObj("WindowFrame::DrawMask", typeid(void (WindowFrame::*)(int )), ".554889e553504889fbbf0100", nullptr, 0, 0, &func);
}

void WindowFrame::DrawMask(int stencilBits)
{
	typedef void (*custom_arg_funcptr_t)(WindowFrame *this_arg, int stencilBits_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1416::func;
	return execfunc(this, stencilBits);
}

namespace _func1417
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::DO_NOT_HOOK_FALSE_CONSTRUCTOR", typeid(void (WorldManager::*)()), ".554889e553504889fb488d7b1048c743", nullptr, 0, 0, &func);
}

namespace _func1418
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(void (WorldManager::*)()), ".554889e553504889fb488d7b1048c743", nullptr, 0, 0, &func);
}

void WorldManager::constructor()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1418::func;
	return execfunc(this);
}

namespace _func1419
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), "!.554889e54157415653504989ff4d8d77104c89f7", nullptr, 0, 0, &func);
}

int WorldManager::OnInit()
{
	typedef int (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1419::func;
	return execfunc(this);
}

namespace _func1420
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::LoadGame", typeid(void (WorldManager::*)(const std::string &)), ".554889e54157415641554154534881ecf8020000", nullptr, 0, 0, &func);
}

void WorldManager::LoadGame(const std::string &fileName)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1420::func;
	return execfunc(this, fileName);
}

namespace _func1421
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::ClearLocation", typeid(void (WorldManager::*)()), ".554889e5415741564154534881ecc003", nullptr, 0, 0, &func);
}

void WorldManager::ClearLocation()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1421::func;
	return execfunc(this);
}

namespace _func1422
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(void (WorldManager::*)(Location *)), ".554889e54157415641554154534881ec38060000", nullptr, 0, 0, &func);
}

void WorldManager::CreateLocation(Location *loc)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1422::func;
	return execfunc(this, loc);
}

namespace _func1423
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(void (WorldManager::*)(LocationEvent *)), "!.554889e54157415641554154534881ec18060000", nullptr, 0, 0, &func);
}

void WorldManager::CreateChoiceBox(LocationEvent *event)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1423::func;
	return execfunc(this, event);
}

namespace _func1424
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(void (WorldManager::*)(std::vector<StatusEffect> &)), "!.554889e5415741564155415453504989f64889fb498b0649", nullptr, 0, 0, &func);
}

void WorldManager::CheckStatusEffects(std::vector<StatusEffect> &vec)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, std::vector<StatusEffect> &vec_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1424::func;
	return execfunc(this, vec);
}

namespace _func1425
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(void (WorldManager::*)(ShipManager *)), ".554889e541574156534883ec384989f64989ff49", nullptr, 0, 0, &func);
}

void WorldManager::StartGame(ShipManager *ship)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1425::func;
	return execfunc(this, ship);
}

namespace _func1426
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(void (WorldManager::*)()), ".554889e541574156534883ec384989fe498b06bf", nullptr, 0, 0, &func);
}

void WorldManager::CreateNewGame()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1426::func;
	return execfunc(this);
}

namespace _func1427
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(CompleteShip *(WorldManager::*)(ShipEvent *, bool )), ".554889e54157415641554154534881ec380a0000", nullptr, 0, 0, &func);
}

CompleteShip *WorldManager::CreateShip(ShipEvent *shipEvent, bool boss)
{
	typedef CompleteShip *(*custom_arg_funcptr_t)(WorldManager *this_arg, ShipEvent *shipEvent_arg, bool boss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1427::func;
	return execfunc(this, shipEvent, boss);
}

namespace _func1428
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CreateStore", typeid(void (WorldManager::*)(LocationEvent *)), ".554889e54156534889f34989fe488bb3", nullptr, 0, 0, &func);
}

void WorldManager::CreateStore(LocationEvent *event)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1428::func;
	return execfunc(this, event);
}

namespace _func1429
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(void (WorldManager::*)(int , int )), "!.554889e553504889fbffce83", nullptr, 0, 0, &func);
}

void WorldManager::ModifyEnvironment(int envFlag, int envTarget)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, int envFlag_arg, int envTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1429::func;
	return execfunc(this, envFlag, envTarget);
}

namespace _func1430
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::AddBoarders", typeid(bool (WorldManager::*)(BoardingEvent &)), ".554889e5415741564154534883ec204989f6488b", nullptr, 0, 0, &func);
}

bool WorldManager::AddBoarders(BoardingEvent &boardingEvent)
{
	typedef bool (*custom_arg_funcptr_t)(WorldManager *this_arg, BoardingEvent &boardingEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1430::func;
	return execfunc(this, boardingEvent);
}

namespace _func1431
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(LocationEvent *(WorldManager::*)(LocationEvent *)), "!.554889e54157415641554154534881ec680a0000", nullptr, 0, 0, &func);
}

LocationEvent *WorldManager::ModifyResources(LocationEvent *event)
{
	typedef LocationEvent *(*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1431::func;
	return execfunc(this, event);
}

namespace _func1432
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::CheckRequirements", typeid(bool (WorldManager::*)(LocationEvent *, bool )), ".554889e5415741564154534883ec204889f34989", nullptr, 0, 0, &func);
}

bool WorldManager::CheckRequirements(LocationEvent *event, bool hidden)
{
	typedef bool (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg, bool hidden_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1432::func;
	return execfunc(this, event, hidden);
}

namespace _func1433
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::ModifyStatusEffect", typeid(void (WorldManager::*)(StatusEffect , ShipManager *, int )), "!.554889e5415741564155415453504489c34989ce", nullptr, 0, 0, &func);
}

void WorldManager::ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, StatusEffect effect_arg, ShipManager *target_arg, int targetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1433::func;
	return execfunc(this, effect, target, targetType);
}

namespace _func1434
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(void (WorldManager::*)(LocationEvent *)), ".554889e54157415641554154534881ecc8050000", nullptr, 0, 0, &func);
}

void WorldManager::UpdateLocation(LocationEvent *event)
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1434::func;
	return execfunc(this, event);
}

namespace _func1435
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::PauseLoop", typeid(void (WorldManager::*)()), "!.554889e54157415641554154534883ec784989fd498b7d00", nullptr, 0, 0, &func);
}

void WorldManager::PauseLoop()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1435::func;
	return execfunc(this);
}

namespace _func1436
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), "!.554889e553504889fb488d7b10e8????e5ff84c0", nullptr, 0, 0, &func);
}

bool WorldManager::HostileEnvironment()
{
	typedef bool (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1436::func;
	return execfunc(this);
}

namespace _func1437
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(void (WorldManager::*)()), ".554889e54157415641554154534881ece8030000", nullptr, 0, 0, &func);
}

void WorldManager::OnLoop()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1437::func;
	return execfunc(this);
}

namespace _func1438
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::SaveGame", typeid(void (WorldManager::*)()), ".554889e54157415641554154534883ec184989fd498bbdd0", nullptr, 0, 0, &func);
}

void WorldManager::SaveGame()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1438::func;
	return execfunc(this);
}

namespace _func1439
{
	static void *func = 0;
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(void (WorldManager::*)()), "!.554889e54156534889fbe8c1", nullptr, 0, 0, &func);
}

void WorldManager::Restart()
{
	typedef void (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1439::func;
	return execfunc(this);
}

namespace _func1440
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::font_data::init", typeid(void (freetype::font_data::*)(const void *, int , unsigned int , bool )), "!554889e5535089d04889fb89c9", nullptr, 0, 0, &func);
}

void freetype::font_data::init(const void *buffer, int bufferSize, unsigned int h, bool glow)
{
	typedef void (*custom_arg_funcptr_t)(freetype::font_data *this_arg, const void *buffer_arg, int bufferSize_arg, unsigned int h_arg, bool glow_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1440::func;
	return execfunc(this, buffer, bufferSize, h, glow);
}

namespace _func1441
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::font_data::init_bitmap", typeid(void (freetype::font_data::*)(const void *, int , int , int )), "!.554889e54157", nullptr, 0, 0, &func);
}

void freetype::font_data::init_bitmap(const void *buffer, int bufferSize, int size, int h)
{
	typedef void (*custom_arg_funcptr_t)(freetype::font_data *this_arg, const void *buffer_arg, int bufferSize_arg, int size_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1441::func;
	return execfunc(this, buffer, bufferSize, size, h);
}

namespace _func1442
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::font_data::clean", typeid(void (freetype::font_data::*)()), "!.554889e5", nullptr, 0, 0, &func);
}

void freetype::font_data::clean()
{
	typedef void (*custom_arg_funcptr_t)(freetype::font_data *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1442::func;
	return execfunc(this);
}

namespace _func1443
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_print", typeid(Pointf (*)(int , float , float , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

Pointf freetype::easy_print(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1443::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1444
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_printRightAlign", typeid(Pointf (*)(int , float , float , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

Pointf freetype::easy_printRightAlign(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1444::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1445
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_printNewlinesCentered", typeid(Pointf (*)(int , float , float , int , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

Pointf freetype::easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1445::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1446
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(Pointf (*)(int , float , float , int , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

Pointf freetype::easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1446::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1447
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_measurePrintLines", typeid(Pointf (*)(int , float , float , int , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

Pointf freetype::easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1447::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1448
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_measureWidth", typeid(int (*)(int , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

int freetype::easy_measureWidth(int fontSize, const std::string &text)
{
	typedef int (*custom_arg_funcptr_t)(int fontSize_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1448::func;
	return execfunc(fontSize, text);
}

namespace _func1449
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_printCenter", typeid(Pointf (*)(int , float , float , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

Pointf freetype::easy_printCenter(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1449::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1450
{
	static void *func = 0;
	static FunctionDefinition funcObj("freetype::easy_printAutoShrink", typeid(void (*)(int , float , float , int , bool , const std::string &)), "!.554889e54157415641554154534883ec", nullptr, 0, 0, &func);
}

void freetype::easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text)
{
	typedef void (*custom_arg_funcptr_t)(int fontId_arg, float x_arg, float y_arg, int maxWidth_arg, bool centered_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1450::func;
	return execfunc(fontId, x, y, maxWidth, centered, text);
}

namespace _func1451
{
	static void *func = 0;
	static FunctionDefinition funcObj("font_height", typeid(float (*)(int , float )), ".554889e5535085ff", nullptr, 0, 0, &func);
}

float __stdcall font_height(int font_id, float size)
{
	typedef float (*custom_arg_funcptr_t)(int font_id_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1451::func;
	return execfunc(font_id, size);
}

namespace _func1452
{
	static void *func = 0;
	static FunctionDefinition funcObj("font_baseline", typeid(float (*)(int , float )), ".554889e5535085ff", nullptr, 0, 0, &func);
}

float __stdcall font_baseline(int font_id, float size)
{
	typedef float (*custom_arg_funcptr_t)(int font_id_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1452::func;
	return execfunc(font_id, size);
}

float *Global_freetype_sil_freetype_outline;

namespace _var1453
{
	static VariableDefinition varObj("Global_freetype_sil_freetype_outline", "!.488b7b18f30f1005(???????\?)", &Global_freetype_sil_freetype_outline);
}

