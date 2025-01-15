#include "FTLGameWin32.h"
#include "zhl_internal.h"

#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
#elif defined(__linux__)
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
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(void (AchievementTracker::*)()), "57b8????????8d7c240883e4f0ff77fc5589e5575653e8????????8d9da4fffeff29c48db5acfffeff", argdata, 1, 5, &func);
}

void AchievementTracker::LoadAchievementDescriptions()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func0::func;
	return execfunc(this);
}

namespace _func1
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(std::vector<CAchievement*> (AchievementTracker::*)(const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b40048b3f894db4c744240802000000c744240400000000", argdata, 3, 1, &func);
}

std::vector<CAchievement*> AchievementTracker::GetShipAchievements(const std::string &ship)
{
	typedef std::vector<CAchievement*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1::func;
	return execfunc(this, ship);
}

namespace _func2
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::CheckShipAchievements", typeid(void (AchievementTracker::*)(int , bool )), ".5789ca8d7c240883e4f0ff77fc5589e557565381ec8c000000", argdata, 3, 5, &func);
}

void AchievementTracker::CheckShipAchievements(int shipId, bool hidePopups)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int shipId_arg, bool hidePopups_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func2::func;
	return execfunc(this, shipId, hidePopups);
}

namespace _func3
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(void (AchievementTracker::*)(const std::string &, bool , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b0789458c0fb6470488857fffffff8b411889c2", argdata, 4, 5, &func);
}

void AchievementTracker::SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &achievement_arg, bool noPopup_arg, bool sendToServer_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func3::func;
	return execfunc(this, achievement, noPopup, sendToServer);
}

namespace _func4
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::UnlockShip", typeid(void (AchievementTracker::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec148b57048b0783fa0274??8b790c8d04408d04872", argdata, 3, 5, &func);
}

void AchievementTracker::UnlockShip(int shipId, int shipType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int shipId_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func4::func;
	return execfunc(this, shipId, shipType);
}

namespace _func5
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e55756538d45d08d7dd881ec????????894d84897dd0890424c744240801000000", argdata, 1, 5, &func);
}

void AchievementTracker::SetSectorEight()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func5::func;
	return execfunc(this);
}

namespace _func6
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipMarker", typeid(int (AchievementTracker::*)(const std::string &, const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b3f8b70048b5f048b4e04", argdata, 3, 1, &func);
}

int AchievementTracker::GetShipMarker(const std::string &baseName, const std::string &thisName)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &baseName_arg, const std::string &thisName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func6::func;
	return execfunc(this, baseName, thisName);
}

namespace _func7
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(void (AchievementTracker::*)(const std::string &)), "5789c88d7c240883e4f0ff77fc5589e557565383ec4c8b582c8b17894dc083c128894dcc85db8955c4", argdata, 2, 5, &func);
}

void AchievementTracker::SetFlag(const std::string &flagName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func7::func;
	return execfunc(this, flagName);
}

namespace _func8
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetFlag", typeid(bool (AchievementTracker::*)(const std::string &)), "578d51288d7c240883e4f0ff77fc5589e557565383ec4c8b078b792c8955cc85ff8945c4", argdata, 2, 1, &func);
}

bool AchievementTracker::GetFlag(const std::string &flagName)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func8::func;
	return execfunc(this, flagName);
}

namespace _func9
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SaveProfile", typeid(void (AchievementTracker::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b008b71188945e48b411c", argdata, 2, 5, &func);
}

void AchievementTracker::SaveProfile(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func9::func;
	return execfunc(this, file);
}

namespace _func10
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::LoadProfile", typeid(void (AchievementTracker::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????8b3f8b4004894d80893c24", argdata, 3, 5, &func);
}

void AchievementTracker::LoadProfile(int file, int version)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int file_arg, int version_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func10::func;
	return execfunc(this, file, version);
}

namespace _func11
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dc089ce83ec6c8b516c8b5970897db889d001d874??", argdata, 1, 5, &func);
}

void AchievementTracker::SetVictoryAchievement()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func11::func;
	return execfunc(this);
}

namespace _func12
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::OnLanguageChange", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e557565381ecfc0400008b511c8b4118898d1cfbffffc7852cfbffff00000000", argdata, 1, 5, &func);
}

void AchievementTracker::OnLanguageChange()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func12::func;
	return execfunc(this);
}

namespace _func13
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetTooltip", typeid(void (AchievementTracker::*)(CAchievement *)), "578d7c240883e4f0ff77fc5589e557565381eccc0100008b0780783c00898548feffff", argdata, 2, 5, &func);
}

void AchievementTracker::SetTooltip(CAchievement *ach)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, CAchievement *ach_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func13::func;
	return execfunc(this, ach);
}

namespace _func14
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::ResetFlags", typeid(void (AchievementTracker::*)()), "578d41248d7c240883e4f0ff77fc5589e557565389cf83ec2c8b712c8945e485f6", argdata, 1, 5, &func);
}

void AchievementTracker::ResetFlags()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func14::func;
	return execfunc(this);
}

namespace _func15
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::OnLoop", typeid(void (AchievementTracker::*)()), "578d7c????83e4f0ff????5589e557565389cb83ec4c8b013b", argdata, 1, 5, &func);
}

void AchievementTracker::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func15::func;
	return execfunc(this);
}

AchievementTracker *Global_AchievementTracker_Tracker;

namespace _var16
{
    static VariableDefinition varObj("Global_AchievementTracker_Tracker", "!b9(???????\?)e8????????c744240c00000000", &Global_AchievementTracker_Tracker);
}

namespace _func17
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::constructor", typeid(void (Animation::*)(const std::string &, int , float , Pointf , int , int , int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec2c8b77048b50148b0ff30f104708", argdata, 9, 5, &func);
}

void Animation::constructor(const std::string &_image, int _length, float _time, Pointf _position, int _imageWidth, int _imageHeight, int _stripStartX, int _numFrames)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, const std::string &_image_arg, int _length_arg, float _time_arg, Pointf _position_arg, int _imageWidth_arg, int _imageHeight_arg, int _stripStartX_arg, int _numFrames_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func17::func;
	return execfunc(this, _image, _length, _time, _position, _imageWidth, _imageHeight, _stripStartX, _numFrames);
}

namespace _func18
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::OnRender", typeid(void (Animation::*)(float , GL_Color , bool )), "5589e557565389cb83e4f083ec408b451c84c089c775??0fb6b984000000f30f104508", argdata, 4, 5, &func);
}

void Animation::OnRender(float opacity, GL_Color color, bool mirror)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func18::func;
	return execfunc(this, opacity, color, mirror);
}

namespace _func19
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::Update", typeid(void (Animation::*)()), "57660fefdb8d7c240883e4f0ff77fc5589e557565389cb83ec4c", argdata, 1, 5, &func);
}

void Animation::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func19::func;
	return execfunc(this);
}

namespace _func20
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetCurrentFrame", typeid(void (Animation::*)(int )), "8b5104538b5c24088d42ff39d80f4fc385c07e??660fefc0660fefdbf30f2ac0898180000000660fefd2f30f104924", argdata, 2, 5, &func);
}

void Animation::SetCurrentFrame(int frame)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func20::func;
	return execfunc(this, frame);
}

namespace _func21
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::Start", typeid(void (Animation::*)(bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec20803f000f85????????660fefd2f30f10492cc6413200", argdata, 2, 5, &func);
}

void Animation::Start(bool reset)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func21::func;
	return execfunc(this, reset);
}

namespace _func22
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::AddSoundQueue", typeid(void (Animation::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec3c8b178b770485d278??8b99880000008b818c00000029d8c1f802", argdata, 3, 5, &func);
}

void Animation::AddSoundQueue(int frame, const std::string &sound)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func22::func;
	return execfunc(this, frame, sound);
}

namespace _func23
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetAnimationId", typeid(void (Animation::*)(GL_Texture *)), "8b442404390174??89c2890185d274??8b500489510889c285d274??8b400889410c", argdata, 2, 5, &func);
}

void Animation::SetAnimationId(GL_Texture *tex)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, GL_Texture *tex_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func23::func;
	return execfunc(this, tex);
}

namespace _func24
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::destructor", typeid(void (Animation::*)()), "558d91a400000089e557565383e4f083ec208b819c000000894c241839d074??890424e8????????8b4424188bb08c00000089f38974241c8bb088000000", argdata, 1, 5, &func);
}

void Animation::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func24::func;
	return execfunc(this);
}

namespace _func25
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::StartReverse", typeid(void (Animation::*)(bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b0784c00f85????????660fefd2f30f10412cc6413200c64130010f2ed00f87????????f30f104924", argdata, 2, 5, &func);
}

void Animation::StartReverse(bool reset)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func25::func;
	return execfunc(this, reset);
}

namespace _func26
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetProgress", typeid(void (Animation::*)(float )), "f30f10512480793000f30f104c24048b5104f30f59ca660fefdb660fefc0f30f11492cf30f2ada74??f30f5ecaf30f5fc80f28c1f30f59c383ea01", argdata, 2, 5, &func);
}

void Animation::SetProgress(float progress)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func26::func;
	return execfunc(this, progress);
}

namespace _func27
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::RandomStart", typeid(int (Animation::*)()), "5589e55389cb83e4f0803d????????00754ee8????????8b4b0499c6433200660fefc0c6433001660fefc9", argdata, 1, 1, &func);
}

int Animation::RandomStart()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func27::func;
	return execfunc(this);
}

namespace _func28
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SaveState", typeid(void (Animation::*)(int )), "5589e5565389cb83e4f083ec100fb641308b750889342489442404", argdata, 2, 5, &func);
}

void Animation::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func28::func;
	return execfunc(this, fd);
}

namespace _func29
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::LoadState", typeid(void (Animation::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b37893424e8????????85c00f85????????893424", argdata, 2, 5, &func);
}

void Animation::LoadState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func29::func;
	return execfunc(this, fd);
}

namespace _func30
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::Done", typeid(bool (Animation::*)()), "0fb6413284c074??660fefc00f2e81940000000f93c0", argdata, 1, 1, &func);
}

bool Animation::Done()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func30::func;
	return execfunc(this);
}

namespace _func31
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationControl::GetAnimation", typeid(Animation (AnimationControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b07898dacfeffff8985b0feffff8b4704c70424????????", argdata, 3, 1, &func);
}

Animation AnimationControl::GetAnimation(const std::string &animName)
{
	typedef Animation __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationControl *this_arg, const std::string &animName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func31::func;
	return execfunc(this, animName);
}

AnimationControl *Global_AnimationControl_Animations;

namespace _var32
{
    static VariableDefinition varObj("Global_AnimationControl_Animations", "!c70424(???????\?)89c18985ecfeffff", &Global_AnimationControl_Animations);
}

namespace _func33
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AnimationTracker::Update", typeid(void (AnimationTracker::*)()), "807910000f84????????5589e55389cb83e4f083ec1080790800", argdata, 1, 5, &func);
}

void AnimationTracker::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func33::func;
	return execfunc(this);
}

namespace _func34
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetLoop", typeid(void (AnimationTracker::*)(bool , float )), ".8b442404f30f10442408f30f114114c7411800000000884108", argdata, 3, 5, &func);
}

void AnimationTracker::SetLoop(bool loop, float loopDelay)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool loop_arg, float loopDelay_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func34::func;
	return execfunc(this, loop, loopDelay);
}

namespace _func35
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Stop", typeid(void (AnimationTracker::*)(bool )), ".807c240400c6411000660fefc074??f30f10410cf30f11410c", argdata, 2, 5, &func);
}

void AnimationTracker::Stop(bool resetTime)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool resetTime_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func35::func;
	return execfunc(this, resetTime);
}

namespace _func36
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Start", typeid(void (AnimationTracker::*)(float )), ".f30f10442404c6411200c6411001f30f11410cc6411100", argdata, 2, 5, &func);
}

void AnimationTracker::Start(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func36::func;
	return execfunc(this, time);
}

namespace _func37
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::StartReverse", typeid(void (AnimationTracker::*)(float )), ".660fefc9c6411200f30f10442404c64110010f2ec876??f30f104104", argdata, 2, 5, &func);
}

void AnimationTracker::StartReverse(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func37::func;
	return execfunc(this, time);
}

namespace _func38
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Progress", typeid(float (AnimationTracker::*)(float )), ".83ec0480791000f30f104c2408660fefc074??0f2ec10f28d077??f30f10410cf30f5ec1", argdata, 2, 1, &func);
}

float AnimationTracker::Progress(float speed)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float speed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func38::func;
	return execfunc(this, speed);
}

namespace _func39
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetProgress", typeid(void (AnimationTracker::*)(float )), ".f30f104104f30f59442404f30f11410c", argdata, 2, 5, &func);
}

void AnimationTracker::SetProgress(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func39::func;
	return execfunc(this, time);
}

namespace _func40
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::GetAlphaLevel", typeid(float (AnimationTracker::*)(bool )), ".5589e583ec04f30f1005????????f30f1015????????807d0800f30f594104f30f10490cf30f5cc80f28d8", argdata, 2, 1, &func);
}

float AnimationTracker::GetAlphaLevel(bool reverse)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool reverse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func40::func;
	return execfunc(this, reverse);
}

namespace _func41
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArmamentControl::Dragging", typeid(bool (ArmamentControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10837970ff74??8b43688b536c8d4960890424", argdata, 1, 1, &func);
}

bool ArmamentControl::Dragging()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func41::func;
	return execfunc(this);
}

namespace _func42
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ArmamentControl::SetPosition", typeid(void (ArmamentControl::*)(Point )), "5589e5565383e4f083ec108b450839411c8b550c74??89411c89512031db8b51408b414489ce", argdata, 2, 5, &func);
}

void ArmamentControl::SetPosition(Point loc)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, Point loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func42::func;
	return execfunc(this, loc);
}

namespace _func43
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::KeyDown", typeid(bool (ArmamentControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565331db89ce83ec2c8b078b79148945e4", argdata, 2, 1, &func);
}

bool ArmamentControl::KeyDown(SDLKey key)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func43::func;
	return execfunc(this, key);
}

namespace _func44
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArmamentControl::CreateHolderTab", typeid(void (ArmamentControl::*)()), "578d7c240883e4f0ff77fc5589e55756538d45b48d5dcc8d75d489cf81ec9c00000089d9c745b41c000000c7442404000000008904248975cc", argdata, 1, 5, &func);
}

void ArmamentControl::CreateHolderTab()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func44::func;
	return execfunc(this);
}

namespace _func45
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::LinkShip", typeid(void (ArmamentControl::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c0000008b078b79148b511089410c89f829d0c1f80285c0", argdata, 2, 5, &func);
}

void ArmamentControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func45::func;
	return execfunc(this, ship);
}

namespace _func46
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ArtilleryBox::constructor", typeid(void (ArtilleryBox::*)(Point , ArtillerySystem *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b77088b078b5704c744240c0100000089742408", argdata, 3, 5, &func);
}

void ArtilleryBox::constructor(Point pos, ArtillerySystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, Point pos_arg, ArtillerySystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func46::func;
	return execfunc(this, pos, sys);
}

namespace _func47
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ArtilleryBox::OnRender", typeid(void (ArtilleryBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????0fb607890424e8????????83ec04e8????????660fefc0c744240800000000", argdata, 2, 5, &func);
}

void ArtilleryBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func47::func;
	return execfunc(this, ignoreStatus);
}

namespace _func48
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArtillerySystem::OnLoop", typeid(void (ArtillerySystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec5c894db0e8????????89f9e8????????85c0", argdata, 1, 5, &func);
}

void ArtillerySystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArtillerySystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func48::func;
	return execfunc(this);
}

namespace _func49
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArtillerySystem::Jump", typeid(void (ArtillerySystem::*)()), "8b81c0010000c7400800000000c7802c06000000000000c3", argdata, 1, 5, &func);
}

void ArtillerySystem::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArtillerySystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func49::func;
	return execfunc(this);
}

namespace _func50
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Asteroid::OnUpdate", typeid(void (Asteroid::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec4080b9b0000000007415c783a402000000000000", argdata, 1, 5, &func);
}

void Asteroid::OnUpdate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Asteroid *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func50::func;
	return execfunc(this);
}

namespace _func51
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Asteroid::constructor", typeid(void (Asteroid::*)(Pointf , int )), "578d7c240883e4f0ff77fc5589e557565381ec5c010000898dc0feffff8d8d18ffffff", argdata, 3, 5, &func);
}

void Asteroid::constructor(Pointf pos, int destinationSpace)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Asteroid *this_arg, Pointf pos_arg, int destinationSpace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func51::func;
	return execfunc(this, pos, destinationSpace);
}

namespace _func52
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::constructor", typeid(void (AsteroidGenerator::*)()), "5589e557565389cb83e4f083ec20c70424????????e8????????8d500cc70424????????89c789542414e8????????8d880002000089470cc703????????c7430800000000c7430c00000000", argdata, 1, 5, &func);
}

void AsteroidGenerator::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func52::func;
	return execfunc(this);
}

namespace _func53
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), ".5589e55389cb8b550c8b451083e4f089918c00000089d1c1e91f01cad1fa", argdata, 4, 1, &func);
}

float AsteroidGenerator::Initialize(int numberOfShips, int shieldCount, bool defense)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int numberOfShips_arg, int shieldCount_arg, bool defense_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func53::func;
	return execfunc(this, numberOfShips, shieldCount, defense);
}

namespace _func54
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SetNumShips", typeid(void (AsteroidGenerator::*)(int )), ".8b442404894170", argdata, 2, 5, &func);
}

void AsteroidGenerator::SetNumShips(int ships)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int ships_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func54::func;
	return execfunc(this, ships);
}

namespace _func55
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextAsteroid", typeid(Projectile *(AsteroidGenerator::*)()), ".8b41083b41180f84????????578d7c240883e4f0ff77fc5589e557", argdata, 1, 1, &func);
}

Projectile *AsteroidGenerator::GetNextAsteroid()
{
	typedef Projectile *__attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func55::func;
	return execfunc(this);
}

namespace _func56
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::OnLoop", typeid(void (AsteroidGenerator::*)()), ".80b9880000000075??c38db600000000578d7c240883e4f0", argdata, 1, 5, &func);
}

void AsteroidGenerator::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func56::func;
	return execfunc(this);
}

namespace _func57
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextState", typeid(void (AsteroidGenerator::*)()), ".5589e5538b417489cb83e4f085c075??803d??????????", argdata, 1, 5, &func);
}

void AsteroidGenerator::GetNextState()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func57::func;
	return execfunc(this);
}

namespace _func58
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::UpdateState", typeid(void (AsteroidGenerator::*)()), ".5589e55389cbb9????????83e4f083ec10e8????????d95c240c", argdata, 1, 5, &func);
}

void AsteroidGenerator::UpdateState()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func58::func;
	return execfunc(this);
}

namespace _func59
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SaveAsteroids", typeid(bool (AsteroidGenerator::*)(void *)), ".5589e5565389ce83e4f083ec108b5d08", argdata, 2, 1, &func);
}

bool AsteroidGenerator::SaveAsteroids(void *file)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, void *file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func59::func;
	return execfunc(this, file);
}

namespace _func60
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::LoadAsteroids", typeid(void (AsteroidGenerator::*)(void *)), ".5589e5565389cb83e4f083ec108b7508", argdata, 2, 5, &func);
}

void AsteroidGenerator::LoadAsteroids(void *file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, void *file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func60::func;
	return execfunc(this, file);
}

namespace _func61
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AugmentEquipBox::RenderIcon", typeid(void (AugmentEquipBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????8b434c660fefc0c744240800000000f7d8f30f2ac0", argdata, 1, 5, &func);
}

void AugmentEquipBox::RenderIcon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func61::func;
	return execfunc(this);
}

namespace _func62
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AugmentEquipBox::CheckContents", typeid(void (AugmentEquipBox::*)()), "8b818400000085c074??578d7c240883e4f0ff77fc5589e557565389cb8d4dc4", argdata, 1, 5, &func);
}

void AugmentEquipBox::CheckContents()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func62::func;
	return execfunc(this);
}

namespace _func63
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AugmentEquipBox::RemoveItem", typeid(void (AugmentEquipBox::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b818400000085c074??", argdata, 1, 5, &func);
}

void AugmentEquipBox::RemoveItem()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func63::func;
	return execfunc(this);
}

namespace _func64
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AugmentStoreBox::constructor", typeid(void (AugmentStoreBox::*)(ShipManager *, const AugmentBlueprint *)), "578d7c240883e4f0ff77fc5589f889e557565389cb8d4dd083ec4c8b70048d45d88b3fc7442404000000008945d08d45cc", argdata, 3, 5, &func);
}

void AugmentStoreBox::constructor(ShipManager *ship, const AugmentBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AugmentStoreBox *this_arg, ShipManager *ship_arg, const AugmentBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func64::func;
	return execfunc(this, ship, bp);
}

namespace _func65
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("BatteryBox::constructor", typeid(void (BatteryBox::*)(Point , BatterySystem *)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d75d081ec????????8b58088b108b4804c744240c00000000895c2408891424", argdata, 3, 5, &func);
}

void BatteryBox::constructor(Point pos, BatterySystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BatteryBox *this_arg, Point pos_arg, BatterySystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func65::func;
	return execfunc(this, pos, sys);
}

namespace _func66
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::OnRenderSpecific", typeid(void (BeamWeapon::*)(int )), "578d??????83e4??ff????5589e557565381ec????????80????????????8b??", argdata, 2, 5, &func);
}

void BeamWeapon::OnRenderSpecific(int spaceId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, int spaceId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func66::func;
	return execfunc(this, spaceId);
}

namespace _func67
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x2ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::constructor", typeid(void (BeamWeapon::*)(Pointf , int , int , Pointf , Pointf , int , Targetable *, float )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b57048b4f148b078b770cf30f105728894dd48955e4f30f1155dc", argdata, 9, 5, &func);
}

void BeamWeapon::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, Pointf _target2_arg, int _length_arg, Targetable *_targetable_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func67::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _target2, _length, _targetable, heading);
}

namespace _func68
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::CollisionCheck", typeid(void (BeamWeapon::*)(Collideable *)), "578d7c240883e4f0ff77fc5589e557565381eccc0100008b99080300008b0785db8985a4feffff740e89cf89c18b00ff50243b4770740e", argdata, 2, 5, &func);
}

void BeamWeapon::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func68::func;
	return execfunc(this, other);
}

namespace _func69
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BeamWeapon::OnUpdate", typeid(void (BeamWeapon::*)()), "80b920030000000f841e030000578d7c240883e4f0ff77fc5589e557565389cb31ff8d93f402000083ec3c", argdata, 1, 5, &func);
}

void BeamWeapon::OnUpdate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func69::func;
	return execfunc(this);
}

namespace _func70
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Blueprint::destructor", typeid(void (Blueprint::*)()), "558d91a800000089e55389cb83e4f083ec108b81a0000000c701????????39d074??890424e8????????8b83840000008d938c00000039d074??890424", argdata, 1, 5, &func);
}

void Blueprint::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Blueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func70::func;
	return execfunc(this);
}

namespace _func71
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Blueprint::GetNameShort", typeid(std::string (Blueprint::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b17807a500075??83c238", argdata, 2, 1, &func);
}

std::string Blueprint::GetNameShort()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(Blueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func71::func;
	return execfunc(this);
}

namespace _func72
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetBlueprintList", typeid(std::vector<std::string> (BlueprintManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec4c8b3f8b40048945c0e8????????84c08d87f4000000", argdata, 3, 1, &func);
}

std::vector<std::string> BlueprintManager::GetBlueprintList(const std::string &name)
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func72::func;
	return execfunc(this, name);
}

namespace _func73
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(const std::string &, int )), "578d7c240883e4f0ff77fc5589e55756538d45d883ec5c8b1f8945d08b77048d7dd0894db48b038b5304", argdata, 3, 1, &func);
}

ShipBlueprint *BlueprintManager::GetShipBlueprint(const std::string &name, int sector)
{
	typedef ShipBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func73::func;
	return execfunc(this, name, sector);
}

namespace _func74
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetDroneBlueprint", typeid(DroneBlueprint *(BlueprintManager::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e557565389cb8d4dd083ec4c8b378dbbf4000000c70424????????e8????????", argdata, 2, 1, &func);
}

DroneBlueprint *BlueprintManager::GetDroneBlueprint(const std::string &name)
{
	typedef DroneBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func74::func;
	return execfunc(this, name);
}

namespace _func75
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentValue", typeid(float (BlueprintManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d714c89cb83c35083ec2c8b3f89f1", argdata, 2, 1, &func);
}

float BlueprintManager::GetAugmentValue(const std::string &name)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func75::func;
	return execfunc(this, name);
}

namespace _func76
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentBlueprint", typeid(AugmentBlueprint *(BlueprintManager::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e557565389cb8d4dd083ec4c8b378dbbf4000000", argdata, 2, 1, &func);
}

AugmentBlueprint *BlueprintManager::GetAugmentBlueprint(const std::string &name)
{
	typedef AugmentBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func76::func;
	return execfunc(this, name);
}

namespace _func77
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetItemBlueprint", typeid(ItemBlueprint *(BlueprintManager::*)(const std::string &)), "578d91c80000008d7c240883e4f0ff77fc5589e557565383ec3c8b99cc000000894dcc", argdata, 2, 1, &func);
}

ItemBlueprint *BlueprintManager::GetItemBlueprint(const std::string &name)
{
	typedef ItemBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func77::func;
	return execfunc(this, name);
}

namespace _func78
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessWeaponBlueprint", typeid(WeaponBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b18899d14ffffff8b5804e8????????8b8514ffffff8d8d4cffffff8b7318895c2404890424e8????????8d954cffffff83ec088d4f1c", argdata, 3, 1, &func);
}

WeaponBlueprint BlueprintManager::ProcessWeaponBlueprint(rapidxml::xml_node<char> *node)
{
	typedef WeaponBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func78::func;
	return execfunc(this, node);
}

namespace _func79
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDescription", typeid(Description (BlueprintManager::*)(rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589e557565383ec7c8b5f04894d94e8????????8b5b1885db0f84????????8d75cce9????????895c2404893424e8????????", argdata, 3, 1, &func);
}

Description BlueprintManager::ProcessDescription(rapidxml::xml_node<char> *node)
{
	typedef Description __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func79::func;
	return execfunc(this, node);
}

namespace _func80
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessEffectsBlueprint", typeid(EffectsBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "57660fefc08d7c240883e4f0ff77fc5589f889e557565389cf83ec5c8b308b58040f11018d41300f1141100f114120", argdata, 3, 1, &func);
}

EffectsBlueprint BlueprintManager::ProcessEffectsBlueprint(rapidxml::xml_node<char> *node)
{
	typedef EffectsBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func80::func;
	return execfunc(this, node);
}

namespace _func81
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewBlueprint", typeid(CrewBlueprint (BlueprintManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec6c8b3f8b7004e8????????8d47648d5768", argdata, 3, 1, &func);
}

CrewBlueprint BlueprintManager::GetCrewBlueprint(const std::string &name)
{
	typedef CrewBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func81::func;
	return execfunc(this, name);
}

namespace _func82
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetWeaponBlueprint", typeid(WeaponBlueprint *(BlueprintManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd083ec4c8b378dbbf4000000c70424????????e8????????83ec04", argdata, 2, 1, &func);
}

WeaponBlueprint *BlueprintManager::GetWeaponBlueprint(const std::string &name)
{
	typedef WeaponBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func82::func;
	return execfunc(this, name);
}

namespace _func83
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomAugment", typeid(std::vector<AugmentBlueprint*> (BlueprintManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d504c", argdata, 4, 1, &func);
}

std::vector<AugmentBlueprint*> BlueprintManager::GetRandomAugment(int count, bool demo_lock)
{
	typedef std::vector<AugmentBlueprint*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func83::func;
	return execfunc(this, count, demo_lock);
}

namespace _func84
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetSystemBlueprint", typeid(SystemBlueprint *(BlueprintManager::*)(const std::string &)), "578d91e00000008d7c240883e4f0ff77fc5589e557565383ec3c8b99e4000000894dcc8b378955d085db0f84????????8955d489df", argdata, 2, 1, &func);
}

SystemBlueprint *BlueprintManager::GetSystemBlueprint(const std::string &name)
{
	typedef SystemBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func84::func;
	return execfunc(this, name);
}

namespace _func85
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetUnusedCrewName", typeid(std::string (BlueprintManager::*)(bool *)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b07894db4c7410400000000c6410800c745a815000000", argdata, 3, 1, &func);
}

std::string BlueprintManager::GetUnusedCrewName(bool *isMale_ret)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, bool *isMale_ret_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func85::func;
	return execfunc(this, isMale_ret);
}

namespace _func86
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewName", typeid(std::string (BlueprintManager::*)(bool *)), "578d7c240883e4f0ff77fc5589e557565389ce8d5dd083ec4c8b178b47048b0d????????8945c08d427c8955bc8945c4", argdata, 3, 1, &func);
}

std::string BlueprintManager::GetCrewName(bool *isMale_ret)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, bool *isMale_ret_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func86::func;
	return execfunc(this, isMale_ret);
}

namespace _func87
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomWeapon", typeid(std::vector<WeaponBlueprint*> (BlueprintManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d501c890424894c240c8954240489d9e8????????", argdata, 4, 1, &func);
}

std::vector<WeaponBlueprint*> BlueprintManager::GetRandomWeapon(int count, bool demo_lock)
{
	typedef std::vector<WeaponBlueprint*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func87::func;
	return execfunc(this, count, demo_lock);
}

namespace _func88
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomDrone", typeid(std::vector<DroneBlueprint*> (BlueprintManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d5034890424894c240c", argdata, 4, 1, &func);
}

std::vector<DroneBlueprint*> BlueprintManager::GetRandomDrone(int count, bool demo_lock)
{
	typedef std::vector<DroneBlueprint*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func88::func;
	return execfunc(this, count, demo_lock);
}

namespace _func89
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessShipBlueprint", typeid(ShipBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589e557565381ec0c0100008b47048b1f898d1cffffff89cf89c6898518ffffff", argdata, 3, 1, &func);
}

ShipBlueprint BlueprintManager::ProcessShipBlueprint(rapidxml::xml_node<char> *node)
{
	typedef ShipBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func89::func;
	return execfunc(this, node);
}

namespace _func90
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDroneBlueprint", typeid(DroneBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589e557565389ce81ecec0000008b07898d24ffffff89851cffffff8b470489c7898518ffffff", argdata, 3, 1, &func);
}

DroneBlueprint BlueprintManager::ProcessDroneBlueprint(rapidxml::xml_node<char> *node)
{
	typedef DroneBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func90::func;
	return execfunc(this, node);
}

namespace _func91
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetSkillIcon", typeid(GL_Texture *(*)(int , bool )), "8d4c240483e4f0ff71fc5589e55756535181ec880000008b198b49040fb6f98d045f", argdata, 2, 2, &func);
}

GL_Texture *BlueprintManager::GetSkillIcon(int skill, bool outline)
{
	typedef GL_Texture *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int skill_arg, bool outline_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func91::func;
	return execfunc(skill, outline);
}

BlueprintManager *Global_BlueprintManager_Blueprints;

namespace _var92
{
    static VariableDefinition varObj("Global_BlueprintManager_Blueprints", "!8b85c0feffff83ec04b9(???????\?)83b83401000003", &Global_BlueprintManager_Blueprints);
}

namespace _func93
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::constructor", typeid(void (BoarderPodDrone::*)(int , int , const DroneBlueprint &)), "578d7c240883e4f0ff77fc5589fa89e557565389cfbb????????81ec????????8b028b720889c18985acfeffff8b4204890c248974240889f989b5bcfeffff", argdata, 4, 5, &func);
}

void BoarderPodDrone::constructor(int _iShipId, int _selfId, const DroneBlueprint &_bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, int _iShipId_arg, int _selfId_arg, const DroneBlueprint &_bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func93::func;
	return execfunc(this, _iShipId, _selfId, _bp);
}

namespace _func94
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::SetMovementTarget", typeid(void (BoarderPodDrone::*)(Targetable *)), "578d7c240883e4f0ff77fc5589e5575383ec208b0785c074??8b1089cb89815001000089c1ff521c89434c8b43048d4df0", argdata, 2, 5, &func);
}

void BoarderPodDrone::SetMovementTarget(Targetable *target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func94::func;
	return execfunc(this, target);
}

namespace _func95
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BoarderPodDrone::CanBeDeployed", typeid(bool (BoarderPodDrone::*)()), ".8b815001000085c074168b108b521881fa????????750cb801000000", argdata, 1, 1, &func);
}

bool BoarderPodDrone::CanBeDeployed()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func95::func;
	return execfunc(this);
}

namespace _func96
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::SetDeployed", typeid(void (BoarderPodDrone::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c807914008b37", argdata, 2, 5, &func);
}

void BoarderPodDrone::SetDeployed(bool _deployed)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, bool _deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func96::func;
	return execfunc(this, _deployed);
}

namespace _func97
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::CollisionMoving", typeid(CollisionResponse (BoarderPodDrone::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b470c8b571080be6c04000000", argdata, 6, 1, &func);
}

CollisionResponse BoarderPodDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func97::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func98
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BoarderPodDrone::OnLoop", typeid(void (BoarderPodDrone::*)()), "578d????0883e4f0ff????5589e557565389cb81ecbc000000e8????????", argdata, 1, 5, &func);
}

void BoarderPodDrone::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func98::func;
	return execfunc(this);
}

namespace _func99
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("BombProjectile::constructor", typeid(void (BombProjectile::*)(Pointf , int , int , Pointf )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec2c0100008b70088b50148b5804898decfeffff8b0889b5f4feffff8b700c8b401089542414890c24895c240489f9", argdata, 5, 5, &func);
}

void BombProjectile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BombProjectile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func99::func;
	return execfunc(this, _position, _ownerId, _targetId, _target);
}

namespace _func100
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BombProjectile::CollisionCheck", typeid(void (BombProjectile::*)(Collideable *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b0789c18945cc8b00ff50283b4378", argdata, 2, 5, &func);
}

void BombProjectile::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BombProjectile *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func100::func;
	return execfunc(this, other);
}

namespace _func101
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BombProjectile::OnUpdate", typeid(void (BombProjectile::*)()), "5589e556538db14c01000089cb83e4f083ec2089f1", argdata, 1, 5, &func);
}

void BombProjectile::OnUpdate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BombProjectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func101::func;
	return execfunc(this);
}

namespace _func102
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::Restart", typeid(void (BossShip::*)()), "c7813401000000000000c7816001000001000000c6815c01000001c38d742600f30f108144010000f30f5c8140010000f30f100d????????0f2ec876??83b934010000010f95c0", argdata, 1, 5, &func);
}

void BossShip::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func102::func;
	return execfunc(this);
}

namespace _func103
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::IncomingFire", typeid(bool (BossShip::*)()), ".f30f108144010000f30f5c8140010000f30f100d????????0f2ec876??", argdata, 1, 1, &func);
}

bool BossShip::IncomingFire()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func103::func;
	return execfunc(this);
}

namespace _func104
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::constructor", typeid(void (BossShip::*)(SpaceManager *)), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b0783c318c744240801000000c744240400000000", argdata, 2, 5, &func);
}

void BossShip::constructor(SpaceManager *space)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg, SpaceManager *space_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func104::func;
	return execfunc(this, space);
}

namespace _func105
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::SaveBoss", typeid(void (BossShip::*)(int )), ".5589e557565389cf83e4f083ec108b5d088b8134010000891c2489442404", argdata, 2, 5, &func);
}

void BossShip::SaveBoss(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func105::func;
	return execfunc(this, file);
}

namespace _func106
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(void (BossShip::*)(int )), ".578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b07890424", argdata, 2, 5, &func);
}

void BossShip::LoadBoss(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func106::func;
	return execfunc(this, file);
}

namespace _func107
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::ClearLocation", typeid(void (BossShip::*)()), ".89c88b490885c974??5589e55389c38b01", argdata, 1, 5, &func);
}

void BossShip::ClearLocation()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func107::func;
	return execfunc(this);
}

namespace _func108
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::Defeated", typeid(bool (BossShip::*)()), ".83b9340100000374??31c0c38d7426008b490880b99904000000", argdata, 1, 1, &func);
}

bool BossShip::Defeated()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func108::func;
	return execfunc(this);
}

namespace _func109
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(LocationEvent *(BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c", argdata, 1, 1, &func);
}

LocationEvent *BossShip::GetSubEvent()
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func109::func;
	return execfunc(this);
}

namespace _func110
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(void (BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce8dbd20ffffff", argdata, 1, 5, &func);
}

void BossShip::StartStage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func110::func;
	return execfunc(this);
}

namespace _func111
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(LocationEvent *(BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 1, 1, &func);
}

LocationEvent *BossShip::GetEvent()
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func111::func;
	return execfunc(this);
}

namespace _func112
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::OnLoop", typeid(void (BossShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c", argdata, 1, 5, &func);
}

void BossShip::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func112::func;
	return execfunc(this);
}

namespace _func113
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(void (Button::*)(const Point )), "578d7c240883e4f0ff77fc5589e55783ec148b078b570489042489542404e8????????8b7dfc83ec08c98d67f85fc20800909090909090909090909090909090f3c39090909090909090909090909090c20800", argdata, 2, 5, &func);
}

void Button::SetLocation(const Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, const Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func113::func;
	return execfunc(this, pos);
}

namespace _func114
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(const std::string &, Point )), "578d7c240883e4f0ff77fc5589e55756538d55a881ec????????8b47048b1f894d948955a08945908b47088b3b", argdata, 3, 5, &func);
}

void Button::OnInit(const std::string &img, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, const std::string &img_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func114::func;
	return execfunc(this, img, pos);
}

namespace _func115
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Button::constructor", typeid(void (Button::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d49048d732483ec2c", argdata, 1, 5, &func);
}

void Button::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func115::func;
	return execfunc(this);
}

namespace _func116
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Button::OnRender", typeid(void (Button::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b4154", argdata, 1, 5, &func);
}

void Button::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func116::func;
	return execfunc(this);
}

namespace _func117
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetInactiveImage", typeid(void (Button::*)(GL_Texture *)), "5589e5565383e4f083ec108b450839414874??8941488b018b40303d????????75??8d59548d71608b03", argdata, 2, 5, &func);
}

void Button::SetInactiveImage(GL_Texture *texture)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, GL_Texture *texture_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func117::func;
	return execfunc(this, texture);
}

namespace _func118
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetActiveImage", typeid(void (Button::*)(GL_Texture *)), ".5589e5565383e4f083ec108b450839414c74??89414c8b018b40303d????????75??8d59548d7160", argdata, 2, 5, &func);
}

void Button::SetActiveImage(GL_Texture *texture)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, GL_Texture *texture_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func118::func;
	return execfunc(this, texture);
}

namespace _func119
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetImageBase", typeid(void (Button::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45a889cb83ec7c8b3f8945a08b178b770489d0", argdata, 2, 5, &func);
}

void Button::SetImageBase(const std::string &imageBase)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, const std::string &imageBase_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func119::func;
	return execfunc(this, imageBase);
}

namespace _func120
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(void (CAchievement::*)(Point , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b57048b77088b7f0c898568ffffff895584", argdata, 4, 5, &func);
}

void CAchievement::OnRender(Point pos, int selected, bool showNew)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CAchievement *this_arg, Point pos_arg, int selected_arg, bool showNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func120::func;
	return execfunc(this, pos, selected, showNew);
}

namespace _func121
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(void (CAchievement::*)()), "578d41088d7c240883e4f0ff77fc5589e557565389cf8d75d08d5dd883ec3c8901", argdata, 1, 5, &func);
}

void CAchievement::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CAchievement *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func121::func;
	return execfunc(this);
}

namespace _func122
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInputFocus", typeid(void (CApp::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec1080b9f734000000", argdata, 1, 5, &func);
}

void CApp::OnInputFocus()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func122::func;
	return execfunc(this);
}

namespace _func123
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInputBlur", typeid(void (CApp::*)()), ".5789c88d7c240883e4f0ff77fc5589e5575383ec10c681f7340000008b4908803d??????????", argdata, 1, 5, &func);
}

void CApp::OnInputBlur()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func123::func;
	return execfunc(this);
}

namespace _func124
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExit", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????c70424????????", argdata, 1, 5, &func);
}

void CApp::OnExit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func124::func;
	return execfunc(this);
}

namespace _func125
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMButtonDown", typeid(void (CApp::*)(int , int )), ".80b9bc3400000074??c208008d74260080791000", argdata, 3, 5, &func);
}

void CApp::OnMButtonDown(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func125::func;
	return execfunc(this, x, y);
}

namespace _func126
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnTextEvent", typeid(void (CApp::*)(CEvent::TextEvent )), ".578d7c240883e4f0ff77fc55", argdata, 2, 5, &func);
}

void CApp::OnTextEvent(CEvent::TextEvent textEvent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, CEvent::TextEvent textEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func126::func;
	return execfunc(this, textEvent);
}

namespace _func127
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnTextInput", typeid(void (CApp::*)(int )), ".578d7c240883e4f0ff77fc5589e55783ec1480b9bc34000000", argdata, 2, 5, &func);
}

void CApp::OnTextInput(int ch)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int ch_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func127::func;
	return execfunc(this, ch);
}

namespace _func128
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRequestExit", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b490885c974??8b430c", argdata, 1, 5, &func);
}

void CApp::OnRequestExit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func128::func;
	return execfunc(this);
}

namespace _func129
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMouseMove", typeid(void (CApp::*)(int , int , int , int , bool , bool , bool )), ".57660fefc08d7c240883e4f0ff77fc5589e557565389cb83ec2c8b072b81103500008b5704", argdata, 8, 5, &func);
}

void CApp::OnMouseMove(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg, int xdiff_arg, int ydiff_arg, bool holdingLMB_arg, bool holdingRMB_arg, bool holdingMMB_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func129::func;
	return execfunc(this, x, y, xdiff, ydiff, holdingLMB, holdingRMB, holdingMMB);
}

namespace _func130
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonUp", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e5575389cb83ec208b072b81103500008b5704", argdata, 3, 5, &func);
}

void CApp::OnRButtonUp(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func130::func;
	return execfunc(this, x, y);
}

namespace _func131
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonUp", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e557", argdata, 3, 5, &func);
}

void CApp::OnLButtonUp(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func131::func;
	return execfunc(this, x, y);
}

namespace _func132
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonDown", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e55753", argdata, 3, 5, &func);
}

void CApp::OnRButtonDown(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func132::func;
	return execfunc(this, x, y);
}

namespace _func133
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonDown", typeid(void (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e5", argdata, 3, 5, &func);
}

void CApp::OnLButtonDown(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func133::func;
	return execfunc(this, x, y);
}

namespace _func134
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnLanguageChange", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

void CApp::OnLanguageChange()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func134::func;
	return execfunc(this);
}

namespace _func135
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyUp", typeid(void (CApp::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e557565383ec4c", argdata, 2, 5, &func);
}

void CApp::OnKeyUp(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func135::func;
	return execfunc(this, key);
}

namespace _func136
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyDown", typeid(void (CApp::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

void CApp::OnKeyDown(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func136::func;
	return execfunc(this, key);
}

namespace _func137
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::constructor", typeid(void (CApp::*)()), ".5589e55389cb83e4f0e8", argdata, 1, 5, &func);
}

void CApp::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func137::func;
	return execfunc(this);
}

namespace _func138
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::ParseArgs", typeid(void (CApp::*)(int , const char **)), ".555789cd565383ec04c68541350000008b5424188b4c241c83fa017e??", argdata, 3, 5, &func);
}

void CApp::ParseArgs(int argc, const char **argv)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int argc_arg, const char **argv_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func138::func;
	return execfunc(this, argc, argv);
}

namespace _func139
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec4ce8????????", argdata, 1, 5, &func);
}

void CApp::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func139::func;
	return execfunc(this);
}

namespace _func140
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(int (CApp::*)()), ".5589e55389cb83e4f0", argdata, 1, 1, &func);
}

int CApp::SetupWindow()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func140::func;
	return execfunc(this);
}

namespace _func141
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnCleanup", typeid(void (CApp::*)()), ".5589e5565389cb83e4f083ec10", argdata, 1, 5, &func);
}

void CApp::OnCleanup()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func141::func;
	return execfunc(this);
}

namespace _func142
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::GenInputEvents", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb", argdata, 1, 5, &func);
}

void CApp::GenInputEvents()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func142::func;
	return execfunc(this);
}

namespace _func143
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnSuspend", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void CApp::OnSuspend()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func143::func;
	return execfunc(this);
}

namespace _func144
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnResume", typeid(void (CApp::*)()), "!.80b9bc3400000075??8079100074??c35589e55389cb8b4908", argdata, 1, 5, &func);
}

void CApp::OnResume()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func144::func;
	return execfunc(this);
}

namespace _func145
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::TranslateMouse", typeid(Point (CApp::*)(int , int )), ".57660fefc08d7c240883e4f0ff77fc5589e55783ec248b072b8110350000", argdata, 3, 9, &func);
}

Point CApp::TranslateMouse(int x, int y)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func145::func;
	return execfunc(this, x, y);
}

namespace _func146
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::UpdateFullScreen", typeid(void (CApp::*)()), ".803d??????????74??c38db6000000005589e5575653", argdata, 1, 5, &func);
}

void CApp::UpdateFullScreen()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func146::func;
	return execfunc(this);
}

namespace _func147
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::UpdateWindowSettings", typeid(void (CApp::*)()), ".80b90c35000000c781ec34000000000000c781f034000000000000c7811035000000000000", argdata, 1, 5, &func);
}

void CApp::UpdateWindowSettings()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func147::func;
	return execfunc(this);
}

namespace _func148
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRender", typeid(void (CApp::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

void CApp::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func148::func;
	return execfunc(this);
}

namespace _func149
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 1, &func);
}

int CApp::OnInit()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func149::func;
	return execfunc(this);
}

namespace _func150
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(int (CApp::*)()), ".578d7c240883e4f0ff77fc5589e557565389cfb9????????81ec????????c70424????????e8????????89f9", argdata, 1, 1, &func);
}

int CApp::OnExecute()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func150::func;
	return execfunc(this);
}

namespace _func151
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f8b4304f20f104308f20f1105????????83e80783f81b77??", argdata, 2, 5, &func);
}

void CEvent::OnEvent(const InputEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CEvent *this_arg, const InputEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func151::func;
	return execfunc(this, event);
}

namespace _func152
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), "83ec04f30f104118f30f110424d9042483c404c39090909090909090909090905589e583e4f083ec10a1????????85c074??890424e8????????a1????????85c074??", argdata, 1, 1, &func);
}

float CFPS::GetSpeedFactor()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func152::func;
	return execfunc(this);
}

namespace _func153
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dd889ce8d5de083ec5ca1????????f20f1015????????893c24f20f5851088945c4", argdata, 1, 5, &func);
}

void CFPS::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func153::func;
	return execfunc(this);
}

CFPS *Global_CFPS_FPSControl;

namespace _var154
{
    static VariableDefinition varObj("Global_CFPS_FPSControl", "!5589e557565389cbb9(???????\?)83ec4c", &Global_CFPS_FPSControl);
}

namespace _func155
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_GetColor", typeid(GL_Color (*)()), "8b4424048b15????????89108b15????????8950048b15????????8950088b15????????89500cc3908db42600000000a1????????3b05????????74??83e810a3????????f3c390908db426000000008b15????????8b0d????????55", argdata, 1, 2, &func);
}

GL_Color CSurface::GL_GetColor()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func155::func;
	return execfunc();
}

namespace _func156
{
    static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(GL_Color )), "8d4c240483e4f0ff71fc5589e55183ec14a1????????3b05????????74??85c074??8b1189108b51048950048b51088950088b510c89500c", argdata, 1, 6, &func);
}

void CSurface::GL_SetColorTint(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func156::func;
	return execfunc(color);
}

namespace _func157
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate2", typeid(void (*)(float , float , float , float )), "5589e55653bb????????83e4f081ec????????8d44243cf30f110424f30f105d08894424088d442438f30f114c2424f30f1154242889442404f30f115c242ce8????????660fefe4", argdata, 4, 6, &func);
}

void CSurface::GL_Rotate2(float angle, float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float angle_arg, float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func157::func;
	return execfunc(angle, x, y, z);
}

namespace _func158
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::IsFrameBufferSupported", typeid(bool (*)()), ".5589e583e4f0e8????????85c0c9", argdata, 0, 2, &func);
}

bool CSurface::IsFrameBufferSupported()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func158::func;
	return execfunc();
}

namespace _func159
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::StartFrame", typeid(void (*)()), ".5589e583e4f0e8????????e8????????", argdata, 0, 6, &func);
}

void CSurface::StartFrame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func159::func;
	return execfunc();
}

namespace _func160
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::FinishFrame", typeid(void (*)()), ".5589e583e4f0e8????????", argdata, 0, 6, &func);
}

void CSurface::FinishFrame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func160::func;
	return execfunc();
}

namespace _func161
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearAll", typeid(void (*)()), ".55660fefc089e583e4f083ec20f30f1144240cc744241400000000", argdata, 0, 6, &func);
}

void CSurface::GL_ClearAll()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func161::func;
	return execfunc();
}

namespace _func162
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearColor", typeid(void (*)()), ".55660fefc089e583e4f083ec10f30f1144240cf30f11442408", argdata, 0, 6, &func);
}

void CSurface::GL_ClearColor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func162::func;
	return execfunc();
}

namespace _func163
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::SetViewPort", typeid(int (*)(int , int , int , int )), ".5589e583e4f083ec108b45148944240c8b4510894424088b450c89442404", argdata, 4, 2, &func);
}

int CSurface::SetViewPort(int left, int bottom, int h, int w)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int left_arg, int bottom_arg, int h_arg, int w_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func163::func;
	return execfunc(left, bottom, h, w);
}

namespace _func164
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopScissor", typeid(void (*)()), ".5589e583e4f083ec10a1????????8b15????????89c129d1c1f90485c974??83e810", argdata, 0, 6, &func);
}

void CSurface::GL_PopScissor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func164::func;
	return execfunc();
}

namespace _func165
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(void (*)(GL_StencilMode , int , int )), ".5589e5565383e4f083ec108b45088b5d0c8b751083f801a3????????891d????????8935????????0f84????????0f82????????", argdata, 3, 6, &func);
}

void CSurface::GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_StencilMode stencilMode_arg, int ref_arg, int mask_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func165::func;
	return execfunc(stencilMode, ref, mask);
}

namespace _func166
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopStencilMode", typeid(void (*)()), ".8b15????????8b0d????????89d029c8c1f80269c0????????85c075??c36690558d4440fd83ea0c89e556", argdata, 0, 6, &func);
}

void CSurface::GL_PopStencilMode()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func166::func;
	return execfunc();
}

namespace _func167
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), ".5589e583e4f083ec20f30f10451cf30f11442414f30f104518f30f11442410f30f104514f30f1144240c", argdata, 6, 2, &func);
}

int CSurface::GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(float mx1_arg, float mx2_arg, float mx3_arg, float mx4_arg, float mx5_arg, float mx6_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func167::func;
	return execfunc(mx1, mx2, mx3, mx4, mx5, mx6);
}

namespace _func168
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_LoadIdentity", typeid(int (*)()), ".55b8????????89e583e4f083ec100f105010c70424????????0f1048200f104030", argdata, 0, 2, &func);
}

int CSurface::GL_LoadIdentity()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func168::func;
	return execfunc();
}

namespace _func169
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), ".a1????????83f80f77??89c10f2805????????c1e106", argdata, 0, 2, &func);
}

int CSurface::GL_PushMatrix()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func169::func;
	return execfunc();
}

namespace _func170
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopMatrix", typeid(int (*)()), ".5589e583e4f083ec30a1????????85c0", argdata, 0, 2, &func);
}

int CSurface::GL_PopMatrix()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func170::func;
	return execfunc();
}

namespace _func171
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), ".55660fefe489e5565383e4f081ec????????f30f1055080f2ed4f30f104d0cf30f104510f30f105d147a??", argdata, 4, 6, &func);
}

void CSurface::GL_Rotate(float angle, float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float angle_arg, float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func171::func;
	return execfunc(angle, x, y, z);
}

namespace _func172
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(void (*)(float , float , float )), ".55b9????????89e583e4f083ec10f30f1005????????f30f10550c0f2ed0f30f104d10f30f105d080f9bc20f45d10f2ec80f9bc00f45c1", argdata, 3, 6, &func);
}

void CSurface::GL_Scale(float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func172::func;
	return execfunc(x, y, z);
}

namespace _func173
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(bool (*)(float , float , float )), ".55660fefc0b9????????89e583e4f083ec20f30f105d0c0f2ed8", argdata, 3, 2, &func);
}

bool CSurface::GL_Translate(float x, float y, float z)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func173::func;
	return execfunc(x, y, z);
}

namespace _func174
{
    static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(GL_Color )), ".5589e583e4f083ec208b4508f30f104508f30f11442410", argdata, 1, 2, &func);
}

int CSurface::GL_SetColor(GL_Color color)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func174::func;
	return execfunc(color);
}

namespace _func175
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), ".a1????????3b05????????74??83e810a3????????", argdata, 0, 6, &func);
}

void CSurface::GL_RemoveColorTint()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func175::func;
	return execfunc();
}

namespace _func176
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color (*)()), ".8b15????????8b0d????????5539d189e58b450874??29ca83e2f08d5411f0", argdata, 1, 2, &func);
}

GL_Color CSurface::GetColorTint()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func176::func;
	return execfunc();
}

namespace _func177
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(bool (*)()), ".5589e583e4f083ec10c744240804000000", argdata, 0, 2, &func);
}

bool CSurface::GL_EnableBlend()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func177::func;
	return execfunc();
}

namespace _func178
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_DisableBlend", typeid(bool (*)()), ".5589e583e4f083ec10c744240800000000", argdata, 0, 2, &func);
}

bool CSurface::GL_DisableBlend()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func178::func;
	return execfunc();
}

namespace _func179
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_ForceAntialias", typeid(void (*)(bool )), ".8b442404a2????????", argdata, 1, 6, &func);
}

void CSurface::GL_ForceAntialias(bool on)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(bool on_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func179::func;
	return execfunc(on);
}

namespace _func180
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLine", typeid(bool (*)(float , float , float , float , float , GL_Color )), ".5589e583e4f081ec????????a1????????8b15????????f30f107d1c", argdata, 6, 2, &func);
}

bool CSurface::GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, float lineWidth_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func180::func;
	return execfunc(x1, y1, x2, y2, lineWidth, color);
}

namespace _func181
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x2ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawTriangle", typeid(bool (*)(Point , Point , Point , GL_Color )), ".5589e557565383e4f081ec????????", argdata, 4, 2, &func);
}

bool CSurface::GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Point vertex1_arg, Point vertex2_arg, Point vertex3_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func181::func;
	return execfunc(vertex1, vertex2, vertex3, color);
}

namespace _func182
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , GL_Color )), ".5589e583e4f081ec????????a1????????8b15????????f30f106d08f30f10650c", argdata, 5, 2, &func);
}

bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func182::func;
	return execfunc(x1, y1, x2, y2, color);
}

namespace _func183
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(int , int , int , int , GL_Color , float )), ".5589e583e4f081ec????????8b55108b4514f30f106520f30f11642424", argdata, 6, 2, &func);
}

bool CSurface::GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x1_arg, int y1_arg, int x2_arg, int y2_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func183::func;
	return execfunc(x1, y1, x2, y2, color, lineWidth);
}

namespace _func184
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".5589e5565383e4f081ec????????8b5520", argdata, 8, 2, &func);
}

bool CSurface::GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float x2_arg, float y2_arg, float rotation_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func184::func;
	return execfunc(tex, x, y, x2, y2, rotation, color, mirror);
}

namespace _func185
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), ".5589e557565383e4f081ec????????8b5520", argdata, 8, 2, &func);
}

bool CSurface::GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float x2_arg, float y2_arg, float rotation_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func185::func;
	return execfunc(tex, x, y, x2, y2, rotation, color, mirror);
}

namespace _func186
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), ".5589e557565383e4f083ec60807d4000", argdata, 12, 2, &func);
}

bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float start_x_arg, float end_x_arg, float start_y_arg, float end_y_arg, float alpha_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func186::func;
	return execfunc(tex, x, y, size_x, size_y, start_x, end_x, start_y, end_y, alpha, color, mirror);
}

namespace _func187
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImageWide", typeid(bool (*)(GL_Texture *, float , float , int , int , float , GL_Color , bool )), ".5589e557565383e4f081ec????????", argdata, 8, 2, &func);
}

bool CSurface::GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, int x2_arg, int y2_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func187::func;
	return execfunc(tex, x, y, x2, y2, opacity, color, mirror);
}

namespace _func188
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitive", typeid(void (*)(GL_Primitive *)), ".5589e55383e4f083ec208b5d0885db0f84????????a1????????8b15????????39d00f84????????29d0", argdata, 1, 6, &func);
}

void CSurface::GL_RenderPrimitive(GL_Primitive *primitive)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func188::func;
	return execfunc(primitive);
}

namespace _func189
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithAlpha", typeid(void (*)(GL_Primitive *, float )), ".5589e55383e4f083ec208b5d0885db0f84????????a1????????8b15????????39d00f84????????", argdata, 2, 6, &func);
}

void CSurface::GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func189::func;
	return execfunc(primitive, alpha);
}

namespace _func190
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(void (*)(GL_Primitive *, GL_Color )), ".5589e55383e4f083ec208b5d08f30f10450cf30f105d1085dbf30f106d14f30f1065180f84????????a1????????8b15????????39d00f84????????", argdata, 2, 6, &func);
}

void CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func190::func;
	return execfunc(primitive, color);
}

namespace _func191
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), ".5589e55383e4f083ec108b5d0885db74??8b4324890424e8????????891c24e8????????", argdata, 1, 6, &func);
}

void CSurface::GL_DestroyPrimitive(GL_Primitive *primitive)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func191::func;
	return execfunc(primitive);
}

namespace _func192
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , GL_Color )), ".5589e55383e4f083ec50f30f10450cc70424????????f30f11442434f30f1144243cf30f584514f30f104d08f30f105510f30f58d1", argdata, 5, 2, &func);
}

GL_Primitive *CSurface::GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float w_arg, float h_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func192::func;
	return execfunc(x, y, w, h, color);
}

namespace _func193
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectOutlinePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , GL_Color , float )), "55660fefdb660fefc089e553660fefd2660fefed83e4f081ecb0000000f30f2a5d08f30f2a450cf30f2a6d14f30f2a5510f30f104d28f30f115c2430f30f114424340f28e0", argdata, 6, 2, &func);
}

GL_Primitive *CSurface::GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int w_arg, int h_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func193::func;
	return execfunc(x, y, w, h, color, lineWidth);
}

namespace _func194
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(void (*)(std::vector<GL_TexVertex> *, float , float , float , float , float , float , float , float )), "8d4c240483e4f0ff71fc5589e55756535183ec388b39f30f105104f30f1059088b17", argdata, 9, 6, &func);
}

void CSurface::AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<GL_TexVertex> *vec_arg, float x1_arg, float y1_arg, float u1_arg, float v1_arg, float x2_arg, float y2_arg, float u2_arg, float v2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func194::func;
	return execfunc(vec, x1, y1, u1, v1, x2, y2, u2, v2);
}

namespace _func195
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawShield", typeid(bool (*)(int , int , float , float , int , int , GL_Color , float )), "8d4c240483e4f0ff71fc5589e55756535181ec880000008b41148b31f30f1071088b5104f30f10510c8b59100f28eaf30f1155880f28fe89459cf30f106128", argdata, 8, 2, &func);
}

bool CSurface::GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, float a1_arg, float b1_arg, int angle1_arg, int angle2_arg, GL_Color color_arg, float thickness_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func195::func;
	return execfunc(x, y, a1, b1, angle1, angle2, color, thickness);
}

namespace _func196
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLaser", typeid(bool (*)(int , int , int , int , GL_Color )), ".8d????0483e4f0ff????", argdata, 5, 2, &func);
}

bool CSurface::GL_DrawLaser(int x, int y, int w, int h, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int w_arg, int h_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func196::func;
	return execfunc(x, y, w, h, color);
}

namespace _func197
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawCircle", typeid(bool (*)(int , int , float , GL_Color )), "8d4c240483e4f0ff71fc5589e55756535183ec788b018b5104f30f105908", argdata, 4, 2, &func);
}

bool CSurface::GL_DrawCircle(int x, int y, float radius, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, float radius_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func197::func;
	return execfunc(x, y, radius, color);
}

namespace _func198
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, std::vector<GL_TexVertex> *, GL_Color )), "8d4c240483e4f0ff71fc5589e55756535183ec588b71048b198b4604", argdata, 3, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, std::vector<GL_TexVertex> *vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func198::func;
	return execfunc(tex, vec, color);
}

namespace _func199
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushStencilMode", typeid(void (*)()), ".a1????????3b05????????74??85c074??8b15????????89108b15????????8950048b15????????89500883c00ca3????????c38d4c240483e4f0", argdata, 0, 6, &func);
}

void CSurface::GL_PushStencilMode()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func199::func;
	return execfunc();
}

namespace _func200
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color )), "8d4c240483e4f0ff71fc5589e556535183ec5c8b31f30f105118f30f1035????????0f2ed6f30f10690cf30f106110f30f116dc0f30f1165c4", argdata, 7, 2, &func);
}

GL_Primitive *CSurface::GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float rotate_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func200::func;
	return execfunc(tex, x, y, size_x, size_y, rotate, color);
}

namespace _func201
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreatePixelImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), "8d4c240483e4f0ff71fc5589e556535183ec5c8b318b4128f30f106118f30f1015????????0f2ee2", argdata, 8, 2, &func);
}

GL_Primitive *CSurface::GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool unk)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float rotate_arg, GL_Color color_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func201::func;
	return execfunc(tex, x, y, size_x, size_y, rotate, color, unk);
}

namespace _func202
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiColorImage", typeid(void (*)(GL_Texture *, const std::vector<GL_ColorTexVertex> &, bool )), "5589e557565383e4f083ec508b45108b15????????8b5d088b7d0c89442430a1????????39d00f84????????29d083e0f08d4402f0f30f1018f30f106804f30f106008f30f10500c8b47042b07", argdata, 3, 6, &func);
}

void CSurface::GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_ColorTexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func202::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func203
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiImage", typeid(void (*)(GL_Texture *, const std::vector<GL_TexVertex> &, bool )), "5589e557565383e4f083ec508b45108b15????????8b5d088b750c89442420a1????????39d00f84????????29d083e0f08d4402f0f30f1020f30f106804f30f107008f30f10780cf30f1164242c", argdata, 3, 6, &func);
}

void CSurface::GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_TexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func203::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func204
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiLinePrimitive", typeid(GL_Primitive *(*)(std::vector<GL_Line> &, GL_Color , float )), "5589e557565383e4f083ec508b7d08f30f10651c8b77042b3789f2c1fa040f2e25????????0f8a????????0f85????????8d0c95????????89d08954244c", argdata, 3, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<GL_Line> &vec_arg, GL_Color color_arg, float thickness_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func204::func;
	return execfunc(vec, color, thickness);
}

namespace _func205
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiRectPrimitive", typeid(GL_Primitive *(*)(std::vector<Globals::Rect> &, GL_Color )), "5589e557565383e4f083ec408b75088b46042b06c1f8048d14c5????????89c78944243cc1e00581fa????????ba????????0f47c2", argdata, 2, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<Globals::Rect> &vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func205::func;
	return execfunc(vec, color);
}

namespace _func206
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreatePiePartialPrimitive", typeid(GL_Primitive *(*)(int , int , float , float , float , float , GL_Color )), "5589e557565383e4f081ec90020000f30f105514f30f105d180f2eda", argdata, 7, 2, &func);
}

GL_Primitive *CSurface::GL_CreatePiePartialPrimitive(int x, int y, float radius, float deg1, float deg2, float thickness, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, float radius_arg, float deg1_arg, float deg2_arg, float thickness_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func206::func;
	return execfunc(x, y, radius, deg1, deg2, thickness, color);
}

namespace _func207
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CachedImage::destructor", typeid(void (CachedImage::*)()), "558d511089e55389cb83e4f083ec108b4108c701????????39d07408890424e8????????89d9e8????????8b5dfcc9c3", argdata, 1, 5, &func);
}

void CachedImage::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func207::func;
	return execfunc(this);
}

namespace _func208
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec1c8b07890424e8????????83ec04", argdata, 2, 5, &func);
}

void CachedImage::SetImagePath(const std::string &imagePath)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &imagePath_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func208::func;
	return execfunc(this, imagePath);
}

namespace _func209
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor1", typeid(void (CachedImage::*)(const std::string &, int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b47048b0f8b5708c7430400000000c703????????8945d4", argdata, 4, 5, &func);
}

void CachedImage::constructor1(const std::string &path, int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &path_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func209::func;
	return execfunc(this, path, x, y);
}

namespace _func210
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor2", typeid(void (CachedImage::*)(const std::string &, CachedImage::Centered )), "578d51108d????0883e4??ff????5589e5575389cb83ec??8b??", argdata, 3, 5, &func);
}

void CachedImage::constructor2(const std::string &path, CachedImage::Centered centered)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &path_arg, CachedImage::Centered centered_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func210::func;
	return execfunc(this, path, centered);
}

namespace _func211
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor_copy", typeid(void (CachedImage::*)(const CachedImage &)), "578d41108d7c240883e4f0ff77fc5589e557565389cb83ec3c8b37c7410400000000", argdata, 2, 5, &func);
}

void CachedImage::constructor_copy(const CachedImage &other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const CachedImage &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func211::func;
	return execfunc(this, other);
}

namespace _func212
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetPosition", typeid(void (CachedImage::*)(int , int )), "5589e557565383e4f083ec108b75083971248b7d0c74??8b410489cb890424", argdata, 3, 5, &func);
}

void CachedImage::SetPosition(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func212::func;
	return execfunc(this, x, y);
}

namespace _func213
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetRotation", typeid(void (CachedImage::*)(float )), "5589e55383e4f083ec20f30f1045080f2e41447a0b75098b5dfcc9", argdata, 2, 5, &func);
}

void CachedImage::SetRotation(float _rotation)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float _rotation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func213::func;
	return execfunc(this, _rotation);
}

namespace _func214
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetMirrored", typeid(void (CachedImage::*)(bool )), "5589e5565383e4f083ec108b750889f038414874198b410489cb890424", argdata, 2, 5, &func);
}

void CachedImage::SetMirrored(bool _mirrored)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, bool _mirrored_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func214::func;
	return execfunc(this, _mirrored);
}

namespace _func215
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetScale", typeid(void (CachedImage::*)(float , float )), "5589e55383e4f083ec10f30f1045080f2e412c7a??75??f30f105d0c0f2e5930", argdata, 3, 5, &func);
}

void CachedImage::SetScale(float wScale, float hScale)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float wScale_arg, float hScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func215::func;
	return execfunc(this, wScale, hScale);
}

namespace _func216
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CachedImage::CreatePrimitive", typeid(void (CachedImage::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b712085f6", argdata, 1, 5, &func);
}

void CachedImage::CreatePrimitive()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func216::func;
	return execfunc(this);
}

namespace _func217
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetPartial", typeid(void (CachedImage::*)(float , float , float , float )), "5589e55383e4f083ec10f30f1045080f2e4134", argdata, 5, 5, &func);
}

void CachedImage::SetPartial(float x_start, float y_start, float x_size, float y_size)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float x_start_arg, float y_start_arg, float x_size_arg, float y_size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func217::func;
	return execfunc(this, x_start, y_start, x_size, y_size);
}

namespace _func218
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedPrimitive::OnRender", typeid(void (CachedPrimitive::*)(const GL_Color &)), "5589e55383e4f083ec308b410485c074??8b55080f1002890424660f7ec20f29442420895424048b542424", argdata, 2, 5, &func);
}

void CachedPrimitive::OnRender(const GL_Color &color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedPrimitive *this_arg, const GL_Color &color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func218::func;
	return execfunc(this, color);
}

namespace _func219
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CachedPrimitive::destructor", typeid(void (CachedPrimitive::*)()), "5589e583e4f083ec108b4104c701????????890424e8????????c9", argdata, 1, 5, &func);
}

void CachedPrimitive::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedPrimitive *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func219::func;
	return execfunc(this);
}

namespace _func220
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedRect::SetPosition", typeid(void (CachedRect::*)(int , int )), "5589e557565383e4f083ec108b75083971088b7d0c74??8b410489cb890424", argdata, 3, 5, &func);
}

void CachedRect::SetPosition(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedRect *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func220::func;
	return execfunc(this, x, y);
}

namespace _func221
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedRect::SetSize", typeid(void (CachedRect::*)(int , int )), ".5589e557565383e4f083ec108b75083971108b7d0c74??8b410489cb890424", argdata, 3, 5, &func);
}

void CachedRect::SetSize(int w, int h)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedRect *this_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func221::func;
	return execfunc(this, w, h);
}

namespace _func222
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b4350c78528feffff09000000", argdata, 1, 5, &func);
}

void ChoiceBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func222::func;
	return execfunc(this);
}

namespace _func223
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::MouseMove", typeid(void (ChoiceBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b4704894de0b9????????8b1f8945e4e8????????8b7e508b464c", argdata, 3, 5, &func);
}

void ChoiceBox::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func223::func;
	return execfunc(this, x, y);
}

namespace _func224
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::MouseClick", typeid(void (ChoiceBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec14833d????????028b078b5704", argdata, 3, 5, &func);
}

void ChoiceBox::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func224::func;
	return execfunc(this, mX, mY);
}

namespace _func225
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CloakingBox::constructor", typeid(void (CloakingBox::*)(Point , CloakingSystem *)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d75d083ec6c8b108b58088b4804c744240c00000000891424895c2408894c2404", argdata, 3, 5, &func);
}

void CloakingBox::constructor(Point pos, CloakingSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloakingBox *this_arg, Point pos_arg, CloakingSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func225::func;
	return execfunc(this, pos, sys);
}

namespace _func226
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloakingSystem::OnLoop", typeid(void (CloakingSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1ce8????????8d8bf0010000e8????????83bba8010000017e??80bbac0100000074??c70424????????", argdata, 1, 5, &func);
}

void CloakingSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func226::func;
	return execfunc(this);
}

namespace _func227
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloakingSystem::FiredWeapon", typeid(void (CloakingSystem::*)()), "57ba524500008d7c240883e4f0ff77fc5589e55756538d45d08d75d889cb83c10883ec3c668955e08975d0890424c745d8434c4f41c745dc4b5f4649c745d40a000000c645e200", argdata, 1, 5, &func);
}

void CloakingSystem::FiredWeapon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func227::func;
	return execfunc(this);
}

namespace _func228
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CloneBox::constructor", typeid(void (CloneBox::*)(Point , CloneSystem *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b5f088b078b570489cfc744240c00000000898d3cfeffff895c2408", argdata, 3, 5, &func);
}

void CloneBox::constructor(Point pos, CloneSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneBox *this_arg, Point pos_arg, CloneSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func228::func;
	return execfunc(this, pos, sys);
}

namespace _func229
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CloneSystem::__DO_NOT_HOOK", typeid(void (CloneSystem::*)()), "578d????0883e4f0ff????5589e557565389ce83ec3c8b????8b??8b????", argdata, 0, 4, &func);
}

namespace _func230
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::GetCloneTime", typeid(int (*)(int )), ".8b44????f30f2c04??????????", argdata, 1, 2, &func);
}

int CloneSystem::GetCloneTime(int level)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func230::func;
	return execfunc(level);
}

namespace _func231
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::OnLoop", typeid(void (CloneSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????898dd4feffffe8????????8b7e0c31c0b9????????", argdata, 1, 5, &func);
}

void CloneSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func231::func;
	return execfunc(this);
}

namespace _func232
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::GetProgress", typeid(float (CloneSystem::*)()), "5589e55389cb83e4f083ec10e8????????85", argdata, 1, 1, &func);
}

float CloneSystem::GetProgress()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func232::func;
	return execfunc(this);
}

namespace _func233
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::GetDeathProgress", typeid(float (CloneSystem::*)()), "660fefc983ec04f30f10??????????0f2ec877", argdata, 1, 1, &func);
}

float CloneSystem::GetDeathProgress()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func233::func;
	return execfunc(this);
}

namespace _func234
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::GetJumpHealth", typeid(int (*)(int )), "8b44????8b04??????????c3", argdata, 1, 2, &func);
}

int CloneSystem::GetJumpHealth(int level)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func234::func;
	return execfunc(level);
}

namespace _func235
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::CloneReady", typeid(CrewMember *(CloneSystem::*)()), "5589e5538b??????????c7??????????00000000", argdata, 1, 1, &func);
}

CrewMember *CloneSystem::CloneReady()
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func235::func;
	return execfunc(this);
}

namespace _func236
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::OnRenderFloor", typeid(void (CloneSystem::*)()), "578d????0883e4f0ff????5589e557565383ec5c8bb1dc010000", argdata, 1, 5, &func);
}

void CloneSystem::OnRenderFloor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func236::func;
	return execfunc(this);
}

namespace _func237
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatAI::UpdateMindControl", typeid(void (CombatAI::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b41308b178b703485f6", argdata, 2, 5, &func);
}

void CombatAI::UpdateMindControl(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatAI *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func237::func;
	return execfunc(this, unk);
}

namespace _func238
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatAI::OnLoop", typeid(void (CombatAI::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1ce8????????8b4b30e8????????84c0", argdata, 1, 5, &func);
}

void CombatAI::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func238::func;
	return execfunc(this);
}

namespace _func239
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::RenderTarget", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????8b81a400000085c074??8b401c83b8b8000000020f84????????8d8518ffffff", argdata, 1, 5, &func);
}

void CombatControl::RenderTarget()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func239::func;
	return execfunc(this);
}

namespace _func240
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::GetCurrentTarget", typeid(ShipManager *(CombatControl::*)()), "8b815c07000085c074??8b4008c3669031c0c3908db6000000008dbf000000008b895c07000085c974??558b0189e583e4f0ff5010c9", argdata, 1, 1, &func);
}

ShipManager *CombatControl::GetCurrentTarget()
{
	typedef ShipManager *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func240::func;
	return execfunc(this);
}

namespace _func241
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::CurrentTargetIsBoss", typeid(char (CombatControl::*)()), "8b895c07000085c974??558b0189e583e4f0ff5010c9c389f68dbc270000000031c0c3908db6000000008dbf00000000578d7c240883e4f0ff77fc5589f889e5", argdata, 1, 1, &func);
}

char CombatControl::CurrentTargetIsBoss()
{
	typedef char __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func241::func;
	return execfunc(this);
}

namespace _func242
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(char (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565383ec5c8b81a400000085c074??8b401c83b8b80000000374??", argdata, 1, 1, &func);
}

char CombatControl::CanTargetSelf()
{
	typedef char __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func242::func;
	return execfunc(this);
}

namespace _func243
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnRenderCombat", typeid(void (CombatControl::*)()), "80b9a80e0000000f84????????578d7c240883e4f0ff77fc5589e557565389cb83ec6c8bb15c07000085f6", argdata, 1, 5, &func);
}

void CombatControl::OnRenderCombat()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func243::func;
	return execfunc(this);
}

namespace _func244
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::AddEnemyShip", typeid(void (CombatControl::*)(CompleteShip *)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b915c0700008b0785d274??c6816011000000", argdata, 2, 5, &func);
}

void CombatControl::AddEnemyShip(CompleteShip *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func244::func;
	return execfunc(this, ship);
}

namespace _func245
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::UpdateAiming", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b817007000083f8ff", argdata, 1, 5, &func);
}

void CombatControl::UpdateAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func245::func;
	return execfunc(this);
}

namespace _func246
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::UpdateTarget", typeid(bool (CombatControl::*)()), "57660fefc98d7c240883e4f0ff77fc5589e557565389cb81ec????????f30f2a4908f30f1081c40e0000f30f5cc1", argdata, 1, 1, &func);
}

bool CombatControl::UpdateTarget()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func246::func;
	return execfunc(this);
}

namespace _func247
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::DrawHostileBox", typeid(void (CombatControl::*)(GL_Color , int )), "578d7c240883e4f0ff77fc5589e55756538d5dd089ce83ec7c8b471089d9c744240400000000c70424????????8945b8e8????????8b86680700000345d4", argdata, 3, 5, &func);
}

void CombatControl::DrawHostileBox(GL_Color color, int stencilBit)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, GL_Color color_arg, int stencilBit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func247::func;
	return execfunc(this, color, stencilBit);
}

namespace _func248
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CombatControl::OnInit", typeid(void (CombatControl::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b078b57048981640700008b816411000089916807000085c00f84????????8d8b68110000e8????????a1????????", argdata, 2, 5, &func);
}

void CombatControl::OnInit(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func248::func;
	return execfunc(this, pos);
}

namespace _func249
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnLoop", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565331f689cb83ec2c8b91440700008b814807000029d0c1f80285c074??", argdata, 1, 5, &func);
}

void CombatControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func249::func;
	return execfunc(this);
}

namespace _func250
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::SetMouseCursor", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b89a400000085c974??0fb683a8000000f30f1005????????3205????????8b93c00300000f2e83b40e00000fb6c0", argdata, 1, 5, &func);
}

void CombatControl::SetMouseCursor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func250::func;
	return execfunc(this);
}

namespace _func251
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::DisarmAll", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b915c07000085d274??8b4904c70424????????e8????????83ec0484c0", argdata, 1, 5, &func);
}

void CombatControl::DisarmAll()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func251::func;
	return execfunc(this);
}

namespace _func252
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::SelectTarget", typeid(bool (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b4904c70424????????e8????????83ec0484c0", argdata, 1, 1, &func);
}

bool CombatControl::SelectTarget()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func252::func;
	return execfunc(this);
}

namespace _func253
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseRClick", typeid(bool (CombatControl::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b81a40000008b378b7f0485c074??b8????????89d98845e7", argdata, 3, 1, &func);
}

bool CombatControl::MouseRClick(int x, int y)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func253::func;
	return execfunc(this, x, y);
}

namespace _func254
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::WeaponsArmed", typeid(bool (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b4904c70424????????e8????????83ec0484c075??8b83a400000085c0", argdata, 1, 1, &func);
}

bool CombatControl::WeaponsArmed()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func254::func;
	return execfunc(this);
}

namespace _func255
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::KeyDown", typeid(void (CombatControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389cb83c11483ec1c8b37893424e8????????83ec0484c074??8b4b04", argdata, 2, 5, &func);
}

void CombatControl::KeyDown(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func255::func;
	return execfunc(this, key);
}

namespace _func256
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::DisarmTeleporter", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b4904c70424????????e8????????83ec0484c089c6", argdata, 1, 5, &func);
}

void CombatControl::DisarmTeleporter()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func256::func;
	return execfunc(this);
}

namespace _func257
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::constructor", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83c1088d5d9c81ec????????c741f800000000c741fc00000000e8????????8d4e14c7461000000000e8????????8d8ec4030000", argdata, 1, 5, &func);
}

void CombatControl::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func257::func;
	return execfunc(this);
}

namespace _func258
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnRenderSelfAiming", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83c11483ec30e8????????8b4b04c70424????????e8????????83ec0484c00f84????????8b4b04", argdata, 1, 5, &func);
}

void CombatControl::OnRenderSelfAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func258::func;
	return execfunc(this);
}

namespace _func259
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x4ff};
	static FunctionDefinition funcObj("CombatControl::RenderShipStatus", typeid(void (CombatControl::*)(Pointf , GL_Color )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b188b7004898564ffffffe8????????89742404891c248d75d0c744240800000000", argdata, 3, 5, &func);
}

void CombatControl::RenderShipStatus(Pointf pos, GL_Color color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, Pointf pos_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func259::func;
	return execfunc(this, pos, color);
}

namespace _func260
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::GetCrewTooltip", typeid(std::string (CombatControl::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b178b4f048b77088b825c07000085c074??2bb2680700002bb27807000089742408", argdata, 4, 1, &func);
}

std::string CombatControl::GetCrewTooltip(int x, int y)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func260::func;
	return execfunc(this, x, y);
}

namespace _func261
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::Clear", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec1cc7815c07000000000000c78160070000000000008b490485c9", argdata, 1, 5, &func);
}

void CombatControl::Clear()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func261::func;
	return execfunc(this);
}

namespace _func262
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseMove", typeid(bool (CombatControl::*)(int , int )), "57660fefc08d7c240883e4f0ff77fc5589e557565383ec2c8b378b5f040fb681a80e0000", argdata, 3, 1, &func);
}

bool CombatControl::MouseMove(int mX, int mY)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func262::func;
	return execfunc(this, mX, mY);
}

namespace _func263
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseClick", typeid(void (CombatControl::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83c11483ec1c8b378b7f04c681b80e000001c744240800000000897c2404893424", argdata, 4, 5, &func);
}

void CombatControl::MouseClick(int mX, int mY, bool shift)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func263::func;
	return execfunc(this, mX, mY, shift);
}

namespace _func264
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::GetTeleportationCommand", typeid(std::pair<int, int> (CombatControl::*)()), "5589e55756538b815c07000089ce83e4f085c0", argdata, 1, 9, &func);
}

std::pair<int, int> CombatControl::GetTeleportationCommand()
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func264::func;
	return execfunc(this);
}

namespace _func265
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatDrone::constructor", typeid(void (CombatDrone::*)(int , int , const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b57048b078b77088d7da889542404890424", argdata, 4, 5, &func);
}

void CombatDrone::constructor(int iShipId, int selfId, const DroneBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatDrone *this_arg, int iShipId_arg, int selfId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func265::func;
	return execfunc(this, iShipId, selfId, bp);
}

namespace _func266
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatDrone::SetWeaponTarget", typeid(void (CombatDrone::*)(Targetable *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b3785f6", argdata, 2, 5, &func);
}

void CombatDrone::SetWeaponTarget(Targetable *target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func266::func;
	return execfunc(this, target);
}

namespace _func267
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatDrone::PickTarget", typeid(void (CombatDrone::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b01ff908000000084c0", argdata, 1, 5, &func);
}

void CombatDrone::PickTarget()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func267::func;
	return execfunc(this);
}

namespace _func268
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(void (CommandGui::*)(std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ec????????8b378945888d45a8898d7cffffff8d4d88c7458c00000000c6459000", argdata, 2, 5, &func);
}

void CommandGui::RunCommand(std::string &command)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, std::string &command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func268::func;
	return execfunc(this, command);
}

namespace _func269
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::CreateNewStore", typeid(Store *(CommandGui::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b178dbbdc380000c70424????????", argdata, 2, 1, &func);
}

Store *CommandGui::CreateNewStore(int sectorNumber)
{
	typedef Store *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int sectorNumber_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func269::func;
	return execfunc(this, sectorNumber);
}

namespace _func270
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::GetWorldCoordinates", typeid(Point (CommandGui::*)(Point , bool )), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd883ec3c8b078b77048b7f088945d4e8????????", argdata, 3, 9, &func);
}

Point CommandGui::GetWorldCoordinates(Point point, bool fromTarget)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, Point point_arg, bool fromTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func270::func;
	return execfunc(this, point, fromTarget);
}

namespace _func271
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::KeyDown", typeid(void (CommandGui::*)(SDLKey , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b984420000008b47048b378945b4", argdata, 3, 5, &func);
}

void CommandGui::KeyDown(SDLKey key, bool shiftHeld)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, SDLKey key_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func271::func;
	return execfunc(this, key, shiftHeld);
}

namespace _func272
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c803d??????????0f85????????8b83081700008b4808c70424????????81c1????????e8????????", argdata, 1, 5, &func);
}

void CommandGui::RenderStatic()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func272::func;
	return execfunc(this);
}

namespace _func273
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RenderPlayerShip", typeid(void (CommandGui::*)(Point &, float )), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd883ec3c8b37f30f104704c744240400000000c7042400000000f30f1145d4", argdata, 3, 5, &func);
}

void CommandGui::RenderPlayerShip(Point &shipCenter, float jumpScale)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, Point &shipCenter_arg, float jumpScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func273::func;
	return execfunc(this, shipCenter, jumpScale);
}

namespace _func274
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::constructor", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db3881e00008dbb7c2e000081ec????????e8????????8d8b78010000e8????????8d8b20030000e8????????8d8bc8030000e8????????", argdata, 1, 5, &func);
}

void CommandGui::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func274::func;
	return execfunc(this);
}

namespace _func275
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::AddEnemyShip", typeid(void (CommandGui::*)(CompleteShip *)), "578d7c240883e4f0ff77fc5589e557565389cb81c1????????83ec5c8b378d7dc0", argdata, 2, 5, &func);
}

void CommandGui::AddEnemyShip(CompleteShip *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func275::func;
	return execfunc(this, ship);
}

namespace _func276
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::Victory", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????8b8108170000898d7cffffff8b400880b868060000000f85????????", argdata, 1, 5, &func);
}

void CommandGui::Victory()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func276::func;
	return execfunc(this);
}

namespace _func277
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::OnInit", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e55756538d992003000089cf8d75cc81ec????????898d54ffffff89d9e8????????ba????????8d8d5cffffffc70424????????", argdata, 1, 5, &func);
}

void CommandGui::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func277::func;
	return execfunc(this);
}

namespace _func278
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::MouseMove", typeid(void (CommandGui::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????81ec????????8b1f8b7f04891c24897c2404e8????????8b960c1700008b8610170000", argdata, 3, 5, &func);
}

void CommandGui::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func278::func;
	return execfunc(this, mX, mY);
}

namespace _func279
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LButtonDown", typeid(void (CommandGui::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b470480b984420000008b37", argdata, 4, 5, &func);
}

void CommandGui::LButtonDown(int mX, int mY, bool shiftHeld)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func279::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func280
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::OnLoop", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c0fb6b18442000089f084c00f85????????8b81d83f000085c074??", argdata, 1, 5, &func);
}

void CommandGui::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func280::func;
	return execfunc(this);
}

namespace _func281
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::CheckGameover", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d45a883ec7c8b89081700008945a0c745a4000000008b7108c645a800", argdata, 1, 5, &func);
}

void CommandGui::CheckGameover()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func281::func;
	return execfunc(this);
}

namespace _func282
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::IsGameOver", typeid(bool (CommandGui::*)()), "803d??????????75??5589e55389cb8b890817000083e4f085c974??8b41088b108b524481fa????????75??80b8990400000075??e8????????84c0", argdata, 1, 1, &func);
}

bool CommandGui::IsGameOver()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func282::func;
	return execfunc(this);
}

namespace _func283
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::NewLocation", typeid(void (CommandGui::*)(const std::string &, std::vector<ChoiceText> *, ResourceEvent &, bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b5f04898dd8fdffff8985d4fdffff8b47088985e4fdffff", argdata, 5, 5, &func);
}

void CommandGui::NewLocation(const std::string &mainText, std::vector<ChoiceText> *choices, ResourceEvent &resources, bool testingEvents)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, const std::string &mainText_arg, std::vector<ChoiceText> *choices_arg, ResourceEvent &resources_arg, bool testingEvents_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func283::func;
	return execfunc(this, mainText, choices, resources, testingEvents);
}

namespace _func284
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LButtonUp", typeid(void (CommandGui::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b0780b984420000008b77048945e48b47088945e075??8bb90c1700008b911017000089cb29fac1fa0285d2", argdata, 4, 5, &func);
}

void CommandGui::LButtonUp(int mX, int mY, bool shiftHeld)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func284::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func285
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(void (CompleteShip::*)()), "558b490889e583e4f0e8????????c9c3578d7c240883e4f0ff77fc", argdata, 1, 5, &func);
}

void CompleteShip::PauseLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func285::func;
	return execfunc(this);
}

namespace _func286
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b4908e8????????8b43088d4b18c744240400000000", argdata, 1, 5, &func);
}

void CompleteShip::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func286::func;
	return execfunc(this);
}

namespace _func287
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(void (CompleteShip::*)(SpaceManager *, bool , int )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b47048b4f088b17c703????????c7430800000000", argdata, 4, 5, &func);
}

void CompleteShip::constructor(SpaceManager *space, bool unk, int unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, SpaceManager *space_arg, bool unk_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func287::func;
	return execfunc(this, space, unk, unk2);
}

namespace _func288
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(void (CompleteShip::*)(ShipManager *)), ".5783c1188d7c240883e4f0ff77fc5589e55783ec148b078b90bc0700008941f089042489542404e8????????", argdata, 2, 5, &func);
}

void CompleteShip::SetShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func288::func;
	return execfunc(this, ship);
}

namespace _func289
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(void (CompleteShip::*)(const ShipBlueprint *, int )), ".578d7c240883e4f0ff77fc5589f889e557565389cb83ec2c8b50048b3fc70424????????8955e4e8????????", argdata, 3, 5, &func);
}

void CompleteShip::OnInit(const ShipBlueprint *blueprint, int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const ShipBlueprint *blueprint_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func289::func;
	return execfunc(this, blueprint, unk);
}

namespace _func290
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , const std::string &, bool )), ".578d7c240883e4f0ff77fc5589f889e557565389cf8d4d8c81ec????????8b10", argdata, 4, 5, &func);
}

void CompleteShip::AddBoarders(int amount, const std::string &race, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int amount_arg, const std::string &race_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func290::func;
	return execfunc(this, amount, race, unk2);
}

namespace _func291
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(CrewMember *(CompleteShip::*)(const CrewBlueprint *, bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b07898d50feffff8b7f04", argdata, 3, 1, &func);
}

CrewMember *CompleteShip::AddCrewMember(const CrewBlueprint *blueprint, bool hostile)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const CrewBlueprint *blueprint_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func291::func;
	return execfunc(this, blueprint, hostile);
}

namespace _func292
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(const std::string &, const std::string &, bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b4708", argdata, 4, 1, &func);
}

CrewMember *CompleteShip::AddCrewMember1(const std::string &race, const std::string &name, bool hostile)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const std::string &race_arg, const std::string &name_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func292::func;
	return execfunc(this, race, name, hostile);
}

namespace _func293
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddDrone", typeid(Drone *(CompleteShip::*)(const DroneBlueprint *, int )), ".578d7c240883e4f0ff77fc5589e55783ec14", argdata, 3, 1, &func);
}

Drone *CompleteShip::AddDrone(const DroneBlueprint *blueprint, int unk)
{
	typedef Drone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const DroneBlueprint *blueprint_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func293::func;
	return execfunc(this, blueprint, unk);
}

namespace _func294
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember2", typeid(CrewMember *(CompleteShip::*)(CrewMember *, int )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b378b7f0485f6", argdata, 3, 1, &func);
}

CrewMember *CompleteShip::AddCrewMember2(CrewMember *member, int unk)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, CrewMember *member_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func294::func;
	return execfunc(this, member, unk);
}

namespace _func295
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(void (CompleteShip::*)(int )), ".5589e583e4f083ec108b8130010000894424048b4508", argdata, 2, 5, &func);
}

void CompleteShip::SaveState(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func295::func;
	return execfunc(this, unk);
}

namespace _func296
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(void (CompleteShip::*)(int )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec208b07890424", argdata, 2, 5, &func);
}

void CompleteShip::LoadState(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func296::func;
	return execfunc(this, unk);
}

namespace _func297
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(void (CompleteShip::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec4c8b811c0100003981180100008b178b7704", argdata, 3, 5, &func);
}

void CompleteShip::InitiateTeleport(int targetRoom, int command)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int targetRoom_arg, int command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func297::func;
	return execfunc(this, targetRoom, command);
}

namespace _func298
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cf31db83ec2c8b4908e8????????", argdata, 1, 5, &func);
}

void CompleteShip::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func298::func;
	return execfunc(this);
}

namespace _func299
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::GetTeleportingParty", typeid(std::vector<CrewMember*> (CompleteShip::*)()), ".5589e557565389cb83e4f083ec208b7d088bb7280100008b872401000039c60f84????????", argdata, 2, 1, &func);
}

std::vector<CrewMember*> CompleteShip::GetTeleportingParty()
{
	typedef std::vector<CrewMember*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func299::func;
	return execfunc(this);
}

namespace _func300
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::KillRandomCrew", typeid(void (CompleteShip::*)()), ".558b490889e583e4f0e8????????c9", argdata, 1, 5, &func);
}

void CompleteShip::KillRandomCrew()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func300::func;
	return execfunc(this);
}

namespace _func301
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::CountCrew", typeid(int (CompleteShip::*)(bool )), ".578d7c240883e4f0ff77fc5589e55783ec140fb6078b4908890424e8????????8b7dfc", argdata, 2, 1, &func);
}

int CompleteShip::CountCrew(bool boarders)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool boarders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func301::func;
	return execfunc(this, boarders);
}

namespace _func302
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(void (CompleteShip::*)()), ".8b811801000089811c0100008b8124010000898128010000", argdata, 1, 5, &func);
}

void CompleteShip::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func302::func;
	return execfunc(this);
}

namespace _func303
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetEnemyShip", typeid(void (CompleteShip::*)(CompleteShip *)), ".5783c1188d7c240883e4f0ff77fc5589e55783ec14", argdata, 2, 5, &func);
}

void CompleteShip::SetEnemyShip(CompleteShip *other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, CompleteShip *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func303::func;
	return execfunc(this, other);
}

namespace _func304
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec1c0fb64114b9????????", argdata, 1, 1, &func);
}

bool CompleteShip::DeadCrew()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func304::func;
	return execfunc(this);
}

namespace _func305
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::TeleportCrew", typeid(std::vector<CrewMember*> (CompleteShip::*)(int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 1, &func);
}

std::vector<CrewMember*> CompleteShip::TeleportCrew(int roomId, bool intruders)
{
	typedef std::vector<CrewMember*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int roomId_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func305::func;
	return execfunc(this, roomId, intruders);
}

namespace _func306
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnRender", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b43048b490c", argdata, 1, 5, &func);
}

void CompleteShip::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func306::func;
	return execfunc(this);
}

namespace _func307
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnRenderSpace", typeid(void (CompleteShip::*)()), ".578d7c240883e4f0ff77fc5589e55783ec14", argdata, 1, 5, &func);
}

void CompleteShip::OnRenderSpace()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func307::func;
	return execfunc(this);
}

namespace _func308
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(void (CompleteShip::*)(bool , bool )), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 3, 5, &func);
}

void CompleteShip::OnRenderShip(bool unk1, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool unk1_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func308::func;
	return execfunc(this, unk1, unk2);
}

namespace _func309
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetText", typeid(void (ConfirmWindow::*)(const TextString &, int , bool , const TextString &, const TextString &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec7c8b5008", argdata, 6, 5, &func);
}

void ConfirmWindow::SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, const TextString &text__arg, int minWidth_arg, bool autoCenter_arg, const TextString &yesText__arg, const TextString &noText__arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func309::func;
	return execfunc(this, text_, minWidth, autoCenter, yesText_, noText_);
}

namespace _func310
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::OnRender", typeid(void (ConfirmWindow::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b8184000000", argdata, 1, 5, &func);
}

void ConfirmWindow::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func310::func;
	return execfunc(this);
}

namespace _func311
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetPosition", typeid(void (ConfirmWindow::*)(Point )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b570489042489542404e8????????8b838400000083ec08", argdata, 2, 5, &func);
}

void ConfirmWindow::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func311::func;
	return execfunc(this, pos);
}

namespace _func312
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::Open", typeid(void (ConfirmWindow::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3ce8????????807b7c000f84????????8b938000000089d085c00f84????????8b52088b03", argdata, 1, 5, &func);
}

void ConfirmWindow::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func312::func;
	return execfunc(this);
}

namespace _func313
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseClick", typeid(void (ConfirmWindow::*)(int , int )), "8079040074??5589e55389cb83e4f083ec1080b9c80000000075??80bbb80100000074??80bbb90100000074??8b03", argdata, 3, 5, &func);
}

void ConfirmWindow::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func313::func;
	return execfunc(this, mX, mY);
}

namespace _func314
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseMove", typeid(void (ConfirmWindow::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec1c807904008b378b7f0474??89cb", argdata, 3, 5, &func);
}

void ConfirmWindow::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func314::func;
	return execfunc(this, mX, mY);
}

namespace _func315
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::constructor", typeid(void (ConfirmWindow::*)()), "5589e55389cb83e4f0e8????????8d43248d8b88000000c703????????c7432000000000c643240089431c8d434cc6433401c7433800000000c7434000000000894344", argdata, 1, 5, &func);
}

void ConfirmWindow::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func315::func;
	return execfunc(this);
}

namespace _func316
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::Close", typeid(void (ConfirmWindow::*)()), "5589e55389cb83e4f083ec108b8184000000890424e8????????c783840000000000000089d9e8????????8b5dfc", argdata, 1, 5, &func);
}

void ConfirmWindow::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func316::func;
	return execfunc(this);
}

namespace _func317
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ControlButton::OnRender", typeid(void (ControlButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b415c83f8010f84????????f30f102d????????83f802f30f1035????????f30f103d????????f30f116da0f30f1175a4", argdata, 1, 5, &func);
}

void ControlButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ControlButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func317::func;
	return execfunc(this);
}

namespace _func318
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ControlsScreen::OnInit", typeid(void (ControlsScreen::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????8b8144050000898d74feffff85c00f84????????8d8570ffffffbf????????8d8d4cffffff6689bd7cffffff", argdata, 1, 5, &func);
}

void ControlsScreen::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func318::func;
	return execfunc(this);
}

namespace _func319
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ControlsScreen::OnLoop", typeid(void (ControlsScreen::*)()), "578d7c240883e4f0ff77fc5589e55756538d45a889ce83ec7c8b79108b59148945a089f801d874??85ff", argdata, 1, 5, &func);
}

void ControlsScreen::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func319::func;
	return execfunc(this);
}

namespace _func320
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ControlsScreen::OnRender", typeid(void (ControlsScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b928010000000f85????????8d8520ffffff8d8d18ffffffc744240400000000c78500ffffff1d000000898518ffffff8d8500ffffff890424e8????????8b9500ffffff", argdata, 1, 5, &func);
}

void ControlsScreen::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func320::func;
	return execfunc(this);
}

namespace _func321
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CooldownSystemBox::constructor", typeid(void (CooldownSystemBox::*)(Point , ShipSystem *, bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b1f8b77048b47088b7f0cc744240c01000000898db0fdffff891c248974240483c324", argdata, 4, 5, &func);
}

void CooldownSystemBox::constructor(Point pos, ShipSystem *sys, bool roundDown)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, bool roundDown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func321::func;
	return execfunc(this, pos, sys, roundDown);
}

namespace _func322
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CooldownSystemBox::OnRender", typeid(void (CooldownSystemBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c0fb607890424e8????????8b0383ec0489d9", argdata, 2, 5, &func);
}

void CooldownSystemBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func322::func;
	return execfunc(this, ignoreStatus);
}

namespace _func323
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::OnRender", typeid(void (CreditScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d7dd881ec????????e8????????b9????????e8????????8d45d88d4dd0c744240400000000", argdata, 1, 5, &func);
}

void CreditScreen::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func323::func;
	return execfunc(this);
}

namespace _func324
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::constructor", typeid(void (CreditScreen::*)()), "8d410cc7410800000000c6410c00c7412000000000c64124008941048d4124c7413400000000c7413c00000000c741400000000089411cc7414400000000c7414800000000", argdata, 1, 5, &func);
}

void CreditScreen::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func324::func;
	return execfunc(this);
}

namespace _func325
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CreditScreen::Start", typeid(void (CreditScreen::*)(const std::string &, const std::vector<std::string> &)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d9d20ffffff81ec????????8b088b4004c744240400000000899d18ffffffc78500ffffff100000008985b8feffff8d8500ffffff", argdata, 3, 5, &func);
}

void CreditScreen::Start(const std::string &shipName, const std::vector<std::string> &crewNames)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CreditScreen *this_arg, const std::string &shipName_arg, const std::vector<std::string> &crewNames_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func325::func;
	return execfunc(this, shipName, crewNames);
}

namespace _func326
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), "55660fefc089e553bb????????83e4f083ec108b51402b513cc1fa0369d2????????89d0f7e3b8????????d1ea8d1492c1e20329d0f30f2ac00f2e01", argdata, 1, 1, &func);
}

bool CreditScreen::Done()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func326::func;
	return execfunc(this);
}

namespace _func327
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::UpdateDrones", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????8b510c8b4110c745940000000029d0c1f80285c00f84????????89cfeb??", argdata, 1, 5, &func);
}

void CrewAI::UpdateDrones()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func327::func;
	return execfunc(this);
}

namespace _func328
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::AssignCrewmembers", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b49308b463429c8c1f80269c0????????", argdata, 1, 5, &func);
}

void CrewAI::AssignCrewmembers()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func328::func;
	return execfunc(this);
}

namespace _func329
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x3ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeTask", typeid(int (CrewAI::*)(CrewTask , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b700c8b188b50048b4008", argdata, 3, 1, &func);
}

int CrewAI::PrioritizeTask(CrewTask task, int crewId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewTask task_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func329::func;
	return execfunc(this, task, crewId);
}

namespace _func330
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::UpdateIntruders", typeid(void (CrewAI::*)()), "8b511c8b411839d00f84????????5729c2c1fa028d7c240883e4f0ff77fc5589e557565331db89ce83ec3c", argdata, 1, 5, &func);
}

void CrewAI::UpdateIntruders()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func330::func;
	return execfunc(this);
}

namespace _func331
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeIntruderRoom", typeid(int (CrewAI::*)(CrewMember *, int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b77048b7f088945e4897dd889c78b4078c70424????????", argdata, 4, 1, &func);
}

int CrewAI::PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewMember *crew_arg, int roomId_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func331::func;
	return execfunc(this, crew, roomId, target);
}

namespace _func332
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::UpdateCrewMember", typeid(void (CrewAI::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b410c8b178b3c908b87a80100008b9fa4010000", argdata, 2, 5, &func);
}

void CrewAI::UpdateCrewMember(int crewId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func332::func;
	return execfunc(this, crewId);
}

namespace _func333
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::CheckForHealing", typeid(void (CrewAI::*)()), "8b510c8b4110c641070029d0c1f80285c00f84????????578d7c240883e4f0ff77fc5589e557565389ce31db83ec3c", argdata, 1, 5, &func);
}

void CrewAI::CheckForHealing()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func333::func;
	return execfunc(this);
}

namespace _func334
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::OnLoop", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8b018d4dd0890424e8????????8b55d08b460c", argdata, 1, 5, &func);
}

void CrewAI::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func334::func;
	return execfunc(this);
}

namespace _func335
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::CheckForProblems", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec7c8b01c64108018b4004890424", argdata, 1, 5, &func);
}

void CrewAI::CheckForProblems()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func335::func;
	return execfunc(this);
}

namespace _func336
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::DangerRating", typeid(int (CrewAI::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b47048b1f89c18945a88b460c8b0488f30f105028", argdata, 3, 1, &func);
}

int CrewAI::DangerRating(int roomId, int crewId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg, int roomId_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func336::func;
	return execfunc(this, roomId, crewId);
}

namespace _func337
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::constructor", typeid(void (CrewAnimation::*)(int , const std::string &, Pointf , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57048b078b5f088b770c894da0", argdata, 5, 5, &func);
}

void CrewAnimation::constructor(int shipId, const std::string &race, Pointf unk, bool hostile)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, int shipId_arg, const std::string &race_arg, Pointf unk_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func337::func;
	return execfunc(this, shipId, race, unk, hostile);
}

namespace _func338
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetDeathSound", typeid(std::string (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec308b0780b8c40900000074??803d??????????0f85????????", argdata, 2, 1, &func);
}

std::string CrewAnimation::GetDeathSound()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func338::func;
	return execfunc(this);
}

namespace _func339
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetShootingSound", typeid(std::string (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c803d??????????0f84????????e8????????89c189c8ba????????8d75d0f7ea", argdata, 2, 1, &func);
}

std::string CrewAnimation::GetShootingSound()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func339::func;
	return execfunc(this);
}

namespace _func340
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnRender", typeid(void (CrewAnimation::*)(float , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec7c8b59048b7008f30f102f8b7f04", argdata, 4, 5, &func);
}

void CrewAnimation::OnRender(float scale, int selectedState, bool outlineOnly)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, float scale_arg, int selectedState_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func340::func;
	return execfunc(this, scale, selectedState, outlineOnly);
}

namespace _func341
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::OnRenderProps", typeid(void (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557565389cb31f683ec3ce8????????8b93900800008b8394080000", argdata, 1, 5, &func);
}

void CrewAnimation::OnRenderProps()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func341::func;
	return execfunc(this);
}

namespace _func342
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnInit", typeid(void (CrewAnimation::*)(const std::string &, Pointf , bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b570889c18985dcfeffff", argdata, 4, 5, &func);
}

void CrewAnimation::OnInit(const std::string &name, Pointf position, bool enemy)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, const std::string &name_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func342::func;
	return execfunc(this, name, position, enemy);
}

namespace _func343
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::SetupStrips", typeid(void (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557568d8578feffff5389cf81ec????????898570feffff8b91ac0900008b81a80900008d8d70feffff", argdata, 1, 5, &func);
}

void CrewAnimation::SetupStrips()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func343::func;
	return execfunc(this);
}

namespace _func344
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdate", typeid(void (CrewAnimation::*)(Pointf , bool , bool , bool , bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b078b57048b4f088b770c8945c08b47108955c48b57148b7f188945bc8b433883f8060f84????????84d20f85????????80bbec09000000", argdata, 7, 5, &func);
}

void CrewAnimation::OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, Pointf position_arg, bool moving_arg, bool fighting_arg, bool repairing_arg, bool dying_arg, bool onFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func344::func;
	return execfunc(this, position, moving, fighting, repairing, dying, onFire);
}

namespace _func345
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::destructor", typeid(void (CrewAnimation::*)()), "5589e557565383e4f083ec308b81c8090000c701????????894c242085c074??890424e8????????8b4c24208b81a80900008d91b009000039d074??890424", argdata, 1, 5, &func);
}

void CrewAnimation::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func345::func;
	return execfunc(this);
}

namespace _func346
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::FireShot", typeid(bool (CrewAnimation::*)()), "5589e5538d999c08000083e4f089d9e8????????89d9e8????????8b5dfc", argdata, 1, 1, &func);
}

bool CrewAnimation::FireShot()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func346::func;
	return execfunc(this);
}

namespace _func347
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::GetFiringFrame", typeid(int (CrewAnimation::*)()), "8b413483f8ff74??8b513c89d183e1fd83f90174??83fa0274??83f8010f94c00fb6c083c001c389f68dbc270000000083f8020f94c0", argdata, 1, 1, &func);
}

int CrewAnimation::GetFiringFrame()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func347::func;
	return execfunc(this);
}

namespace _func348
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::RenderIcon", typeid(void (CrewAnimation::*)(bool )), "578d7c240883e4f0ff77fc5589e55756538db51cffffff89cb81ec1c010000803f008b41088b00", argdata, 2, 5, &func);
}

void CrewAnimation::RenderIcon(bool border)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, bool border_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func348::func;
	return execfunc(this, border);
}

namespace _func349
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdateEffects", typeid(void (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83c14083ec2ce8????????8b8e900800008b8694080000", argdata, 1, 5, &func);
}

void CrewAnimation::OnUpdateEffects()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func349::func;
	return execfunc(this);
}

namespace _func350
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RandomSkills", typeid(void (CrewBlueprint::*)(int )), "578d7c240883e4f0ff77fc5589fa89e557565389cb83ec3c8b07c745d80000000085c0", argdata, 2, 5, &func);
}

void CrewBlueprint::RandomSkills(int worldLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func350::func;
	return execfunc(this, worldLevel);
}

namespace _func351
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderSkill", typeid(void (CrewBlueprint::*)(int , int , int , int , int )), "57660fefc0660fefc98d7c240883e4f0ff77fc5589e557565383ec7c8b078b57108b77088b5f0c8945d48b47048bb904010000", argdata, 6, 5, &func);
}

void CrewBlueprint::RenderSkill(int x, int y, int length, int height, int skill)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int x_arg, int y_arg, int length_arg, int height_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func351::func;
	return execfunc(this, x, y, length, height, skill);
}

namespace _func352
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderIcon", typeid(void (CrewBlueprint::*)(float )), "578d7c240883e4f0ff77fc5589e557568d8520ffffff5389ce8d9d20ffffff81ec????????898518ffffff8b51088b4104f30f10278dbd18fffffff30f11a5b0fdffff01c289042489f989542404", argdata, 2, 5, &func);
}

void CrewBlueprint::RenderIcon(float opacity)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, float opacity_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func352::func;
	return execfunc(this, opacity);
}

namespace _func353
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBlueprint::destructor", typeid(void (CrewBlueprint::*)()), "5589e557565389ce83e4f083ec108b811c010000c701????????85c074??890424e8????????8bbe140100008b9e1001000039df74??", argdata, 1, 5, &func);
}

void CrewBlueprint::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func353::func;
	return execfunc(this);
}

namespace _func354
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::GetNameShort", typeid(std::string (CrewBlueprint::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b1f80bbd4000000008dbbbc000000", argdata, 2, 1, &func);
}

std::string CrewBlueprint::GetNameShort()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func354::func;
	return execfunc(this);
}

namespace _func355
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::GetCurrentSkillColor", typeid(GL_Color (CrewBlueprint::*)(int )), "8b54240489c88b4c2408660fefc0660fefc98b9204010000", argdata, 3, 1, &func);
}

GL_Color CrewBlueprint::GetCurrentSkillColor(int skill)
{
	typedef GL_Color __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func355::func;
	return execfunc(this, skill);
}

namespace _func356
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::constructor", typeid(void (CrewBox::*)(Point , CrewMember *, int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b70088b088b50048b580c", argdata, 4, 5, &func);
}

void CrewBox::constructor(Point pos, CrewMember *crew, int number)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg, Point pos_arg, CrewMember *crew_arg, int number_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func356::func;
	return execfunc(this, pos, crew, number);
}

namespace _func357
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::OnRender", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81c1????????83ec6ce8????????8d8b74020000e8????????", argdata, 1, 5, &func);
}

void CrewBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func357::func;
	return execfunc(this);
}

namespace _func358
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::GetSelected", typeid(CrewMember *(CrewBox::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b4004c744240c00000000", argdata, 3, 1, &func);
}

CrewMember *CrewBox::GetSelected(int mouseX, int mouseY)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func358::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func359
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::OnLoop", typeid(void (CrewBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b49208b378b11", argdata, 2, 5, &func);
}

void CrewBox::OnLoop(bool selected)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg, bool selected_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func359::func;
	return execfunc(this, selected);
}

namespace _func360
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::OnRenderSkillLevel", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec3080b9300100000075??8b43048d4de8", argdata, 1, 5, &func);
}

void CrewBox::OnRenderSkillLevel()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func360::func;
	return execfunc(this);
}

namespace _func361
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::destructor", typeid(void (CrewBox::*)()), "5589e557565389ce83e4f083ec208b813c010000894c2418890424e8????????8b8640010000890424e8????????8b8644010000890424e8????????8b8648010000890424", argdata, 1, 5, &func);
}

void CrewBox::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func361::func;
	return execfunc(this);
}

namespace _func362
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::MouseClick", typeid(bool (CrewBox::*)()), "5589e5530fb6596883e4f084db74130fb6596984db740b8b49208b01ff90c400000089d88b5dfcc9", argdata, 1, 1, &func);
}

bool CrewBox::MouseClick()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func362::func;
	return execfunc(this);
}

namespace _func363
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::RenderIcon", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b49208b01ff90c80000003c0119f6", argdata, 1, 5, &func);
}

void CrewBox::RenderIcon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func363::func;
	return execfunc(this);
}

namespace _func364
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::RenderLabels", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e55756538d5dd089ce83ec6c8b412089d9890424", argdata, 1, 5, &func);
}

void CrewBox::RenderLabels()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func364::func;
	return execfunc(this);
}

namespace _func365
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::RenderCloneDying", typeid(void (CrewBox::*)()), "80b91c010000000f859b0000008b4120f30f1080f00600000f2e05????????0f868300000055660fefd2660fefc989e583e4f083ec308b4108", argdata, 1, 5, &func);
}

void CrewBox::RenderCloneDying()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func365::func;
	return execfunc(this);
}

namespace _func366
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::OnRender", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b793c8b414029f8c1f80285c0", argdata, 1, 5, &func);
}

void CrewControl::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func366::func;
	return execfunc(this);
}

namespace _func367
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::OnLoop", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e557568db18c0000005389cb83ec6c89f1e8????????80bb9e000000000f85????????89d9", argdata, 1, 5, &func);
}

void CrewControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func367::func;
	return execfunc(this);
}

namespace _func368
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::UpdateCrewBoxes", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e55756538d45dc89cbb9????????83ec5cc745dc00000000c745e000000000890424c744240400000000", argdata, 1, 5, &func);
}

void CrewControl::UpdateCrewBoxes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func368::func;
	return execfunc(this);
}

namespace _func369
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LinkShip", typeid(void (CrewControl::*)(ShipManager *)), "5589e55389cb8b450883e4f08901e8????????c7432000000000c7431c000000008b5dfc", argdata, 2, 5, &func);
}

void CrewControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func369::func;
	return execfunc(this, ship);
}

namespace _func370
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::MouseMove", typeid(void (CrewControl::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57088b378b4704", argdata, 5, 5, &func);
}

void CrewControl::MouseMove(int mX, int mY, int wX, int wY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, int wX_arg, int wY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func370::func;
	return execfunc(this, mX, mY, wX, wY);
}

namespace _func371
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LButton", typeid(void (CrewControl::*)(int , int , int , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec5c8b178b89840000008b7f048955b48b50088b400c", argdata, 6, 5, &func);
}

void CrewControl::LButton(int mX, int mY, int wX, int wY, bool shiftHeld)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, int wX_arg, int wY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func371::func;
	return execfunc(this, mX, mY, wX, wY, shiftHeld);
}

namespace _func372
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::ClearDeadCrew", typeid(void (CrewControl::*)(std::vector<CrewMember*> *)), "5589e557565383e4f083ec208b45088b50048b3089d029f0c1f80285c00f84????????31db", argdata, 2, 5, &func);
}

void CrewControl::ClearDeadCrew(std::vector<CrewMember*> *crew)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, std::vector<CrewMember*> *crew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func372::func;
	return execfunc(this, crew);
}

namespace _func373
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::ClearCrewBoxes", typeid(void (CrewControl::*)()), "5589e557565389ce83e4f083ec108b513c8b494089c829d083f8037e??31db908b3c9a85ff", argdata, 1, 5, &func);
}

void CrewControl::ClearCrewBoxes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func373::func;
	return execfunc(this);
}

namespace _func374
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::SelectPotentialCrew", typeid(void (CrewControl::*)(CrewMember *, bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b1f8b570485db74??89ce8b0b", argdata, 3, 5, &func);
}

void CrewControl::SelectPotentialCrew(CrewMember *crew, bool allowTeleportLeaving)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, CrewMember *crew_arg, bool allowTeleportLeaving_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func374::func;
	return execfunc(this, crew, allowTeleportLeaving);
}

namespace _func375
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::KeyDown", typeid(void (CrewControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b07c78520ffffff6c6f636bc78524ffffff646f776ec7851cffffff08000000c68528ffffff008985bcfeffff8d8520ffffff898518ffffff8d8518ffffff890424", argdata, 2, 5, &func);
}

void CrewControl::KeyDown(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func375::func;
	return execfunc(this, key);
}

namespace _func376
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::RButton", typeid(void (CrewControl::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c807930000f84a00000008b39", argdata, 4, 5, &func);
}

void CrewControl::RButton(int mX, int mY, bool shiftHeld)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func376::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func377
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::SelectCrew", typeid(void (CrewControl::*)(bool )), "5589e557565383e4f083ec20807d080075??8b59048b710831c029dec1fe0285f6", argdata, 2, 5, &func);
}

void CrewControl::SelectCrew(bool keep_current)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, bool keep_current_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func377::func;
	return execfunc(this, keep_current);
}

namespace _func378
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewCustomizeBox::CheckContents", typeid(void (CrewCustomizeBox::*)()), "80b9880600000075??80b96e0200000074??c3578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b8984000000", argdata, 1, 5, &func);
}

void CrewCustomizeBox::CheckContents()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewCustomizeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func378::func;
	return execfunc(this);
}

namespace _func379
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewDrone::constructor", typeid(void (CrewDrone::*)(const std::string &, const std::string &, int , const DroneBlueprint *, CrewAnimation *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b70048b088b580c89b574feffff8b70088b4010899d5cfeffff8b5904", argdata, 6, 5, &func);
}

void CrewDrone::constructor(const std::string &type, const std::string &name, int shipId, const DroneBlueprint *blueprint, CrewAnimation *anim)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewDrone *this_arg, const std::string &type_arg, const std::string &name_arg, int shipId_arg, const DroneBlueprint *blueprint_arg, CrewAnimation *anim_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func379::func;
	return execfunc(this, type, name, shipId, blueprint, anim);
}

namespace _func380
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewDrone::OnLoop", typeid(void (CrewDrone::*)()), "578d7c240883e4f0ff77fc5589e557568db15c0700005389cb83ec4c89f1e8????????80bbfc0100000074??80bb7007000000", argdata, 1, 5, &func);
}

void CrewDrone::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func380::func;
	return execfunc(this);
}

namespace _func381
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewDrone::ProvidesVision", typeid(bool (CrewDrone::*)()), "8b410485c074??0fb6813d05000084c074??8b815c0700008d915c0700008b40303d????????75??0fb68170070000c3f3c35589d1", argdata, 1, 1, &func);
}

bool CrewDrone::ProvidesVision()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func381::func;
	return execfunc(this);
}

namespace _func382
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewDrone::SetCurrentShip", typeid(void (CrewDrone::*)(int )), ".578d7c240883e4f0ff77fc5589e55783ec148b07890424e8????????8b7dfc83ec04c98d67f85f", argdata, 2, 5, &func);
}

void CrewDrone::SetCurrentShip(int shipId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewDrone *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func382::func;
	return execfunc(this, shipId);
}

namespace _func383
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewDrone::destructor", typeid(void (CrewDrone::*)()), "558d910809000089e557565383e4f083ec208b8100090000c701????????894c2", argdata, 1, 5, &func);
}

void CrewDrone::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func383::func;
	return execfunc(this);
}

namespace _func384
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::RemoveItem", typeid(void (CrewEquipBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b496885c974??80bb6e0200000075??c70424????????e8????????", argdata, 1, 5, &func);
}

void CrewEquipBox::RemoveItem()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func384::func;
	return execfunc(this);
}

namespace _func385
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::constructor", typeid(void (CrewEquipBox::*)(Point , ShipManager *, int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4d9881ec????????8b77088b07", argdata, 4, 5, &func);
}

void CrewEquipBox::constructor(Point pos, ShipManager *ship, int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, Point pos_arg, ShipManager *ship_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func385::func;
	return execfunc(this, pos, ship, slot);
}

namespace _func386
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::GetConfirmDelete", typeid(bool (CrewEquipBox::*)()), "0fb681d0020000c681d002000000", argdata, 1, 1, &func);
}

bool CrewEquipBox::GetConfirmDelete()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func386::func;
	return execfunc(this);
}

namespace _func387
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::RenderLabels", typeid(void (CrewEquipBox::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b51608b078b770485d20f84????????0fb68b6c02000083f10109c889f138c10f87????????f30f102d????????", argdata, 3, 5, &func);
}

void CrewEquipBox::RenderLabels(bool dragging, bool isNew)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, bool dragging_arg, bool isNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func387::func;
	return execfunc(this, dragging, isNew);
}

namespace _func388
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnRender", typeid(void (CrewEquipBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????83ec6c8b1fe8????????83f8018d968c0000000f9fc00fb6c089d1", argdata, 2, 5, &func);
}

void CrewEquipBox::OnRender(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func388::func;
	return execfunc(this, unk);
}

namespace _func389
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextInput", typeid(void (CrewEquipBox::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e55756538d997002000083ec1c89d98b37e8????????84c074??893424", argdata, 2, 5, &func);
}

void CrewEquipBox::OnTextInput(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func389::func;
	return execfunc(this, key);
}

namespace _func390
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextEvent", typeid(void (CrewEquipBox::*)(CEvent::TextEvent )), ".578d7c240883e4f0ff77fc5589e55756538d997002000083ec1c89d98b37e8????????84c074??893424", argdata, 2, 5, &func);
}

void CrewEquipBox::OnTextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func390::func;
	return execfunc(this, event);
}

namespace _func391
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::MouseClick", typeid(void (CrewEquipBox::*)()), "578d7c240883e4f0ff77fc5589e557565383ec6c8b716085f60f84????????80b96c0200000089cb74??80bbcc0000000074??", argdata, 1, 5, &func);
}

void CrewEquipBox::MouseClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func391::func;
	return execfunc(this);
}

namespace _func392
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::CloseRename", typeid(void (CrewEquipBox::*)()), "80b96e0200000075??c38db6000000005581c1????????c641fe0089e583e4f0", argdata, 1, 5, &func);
}

void CrewEquipBox::CloseRename()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func392::func;
	return execfunc(this);
}

namespace _func393
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnInit", typeid(void (CrewManifest::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078bb9d80000008b91d40000008945cc89f829d083f8037e??31f68b0cb285c974??8b01", argdata, 2, 5, &func);
}

void CrewManifest::OnInit(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func393::func;
	return execfunc(this, ship);
}

namespace _func394
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::OnRender", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b831c02000085c078??0f2805????????c70424????????0f2945c8", argdata, 1, 5, &func);
}

void CrewManifest::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func394::func;
	return execfunc(this);
}

namespace _func395
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::constructor", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d7d948d75d481ec????????e8????????8d4320c703????????89c1898554ffffff", argdata, 1, 5, &func);
}

void CrewManifest::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func395::func;
	return execfunc(this);
}

namespace _func396
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::Update", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e55756538d45cc89ceb9????????83ec3cc745cc00000000c745d000000000890424c744240800000000", argdata, 1, 5, &func);
}

void CrewManifest::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func396::func;
	return execfunc(this);
}

namespace _func397
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnKeyDown", typeid(void (CrewManifest::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??89cf31db", argdata, 2, 5, &func);
}

void CrewManifest::OnKeyDown(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func397::func;
	return execfunc(this, key);
}

namespace _func398
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnKeyUp", typeid(void (CrewManifest::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??", argdata, 2, 5, &func);
}

void CrewManifest::OnKeyUp(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func398::func;
	return execfunc(this, key);
}

namespace _func399
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnTextInput", typeid(void (CrewManifest::*)(SDLKey )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??89cf31db", argdata, 2, 5, &func);
}

void CrewManifest::OnTextInput(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func399::func;
	return execfunc(this, key);
}

namespace _func400
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnTextEvent", typeid(void (CrewManifest::*)(CEvent::TextEvent )), ".578d7c240883e4f0ff77fc5589e557565383ec1c8b91d40000008b81d80000008b3729d0c1f80285c074??89cf31db", argdata, 2, 5, &func);
}

void CrewManifest::OnTextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func400::func;
	return execfunc(this, event);
}

namespace _func401
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::Close", typeid(void (CrewManifest::*)()), "5589e556538b91d40000008b81d800000031db83e4f089ce29d0c1f80285c075??eb??8b96d40000008b86d800000083c30129d0c1f802", argdata, 1, 5, &func);
}

void CrewManifest::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func401::func;
	return execfunc(this);
}

namespace _func402
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::MouseClick", typeid(void (CrewManifest::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b891c0200008b078b570485c978??8d8e2002000089542404890424e8????????83ec08", argdata, 3, 5, &func);
}

void CrewManifest::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func402::func;
	return execfunc(this, mX, mY);
}

namespace _func403
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::MouseMove", typeid(void (CrewManifest::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b308b40048945e48d81e000000089c1", argdata, 3, 5, &func);
}

void CrewManifest::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func403::func;
	return execfunc(this, mX, mY);
}

namespace _func404
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanSabotage", typeid(bool (CrewMember::*)()), ".0fb68198000000", argdata, 1, 1, &func);
}

bool CrewMember::CanSabotage()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func404::func;
	return execfunc(this);
}

namespace _func405
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanRepair", typeid(bool (CrewMember::*)()), "80b9980000000074??31c0c38d7426008b015589e55389cb8b8088000000", argdata, 1, 1, &func);
}

bool CrewMember::CanRepair()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func405::func;
	return execfunc(this);
}

namespace _func406
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanMan", typeid(bool (CrewMember::*)()), "0fb6819800000084c075??f30f1081080700000f2e05????????76??f3c3", argdata, 1, 1, &func);
}

bool CrewMember::CanMan()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func406::func;
	return execfunc(this);
}

namespace _func407
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanHeal", typeid(bool (CrewMember::*)()), "f30f1041280f2e412c7a??75??5589e55389cb83e4f080796c0075??8b8300020000", argdata, 1, 1, &func);
}

bool CrewMember::CanHeal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func407::func;
	return execfunc(this);
}

namespace _func408
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e5575383ec3080b9fc010000008b3f74??8d65f85b5f5d8d67f8", argdata, 2, 5, &func);
}

void CrewMember::OnRender(bool outlineOnly)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func408::func;
	return execfunc(this, outlineOnly);
}

namespace _func409
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetRoomDamage", typeid(Damage (CrewMember::*)()), "89c8c701????????c7410400000000c7410800000000c7410c00000000c7411000000000c7411400000000c7411800000000c7411c00000000c6412000", argdata, 2, 1, &func);
}

Damage CrewMember::GetRoomDamage()
{
	typedef Damage __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func409::func;
	return execfunc(this);
}

namespace _func410
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(void (CrewMember::*)(CrewBlueprint &, int , bool , CrewAnimation *)), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b5808", argdata, 5, 5, &func);
}

void CrewMember::constructor(CrewBlueprint &blueprint, int shipId, bool intruder, CrewAnimation *animation)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewBlueprint &blueprint_arg, int shipId_arg, bool intruder_arg, CrewAnimation *animation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func410::func;
	return execfunc(this, blueprint, shipId, intruder, animation);
}

namespace _func411
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)()), "8b81f00400005589e583e4f083400c018b01ff90cc000000", argdata, 1, 5, &func);
}

void CrewMember::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func411::func;
	return execfunc(this);
}

namespace _func412
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetIntruder", typeid(bool (CrewMember::*)()), ".80b93d050000008b410475??398160010000", argdata, 1, 1, &func);
}

bool CrewMember::GetIntruder()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func412::func;
	return execfunc(this);
}

namespace _func413
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SetOutOfGame", typeid(void (CrewMember::*)()), ".a1????????c681e001000001c681fc01000001c7810807000000000000", argdata, 1, 5, &func);
}

void CrewMember::SetOutOfGame()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func413::func;
	return execfunc(this);
}

namespace _func414
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::PositionShift", typeid(float (CrewMember::*)()), ".55660fefc989e583ec04f30f2a8990000000f30f1015????????f30f104108f30f5cc1", argdata, 1, 1, &func);
}

float CrewMember::PositionShift()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func414::func;
	return execfunc(this);
}

namespace _func415
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf31f683ec1c8b18f30f108108070000f30f11442404891c24e8????????", argdata, 2, 5, &func);
}

void CrewMember::SaveState(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func415::func;
	return execfunc(this, fileHelper);
}

namespace _func416
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CanTeleport", typeid(bool (CrewMember::*)()), ".8b819c000000837838030f84????????55660fefc9", argdata, 1, 1, &func);
}

bool CrewMember::CanTeleport()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func416::func;
	return execfunc(this);
}

namespace _func417
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::destructor", typeid(void (CrewMember::*)()), ".5589e5575653", argdata, 1, 5, &func);
}

void CrewMember::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func417::func;
	return execfunc(this);
}

namespace _func418
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Cleanup", typeid(void (CrewMember::*)()), ".5589e55389cb", argdata, 1, 5, &func);
}

void CrewMember::Cleanup()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func418::func;
	return execfunc(this);
}

namespace _func419
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b30893424e8????????d95de48b45e4893424", argdata, 2, 5, &func);
}

void CrewMember::LoadState(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func419::func;
	return execfunc(this, fileHelper);
}

namespace _func420
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(void (CrewMember::*)(ShipSystem *)), ".578d7c240883e4f0ff77fc", argdata, 2, 5, &func);
}

void CrewMember::SetCurrentSystem(ShipSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, ShipSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func420::func;
	return execfunc(this, sys);
}

namespace _func421
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::IsManningArtillery", typeid(bool (CrewMember::*)()), ".83797c0b0f94c0", argdata, 1, 1, &func);
}

bool CrewMember::IsManningArtillery()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func421::func;
	return execfunc(this);
}

namespace _func422
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::IncreaseSkill", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc55", argdata, 2, 5, &func);
}

void CrewMember::IncreaseSkill(int skillId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func422::func;
	return execfunc(this, skillId);
}

namespace _func423
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc55", argdata, 1, 5, &func);
}

void CrewMember::CheckSkills()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func423::func;
	return execfunc(this);
}

namespace _func424
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MasterSkill", typeid(void (CrewMember::*)(int )), ".8b81140300008b5424048d04d08b5004", argdata, 2, 5, &func);
}

void CrewMember::MasterSkill(int skillId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func424::func;
	return execfunc(this, skillId);
}

namespace _func425
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillFromSystem", typeid(int (*)(int )), ".8b54240483fa0174??83fa0674??", argdata, 1, 2, &func);
}

int CrewMember::GetSkillFromSystem(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func425::func;
	return execfunc(systemId);
}

namespace _func426
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(void (CrewMember::*)(bool )), ".8b4424048881f4060000", argdata, 2, 5, &func);
}

void CrewMember::SetResisted(bool resisted)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool resisted_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func426::func;
	return execfunc(this, resisted);
}

namespace _func427
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(bool (CrewMember::*)()), ".0fb681f4060000c681f406000000", argdata, 1, 1, &func);
}

bool CrewMember::GetResisted()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func427::func;
	return execfunc(this);
}

namespace _func428
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(void (CrewMember::*)(int , int )), ".8b81140300008b5424048b4c2408", argdata, 3, 5, &func);
}

void CrewMember::SetSkillProgress(int skillId, int skillLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg, int skillLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func428::func;
	return execfunc(this, skillId, skillLevel);
}

namespace _func429
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), ".8b542404b8????????83fa0577??8b8114030000", argdata, 2, 1, &func);
}

int CrewMember::GetSkillLevel(int skillId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func429::func;
	return execfunc(this, skillId);
}

namespace _func430
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(std::pair<int, int> (CrewMember::*)(int )), ".558b811403000089e58b55085d8d14d08b02", argdata, 2, 9, &func);
}

std::pair<int, int> CrewMember::GetSkillProgress(int skillId)
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func430::func;
	return execfunc(this, skillId);
}

namespace _func431
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillModifier", typeid(float (CrewMember::*)(int )), ".55b8????????89e55383e4f083ec10", argdata, 2, 1, &func);
}

float CrewMember::GetSkillModifier(int skillId)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func431::func;
	return execfunc(this, skillId);
}

namespace _func432
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::BadAtCombat", typeid(bool (CrewMember::*)()), ".5589e55389cb83e4f083ec108b01", argdata, 1, 1, &func);
}

bool CrewMember::BadAtCombat()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func432::func;
	return execfunc(this);
}

namespace _func433
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), ".8b818800000085c00f88????????578d7c240883e4f0", argdata, 1, 5, &func);
}

void CrewMember::EmptySlot()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func433::func;
	return execfunc(this);
}

namespace _func434
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedsSlot", typeid(bool (CrewMember::*)()), ".0fb681fc01000084c075??83b98c000000ff74??", argdata, 1, 1, &func);
}

bool CrewMember::NeedsSlot()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func434::func;
	return execfunc(this);
}

namespace _func435
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(bool (CrewMember::*)(float )), ".57660fefc98d7c240883e4f0ff77fc5589e557565383ec4cf30f1041280f2ec8f30f10170f83????????f30f2cf0f30f58c2", argdata, 2, 1, &func);
}

bool CrewMember::DirectModifyHealth(float health)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func435::func;
	return execfunc(this, health);
}

namespace _func436
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(void (CrewMember::*)(float )), ".578d7c240883e4f0ff77fc5589e55753", argdata, 2, 5, &func);
}

void CrewMember::ModifyHealth(float health)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func436::func;
	return execfunc(this, health);
}

namespace _func437
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ApplyDamage", typeid(bool (CrewMember::*)(float )), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 1, &func);
}

bool CrewMember::ApplyDamage(float damage)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func437::func;
	return execfunc(this, damage);
}

namespace _func438
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingSystem", typeid(bool (CrewMember::*)()), ".8b516885d274??8b810002000085c0", argdata, 1, 1, &func);
}

bool CrewMember::RepairingSystem()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func438::func;
	return execfunc(this);
}

namespace _func439
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), ".8b416885c074??5589e5538b10", argdata, 1, 1, &func);
}

bool CrewMember::Sabotaging()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func439::func;
	return execfunc(this);
}

namespace _func440
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingFire", typeid(bool (CrewMember::*)()), ".8b516831c085d274??8b9100020000", argdata, 1, 1, &func);
}

bool CrewMember::RepairingFire()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func440::func;
	return execfunc(this);
}

namespace _func441
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(Pointf (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 9, &func);
}

Pointf CrewMember::SelectSabotageTarget()
{
	typedef Pointf __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func441::func;
	return execfunc(this);
}

namespace _func442
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), ".8b81880000008981f80600008b818c0000008981fc0600008b8190000000898100070000", argdata, 1, 5, &func);
}

void CrewMember::SavePosition()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func442::func;
	return execfunc(this);
}

namespace _func443
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), ".c781fc060000ffffffffc781f8060000ffffffff", argdata, 1, 5, &func);
}

void CrewMember::ClearPosition()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func443::func;
	return execfunc(this);
}

namespace _func444
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(Slot (CrewMember::*)()), ".8b54240489c88b8af806000089088b8afc060000894804", argdata, 2, 1, &func);
}

Slot CrewMember::GetSavedPosition()
{
	typedef Slot __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func444::func;
	return execfunc(this);
}

namespace _func445
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(Slot )), ".8b4424048981f80600008b4424088981fc060000", argdata, 2, 5, &func);
}

void CrewMember::SetSavePosition(Slot position)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Slot position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func445::func;
	return execfunc(this, position);
}

namespace _func446
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StopRepairing", typeid(void (CrewMember::*)()), ".8b416885c074??8b015589e5", argdata, 1, 5, &func);
}

void CrewMember::StopRepairing()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func446::func;
	return execfunc(this);
}

namespace _func447
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), ".8b416885c00f95c0", argdata, 1, 1, &func);
}

bool CrewMember::Repairing()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func447::func;
	return execfunc(this);
}

namespace _func448
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozen", typeid(void (CrewMember::*)(bool )), ".8b44240484c074??80b9a00100000074??8881a0010000", argdata, 2, 5, &func);
}

void CrewMember::SetFrozen(bool frozen)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func448::func;
	return execfunc(this, frozen);
}

namespace _func449
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(void (CrewMember::*)(bool )), ".8b4424048881a1010000", argdata, 2, 5, &func);
}

void CrewMember::SetFrozenLocation(bool frozenLocation)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozenLocation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func449::func;
	return execfunc(this, frozenLocation);
}

namespace _func450
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x3ff};
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(CrewTask )), ".8b4424048981a40100008b4424088981a8010000", argdata, 2, 5, &func);
}

void CrewMember::SetTask(CrewTask task)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTask task_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func450::func;
	return execfunc(this, task);
}

namespace _func451
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::FindSlot", typeid(Slot (CrewMember::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589f889e557", argdata, 5, 1, &func);
}

Slot CrewMember::FindSlot(int roomId, int slotId, bool closeEnough)
{
	typedef Slot __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool closeEnough_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func451::func;
	return execfunc(this, roomId, slotId, closeEnough);
}

namespace _func452
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckRoomPath", typeid(bool (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 1, &func);
}

bool CrewMember::CheckRoomPath(int roomId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func452::func;
	return execfunc(this, roomId);
}

namespace _func453
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::SetPosition", typeid(void (CrewMember::*)(Point )), ".57660fefc9660fefc08d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

void CrewMember::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func453::func;
	return execfunc(this, pos);
}

namespace _func454
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(void (CrewMember::*)()), ".8b4178c781ac010000ffffffffc781a401000004000000", argdata, 1, 5, &func);
}

void CrewMember::ClearTask()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func454::func;
	return execfunc(this);
}

namespace _func455
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPath", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

void CrewMember::ClearPath()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func455::func;
	return execfunc(this);
}

namespace _func456
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoom", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

void CrewMember::SetRoom(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func456::func;
	return execfunc(this, roomId);
}

namespace _func457
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::IsBusy", typeid(bool (CrewMember::*)()), ".8b5168b8????????85d274??f3c3", argdata, 1, 1, &func);
}

bool CrewMember::IsBusy()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func457::func;
	return execfunc(this);
}

namespace _func458
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnInit", typeid(bool (CrewMember::*)()), ".c741201e000000c7416400000000b8????????", argdata, 1, 1, &func);
}

bool CrewMember::OnInit()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func458::func;
	return execfunc(this);
}

namespace _func459
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetFinalGoal", typeid(Point (CrewMember::*)()), ".f30f1005????????0f2e41547a??74??8b414c8b5150", argdata, 1, 9, &func);
}

Point CrewMember::GetFinalGoal()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func459::func;
	return execfunc(this);
}

namespace _func460
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNextGoal", typeid(Point (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55753", argdata, 1, 9, &func);
}

Point CrewMember::GetNextGoal()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func460::func;
	return execfunc(this);
}

namespace _func461
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CloseDoorBehind", typeid(void (CrewMember::*)(Door *)), ".8b442404894164", argdata, 2, 5, &func);
}

void CrewMember::CloseDoorBehind(Door *door)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Door *door_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func461::func;
	return execfunc(this, door);
}

namespace _func462
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(float (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 1, &func);
}

float CrewMember::GetMoveSpeed()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func462::func;
	return execfunc(this);
}

namespace _func463
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Restart", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

void CrewMember::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func463::func;
	return execfunc(this);
}

namespace _func464
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), ".f30f10442404f30f1181ec060000", argdata, 2, 5, &func);
}

void CrewMember::SetDamageBoost(float damageBoost)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float damageBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func464::func;
	return execfunc(this, damageBoost);
}

namespace _func465
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetHealthBoost", typeid(void (CrewMember::*)(int )), ".558b81e806000089e5538b550883e4f039d074??", argdata, 2, 5, &func);
}

void CrewMember::SetHealthBoost(int healthBoost)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int healthBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func465::func;
	return execfunc(this, healthBoost);
}

namespace _func466
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void CrewMember::InitializeSkills()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func466::func;
	return execfunc(this);
}

namespace _func467
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCloneReady", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

void CrewMember::SetCloneReady(bool cloneReady)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool cloneReady_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func467::func;
	return execfunc(this, cloneReady);
}

namespace _func468
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::Kill", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

void CrewMember::Kill(bool noClone)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool noClone_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func468::func;
	return execfunc(this, noClone);
}

namespace _func469
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), ".0fb681a00100005589e584c074??660fefc9", argdata, 1, 1, &func);
}

bool CrewMember::NeedFrozenLocation()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func469::func;
	return execfunc(this);
}

namespace _func470
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(void (CrewMember::*)(int )), ".8b4424048b919c000000898160010000", argdata, 2, 5, &func);
}

void CrewMember::SetCurrentShip(int shipId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func470::func;
	return execfunc(this, shipId);
}

namespace _func471
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), ".8b818801000085c00f958199000000", argdata, 1, 5, &func);
}

void CrewMember::CheckFighting()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func471::func;
	return execfunc(this);
}

namespace _func472
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDeathNumber", typeid(void (CrewMember::*)(int )), ".8b4424043b05????????898140050000", argdata, 2, 5, &func);
}

void CrewMember::SetDeathNumber(int deathNum)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int deathNum_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func472::func;
	return execfunc(this, deathNum);
}

namespace _func473
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(void (CrewMember::*)(bool )), ".8b44240488813d050000", argdata, 2, 5, &func);
}

void CrewMember::ForceMindControl(bool force)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func473::func;
	return execfunc(this, force);
}

namespace _func474
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::RenderSkillUpAnimation", typeid(void (CrewMember::*)(Point )), ".578d7c240883e4f0ff77fc5589e557565383ec7c8b17", argdata, 2, 5, &func);
}

void CrewMember::RenderSkillUpAnimation(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func474::func;
	return execfunc(this, pos);
}

namespace _func475
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Clone", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

void CrewMember::Clone()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func475::func;
	return execfunc(this);
}

namespace _func476
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc55", argdata, 1, 5, &func);
}

void CrewMember::UpdateHealth()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func476::func;
	return execfunc(this);
}

namespace _func477
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), ".8b410485c00f85????????660fefc9f30f104108f30f1015????????", argdata, 1, 5, &func);
}

void CrewMember::OnRenderPath()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func477::func;
	return execfunc(this);
}

namespace _func478
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetPath", typeid(bool (CrewMember::*)(Path *)), ".578d7c240883e4f0ff77fc5589e557565389cb", argdata, 2, 1, &func);
}

bool CrewMember::SetPath(Path *path)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Path *path_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func478::func;
	return execfunc(this, path);
}

namespace _func479
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoomPath", typeid(void (CrewMember::*)(int , int )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

void CrewMember::SetRoomPath(int slotId, int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func479::func;
	return execfunc(this, slotId, roomId);
}

namespace _func480
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetLocation", typeid(Point (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec30", argdata, 1, 9, &func);
}

Point CrewMember::GetLocation()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func480::func;
	return execfunc(this);
}

namespace _func481
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtGoal", typeid(bool (CrewMember::*)()), ".f30f104918f30f101d????????f30f10410855f30f5cc1f30f1015????????", argdata, 1, 1, &func);
}

bool CrewMember::AtGoal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func481::func;
	return execfunc(this);
}

namespace _func482
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), ".660fefc9f30f1015????????f30f10410831c055f30f2a899000000089e5", argdata, 1, 1, &func);
}

bool CrewMember::AtFinalGoal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func482::func;
	return execfunc(this);
}

namespace _func483
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderHealth", typeid(void (CrewMember::*)()), ".80b9fc0100000074??f3c3908d7426008b819c000000837838030f84????????57", argdata, 1, 5, &func);
}

void CrewMember::OnRenderHealth()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func483::func;
	return execfunc(this);
}

namespace _func484
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), ".31c080b9fc0100000075??f30f2c4128ba????????85c00f4ec2", argdata, 1, 1, &func);
}

int CrewMember::GetIntegerHealth()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func484::func;
	return execfunc(this);
}

namespace _func485
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetRepairingId", typeid(int (CrewMember::*)()), ".8b496885c974??558b01", argdata, 1, 1, &func);
}

int CrewMember::GetRepairingId()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func485::func;
	return execfunc(this);
}

namespace _func486
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::WithinRect", typeid(bool (CrewMember::*)(int , int , int , int )), ".538b4424108b5c24088b54241485c078??85d278??", argdata, 5, 1, &func);
}

bool CrewMember::WithinRect(int x, int y, int w, int h)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func486::func;
	return execfunc(this, x, y, w, h);
}

namespace _func487
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetLongName", typeid(std::string (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 1, &func);
}

std::string CrewMember::GetLongName()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func487::func;
	return execfunc(this);
}

namespace _func488
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(void (CrewMember::*)(TextString *, bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

void CrewMember::SetName(TextString *name, bool force)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, TextString *name_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func488::func;
	return execfunc(this, name, force);
}

namespace _func489
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetName", typeid(std::string (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10", argdata, 2, 1, &func);
}

std::string CrewMember::GetName()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func489::func;
	return execfunc(this);
}

namespace _func490
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(void (CrewMember::*)(CrewTarget *, bool )), ".5589e55756538b0189cb8b75088b7d0c83e4f08b40643d????????75??", argdata, 3, 5, &func);
}

void CrewMember::SetCurrentTarget(CrewTarget *target, bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTarget *target_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func490::func;
	return execfunc(this, target, unk);
}

namespace _func491
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557565383ec1c", argdata, 1, 5, &func);
}

void CrewMember::CheckForTeleport()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func491::func;
	return execfunc(this);
}

namespace _func492
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(bool (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b496485c974??e8????????f30f1005????????", argdata, 1, 1, &func);
}

bool CrewMember::GetNewGoal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func492::func;
	return execfunc(this);
}

namespace _func493
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 4, 1, &func);
}

bool CrewMember::MoveToRoom(int roomId, int slotId, bool forceMove)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool forceMove_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func493::func;
	return execfunc(this, roomId, slotId, forceMove);
}

namespace _func494
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMindControl", typeid(void (CrewMember::*)(bool )), ".578d7c240883e4f0ff77fc5589e55753", argdata, 2, 5, &func);
}

void CrewMember::SetMindControl(bool controlled)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool controlled_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func494::func;
	return execfunc(this, controlled);
}

namespace _func495
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RestorePosition", typeid(bool (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 1, &func);
}

bool CrewMember::RestorePosition()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func495::func;
	return execfunc(this);
}

namespace _func496
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int )), ".f30f1005????????f30f594114f30f104908660fefd20f28d9f30f2a542404", argdata, 3, 1, &func);
}

bool CrewMember::ContainsPoint(int x, int y)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func496::func;
	return execfunc(this, x, y);
}

namespace _func497
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), ".5589e55389cb83e4f083ec108b11", argdata, 2, 5, &func);
}

void CrewMember::SetMedbay(float health)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func497::func;
	return execfunc(this, health);
}

namespace _func498
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void CrewMember::StartTeleport()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func498::func;
	return execfunc(this);
}

namespace _func499
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55753", argdata, 1, 5, &func);
}

void CrewMember::StartTeleportArrive()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func499::func;
	return execfunc(this);
}

namespace _func500
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(void (CrewMember::*)(Repairable *)), ".57660fefc98d7c240883e4f0ff77fc5589e5575383ec308b3ff30f2a8990000000", argdata, 2, 5, &func);
}

void CrewMember::StartRepair(Repairable *toRepair)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Repairable *toRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func500::func;
	return execfunc(this, toRepair);
}

namespace _func501
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateRepair", typeid(void (CrewMember::*)()), ".57660fefc98d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void CrewMember::UpdateRepair()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func501::func;
	return execfunc(this);
}

namespace _func502
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateMovement", typeid(void (CrewMember::*)()), ".8b819c0000008b403883f8060f84????????660fefc00f2e41280f83????????578d7c2408", argdata, 1, 5, &func);
}

void CrewMember::UpdateMovement()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func502::func;
	return execfunc(this);
}

namespace _func503
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

void CrewMember::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func503::func;
	return execfunc(this);
}

namespace _func504
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(void (CrewMember::*)(bool )), ".5589e556538b750889cb8b899c00000083e4f089f08881c4090000e8????????89f08883100300008d65f85b", argdata, 2, 5, &func);
}

void CrewMember::SetSex(bool male)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func504::func;
	return execfunc(this, male);
}

namespace _func505
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CycleColorLayer", typeid(void (CrewMember::*)(int )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 5, &func);
}

void CrewMember::CycleColorLayer(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func505::func;
	return execfunc(this, unk);
}

namespace _func506
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Functional", typeid(bool (CrewMember::*)()), "8b018b80880000003d????????75??0fb681fc01000083f001c38db6000000005589e583e4f0ffd0c9", argdata, 1, 1, &func);
}

bool CrewMember::Functional()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func506::func;
	return execfunc(this);
}

namespace _func507
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::InsideRoom", typeid(bool (CrewMember::*)(int )), ".8b4424043941780f94c0", argdata, 2, 1, &func);
}

bool CrewMember::InsideRoom(int roomId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func507::func;
	return execfunc(this, roomId);
}

namespace _func508
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetControllable", typeid(bool (CrewMember::*)()), "8b410485c074??31c0c38db6000000008b015589e55389cb8b808800000083e4f0", argdata, 1, 1, &func);
}

bool CrewMember::GetControllable()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func508::func;
	return execfunc(this);
}

namespace _func509
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetUniqueRepairing", typeid(std::string (CrewMember::*)()), ".8d510889c8c7410872657061c7410406000000c6410e008911ba????????6689510c", argdata, 2, 1, &func);
}

std::string CrewMember::GetUniqueRepairing()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func509::func;
	return execfunc(this);
}

namespace _func510
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetTooltip", typeid(std::string (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????8b1f898d18ffffffc70424????????e8????????83ec0480bbe4020000008d45d0", argdata, 2, 1, &func);
}

std::string CrewMember::GetTooltip()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func510::func;
	return execfunc(this);
}

namespace _func511
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillTooltip", typeid(std::string (*)(int , int , std::pair<int, int> , bool )), ".8d4c240483e4f0ff71fc5589e55756535181ec280100008b790c8b018b59048b710889bde0feffff", argdata, 5, 2, &func);
}

std::string CrewMember::GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int skillId_arg, int skillLevel_arg, std::pair<int, int> progress_arg, bool infoScreen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func511::func;
	return execfunc(skillId, skillLevel, progress, infoScreen);
}

namespace _func512
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CountForVictory", typeid(bool (CrewMember::*)()), "8b015589e55389cb8b808800000083e4f03d????????75??0fb681fc01000084c075??8b939c000000", argdata, 1, 1, &func);
}

bool CrewMember::CountForVictory()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func512::func;
	return execfunc(this);
}

namespace _func513
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::destructor", typeid(void (CrewMemberFactory::*)()), "5589e557565389ce83e4f083ec108b79108b510c89f829d0c1f80285c074??", argdata, 1, 5, &func);
}

void CrewMemberFactory::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func513::func;
	return execfunc(this);
}

namespace _func514
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::Restart", typeid(void (CrewMemberFactory::*)()), ".5589e557565389cb83e4f0", argdata, 1, 5, &func);
}

void CrewMemberFactory::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func514::func;
	return execfunc(this);
}

namespace _func515
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CountCloneReadyCrew", typeid(int (CrewMemberFactory::*)(bool )), ".5589e557565383e4f0", argdata, 2, 1, &func);
}

int CrewMemberFactory::CountCloneReadyCrew(bool player)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func515::func;
	return execfunc(this, player);
}

namespace _func516
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetPlayerCrewCount", typeid(int (CrewMemberFactory::*)()), ".8b01", argdata, 1, 1, &func);
}

int CrewMemberFactory::GetPlayerCrewCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func516::func;
	return execfunc(this);
}

namespace _func517
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCloneCount", typeid(int (CrewMemberFactory::*)()), ".8b4108", argdata, 1, 1, &func);
}

int CrewMemberFactory::GetEnemyCloneCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func517::func;
	return execfunc(this);
}

namespace _func518
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewCount", typeid(int (CrewMemberFactory::*)(bool )), ".807c2404008b41040f4401", argdata, 2, 1, &func);
}

int CrewMemberFactory::GetCrewCount(bool enemy)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func518::func;
	return execfunc(this, enemy);
}

namespace _func519
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCrewCount", typeid(int (CrewMemberFactory::*)()), ".8b4104", argdata, 1, 1, &func);
}

int CrewMemberFactory::GetEnemyCrewCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func519::func;
	return execfunc(this);
}

namespace _func520
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e5", argdata, 1, 2, &func);
}

bool CrewMemberFactory::IsRace(const std::string &species)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &species_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func520::func;
	return execfunc(species);
}

namespace _func521
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetRandomFriendlyName", typeid(std::pair<std::string, bool> (CrewMemberFactory::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 9, &func);
}

std::pair<std::string, bool> CrewMemberFactory::GetRandomFriendlyName(const std::string &race)
{
	typedef std::pair<std::string, bool> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, const std::string &race_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func521::func;
	return execfunc(this, race);
}

namespace _func522
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewNames", typeid(std::vector<std::string> (CrewMemberFactory::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 1, &func);
}

std::vector<std::string> CrewMemberFactory::GetCrewNames()
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func522::func;
	return execfunc(this);
}

namespace _func523
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateRepairDrone", typeid(RepairDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 1, &func);
}

RepairDrone *CrewMemberFactory::CreateRepairDrone(int shipId, const DroneBlueprint *bp)
{
	typedef RepairDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func523::func;
	return execfunc(this, shipId, bp);
}

namespace _func524
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewPortraitList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int )), ".578d7c240883e4f0ff77fc5589f889e55756", argdata, 3, 5, &func);
}

void CrewMemberFactory::GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int teamId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func524::func;
	return execfunc(this, vec, teamId);
}

namespace _func525
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCloneReadyList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, bool )), ".578d7c240883e4f0ff77fc5589e557565383ec4c", argdata, 3, 5, &func);
}

void CrewMemberFactory::GetCloneReadyList(std::vector<CrewMember*> &vec, bool player)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> &vec_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func525::func;
	return execfunc(this, vec, player);
}

namespace _func526
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBattleDrone", typeid(BattleDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589f889e5", argdata, 3, 1, &func);
}

BattleDrone *CrewMemberFactory::CreateBattleDrone(int shipId, const DroneBlueprint *bp)
{
	typedef BattleDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func526::func;
	return execfunc(this, shipId, bp);
}

namespace _func527
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 5, &func);
}

void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int unk_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func527::func;
	return execfunc(this, vec, unk, unk2);
}

namespace _func528
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBoarderDrone", typeid(BoarderDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), ".578d7c240883e4f0ff77fc5589e5", argdata, 3, 1, &func);
}

BoarderDrone *CrewMemberFactory::CreateBoarderDrone(int shipId, const DroneBlueprint *bp)
{
	typedef BoarderDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func528::func;
	return execfunc(this, shipId, bp);
}

namespace _func529
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::OnLoop", typeid(void (CrewMemberFactory::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

void CrewMemberFactory::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func529::func;
	return execfunc(this);
}

namespace _func530
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMemberFactory::RemoveExcessCrew", typeid(void (CrewMemberFactory::*)()), ".5589e557565331db", argdata, 1, 5, &func);
}

void CrewMemberFactory::RemoveExcessCrew()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func530::func;
	return execfunc(this);
}

namespace _func531
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateCrewMember", typeid(CrewMember *(CrewMemberFactory::*)(CrewBlueprint *, int , bool )), ".578d7c240883e4f0ff77fc5589e557", argdata, 4, 1, &func);
}

CrewMember *CrewMemberFactory::CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, CrewBlueprint *bp_arg, int shipId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func531::func;
	return execfunc(this, bp, shipId, intruder);
}

CrewMemberFactory *Global_CrewMemberFactory_Factory;

namespace _var532
{
    static VariableDefinition varObj("Global_CrewMemberFactory_Factory", "!b9(???????\?)e8????????29c6", &Global_CrewMemberFactory_Factory);
}

namespace _func533
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewStoreBox::CanHold", typeid(bool (CrewStoreBox::*)()), "8b893801000085c974165589e583e4f0", argdata, 1, 1, &func);
}

bool CrewStoreBox::CanHold()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func533::func;
	return execfunc(this);
}

namespace _func534
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewStoreBox::constructor", typeid(void (CrewStoreBox::*)(ShipManager *, int , const std::string &)), ".578d7c240883e4f0ff77fc5589e557565389cb8d8dc0feffff81ec????????8b47048b378b7f08c744240400000000c785a8feffff16000000898554feffff8d85c8feffff8985c0feffff", argdata, 4, 5, &func);
}

void CrewStoreBox::constructor(ShipManager *ship, int worldLevel, const std::string &type)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg, ShipManager *ship_arg, int worldLevel_arg, const std::string &type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func534::func;
	return execfunc(this, ship, worldLevel, type);
}

namespace _func535
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewStoreBox::Purchase", typeid(void (CrewStoreBox::*)()), ".578d7c240883e4f0ff77fc5589e557565389cf81ec????????898dacfeffffe8????????b9????????e8????????8bb73c020000", argdata, 1, 5, &func);
}

void CrewStoreBox::Purchase()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func535::func;
	return execfunc(this);
}

namespace _func536
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewStoreBox::MouseMove", typeid(void (CrewStoreBox::*)(int , int )), ".578d7c240883e4f0ff77fc5589e5575389cb83c12483ec408b078b5704c74424080000000089542404890424e8????????83ec0c807b6500", argdata, 3, 5, &func);
}

void CrewStoreBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func536::func;
	return execfunc(this, mX, mY);
}

namespace _func537
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("DamageMessage::constructor", typeid(void (DamageMessage::*)(float , Pointf , DamageMessage::MessageType )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b4f0c8b47048b5708f30f1007c703????????f30f114304c643080085c9", argdata, 4, 5, &func);
}

void DamageMessage::constructor(float length, Pointf pos, DamageMessage::MessageType type)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DamageMessage *this_arg, float length_arg, Pointf pos_arg, DamageMessage::MessageType type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func537::func;
	return execfunc(this, length, pos, type);
}

namespace _func538
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("DamageMessage::constructor2", typeid(void (DamageMessage::*)(float , int , Pointf , bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec9c0200008b4f108b47088b570cf30f10078b5f04c706????????f30f11460484c9", argdata, 5, 5, &func);
}

void DamageMessage::constructor2(float length, int amount, Pointf pos, bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DamageMessage *this_arg, float length_arg, int amount_arg, Pointf pos_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func538::func;
	return execfunc(this, length, amount, pos, unk);
}

namespace _func539
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DebugHelper::CrashCatcher", typeid(int (*)(void *)), "8d4c240483e4f0ff71fc5589e55756535181ec????????8b018d8d30f8ffffc785acf2ffff00000000c685b0f2ffff00898590f2ffff8d85b0f2ffff8985a8f2ffffe8????????", argdata, 1, 0, &func);
}

int DebugHelper::CrashCatcher(void *exception_pointers)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(void *exception_pointers_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func539::func;
	return execfunc(exception_pointers);
}

namespace _func540
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::ValidTargetObject", typeid(bool (DefenseDrone::*)(Targetable *)), "5589e55756538b5d0883e4f085db74??8b430483f80274??", argdata, 2, 1, &func);
}

bool DefenseDrone::ValidTargetObject(Targetable *target)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func540::func;
	return execfunc(this, target);
}

namespace _func541
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::SetWeaponTarget", typeid(void (DefenseDrone::*)(Targetable *)), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b018b1f8b80a0000000", argdata, 2, 5, &func);
}

void DefenseDrone::SetWeaponTarget(Targetable *target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func541::func;
	return execfunc(this, target);
}

namespace _func542
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DefenseDrone::PickTarget", typeid(void (DefenseDrone::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b955020000000f84????????0fb6710c", argdata, 1, 5, &func);
}

void DefenseDrone::PickTarget()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func542::func;
	return execfunc(this);
}

namespace _func543
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::GetTooltip", typeid(std::string (DefenseDrone::*)()), "578d7c240883e4f0ff77fc5589f889e55756538d75a889cfbb0800000083ec7c8b108975a0c745a864656665c745ac6e73655f", argdata, 2, 1, &func);
}

std::string DefenseDrone::GetTooltip()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func543::func;
	return execfunc(this);
}

namespace _func544
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DefenseDrone::OnLoop", typeid(void (DefenseDrone::*)()), "578d????0883e4f0ff????5589e557565389cb83ec4ce8????????660fefd2", argdata, 1, 5, &func);
}

void DefenseDrone::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func544::func;
	return execfunc(this);
}

namespace _func545
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Description::constructor", typeid(void (Description::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c70424????????e8????????8d4b1c83ec04c6431801c70424????????e8????????8d4b3883ec04c6433401c70424????????e8????????8d4b68", argdata, 1, 5, &func);
}

void Description::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Description *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func545::func;
	return execfunc(this);
}

namespace _func546
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Description::copy_assign_1", typeid(Description &(Description::*)(Description &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f891c24e8????????0fb643188d4e1c83ec048846188d431c890424e8????????0fb643348d4e3883ec04", argdata, 2, 1, &func);
}

Description &Description::copy_assign_1(Description &other)
{
	typedef Description &__attribute__((thiscall)) (*custom_arg_funcptr_t)(Description *this_arg, Description &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func546::func;
	return execfunc(this, other);
}

namespace _func547
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Description::copy_assign_2", typeid(Description &(Description::*)(const Description &)), ".578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f891c24e8????????0fb643188d4e1c83ec048846188d431c890424e8????????0fb643348d4e3883ec04", argdata, 2, 1, &func);
}

Description &Description::copy_assign_2(const Description &other)
{
	typedef Description &__attribute__((thiscall)) (*custom_arg_funcptr_t)(Description *this_arg, const Description &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func547::func;
	return execfunc(this, other);
}

namespace _func548
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Description::destructor", typeid(void (Description::*)()), "558d918c00000089e55389cb83e4f083ec108b818400000039d074??890424e8????????8b43688d537039d074??890424e8????????8b43388d534039d0", argdata, 1, 5, &func);
}

void Description::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Description *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func548::func;
	return execfunc(this);
}

namespace _func549
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80791800c641200075??", argdata, 1, 5, &func);
}

void Door::FakeClose()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func549::func;
	return execfunc(this);
}

namespace _func550
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Door::IsSealed", typeid(bool (Door::*)(int )), "8b913c0200008b410485d27e??85c00f94c00fb6c08b511c85d274??80791800", argdata, 2, 1, &func);
}

bool Door::IsSealed(int shipId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func550::func;
	return execfunc(this, shipId);
}

namespace _func551
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::FakeOpen", typeid(void (Door::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c83b9b400000004", argdata, 1, 5, &func);
}

void Door::FakeOpen()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func551::func;
	return execfunc(this);
}

namespace _func552
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::OnLoop", typeid(void (Door::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b813c02000085c0", argdata, 1, 5, &func);
}

void Door::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func552::func;
	return execfunc(this);
}

namespace _func553
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::GetPosition", typeid(Point (Door::*)()), "578d7c240883e4f0ff77fc5589e55783ec248b8144020000894424048b81400200008d4df0890424e8????????8b45f483ec088d4df083c008894424048b45f0890424", argdata, 1, 9, &func);
}

Point Door::GetPosition()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func553::func;
	return execfunc(this);
}

namespace _func554
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Door::ApplyDamage", typeid(bool (Door::*)(float )), ".80b9e801000000740731c0", argdata, 2, 1, &func);
}

bool Door::ApplyDamage(float amount)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func554::func;
	return execfunc(this, amount);
}

namespace _func555
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DoorBox::constructor", typeid(void (DoorBox::*)(Point , ShipSystem *, ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b57048b078b4f088b770c8d7dd0c744240c0100000089542404890424894c2408", argdata, 4, 5, &func);
}

void DoorBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DoorBox *this_arg, Point pos_arg, ShipSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func555::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func556
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DroneBlueprint::RenderIcon", typeid(void (DroneBlueprint::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b83b8000000", argdata, 2, 5, &func);
}

void DroneBlueprint::RenderIcon(float scale)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneBlueprint *this_arg, float scale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func556::func;
	return execfunc(this, scale);
}

namespace _func557
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DroneControl::HolderLabel", typeid(TextString (DroneControl::*)()), "8d510883ec2089c8c7410864726f6ec7410c65735f6c8911c741106162656cc741040c000000c6411400c641180083c420", argdata, 2, 1, &func);
}

TextString DroneControl::HolderLabel()
{
	typedef TextString __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func557::func;
	return execfunc(this);
}

namespace _func558
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DroneControl::ArmamentHotkey", typeid(SDLKey (DroneControl::*)(unsigned int )), ".578d7c240883e4f0ff77fc5589e55756538d8d60ffffff81ec4c0100008b1f", argdata, 2, 1, &func);
}

SDLKey DroneControl::ArmamentHotkey(unsigned int i)
{
	typedef SDLKey __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func558::func;
	return execfunc(this, i);
}

namespace _func559
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DroneControl::OnLoop", typeid(void (DroneControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b490cc7042404000000", argdata, 1, 5, &func);
}

void DroneControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func559::func;
	return execfunc(this);
}

namespace _func560
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneStoreBox::constructor", typeid(void (DroneStoreBox::*)(ShipManager *, Equipment *, const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589f889e557565389cb8d4dd083ec4c8b70088d45d88b178b7f04", argdata, 4, 5, &func);
}

void DroneStoreBox::constructor(ShipManager *ship, Equipment *equip, const DroneBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneStoreBox *this_arg, ShipManager *ship_arg, Equipment *equip_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func560::func;
	return execfunc(this, ship, equip, bp);
}

namespace _func561
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::RemoveDrone", typeid(void (DroneSystem::*)(int )), "5731c08d7c240883e4f0ff77fc5589e557565383ec4c8b1f85db0f88????????89ce", argdata, 2, 5, &func);
}

void DroneSystem::RemoveDrone(int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneSystem *this_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func561::func;
	return execfunc(this, slot);
}

namespace _func562
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DroneSystem::UpdateBonusPower", typeid(void (DroneSystem::*)()), "578d7c240883e4f0ff77fc5589e557565383ec2c8b81700100008b91c0010000c745e4000000008945dc8b81c401000029d0c1f802", argdata, 1, 5, &func);
}

void DroneSystem::UpdateBonusPower()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func562::func;
	return execfunc(this);
}

namespace _func563
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::SetBonusPower", typeid(void (DroneSystem::*)(int , int )), ".5589e556538b750889cb83e4f0e8????????39f089d90f4fc6898370010000", argdata, 3, 5, &func);
}

void DroneSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func563::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func564
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DroneSystem::OnLoop", typeid(void (DroneSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec5ce8????????89f9e8????????8bb7c00100008b87c4010000", argdata, 1, 5, &func);
}

void DroneSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func564::func;
	return execfunc(this);
}

namespace _func565
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::DePowerDrone", typeid(bool (DroneSystem::*)(Drone *, bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c807f04008b37", argdata, 3, 1, &func);
}

bool DroneSystem::DePowerDrone(Drone *drone, bool unk)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneSystem *this_arg, Drone *drone_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func565::func;
	return execfunc(this, drone, unk);
}

namespace _func566
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DroneSystem::Jump", typeid(void (DroneSystem::*)()), "8b91c00100008b81c401000029d0c1f80285c00f84????????578d7c240883e4f0ff77fc5589e557565389cf", argdata, 1, 5, &func);
}

void DroneSystem::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func566::func;
	return execfunc(this);
}

namespace _func567
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneSystem::StringToDrone", typeid(int (*)(std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c0750a8d65f8595b5d8d61fcc3c70424????????89d9e8????????89c283ec04b80100000085d274da", argdata, 1, 2, &func);
}

int DroneSystem::StringToDrone(std::string &name)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func567::func;
	return execfunc(name);
}

namespace _func568
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b43148b7c830c89f8", argdata, 1, 5, &func);
}

void DropBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func568::func;
	return execfunc(this);
}

namespace _func569
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DropBox::GetHeight", typeid(int (DropBox::*)()), "8b510c89d085c074??8b42080381ac0000000381a8000000c38db42600000000b8????????0381ac000000", argdata, 1, 1, &func);
}

int DropBox::GetHeight()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func569::func;
	return execfunc(this);
}

namespace _func570
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EnergyAlien::OnLoop", typeid(void (EnergyAlien::*)()), "5589e55389cb83e4f0e8????????8b839c0000008378380374??80bbfc0100000075??c6835907000000c6835a07000000", argdata, 1, 5, &func);
}

void EnergyAlien::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EnergyAlien *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func570::func;
	return execfunc(this);
}

namespace _func571
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EnergyAlien::GetRoomDamage", typeid(Damage (EnergyAlien::*)()), "8b54240489c880ba590700000074??80ba5a0700000074??c700????????c7400400000000c7400800000000c7400c00000000c7401000000000c7401400000000c7401800000000c7401c00000000c6402000c74024ffffffffc74028ffffffffc6402c00c6402d00", argdata, 2, 1, &func);
}

Damage EnergyAlien::GetRoomDamage()
{
	typedef Damage __attribute__((thiscall)) (*custom_arg_funcptr_t)(EnergyAlien *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func571::func;
	return execfunc(this);
}

namespace _func572
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Equipment::OnInit", typeid(void (Equipment::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078bb948020000", argdata, 2, 5, &func);
}

void Equipment::OnInit(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func572::func;
	return execfunc(this, ship);
}

namespace _func573
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::OnLoop", typeid(void (Equipment::*)()), "8b81400200002b813c020000c1f80285c00f84????????578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

void Equipment::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func573::func;
	return execfunc(this);
}

namespace _func574
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseClick", typeid(void (Equipment::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570489042489542404e8????????8b835c02000083ec0883f8ff74??8b933c0200008b0c82", argdata, 3, 5, &func);
}

void Equipment::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func574::func;
	return execfunc(this, mX, mY);
}

namespace _func575
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseUp", typeid(void (Equipment::*)(int , int )), "80b968020000000f84????????578d7c240883e4f0ff77fc5589e557565389cb83ec4c80b934020000000f85????????8b815c02000083f8ff0f84????????8b916002000039d0", argdata, 3, 5, &func);
}

void Equipment::MouseUp(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func575::func;
	return execfunc(this, mX, mY);
}

namespace _func576
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddWeapon", typeid(void (Equipment::*)(WeaponBlueprint *, bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b47088b378b893802000084c089c7", argdata, 4, 5, &func);
}

void Equipment::AddWeapon(WeaponBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, WeaponBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func576::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func577
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddDrone", typeid(void (Equipment::*)(DroneBlueprint *, bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c807f08008b378b8938020000", argdata, 4, 5, &func);
}

void Equipment::AddDrone(DroneBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, DroneBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func577::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func578
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddAugment", typeid(void (Equipment::*)(AugmentBlueprint *, bool , bool )), "578d7c240883e4f0ff77fc5589e55756538d45d889cb83ec4c8b3f8945d08b57048b770889d001f0", argdata, 4, 5, &func);
}

void Equipment::AddAugment(AugmentBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, AugmentBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func578::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func579
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddToCargo", typeid(void (Equipment::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459089cb81ec8c0000008b378945888b168b7e0489d001f8", argdata, 2, 5, &func);
}

void Equipment::AddToCargo(const std::string &name)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func579::func;
	return execfunc(this, name);
}

namespace _func580
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Equipment::GetCargoHold", typeid(std::vector<std::string> (Equipment::*)()), "578d7c240883e4f0ff77fc5589e557565383ec3c8b1fc70100000000c7410400000000c7410800000000894dd08b83e40300008b933c02000089c68945d48b834002000029d0c1f80239c6", argdata, 2, 1, &func);
}

std::vector<std::string> Equipment::GetCargoHold()
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func580::func;
	return execfunc(this);
}

namespace _func581
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::Open", typeid(void (Equipment::*)()), "5589e5565389ce83e4f0e8????????8d8e8c020000c78660020000ffffffffc7865c020000ffffffffc6866802000000", argdata, 1, 5, &func);
}

void Equipment::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func581::func;
	return execfunc(this);
}

namespace _func582
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::Close", typeid(void (Equipment::*)()), ".5589e583e4f0e8????????c9c3", argdata, 1, 5, &func);
}

void Equipment::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func582::func;
	return execfunc(this);
}

namespace _func583
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::constructor", typeid(void (EquipmentBox::*)(Point , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b35????????8b47048b178b4f088d7dd8c703????????c7431c000000008973088b35????????89434c", argdata, 3, 5, &func);
}

void EquipmentBox::constructor(Point pos, int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Point pos_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func583::func;
	return execfunc(this, pos, slot);
}

namespace _func584
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::GetBlueprint", typeid(Blueprint *(EquipmentBox::*)()), "8b416485c074??8b401cc3908d7426008b416085c075??8b416885c074??", argdata, 1, 1, &func);
}

Blueprint *EquipmentBox::GetBlueprint()
{
	typedef Blueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func584::func;
	return execfunc(this);
}

namespace _func585
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::SetBlueprint", typeid(void (EquipmentBox::*)(InfoBox *, bool )), "5731c08d7c240883e4f0ff77fc5589e557565389cb83ec1c80b98100000000", argdata, 3, 5, &func);
}

void EquipmentBox::SetBlueprint(InfoBox *infoBox, bool detailedBox)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, InfoBox *infoBox_arg, bool detailedBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func585::func;
	return execfunc(this, infoBox, detailedBox);
}

namespace _func586
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::destructor", typeid(void (EquipmentBox::*)()), "5589e55389cb83e4f083ec108b4130c701????????890424e8????????8b4334890424", argdata, 1, 5, &func);
}

void EquipmentBox::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func586::func;
	return execfunc(this);
}

namespace _func587
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldWeapon", typeid(bool (EquipmentBox::*)()), ".8b416085c074??85c00f95c0", argdata, 1, 1, &func);
}

bool EquipmentBox::CanHoldWeapon()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func587::func;
	return execfunc(this);
}

namespace _func588
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldDrone", typeid(bool (EquipmentBox::*)()), ".8b416085c08b416474??85c0", argdata, 1, 1, &func);
}

bool EquipmentBox::CanHoldDrone()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func588::func;
	return execfunc(this);
}

namespace _func589
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::GetType", typeid(int (EquipmentBox::*)()), ".8b51608b44240485d274??3c01", argdata, 1, 1, &func);
}

int EquipmentBox::GetType()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func589::func;
	return execfunc(this);
}

namespace _func590
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::OnRender", typeid(void (EquipmentBox::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b37e8????????660fefc0c74424080000000089f7", argdata, 2, 5, &func);
}

void EquipmentBox::OnRender(bool isEmpty)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool isEmpty_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func590::func;
	return execfunc(this, isEmpty);
}

namespace _func591
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::UpdateBoxImage", typeid(void (EquipmentBox::*)(bool )), ".578d7c240883e4f0ff77fc5589e55756538db560ffffff89cb81ec????????8b07", argdata, 2, 5, &func);
}

void EquipmentBox::UpdateBoxImage(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func591::func;
	return execfunc(this, unk);
}

namespace _func592
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::RenderLabels", typeid(void (EquipmentBox::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b4160", argdata, 2, 5, &func);
}

void EquipmentBox::RenderLabels(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func592::func;
	return execfunc(this, unk);
}

namespace _func593
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::MouseMove", typeid(void (EquipmentBox::*)(int , int )), "538b415031db8b54240839c27e??03415839c27d??8b41543944240c7e??", argdata, 3, 5, &func);
}

void EquipmentBox::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func593::func;
	return execfunc(this, x, y);
}

namespace _func594
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("EquipmentBox::AddItem", typeid(void (EquipmentBox::*)(EquipmentBoxItem )), ".8b4424048941608b4424088941648b44240c8941688b442410", argdata, 2, 5, &func);
}

void EquipmentBox::AddItem(EquipmentBoxItem item)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, EquipmentBoxItem item_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func594::func;
	return execfunc(this, item);
}

namespace _func595
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::Restart", typeid(void (EquipmentBox::*)()), ".660fefc05589e50f1141605d", argdata, 1, 5, &func);
}

void EquipmentBox::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func595::func;
	return execfunc(this);
}

namespace _func596
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("EquipmentBox::SetPosition", typeid(void (EquipmentBox::*)(Point )), "5589e58b55088b450c5d89514889414c895150894154", argdata, 2, 5, &func);
}

void EquipmentBox::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func596::func;
	return execfunc(this, pos);
}

namespace _func597
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EquipmentBox::GetItemValue", typeid(int (EquipmentBox::*)()), "8b416085c074??8b401c8b4070c366908b416485c075??8b416c85c074??8b500885d2", argdata, 1, 1, &func);
}

int EquipmentBox::GetItemValue()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func597::func;
	return execfunc(this);
}

namespace _func598
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetBaseEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b4704894dc48b1f8945bc8b47088945c08b470c83f8ff74??803d??????????8904240f85????????e8????????8b7dc48d4f60c6876c01000001c6876d01000000891c24", argdata, 5, 1, &func);
}

LocationEvent *EventGenerator::GetBaseEvent(const std::string &name, int worldLevel, bool ignoreUnique, int seed)
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, bool ignoreUnique_arg, int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func598::func;
	return execfunc(this, name, worldLevel, ignoreUnique, seed);
}

namespace _func599
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::CreateEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b5f048b37898dc4fcffff899dbcfcffff8b5f088d7944899dacfcffff89342489f9e8????????83ec04", argdata, 4, 1, &func);
}

LocationEvent *EventGenerator::CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique)
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, bool ignoreUnique_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func599::func;
	return execfunc(this, name, worldLevel, ignoreUnique);
}

namespace _func600
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetSpecificSector", typeid(SectorDescription (EventGenerator::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b7f04c744240807690fc789c389851cffffff83c00c", argdata, 3, 1, &func);
}

SectorDescription EventGenerator::GetSpecificSector(const std::string &name)
{
	typedef SectorDescription __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func600::func;
	return execfunc(this, name);
}

namespace _func601
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetImageFromList", typeid(std::string (EventGenerator::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1f8b7f0481c3????????893c2489d9", argdata, 3, 1, &func);
}

std::string EventGenerator::GetImageFromList(const std::string &listName)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func601::func;
	return execfunc(this, listName);
}

namespace _func602
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetSectorDescription", typeid(SectorDescription (EventGenerator::*)(const std::string &, int )), "5789c883c0488d7c240883e4f0ff77fc5589e557565389ce81ec8c0000008b57088b1f894140894d9cc70100000000c74104000000008955a089ca", argdata, 4, 1, &func);
}

SectorDescription EventGenerator::GetSectorDescription(const std::string &type, int level)
{
	typedef SectorDescription __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &type_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func602::func;
	return execfunc(this, type, level);
}

namespace _func603
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetShipEvent", typeid(ShipEvent (EventGenerator::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f8b7f04c744240807690fc7894dc08d83ec000000", argdata, 3, 1, &func);
}

ShipEvent EventGenerator::GetShipEvent(const std::string &event)
{
	typedef ShipEvent __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func603::func;
	return execfunc(this, event);
}

EventGenerator *Global_EventGenerator_Generator;

namespace _var604
{
    static VariableDefinition varObj("Global_EventGenerator_Generator", "!8b8318120000c744240800000000b9(???????\?)8944240c8b8334080000", &Global_EventGenerator_Generator);
}

namespace _func605
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), "538b54240885d278??8b590c8b411029d8c1f80239c27d??830493015b", argdata, 2, 5, &func);
}

void EventSystem::AddEvent(int id)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func605::func;
	return execfunc(this, id);
}

namespace _func606
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EventSystem::PollEvent", typeid(bool (EventSystem::*)(int )), "56538b5c240c85db78??8b318b510431c029f2c1fa0239d37d??8b049e5b", argdata, 2, 1, &func);
}

bool EventSystem::PollEvent(int id)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func606::func;
	return execfunc(this, id);
}

EventSystem *Global_EventSystem_EventManager;

namespace _var607
{
    static VariableDefinition varObj("Global_EventSystem_EventManager", "!c704240c000000b9(???????\?)e8????????31c0", &Global_EventSystem_EventManager);
}

namespace _func608
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8d4da083ec7c8b47088b7704c70424????????894594e8????????", argdata, 4, 1, &func);
}

RandomAmount EventsParser::PullMinMax(rapidxml::xml_node<char> *node, const std::string &name)
{
	typedef RandomAmount __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func608::func;
	return execfunc(this, node, name);
}

namespace _func609
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(std::string (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b07898d2cfeffff8b5f08898528feffff8b4704c70424????????89c1898524feffffe8????????83ec0485c074??", argdata, 4, 1, &func);
}

std::string EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &eventName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func609::func;
	return execfunc(this, node, eventName);
}

namespace _func610
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessShipEvent", typeid(ShipTemplate (EventsParser::*)(rapidxml::xml_node<char> *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b7704c70424????????89cf898d50fbffff898540fbffffe8????????8d8dbcfbffff83ec04c6471800", argdata, 3, 1, &func);
}

ShipTemplate EventsParser::ProcessShipEvent(rapidxml::xml_node<char> *node)
{
	typedef ShipTemplate __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func610::func;
	return execfunc(this, node);
}

namespace _func611
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessModifyItem", typeid(ResourcesTemplate (EventsParser::*)(ResourcesTemplate &, rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589f889e55756538d55d889cf83ec6c8b308b58048955d08975a48b70088b400c", argdata, 5, 1, &func);
}

ResourcesTemplate EventsParser::ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &unk)
{
	typedef ResourcesTemplate __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, ResourcesTemplate &resources_arg, rapidxml::xml_node<char> *node_arg, const std::string &unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func611::func;
	return execfunc(this, resources, node, unk);
}

namespace _func612
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EventsParser::AddAllEvents", typeid(void (EventsParser::*)()), "578d7c240883e4f0ff77fc5589e55756538d75d08d7dd883ec5c894db4b9????????", argdata, 1, 5, &func);
}

void EventsParser::AddAllEvents()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func612::func;
	return execfunc(this);
}

namespace _func613
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::AddEvents", typeid(void (EventsParser::*)(EventGenerator &, char *, const std::string &)), "57b8????????8d7c240883e4f0ff77fc5589e5575653e8????????29c48b77048b4708898d80fffeff8b1f85f6898578fffeff0f84????????", argdata, 4, 5, &func);
}

void EventsParser::AddEvents(EventGenerator &generator, char *file, const std::string &fileName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, EventGenerator &generator_arg, char *file_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func613::func;
	return execfunc(this, generator, file, fileName);
}

namespace _func614
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEventList", typeid(std::vector<std::string> (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "5789c88d7c240883e4f0ff77fc5589e557565383ec5c8b1f894db08b4f04c700????????c7400400000000c7400800000000", argdata, 4, 1, &func);
}

std::vector<std::string> EventsParser::ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName)
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func614::func;
	return execfunc(this, node, listName);
}

namespace _func615
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessChoice", typeid(void (EventsParser::*)(EventTemplate *, rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d9d68ffffff", argdata, 4, 5, &func);
}

void EventsParser::ProcessChoice(EventTemplate *event, rapidxml::xml_node<char> *node, const std::string &eventName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, EventTemplate *event_arg, rapidxml::xml_node<char> *node_arg, const std::string &eventName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func615::func;
	return execfunc(this, event, node, eventName);
}

namespace _func616
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessBaseNode", typeid(void (EventsParser::*)(rapidxml::xml_node<char> *, EventGenerator &)), "578d7c240883e4f0ff77fc5589e5575653bb????????81ec7c0100008b378b4704898dc4feffff8d8dd4feffff", argdata, 3, 5, &func);
}

void EventsParser::ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, EventGenerator &generator_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func616::func;
	return execfunc(this, node, generator);
}

EventsParser *Global_EventsParser_Parser;

namespace _var617
{
    static VariableDefinition varObj("Global_EventsParser_Parser", "!b9(???????\?)8974240889442404", &Global_EventsParser_Parser);
}

namespace _func618
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ExplosionAnimation::OnInit", typeid(void (ExplosionAnimation::*)(rapidxml::xml_node<char> *, const std::string &, Point )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec8c0100008b70048b1889b594feffff8b70088b400c89b580feffff89857cfeffff8b412085c0", argdata, 4, 5, &func);
}

void ExplosionAnimation::OnInit(rapidxml::xml_node<char> *node, const std::string &name, Point glowOffset)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg, Point glowOffset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func618::func;
	return execfunc(this, node, name, glowOffset);
}

namespace _func619
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x7ff, 0x1ff};
	static FunctionDefinition funcObj("ExplosionAnimation::OnRender", typeid(void (ExplosionAnimation::*)(Globals::Rect *, ImageDesc , GL_Primitive *)), "578d????0883e4f0ff????5589f889e557565389cb83ec6c8b????8b5130", argdata, 4, 5, &func);
}

void ExplosionAnimation::OnRender(Globals::Rect *shipRect, ImageDesc shipImage, GL_Primitive *shipImagePrimitive)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg, Globals::Rect *shipRect_arg, ImageDesc shipImage_arg, GL_Primitive *shipImagePrimitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func619::func;
	return execfunc(this, shipRect, shipImage, shipImagePrimitive);
}

namespace _func620
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ExplosionAnimation::LoadGibs", typeid(void (ExplosionAnimation::*)()), "8b51308b413429d0c1f802", argdata, 1, 5, &func);
}

void ExplosionAnimation::LoadGibs()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func620::func;
	return execfunc(this);
}

namespace _func621
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("FTLButton::OnRender", typeid(void (FTLButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b89fc000000c70424????????e8????????83ec0485c00f85????????8b8b3c010000e8????????8b8b3c010000", argdata, 1, 5, &func);
}

void FTLButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FTLButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func621::func;
	return execfunc(this);
}

namespace _func622
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FTLButton::MouseMove", typeid(void (FTLButton::*)(int , int , bool )), "5731d28d7c240883e4f0ff77fc5589e557565383ec2c8b47048b3789c38945e48b47088945dc8b410c39c6", argdata, 4, 5, &func);
}

void FTLButton::MouseMove(int mX, int mY, bool silent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FTLButton *this_arg, int mX_arg, int mY_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func622::func;
	return execfunc(this, mX, mY, silent);
}

namespace _func623
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::deleteFile", typeid(void (*)(const std::string &)), "8d4c240483e4f031c0ff71fc5589e5575653518d75d883ec588b39668945d8", argdata, 1, 6, &func);
}

void FileHelper::deleteFile(const std::string &fileName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func623::func;
	return execfunc(fileName);
}

namespace _func624
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getResourceFile", typeid(std::string (*)()), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 1, 2, &func);
}

std::string FileHelper::getResourceFile()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func624::func;
	return execfunc();
}

namespace _func625
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getUserFolder", typeid(std::string (*)()), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 1, 2, &func);
}

std::string FileHelper::getUserFolder()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func625::func;
	return execfunc();
}

namespace _func626
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getSaveFile", typeid(std::string (*)()), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 1, 2, &func);
}

std::string FileHelper::getSaveFile()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func626::func;
	return execfunc();
}

namespace _func627
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::initFileHelper", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 0, 6, &func);
}

void FileHelper::initFileHelper()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func627::func;
	return execfunc();
}

namespace _func628
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::fileLength", typeid(int (*)(int )), ".8d4c240483e4f0ff71fc5589e55183ec14", argdata, 1, 2, &func);
}

int FileHelper::fileLength(int file)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func628::func;
	return execfunc(file);
}

namespace _func629
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::fileExists", typeid(bool (*)(const std::string &)), ".8d4c240483e4f031c0ff71fc5589e55756", argdata, 1, 2, &func);
}

bool FileHelper::fileExists(const std::string &fileName)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func629::func;
	return execfunc(fileName);
}

namespace _func630
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::renameFile", typeid(void (*)(const std::string &, const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d45b88d75d8", argdata, 2, 6, &func);
}

void FileHelper::renameFile(const std::string &fileName, const std::string &newName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg, const std::string &newName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func630::func;
	return execfunc(fileName, newName);
}

namespace _func631
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::createBinaryFile", typeid(int (*)(const std::string &)), ".8d4c240483e4f031d2ff71fc5589e5575653518dbd08fcffff81ec????????", argdata, 1, 2, &func);
}

int FileHelper::createBinaryFile(const std::string &fileName)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func631::func;
	return execfunc(fileName);
}

namespace _func632
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createSaveFile", typeid(int (*)()), ".a1????????a3????????b8????????", argdata, 0, 2, &func);
}

int FileHelper::createSaveFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func632::func;
	return execfunc();
}

namespace _func633
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createStatsFile", typeid(int (*)()), ".a1????????a3????????b8????????", argdata, 0, 2, &func);
}

int FileHelper::createStatsFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func633::func;
	return execfunc();
}

namespace _func634
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteSaveFile", typeid(void (*)()), ".5589e55383e4f083ec10c70424????????e8????????", argdata, 0, 6, &func);
}

void FileHelper::deleteSaveFile()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func634::func;
	return execfunc();
}

namespace _func635
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteAllSaveFiles", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e5575653518d45b8", argdata, 0, 6, &func);
}

void FileHelper::deleteAllSaveFiles()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func635::func;
	return execfunc();
}

namespace _func636
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getPosition", typeid(int (*)(int )), ".8d4c240483e4f0ff71fc5589e55183ec14", argdata, 1, 2, &func);
}

int FileHelper::getPosition(int file)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func636::func;
	return execfunc(file);
}

namespace _func637
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBinaryFile", typeid(int (*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 1, 2, &func);
}

int FileHelper::readBinaryFile(const std::string &fileName)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func637::func;
	return execfunc(fileName);
}

namespace _func638
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::closeBinaryFile", typeid(void (*)(int )), ".8d4c240483e4f0ff71fc5589e5535183ec10", argdata, 1, 6, &func);
}

void FileHelper::closeBinaryFile(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func638::func;
	return execfunc(file);
}

namespace _func639
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readString", typeid(std::string (*)(int )), ".8d4c240483e4f0ff71fc5589e55756535183ec48", argdata, 2, 2, &func);
}

std::string FileHelper::readString(int file)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func639::func;
	return execfunc(file);
}

namespace _func640
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readFloat", typeid(float (*)(int )), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 1, 2, &func);
}

float FileHelper::readFloat(int file)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func640::func;
	return execfunc(file);
}

namespace _func641
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readInteger", typeid(int (*)(int )), ".8d4c240483e4f0ff71fc5589e55756535183ec48", argdata, 1, 2, &func);
}

int FileHelper::readInteger(int file)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func641::func;
	return execfunc(file);
}

namespace _func642
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::seekPosition", typeid(bool (*)(int , int )), ".8d4c240483e4f0ff71fc5589e5535183ec10", argdata, 2, 2, &func);
}

bool FileHelper::seekPosition(int file, int pos)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func642::func;
	return execfunc(file, pos);
}

namespace _func643
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBuffer", typeid(char *(*)(int , int , bool )), ".8d4c240483e4f0ff71fc5589e55756", argdata, 3, 2, &func);
}

char *FileHelper::readBuffer(int file, int len, bool nullTerminate)
{
	typedef char *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int len_arg, bool nullTerminate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func643::func;
	return execfunc(file, len, nullTerminate);
}

namespace _func644
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readData", typeid(void (*)(int , void *, int )), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 3, 6, &func);
}

void FileHelper::readData(int file, void *data, int len)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, void *data_arg, int len_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func644::func;
	return execfunc(file, data, len);
}

namespace _func645
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeData", typeid(bool (*)(int , void *, int )), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 3, 2, &func);
}

bool FileHelper::writeData(int file, void *data, int len)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, void *data_arg, int len_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func645::func;
	return execfunc(file, data, len);
}

namespace _func646
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readSaveFile", typeid(int (*)()), ".8d4c240483e4f0ff71fc5589e55351", argdata, 0, 2, &func);
}

int FileHelper::readSaveFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func646::func;
	return execfunc();
}

namespace _func647
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readStatsFile", typeid(int (*)()), ".8d4c240483e4f0ff71fc5589e553518d45f483ec20", argdata, 0, 2, &func);
}

int FileHelper::readStatsFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func647::func;
	return execfunc();
}

namespace _func648
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::saveFileExists", typeid(bool (*)()), ".8d4c240483e4f0ff71fc5589e553518d45f483ec2089442408", argdata, 0, 2, &func);
}

bool FileHelper::saveFileExists()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func648::func;
	return execfunc();
}

namespace _func649
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeFloat", typeid(bool (*)(int , float )), ".8d4c240483e4f0ff71fc5589e5565351", argdata, 2, 2, &func);
}

bool FileHelper::writeFloat(int file, float data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, float data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func649::func;
	return execfunc(file, data);
}

namespace _func650
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeString", typeid(bool (*)(int , const std::string &)), ".8d4c240483e4f0ff71fc5589e55756535183ec488b41048b318b38", argdata, 2, 2, &func);
}

bool FileHelper::writeString(int file, const std::string &data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, const std::string &data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func650::func;
	return execfunc(file, data);
}

namespace _func651
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeInt", typeid(bool (*)(int , int )), "8d4c240483e4f0ff71fc5589e556535183ec3c803d??????????8b41048b198945e075??", argdata, 2, 2, &func);
}

bool FileHelper::writeInt(int file, int data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func651::func;
	return execfunc(file, data);
}

namespace _func652
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Fire::OnLoop", typeid(void (Fire::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80b9fc0100000075??8b038db3300100008b4028", argdata, 1, 5, &func);
}

void Fire::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Fire *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func652::func;
	return execfunc(this);
}

namespace _func653
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Fire::UpdateStartTimer", typeid(void (Fire::*)(int )), ".5589e5565389cb83e4f083ec108b018b75088b40283d????????0f85????????f30f1041100f2e05????????0f97c084c00f85????????", argdata, 2, 5, &func);
}

void Fire::UpdateStartTimer(int doorLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Fire *this_arg, int doorLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func653::func;
	return execfunc(this, doorLevel);
}

namespace _func654
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Fire::UpdateDeathTimer", typeid(void (Fire::*)(int )), ".5589e55389cb83e4f083ec108b018b40283d????????0f85????????f30f1041100f2e05????????0f97c084c00f84????????660fefd2f30f104358", argdata, 2, 5, &func);
}

void Fire::UpdateDeathTimer(int connectedFires)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Fire *this_arg, int connectedFires_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func654::func;
	return execfunc(this, connectedFires);
}

namespace _func655
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FocusWindow::MouseClick", typeid(void (FocusWindow::*)(int , int )), "8079100075??c208008db426000000008b01c64110008b40103d????????75??c6410400c2080089f68dbc27000000005589e5", argdata, 3, 5, &func);
}

void FocusWindow::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func655::func;
	return execfunc(this, x, y);
}

namespace _func656
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FocusWindow::MouseMove", typeid(void (FocusWindow::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575383ec108b41088b1f8b7f0483f8ff", argdata, 3, 5, &func);
}

void FocusWindow::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func656::func;
	return execfunc(this, x, y);
}

namespace _func657
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("GameOver::OpenText", typeid(void (GameOver::*)(const std::string &)), "578d7c240883e4f0ff77fc5589f889e557565389cf83c14c81ec????????8b00c641b801", argdata, 2, 5, &func);
}

void GameOver::OpenText(const std::string &text)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GameOver *this_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func657::func;
	return execfunc(this, text);
}

namespace _func658
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GameOver::OnRender", typeid(void (GameOver::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b9d0000000000f85????????807940000f85????????8b4728bb????????890424e8????????", argdata, 1, 5, &func);
}

void GameOver::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func658::func;
	return execfunc(this);
}

namespace _func659
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GameOver::OnLoop", typeid(void (GameOver::*)()), "578d7c240883e4f0ff77fc5589e557565389ceb9????????83ec5ce8????????d95db4f30f1045b4", argdata, 1, 5, &func);
}

void GameOver::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func659::func;
	return execfunc(this);
}

namespace _func660
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void (GenericButton::*)(Point )), "5589e557568b4508538b59048b550c83e4f08b710839d874??89c78941048b0129df89d301790c29f3015910895108ff50308d65f45b5e5f5dc20800", argdata, 2, 5, &func);
}

void GenericButton::SetLocation(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func660::func;
	return execfunc(this, pos);
}

namespace _func661
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::SetActive", typeid(void (GenericButton::*)(bool )), "8b44240484c088414075??c6414200c6414300c204008d76008dbc27000000005589e583e4f083ec10", argdata, 2, 5, &func);
}

void GenericButton::SetActive(bool active)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg, bool active_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func661::func;
	return execfunc(this, active);
}

namespace _func662
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::MouseMove", typeid(void (GenericButton::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e5575383ec108b178b410c8b5f048b7f0839c27e??03411439c27c??c6414100", argdata, 4, 5, &func);
}

void GenericButton::MouseMove(int x, int y, bool silent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg, int x_arg, int y_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func662::func;
	return execfunc(this, x, y, silent);
}

namespace _func663
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GenericButton::OnRightClick", typeid(void (GenericButton::*)()), "f3c39090909090909090909090909090", argdata, 1, 5, &func);
}

void GenericButton::OnRightClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func663::func;
	return execfunc(this);
}

namespace _func664
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GenericButton::ResetPrimitives", typeid(void (GenericButton::*)()), ".f3c39090909090909090909090909090", argdata, 1, 5, &func);
}

void GenericButton::ResetPrimitives()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func664::func;
	return execfunc(this);
}

namespace _func665
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GenericButton::OnClick", typeid(void (GenericButton::*)()), ".f3c39090909090909090909090909090", argdata, 1, 5, &func);
}

void GenericButton::OnClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func665::func;
	return execfunc(this);
}

namespace _func666
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_text_width", typeid(float (*)(freetype::font_data &, const char *, float )), "5589e557565383e4f083ec408b4d088b750c85c9", argdata, 3, 2, &func);
}

float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(freetype::font_data &fontData_arg, const char *str_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func666::func;
	return execfunc(fontData, str, size);
}

namespace _func667
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("random32", typeid(int (*)()), "556905????????????????89e556536935????????????????83e4f801c6b8????????f725????????01f283c00183d200a3????????8915????????", argdata, 0, 0, &func);
}

int __stdcall random32()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func667::func;
	return execfunc();
}

namespace _func668
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("srandom32", typeid(void (*)(unsigned int )), "55c705????????????????89e583e4f88b4508a3????????", argdata, 1, 6, &func);
}

void __stdcall srandom32(unsigned int seed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(unsigned int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func668::func;
	return execfunc(seed);
}

namespace _func669
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("getSkillBonus", typeid(float (*)(int , int )), "83ec048b4424088b54240c83f80577??ff2485????????89f68dbc270000000085d2660fefc074??83fa010f84????????", argdata, 2, 2, &func);
}

float __stdcall getSkillBonus(int skill, int level)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int skill_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func669::func;
	return execfunc(skill, level);
}

namespace _func670
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenerateReward", typeid(void (*)(ResourceEvent &, RewardDesc &, int )), "8d4c240483e4f0ff71fc5589e55756535181ec????????8b018b79088985d4fcffff8b410489bdd0fcffff8985ccfcffff8b4018", argdata, 3, 6, &func);
}

void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, RewardDesc &reward_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func670::func;
	return execfunc(ref, reward, worldLevel);
}

namespace _func671
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GetValue", typeid(void (*)(ResourceEvent &, const std::string &, int , int )), "8d4c240483e4f0ff71fc5589e55756535183ec288b59048b410c8b398b7108c70424????????89d98945e4e8????????83ec0485c00f84????????", argdata, 4, 6, &func);
}

void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, const std::string &type_arg, int level_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func671::func;
	return execfunc(ref, type, level, worldLevel);
}

namespace _func672
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("sys_graphics_set_window_title", typeid(void (*)(char *)), "5589e55383e4f083ec10a1????????8b5d08890424e8????????", argdata, 1, 6, &func);
}

void __stdcall sys_graphics_set_window_title(char *title)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(char *title_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func672::func;
	return execfunc(title);
}

namespace _func673
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("graphics_clear", typeid(void (*)(float , float , float , float , float , unsigned int )), "55660fefc089e583e4f083ec30f30f106d180f2ee8f30f106508f30f105d0cf30f105510f30f104d14", argdata, 6, 6, &func);
}

void __stdcall graphics_clear(float r, float g, float b, float a, float depth, unsigned int stencil)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float r_arg, float g_arg, float b_arg, float a_arg, float depth_arg, unsigned int stencil_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func673::func;
	return execfunc(r, g, b, a, depth, stencil);
}

namespace _func674
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Globals::AimAhead", typeid(float (*)(Pointf , Pointf , float )), "5589e583e4f083ec20f30f106510f30f1045140f28f40f28d0f30f59e4f30f59c0f30f104d08f30f105d0cf30f59f1f30f106d18f30f59d3f30f59ed", argdata, 3, 2, &func);
}

float Globals::AimAhead(Pointf delta, Pointf vr, float muzzleV)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf delta_arg, Pointf vr_arg, float muzzleV_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func674::func;
	return execfunc(delta, vr, muzzleV);
}

namespace _func675
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), "8b15????????8d420185d2ba????????0f44c2a3????????", argdata, 0, 0, &func);
}

int Globals::GetNextSpaceId()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func675::func;
	return execfunc();
}

namespace _func676
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , float )), "8d4c240483e4f0ff71fc5589e55183ec44f30f1005????????f30f59410cf30f105108f30f1019f30f106104f30f1155d4f30f115de4f30f1165e0", argdata, 3, 10, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, float heading)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func676::func;
	return execfunc(current, mag_speed, heading);
}

namespace _func677
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , Pointf )), "8d4c240483e4f0ff71fc5589e5535183ec408b41108b590cf30f104108f30f10510c8945e4f30f1019f30f106904", argdata, 3, 10, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, Pointf dest)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, Pointf dest_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func677::func;
	return execfunc(current, mag_speed, dest);
}

TextLibrary *Global_Globals_Library;

namespace _var678
{
    static VariableDefinition varObj("Global_Globals_Library", "!899d8ccaffffc6041800b9(???????\?)", &Global_Globals_Library);
}

int *Globals_GetNextSpaceId_id;

namespace _var679
{
    static VariableDefinition varObj("Globals_GetNextSpaceId_id", "8b15(???????\?)8d420185d2ba650000000f44c2a3????????c3", &Globals_GetNextSpaceId_id);
}

bool *Globals_RNG;

namespace _var680
{
    static VariableDefinition varObj("Globals_RNG", "!578d7c240883e4f0ff77fc5589e557565389cb83ec4cc7042400000000e8????????803d(???????\?)00890424", &Globals_RNG);
}

FILE *ftl_log_logfile;

namespace _var681
{
    static VariableDefinition varObj("ftl_log_logfile", "5589e556538d750c83e4f083ec108b5d0889742404891c24e8????????a1(???????\?)85c0", &ftl_log_logfile);
}

namespace _func682
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("HackBox::constructor", typeid(void (HackBox::*)(Point , HackingSystem *, ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389fe89cb81ec????????8b57048b078b7f088b760cc744240c0000000089542404", argdata, 4, 5, &func);
}

void HackBox::constructor(Point pos, HackingSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackBox *this_arg, Point pos_arg, HackingSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func682::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func683
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingDrone::OnLoop", typeid(void (HackingDrone::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6ce8????????", argdata, 1, 5, &func);
}

void HackingDrone::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func683::func;
	return execfunc(this);
}

namespace _func684
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("HackingDrone::SetMovementTarget", typeid(void (HackingDrone::*)(Targetable *)), "578d7c240883e4f0ff77fc5589e557565383ec2c8b3785f60f84????????89cb89b150010000c6815c03000000c6815d030000008d897c030000c7042400000000", argdata, 2, 5, &func);
}

void HackingDrone::SetMovementTarget(Targetable *target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func684::func;
	return execfunc(this, target);
}

namespace _func685
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("HackingDrone::CollisionMoving", typeid(CollisionResponse (HackingDrone::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec9c0000008b378b47048b57088b4f48", argdata, 6, 1, &func);
}

CollisionResponse HackingDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func685::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func686
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingSystem::BlowHackingDrone", typeid(void (HackingSystem::*)()), "80b9d80100000075??c38db6000000005781c1????????8d7c240883e4f0ff77fc5589e55783ec14c70424????????e8????????8b7dfc", argdata, 1, 5, &func);
}

void HackingSystem::BlowHackingDrone()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func686::func;
	return execfunc(this);
}

namespace _func687
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingSystem::OnLoop", typeid(void (HackingSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4ce8????????80bbe4010000000f84????????80bbc0010000000f84????????8b8bac070000", argdata, 1, 5, &func);
}

void HackingSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func687::func;
	return execfunc(this);
}

namespace _func688
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingSystem::SoundLoop", typeid(bool (HackingSystem::*)()), "80b9c00100000075??31c0c38d7426005589e55389cb83e4??e8????????83f8??74??", argdata, 1, 1, &func);
}

bool HackingSystem::SoundLoop()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func688::func;
	return execfunc(this);
}

namespace _func689
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::OnRender", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????8b018b91c8000000", argdata, 1, 5, &func);
}

void InfoBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func689::func;
	return execfunc(this);
}

namespace _func690
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::Clear", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e55756538d45cc8d75d489cb83c10c", argdata, 1, 5, &func);
}

void InfoBox::Clear()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func690::func;
	return execfunc(this);
}

namespace _func691
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(void (InfoBox::*)(Description *, int , int , InfoBox::ExpandDir )), "578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec2c8b378b5708", argdata, 5, 5, &func);
}

void InfoBox::SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, Description *desc_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func691::func;
	return execfunc(this, desc, width, height, dir);
}

namespace _func692
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetText", typeid(void (InfoBox::*)(const std::string &, const std::string &, int , int , InfoBox::ExpandDir )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b47048b37c78550ffffff00000000c68554ffffff00c68564ffffff01c7856cffffff00000000", argdata, 6, 5, &func);
}

void InfoBox::SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const std::string &title_arg, const std::string &text_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func692::func;
	return execfunc(this, title, text, width, height, dir);
}

namespace _func693
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintWeapon", typeid(void (InfoBox::*)(const WeaponBlueprint *, int , bool , int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4d9c81ec????????8b47048b378945948b470cc744240400000000893424894588e8????????8d461c", argdata, 5, 5, &func);
}

void InfoBox::SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const WeaponBlueprint *bp_arg, int status_arg, bool hasWeaponSystem_arg, int yShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func693::func;
	return execfunc(this, bp, status, hasWeaponSystem, yShift);
}

namespace _func694
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintDrone", typeid(void (InfoBox::*)(const DroneBlueprint *, int , bool , int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83c10c81ec????????8b50048b30899558fdffff8b50088b400c89b544fdffff899548fdffff898554fdffff8d461c", argdata, 5, 5, &func);
}

void InfoBox::SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const DroneBlueprint *bp_arg, int status_arg, bool hasDroneSystem_arg, int yShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func694::func;
	return execfunc(this, bp, status, hasDroneSystem, yShift);
}

namespace _func695
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprint", typeid(void (InfoBox::*)(const ItemBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec1c8b378d461c890424", argdata, 2, 5, &func);
}

void InfoBox::SetBlueprint(const ItemBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const ItemBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func695::func;
	return execfunc(this, bp);
}

namespace _func696
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintCrew", typeid(void (InfoBox::*)(const CrewBlueprint *, int , bool )), ".5789ca8d7c240883e4f0ff77fc5589e55756538d720c81ec????????8b078b5f08898d78fdffffc782c000000031010000c782c4000000b6000000c7821c0100004300000089c1", argdata, 4, 5, &func);
}

void InfoBox::SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const CrewBlueprint *bp_arg, int yShift_arg, bool detailedCrew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func696::func;
	return execfunc(this, bp, yShift, detailedCrew);
}

namespace _func697
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintAugment", typeid(void (InfoBox::*)(const AugmentBlueprint *)), ".578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec1c8b378d461c890424", argdata, 2, 5, &func);
}

void InfoBox::SetBlueprintAugment(const AugmentBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const AugmentBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func697::func;
	return execfunc(this, bp);
}

namespace _func698
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::CalcBoxHeight", typeid(int (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????83b9ac000000010f84????????8b8fd000000085c90f85????????c78500ffffff30000000807f5c00", argdata, 1, 1, &func);
}

int InfoBox::CalcBoxHeight()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func698::func;
	return execfunc(this);
}

namespace _func699
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::IsEmpty", typeid(bool (InfoBox::*)()), "83b9b4000000ff74??31c0c38d742600578d7c240883e4f0ff77fc5589e557565389cb83ec4c80792400", argdata, 1, 1, &func);
}

bool InfoBox::IsEmpty()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func699::func;
	return execfunc(this);
}

namespace _func700
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::constructor", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c744240400000000c70424????????e8????????8d43148d8bc0000000", argdata, 1, 5, &func);
}

void InfoBox::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func700::func;
	return execfunc(this);
}

namespace _func701
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetSystemId", typeid(void (InfoBox::*)(int , int , int , int , int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec4c8b70048b3f8b50088b480cc783c8000000000000008975bc8b701083ffff8b4014", argdata, 7, 5, &func);
}

void InfoBox::SetSystemId(int systemId, int maxPower, int currentLevel, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, int systemId_arg, int maxPower_arg, int currentLevel_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func701::func;
	return execfunc(this, systemId, maxPower, currentLevel, upgrade, yShift, forceSystemWidth);
}

namespace _func702
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetSystem", typeid(void (InfoBox::*)(ShipSystem *, int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b378b47048b57088b7f0c85f68945c40f84????????", argdata, 5, 5, &func);
}

void InfoBox::SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, ShipSystem *system_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func702::func;
	return execfunc(this, system, upgrade, yShift, forceSystemWidth);
}

GL_Color *Global_InfoBox_detailsBarOn;

namespace _var703
{
    static VariableDefinition varObj("Global_InfoBox_detailsBarOn", "!83ec083bb514fdffffba(???????\?)b8(???????\?)", &Global_InfoBox_detailsBarOn);
}

GL_Color *Global_InfoBox_detailsBarOff;

namespace _var704
{
    static VariableDefinition varObj("Global_InfoBox_detailsBarOff", "", &Global_InfoBox_detailsBarOff);
}

namespace _func705
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InputBox::TextEvent", typeid(void (InputBox::*)(CEvent::TextEvent )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b0783f8010f84????????89cb72??", argdata, 2, 5, &func);
}

void InputBox::TextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InputBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func705::func;
	return execfunc(this, event);
}

namespace _func706
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InputBox::StartInput", typeid(void (InputBox::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

void InputBox::StartInput()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InputBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func706::func;
	return execfunc(this);
}

namespace _func707
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InputBox::OnRender", typeid(void (InputBox::*)()), "80790400750ac389f68dbc2700000000578d7c240883e4f0ff77fc5589e55753", argdata, 1, 5, &func);
}

void InputBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InputBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func707::func;
	return execfunc(this);
}

namespace _func708
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InputBox::TextInput", typeid(void (InputBox::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec??8b3783fe??0f8f7f000000", argdata, 2, 5, &func);
}

void InputBox::TextInput(int ch)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InputBox *this_arg, int ch_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func708::func;
	return execfunc(this, ch);
}

namespace _func709
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("IonDrone::GetRoomDamage", typeid(Damage (IonDrone::*)()), "5589e556538b7508c701????????89cbc7410400000000c741080000000083e4f0c7410c00000000c7411000000000c7411400000000c7411800000000c7411c00000000c6412000c74124ffffffffc74128ffffffffc6412c00c6412d00c6412e01", argdata, 2, 1, &func);
}

Damage IonDrone::GetRoomDamage()
{
	typedef Damage __attribute__((thiscall)) (*custom_arg_funcptr_t)(IonDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func709::func;
	return execfunc(this);
}

namespace _func710
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("IonDrone::constructor", typeid(void (IonDrone::*)(int , DroneBlueprint *)), "578d????0883e4f0ff????5589f889e557565389cf8d??e4feffff", argdata, 3, 5, &func);
}

void IonDrone::constructor(int iShipId, DroneBlueprint *blueprint)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(IonDrone *this_arg, int iShipId_arg, DroneBlueprint *blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func710::func;
	return execfunc(this, iShipId, blueprint);
}

namespace _func711
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("IonDroneAnimation::constructor", typeid(void (IonDroneAnimation::*)(int , Pointf , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf8db524ffffff81ec4c0100008b48048b108b58088b400c89b51cffffff", argdata, 4, 5, &func);
}

void IonDroneAnimation::constructor(int iShipId, Pointf position, bool enemy)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(IonDroneAnimation *this_arg, int iShipId_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func711::func;
	return execfunc(this, iShipId, position, enemy);
}

namespace _func712
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("IonDroneAnimation::UpdateShooting", typeid(void (IonDroneAnimation::*)()), "578d7c240883e4f0ff77fc5589e557568db19c0800005383ec4c", argdata, 1, 5, &func);
}

void IonDroneAnimation::UpdateShooting()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(IonDroneAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func712::func;
	return execfunc(this);
}

namespace _func713
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ItemStoreBox::constructor", typeid(void (ItemStoreBox::*)(ShipManager *, const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45d889cb8d4dd083ec5c8b378b7f048945d0c745d400000000c645d8008b4704", argdata, 3, 5, &func);
}

void ItemStoreBox::constructor(ShipManager *ship, const std::string &resourceName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ItemStoreBox *this_arg, ShipManager *ship_arg, const std::string &resourceName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func713::func;
	return execfunc(this, ship, resourceName);
}

namespace _func714
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LanguageChooser::OnRender", typeid(void (LanguageChooser::*)()), "57????????83e4f0ff77fc5589e557565389ce8d4d9081ecac000000", argdata, 1, 5, &func);
}

void LanguageChooser::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LanguageChooser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func714::func;
	return execfunc(this);
}

std::vector<std::string> *Global_OptionsScreen_languageList;

namespace _var715
{
    static VariableDefinition varObj("Global_OptionsScreen_languageList", "!83ec1ca1(???????\?)c1e30301d8", &Global_OptionsScreen_languageList);
}

namespace _func716
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LaserBlast::OnUpdate", typeid(void (LaserBlast::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec4080b9b00000000074??8d8b4c010000", argdata, 1, 5, &func);
}

void LaserBlast::OnUpdate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func716::func;
	return execfunc(this);
}

namespace _func717
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LaserBlast::OnInit", typeid(void (LaserBlast::*)()), "5589e5538b417489cbc7413801000000c741400100000083e4f0394170c7414400000000c74108040000007463", argdata, 1, 5, &func);
}

void LaserBlast::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func717::func;
	return execfunc(this);
}

void **VTable_LaserBlast;

namespace _var718
{
    static VariableDefinition varObj("VTable_LaserBlast", "!660fefc989c3660fefd28b45b48b5598f30f2a4da4f30f2a55ac8b480489542410897c240c894da88b4d9c894c24148b4da8894c240889d90f28d9660f7ed0660f7e1c2489442404e8????????89f0ba????????83ec18f7ea660fefc089d9c703(???????\?)c74304(???????\?)c783a002000000000000c783a402000000000000", &VTable_LaserBlast);
}

void **VTable_Targetable_LaserBlast;

namespace _var719
{
    static VariableDefinition varObj("VTable_Targetable_LaserBlast", "", &VTable_Targetable_LaserBlast);
}

namespace _func720
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c83b910060000018b0775??", argdata, 2, 5, &func);
}

void LocationEvent::ClearEvent(bool force)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LocationEvent *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func720::func;
	return execfunc(this, force);
}

namespace _func721
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LocationEvent::constructor", typeid(void (LocationEvent::*)()), "558d410889e55389018d4128c7410400000000c6410800c6411801c6411c0089cb8941208d4140c7412400000000c6412800c7413c00000000", argdata, 1, 5, &func);
}

void LocationEvent::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LocationEvent *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func721::func;
	return execfunc(this);
}

namespace _func722
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LockdownShard::Update", typeid(void (LockdownShard::*)()), "578d7c240883e4f0ff77fc5589e5575389cbb9????????83ec30e8????????d95df4f30f1045f4f30f5905????????f30f5883e4000000f30f1183e4000000f30f1083d40000000f2e83cc0000007a??", argdata, 1, 5, &func);
}

void LockdownShard::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LockdownShard *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func722::func;
	return execfunc(this);
}

namespace _func723
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OnRender", typeid(void (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b910340000000f85????????80b948200000000f84????????", argdata, 1, 5, &func);
}

void MainMenu::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func723::func;
	return execfunc(this);
}

namespace _func724
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::Open", typeid(bool (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????80b92003000000898da4fdffff0f85????????8d8510feffff89859cfdffff8d85f8fdffff", argdata, 1, 1, &func);
}

bool MainMenu::Open()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func724::func;
	return execfunc(this);
}

namespace _func725
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::OnLoop", typeid(void (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b910340000000f85????????a1????????89f9", argdata, 1, 5, &func);
}

void MainMenu::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func725::func;
	return execfunc(this);
}

namespace _func726
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::constructor", typeid(void (MainMenu::*)()), "578d412c8d7c240883e4f0ff77fc5589e557565389cb8dbb040100008db37001000083ec4cc60100", argdata, 1, 5, &func);
}

void MainMenu::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func726::func;
	return execfunc(this);
}

namespace _func727
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseClick", typeid(void (MainMenu::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c80b910340000008b078b57040f85????????80b9d03100000089cb", argdata, 3, 5, &func);
}

void MainMenu::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func727::func;
	return execfunc(this, x, y);
}

namespace _func728
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseMove", typeid(void (MainMenu::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec5c80b910340000008b078b77048945b40f85????????80b95c2f00000089cf0f85????????80b9d031000000", argdata, 3, 5, &func);
}

void MainMenu::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func728::func;
	return execfunc(this, x, y);
}

namespace _func729
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK", typeid(void (MantisAnimation::*)()), "5e5f5d8d67f85fc20400908d742600e8????????89c1e9????????8d7426000f1040080f114308eb??", argdata, 0, 4, &func);
}

namespace _func730
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::GetShootingSound", typeid(std::string (MantisAnimation::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c803d??????????0f84????????e8????????89c189c8ba????????", argdata, 2, 1, &func);
}

std::string MantisAnimation::GetShootingSound()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func730::func;
	return execfunc(this);
}

namespace _func731
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK2", typeid(void (MantisAnimation::*)()), "578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 0, 4, &func);
}

namespace _func732
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::GetDeathSound", typeid(std::string (MantisAnimation::*)()), ".578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 2, 1, &func);
}

std::string MantisAnimation::GetDeathSound()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func732::func;
	return execfunc(this);
}

namespace _func733
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MantisAnimation::FireShot", typeid(bool (MantisAnimation::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b41308b5108694938cc0000008d04408d04820308c70424????????83c120e8????????8b5308d95df48b45f4", argdata, 1, 1, &func);
}

bool MantisAnimation::FireShot()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func733::func;
	return execfunc(this);
}

namespace _func734
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::OnLanguageChange", typeid(void (MenuScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b511c89d085c0", argdata, 1, 5, &func);
}

void MenuScreen::OnLanguageChange()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func734::func;
	return execfunc(this);
}

namespace _func735
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::constructor", typeid(void (MenuScreen::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8db564ffffff81ec????????e8????????8d4b44c703????????c7432000000000c7432800000000c7432c00000000", argdata, 1, 5, &func);
}

void MenuScreen::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func735::func;
	return execfunc(this);
}

namespace _func736
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::OnRender", typeid(void (MenuScreen::*)()), ".578d7c240883e4f0ff77fc5589e557565381ec????????80b9c0020000000f84????????", argdata, 1, 5, &func);
}

void MenuScreen::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func736::func;
	return execfunc(this);
}

namespace _func737
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::Open", typeid(void (MenuScreen::*)()), ".578d7c240883e4f0ff77fc5589e557565389cf83c14c8d75d883ec5cc641b801", argdata, 1, 5, &func);
}

void MenuScreen::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func737::func;
	return execfunc(this);
}

namespace _func738
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("MindBox::constructor", typeid(void (MindBox::*)(Point , MindSystem *)), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b77088b5704c744240c000000008d7db4890424", argdata, 3, 5, &func);
}

void MindBox::constructor(Point pos, MindSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindBox *this_arg, Point pos_arg, MindSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func738::func;
	return execfunc(this, pos, sys);
}

namespace _func739
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::ReleaseCrew", typeid(void (MindSystem::*)()), "578d????0883e4f0ff????5589e557565389cf83ec3c8b89d0010000", argdata, 1, 5, &func);
}

void MindSystem::ReleaseCrew()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func739::func;
	return execfunc(this);
}

namespace _func740
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MindSystem::SetArmed", typeid(void (MindSystem::*)(int )), "5589e55389cb83e4f0837d080174??c783cc010000000000008b5dfcc9c2040080b9c80100000074??", argdata, 2, 5, &func);
}

void MindSystem::SetArmed(int armed)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindSystem *this_arg, int armed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func740::func;
	return execfunc(this, armed);
}

namespace _func741
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MindSystem::SetHackingLevel", typeid(void (MindSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b3783fe01", argdata, 2, 5, &func);
}

void MindSystem::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func741::func;
	return execfunc(this, hackingLevel);
}

namespace _func742
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::InitiateMindControl", typeid(void (MindSystem::*)()), "578d7c240883e4f0ff77fc5589e557565383ec5c8b81ec0100008bb1e8010000894dbc89c329f389d8c1f80285c0", argdata, 1, 5, &func);
}

void MindSystem::InitiateMindControl()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func742::func;
	return execfunc(this);
}

namespace _func743
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::OnLoop", typeid(void (MindSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4ce8????????8b83ec0100003983e8010000740789d9", argdata, 1, 5, &func);
}

void MindSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func743::func;
	return execfunc(this);
}

namespace _func744
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Missile::constructor", typeid(void (Missile::*)(Pointf , int , int , Pointf , float )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec2c010000898decfeffff8b58048b088b5010f30f104018", argdata, 6, 5, &func);
}

void Missile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Missile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, float _heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func744::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _heading);
}

namespace _func745
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltip", typeid(void (MouseControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b3f8b5f0485db", argdata, 2, 5, &func);
}

void MouseControl::SetTooltip(const std::string &tooltip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func745::func;
	return execfunc(this, tooltip);
}

namespace _func746
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltipTitle", typeid(void (MouseControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55783ec148b91300100008b0785d2751181c12c010000890424", argdata, 2, 5, &func);
}

void MouseControl::SetTooltipTitle(const std::string &tooltip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func746::func;
	return execfunc(this, tooltip);
}

namespace _func747
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::MeasureTooltip", typeid(Point (MouseControl::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd883ec4c8b37", argdata, 2, 9, &func);
}

Point MouseControl::MeasureTooltip(int unk)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func747::func;
	return execfunc(this, unk);
}

namespace _func748
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("MouseControl::QueueStaticTooltip", typeid(void (MouseControl::*)(Point )), ".5589e58b45088b550c5d898164010000", argdata, 2, 5, &func);
}

void MouseControl::QueueStaticTooltip(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func748::func;
	return execfunc(this, pos);
}

namespace _func749
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::OnLoop", typeid(void (MouseControl::*)()), "5589e55389cb83e4f083ec1080b91c0100000074??f30f1005????????0f2e8318010000", argdata, 1, 5, &func);
}

void MouseControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func749::func;
	return execfunc(this);
}

namespace _func750
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::InstantTooltip", typeid(void (MouseControl::*)()), ".c6812801000001", argdata, 1, 5, &func);
}

void MouseControl::InstantTooltip()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func750::func;
	return execfunc(this);
}

namespace _func751
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::OnRender", typeid(void (MouseControl::*)()), "80b91d010000000f85????????578d7c240883e4f0ff77fc5589e557565389cf81ec????????0fb6411d8b592884c00f84????????", argdata, 1, 5, &func);
}

void MouseControl::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func751::func;
	return execfunc(this);
}

namespace _func752
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetDoor", typeid(void (MouseControl::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f83fb0174??", argdata, 2, 5, &func);
}

void MouseControl::SetDoor(int state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, int state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func752::func;
	return execfunc(this, state);
}

namespace _func753
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::RenderTooltip", typeid(void (MouseControl::*)(Point , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c83bb30010000018b078b57048b4f088bbb60010000", argdata, 3, 5, &func);
}

void MouseControl::RenderTooltip(Point tooltipPoint, bool staticPos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, Point tooltipPoint_arg, bool staticPos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func753::func;
	return execfunc(this, tooltipPoint, staticPos);
}

namespace _func754
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::ResetArmed", typeid(void (MouseControl::*)()), "c7411000000000c7411400000000c7411800000000c7815c01000000000000c7412000000000", argdata, 1, 5, &func);
}

void MouseControl::ResetArmed()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func754::func;
	return execfunc(this);
}

namespace _func755
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::Reset", typeid(void (MouseControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d890001000083ec20c78120ffffff00000000", argdata, 1, 5, &func);
}

void MouseControl::Reset()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func755::func;
	return execfunc(this);
}

namespace _func756
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::LoadTooltip", typeid(void (MouseControl::*)(const std::string &)), "578d????0883e4f0ff????5589e55756538d??c089cb", argdata, 2, 5, &func);
}

void MouseControl::LoadTooltip(const std::string &tooltipName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltipName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func756::func;
	return execfunc(this, tooltipName);
}

MouseControl *Global_MouseControl_Mouse;

namespace _var757
{
    static VariableDefinition varObj("Global_MouseControl_Mouse", "!e8????????e8????????b9(???????\?)", &Global_MouseControl_Mouse);
}

namespace _func758
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OptionsScreen::OnInit", typeid(void (OptionsScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????8d7dcc8db31808000081ec????????e8????????8b83880200008b938c020000d99d34ffffff660fefc9", argdata, 1, 5, &func);
}

void OptionsScreen::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func758::func;
	return execfunc(this);
}

namespace _func759
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OptionsScreen::OnLoop", typeid(void (OptionsScreen::*)()), "57660fefc0660fefc98d7c240883e4f0ff77fc5589e557565389cf83ec7c8b91880200008b8168020000894d9029d0f30f2ac08b818c020000b9????????894594", argdata, 1, 5, &func);
}

void OptionsScreen::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func759::func;
	return execfunc(this);
}

namespace _func760
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("OptionsScreen::Open", typeid(void (OptionsScreen::*)(bool )), "57660f76c08d7c240883e4f0ff77fc5589e557565381ec9c0400008b07898d70fbffff0f1181f8090000c681cc02000000", argdata, 2, 5, &func);
}

void OptionsScreen::Open(bool mainMenu)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg, bool mainMenu_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func760::func;
	return execfunc(this, mainMenu);
}

void **VTable_OuterHull;

namespace _var761
{
    static VariableDefinition varObj("VTable_OuterHull", "578d7c240883e4f0ff77fc5589f889e557565389cf8db7840000008d9f9c00000081ec4c0100008b00890424e8????????8d4f7c83ec04c707(???????\?)", &VTable_OuterHull);
}

namespace _func762
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(void (OxygenSystem::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e5575383ec108b47048b1f8b570885c07e??", argdata, 4, 5, &func);
}

void OxygenSystem::UpdateBreach(int roomId, int hasBreach, bool unk3)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int hasBreach_arg, bool unk3_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func762::func;
	return execfunc(this, roomId, hasBreach, unk3);
}

namespace _func763
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(void (OxygenSystem::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b5f048b1785db7e??8b81c4010000", argdata, 3, 5, &func);
}

void OxygenSystem::UpdateAirlock(int roomId, int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func763::func;
	return execfunc(this, roomId, unk);
}

namespace _func764
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(void (OxygenSystem::*)(int )), ".8b81c40100008b542404c70490????????", argdata, 2, 5, &func);
}

void OxygenSystem::EmptyOxygen(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func764::func;
	return execfunc(this, roomId);
}

namespace _func765
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(void (OxygenSystem::*)(int , float )), "8b81c40100008b5424048d0490f30f1000f30f58442408f30f1100", argdata, 3, 5, &func);
}

void OxygenSystem::ModifyRoomOxygen(int roomId, float value)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func765::func;
	return execfunc(this, roomId, value);
}

namespace _func766
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(void (OxygenSystem::*)(int , float , bool )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec3c8b18f30f106804", argdata, 4, 5, &func);
}

void OxygenSystem::ComputeAirLoss(int roomId, float value, bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func766::func;
	return execfunc(this, roomId, value, unk);
}

namespace _func767
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OxygenSystem::GetRefillSpeed", typeid(float (OxygenSystem::*)()), "5589e55389cb83e4f083ec1083b9a8010000017e??80b9ac0100000074??b9????????e8????????d95c240c8b5dfcf30f1044240cf30f5905????????f30f1144240c", argdata, 1, 1, &func);
}

float OxygenSystem::GetRefillSpeed()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func767::func;
	return execfunc(this);
}

namespace _func768
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::constructor", typeid(void (OxygenSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4f0c8b47048b57088b37c70424????????894c240c8944240489d989542408e8????????", argdata, 5, 5, &func);
}

void OxygenSystem::constructor(int numRooms, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int numRooms_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func768::func;
	return execfunc(this, numRooms, roomId, shipId, startingPower);
}

namespace _func769
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("PDSFire::CollisionCheck", typeid(void (PDSFire::*)(Collideable *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b378b0689f1ff50283b4378740e", argdata, 2, 5, &func);
}

void PDSFire::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(PDSFire *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func769::func;
	return execfunc(this, other);
}

namespace _func770
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("PDSFire::OnUpdate", typeid(void (PDSFire::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c80b9b000000000", argdata, 1, 5, &func);
}

void PDSFire::OnUpdate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(PDSFire *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func770::func;
	return execfunc(this);
}

namespace _func771
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("PDSFire::constructor", typeid(void (PDSFire::*)(Point , int , Pointf )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec3c010000", argdata, 4, 5, &func);
}

void PDSFire::constructor(Point pos, int destinationSpace, Pointf destination)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(PDSFire *this_arg, Point pos_arg, int destinationSpace_arg, Pointf destination_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func771::func;
	return execfunc(this, pos, destinationSpace, destination);
}

namespace _func772
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), "558b018b510489e52b45082b550c5d0fafc00fafd201d0", argdata, 2, 1, &func);
}

int Point::RelativeDistance(Point other)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func772::func;
	return execfunc(this, other);
}

namespace _func773
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Point::Distance", typeid(int (Point::*)(Point )), "55660fefc089e583e4f083ec208b118b41042b55082b450c0fafd20fafc001d0f30f2ac0f30f51c80f2ec97a??f30f2cc1c9", argdata, 2, 1, &func);
}

int Point::Distance(Point other)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func773::func;
	return execfunc(this, other);
}

namespace _func774
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), "f30f10442404f30f1101f30f10442408f30f114104c20800908db426000000005589e583ec04f30f1009f30f104104f30f5c4d08f30f5c450cf30f59c9f30f59c0f30f58c1f30f110424", argdata, 3, 5, &func);
}

void Pointf::constructor(float x, float y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Pointf *this_arg, float x_arg, float y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func774::func;
	return execfunc(this, x, y);
}

namespace _func775
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Pointf::RelativeDistance", typeid(float (Pointf::*)(Pointf )), "5589e583ec04f30f1009f30f104104f30f5c4d08f30f5c450cf30f59c9f30f59c0f30f58c1f30f110424", argdata, 2, 1, &func);
}

float Pointf::RelativeDistance(Pointf other)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(Pointf *this_arg, Pointf other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func775::func;
	return execfunc(this, other);
}

namespace _func776
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Pointf::Normalize", typeid(Pointf (Pointf::*)()), "5589e583e4f083ec20f30f1009f30f104104f30f59c9f30f59c0f30f58c1f30f51c80f2ec9", argdata, 1, 9, &func);
}

Pointf Pointf::Normalize()
{
	typedef Pointf __attribute__((thiscall)) (*custom_arg_funcptr_t)(Pointf *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func776::func;
	return execfunc(this);
}

namespace _func777
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("PowerManager::SetHacked", typeid(void (PowerManager::*)(bool )), "807c24040119c0f7d083e002894120", argdata, 2, 5, &func);
}

void PowerManager::SetHacked(bool val)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(PowerManager *this_arg, bool val_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func777::func;
	return execfunc(this, val);
}

namespace _func778
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("PowerManager::GetPowerManager", typeid(PowerManager *(*)(int )), "8d4c240483e4f0ff71fc5589e5535183ec408b15????????a1????????8b1989d129c1", argdata, 1, 2, &func);
}

PowerManager *PowerManager::GetPowerManager(int iShipId)
{
	typedef PowerManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int iShipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func778::func;
	return execfunc(iShipId);
}

namespace _func779
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Projectile::CollisionCheck", typeid(void (Projectile::*)(Collideable *)), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b378b79348b0689f1ff5028", argdata, 2, 5, &func);
}

void Projectile::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func779::func;
	return execfunc(this, other);
}

namespace _func780
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Projectile::constructor", typeid(void (Projectile::*)(Pointf , int , int , Pointf )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b57048b5f088b4f0cc7460805000000c6460c018985f0feffff8995f4feffff8b47108b5714", argdata, 5, 5, &func);
}

void Projectile::constructor(Pointf position, int ownerId, int targetId, Pointf target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg, Pointf position_arg, int ownerId_arg, int targetId_arg, Pointf target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func780::func;
	return execfunc(this, position, ownerId, targetId, target);
}

namespace _func781
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Projectile::destructor", typeid(void (Projectile::*)()), ".558d915c02000089e5575653", argdata, 1, 5, &func);
}

void Projectile::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func781::func;
	return execfunc(this);
}

namespace _func782
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Projectile::Initialize", typeid(void (Projectile::*)(const WeaponBlueprint &)), "578d7c240883e4f0ff77fc5589e557565331db81ec????????8b07898dbcfeffffc785c8feffff00000000c785ccfeffff00000000c785d0feffff000000008d8824010000", argdata, 2, 5, &func);
}

void Projectile::Initialize(const WeaponBlueprint &bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg, const WeaponBlueprint &bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func782::func;
	return execfunc(this, bp);
}

namespace _func783
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Projectile::ValidTarget", typeid(bool (Projectile::*)()), "!0fb6817002000083f001c3", argdata, 1, 1, &func);
}

bool Projectile::ValidTarget()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func783::func;
	return execfunc(this);
}

namespace _func784
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Projectile::ForceRenderLayer", typeid(int (Projectile::*)()), ".!b8ffffffffc3", argdata, 1, 1, &func);
}

int Projectile::ForceRenderLayer()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func784::func;
	return execfunc(this);
}

namespace _func785
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Projectile::OnUpdate", typeid(void (Projectile::*)()), "80b9b0000000000f85e6000000578d7c240883e4f0ff77fc5589e5575389cb83ec408b41108b51148941188b417039417489511c", argdata, 1, 5, &func);
}

void Projectile::OnUpdate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func785::func;
	return execfunc(this);
}

namespace _func786
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("Projectile::CollisionMoving", typeid(CollisionResponse (Projectile::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83c10483ec2c8b1fc741fc00000000c7442404000000cfc70424000000cf", argdata, 6, 1, &func);
}

CollisionResponse Projectile::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(Projectile *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func786::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func787
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::RandomSidePoint", typeid(Pointf (*)(int )), "8d4c240483e4f0ff71fc5589e5535183ec208b198d4df0c7442404ffffffffc70424ffffffff", argdata, 1, 10, &func);
}

Pointf Projectile::RandomSidePoint(int side)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int side_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func787::func;
	return execfunc(side);
}

namespace _func788
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::constructor", typeid(void (ProjectileFactory::*)(const WeaponBlueprint *, int )), "578d7c240883e4f0ff77fc5589e557565389ce83c12081ec????????8b07c741e800000000", argdata, 3, 5, &func);
}

void ProjectileFactory::constructor(const WeaponBlueprint *bp, int shipId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, const WeaponBlueprint *bp_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func788::func;
	return execfunc(this, bp, shipId);
}

namespace _func789
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(void (ProjectileFactory::*)()), ".5589e55389cb83e4f0803d??????????75??e8????????", argdata, 1, 5, &func);
}

void ProjectileFactory::SelectChargeGoal()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func789::func;
	return execfunc(this);
}

namespace _func790
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::IsChargedGoal", typeid(bool (ProjectileFactory::*)()), ".8b411c8b80d801000085c07e??", argdata, 1, 1, &func);
}

bool ProjectileFactory::IsChargedGoal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func790::func;
	return execfunc(this);
}

namespace _func791
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetHacked", typeid(void (ProjectileFactory::*)(int )), ".5781c1????????8d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

void ProjectileFactory::SetHacked(int hacked)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, int hacked_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func791::func;
	return execfunc(this, hacked);
}

namespace _func792
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCurrentShip", typeid(void (ProjectileFactory::*)(Targetable *)), ".8b44240439814001000074??85c074??c7811c06000000000000", argdata, 2, 5, &func);
}

void ProjectileFactory::SetCurrentShip(Targetable *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, Targetable *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func792::func;
	return execfunc(this, ship);
}

namespace _func793
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), ".f30f1041080f28c8f30f10542404f30f104118", argdata, 2, 5, &func);
}

void ProjectileFactory::SetCooldownModifier(float mod)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float mod_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func793::func;
	return execfunc(this, mod);
}

namespace _func794
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(void (ProjectileFactory::*)()), ".80b9f60000000074??8b411cf30f10410cf30f114108c7812c06000001000000", argdata, 1, 5, &func);
}

void ProjectileFactory::ForceCoolup()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func794::func;
	return execfunc(this);
}

namespace _func795
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(void (ProjectileFactory::*)(float )), ".5781c1????????8d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

void ProjectileFactory::RenderChargeBar(float unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func795::func;
	return execfunc(this, unk);
}

namespace _func796
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??8d65f8", argdata, 1, 2, &func);
}

int ProjectileFactory::StringToWeapon(const std::string &str)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &str_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func796::func;
	return execfunc(str);
}

namespace _func797
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::Fire", typeid(void (ProjectileFactory::*)(std::vector<Pointf> &, int )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b47048b1f8945e4", argdata, 3, 5, &func);
}

void ProjectileFactory::Fire(std::vector<Pointf> &points, int target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, std::vector<Pointf> &points_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func797::func;
	return execfunc(this, points, target);
}

namespace _func798
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::FireNextShot", typeid(bool (ProjectileFactory::*)()), "8b912c06000031c085d27e??0fb681f600000084c074??8b411c8b911801000039900c0100007e??31c0c3908d74260080b9f50000000075??", argdata, 1, 1, &func);
}

bool ProjectileFactory::FireNextShot()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func798::func;
	return execfunc(this);
}

namespace _func799
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SpendMissiles", typeid(int (ProjectileFactory::*)()), "8b811406000085c00f8e????????578d7c240883e4f0ff77fc5589e55756538d7dd08d45cc8d75d889cb83ec3c89f9c745cc14000000c744240400000000", argdata, 1, 1, &func);
}

int ProjectileFactory::SpendMissiles()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func799::func;
	return execfunc(this);
}

namespace _func800
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::OnRender", typeid(void (ProjectileFactory::*)(float , bool )), "578d7c240883e4f0ff77fc5589e557538d994801000083ec20807f0400f30f100774??8d9948010000c70424????????f30f1145f489d9", argdata, 3, 5, &func);
}

void ProjectileFactory::OnRender(float alpha, bool forceVisual)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float alpha_arg, bool forceVisual_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func800::func;
	return execfunc(this, alpha, forceVisual);
}

namespace _func801
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), "8b411c83b8d8010000017e??8b812c06000085c0b8????????0f4f812c060000c38b8134010000", argdata, 1, 1, &func);
}

int ProjectileFactory::NumTargetsRequired()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func801::func;
	return execfunc(this);
}

namespace _func802
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::Update", typeid(void (ProjectileFactory::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????8b912c06000085d20f8e????????0fb681f600000084c08885b4feffff", argdata, 1, 5, &func);
}

void ProjectileFactory::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func802::func;
	return execfunc(this);
}

namespace _func803
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::GetProjectile", typeid(Projectile *(ProjectileFactory::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81c14801000083ec5c", argdata, 1, 1, &func);
}

Projectile *ProjectileFactory::GetProjectile()
{
	typedef Projectile *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func803::func;
	return execfunc(this);
}

namespace _func804
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ClearAiming", typeid(void (ProjectileFactory::*)()), "8b91fc0000008b81000100005329d0c1f80385c07e2a8b591c83bbd8010000017e3e8b992c06000085db", argdata, 1, 5, &func);
}

void ProjectileFactory::ClearAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func804::func;
	return execfunc(this);
}

namespace _func805
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ClearProjectiles", typeid(void (ProjectileFactory::*)()), "8b8100060000898104060000c3", argdata, 1, 5, &func);
}

void ProjectileFactory::ClearProjectiles()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func805::func;
	return execfunc(this);
}

namespace _func806
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::destructor", typeid(void (ProjectileFactory::*)()), "5589e557565389cf83e4f083ec208b8100060000", argdata, 1, 5, &func);
}

void ProjectileFactory::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func806::func;
	return execfunc(this);
}

namespace _func807
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::LoadProjectile", typeid(Projectile *(*)(int )), "8d4c240483e4f0ff71fc5589e556535183ec6c8b19891c24", argdata, 1, 2, &func);
}

Projectile *ProjectileFactory::LoadProjectile(int fd)
{
	typedef Projectile *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func807::func;
	return execfunc(fd);
}

namespace _func808
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveProjectile", typeid(void (*)(Projectile *, int )), "8d4c240483e4f0ff71fc5589e556535183ec1c8b198b71048b0389d9ff507c89342489442404", argdata, 2, 6, &func);
}

void ProjectileFactory::SaveProjectile(Projectile *p, int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *p_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func808::func;
	return execfunc(p, fd);
}

namespace _func809
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveState", typeid(void (ProjectileFactory::*)(int )), ".578d????0883e4f0ff????5589e557565389cb83ec2c8b??31", argdata, 2, 5, &func);
}

void ProjectileFactory::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func809::func;
	return execfunc(this, fd);
}

namespace _func810
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ReactorButton::Accept", typeid(void (ReactorButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b496c85c97e??8d45d08d75d8ba????????b9????????", argdata, 1, 5, &func);
}

void ReactorButton::Accept()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func810::func;
	return execfunc(this);
}

namespace _func811
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ReactorButton::OnClick", typeid(void (ReactorButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4970e8????????03536c83fa180f8f????????807b40000f84????????", argdata, 1, 5, &func);
}

void ReactorButton::OnClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func811::func;
	return execfunc(this);
}

namespace _func812
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ReactorButton::OnRightClick", typeid(void (ReactorButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b496c85c97e??807b410075??", argdata, 1, 5, &func);
}

void ReactorButton::OnRightClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func812::func;
	return execfunc(this);
}

namespace _func813
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ReactorButton::OnRender", typeid(void (ReactorButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????898db4fbffffe8????????807f410074??807f40000f85????????", argdata, 1, 5, &func);
}

void ReactorButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func813::func;
	return execfunc(this);
}

void **VTable_RepairAnimation;

namespace _var814
{
    static VariableDefinition varObj("VTable_RepairAnimation", "894424088d45ccc645da0089442404e8????????8b45cc83ec1439f874??890424e8????????8b4584c700(???????\?)c680ee09000001c7042438090000", &VTable_RepairAnimation);
}

namespace _func815
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("RepairStoreBox::constructor", typeid(void (RepairStoreBox::*)(ShipManager *, bool , int )), "578d7c240883e4f0ff77fc5589e557565389ce8d4dcc81ec????????8b47048b1fc745b014000000898504ffffff8b47088d7dd4c744240400000000", argdata, 4, 5, &func);
}

void RepairStoreBox::constructor(ShipManager *ship, bool repairAll, int price)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(RepairStoreBox *this_arg, ShipManager *ship_arg, bool repairAll_arg, int price_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func815::func;
	return execfunc(this, ship, repairAll, price);
}

namespace _func816
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ResourceControl::constructor", typeid(void (ResourceControl::*)()), "8d4118f30f1005????????c7410401000000c7410800000000f30f11411089018d4134c7410c00000000c7411400000000f30f11412c89411c8d4150c7411800000000c7412001000000f30f1141488941388d4164c7412400000000c741280000000089415c", argdata, 1, 5, &func);
}

void ResourceControl::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func816::func;
	return execfunc(this);
}

namespace _func817
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitive", typeid(GL_Primitive *(ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "5589e583e4f083ec408b45088b552c85c00f84????????660fefe489c185c9f30f104d20f30f106d1cf30f104518f30f2a6514", argdata, 8, 1, &func);
}

GL_Primitive *ResourceControl::CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror)
{
	typedef GL_Primitive *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg, int unk1_arg, int unk2_arg, int unk3_arg, GL_Color color_arg, float alpha_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func817::func;
	return execfunc(this, tex, unk1, unk2, unk3, color, alpha, mirror);
}

namespace _func818
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::OnInit", typeid(void (ResourceControl::*)(int )), ".5589e55389cb", argdata, 2, 5, &func);
}

void ResourceControl::OnInit(int imageSwappingMode)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, int imageSwappingMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func818::func;
	return execfunc(this, imageSwappingMode);
}

namespace _func819
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::LoadFile", typeid(char *(ResourceControl::*)(const std::string &)), "5589e557565389cf31db83e4f083ec408d442430c744240c10000000c744240800000000c744243064617461c74424342e646174894424288b4508", argdata, 2, 1, &func);
}

char *ResourceControl::LoadFile(const std::string &fileName)
{
	typedef char *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func819::func;
	return execfunc(this, fileName);
}

namespace _func820
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::LoadFromResourceFile", typeid(char *(ResourceControl::*)(const std::string &, std::size_t &, const std::string *)), "5589e557565389ce31db83e4f083ec208b45088b7d0cc744240c10000000c7442408000000008b00894424048b81c8000000890424", argdata, 4, 1, &func);
}

char *ResourceControl::LoadFromResourceFile(const std::string &fileName, std::size_t &fileSize, const std::string *unused_resourceFile)
{
	typedef char *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &fileName_arg, std::size_t &fileSize_arg, const std::string *unused_resourceFile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func820::func;
	return execfunc(this, fileName, fileSize, unused_resourceFile);
}

namespace _func821
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(GL_Texture *(ResourceControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ec????????8b1f8b3d????????", argdata, 2, 1, &func);
}

GL_Texture *ResourceControl::GetImageId(const std::string &dir)
{
	typedef GL_Texture *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func821::func;
	return execfunc(this, dir);
}

namespace _func822
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImage", typeid(int (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "5589e583e4f083ec408b45088b552c85c00f84????????660fefd289c185c9f30f104d20f30f106d1cf30f104518", argdata, 8, 1, &func);
}

int ResourceControl::RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func822::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func823
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImageString", typeid(int (ResourceControl::*)(std::string &, int , int , int , GL_Color , float , bool )), "578d7c240883e4f0ff77fc5589e557565383ec5c8b570c8b07f30f1077208b5f048b7708f30f1175d08955d48b5724", argdata, 8, 1, &func);
}

int ResourceControl::RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, std::string &tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func823::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func824
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitiveString", typeid(GL_Primitive *(ResourceControl::*)(const std::string &, int , int , int , GL_Color , float , bool )), ".578d7c240883e4f0ff77fc5589e557565383ec5c8b570c8b07f30f1077208b5f048b7708f30f1175d08955d48b5724890424", argdata, 8, 1, &func);
}

GL_Primitive *ResourceControl::CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)
{
	typedef GL_Primitive *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float alpha_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func824::func;
	return execfunc(this, tex, x, y, rotation, color, alpha, mirror);
}

namespace _func825
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(freetype::font_data &(ResourceControl::*)(int , bool )), "57????????83e4f0ff77fc5589e557565389cb83ec4c8b37897dc08b4f048d46fa83f8020f87????????c70709000000b809000000ba01000000be09000000", argdata, 3, 1, &func);
}

freetype::font_data &ResourceControl::GetFontData(int size, bool ignoreLanguage)
{
	typedef freetype::font_data &__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, int size_arg, bool ignoreLanguage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func825::func;
	return execfunc(this, size, ignoreLanguage);
}

namespace _func826
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageData", typeid(ImageDesc (ResourceControl::*)(GL_Texture *)), "5731d28d7c240883e4f0ff77fc5589f889e557565389ce83ec2c8b0f897dd8", argdata, 3, 1, &func);
}

ImageDesc ResourceControl::GetImageData(GL_Texture *tex)
{
	typedef ImageDesc __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func826::func;
	return execfunc(this, tex);
}

namespace _func827
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::PreloadResources", typeid(bool (ResourceControl::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec1c0200000fb6078885effdffffe8????????8b86cc000000", argdata, 2, 1, &func);
}

bool ResourceControl::PreloadResources(bool unk)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func827::func;
	return execfunc(this, unk);
}

namespace _func828
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderLoadingBar", typeid(void (ResourceControl::*)(float , float )), "578d7c240883e4f0ff77fc5589e557565389ce81ec8c0000008b89d0000000f30f1017f30f104f048d7dd085c9", argdata, 3, 5, &func);
}

void ResourceControl::RenderLoadingBar(float initialProgress, float finalProgress)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, float initialProgress_arg, float finalProgress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func828::func;
	return execfunc(this, initialProgress, finalProgress);
}

namespace _func829
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::ImageExists", typeid(bool (ResourceControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d5dd083ec4c8b378d7dd8894dc489d9c745d400000000897dd0c645d8008b460483c004890424", argdata, 2, 1, &func);
}

bool ResourceControl::ImageExists(const std::string &name)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func829::func;
	return execfunc(this, name);
}

ResourceControl *Global_ResourceControl_GlobalResources;

namespace _var830
{
    static VariableDefinition varObj("Global_ResourceControl_GlobalResources", "!8b45b8890424e8????????b9(???????\?)", &Global_ResourceControl_GlobalResources);
}

namespace _func831
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::constructor", typeid(void (RockAnimation::*)(const std::string &, int , Pointf , bool )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????898de0feffff8b57048b0f8b58108d8520ffffff8b77088b7f0c8995e4feffff898518ffffff", argdata, 5, 5, &func);
}

void RockAnimation::constructor(const std::string &subRace, int iShipId, Pointf position, bool enemy)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(RockAnimation *this_arg, const std::string &subRace_arg, int iShipId_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func831::func;
	return execfunc(this, subRace, iShipId, position, enemy);
}

namespace _func832
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK", typeid(void (RockAnimation::*)()), "5f5d8d67f85fc20400908d742600e8????????89c1e9????????8d7426000f1040080f114308", argdata, 0, 4, &func);
}

namespace _func833
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK2", typeid(void (RockAnimation::*)()), ".5f5d8d67f85fc20400908d742600e8????????89c1e9????????8d7426000f1040080f114308", argdata, 0, 4, &func);
}

namespace _func834
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::GetShootingSound", typeid(std::string (RockAnimation::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c803d??????????0f84????????", argdata, 2, 1, &func);
}

std::string RockAnimation::GetShootingSound()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(RockAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func834::func;
	return execfunc(this);
}

namespace _func835
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK3", typeid(void (RockAnimation::*)()), "578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 0, 4, &func);
}

namespace _func836
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK4", typeid(void (RockAnimation::*)()), ".578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 0, 4, &func);
}

namespace _func837
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::GetDeathSound", typeid(std::string (RockAnimation::*)()), ".578d41088d7c240883e4f0ff77fc5589e5575389cb83ec108901", argdata, 2, 1, &func);
}

std::string RockAnimation::GetDeathSound()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(RockAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func837::func;
	return execfunc(this);
}

namespace _func838
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::GetEmptySlots", typeid(int (Room::*)(bool )), "530fb65424088b41348b49288d1c928d1c988b43082b03c1f802c1e0052b430403430c2b0491", argdata, 2, 1, &func);
}

int Room::GetEmptySlots(bool intruder)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func838::func;
	return execfunc(this, intruder);
}

namespace _func839
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::constructor", typeid(void (Room::*)(int , int , int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b57048b078b7714898d9cfeffffc7410400000000c701????????", argdata, 7, 5, &func);
}

void Room::constructor(int iShipId, int x, int y, int w, int h, int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, int iShipId_arg, int x_arg, int y_arg, int w_arg, int h_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func839::func;
	return execfunc(this, iShipId, x, y, w, h, roomId);
}

namespace _func840
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderFloor", typeid(void (Room::*)(float , bool )), "5589e55383e4f083ec308b517cf30f1005????????f30f5c4178f30f100d????????891424f30f5905????????f30f2cc0660fefc08d1c0005????????f30f2ac0b8????????", argdata, 3, 5, &func);
}

void Room::OnRenderFloor(float alpha, bool experimental)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg, bool experimental_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func840::func;
	return execfunc(this, alpha, experimental);
}

namespace _func841
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderWalls", typeid(void (Room::*)(float )), "8079400074??8079240074??c20400905589e55389cb83e4f083ec108b819c000000f30f105d08f30f115c2404", argdata, 2, 5, &func);
}

void Room::OnRenderWalls(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func841::func;
	return execfunc(this, alpha);
}

namespace _func842
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Room::__DO_NOT_HOOK", typeid(void (Room::*)()), "890424e8????????89742404893c2489c1c744240800000000e8????????89433883ec0c8d65f45b5e5f5d", argdata, 0, 4, &func);
}

namespace _func843
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Room::destructor", typeid(void (Room::*)()), ".5589e557565389ce83e4f083ec20", argdata, 1, 5, &func);
}

void Room::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func843::func;
	return execfunc(this);
}

namespace _func844
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::GetEmptySlot", typeid(int (Room::*)(bool )), "555756538b54241484d275??8b417083f8ff74??8b593489c5be????????c1ed0589c1d3e68b3b8534af75??", argdata, 2, 1, &func);
}

int Room::GetEmptySlot(bool intruder)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func844::func;
	return execfunc(this, intruder);
}

namespace _func845
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::Full", typeid(bool (Room::*)(bool )), "530fb65424088b41348b49288d1c928d1c988b43082b03c1f802c1e0052b430403430c3b04915b0f94c0", argdata, 2, 1, &func);
}

bool Room::Full(bool intruder)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func845::func;
	return execfunc(this, intruder);
}

namespace _func846
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::FillSlot", typeid(void (Room::*)(int , bool )), "565389cb0fb64424108b73348b4c240c8d14850000000001d08d048689cec1ee058b008d34b0b801000000d3e08b0e85c175??03532809c88906830201", argdata, 3, 5, &func);
}

void Room::FillSlot(int slot, bool intruder)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, int slot_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func846::func;
	return execfunc(this, slot, intruder);
}

namespace _func847
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipUnlocked", typeid(bool (ScoreKeeper::*)(int , int )), "5731c08d7c240883e4f0ff77fc5589e557565381ec????????8b5f048b37", argdata, 3, 1, &func);
}

bool ScoreKeeper::GetShipUnlocked(int shipId, int shipVariant)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipId_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func847::func;
	return execfunc(this, shipId, shipVariant);
}

namespace _func848
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipBlueprint", typeid(std::string (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b4704", argdata, 3, 1, &func);
}

std::string ScoreKeeper::GetShipBlueprint(int index)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int index_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func848::func;
	return execfunc(this, index);
}

namespace _func849
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::OnInit", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d75cc8d7dd481ec????????c70424????????e8????????8d45bc", argdata, 1, 5, &func);
}

void ScoreKeeper::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func849::func;
	return execfunc(this);
}

namespace _func850
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Save", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????81ec????????8b37e8????????84c00f85????????8b15????????f30f1005????????", argdata, 2, 5, &func);
}

void ScoreKeeper::Save(bool newHighScore)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool newHighScore_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func850::func;
	return execfunc(this, newHighScore);
}

namespace _func851
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::OnRender", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????80b9c40b0000008b00898528fdffff888530fdffff0f85????????0f2805????????b9????????8db5c0feffff", argdata, 2, 5, &func);
}

void ScoreKeeper::OnRender(bool lastPlaythrough)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool lastPlaythrough_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func851::func;
	return execfunc(this, lastPlaythrough);
}

namespace _func852
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(void (ScoreKeeper::*)(int , int , bool , bool )), "5789c88d7c240883e4f0ff77fc5589e557565383ec5c8b57048b1f8955c48b570885db8b7f0c8955bc", argdata, 5, 5, &func);
}

void ScoreKeeper::UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipType_arg, int shipVariant_arg, bool save_arg, bool hidePopup_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func852::func;
	return execfunc(this, shipType, shipVariant, save, hidePopup);
}

namespace _func853
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetVictory", typeid(void (ScoreKeeper::*)(bool )), "8b44240484c088818802000074??83814802000001c20400", argdata, 2, 5, &func);
}

void ScoreKeeper::SetVictory(bool victory)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool victory_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func853::func;
	return execfunc(this, victory);
}

namespace _func854
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::constructor", typeid(void (ScoreKeeper::*)()), "5789c883c0148d7c240883e4f0ff77fc5589e557565389cf83ec5c89410c89c883c03c894db0c701????????", argdata, 1, 5, &func);
}

void ScoreKeeper::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func854::func;
	return execfunc(this);
}

namespace _func855
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipId", typeid(std::pair<int, int> (ScoreKeeper::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 9, &func);
}

std::pair<int, int> ScoreKeeper::GetShipId(const std::string &blueprintName)
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::string &blueprintName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func855::func;
	return execfunc(this, blueprintName);
}

namespace _func856
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::LoadVersionFour", typeid(void (ScoreKeeper::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????8b4004898d28ffffff8b3f83f808898530ffffff898124130000", argdata, 3, 5, &func);
}

void ScoreKeeper::LoadVersionFour(int file, int version)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int file_arg, int version_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func856::func;
	return execfunc(this, file, version);
}

namespace _func857
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::WipeProfile", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b07894ddcb9????????8945d4e8????????c745e000000000c745e4000000008b4ddc8b75e4", argdata, 2, 5, &func);
}

void ScoreKeeper::WipeProfile(bool permanent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool permanent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func857::func;
	return execfunc(this, permanent);
}

namespace _func858
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::MouseClick", typeid(void (ScoreKeeper::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80b9c40b0000000f85????????0fb6812c06000084c0", argdata, 3, 5, &func);
}

void ScoreKeeper::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func858::func;
	return execfunc(this, x, y);
}

namespace _func859
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetupTopShip", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e55756538d55d889cb83ec5c8b078955d08945b08b81dc0200008981e00200008b81800b0000", argdata, 2, 5, &func);
}

void ScoreKeeper::SetupTopShip(int variant)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func859::func;
	return execfunc(this, variant);
}

namespace _func860
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CheckTypes", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db3cc07000083ec3cc7442404010000008b81800b0000890424", argdata, 1, 5, &func);
}

void ScoreKeeper::CheckTypes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func860::func;
	return execfunc(this);
}

namespace _func861
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreType", typeid(void (ScoreKeeper::*)(TopScore &, int )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????81ec????????8b47048b1f8d7da8c7442404ffffffff", argdata, 3, 5, &func);
}

void ScoreKeeper::AddTopScoreType(TopScore &topScore, int type)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, TopScore &topScore_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func861::func;
	return execfunc(this, topScore, type);
}

namespace _func862
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreList", typeid(int (ScoreKeeper::*)(TopScore &, std::vector<TopScore> &)), "578d7c240883e4f0ff77fc5589e557565383ec7c8b77048b078b5e0489c28945948b0689d929c1", argdata, 3, 1, &func);
}

int ScoreKeeper::AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, TopScore &score_arg, std::vector<TopScore> &topScoreList_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func862::func;
	return execfunc(this, score, topScoreList);
}

namespace _func863
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::RenderTopScores", typeid(void (ScoreKeeper::*)(const std::vector<TopScore> &, Point , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b5f048b078b5708899de4faffff8b5f0c8985f8faffff899dd4faffff", argdata, 4, 5, &func);
}

void ScoreKeeper::RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::vector<TopScore> &topScoreList_arg, Point position_arg, int newHighScore_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func863::func;
	return execfunc(this, topScoreList, position, newHighScore);
}

namespace _func864
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CycleLeft", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cebb????????83ec1c908d7426008b96800b000089f185d2", argdata, 1, 5, &func);
}

void ScoreKeeper::CycleLeft()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func864::func;
	return execfunc(this);
}

namespace _func865
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CycleRight", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389ce31db83ec1c908db426000000008b96800b000089f183fa09", argdata, 1, 5, &func);
}

void ScoreKeeper::CycleRight()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func865::func;
	return execfunc(this);
}

namespace _func866
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Open", typeid(void (ScoreKeeper::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389ce83c10c", argdata, 2, 5, &func);
}

void ScoreKeeper::Open(bool fromGameOver)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool fromGameOver_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func866::func;
	return execfunc(this, fromGameOver);
}

namespace _func867
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::KeyDown", typeid(bool (ScoreKeeper::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c0fb681c40b00008b3784c0", argdata, 2, 1, &func);
}

bool ScoreKeeper::KeyDown(SDLKey key)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func867::func;
	return execfunc(this, key);
}

namespace _func868
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddScrapCollected", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec3c8b37e8????????84c0", argdata, 2, 5, &func);
}

void ScoreKeeper::AddScrapCollected(int scrap)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int scrap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func868::func;
	return execfunc(this, scrap);
}

namespace _func869
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SaveScores", typeid(void (ScoreKeeper::*)(int , std::vector<TopScore> &)), "578d7c240883e4f0ff77fc5589f889e557565383ec7c8b40048b3f8b1889458c", argdata, 3, 5, &func);
}

void ScoreKeeper::SaveScores(int file, std::vector<TopScore> &topScores)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int file_arg, std::vector<TopScore> &topScores_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func869::func;
	return execfunc(this, file, topScores);
}

namespace _func870
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SaveGame", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1fa1????????8d7e0889442404891c24", argdata, 2, 5, &func);
}

void ScoreKeeper::SaveGame(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func870::func;
	return execfunc(this, fd);
}

namespace _func871
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::LoadGame", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b3f894dc4893c24", argdata, 2, 5, &func);
}

void ScoreKeeper::LoadGame(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func871::func;
	return execfunc(this, fd);
}

namespace _func872
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::MouseMove", typeid(void (ScoreKeeper::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec2c80b9c40b0000008b40048b3f8945e4", argdata, 3, 5, &func);
}

void ScoreKeeper::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func872::func;
	return execfunc(this, mX, mY);
}

namespace _func873
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetSector", typeid(void (ScoreKeeper::*)(int )), "8b442404c7412400000000c7414c00000000c7417400000000c7819c00000000000000898180020000", argdata, 2, 5, &func);
}

void ScoreKeeper::SetSector(int sector)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func873::func;
	return execfunc(this, sector);
}

ScoreKeeper *Global_ScoreKeeper_Keeper;

namespace _var874
{
    static VariableDefinition varObj("Global_ScoreKeeper_Keeper", "!8b430cb9(???????\?)c6804412000000c7042401000000", &Global_ScoreKeeper_Keeper);
}

namespace _func875
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(char (*)()), "0fb605????????c3908db426000000005589e583e4f083ec100fb605????????c70424????????83f001a2????????", argdata, 0, 0, &func);
}

char Settings::GetCommandConsole()
{
	typedef char __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func875::func;
	return execfunc();
}

namespace _func876
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetDlcEnabled", typeid(bool (*)()), "0fb605????????84c075??c38d74260055b9????????89e583e4f0e8????????", argdata, 0, 0, &func);
}

bool Settings::GetDlcEnabled()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func876::func;
	return execfunc();
}

namespace _func877
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkeyName", typeid(std::string (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d75cc8d7dd483ec788b01", argdata, 2, 2, &func);
}

std::string Settings::GetHotkeyName(const std::string &name)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func877::func;
	return execfunc(name);
}

namespace _func878
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkey", typeid(SDLKey (*)(const std::string &)), ".5589e557565383e4f0", argdata, 1, 2, &func);
}

SDLKey Settings::GetHotkey(const std::string &hotkeyName)
{
	typedef SDLKey __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func878::func;
	return execfunc(hotkeyName);
}

namespace _func879
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Settings::SetHotkey", typeid(void (*)(const std::string &, SDLKey )), ".8d4c240483e4f0ff71fc5589e5575653", argdata, 2, 6, &func);
}

void Settings::SetHotkey(const std::string &hotkeyName, SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func879::func;
	return execfunc(hotkeyName, key);
}

namespace _func880
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::SaveSettings", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 0, 6, &func);
}

void Settings::SaveSettings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func880::func;
	return execfunc();
}

namespace _func881
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::ResetHotkeys", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e557565351be????????83ec688b465c8b5e6039d88945a489c774??90", argdata, 0, 6, &func);
}

void Settings::ResetHotkeys()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func881::func;
	return execfunc();
}

namespace _func882
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::LoadSettings", typeid(void (*)()), ".8d4c240483e4f0ff71fc5589e5575653518d9d24ffffff81ec????????e8????????8d8d60ffffffe8????????a1????????c645d400", argdata, 0, 6, &func);
}

void Settings::LoadSettings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func882::func;
	return execfunc();
}

SettingValues *Global_Settings_Settings;

namespace _var883
{
    static VariableDefinition varObj("Global_Settings_Settings", "!5756535183ec588b01c745a8(???????\?)", &Global_Settings_Settings);
}

namespace _func884
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("Shields::CollisionReal", typeid(CollisionResponse (Shields::*)(float , float , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83c10481ec????????8b47408b1ff30f105f04c741fc00000000f30f105708", argdata, 6, 1, &func);
}

CollisionResponse Shields::CollisionReal(float x, float y, Damage damage, bool force)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, float x_arg, float y_arg, Damage damage_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func884::func;
	return execfunc(this, x, y, damage, force);
}

namespace _func885
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Shields::constructor", typeid(void (Shields::*)(int , int , int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b57048b078b4f088b770cc70424????????8954240889442404894c240c89d9", argdata, 5, 5, &func);
}

void Shields::constructor(int roomId, int shipId, int startingPower, const std::string &shieldFile)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, int roomId_arg, int shipId_arg, int startingPower_arg, const std::string &shieldFile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func885::func;
	return execfunc(this, roomId, shipId, startingPower, shieldFile);
}

namespace _func886
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("Shields::SetBaseEllipse", typeid(void (Shields::*)(Globals::Ellipse )), "5589e5f30f104d108b4508f30f1045148b550cf30f1181d8010000f30f5ec1f30f1189d40100008981cc0100008991d00100005df30f1181c0010000", argdata, 2, 5, &func);
}

void Shields::SetBaseEllipse(Globals::Ellipse ellipse)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, Globals::Ellipse ellipse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func886::func;
	return execfunc(this, ellipse);
}

namespace _func887
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Shields::SetHackingLevel", typeid(void (Shields::*)(int )), "538b44????83f8017e??83b9a801000001", argdata, 2, 5, &func);
}

void Shields::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func887::func;
	return execfunc(this, hackingLevel);
}

namespace _func888
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Shields::InstantCharge", typeid(void (Shields::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db33802000083ec3ce8????????89c289f1c70424????????c1ea1f01d0d1f8", argdata, 1, 5, &func);
}

void Shields::InstantCharge()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func888::func;
	return execfunc(this);
}

namespace _func889
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Shields::Jump", typeid(void (Shields::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d7dd883ec3ce8????????f30f1015????????8b83040200000f28ca8d4b08f30f108314020000897dd0", argdata, 1, 5, &func);
}

void Shields::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func889::func;
	return execfunc(this);
}

namespace _func890
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Shields::OnLoop", typeid(void (Shields::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d7dd083ec4ce8????????8d45d8893c24c745d8454e4552c745dc47595f53c745e04849454c8945d0", argdata, 1, 5, &func);
}

void Shields::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func890::func;
	return execfunc(this);
}

namespace _func891
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Shields::AddSuperShield", typeid(void (Shields::*)(Point )), "57ba????????8d7c240883e4f0ff77fc5589e557565383ec1c8b81f40100008b378b7f0483c001", argdata, 2, 5, &func);
}

void Shields::AddSuperShield(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func891::func;
	return execfunc(this, pos);
}

namespace _func892
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Shields::RenderBase", typeid(void (Shields::*)(float , float )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b81ec010000f30f103ff30f117dc485c0f30f105f040f85????????8b410c", argdata, 3, 5, &func);
}

void Shields::RenderBase(float alpha, float superShieldOverwrite)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, float alpha_arg, float superShieldOverwrite_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func892::func;
	return execfunc(this, alpha, superShieldOverwrite);
}

namespace _func893
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("Shields::CollisionTest", typeid(CollisionResponse (Shields::*)(float , float , Damage )), "578d7c240883e4f0ff77fc5589e557565389cb83c10483ec2c8b37c741fc00000000f30f106704", argdata, 5, 1, &func);
}

CollisionResponse Shields::CollisionTest(float x, float y, Damage damage)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, float x_arg, float y_arg, Damage damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func893::func;
	return execfunc(this, x, y, damage);
}

GL_Color *Global_COLOR_GREEN;

namespace _var894
{
    static VariableDefinition varObj("Global_COLOR_GREEN", "!f30f1015(???????\?)f30f5ee6", &Global_COLOR_GREEN);
}

namespace _func895
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetSelectedRoomId", typeid(int (Ship::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b41048b57048b378b5f08", argdata, 4, 1, &func);
}

int Ship::GetSelectedRoomId(int x, int y, bool unk)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int x_arg, int y_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func895::func;
	return execfunc(this, x, y, unk);
}

namespace _func896
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Ship::LockdownRoom", typeid(void (Ship::*)(int , Pointf )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b570889c68985d0feffff8b47048995ccfeffff8985c8feffff8b4104890424", argdata, 3, 5, &func);
}

void Ship::LockdownRoom(int roomId, Pointf pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, Pointf pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func896::func;
	return execfunc(this, roomId, pos);
}

namespace _func897
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::RoomLocked", typeid(bool (Ship::*)(int )), "538b81bc0300008b89c00300008b5c240829c1c1f90469c9????????85c974??3b98ec00000074??05????????31d2eb??05????????3b9810ffffff", argdata, 2, 1, &func);
}

bool Ship::RoomLocked(int roomId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func897::func;
	return execfunc(this, roomId);
}

namespace _func898
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::DestroyedDone", typeid(bool (Ship::*)()), "0fb681f001000084c0", argdata, 1, 1, &func);
}

bool Ship::DestroyedDone()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func898::func;
	return execfunc(this);
}

namespace _func899
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::FullRoom", typeid(bool (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b59088b410c8b178b770429d8", argdata, 3, 1, &func);
}

bool Ship::FullRoom(int roomId, bool intruder)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func899::func;
	return execfunc(this, roomId, intruder);
}

namespace _func900
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::EmptySlots", typeid(int (Ship::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec1c8b008b51088b0c828d1c85????????8b5134", argdata, 2, 1, &func);
}

int Ship::EmptySlots(int roomId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func900::func;
	return execfunc(this, roomId);
}

namespace _func901
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetAvailableRoomSlot", typeid(int (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e55783ec148b178b41088b0c900fb64704", argdata, 3, 1, &func);
}

int Ship::GetAvailableRoomSlot(int roomId, bool intruder)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func901::func;
	return execfunc(this, roomId, intruder);
}

namespace _func902
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::OnRenderBreaches", typeid(void (Ship::*)()), "8b51208b412429d0c1f80285c074??5589e557565389ce31db83e4f0eb??66908b462483c301", argdata, 1, 5, &func);
}

void Ship::OnRenderBreaches()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func902::func;
	return execfunc(this);
}

namespace _func903
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderWalls", typeid(void (Ship::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c0fb6078b770431ff8845cc8b410c2b4108c1f80285c075??e9????????8b43088b0cb8f30f110424", argdata, 3, 5, &func);
}

void Ship::OnRenderWalls(bool forceView, bool doorControlMode)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, bool forceView_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func903::func;
	return execfunc(this, forceView, doorControlMode);
}

namespace _func904
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnInit", typeid(void (Ship::*)(ShipBlueprint &)), "57b8????????8d7c240883e4f0ff77fc5589e5575653e8????????29c48b0789cb8db5a4fffeff898544fefeffa1????????85c00f84????????8b3d????????85ff", argdata, 2, 5, &func);
}

void Ship::OnInit(ShipBlueprint &bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, ShipBlueprint &bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func904::func;
	return execfunc(this, bp);
}

namespace _func905
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::OnRenderSparks", typeid(void (Ship::*)()), "8b51088b410c29d0c1f80285c074??5589e5565389ce31db83e4f0908d7426008b0c9a83c301", argdata, 1, 5, &func);
}

void Ship::OnRenderSparks()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func905::func;
	return execfunc(this);
}

namespace _func906
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::SetRoomBlackout", typeid(void (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e55783ec148b178b41088b0c900fb64704890424e8????????8b7dfc", argdata, 3, 5, &func);
}

void Ship::SetRoomBlackout(int roomId, bool blackout)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool blackout_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func906::func;
	return execfunc(this, roomId, blackout);
}

namespace _func907
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderBase", typeid(void (Ship::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec5c8b008945d08b4104890424e8????????", argdata, 2, 5, &func);
}

void Ship::OnRenderBase(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func907::func;
	return execfunc(this, unk);
}

namespace _func908
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderFloor", typeid(void (Ship::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c80b9b803000000", argdata, 2, 5, &func);
}

void Ship::OnRenderFloor(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func908::func;
	return execfunc(this, unk);
}

namespace _func909
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderJump", typeid(void (Ship::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b4104f30f1027f30f1165d4890424", argdata, 2, 5, &func);
}

void Ship::OnRenderJump(float progress)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func909::func;
	return execfunc(this, progress);
}

namespace _func910
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetBaseEllipse", typeid(Globals::Ellipse (Ship::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1f8b83f401000089018b83f80100008941048b83fc0100008941088b830002000089410c", argdata, 2, 1, &func);
}

Globals::Ellipse Ship::GetBaseEllipse()
{
	typedef Globals::Ellipse __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func910::func;
	return execfunc(this);
}

namespace _func911
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::SetSelectedRoom", typeid(void (Ship::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b378b790c8b4108894de489fa29c2c1fa02", argdata, 2, 5, &func);
}

void Ship::SetSelectedRoom(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func911::func;
	return execfunc(this, roomId);
}

namespace _func912
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnLoop", typeid(void (Ship::*)(std::vector<float> &)), "578d7c240883e4f0ff77fc5589e557568db19c0300005381ec????????894dac8b1f89cf89f1e8????????80bfae0300000074??c70424????????", argdata, 2, 5, &func);
}

void Ship::OnLoop(std::vector<float> &oxygenLevels)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, std::vector<float> &oxygenLevels_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func912::func;
	return execfunc(this, oxygenLevels);
}

namespace _func913
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::BreachRandomHull", typeid(void (Ship::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec5c8b51208b41248b3fc745c400000000c745c800000000c745cc0000000029d0", argdata, 2, 5, &func);
}

void Ship::BreachRandomHull(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func913::func;
	return execfunc(this, roomId);
}

namespace _func914
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::BreachSpecificHull", typeid(bool (Ship::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565331db89ce83ec4c8b078b51208945c48b47048945c08b4124", argdata, 3, 1, &func);
}

bool Ship::BreachSpecificHull(int grid_x, int grid_y)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int grid_x_arg, int grid_y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func914::func;
	return execfunc(this, grid_x, grid_y);
}

namespace _func915
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetAvailableRoom", typeid(int (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b0789c68945c08b470483feff8845b8", argdata, 3, 1, &func);
}

int Ship::GetAvailableRoom(int preferred, bool intruder)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int preferred_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func915::func;
	return execfunc(this, preferred, intruder);
}

namespace _func916
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetHullBreaches", typeid(std::vector<Repairable*> (Ship::*)(bool )), "5589e557565383e4f083ec300fb6450c8b7d08c70100000000c7410400000000c7410800000000894c242c", argdata, 3, 1, &func);
}

std::vector<Repairable*> Ship::GetHullBreaches(bool onlyDamaged)
{
	typedef std::vector<Repairable*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, bool onlyDamaged_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func916::func;
	return execfunc(this, onlyDamaged);
}

namespace _noop917
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_0", "!1ef7ffff(c6841d5afefeff01)");
}

namespace _noop918
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_1", "!89ca7d08(c6841d58fefeff01)");
}

namespace _noop919
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_2", "!89c87ddf(c6841d56fefeff01)");
}

namespace _noop920
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_3", "!89c87d08(c6841d54fefeff01)");
}

namespace _func921
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::constructor", typeid(void (ShipAI::*)(bool )), "5589e556538b750889cbc741040000000083e4f083c108e8????????8d4b74e8????????89f0c683a900000000", argdata, 2, 5, &func);
}

void ShipAI::constructor(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func921::func;
	return execfunc(this, unk);
}

namespace _func922
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), ".8b44240484c074??80b9ec0000000075??c781f0000000000000008881ec000000", argdata, 2, 5, &func);
}

void ShipAI::SetStalemate(bool stalemate)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool stalemate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func922::func;
	return execfunc(this, stalemate);
}

namespace _func923
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::OnLoop", typeid(void (ShipAI::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b3789f084c08b010f84????????8bb8cc000000", argdata, 2, 5, &func);
}

void ShipAI::OnLoop(bool hostile)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func923::func;
	return execfunc(this, hostile);
}

namespace _func924
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipAI::GetTeleportCommand", typeid(std::pair<int, int> (ShipAI::*)()), "8b410485c00f84????????8b0185c00f84????????578d7c240883e4f0ff77fc5589e5575389cb89c1", argdata, 1, 9, &func);
}

std::pair<int, int> ShipAI::GetTeleportCommand()
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func924::func;
	return execfunc(this);
}

namespace _func925
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBlueprint::destructor", typeid(void (ShipBlueprint::*)()), "578d91f80200008d7c240883e4f0ff77fc5589e557565389cb83ec1c8b81f0020000c701????????39d074??890424", argdata, 1, 5, &func);
}

void ShipBlueprint::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func925::func;
	return execfunc(this);
}

namespace _func926
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db32c0a000083ec3cc7442404010000008b8124110000b9????????890424e8????????83ec0884c00f85????????c70424????????89f1e8????????c6834a0a000000", argdata, 1, 5, &func);
}

void ShipBuilder::CheckTypes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func926::func;
	return execfunc(this);
}

namespace _func927
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseClick", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c80b9bc190000008b07", argdata, 3, 5, &func);
}

void ShipBuilder::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func927::func;
	return execfunc(this, x, y);
}

namespace _func928
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b178b7f0489b9001c0000", argdata, 3, 5, &func);
}

void ShipBuilder::SwitchShip(int shipType, int shipVariant)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int shipType_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func928::func;
	return execfunc(this, shipType, shipVariant);
}

namespace _func929
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CreateEquipmentBoxes", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8bb94c0f00008b91480f000089f829d0c1f802", argdata, 1, 5, &func);
}

void ShipBuilder::CreateEquipmentBoxes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func929::func;
	return execfunc(this);
}

namespace _func930
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CreateSystemBoxes", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8bb9941000008b919010000089f829d0c1f802", argdata, 1, 5, &func);
}

void ShipBuilder::CreateSystemBoxes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func930::func;
	return execfunc(this);
}

namespace _func931
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::SetupShipAchievements", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b816c1c0000c781781c0000ffffffff8981701c0000", argdata, 1, 5, &func);
}

void ShipBuilder::SetupShipAchievements()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func931::func;
	return execfunc(this);
}

namespace _func932
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::ClearShipAchievements", typeid(void (ShipBuilder::*)()), "8b816c1c0000c781781c0000ffffffff8981701c0000c390908db426000000005589e5575653", argdata, 1, 5, &func);
}

void ShipBuilder::ClearShipAchievements()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func932::func;
	return execfunc(this);
}

namespace _func933
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(void (ShipBuilder::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b098b3785c9", argdata, 2, 5, &func);
}

void ShipBuilder::SwapType(int variant)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func933::func;
	return execfunc(this, variant);
}

namespace _func934
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipNext", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b0985c974??", argdata, 1, 5, &func);
}

void ShipBuilder::CycleShipNext()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func934::func;
	return execfunc(this);
}

namespace _func935
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipPrevious", typeid(void (ShipBuilder::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b0985c974??", argdata, 1, 5, &func);
}

void ShipBuilder::CycleShipPrevious()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func935::func;
	return execfunc(this);
}

namespace _func936
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565381ec????????898d38fbffff", argdata, 1, 5, &func);
}

void ShipBuilder::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func936::func;
	return execfunc(this);
}

namespace _func937
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::OnRender", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????80b960120000000f85????????e8????????8b831c0f00008d7dd0", argdata, 1, 5, &func);
}

void ShipBuilder::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func937::func;
	return execfunc(this);
}

namespace _func938
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::OnLoop", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????81ec????????e8????????84c0", argdata, 1, 5, &func);
}

void ShipBuilder::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func938::func;
	return execfunc(this);
}

namespace _func939
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::constructor", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83c10c8d7dd08d75d883ec3cc741f800000000c741fc00000000", argdata, 1, 5, &func);
}

void ShipBuilder::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func939::func;
	return execfunc(this);
}

namespace _func940
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseMove", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b308b4004898570feffff8d81540f000089b574feffff", argdata, 3, 5, &func);
}

void ShipBuilder::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func940::func;
	return execfunc(this, x, y);
}

namespace _func941
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::OnKeyDown", typeid(void (ShipBuilder::*)(SDLKey )), "5789c88d7c240883e4f0ff77fc5589e557565383ec2c80b96012000000894de4", argdata, 2, 5, &func);
}

void ShipBuilder::OnKeyDown(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func941::func;
	return execfunc(this, key);
}

namespace _func942
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipButton::constructor", typeid(void (ShipButton::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b0789c389857cfdffff8b4704898580fdffffe8????????", argdata, 3, 5, &func);
}

void ShipButton::constructor(int shipType, int shipVariant)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipButton *this_arg, int shipType_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func942::func;
	return execfunc(this, shipType, shipVariant);
}

namespace _func943
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipButton::OnInit", typeid(void (ShipButton::*)(const std::string &, Point )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10807b70008b17", argdata, 3, 5, &func);
}

void ShipButton::OnInit(const std::string &imgName, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipButton *this_arg, const std::string &imgName_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func943::func;
	return execfunc(this, imgName, pos);
}

namespace _func944
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipButton::MouseMove", typeid(void (ShipButton::*)(int , int )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c807970008b108b4004", argdata, 3, 5, &func);
}

void ShipButton::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipButton *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func944::func;
	return execfunc(this, x, y);
}

namespace _func945
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipButton::OnRender", typeid(void (ShipButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8079700075??807972000f84????????", argdata, 1, 5, &func);
}

void ShipButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func945::func;
	return execfunc(this);
}

namespace _func946
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipEvent::constructor", typeid(void (ShipEvent::*)(const ShipEvent &)), "578d7c240883e4f0ff77fc5589f889e557565389cf83c10483ec2c8b100fb6028b5a088955e48841fc", argdata, 2, 5, &func);
}

void ShipEvent::constructor(const ShipEvent &event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipEvent *this_arg, const ShipEvent &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func946::func;
	return execfunc(this, event);
}

namespace _func947
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::CreateShip", typeid(ShipManager *(*)(const std::string &, int , ShipEvent &)), "8d4c240483e4f0ff71fc5589e55756535131db81ec????????8b01c7850cfbffff00000000c78510fbffff00000000c78514fbffff000000008985f0faffff8b4104898500fbffff8b4108", argdata, 3, 2, &func);
}

ShipManager *ShipGenerator::CreateShip(const std::string &name, int sector, ShipEvent &event)
{
	typedef ShipManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg, int sector_arg, ShipEvent &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func947::func;
	return execfunc(name, sector, event);
}

namespace _func948
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GenerateSystemMaxes", typeid(std::vector<int> (*)(const ShipBlueprint &, int )), "8d4c240483e4f0ff71fc5589e55756535183ec488b018b79048b59088945d4c70000000000c7400400000000c7400800000000", argdata, 3, 2, &func);
}

std::vector<int> ShipGenerator::GenerateSystemMaxes(const ShipBlueprint &ship, int level)
{
	typedef std::vector<int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(const ShipBlueprint &ship_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func948::func;
	return execfunc(ship, level);
}

namespace _func949
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::UpgradeSystem", typeid(bool (*)(ShipManager *, std::vector<int> &, unsigned int )), "8d4c240483e4f0ff71fc5589e55756535183ec388b41088b318b790489042489f18945e4", argdata, 3, 2, &func);
}

bool ShipGenerator::UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, unsigned int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func949::func;
	return execfunc(ship, systemMaxes, sysId);
}

namespace _func950
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "8d4c240483e4f0ff71fc5589e55756535183ec688b018b71048b7910c745c8000000008945c08975b8c70000000000c7400400000000c74008000000008b710831c0897dbc", argdata, 5, 2, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func950::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func951
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades0", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8945c0c70000000000c7400400000000c740080000000031c08955bcc745c8000000008db42600000000", argdata, 5, 2, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades0(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func951::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func952
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades1", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8945c0c70000000000c7400400000000c740080000000031c08955bcc745c800000000eb1c", argdata, 5, 2, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades1(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func952::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func953
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades2", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8945c0c70000000000c7400400000000c740080000000031c08955bcc745c800000000eb1f", argdata, 5, 2, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades2(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func953::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func954
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleWeaponList", typeid(std::vector<WeaponBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int )), "8d4c240483e4f0ff71fc5589c889e55756535181ec880000008b198b78088b49048b4010895da0897d9489459c", argdata, 5, 2, &func);
}

std::vector<WeaponBlueprint*> ShipGenerator::GetPossibleWeaponList(ShipManager *ship, const std::string &weaponList, int scrap, unsigned int flags)
{
	typedef std::vector<WeaponBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &weaponList_arg, int scrap_arg, unsigned int flags_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func954::func;
	return execfunc(ship, weaponList, scrap, flags);
}

namespace _func955
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleDroneList", typeid(std::vector<DroneBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int , bool )), "8d4c240483e4f0ff71fc5589e55756535181ec880000008b0189c78945988b410489c68945a08b41088945908b411089458c0fb6411489f188459f", argdata, 6, 2, &func);
}

std::vector<DroneBlueprint*> ShipGenerator::GetPossibleDroneList(ShipManager *ship, const std::string &droneList, int scrap, unsigned int flags, bool repeat)
{
	typedef std::vector<DroneBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &droneList_arg, int scrap_arg, unsigned int flags_arg, bool repeat_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func955::func;
	return execfunc(ship, droneList, scrap, flags, repeat);
}

namespace _func956
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleCrewList", typeid(std::vector<CrewBlueprint> (*)(ShipManager *, const std::string &, unsigned int )), "8d4c240483e4f0ff71fc5589c889e55756535181eca80100008b398b49048b5808c70700000000c7470400000000c747080000000089bd60feffff", argdata, 4, 2, &func);
}

std::vector<CrewBlueprint> ShipGenerator::GetPossibleCrewList(ShipManager *ship, const std::string &crewList, unsigned int flags)
{
	typedef std::vector<CrewBlueprint> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &crewList_arg, unsigned int flags_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func956::func;
	return execfunc(ship, crewList, flags);
}

namespace _func957
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetShipInfo", typeid(ShipGraph *(*)(int )), "8d4c240483e4f0ff71fc5589e55756535181ec????????a1????????8b15????????8b1929c2", argdata, 1, 2, &func);
}

ShipGraph *ShipGraph::GetShipInfo(int shipId)
{
	typedef ShipGraph *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func957::func;
	return execfunc(shipId);
}

namespace _func958
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotRenderPosition_DO_NOT_USE_DIRECTLY", typeid(__int64 (ShipGraph::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b188b70048b40088945c08b01", argdata, 4, 9, &func);
}

FUNC_NAKED __int64 ShipGraph::GetSlotRenderPosition_DO_NOT_USE_DIRECTLY(int slotId, int roomId, bool intruder)
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
		"pushl 16(%%ebp)\n\t"		// intruder
		"pushl 12(%%ebp)\n\t"		// roomId
		"pushl 8(%%ebp)\n\t"		// slotId
			// ecx has this
		"call *%0\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret $12\n\t"
		 :: "m"(_func958::func)
	);
}

namespace _func959
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), ".538b411c8b59188b54240829d8c1f80239c27d??85d278??8b04935bc20400", argdata, 2, 1, &func);
}

int ShipGraph::DoorCount(int roomId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func959::func;
	return execfunc(this, roomId);
}

namespace _func960
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(std::vector<Door*> (ShipGraph::*)(int )), ".578d7c240883e4f0ff77fc5589e557565383ec3c8b37c701????????c7410400000000", argdata, 3, 1, &func);
}

std::vector<Door*> ShipGraph::GetDoors(int roomId)
{
	typedef std::vector<Door*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func960::func;
	return execfunc(this, roomId);
}

namespace _func961
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::IsRoomConnected", typeid(bool (ShipGraph::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b1f8b7704bf????????", argdata, 3, 1, &func);
}

bool ShipGraph::IsRoomConnected(int room1, int room2)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room1_arg, int room2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func961::func;
	return execfunc(this, room1, room2);
}

namespace _func962
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(int , int , int , int )), ".578d7c240883e4f0ff77fc5589f889e557565389cb8d4de083ec5c8b378b7f048b50088b400c", argdata, 5, 1, &func);
}

Door *ShipGraph::ConnectingDoor(int x1, int y1, int x2, int y2)
{
	typedef Door *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x1_arg, int y1_arg, int x2_arg, int y2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func962::func;
	return execfunc(this, x1, y1, x2, y2);
}

namespace _func963
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(int , int , int , int )), ".578d7c240883e4f0ff77fc5589e557565389ce8d4de083ec6c8b078b5f0889c28945a88b47048b7f0c", argdata, 5, 1, &func);
}

int ShipGraph::ConnectedGridSquares(int x1, int y1, int x2, int y2)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x1_arg, int y1_arg, int x2_arg, int y2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func963::func;
	return execfunc(this, x1, y1, x2, y2);
}

namespace _func964
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquaresPoint", typeid(int (ShipGraph::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575383ec108b5f088b078b5704", argdata, 3, 1, &func);
}

int ShipGraph::ConnectedGridSquaresPoint(Point p1, Point p2)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func964::func;
	return execfunc(this, p1, p2);
}

namespace _func965
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575383ec108b5f088b078b57048b7f0c895c2408890424", argdata, 3, 1, &func);
}

Door *ShipGraph::ConnectingDoor(Point p1, Point p2)
{
	typedef Door *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func965::func;
	return execfunc(this, p1, p2);
}

namespace _func966
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), ".8b5424048b018b04908b50348b421c2b4214c1f802c1e005", argdata, 2, 1, &func);
}

int ShipGraph::GetNumSlots(int room)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func966::func;
	return execfunc(this, room);
}

namespace _func967
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::PopClosestDoor", typeid(int (ShipGraph::*)(std::vector<int> &, std::vector<float> &)), ".5589e557565383e4f083ec208b45088b388b450c8b0f8b0089442418f30f2c14888b45088b400489442410", argdata, 3, 1, &func);
}

int ShipGraph::PopClosestDoor(std::vector<int> &doors, std::vector<float> &distances)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, std::vector<int> &doors_arg, std::vector<float> &distances_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func967::func;
	return execfunc(this, doors, distances);
}

namespace _func968
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::Dijkstra", typeid(Path (ShipGraph::*)(Point , Point , int )), ".578d7c240883e4f0ff77fc5589f889e557565381ec????????89bd70ffffff8b3f898d74ffffff8b5804", argdata, 5, 1, &func);
}

Path ShipGraph::Dijkstra(Point start, Point goal, int shipId)
{
	typedef Path __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point start_arg, Point goal_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func968::func;
	return execfunc(this, start, goal, shipId);
}

namespace _func969
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(Path (ShipGraph::*)(Point , Point , int )), ".578d7c240883e4f0ff77fc5589f889e557565383ec6c8b500c", argdata, 5, 1, &func);
}

Path ShipGraph::FindPath(Point p1, Point p2, int shipId)
{
	typedef Path __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func969::func;
	return execfunc(this, p1, p2, shipId);
}

namespace _func970
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldAngle", typeid(float (ShipGraph::*)(float )), ".83ec04f30f10442408f30f584134f30f110424d9042483c404", argdata, 2, 1, &func);
}

float ShipGraph::ConvertToWorldAngle(float ang)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, float ang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func970::func;
	return execfunc(this, ang);
}

namespace _func971
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalAngle", typeid(float (ShipGraph::*)(float )), ".83ec04f30f10442408f30f5c4134f30f110424d90424", argdata, 2, 1, &func);
}

float ShipGraph::ConvertToLocalAngle(float ang)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, float ang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func971::func;
	return execfunc(this, ang);
}

namespace _func972
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldPosition_DO_NOT_USE_DIRECTLY", typeid(__int64 (ShipGraph::*)(Pointf )), ".57660feff6660fefff8d7c240883e4f0ff77fc5589e5575389cb83ec20f30f2a7124f30f2a7928660f7ef2660f7ef8", argdata, 2, 9, &func);
}

FUNC_NAKED __int64 ShipGraph::ConvertToWorldPosition_DO_NOT_USE_DIRECTLY(Pointf local)
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
		"pushl 12(%%ebp)\n\t"		// local
		"pushl 8(%%ebp)\n\t"		// local
			// ecx has this
		"call *%0\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret $8\n\t"
		 :: "m"(_func972::func)
	);
}

namespace _func973
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalPosition_DO_NOT_USE_DIRECTLY", typeid(__int64 (ShipGraph::*)(Pointf , bool )), ".578d7c240883e4f0ff77fc5589e55783ec14807f0800f30f10692cf30f105930f30f10613474??", argdata, 3, 9, &func);
}

FUNC_NAKED __int64 ShipGraph::ConvertToLocalPosition_DO_NOT_USE_DIRECTLY(Pointf world, bool past)
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
		"pushl 16(%%ebp)\n\t"		// past
		"pushl 12(%%ebp)\n\t"		// world
		"pushl 8(%%ebp)\n\t"		// world
			// ecx has this
		"call *%0\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret $12\n\t"
		 :: "m"(_func973::func)
	);
}

namespace _func974
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(void (ShipGraph::*)()), ".578d7c240883e4f0ff77fc5589e557565383ec4c8b79048b01", argdata, 1, 5, &func);
}

void ShipGraph::ComputeCenter()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func974::func;
	return execfunc(this);
}

namespace _func975
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ContainsPoint", typeid(bool (ShipGraph::*)(int , int )), ".538b514431c08b5c240839da7f??03514c39d37f??", argdata, 3, 1, &func);
}

bool ShipGraph::ContainsPoint(int x, int y)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func975::func;
	return execfunc(this, x, y);
}

namespace _func976
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), ".578d7c240883e4f0ff77fc5589e557565389fb89ce83ec2c8b43040fb6530831db", argdata, 4, 1, &func);
}

int ShipGraph::GetSelectedRoom(int x, int y, bool unk)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func976::func;
	return execfunc(this, x, y, unk);
}

namespace _func977
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), ".8b41042b01c1f802", argdata, 1, 1, &func);
}

int ShipGraph::RoomCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func977::func;
	return execfunc(this);
}

namespace _func978
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomShape", typeid(Globals::Rect (ShipGraph::*)(int )), ".5789c88d7c240883e4f0ff77fc5589e557565383ec2c8b178b7f04", argdata, 3, 1, &func);
}

Globals::Rect ShipGraph::GetRoomShape(int room)
{
	typedef Globals::Rect __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func978::func;
	return execfunc(this, room);
}

namespace _func979
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomOxygen", typeid(float (ShipGraph::*)(int )), ".53660fefc083ec048b54240c85d278??8b198b410429d8c1f80239c27d??8b0493", argdata, 2, 1, &func);
}

float ShipGraph::GetRoomOxygen(int room)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func979::func;
	return execfunc(this, room);
}

namespace _func980
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), ".5653b8????????8b5c240c85db78??8b318b510429f2c1fa02", argdata, 2, 1, &func);
}

bool ShipGraph::GetRoomBlackedOut(int room)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func980::func;
	return execfunc(this, room);
}

namespace _func981
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetClosestSlot", typeid(Slot (ShipGraph::*)(Point , int , bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b7704898d6cffffff8b10894588", argdata, 5, 1, &func);
}

Slot ShipGraph::GetClosestSlot(Point pos, int shipId, bool intruder)
{
	typedef Slot __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point pos_arg, int shipId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func981::func;
	return execfunc(this, pos, shipId, intruder);
}

namespace _func982
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotWorldPosition", typeid(Point (ShipGraph::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b57048b018d4dd88b1f8b0490890424", argdata, 3, 9, &func);
}

Point ShipGraph::GetSlotWorldPosition(int slotId, int roomId)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func982::func;
	return execfunc(this, slotId, roomId);
}

namespace _func983
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(char (ShipInfo::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d560483ec5c894dbc8b0f89d3894db4890c24", argdata, 2, 1, &func);
}

char ShipInfo::AddAugmentation(const std::string &augment)
{
	typedef char __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func983::func;
	return execfunc(this, augment);
}

namespace _func984
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d560483ec4c894dc88b0f89d3894dc4890c2489cf", argdata, 2, 1, &func);
}

bool ShipInfo::HasAugmentation(const std::string &augment)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func984::func;
	return execfunc(this, augment);
}

namespace _func985
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::GetAugmentationValue", typeid(float (ShipInfo::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d55a881ec????????8b07894d8c8955a08b308b580489458089f001d874??", argdata, 2, 1, &func);
}

float ShipInfo::GetAugmentationValue(const std::string &augment)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func985::func;
	return execfunc(this, augment);
}

namespace _func986
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::constructor", typeid(int (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83c17083ec6c8b1fc7419c00000000", argdata, 2, 1, &func);
}

int ShipManager::constructor(int shipId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func986::func;
	return execfunc(this, shipId);
}

namespace _func987
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddInitialCrew", typeid(void (ShipManager::*)(std::vector<CrewBlueprint> &)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d8d90feffff81ec????????", argdata, 2, 5, &func);
}

void ShipManager::AddInitialCrew(std::vector<CrewBlueprint> &blueprints)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, std::vector<CrewBlueprint> &blueprints_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func987::func;
	return execfunc(this, blueprints);
}

namespace _func988
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565383ec2c8bb1c8040000837e04ff74??c70424????????89cb", argdata, 1, 1, &func);
}

int ShipManager::GetDodgeFactor()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func988::func;
	return execfunc(this);
}

namespace _func989
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(void (ShipManager::*)(bool , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????803d??????????8b188b4004889d44ffffff898530ffffff0f84????????", argdata, 3, 5, &func);
}

void ShipManager::OnRender(bool showInterior, bool doorControlMode)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool showInterior_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func989::func;
	return execfunc(this, showInterior, doorControlMode);
}

namespace _func990
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(bool )), "5589e557565383e4f083ec100fb645088b51648844240f8b416829d0c1f80285c00f84????????", argdata, 2, 1, &func);
}

int ShipManager::CountCrew(bool boarders)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool boarders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func990::func;
	return execfunc(this, boarders);
}

namespace _func991
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec3c8b3f8b70040fb64008", argdata, 4, 1, &func);
}

std::vector<CrewMember*> ShipManager::TeleportCrew(int roomId, bool intruders)
{
	typedef std::vector<CrewMember*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func991::func;
	return execfunc(this, roomId, intruders);
}

namespace _func992
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnInit", typeid(int (ShipManager::*)(ShipBlueprint *, int )), "578d7c240883e4f0ff77fc5589fa89e55756538d99e0040000", argdata, 3, 1, &func);
}

int ShipManager::OnInit(ShipBlueprint *bp, int shipLevel)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, ShipBlueprint *bp_arg, int shipLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func992::func;
	return execfunc(this, bp, shipLevel);
}

namespace _func993
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(bool (ShipManager::*)(int )), "8b44240483f81174??8b91c8040000833c82ff0f95c0c204008db42600000000b8????????", argdata, 2, 1, &func);
}

bool ShipManager::HasSystem(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func993::func;
	return execfunc(this, systemId);
}

namespace _func994
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), "8b51188b411c29d0c1f80285c074??5589e557565389ce31db83e4f0eb??66908b41383b450874??8b461c83c301", argdata, 2, 1, &func);
}

ShipSystem *ShipManager::GetSystemInRoom(int roomId)
{
	typedef ShipSystem *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func994::func;
	return execfunc(this, roomId);
}

namespace _func995
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d8d1cffffff81ec????????", argdata, 1, 5, &func);
}

void ShipManager::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func995::func;
	return execfunc(this);
}

namespace _func996
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLoss", typeid(void (ShipManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec148b078b7f0483f81174??83f8ff74??8b91c8040000", argdata, 3, 5, &func);
}

void ShipManager::SetSystemPowerLoss(int systemId, int powerLoss)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int powerLoss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func996::func;
	return execfunc(this, systemId, powerLoss);
}

namespace _func997
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(int (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b810807000085c0", argdata, 1, 1, &func);
}

int ShipManager::CreateSystems()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func997::func;
	return execfunc(this);
}

namespace _func998
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddSystem", typeid(int (ShipManager::*)(int )), "8b810807000085c00f84????????578d7c240883e4f0ff77fc5589e557568db104070000", argdata, 2, 1, &func);
}

int ShipManager::AddSystem(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func998::func;
	return execfunc(this, systemId);
}

namespace _func999
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateCrewMembers", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565331db89cf81ec????????8b5118", argdata, 1, 5, &func);
}

void ShipManager::UpdateCrewMembers()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func999::func;
	return execfunc(this);
}

namespace _func1000
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::PowerDrone", typeid(bool (ShipManager::*)(Drone *, int , bool , bool )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b81c80400008b57088b1f8b7f0c837810ff8955e4", argdata, 5, 1, &func);
}

bool ShipManager::PowerDrone(Drone *drone, int roomId, bool userDriven, bool force)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Drone *drone_arg, int roomId_arg, bool userDriven_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1000::func;
	return execfunc(this, drone, roomId, userDriven, force);
}

namespace _func1001
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(void (ShipManager::*)()), "578d41708d7c240883e4f0ff77fc5589e557565389cf89c1", argdata, 1, 5, &func);
}

void ShipManager::UpdateEnvironment()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1001::func;
	return execfunc(this);
}

namespace _func1002
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromBlueprint", typeid(CrewMember *(ShipManager::*)(CrewBlueprint *, int , bool , int , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d4d9c81ec????????8b0789c389458c8b47048945908b4708", argdata, 6, 1, &func);
}

CrewMember *ShipManager::AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewBlueprint *bp_arg, int slot_arg, bool init_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1002::func;
	return execfunc(this, bp, slot, init, roomId, intruder);
}

namespace _func1003
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromString", typeid(CrewMember *(ShipManager::*)(const std::string &, const std::string &, bool , int , bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b770c8b490489855cfdffff89b570fdffff8b47048b771085c9898568fdffff89b558fdffff", argdata, 7, 1, &func);
}

CrewMember *ShipManager::AddCrewMemberFromString(const std::string &name, const std::string &race, bool intruder, int roomId, bool init, bool male)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const std::string &name_arg, const std::string &race_arg, bool intruder_arg, int roomId_arg, bool init_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1003::func;
	return execfunc(this, name, race, intruder, roomId, init, male);
}

namespace _func1004
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(void (ShipManager::*)(CrewMember *, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b41048b77048904248b0f", argdata, 3, 5, &func);
}

void ShipManager::AddCrewMember(CrewMember *crew, int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1004::func;
	return execfunc(this, crew, roomId);
}

namespace _func1005
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetOxygenPercentage", typeid(int (ShipManager::*)()), "8b81c8040000837808ff74??55660fefc989e583e4f083ec208b4124f30f1005????????f30f5980d0010000f30f5ac8f20f110c24e8????????dd5c2418f20f2c442418", argdata, 1, 1, &func);
}

int ShipManager::GetOxygenPercentage()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1005::func;
	return execfunc(this);
}

namespace _func1006
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(bool (ShipManager::*)(CrewMember *, Damage )), "578d7c240883e4f0ff77fc5589f889e557565383ec2c807832008b1f8b7f2875??3b7b04", argdata, 3, 1, &func);
}

bool ShipManager::DamageCrew(CrewMember *crew, Damage dmg)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1006::func;
	return execfunc(this, crew, dmg);
}

namespace _func1007
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::RemoveItem", typeid(void (ShipManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45d889cb83ec5c8b378945d0894dac", argdata, 2, 5, &func);
}

void ShipManager::RemoveItem(const std::string &name)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1007::func;
	return execfunc(this, name);
}

namespace _func1008
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageArea", typeid(bool (ShipManager::*)(Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b47088b5f3cf30f105704f30f100f8945908b4710f30f118d78fffffff30f119574ffffff", argdata, 4, 1, &func);
}

bool ShipManager::DamageArea(Pointf location, Damage dmg, bool forceHit)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf location_arg, Damage dmg_arg, bool forceHit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1008::func;
	return execfunc(this, location, dmg, forceHit);
}

namespace _func1009
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageBeam", typeid(bool (ShipManager::*)(Pointf , Pointf , Damage )), "578d7c240883e4f0ff77fc5589e557565381eccc0000008b07807910008b570889459c8b47048945988b470c", argdata, 4, 1, &func);
}

bool ShipManager::DamageBeam(Pointf location1, Pointf location2, Damage dmg)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf location1_arg, Pointf location2_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1009::func;
	return execfunc(this, location1, location2, dmg);
}

namespace _func1010
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SelectRandomCrew", typeid(CrewBlueprint (ShipManager::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b47048b7708894da883f8ff", argdata, 4, 1, &func);
}

CrewBlueprint ShipManager::SelectRandomCrew(int seed, const std::string &racePref)
{
	typedef CrewBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int seed_arg, const std::string &racePref_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1010::func;
	return execfunc(this, seed, racePref);
}

namespace _func1011
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ClearStatusAll", typeid(void (ShipManager::*)()), "5589e5565331db89ce83e4f083ec108b51188b411c29d0c1f80285c074??66908b0c9a", argdata, 1, 5, &func);
}

void ShipManager::ClearStatusAll()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1011::func;
	return execfunc(this);
}

namespace _func1012
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c8b816c0800003b81700800000f84????????8b0d????????ba????????83f90274??83f901", argdata, 1, 5, &func);
}

void ShipManager::PrepareSuperDrones()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1012::func;
	return execfunc(this);
}

namespace _func1013
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::JumpLeave", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c83a994040000018b51188b8194040000c681d80400000185c0", argdata, 1, 5, &func);
}

void ShipManager::JumpLeave()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1013::func;
	return execfunc(this);
}

namespace _func1014
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(void (ShipManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b470485f6", argdata, 3, 5, &func);
}

void ShipManager::ModifyScrapCount(int scrap, bool income)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int scrap_arg, bool income_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1014::func;
	return execfunc(this, scrap, income);
}

namespace _func1015
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyMissileCount", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b81c80400008b1783780cff75300191040800008b7dfc8b810408000085c0b800000000", argdata, 2, 5, &func);
}

void ShipManager::ModifyMissileCount(int missiles)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int missiles_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1015::func;
	return execfunc(this, missiles);
}

namespace _func1016
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetMissileCount", typeid(int (ShipManager::*)()), ".8b81c804000083780cff", argdata, 1, 1, &func);
}

int ShipManager::GetMissileCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1016::func;
	return execfunc(this);
}

namespace _func1017
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyDroneCount", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b81c80400008b17837810ff75300191000800008b7dfc8b8100080000", argdata, 2, 5, &func);
}

void ShipManager::ModifyDroneCount(int drones)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int drones_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1017::func;
	return execfunc(this, drones);
}

namespace _func1018
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DoSensorsProvide", typeid(bool (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b81c80400008b3f8b701c83feff74??", argdata, 2, 1, &func);
}

bool ShipManager::DoSensorsProvide(int vision)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int vision_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1018::func;
	return execfunc(this, vision);
}

namespace _func1019
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b5104b9????????85d20f95c0890424e8????????83ec04837b0401b9????????19d2", argdata, 1, 1, &func);
}

bool ShipManager::IsCrewFull()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1019::func;
	return execfunc(this);
}

namespace _func1020
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b5104b9????????85d20f95c0890424e8????????83ec04837b040119d283e2fe", argdata, 1, 1, &func);
}

bool ShipManager::IsCrewOverFull()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1020::func;
	return execfunc(this);
}

namespace _func1021
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(CrewDrone *(ShipManager::*)(const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b178b82b800000083f8020f84????????83f8030f85????????89542404", argdata, 2, 1, &func);
}

CrewDrone *ShipManager::CreateCrewDrone(const DroneBlueprint *bp)
{
	typedef CrewDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1021::func;
	return execfunc(this, bp);
}

namespace _func1022
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(SpaceDrone *(ShipManager::*)(const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565383ec3c8b3fc745dc0000000083bfb8000000070f87????????8b87b800000089cbff2485????????8db42600000000e8????????c70424????????8945d4", argdata, 2, 1, &func);
}

SpaceDrone *ShipManager::CreateSpaceDrone(const DroneBlueprint *bp)
{
	typedef SpaceDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1022::func;
	return execfunc(this, bp);
}

namespace _func1023
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (ShipManager::*)(CrewMember *, int )), "578d7c240883e4f0ff77fc5589e55783ec148b47048b0fc744240800000000c7442404ffffffff890424", argdata, 3, 1, &func);
}

bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int roomId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1023::func;
	return execfunc(this, crew, roomId);
}

namespace _func1024
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemRoom", typeid(int (ShipManager::*)(int )), "55b8????????89e5538b550883e4f083faff74??8b99c80400008b149383faff74??8b49188b0c9185c9", argdata, 2, 1, &func);
}

int ShipManager::GetSystemRoom(int sysId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1024::func;
	return execfunc(this, sysId);
}

namespace _func1025
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(std::vector<ProjectileFactory*> (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b90c8040000837a0cff75??c701????????c741040000000089d8c7410800000000", argdata, 2, 1, &func);
}

std::vector<ProjectileFactory*> ShipManager::GetWeaponList()
{
	typedef std::vector<ProjectileFactory*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1025::func;
	return execfunc(this);
}

namespace _func1026
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(Drone *(ShipManager::*)(const DroneBlueprint *, int )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b81c80400008b1f8b7704837810ff", argdata, 3, 1, &func);
}

Drone *ShipManager::AddDrone(const DroneBlueprint *bp, int slot)
{
	typedef Drone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1026::func;
	return execfunc(this, bp, slot);
}

namespace _func1027
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Restart", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec4c8b410485c075??c641100189f9e8????????8b8fc00400008b97bc04000089c8", argdata, 1, 5, &func);
}

void ShipManager::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1027::func;
	return execfunc(this);
}

namespace _func1028
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), "558b81c804000089e583e4f08b55088b049083f8ff74??8b51188b0c82e8????????", argdata, 2, 1, &func);
}

int ShipManager::GetSystemPower(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1028::func;
	return execfunc(this, systemId);
}

namespace _func1029
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrewShipId", typeid(int (ShipManager::*)(int , int )), "5589e557565383e4f083ec108b41688b51648944240c29d0c1f80285c074??894c240431db31ffeb??8db4260000000001c78b44240c", argdata, 3, 1, &func);
}

int ShipManager::CountCrewShipId(int roomId, int shipId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1029::func;
	return execfunc(this, roomId, shipId);
}

namespace _func1030
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), "8b44240483f8ff74??8b91c80400008b048283f8ff74??8b51188b0482", argdata, 2, 1, &func);
}

ShipSystem *ShipManager::GetSystem(int systemId)
{
	typedef ShipSystem *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1030::func;
	return execfunc(this, systemId);
}

namespace _func1031
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportShip", typeid(void (ShipManager::*)(int )), "5789c805????????8d7c240883e4f0ff77fc5589e557565381ec????????8b3789cf89442404898d90feffff893424e8????????80bf68060000008d85c0feffff89c1898594feffff", argdata, 2, 5, &func);
}

void ShipManager::ExportShip(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1031::func;
	return execfunc(this, file);
}

namespace _func1032
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::destructor", typeid(void (ShipManager::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce", argdata, 1, 5, &func);
}

void ShipManager::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1032::func;
	return execfunc(this);
}

namespace _func1033
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::destructor2", typeid(void (ShipManager::*)()), ".5589e55389cb83e4f083ec10e8????????891c24e8????????8b5dfc", argdata, 1, 5, &func);
}

void ShipManager::destructor2()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1033::func;
	return execfunc(this);
}

namespace _func1034
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportShip", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55756538d85dcfcffff89ce8d9de4fcffff81ec????????8b3f898d4cfbffff890424897c2404e8????????", argdata, 2, 5, &func);
}

void ShipManager::ImportShip(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1034::func;
	return execfunc(this, file);
}

namespace _func1035
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckVision", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b81c8040000c645b7008b701c83feff74??", argdata, 1, 5, &func);
}

void ShipManager::CheckVision()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1035::func;
	return execfunc(this);
}

namespace _func1036
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked", typeid(int (ShipManager::*)(int )), "5383ec048b54240c83fa1174??8b99c804000031c0833c93ff75??83c4045bc20400891424e8????????83ec04", argdata, 2, 1, &func);
}

int ShipManager::IsSystemHacked(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1036::func;
	return execfunc(this, systemId);
}

namespace _func1037
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrewPoint", typeid(CrewMember *(ShipManager::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b078b51648945d48b47048945d00fb64708", argdata, 4, 1, &func);
}

CrewMember *ShipManager::GetSelectedCrewPoint(int x, int y, bool intruder)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1037::func;
	return execfunc(this, x, y, intruder);
}

namespace _func1038
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RenderWeapons", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e5578db994000000565389ce89f983ec5ce8????????8945c08b86c8040000", argdata, 1, 5, &func);
}

void ShipManager::RenderWeapons()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1038::func;
	return execfunc(this);
}

namespace _func1039
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ClearStatusSystem", typeid(void (ShipManager::*)(int )), "5589e583e4f083ec108b450883f81174??83f8ff74??8b91c80400008b048283f8ff74??8b51188b0c8285c974??e8????????c9", argdata, 2, 5, &func);
}

void ShipManager::ClearStatusSystem(int system)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1039::func;
	return execfunc(this, system);
}

namespace _func1040
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(void (ShipManager::*)()), "a1????????c781d40400001e00000083f80174??83f80274??f3c3908d742600c781d404000000000000c3908d742600c781d40400000a000000", argdata, 1, 5, &func);
}

void ShipManager::ResetScrapLevel()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1040::func;
	return execfunc(this);
}

namespace _func1041
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::JumpArrive", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce81c1????????83ec3c8b411cc741ec000000008941208b812cfcffff89810c040000c70424????????", argdata, 1, 5, &func);
}

void ShipManager::JumpArrive()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1041::func;
	return execfunc(this);
}

namespace _func1042
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CheckSpreadDamage", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565383ec4c8b51188b411cc745b80000000029d0c1f80285c00f84????????89cf", argdata, 1, 5, &func);
}

void ShipManager::CheckSpreadDamage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1042::func;
	return execfunc(this);
}

namespace _func1043
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ForceDecreaseSystemPower", typeid(bool (ShipManager::*)(int )), "5731c08d7c240883e4f0ff77fc5589e55783ec148b1783faff74??8bb9c80400008b149783faff74??8b4918", argdata, 2, 1, &func);
}

bool ShipManager::ForceDecreaseSystemPower(int sys)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1043::func;
	return execfunc(this, sys);
}

namespace _func1044
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetShieldPower", typeid(ShieldPower (ShipManager::*)()), "5589c889e58b55088b524485d274??8b8aec0100005d89088b8af00100008948048b8af40100008b92f801000089480889500c", argdata, 2, 1, &func);
}

ShieldPower ShipManager::GetShieldPower()
{
	typedef ShieldPower __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1044::func;
	return execfunc(this);
}

namespace _func1045
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddWeapon", typeid(int (ShipManager::*)(const WeaponBlueprint *, int )), "5731c08d7c240883e4f0ff77fc5589e5575383ec108b91c80400008b1f8b7f04837a0cff74??8b4948", argdata, 3, 1, &func);
}

int ShipManager::AddWeapon(const WeaponBlueprint *bp, int slot)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const WeaponBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1045::func;
	return execfunc(this, bp, slot);
}

namespace _func1046
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddEquipmentFromList", typeid(void (ShipManager::*)(std::vector<std::string> *)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b3f8b178b470429d0c1f80369c0????????85c00f84????????", argdata, 2, 5, &func);
}

void ShipManager::AddEquipmentFromList(std::vector<std::string> *equipmentList)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, std::vector<std::string> *equipmentList_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1046::func;
	return execfunc(this, equipmentList);
}

namespace _func1047
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RenderChargeBars", typeid(void (ShipManager::*)()), "8b410485c075??c3908db4260000000080b9b00400000075??80b9990400000074??f3c38b915408000085d2", argdata, 1, 5, &func);
}

void ShipManager::RenderChargeBars()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1047::func;
	return execfunc(this);
}

namespace _func1048
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportBattleState", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec3c8b188b81c8040000837810ff0f84????????8b414c", argdata, 2, 5, &func);
}

void ShipManager::ExportBattleState(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1048::func;
	return execfunc(this, file);
}

namespace _func1049
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportBattleState", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b81c80400008b37837810ff0f84????????8b414c8d4ddc05????????", argdata, 2, 5, &func);
}

void ShipManager::ImportBattleState(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1049::func;
	return execfunc(this, file);
}

namespace _func1050
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemFunctions", typeid(bool (ShipManager::*)(int )), "558b81c804000089e583e4f08b55088b149031c083faff74??8b41188b0c908b01ff502c", argdata, 2, 1, &func);
}

bool ShipManager::SystemFunctions(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1050::func;
	return execfunc(this, systemId);
}

namespace _func1051
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanFitSystem", typeid(bool (ShipManager::*)(int )), "5589e557565383e4f083ec108b450883f8050f84????????83f80d74??8b791c8b511889f829d0", argdata, 2, 1, &func);
}

bool ShipManager::CanFitSystem(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1051::func;
	return execfunc(this, systemId);
}

namespace _func1052
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanFitSubsystem", typeid(bool (ShipManager::*)(int )), "5589e557565383e4f083ec108b791c8b511889f829d0c1f80285c074??894c240c31db31f6eb??", argdata, 2, 3, &func);
}

FUNC_NAKED bool ShipManager::CanFitSubsystem(int systemId)
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%edx\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
		"pushl 8(%%ebp)\n\t"		// systemId
			// ecx has this
		"call *%0\n\t"
		"addl $4, %%esp\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"popl %%edx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret $4\n\t"
		 :: "m"(_func1052::func)
	);
}

namespace _func1053
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageHull", typeid(int (ShipManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b018b378b57048b40403d????????75??0fb681d804000038d0", argdata, 3, 1, &func);
}

int ShipManager::DamageHull(int dmg, bool force)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int dmg_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1053::func;
	return execfunc(this, dmg, force);
}

namespace _func1054
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageSystem", typeid(void (ShipManager::*)(int , Damage )), "578d7c240883e4f0ff77fc5589f889e557565383ec6c8b308b58048b4018897db089cf", argdata, 3, 5, &func);
}

void ShipManager::DamageSystem(int systemId, Damage damage)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, Damage damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1054::func;
	return execfunc(this, systemId, damage);
}

namespace _func1055
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::StartFire", typeid(void (ShipManager::*)(int )), "5783c1708d7c240883e4f0ff77fc5589e55783ec148b07c744240402000000890424e8????????8b7dfc83ec08c9", argdata, 2, 5, &func);
}

void ShipManager::StartFire(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1055::func;
	return execfunc(this, roomId);
}

namespace _func1056
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::FindCrew", typeid(CrewMember *(ShipManager::*)(const CrewBlueprint *)), "57b9????????8d7c240883e4f0ff77fc5589e557565383ec4c8b07c745dc00000000c744240800000000c744240400000000c745e000000000c745e4000000008945c489c38d45dc890424", argdata, 2, 1, &func);
}

CrewMember *ShipManager::FindCrew(const CrewBlueprint *bp)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const CrewBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1056::func;
	return execfunc(this, bp);
}

namespace _func1057
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDodged", typeid(bool (ShipManager::*)()), "8079100075??b8????????c38d742600578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 1, &func);
}

bool ShipManager::GetDodged()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1057::func;
	return execfunc(this);
}

namespace _func1058
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperBarrage", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e55756538d995c08000081ec8c0000008b8188040000894db4c745a007000000895d9485c00f842a030000908db42600000000", argdata, 1, 5, &func);
}

void ShipManager::PrepareSuperBarrage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1058::func;
	return execfunc(this);
}

namespace _func1059
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetTooltip", typeid(std::string (ShipManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec7c8b47048b1f894d8c8945948b4708c70424????????894590e8????????8b53648b436883ec0429d0", argdata, 4, 1, &func);
}

std::string ShipManager::GetTooltip(int x, int y)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1059::func;
	return execfunc(this, x, y);
}

namespace _func1060
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RestoreCrewPositions", typeid(bool (ShipManager::*)()), "57b9????????8d7c240883e4f0ff77fc5589e55756538d45ac31db83ec6cc745ac00000000c745b000000000890424c744240400000000c745b400000000", argdata, 1, 1, &func);
}

bool ShipManager::RestoreCrewPositions()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1060::func;
	return execfunc(this);
}

namespace _func1061
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetCrewmember", typeid(CrewMember *(ShipManager::*)(int , bool )), "5589e557565383e4f083ec108b79688b4164c744240c0000000089fa29c2c1fa0285d274??31db894c2408eb??8d760089fa83c301", argdata, 3, 1, &func);
}

CrewMember *ShipManager::GetCrewmember(int slot, bool present)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int slot_arg, bool present_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1061::func;
	return execfunc(this, slot, present);
}

namespace _func1062
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanUpgrade", typeid(int (ShipManager::*)(int , int )), "5589e55383e4f083ec108b550883fa11744e8b81c80400008b1c9031c083fbff750e8b5dfcc9c20800", argdata, 3, 1, &func);
}

int ShipManager::CanUpgrade(int systemId, int amount)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1062::func;
	return execfunc(this, systemId, amount);
}

namespace _func1063
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SaveToBlueprint", typeid(ShipBlueprint (ShipManager::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83c10483ec6c8b078b7704", argdata, 3, 1, &func);
}

ShipBlueprint ShipManager::SaveToBlueprint(bool unk)
{
	typedef ShipBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1063::func;
	return execfunc(this, unk);
}

namespace _func1064
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ShipManager::CheckCrystalAugment", typeid(void (ShipManager::*)(Pointf )), "578d7c240883e4f0ff77fc5589e55756538d5dd089ce83ec7c8b078b570489d9", argdata, 2, 5, &func);
}

void ShipManager::CheckCrystalAugment(Pointf pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1064::func;
	return execfunc(this, pos);
}

namespace _func1065
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CollisionMoving", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565381ecfc0000008b178b5f488b7710c70100000000898d50ffffff83c104", argdata, 6, 1, &func);
}

CollisionResponse ShipManager::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1065::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1066
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerMax", typeid(int (ShipManager::*)(int )), "8b81c80400008b5424048b049083f8ff740e8b51188b04828b4054c20400", argdata, 2, 1, &func);
}

int ShipManager::GetSystemPowerMax(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1066::func;
	return execfunc(this, systemId);
}

namespace _func1067
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetDroneList", typeid(std::vector<Drone*> (ShipManager::*)()), "5589e557565389cb83e4f083ec208b45088b90c8040000837a10ff7523c70100000000c741040000000089d8c74108000000008d65f4", argdata, 2, 1, &func);
}

std::vector<Drone*> ShipManager::GetDroneList()
{
	typedef std::vector<Drone*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1067::func;
	return execfunc(this);
}

namespace _func1068
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDroneCount", typeid(int (ShipManager::*)()), "8b81c8040000837810ff74148b414c8b80cc010000c3", argdata, 1, 1, &func);
}

int ShipManager::GetDroneCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1068::func;
	return execfunc(this);
}

namespace _func1069
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::InstantPowerShields", typeid(void (ShipManager::*)()), "8b81c80400008b0083f8ff7455578d7c240883e4f0ff77fc5589e5575389cb83ec10", argdata, 1, 5, &func);
}

void ShipManager::InstantPowerShields()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1069::func;
	return execfunc(this);
}

namespace _func1070
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::SetDestroyed", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565331db89ce83ec1c8b51188b411cc681990400000129d0c1f80285c0", argdata, 1, 5, &func);
}

void ShipManager::SetDestroyed()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1070::func;
	return execfunc(this);
}

namespace _func1071
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetFireCount", typeid(int (ShipManager::*)(int )), "5783c1708d7c240883e4f0ff77fc5589e55783ec148b07890424e8????????8b7dfc83ec04c98d67f85fc20400", argdata, 2, 1, &func);
}

int ShipManager::GetFireCount(int roomId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1071::func;
	return execfunc(this, roomId);
}

namespace _func1072
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::DoorsFunction", typeid(bool (ShipManager::*)()), "8b81c80400008b402083f8ff74??5589e5538b511889cb83e4f08b0c828b01ff502c84c074??", argdata, 1, 1, &func);
}

bool ShipManager::DoorsFunction()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1072::func;
	return execfunc(this);
}

namespace _func1073
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetLeavingCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec2c8b3f0fb64004c70100000000c7410400000000", argdata, 3, 1, &func);
}

std::vector<CrewMember*> ShipManager::GetLeavingCrew(bool intruders)
{
	typedef std::vector<CrewMember*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1073::func;
	return execfunc(this, intruders);
}

namespace _func1074
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CollisionShield", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d4d9c81ecdc0000008b47048b1fc7442404000000cf", argdata, 6, 1, &func);
}

CollisionResponse ShipManager::CollisionShield(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1074::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1075
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCloaked", typeid(bool (ShipManager::*)()), "8b81c8040000837828ff74148b412c0fb680c0010000c3", argdata, 1, 1, &func);
}

bool ShipManager::IsCloaked()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1075::func;
	return execfunc(this);
}

namespace _func1076
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::UpgradeSystem", typeid(void (ShipManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f8b4704891c2489442404", argdata, 3, 5, &func);
}

void ShipManager::UpgradeSystem(int id, int amount)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int id_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1076::func;
	return execfunc(this, id, amount);
}

namespace _func1077
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CountPlayerCrew", typeid(int (ShipManager::*)()), "5589e557565383e4f083ec108b41688b516489c3", argdata, 1, 1, &func);
}

int ShipManager::CountPlayerCrew()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1077::func;
	return execfunc(this);
}

namespace _func1078
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Wait", typeid(void (ShipManager::*)()), "578d????0883e4f0ff????5589e557565389cb83ec1c8b81c8040000", argdata, 1, 5, &func);
}

void ShipManager::Wait()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1078::func;
	return execfunc(this);
}

namespace _func1079
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CloneHealing", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b????e8", argdata, 1, 5, &func);
}

void ShipManager::CloneHealing()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1079::func;
	return execfunc(this);
}

namespace _func1080
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(const std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d4dd883ec5c8b07894dd08b308b580489f0", argdata, 2, 1, &func);
}

int ShipObject::HasAugmentation(const std::string &augment)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1080::func;
	return execfunc(this, augment);
}

namespace _func1081
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(const std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d4d9081ec????????8b07894d888b308b5804", argdata, 2, 1, &func);
}

float ShipObject::GetAugmentationValue(const std::string &augment)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1081::func;
	return execfunc(this, augment);
}

namespace _func1082
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::RemoveAugmentation", typeid(void (ShipObject::*)(const std::string &)), ".5789ca8d7c240883e4f0ff77fc5589e55756538d4d9081ec????????8b07894d888b308b580489f001d874??85f675??c70424????????e8????????8d74260083fb0f895dd00f87????????", argdata, 2, 5, &func);
}

void ShipObject::RemoveAugmentation(const std::string &augment)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1082::func;
	return execfunc(this, augment);
}

namespace _func1083
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasEquipment", typeid(int (ShipObject::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d75a881ec????????8b3f898d70ffffff8975a0", argdata, 2, 1, &func);
}

int ShipObject::HasEquipment(const std::string &equip)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1083::func;
	return execfunc(this, equip);
}

namespace _func1084
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationList", typeid(std::vector<std::string> (ShipObject::*)()), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b008b400485c0", argdata, 2, 1, &func);
}

std::vector<std::string> ShipObject::GetAugmentationList()
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1084::func;
	return execfunc(this);
}

namespace _func1085
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::AddAugmentation", typeid(bool (ShipObject::*)(const std::string &)), "5789ca8d7c240883e4f0ff77fc5589e55756538d75d883ec4c8b078975d0", argdata, 2, 1, &func);
}

bool ShipObject::AddAugmentation(const std::string &augment)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1085::func;
	return execfunc(this, augment);
}

namespace _func1086
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipObject::__DO_NOT_HOOK", typeid(void (ShipObject::*)()), "89b5a4feffffe9????????c70424????????e8????????89c60fb68590feffff89f1894424088b8594feffff894424048b858cfeffff890424", argdata, 0, 4, &func);
}

namespace _func1087
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), ".8b510431c085d20f94c06bc0340305????????8b4030", argdata, 1, 1, &func);
}

int ShipObject::GetAugmentationCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1087::func;
	return execfunc(this);
}

namespace _func1088
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipObject::ClearShipInfo", typeid(void (ShipObject::*)()), "578d7c240883e4f0ff77fc5589e557565331db83ec2c8b410485c00f94c36bdb34", argdata, 1, 5, &func);
}

void ShipObject::ClearShipInfo()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1088::func;
	return execfunc(this);
}

ShipInfo **Global_ShipObject_ShipInfoList;

namespace _var1089
{
    static VariableDefinition varObj("Global_ShipObject_ShipInfoList", "!6bc0340305(???????\?)8b4030c3", &Global_ShipObject_ShipInfoList);
}

namespace _func1090
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::SelectShip", typeid(void (ShipSelect::*)(int )), "578d7c240883e4f0ff77fc5589e55756538d9d48f9ffff81ec????????8b07", argdata, 2, 5, &func);
}

void ShipSelect::SelectShip(int shipType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1090::func;
	return execfunc(this, shipType);
}

namespace _func1091
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::constructor", typeid(void (ShipSelect::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c74424046e000000c70424????????e8????????8d4b08", argdata, 1, 5, &func);
}

void ShipSelect::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1091::func;
	return execfunc(this);
}

namespace _func1092
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::ClearShipButtons", typeid(void (ShipSelect::*)()), ".5589e55756538b792089ce8b511c83e4f089f829d083f8037e??31db", argdata, 1, 5, &func);
}

void ShipSelect::ClearShipButtons()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1092::func;
	return execfunc(this);
}

namespace _func1093
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::MouseMove", typeid(void (ShipSelect::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b1780b94805000000", argdata, 3, 5, &func);
}

void ShipSelect::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1093::func;
	return execfunc(this, x, y);
}

namespace _func1094
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::OnLoop", typeid(void (ShipSelect::*)()), ".80b9480500000075??f3c3908d742600578d7c240883e4f0ff77fc5589e557568db144050000", argdata, 1, 5, &func);
}

void ShipSelect::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1094::func;
	return execfunc(this);
}

namespace _func1095
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::KeyDown", typeid(int (ShipSelect::*)(SDLKey )), ".5781c1????????8d7c240883e4f0ff77fc5589e55783ec148b07", argdata, 2, 1, &func);
}

int ShipSelect::KeyDown(SDLKey key)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1095::func;
	return execfunc(this, key);
}

namespace _func1096
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::MouseClick", typeid(void (ShipSelect::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec1080b948050000000f85????????80b9bc01000000", argdata, 1, 5, &func);
}

void ShipSelect::MouseClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1096::func;
	return execfunc(this);
}

namespace _func1097
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::PreSelectShip", typeid(void (ShipSelect::*)(int )), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b0785c078??83b9780100000274??89d9890424e8????????83ec048d65f8", argdata, 2, 5, &func);
}

void ShipSelect::PreSelectShip(int shipType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1097::func;
	return execfunc(this, shipType);
}

namespace _func1098
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::Close", typeid(void (ShipSelect::*)()), ".5581c1????????c681f0faffff0089e583e4f0", argdata, 1, 5, &func);
}

void ShipSelect::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1098::func;
	return execfunc(this);
}

namespace _func1099
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::GetSelectedShip", typeid(int (ShipSelect::*)()), ".8b4138", argdata, 1, 1, &func);
}

int ShipSelect::GetSelectedShip()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1099::func;
	return execfunc(this);
}

namespace _func1100
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::Open", typeid(void (ShipSelect::*)(int , int )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 3, 5, &func);
}

void ShipSelect::Open(int currentId, int currentType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int currentId_arg, int currentType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1100::func;
	return execfunc(this, currentId, currentType);
}

namespace _func1101
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::OnRender", typeid(void (ShipSelect::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c80b948050000000f85????????807b34000f84????????8b7b148b731039f774??89f68dbc27000000008b06", argdata, 1, 5, &func);
}

void ShipSelect::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1101::func;
	return execfunc(this);
}

namespace _func1102
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565381ec????????803f000f85????????89cb8b79148bb180000000", argdata, 2, 5, &func);
}

void ShipStatus::RenderHealth(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1102::func;
	return execfunc(this, unk);
}

namespace _func1103
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), "578d7c240883e4f0ff77fc5589e55756538db5c0feffff81ec????????8b078b5704f30f104708", argdata, 3, 5, &func);
}

void ShipStatus::OnInit(Point unk, float unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, Point unk_arg, float unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1103::func;
	return execfunc(this, unk, unk2);
}

namespace _func1104
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????803f008b490c0f84????????e8????????", argdata, 2, 5, &func);
}

void ShipStatus::RenderEvadeOxygen(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1104::func;
	return execfunc(this, unk);
}

namespace _func1105
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(void (ShipStatus::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????660fefc0c744240800000000f30f2a4304f30f11442404660fefc0f30f2a03", argdata, 1, 5, &func);
}

void ShipStatus::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1105::func;
	return execfunc(this);
}

namespace _func1106
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderShields", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cf83ec5c8b410c8d4dc88b10890424ff52388b45cc8b4f0c", argdata, 2, 7, &func);
}

FUNC_NAKED void ShipStatus::RenderShields(bool renderText)
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%edx\n\t"
		"pushl %%eax\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
		"pushl 8(%%ebp)\n\t"		// renderText
			// ecx has this
		"call *%0\n\t"
		"addl $4, %%esp\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"popl %%eax\n\t"
		"popl %%edx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret $4\n\t"
		 :: "m"(_func1106::func)
	);
}

namespace _func1107
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipStatus::OnLoop", typeid(void (ShipStatus::*)()), "578d7c240883e4f0ff77fc5589e557565331db89ce83ec7c8b91100100008b811401000029d0c1f80285c0", argdata, 1, 5, &func);
}

void ShipStatus::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1107::func;
	return execfunc(this);
}

namespace _func1108
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::DamageOverTime", typeid(bool (ShipSystem::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec2cf30f100ff30f114de4e8????????d95de031c0f30f1045e0f30f5945e4f30f5883080100000f2e05????????f30f118308010000", argdata, 2, 1, &func);
}

bool ShipSystem::DamageOverTime(float unk)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, float unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1108::func;
	return execfunc(this, unk);
}

namespace _func1109
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::CheckForRepower", typeid(void (ShipSystem::*)()), ".8b414083e80383f801", argdata, 1, 5, &func);
}

void ShipSystem::CheckForRepower()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1109::func;
	return execfunc(this);
}

namespace _func1110
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(const std::string &)), ".8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e8????????83ec0485c075??", argdata, 1, 2, &func);
}

int ShipSystem::NameToSystemId(const std::string &name)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1110::func;
	return execfunc(name);
}

namespace _func1111
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), "8b414885c07e??80794c0074??8b9104010000399100010000ba????????", argdata, 1, 1, &func);
}

int ShipSystem::IsMannedBoost()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1111::func;
	return execfunc(this);
}

namespace _func1112
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(std::string (*)(int )), "8d4c240483e4f0ff71fc5589e5535183ec108b41048b1983f8110f87????????ff2485????????89f68dbc2700000000c70424????????89d9e8????????83ec048d65f8", argdata, 2, 2, &func);
}

std::string ShipSystem::SystemIdToName(int systemId)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1112::func;
	return execfunc(systemId);
}

namespace _func1113
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(void (ShipSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b812801000085c0", argdata, 1, 5, &func);
}

void ShipSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1113::func;
	return execfunc(this);
}

namespace _func1114
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::Ioned", typeid(bool (ShipSystem::*)(int )), "538b812801000083f8ff0f94c285c00f9fc008d075??83b9a8010000017e??8b911c0100008b415483fa077e??", argdata, 2, 1, &func);
}

bool ShipSystem::Ioned(int num)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int num_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1114::func;
	return execfunc(this, num);
}

namespace _func1115
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerLoss", typeid(int (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b338b0f8b8680000000898b200100003d????????0f85????????", argdata, 2, 1, &func);
}

int ShipSystem::SetPowerLoss(int power)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int power_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1115::func;
	return execfunc(this, power);
}

namespace _func1116
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::constructor", typeid(void (ShipSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b5f048b770c898d24feffff898504feffff8b4708", argdata, 5, 5, &func);
}

void ShipSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int systemId_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1116::func;
	return execfunc(this, systemId, roomId, shipId, startingPower);
}

namespace _func1117
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), "8b811c01000083f8077f??85c0ba????????0f48c2c38d76008dbc27000000008b415485c0", argdata, 1, 1, &func);
}

int ShipSystem::GetPowerCap()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1117::func;
	return execfunc(this);
}

namespace _func1118
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerCap", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b338b0f8b8680000000898b1c010000", argdata, 2, 5, &func);
}

void ShipSystem::SetPowerCap(int cap)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int cap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1118::func;
	return execfunc(this, cap);
}

namespace _func1119
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LockSystem", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b0783f80075??8b812801000085c0", argdata, 2, 5, &func);
}

void ShipSystem::LockSystem(int lock)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1119::func;
	return execfunc(this, lock);
}

namespace _func1120
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::ForceDecreasePower", typeid(bool (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec2c80b918010000008b1f74??", argdata, 2, 1, &func);
}

bool ShipSystem::ForceDecreasePower(int powerLoss)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int powerLoss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1120::func;
	return execfunc(this, powerLoss);
}

namespace _func1121
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), "8b414831d285c07e??80794c0074??8b810401000039810001000074??8b8170010000034150", argdata, 1, 1, &func);
}

int ShipSystem::GetEffectivePower()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1121::func;
	return execfunc(this);
}

namespace _func1122
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetMaxPower", typeid(int (ShipSystem::*)()), "538b59548b910001000001da2b91040100002b91200100008b891c01000083f9077f??85c9b8????????0f49c139c20f4ec2", argdata, 1, 1, &func);
}

int ShipSystem::GetMaxPower()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1122::func;
	return execfunc(this);
}

namespace _func1123
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetBonusPower", typeid(void (ShipSystem::*)(int , int )), "80b918010000000f84????????5589e5578bb904010000568bb100010000538b595489f829f083e4f089da29c28b811c010000", argdata, 3, 5, &func);
}

void ShipSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1123::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func1124
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::CheckMaxPower", typeid(void (ShipSystem::*)()), "578d7c240883e4f0ff77fc5589e557565383ec2c80b918010000000f84????????8d81a401000089cf8945dc8d41508945d8eb49", argdata, 1, 5, &func);
}

void ShipSystem::CheckMaxPower()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1124::func;
	return execfunc(this);
}

namespace _func1125
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::__DO_NOT_HOOK", typeid(void (ShipSystem::*)()), "55c701????????89e583e4f0e8????????c9c390909090909090909090909090b8????????", argdata, 1, 5, &func);
}

namespace _func1126
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::PartialDamage", typeid(bool (ShipSystem::*)(float )), ".578d7c240883e4f0ff77fc5589e55783ec14f30f1007f30f110424e8????????8b7dfc83ec04", argdata, 2, 1, &func);
}

bool ShipSystem::PartialDamage(float amount)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1126::func;
	return execfunc(this, amount);
}

namespace _func1127
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetHackingLevel", typeid(void (ShipSystem::*)(int )), ".8b44????8981a8010000", argdata, 2, 5, &func);
}

void ShipSystem::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1127::func;
	return execfunc(this, hackingLevel);
}

namespace _func1128
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IsSubsystem", typeid(bool (*)(int )), "8b54240483fa060f94c183fa0c0f94c008c875??83ea0783fa01", argdata, 1, 2, &func);
}

bool ShipSystem::IsSubsystem(int systemType)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1128::func;
	return execfunc(systemType);
}

namespace _func1129
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::ClearStatus", typeid(void (ShipSystem::*)()), "83b91c010000077e??8b812001000085c07e??8b4140c7811c010000e8030000c7812001000000000000c781240100000100000083e80383f80176??55", argdata, 1, 5, &func);
}

void ShipSystem::ClearStatus()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1129::func;
	return execfunc(this);
}

namespace _func1130
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLevelDescription", typeid(std::string (*)(int , int , bool )), "8d4c240483e4f0ff71fc5589e55756535181ec????????8b41048b398b59088b510c83f80f0f87????????85db", argdata, 4, 2, &func);
}

std::string ShipSystem::GetLevelDescription(int systemId, int level, bool tooltip)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg, int level_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1130::func;
	return execfunc(systemId, level, tooltip);
}

namespace _func1131
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetLocked", typeid(bool (ShipSystem::*)()), "8b812801000085c00f9fc283f8ff0f94c008d075??83b9a8010000010f9fc0", argdata, 1, 1, &func);
}

bool ShipSystem::GetLocked()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1131::func;
	return execfunc(this);
}

namespace _func1132
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::AddLock", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b81280100008b1785c07f??83f8ff74??85c074??85d2", argdata, 2, 5, &func);
}

void ShipSystem::AddLock(int lock)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1132::func;
	return execfunc(this, lock);
}

namespace _func1133
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::StopHacking", typeid(void (ShipSystem::*)()), "8b01c681ac010000008b40643d????????75??c781a801000000000000c36690578d7c240883e4f0ff77fc5589e55783ec14", argdata, 1, 5, &func);
}

void ShipSystem::StopHacking()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1133::func;
	return execfunc(this);
}

namespace _func1134
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SaveState", typeid(void (ShipSystem::*)(int )), "5589e5565389ce83e4f083ec108b5d088b811c010000891c2489442404e8????????8b8620010000891c2489442404e8????????8b8624010000891c2489442404e8????????", argdata, 2, 5, &func);
}

void ShipSystem::SaveState(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1134::func;
	return execfunc(this, file);
}

namespace _func1135
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LoadState", typeid(void (ShipSystem::*)(int )), "5589e5565389cb83e4f083ec108b7508893424e8????????89342489831c010000e8????????893424898320010000e8????????8983240100008d65f85b", argdata, 2, 5, &func);
}

void ShipSystem::LoadState(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1135::func;
	return execfunc(this, file);
}

namespace _func1136
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::UpgradeSystem", typeid(bool (ShipSystem::*)(int )), "8b015589e556538b401089cb8b750883e4f03d????????75??8b810001000085c00f94c001735401b304010000", argdata, 2, 1, &func);
}

bool ShipSystem::UpgradeSystem(int amount)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1136::func;
	return execfunc(this, amount);
}

namespace _func1137
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IncreasePower", typeid(bool (ShipSystem::*)(int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec2c8b70048b81280100008b3f85c0", argdata, 3, 1, &func);
}

bool ShipSystem::IncreasePower(int amount, bool force)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1137::func;
	return execfunc(this, amount, force);
}

namespace _func1138
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::DecreasePower", typeid(bool (ShipSystem::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec1c0fb681180100008b1f84c074??8b812801000085c00f9fc283f8ff0f94c008d075??83b9a8010000017f??", argdata, 2, 1, &func);
}

bool ShipSystem::DecreasePower(bool force)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1138::func;
	return execfunc(this, force);
}

namespace _func1139
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::PartialRepair", typeid(bool (ShipSystem::*)(float , bool )), "5531c089e5565383e4f083ec108b91040100003991000100008b750c74??89cbb9????????e8????????f30f100d????????89f0f30f10450884c0f30f59c1d95c240c", argdata, 3, 1, &func);
}

bool ShipSystem::PartialRepair(float speed, bool autoRepair)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, float speed_arg, bool autoRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1139::func;
	return execfunc(this, speed, autoRepair);
}

namespace _func1140
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxes", typeid(int (ShipSystem::*)(int , int , int , int , int , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec????????8b70088b188975a08b700c895d848b5804", argdata, 8, 1, &func);
}

int ShipSystem::RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int heightMod_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1140::func;
	return execfunc(this, x, y, width, height, gap, heightMod, flash);
}

namespace _func1141
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::AddDamage", typeid(void (ShipSystem::*)(int )), "568b8100010000532b44240c8b99040100008b715439d80f4fc331d285c00f48c229c389810001000089f029d88b991c0100002b812001000083fb07", argdata, 2, 5, &func);
}

void ShipSystem::AddDamage(int amount)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1141::func;
	return execfunc(this, amount);
}

namespace _func1142
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::destructor", typeid(void (ShipSystem::*)()), "5589e557565389ce8d5e6883e4f083ec308b4160c701????????c74108????????894c2420890424", argdata, 1, 5, &func);
}

void ShipSystem::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1142::func;
	return execfunc(this);
}

namespace _func1143
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::BlockedBoosted", typeid(bool (ShipSystem::*)(bool )), "5589e55383e4f0807d080074??31c080794c008b911c0100008b595474??0fb681ad010000", argdata, 2, 1, &func);
}

bool ShipSystem::BlockedBoosted(bool countLimit)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool countLimit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1143::func;
	return execfunc(this, countLimit);
}

namespace _func1144
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxesPlain", typeid(int (*)(int , int , int , int , int , int , int , int )), "55b840000000", argdata, 8, 2, &func);
}

int ShipSystem::RenderPowerBoxesPlain(int x, int y, int width, int height, int gap, int current, int temp, int max)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int current_arg, int temp_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1144::func;
	return execfunc(x, y, width, height, gap, current, temp, max);
}

namespace _func1145
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderSystemSymbol", typeid(void (ShipSystem::*)(bool , int )), "578d????0883e4f0ff????5589e557565389cb83ec4c8b????8b0985f60f88????????31ffc6????008b41143d????????0f85????????8b4b408d??d08904??894c????e8????????85f675??", argdata, 3, 5, &func);
}

void ShipSystem::RenderSystemSymbol(bool forPowerUI, int forceColor)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool forPowerUI_arg, int forceColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1145::func;
	return execfunc(this, forPowerUI, forceColor);
}

namespace _func1146
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLockTimer", typeid(TimerHelper (ShipSystem::*)()), "8b54????89c88b8a2c010000", argdata, 2, 1, &func);
}

TimerHelper ShipSystem::GetLockTimer()
{
	typedef TimerHelper __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1146::func;
	return execfunc(this);
}

GL_Primitive **ShipSystem__glowBlue;

namespace _var1147
{
    static VariableDefinition varObj("ShipSystem__glowBlue", "f30f11542404c7042400000000e8????????a1(???????\?)890424e8????????e8????????", &ShipSystem__glowBlue);
}

GL_Primitive **ShipSystem__glowWhite;

namespace _var1148
{
    static VariableDefinition varObj("ShipSystem__glowWhite", "c7042400000000f30f11442404e8????????a1(???????\?)890424", &ShipSystem__glowWhite);
}

GL_Primitive **ShipSystem__glowRed;

namespace _var1149
{
    static VariableDefinition varObj("ShipSystem__glowRed", "f30f11742404c7042400000000e8????????a1(???????\?)890424", &ShipSystem__glowRed);
}

GL_Primitive **ShipSystem__manningOutline;

namespace _var1150
{
    static VariableDefinition varObj("ShipSystem__manningOutline", "a1(???????\?)bef0ffffffbb10000000890424e8????????", &ShipSystem__manningOutline);
}

GL_Primitive **ShipSystem__manningWhite;

namespace _var1151
{
    static VariableDefinition varObj("ShipSystem__manningWhite", "a1(???????\?)bef0ffffffbb10000000e9????????a1(???????\?)bee8ffffffbb18000000e9????????a1(???????\?)bee8ffffffbb18000000e9????????", &ShipSystem__manningWhite);
}

GL_Primitive **ShipSystem__manningGreen;

namespace _var1152
{
    static VariableDefinition varObj("ShipSystem__manningGreen", "", &ShipSystem__manningGreen);
}

GL_Primitive **ShipSystem__manningYellow;

namespace _var1153
{
    static VariableDefinition varObj("ShipSystem__manningYellow", "", &ShipSystem__manningYellow);
}

GL_Primitive **ShipSystem__manningBarOn;

namespace _var1154
{
    static VariableDefinition varObj("ShipSystem__manningBarOn", "a1(???????\?)74??c704240100000089f9f30f114dcce8????????83ec0484c0a1(???????\?)0f4505(???????\?)f30f104dcc", &ShipSystem__manningBarOn);
}

GL_Primitive **ShipSystem__manningBarOff;

namespace _var1155
{
    static VariableDefinition varObj("ShipSystem__manningBarOff", "", &ShipSystem__manningBarOff);
}

GL_Primitive **ShipSystem__manningBarIon;

namespace _var1156
{
    static VariableDefinition varObj("ShipSystem__manningBarIon", "", &ShipSystem__manningBarIon);
}

GL_Primitive **ShipSystem__lockBlue;

namespace _var1157
{
    static VariableDefinition varObj("ShipSystem__lockBlue", "8b1d(???????\?)83faff895dbc0f85????????8b1d(???????\?)c745c8ff000000baff000000c745ccff000000895dbce9????????a1(???????\?)", &ShipSystem__lockBlue);
}

GL_Primitive **ShipSystem__lockWhite;

namespace _var1158
{
    static VariableDefinition varObj("ShipSystem__lockWhite", "", &ShipSystem__lockWhite);
}

GL_Primitive **ShipSystem__lockHack;

namespace _var1159
{
    static VariableDefinition varObj("ShipSystem__lockHack", "", &ShipSystem__lockHack);
}

GL_Primitive **ShipSystem__sabotageImage;

namespace _var1160
{
    static VariableDefinition varObj("ShipSystem__sabotageImage", "a1(???????\?)890424e8????????c744240800000000c74424040000c0c1c7042400000000", &ShipSystem__sabotageImage);
}

GL_Primitive **ShipSystem__fireImage;

namespace _var1161
{
    static VariableDefinition varObj("ShipSystem__fireImage", "a1(???????\?)890424e8????????c744240800000000c74424040000b0c1c7042400000000e8????????f30f105dd4", &ShipSystem__fireImage);
}

namespace _func1162
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(const std::string &, float , bool )), "578d7c240883e4f0ff77fc5589e557565331db81ec????????8039008b07f30f104704f30f11458889458c74??80b9b80000000075??", argdata, 4, 1, &func);
}

int SoundControl::PlaySoundMix(const std::string &soundName, float volume, bool loop)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &soundName_arg, float volume_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1162::func;
	return execfunc(this, soundName, volume, loop);
}

namespace _func1163
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::StopPlaylist", typeid(void (SoundControl::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148039008b0774??890424e8????????83ec048b7dfcc98d67f8", argdata, 2, 5, &func);
}

void SoundControl::StopPlaylist(int fadeOut)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SoundControl *this_arg, int fadeOut_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1163::func;
	return execfunc(this, fadeOut);
}

namespace _func1164
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::StartPlaylist", typeid(void (SoundControl::*)(std::vector<std::string> &)), "578d7c240883e4f0ff77fc5589e557565383ec5c8039008b078945b0", argdata, 2, 5, &func);
}

void SoundControl::StartPlaylist(std::vector<std::string> &playlist)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SoundControl *this_arg, std::vector<std::string> &playlist_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1164::func;
	return execfunc(this, playlist);
}

namespace _func1165
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::UpdateSoundLoop", typeid(void (SoundControl::*)(const std::string &, float )), "578d????0883e4??ff????5589e557565383ec??8039??8b??f30f10????", argdata, 3, 5, &func);
}

void SoundControl::UpdateSoundLoop(const std::string &loopId, float count)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &loopId_arg, float count_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1165::func;
	return execfunc(this, loopId, count);
}

SoundControl *Global_SoundControl_Sounds;

namespace _var1166
{
    static VariableDefinition varObj("Global_SoundControl_Sounds", "!8b4b08e8????????0fb6c0b9(???????\?)890424e8????????b9", &Global_SoundControl_Sounds);
}

namespace _func1167
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::UpdateAimingAngle", typeid(float (SpaceDrone::*)(Pointf , float , float )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b178b7704f30f1089400100000f2e0d????????", argdata, 4, 1, &func);
}

float SpaceDrone::UpdateAimingAngle(Pointf location, float percentage, float forceDesired)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Pointf location_arg, float percentage_arg, float forceDesired_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1167::func;
	return execfunc(this, location, percentage, forceDesired);
}

namespace _func1168
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetDeployed", typeid(void (SpaceDrone::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b5030", argdata, 2, 5, &func);
}

void SpaceDrone::SetDeployed(bool deployed)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, bool deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1168::func;
	return execfunc(this, deployed);
}

namespace _func1169
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetMovementTarget", typeid(void (SpaceDrone::*)(Targetable *)), "5589e556538b750883e4f085f674??8b0689cb89f1ff501c89434c8b0689f1ff501c894348", argdata, 2, 5, &func);
}

void SpaceDrone::SetMovementTarget(Targetable *target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1169::func;
	return execfunc(this, target);
}

namespace _func1170
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::CollisionMoving", typeid(CollisionResponse (SpaceDrone::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83c10483ec3c8b378b4728c741fc00000000c7442404000000cfc70424000000cf8945e0", argdata, 6, 1, &func);
}

CollisionResponse SpaceDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1170::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1171
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceDrone::GetNextProjectile", typeid(Projectile *(SpaceDrone::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c0000008b01ff507c8b0389d9ff908000000084c0", argdata, 1, 1, &func);
}

Projectile *SpaceDrone::GetNextProjectile()
{
	typedef Projectile *__attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1171::func;
	return execfunc(this);
}

namespace _func1172
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::constructor", typeid(void (SpaceDrone::*)(int , int , DroneBlueprint *)), "578d????0883e4f0ff????5589e557565389cb83c150", argdata, 4, 5, &func);
}

void SpaceDrone::constructor(int iShipId, int selfId, DroneBlueprint *blueprint)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, int iShipId_arg, int selfId_arg, DroneBlueprint *blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1172::func;
	return execfunc(this, iShipId, selfId, blueprint);
}

namespace _func1173
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceDrone::destructor", typeid(void (SpaceDrone::*)()), "558d9118030000", argdata, 1, 5, &func);
}

void SpaceDrone::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1173::func;
	return execfunc(this);
}

namespace _func1174
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::constructor", typeid(void (SpaceManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d490c8db3640100008dbbd001000083ec1cc741f400000000c741f800000000", argdata, 1, 5, &func);
}

void SpaceManager::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1174::func;
	return execfunc(this);
}

namespace _func1175
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(int (SpaceManager::*)()), ".0fb68188030000c6818803000000", argdata, 1, 1, &func);
}

int SpaceManager::GetScreenShake()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1175::func;
	return execfunc(this);
}

namespace _func1176
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(void (SpaceManager::*)(int )), ".578d7c240883e4f0ff77fc", argdata, 2, 5, &func);
}

void SpaceManager::SaveSpace(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1176::func;
	return execfunc(this, fileHelper);
}

namespace _func1177
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBeacon", typeid(ImageDesc (SpaceManager::*)()), ".8b54240489c88b8ae802000089088b8aec0200008948048b8af00200008948088b8af4020000", argdata, 2, 1, &func);
}

ImageDesc SpaceManager::SwitchBeacon()
{
	typedef ImageDesc __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1177::func;
	return execfunc(this);
}

namespace _func1178
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(ImageDesc (SpaceManager::*)(const std::string &)), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 3, 1, &func);
}

ImageDesc SpaceManager::SwitchPlanet(const std::string &name)
{
	typedef ImageDesc __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1178::func;
	return execfunc(this, name);
}

namespace _func1179
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::UpdatePlanetImage", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void SpaceManager::UpdatePlanetImage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1179::func;
	return execfunc(this);
}

namespace _func1180
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x701, 0x701, 0x701};
	static FunctionDefinition funcObj("SpaceManager::SwitchImages", typeid(void (SpaceManager::*)(ImageDesc , ImageDesc , ImageDesc )), ".578d7c240883e4f0", argdata, 4, 5, &func);
}

void SpaceManager::SwitchImages(ImageDesc planet, ImageDesc unk1, ImageDesc unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, ImageDesc planet_arg, ImageDesc unk1_arg, ImageDesc unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1180::func;
	return execfunc(this, planet, unk1, unk2);
}

namespace _func1181
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(ImageDesc (SpaceManager::*)(const std::string &)), ".578d7c240883e4f0", argdata, 3, 1, &func);
}

ImageDesc SpaceManager::SwitchBackground(const std::string &name)
{
	typedef ImageDesc __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1181::func;
	return execfunc(this, name);
}

namespace _func1182
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(void (SpaceManager::*)(int , bool )), ".5789ca83c10c8d7c2408", argdata, 3, 5, &func);
}

void SpaceManager::StartAsteroids(int shieldCount, bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int shieldCount_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1182::func;
	return execfunc(this, shieldCount, unk);
}

namespace _func1183
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????", argdata, 3, 5, &func);
}

void SpaceManager::SetPlanetaryDefense(char state, int target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, char state_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1183::func;
	return execfunc(this, state, target);
}

namespace _func1184
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(void (SpaceManager::*)(bool )), ".578d7c240883e4f0ff77fc5589f889e557", argdata, 2, 5, &func);
}

void SpaceManager::SetPulsarLevel(bool pulsarLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool pulsarLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1184::func;
	return execfunc(this, pulsarLevel);
}

namespace _func1185
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::DangerousEnvironment", typeid(bool (SpaceManager::*)()), ".0fb6919802000084d274??83b99c0200000174??", argdata, 1, 1, &func);
}

bool SpaceManager::DangerousEnvironment()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1185::func;
	return execfunc(this);
}

namespace _func1186
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::MouseMove", typeid(void (SpaceManager::*)(int , int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b07", argdata, 4, 5, &func);
}

void SpaceManager::MouseMove(int x, int y, int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int x_arg, int y_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1186::func;
	return execfunc(this, x, y, unk);
}

namespace _func1187
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetSelectedDrone", typeid(SpaceDrone *(SpaceManager::*)(int , int , int )), ".578d7c240883e4f0ff77fc5589e557565383ec2c8b078b91a80000008945e0", argdata, 4, 1, &func);
}

SpaceDrone *SpaceManager::GetSelectedDrone(int x, int y, int unk)
{
	typedef SpaceDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int x_arg, int y_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1187::func;
	return execfunc(this, x, y, unk);
}

namespace _func1188
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), ".57660fefc08d7c240883e4f0ff77fc5589e5575383ec2080b9dc02000000", argdata, 1, 1, &func);
}

float SpaceManager::GetFlashOpacity()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1188::func;
	return execfunc(this);
}

namespace _func1189
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetColorTint", typeid(GL_Color (SpaceManager::*)()), ".5589c80f2805????????89e58b55080f110180ba600300000075??f30f100d????????", argdata, 2, 1, &func);
}

GL_Color SpaceManager::GetColorTint()
{
	typedef GL_Color __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1189::func;
	return execfunc(this);
}

namespace _func1190
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderBackground", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

void SpaceManager::OnRenderBackground()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1190::func;
	return execfunc(this);
}

namespace _func1191
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderFleet", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void SpaceManager::OnRenderFleet()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1191::func;
	return execfunc(this);
}

namespace _func1192
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void SpaceManager::OnRenderForeground()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1192::func;
	return execfunc(this);
}

namespace _func1193
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(void (SpaceManager::*)(int )), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

void SpaceManager::SetDangerZone(int fleetType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fleetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1193::func;
	return execfunc(this, fleetType);
}

namespace _func1194
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderAsteroids", typeid(void (SpaceManager::*)(int , float )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 3, 5, &func);
}

void SpaceManager::OnRenderAsteroids(int fieldLayers, float unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fieldLayers_arg, float unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1194::func;
	return execfunc(this, fieldLayers, unk2);
}

namespace _func1195
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderProjectiles", typeid(void (SpaceManager::*)(int , int )), ".578d7c240883e4f0ff77fc5589f889e5575653", argdata, 3, 5, &func);
}

void SpaceManager::OnRenderProjectiles(int iShipId, int layerCommand)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int iShipId_arg, int layerCommand_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1195::func;
	return execfunc(this, iShipId, layerCommand);
}

namespace _func1196
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557568d45d8", argdata, 1, 5, &func);
}

void SpaceManager::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1196::func;
	return execfunc(this);
}

namespace _func1197
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::Restart", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e55756", argdata, 1, 5, &func);
}

void SpaceManager::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1197::func;
	return execfunc(this);
}

namespace _func1198
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), ".c6818802000000c6818902000000c6819802000000c7819c02000002000000", argdata, 1, 5, &func);
}

void SpaceManager::ClearEnvironment()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1198::func;
	return execfunc(this);
}

namespace _func1199
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::Clear", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 1, 5, &func);
}

void SpaceManager::Clear()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1199::func;
	return execfunc(this);
}

namespace _func1200
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::ClearProjectiles", typeid(void (SpaceManager::*)()), ".5589e55756538b1189ce", argdata, 1, 5, &func);
}

void SpaceManager::ClearProjectiles()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1200::func;
	return execfunc(this);
}

namespace _func1201
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::UpdateProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".578d7c240883e4f0ff77fc5589e557", argdata, 2, 5, &func);
}

void SpaceManager::UpdateProjectile(Projectile *proj)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1201::func;
	return execfunc(this, proj);
}

namespace _func1202
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::TransferProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".5589e556538b5d0883e4f0", argdata, 2, 5, &func);
}

void SpaceManager::TransferProjectile(Projectile *proj)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1202::func;
	return execfunc(this, proj);
}

namespace _func1203
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddShip", typeid(void (SpaceManager::*)(ShipManager *)), ".578d7c240883e4f0ff77fc5589f8", argdata, 2, 5, &func);
}

void SpaceManager::AddShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1203::func;
	return execfunc(this, ship);
}

namespace _func1204
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddProjectile", typeid(void (SpaceManager::*)(Projectile *)), ".578d7c240883e4f0ff77fc5589e55783ec148b41043b410874??85c08b17", argdata, 2, 5, &func);
}

void SpaceManager::AddProjectile(Projectile *proj)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1204::func;
	return execfunc(this, proj);
}

namespace _func1205
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(void (SpaceManager::*)(int )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

void SpaceManager::LoadSpace(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1205::func;
	return execfunc(this, fileHelper);
}

namespace _func1206
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::UpdatePDS", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void SpaceManager::UpdatePDS()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1206::func;
	return execfunc(this);
}

namespace _func1207
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoopNebulas", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

void SpaceManager::OnLoopNebulas()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1207::func;
	return execfunc(this);
}

namespace _func1208
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(void (SpaceManager::*)()), ".578d7c240883e4f0ff77fc5589e557", argdata, 1, 5, &func);
}

void SpaceManager::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1208::func;
	return execfunc(this);
}

namespace _func1209
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)(bool )), ".578d7c240883e4f0ff77fc5589e55756", argdata, 2, 5, &func);
}

void SpaceManager::SetNebula(bool state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1209::func;
	return execfunc(this, state);
}

namespace _func1210
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)(bool )), ".578d7c240883e4f0ff77fc5589e5", argdata, 2, 5, &func);
}

void SpaceManager::SetStorm(bool state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1210::func;
	return execfunc(this, state);
}

namespace _func1211
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(void (SpaceManager::*)(bool )), "578d7c240883e4f0ff77fc5589f889e55756538d99b802000089cf8d75d083ec3c8b0088818802000089d9", argdata, 2, 5, &func);
}

void SpaceManager::SetFireLevel(bool state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1211::func;
	return execfunc(this, state);
}

namespace _func1212
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("SpaceStatus::OnInit", typeid(void (SpaceStatus::*)(SpaceManager *, Point )), "578d????0883e4??ff????5589e557565389cb89de81ec????????", argdata, 3, 5, &func);
}

void SpaceStatus::OnInit(SpaceManager *space, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, SpaceManager *space_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1212::func;
	return execfunc(this, space, pos);
}

namespace _func1213
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceStatus::RenderWarningText", typeid(void (SpaceStatus::*)(int , int )), "578d????0883e4f0ff????5589e557565381ecac0000008b7160", argdata, 3, 5, &func);
}

void SpaceStatus::RenderWarningText(int effect, int textOffset)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int effect_arg, int textOffset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1213::func;
	return execfunc(this, effect, textOffset);
}

namespace _func1214
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceStatus::OnRender", typeid(void (SpaceStatus::*)()), "578d????0883e4f0ff????5589e557565389cb83ec2c8b492c", argdata, 1, 5, &func);
}

void SpaceStatus::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1214::func;
	return execfunc(this);
}

namespace _func1215
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceStatus::MouseMove", typeid(void (SpaceStatus::*)(int , int )), "578d????0883e4f0ff????5589e557565389cb83ec4c8b??8b4130", argdata, 3, 5, &func);
}

void SpaceStatus::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1215::func;
	return execfunc(this, mX, mY);
}

namespace _func1216
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("StarMap::SetPosition", typeid(void (StarMap::*)(Point )), "5589e58b45088b550c5d89415c895160c208008d", argdata, 2, 5, &func);
}

void StarMap::SetPosition(Point unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1216::func;
	return execfunc(this, unk0);
}

namespace _func1217
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::KeyDown", typeid(void (StarMap::*)(int )), ".80b91007000000741a5653837c240c31741e837c", argdata, 2, 5, &func);
}

void StarMap::KeyDown(int unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1217::func;
	return execfunc(this, unk0);
}

namespace _func1218
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetNextDangerMove", typeid(int (StarMap::*)()), ".56538b999804000085db78??83fb0119d283e2e083c24083fb0119c0", argdata, 1, 1, &func);
}

int StarMap::GetNextDangerMove()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1218::func;
	return execfunc(this);
}

namespace _func1219
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::Open", typeid(void (StarMap::*)()), ".80790400740ac389f68dbc2700000000578d7c24", argdata, 1, 5, &func);
}

void StarMap::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1219::func;
	return execfunc(this);
}

namespace _func1220
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::Close", typeid(void (StarMap::*)()), ".80b9c0060000000f85b6000000578d7c240883e4", argdata, 1, 5, &func);
}

void StarMap::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1220::func;
	return execfunc(this);
}

namespace _func1221
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetOpen", typeid(void (StarMap::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 2, 5, &func);
}

void StarMap::SetOpen(bool unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1221::func;
	return execfunc(this, unk0);
}

namespace _func1222
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitMapTitle", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce8d", argdata, 1, 5, &func);
}

void StarMap::InitMapTitle()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1222::func;
	return execfunc(this);
}

namespace _func1223
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitNoFuelText", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8d", argdata, 1, 5, &func);
}

void StarMap::InitNoFuelText()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1223::func;
	return execfunc(this);
}

namespace _func1224
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitBossMessageBox", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 1, 5, &func);
}

void StarMap::InitBossMessageBox()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1224::func;
	return execfunc(this);
}

namespace _func1225
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnLanguageChange", typeid(void (StarMap::*)()), ".5589e55389cb83e4f0e812f7ffff89d9e8ebfaff", argdata, 1, 5, &func);
}

void StarMap::OnLanguageChange()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1225::func;
	return execfunc(this);
}

namespace _func1226
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetRandomSectorChoice", typeid(int (StarMap::*)()), ".5589e583e4f0803d????????007435e8a46e1500", argdata, 1, 1, &func);
}

int StarMap::GetRandomSectorChoice()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1226::func;
	return execfunc(this);
}

namespace _func1227
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::NeighboringSector", typeid(void (StarMap::*)(int )), ".565331c08b5c240c85db78438bb1fc0600008b91", argdata, 2, 5, &func);
}

void StarMap::NeighboringSector(int unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1227::func;
	return execfunc(this, unk0);
}

namespace _func1228
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetSelectedSector", typeid(void (StarMap::*)(int , int , int )), ".578d7c240883e4f0ff77fc5589fa89e557565389", argdata, 4, 5, &func);
}

void StarMap::GetSelectedSector(int unk0, int unk1, int unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg, int unk1_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1228::func;
	return execfunc(this, unk0, unk1, unk2);
}

namespace _func1229
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::StartSecretSector", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e55756538d75d0", argdata, 1, 5, &func);
}

void StarMap::StartSecretSector()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1229::func;
	return execfunc(this);
}

namespace _func1230
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ReachSector", typeid(void (StarMap::*)(Sector *)), ".578d7c240883e4f0ff77fc5589e557565383ec6c", argdata, 2, 5, &func);
}

void StarMap::ReachSector(Sector *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1230::func;
	return execfunc(this, unk0);
}

namespace _func1231
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::UpdateSectorMap", typeid(void (StarMap::*)(Sector *)), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 5, &func);
}

void StarMap::UpdateSectorMap(Sector *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1231::func;
	return execfunc(this, unk0);
}

namespace _func1232
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SaveGame", typeid(void (StarMap::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 5, &func);
}

void StarMap::SaveGame(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1232::func;
	return execfunc(this, file);
}

namespace _func1233
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitStatistics", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000f3c38db4", argdata, 1, 5, &func);
}

void StarMap::InitStatistics()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1233::func;
	return execfunc(this);
}

namespace _func1234
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::PrintStatistics", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000f3c38db4", argdata, 1, 5, &func);
}

void StarMap::PrintStatistics()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1234::func;
	return execfunc(this);
}

namespace _func1235
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AnalyzeMap", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc27000000008b442404", argdata, 1, 5, &func);
}

void StarMap::AnalyzeMap()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1235::func;
	return execfunc(this);
}

namespace _func1236
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ModifyPursuit", typeid(void (StarMap::*)(int )), ".8b442404018198040000c2040090669031c083b9", argdata, 2, 5, &func);
}

void StarMap::ModifyPursuit(int unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1236::func;
	return execfunc(this, unk0);
}

namespace _func1237
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AtBeacon", typeid(void (StarMap::*)()), ".31c083b9800000003b7f4656538b999804000085", argdata, 1, 5, &func);
}

void StarMap::AtBeacon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1237::func;
	return execfunc(this);
}

namespace _func1238
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetWaitLocation", typeid(void (StarMap::*)()), ".80797c00741a80b9ac060000007411c6417c00c6", argdata, 1, 5, &func);
}

void StarMap::GetWaitLocation()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1238::func;
	return execfunc(this);
}

namespace _func1239
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::StartBeacon", typeid(void (StarMap::*)()), ".8b919004000031c085d27e04c38d760056538b71", argdata, 1, 5, &func);
}

void StarMap::StartBeacon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1239::func;
	return execfunc(this);
}

namespace _func1240
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationsConnected", typeid(void (StarMap::*)(Location *, Location *)), ".538b4424088b5c240c8b48088b500c29cac1fa02", argdata, 3, 5, &func);
}

void StarMap::LocationsConnected(Location *unk0, Location *unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg, Location *unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1240::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1241
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PointToGrid", typeid(Point (StarMap::*)(float , float )), ".578d7c240883e4f0ff77fc5589e5578d4df083ec", argdata, 3, 9, &func);
}

Point StarMap::PointToGrid(float x, float y)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, float x_arg, float y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1241::func;
	return execfunc(this, x, y);
}

namespace _func1242
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::TravelToLocation", typeid(void (StarMap::*)(Location *)), ".538b44240880787c008941507404c6407c008b58", argdata, 2, 5, &func);
}

void StarMap::TravelToLocation(Location *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1242::func;
	return execfunc(this, unk0);
}

namespace _func1243
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ForceExitBeacon", typeid(void (StarMap::*)()), ".8b4150c6401401c3908db42600000000f3c38db4", argdata, 1, 5, &func);
}

void StarMap::ForceExitBeacon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1243::func;
	return execfunc(this);
}

namespace _func1244
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnRenderFogEffect", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000568b9174", argdata, 1, 5, &func);
}

void StarMap::OnRenderFogEffect()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1244::func;
	return execfunc(this);
}

namespace _func1245
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasBoss", typeid(void (StarMap::*)(Location *)), ".568b917408000031c0538b99680800008b74240c", argdata, 2, 5, &func);
}

void StarMap::LocationHasBoss(Location *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1245::func;
	return execfunc(this, unk0);
}

namespace _func1246
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasStore", typeid(void (StarMap::*)(Location *)), ".56538b54240c8b422085c074258b801c06000085", argdata, 2, 5, &func);
}

void StarMap::LocationHasStore(Location *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1246::func;
	return execfunc(this, unk0);
}

namespace _func1247
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasShip", typeid(void (StarMap::*)(Location *)), ".8b4424048b402085c074070fb6401cc2040031c0", argdata, 2, 5, &func);
}

void StarMap::LocationHasShip(Location *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1247::func;
	return execfunc(this, unk0);
}

namespace _func1248
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AdvanceWorldLevel", typeid(void (StarMap::*)()), ".8b819004000083c00183f8038981900400007f01", argdata, 1, 5, &func);
}

void StarMap::AdvanceWorldLevel()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1248::func;
	return execfunc(this);
}

namespace _func1249
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ReverseBossPath", typeid(void (StarMap::*)()), ".568b8174080000538b997808000080b170080000", argdata, 1, 5, &func);
}

void StarMap::ReverseBossPath()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1249::func;
	return execfunc(this);
}

namespace _func1250
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ForceBossJump", typeid(void (StarMap::*)()), ".80b97008000000c6817108000001751a8b817808", argdata, 1, 5, &func);
}

void StarMap::ForceBossJump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1250::func;
	return execfunc(this);
}

namespace _func1251
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ClearBoss", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565331db89", argdata, 1, 5, &func);
}

void StarMap::ClearBoss()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1251::func;
	return execfunc(this);
}

namespace _func1252
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), ".8b4424048981e4090000c2040090669031c083b9", argdata, 2, 5, &func);
}

void StarMap::SetBossStage(int stage)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int stage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1252::func;
	return execfunc(this, stage);
}

namespace _func1253
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::CheckGameOver", typeid(void (StarMap::*)()), ".31c083b96c080000047405f3c38d76008b817408", argdata, 1, 5, &func);
}

void StarMap::CheckGameOver()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1253::func;
	return execfunc(this);
}

namespace _func1254
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::RenderLabels", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cf81", argdata, 1, 5, &func);
}

void StarMap::RenderLabels()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1254::func;
	return execfunc(this);
}

namespace _func1255
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::DeleteMap", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b81d80900008b99dc09000039d8", argdata, 1, 5, &func);
}

void StarMap::DeleteMap()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1255::func;
	return execfunc(this);
}

namespace _func1256
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseClick", typeid(void (StarMap::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 3, 5, &func);
}

void StarMap::MouseClick(int unk0, int unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg, int unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1256::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1257
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AddSectorColumn", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cebb", argdata, 1, 5, &func);
}

void StarMap::AddSectorColumn()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1257::func;
	return execfunc(this);
}

namespace _func1258
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::PushSectorColumn", typeid(void (StarMap::*)()), ".5589e557565389cf83e4f083ec208b81fc060000", argdata, 1, 5, &func);
}

void StarMap::PushSectorColumn()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1258::func;
	return execfunc(this);
}

namespace _func1259
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SelectNewSector", typeid(void (StarMap::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 5, &func);
}

void StarMap::SelectNewSector(int unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1259::func;
	return execfunc(this, unk0);
}

namespace _func1260
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GenerateSectorMap", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb81", argdata, 1, 5, &func);
}

void StarMap::GenerateSectorMap()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1260::func;
	return execfunc(this);
}

namespace _func1261
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::constructor", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8d", argdata, 1, 5, &func);
}

void StarMap::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1261::func;
	return execfunc(this);
}

namespace _func1262
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("StarMap::RenderSectorName", typeid(void (StarMap::*)(Sector *, GL_Color )), ".578d7c240883e4f0ff77fc5589e55756538d85d0", argdata, 3, 5, &func);
}

void StarMap::RenderSectorName(Sector *unk0, GL_Color unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg, GL_Color unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1262::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1263
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::UpdateDangerZone", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4c80b9c0060000000f85????????80b980080000000f85????????8bb38000000083fe3b0f8f????????89d9e8????????01f083f83b898380000000", argdata, 1, 5, &func);
}

void StarMap::UpdateDangerZone()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1263::func;
	return execfunc(this);
}

namespace _func1264
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetNewLocation", typeid(Location *(StarMap::*)()), ".31c080797c00747880b9ac06000000755c5589e5", argdata, 1, 1, &func);
}

Location *StarMap::GetNewLocation()
{
	typedef Location *__attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1264::func;
	return execfunc(this);
}

namespace _func1265
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnLoop", typeid(void (StarMap::*)()), ".80790400750ac389f68dbc2700000000578d7c24", argdata, 1, 5, &func);
}

void StarMap::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1265::func;
	return execfunc(this);
}

namespace _func1266
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateEvents", typeid(void (StarMap::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????8b81a00600008b919c0600008b37898de8feffff898504ffffff29d0c1f802", argdata, 2, 5, &func);
}

void StarMap::GenerateEvents(bool tutorial)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool tutorial_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1266::func;
	return execfunc(this, tutorial);
}

namespace _func1267
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddConnections", typeid(void (StarMap::*)(Location *)), ".578d7c240883e4f0ff77fc5589e557565383ec2c", argdata, 2, 5, &func);
}

void StarMap::AddConnections(Location *unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1267::func;
	return execfunc(this, unk0);
}

namespace _func1268
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::MapConnected", typeid(void (StarMap::*)()), ".578d810c0a00008d7c240883e4f0ff77fc5589e5", argdata, 1, 5, &func);
}

void StarMap::MapConnected()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1268::func;
	return execfunc(this);
}

namespace _func1269
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("StarMap::ConnectLocations", typeid(void (StarMap::*)(Point , Point )), ".578d7c240883e4f0ff77fc5589e5575653", argdata, 3, 5, &func);
}

void StarMap::ConnectLocations(Point unk0, Point unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg, Point unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1269::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1270
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("StarMap::PopulateGrid", typeid(void (StarMap::*)(Point )), ".5789c883c02c8d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

void StarMap::PopulateGrid(Point unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1270::func;
	return execfunc(this, unk0);
}

namespace _func1271
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PopClosestLoc", typeid(Location *(StarMap::*)(std::vector<Location*> &, std::map<Location*, int> &)), ".578d7c240883e4f0ff77fc5589e557565383ec4c8b07", argdata, 3, 1, &func);
}

Location *StarMap::PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map)
{
	typedef Location *__attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, std::vector<Location*> &vec_arg, std::map<Location*, int> &map_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1271::func;
	return execfunc(this, vec, map);
}

namespace _func1272
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddQuest", typeid(bool (StarMap::*)(const std::string &, bool )), ".578d7c240883e4f0ff77fc5589f889e557565389cf83ec5c8b100fb64004", argdata, 3, 1, &func);
}

bool StarMap::AddQuest(const std::string &questEvent, bool force)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, const std::string &questEvent_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1272::func;
	return execfunc(this, questEvent, force);
}

namespace _func1273
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateMap", typeid(Location *(StarMap::*)(bool , bool )), ".578d7c240883e4f0ff77fc5589e557565381ec????????", argdata, 3, 1, &func);
}

Location *StarMap::GenerateMap(bool tutorial, bool seed)
{
	typedef Location *__attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool tutorial_arg, bool seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1273::func;
	return execfunc(this, tutorial, seed);
}

namespace _func1274
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::NewGame", typeid(Location *(StarMap::*)(bool )), ".578d7c240883e4f0ff77fc5589e557565389ce83", argdata, 2, 1, &func);
}

Location *StarMap::NewGame(bool unk0)
{
	typedef Location *__attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1274::func;
	return execfunc(this, unk0);
}

namespace _func1275
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::Dijkstra", typeid(std::vector<Location*> (StarMap::*)(Location *, Location *, bool )), ".578d7c240883e4f0ff77fc5589f889e557565381", argdata, 5, 1, &func);
}

std::vector<Location*> StarMap::Dijkstra(Location *start, Location *finish, bool include_unknown)
{
	typedef std::vector<Location*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *start_arg, Location *finish_arg, bool include_unknown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1275::func;
	return execfunc(this, start, finish, include_unknown);
}

namespace _func1276
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseMove", typeid(void (StarMap::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565381ec8c", argdata, 3, 5, &func);
}

void StarMap::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1276::func;
	return execfunc(this, x, y);
}

namespace _func1277
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::OnTouch", typeid(void (StarMap::*)(TouchAction , int , int , int , int , int )), ".578d7c240883e4f0ff77fc5589e557565389ce81", argdata, 7, 5, &func);
}

void StarMap::OnTouch(TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, TouchAction unk0_arg, int unk1_arg, int unk2_arg, int unk3_arg, int unk4_arg, int unk5_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1277::func;
	return execfunc(this, unk0, unk1, unk2, unk3, unk4, unk5);
}

namespace _func1278
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LoadGame", typeid(Location *(StarMap::*)(int )), ".578d7c240883e4f0ff77fc5589f889e557565389", argdata, 2, 1, &func);
}

Location *StarMap::LoadGame(int fileHelper)
{
	typedef Location *__attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1278::func;
	return execfunc(this, fileHelper);
}

namespace _func1279
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::RenderLeftInsetButton", typeid(void (StarMap::*)(float , float , bool )), ".578d7c240883e4f0ff77fc5589e557565389cb83", argdata, 4, 5, &func);
}

void StarMap::RenderLeftInsetButton(float unk0, float unk1, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, float unk0_arg, float unk1_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1279::func;
	return execfunc(this, unk0, unk1, unk2);
}

namespace _func1280
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::RenderDistressButtons", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e55756538d7dc8", argdata, 1, 5, &func);
}

void StarMap::RenderDistressButtons()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1280::func;
	return execfunc(this);
}

namespace _func1281
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::OnRender", typeid(void (StarMap::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb81ec????????80b91007000000", argdata, 1, 5, &func);
}

void StarMap::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1281::func;
	return execfunc(this);
}

namespace _func1282
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::DrawConnection", typeid(void (StarMap::*)(const Pointf &, const Pointf &, const GL_Color *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b078b57048b5f08894db889458089d689957cffffff8b5004", argdata, 4, 5, &func);
}

void StarMap::DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color *color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, const Pointf &pos1_arg, const Pointf &pos2_arg, const GL_Color *color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1282::func;
	return execfunc(this, pos1, pos2, color);
}

namespace _func1283
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::TurnIntoFleetLocation", typeid(void (StarMap::*)(Location *)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f8b4320c6431c01c6839c00000000", argdata, 2, 5, &func);
}

void StarMap::TurnIntoFleetLocation(Location *loc)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1283::func;
	return execfunc(this, loc);
}

namespace _func1284
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetLocationText", typeid(std::string (StarMap::*)(const Location *)), "578d41088d7c240883e4f0ff77fc5589e557565389ce83ec7c8b1f8d7dd08901", argdata, 3, 1, &func);
}

std::string StarMap::GetLocationText(const Location *loc)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, const Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1284::func;
	return execfunc(this, loc);
}

namespace _func1285
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetupNoFuel", typeid(void (StarMap::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????833fff8b77040f84????????8b81ac090000c68543ffffff00803d??????????c683c8090000018983ac090000", argdata, 3, 5, &func);
}

void StarMap::SetupNoFuel(int seed, const std::string &forceEscape)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int seed_arg, const std::string &forceEscape_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1285::func;
	return execfunc(this, seed, forceEscape);
}

namespace _func1286
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateNebulas", typeid(void (StarMap::*)(const std::vector<std::string> &)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b0789c78945888b40048b17", argdata, 2, 5, &func);
}

void StarMap::GenerateNebulas(const std::vector<std::string> &names)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, const std::vector<std::string> &names_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1286::func;
	return execfunc(this, names);
}

namespace _func1287
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::UpdateBoss", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b81680800008b91740800008b3c82", argdata, 1, 5, &func);
}

void StarMap::UpdateBoss()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1287::func;
	return execfunc(this);
}

namespace _func1288
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("StatusEffect::GetNebulaEffect", typeid(StatusEffect *(*)()), "5589e55383e4f083ec10803d??????????8b5d0874??660f6f05????????c703????????0f2905????????a1????????894304a1????????", argdata, 0, 2, &func);
}

StatusEffect *StatusEffect::GetNebulaEffect()
{
	typedef StatusEffect *__attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1288::func;
	return execfunc();
}

namespace _func1289
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::OnInit", typeid(void (Store::*)(ShipManager *, Equipment *, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b078b918c0400008945e48b47048945dc8b4708", argdata, 4, 5, &func);
}

void Store::OnInit(ShipManager *shopper, Equipment *equip, int worldLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *shopper_arg, Equipment *equip_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1289::func;
	return execfunc(this, shopper, equip, worldLevel);
}

namespace _func1290
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::CreateStoreBoxes", typeid(void (Store::*)(int , Equipment *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b178b47048955a08945a4", argdata, 3, 5, &func);
}

void Store::CreateStoreBoxes(int type, Equipment *equip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int type_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1290::func;
	return execfunc(this, type, equip);
}

namespace _func1291
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Store::KeyDown", typeid(bool (Store::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e55783ec1483b964060000028b077e??83f83189cf", argdata, 2, 1, &func);
}

bool Store::KeyDown(SDLKey key)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1291::func;
	return execfunc(this, key);
}

namespace _func1292
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::OnLoop", typeid(void (Store::*)()), "8b918c0400008b819004000029d0c1f80285c074??5589e5565389ce31db83e4f08b0c9a83c301", argdata, 1, 5, &func);
}

void Store::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1292::func;
	return execfunc(this);
}

namespace _func1293
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::Close", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c64104008b897c06000085c974??8b01c70424????????ff5030", argdata, 1, 5, &func);
}

void Store::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1293::func;
	return execfunc(this);
}

namespace _func1294
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::MouseMove", typeid(void (Store::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b378b7f04893424897c2404e8????????8b837c06000083ec0885c074??8d8b68010000897c2404893424", argdata, 3, 5, &func);
}

void Store::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1294::func;
	return execfunc(this, x, y);
}

namespace _func1295
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::constructor", typeid(void (Store::*)()), "5589e55389cb83e4f0e8????????8d43288d8b90000000c703????????c7432400000000c64328008943208d4344c6433801c7434000000000", argdata, 1, 5, &func);
}

void Store::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1295::func;
	return execfunc(this);
}

namespace _func1296
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Store::SaveStore", typeid(void (Store::*)(int )), "5589e557565389cb83e4f083ec208b8164060000894424048b4508890424e8????????8b836406000085c00f8e????????31f68b84b3680600008d3c76", argdata, 2, 5, &func);
}

void Store::SaveStore(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1296::func;
	return execfunc(this, file);
}

namespace _func1297
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::RelinkShip", typeid(void (Store::*)(ShipManager *, Equipment *)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b47048b1f8945e48999a40400008b898c0400008b8690040000", argdata, 3, 5, &func);
}

void Store::RelinkShip(ShipManager *ship, Equipment *equip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *ship_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1297::func;
	return execfunc(this, ship, equip);
}

namespace _func1298
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Store::HasType", typeid(bool (Store::*)(int )), "8b4424043b816806000074??3b816c06000074??3b817006000074??3981740600000f94c0c20400908db42600000000b8????????", argdata, 2, 1, &func);
}

bool Store::HasType(int type)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1298::func;
	return execfunc(this, type);
}

namespace _func1299
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::Clear", typeid(void (Store::*)()), "5589e55756538bb99004000089ce8b918c04000083e4f089f829d0c1f80285c074??31db8b0c9a85c9", argdata, 1, 5, &func);
}

void Store::Clear()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1299::func;
	return execfunc(this);
}

namespace _func1300
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Store::InitHeading", typeid(void (Store::*)(int , Point )), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c8b1f8d7da4c745a000000000c645a400897d9c", argdata, 3, 5, &func);
}

void Store::InitHeading(int index, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int index_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1300::func;
	return execfunc(this, index, pos);
}

namespace _func1301
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Store::DrawBuySellTabText", typeid(void (*)()), "8d4c240483e4f0ff71fc5589e5575653518d45d08d75a08d5dd881ec????????c745d873746f72c745dc655f746189442404", argdata, 0, 4, &func);
}

void Store::DrawBuySellTabText()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1301::func;
	return execfunc();
}

namespace _func1302
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::MouseClick", typeid(void (Store::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b7f04890424897c2404894584e8????????8b837c06000083ec08", argdata, 3, 5, &func);
}

void Store::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1302::func;
	return execfunc(this, x, y);
}

namespace _func1303
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::OnRender", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????e8????????8b837c06000085c074??0f2805????????c70424????????0f298518ffffff8b851cffffff89442404", argdata, 1, 5, &func);
}

void Store::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1303::func;
	return execfunc(this);
}

namespace _func1304
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::SetPositions", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e557565389cf31f683ec7cc64105018d4dd0c74424042a000000c70424????????e8????????83ec088b45d08b55d489f9", argdata, 1, 5, &func);
}

void Store::SetPositions()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1304::func;
	return execfunc(this);
}

namespace _func1305
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::LoadStore", typeid(void (Store::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b078b918c040000898550ffffff8b47048bb990040000898538ffffff89f8", argdata, 3, 5, &func);
}

void Store::LoadStore(int file, int worldLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int file_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1305::func;
	return execfunc(this, file, worldLevel);
}

namespace _func1306
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Store::SetPosition", typeid(void (Store::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570489042489542404e8????????", argdata, 2, 5, &func);
}

void Store::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1306::func;
	return execfunc(this, pos);
}

namespace _func1307
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::destructor", typeid(void (Store::*)()), "5589e557565331db89ce83e4f083ec108bb9900400008b918c040000c701????????89f829d0c1f80285c074??", argdata, 1, 5, &func);
}

void Store::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1307::func;
	return execfunc(this);
}

namespace _func1308
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::MouseClick", typeid(void (StoreBox::*)(int , int )), "8079640075??c208008db426000000008079650074??8b015589e583e4f0", argdata, 3, 5, &func);
}

void StoreBox::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1308::func;
	return execfunc(this, x, y);
}

namespace _func1309
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::Activate", typeid(void (StoreBox::*)()), "578d7c240883e4f0ff77fc5589e5575383ec308b81380100008b80d40400003981e80000007e??b9????????c70424????????8d5de8e8????????8d45e083ec04", argdata, 1, 5, &func);
}

void StoreBox::Activate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1309::func;
	return execfunc(this);
}

namespace _func1310
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::InitBlueprint", typeid(void (StoreBox::*)(Blueprint *)), "578d7c240883e4f0ff77fc5589e557565389ce81c1????????83ec4c8b1f8b83b8000000898170ffffff8d431c890424e8????????", argdata, 2, 5, &func);
}

void StoreBox::InitBlueprint(Blueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg, Blueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1310::func;
	return execfunc(this, bp);
}

namespace _func1311
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::constructor", typeid(void (StoreBox::*)(const std::string &, ShipManager *, Equipment *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b07c701????????c74104ffffffffc741080000000089c28945c48b47048945c08b470889d78b7704", argdata, 4, 5, &func);
}

void StoreBox::constructor(const std::string &buttonImage, ShipManager *shopper, Equipment *equip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg, const std::string &buttonImage_arg, ShipManager *shopper_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1311::func;
	return execfunc(this, buttonImage, shopper, equip);
}

namespace _func1312
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::OnLoop", typeid(void (StoreBox::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b913001000085d27e??80b9f80000000074??", argdata, 1, 5, &func);
}

void StoreBox::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1312::func;
	return execfunc(this);
}

namespace _func1313
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("StoreBox::SetPosition", typeid(void (StoreBox::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb8d4df083ec208b078b570489042489542404e8????????8b45f08b55f483ec08", argdata, 2, 5, &func);
}

void StoreBox::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1313::func;
	return execfunc(this, pos);
}

namespace _func1314
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::OnRender", typeid(void (StoreBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf8d492481ec????????80b920010000000f84????????e8????????", argdata, 1, 5, &func);
}

void StoreBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1314::func;
	return execfunc(this);
}

namespace _func1315
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::Purchase", typeid(void (StoreBox::*)()), "57ba????????8d7c240883e4f0ff77fc5589e55756538d7dd08d75d889cbb9????????83ec3c8975d0", argdata, 1, 5, &func);
}

void StoreBox::Purchase()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1315::func;
	return execfunc(this);
}

namespace _func1316
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SuperShieldDrone::constructor", typeid(void (SuperShieldDrone::*)(int , int , DroneBlueprint *)), "578d????0883e4??ff????5589e557565389cb8d??d883ec??8b????8b??8b????8d??d0", argdata, 4, 5, &func);
}

void SuperShieldDrone::constructor(int iShipId, int selfId, DroneBlueprint *blueprint)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SuperShieldDrone *this_arg, int iShipId_arg, int selfId_arg, DroneBlueprint *blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1316::func;
	return execfunc(this, iShipId, selfId, blueprint);
}

namespace _func1317
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SuperShieldDrone::OnLoop", typeid(void (SuperShieldDrone::*)()), "578d????0883e4f0ff????5589e557565389ce83ec4ce8????????8b16", argdata, 1, 5, &func);
}

void SuperShieldDrone::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SuperShieldDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1317::func;
	return execfunc(this);
}

namespace _func1318
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::OnRender", typeid(void (SystemBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c0fb641508b1fc781b401000000000000", argdata, 2, 5, &func);
}

void SystemBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1318::func;
	return execfunc(this, ignoreStatus);
}

namespace _func1319
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::constructor", typeid(void (SystemBox::*)(Point , ShipSystem *, bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d9e8000000081ec????????8b4f088b57048b078b7f0cc706????????", argdata, 4, 5, &func);
}

void SystemBox::constructor(Point pos, ShipSystem *sys, bool playerUI)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, bool playerUI_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1319::func;
	return execfunc(this, pos, sys, playerUI);
}

namespace _func1320
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::MouseMove", typeid(void (SystemBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b81800100008b7f0439c67e??03818801000039c6", argdata, 3, 5, &func);
}

void SystemBox::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1320::func;
	return execfunc(this, x, y);
}

namespace _func1321
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::MouseClick", typeid(bool (SystemBox::*)(bool )), "5589e5565389cb8b494c8b750883e4f0e8????????84c075??807b580075??89f084c075??8d65f831c0", argdata, 2, 1, &func);
}

bool SystemBox::MouseClick(bool shift)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1321::func;
	return execfunc(this, shift);
}

namespace _func1322
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::KeyDown", typeid(void (SystemBox::*)(SDLKey , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d5db883ec6c8b078945a48b470489459c8b414c8b10", argdata, 3, 5, &func);
}

void SystemBox::KeyDown(SDLKey key, bool shift)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, SDLKey key_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1322::func;
	return execfunc(this, key, shift);
}

namespace _func1323
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemControl::CreateSystemBoxes", typeid(void (SystemControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d4ddc83ec5cc744240400000000c70424????????e8????????8b45dc8b55e0", argdata, 1, 5, &func);
}

void SystemControl::CreateSystemBoxes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1323::func;
	return execfunc(this);
}

namespace _func1324
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemControl::GetSystemBox", typeid(SystemBox *(SystemControl::*)(int )), "8b51088b410c29d0c1f80285c074??5589e557565389ce31db83e4f0eb??66908b4140", argdata, 2, 1, &func);
}

SystemBox *SystemControl::GetSystemBox(int systemId)
{
	typedef SystemBox *__attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemControl *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1324::func;
	return execfunc(this, systemId);
}

namespace _func1325
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemControl::RenderPowerBar", typeid(void (SystemControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b09e8????????c70424????????8955d489c7e8????????8b7028c70424????????e8????????2b7024", argdata, 1, 5, &func);
}

void SystemControl::RenderPowerBar()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1325::func;
	return execfunc(this);
}

namespace _func1326
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemControl::GetPowerBars", typeid(SystemControl::PowerBars *(*)(int , int , int , bool )), "8d4c240483e4f0ff71fc5589e5575653518d5dc881ec????????8b41048b1189c78945c08b41088955c88955c4897dcc", argdata, 4, 2, &func);
}

SystemControl::PowerBars *SystemControl::GetPowerBars(int width, int height, int gap, bool useShieldGap)
{
	typedef SystemControl::PowerBars *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int width_arg, int height_arg, int gap_arg, bool useShieldGap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1326::func;
	return execfunc(width, height, gap, useShieldGap);
}

Point *Global_SystemControl_weapon_position;

namespace _var1327
{
    static VariableDefinition varObj("Global_SystemControl_weapon_position", "!a3(???????\?)8915????????e8????????8b55e08b45dc83ec088b7b0c8915????????8b5308a3(???????\?)", &Global_SystemControl_weapon_position);
}

Point *Global_SystemControl_drone_position;

namespace _var1328
{
    static VariableDefinition varObj("Global_SystemControl_drone_position", "", &Global_SystemControl_drone_position);
}

namespace _func1329
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemCustomBox::constructor", typeid(void (SystemCustomBox::*)(Point , ShipSystem *, ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b078b77048b57088b7f0cc744240c000000008904248974240489542408", argdata, 4, 5, &func);
}

void SystemCustomBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemCustomBox *this_arg, Point pos_arg, ShipSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1329::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func1330
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::SetExtraData", typeid(void (SystemStoreBox::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec4c837904048b0789819001000074??", argdata, 2, 5, &func);
}

void SystemStoreBox::SetExtraData(int droneChoice)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, int droneChoice_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1330::func;
	return execfunc(this, droneChoice);
}

namespace _func1331
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::constructor", typeid(void (SystemStoreBox::*)(ShipManager *, Equipment *, int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b078b57048945808b470889c7894584", argdata, 4, 5, &func);
}

void SystemStoreBox::constructor(ShipManager *shopper, Equipment *equip, int sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, ShipManager *shopper_arg, Equipment *equip_arg, int sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1331::func;
	return execfunc(this, shopper, equip, sys);
}

namespace _func1332
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemStoreBox::CanHold", typeid(bool (SystemStoreBox::*)()), "8b913801000031c085d274??578d7c240883e4f0ff77fc5589e5575389cb83ec108b4104890424e8????????", argdata, 1, 1, &func);
}

bool SystemStoreBox::CanHold()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1332::func;
	return execfunc(this);
}

namespace _func1333
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::MouseMove", typeid(void (SystemStoreBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b81300100008b378b7f0485c07e??", argdata, 3, 5, &func);
}

void SystemStoreBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1333::func;
	return execfunc(this, mX, mY);
}

namespace _func1334
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemStoreBox::Activate", typeid(void (SystemStoreBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec308b89380100008b81d40400003983e8000000", argdata, 1, 5, &func);
}

void SystemStoreBox::Activate()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1334::func;
	return execfunc(this);
}

namespace _func1335
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemStoreBox::Purchase", typeid(void (SystemStoreBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d75d883ec4c", argdata, 1, 5, &func);
}

void SystemStoreBox::Purchase()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1335::func;
	return execfunc(this);
}

namespace _func1336
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TabbedWindow::Close", typeid(void (TabbedWindow::*)()), "5589e5538b51408b412889cb83e4f08b0c908b01ff501089d9e8????????8b5dfcc9c3", argdata, 1, 5, &func);
}

void TabbedWindow::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1336::func;
	return execfunc(this);
}

namespace _func1337
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportBox::constructor", typeid(void (TeleportBox::*)(Point , TeleportSystem *)), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b57048b77088b07c744240c010000008954240489742408890424e8????????8d8304020000", argdata, 3, 5, &func);
}

void TeleportBox::constructor(Point pos, TeleportSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportBox *this_arg, Point pos_arg, TeleportSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1337::func;
	return execfunc(this, pos, sys);
}

namespace _func1338
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("TeleportSystem::__DO_NOT_HOOK", typeid(void (TeleportSystem::*)()), "8d????0483e4f0ff????5589e5535183ec408b15????????a1????????", argdata, 0, 4, &func);
}

namespace _func1339
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::SetHackingLevel", typeid(void (TeleportSystem::*)(int )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b3783fe01", argdata, 2, 5, &func);
}

void TeleportSystem::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1339::func;
	return execfunc(this, hackingLevel);
}

namespace _func1340
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::OnRenderFloor", typeid(void (TeleportSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec7c803d??????????0f84????????803d??????????0f84????????", argdata, 1, 5, &func);
}

void TeleportSystem::OnRenderFloor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1340::func;
	return execfunc(this);
}

namespace _func1341
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::constructor", typeid(void (TeleportSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b77048b57088b078b4f0c8954240889742404894c240c890424", argdata, 5, 5, &func);
}

void TeleportSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int systemId_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1341::func;
	return execfunc(this, systemId, roomId, shipId, startingPower);
}

namespace _func1342
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::GetChargedPercent", typeid(float (TeleportSystem::*)()), ".83ec04f30f1081c0010000f30f5e05????????f30f110424d9042483c404", argdata, 1, 1, &func);
}

float TeleportSystem::GetChargedPercent()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1342::func;
	return execfunc(this);
}

namespace _func1343
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::Charged", typeid(bool (TeleportSystem::*)()), ".5589e55389cb83e4f0e8????????31d284c075??8b03", argdata, 1, 1, &func);
}

bool TeleportSystem::Charged()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1343::func;
	return execfunc(this);
}

namespace _func1344
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::ClearCrewLocations", typeid(void (TeleportSystem::*)()), "5589e557565383e4f083ec208b99e4010000c781e001000000000000894c241c8d7b1f89fec1ee05c1e602893424e8????????", argdata, 1, 5, &func);
}

void TeleportSystem::ClearCrewLocations()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1344::func;
	return execfunc(this);
}

namespace _func1345
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::UpdateCrewLocation", typeid(void (TeleportSystem::*)(int )), ".5389ca8b4c24088b82cc01000089cbc1eb058d1c98b8????????d3e08b0b85c1", argdata, 2, 5, &func);
}

void TeleportSystem::UpdateCrewLocation(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1345::func;
	return execfunc(this, unk);
}

namespace _func1346
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::SetArmed", typeid(void (TeleportSystem::*)(int )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b07", argdata, 2, 5, &func);
}

void TeleportSystem::SetArmed(int armed)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int armed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1346::func;
	return execfunc(this, armed);
}

namespace _func1347
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::ForceReady", typeid(void (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e55783ec14c781c00100000000c842c70424????????e8????????8b7dfc", argdata, 1, 5, &func);
}

void TeleportSystem::ForceReady()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1347::func;
	return execfunc(this);
}

namespace _func1348
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::CanSend", typeid(bool (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b490c85c975??80bbc401000000", argdata, 1, 1, &func);
}

bool TeleportSystem::CanSend()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1348::func;
	return execfunc(this);
}

namespace _func1349
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::CanReceive", typeid(bool (TeleportSystem::*)()), ".5589e556538b750883e4f080b9c50100000075??8b410c85c074??8b0189cbff502c84c0", argdata, 1, 1, &func);
}

bool TeleportSystem::CanReceive()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1349::func;
	return execfunc(this);
}

namespace _func1350
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::InitiateTeleport", typeid(void (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec30e8????????83e80131d283f80277??", argdata, 1, 5, &func);
}

void TeleportSystem::InitiateTeleport()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1350::func;
	return execfunc(this);
}

namespace _func1351
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::OnLoop", typeid(void (TeleportSystem::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec4ce8????????8b0389d9", argdata, 1, 5, &func);
}

void TeleportSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1351::func;
	return execfunc(this);
}

namespace _func1352
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::Jump", typeid(void (TeleportSystem::*)()), ".5589e55389cb83e4f0e8????????c783c0010000000000008b5dfc", argdata, 1, 5, &func);
}

void TeleportSystem::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1352::func;
	return execfunc(this);
}

namespace _func1353
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::ResetPrimitives", typeid(void (TextButton::*)()), "5589e55756538d79548d594889ce83e4f083ec108b0383c304890424e8????????c743fc0000000039fb75??", argdata, 1, 5, &func);
}

void TextButton::ResetPrimitives()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1353::func;
	return execfunc(this);
}

namespace _func1354
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b9dc000000000f85????????8d81c40000008d7dd0", argdata, 1, 1, &func);
}

int TextButton::GetIdealButtonWidth()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1354::func;
	return execfunc(this);
}

namespace _func1355
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("TextButton::__DO_NOT_HOOK", typeid(void (TextButton::*)()), ".83c30439f375??8d65f85b5e5dc204008d742600ffd08d65f85b", argdata, 0, 4, &func);
}

namespace _func1356
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::constructor", typeid(void (TextButton::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb8d49048d7324", argdata, 1, 5, &func);
}

void TextButton::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1356::func;
	return execfunc(this);
}

namespace _func1357
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::OnInit", typeid(void (TextButton::*)(Point , Point , int , TextString *, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4f0c8b078b57148b7704894dd08b4f108945c88b4708", argdata, 6, 5, &func);
}

void TextButton::OnInit(Point pos, Point size, int cornerInset, TextString *buttonLabel, int font)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, Point pos_arg, Point size_arg, int cornerInset_arg, TextString *buttonLabel_arg, int font_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1357::func;
	return execfunc(this, pos, size, cornerInset, buttonLabel, font);
}

namespace _func1358
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????80b9b4000000000f85????????8b474885c0", argdata, 1, 5, &func);
}

void TextButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1358::func;
	return execfunc(this);
}

namespace _func1359
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "5589e55389cb81c3????????83e4f083ec108b4148c701????????890424e8????????8b4380890424e8????????8b4384890424e8????????8b4394890424", argdata, 1, 5, &func);
}

void TextButton::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1359::func;
	return execfunc(this);
}

namespace _func1360
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::GetSize_DO_NOT_USE_DIRECTLY", typeid(__int64 (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b9b40000000075??8b83a80000008b93ac000000", argdata, 1, 9, &func);
}

FUNC_NAKED __int64 TextButton::GetSize_DO_NOT_USE_DIRECTLY()
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
			// ecx has this
		"call *%0\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret\n\t"
		 :: "m"(_func1360::func)
	);
}

namespace _func1361
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::OnInitRect", typeid(void (TextButton::*)(Globals::Rect &, int , TextString &, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b378b47088b57048b4e0c8945b88b470c8955b4894c24048b4e08", argdata, 5, 5, &func);
}

void TextButton::OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, Globals::Rect &rect_arg, int cornerInset_arg, TextString &buttonLabel_arg, int font_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1361::func;
	return execfunc(this, rect, cornerInset, buttonLabel, font);
}

namespace _func1362
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::SetBaseImage", typeid(void (TextButton::*)(const std::string &, Point , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b57048b078b4f088b5f0c8955e08b5004894de485d275??", argdata, 4, 5, &func);
}

void TextButton::SetBaseImage(const std::string &name, Point pos, int autoWidthMin)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, const std::string &name_arg, Point pos_arg, int autoWidthMin_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1362::func;
	return execfunc(this, name, pos, autoWidthMin);
}

namespace _func1363
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::SetAutoWidth", typeid(void (TextButton::*)(bool , bool , int , int )), "8b5424048b4424108891b40000008b54240885c08891c00000008b54240c8991b80000007e??8981bc000000", argdata, 5, 5, &func);
}

void TextButton::SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, bool autoWidth_arg, bool autoRightAlign_arg, int margin_arg, int min_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1363::func;
	return execfunc(this, autoWidth, autoRightAlign, margin, min);
}

namespace _func1364
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::UpdateAutoWidth", typeid(void (TextButton::*)()), ".80b9b400000000", argdata, 1, 5, &func);
}

void TextButton::UpdateAutoWidth()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1364::func;
	return execfunc(this);
}

namespace _func1365
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetInactiveColor", typeid(void (TextButton::*)(GL_Color )), "5589e557565389cb83e4f083ec10807964000f85????????f30f1005????????c6416401f30f100d????????c781840000000000803ff30f1015????????f30f5ec8c781940000000000803f", argdata, 2, 5, &func);
}

void TextButton::SetInactiveColor(GL_Color color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1365::func;
	return execfunc(this, color);
}

namespace _func1366
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetActiveColor", typeid(void (TextButton::*)(GL_Color )), ".5589e557565389cb83e4f083ec10807964000f85????????f30f1005????????c6416401f30f100d????????c741740000803ff30f1015????????", argdata, 2, 5, &func);
}

void TextButton::SetActiveColor(GL_Color color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1366::func;
	return execfunc(this, color);
}

namespace _func1367
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetSelectedColor", typeid(void (TextButton::*)(GL_Color )), ".5589e557565389cb83e4f083ec10807964000f85????????f30f1005????????c6416401f30f100d????????c741740000803ff30f1015????????f30f5ec8c781840000000000803f", argdata, 2, 5, &func);
}

void TextButton::SetSelectedColor(GL_Color color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1367::func;
	return execfunc(this, color);
}

namespace _func1368
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetTextColor", typeid(void (TextButton::*)(GL_Color )), ".807964000f85????????f30f1005????????c6416401f30f100d????????c741740000803ff30f1015????????f30f5ec8c781840000000000803ff30f101d????????c781940000000000803ff30f5ed0f30f114970f30f100d????????", argdata, 2, 5, &func);
}

void TextButton::SetTextColor(GL_Color color)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1368::func;
	return execfunc(this, color);
}

namespace _func1369
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::InitPrimitives", typeid(void (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????807964000f84????????8b4704c745c000000000c745c400000000c745c8000000008945b08b4708", argdata, 1, 5, &func);
}

void TextButton::InitPrimitives()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1369::func;
	return execfunc(this);
}

namespace _func1370
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::constructor", typeid(void (TextInput::*)(int , TextInput::AllowedCharType , const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b4f088b57048945d48d43088b710489038b3989f901f174??85ff75??c70424????????e8????????83fe0f8975e40f87????????83fe010f84????????85f689c10f85????????8b45d4897304c60431008d4b44c7431800000000c7431c00000000c7432000000000", argdata, 4, 5, &func);
}

void TextInput::constructor(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string &prompt)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg, int maxChars_arg, TextInput::AllowedCharType allowedCharType_arg, const std::string &prompt_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1370::func;
	return execfunc(this, maxChars, allowedCharType, prompt);
}

namespace _func1371
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("TextInput::OnRender", typeid(void (TextInput::*)(int , Point )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????8b07898564ffffff8b4704", argdata, 3, 5, &func);
}

void TextInput::OnRender(int font, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg, int font_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1371::func;
	return execfunc(this, font, pos);
}

namespace _func1372
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::OnLoop", typeid(void (TextInput::*)()), ".5589e5538b413083e4f039413474??c7414c000000008d5944", argdata, 1, 5, &func);
}

void TextInput::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1372::func;
	return execfunc(this);
}

namespace _func1373
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::OnTextEvent", typeid(void (TextInput::*)(CEvent::TextEvent )), ".8079380074??5589e557565383e4f083ec20837d080877??", argdata, 2, 5, &func);
}

void TextInput::OnTextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1373::func;
	return execfunc(this, event);
}

namespace _func1374
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::GetActive", typeid(bool (TextInput::*)()), ".0fb64138c3", argdata, 1, 1, &func);
}

bool TextInput::GetActive()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1374::func;
	return execfunc(this);
}

namespace _func1375
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::GetText", typeid(std::string (TextInput::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b07c7442408ffffffffc744240400000000890424", argdata, 2, 1, &func);
}

std::string TextInput::GetText()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1375::func;
	return execfunc(this);
}

namespace _func1376
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::Start", typeid(void (TextInput::*)()), ".578d7c240883e4f0ff77fc5589e5575383ec408b411c", argdata, 1, 5, &func);
}

void TextInput::Start()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1376::func;
	return execfunc(this);
}

namespace _func1377
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::Stop", typeid(void (TextInput::*)()), ".55c641380089e583e4f0e8????????", argdata, 1, 5, &func);
}

void TextInput::Stop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1377::func;
	return execfunc(this);
}

namespace _func1378
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::SetText", typeid(int (TextInput::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce8d5de083ec2c", argdata, 2, 1, &func);
}

int TextInput::SetText(const std::string &text)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1378::func;
	return execfunc(this, text);
}

namespace _func1379
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextInput::OnTextInput", typeid(void (TextInput::*)(int )), ".8079380074??578d7c240883e4f0ff77fc5589e557565383ec6c", argdata, 2, 5, &func);
}

void TextInput::OnTextInput(int asciiChar)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg, int asciiChar_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1379::func;
	return execfunc(this, asciiChar);
}

namespace _func1380
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string (TextLibrary::*)(const std::string &, const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b07894dc889c18945bc8b47048b59208d511c", argdata, 4, 1, &func);
}

std::string TextLibrary::GetText(const std::string &name, const std::string &lang)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextLibrary *this_arg, const std::string &name_arg, const std::string &lang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1380::func;
	return execfunc(this, name, lang);
}

namespace _func1381
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextString::GetText", typeid(std::string (TextString::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b17807a1800", argdata, 2, 1, &func);
}

std::string TextString::GetText()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextString *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1381::func;
	return execfunc(this);
}

namespace _func1382
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(void (TimerHelper::*)(int )), "5589e55653c6411101c741080000000083e4f0837d08ff74??660fefc0f30f2a4508f30f11410c", argdata, 2, 5, &func);
}

void TimerHelper::Start(int goal)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, int goal_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1382::func;
	return execfunc(this, goal);
}

namespace _func1383
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), ".0fb64111", argdata, 1, 1, &func);
}

bool TimerHelper::Running()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1383::func;
	return execfunc(this);
}

namespace _func1384
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), ".8b44240889018b442404894104", argdata, 3, 5, &func);
}

void TimerHelper::ResetMinMax(int min, int max)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, int min_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1384::func;
	return execfunc(this, min, max);
}

namespace _func1385
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), ".f30f104108f30f5e410cf30f104c2404f30f11490cf30f59c1", argdata, 2, 5, &func);
}

void TimerHelper::SetMaxTime(float max)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, float max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1385::func;
	return execfunc(this, max);
}

namespace _func1386
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Stop", typeid(void (TimerHelper::*)()), ".c6411100", argdata, 1, 5, &func);
}

void TimerHelper::Stop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1386::func;
	return execfunc(this);
}

namespace _func1387
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), ".8079110075??c389f68dbc27000000005589e55389cbb9????????83e4f0", argdata, 1, 5, &func);
}

void TimerHelper::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1387::func;
	return execfunc(this);
}

namespace _func1388
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), ".0fb6411184c074??f30f1041080f2e410c76??5589e55756530fb6711083e4f0", argdata, 1, 1, &func);
}

bool TimerHelper::Done()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1388::func;
	return execfunc(this);
}

namespace _func1389
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TopScore::copy_constructor", typeid(void (TopScore::*)(const TopScore &)), "578d41088d7c240883e4f0ff77fc5589e557565389cb83ec3c8b3789018b16", argdata, 2, 5, &func);
}

void TopScore::copy_constructor(const TopScore &other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TopScore *this_arg, const TopScore &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1389::func;
	return execfunc(this, other);
}

namespace _func1390
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::constructor", typeid(void (TutorialManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d490483ec20c641fc00e8????????8d8300010000", argdata, 1, 5, &func);
}

void TutorialManager::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1390::func;
	return execfunc(this);
}

namespace _func1391
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::Running", typeid(bool (TutorialManager::*)()), ".0fb601", argdata, 1, 1, &func);
}

bool TutorialManager::Running()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1391::func;
	return execfunc(this);
}

namespace _func1392
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnInit", typeid(void (TutorialManager::*)(ShipManager *, CommandGui *, CrewControl *, Upgrades *, CombatControl *, SystemControl *, TabbedWindow *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b470c8b378b4f048b5708c745b412000000", argdata, 8, 5, &func);
}

void TutorialManager::OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg, ShipManager *ship_arg, CommandGui *gui_arg, CrewControl *crewControl_arg, Upgrades *upgradesScreen_arg, CombatControl *combatControl_arg, SystemControl *sysControl_arg, TabbedWindow *unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1392::func;
	return execfunc(this, ship, gui, crewControl, upgradesScreen, combatControl, sysControl, unk);
}

TutorialManager *Global_TutorialManager_Tutorial;

namespace _var1393
{
    static VariableDefinition varObj("Global_TutorialManager_Tutorial", "!b9(???????\?)e8????????84c075??8b4b08", &Global_TutorialManager_Tutorial);
}

namespace _func1394
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b10803d??????????8b4808c74708ffffffffc7470cffffffffc74710000000008955c4", argdata, 4, 5, &func);
}

void UnlockArrow::constructor(Point pos, int unk1, int unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg, Point pos_arg, int unk1_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1394::func;
	return execfunc(this, pos, unk1, unk2);
}

namespace _func1395
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::MouseMove", typeid(bool (UnlockArrow::*)(int , int )), ".8379040374??8b510831c0395424047e??035110395424047d??8b510c395424087e??", argdata, 3, 1, &func);
}

bool UnlockArrow::MouseMove(int x, int y)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1395::func;
	return execfunc(this, x, y);
}

namespace _func1396
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("UnlockArrow::OnRender", typeid(void (UnlockArrow::*)()), ".578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b0185c0", argdata, 1, 5, &func);
}

void UnlockArrow::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1396::func;
	return execfunc(this);
}

namespace _func1397
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::constructorEmpty", typeid(void (UpgradeBox::*)(Point , bool )), "578d51248d7c240883e4f0ff77fc5589f889e557565389cb83c13481ec????????8b378b7f048b40088951e8", argdata, 3, 5, &func);
}

void UpgradeBox::constructorEmpty(Point pos, bool subsystem)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, Point pos_arg, bool subsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1397::func;
	return execfunc(this, pos, subsystem);
}

namespace _func1398
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::constructorSystem", typeid(void (UpgradeBox::*)(ShipManager *, ShipSystem *, Point , bool )), "578d7c240883e4f0ff77fc5589fa89e557565389cb83ec5c8b47048b720c8b52108b0f8b7f08c743140000000089038945ac8d83a0000000", argdata, 5, 5, &func);
}

void UpgradeBox::constructorSystem(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, ShipManager *ship_arg, ShipSystem *sys_arg, Point pos_arg, bool subsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1398::func;
	return execfunc(this, ship, sys, pos, subsystem);
}

namespace _func1399
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("UpgradeBox::destructor", typeid(void (UpgradeBox::*)()), "5589e55389cb83e4f083ec108b8110010000890424e8????????8d8ba0000000e8????????8d4b3483c324e8????????8b43f839d874??890424", argdata, 1, 5, &func);
}

void UpgradeBox::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1399::func;
	return execfunc(this);
}

namespace _func1400
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("UpgradeBox::OnRender", typeid(void (UpgradeBox::*)()), "5589e583e4f083ec1080b90d0100000075??e8????????c9c38db426000000008b8110010000890424e8????????c9", argdata, 1, 5, &func);
}

void UpgradeBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1400::func;
	return execfunc(this);
}

namespace _func1401
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::MouseMove", typeid(void (UpgradeBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec148b078b57048b3985ff74??8b49188b39", argdata, 3, 5, &func);
}

void UpgradeBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1401::func;
	return execfunc(this, mX, mY);
}

namespace _func1402
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::MouseClick", typeid(void (UpgradeBox::*)(int , int )), "8b1185d20f84????????8b4118807840000f84????????807841000f84????????8b42540341143b82a00100000f8d????????5783e8018d7c240883e4f0ff77fc5589e557", argdata, 3, 5, &func);
}

void UpgradeBox::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1402::func;
	return execfunc(this, mX, mY);
}

namespace _func1403
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::MouseRightClick", typeid(void (UpgradeBox::*)(int , int )), "8b1185d20f84????????8b4118807840000f84????????807841000f84????????8b411485c00f8e????????578d7c240883e4f0ff77fc5589e557", argdata, 3, 5, &func);
}

void UpgradeBox::MouseRightClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1403::func;
	return execfunc(this, mX, mY);
}

namespace _func1404
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("UpgradeBox::Undo", typeid(void (UpgradeBox::*)()), "8b411485c07e??578d7c240883e4f0ff77fc5589e557565389cb83ec1c8d76008b1331f60342548b53088b8ac4000000", argdata, 1, 5, &func);
}

void UpgradeBox::Undo()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1404::func;
	return execfunc(this);
}

namespace _func1405
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("UpgradeBox::Accept", typeid(void (UpgradeBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b0985c90f84????????8b4314890424e8????????8b0b83ec04", argdata, 1, 5, &func);
}

void UpgradeBox::Accept()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1405::func;
	return execfunc(this);
}

namespace _func1406
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::OnInit", typeid(void (Upgrades::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb8d75bc81ec????????8b07c64105018d7dd489412c8945888b4118894424048b41148d4dcc", argdata, 2, 5, &func);
}

void Upgrades::OnInit(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1406::func;
	return execfunc(this, ship);
}

namespace _func1407
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Upgrades::ClearUpgradeBoxes", typeid(void (Upgrades::*)()), "5589e557565389cf83e4f083ec108b51208b492489c829d083f8037e??31f6908b1cb285db", argdata, 1, 5, &func);
}

void Upgrades::ClearUpgradeBoxes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1407::func;
	return execfunc(this);
}

namespace _func1408
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::MouseMove", typeid(void (Upgrades::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b3089f38975e48b7004891c24", argdata, 3, 5, &func);
}

void Upgrades::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1408::func;
	return execfunc(this, mX, mY);
}

namespace _func1409
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Upgrades::OnLoop", typeid(void (Upgrades::*)()), "807904000f84????????578d7c240883e4f0ff77fc5589e557565381ec????????8b818c0100008b71208b592485c00f9fc2", argdata, 1, 5, &func);
}

void Upgrades::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1409::func;
	return execfunc(this);
}

namespace _func1410
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::MouseClick", typeid(void (Upgrades::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb31f683ec4c8b078b7f04890424897c2404", argdata, 3, 5, &func);
}

void Upgrades::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1410::func;
	return execfunc(this, mX, mY);
}

namespace _func1411
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::MouseRightClick", typeid(void (Upgrades::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565331ff8d75d883ec4c8b41248b5120894dc0", argdata, 3, 5, &func);
}

void Upgrades::MouseRightClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1411::func;
	return execfunc(this, mX, mY);
}

namespace _func1412
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Upgrades::OnRender", typeid(void (Upgrades::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec????????8b511c0f2825????????89d085c00f2965c80f84????????", argdata, 1, 5, &func);
}

void Upgrades::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1412::func;
	return execfunc(this);
}

namespace _func1413
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Upgrades::Close", typeid(void (Upgrades::*)()), "8079040075??c389f68dbc2700000000578d7c240883e4f0ff77fc5589e557565389cf31db8d75d883ec4c", argdata, 1, 5, &func);
}

void Upgrades::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1413::func;
	return execfunc(this);
}

namespace _func1414
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Upgrades::ConfirmUpgrades", typeid(void (Upgrades::*)()), "578d7c240883e4f0ff77fc5589e557565331f68d7dd883ec4c8b51248b4120894dc489d129c1c1f902", argdata, 1, 5, &func);
}

void Upgrades::ConfirmUpgrades()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1414::func;
	return execfunc(this);
}

namespace _func1415
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::Start", typeid(void (WarningMessage::*)()), "8079140075??578d7c240883e4f0ff77fc5589e5575389cb", argdata, 1, 5, &func);
}

void WarningMessage::Start()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1415::func;
	return execfunc(this);
}

namespace _func1416
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::OnRender", typeid(void (WarningMessage::*)()), "807916000f85????????807914000f84????????578d7c240883e4f0ff77fc5589e55753", argdata, 1, 5, &func);
}

void WarningMessage::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1416::func;
	return execfunc(this);
}

namespace _func1417
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::RenderWithAlpha", typeid(void (WarningMessage::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c00000080792800f30f100f744d", argdata, 2, 5, &func);
}

void WarningMessage::RenderWithAlpha(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1417::func;
	return execfunc(this, alpha);
}

namespace _func1418
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::constructor", typeid(void (WarningMessage::*)()), "57660fefc08d7c240883e4f0ff77fc5589e5575389cb8d492083ec20f30f1141e8", argdata, 1, 5, &func);
}

void WarningMessage::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1418::func;
	return execfunc(this);
}

namespace _func1419
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::InitImage", typeid(void (WarningMessage::*)(const std::string &, Point , float , bool )), "578d7c240883e4f0ff77fc5589e557565389fe89cb83ec2c8b4e108b46088b178b7f04f30f104e0c", argdata, 5, 5, &func);
}

void WarningMessage::InitImage(const std::string &imageName, Point position, float time, bool flash)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &imageName_arg, Point position_arg, float time_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1419::func;
	return execfunc(this, imageName, position, time, flash);
}

namespace _func1420
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::InitText", typeid(void (WarningMessage::*)(const TextString &, Point , float , GL_Color , bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb8d492c83ec2c8b57208b47248b37c641fc00f30f105f0c8955e08945e4f30f115ddc8b47048b57088941f48951f8893424", argdata, 7, 5, &func);
}

void WarningMessage::InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, Point position_arg, float time_arg, GL_Color textColor_arg, bool centerText_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1420::func;
	return execfunc(this, text, position, time, textColor, centerText, flash);
}

namespace _func1421
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::OnLoop", typeid(void (WarningMessage::*)()), "578d7c240883e4f0ff77fc5589e557568d71045389cb83ec1c89f1", argdata, 1, 5, &func);
}

void WarningMessage::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1421::func;
	return execfunc(this);
}

namespace _func1422
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetImage", typeid(void (WarningMessage::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec2c807928008b37741a8b91b00000008b7e0489cb39fa89f80f46c285c07512", argdata, 2, 5, &func);
}

void WarningMessage::SetImage(const std::string &imageName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &imageName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1422::func;
	return execfunc(this, imageName);
}

namespace _func1423
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &)), "578d7c240883e4f0ff77fc5589e557565383ec2c807928008b3775140fb641440fb6561889cb38c2741629d085c07540", argdata, 2, 5, &func);
}

void WarningMessage::SetText(const TextString &text)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1423::func;
	return execfunc(this, text);
}

namespace _func1424
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &, GL_Color )), "578d7c240883e4f0ff77fc5589e557565383ec2c807928008b3775140fb641440fb6561889cb38c2741629d085c0754a", argdata, 3, 5, &func);
}

void WarningMessage::SetText(const TextString &text, GL_Color textColor)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, GL_Color textColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1424::func;
	return execfunc(this, text, textColor);
}

namespace _func1425
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("WarningMessage::SetPosition", typeid(void (WarningMessage::*)(Point )), "578d7c240883e4f0ff77fc5589e55783ec14807928008b078b5704894120895124741283c16089542404890424", argdata, 2, 5, &func);
}

void WarningMessage::SetPosition(Point position)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1425::func;
	return execfunc(this, position);
}

namespace _func1426
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetLoop", typeid(void (WarningMessage::*)(bool )), "5783c1048d7c240883e4f0ff77fc5589e55783ec148b07c7442404000000000fb6c0890424", argdata, 2, 5, &func);
}

void WarningMessage::SetLoop(bool loop)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1426::func;
	return execfunc(this, loop);
}

namespace _func1427
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetSound", typeid(void (WarningMessage::*)(const std::string &)), "5781c1c80000008d7c240883e4f0ff77fc5589e55783ec148b07890424", argdata, 2, 5, &func);
}

void WarningMessage::SetSound(const std::string &sound)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1427::func;
	return execfunc(this, sound);
}

namespace _func1428
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SaveState", typeid(void (WeaponAnimation::*)(int )), "578d????0883e4f0ff????5589e557565389cb83ec2c8b??8934??e8????????8d", argdata, 2, 5, &func);
}

void WeaponAnimation::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1428::func;
	return execfunc(this, fd);
}

namespace _func1429
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponAnimation::StartFire", typeid(bool (WeaponAnimation::*)()), "0fb681cd00000084c0756580b9cc000000007401c3578d7c240883e4f0ff77fc5589e5575389cb83ec10c7042401000000", argdata, 1, 1, &func);
}

bool WeaponAnimation::StartFire()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1429::func;
	return execfunc(this);
}

namespace _func1430
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SetFireTime", typeid(void (WeaponAnimation::*)(float )), "8b5104660fefc0660fefc989d02b81d4000000f30f2acaf30f2ac0f30f5ec1f30f104c2404f30f5ec8f30f114924", argdata, 2, 5, &func);
}

void WeaponAnimation::SetFireTime(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1430::func;
	return execfunc(this, time);
}

namespace _func1431
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponAnimation::GetSlide", typeid(Pointf (WeaponAnimation::*)()), "578d??????83e4??ff????5589e5575389cb81c1????????83ec??c704", argdata, 1, 9, &func);
}

Pointf WeaponAnimation::GetSlide()
{
	typedef Pointf __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1431::func;
	return execfunc(this);
}

namespace _func1432
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponAnimation::Update", typeid(void (WeaponAnimation::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c80bbcd000000008b81800000008945d489c1", argdata, 1, 5, &func);
}

void WeaponAnimation::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1432::func;
	return execfunc(this);
}

namespace _func1433
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::OnRender", typeid(void (WeaponAnimation::*)(float )), "578d????0883e4f0ff????5589e557565389cb83ec5cf30f10??", argdata, 2, 5, &func);
}

void WeaponAnimation::OnRender(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1433::func;
	return execfunc(this, alpha);
}

namespace _func1434
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponBlueprint::__DO_NOT_HOOK", typeid(void (WeaponBlueprint::*)()), "5589e55389cb83e4f083ec108b81c4000000c701????????85c074??890424e8????????8b83a00000008d93a8000000c703????????39d0", argdata, 0, 4, &func);
}

namespace _func1435
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::constructor", typeid(void (WeaponBlueprint::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb8d4904", argdata, 1, 5, &func);
}

void WeaponBlueprint::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1435::func;
	return execfunc(this);
}

namespace _func1436
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::destructor", typeid(void (WeaponBlueprint::*)()), "558d91e401000089e557565389ce83e4f083ec108b81dc010000c701????????39d074??890424e8????????8bbebc0100008b9eb801000039df74??", argdata, 1, 5, &func);
}

void WeaponBlueprint::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1436::func;
	return execfunc(this);
}

namespace _func1437
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDescription", typeid(std::string (WeaponBlueprint::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565381ec????????8b40048b3f898da8feffff89c6", argdata, 3, 1, &func);
}

std::string WeaponBlueprint::GetDescription(bool tooltip)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1437::func;
	return execfunc(this, tooltip);
}

namespace _func1438
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::RenderIcon", typeid(void (WeaponBlueprint::*)(float )), "5781c16c0100008d7c240883e4f0ff77fc5589e55783ec14890c24b9????????e8????????8b7dfc83ec04c98d67f85fc20400", argdata, 2, 5, &func);
}

void WeaponBlueprint::RenderIcon(float scale)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg, float scale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1438::func;
	return execfunc(this, scale);
}

namespace _func1439
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDimensions", typeid(Point (WeaponBlueprint::*)()), ".5781c16c0100008d7c2408", argdata, 1, 9, &func);
}

Point WeaponBlueprint::GetDimensions()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1439::func;
	return execfunc(this);
}

namespace _func1440
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBox::RenderBox", typeid(void (WeaponBox::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b070fb657040fb6c089042489542404", argdata, 3, 5, &func);
}

void WeaponBox::RenderBox(bool dragging, bool flashPowerBox)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBox *this_arg, bool dragging_arg, bool flashPowerBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1440::func;
	return execfunc(this, dragging, flashPowerBox);
}

namespace _func1441
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponBox::GenerateTooltip", typeid(std::string (WeaponBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b3f8b078b40083d????????0f85????????8b87bc01000085c00f94c084c00f85????????c744240401000000", argdata, 2, 1, &func);
}

std::string WeaponBox::GenerateTooltip()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1441::func;
	return execfunc(this);
}

namespace _func1442
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::Fire", typeid(void (WeaponControl::*)(std::vector<Pointf> &, int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec3c8b91900000008b70048b3f8b400885d28975d00f84????????", argdata, 4, 5, &func);
}

void WeaponControl::Fire(std::vector<Pointf> &points, int target, bool autoFire)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, std::vector<Pointf> &points_arg, int target_arg, bool autoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1442::func;
	return execfunc(this, points, target, autoFire);
}

namespace _func1443
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::OnRender", typeid(void (WeaponControl::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b490c8b37c70424????????e8????????83ec0484c00f84????????", argdata, 2, 5, &func);
}

void WeaponControl::OnRender(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1443::func;
	return execfunc(this, unk);
}

namespace _func1444
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LButton", typeid(bool (WeaponControl::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c80b9d8000000008b1f8b77048b570874??0fb681d900000084c0", argdata, 4, 1, &func);
}

bool WeaponControl::LButton(int x, int y, bool holdingShift)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg, bool holdingShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1444::func;
	return execfunc(this, x, y, holdingShift);
}

namespace _func1445
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::MouseMove", typeid(void (WeaponControl::*)(int , int )), ".578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b378b7f04893424897c2404", argdata, 3, 5, &func);
}

void WeaponControl::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1445::func;
	return execfunc(this, x, y);
}

namespace _func1446
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LinkShip", typeid(void (WeaponControl::*)(ShipManager *)), ".578d7c240883e4f0ff77fc5589e5575389cb83ec108b07890424e8????????8b0383ec04", argdata, 2, 5, &func);
}

void WeaponControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1446::func;
	return execfunc(this, ship);
}

namespace _func1447
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::constructor", typeid(void (WeaponControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cf8db518feffff81ec????????898d10fdffffc70424????????e8????????8d8f9800000083ec04c707????????c7878c00000000000000c7879000000000000000", argdata, 1, 5, &func);
}

void WeaponControl::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1447::func;
	return execfunc(this);
}

namespace _func1448
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SetAutofiring", typeid(void (WeaponControl::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b078b7f04f30f101d????????84c08881940000000f84????????f30f1005????????f30f100d????????", argdata, 3, 5, &func);
}

void WeaponControl::SetAutofiring(bool on, bool simple)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool on_arg, bool simple_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1448::func;
	return execfunc(this, on, simple);
}

namespace _func1449
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::KeyDown", typeid(bool (WeaponControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b3f893c24e8????????83ec0484c0", argdata, 2, 1, &func);
}

bool WeaponControl::KeyDown(SDLKey key)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1449::func;
	return execfunc(this, key);
}

namespace _func1450
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::RenderAiming", typeid(void (WeaponControl::*)()), "5589e557565383e4f083ec508b41148b79108944243029f8c1f80285c0", argdata, 1, 5, &func);
}

void WeaponControl::RenderAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1450::func;
	return execfunc(this);
}

namespace _func1451
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::RenderSelfAiming", typeid(void (WeaponControl::*)()), "5589e557565383e4f083ec308b41148b71108944242429f0c1f80285c0", argdata, 1, 5, &func);
}

void WeaponControl::RenderSelfAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1451::func;
	return execfunc(this);
}

namespace _func1452
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SelectArmament", typeid(void (WeaponControl::*)(unsigned int )), "578d????0883e4f0ff????5589e557565389ce81ecdc000000", argdata, 2, 5, &func);
}

void WeaponControl::SelectArmament(unsigned int armamentSlot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, unsigned int armamentSlot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1452::func;
	return execfunc(this, armamentSlot);
}

namespace _func1453
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::OnLanguageChange", typeid(void (WeaponControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cf8d75b48d5dd481ecac0000008b8188010000890424", argdata, 1, 5, &func);
}

void WeaponControl::OnLanguageChange()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1453::func;
	return execfunc(this);
}

namespace _func1454
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::RenderBeamAiming", typeid(void (*)(Pointf , Pointf , bool )), "8d4c240483e4f0ff71fc5589e55756535189cb81ec880000008b018b7910f30f10410c", argdata, 3, 6, &func);
}

void WeaponControl::RenderBeamAiming(Pointf one, Pointf two, bool bAutoFire)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf one_arg, Pointf two_arg, bool bAutoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1454::func;
	return execfunc(one, two, bAutoFire);
}

namespace _func1455
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::HolderLabel", typeid(TextString (WeaponControl::*)()), "8d510883ec2089c8c7410877656170c7410c6f6e735f8911c741106c616265c641146cc741040d000000c6411500c641180083c420", argdata, 2, 1, &func);
}

TextString WeaponControl::HolderLabel()
{
	typedef TextString __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1455::func;
	return execfunc(this);
}

namespace _func1456
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::ArmamentHotkey", typeid(SDLKey (WeaponControl::*)(unsigned int )), ".578d7c240883e4f0ff77fc5589e55756538d8d60ffffff81ec4c0100008b1f", argdata, 2, 1, &func);
}

SDLKey WeaponControl::ArmamentHotkey(unsigned int i)
{
	typedef SDLKey __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1456::func;
	return execfunc(this, i);
}

namespace _func1457
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponStoreBox::__DO_NOT_HOOK", typeid(void (WeaponStoreBox::*)()), "c7442404000000008904248975d0e8????????8b55ccc7400c655f627583ec08c74010795f7765c7401461706f6e89d9c64018738945d08955d8c700????????c740046555492fc7400873746f72", argdata, 0, 4, &func);
}

namespace _func1458
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponStoreBox::constructor", typeid(void (WeaponStoreBox::*)(ShipManager *, Equipment *, const WeaponBlueprint *)), ".578d7c240883e4f0ff77fc5589f889e557565389cb8d4dd083ec4c8b70088d45d88b178b7f04", argdata, 4, 5, &func);
}

void WeaponStoreBox::constructor(ShipManager *ship, Equipment *equip, const WeaponBlueprint *weaponBp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponStoreBox *this_arg, ShipManager *ship_arg, Equipment *equip_arg, const WeaponBlueprint *weaponBp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1458::func;
	return execfunc(this, ship, equip, weaponBp);
}

namespace _func1459
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::RemoveWeapon", typeid(void (WeaponSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b3f85ff78??", argdata, 2, 5, &func);
}

void WeaponSystem::RemoveWeapon(int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1459::func;
	return execfunc(this, slot);
}

namespace _func1460
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::SetBonusPower", typeid(void (WeaponSystem::*)(int , int )), "5589e556538b750889cb83e4f0e8????????39f089d90f4fc6", argdata, 3, 5, &func);
}

void WeaponSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1460::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func1461
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponSystem::OnLoop", typeid(void (WeaponSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec4ce8????????8b8ec80100008b86cc01000031d229c8c1f80285c0", argdata, 1, 5, &func);
}

void WeaponSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1461::func;
	return execfunc(this);
}

namespace _func1462
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystemBox::constructor", typeid(void (WeaponSystemBox::*)(Point , ShipSystem *, WeaponControl *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57048b4f088b7f0cc744240c0100000089042489542404894c2408", argdata, 4, 5, &func);
}

void WeaponSystemBox::constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponSystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, WeaponControl *weapCtrl_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1462::func;
	return execfunc(this, pos, sys, weapCtrl);
}

namespace _func1463
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::Draw", typeid(void (WindowFrame::*)(int , int )), "5589e55389cb83e4f083ec10e8????????660fefc0c744240800000000f30f2a450cf30f11442404", argdata, 3, 5, &func);
}

void WindowFrame::Draw(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1463::func;
	return execfunc(this, x, y);
}

namespace _func1464
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::DrawMask", typeid(void (WindowFrame::*)(int )), "5589e55389cb83e4f083ec108b4508c70424????????8944240889442404e8????????8b4314890424e8????????", argdata, 2, 5, &func);
}

void WindowFrame::DrawMask(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1464::func;
	return execfunc(this, unk);
}

namespace _func1465
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::constructor", typeid(void (WindowFrame::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e55756538d5dd081ec????????8b77048b07898d58ffffff895dc8c745d077696e64c745d46f775f628975a0", argdata, 5, 5, &func);
}

void WindowFrame::constructor(int x, int y, int w, int h)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int x_arg, int y_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1465::func;
	return execfunc(this, x, y, w, h);
}

namespace _func1466
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WindowFrame::destructor", typeid(void (WindowFrame::*)()), "5589e55389cb83e4f083ec108b4110890424e8????????8b4314890424e8????????8b4318890424e8????????8b5dfc", argdata, 1, 5, &func);
}

void WindowFrame::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1466::func;
	return execfunc(this);
}

namespace _func1467
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d490883ec10c741f800000000c741fc00000000", argdata, 1, 5, &func);
}

void WorldManager::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1467::func;
	return execfunc(this);
}

namespace _func1468
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557568d71085389cb83ec1c89f1e8????????c70424????????e8????????", argdata, 1, 1, &func);
}

int WorldManager::OnInit()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1468::func;
	return execfunc(this);
}

namespace _func1469
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(CompleteShip *(WorldManager::*)(ShipEvent *, bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????807f04008b1f0f85????????c70424????????e8????????89c7", argdata, 3, 1, &func);
}

CompleteShip *WorldManager::CreateShip(ShipEvent *shipEvent, bool boss)
{
	typedef CompleteShip *__attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipEvent *shipEvent_arg, bool boss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1469::func;
	return execfunc(this, shipEvent, boss);
}

namespace _func1470
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(void (WorldManager::*)(Location *)), "578d7c240883e4f0ff77fc5589e557565389ce81ec????????898d54fbffffc6814612000000b9????????8b3f", argdata, 2, 5, &func);
}

void WorldManager::CreateLocation(Location *loc)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1470::func;
	return execfunc(this, loc);
}

namespace _func1471
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::ClearLocation", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83c10881ec5c030000", argdata, 1, 5, &func);
}

void WorldManager::ClearLocation()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1471::func;
	return execfunc(this);
}

namespace _func1472
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::SaveGame", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec3c8b89e40d0000e8????????84c074??8d65f45b5e5f5d", argdata, 1, 5, &func);
}

void WorldManager::SaveGame()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1472::func;
	return execfunc(this);
}

namespace _func1473
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(void (WorldManager::*)(LocationEvent *)), "5789c805????????8d7c240883e4f0ff77fc5589e557565389cb89c681ec????????8b3f", argdata, 2, 5, &func);
}

void WorldManager::CreateChoiceBox(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1473::func;
	return execfunc(this, event);
}

namespace _func1474
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox0", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b48088b018b40443d????????752a0fb6819904000084c0751185f6742889342489d9e8????????83ec04", argdata, 2, 5, &func);
}

void WorldManager::CreateChoiceBox0(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1474::func;
	return execfunc(this, event);
}

namespace _func1475
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565381ec????????8b3f898d70fbffff807f1c000f85????????8d85bcfbffff89ce898568fbffff8d85c4fbffff898564fbffff8d874406000089f1890424", argdata, 2, 5, &func);
}

void WorldManager::UpdateLocation(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1475::func;
	return execfunc(this, event);
}

namespace _func1476
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation0", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b48088b018b40443d????????75270fb6819904000084c0750d89342489d9e8????????83ec04", argdata, 2, 5, &func);
}

void WorldManager::UpdateLocation0(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1476::func;
	return execfunc(this, event);
}

namespace _func1477
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(LocationEvent *(WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389ce8d8d2cfeffff81ec????????8b078985d8fcffff", argdata, 2, 1, &func);
}

LocationEvent *WorldManager::ModifyResources(LocationEvent *event)
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1477::func;
	return execfunc(this, event);
}

namespace _func1478
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(void (WorldManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570483f801", argdata, 3, 5, &func);
}

void WorldManager::ModifyEnvironment(int envFlag, int envTarget)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, int envFlag_arg, int envTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1478::func;
	return execfunc(this, envFlag, envTarget);
}

namespace _func1479
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(void (WorldManager::*)(std::vector<StatusEffect> &)), "5789ca81c2????????8d7c240883e4f0ff77fc5589e5575653", argdata, 2, 5, &func);
}

void WorldManager::CheckStatusEffects(std::vector<StatusEffect> &vec)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, std::vector<StatusEffect> &vec_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1479::func;
	return execfunc(this, vec);
}

namespace _func1480
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyStatusEffect", typeid(void (WorldManager::*)(StatusEffect , ShipManager *, int )), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b70148b500c8b7f1039d6", argdata, 4, 5, &func);
}

void WorldManager::ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, StatusEffect effect_arg, ShipManager *target_arg, int targetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1480::func;
	return execfunc(this, effect, target, targetType);
}

namespace _func1481
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(void (WorldManager::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b098b3785c9", argdata, 2, 5, &func);
}

void WorldManager::StartGame(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1481::func;
	return execfunc(this, ship);
}

namespace _func1482
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(void (WorldManager::*)()), ".578d7c240883e4f0ff77fc5589e5575389cb83ec10e8????????e8????????", argdata, 1, 5, &func);
}

void WorldManager::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1482::func;
	return execfunc(this);
}

namespace _func1483
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::LoadGame", typeid(void (WorldManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8db51cfeffff81ec????????8b07c7852cfeffff00000000c78530feffff00000000c78534feffff00000000c78538feffff00000000c7853cfeffff00000000", argdata, 2, 5, &func);
}

void WorldManager::LoadGame(const std::string &fileName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1483::func;
	return execfunc(this, fileName);
}

namespace _func1484
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec????????c70424????????e8????????83ec0484c074??8d65f45b5e5f5d8d67f85f", argdata, 1, 5, &func);
}

void WorldManager::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1484::func;
	return execfunc(this);
}

namespace _func1485
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::PauseLoop", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b098b01ff500c83be3408000001", argdata, 1, 5, &func);
}

void WorldManager::PauseLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1485::func;
	return execfunc(this);
}

namespace _func1486
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d5dd88d7dd083ec3c8b018b480881c1????????e8????????8b068b5008895dd08b8aa4060000", argdata, 1, 5, &func);
}

void WorldManager::CreateNewGame()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1486::func;
	return execfunc(this);
}

namespace _func1487
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), "5589e55389cb83c10883e4f0e8????????84c075??8b038b4808b8????????8b91f007000085d274??", argdata, 1, 1, &func);
}

bool WorldManager::HostileEnvironment()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1487::func;
	return execfunc(this);
}

namespace _func1488
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::AddBoarders", typeid(bool (WorldManager::*)(BoardingEvent &)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b018b1f8b500831c083baf00700000e7f??", argdata, 2, 1, &func);
}

bool WorldManager::AddBoarders(BoardingEvent &boardingEvent)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, BoardingEvent &boardingEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1488::func;
	return execfunc(this, boardingEvent);
}

namespace _func1489
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateStore", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b378b961c06000085d274??0fb683451200008b89e40d0000891424", argdata, 2, 5, &func);
}

void WorldManager::CreateStore(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1489::func;
	return execfunc(this, event);
}

namespace _func1490
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckRequirements", typeid(bool (WorldManager::*)(LocationEvent *, bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f85db0f84120100000fb693d405000084d20f85030100008b834c04000085c00f880a010000", argdata, 3, 1, &func);
}

bool WorldManager::CheckRequirements(LocationEvent *event, bool hidden)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg, bool hidden_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1490::func;
	return execfunc(this, event, hidden);
}

namespace _func1491
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_measurePrintLines", typeid(Pointf (*)(int , float , float , int , const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d75d883ec488b018975d08945c08b410c8945bc8b41108b38", argdata, 5, 10, &func);
}

Pointf freetype::easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1491::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1492
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_measureWidth", typeid(int (*)(int , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d75d883ec488b018975d08945c48b4104", argdata, 2, 2, &func);
}

int freetype::easy_measureWidth(int fontSize, const std::string &text)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1492::func;
	return execfunc(fontSize, text);
}

namespace _func1493
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_print", typeid(Pointf (*)(int , float , float , const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01897dd0", argdata, 4, 10, &func);
}

Pointf freetype::easy_print(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1493::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1494
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printRightAlign", typeid(Pointf (*)(int , float , float , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01897dd0f30f104104f30f1049088945c08b410c", argdata, 4, 10, &func);
}

Pointf freetype::easy_printRightAlign(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1494::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1495
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printNewlinesCentered", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".8d4c240483e4f0ff71fc5589e557565351", argdata, 5, 10, &func);
}

Pointf freetype::easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1495::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1496
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d75d883ec68", argdata, 5, 10, &func);
}

Pointf freetype::easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1496::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1497
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printCenter", typeid(Pointf (*)(int , float , float , const std::string &)), ".8d4c240483e4f0ff71fc5589e5575653518d7dd883ec588b01", argdata, 4, 10, &func);
}

Pointf freetype::easy_printCenter(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1497::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1498
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoShrink", typeid(void (*)(int , float , float , int , bool , const std::string &)), ".8d4c240483e4f0ff71fc5589e55756535181ec????????8b5110", argdata, 6, 6, &func);
}

void freetype::easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontId_arg, float x_arg, float y_arg, int maxWidth_arg, bool centered_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1498::func;
	return execfunc(fontId, x, y, maxWidth, centered, text);
}

namespace _func1499
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::font_data::init", typeid(void (freetype::font_data::*)(const void *, int , unsigned int , bool )), "55660fefc9660fefc089e55389cb83e4f083ec20", argdata, 5, 5, &func);
}

void freetype::font_data::init(const void *buffer, int bufferSize, unsigned int h, bool glow)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(freetype::font_data *this_arg, const void *buffer_arg, int bufferSize_arg, unsigned int h_arg, bool glow_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1499::func;
	return execfunc(this, buffer, bufferSize, h, glow);
}

namespace _func1500
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::font_data::init_bitmap", typeid(void (freetype::font_data::*)(const void *, int , int , int )), "5589e55389cb83e4f083ec208b????c744????00000000", argdata, 5, 5, &func);
}

void freetype::font_data::init_bitmap(const void *buffer, int bufferSize, int size, int h)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(freetype::font_data *this_arg, const void *buffer_arg, int bufferSize_arg, int size_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1500::func;
	return execfunc(this, buffer, bufferSize, size, h);
}

namespace _func1501
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("freetype::font_data::clean", typeid(void (freetype::font_data::*)()), "5589e583e4f083ec108b4104890424e8????????c9c3", argdata, 1, 5, &func);
}

void freetype::font_data::clean()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(freetype::font_data *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1501::func;
	return execfunc(this);
}

namespace _func1502
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_baseline", typeid(float (*)(int , float )), "5589e5565383e4f083ec308b4d08f30f104d0c85c97e??3b0d????????7d??803d????????008b15????????74??8b1d????????39d97c??8d349d000000008b143285d274??89c829d88db60000000039c389c17f??8b143229d885d275??660fefc0eb??8b1c8a660fefc085db74??0f2ec173??0f2ec876??0f2e4b247a??75??f30f10432c", argdata, 2, 2, &func);
}

float __stdcall font_baseline(int font_id, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int font_id_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1502::func;
	return execfunc(font_id, size);
}

namespace _func1503
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_height", typeid(float (*)(int , float )), "5589e5565383e4f083ec308b4d08f30f104d0c85c97e??3b0d????????7d??803d????????008b15????????74??8b1d????????39d97c??8d349d000000008b143285d274??89c829d88db60000000039c389c17f??8b143229d885d275??660fefc0eb??8b1c8a660fefc085db74??0f2ec173??0f2ec876??0f2e4b247a??75??f30f104328", argdata, 2, 2, &func);
}

float __stdcall font_height(int font_id, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int font_id_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1503::func;
	return execfunc(font_id, size);
}

float *Global_freetype_sil_freetype_outline;

namespace _var1504
{
    static VariableDefinition varObj("Global_freetype_sil_freetype_outline", "!89108b559cc705(???????\?)000000408950048b55a0", &Global_freetype_sil_freetype_outline);
}

