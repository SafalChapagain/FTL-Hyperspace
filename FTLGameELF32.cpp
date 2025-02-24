#include "FTLGameELF32.h"
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
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(void (AchievementTracker::*)()), "5589e557565381ecfc0101008b4508????????????????89853cfefeff65a114000000", argdata, 1, 6, &func);
}

void AchievementTracker::LoadAchievementDescriptions()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func0::func;
	return execfunc(this);
}

namespace _func1
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipAchievements", typeid(std::vector<CAchievement*> (AchievementTracker::*)(const std::string &)), "5557565383ec3c8b442458c744240c02000000", argdata, 3, 18, &func);
}

std::vector<CAchievement*> AchievementTracker::GetShipAchievements(const std::string &ship)
{
	typedef std::vector<CAchievement*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1::func;
	return execfunc(this, ship);
}

namespace _func2
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::CheckShipAchievements", typeid(void (AchievementTracker::*)(int , bool )), ".5589e557565383ec5c8b450c0fb65d10", argdata, 3, 6, &func);
}

void AchievementTracker::CheckShipAchievements(int shipId, bool hidePopups)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int shipId_arg, bool hidePopups_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func2::func;
	return execfunc(this, shipId, hidePopups);
}

namespace _func3
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(void (AchievementTracker::*)(const std::string &, bool , bool )), "5589e557565331db83ec4c0fb645108b7508", argdata, 4, 6, &func);
}

void AchievementTracker::SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &achievement_arg, bool noPopup_arg, bool sendToServer_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func3::func;
	return execfunc(this, achievement, noPopup, sendToServer);
}

namespace _func4
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::UnlockShip", typeid(void (AchievementTracker::*)(int , int )), "538b4c24108b4424088b54240c83f902????8b580c8d14528d14938b128d1c8a", argdata, 3, 6, &func);
}

void AchievementTracker::UnlockShip(int shipId, int shipType)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int shipId_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func4::func;
	return execfunc(this, shipId, shipType);
}

namespace _func5
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(void (AchievementTracker::*)()), "5589e557565381ec8c0000008d45b88d7dd8", argdata, 1, 6, &func);
}

void AchievementTracker::SetSectorEight()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func5::func;
	return execfunc(this);
}

namespace _func6
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetShipMarker", typeid(int (AchievementTracker::*)(const std::string &, const std::string &)), "5557565383ec2c8b7424448b5c24488b168b038b7af48b68f48954240489042439ef89e90f46cf894c2408", argdata, 3, 2, &func);
}

int AchievementTracker::GetShipMarker(const std::string &baseName, const std::string &thisName)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &baseName_arg, const std::string &thisName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func6::func;
	return execfunc(this, baseName, thisName);
}

namespace _func7
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(void (AchievementTracker::*)(const std::string &)), "5589e557565383ec5c8b5d088d532889d78955b88b550c8d43248945b4894424048d45c489042489542408", argdata, 2, 6, &func);
}

void AchievementTracker::SetFlag(const std::string &flagName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func7::func;
	return execfunc(this, flagName);
}

namespace _func8
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::GetFlag", typeid(bool (AchievementTracker::*)(const std::string &)), "5589e557565383ec5c8b5d088d432489c28945b48d432889c78945b88b450c89542404894424088d45c4890424??????????31c089fa83ec043b7dc4", argdata, 2, 2, &func);
}

bool AchievementTracker::GetFlag(const std::string &flagName)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func8::func;
	return execfunc(this, flagName);
}

namespace _func9
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SaveProfile", typeid(void (AchievementTracker::*)(int )), "5557565383ec1c8b7c24308b6f188b5f1c29ebc1fb0285db", argdata, 2, 6, &func);
}

void AchievementTracker::SaveProfile(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func9::func;
	return execfunc(this, file);
}

namespace _func10
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::LoadProfile", typeid(void (AchievementTracker::*)(int , int )), "5589e557565383ec4c8b750c8d7dd8893424", argdata, 3, 6, &func);
}

void AchievementTracker::LoadProfile(int file, int version)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, int file_arg, int version_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func10::func;
	return execfunc(this, file, version);
}

namespace _func11
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(void (AchievementTracker::*)()), "57565383ec308b7424408d5c2420891c248d7e6c897c2404", argdata, 1, 6, &func);
}

void AchievementTracker::SetVictoryAchievement()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func11::func;
	return execfunc(this);
}

namespace _func12
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::OnLanguageChange", typeid(void (AchievementTracker::*)()), "5589e557565381ec9c0000008b75088b45088b4e1c8b4018", argdata, 1, 6, &func);
}

void AchievementTracker::OnLanguageChange()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func12::func;
	return execfunc(this);
}

namespace _func13
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetTooltip", typeid(void (AchievementTracker::*)(CAchievement *)), "5589e557565381ecbc0000008b450c80781400", argdata, 2, 6, &func);
}

void AchievementTracker::SetTooltip(CAchievement *ach)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, CAchievement *ach_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func13::func;
	return execfunc(this, ach);
}

namespace _func14
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::ResetFlags", typeid(void (AchievementTracker::*)()), "565383ec148b7424208b462c894424048d4624890424", argdata, 1, 6, &func);
}

void AchievementTracker::ResetFlags()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func14::func;
	return execfunc(this);
}

namespace _func15
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::OnLoop", typeid(void (AchievementTracker::*)()), "554889e5415741564154534883ec204989fc", argdata, 1, 6, &func);
}

void AchievementTracker::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func15::func;
	return execfunc(this);
}

AchievementTracker *Global_AchievementTracker_Tracker;

namespace _var16
{
    static VariableDefinition varObj("Global_AchievementTracker_Tracker", "!e8????????89742404c70424(???????\?)e8????????8b44242c8d50f4", &Global_AchievementTracker_Tracker);
}

namespace _func17
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::constructor", typeid(void (Animation::*)(const std::string &, int , float , Pointf , int , int , int , int )), "5557565383ec3c8b5c????8b44????8b54????f30f1044????c74304000000008b7c????89433c8d??242f8b74????f30f114324", argdata, 9, 6, &func);
}

void Animation::constructor(const std::string &_image, int _length, float _time, Pointf _position, int _imageWidth, int _imageHeight, int _stripStartX, int _numFrames)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, const std::string &_image_arg, int _length_arg, float _time_arg, Pointf _position_arg, int _imageWidth_arg, int _imageHeight_arg, int _stripStartX_arg, int _numFrames_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func17::func;
	return execfunc(this, _image, _length, _time, _position, _imageWidth, _imageHeight, _stripStartX, _numFrames);
}

namespace _func18
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::OnRender", typeid(void (Animation::*)(float , GL_Color , bool )), "57565383ec508b4424788b5c246084c089c675??0fb6735cf30f10442464f30f104b708b7b58f30f59442474f30f11442420", argdata, 4, 6, &func);
}

void Animation::OnRender(float opacity, GL_Color color, bool mirror)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func18::func;
	return execfunc(this, opacity, color, mirror);
}

namespace _func19
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Animation::Update", typeid(void (Animation::*)()), "5557565383ec4c8b5c24608b4304807b3000f30f2ad0", argdata, 1, 6, &func);
}

void Animation::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func19::func;
	return execfunc(this);
}

namespace _func20
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetCurrentFrame", typeid(void (Animation::*)(int )), "8b4424048b48048d51ff395424080f4e54240885d27e??f30f2ac20f57d2f30f2ad9", argdata, 2, 6, &func);
}

void Animation::SetCurrentFrame(int frame)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func20::func;
	return execfunc(this, frame);
}

namespace _func21
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::Start", typeid(void (Animation::*)(bool )), "5383ec28807c2434008b5c24300f85????????f30f10432c0f57c9c6433200c6433001c6433100f30f5e43240f2ec1", argdata, 2, 6, &func);
}

void Animation::Start(bool reset)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func21::func;
	return execfunc(this, reset);
}

namespace _func22
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::AddSoundQueue", typeid(void (Animation::*)(int , const std::string &)), "565383ec148b5424248b4424208b74242885d278??8b48608b406429c8c1f802", argdata, 3, 6, &func);
}

void Animation::AddSoundQueue(int frame, const std::string &sound)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func22::func;
	return execfunc(this, frame, sound);
}

namespace _func23
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetAnimationId", typeid(void (Animation::*)(GL_Texture *)), "8b4424048b542408391074??89d185c9891074??8b4a0489480889d185c974??8b520889500c", argdata, 2, 6, &func);
}

void Animation::SetAnimationId(GL_Texture *tex)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, GL_Texture *tex_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func23::func;
	return execfunc(this, tex);
}

namespace _func24
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Animation::destructor", typeid(void (Animation::*)()), "5557565383ec2c8d44241f894424048b4424408b40748944240883e80c890424e8????????8b4424408b4c24408b40648b69608944240839e8", argdata, 1, 6, &func);
}

void Animation::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func24::func;
	return execfunc(this);
}

namespace _func25
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::StartReverse", typeid(void (Animation::*)(bool )), "5383ec288b4424348b5c243084c075??f30f10432c0f57c9c6433200c64330010f2ec8", argdata, 2, 6, &func);
}

void Animation::StartReverse(bool reset)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func25::func;
	return execfunc(this, reset);
}

namespace _func26
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetProgress", typeid(void (Animation::*)(float )), "8b4424040f57c0f30f10542408f30f1048248b500480783000f30f59d1f30f2adaf30f11502c", argdata, 2, 6, &func);
}

void Animation::SetProgress(float progress)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func26::func;
	return execfunc(this, progress);
}

namespace _func27
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Animation::RandomStart", typeid(int (Animation::*)()), "5383ec08803d????????008b5c241075??e8????????8b4b0499c6433200c6433001c6433100f7f9", argdata, 1, 2, &func);
}

int Animation::RandomStart()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func27::func;
	return execfunc(this);
}

namespace _func28
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::SaveState", typeid(void (Animation::*)(int )), "!565383ec148b5c24208b7424240fb64330", argdata, 2, 6, &func);
}

void Animation::SaveState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func28::func;
	return execfunc(this, fd);
}

namespace _func29
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Animation::Done", typeid(bool (Animation::*)()), ".8b54240431c0807a3200", argdata, 1, 2, &func);
}

bool Animation::Done()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func29::func;
	return execfunc(this);
}

namespace _func30
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::LoadState", typeid(void (Animation::*)(int )), ".565383ec148b7424248b5c2420893424", argdata, 2, 6, &func);
}

void Animation::LoadState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func30::func;
	return execfunc(this, fd);
}

namespace _func31
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationControl::GetAnimation", typeid(Animation (AnimationControl::*)(const std::string &)), "5589e557565381ec1c0100008b4510c7442404????????890424??????????85c0", argdata, 3, 18, &func);
}

Animation AnimationControl::GetAnimation(const std::string &animName)
{
	typedef Animation __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationControl *this_arg, const std::string &animName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func31::func;
	return execfunc(this, animName);
}

AnimationControl *Global_AnimationControl_Animations;

namespace _var32
{
    static VariableDefinition varObj("Global_AnimationControl_Animations", "!89c6890424c7442404(???????\?)8985d4feffff", &Global_AnimationControl_Animations);
}

namespace _func33
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Update", typeid(void (AnimationTracker::*)()), "5383ec188b5c2420807b10000f84????????807b08000f84????????f30f104b180f57c00f2ec80f87????????807b11000f84????????0f2e430c7a??8d760075??", argdata, 1, 6, &func);
}

void AnimationTracker::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func33::func;
	return execfunc(this);
}

namespace _func34
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetLoop", typeid(void (AnimationTracker::*)(bool , float )), "8b4424048b542408f30f1044240cc7401800000000885008f30f114014", argdata, 3, 6, &func);
}

void AnimationTracker::SetLoop(bool loop, float loopDelay)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool loop_arg, float loopDelay_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func34::func;
	return execfunc(this, loop, loopDelay);
}

namespace _func35
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Stop", typeid(void (AnimationTracker::*)(bool )), "8b54????0f57c08b44????84d2c640100074??f30f10400cf30f11400c", argdata, 2, 6, &func);
}

void AnimationTracker::Stop(bool resetTime)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool resetTime_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func35::func;
	return execfunc(this, resetTime);
}

namespace _func36
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Start", typeid(void (AnimationTracker::*)(float )), "8b44????f30f1044????c6401200c6401001f30f11400cc6401100", argdata, 2, 6, &func);
}

void AnimationTracker::Start(float time)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func36::func;
	return execfunc(this, time);
}

namespace _func37
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::StartReverse", typeid(void (AnimationTracker::*)(float )), "8b44????0f57c9f30f1044????0f2ec8c6401200c640100176??f30f104004f30f11400cc6401101", argdata, 2, 6, &func);
}

void AnimationTracker::StartReverse(float time)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func37::func;
	return execfunc(this, time);
}

namespace _func38
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Progress", typeid(float (AnimationTracker::*)(float )), "83ec040f57c08b44????f30f104c????8078100074??0f2ec10f28d077??f30f10400cf30f5ec10f2ec2", argdata, 2, 2, &func);
}

float AnimationTracker::Progress(float speed)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float speed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func38::func;
	return execfunc(this, speed);
}

namespace _func39
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetProgress", typeid(void (AnimationTracker::*)(float )), "8b442404f30f104004f30f59442408f30f11400c", argdata, 2, 6, &func);
}

void AnimationTracker::SetProgress(float time)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func39::func;
	return execfunc(this, time);
}

namespace _func40
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::GetAlphaLevel", typeid(float (AnimationTracker::*)(bool )), "83ec048b44????f30f1005????????f30f1015????????807c????00f30f594004f30f10480cf30f5cc80f28d80f54caf30f5cd90f28cbf30f5ec8", argdata, 2, 2, &func);
}

float AnimationTracker::GetAlphaLevel(bool reverse)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool reverse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func40::func;
	return execfunc(this, reverse);
}

namespace _func41
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::KeyDown", typeid(bool (ArmamentControl::*)(SDLKey )), "57565331db83ec108b7c24208b7424248b57108b471429d0c1f80285c0", argdata, 2, 2, &func);
}

bool ArmamentControl::KeyDown(SDLKey key)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func41::func;
	return execfunc(this, key);
}

namespace _func42
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::Dragging", typeid(bool (ArmamentControl::*)()), ".5383ec188b5c2420837b70ff74??8b43688b536c894424048d436089542408890424", argdata, 1, 2, &func);
}

bool ArmamentControl::Dragging()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func42::func;
	return execfunc(this);
}

namespace _func43
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::CreateHolderTab", typeid(void (ArmamentControl::*)()), ".5589e557565383ec7c8b75088d45c88d7dd889442408", argdata, 1, 6, &func);
}

void ArmamentControl::CreateHolderTab()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func43::func;
	return execfunc(this);
}

namespace _func44
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ArmamentControl::SetPosition", typeid(void (ArmamentControl::*)(Point )), ".565383ec148b7424208b4424248b54242839461c74??89461c", argdata, 2, 6, &func);
}

void ArmamentControl::SetPosition(Point loc)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, Point loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func44::func;
	return execfunc(this, loc);
}

namespace _func45
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::LinkShip", typeid(void (ArmamentControl::*)(ShipManager *)), ".5589e557565383ec6c8b5d088b450c8b4b148b531089430c89c829d0", argdata, 2, 6, &func);
}

void ArmamentControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func45::func;
	return execfunc(this, ship);
}

namespace _func46
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ArtilleryBox::constructor", typeid(void (ArtilleryBox::*)(Point , ArtillerySystem *)), "565383ec248b5c24308b74243c8b4424348b542438891c2481c3f4010000", argdata, 3, 6, &func);
}

void ArtilleryBox::constructor(Point pos, ArtillerySystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, Point pos_arg, ArtillerySystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func46::func;
	return execfunc(this, pos, sys);
}

namespace _func47
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ArtilleryBox::OnRender", typeid(void (ArtilleryBox::*)(bool )), "5557565381ec1c0100008b9c24300100008d6c24580fb6842434010000891c2489442404e8????????e8????????c744240800000000", argdata, 2, 6, &func);
}

void ArtilleryBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func47::func;
	return execfunc(this, ignoreStatus);
}

namespace _func48
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ArtillerySystem::Jump", typeid(void (ArtillerySystem::*)()), "8b4424048b8098010000c7400800000000", argdata, 1, 6, &func);
}

void ArtillerySystem::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArtillerySystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func48::func;
	return execfunc(this);
}

namespace _func49
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ArtillerySystem::OnLoop", typeid(void (ArtillerySystem::*)()), ".5589e557565383ec6c8b5d08891c24e8????????891c24e8????????85c0", argdata, 1, 6, &func);
}

void ArtillerySystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ArtillerySystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func49::func;
	return execfunc(this);
}

namespace _func50
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Asteroid::OnUpdate", typeid(void (Asteroid::*)()), "5589e55383ec448b5d0880bbb0000000007415c783f001000000000000", argdata, 1, 6, &func);
}

void Asteroid::OnUpdate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Asteroid *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func50::func;
	return execfunc(this);
}

namespace _func51
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Asteroid::constructor", typeid(void (Asteroid::*)(Pointf , int )), ".5589e557565381ec1c0100008b5d14", argdata, 3, 6, &func);
}

void Asteroid::constructor(Pointf pos, int destinationSpace)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Asteroid *this_arg, Pointf pos_arg, int destinationSpace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func51::func;
	return execfunc(this, pos, destinationSpace);
}

namespace _func52
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::constructor", typeid(void (AsteroidGenerator::*)()), "5557565383ec1cc70424200000008b5c2430e8????????89c78d400c89c1894424048d471039c1", argdata, 1, 6, &func);
}

void AsteroidGenerator::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func52::func;
	return execfunc(this);
}

namespace _func53
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), ".5383ec188b4424288b5c24208b54242c89c1c1e91f89838c00000001c8d1f883f801", argdata, 4, 2, &func);
}

float AsteroidGenerator::Initialize(int numberOfShips, int shieldCount, bool defense)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int numberOfShips_arg, int shieldCount_arg, bool defense_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func53::func;
	return execfunc(this, numberOfShips, shieldCount, defense);
}

namespace _func54
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SetNumShips", typeid(void (AsteroidGenerator::*)(int )), ".8b5424088b442404895070", argdata, 2, 6, &func);
}

void AsteroidGenerator::SetNumShips(int ships)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int ships_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func54::func;
	return execfunc(this, ships);
}

namespace _func55
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextAsteroid", typeid(Projectile *(AsteroidGenerator::*)()), ".5557565381ecbc0100008b9c24d00100008b43083943180f84????????8b08", argdata, 1, 2, &func);
}

Projectile *AsteroidGenerator::GetNextAsteroid()
{
	typedef Projectile *__attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func55::func;
	return execfunc(this);
}

namespace _func56
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::OnLoop", typeid(void (AsteroidGenerator::*)()), ".5589e557565383ec3c8b5d0880bb880000000075??8d65f45b5e5f5d", argdata, 1, 6, &func);
}

void AsteroidGenerator::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func56::func;
	return execfunc(this);
}

namespace _func57
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextState", typeid(void (AsteroidGenerator::*)()), ".5383ec188b5c24208b437485c074??c743740000000031c0", argdata, 1, 6, &func);
}

void AsteroidGenerator::GetNextState()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func57::func;
	return execfunc(this);
}

namespace _func58
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::UpdateState", typeid(void (AsteroidGenerator::*)()), ".5383ec18c70424????????8b5c2420e8????????f30f108380000000", argdata, 1, 6, &func);
}

void AsteroidGenerator::UpdateState()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func58::func;
	return execfunc(this);
}

namespace _func59
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SaveAsteroids", typeid(bool (AsteroidGenerator::*)(void *)), ".565383ec148b742420f30f1005????????8b5c2424f30f598680000000891c24f30f2cc0", argdata, 2, 2, &func);
}

bool AsteroidGenerator::SaveAsteroids(void *file)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, void *file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func59::func;
	return execfunc(this, file);
}

namespace _func60
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::LoadAsteroids", typeid(void (AsteroidGenerator::*)(void *)), ".565383ec148b7424248b5c2420893424", argdata, 2, 6, &func);
}

void AsteroidGenerator::LoadAsteroids(void *file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, void *file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func60::func;
	return execfunc(this, file);
}

namespace _func61
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AugmentEquipBox::RenderIcon", typeid(void (AugmentEquipBox::*)()), "5383ec188b5c2420e8????????c7442408000000008b4338f7d8f30f2ac0", argdata, 1, 6, &func);
}

void AugmentEquipBox::RenderIcon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func61::func;
	return execfunc(this);
}

namespace _func62
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AugmentEquipBox::CheckContents", typeid(void (AugmentEquipBox::*)()), "5589e557565383ec3c8b7d088b477085c0", argdata, 1, 6, &func);
}

void AugmentEquipBox::CheckContents()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func62::func;
	return execfunc(this);
}

namespace _func63
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AugmentEquipBox::RemoveItem", typeid(void (AugmentEquipBox::*)()), "565383ec248b5c24308b437085c0", argdata, 1, 6, &func);
}

void AugmentEquipBox::RemoveItem()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func63::func;
	return execfunc(this);
}

namespace _func64
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AugmentEquipBox::constructor", typeid(void (AugmentEquipBox::*)(Point , ShipManager *, int )), "57565383ec508d", argdata, 4, 6, &func);
}

void AugmentEquipBox::constructor(Point loc, ShipManager *shipManager, int slot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg, Point loc_arg, ShipManager *shipManager_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func64::func;
	return execfunc(this, loc, shipManager, slot);
}

namespace _func65
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AugmentStoreBox::constructor", typeid(void (AugmentStoreBox::*)(ShipManager *, const AugmentBlueprint *)), "5557565383ec2c8d44241a8b5c24408d7c241c8b742448", argdata, 3, 6, &func);
}

void AugmentStoreBox::constructor(ShipManager *ship, const AugmentBlueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentStoreBox *this_arg, ShipManager *ship_arg, const AugmentBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func65::func;
	return execfunc(this, ship, bp);
}

namespace _func66
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("AugmentStoreBox::CanHold", typeid(bool (AugmentStoreBox::*)()), "565383ec348b5c24408b", argdata, 1, 2, &func);
}

bool AugmentStoreBox::CanHold()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func66::func;
	return execfunc(this);
}

namespace _func67
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AugmentStoreBox::MouseMove", typeid(void (AugmentStoreBox::*)(int , int )), "5589e557565383ec4c8b45108b5d08c744", argdata, 3, 6, &func);
}

void AugmentStoreBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(AugmentStoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func67::func;
	return execfunc(this, mX, mY);
}

namespace _func68
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("BatteryBox::constructor", typeid(void (BatteryBox::*)(Point , BatterySystem *)), "5557565383ec7c8b9c24900000008d7c243e8b9424980000008bb4249c0000008b842494000000", argdata, 3, 6, &func);
}

void BatteryBox::constructor(Point pos, BatterySystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BatteryBox *this_arg, Point pos_arg, BatterySystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func68::func;
	return execfunc(this, pos, sys);
}

namespace _func69
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::OnRenderSpecific", typeid(void (BeamWeapon::*)(int )), "5589e557565381ecbc0000008b5d0880bb6c0200", argdata, 2, 6, &func);
}

void BeamWeapon::OnRenderSpecific(int spaceId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, int spaceId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func69::func;
	return execfunc(this, spaceId);
}

namespace _func70
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x2ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::constructor", typeid(void (BeamWeapon::*)(Pointf , int , int , Pointf , Pointf , int , Targetable *, float )), ".565383ec308b451c8b55208b75088b5d30", argdata, 9, 6, &func);
}

void BeamWeapon::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, Pointf _target2_arg, int _length_arg, Targetable *_targetable_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func70::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _target2, _length, _targetable, heading);
}

namespace _func71
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::OnUpdate", typeid(void (BeamWeapon::*)()), ".5589e557565383ec4c8b5d0880bb6c02000000", argdata, 1, 6, &func);
}

void BeamWeapon::OnUpdate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func71::func;
	return execfunc(this);
}

namespace _func72
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::CollisionCheck", typeid(void (BeamWeapon::*)(Collideable *)), ".5589e557565381ec8c0100008b7d08", argdata, 2, 6, &func);
}

void BeamWeapon::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func72::func;
	return execfunc(this, other);
}

namespace _func73
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Blueprint::destructor", typeid(void (Blueprint::*)()), "565383ec248b5c24308b433cc703????????8d50f481fa????????75608b43348d50f481fa????????0f85????????8b43188d50f481fa????????", argdata, 1, 6, &func);
}

void Blueprint::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Blueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func73::func;
	return execfunc(this);
}

namespace _func74
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Blueprint::GetNameShort", typeid(std::string (Blueprint::*)()), "5589e55383ec148b450c8b5d0880781400", argdata, 2, 18, &func);
}

std::string Blueprint::GetNameShort()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(Blueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func74::func;
	return execfunc(this);
}

namespace _func75
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetBlueprintList", typeid(std::vector<std::string> (BlueprintManager::*)(const std::string &)), "5589e557565383ec5c8b5d10e8????????84c08b450c", argdata, 3, 18, &func);
}

std::vector<std::string> BlueprintManager::GetBlueprintList(const std::string &name)
{
	typedef std::vector<std::string> __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func75::func;
	return execfunc(this, name);
}

namespace _func76
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(const std::string &, int )), "5589e557565383ec6c8b7d0c8d45d88b75088904248b5d10897c2404", argdata, 3, 2, &func);
}

ShipBlueprint *BlueprintManager::GetShipBlueprint(const std::string &name, int sector)
{
	typedef ShipBlueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func76::func;
	return execfunc(this, name, sector);
}

namespace _func77
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetDroneBlueprint", typeid(DroneBlueprint *(BlueprintManager::*)(const std::string &)), ".5589e557565383ec4c8d7dd78d75d8897c2408", argdata, 2, 2, &func);
}

DroneBlueprint *BlueprintManager::GetDroneBlueprint(const std::string &name)
{
	typedef DroneBlueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func77::func;
	return execfunc(this, name);
}

namespace _func78
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentValue", typeid(float (BlueprintManager::*)(const std::string &)), "5589e557565383ec5c8b5d088d434c89c28945b48d435089c7", argdata, 2, 2, &func);
}

float BlueprintManager::GetAugmentValue(const std::string &name)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func78::func;
	return execfunc(this, name);
}

namespace _func79
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetItemBlueprint", typeid(ItemBlueprint *(BlueprintManager::*)(const std::string &)), "5589e557565383ec5c8b55088b45088bbacc00000005c80000008945b885ff", argdata, 2, 2, &func);
}

ItemBlueprint *BlueprintManager::GetItemBlueprint(const std::string &name)
{
	typedef ItemBlueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func79::func;
	return execfunc(this, name);
}

namespace _func80
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentBlueprint", typeid(AugmentBlueprint *(BlueprintManager::*)(const std::string &)), ".5589e557565383ec4c8d7dd78d75d8897c2408", argdata, 2, 2, &func);
}

AugmentBlueprint *BlueprintManager::GetAugmentBlueprint(const std::string &name)
{
	typedef AugmentBlueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func80::func;
	return execfunc(this, name);
}

namespace _func81
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessWeaponBlueprint", typeid(WeaponBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "5589e557565381ec8c0000008b45088b75108d7db0890424", argdata, 3, 18, &func);
}

WeaponBlueprint BlueprintManager::ProcessWeaponBlueprint(rapidxml::xml_node<char> *node)
{
	typedef WeaponBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func81::func;
	return execfunc(this, node);
}

namespace _func82
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDescription", typeid(Description (BlueprintManager::*)(rapidxml::xml_node<char> *)), "5589e557565383ec6c8b7d088d5de0895c2408", argdata, 3, 18, &func);
}

Description BlueprintManager::ProcessDescription(rapidxml::xml_node<char> *node)
{
	typedef Description __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func82::func;
	return execfunc(this, node);
}

namespace _func83
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessEffectsBlueprint", typeid(EffectsBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "55660fefc089e557565383ec3c8b45088d5ddc", argdata, 3, 18, &func);
}

EffectsBlueprint BlueprintManager::ProcessEffectsBlueprint(rapidxml::xml_node<char> *node)
{
	typedef EffectsBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func83::func;
	return execfunc(this, node);
}

namespace _func84
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewBlueprint", typeid(CrewBlueprint (BlueprintManager::*)(const std::string &)), "5589e557565383ec5c8b5d088b7510", argdata, 3, 18, &func);
}

CrewBlueprint BlueprintManager::GetCrewBlueprint(const std::string &name)
{
	typedef CrewBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func84::func;
	return execfunc(this, name);
}

namespace _func85
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetWeaponBlueprint", typeid(WeaponBlueprint *(BlueprintManager::*)(const std::string &)), "5589e557565383ec7c8b5d088b750c", argdata, 2, 2, &func);
}

WeaponBlueprint *BlueprintManager::GetWeaponBlueprint(const std::string &name)
{
	typedef WeaponBlueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func85::func;
	return execfunc(this, name);
}

namespace _func86
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomAugment", typeid(std::vector<AugmentBlueprint*> (BlueprintManager::*)(int , bool )), "5589e55383ec240fb655148b450c8b5d08895424108b551089442404891c248954240c8d504c", argdata, 4, 18, &func);
}

std::vector<AugmentBlueprint*> BlueprintManager::GetRandomAugment(int count, bool demo_lock)
{
	typedef std::vector<AugmentBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func86::func;
	return execfunc(this, count, demo_lock);
}

namespace _func87
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetSystemBlueprint", typeid(SystemBlueprint *(BlueprintManager::*)(const std::string &)), "5589e557565383ec5c8b55088b45088bbae4000000", argdata, 2, 2, &func);
}

SystemBlueprint *BlueprintManager::GetSystemBlueprint(const std::string &name)
{
	typedef SystemBlueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func87::func;
	return execfunc(this, name);
}

namespace _func88
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetUnusedCrewName", typeid(std::string (BlueprintManager::*)(bool *)), "5589e557565383ec3c8b4508c745c415000000", argdata, 3, 18, &func);
}

std::string BlueprintManager::GetUnusedCrewName(bool *isMale_ret)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, bool *isMale_ret_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func88::func;
	return execfunc(this, isMale_ret);
}

namespace _func89
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetCrewName", typeid(std::string (BlueprintManager::*)(bool *)), "5557565383ec4c8b5c2464c7442404????????", argdata, 3, 18, &func);
}

std::string BlueprintManager::GetCrewName(bool *isMale_ret)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, bool *isMale_ret_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func89::func;
	return execfunc(this, isMale_ret);
}

namespace _func90
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomWeapon", typeid(std::vector<WeaponBlueprint*> (BlueprintManager::*)(int , bool )), "5589e55383ec240fb655148b450c8b5d08895424108b551089442404891c248954240c8d501c", argdata, 4, 18, &func);
}

std::vector<WeaponBlueprint*> BlueprintManager::GetRandomWeapon(int count, bool demo_lock)
{
	typedef std::vector<WeaponBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func90::func;
	return execfunc(this, count, demo_lock);
}

namespace _func91
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomDrone", typeid(std::vector<DroneBlueprint*> (BlueprintManager::*)(int , bool )), "5589e55383ec240fb655148b450c8b5d08895424108b551089442404891c248954240c8d5034", argdata, 4, 18, &func);
}

std::vector<DroneBlueprint*> BlueprintManager::GetRandomDrone(int count, bool demo_lock)
{
	typedef std::vector<DroneBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func91::func;
	return execfunc(this, count, demo_lock);
}

namespace _func92
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessShipBlueprint", typeid(ShipBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "5589e557565381ecbc0000008b75088d7da8", argdata, 3, 18, &func);
}

ShipBlueprint BlueprintManager::ProcessShipBlueprint(rapidxml::xml_node<char> *node)
{
	typedef ShipBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func92::func;
	return execfunc(this, node);
}

namespace _func93
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::ProcessDroneBlueprint", typeid(DroneBlueprint (BlueprintManager::*)(rapidxml::xml_node<char> *)), "5589e557565383ec7c8b45088d5da8", argdata, 3, 18, &func);
}

DroneBlueprint BlueprintManager::ProcessDroneBlueprint(rapidxml::xml_node<char> *node)
{
	typedef DroneBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func93::func;
	return execfunc(this, node);
}

namespace _func94
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetSkillIcon", typeid(GL_Texture *(*)(int , bool )), "5589e557565383ec3c8b550c8b5d080fb6f2", argdata, 2, 2, &func);
}

GL_Texture *BlueprintManager::GetSkillIcon(int skill, bool outline)
{
	typedef GL_Texture *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int skill_arg, bool outline_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func94::func;
	return execfunc(skill, outline);
}

BlueprintManager *Global_BlueprintManager_Blueprints;

namespace _var95
{
    static VariableDefinition varObj("Global_BlueprintManager_Blueprints", "!c7442408ffffffff895c2404c70424(???????\?)e8????????c74424080000000089342489442404", &Global_BlueprintManager_Blueprints);
}

namespace _func96
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::OnLoop", typeid(void (BoarderPodDrone::*)()), "5589e557565381ecdc0000008b????", argdata, 1, 6, &func);
}

void BoarderPodDrone::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func96::func;
	return execfunc(this);
}

namespace _func97
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::constructor", typeid(void (BoarderPodDrone::*)(int , int , const DroneBlueprint &)), ".5589e557565381ecdc0000008b45148b4d088dbd58ffffff", argdata, 4, 6, &func);
}

void BoarderPodDrone::constructor(int _iShipId, int _selfId, const DroneBlueprint &_bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, int _iShipId_arg, int _selfId_arg, const DroneBlueprint &_bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func97::func;
	return execfunc(this, _iShipId, _selfId, _bp);
}

namespace _func98
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::SetMovementTarget", typeid(void (BoarderPodDrone::*)(Targetable *)), "5383ec288b4424348b5c243085c0", argdata, 2, 6, &func);
}

void BoarderPodDrone::SetMovementTarget(Targetable *target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func98::func;
	return execfunc(this, target);
}

namespace _func99
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("BoarderPodDrone::_DO_NOT_HOOK_1", typeid(void (BoarderPodDrone::*)()), "5531c089e55383ec24", argdata, 0, 4, &func);
}

namespace _func100
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::CanBeDeployed", typeid(bool (BoarderPodDrone::*)()), ".5531c089e55383ec24", argdata, 1, 2, &func);
}

bool BoarderPodDrone::CanBeDeployed()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func100::func;
	return execfunc(this);
}

namespace _func101
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::SetDeployed", typeid(void (BoarderPodDrone::*)(bool )), "57565383ec108b5c24208b742424807b1400", argdata, 2, 6, &func);
}

void BoarderPodDrone::SetDeployed(bool _deployed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, bool _deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func101::func;
	return execfunc(this, _deployed);
}

namespace _func102
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("BoarderPodDrone::CollisionMoving", typeid(CollisionResponse (BoarderPodDrone::*)(Pointf , Pointf , Damage , bool )), ".5557565383ec3c8b6c24548b5c245080bd6803000000", argdata, 6, 18, &func);
}

CollisionResponse BoarderPodDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(BoarderPodDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func102::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func103
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BombProjectile::OnUpdate", typeid(void (BombProjectile::*)()), "565383ec148b5c24208db310010000", argdata, 1, 6, &func);
}

void BombProjectile::OnUpdate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BombProjectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func103::func;
	return execfunc(this);
}

namespace _func104
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BombProjectile::CollisionCheck", typeid(void (BombProjectile::*)(Collideable *)), ".5589e557565383ec7c8b5d0c8b7508", argdata, 2, 6, &func);
}

void BombProjectile::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BombProjectile *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func104::func;
	return execfunc(this, other);
}

namespace _func105
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("BombProjectile::constructor", typeid(void (BombProjectile::*)(Pointf , int , int , Pointf )), ".5589e557565381ecdc0000008b451c8b55208d9d54ffffff", argdata, 5, 6, &func);
}

void BombProjectile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BombProjectile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func105::func;
	return execfunc(this, _position, _ownerId, _targetId, _target);
}

namespace _func106
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::Restart", typeid(void (BossShip::*)()), "8b442404c7803401000000000000c7806001000001000000c6805c01000001", argdata, 1, 6, &func);
}

void BossShip::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func106::func;
	return execfunc(this);
}

namespace _func107
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::IncomingFire", typeid(bool (BossShip::*)()), ".8b442404f30f100d????????f30f108044010000f30f5c8040010000", argdata, 1, 2, &func);
}

bool BossShip::IncomingFire()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func107::func;
	return execfunc(this);
}

namespace _func108
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BossShip::constructor", typeid(void (BossShip::*)(SpaceManager *)), ".!5383ec188b5c24208b442424c744240c01000000", argdata, 2, 6, &func);
}

void BossShip::constructor(SpaceManager *space)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg, SpaceManager *space_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func108::func;
	return execfunc(this, space);
}

namespace _func109
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::ClearLocation", typeid(void (BossShip::*)()), ".5383ec188b5c24208b430885c074??8b10", argdata, 1, 6, &func);
}

void BossShip::ClearLocation()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func109::func;
	return execfunc(this);
}

namespace _func110
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::Defeated", typeid(bool (BossShip::*)()), ".83ec1c31c08b54242083ba3401000003", argdata, 1, 2, &func);
}

bool BossShip::Defeated()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func110::func;
	return execfunc(this);
}

namespace _func111
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(LocationEvent *(BossShip::*)()), ".5557565383ec3c8b5c2450891c24e8????????84c0", argdata, 1, 2, &func);
}

LocationEvent *BossShip::GetSubEvent()
{
	typedef LocationEvent *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func111::func;
	return execfunc(this);
}

namespace _func112
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(void (BossShip::*)()), ".5557565381ec1c0100008b8424300100008d5c24588bbc2430010000", argdata, 1, 6, &func);
}

void BossShip::StartStage()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func112::func;
	return execfunc(this);
}

namespace _func113
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BossShip::SaveBoss", typeid(void (BossShip::*)(int )), ".57565383ec108b7c24208b7424248b873401000089342489442404", argdata, 2, 6, &func);
}

void BossShip::SaveBoss(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func113::func;
	return execfunc(this, file);
}

namespace _func114
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::GetEvent", typeid(LocationEvent *(BossShip::*)()), ".5557565381ec0c0100008d742474893424e8????????8b1d????????", argdata, 1, 2, &func);
}

LocationEvent *BossShip::GetEvent()
{
	typedef LocationEvent *__attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func114::func;
	return execfunc(this);
}

namespace _func115
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(void (BossShip::*)(int )), ".5557565383ec2c8b5c24448b6c2440891c24", argdata, 2, 6, &func);
}

void BossShip::LoadBoss(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func115::func;
	return execfunc(this, file);
}

namespace _func116
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("BossShip::OnLoop", typeid(void (BossShip::*)()), ".5557565383ec2c8b5c2440c6831001000001891c24", argdata, 1, 6, &func);
}

void BossShip::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func116::func;
	return execfunc(this);
}

namespace _func117
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Button::SetLocation", typeid(void (Button::*)(const Point )), "5756538b4424108b5424148b4c24188b58048b700839d3", argdata, 2, 6, &func);
}

void Button::SetLocation(const Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg, const Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func117::func;
	return execfunc(this, pos);
}

namespace _func118
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(const std::string &, Point )), "5557565383ec4c8b6c2464", argdata, 3, 6, &func);
}

void Button::OnInit(const std::string &img, Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg, const std::string &img_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func118::func;
	return execfunc(this, img, pos);
}

namespace _func119
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Button::constructor", typeid(void (Button::*)()), "565383ec148b5c24208d4304c703????????8d7324", argdata, 1, 6, &func);
}

void Button::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func119::func;
	return execfunc(this);
}

namespace _func120
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Button::OnRender", typeid(void (Button::*)()), "57565383ec408b5c24508b435485c0", argdata, 1, 6, &func);
}

void Button::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func120::func;
	return execfunc(this);
}

namespace _func121
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Button::SetInactiveImage", typeid(void (Button::*)(GL_Texture *)), "8b4424048b542408395048", argdata, 2, 6, &func);
}

void Button::SetInactiveImage(GL_Texture *texture)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg, GL_Texture *texture_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func121::func;
	return execfunc(this, texture);
}

namespace _func122
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Button::SetActiveImage", typeid(void (Button::*)(GL_Texture *)), "8b4424048b54240839504c", argdata, 2, 6, &func);
}

void Button::SetActiveImage(GL_Texture *texture)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg, GL_Texture *texture_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func122::func;
	return execfunc(this, texture);
}

namespace _func123
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Button::SetImageBase", typeid(void (Button::*)(const std::string &)), "5557565383ec2c8b7c24448d5c241c891c248b742440897c2404", argdata, 2, 6, &func);
}

void Button::SetImageBase(const std::string &imageBase)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Button *this_arg, const std::string &imageBase_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func123::func;
	return execfunc(this, imageBase);
}

namespace _func124
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(void (CAchievement::*)(Point , int , bool )), "5589e557565381ec9c0000008b45188b7d108b750c8b5d0889458c", argdata, 4, 6, &func);
}

void CAchievement::OnRender(Point pos, int selected, bool showNew)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CAchievement *this_arg, Point pos_arg, int selected_arg, bool showNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func124::func;
	return execfunc(this, pos, selected, showNew);
}

namespace _func125
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(void (CAchievement::*)()), "5557565383ec2c8b5c24408d74241c897424088d7c241a", argdata, 1, 6, &func);
}

void CAchievement::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CAchievement *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func125::func;
	return execfunc(this);
}

namespace _func126
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnRequestExit", typeid(void (CApp::*)()), "5383ec188b5c24208b430885c074??8b530c", argdata, 1, 6, &func);
}

void CApp::OnRequestExit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func126::func;
	return execfunc(this);
}

namespace _func127
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnExit", typeid(void (CApp::*)()), "83ec1ce8????????c744240400000000c70424????????", argdata, 1, 6, &func);
}

void CApp::OnExit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func127::func;
	return execfunc(this);
}

namespace _func128
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMButtonDown", typeid(void (CApp::*)(int , int )), "8b442404????????????0075??80781000", argdata, 3, 6, &func);
}

void CApp::OnMButtonDown(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func128::func;
	return execfunc(this, x, y);
}

namespace _func129
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnTextInput", typeid(void (CApp::*)(int )), ".8b4424048b542408????????????0075??80781000", argdata, 2, 6, &func);
}

void CApp::OnTextInput(int ch)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int ch_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func129::func;
	return execfunc(this, ch);
}

namespace _func130
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnTextEvent", typeid(void (CApp::*)(CEvent::TextEvent )), ".8b4424048b542408????????????0075??80781000", argdata, 2, 6, &func);
}

void CApp::OnTextEvent(CEvent::TextEvent textEvent)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, CEvent::TextEvent textEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func130::func;
	return execfunc(this, textEvent);
}

namespace _func131
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnInputFocus", typeid(void (CApp::*)()), "5383ec188b5c2420????????????0075??803d????????00", argdata, 1, 6, &func);
}

void CApp::OnInputFocus()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func131::func;
	return execfunc(this);
}

namespace _func132
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnInputBlur", typeid(void (CApp::*)()), "5383ec188b5c2420803d????????008b4308", argdata, 1, 6, &func);
}

void CApp::OnInputBlur()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func132::func;
	return execfunc(this);
}

namespace _func133
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonUp", typeid(void (CApp::*)(int , int )), ".5383ec288b5c24308b4424348b542438", argdata, 3, 6, &func);
}

void CApp::OnRButtonUp(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func133::func;
	return execfunc(this, x, y);
}

namespace _func134
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnRButtonDown", typeid(void (CApp::*)(int , int )), ".5383ec288b5c24308b4424348b542438", argdata, 3, 6, &func);
}

void CApp::OnRButtonDown(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func134::func;
	return execfunc(this, x, y);
}

namespace _func135
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonUp", typeid(void (CApp::*)(int , int )), ".5383ec288b5c24308b4424348b542438", argdata, 3, 6, &func);
}

void CApp::OnLButtonUp(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func135::func;
	return execfunc(this, x, y);
}

namespace _func136
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnLButtonDown", typeid(void (CApp::*)(int , int )), ".5383ec288b5c24308b4424348b542438", argdata, 3, 6, &func);
}

void CApp::OnLButtonDown(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func136::func;
	return execfunc(this, x, y);
}

namespace _func137
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnMouseMove", typeid(void (CApp::*)(int , int , int , int , bool , bool , bool )), "57565383ec208b5c24308b4424348b542438", argdata, 8, 6, &func);
}

void CApp::OnMouseMove(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg, int xdiff_arg, int ydiff_arg, bool holdingLMB_arg, bool holdingRMB_arg, bool holdingMMB_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func137::func;
	return execfunc(this, x, y, xdiff, ydiff, holdingLMB, holdingRMB, holdingMMB);
}

namespace _func138
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyUp", typeid(void (CApp::*)(SDLKey )), "57565383ec208b5c243485db", argdata, 2, 6, &func);
}

void CApp::OnKeyUp(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func138::func;
	return execfunc(this, key);
}

namespace _func139
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnLanguageChange", typeid(void (CApp::*)()), "5589e557565383ec2c8b75088d5de4", argdata, 1, 6, &func);
}

void CApp::OnLanguageChange()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func139::func;
	return execfunc(this);
}

namespace _func140
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::OnKeyDown", typeid(void (CApp::*)(SDLKey )), "5557565383ec4c8b5c246485db", argdata, 2, 6, &func);
}

void CApp::OnKeyDown(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func140::func;
	return execfunc(this, key);
}

namespace _func141
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::constructor", typeid(void (CApp::*)()), "5383ec188b5c2420891c24e8????????8d4310", argdata, 1, 6, &func);
}

void CApp::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func141::func;
	return execfunc(this);
}

namespace _func142
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::ParseArgs", typeid(void (CApp::*)(int , const char **)), ".f3c38db426000000008dbc2700000000", argdata, 3, 6, &func);
}

void CApp::ParseArgs(int argc, const char **argv)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int argc_arg, const char **argv_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func142::func;
	return execfunc(this, argc, argv);
}

namespace _func143
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(void (CApp::*)()), "5589e557565383ec2c8b5d08c70424????????e8????????e8????????884305c70424????????", argdata, 1, 6, &func);
}

void CApp::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func143::func;
	return execfunc(this);
}

namespace _func144
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(int (CApp::*)()), "5383ec38c7442404010000008b5c2440", argdata, 1, 2, &func);
}

int CApp::SetupWindow()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func144::func;
	return execfunc(this);
}

namespace _func145
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnCleanup", typeid(void (CApp::*)()), "565383ec148b5c24208b430c890424", argdata, 1, 6, &func);
}

void CApp::OnCleanup()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func145::func;
	return execfunc(this);
}

namespace _func146
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::GenInputEvents", typeid(void (CApp::*)()), "5383ec188b5c2420e8????????85c00f95??", argdata, 1, 6, &func);
}

void CApp::GenInputEvents()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func146::func;
	return execfunc(this);
}

namespace _func147
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnSuspend", typeid(void (CApp::*)()), "5383ec188b5c2420e8????????8b4308", argdata, 1, 6, &func);
}

void CApp::OnSuspend()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func147::func;
	return execfunc(this);
}

namespace _func148
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnResume", typeid(void (CApp::*)()), "5383ec188b5c242080??????????0075??807b100074??83c4185b", argdata, 1, 6, &func);
}

void CApp::OnResume()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func148::func;
	return execfunc(this);
}

namespace _func149
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CApp::TranslateMouse", typeid(Point (CApp::*)(int , int )), "565383ec148b5424248b4c24288b44242c8b742420", argdata, 4, 18, &func);
}

Point CApp::TranslateMouse(int x, int y)
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func149::func;
	return execfunc(this, x, y);
}

namespace _func150
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::UpdateFullScreen", typeid(void (CApp::*)()), "803d????????0074??c38db600000000575653", argdata, 1, 6, &func);
}

void CApp::UpdateFullScreen()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func150::func;
	return execfunc(this);
}

namespace _func151
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::UpdateWindowSettings", typeid(void (CApp::*)()), "56538b44240c????????????00", argdata, 1, 6, &func);
}

void CApp::UpdateWindowSettings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func151::func;
	return execfunc(this);
}

namespace _func152
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnRender", typeid(void (CApp::*)()), "5589e557565383ec3c8b5d08891c24", argdata, 1, 6, &func);
}

void CApp::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func152::func;
	return execfunc(this);
}

namespace _func153
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), "5589e557565383ec4c8b5d08c7042400000000", argdata, 1, 2, &func);
}

int CApp::OnInit()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func153::func;
	return execfunc(this);
}

namespace _func154
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(int (CApp::*)()), "5589e557565381ecfc0100008b5d08", argdata, 1, 2, &func);
}

int CApp::OnExecute()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func154::func;
	return execfunc(this);
}

namespace _func155
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "5557565383ec3c8b7424548b5c24508b4604f20f104608", argdata, 2, 6, &func);
}

void CEvent::OnEvent(const InputEvent *event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CEvent *this_arg, const InputEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func155::func;
	return execfunc(this, event);
}

namespace _func156
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), "83ec048b4424088b4014890424d9042483c404", argdata, 1, 2, &func);
}

float CFPS::GetSpeedFactor()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func156::func;
	return execfunc(this);
}

namespace _func157
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CFPS::OnLoop", typeid(void (CFPS::*)()), "5383ec188b5c2420f20f1015????????", argdata, 1, 6, &func);
}

void CFPS::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func157::func;
	return execfunc(this);
}

CFPS *Global_CFPS_FPSControl;

namespace _var158
{
    static VariableDefinition varObj("Global_CFPS_FPSControl", "!83ec2c8b5d08c70424(???????\?)e8????????e8????????884305", &Global_CFPS_FPSControl);
}

namespace _func159
{
    static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(GL_Color )), "83ec2c8b442430f30f10442430", argdata, 1, 2, &func);
}

int CSurface::GL_SetColor(GL_Color color)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func159::func;
	return execfunc(color);
}

namespace _func160
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_GetColor", typeid(GL_Color (*)()), ".8b4424048b15????????8910", argdata, 1, 18, &func);
}

GL_Color CSurface::GL_GetColor()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func160::func;
	return execfunc();
}

namespace _func161
{
    static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(GL_Color )), "83ec1ca1????????3b05????????74??85c0", argdata, 1, 6, &func);
}

void CSurface::GL_SetColorTint(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func161::func;
	return execfunc(color);
}

namespace _func162
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::IsFrameBufferSupported", typeid(bool (*)()), "83ec0ce8????????85c0??????83c40c", argdata, 0, 2, &func);
}

bool CSurface::IsFrameBufferSupported()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func162::func;
	return execfunc();
}

namespace _func163
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::StartFrame", typeid(void (*)()), "83ec0ce8????????83c40c", argdata, 0, 6, &func);
}

void CSurface::StartFrame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func163::func;
	return execfunc();
}

namespace _func164
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::FinishFrame", typeid(void (*)()), "83ec1ca1????????89442404a1????????890424", argdata, 0, 6, &func);
}

void CSurface::FinishFrame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func164::func;
	return execfunc();
}

namespace _func165
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearAll", typeid(void (*)()), "0f57c083ec2cc744241400000000f30f1144240cf30f11442408f30f11442404", argdata, 0, 6, &func);
}

void CSurface::GL_ClearAll()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func165::func;
	return execfunc();
}

namespace _func166
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_ClearColor", typeid(void (*)()), "0f57c083ec1cf30f1144240cf30f11442408f30f11442404f30f110424", argdata, 0, 6, &func);
}

void CSurface::GL_ClearColor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func166::func;
	return execfunc();
}

namespace _func167
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::SetViewPort", typeid(int (*)(int , int , int , int )), "83ec1c8b44242c8944240c8b44242889442408", argdata, 4, 2, &func);
}

int CSurface::SetViewPort(int left, int bottom, int h, int w)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int left_arg, int bottom_arg, int h_arg, int w_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func167::func;
	return execfunc(left, bottom, h, w);
}

namespace _func168
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopScissor", typeid(void (*)()), "83ec1c8b0d????????8b15????????89c829d0c1f804", argdata, 0, 6, &func);
}

void CSurface::GL_PopScissor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func168::func;
	return execfunc();
}

namespace _func169
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(void (*)(GL_StencilMode , int , int )), "565383ec148b4424208b5c24248b74242883f801", argdata, 3, 6, &func);
}

void CSurface::GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_StencilMode stencilMode_arg, int ref_arg, int mask_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func169::func;
	return execfunc(stencilMode, ref, mask);
}

namespace _func170
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopStencilMode", typeid(void (*)()), "8b15????????8b0d????????89d029c8c1f80269c0abaaaaaa85c0", argdata, 0, 6, &func);
}

void CSurface::GL_PopStencilMode()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func170::func;
	return execfunc();
}

namespace _func171
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), "83ec5ca1????????f30f10742464f30f1005????????f30f10542474", argdata, 6, 2, &func);
}

int CSurface::GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(float mx1_arg, float mx2_arg, float mx3_arg, float mx4_arg, float mx5_arg, float mx6_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func171::func;
	return execfunc(mx1, mx2, mx3, mx4, mx5, mx6);
}

namespace _func172
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_LoadIdentity", typeid(int (*)()), "83ec1c0f57d20f57c90f57c0", argdata, 0, 2, &func);
}

int CSurface::GL_LoadIdentity()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func172::func;
	return execfunc();
}

namespace _func173
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), "8b15????????83fa0f76??83ec1cc70424????????", argdata, 0, 2, &func);
}

int CSurface::GL_PushMatrix()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func173::func;
	return execfunc();
}

namespace _func174
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PopMatrix", typeid(int (*)()), "83ec2ca1????????85c00f84????????83e801", argdata, 0, 2, &func);
}

int CSurface::GL_PopMatrix()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func174::func;
	return execfunc();
}

namespace _func175
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate2", typeid(void (*)(float , float , float , float )), "81ec0c0100000f57c9f30f10842410010000f30f10942414010000f30f109c2418010000", argdata, 4, 6, &func);
}

void CSurface::GL_Rotate2(float angle, float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float angle_arg, float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func175::func;
	return execfunc(angle, x, y, z);
}

namespace _func176
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), "81ec0c0100000f57c9f30f10842410010000f30f10942414010000f30f109c2418010000", argdata, 4, 6, &func);
}

void CSurface::GL_Rotate(float angle, float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float angle_arg, float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func176::func;
	return execfunc(angle, x, y, z);
}

namespace _func177
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(void (*)(float , float , float )), "f30f104c2404b800000000f30f1005????????f30f10542408f30f105c240c", argdata, 3, 6, &func);
}

void CSurface::GL_Scale(float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func177::func;
	return execfunc(x, y, z);
}

namespace _func178
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(bool (*)(float , float , float )), "83ec100f57c0f30f104c2414b800000000f30f10542418f30f1074241c", argdata, 3, 2, &func);
}

bool CSurface::GL_Translate(float x, float y, float z)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func178::func;
	return execfunc(x, y, z);
}

namespace _func179
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), "a1????????3b05????????74??83e810a3????????", argdata, 0, 6, &func);
}

void CSurface::GL_RemoveColorTint()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func179::func;
	return execfunc();
}

namespace _func180
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color (*)()), "8b0d????????8b15????????8b442404", argdata, 1, 18, &func);
}

GL_Color CSurface::GetColorTint()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func180::func;
	return execfunc();
}

namespace _func181
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(bool (*)()), "83ec1cc744240804000000c744240403000000", argdata, 0, 2, &func);
}

bool CSurface::GL_EnableBlend()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func181::func;
	return execfunc();
}

namespace _func182
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_DisableBlend", typeid(bool (*)()), "83ec1cc744240800000000c744240401000000c7042401000000e8????????83c41c", argdata, 0, 2, &func);
}

bool CSurface::GL_DisableBlend()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func182::func;
	return execfunc();
}

namespace _func183
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_ForceAntialias", typeid(void (*)(bool )), "8b442404a2????????", argdata, 1, 6, &func);
}

void CSurface::GL_ForceAntialias(bool on)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(bool on_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func183::func;
	return execfunc(on);
}

namespace _func184
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLine", typeid(bool (*)(float , float , float , float , float , GL_Color )), "81ecbc0000008b15????????a1????????f30f109c24d4000000f30f109424d8000000f30f108c24dc000000", argdata, 6, 2, &func);
}

bool CSurface::GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, float lineWidth_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func184::func;
	return execfunc(x1, y1, x2, y2, lineWidth, color);
}

namespace _func185
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x2ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawTriangle", typeid(bool (*)(Point , Point , Point , GL_Color )), "5557565381ec8c0000008b15????????8b8424b00000008bbc24a00000008bac24a40000008b9c24a8000000", argdata, 4, 2, &func);
}

bool CSurface::GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Point vertex1_arg, Point vertex2_arg, Point vertex3_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func185::func;
	return execfunc(vertex1, vertex2, vertex3, color);
}

namespace _func186
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , GL_Color )), "81ec9c0000008b15????????a1????????f30f108424a0000000f30f108c24a4000000", argdata, 5, 2, &func);
}

bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func186::func;
	return execfunc(x1, y1, x2, y2, color);
}

namespace _func187
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(int , int , int , int , GL_Color , float )), "5381ecc8010000f30f10a424e80100008b9424d80100008b9c24d0010000", argdata, 6, 2, &func);
}

bool CSurface::GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x1_arg, int y1_arg, int x2_arg, int y2_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func187::func;
	return execfunc(x1, y1, x2, y2, color, lineWidth);
}

namespace _func188
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), "565381ecb40000008b9424d8000000f30f109c24d8000000f30f10a424dc000000", argdata, 8, 2, &func);
}

bool CSurface::GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float x2_arg, float y2_arg, float rotation_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func188::func;
	return execfunc(tex, x, y, x2, y2, rotation, color, mirror);
}

namespace _func189
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImage", typeid(bool (*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), "57565381ecb00000000fb63d????????8b9424d8000000f30f109c24d8000000f30f10a424dc000000", argdata, 8, 2, &func);
}

bool CSurface::GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float x2_arg, float y2_arg, float rotation_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func189::func;
	return execfunc(tex, x, y, x2, y2, rotation, color, mirror);
}

namespace _func190
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), "57565383ec6080bc24a8000000008b5c2470", argdata, 12, 2, &func);
}

bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float start_x_arg, float end_x_arg, float start_y_arg, float end_y_arg, float alpha_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func190::func;
	return execfunc(tex, x, y, size_x, size_y, start_x, end_x, start_y, end_y, alpha, color, mirror);
}

namespace _func191
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitPixelImageWide", typeid(bool (*)(GL_Texture *, float , float , int , int , float , GL_Color , bool )), "5557565381ec8c0000008bbc24a00000008b9c24ac000000", argdata, 8, 2, &func);
}

bool CSurface::GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, int x2_arg, int y2_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func191::func;
	return execfunc(tex, x, y, x2, y2, opacity, color, mirror);
}

namespace _func192
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiImage", typeid(void (*)(GL_Texture *, const std::vector<GL_TexVertex> &, bool )), "5557565383ec4c8b15????????8b4424688b5c24608b7c246489442418", argdata, 3, 6, &func);
}

void CSurface::GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_TexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func192::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func193
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiColorImage", typeid(void (*)(GL_Texture *, const std::vector<GL_ColorTexVertex> &, bool )), "5557565383ec4c8b15????????8b4424688b5c24608b7c246489442420a1????????", argdata, 3, 6, &func);
}

void CSurface::GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_ColorTexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func193::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func194
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitive", typeid(void (*)(GL_Primitive *)), "5383ec288b5c243085db0f84????????8b15????????a1????????39c20f84????????29c283e2f08d4410f0f30f10400c", argdata, 1, 6, &func);
}

void CSurface::GL_RenderPrimitive(GL_Primitive *primitive)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func194::func;
	return execfunc(primitive);
}

namespace _func195
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithAlpha", typeid(void (*)(GL_Primitive *, float )), "5383ec288b5c243085db0f84????????8b15????????a1????????39c20f84????????29c283e2f08d4410f0f30f10500c", argdata, 2, 6, &func);
}

void CSurface::GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func195::func;
	return execfunc(primitive, alpha);
}

namespace _func196
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_RenderPrimitiveWithColor", typeid(void (*)(GL_Primitive *, GL_Color )), "5383ec288b5c2430f30f104c2434f30f106c2438f30f105c243c85dbf30f10542440", argdata, 2, 6, &func);
}

void CSurface::GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func196::func;
	return execfunc(primitive, color);
}

namespace _func197
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), "5383ec188b5c242085db74??8b4324890424", argdata, 1, 6, &func);
}

void CSurface::GL_DestroyPrimitive(GL_Primitive *primitive)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func197::func;
	return execfunc(primitive);
}

namespace _func198
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , GL_Color )), "5383ec58f30f10442460f30f104c2464f30f10542468f30f10642478", argdata, 5, 2, &func);
}

GL_Primitive *CSurface::GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float w_arg, float h_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func198::func;
	return execfunc(x, y, w, h, color);
}

namespace _func199
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectOutlinePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , GL_Color , float )), "5381ecb8000000f30f2a9424c0000000", argdata, 6, 2, &func);
}

GL_Primitive *CSurface::GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int w_arg, int h_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func199::func;
	return execfunc(x, y, w, h, color, lineWidth);
}

namespace _func200
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiRectPrimitive", typeid(GL_Primitive *(*)(std::vector<Globals::Rect> &, GL_Color )), "55b8ffffffff57565383ec4c8b7c24608b77042b37", argdata, 2, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<Globals::Rect> &vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func200::func;
	return execfunc(vec, color);
}

namespace _func201
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiLinePrimitive", typeid(GL_Primitive *(*)(std::vector<GL_Line> &, GL_Color , float )), "5557565383ec4c8b6c2460f30f105424748b7d04", argdata, 3, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<GL_Line> &vec_arg, GL_Color color_arg, float thickness_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func201::func;
	return execfunc(vec, color, thickness);
}

namespace _func202
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreatePiePartialPrimitive", typeid(GL_Primitive *(*)(int , int , float , float , float , float , GL_Color )), ".5557565381ec8c020000", argdata, 7, 2, &func);
}

GL_Primitive *CSurface::GL_CreatePiePartialPrimitive(int x, int y, float radius, float deg1, float deg2, float thickness, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, float radius_arg, float deg1_arg, float deg2_arg, float thickness_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func202::func;
	return execfunc(x, y, radius, deg1, deg2, thickness, color);
}

namespace _func203
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, std::vector<GL_TexVertex> *, GL_Color )), "5557565383ec4c8b7424648b5c24608b46048b2e", argdata, 3, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, std::vector<GL_TexVertex> *vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func203::func;
	return execfunc(tex, vec, color);
}

namespace _func204
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushStencilMode", typeid(void (*)()), "a1????????3b05????????74??85c074??8b15????????", argdata, 0, 6, &func);
}

void CSurface::GL_PushStencilMode()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func204::func;
	return execfunc();
}

namespace _func205
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(void (*)(std::vector<GL_TexVertex> *, float , float , float , float , float , float , float , float )), "565383ec248b742430f30f10442434f30f104c2438f30f105c2444", argdata, 9, 6, &func);
}

void CSurface::AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<GL_TexVertex> *vec_arg, float x1_arg, float y1_arg, float u1_arg, float v1_arg, float x2_arg, float y2_arg, float u2_arg, float v2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func205::func;
	return execfunc(vec, x1, y1, u1, v1, x2, y2, u2, v2);
}

namespace _func206
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawCircle", typeid(bool (*)(int , int , float , GL_Color )), ".5557565383ec6c", argdata, 4, 2, &func);
}

bool CSurface::GL_DrawCircle(int x, int y, float radius, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, float radius_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func206::func;
	return execfunc(x, y, radius, color);
}

namespace _func207
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawShield", typeid(bool (*)(int , int , float , float , int , int , GL_Color , float )), ".5557565383ec7c8b15????????f30f10b42498000000", argdata, 8, 2, &func);
}

bool CSurface::GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, float a1_arg, float b1_arg, int angle1_arg, int angle2_arg, GL_Color color_arg, float thickness_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func207::func;
	return execfunc(x, y, a1, b1, angle1, angle2, color, thickness);
}

namespace _func208
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawLaser", typeid(bool (*)(int , int , int , int , GL_Color )), ".5557565383ec5c", argdata, 5, 2, &func);
}

bool CSurface::GL_DrawLaser(int x, int y, int w, int h, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int w_arg, int h_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func208::func;
	return execfunc(x, y, w, h, color);
}

namespace _func209
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color )), "565383ec54f30f10442478", argdata, 7, 2, &func);
}

GL_Primitive *CSurface::GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float rotate_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func209::func;
	return execfunc(tex, x, y, size_x, size_y, rotate, color);
}

namespace _func210
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreatePixelImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , GL_Color , bool )), "565383ec54f30f104c2478", argdata, 8, 2, &func);
}

GL_Primitive *CSurface::GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool unk)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float rotate_arg, GL_Color color_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func210::func;
	return execfunc(tex, x, y, size_x, size_y, rotate, color, unk);
}

namespace _func211
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CachedImage::destructor", typeid(void (CachedImage::*)()), "565383ec248b5c24308b4308c703????????8d50f481fa????????750e", argdata, 1, 6, &func);
}

void CachedImage::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func211::func;
	return execfunc(this);
}

namespace _func212
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), "565383ec148b4424248b5c2420c70424????????89442404", argdata, 2, 6, &func);
}

void CachedImage::SetImagePath(const std::string &imagePath)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &imagePath_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func212::func;
	return execfunc(this, imagePath);
}

namespace _func213
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetPosition", typeid(void (CachedImage::*)(int , int )), ".57565383ec108b5c24208b7424248b7c2428397310", argdata, 3, 6, &func);
}

void CachedImage::SetPosition(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func213::func;
	return execfunc(this, x, y);
}

namespace _func214
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor1", typeid(void (CachedImage::*)(const std::string &, int , int )), "5383ec188b5c24208b442424c7430400000000c703????????89442404", argdata, 4, 6, &func);
}

void CachedImage::constructor1(const std::string &path, int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &path_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func214::func;
	return execfunc(this, path, x, y);
}

namespace _func215
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor2", typeid(void (CachedImage::*)(const std::string &, CachedImage::Centered )), "5383ec??8b5c????8b44????c7430400000000c703????????c74308????????8944????", argdata, 3, 6, &func);
}

void CachedImage::constructor2(const std::string &path, CachedImage::Centered centered)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &path_arg, CachedImage::Centered centered_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func215::func;
	return execfunc(this, path, centered);
}

namespace _func216
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor_copy", typeid(void (CachedImage::*)(const CachedImage &)), "565383ec148b7424248b5c24208d4608", argdata, 2, 6, &func);
}

void CachedImage::constructor_copy(const CachedImage &other)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const CachedImage &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func216::func;
	return execfunc(this, other);
}

namespace _func217
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetRotation", typeid(void (CachedImage::*)(float )), "5383ec188b5c2420f30f104424240f2e4330", argdata, 2, 6, &func);
}

void CachedImage::SetRotation(float _rotation)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float _rotation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func217::func;
	return execfunc(this, _rotation);
}

namespace _func218
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetMirrored", typeid(void (CachedImage::*)(bool )), "565383ec148b5c24208b74242489f0", argdata, 2, 6, &func);
}

void CachedImage::SetMirrored(bool _mirrored)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, bool _mirrored_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func218::func;
	return execfunc(this, _mirrored);
}

namespace _func219
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetScale", typeid(void (CachedImage::*)(float , float )), "5383ec188b5c2420f30f104424240f2e4318", argdata, 3, 6, &func);
}

void CachedImage::SetScale(float wScale, float hScale)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float wScale_arg, float hScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func219::func;
	return execfunc(this, wScale, hScale);
}

namespace _func220
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetPartial", typeid(void (CachedImage::*)(float , float , float , float )), ".554889e5534883ec??4889fb0f2e", argdata, 5, 6, &func);
}

void CachedImage::SetPartial(float x_start, float y_start, float x_size, float y_size)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float x_start_arg, float y_start_arg, float x_size_arg, float y_size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func220::func;
	return execfunc(this, x_start, y_start, x_size, y_size);
}

namespace _func221
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CachedImage::CreatePrimitive", typeid(void (CachedImage::*)()), "565383ec748b9c24800000008b430c", argdata, 1, 6, &func);
}

void CachedImage::CreatePrimitive()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedImage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func221::func;
	return execfunc(this);
}

namespace _func222
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedPrimitive::OnRender", typeid(void (CachedPrimitive::*)(const GL_Color &)), "565383ec448b7424508b5c24548b460485c0", argdata, 2, 6, &func);
}

void CachedPrimitive::OnRender(const GL_Color &color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedPrimitive *this_arg, const GL_Color &color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func222::func;
	return execfunc(this, color);
}

namespace _func223
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CachedPrimitive::destructor", typeid(void (CachedPrimitive::*)()), "8b442404c700????????8b4004", argdata, 1, 6, &func);
}

void CachedPrimitive::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedPrimitive *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func223::func;
	return execfunc(this);
}

namespace _func224
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedRect::SetPosition", typeid(void (CachedRect::*)(int , int )), "57565383ec108b5c24208b7424248b7c2428397308", argdata, 3, 6, &func);
}

void CachedRect::SetPosition(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedRect *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func224::func;
	return execfunc(this, x, y);
}

namespace _func225
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedRect::SetSize", typeid(void (CachedRect::*)(int , int )), ".57565383ec108b5c24208b7424248b7c2428397310", argdata, 3, 6, &func);
}

void CachedRect::SetSize(int w, int h)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CachedRect *this_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func225::func;
	return execfunc(this, w, h);
}

namespace _func226
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "5589e557565381ecdc0100008b7508", argdata, 1, 6, &func);
}

void ChoiceBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func226::func;
	return execfunc(this);
}

namespace _func227
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::MouseMove", typeid(void (ChoiceBox::*)(int , int )), "5557565383ec1c8b442430c70424????????", argdata, 3, 6, &func);
}

void ChoiceBox::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func227::func;
	return execfunc(this, x, y);
}

namespace _func228
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::MouseClick", typeid(void (ChoiceBox::*)(int , int )), "833d????????02538b4424088b54240c8b4c2410", argdata, 3, 6, &func);
}

void ChoiceBox::MouseClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func228::func;
	return execfunc(this, mX, mY);
}

namespace _func229
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::PrintResourceBox", typeid(ResourceBoxDesc (ChoiceBox::*)(ResourceEvent *, int , int , GL_Color , bool )), "5589e557565381ec5c0100008b", argdata, 7, 18, &func);
}

ResourceBoxDesc ChoiceBox::PrintResourceBox(ResourceEvent *resources, int x, int y, GL_Color border, bool choice)
{
	typedef ResourceBoxDesc __attribute__((cdecl)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, ResourceEvent *resources_arg, int x_arg, int y_arg, GL_Color border_arg, bool choice_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func229::func;
	return execfunc(this, resources, x, y, border, choice);
}

namespace _func230
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CloakingBox::constructor", typeid(void (CloakingBox::*)(Point , CloakingSystem *)), "5557565383ec6c8bbc2480000000", argdata, 3, 6, &func);
}

void CloakingBox::constructor(Point pos, CloakingSystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloakingBox *this_arg, Point pos_arg, CloakingSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func230::func;
	return execfunc(this, pos, sys);
}

namespace _func231
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloakingSystem::OnLoop", typeid(void (CloakingSystem::*)()), "565383ec148b5c2420891c24e8????????????????????890424", argdata, 1, 6, &func);
}

void CloakingSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func231::func;
	return execfunc(this);
}

namespace _func232
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloakingSystem::FiredWeapon", typeid(void (CloakingSystem::*)()), "57565383ec208b5c24308d44241a8d74241c89442408c7442404????????893424e8????????8d4308", argdata, 1, 6, &func);
}

void CloakingSystem::FiredWeapon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func232::func;
	return execfunc(this);
}

namespace _func233
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CloneBox::constructor", typeid(void (CloneBox::*)(Point , CloneSystem *)), "5557565381ec4c0100008b8424640100008b9c246c0100008b942468010000", argdata, 3, 6, &func);
}

void CloneBox::constructor(Point pos, CloneSystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloneBox *this_arg, Point pos_arg, CloneSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func233::func;
	return execfunc(this, pos, sys);
}

namespace _func234
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::OnRenderFloor", typeid(void (CloneSystem::*)()), "5589e557565383ec6c8b????83bbb4010000ff", argdata, 1, 6, &func);
}

void CloneSystem::OnRenderFloor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func234::func;
	return execfunc(this);
}

namespace _func235
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::GetCloneTime", typeid(int (*)(int )), ".8b44??f30f2c04??????????", argdata, 1, 2, &func);
}

int CloneSystem::GetCloneTime(int level)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func235::func;
	return execfunc(level);
}

namespace _func236
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::GetJumpHealth", typeid(int (*)(int )), ".8b442404", argdata, 1, 2, &func);
}

int CloneSystem::GetJumpHealth(int level)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func236::func;
	return execfunc(level);
}

namespace _func237
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::GetDeathProgress", typeid(float (CloneSystem::*)()), ".83ec040f57c98b44????", argdata, 1, 2, &func);
}

float CloneSystem::GetDeathProgress()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func237::func;
	return execfunc(this);
}

namespace _func238
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::GetProgress", typeid(float (CloneSystem::*)()), ".5383ec188b5c????891c??e8????????0f57c085c0", argdata, 1, 2, &func);
}

float CloneSystem::GetProgress()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func238::func;
	return execfunc(this);
}

namespace _func239
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::CloneReady", typeid(CrewMember *(CloneSystem::*)()), ".5383ec188b44????8b989c010000", argdata, 1, 2, &func);
}

CrewMember *CloneSystem::CloneReady()
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func239::func;
	return execfunc(this);
}

namespace _func240
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CloneSystem::OnLoop", typeid(void (CloneSystem::*)()), ".5589e557565381ec4c0100008b4508890424", argdata, 1, 6, &func);
}

void CloneSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func240::func;
	return execfunc(this);
}

namespace _func241
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatAI::UpdateMindControl", typeid(void (CombatAI::*)(bool )), "5589e557565383ec4c8b45088b550c", argdata, 2, 6, &func);
}

void CombatAI::UpdateMindControl(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatAI *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func241::func;
	return execfunc(this, unk);
}

namespace _func242
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatAI::PrioritizeSystem", typeid(int (CombatAI::*)(int )), ".5589e557565383ec4ca1????????8b????83f802", argdata, 2, 2, &func);
}

int CombatAI::PrioritizeSystem(int weaponType)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatAI *this_arg, int weaponType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func242::func;
	return execfunc(this, weaponType);
}

namespace _func243
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatAI::UpdateWeapons", typeid(void (CombatAI::*)()), ".5589e557565383ec5c8b????807b2c008b4330", argdata, 1, 6, &func);
}

void CombatAI::UpdateWeapons()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func243::func;
	return execfunc(this);
}

namespace _func244
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatAI::OnLoop", typeid(void (CombatAI::*)()), ".57565383ec108b742420893424e8????????8b4630", argdata, 1, 6, &func);
}

void CombatAI::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func244::func;
	return execfunc(this);
}

namespace _func245
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::RenderTarget", typeid(void (CombatControl::*)()), "5589e557565381ecac0100008b7d08", argdata, 1, 6, &func);
}

void CombatControl::RenderTarget()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func245::func;
	return execfunc(this);
}

namespace _func246
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::GetCurrentTarget", typeid(ShipManager *(CombatControl::*)()), "8b4424048b80b805000085c074??8b4008c38db60000000031c0", argdata, 1, 2, &func);
}

ShipManager *CombatControl::GetCurrentTarget()
{
	typedef ShipManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func246::func;
	return execfunc(this);
}

namespace _func247
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::CurrentTargetIsBoss", typeid(char (CombatControl::*)()), "8b4424048b80b805000085c074??8b10", argdata, 1, 2, &func);
}

char CombatControl::CurrentTargetIsBoss()
{
	typedef char __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func247::func;
	return execfunc(this);
}

namespace _func248
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(char (CombatControl::*)()), "5589e557565383ec4c8b75088b86a4000000", argdata, 1, 2, &func);
}

char CombatControl::CanTargetSelf()
{
	typedef char __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func248::func;
	return execfunc(this);
}

namespace _func249
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::OnRenderCombat", typeid(void (CombatControl::*)()), "5589e5565383ec208b5d0880bb240b000000", argdata, 1, 6, &func);
}

void CombatControl::OnRenderCombat()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func249::func;
	return execfunc(this);
}

namespace _func250
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::AddEnemyShip", typeid(void (CombatControl::*)(CompleteShip *)), "5557565383ec3c8b5c24508b83b8050000", argdata, 2, 6, &func);
}

void CombatControl::AddEnemyShip(CompleteShip *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func250::func;
	return execfunc(this, ship);
}

namespace _func251
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::UpdateAiming", typeid(void (CombatControl::*)()), "5589e557565383ec4c8b5d0883bbcc050000ff", argdata, 1, 6, &func);
}

void CombatControl::UpdateAiming()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func251::func;
	return execfunc(this);
}

namespace _func252
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::UpdateTarget", typeid(bool (CombatControl::*)()), "5589e557565383ec7c8b7d08f30f2a4f08", argdata, 1, 2, &func);
}

bool CombatControl::UpdateTarget()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func252::func;
	return execfunc(this);
}

namespace _func253
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::DrawHostileBox", typeid(void (CombatControl::*)(GL_Color , int )), "5557565383ec6c8bb424800000008d7c2448", argdata, 3, 6, &func);
}

void CombatControl::DrawHostileBox(GL_Color color, int stencilBit)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, GL_Color color_arg, int stencilBit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func253::func;
	return execfunc(this, color, stencilBit);
}

namespace _func254
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("CombatControl::OnInit", typeid(void (CombatControl::*)(Point )), "565383ec348b5c24408b4424448b542448", argdata, 2, 6, &func);
}

void CombatControl::OnInit(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func254::func;
	return execfunc(this, pos);
}

namespace _func255
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::OnLoop", typeid(void (CombatControl::*)()), "55575631f65383ec2c8b5c24408b93a0050000", argdata, 1, 6, &func);
}

void CombatControl::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func255::func;
	return execfunc(this);
}

namespace _func256
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::SetMouseCursor", typeid(void (CombatControl::*)()), "5383ec188b5c24208b83a400000085c0", argdata, 1, 6, &func);
}

void CombatControl::SetMouseCursor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func256::func;
	return execfunc(this);
}

namespace _func257
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::GetTeleportationCommand", typeid(std::pair<int, int> (CombatControl::*)()), "5557565383ec1c8b7424348b5c24308b86b8050000", argdata, 2, 18, &func);
}

std::pair<int, int> CombatControl::GetTeleportationCommand()
{
	typedef std::pair<int, int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func257::func;
	return execfunc(this);
}

namespace _func258
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::DisarmAll", typeid(void (CombatControl::*)()), "5383ec188b5c24208b93b805000085d2", argdata, 1, 6, &func);
}

void CombatControl::DisarmAll()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func258::func;
	return execfunc(this);
}

namespace _func259
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::SelectTarget", typeid(bool (CombatControl::*)()), "5589e557565383ec5c8b5d08c744240409000000", argdata, 1, 2, &func);
}

bool CombatControl::SelectTarget()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func259::func;
	return execfunc(this);
}

namespace _func260
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseRClick", typeid(bool (CombatControl::*)(int , int )), "5557565383ec1c8b5c24308b7424348b7c24388b83a4000000", argdata, 3, 2, &func);
}

bool CombatControl::MouseRClick(int x, int y)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func260::func;
	return execfunc(this, x, y);
}

namespace _func261
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::WeaponsArmed", typeid(bool (CombatControl::*)()), "5383ec188b5c2420c7442404090000008b4304890424e8????????84c075??8b83a4000000", argdata, 1, 2, &func);
}

bool CombatControl::WeaponsArmed()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func261::func;
	return execfunc(this);
}

namespace _func262
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::KeyDown", typeid(void (CombatControl::*)(SDLKey )), "565383ec148b5c24208b7424248d4314", argdata, 2, 6, &func);
}

void CombatControl::KeyDown(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func262::func;
	return execfunc(this, key);
}

namespace _func263
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::DisarmTeleporter", typeid(void (CombatControl::*)()), "5631f65383ec148b5c2420c744240409000000", argdata, 1, 6, &func);
}

void CombatControl::DisarmTeleporter()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func263::func;
	return execfunc(this);
}

namespace _func264
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::constructor", typeid(void (CombatControl::*)()), "5557565381ecbc0000008bb424d0000000", argdata, 1, 6, &func);
}

void CombatControl::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func264::func;
	return execfunc(this);
}

namespace _func265
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::OnRenderSelfAiming", typeid(void (CombatControl::*)()), "5589e55383ec348b5d088d4314", argdata, 1, 6, &func);
}

void CombatControl::OnRenderSelfAiming()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func265::func;
	return execfunc(this);
}

namespace _func266
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x4ff};
	static FunctionDefinition funcObj("CombatControl::RenderShipStatus", typeid(void (CombatControl::*)(Pointf , GL_Color )), "5589e557565381ec9c0000008b5d0c8b75108b7d08", argdata, 3, 6, &func);
}

void CombatControl::RenderShipStatus(Pointf pos, GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, Pointf pos_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func266::func;
	return execfunc(this, pos, color);
}

namespace _func267
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::GetCrewTooltip", typeid(std::string (CombatControl::*)(int , int )), "5589e55383ec248b550c8b5d08", argdata, 4, 18, &func);
}

std::string CombatControl::GetCrewTooltip(int x, int y)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func267::func;
	return execfunc(this, x, y);
}

namespace _func268
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatControl::Clear", typeid(void (CombatControl::*)()), "565383ec148b7424208b4604", argdata, 1, 6, &func);
}

void CombatControl::Clear()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func268::func;
	return execfunc(this);
}

namespace _func269
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseMove", typeid(bool (CombatControl::*)(int , int )), "5557565383ec1c8b7c24348b6c24308b742438f30f2ac7", argdata, 3, 2, &func);
}

bool CombatControl::MouseMove(int mX, int mY)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func269::func;
	return execfunc(this, mX, mY);
}

namespace _func270
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseClick", typeid(void (CombatControl::*)(int , int , bool )), "57565383ec108b5c24208b7424248b7c24288d4314c683480b000001", argdata, 4, 6, &func);
}

void CombatControl::MouseClick(int mX, int mY, bool shift)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func270::func;
	return execfunc(this, mX, mY, shift);
}

namespace _func271
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatDrone::constructor", typeid(void (CombatDrone::*)(int , int , const DroneBlueprint *)), "5557565383ec3c8b4424588d5c242c8b7424508b7c245c", argdata, 4, 6, &func);
}

void CombatDrone::constructor(int iShipId, int selfId, const DroneBlueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatDrone *this_arg, int iShipId_arg, int selfId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func271::func;
	return execfunc(this, iShipId, selfId, bp);
}

namespace _func272
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatDrone::SetWeaponTarget", typeid(void (CombatDrone::*)(Targetable *)), "565383ec148b7424248b5c242085f674??8b0389742404", argdata, 2, 6, &func);
}

void CombatDrone::SetWeaponTarget(Targetable *target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func272::func;
	return execfunc(this, target);
}

namespace _func273
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CombatDrone::PickTarget", typeid(void (CombatDrone::*)()), "5589e55383ec248b5d088b03", argdata, 1, 6, &func);
}

void CombatDrone::PickTarget()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CombatDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func273::func;
	return execfunc(this);
}

namespace _func274
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(void (CommandGui::*)(std::string &)), "5589e557565331db81ec8c0000008b750c", argdata, 2, 6, &func);
}

void CommandGui::RunCommand(std::string &command)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, std::string &command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func274::func;
	return execfunc(this, command);
}

namespace _func275
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::CreateNewStore", typeid(Store *(CommandGui::*)(int )), "5557565383ec2cc70424a40400008b5c2440", argdata, 2, 2, &func);
}

Store *CommandGui::CreateNewStore(int sectorNumber)
{
	typedef Store *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int sectorNumber_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func275::func;
	return execfunc(this, sectorNumber);
}

namespace _func276
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::Restart", typeid(void (CommandGui::*)()), ".5557565383ec1c8b5c24308db3", argdata, 1, 6, &func);
}

void CommandGui::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func276::func;
	return execfunc(this);
}

namespace _func277
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::GetWorldCoordinates", typeid(Point (CommandGui::*)(Point , bool )), "5589e557565383ec3c8b5d188d55d8", argdata, 4, 18, &func);
}

Point CommandGui::GetWorldCoordinates(Point point, bool fromTarget)
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, Point point_arg, bool fromTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func277::func;
	return execfunc(this, point, fromTarget);
}

namespace _func278
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::KeyDown", typeid(void (CommandGui::*)(SDLKey , bool )), "5589e557565383ec4c8b5d088b4510", argdata, 3, 6, &func);
}

void CommandGui::KeyDown(SDLKey key, bool shiftHeld)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, SDLKey key_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func278::func;
	return execfunc(this, key, shiftHeld);
}

namespace _func279
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(void (CommandGui::*)()), "5589e557565383ec7c8b5d08803d????????00", argdata, 1, 6, &func);
}

void CommandGui::RenderStatic()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func279::func;
	return execfunc(this);
}

namespace _func280
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::constructor", typeid(void (CommandGui::*)()), "5557565381ec8c0000008b9c24a00000008d742470", argdata, 1, 6, &func);
}

void CommandGui::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func280::func;
	return execfunc(this);
}

namespace _func281
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::AddEnemyShip", typeid(void (CommandGui::*)(CompleteShip *)), "5557565383ec3c8b5c24508d7c24208b7424548d83ac030000", argdata, 2, 6, &func);
}

void CommandGui::AddEnemyShip(CompleteShip *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func281::func;
	return execfunc(this, ship);
}

namespace _func282
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LinkShip", typeid(void (CommandGui::*)(CompleteShip *)), ".5557565381ec0c0100008b9c24200100008d", argdata, 2, 6, &func);
}

void CommandGui::LinkShip(CompleteShip *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func282::func;
	return execfunc(this, ship);
}

namespace _func283
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::Victory", typeid(void (CommandGui::*)()), "5589e557565383ec6c8b45088b80b4120000", argdata, 1, 6, &func);
}

void CommandGui::Victory()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func283::func;
	return execfunc(this);
}

namespace _func284
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::OnInit", typeid(void (CommandGui::*)()), "5557565381ecbc0000008b8424d00000008d7424688d7c244c", argdata, 1, 6, &func);
}

void CommandGui::OnInit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func284::func;
	return execfunc(this);
}

namespace _func285
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::MouseMove", typeid(void (CommandGui::*)(int , int )), "5589e557565383ec6c8b5d088b750c8b4510", argdata, 3, 6, &func);
}

void CommandGui::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func285::func;
	return execfunc(this, mX, mY);
}

namespace _func286
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LButtonDown", typeid(void (CommandGui::*)(int , int , bool )), "5589e557565383ec3c8b5d088b7514", argdata, 4, 6, &func);
}

void CommandGui::LButtonDown(int mX, int mY, bool shiftHeld)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func286::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func287
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::OnLoop", typeid(void (CommandGui::*)()), "5589e557565383ec5c8b5d08????????????000f85????????????????????85ff", argdata, 1, 6, &func);
}

void CommandGui::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func287::func;
	return execfunc(this);
}

namespace _func288
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::CheckGameover", typeid(void (CommandGui::*)()), "5589e557565383ec5c8b7d08????????????0075??", argdata, 1, 6, &func);
}

void CommandGui::CheckGameover()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func288::func;
	return execfunc(this);
}

namespace _func289
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CommandGui::IsGameOver", typeid(bool (CommandGui::*)()), "5383ec18803d????????008b5c242075??????????????85c0", argdata, 1, 2, &func);
}

bool CommandGui::IsGameOver()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func289::func;
	return execfunc(this);
}

namespace _func290
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::NewLocation", typeid(void (CommandGui::*)(const std::string &, std::vector<ChoiceText> *, ResourceEvent &, bool )), "5557565381ec7c0100008bbc24980100008b8424a0010000", argdata, 5, 6, &func);
}

void CommandGui::NewLocation(const std::string &mainText, std::vector<ChoiceText> *choices, ResourceEvent &resources, bool testingEvents)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, const std::string &mainText_arg, std::vector<ChoiceText> *choices_arg, ResourceEvent &resources_arg, bool testingEvents_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func290::func;
	return execfunc(this, mainText, choices, resources, testingEvents);
}

namespace _func291
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RenderPlayerShip", typeid(void (CommandGui::*)(Point &, float )), "565383ec248b7424348d4424108904248b5c2430", argdata, 3, 6, &func);
}

void CommandGui::RenderPlayerShip(Point &shipCenter, float jumpScale)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, Point &shipCenter_arg, float jumpScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func291::func;
	return execfunc(this, shipCenter, jumpScale);
}

namespace _func292
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::LButtonUp", typeid(void (CommandGui::*)(int , int , bool )), ".5557565383ec2c8b7424408b44244c8b7c24448b6c2448", argdata, 4, 6, &func);
}

void CommandGui::LButtonUp(int mX, int mY, bool shiftHeld)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func292::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func293
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CompleteShip::DO_NOT_HOOK", typeid(void (CompleteShip::*)()), "!8b48fc8d59ff8958fc89c8e9????????8b48fc8d59ff8958fc89c8eb??6690", argdata, 0, 4, &func);
}

namespace _func294
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CompleteShip::DO_NOT_HOOK2", typeid(void (CompleteShip::*)()), "!.8b48fc8d59ff8958fc89c8e9????????8b48fc8d59ff8958fc89c8eb??6690", argdata, 0, 4, &func);
}

namespace _func295
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::PauseLoop", typeid(void (CompleteShip::*)()), "!.8b4424048b400889442404e9????????", argdata, 1, 6, &func);
}

void CompleteShip::PauseLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func295::func;
	return execfunc(this);
}

namespace _func296
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::Restart", typeid(void (CompleteShip::*)()), "5383ec188b5c24208b430883c318890424", argdata, 1, 6, &func);
}

void CompleteShip::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func296::func;
	return execfunc(this);
}

namespace _func297
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(void (CompleteShip::*)(SpaceManager *, bool , int )), "5383ec188b5c24208b54242c8b442428", argdata, 4, 6, &func);
}

void CompleteShip::constructor(SpaceManager *space, bool unk, int unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, SpaceManager *space_arg, bool unk_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func297::func;
	return execfunc(this, space, unk, unk2);
}

namespace _func298
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(void (CompleteShip::*)(ShipManager *)), "83ec1c8b4424248b5424208b8850050000894208", argdata, 2, 6, &func);
}

void CompleteShip::SetShip(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func298::func;
	return execfunc(this, ship);
}

namespace _func299
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(void (CompleteShip::*)(const ShipBlueprint *, int )), "5557565383ec1cc7042440060000", argdata, 3, 6, &func);
}

void CompleteShip::OnInit(const ShipBlueprint *blueprint, int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const ShipBlueprint *blueprint_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func299::func;
	return execfunc(this, blueprint, unk);
}

namespace _func300
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , const std::string &, bool )), "5589e557565383ec6c8b4514c744240402000000", argdata, 4, 6, &func);
}

void CompleteShip::AddBoarders(int amount, const std::string &race, bool unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int amount_arg, const std::string &race_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func300::func;
	return execfunc(this, amount, race, unk2);
}

namespace _func301
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(CrewMember *(CompleteShip::*)(const CrewBlueprint *, bool )), "5589e557565381ecdc0000008b450c8b7d10", argdata, 3, 2, &func);
}

CrewMember *CompleteShip::AddCrewMember(const CrewBlueprint *blueprint, bool hostile)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const CrewBlueprint *blueprint_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func301::func;
	return execfunc(this, blueprint, hostile);
}

namespace _func302
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(const std::string &, const std::string &, bool )), "5589e557565383ec5c8b45148b5d10", argdata, 4, 2, &func);
}

CrewMember *CompleteShip::AddCrewMember1(const std::string &race, const std::string &name, bool hostile)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const std::string &race_arg, const std::string &name_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func302::func;
	return execfunc(this, race, name, hostile);
}

namespace _func303
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddDrone", typeid(Drone *(CompleteShip::*)(const DroneBlueprint *, int )), "!.8b4424048b400889442404e9????????", argdata, 3, 2, &func);
}

Drone *CompleteShip::AddDrone(const DroneBlueprint *blueprint, int unk)
{
	typedef Drone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const DroneBlueprint *blueprint_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func303::func;
	return execfunc(this, blueprint, unk);
}

namespace _func304
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember2", typeid(CrewMember *(CompleteShip::*)(CrewMember *, int )), "57565383ec108b5c24248b7424208b7c242885db", argdata, 3, 2, &func);
}

CrewMember *CompleteShip::AddCrewMember2(CrewMember *member, int unk)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, CrewMember *member_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func304::func;
	return execfunc(this, member, unk);
}

namespace _func305
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(void (CompleteShip::*)(int )), "!8b5424048b4424088b92300100008944240489542408e9????????", argdata, 2, 6, &func);
}

void CompleteShip::SaveState(int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func305::func;
	return execfunc(this, unk);
}

namespace _func306
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(void (CompleteShip::*)(int )), "5589e5565383ec208b450c8b5d088d75ec", argdata, 2, 6, &func);
}

void CompleteShip::LoadState(int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func306::func;
	return execfunc(this, unk);
}

namespace _func307
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(void (CompleteShip::*)(int , int )), "5589e557565383ec3c8b5d088b8318010000", argdata, 3, 6, &func);
}

void CompleteShip::InitiateTeleport(int targetRoom, int command)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int targetRoom_arg, int command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func307::func;
	return execfunc(this, targetRoom, command);
}

namespace _func308
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(void (CompleteShip::*)()), "5589e557565331db83ec3c8b45088b4008", argdata, 1, 6, &func);
}

void CompleteShip::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func308::func;
	return execfunc(this);
}

namespace _func309
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::GetTeleportingParty", typeid(std::vector<CrewMember*> (CompleteShip::*)()), "5557565383ec1c8b7424348b5c24308b8628010000", argdata, 2, 18, &func);
}

std::vector<CrewMember*> CompleteShip::GetTeleportingParty()
{
	typedef std::vector<CrewMember*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func309::func;
	return execfunc(this);
}

namespace _func310
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::KillRandomCrew", typeid(void (CompleteShip::*)()), "!.8b4424048b400889442404e9????????", argdata, 1, 6, &func);
}

void CompleteShip::KillRandomCrew()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func310::func;
	return execfunc(this);
}

namespace _func311
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::CountCrew", typeid(int (CompleteShip::*)(bool )), "!0fb6442408894424088b4424048b400889442404e9????????", argdata, 2, 2, &func);
}

int CompleteShip::CountCrew(bool boarders)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool boarders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func311::func;
	return execfunc(this, boarders);
}

namespace _func312
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(void (CompleteShip::*)()), "8b4424048b901801000089901c010000", argdata, 1, 6, &func);
}

void CompleteShip::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func312::func;
	return execfunc(this);
}

namespace _func313
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetEnemyShip", typeid(void (CompleteShip::*)(CompleteShip *)), "!8b4424088b54240485c0894210", argdata, 2, 6, &func);
}

void CompleteShip::SetEnemyShip(CompleteShip *other)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, CompleteShip *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func313::func;
	return execfunc(this, other);
}

namespace _func314
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), "565383ec148b5c24200fb64314", argdata, 1, 2, &func);
}

bool CompleteShip::DeadCrew()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func314::func;
	return execfunc(this);
}

namespace _func315
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::TeleportCrew", typeid(std::vector<CrewMember*> (CompleteShip::*)(int , bool )), "5589e55383ec140fb645148b5d08", argdata, 4, 18, &func);
}

std::vector<CrewMember*> CompleteShip::TeleportCrew(int roomId, bool intruders)
{
	typedef std::vector<CrewMember*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int roomId_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func315::func;
	return execfunc(this, roomId, intruders);
}

namespace _func316
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRender", typeid(void (CompleteShip::*)()), "5383ec188b5c2420c7442408020000008b4304", argdata, 1, 6, &func);
}

void CompleteShip::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func316::func;
	return execfunc(this);
}

namespace _func317
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRenderSpace", typeid(void (CompleteShip::*)()), "83ec1c8b442420c74424080000803fc744240403000000", argdata, 1, 6, &func);
}

void CompleteShip::OnRenderSpace()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func317::func;
	return execfunc(this);
}

namespace _func318
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(void (CompleteShip::*)(bool , bool )), "57565383ec108b5c2420c744240802000000", argdata, 3, 6, &func);
}

void CompleteShip::OnRenderShip(bool unk1, bool unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool unk1_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func318::func;
	return execfunc(this, unk1, unk2);
}

namespace _func319
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetText", typeid(void (ConfirmWindow::*)(const TextString &, int , bool , const TextString &, const TextString &)), "5589e557565383ec4c8b5d088b4514", argdata, 6, 6, &func);
}

void ConfirmWindow::SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, const TextString &text__arg, int minWidth_arg, bool autoCenter_arg, const TextString &yesText__arg, const TextString &noText__arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func319::func;
	return execfunc(this, text_, minWidth, autoCenter, yesText_, noText_);
}

namespace _func320
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::OnRender", typeid(void (ConfirmWindow::*)()), "5589e557565381eccc0000008b5d088b434885c0", argdata, 1, 6, &func);
}

void ConfirmWindow::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func320::func;
	return execfunc(this);
}

namespace _func321
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetPosition", typeid(void (ConfirmWindow::*)(Point )), "5589e557565383ec3c8b5d088b450c8b5510", argdata, 2, 6, &func);
}

void ConfirmWindow::SetPosition(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func321::func;
	return execfunc(this, pos);
}

namespace _func322
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::Open", typeid(void (ConfirmWindow::*)()), "5589e557565383ec4c8b5d088d7de0", argdata, 1, 6, &func);
}

void ConfirmWindow::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func322::func;
	return execfunc(this);
}

namespace _func323
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseClick", typeid(void (ConfirmWindow::*)(int , int )), "8b4424048078040074??80b88c00000000", argdata, 3, 6, &func);
}

void ConfirmWindow::MouseClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func323::func;
	return execfunc(this, mX, mY);
}

namespace _func324
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseMove", typeid(void (ConfirmWindow::*)(int , int )), "5383ec188b5c2420807b040074??8b442428", argdata, 3, 6, &func);
}

void ConfirmWindow::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func324::func;
	return execfunc(this, mX, mY);
}

namespace _func325
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::constructor", typeid(void (ConfirmWindow::*)()), "565383ec248b5c24308d74241f891c24e8????????8d431c", argdata, 1, 6, &func);
}

void ConfirmWindow::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func325::func;
	return execfunc(this);
}

namespace _func326
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::Close", typeid(void (ConfirmWindow::*)()), "5383ec188b5c24208b4348890424", argdata, 1, 6, &func);
}

void ConfirmWindow::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func326::func;
	return execfunc(this);
}

namespace _func327
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ControlButton::OnRender", typeid(void (ControlButton::*)()), "5589e557565383ec6c8b5d08f30f102d????????", argdata, 1, 6, &func);
}

void ControlButton::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ControlButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func327::func;
	return execfunc(this);
}

namespace _func328
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ControlsScreen::OnInit", typeid(void (ControlsScreen::*)()), "5589e557565381ecbc0000008b45088b80cc040000", argdata, 1, 6, &func);
}

void ControlsScreen::OnInit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func328::func;
	return execfunc(this);
}

namespace _func329
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ControlsScreen::OnLoop", typeid(void (ControlsScreen::*)()), "5589e557565331db83ec4c8b45088b4d08", argdata, 1, 6, &func);
}

void ControlsScreen::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func329::func;
	return execfunc(this);
}

namespace _func330
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ControlsScreen::OnRender", typeid(void (ControlsScreen::*)()), "5589e557565381ec7c0100008b7508", argdata, 1, 6, &func);
}

void ControlsScreen::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ControlsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func330::func;
	return execfunc(this);
}

namespace _func331
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CooldownSystemBox::constructor", typeid(void (CooldownSystemBox::*)(Point , ShipSystem *, bool )), "5557565381ec1c0100008bac24300100008b9c24340100008bb424380100008b84243c0100008bbc2440010000", argdata, 4, 6, &func);
}

void CooldownSystemBox::constructor(Point pos, ShipSystem *sys, bool roundDown)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, bool roundDown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func331::func;
	return execfunc(this, pos, sys, roundDown);
}

namespace _func332
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CooldownSystemBox::OnRender", typeid(void (CooldownSystemBox::*)(bool )), "5589e557565383ec5c8b5d080fb6450c", argdata, 2, 6, &func);
}

void CooldownSystemBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func332::func;
	return execfunc(this, ignoreStatus);
}

namespace _func333
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CreditScreen::OnRender", typeid(void (CreditScreen::*)()), "5589e557565383ec7c8b7508e8????????c70424????????", argdata, 1, 6, &func);
}

void CreditScreen::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func333::func;
	return execfunc(this);
}

namespace _func334
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CreditScreen::constructor", typeid(void (CreditScreen::*)()), "8b442404c74008????????c7400c????????", argdata, 1, 6, &func);
}

void CreditScreen::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func334::func;
	return execfunc(this);
}

namespace _func335
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CreditScreen::Start", typeid(void (CreditScreen::*)(const std::string &, const std::vector<std::string> &)), "5589e557565381ec0c0100008b5d08", argdata, 3, 6, &func);
}

void CreditScreen::Start(const std::string &shipName, const std::vector<std::string> &crewNames)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CreditScreen *this_arg, const std::string &shipName_arg, const std::vector<std::string> &crewNames_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func335::func;
	return execfunc(this, shipName, crewNames);
}

namespace _func336
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), "53baabaaaaaa83ec188b5c24208b431c2b4318", argdata, 1, 2, &func);
}

bool CreditScreen::Done()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func336::func;
	return execfunc(this);
}

namespace _func337
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAI::UpdateDrones", typeid(void (CrewAI::*)()), "5589e557565381ecbc0000008b5d08c78574ffffff00000000", argdata, 1, 6, &func);
}

void CrewAI::UpdateDrones()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func337::func;
	return execfunc(this);
}

namespace _func338
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAI::AssignCrewmembers", typeid(void (CrewAI::*)()), "5557565331db83ec1c8b7424308b56308b4634", argdata, 1, 6, &func);
}

void CrewAI::AssignCrewmembers()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func338::func;
	return execfunc(this);
}

namespace _func339
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x3ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeTask", typeid(int (CrewAI::*)(CrewTask , int )), "5557565383ec1c8b6c24408b5c24348b742438", argdata, 3, 2, &func);
}

int CrewAI::PrioritizeTask(CrewTask task, int crewId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewTask task_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func339::func;
	return execfunc(this, task, crewId);
}

namespace _func340
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAI::UpdateIntruders", typeid(void (CrewAI::*)()), "5557565383ec3c8b6c24508b451c8b5518", argdata, 1, 6, &func);
}

void CrewAI::UpdateIntruders()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func340::func;
	return execfunc(this);
}

namespace _func341
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeIntruderRoom", typeid(int (CrewAI::*)(CrewMember *, int , int )), "5557565383ec2c8b7c24448b5c24408b7424488b4778", argdata, 4, 2, &func);
}

int CrewAI::PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewMember *crew_arg, int roomId_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func341::func;
	return execfunc(this, crew, roomId, target);
}

namespace _func342
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::UpdateCrewMember", typeid(void (CrewAI::*)(int )), "5557565383ec5c8b5c24708b5424748b430c", argdata, 2, 6, &func);
}

void CrewAI::UpdateCrewMember(int crewId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func342::func;
	return execfunc(this, crewId);
}

namespace _func343
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAI::CheckForHealing", typeid(void (CrewAI::*)()), "5589e557565331db83ec4c8b7d088b4f0c8b4710", argdata, 1, 6, &func);
}

void CrewAI::CheckForHealing()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func343::func;
	return execfunc(this);
}

namespace _func344
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAI::OnLoop", typeid(void (CrewAI::*)()), "5589e557565383ec4c8b5d088b0389442404", argdata, 1, 6, &func);
}

void CrewAI::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func344::func;
	return execfunc(this);
}

namespace _func345
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAI::CheckForProblems", typeid(void (CrewAI::*)()), "5589e557565383ec7c8b7d088b07c6470801", argdata, 1, 6, &func);
}

void CrewAI::CheckForProblems()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func345::func;
	return execfunc(this);
}

namespace _func346
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::DangerRating", typeid(int (CrewAI::*)(int , int )), "5589e557565383ec5c8b75088b4d108b5d0c", argdata, 3, 2, &func);
}

int CrewAI::DangerRating(int roomId, int crewId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAI *this_arg, int roomId_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func346::func;
	return execfunc(this, roomId, crewId);
}

namespace _func347
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::constructor", typeid(void (CrewAnimation::*)(int , const std::string &, Pointf , bool )), "5557565383ec4c8b4424748b4c2460", argdata, 5, 6, &func);
}

void CrewAnimation::constructor(int shipId, const std::string &race, Pointf unk, bool hostile)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, int shipId_arg, const std::string &race_arg, Pointf unk_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func347::func;
	return execfunc(this, shipId, race, unk, hostile);
}

namespace _func348
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetDeathSound", typeid(std::string (CrewAnimation::*)()), "5589e557565381ec0c0100008b450c80b87409000000", argdata, 2, 18, &func);
}

std::string CrewAnimation::GetDeathSound()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func348::func;
	return execfunc(this);
}

namespace _func349
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("DO_NOT_HOOK_MANTISANIMATIONSHOOTINGSOUND", typeid(void (*)()), "5557565381ec0c010000803d????????00", argdata, 0, 4, &func);
}

namespace _func350
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("DO_NOT_HOOK_ROCKANIMATIONSHOOTINGSOUND", typeid(void (*)()), ".5557565381ec0c010000803d????????00", argdata, 0, 4, &func);
}

namespace _func351
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetShootingSound", typeid(std::string (CrewAnimation::*)()), ".5557565381ec0c010000803d????????00", argdata, 2, 18, &func);
}

std::string CrewAnimation::GetShootingSound()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func351::func;
	return execfunc(this);
}

namespace _func352
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnRender", typeid(void (CrewAnimation::*)(float , int , bool )), "565383ec648b5c24708b74247c8b430485c0", argdata, 4, 6, &func);
}

void CrewAnimation::OnRender(float scale, int selectedState, bool outlineOnly)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, float scale_arg, int selectedState_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func352::func;
	return execfunc(this, scale, selectedState, outlineOnly);
}

namespace _func353
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnRenderProps", typeid(void (CrewAnimation::*)()), "5631f65383ec348b5c2440", argdata, 1, 6, &func);
}

void CrewAnimation::OnRenderProps()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func353::func;
	return execfunc(this);
}

namespace _func354
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnInit", typeid(void (CrewAnimation::*)(const std::string &, Pointf , bool )), "5589e557565381eccc0000008b45188b5d08", argdata, 4, 6, &func);
}

void CrewAnimation::OnInit(const std::string &name, Pointf position, bool enemy)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, const std::string &name_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func354::func;
	return execfunc(this, name, position, enemy);
}

namespace _func355
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::SetupStrips", typeid(void (CrewAnimation::*)()), "5589e557565381ec2c0100008b7d088d876c090000", argdata, 1, 6, &func);
}

void CrewAnimation::SetupStrips()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func355::func;
	return execfunc(this);
}

namespace _func356
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdate", typeid(void (CrewAnimation::*)(Pointf , bool , bool , bool , bool , bool )), "5589e557565383ec3c8b45248b5d088b4d148b7518", argdata, 7, 6, &func);
}

void CrewAnimation::OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, Pointf position_arg, bool moving_arg, bool fighting_arg, bool repairing_arg, bool dying_arg, bool onFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func356::func;
	return execfunc(this, position, moving, fighting, repairing, dying, onFire);
}

namespace _func357
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::destructor", typeid(void (CrewAnimation::*)()), "5557565383ec5c8b442470c700????????8b807809000085c074??890424e8????????8b4424708b806c0900008d48f481f9????????0f85????????", argdata, 1, 6, &func);
}

void CrewAnimation::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func357::func;
	return execfunc(this);
}

namespace _func358
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::FireShot", typeid(bool (CrewAnimation::*)()), "5383ec188b4424208d989c080000", argdata, 1, 2, &func);
}

bool CrewAnimation::FireShot()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func358::func;
	return execfunc(this);
}

namespace _func359
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::GetFiringFrame", typeid(int (CrewAnimation::*)()), "8b5424048b423483f8ff", argdata, 1, 2, &func);
}

int CrewAnimation::GetFiringFrame()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func359::func;
	return execfunc(this);
}

namespace _func360
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::RenderIcon", typeid(void (CrewAnimation::*)(bool )), "57565381ecd00000008b9c24e0000000", argdata, 2, 6, &func);
}

void CrewAnimation::RenderIcon(bool border)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, bool border_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func360::func;
	return execfunc(this, border);
}

namespace _func361
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnUpdateEffects", typeid(void (CrewAnimation::*)()), "5557565383ec5c8b44247083c040890424", argdata, 1, 6, &func);
}

void CrewAnimation::OnUpdateEffects()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func361::func;
	return execfunc(this);
}

namespace _func362
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RandomSkills", typeid(void (CrewBlueprint::*)(int )), "5531c057565383ec3c8b5424548b742450", argdata, 2, 6, &func);
}

void CrewBlueprint::RandomSkills(int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func362::func;
	return execfunc(this, worldLevel);
}

namespace _func363
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderSkill", typeid(void (CrewBlueprint::*)(int , int , int , int , int )), "5557565383ec7c8b8424900000008b9424a40000008bbc24940000008bac24980000008b4864", argdata, 6, 6, &func);
}

void CrewBlueprint::RenderSkill(int x, int y, int length, int height, int skill)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int x_arg, int y_arg, int length_arg, int height_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func363::func;
	return execfunc(this, x, y, length, height, skill);
}

namespace _func364
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderIcon", typeid(void (CrewBlueprint::*)(float )), "5589e557565381eccc0100008b4508", argdata, 2, 6, &func);
}

void CrewBlueprint::RenderIcon(float opacity)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, float opacity_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func364::func;
	return execfunc(this, opacity);
}

namespace _func365
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::destructor", typeid(void (CrewBlueprint::*)()), "5557565383ec2c8b7424408b467c", argdata, 1, 6, &func);
}

void CrewBlueprint::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func365::func;
	return execfunc(this);
}

namespace _func366
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::GetNameShort", typeid(std::string (CrewBlueprint::*)()), "5589e557565383ec3c8b5d0c807b4800", argdata, 2, 18, &func);
}

std::string CrewBlueprint::GetNameShort()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func366::func;
	return execfunc(this);
}

namespace _func367
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::GetCurrentSkillColor", typeid(GL_Color (CrewBlueprint::*)(int )), "8b5424088b4c240c8b4424048b52648d14ca", argdata, 3, 18, &func);
}

GL_Color CrewBlueprint::GetCurrentSkillColor(int skill)
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func367::func;
	return execfunc(this, skill);
}

namespace _func368
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::constructor", typeid(void (CrewBox::*)(Point , CrewMember *, int )), "5557565381ec8c0000008bbc24a00000008b8424a40000008b9c24ac000000", argdata, 4, 6, &func);
}

void CrewBox::constructor(Point pos, CrewMember *crew, int number)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg, Point pos_arg, CrewMember *crew_arg, int number_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func368::func;
	return execfunc(this, pos, crew, number);
}

namespace _func369
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::OnRender", typeid(void (CrewBox::*)()), "5589e557565383ec6c8b5d088d8380010000", argdata, 1, 6, &func);
}

void CrewBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func369::func;
	return execfunc(this);
}

namespace _func370
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::GetSelected", typeid(CrewMember *(CrewBox::*)(int , int )), "5589e557565381ecdc0200008b4508", argdata, 3, 2, &func);
}

CrewMember *CrewBox::GetSelected(int mouseX, int mouseY)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg, int mouseX_arg, int mouseY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func370::func;
	return execfunc(this, mouseX, mouseY);
}

namespace _func371
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::OnLoop", typeid(void (CrewBox::*)(bool )), "565383ec148b5c24208b7424248b4320", argdata, 2, 6, &func);
}

void CrewBox::OnLoop(bool selected)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg, bool selected_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func371::func;
	return execfunc(this, selected);
}

namespace _func372
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::OnRenderSkillLevel", typeid(void (CrewBox::*)()), "5383ec288b5c243080bb1c01000000", argdata, 1, 6, &func);
}

void CrewBox::OnRenderSkillLevel()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func372::func;
	return execfunc(this);
}

namespace _func373
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::destructor", typeid(void (CrewBox::*)()), "5557565383ec2c8b7424408b8628010000890424", argdata, 1, 6, &func);
}

void CrewBox::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func373::func;
	return execfunc(this);
}

namespace _func374
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::MouseClick", typeid(bool (CrewBox::*)()), "83ec1c8b5424200fb64268", argdata, 1, 2, &func);
}

bool CrewBox::MouseClick()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func374::func;
	return execfunc(this);
}

namespace _func375
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::RenderIcon", typeid(void (CrewBox::*)()), "565383ec348b5c24408b4320", argdata, 1, 6, &func);
}

void CrewBox::RenderIcon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func375::func;
	return execfunc(this);
}

namespace _func376
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::RenderLabels", typeid(void (CrewBox::*)()), "5589e557565383ec5c8b75088d5dd4", argdata, 1, 6, &func);
}

void CrewBox::RenderLabels()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func376::func;
	return execfunc(this);
}

namespace _func377
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewBox::RenderCloneDying", typeid(void (CrewBox::*)()), "83ec3c8b44244080b80801000000", argdata, 1, 6, &func);
}

void CrewBox::RenderCloneDying()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func377::func;
	return execfunc(this);
}

namespace _func378
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewControl::OnRender", typeid(void (CrewControl::*)()), "5589e557565381ec8c0000008b5d088b4b3c8b4340", argdata, 1, 6, &func);
}

void CrewControl::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func378::func;
	return execfunc(this);
}

namespace _func379
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewControl::OnLoop", typeid(void (CrewControl::*)()), "5589e557565383ec4c8b5d088db388000000", argdata, 1, 6, &func);
}

void CrewControl::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func379::func;
	return execfunc(this);
}

namespace _func380
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewControl::UpdateCrewBoxes", typeid(void (CrewControl::*)()), "5557565383ec4c8b5c24608d442430", argdata, 1, 6, &func);
}

void CrewControl::UpdateCrewBoxes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func380::func;
	return execfunc(this);
}

namespace _func381
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LinkShip", typeid(void (CrewControl::*)(ShipManager *)), "5383ec188b5c24208b4424248903891c24", argdata, 2, 6, &func);
}

void CrewControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func381::func;
	return execfunc(this, ship);
}

namespace _func382
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::MouseMove", typeid(void (CrewControl::*)(int , int , int , int )), "5589e557565381ecac0000008b7d08837d0cff", argdata, 5, 6, &func);
}

void CrewControl::MouseMove(int mX, int mY, int wX, int wY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, int wX_arg, int wY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func382::func;
	return execfunc(this, mX, mY, wX, wY);
}

namespace _func383
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LButton", typeid(void (CrewControl::*)(int , int , int , int , bool )), "5589e557565383ec2c8b5d088b8380000000", argdata, 6, 6, &func);
}

void CrewControl::LButton(int mX, int mY, int wX, int wY, bool shiftHeld)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, int wX_arg, int wY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func383::func;
	return execfunc(this, mX, mY, wX, wY, shiftHeld);
}

namespace _func384
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::ClearDeadCrew", typeid(void (CrewControl::*)(std::vector<CrewMember*> *)), "5557565331db83ec1c8b7424348b56048b0e", argdata, 2, 6, &func);
}

void CrewControl::ClearDeadCrew(std::vector<CrewMember*> *crew)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, std::vector<CrewMember*> *crew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func384::func;
	return execfunc(this, crew);
}

namespace _func385
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewControl::ClearCrewBoxes", typeid(void (CrewControl::*)()), "57565383ec108b7c24208b4f408b573c", argdata, 1, 6, &func);
}

void CrewControl::ClearCrewBoxes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func385::func;
	return execfunc(this);
}

namespace _func386
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::SelectPotentialCrew", typeid(void (CrewControl::*)(CrewMember *, bool )), "57565383ec108b4424248b5c24208b742428", argdata, 3, 6, &func);
}

void CrewControl::SelectPotentialCrew(CrewMember *crew, bool allowTeleportLeaving)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, CrewMember *crew_arg, bool allowTeleportLeaving_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func386::func;
	return execfunc(this, crew, allowTeleportLeaving);
}

namespace _func387
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::KeyDown", typeid(void (CrewControl::*)(SDLKey )), "5557565381ec0c0100008d442430", argdata, 2, 6, &func);
}

void CrewControl::KeyDown(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func387::func;
	return execfunc(this, key);
}

namespace _func388
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::RButton", typeid(void (CrewControl::*)(int , int , bool )), "5557565383ec1c8b742430807e3000", argdata, 4, 6, &func);
}

void CrewControl::RButton(int mX, int mY, bool shiftHeld)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, int mX_arg, int mY_arg, bool shiftHeld_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func388::func;
	return execfunc(this, mX, mY, shiftHeld);
}

namespace _func389
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::SelectCrew", typeid(void (CrewControl::*)(bool )), "5557565383ec1c807c243400", argdata, 2, 6, &func);
}

void CrewControl::SelectCrew(bool keep_current)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewControl *this_arg, bool keep_current_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func389::func;
	return execfunc(this, keep_current);
}

namespace _func390
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewCustomizeBox::CheckContents", typeid(void (CrewCustomizeBox::*)()), "5589e5565383ec208b5d0880bbfc05000000", argdata, 1, 6, &func);
}

void CrewCustomizeBox::CheckContents()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewCustomizeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func390::func;
	return execfunc(this);
}

namespace _func391
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewCustomizeBox::constructor", typeid(void (CrewCustomizeBox::*)(Point , ShipManager *, int )), "5557565383ec7c8b8424a00000008d", argdata, 4, 6, &func);
}

void CrewCustomizeBox::constructor(Point location, ShipManager *shipManager, int slot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewCustomizeBox *this_arg, Point location_arg, ShipManager *shipManager_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func391::func;
	return execfunc(this, location, shipManager, slot);
}

namespace _func392
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewDrone::constructor", typeid(void (CrewDrone::*)(const std::string &, const std::string &, int , const DroneBlueprint *, CrewAnimation *)), "5589e557565381ecdc0000008b450c8b4d08", argdata, 6, 6, &func);
}

void CrewDrone::constructor(const std::string &type, const std::string &name, int shipId, const DroneBlueprint *blueprint, CrewAnimation *anim)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewDrone *this_arg, const std::string &type_arg, const std::string &name_arg, int shipId_arg, const DroneBlueprint *blueprint_arg, CrewAnimation *anim_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func392::func;
	return execfunc(this, type, name, shipId, blueprint, anim);
}

namespace _func393
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewDrone::OnLoop", typeid(void (CrewDrone::*)()), "5589e557565383ec4c8b5d088db340050000", argdata, 1, 6, &func);
}

void CrewDrone::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func393::func;
	return execfunc(this);
}

namespace _func394
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewDrone::ProvidesVision", typeid(bool (CrewDrone::*)()), "8b4424048b500485d2", argdata, 1, 2, &func);
}

bool CrewDrone::ProvidesVision()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func394::func;
	return execfunc(this);
}

namespace _func395
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewDrone::SetCurrentShip", typeid(void (CrewDrone::*)(int )), "8b5424048b442408898238010000", argdata, 2, 6, &func);
}

void CrewDrone::SetCurrentShip(int shipId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewDrone *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func395::func;
	return execfunc(this, shipId);
}

namespace _func396
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewDrone::destructor", typeid(void (CrewDrone::*)()), "5557565383ec2c8b442440c700????????c78040050000????????8b80800600008d50f481fa????????0f853f030000", argdata, 1, 6, &func);
}

void CrewDrone::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func396::func;
	return execfunc(this);
}

namespace _func397
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::RemoveItem", typeid(void (CrewEquipBox::*)()), "5383ec188b5c24208b435485c0", argdata, 1, 6, &func);
}

void CrewEquipBox::RemoveItem()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func397::func;
	return execfunc(this);
}

namespace _func398
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::constructor", typeid(void (CrewEquipBox::*)(Point , ShipManager *, int )), "5557565383ec7c8b8424980000008d742448", argdata, 4, 6, &func);
}

void CrewEquipBox::constructor(Point pos, ShipManager *ship, int slot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, Point pos_arg, ShipManager *ship_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func398::func;
	return execfunc(this, pos, ship, slot);
}

namespace _func399
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::GetConfirmDelete", typeid(bool (CrewEquipBox::*)()), "8b5424040fb68280020000c6828002000000", argdata, 1, 2, &func);
}

bool CrewEquipBox::GetConfirmDelete()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func399::func;
	return execfunc(this);
}

namespace _func400
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::RenderLabels", typeid(void (CrewEquipBox::*)(bool , bool )), "5589e557565381ecac0000008b5d088b4d0c8b75108b434c", argdata, 3, 6, &func);
}

void CrewEquipBox::RenderLabels(bool dragging, bool isNew)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, bool dragging_arg, bool isNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func400::func;
	return execfunc(this, dragging, isNew);
}

namespace _func401
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnRender", typeid(void (CrewEquipBox::*)(bool )), "5589e557565383ec2c8b5d08c70424????????8b750c", argdata, 2, 6, &func);
}

void CrewEquipBox::OnRender(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func401::func;
	return execfunc(this, unk);
}

namespace _func402
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextInput", typeid(void (CrewEquipBox::*)(SDLKey )), "565383ec148b4424208b7424248d9834020000891c24", argdata, 2, 6, &func);
}

void CrewEquipBox::OnTextInput(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func402::func;
	return execfunc(this, key);
}

namespace _func403
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::OnTextEvent", typeid(void (CrewEquipBox::*)(CEvent::TextEvent )), ".565383ec148b4424208b7424248d9834020000891c24", argdata, 2, 6, &func);
}

void CrewEquipBox::OnTextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func403::func;
	return execfunc(this, event);
}

namespace _func404
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::MouseClick", typeid(void (CrewEquipBox::*)()), "5589e557565383ec2c8b5d088b734c85f6", argdata, 1, 6, &func);
}

void CrewEquipBox::MouseClick()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func404::func;
	return execfunc(this);
}

namespace _func405
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::CloseRename", typeid(void (CrewEquipBox::*)()), "8b44240480b83202000000", argdata, 1, 6, &func);
}

void CrewEquipBox::CloseRename()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func405::func;
	return execfunc(this);
}

namespace _func406
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnInit", typeid(void (CrewManifest::*)(ShipManager *)), "5557565383ec4c8b5c24608b4b748b537089c829d083f803", argdata, 2, 6, &func);
}

void CrewManifest::OnInit(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func406::func;
	return execfunc(this, ship);
}

namespace _func407
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnRender", typeid(void (CrewManifest::*)()), "5589e557565383ec6c8b5d08e8????????8b9304010000", argdata, 1, 6, &func);
}

void CrewManifest::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func407::func;
	return execfunc(this);
}

namespace _func408
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewManifest::Update", typeid(void (CrewManifest::*)()), "565383ec448b7424508d442420", argdata, 1, 6, &func);
}

void CrewManifest::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func408::func;
	return execfunc(this);
}

namespace _func409
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewManifest::constructor", typeid(void (CrewManifest::*)()), "5557565381ec8c0000008bbc24a00000008d5c24708d7424688d6c2458", argdata, 1, 6, &func);
}

void CrewManifest::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func409::func;
	return execfunc(this);
}

namespace _func410
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnKeyDown", typeid(void (CrewManifest::*)(SDLKey )), ".57565331db83ec108b7c24208b7424248b57708b477429d0c1f80285c0", argdata, 2, 6, &func);
}

void CrewManifest::OnKeyDown(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func410::func;
	return execfunc(this, key);
}

namespace _func411
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnKeyUp", typeid(void (CrewManifest::*)(SDLKey )), ".57565331db83ec108b7c24208b7424248b57708b477429d0c1f80285c0", argdata, 2, 6, &func);
}

void CrewManifest::OnKeyUp(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func411::func;
	return execfunc(this, key);
}

namespace _func412
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnTextInput", typeid(void (CrewManifest::*)(SDLKey )), ".57565331db83ec108b7c24208b7424248b57708b477429d0c1f80285c0", argdata, 2, 6, &func);
}

void CrewManifest::OnTextInput(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func412::func;
	return execfunc(this, key);
}

namespace _func413
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::OnTextEvent", typeid(void (CrewManifest::*)(CEvent::TextEvent )), ".57565331db83ec108b7c24208b7424248b57708b477429d0c1f80285c0", argdata, 2, 6, &func);
}

void CrewManifest::OnTextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func413::func;
	return execfunc(this, event);
}

namespace _func414
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewManifest::Close", typeid(void (CrewManifest::*)()), "565331db83ec148b7424208b56708b4674", argdata, 1, 6, &func);
}

void CrewManifest::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func414::func;
	return execfunc(this);
}

namespace _func415
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewManifest::Open", typeid(void (CrewManifest::*)()), "!.5383ec188b5c2420891c24e8????????8d437c", argdata, 1, 6, &func);
}

void CrewManifest::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func415::func;
	return execfunc(this);
}

namespace _func416
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::MouseClick", typeid(void (CrewManifest::*)(int , int )), "565383ec148b7424208b4424248b5424288b8e0401000085c9", argdata, 3, 6, &func);
}

void CrewManifest::MouseClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func416::func;
	return execfunc(this, mX, mY);
}

namespace _func417
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewManifest::MouseMove", typeid(void (CrewManifest::*)(int , int )), "5557565383ec2c8b5c24408b7424448b7c24488d437c", argdata, 3, 6, &func);
}

void CrewManifest::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewManifest *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func417::func;
	return execfunc(this, mX, mY);
}

namespace _func418
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), "565383ec348b5c24408b74244480bbac01000000", argdata, 2, 6, &func);
}

void CrewMember::OnRender(bool outlineOnly)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func418::func;
	return execfunc(this, outlineOnly);
}

namespace _func419
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetRoomDamage", typeid(Damage (CrewMember::*)()), "8b442404c70000000000c7400400000000c7400800000000c7400c00000000c7401000000000c7401400000000c7401800000000c7401c00000000", argdata, 2, 18, &func);
}

Damage CrewMember::GetRoomDamage()
{
	typedef Damage __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func419::func;
	return execfunc(this);
}

namespace _func420
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(void (CrewMember::*)(Repairable *)), "5589e557565383ec3c8b5d08f30f1015????????", argdata, 2, 6, &func);
}

void CrewMember::StartRepair(Repairable *toRepair)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Repairable *toRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func420::func;
	return execfunc(this, toRepair);
}

namespace _func421
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::UpdateRepair", typeid(void (CrewMember::*)()), "5589e557565383ec6c8b5d088b4368f30f2a8b90000000f30f104308", argdata, 1, 6, &func);
}

void CrewMember::UpdateRepair()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func421::func;
	return execfunc(this);
}

namespace _func422
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::UpdateMovement", typeid(void (CrewMember::*)()), "5589e5565383ec408b5d088b839c00000083783806", argdata, 1, 6, &func);
}

void CrewMember::UpdateMovement()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func422::func;
	return execfunc(this);
}

namespace _func423
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), "5589e557565381ec8c0000008b5d0880bbac01000000", argdata, 1, 6, &func);
}

void CrewMember::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func423::func;
	return execfunc(this);
}

namespace _func424
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetTooltip", typeid(std::string (CrewMember::*)()), "5589e557565381ec8c0000008b45088d5dd8895c2408", argdata, 2, 18, &func);
}

std::string CrewMember::GetTooltip()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func424::func;
	return execfunc(this);
}

namespace _func425
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillTooltip", typeid(std::string (*)(int , int , std::pair<int, int> , bool )), ".5589e557565381ecac000000", argdata, 5, 18, &func);
}

std::string CrewMember::GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int skillId_arg, int skillLevel_arg, std::pair<int, int> progress_arg, bool infoScreen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func425::func;
	return execfunc(skillId, skillLevel, progress, infoScreen);
}

namespace _func426
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(void (CrewMember::*)(bool )), "565383ec148b5c24208b7424248b839c000000", argdata, 2, 6, &func);
}

void CrewMember::SetSex(bool male)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func426::func;
	return execfunc(this, male);
}

namespace _func427
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CycleColorLayer", typeid(void (CrewMember::*)(int )), "5557565383ec4c8b442460????????00000000????????00000000", argdata, 2, 6, &func);
}

void CrewMember::CycleColorLayer(int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func427::func;
	return execfunc(this, unk);
}

namespace _func428
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::constructor", typeid(void (CrewMember::*)(CrewBlueprint &, int , bool , CrewAnimation *)), "5557565381ec9c0000008b8424b00000008bbc24b80000008b9c24bc000000", argdata, 5, 6, &func);
}

void CrewMember::constructor(CrewBlueprint &blueprint, int shipId, bool intruder, CrewAnimation *animation)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewBlueprint &blueprint_arg, int shipId_arg, bool intruder_arg, CrewAnimation *animation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func428::func;
	return execfunc(this, blueprint, shipId, intruder, animation);
}

namespace _func429
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Functional", typeid(bool (CrewMember::*)()), "83ec1c8b4424208b10890424????????????83c41c", argdata, 1, 2, &func);
}

bool CrewMember::Functional()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func429::func;
	return execfunc(this);
}

namespace _func430
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CountForVictory", typeid(bool (CrewMember::*)()), "5383ec188b5c24208b03891c24ff9088000000", argdata, 1, 2, &func);
}

bool CrewMember::CountForVictory()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func430::func;
	return execfunc(this);
}

namespace _func431
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CanSabotage", typeid(bool (CrewMember::*)()), "8b4424040fb68098000000", argdata, 1, 2, &func);
}

bool CrewMember::CanSabotage()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func431::func;
	return execfunc(this);
}

namespace _func432
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CanMan", typeid(bool (CrewMember::*)()), "8b54240431c080ba9800000000", argdata, 1, 2, &func);
}

bool CrewMember::CanMan()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func432::func;
	return execfunc(this);
}

namespace _func433
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CanRepair", typeid(bool (CrewMember::*)()), "5383ec188b5c242080bb9800000000", argdata, 1, 2, &func);
}

bool CrewMember::CanRepair()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func433::func;
	return execfunc(this);
}

namespace _func434
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetControllable", typeid(bool (CrewMember::*)()), "5331c083ec188b5c24208b530485d2", argdata, 1, 2, &func);
}

bool CrewMember::GetControllable()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func434::func;
	return execfunc(this);
}

namespace _func435
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CanHeal", typeid(bool (CrewMember::*)()), "5383ec188b5c2420f30f1043280f2e432c", argdata, 1, 2, &func);
}

bool CrewMember::CanHeal()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func435::func;
	return execfunc(this);
}

namespace _func436
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)()), "!8b4424048b908803000083420c018b108b82cc000000", argdata, 1, 6, &func);
}

void CrewMember::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func436::func;
	return execfunc(this);
}

namespace _func437
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetIntruder", typeid(bool (CrewMember::*)()), ".8b44240480b8ad03000000", argdata, 1, 2, &func);
}

bool CrewMember::GetIntruder()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func437::func;
	return execfunc(this);
}

namespace _func438
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetOutOfGame", typeid(void (CrewMember::*)()), "8b0d????????8b4424048d5101c680a401000001c680ac01000001", argdata, 1, 6, &func);
}

void CrewMember::SetOutOfGame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func438::func;
	return execfunc(this);
}

namespace _func439
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::PositionShift", typeid(float (CrewMember::*)()), "83ec048b15????????8b442408f30f1015????????", argdata, 1, 2, &func);
}

float CrewMember::PositionShift()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func439::func;
	return execfunc(this);
}

namespace _func440
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), "57565331db83ec108b7c24208b742424f30f108700050000", argdata, 2, 6, &func);
}

void CrewMember::SaveState(int fileHelper)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func440::func;
	return execfunc(this, fileHelper);
}

namespace _func441
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CanTeleport", typeid(bool (CrewMember::*)()), "5383ec188b5c24208b839c000000", argdata, 1, 2, &func);
}

bool CrewMember::CanTeleport()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func441::func;
	return execfunc(this);
}

namespace _func442
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::destructor", typeid(void (CrewMember::*)()), "5557565383ec2c8b7c24408b879c000000", argdata, 1, 6, &func);
}

void CrewMember::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func442::func;
	return execfunc(this);
}

namespace _func443
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Cleanup", typeid(void (CrewMember::*)()), ".5383ec188b5c2420891c24", argdata, 1, 6, &func);
}

void CrewMember::Cleanup()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func443::func;
	return execfunc(this);
}

namespace _func444
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), "57565383ec108b7424248b7c2420893424", argdata, 2, 6, &func);
}

void CrewMember::LoadState(int fileHelper)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func444::func;
	return execfunc(this, fileHelper);
}

namespace _func445
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(void (CrewMember::*)(ShipSystem *)), "565383ec148b5c24208b7424248b03c683b401000000", argdata, 2, 6, &func);
}

void CrewMember::SetCurrentSystem(ShipSystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, ShipSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func445::func;
	return execfunc(this, sys);
}

namespace _func446
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::IsManningArtillery", typeid(bool (CrewMember::*)()), "8b44240483787c0b0f94??", argdata, 1, 2, &func);
}

bool CrewMember::IsManningArtillery()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func446::func;
	return execfunc(this);
}

namespace _func447
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::IncreaseSkill", typeid(void (CrewMember::*)(int )), "5557565383ec2c8b5c24408b7424448b03", argdata, 2, 6, &func);
}

void CrewMember::IncreaseSkill(int skillId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func447::func;
	return execfunc(this, skillId);
}

namespace _func448
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(void (CrewMember::*)()), "57565383ec108b5c24208b83b8010000", argdata, 1, 6, &func);
}

void CrewMember::CheckSkills()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func448::func;
	return execfunc(this);
}

namespace _func449
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MasterSkill", typeid(void (CrewMember::*)(int )), "8b4424048b5424088b8024020000", argdata, 2, 6, &func);
}

void CrewMember::MasterSkill(int skillId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func449::func;
	return execfunc(this, skillId);
}

namespace _func450
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillFromSystem", typeid(int (*)(int )), "8b54240483fa01", argdata, 1, 2, &func);
}

int CrewMember::GetSkillFromSystem(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func450::func;
	return execfunc(systemId);
}

namespace _func451
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(void (CrewMember::*)(bool )), "8b4424088b5424048882ec040000", argdata, 2, 6, &func);
}

void CrewMember::SetResisted(bool resisted)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool resisted_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func451::func;
	return execfunc(this, resisted);
}

namespace _func452
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(bool (CrewMember::*)()), "8b5424040fb682ec040000", argdata, 1, 2, &func);
}

bool CrewMember::GetResisted()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func452::func;
	return execfunc(this);
}

namespace _func453
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(void (CrewMember::*)(int , int )), "8b4424048b4c240c8b5424088b8024020000", argdata, 3, 6, &func);
}

void CrewMember::SetSkillProgress(int skillId, int skillLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg, int skillLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func453::func;
	return execfunc(this, skillId, skillLevel);
}

namespace _func454
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), "8b542408b80100000083fa05", argdata, 2, 2, &func);
}

int CrewMember::GetSkillLevel(int skillId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func454::func;
	return execfunc(this, skillId);
}

namespace _func455
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(std::pair<int, int> (CrewMember::*)(int )), "8b5424088b4c240c8b4424048b9224020000", argdata, 3, 18, &func);
}

std::pair<int, int> CrewMember::GetSkillProgress(int skillId)
{
	typedef std::pair<int, int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func455::func;
	return execfunc(this, skillId);
}

namespace _func456
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillModifier", typeid(float (CrewMember::*)(int )), "538b44240cba010000008b4c240883f805", argdata, 2, 2, &func);
}

float CrewMember::GetSkillModifier(int skillId)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func456::func;
	return execfunc(this, skillId);
}

namespace _func457
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::BadAtCombat", typeid(bool (CrewMember::*)()), "5383ec188b5c24208b03891c24ff90a8000000", argdata, 1, 2, &func);
}

bool CrewMember::BadAtCombat()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func457::func;
	return execfunc(this);
}

namespace _func458
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), "5383ec288b5c24308b8388000000", argdata, 1, 6, &func);
}

void CrewMember::EmptySlot()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func458::func;
	return execfunc(this);
}

namespace _func459
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::NeedsSlot", typeid(bool (CrewMember::*)()), "8b44240480b8ac01000000", argdata, 1, 2, &func);
}

bool CrewMember::NeedsSlot()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func459::func;
	return execfunc(this);
}

namespace _func460
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(bool (CrewMember::*)(float )), "560f57c95383ec348b5c2440f30f10542444f30f105b28", argdata, 2, 2, &func);
}

bool CrewMember::DirectModifyHealth(float health)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func460::func;
	return execfunc(this, health);
}

namespace _func461
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(void (CrewMember::*)(float )), "5383ec18f30f104c2424", argdata, 2, 6, &func);
}

void CrewMember::ModifyHealth(float health)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func461::func;
	return execfunc(this, health);
}

namespace _func462
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ApplyDamage", typeid(bool (CrewMember::*)(float )), "5383ec188b5c2420f30f10442424f30f104b28", argdata, 2, 2, &func);
}

bool CrewMember::ApplyDamage(float damage)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func462::func;
	return execfunc(this, damage);
}

namespace _func463
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::RepairingSystem", typeid(bool (CrewMember::*)()), "5383ec188b5c24208b5368", argdata, 1, 2, &func);
}

bool CrewMember::RepairingSystem()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func463::func;
	return execfunc(this);
}

namespace _func464
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), "5383ec188b5c24208b436885c074??8b10", argdata, 1, 2, &func);
}

bool CrewMember::Sabotaging()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func464::func;
	return execfunc(this);
}

namespace _func465
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::RepairingFire", typeid(bool (CrewMember::*)()), "8b54240431c08b4a6885c9", argdata, 1, 2, &func);
}

bool CrewMember::RepairingFire()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func465::func;
	return execfunc(this);
}

namespace _func466
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(Pointf (CrewMember::*)()), "5589e557565383ec2c8b750c8b5d088b4668", argdata, 2, 18, &func);
}

Pointf CrewMember::SelectSabotageTarget()
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func466::func;
	return execfunc(this);
}

namespace _func467
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), "8b4424048b90880000008990f0040000", argdata, 1, 6, &func);
}

void CrewMember::SavePosition()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func467::func;
	return execfunc(this);
}

namespace _func468
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), "8b442404c780f4040000ffffffffc780f0040000ffffffff", argdata, 1, 6, &func);
}

void CrewMember::ClearPosition()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func468::func;
	return execfunc(this);
}

namespace _func469
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(Slot (CrewMember::*)()), "8b5424088b4424048b8af00400008908", argdata, 2, 18, &func);
}

Slot CrewMember::GetSavedPosition()
{
	typedef Slot __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func469::func;
	return execfunc(this);
}

namespace _func470
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(Slot )), "8b4424048b5424088990f00400008b54240c", argdata, 2, 6, &func);
}

void CrewMember::SetSavePosition(Slot position)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Slot position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func470::func;
	return execfunc(this, position);
}

namespace _func471
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::StopRepairing", typeid(void (CrewMember::*)()), "5383ec188b5c24208b436885c074??8b03", argdata, 1, 6, &func);
}

void CrewMember::StopRepairing()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func471::func;
	return execfunc(this);
}

namespace _func472
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), "8b4424048b406885c00f95??", argdata, 1, 2, &func);
}

bool CrewMember::Repairing()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func472::func;
	return execfunc(this);
}

namespace _func473
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozen", typeid(void (CrewMember::*)(bool )), "8b5424088b44240484d274??", argdata, 2, 6, &func);
}

void CrewMember::SetFrozen(bool frozen)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func473::func;
	return execfunc(this, frozen);
}

namespace _func474
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(void (CrewMember::*)(bool )), "8b4424088b542404888279010000", argdata, 2, 6, &func);
}

void CrewMember::SetFrozenLocation(bool frozenLocation)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozenLocation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func474::func;
	return execfunc(this, frozenLocation);
}

namespace _func475
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x3ff};
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(CrewTask )), "8b4424048b54240889907c010000", argdata, 2, 6, &func);
}

void CrewMember::SetTask(CrewTask task)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTask task_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func475::func;
	return execfunc(this, task);
}

namespace _func476
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::FindSlot", typeid(Slot (CrewMember::*)(int , int , bool )), "5589e557565383ec3c8b45188b7d0c8b5d088b7510", argdata, 5, 18, &func);
}

Slot CrewMember::FindSlot(int roomId, int slotId, bool closeEnough)
{
	typedef Slot __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool closeEnough_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func476::func;
	return execfunc(this, roomId, slotId, closeEnough);
}

namespace _func477
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckRoomPath", typeid(bool (CrewMember::*)(int )), "5589e557565383ec6c8b750c8b5d088d45b8", argdata, 2, 2, &func);
}

bool CrewMember::CheckRoomPath(int roomId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func477::func;
	return execfunc(this, roomId);
}

namespace _func478
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::SetPosition", typeid(void (CrewMember::*)(Point )), "565383ec248b4424348b5424388b5c2430", argdata, 2, 6, &func);
}

void CrewMember::SetPosition(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func478::func;
	return execfunc(this, pos);
}

namespace _func479
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(void (CrewMember::*)()), "8b4424048b5078c78084010000ffffffff", argdata, 1, 6, &func);
}

void CrewMember::ClearTask()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func479::func;
	return execfunc(this);
}

namespace _func480
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::ClearPath", typeid(void (CrewMember::*)()), "5589e557565383ec5c8b5d088d55c0", argdata, 1, 6, &func);
}

void CrewMember::ClearPath()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func480::func;
	return execfunc(this);
}

namespace _func481
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoom", typeid(void (CrewMember::*)(int )), "5589e557565383ec3c8b5d088b838c010000", argdata, 2, 6, &func);
}

void CrewMember::SetRoom(int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func481::func;
	return execfunc(this, roomId);
}

namespace _func482
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::IsBusy", typeid(bool (CrewMember::*)()), "8b542404b8010000008b4a6885c9", argdata, 1, 2, &func);
}

bool CrewMember::IsBusy()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func482::func;
	return execfunc(this);
}

namespace _func483
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnInit", typeid(bool (CrewMember::*)()), "8b442404c740201e000000c7406400000000c680ac01000000", argdata, 1, 2, &func);
}

bool CrewMember::OnInit()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func483::func;
	return execfunc(this);
}

namespace _func484
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetFinalGoal", typeid(Point (CrewMember::*)()), "83ec1c8b542424f30f1005????????", argdata, 2, 18, &func);
}

Point CrewMember::GetFinalGoal()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func484::func;
	return execfunc(this);
}

namespace _func485
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetNextGoal", typeid(Point (CrewMember::*)()), "57565383ec108b7424248b5c2420f30f10461c", argdata, 2, 18, &func);
}

Point CrewMember::GetNextGoal()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func485::func;
	return execfunc(this);
}

namespace _func486
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::CloseDoorBehind", typeid(void (CrewMember::*)(Door *)), "8b5424088b442404895064", argdata, 2, 6, &func);
}

void CrewMember::CloseDoorBehind(Door *door)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Door *door_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func486::func;
	return execfunc(this, door);
}

namespace _func487
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(float (CrewMember::*)()), "5557565383ec4c8b5c24608d7424308d7c242e", argdata, 1, 2, &func);
}

float CrewMember::GetMoveSpeed()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func487::func;
	return execfunc(this);
}

namespace _func488
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Restart", typeid(void (CrewMember::*)()), "5589e557565383ec3c8b5d088d75d08b03", argdata, 1, 6, &func);
}

void CrewMember::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func488::func;
	return execfunc(this);
}

namespace _func489
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), "8b442404f30f10442408f30f1180e4040000", argdata, 2, 6, &func);
}

void CrewMember::SetDamageBoost(float damageBoost)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float damageBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func489::func;
	return execfunc(this, damageBoost);
}

namespace _func490
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetHealthBoost", typeid(void (CrewMember::*)(int )), "5383ec188b5c24208b4424248b93e0040000", argdata, 2, 6, &func);
}

void CrewMember::SetHealthBoost(int healthBoost)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int healthBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func490::func;
	return execfunc(this, healthBoost);
}

namespace _func491
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), "575631f65331db83ec108b7c2420", argdata, 1, 6, &func);
}

void CrewMember::InitializeSkills()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func491::func;
	return execfunc(this);
}

namespace _func492
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCloneReady", typeid(void (CrewMember::*)(bool )), "565383ec248b5c24308b44243480bbac01000000", argdata, 2, 6, &func);
}

void CrewMember::SetCloneReady(bool cloneReady)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool cloneReady_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func492::func;
	return execfunc(this, cloneReady);
}

namespace _func493
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::Kill", typeid(void (CrewMember::*)(bool )), "565383ec248b5c24308b7424348b4368", argdata, 2, 6, &func);
}

void CrewMember::Kill(bool noClone)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool noClone_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func493::func;
	return execfunc(this, noClone);
}

namespace _func494
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), "8b54240431c080ba7801000000", argdata, 1, 2, &func);
}

bool CrewMember::NeedFrozenLocation()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func494::func;
	return execfunc(this);
}

namespace _func495
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), "565383ec148b5c24208bb39c000000", argdata, 1, 6, &func);
}

void CrewMember::CheckForTeleport()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func495::func;
	return execfunc(this);
}

namespace _func496
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(void (CrewMember::*)(int )), "8b5424048b442408898238010000", argdata, 2, 6, &func);
}

void CrewMember::SetCurrentShip(int shipId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func496::func;
	return execfunc(this, shipId);
}

namespace _func497
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), "8b4424048b9060010000", argdata, 1, 6, &func);
}

void CrewMember::CheckFighting()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func497::func;
	return execfunc(this);
}

namespace _func498
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDeathNumber", typeid(void (CrewMember::*)(int )), "8b4424088b5424043b05????????", argdata, 2, 6, &func);
}

void CrewMember::SetDeathNumber(int deathNum)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int deathNum_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func498::func;
	return execfunc(this, deathNum);
}

namespace _func499
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(void (CrewMember::*)(bool )), "8b4424088b5424048882ad030000", argdata, 2, 6, &func);
}

void CrewMember::ForceMindControl(bool force)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func499::func;
	return execfunc(this, force);
}

namespace _func500
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("CrewMember::RenderSkillUpAnimation", typeid(void (CrewMember::*)(Point )), "5557565383ec6c8b842484000000c744242c0000000089442434", argdata, 2, 6, &func);
}

void CrewMember::RenderSkillUpAnimation(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func500::func;
	return execfunc(this, pos);
}

namespace _func501
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::Clone", typeid(void (CrewMember::*)()), "57565383ec208b5c2430c683a401000000c683ac01000000c7830005000000000000", argdata, 1, 6, &func);
}

void CrewMember::Clone()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func501::func;
	return execfunc(this);
}

namespace _func502
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), "565383ec448b5c24508b83b0010000", argdata, 1, 6, &func);
}

void CrewMember::UpdateHealth()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func502::func;
	return execfunc(this);
}

namespace _func503
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), "5383ec288b5c24308b4b0485c9", argdata, 1, 6, &func);
}

void CrewMember::OnRenderPath()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func503::func;
	return execfunc(this);
}

namespace _func504
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetPath", typeid(bool (CrewMember::*)(Path *)), "5557565383ec3c8b742454f30f1005????????", argdata, 2, 2, &func);
}

bool CrewMember::SetPath(Path *path)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Path *path_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func504::func;
	return execfunc(this, path);
}

namespace _func505
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetRoomPath", typeid(void (CrewMember::*)(int , int )), "5589e557565383ec5c8b5d088b750c8b7d108b838c010000", argdata, 3, 6, &func);
}

void CrewMember::SetRoomPath(int slotId, int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func505::func;
	return execfunc(this, slotId, roomId);
}

namespace _func506
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetLocation", typeid(Point (CrewMember::*)()), "57565383ec108b7424248b5c2420f30f10460c", argdata, 2, 18, &func);
}

Point CrewMember::GetLocation()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func506::func;
	return execfunc(this);
}

namespace _func507
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::AtGoal", typeid(bool (CrewMember::*)()), "8b442404f30f1015????????f30f100d????????f30f105818", argdata, 1, 2, &func);
}

bool CrewMember::AtGoal()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func507::func;
	return execfunc(this);
}

namespace _func508
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), ".8b442404f30f1015????????f30f2a8890000000f30f104008", argdata, 1, 2, &func);
}

bool CrewMember::AtFinalGoal()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func508::func;
	return execfunc(this);
}

namespace _func509
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRenderHealth", typeid(void (CrewMember::*)()), "5589e557565381ecac0000008b7d0880bfac01000000", argdata, 1, 6, &func);
}

void CrewMember::OnRenderHealth()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func509::func;
	return execfunc(this);
}

namespace _func510
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), "8b54240431c080baac0100000075??f30f2c4228", argdata, 1, 2, &func);
}

int CrewMember::GetIntegerHealth()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func510::func;
	return execfunc(this);
}

namespace _func511
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetRepairingId", typeid(int (CrewMember::*)()), "8b4424048b406885c074??", argdata, 1, 2, &func);
}

int CrewMember::GetRepairingId()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func511::func;
	return execfunc(this);
}

namespace _func512
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::WithinRect", typeid(bool (CrewMember::*)(int , int , int , int )), "538b4424148b5c24088b54240c8b4c2418", argdata, 5, 2, &func);
}

bool CrewMember::WithinRect(int x, int y, int w, int h)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func512::func;
	return execfunc(this, x, y, w, h);
}

namespace _func513
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetLongName", typeid(std::string (CrewMember::*)()), "5589e55383ec148b450c8b5d0880b81002000000", argdata, 2, 18, &func);
}

std::string CrewMember::GetLongName()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func513::func;
	return execfunc(this);
}

namespace _func514
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetName", typeid(void (CrewMember::*)(TextString *, bool )), "5589e557565383ec3c8b5d088b750c8b7d108d830c020000", argdata, 3, 6, &func);
}

void CrewMember::SetName(TextString *name, bool force)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, TextString *name_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func514::func;
	return execfunc(this, name, force);
}

namespace _func515
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetName", typeid(std::string (CrewMember::*)()), "5589e55383ec148b450c8b5d0880b80802000000", argdata, 2, 18, &func);
}

std::string CrewMember::GetName()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func515::func;
	return execfunc(this);
}

namespace _func516
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(void (CrewMember::*)(CrewTarget *, bool )), "57565383ec108b5c24208b7424248b7c24288b03", argdata, 3, 6, &func);
}

void CrewMember::SetCurrentTarget(CrewTarget *target, bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTarget *target_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func516::func;
	return execfunc(this, target, unk);
}

namespace _func517
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(bool (CrewMember::*)()), "5589e557565383ec5c8b7d088b4764", argdata, 1, 2, &func);
}

bool CrewMember::GetNewGoal()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func517::func;
	return execfunc(this);
}

namespace _func518
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), "5589e557565383ec7c8b5d088b7514f30f108300050000", argdata, 4, 2, &func);
}

bool CrewMember::MoveToRoom(int roomId, int slotId, bool forceMove)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool forceMove_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func518::func;
	return execfunc(this, roomId, slotId, forceMove);
}

namespace _func519
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMindControl", typeid(void (CrewMember::*)(bool )), "5589e5565383ec308b5d088b750c", argdata, 2, 6, &func);
}

void CrewMember::SetMindControl(bool controlled)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool controlled_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func519::func;
	return execfunc(this, controlled);
}

namespace _func520
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::RestorePosition", typeid(bool (CrewMember::*)()), "5589e557565383ec7c8b5d088b038bbbf40400008bb3f0040000", argdata, 1, 2, &func);
}

bool CrewMember::RestorePosition()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func520::func;
	return execfunc(this);
}

namespace _func521
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int )), "8b542404f30f1005????????f30f2a4c2408f30f594214f30f105208", argdata, 3, 2, &func);
}

bool CrewMember::ContainsPoint(int x, int y)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func521::func;
	return execfunc(this, x, y);
}

namespace _func522
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), "5383ec188b5c24208b03891c24ff5078", argdata, 2, 6, &func);
}

void CrewMember::SetMedbay(float health)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func522::func;
	return execfunc(this, health);
}

namespace _func523
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(void (CrewMember::*)()), ".5383ec188b4424208b989c000000c7433806000000", argdata, 1, 6, &func);
}

void CrewMember::StartTeleport()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func523::func;
	return execfunc(this);
}

namespace _func524
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(void (CrewMember::*)()), ".5383ec188b4424208b989c000000c7433806000000", argdata, 1, 6, &func);
}

void CrewMember::StartTeleportArrive()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func524::func;
	return execfunc(this);
}

namespace _func525
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::InsideRoom", typeid(bool (CrewMember::*)(int )), "8b4424048b5424083950780f94??", argdata, 2, 2, &func);
}

bool CrewMember::InsideRoom(int roomId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func525::func;
	return execfunc(this, roomId);
}

namespace _func526
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetUniqueRepairing", typeid(std::string (CrewMember::*)()), ".5383ec288b5c24308d44241f89442408", argdata, 2, 18, &func);
}

std::string CrewMember::GetUniqueRepairing()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func526::func;
	return execfunc(this);
}

namespace _func527
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::destructor", typeid(void (CrewMemberFactory::*)()), "565383ec148b7424208b4e108b560c", argdata, 1, 6, &func);
}

void CrewMemberFactory::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func527::func;
	return execfunc(this);
}

namespace _func528
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::Restart", typeid(void (CrewMemberFactory::*)()), "565383ec148b5c24208b430c8b5310", argdata, 1, 6, &func);
}

void CrewMemberFactory::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func528::func;
	return execfunc(this);
}

namespace _func529
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CountCloneReadyCrew", typeid(int (CrewMemberFactory::*)(bool )), "5557565383ec1c8b6c24300fb67c2434", argdata, 2, 2, &func);
}

int CrewMemberFactory::CountCloneReadyCrew(bool player)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func529::func;
	return execfunc(this, player);
}

namespace _func530
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewPortraitList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int )), "5557565331db83ec2c8b7424408b6c24448b560c8b4610", argdata, 3, 6, &func);
}

void CrewMemberFactory::GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int teamId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func530::func;
	return execfunc(this, vec, teamId);
}

namespace _func531
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int , bool )), "5557565331db83ec2c8b7424400fb644244c8b6c24488b560c", argdata, 4, 6, &func);
}

void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int unk_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func531::func;
	return execfunc(this, vec, unk, unk2);
}

namespace _func532
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetPlayerCrewCount", typeid(int (CrewMemberFactory::*)()), ".8b4424048b00", argdata, 1, 2, &func);
}

int CrewMemberFactory::GetPlayerCrewCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func532::func;
	return execfunc(this);
}

namespace _func533
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCloneCount", typeid(int (CrewMemberFactory::*)()), ".8b4424048b4008", argdata, 1, 2, &func);
}

int CrewMemberFactory::GetEnemyCloneCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func533::func;
	return execfunc(this);
}

namespace _func534
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewCount", typeid(int (CrewMemberFactory::*)(bool )), "8b542404807c2408008b42040f4402", argdata, 2, 2, &func);
}

int CrewMemberFactory::GetCrewCount(bool enemy)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func534::func;
	return execfunc(this, enemy);
}

namespace _func535
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetEnemyCrewCount", typeid(int (CrewMemberFactory::*)()), ".8b4424048b4004", argdata, 1, 2, &func);
}

int CrewMemberFactory::GetEnemyCrewCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func535::func;
	return execfunc(this);
}

namespace _func536
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(const std::string &)), ".5383ec188b5c2420c7442404????????891c24", argdata, 1, 2, &func);
}

bool CrewMemberFactory::IsRace(const std::string &species)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &species_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func536::func;
	return execfunc(species);
}

namespace _func537
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBoarderDrone", typeid(BoarderDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), "5557565383ec4c8b442468c7442404????????", argdata, 3, 2, &func);
}

BoarderDrone *CrewMemberFactory::CreateBoarderDrone(int shipId, const DroneBlueprint *bp)
{
	typedef BoarderDrone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func537::func;
	return execfunc(this, shipId, bp);
}

namespace _func538
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateBattleDrone", typeid(BattleDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), "5557565383ec4cc70424a40600008b7424608d7c2434", argdata, 3, 2, &func);
}

BattleDrone *CrewMemberFactory::CreateBattleDrone(int shipId, const DroneBlueprint *bp)
{
	typedef BattleDrone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func538::func;
	return execfunc(this, shipId, bp);
}

namespace _func539
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCloneReadyList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, bool )), "5589e557565383ec3c0fb645108b7d08", argdata, 3, 6, &func);
}

void CrewMemberFactory::GetCloneReadyList(std::vector<CrewMember*> &vec, bool player)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> &vec_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func539::func;
	return execfunc(this, vec, player);
}

namespace _func540
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateRepairDrone", typeid(RepairDrone *(CrewMemberFactory::*)(int , const DroneBlueprint *)), "5557565383ec4c8d4424308904248d5c2438c744240800000000", argdata, 3, 2, &func);
}

RepairDrone *CrewMemberFactory::CreateRepairDrone(int shipId, const DroneBlueprint *bp)
{
	typedef RepairDrone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, int shipId_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func540::func;
	return execfunc(this, shipId, bp);
}

namespace _func541
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetRandomFriendlyName", typeid(std::pair<std::string, bool> (CrewMemberFactory::*)(const std::string &)), "5589e557565383ec4c8b750c??????00000000", argdata, 3, 18, &func);
}

std::pair<std::string, bool> CrewMemberFactory::GetRandomFriendlyName(const std::string &race)
{
	typedef std::pair<std::string, bool> __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, const std::string &race_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func541::func;
	return execfunc(this, race);
}

namespace _func542
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewNames", typeid(std::vector<std::string> (CrewMemberFactory::*)()), "5589e557565331db83ec3c8b750c8b45088b4e10", argdata, 2, 18, &func);
}

std::vector<std::string> CrewMemberFactory::GetCrewNames()
{
	typedef std::vector<std::string> __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func542::func;
	return execfunc(this);
}

namespace _func543
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::OnLoop", typeid(void (CrewMemberFactory::*)()), "5589e557565381ecbc0000008b4508??????00000000", argdata, 1, 6, &func);
}

void CrewMemberFactory::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func543::func;
	return execfunc(this);
}

namespace _func544
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::RemoveExcessCrew", typeid(void (CrewMemberFactory::*)()), "5557565331db83ec1c8b7424308b460c8b5610", argdata, 1, 6, &func);
}

void CrewMemberFactory::RemoveExcessCrew()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func544::func;
	return execfunc(this);
}

namespace _func545
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::CreateCrewMember", typeid(CrewMember *(CrewMemberFactory::*)(CrewBlueprint *, int , bool )), "5589e557565381ecdc0000008b4514c7442404????????", argdata, 4, 2, &func);
}

CrewMember *CrewMemberFactory::CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, CrewBlueprint *bp_arg, int shipId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func545::func;
	return execfunc(this, bp, shipId, intruder);
}

CrewMemberFactory *Global_CrewMemberFactory_Factory;

namespace _var546
{
    static VariableDefinition varObj("Global_CrewMemberFactory_Factory", "!c70424(???????\?)e8????????29c6", &Global_CrewMemberFactory_Factory);
}

namespace _func547
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewStoreBox::CanHold", typeid(bool (CrewStoreBox::*)()), "83ec1c8b4424208b90c00000", argdata, 1, 2, &func);
}

bool CrewStoreBox::CanHold()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func547::func;
	return execfunc(this);
}

namespace _func548
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewStoreBox::constructor", typeid(void (CrewStoreBox::*)(ShipManager *, int , const std::string &)), ".5589e557565381ecdc0000008b5d088d8553ffffff", argdata, 4, 6, &func);
}

void CrewStoreBox::constructor(ShipManager *ship, int worldLevel, const std::string &type)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg, ShipManager *ship_arg, int worldLevel_arg, const std::string &type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func548::func;
	return execfunc(this, ship, worldLevel, type);
}

namespace _func549
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewStoreBox::Purchase", typeid(void (CrewStoreBox::*)()), ".5557565331db81eccc0000008bac24e0000000892c24", argdata, 1, 6, &func);
}

void CrewStoreBox::Purchase()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func549::func;
	return execfunc(this);
}

namespace _func550
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewStoreBox::MouseMove", typeid(void (CrewStoreBox::*)(int , int )), ".5589e5565383ec208b45108b5d08c744240c00000000894424088b450c894424048d4310890424e8????f6ff807b5100", argdata, 3, 6, &func);
}

void CrewStoreBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(CrewStoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func550::func;
	return execfunc(this, mX, mY);
}

namespace _func551
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("DamageMessage::constructor", typeid(void (DamageMessage::*)(float , Pointf , DamageMessage::MessageType )), "565383ec748b8c24900000008b9c24800000008b8424880000008b94248c000000", argdata, 4, 6, &func);
}

void DamageMessage::constructor(float length, Pointf pos, DamageMessage::MessageType type)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DamageMessage *this_arg, float length_arg, Pointf pos_arg, DamageMessage::MessageType type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func551::func;
	return execfunc(this, length, pos, type);
}

namespace _func552
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("DamageMessage::constructor2", typeid(void (DamageMessage::*)(float , int , Pointf , bool )), "5557565381ecec0100008b8c24140200008bac24000200008b84240c0200008b942410020000f30f10842404020000", argdata, 5, 6, &func);
}

void DamageMessage::constructor2(float length, int amount, Pointf pos, bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DamageMessage *this_arg, float length_arg, int amount_arg, Pointf pos_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func552::func;
	return execfunc(this, length, amount, pos, unk);
}

namespace _func553
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::ValidTargetObject", typeid(bool (DefenseDrone::*)(Targetable *)), "565383ec148b5c24248b74242085db74??8b4304", argdata, 2, 2, &func);
}

bool DefenseDrone::ValidTargetObject(Targetable *target)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func553::func;
	return execfunc(this, target);
}

namespace _func554
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::PickTarget", typeid(void (DefenseDrone::*)()), "5589e5565383ec608b5d0880bbdd01000000", argdata, 1, 6, &func);
}

void DefenseDrone::PickTarget()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func554::func;
	return execfunc(this);
}

namespace _func555
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::SetWeaponTarget", typeid(void (DefenseDrone::*)(Targetable *)), "5589e557565383ec1c8b5d088b750c8b03", argdata, 2, 6, &func);
}

void DefenseDrone::SetWeaponTarget(Targetable *target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func555::func;
	return execfunc(this, target);
}

namespace _func556
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::GetTooltip", typeid(std::string (DefenseDrone::*)()), "5589e557565383ec3c8b7d0c8d5de4", argdata, 2, 18, &func);
}

std::string DefenseDrone::GetTooltip()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func556::func;
	return execfunc(this);
}

namespace _func557
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DefenseDrone::OnLoop", typeid(void (DefenseDrone::*)()), "5589e5565383ec408b5d0889", argdata, 1, 6, &func);
}

void DefenseDrone::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func557::func;
	return execfunc(this);
}

namespace _func558
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Description::copy_assign_2", typeid(Description &(Description::*)(Description &)), "565383ec148b5c24208b742424891c2489742404e8????????0fb646048843048d4608894424048d4308890424e8????????0fb6460c88430c8d4610894424048d4310890424e8????????0fb646148843148b46188943188b461c89431c8b46208943208b46248943240fb646288843288d462c83c634894424048d432c890424", argdata, 2, 2, &func);
}

Description &Description::copy_assign_2(Description &other)
{
	typedef Description &__attribute__((cdecl)) (*custom_arg_funcptr_t)(Description *this_arg, Description &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func558::func;
	return execfunc(this, other);
}

namespace _func559
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Description::copy_assign_1", typeid(Description &(Description::*)(const Description &)), ".565383ec148b5c24208b742424891c2489742404e8????????0fb646048843048d4608894424048d4308890424e8????????0fb6460c88430c8d4610894424048d4310890424e8????????0fb646148843148b46188943188b461c89431c8b46208943208b46248943240fb646288843288d462c83c634894424048d432c890424", argdata, 2, 2, &func);
}

Description &Description::copy_assign_1(const Description &other)
{
	typedef Description &__attribute__((cdecl)) (*custom_arg_funcptr_t)(Description *this_arg, const Description &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func559::func;
	return execfunc(this, other);
}

namespace _func560
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Description::destructor", typeid(void (Description::*)()), "565383ec248b5c24308b43348d50f4", argdata, 1, 6, &func);
}

void Description::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Description *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func560::func;
	return execfunc(this);
}

namespace _func561
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Door::GetPosition", typeid(Point (Door::*)()), "5383ec288b4424348b5c24308b90cc010000", argdata, 2, 18, &func);
}

Point Door::GetPosition()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func561::func;
	return execfunc(this);
}

namespace _func562
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Door::ApplyDamage", typeid(bool (Door::*)(float )), ".5383ec188b5c242080bb7001000000", argdata, 2, 2, &func);
}

bool Door::ApplyDamage(float amount)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func562::func;
	return execfunc(this, amount);
}

namespace _func563
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Door::SaveState", typeid(void (Door::*)(int )), ".5589e5565389ce83e4f083ec108b????8b81d0010000", argdata, 2, 6, &func);
}

void Door::SaveState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func563::func;
	return execfunc(this, fd);
}

namespace _func564
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Door::LoadState", typeid(void (Door::*)(int )), ".578d????0883e4f0ff????5589e557565389cb83ec1c8b??8934??e8????????8934??", argdata, 2, 6, &func);
}

void Door::LoadState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func564::func;
	return execfunc(this, fd);
}

namespace _func565
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Door::FakeOpen", typeid(void (Door::*)()), ".565383ec148b5c242083bb8c00000004c6432001c783a001000000000000", argdata, 1, 6, &func);
}

void Door::FakeOpen()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func565::func;
	return execfunc(this);
}

namespace _func566
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), ".565383ec148b5c24200fb64318c6432000", argdata, 1, 6, &func);
}

void Door::FakeClose()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func566::func;
	return execfunc(this);
}

namespace _func567
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Door::IsSealed", typeid(bool (Door::*)(int )), ".8b5424048b82c40100008b4a0485c0", argdata, 2, 2, &func);
}

bool Door::IsSealed(int shipId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func567::func;
	return execfunc(this, shipId);
}

namespace _func568
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Door::OnLoop", typeid(void (Door::*)()), "!.565383ec148b5c24208b83c4010000", argdata, 1, 6, &func);
}

void Door::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func568::func;
	return execfunc(this);
}

namespace _func569
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DoorBox::constructor", typeid(void (DoorBox::*)(Point , ShipSystem *, ShipManager *)), "5557565383ec5c8b44247c8d74242c8b5c24708d6c242a8b542478", argdata, 4, 6, &func);
}

void DoorBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DoorBox *this_arg, Point pos_arg, ShipSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func569::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func570
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneBlueprint::RenderIcon", typeid(void (DroneBlueprint::*)(float )), "5589e557565381ecfc0000008b5d08e8", argdata, 2, 6, &func);
}

void DroneBlueprint::RenderIcon(float scale)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneBlueprint *this_arg, float scale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func570::func;
	return execfunc(this, scale);
}

namespace _func571
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("DroneControl::DO_NOT_HOOK", typeid(void (DroneControl::*)()), "!565383ec148b4424208b5c24248b7424288b400c890424", argdata, 0, 4, &func);
}

namespace _func572
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneControl::HolderLabel", typeid(TextString (DroneControl::*)()), ".565383ec248b5c24308d44241a8d74241c89442408", argdata, 2, 18, &func);
}

TextString DroneControl::HolderLabel()
{
	typedef TextString __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func572::func;
	return execfunc(this);
}

namespace _func573
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneControl::ArmamentHotkey", typeid(SDLKey (DroneControl::*)(unsigned int )), ".5557565381ec0c0100008d7424748934248d7c2448", argdata, 2, 2, &func);
}

SDLKey DroneControl::ArmamentHotkey(unsigned int i)
{
	typedef SDLKey __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func573::func;
	return execfunc(this, i);
}

namespace _func574
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneControl::SelectArmament", typeid(void (DroneControl::*)(unsigned int )), ".5589e557565383ec4c8b????8b5310", argdata, 2, 6, &func);
}

void DroneControl::SelectArmament(unsigned int i)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func574::func;
	return execfunc(this, i);
}

namespace _func575
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneControl::OnLoop", typeid(void (DroneControl::*)()), ".5589e557565383ec2c8b5d08c744240404000000", argdata, 1, 6, &func);
}

void DroneControl::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func575::func;
	return execfunc(this);
}

namespace _func576
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneStoreBox::constructor", typeid(void (DroneStoreBox::*)(ShipManager *, Equipment *, const DroneBlueprint *)), "5557565383ec2c8d44241a8b5c24408d7c241c8b74244c89442408c7442404????????893c24e8????????8b442448897c2404891c248944240c", argdata, 4, 6, &func);
}

void DroneStoreBox::constructor(ShipManager *ship, Equipment *equip, const DroneBlueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneStoreBox *this_arg, ShipManager *ship_arg, Equipment *equip_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func576::func;
	return execfunc(this, ship, equip, bp);
}

namespace _func577
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::RemoveDrone", typeid(Drone *(DroneSystem::*)(int )), "5731c0565383ec108b4c24248b5c242085c9", argdata, 2, 2, &func);
}

Drone *DroneSystem::RemoveDrone(int slot)
{
	typedef Drone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneSystem *this_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func577::func;
	return execfunc(this, slot);
}

namespace _func578
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneSystem::Jump", typeid(void (DroneSystem::*)()), ".554889e54156534989fe", argdata, 1, 6, &func);
}

void DroneSystem::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func578::func;
	return execfunc(this);
}

namespace _func579
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneSystem::UpdateBonusPower", typeid(void (DroneSystem::*)()), "555731ff565383ec2c8b6c24408b85480100008b959c010000", argdata, 1, 6, &func);
}

void DroneSystem::UpdateBonusPower()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func579::func;
	return execfunc(this);
}

namespace _func580
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneSystem::SetBonusPower", typeid(void (DroneSystem::*)(int , int )), ".565383ec148b5c24208b742424891c24e8????????39f00f4ef0", argdata, 3, 6, &func);
}

void DroneSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func580::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func581
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneSystem::OnLoop", typeid(void (DroneSystem::*)()), "5557565383ec3c8b6c2450892c24e8????????892c24", argdata, 1, 6, &func);
}

void DroneSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func581::func;
	return execfunc(this);
}

namespace _func582
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101};
	static FunctionDefinition funcObj("DroneSystem::DePowerDrone", typeid(bool (DroneSystem::*)(Drone *, bool )), "55575689d65389c383ec1c84c9", argdata, 3, 2, &func);
}

bool DroneSystem::DePowerDrone(Drone *drone, bool unk)
{
	typedef bool __attribute__((regparm(3))) (*custom_arg_funcptr_t)(DroneSystem *this_arg, Drone *drone_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func582::func;
	return execfunc(this, drone, unk);
}

namespace _func583
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneSystem::StringToDrone", typeid(int (*)(std::string &)), ".5383ec188b5c2420c7442404", argdata, 1, 2, &func);
}

int DroneSystem::StringToDrone(std::string &name)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func583::func;
	return execfunc(name);
}

namespace _func584
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), "5589e557565381ecac0000008b7d08893c24", argdata, 1, 6, &func);
}

void DropBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func584::func;
	return execfunc(this);
}

namespace _func585
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DropBox::GetHeight", typeid(int (DropBox::*)()), "8b5424048b4a0c89c885c0", argdata, 1, 2, &func);
}

int DropBox::GetHeight()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func585::func;
	return execfunc(this);
}

namespace _func586
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DropBox::Contains", typeid(bool (DropBox::*)(int , int )), "5631c0538b54240c8b4c", argdata, 3, 2, &func);
}

bool DropBox::Contains(int x, int y)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(DropBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func586::func;
	return execfunc(this, x, y);
}

namespace _func587
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DropBox::GetBodySpaceOffset", typeid(int (DropBox::*)()), "5589e557565383ec4c8b5d088b4348", argdata, 1, 2, &func);
}

int DropBox::GetBodySpaceOffset()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func587::func;
	return execfunc(this);
}

namespace _func588
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DropBox::OnInit", typeid(void (DropBox::*)(Point , bool , TextString *, TextString *, int , TextString *)), "5557565383ec3c8b44245c8d", argdata, 7, 6, &func);
}

void DropBox::OnInit(Point p, bool isSellBox_, TextString *titleText_, TextString *bodyText_, int bodySpace_, TextString *lowerText_)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DropBox *this_arg, Point p_arg, bool isSellBox__arg, TextString *titleText__arg, TextString *bodyText__arg, int bodySpace__arg, TextString *lowerText__arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func588::func;
	return execfunc(this, p, isSellBox_, titleText_, bodyText_, bodySpace_, lowerText_);
}

namespace _func589
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EnergyAlien::OnLoop", typeid(void (EnergyAlien::*)()), "5383ec188b5c2420891c24e8????????8b839c000000", argdata, 1, 6, &func);
}

void EnergyAlien::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EnergyAlien *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func589::func;
	return execfunc(this);
}

namespace _func590
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EnergyAlien::GetRoomDamage", typeid(Damage (EnergyAlien::*)()), "8b5424088b44240480ba3d05000000", argdata, 2, 18, &func);
}

Damage EnergyAlien::GetRoomDamage()
{
	typedef Damage __attribute__((cdecl)) (*custom_arg_funcptr_t)(EnergyAlien *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func590::func;
	return execfunc(this);
}

namespace _func591
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::Open", typeid(void (Equipment::*)()), "565331db83ec148b742420893424", argdata, 1, 6, &func);
}

void Equipment::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func591::func;
	return execfunc(this);
}

namespace _func592
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::Close", typeid(void (Equipment::*)()), "!.e97b660000908d76008dbc2700000000", argdata, 1, 6, &func);
}

void Equipment::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func592::func;
	return execfunc(this);
}

namespace _func593
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::OnInit", typeid(void (Equipment::*)(ShipManager *)), "5557565381ec8c0000008bac24a00000008bb5200100008b8d1c010000", argdata, 2, 6, &func);
}

void Equipment::OnInit(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func593::func;
	return execfunc(this, ship);
}

namespace _func594
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::OnLoop", typeid(void (Equipment::*)()), "55575631f65383ec2c8b5c24408b83140100002b8310010000", argdata, 1, 6, &func);
}

void Equipment::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func594::func;
	return execfunc(this);
}

namespace _func595
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseClick", typeid(void (Equipment::*)(int , int )), "5383ec188b4424288b5c242089442408", argdata, 3, 6, &func);
}

void Equipment::MouseClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func595::func;
	return execfunc(this, mX, mY);
}

namespace _func596
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseUp", typeid(void (Equipment::*)(int , int )), "565383ec548b5c246080bb3c01000000", argdata, 3, 6, &func);
}

void Equipment::MouseUp(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func596::func;
	return execfunc(this, mX, mY);
}

namespace _func597
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddWeapon", typeid(void (Equipment::*)(WeaponBlueprint *, bool , bool )), "5557565383ec4c8b44246c8b5c2460", argdata, 4, 6, &func);
}

void Equipment::AddWeapon(WeaponBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, WeaponBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func597::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func598
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddDrone", typeid(void (Equipment::*)(DroneBlueprint *, bool , bool )), "57565383ec30807c244c00", argdata, 4, 6, &func);
}

void Equipment::AddDrone(DroneBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, DroneBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func598::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func599
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddAugment", typeid(void (Equipment::*)(AugmentBlueprint *, bool , bool )), "5557565383ec4c8b7c24648d742430", argdata, 4, 6, &func);
}

void Equipment::AddAugment(AugmentBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, AugmentBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func599::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func600
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddToCargo", typeid(void (Equipment::*)(const std::string &)), "5557565383ec3c8b7424548d5c242c", argdata, 2, 6, &func);
}

void Equipment::AddToCargo(const std::string &name)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func600::func;
	return execfunc(this, name);
}

namespace _func601
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::GetCargoHold", typeid(std::vector<std::string> (Equipment::*)()), "5557565383ec1c8b7424348b7c2430", argdata, 2, 18, &func);
}

std::vector<std::string> Equipment::GetCargoHold()
{
	typedef std::vector<std::string> __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func601::func;
	return execfunc(this);
}

namespace _func602
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::IsCompletelyFull", typeid(bool (Equipment::*)(int )), "5557565331db83ec1c8b7424308b7c24348b", argdata, 2, 2, &func);
}

bool Equipment::IsCompletelyFull(int type)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func602::func;
	return execfunc(this, type);
}

namespace _func603
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::Jump", typeid(void (Equipment::*)()), "5383ec188b5c24208b8328010000", argdata, 1, 6, &func);
}

void Equipment::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func603::func;
	return execfunc(this);
}

namespace _func604
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::MouseMove", typeid(void (Equipment::*)(int , int )), "5557565381ec0c0100008bbc", argdata, 3, 6, &func);
}

void Equipment::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func604::func;
	return execfunc(this, mX, mY);
}

namespace _func605
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::OnRender", typeid(void (Equipment::*)()), "5589e557565381ec9c0000008b5d08e8", argdata, 1, 6, &func);
}

void Equipment::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func605::func;
	return execfunc(this);
}

namespace _func606
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Equipment::SetPosition", typeid(void (Equipment::*)(Point )), "5557565383ec7c8b9c24900000008b", argdata, 2, 6, &func);
}

void Equipment::SetPosition(Point p)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg, Point p_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func606::func;
	return execfunc(this, p);
}

namespace _func607
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::constructor", typeid(void (Equipment::*)()), "565383ec248b5c24308d74241f891c24e8????????8d4324", argdata, 1, 6, &func);
}

void Equipment::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func607::func;
	return execfunc(this);
}

namespace _func608
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Equipment::destructor", typeid(void (Equipment::*)()), "565383ec248b5c24308b83e8010000", argdata, 1, 6, &func);
}

void Equipment::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func608::func;
	return execfunc(this);
}

namespace _func609
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("EquipmentBox::SetPosition", typeid(void (EquipmentBox::*)(Point )), "8b4424048b4c24088b54240c894834", argdata, 2, 6, &func);
}

void EquipmentBox::SetPosition(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func609::func;
	return execfunc(this, pos);
}

namespace _func610
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::MouseMove", typeid(void (EquipmentBox::*)(int , int )), "538b44240831db8b54240c8b483c", argdata, 3, 6, &func);
}

void EquipmentBox::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func610::func;
	return execfunc(this, x, y);
}

namespace _func611
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::Restart", typeid(void (EquipmentBox::*)()), ".8b442404660fefc0f30f7f404c", argdata, 1, 6, &func);
}

void EquipmentBox::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func611::func;
	return execfunc(this);
}

namespace _func612
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("EquipmentBox::AddItem", typeid(void (EquipmentBox::*)(EquipmentBoxItem )), "8b4424048b54240889504c8b54240c", argdata, 2, 6, &func);
}

void EquipmentBox::AddItem(EquipmentBoxItem item)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, EquipmentBoxItem item_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func612::func;
	return execfunc(this, item);
}

namespace _func613
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldWeapon", typeid(bool (EquipmentBox::*)()), "8b5424048b424c85c074??85c0", argdata, 1, 2, &func);
}

bool EquipmentBox::CanHoldWeapon()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func613::func;
	return execfunc(this);
}

namespace _func614
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::CanHoldDrone", typeid(bool (EquipmentBox::*)()), "8b4424048b504c85d28b5050", argdata, 1, 2, &func);
}

bool EquipmentBox::CanHoldDrone()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func614::func;
	return execfunc(this);
}

namespace _func615
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::GetType", typeid(int (EquipmentBox::*)(bool )), "8b5424048b4c24088b424c85c0", argdata, 2, 2, &func);
}

int EquipmentBox::GetType(bool forcedEmpty)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool forcedEmpty_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func615::func;
	return execfunc(this, forcedEmpty);
}

namespace _func616
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::OnRender", typeid(void (EquipmentBox::*)(bool )), "57565383ec408b5c24508b742454", argdata, 2, 6, &func);
}

void EquipmentBox::OnRender(bool isEmpty)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool isEmpty_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func616::func;
	return execfunc(this, isEmpty);
}

namespace _func617
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::destructor", typeid(void (EquipmentBox::*)()), ".565383ec248b5c24308b431c", argdata, 1, 6, &func);
}

void EquipmentBox::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func617::func;
	return execfunc(this);
}

namespace _func618
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::UpdateBoxImage", typeid(void (EquipmentBox::*)(bool )), "5557565383ec6c8bb42484000000", argdata, 2, 6, &func);
}

void EquipmentBox::UpdateBoxImage(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func618::func;
	return execfunc(this, unk);
}

namespace _func619
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::RenderLabels", typeid(void (EquipmentBox::*)(bool )), "5589e557565383ec5c8b5d088b450c8d7dd8", argdata, 2, 6, &func);
}

void EquipmentBox::RenderLabels(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func619::func;
	return execfunc(this, unk);
}

namespace _func620
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::constructor", typeid(void (EquipmentBox::*)(Point , int )), "565383ec548b0d????????8b5c24608d74243c8b4424688b542464894b088b0d????????8943388943408b44246c", argdata, 3, 6, &func);
}

void EquipmentBox::constructor(Point pos, int slot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Point pos_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func620::func;
	return execfunc(this, pos, slot);
}

namespace _func621
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::GetItemValue", typeid(int (EquipmentBox::*)()), "8b5424048b424c85c074??8b401c", argdata, 1, 2, &func);
}

int EquipmentBox::GetItemValue()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func621::func;
	return execfunc(this);
}

namespace _func622
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::SetBlueprint", typeid(void (EquipmentBox::*)(InfoBox *, bool )), "5731c0565383ec208b5c24308b7424348b7c2438", argdata, 3, 6, &func);
}

void EquipmentBox::SetBlueprint(InfoBox *infoBox, bool detailedBox)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, InfoBox *infoBox_arg, bool detailedBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func622::func;
	return execfunc(this, infoBox, detailedBox);
}

namespace _func623
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::GetBlueprint", typeid(Blueprint *(EquipmentBox::*)()), "8b5424048b425085c0", argdata, 1, 2, &func);
}

Blueprint *EquipmentBox::GetBlueprint()
{
	typedef Blueprint *__attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func623::func;
	return execfunc(this);
}

namespace _func624
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::RenderIcon", typeid(void (EquipmentBox::*)()), "5383ec188b5c24208b434c85", argdata, 1, 6, &func);
}

void EquipmentBox::RenderIcon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func624::func;
	return execfunc(this);
}

namespace _func625
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::ForceHitBox", typeid(void (EquipmentBox::*)(Globals::Rect *)), "8b5424088b4424048b0a89483c", argdata, 2, 6, &func);
}

void EquipmentBox::ForceHitBox(Globals::Rect *newBox)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Globals::Rect *newBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func625::func;
	return execfunc(this, newBox);
}

namespace _func626
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetBaseEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool , int )), "5557565383ec1c8b4424408b5c24308b7424348b7c2438", argdata, 5, 2, &func);
}

LocationEvent *EventGenerator::GetBaseEvent(const std::string &name, int worldLevel, bool ignoreUnique, int seed)
{
	typedef LocationEvent *__attribute__((cdecl)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, bool ignoreUnique_arg, int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func626::func;
	return execfunc(this, name, worldLevel, ignoreUnique, seed);
}

namespace _func627
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::CreateEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool )), "5589e557565381ecdc0100008b45148b5d0c", argdata, 4, 2, &func);
}

LocationEvent *EventGenerator::CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique)
{
	typedef LocationEvent *__attribute__((cdecl)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, bool ignoreUnique_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func627::func;
	return execfunc(this, name, worldLevel, ignoreUnique);
}

namespace _func628
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetSpecificSector", typeid(SectorDescription (EventGenerator::*)(const std::string &)), "5589e557565381ecac0000008b75108b450c", argdata, 3, 18, &func);
}

SectorDescription EventGenerator::GetSpecificSector(const std::string &name)
{
	typedef SectorDescription __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func628::func;
	return execfunc(this, name);
}

namespace _func629
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetImageFromList", typeid(std::string (EventGenerator::*)(const std::string &)), "5589e557565383ec3c8b450c8b7d108b5d08", argdata, 3, 18, &func);
}

std::string EventGenerator::GetImageFromList(const std::string &listName)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func629::func;
	return execfunc(this, listName);
}

namespace _func630
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetSectorDescription", typeid(SectorDescription (EventGenerator::*)(const std::string &, int )), "5589e557565383ec5c8b45088b5d108d7dc4", argdata, 4, 18, &func);
}

SectorDescription EventGenerator::GetSectorDescription(const std::string &type, int level)
{
	typedef SectorDescription __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &type_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func630::func;
	return execfunc(this, type, level);
}

namespace _func631
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetShipEvent", typeid(ShipEvent (EventGenerator::*)(const std::string &)), "5589e557565383ec2c8b450c8b75108b5d08", argdata, 3, 18, &func);
}

ShipEvent EventGenerator::GetShipEvent(const std::string &event)
{
	typedef ShipEvent __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func631::func;
	return execfunc(this, event);
}

EventGenerator *Global_EventGenerator_Generator;

namespace _var632
{
    static VariableDefinition varObj("Global_EventGenerator_Generator", "!c74424080000000089742404c70424(???????\?)e8????????8b54242c8d4af4", &Global_EventGenerator_Generator);
}

namespace _func633
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), "8b5424088b44240485d278??8b480c", argdata, 2, 6, &func);
}

void EventSystem::AddEvent(int id)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func633::func;
	return execfunc(this, id);
}

namespace _func634
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventSystem::PollEvent", typeid(bool (EventSystem::*)(int )), "538b4c240c8b44240885c9", argdata, 2, 2, &func);
}

bool EventSystem::PollEvent(int id)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func634::func;
	return execfunc(this, id);
}

EventSystem *Global_EventSystem_EventManager;

namespace _var635
{
    static VariableDefinition varObj("Global_EventSystem_EventManager", "!c74424040c000000c70424(???????\?)e8????????31c0", &Global_EventSystem_EventManager);
}

namespace _func636
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "5557565383ec4c8d5c243c8d7c2420895c24088d6c2430", argdata, 4, 18, &func);
}

RandomAmount EventsParser::PullMinMax(rapidxml::xml_node<char> *node, const std::string &name)
{
	typedef RandomAmount __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func636::func;
	return execfunc(this, node, name);
}

namespace _func637
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(std::string (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "55ba????????89e557565381ec3c0100008b4510", argdata, 4, 18, &func);
}

std::string EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &eventName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func637::func;
	return execfunc(this, node, eventName);
}

namespace _func638
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessShipEvent", typeid(ShipTemplate (EventsParser::*)(rapidxml::xml_node<char> *)), "5589e557565381ec5c0200008d8508feffff89442408", argdata, 3, 18, &func);
}

ShipTemplate EventsParser::ProcessShipEvent(rapidxml::xml_node<char> *node)
{
	typedef ShipTemplate __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func638::func;
	return execfunc(this, node);
}

namespace _func639
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessModifyItem", typeid(ResourcesTemplate (EventsParser::*)(ResourcesTemplate &, rapidxml::xml_node<char> *, const std::string &)), "5589e557565383ec5c8b45188d7de48b5d10", argdata, 5, 18, &func);
}

ResourcesTemplate EventsParser::ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &unk)
{
	typedef ResourcesTemplate __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, ResourcesTemplate &resources_arg, rapidxml::xml_node<char> *node_arg, const std::string &unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func639::func;
	return execfunc(this, resources, node, unk);
}

namespace _func640
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("EventsParser::AddAllEvents", typeid(void (EventsParser::*)()), "5557565383ec3c8d5c241c8d6c241ac744240800000000", argdata, 1, 6, &func);
}

void EventsParser::AddAllEvents()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func640::func;
	return execfunc(this);
}

namespace _func641
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::AddEvents", typeid(void (EventsParser::*)(EventGenerator &, char *, const std::string &)), "5589e557565381ecac0001008b45088b7510", argdata, 4, 6, &func);
}

void EventsParser::AddEvents(EventGenerator &generator, char *file, const std::string &fileName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, EventGenerator &generator_arg, char *file_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func641::func;
	return execfunc(this, generator, file, fileName);
}

namespace _func642
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEventList", typeid(std::vector<std::string> (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "55ba????????89e557565383ec2c8b4508c70000000000c7400400000000c74008000000008b451083c018e8????????85c089c60f84????????8db6000000008b4514", argdata, 4, 18, &func);
}

std::vector<std::string> EventsParser::ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName)
{
	typedef std::vector<std::string> __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func642::func;
	return execfunc(this, node, listName);
}

namespace _func643
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessChoice", typeid(void (EventsParser::*)(EventTemplate *, rapidxml::xml_node<char> *, std::string &)), "5589e557565383ec7c8d", argdata, 4, 6, &func);
}

void EventsParser::ProcessChoice(EventTemplate *event, rapidxml::xml_node<char> *node, std::string &eventName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, EventTemplate *event_arg, rapidxml::xml_node<char> *node_arg, std::string &eventName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func643::func;
	return execfunc(this, event, node, eventName);
}

namespace _func644
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessBaseNode", typeid(void (EventsParser::*)(rapidxml::xml_node<char> *, EventGenerator &)), "5589e557bf????????565381ecdc0000008b450c", argdata, 3, 6, &func);
}

void EventsParser::ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, EventGenerator &generator_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func644::func;
	return execfunc(this, node, generator);
}

EventsParser *Global_EventsParser_Parser;

namespace _var645
{
    static VariableDefinition varObj("Global_EventsParser_Parser", "!c70424(???????\?)89442408898554ffffff", &Global_EventsParser_Parser);
}

namespace _func646
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ExplosionAnimation::OnInit", typeid(void (ExplosionAnimation::*)(rapidxml::xml_node<char> *, const std::string &, Point )), "5557565381ec6c0100008b84248c0100008bb424800100008bac2484010000", argdata, 4, 6, &func);
}

void ExplosionAnimation::OnInit(rapidxml::xml_node<char> *node, const std::string &name, Point glowOffset)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg, Point glowOffset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func646::func;
	return execfunc(this, node, name, glowOffset);
}

namespace _func647
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x7ff, 0x1ff};
	static FunctionDefinition funcObj("ExplosionAnimation::OnRender", typeid(void (ExplosionAnimation::*)(Globals::Rect *, ImageDesc , GL_Primitive *)), "5557565383ec5c8b7c????8b74????", argdata, 4, 6, &func);
}

void ExplosionAnimation::OnRender(Globals::Rect *shipRect, ImageDesc shipImage, GL_Primitive *shipImagePrimitive)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg, Globals::Rect *shipRect_arg, ImageDesc shipImage_arg, GL_Primitive *shipImagePrimitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func647::func;
	return execfunc(this, shipRect, shipImage, shipImagePrimitive);
}

namespace _func648
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ExplosionAnimation::LoadGibs", typeid(void (ExplosionAnimation::*)()), "8b51308b4134", argdata, 1, 6, &func);
}

void ExplosionAnimation::LoadGibs()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ExplosionAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func648::func;
	return execfunc(this);
}

namespace _func649
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FTLButton::OnRender", typeid(void (FTLButton::*)()), "5589e557565381ec6c0100008b5d08c744240401000000", argdata, 1, 6, &func);
}

void FTLButton::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FTLButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func649::func;
	return execfunc(this);
}

namespace _func650
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FTLButton::MouseMove", typeid(void (FTLButton::*)(int , int , bool )), ".55575631f65383ec1c8b5c24308b5424348b4c24388b7c243c8b430c39c2", argdata, 4, 6, &func);
}

void FTLButton::MouseMove(int mX, int mY, bool silent)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FTLButton *this_arg, int mX_arg, int mY_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func650::func;
	return execfunc(this, mX, mY, silent);
}

namespace _func651
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::deleteFile", typeid(void (*)(const std::string &)), "5383ec188b5c2420c7442404000000008b03890424e8????????85c074??", argdata, 1, 6, &func);
}

void FileHelper::deleteFile(const std::string &fileName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func651::func;
	return execfunc(fileName);
}

namespace _func652
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getResourceFile", typeid(std::string (*)()), "565383ec248b5c24308d74241ce8????????", argdata, 1, 18, &func);
}

std::string FileHelper::getResourceFile()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func652::func;
	return execfunc();
}

namespace _func653
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getUserFolder", typeid(std::string (*)()), "5383ec288b5c2430e8????????", argdata, 1, 18, &func);
}

std::string FileHelper::getUserFolder()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func653::func;
	return execfunc();
}

namespace _func654
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getSaveFile", typeid(std::string (*)()), "57565383ec208b5c24308d74241ce8????????", argdata, 1, 18, &func);
}

std::string FileHelper::getSaveFile()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func654::func;
	return execfunc();
}

namespace _func655
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::initFileHelper", typeid(void (*)()), "565383ec34c605????????018d5c241f", argdata, 0, 6, &func);
}

void FileHelper::initFileHelper()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func655::func;
	return execfunc();
}

namespace _func656
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::fileExists", typeid(bool (*)(const std::string &)), "83ec1c8b442420c7442404000000008b00", argdata, 1, 2, &func);
}

bool FileHelper::fileExists(const std::string &fileName)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func656::func;
	return execfunc(fileName);
}

namespace _func657
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::renameFile", typeid(void (*)(const std::string &, const std::string &)), "8b4424088b00894424088b442404", argdata, 2, 6, &func);
}

void FileHelper::renameFile(const std::string &fileName, const std::string &newName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg, const std::string &newName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func657::func;
	return execfunc(fileName, newName);
}

namespace _func658
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::createBinaryFile", typeid(int (*)(const std::string &)), "5383ec188b5c2420c7442404000000008b03890424e8????????85c075??", argdata, 1, 2, &func);
}

int FileHelper::createBinaryFile(const std::string &fileName)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func658::func;
	return execfunc(fileName);
}

namespace _func659
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::saveFileExists", typeid(bool (*)()), ".5557565383ec3c8d442420894424088d442410", argdata, 0, 2, &func);
}

bool FileHelper::saveFileExists()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func659::func;
	return execfunc();
}

namespace _func660
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readSaveFile", typeid(int (*)()), ".5557565383ec3c8d442420894424088d442410", argdata, 0, 2, &func);
}

int FileHelper::readSaveFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func660::func;
	return execfunc();
}

namespace _func661
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::readStatsFile", typeid(int (*)()), ".5557565383ec3c8d442420894424088d442410", argdata, 0, 2, &func);
}

int FileHelper::readStatsFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func661::func;
	return execfunc();
}

namespace _func662
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createSaveFile", typeid(int (*)()), ".a1????????a3????????b8????????", argdata, 0, 2, &func);
}

int FileHelper::createSaveFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func662::func;
	return execfunc();
}

namespace _func663
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::createStatsFile", typeid(int (*)()), ".a1????????a3????????b8????????", argdata, 0, 2, &func);
}

int FileHelper::createStatsFile()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func663::func;
	return execfunc();
}

namespace _func664
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteSaveFile", typeid(void (*)()), "5383ec18c70424????????e8????????89c3", argdata, 0, 6, &func);
}

void FileHelper::deleteSaveFile()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func664::func;
	return execfunc();
}

namespace _func665
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::deleteAllSaveFiles", typeid(void (*)()), "5557565383ec2ce8????????8d74241c8d7c241b", argdata, 0, 6, &func);
}

void FileHelper::deleteAllSaveFiles()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func665::func;
	return execfunc();
}

namespace _func666
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getPosition", typeid(int (*)(int )), ".a1????????c3", argdata, 1, 2, &func);
}

int FileHelper::getPosition(int file)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func666::func;
	return execfunc(file);
}

namespace _func667
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBinaryFile", typeid(int (*)(const std::string &)), "5383ec188b442420c744240400000000", argdata, 1, 2, &func);
}

int FileHelper::readBinaryFile(const std::string &fileName)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func667::func;
	return execfunc(fileName);
}

namespace _func668
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeFloat", typeid(bool (*)(int , float )), "5557565383ec2cf30f1005????????", argdata, 2, 2, &func);
}

bool FileHelper::writeFloat(int file, float data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, float data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func668::func;
	return execfunc(file, data);
}

namespace _func669
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeInt", typeid(bool (*)(int , int )), "5557565383ec2c8b542444803d????????00", argdata, 2, 2, &func);
}

bool FileHelper::writeInt(int file, int data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func669::func;
	return execfunc(file, data);
}

namespace _func670
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeData", typeid(bool (*)(int , void *, int )), "5557565383ec2c8b4424408b5c24483dfffeff7f", argdata, 3, 2, &func);
}

bool FileHelper::writeData(int file, void *data, int len)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, void *data_arg, int len_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func670::func;
	return execfunc(file, data, len);
}

namespace _func671
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeString", typeid(bool (*)(int , const std::string &)), "5557565383ec3c8b4424548b7424508b38", argdata, 2, 2, &func);
}

bool FileHelper::writeString(int file, const std::string &data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, const std::string &data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func671::func;
	return execfunc(file, data);
}

namespace _func672
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::closeBinaryFile", typeid(void (*)(int )), "5383ec188b4424203dfffeff7f", argdata, 1, 6, &func);
}

void FileHelper::closeBinaryFile(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func672::func;
	return execfunc(file);
}

namespace _func673
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readString", typeid(std::string (*)(int )), "5557565383ec3c8b5c24548d6c2420", argdata, 2, 18, &func);
}

std::string FileHelper::readString(int file)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func673::func;
	return execfunc(file);
}

namespace _func674
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readFloat", typeid(float (*)(int )), ".5557565383ec3c8b5c24508d7c242081fbfffeff7f", argdata, 1, 2, &func);
}

float FileHelper::readFloat(int file)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func674::func;
	return execfunc(file);
}

namespace _func675
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readInteger", typeid(int (*)(int )), ".5557565383ec3c8b5c24508d7c242081fbfffeff7f", argdata, 1, 2, &func);
}

int FileHelper::readInteger(int file)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func675::func;
	return execfunc(file);
}

namespace _func676
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::seekPosition", typeid(bool (*)(int , int )), "83ec1c8b442424c74424080000000089442404a3????????", argdata, 2, 2, &func);
}

bool FileHelper::seekPosition(int file, int pos)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func676::func;
	return execfunc(file, pos);
}

namespace _func677
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBuffer", typeid(char *(*)(int , int , bool )), "5557565383ec2c8b6c24488b5c24448b742440", argdata, 3, 2, &func);
}

char *FileHelper::readBuffer(int file, int len, bool nullTerminate)
{
	typedef char *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int len_arg, bool nullTerminate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func677::func;
	return execfunc(file, len, nullTerminate);
}

namespace _func678
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readData", typeid(void (*)(int , void *, int )), "5557565383ec1c8b5c24308b7c24348b74243881fb????????", argdata, 3, 6, &func);
}

void FileHelper::readData(int file, void *data, int len)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, void *data_arg, int len_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func678::func;
	return execfunc(file, data, len);
}

namespace _func679
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Fire::OnLoop", typeid(void (Fire::*)()), "565383ec148b5c242080bb5c01000000", argdata, 1, 6, &func);
}

void Fire::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Fire *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func679::func;
	return execfunc(this);
}

namespace _func680
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Fire::UpdateDeathTimer", typeid(void (Fire::*)(int )), ".565383ec148b5c24208b7424248b03891c24ff502884c0", argdata, 2, 6, &func);
}

void Fire::UpdateDeathTimer(int connectedFires)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Fire *this_arg, int connectedFires_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func680::func;
	return execfunc(this, connectedFires);
}

namespace _func681
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Fire::UpdateStartTimer", typeid(void (Fire::*)(int )), ".565383ec148b5c24208b7424248b03891c24ff502884c0", argdata, 2, 6, &func);
}

void Fire::UpdateStartTimer(int doorLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Fire *this_arg, int doorLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func681::func;
	return execfunc(this, doorLevel);
}

namespace _func682
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("FocusWindow::SetPosition", typeid(void (FocusWindow::*)(Point )), "8b4c24048b4424088b54240c89411489", argdata, 2, 6, &func);
}

void FocusWindow::SetPosition(Point p)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, Point p_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func682::func;
	return execfunc(this, p);
}

namespace _func683
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FocusWindow::Close", typeid(void (FocusWindow::*)()), ".8b442404c6400400c3", argdata, 1, 6, &func);
}

void FocusWindow::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FocusWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func683::func;
	return execfunc(this);
}

namespace _func684
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FocusWindow::Open", typeid(void (FocusWindow::*)()), ".8b442404c6400401c3", argdata, 1, 6, &func);
}

void FocusWindow::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FocusWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func684::func;
	return execfunc(this);
}

namespace _func685
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FocusWindow::MouseClick", typeid(void (FocusWindow::*)(int , int )), "8b44240480781000", argdata, 3, 6, &func);
}

void FocusWindow::MouseClick(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func685::func;
	return execfunc(this, x, y);
}

namespace _func686
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FocusWindow::MouseMove", typeid(void (FocusWindow::*)(int , int )), ".56538b44240c8b4c24108b7424148b500883faff", argdata, 3, 6, &func);
}

void FocusWindow::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func686::func;
	return execfunc(this, x, y);
}

namespace _func687
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FocusWindow::constructor", typeid(void (FocusWindow::*)()), "!.5383ec188b5c24208d430883", argdata, 1, 6, &func);
}

void FocusWindow::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(FocusWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func687::func;
	return execfunc(this);
}

namespace _func688
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GameOver::OpenText", typeid(void (GameOver::*)(const std::string &)), "5589e557565381ec2c0100008b7d088b450cc6470401", argdata, 2, 6, &func);
}

void GameOver::OpenText(const std::string &text)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GameOver *this_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func688::func;
	return execfunc(this, text);
}

namespace _func689
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("GameOver::OnRender", typeid(void (GameOver::*)()), "5589e557565381ec3c0100008b5d0880bb9000000000", argdata, 1, 6, &func);
}

void GameOver::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func689::func;
	return execfunc(this);
}

namespace _func690
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("GameOver::OnLoop", typeid(void (GameOver::*)()), "5557565383ec4cc70424????????8b742460e8????????", argdata, 1, 6, &func);
}

void GameOver::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func690::func;
	return execfunc(this);
}

namespace _func691
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void (GenericButton::*)(Point )), "5756538b4424108b5424148b4c24188b58048b700839da", argdata, 2, 6, &func);
}

void GenericButton::SetLocation(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GenericButton *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func691::func;
	return execfunc(this, pos);
}

namespace _func692
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::SetActive", typeid(void (GenericButton::*)(bool )), "8b5424088b44240484d2885040", argdata, 2, 6, &func);
}

void GenericButton::SetActive(bool active)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GenericButton *this_arg, bool active_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func692::func;
	return execfunc(this, active);
}

namespace _func693
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::MouseMove", typeid(void (GenericButton::*)(int , int , bool )), "5756538b4424108b5424148b5c24188b74241c", argdata, 4, 6, &func);
}

void GenericButton::MouseMove(int x, int y, bool silent)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GenericButton *this_arg, int x_arg, int y_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func693::func;
	return execfunc(this, x, y, silent);
}

namespace _func694
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("GenericButton::__DO_NOT_HOOK", typeid(void (GenericButton::*)()), "f3c36690669066906690669066906690", argdata, 0, 4, &func);
}

namespace _func695
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("GenericButton::OnClick", typeid(void (GenericButton::*)()), ".f3c36690669066906690669066906690", argdata, 1, 6, &func);
}

void GenericButton::OnClick()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GenericButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func695::func;
	return execfunc(this);
}

namespace _func696
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("GenericButton::OnRightClick", typeid(void (GenericButton::*)()), ".f3c36690669066906690669066906690", argdata, 1, 6, &func);
}

void GenericButton::OnRightClick()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GenericButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func696::func;
	return execfunc(this);
}

namespace _func697
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("GenericButton::ResetPrimitives", typeid(void (GenericButton::*)()), ".f3c36690669066906690669066906690", argdata, 1, 6, &func);
}

void GenericButton::ResetPrimitives()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GenericButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func697::func;
	return execfunc(this);
}

namespace _func698
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_text_width", typeid(float (*)(freetype::font_data &, const char *, float )), "5557565383ec4c8b4c24608b6c246485c9", argdata, 3, 2, &func);
}

float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(freetype::font_data &fontData_arg, const char *str_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func698::func;
	return execfunc(fontData, str, size);
}

namespace _func699
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("random32", typeid(int (*)()), "6905????????????????690d????????????????01c1b82d7f954cf725????????01ca83c00183d200a3????????89d08915????????d1e8", argdata, 0, 0, &func);
}

int __stdcall random32()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func699::func;
	return execfunc();
}

namespace _func700
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("srandom32", typeid(void (*)(unsigned int )), "8b442404c705????????00000000a3????????", argdata, 1, 6, &func);
}

void __stdcall srandom32(unsigned int seed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(unsigned int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func700::func;
	return execfunc(seed);
}

namespace _func701
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("getSkillBonus", typeid(float (*)(int , int )), "83ec048b5424088b44240c83fa05", argdata, 2, 2, &func);
}

float __stdcall getSkillBonus(int skill, int level)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int skill_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func701::func;
	return execfunc(skill, level);
}

namespace _func702
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenerateReward", typeid(void (*)(ResourceEvent &, RewardDesc &, int )), "5589e557565381ec4c0100008b450c8b400483f8ff", argdata, 3, 6, &func);
}

void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, RewardDesc &reward_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func702::func;
	return execfunc(ref, reward, worldLevel);
}

namespace _func703
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GetValue", typeid(void (*)(ResourceEvent &, const std::string &, int , int )), "57565383ec108b5c2424c7442404????????", argdata, 4, 6, &func);
}

void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, const std::string &type_arg, int level_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func703::func;
	return execfunc(ref, type, level, worldLevel);
}

namespace _func704
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("sys_graphics_set_window_title", typeid(void (*)(char *)), "83ec3ca1????????890424e8????????", argdata, 1, 6, &func);
}

void __stdcall sys_graphics_set_window_title(char *title)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(char *title_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func704::func;
	return execfunc(title);
}

namespace _func705
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("graphics_clear", typeid(void (*)(float , float , float , float , float , unsigned int )), "83ec3c0f57c0f30f106c2450f30f10642440f30f105c2444", argdata, 6, 6, &func);
}

void __stdcall graphics_clear(float r, float g, float b, float a, float depth, unsigned int stencil)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float r_arg, float g_arg, float b_arg, float a_arg, float depth_arg, unsigned int stencil_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func705::func;
	return execfunc(r, g, b, a, depth, stencil);
}

namespace _func706
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , Pointf )), "57565383ec308b7c24508d442444", argdata, 4, 18, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, Pointf dest)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, Pointf dest_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func706::func;
	return execfunc(current, mag_speed, dest);
}

namespace _func707
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), ".8b15????????b8650000008d4a0185d20f45c1", argdata, 0, 0, &func);
}

int Globals::GetNextSpaceId()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func707::func;
	return execfunc();
}

namespace _func708
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Globals::AimAhead", typeid(float (*)(Pointf , Pointf , float )), ".83ec1cf30f10642424f30f10442428f30f106c242c0f28f4", argdata, 3, 2, &func);
}

float Globals::AimAhead(Pointf delta, Pointf vr, float muzzleV)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf delta_arg, Pointf vr_arg, float muzzleV_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func708::func;
	return execfunc(delta, vr, muzzleV);
}

namespace _func709
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , float )), ".5383ec28f30f10442440f30f10542434f30f105c2438", argdata, 4, 18, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, float heading)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func709::func;
	return execfunc(current, mag_speed, heading);
}

TextLibrary *Global_Globals_Library;

namespace _var710
{
    static VariableDefinition varObj("Global_Globals_Library", "!c744240c????????895c2408c7442404(???????\?)893c24", &Global_Globals_Library);
}

int *Globals_GetNextSpaceId_id;

namespace _var711
{
    static VariableDefinition varObj("Globals_GetNextSpaceId_id", "!8b15(???????\?)b8650000008d4a0185d20f45c1", &Globals_GetNextSpaceId_id);
}

bool *Globals_RNG;

namespace _var712
{
    static VariableDefinition varObj("Globals_RNG", "!803d(???????\?)00c787800000003c000000c78784000000c8000000", &Globals_RNG);
}

FILE *ftl_log_logfile;

namespace _var713
{
    static VariableDefinition varObj("ftl_log_logfile", "!8974240c895c2408c744240401000000890424e8????????a1(???????\?)890424", &ftl_log_logfile);
}

namespace _func714
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("HackBox::constructor", typeid(void (HackBox::*)(Point , HackingSystem *, ShipManager *)), "5557565381ec9c0000008b9c24b00000008dbc2480000000", argdata, 4, 6, &func);
}

void HackBox::constructor(Point pos, HackingSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackBox *this_arg, Point pos_arg, HackingSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func714::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func715
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("HackingDrone::SetMovementTarget", typeid(void (HackingDrone::*)(Targetable *)), "565383ec248b7424348b5c243085f6", argdata, 2, 6, &func);
}

void HackingDrone::SetMovementTarget(Targetable *target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackingDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func715::func;
	return execfunc(this, target);
}

namespace _func716
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("HackingDrone::CollisionMoving", typeid(CollisionResponse (HackingDrone::*)(Pointf , Pointf , Damage , bool )), ".5589e557565383ec7c8b750c8b5d088b55548b7d34", argdata, 6, 18, &func);
}

CollisionResponse HackingDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackingDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func716::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func717
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("HackingDrone::OnLoop", typeid(void (HackingDrone::*)()), ".5589e55756be050000005383ec7c8b5d08891c24", argdata, 1, 6, &func);
}

void HackingDrone::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackingDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func717::func;
	return execfunc(this);
}

namespace _func718
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("HackingSystem::BlowHackingDrone", typeid(void (HackingSystem::*)()), "83ec1c8b44242080b8b001000000", argdata, 1, 6, &func);
}

void HackingSystem::BlowHackingDrone()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func718::func;
	return execfunc(this);
}

namespace _func719
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("HackingSystem::OnLoop", typeid(void (HackingSystem::*)()), "57565383ec308b5c2440891c24e8????????80bbbc01000000", argdata, 1, 6, &func);
}

void HackingSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func719::func;
	return execfunc(this);
}

namespace _func720
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("HackingSystem::SoundLoop", typeid(bool (HackingSystem::*)()), "5383ec??8b5c????80bb980100000075??83c4??31c05b", argdata, 1, 2, &func);
}

bool HackingSystem::SoundLoop()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func720::func;
	return execfunc(this);
}

namespace _func721
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InfoBox::OnRender", typeid(void (InfoBox::*)()), "5589e557565381ecbc0100008b7d088b078b7764", argdata, 1, 6, &func);
}

void InfoBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func721::func;
	return execfunc(this);
}

namespace _func722
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InfoBox::Clear", typeid(void (InfoBox::*)()), "57565383ec208b5c24308d7424188d7c2417", argdata, 1, 6, &func);
}

void InfoBox::Clear()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func722::func;
	return execfunc(this);
}

namespace _func723
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(void (InfoBox::*)(Description *, int , int , InfoBox::ExpandDir )), "5557565383ec2c8b5c24408b7424448b7c24488b6c244c", argdata, 5, 6, &func);
}

void InfoBox::SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, Description *desc_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func723::func;
	return execfunc(this, desc, width, height, dir);
}

namespace _func724
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetText", typeid(void (InfoBox::*)(const std::string &, const std::string &, int , int , InfoBox::ExpandDir )), "5557565383ec7c8d7c24378b9c24900000008d7424388bac24a0000000", argdata, 6, 6, &func);
}

void InfoBox::SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const std::string &title_arg, const std::string &text_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func724::func;
	return execfunc(this, title, text, width, height, dir);
}

namespace _func725
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintWeapon", typeid(void (InfoBox::*)(const WeaponBlueprint *, int , bool , int )), "5589e557565383ec4c8b7d0c8d75d8", argdata, 5, 6, &func);
}

void InfoBox::SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const WeaponBlueprint *bp_arg, int status_arg, bool hasWeaponSystem_arg, int yShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func725::func;
	return execfunc(this, bp, status, hasWeaponSystem, yShift);
}

namespace _func726
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintDrone", typeid(void (InfoBox::*)(const DroneBlueprint *, int , bool , int )), "5589e557565381ec3c0100008b45148b7508", argdata, 5, 6, &func);
}

void InfoBox::SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const DroneBlueprint *bp_arg, int status_arg, bool hasDroneSystem_arg, int yShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func726::func;
	return execfunc(this, bp, status, hasDroneSystem, yShift);
}

namespace _func727
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprint", typeid(void (InfoBox::*)(const ItemBlueprint *)), ".57565383ec208b7424348b5c24308d4608894424048d430c890424", argdata, 2, 6, &func);
}

void InfoBox::SetBlueprint(const ItemBlueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const ItemBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func727::func;
	return execfunc(this, bp);
}

namespace _func728
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintCrew", typeid(void (InfoBox::*)(const CrewBlueprint *, int , bool )), "5589e557565381ec8c0000008b45148b4d088945808b4508", argdata, 4, 6, &func);
}

void InfoBox::SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const CrewBlueprint *bp_arg, int yShift_arg, bool detailedCrew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func728::func;
	return execfunc(this, bp, yShift, detailedCrew);
}

namespace _func729
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprintAugment", typeid(void (InfoBox::*)(const AugmentBlueprint *)), ".57565383ec208b7424348b5c24308d4608894424048d430c890424", argdata, 2, 6, &func);
}

void InfoBox::SetBlueprintAugment(const AugmentBlueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const AugmentBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func729::func;
	return execfunc(this, bp);
}

namespace _func730
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InfoBox::IsEmpty", typeid(bool (InfoBox::*)()), "5589e557565383ec3c8b5d08837b50ff", argdata, 1, 2, &func);
}

bool InfoBox::IsEmpty()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func730::func;
	return execfunc(this);
}

namespace _func731
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InfoBox::CalcBoxHeight", typeid(int (InfoBox::*)()), "5589e557565383ec6c8b7d08837f4801", argdata, 1, 2, &func);
}

int InfoBox::CalcBoxHeight()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func731::func;
	return execfunc(this);
}

namespace _func732
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InfoBox::constructor", typeid(void (InfoBox::*)()), "565383ec248b5c24308d74241fc744240800000000c744240400000000", argdata, 1, 6, &func);
}

void InfoBox::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func732::func;
	return execfunc(this);
}

namespace _func733
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetSystemId", typeid(void (InfoBox::*)(int , int , int , int , int , int )), "5589e557565383ec3c8b5d088b45188b7d0c", argdata, 7, 6, &func);
}

void InfoBox::SetSystemId(int systemId, int maxPower, int currentLevel, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, int systemId_arg, int maxPower_arg, int currentLevel_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func733::func;
	return execfunc(this, systemId, maxPower, currentLevel, upgrade, yShift, forceSystemWidth);
}

namespace _func734
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetSystem", typeid(void (InfoBox::*)(ShipSystem *, int , int , int )), "5557565383ec3c8b7424548b5c245085f6", argdata, 5, 6, &func);
}

void InfoBox::SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InfoBox *this_arg, ShipSystem *system_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func734::func;
	return execfunc(this, system, upgrade, yShift, forceSystemWidth);
}

GL_Color *Global_InfoBox_detailsBarOn;

namespace _var735
{
    static VariableDefinition varObj("Global_InfoBox_detailsBarOn", "!b8(???????\?)89fa84d2ba(???????\?)", &Global_InfoBox_detailsBarOn);
}

GL_Color *Global_InfoBox_detailsBarOff;

namespace _var736
{
    static VariableDefinition varObj("Global_InfoBox_detailsBarOff", "", &Global_InfoBox_detailsBarOff);
}

namespace _func737
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InputBox::OnRender", typeid(void (InputBox::*)()), "5589e5565383ec??8b5d08807b04??", argdata, 1, 6, &func);
}

void InputBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InputBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func737::func;
	return execfunc(this);
}

namespace _func738
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InputBox::TextInput", typeid(void (InputBox::*)(int )), ".5557565383ec??8b4424448b5c244083f8??", argdata, 2, 6, &func);
}

void InputBox::TextInput(int ch)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InputBox *this_arg, int ch_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func738::func;
	return execfunc(this, ch);
}

namespace _func739
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InputBox::TextEvent", typeid(void (InputBox::*)(CEvent::TextEvent )), ".578d7c240883e4??ff77fc5589e557565383ec??8b0783f8??", argdata, 2, 6, &func);
}

void InputBox::TextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InputBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func739::func;
	return execfunc(this, event);
}

namespace _func740
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("InputBox::StartInput", typeid(void (InputBox::*)()), ".565383ec??8b5c2440c7442408????????c7442404????????8d4328", argdata, 1, 6, &func);
}

void InputBox::StartInput()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(InputBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func740::func;
	return execfunc(this);
}

namespace _func741
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("IonDrone::GetRoomDamage", typeid(Damage (IonDrone::*)()), "565383ec148b7424248b5c24208b869c000000", argdata, 2, 18, &func);
}

Damage IonDrone::GetRoomDamage()
{
	typedef Damage __attribute__((cdecl)) (*custom_arg_funcptr_t)(IonDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func741::func;
	return execfunc(this);
}

namespace _func742
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("IonDrone::constructor", typeid(void (IonDrone::*)(int , DroneBlueprint *)), ".5589e557565381ecec000000", argdata, 3, 6, &func);
}

void IonDrone::constructor(int iShipId, DroneBlueprint *blueprint)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(IonDrone *this_arg, int iShipId_arg, DroneBlueprint *blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func742::func;
	return execfunc(this, iShipId, blueprint);
}

namespace _func743
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("IonDroneAnimation::constructor", typeid(void (IonDroneAnimation::*)(int , Pointf , bool )), "5589e557565381ecfc0000008b5d18", argdata, 4, 6, &func);
}

void IonDroneAnimation::constructor(int iShipId, Pointf position, bool enemy)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(IonDroneAnimation *this_arg, int iShipId_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func743::func;
	return execfunc(this, iShipId, position, enemy);
}

namespace _func744
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("IonDroneAnimation::UpdateShooting", typeid(void (IonDroneAnimation::*)()), ".554889e54157415641554154534883ec28", argdata, 1, 6, &func);
}

void IonDroneAnimation::UpdateShooting()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(IonDroneAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func744::func;
	return execfunc(this);
}

namespace _func745
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ItemStoreBox::constructor", typeid(void (ItemStoreBox::*)(ShipManager *, const std::string &)), "5557565383ec3c8b7c24588d7424208b5c2450", argdata, 3, 6, &func);
}

void ItemStoreBox::constructor(ShipManager *ship, const std::string &resourceName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ItemStoreBox *this_arg, ShipManager *ship_arg, const std::string &resourceName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func745::func;
	return execfunc(this, ship, resourceName);
}

std::vector<std::string> *Global_OptionsScreen_languageList;

namespace _var746
{
    static VariableDefinition varObj("Global_OptionsScreen_languageList", "!8d348500000000a1(???????\?)", &Global_OptionsScreen_languageList);
}

namespace _func747
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("LanguageChooser::OnRender", typeid(void (LanguageChooser::*)()), ".5557565331db83ec6c", argdata, 1, 6, &func);
}

void LanguageChooser::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(LanguageChooser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func747::func;
	return execfunc(this);
}

namespace _func748
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("LaserBlast::OnUpdate", typeid(void (LaserBlast::*)()), "5589e55383ec448b5d0880bbb00000000074??8d8310010000", argdata, 1, 6, &func);
}

void LaserBlast::OnUpdate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func748::func;
	return execfunc(this);
}

namespace _func749
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("LaserBlast::OnInit", typeid(void (LaserBlast::*)()), "5383ec188b5c24208b4374394370c7433801000000", argdata, 1, 6, &func);
}

void LaserBlast::OnInit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func749::func;
	return execfunc(this);
}

void **VTable_LaserBlast;

namespace _var750
{
    static VariableDefinition varObj("VTable_LaserBlast", "!e8????????8b8d3cfffffff30f108538ffffff8b4174394170c701(???????\?)c74104(???????\?)", &VTable_LaserBlast);
}

void **VTable_Targetable_LaserBlast;

namespace _var751
{
    static VariableDefinition varObj("VTable_Targetable_LaserBlast", "", &VTable_Targetable_LaserBlast);
}

namespace _func752
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), "5557565383ec4c8b7424608b442464", argdata, 2, 6, &func);
}

void LocationEvent::ClearEvent(bool force)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(LocationEvent *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func752::func;
	return execfunc(this, force);
}

namespace _func753
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("LocationEvent::constructor", typeid(void (LocationEvent::*)()), "565383ec248b5c24308d74241f89742408", argdata, 1, 6, &func);
}

void LocationEvent::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(LocationEvent *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func753::func;
	return execfunc(this);
}

namespace _func754
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("LockdownShard::Update", typeid(void (LockdownShard::*)()), "5589e55383ec348b5d08c70424????????", argdata, 1, 6, &func);
}

void LockdownShard::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(LockdownShard *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func754::func;
	return execfunc(this);
}

namespace _func755
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MainMenu::OnRender", typeid(void (MainMenu::*)()), "5589e557565381ecdc0200008b7d08????????????00", argdata, 1, 6, &func);
}

void MainMenu::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func755::func;
	return execfunc(this);
}

namespace _func756
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MainMenu::Open", typeid(bool (MainMenu::*)()), ".5589e557565381ec", argdata, 1, 2, &func);
}

bool MainMenu::Open()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func756::func;
	return execfunc(this);
}

namespace _func757
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseMove", typeid(void (MainMenu::*)(int , int )), "5589e557565383ec2c8b7d088b7510", argdata, 3, 6, &func);
}

void MainMenu::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MainMenu *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func757::func;
	return execfunc(this, x, y);
}

namespace _func758
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MainMenu::OnLoop", typeid(void (MainMenu::*)()), ".5589e557565381ec", argdata, 1, 6, &func);
}

void MainMenu::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func758::func;
	return execfunc(this);
}

namespace _func759
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MainMenu::MouseClick", typeid(void (MainMenu::*)(int , int )), ".5589e557565383ec3c8b5d08????????????00", argdata, 3, 6, &func);
}

void MainMenu::MouseClick(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MainMenu *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func759::func;
	return execfunc(this, x, y);
}

namespace _func760
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MainMenu::constructor", typeid(void (MainMenu::*)()), "5557565383ec3c8b5c24508d7424208d432c", argdata, 1, 6, &func);
}

void MainMenu::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func760::func;
	return execfunc(this);
}

namespace _func761
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK", typeid(void (MantisAnimation::*)()), "565383ec148b7424208b5c2424893424895c2404e8????????f30f108640050000", argdata, 0, 4, &func);
}

namespace _func762
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::GetShootingSound", typeid(std::string (MantisAnimation::*)()), ".5557565381ec0c010000803d????????00", argdata, 2, 18, &func);
}

std::string MantisAnimation::GetShootingSound()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func762::func;
	return execfunc(this);
}

namespace _func763
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK2", typeid(void (MantisAnimation::*)()), "8b44240431d280b8d108000000", argdata, 0, 4, &func);
}

namespace _func764
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::GetDeathSound", typeid(std::string (MantisAnimation::*)()), ".5383ec288b5c24308d44241f89442408", argdata, 2, 18, &func);
}

std::string MantisAnimation::GetDeathSound()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func764::func;
	return execfunc(this);
}

namespace _func765
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("MantisAnimation::__DO_NOT_HOOK3", typeid(void (MantisAnimation::*)()), "31c080bb9f0900000075??c6839f0900000183c418b8010000005b", argdata, 0, 4, &func);
}

namespace _func766
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MantisAnimation::FireShot", typeid(bool (MantisAnimation::*)()), ".5383ec188b5c2420c7442404000080bf", argdata, 1, 2, &func);
}

bool MantisAnimation::FireShot()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(MantisAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func766::func;
	return execfunc(this);
}

namespace _func767
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MenuScreen::OnLanguageChange", typeid(void (MenuScreen::*)()), "5589e557565381ec9c0000008b75088b561c", argdata, 1, 6, &func);
}

void MenuScreen::OnLanguageChange()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func767::func;
	return execfunc(this);
}

namespace _func768
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MenuScreen::OnRender", typeid(void (MenuScreen::*)()), ".5589e557565381ecbc0000008b5d0880bb5c02000000", argdata, 1, 6, &func);
}

void MenuScreen::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func768::func;
	return execfunc(this);
}

namespace _func769
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MenuScreen::Open", typeid(void (MenuScreen::*)()), ".5589e557565383ec4c8b7d088d75d88d", argdata, 1, 6, &func);
}

void MenuScreen::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func769::func;
	return execfunc(this);
}

namespace _func770
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MenuScreen::constructor", typeid(void (MenuScreen::*)()), ".5557565381ec0c0100008b9c24200100008db424a8000000", argdata, 1, 6, &func);
}

void MenuScreen::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func770::func;
	return execfunc(this);
}

namespace _func771
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("MindBox::constructor", typeid(void (MindBox::*)(Point , MindSystem *)), "5557565383ec7c8b9c24900000008d7c243c", argdata, 3, 6, &func);
}

void MindBox::constructor(Point pos, MindSystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MindBox *this_arg, Point pos_arg, MindSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func771::func;
	return execfunc(this, pos, sys);
}

namespace _func772
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MindSystem::ReleaseCrew", typeid(void (MindSystem::*)()), "5557565383ec3c8b5c24508b93a80100", argdata, 1, 6, &func);
}

void MindSystem::ReleaseCrew()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func772::func;
	return execfunc(this);
}

namespace _func773
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MindSystem::SetHackingLevel", typeid(void (MindSystem::*)(int )), ".565383ec148b74????8b5c????83fe01", argdata, 2, 6, &func);
}

void MindSystem::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MindSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func773::func;
	return execfunc(this, hackingLevel);
}

namespace _func774
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MindSystem::SetArmed", typeid(void (MindSystem::*)(int )), "5383ec18837c2424018b5c2420", argdata, 2, 6, &func);
}

void MindSystem::SetArmed(int armed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MindSystem *this_arg, int armed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func774::func;
	return execfunc(this, armed);
}

namespace _func775
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MindSystem::InitiateMindControl", typeid(void (MindSystem::*)()), "5557565383ec4c8b6c24608b95c0010000", argdata, 1, 6, &func);
}

void MindSystem::InitiateMindControl()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func775::func;
	return execfunc(this);
}

namespace _func776
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MindSystem::OnLoop", typeid(void (MindSystem::*)()), "5557565383ec3c8b5c2450891c24e8????????8b83c0010000", argdata, 1, 6, &func);
}

void MindSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func776::func;
	return execfunc(this);
}

namespace _func777
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("Missile::constructor", typeid(void (Missile::*)(Pointf , int , int , Pointf , float )), "5589e557565381ecdc0000008b451c8b55208b4d088b75148b5d18", argdata, 6, 6, &func);
}

void Missile::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Missile *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, float _heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func777::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _heading);
}

namespace _func778
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltip", typeid(void (MouseControl::*)(const std::string &)), "57565383ec108b7c24248b7424208b07", argdata, 2, 6, &func);
}

void MouseControl::SetTooltip(const std::string &tooltip)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func778::func;
	return execfunc(this, tooltip);
}

namespace _func779
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltipTitle", typeid(void (MouseControl::*)(const std::string &)), "8b4424048b90d80000008b52f485d2", argdata, 2, 6, &func);
}

void MouseControl::SetTooltipTitle(const std::string &tooltip)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func779::func;
	return execfunc(this, tooltip);
}

namespace _func780
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::MeasureTooltip", typeid(Point (MouseControl::*)(int )), "5589e557565383ec5c8b7d0c8d45d8890424c744240800000000", argdata, 3, 18, &func);
}

Point MouseControl::MeasureTooltip(int unk)
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func780::func;
	return execfunc(this, unk);
}

namespace _func781
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("MouseControl::QueueStaticTooltip", typeid(void (MouseControl::*)(Point )), "8b4c24048b4424088b54240c8981e8000000", argdata, 2, 6, &func);
}

void MouseControl::QueueStaticTooltip(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func781::func;
	return execfunc(this, pos);
}

namespace _func782
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::RenderTooltip", typeid(void (MouseControl::*)(Point , bool )), "5589e557565383ec7c8b5d088b4d0c8b55108b83d8000000", argdata, 3, 6, &func);
}

void MouseControl::RenderTooltip(Point tooltipPoint, bool staticPos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, Point tooltipPoint_arg, bool staticPos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func782::func;
	return execfunc(this, tooltipPoint, staticPos);
}

namespace _func783
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MouseControl::OnLoop", typeid(void (MouseControl::*)()), "5383ec188b5c242080bbc800000000", argdata, 1, 6, &func);
}

void MouseControl::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func783::func;
	return execfunc(this);
}

namespace _func784
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MouseControl::InstantTooltip", typeid(void (MouseControl::*)()), "8b442404c680d400000001", argdata, 1, 6, &func);
}

void MouseControl::InstantTooltip()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func784::func;
	return execfunc(this);
}

namespace _func785
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MouseControl::ResetArmed", typeid(void (MouseControl::*)()), ".8b442404c7401000000000c7401400000000c7401800000000c780e000000000000000c7402000000000", argdata, 1, 6, &func);
}

void MouseControl::ResetArmed()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func785::func;
	return execfunc(this);
}

namespace _func786
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MouseControl::OnRender", typeid(void (MouseControl::*)()), "5557565381ec3c0100008b9c245001000080bbc900000000", argdata, 1, 6, &func);
}

void MouseControl::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func786::func;
	return execfunc(this);
}

namespace _func787
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("MouseControl::Reset", typeid(void (MouseControl::*)()), ".5383ec288b5c24308d83c0000000", argdata, 1, 6, &func);
}

void MouseControl::Reset()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func787::func;
	return execfunc(this);
}

namespace _func788
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetDoor", typeid(void (MouseControl::*)(int )), "565383ec148b5c24248b74242083fb01", argdata, 2, 6, &func);
}

void MouseControl::SetDoor(int state)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, int state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func788::func;
	return execfunc(this, state);
}

namespace _func789
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetValid", typeid(void (MouseControl::*)(bool , bool )), ".8b4c????8b44????8b54????84c988501d", argdata, 3, 6, &func);
}

void MouseControl::SetValid(bool valid, bool newValid)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, bool valid_arg, bool newValid_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func789::func;
	return execfunc(this, valid, newValid);
}

namespace _func790
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::LoadTooltip", typeid(void (MouseControl::*)(const std::string &)), "5589e557565383ec4c8b750c8d5dd8c7", argdata, 2, 6, &func);
}

void MouseControl::LoadTooltip(const std::string &tooltipName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltipName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func790::func;
	return execfunc(this, tooltipName);
}

MouseControl *Global_MouseControl_Mouse;

namespace _var791
{
    static VariableDefinition varObj("Global_MouseControl_Mouse", "!e8????????e8????????884305c70424(???????\?)", &Global_MouseControl_Mouse);
}

namespace _func792
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OptionsScreen::Open", typeid(void (OptionsScreen::*)(bool )), "55660f76c089e557565381ec7c020000", argdata, 2, 6, &func);
}

void OptionsScreen::Open(bool mainMenu)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg, bool mainMenu_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func792::func;
	return execfunc(this, mainMenu);
}

namespace _func793
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("OptionsScreen::OnLoop", typeid(void (OptionsScreen::*)()), ".5589e557565331db83ec4c", argdata, 1, 6, &func);
}

void OptionsScreen::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func793::func;
	return execfunc(this);
}

namespace _func794
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("OptionsScreen::OnInit", typeid(void (OptionsScreen::*)()), ".5557565383ec6c8b9c2480000000????????c70424", argdata, 1, 6, &func);
}

void OptionsScreen::OnInit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func794::func;
	return execfunc(this);
}

void **VTable_OuterHull;

namespace _var795
{
    static VariableDefinition varObj("VTable_OuterHull", "!8b8d44ffffff8d4168c701(???????\?)", &VTable_OuterHull);
}

namespace _func796
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(void (OxygenSystem::*)(int , int , bool )), "538b4424108b5c241485c0", argdata, 4, 6, &func);
}

void OxygenSystem::UpdateBreach(int roomId, int hasBreach, bool unk3)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int hasBreach_arg, bool unk3_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func796::func;
	return execfunc(this, roomId, hasBreach, unk3);
}

namespace _func797
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(void (OxygenSystem::*)(int , int )), "5557565383ec2c8b5c24488b7424408b7c244485db", argdata, 3, 6, &func);
}

void OxygenSystem::UpdateAirlock(int roomId, int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func797::func;
	return execfunc(this, roomId, unk);
}

namespace _func798
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(void (OxygenSystem::*)(int )), "8b4424048b5424088b809c010000c7049000000000", argdata, 2, 6, &func);
}

void OxygenSystem::EmptyOxygen(int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func798::func;
	return execfunc(this, roomId);
}

namespace _func799
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(void (OxygenSystem::*)(int , float )), "8b4424048b5424088b809c0100008d0490", argdata, 3, 6, &func);
}

void OxygenSystem::ModifyRoomOxygen(int roomId, float value)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func799::func;
	return execfunc(this, roomId, value);
}

namespace _func800
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(void (OxygenSystem::*)(int , float , bool )), "5589e557565383ec3c0fb645148b7508", argdata, 4, 6, &func);
}

void OxygenSystem::ComputeAirLoss(int roomId, float value, bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func800::func;
	return execfunc(this, roomId, value, unk);
}

namespace _func801
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::GetRefillSpeed", typeid(float (OxygenSystem::*)()), "5383ec188b5c242080bb84010000008b8380010000", argdata, 1, 2, &func);
}

float OxygenSystem::GetRefillSpeed()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func801::func;
	return execfunc(this);
}

namespace _func802
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::constructor", typeid(void (OxygenSystem::*)(int , int , int , int )), "5557565383ec2c8b4424508b5c24408b742444", argdata, 5, 6, &func);
}

void OxygenSystem::constructor(int numRooms, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int numRooms_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func802::func;
	return execfunc(this, numRooms, roomId, shipId, startingPower);
}

namespace _func803
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("PDSFire::OnUpdate", typeid(void (PDSFire::*)()), "565383ec148b5c242080bbb000000000", argdata, 1, 6, &func);
}

void PDSFire::OnUpdate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(PDSFire *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func803::func;
	return execfunc(this);
}

namespace _func804
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("PDSFire::CollisionCheck", typeid(void (PDSFire::*)(Collideable *)), ".565383ec648b7424748b5c24708b06", argdata, 2, 6, &func);
}

void PDSFire::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(PDSFire *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func804::func;
	return execfunc(this, other);
}

namespace _func805
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("PDSFire::constructor", typeid(void (PDSFire::*)(Point , int , Pointf )), ".5589e557565381ecdc0000008b4d08", argdata, 4, 6, &func);
}

void PDSFire::constructor(Point pos, int destinationSpace, Pointf destination)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(PDSFire *this_arg, Point pos_arg, int destinationSpace_arg, Pointf destination_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func805::func;
	return execfunc(this, pos, destinationSpace, destination);
}

namespace _func806
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), "8b4424048b108b40042b5424082b44240c", argdata, 2, 2, &func);
}

int Point::RelativeDistance(Point other)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func806::func;
	return execfunc(this, other);
}

namespace _func807
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Point::Distance", typeid(int (Point::*)(Point )), "83ec1c8b4424208b108b40042b5424242b442428", argdata, 2, 2, &func);
}

int Point::Distance(Point other)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func807::func;
	return execfunc(this, other);
}

namespace _func808
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Pointf::constructor", typeid(void (Pointf::*)(float , float )), "8b442404f30f10442408f30f1100f30f1044240c", argdata, 3, 6, &func);
}

void Pointf::constructor(float x, float y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf *this_arg, float x_arg, float y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func808::func;
	return execfunc(this, x, y);
}

namespace _func809
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Pointf::RelativeDistance", typeid(float (Pointf::*)(Pointf )), "83ec048b442408f30f1000f30f104804f30f5c44240cf30f5c4c2410", argdata, 2, 2, &func);
}

float Pointf::RelativeDistance(Pointf other)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf *this_arg, Pointf other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func809::func;
	return execfunc(this, other);
}

namespace _func810
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Pointf::Normalize", typeid(Pointf (Pointf::*)()), "5383ec288b5c24348b442430", argdata, 2, 18, &func);
}

Pointf Pointf::Normalize()
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func810::func;
	return execfunc(this);
}

namespace _func811
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("PowerManager::DO_NOT_HOOK", typeid(void (PowerManager::*)()), "807c????018b54????", argdata, 0, 4, &func);
}

namespace _func812
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("PowerManager::SetHacked", typeid(void (PowerManager::*)(bool )), ".807c????018b54????", argdata, 2, 6, &func);
}

void PowerManager::SetHacked(bool val)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(PowerManager *this_arg, bool val_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func812::func;
	return execfunc(this, val);
}

namespace _func813
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("PowerManager::RestartAll", typeid(void (*)()), ".8b15????????a1????????29d0", argdata, 0, 6, &func);
}

void PowerManager::RestartAll()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func813::func;
	return execfunc();
}

namespace _func814
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("PowerManager::GetPowerManager", typeid(PowerManager *(*)(int )), ".565383ec448b15????????8b1d????????8b742450", argdata, 1, 2, &func);
}

PowerManager *PowerManager::GetPowerManager(int iShipId)
{
	typedef PowerManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int iShipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func814::func;
	return execfunc(iShipId);
}

namespace _func815
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::ValidTarget", typeid(bool (Projectile::*)()), "8b4424040fb680bc010000", argdata, 1, 2, &func);
}

bool Projectile::ValidTarget()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func815::func;
	return execfunc(this);
}

namespace _func816
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::ForceRenderLayer", typeid(int (Projectile::*)()), ".!b8ffffffffc3", argdata, 1, 2, &func);
}

int Projectile::ForceRenderLayer()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func816::func;
	return execfunc(this);
}

namespace _func817
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("Projectile::CollisionMoving", typeid(CollisionResponse (Projectile::*)(Pointf , Pointf , Damage , bool )), ".565383ec148b5c24208b7424248d4304", argdata, 6, 18, &func);
}

CollisionResponse Projectile::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func817::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func818
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::OnUpdate", typeid(void (Projectile::*)()), ".5589e55383ec448b5d0880bbb000000000", argdata, 1, 6, &func);
}

void Projectile::OnUpdate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func818::func;
	return execfunc(this);
}

namespace _func819
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Projectile::CollisionCheck", typeid(void (Projectile::*)(Collideable *)), ".5589e557565381ec8c0000008b750c8b5d088b06", argdata, 2, 6, &func);
}

void Projectile::CollisionCheck(Collideable *other)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg, Collideable *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func819::func;
	return execfunc(this, other);
}

namespace _func820
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Projectile::constructor", typeid(void (Projectile::*)(Pointf , int , int , Pointf )), ".5589e557565381ecec0000008b7d088b450c", argdata, 5, 6, &func);
}

void Projectile::constructor(Pointf position, int ownerId, int targetId, Pointf target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg, Pointf position_arg, int ownerId_arg, int targetId_arg, Pointf target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func820::func;
	return execfunc(this, position, ownerId, targetId, target);
}

namespace _func821
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Projectile::Initialize", typeid(void (Projectile::*)(const WeaponBlueprint &)), ".5589e557565381ecdc0000008b450cc78538ffffff00000000", argdata, 2, 6, &func);
}

void Projectile::Initialize(const WeaponBlueprint &bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg, const WeaponBlueprint &bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func821::func;
	return execfunc(this, bp);
}

namespace _func822
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Projectile::RandomSidePoint", typeid(Pointf (*)(int )), ".565383ec248b7424348d442410", argdata, 2, 18, &func);
}

Pointf Projectile::RandomSidePoint(int side)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int side_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func822::func;
	return execfunc(side);
}

namespace _func823
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::destructor", typeid(void (Projectile::*)()), ".5557565383ec2c8b7424408b86b4010000", argdata, 1, 6, &func);
}

void Projectile::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func823::func;
	return execfunc(this);
}

namespace _func824
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::constructor", typeid(void (ProjectileFactory::*)(const WeaponBlueprint *, int )), "5589e557565381ecdc0000008b4d088b4510", argdata, 3, 6, &func);
}

void ProjectileFactory::constructor(const WeaponBlueprint *bp, int shipId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, const WeaponBlueprint *bp_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func824::func;
	return execfunc(this, bp, shipId);
}

namespace _func825
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(void (ProjectileFactory::*)()), ".5383ec08803d????????008b5c2410", argdata, 1, 6, &func);
}

void ProjectileFactory::SelectChargeGoal()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func825::func;
	return execfunc(this);
}

namespace _func826
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::IsChargedGoal", typeid(bool (ProjectileFactory::*)()), "8b4424048b501c8b92fc00000085d2", argdata, 1, 2, &func);
}

bool ProjectileFactory::IsChargedGoal()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func826::func;
	return execfunc(this);
}

namespace _func827
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetHacked", typeid(void (ProjectileFactory::*)(int )), "8b4424048b54240805f80000008990bc03000089442404", argdata, 2, 6, &func);
}

void ProjectileFactory::SetHacked(int hacked)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, int hacked_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func827::func;
	return execfunc(this, hacked);
}

namespace _func828
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCurrentShip", typeid(void (ProjectileFactory::*)(Targetable *)), "8b4424048b5424083990f0000000", argdata, 2, 6, &func);
}

void ProjectileFactory::SetCurrentShip(Targetable *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, Targetable *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func828::func;
	return execfunc(this, ship);
}

namespace _func829
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), "8b442404f30f104c2408f30f105018f30f104008f30f11889c040000", argdata, 2, 6, &func);
}

void ProjectileFactory::SetCooldownModifier(float mod)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float mod_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func829::func;
	return execfunc(this, mod);
}

namespace _func830
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(void (ProjectileFactory::*)()), "5383ec188b5c242080bbba00000000", argdata, 1, 6, &func);
}

void ProjectileFactory::ForceCoolup()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func830::func;
	return execfunc(this);
}

namespace _func831
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(void (ProjectileFactory::*)(float )), "8b44240405f800000089442404", argdata, 2, 6, &func);
}

void ProjectileFactory::RenderChargeBar(float unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func831::func;
	return execfunc(this, unk);
}

namespace _func832
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(const std::string &)), ".5383ec188b5c2420c7442404????????891c24", argdata, 1, 2, &func);
}

int ProjectileFactory::StringToWeapon(const std::string &str)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &str_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func832::func;
	return execfunc(str);
}

namespace _func833
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::QueuedShots", typeid(bool (Projectile::*)()), ".8b44????8b90840400003990880400000f95??", argdata, 1, 2, &func);
}

bool Projectile::QueuedShots()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func833::func;
	return execfunc(this);
}

namespace _func834
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::Fire", typeid(void (ProjectileFactory::*)(std::vector<Pointf> &, int )), "57565383ec108b7424208b7c24248b86c40000002b86c0000000", argdata, 3, 6, &func);
}

void ProjectileFactory::Fire(std::vector<Pointf> &points, int target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, std::vector<Pointf> &points_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func834::func;
	return execfunc(this, points, target);
}

namespace _func835
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::LoadState", typeid(void (ProjectileFactory::*)(int )), ".!5531ed57565383ec4c8b74????8d????208b5c????", argdata, 2, 6, &func);
}

void ProjectileFactory::LoadState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func835::func;
	return execfunc(this, fd);
}

namespace _func836
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::FireNextShot", typeid(bool (ProjectileFactory::*)()), "538b54240831c08b8ab004000085c9", argdata, 1, 2, &func);
}

bool ProjectileFactory::FireNextShot()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func836::func;
	return execfunc(this);
}

namespace _func837
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::ReadyToFire", typeid(bool (ProjectileFactory::*)()), ".8b54????31c08b8ab004000085c97e??80baba0000000074??8b421c", argdata, 1, 2, &func);
}

bool ProjectileFactory::ReadyToFire()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func837::func;
	return execfunc(this);
}

namespace _func838
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SpendMissiles", typeid(int (ProjectileFactory::*)()), "57565383ec308b5c24408b839804000085c0", argdata, 1, 2, &func);
}

int ProjectileFactory::SpendMissiles()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func838::func;
	return execfunc(this);
}

namespace _func839
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::OnRender", typeid(void (ProjectileFactory::*)(float , bool )), "!5383ec18807c2428008b5c2420f30f10442424", argdata, 3, 6, &func);
}

void ProjectileFactory::OnRender(float alpha, bool forceVisual)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float alpha_arg, bool forceVisual_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func839::func;
	return execfunc(this, alpha, forceVisual);
}

namespace _func840
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::ClearAiming", typeid(void (ProjectileFactory::*)()), ".538b4424088b88c00000008b90c400000029cac1fa0385d2", argdata, 1, 6, &func);
}

void ProjectileFactory::ClearAiming()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func840::func;
	return execfunc(this);
}

namespace _func841
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::ClearProjectiles", typeid(void (ProjectileFactory::*)()), ".8b4424048b9084040000899088040000", argdata, 1, 6, &func);
}

void ProjectileFactory::ClearProjectiles()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func841::func;
	return execfunc(this);
}

namespace _func842
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), "8b5424048b421c83b8fc00000001", argdata, 1, 2, &func);
}

int ProjectileFactory::NumTargetsRequired()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func842::func;
	return execfunc(this);
}

namespace _func843
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::Update", typeid(void (ProjectileFactory::*)()), "5589e557565381ec7c0100008b7d088b8fb004000085c9", argdata, 1, 6, &func);
}

void ProjectileFactory::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func843::func;
	return execfunc(this);
}

namespace _func844
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::GetProjectile", typeid(Projectile *(ProjectileFactory::*)()), "5589e557565383ec4c8b75088d86f8000000890424", argdata, 1, 2, &func);
}

Projectile *ProjectileFactory::GetProjectile()
{
	typedef Projectile *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func844::func;
	return execfunc(this);
}

namespace _func845
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::destructor", typeid(void (ProjectileFactory::*)()), "5557565383ec2c8b442440c700????3d088b8084", argdata, 1, 6, &func);
}

void ProjectileFactory::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func845::func;
	return execfunc(this);
}

namespace _func846
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveProjectile", typeid(void (*)(Projectile *, int )), "565383ec148b5c24208b7424248b03891c24", argdata, 2, 6, &func);
}

void ProjectileFactory::SaveProjectile(Projectile *p, int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *p_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func846::func;
	return execfunc(p, fd);
}

namespace _func847
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::LoadProjectile", typeid(Projectile *(*)(int )), "5589e557565383ec6c8b4508890424", argdata, 1, 2, &func);
}

Projectile *ProjectileFactory::LoadProjectile(int fd)
{
	typedef Projectile *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func847::func;
	return execfunc(fd);
}

namespace _func848
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveState", typeid(void (ProjectileFactory::*)(int )), ".555731ff565383ec1c8b5c????8b74????f30f10", argdata, 2, 6, &func);
}

void ProjectileFactory::SaveState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func848::func;
	return execfunc(this, fd);
}

namespace _func849
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetAutoFire", typeid(void (ProjectileFactory::*)(bool )), "8b5424088b44240484d275", argdata, 2, 6, &func);
}

void ProjectileFactory::SetAutoFire(bool autoFire)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, bool autoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func849::func;
	return execfunc(this, autoFire);
}

namespace _func850
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ReactorButton::Accept", typeid(void (ReactorButton::*)()), "5589e5565383ec308b5d088b436c85c0", argdata, 1, 6, &func);
}

void ReactorButton::Accept()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func850::func;
	return execfunc(this);
}

namespace _func851
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ReactorButton::OnClick", typeid(void (ReactorButton::*)()), "5589e557565383ec3c8b5d088d75d08b4370", argdata, 1, 6, &func);
}

void ReactorButton::OnClick()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func851::func;
	return execfunc(this);
}

namespace _func852
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ReactorButton::OnRightClick", typeid(void (ReactorButton::*)()), "5589e557565383ec3c8b5d088d75d08b436c", argdata, 1, 6, &func);
}

void ReactorButton::OnRightClick()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func852::func;
	return execfunc(this);
}

namespace _func853
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ReactorButton::OnRender", typeid(void (ReactorButton::*)()), "5589e557565381ec0c0300008b4508890424", argdata, 1, 6, &func);
}

void ReactorButton::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func853::func;
	return execfunc(this);
}

void **VTable_RepairAnimation;

namespace _var854
{
    static VariableDefinition varObj("VTable_RepairAnimation", "!0f85150100008d44242889442418c706(???????\?)", &VTable_RepairAnimation);
}

namespace _func855
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("RepairStoreBox::constructor", typeid(void (RepairStoreBox::*)(ShipManager *, bool , int )), "5589e557565383ec7c8b45108d75e08b5d08", argdata, 4, 6, &func);
}

void RepairStoreBox::constructor(ShipManager *ship, bool repairAll, int price)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(RepairStoreBox *this_arg, ShipManager *ship_arg, bool repairAll_arg, int price_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func855::func;
	return execfunc(this, ship, repairAll, price);
}

namespace _func856
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ResourceControl::constructor", typeid(void (ResourceControl::*)()), "57565383ec208b5c24308d4310c7430400000000", argdata, 1, 6, &func);
}

void ResourceControl::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func856::func;
	return execfunc(this);
}

namespace _func857
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitive", typeid(GL_Primitive *(ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "83ec5c8b4424648b8c248800000085c00f84????????89c285d2f30f1074247cf30f10642478f30f106c2474f30f2a542470", argdata, 8, 2, &func);
}

GL_Primitive *ResourceControl::CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg, int unk1_arg, int unk2_arg, int unk3_arg, GL_Color color_arg, float alpha_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func857::func;
	return execfunc(this, tex, unk1, unk2, unk3, color, alpha, mirror);
}

namespace _func858
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::OnInit", typeid(void (ResourceControl::*)(int )), "5383ec188b5c24208b442424c7838800000000000000894354c70424b80b0000", argdata, 2, 6, &func);
}

void ResourceControl::OnInit(int imageSwappingMode)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, int imageSwappingMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func858::func;
	return execfunc(this, imageSwappingMode);
}

namespace _func859
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::LoadFile", typeid(char *(ResourceControl::*)(const std::string &)), "555731ff565383ec4c8d44241e8b5c246089442408", argdata, 2, 2, &func);
}

char *ResourceControl::LoadFile(const std::string &fileName)
{
	typedef char *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func859::func;
	return execfunc(this, fileName);
}

namespace _func860
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::LoadFromResourceFile", typeid(char *(ResourceControl::*)(const std::string &, std::size_t &, const std::string *)), ".5531ed57565383ec2c8b442444", argdata, 4, 2, &func);
}

char *ResourceControl::LoadFromResourceFile(const std::string &fileName, std::size_t &fileSize, const std::string *unused_resourceFile)
{
	typedef char *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &fileName_arg, std::size_t &fileSize_arg, const std::string *unused_resourceFile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func860::func;
	return execfunc(this, fileName, fileSize, unused_resourceFile);
}

namespace _func861
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(GL_Texture *(ResourceControl::*)(const std::string &)), "5589e557565383ec5c8d45d4890424", argdata, 2, 2, &func);
}

GL_Texture *ResourceControl::GetImageId(const std::string &dir)
{
	typedef GL_Texture *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func861::func;
	return execfunc(this, dir);
}

namespace _func862
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImage", typeid(int (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "83ec5c8b4424648b8c248800000085c00f84????????89c285d2f30f1074247cf30f10542478f30f105c2474f30f2a442470", argdata, 8, 2, &func);
}

int ResourceControl::RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func862::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func863
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImageString", typeid(int (ResourceControl::*)(std::string &, int , int , int , GL_Color , float , bool )), "5383ec588b4424648b9c2488000000894424048b442460890424e8????????f30f104c2474f30f10442478f30f1054247c85c00f84????????89c285d2f30f2a5c2470", argdata, 8, 2, &func);
}

int ResourceControl::RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, std::string &tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func863::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func864
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::CreateImagePrimitiveString", typeid(GL_Primitive *(ResourceControl::*)(const std::string &, int , int , int , GL_Color , float , bool )), "5383ec588b4424648b9c2488000000894424048b442460890424e8????????f30f104c2474f30f10442478f30f1054247c85c00f84????????89c285d2f30f2a6c2470", argdata, 8, 2, &func);
}

GL_Primitive *ResourceControl::CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float alpha_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func864::func;
	return execfunc(this, tex, x, y, rotation, color, alpha, mirror);
}

namespace _func865
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(freetype::font_data &(ResourceControl::*)(int , bool )), "5557565383ec4c8b4424648b5c24608b4c24688d50fa83fa02", argdata, 3, 2, &func);
}

freetype::font_data &ResourceControl::GetFontData(int size, bool ignoreLanguage)
{
	typedef freetype::font_data &__attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, int size_arg, bool ignoreLanguage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func865::func;
	return execfunc(this, size, ignoreLanguage);
}

namespace _func866
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageData", typeid(ImageDesc (ResourceControl::*)(GL_Texture *)), "5531d257565383ec1c8b4424348b7c24388b7034", argdata, 3, 18, &func);
}

ImageDesc ResourceControl::GetImageData(GL_Texture *tex)
{
	typedef ImageDesc __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func866::func;
	return execfunc(this, tex);
}

namespace _func867
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::ImageExists", typeid(bool (ResourceControl::*)(const std::string &)), ".5589e557565383ec4c8b7d0c", argdata, 2, 2, &func);
}

bool ResourceControl::ImageExists(const std::string &name)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func867::func;
	return execfunc(this, name);
}

namespace _func868
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::PreloadResources", typeid(bool (ResourceControl::*)(bool )), "5557565381ec8c0000000fb68424a40000008bbc24a00000008844242f", argdata, 2, 2, &func);
}

bool ResourceControl::PreloadResources(bool unk)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func868::func;
	return execfunc(this, unk);
}

namespace _func869
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderLoadingBar", typeid(void (ResourceControl::*)(float , float )), "5557565381ec8c0000008b9c24a00000008d6c246e", argdata, 3, 6, &func);
}

void ResourceControl::RenderLoadingBar(float initialProgress, float finalProgress)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, float initialProgress_arg, float finalProgress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func869::func;
	return execfunc(this, initialProgress, finalProgress);
}

ResourceControl *Global_ResourceControl_GlobalResources;

namespace _var870
{
    static VariableDefinition varObj("Global_ResourceControl_GlobalResources", "!8b45e0890424e8????????c70424(???????\?)", &Global_ResourceControl_GlobalResources);
}

namespace _func871
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::constructor", typeid(void (RockAnimation::*)(const std::string &, int , Pointf , bool )), "5589e557565383ec4c8b450c8b751c8d5de4891c248b7d0889442404", argdata, 5, 6, &func);
}

void RockAnimation::constructor(const std::string &subRace, int iShipId, Pointf position, bool enemy)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(RockAnimation *this_arg, const std::string &subRace_arg, int iShipId_arg, Pointf position_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func871::func;
	return execfunc(this, subRace, iShipId, position, enemy);
}

namespace _func872
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK", typeid(void (RockAnimation::*)()), "5557565381ec0c010000803d????????000f85????????e8????????89c7", argdata, 0, 4, &func);
}

namespace _func873
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::GetShootingSound", typeid(std::string (RockAnimation::*)()), ".5557565381ec0c010000803d????????000f85????????e8????????89c7", argdata, 2, 18, &func);
}

std::string RockAnimation::GetShootingSound()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(RockAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func873::func;
	return execfunc(this);
}

namespace _func874
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK2", typeid(void (RockAnimation::*)()), "5383ec288b5c24308d44241f89442408c7442404????????891c24e8????????83c42889d85b", argdata, 0, 4, &func);
}

namespace _func875
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("RockAnimation::__DO_NOT_HOOK3", typeid(void (RockAnimation::*)()), ".5383ec288b5c24308d44241f89442408c7442404????????891c24e8????????83c42889d85b", argdata, 0, 4, &func);
}

namespace _func876
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("RockAnimation::GetDeathSound", typeid(std::string (RockAnimation::*)()), ".5383ec288b5c24308d44241f89442408c7442404????????891c24e8????????83c42889d85b", argdata, 2, 18, &func);
}

std::string RockAnimation::GetDeathSound()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(RockAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func876::func;
	return execfunc(this);
}

namespace _func877
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::GetEmptySlots", typeid(int (Room::*)(bool )), "56538b74240c0fb64c24108b4634", argdata, 2, 2, &func);
}

int Room::GetEmptySlots(bool intruder)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func877::func;
	return execfunc(this, intruder);
}

namespace _func878
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::Full", typeid(bool (Room::*)(bool )), ".56538b44240c0fb64c2410", argdata, 2, 2, &func);
}

bool Room::Full(bool intruder)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func878::func;
	return execfunc(this, intruder);
}

namespace _func879
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::GetEmptySlot", typeid(int (Room::*)(bool )), ".555756538b5424188b4c241484d2", argdata, 2, 2, &func);
}

int Room::GetEmptySlot(bool intruder)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func879::func;
	return execfunc(this, intruder);
}

namespace _func880
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Room::DO_NOT_HOOK", typeid(void (Room::*)()), ".56538b5c240c0fb64424148b4c2410", argdata, 0, 4, &func);
}

namespace _func881
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::FillSlot", typeid(void (Room::*)(int , bool )), ".56538b5c240c0fb64424148b4c2410", argdata, 3, 6, &func);
}

void Room::FillSlot(int slot, bool intruder)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, int slot_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func881::func;
	return execfunc(this, slot, intruder);
}

namespace _func882
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::constructor", typeid(void (Room::*)(int , int , int , int , int , int )), "5589e557565381ec2c0100008b45088b5508c7400400000000", argdata, 7, 6, &func);
}

void Room::constructor(int iShipId, int x, int y, int w, int h, int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, int iShipId_arg, int x_arg, int y_arg, int w_arg, int h_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func882::func;
	return execfunc(this, iShipId, x, y, w, h, roomId);
}

namespace _func883
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderFloor", typeid(void (Room::*)(float , bool )), "83ec3c8b4c2440f30f1005????????f30f100d????????", argdata, 3, 6, &func);
}

void Room::OnRenderFloor(float alpha, bool experimental)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg, bool experimental_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func883::func;
	return execfunc(this, alpha, experimental);
}

namespace _func884
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderWalls", typeid(void (Room::*)(float )), "5383ec188b5c2420f30f104c2424807b4000", argdata, 2, 6, &func);
}

void Room::OnRenderWalls(float alpha)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func884::func;
	return execfunc(this, alpha);
}

namespace _func885
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Room::destructor", typeid(void (Room::*)()), "5557565383ec4c8b442460c700????????c74008????????8b407c890424", argdata, 1, 6, &func);
}

void Room::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Room *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func885::func;
	return execfunc(this);
}

namespace _func886
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipUnlocked", typeid(bool (ScoreKeeper::*)(int , int )), "5531c057565381ec1c01000083bc243801000002", argdata, 3, 2, &func);
}

bool ScoreKeeper::GetShipUnlocked(int shipId, int shipVariant)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipId_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func886::func;
	return execfunc(this, shipId, shipVariant);
}

namespace _func887
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipBlueprint", typeid(std::string (ScoreKeeper::*)(int )), "5383ec188b4424288b5c2420??????????????89442404", argdata, 3, 18, &func);
}

std::string ScoreKeeper::GetShipBlueprint(int index)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int index_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func887::func;
	return execfunc(this, index);
}

namespace _func888
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::OnInit", typeid(void (ScoreKeeper::*)()), "5589e557565381ec9c0000008b5d08c744240400000000", argdata, 1, 6, &func);
}

void ScoreKeeper::OnInit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func888::func;
	return execfunc(this);
}

namespace _func889
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Save", typeid(void (ScoreKeeper::*)(bool )), "5589e557565383ec6c8b5d08c70424????????", argdata, 2, 6, &func);
}

void ScoreKeeper::Save(bool newHighScore)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool newHighScore_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func889::func;
	return execfunc(this, newHighScore);
}

namespace _func890
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::OnRender", typeid(void (ScoreKeeper::*)(bool )), "5589e557565381ec0c0200008b5d088b450c", argdata, 2, 6, &func);
}

void ScoreKeeper::OnRender(bool lastPlaythrough)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool lastPlaythrough_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func890::func;
	return execfunc(this, lastPlaythrough);
}

namespace _func891
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(void (ScoreKeeper::*)(int , int , bool , bool )), "555789cf5689c65389d383ec3c85d2", argdata, 5, 6, &func);
}

void ScoreKeeper::UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup)
{
	typedef void __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipType_arg, int shipVariant_arg, bool save_arg, bool hidePopup_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func891::func;
	return execfunc(this, shipType, shipVariant, save, hidePopup);
}

namespace _func892
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetVictory", typeid(void (ScoreKeeper::*)(bool )), "8b5424088b44240484d28890e4000000", argdata, 2, 6, &func);
}

void ScoreKeeper::SetVictory(bool victory)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool victory_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func892::func;
	return execfunc(this, victory);
}

namespace _func893
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::constructor", typeid(void (ScoreKeeper::*)()), "5557565383ec4c8b442460c70000000000", argdata, 1, 6, &func);
}

void ScoreKeeper::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func893::func;
	return execfunc(this);
}

namespace _func894
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipId", typeid(std::pair<int, int> (ScoreKeeper::*)(const std::string &)), "55575653bb????????83ec3c8b6c2458c744241800000000", argdata, 3, 18, &func);
}

std::pair<int, int> ScoreKeeper::GetShipId(const std::string &blueprintName)
{
	typedef std::pair<int, int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::string &blueprintName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func894::func;
	return execfunc(this, blueprintName);
}

namespace _func895
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::LoadVersionFour", typeid(void (ScoreKeeper::*)(int , int )), "5589e557565381ec8c0000008b4d108b45088b7d0c", argdata, 3, 6, &func);
}

void ScoreKeeper::LoadVersionFour(int file, int version)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int file_arg, int version_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func895::func;
	return execfunc(this, file, version);
}

namespace _func896
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::WipeProfile", typeid(void (ScoreKeeper::*)(bool )), "5557565383ec3c8b4c24508b442454", argdata, 2, 6, &func);
}

void ScoreKeeper::WipeProfile(bool permanent)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool permanent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func896::func;
	return execfunc(this, permanent);
}

namespace _func897
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::MouseClick", typeid(void (ScoreKeeper::*)(int , int )), "565383ec148b5c242080bb0809000000", argdata, 3, 6, &func);
}

void ScoreKeeper::MouseClick(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func897::func;
	return execfunc(this, x, y);
}

namespace _func898
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetupTopShip", typeid(void (ScoreKeeper::*)(int )), "5589e557565383ec5c8b5d088d75c8", argdata, 2, 6, &func);
}

void ScoreKeeper::SetupTopShip(int variant)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func898::func;
	return execfunc(this, variant);
}

namespace _func899
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::CheckTypes", typeid(void (ScoreKeeper::*)()), "5557565383ec2c8b6c2440c7442408010000008b85c4080000", argdata, 1, 6, &func);
}

void ScoreKeeper::CheckTypes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func899::func;
	return execfunc(this);
}

namespace _func900
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreType", typeid(void (ScoreKeeper::*)(TopScore &, int )), "5589e55789c7565389d381ec9c000000", argdata, 3, 6, &func);
}

void ScoreKeeper::AddTopScoreType(TopScore &topScore, int type)
{
	typedef void __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, TopScore &topScore_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func900::func;
	return execfunc(this, topScore, type);
}

namespace _func901
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddTopScoreList", typeid(int (ScoreKeeper::*)(TopScore &, std::vector<TopScore> &)), "5557565383ec4c8b5c24688b6c24648b4304", argdata, 3, 2, &func);
}

int ScoreKeeper::AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, TopScore &score_arg, std::vector<TopScore> &topScoreList_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func901::func;
	return execfunc(this, score, topScoreList);
}

namespace _func902
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::RenderTopScores", typeid(void (ScoreKeeper::*)(const std::vector<TopScore> &, Point , int )), "5589e557565381eccc0100008b4510", argdata, 4, 6, &func);
}

void ScoreKeeper::RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::vector<TopScore> &topScoreList_arg, Point position_arg, int newHighScore_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func902::func;
	return execfunc(this, topScoreList, position, newHighScore);
}

namespace _func903
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::CycleLeft", typeid(void (ScoreKeeper::*)()), "56be090000005383ec14", argdata, 1, 6, &func);
}

void ScoreKeeper::CycleLeft()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func903::func;
	return execfunc(this);
}

namespace _func904
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::CycleRight", typeid(void (ScoreKeeper::*)()), "5631f65383ec148b5c2420908d74??00", argdata, 1, 6, &func);
}

void ScoreKeeper::CycleRight()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func904::func;
	return execfunc(this);
}

namespace _func905
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Open", typeid(void (ScoreKeeper::*)(bool )), "5557565381ec9c0000008b9c24b0000000c74424080d000000", argdata, 2, 6, &func);
}

void ScoreKeeper::Open(bool fromGameOver)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool fromGameOver_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func905::func;
	return execfunc(this, fromGameOver);
}

namespace _func906
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::KeyDown", typeid(bool (ScoreKeeper::*)(SDLKey )), "565383ec148b5c24208b7424240fb68308090000", argdata, 2, 2, &func);
}

bool ScoreKeeper::KeyDown(SDLKey key)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func906::func;
	return execfunc(this, key);
}

namespace _func907
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddScrapCollected", typeid(void (ScoreKeeper::*)(int )), "565383ec24c70424????????8b5c24308b742434", argdata, 2, 6, &func);
}

void ScoreKeeper::AddScrapCollected(int scrap)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int scrap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func907::func;
	return execfunc(this, scrap);
}

namespace _func908
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SaveScores", typeid(void (ScoreKeeper::*)(int , std::vector<TopScore> &)), "55575631f65383ec4c8b442468", argdata, 3, 6, &func);
}

void ScoreKeeper::SaveScores(int file, std::vector<TopScore> &topScores)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int file_arg, std::vector<TopScore> &topScores_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func908::func;
	return execfunc(this, file, topScores);
}

namespace _func909
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SaveGame", typeid(void (ScoreKeeper::*)(int )), "!57565331db83ec10a1????????8b7424248b7c242089442404893424", argdata, 2, 6, &func);
}

void ScoreKeeper::SaveGame(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func909::func;
	return execfunc(this, fd);
}

namespace _func910
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::LoadGame", typeid(void (ScoreKeeper::*)(int )), ".5589e557565383ec2c8b750c8b7d08893424", argdata, 2, 6, &func);
}

void ScoreKeeper::LoadGame(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func910::func;
	return execfunc(this, fd);
}

namespace _func911
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::MouseMove", typeid(void (ScoreKeeper::*)(int , int )), ".5557565383ec2c8b5c24408b7c24448b6c2448", argdata, 3, 6, &func);
}

void ScoreKeeper::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func911::func;
	return execfunc(this, mX, mY);
}

namespace _func912
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetSector", typeid(void (ScoreKeeper::*)(int )), "8b4424048b542408c7401000000000", argdata, 2, 6, &func);
}

void ScoreKeeper::SetSector(int sector)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func912::func;
	return execfunc(this, sector);
}

ScoreKeeper *Global_ScoreKeeper_Keeper;

namespace _var913
{
    static VariableDefinition varObj("Global_ScoreKeeper_Keeper", "!c744240401000000c70424(???????\?)e8????????89742408", &Global_ScoreKeeper_Keeper);
}

namespace _func914
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(char (*)()), "0fb605????????c3908db4260000000083ec1c0fb605", argdata, 0, 0, &func);
}

char Settings::GetCommandConsole()
{
	typedef char __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func914::func;
	return execfunc();
}

namespace _func915
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetDlcEnabled", typeid(bool (*)()), "31c0803d????????0075??c38d74260083ec1c", argdata, 0, 0, &func);
}

bool Settings::GetDlcEnabled()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func915::func;
	return execfunc();
}

namespace _func916
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkeyName", typeid(std::string (*)(const std::string &)), "5589e557565383ec5c8b450c8d75d8", argdata, 2, 18, &func);
}

std::string Settings::GetHotkeyName(const std::string &name)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func916::func;
	return execfunc(name);
}

namespace _func917
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkey", typeid(SDLKey (*)(const std::string &)), "5557565383ec2cc744241c????????", argdata, 1, 2, &func);
}

SDLKey Settings::GetHotkey(const std::string &hotkeyName)
{
	typedef SDLKey __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func917::func;
	return execfunc(hotkeyName);
}

namespace _func918
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Settings::SetHotkey", typeid(void (*)(const std::string &, SDLKey )), "5557565383ec5cc744242c????????", argdata, 2, 6, &func);
}

void Settings::SetHotkey(const std::string &hotkeyName, SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func918::func;
	return execfunc(hotkeyName, key);
}

namespace _func919
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::SaveSettings", typeid(void (*)()), "5557565381ec3c0100008d84249c000000", argdata, 0, 6, &func);
}

void Settings::SaveSettings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func919::func;
	return execfunc();
}

namespace _func920
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::ResetHotkeys", typeid(void (*)()), "5557bf????????565383ec4c8d6c2430", argdata, 0, 6, &func);
}

void Settings::ResetHotkeys()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func920::func;
	return execfunc();
}

namespace _func921
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::LoadSettings", typeid(void (*)()), "5589e557565381ec9c01000065a114000000", argdata, 0, 6, &func);
}

void Settings::LoadSettings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func921::func;
	return execfunc();
}

SettingValues *Global_Settings_Settings;

namespace _var922
{
    static VariableDefinition varObj("Global_Settings_Settings", "!89c557565383ec2cc744241c(???????\?)", &Global_Settings_Settings);
}

namespace _func923
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Shields::SetHackingLevel", typeid(void (Shields::*)(int )), "538b54????8b44????83fa01", argdata, 2, 6, &func);
}

void Shields::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func923::func;
	return execfunc(this, hackingLevel);
}

namespace _func924
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("Shields::CollisionReal", typeid(CollisionResponse (Shields::*)(float , float , Damage , bool )), "5557565381ec9c0000008b8424c00000008bac24b0000000", argdata, 6, 18, &func);
}

CollisionResponse Shields::CollisionReal(float x, float y, Damage damage, bool force)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, float x_arg, float y_arg, Damage damage_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func924::func;
	return execfunc(this, x, y, damage, force);
}

namespace _func925
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Shields::constructor", typeid(void (Shields::*)(int , int , int , const std::string &)), "57565383ec508b44246c8b5c2460c744240400000000", argdata, 5, 6, &func);
}

void Shields::constructor(int roomId, int shipId, int startingPower, const std::string &shieldFile)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, int roomId_arg, int shipId_arg, int startingPower_arg, const std::string &shieldFile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func925::func;
	return execfunc(this, roomId, shipId, startingPower, shieldFile);
}

namespace _func926
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("Shields::SetBaseEllipse", typeid(void (Shields::*)(Globals::Ellipse )), "8b4c2404f30f10442410f30f104c2414", argdata, 2, 6, &func);
}

void Shields::SetBaseEllipse(Globals::Ellipse ellipse)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, Globals::Ellipse ellipse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func926::func;
	return execfunc(this, ellipse);
}

namespace _func927
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Shields::InstantCharge", typeid(void (Shields::*)()), "57565383ec208b5c2430891c248db310020000", argdata, 1, 6, &func);
}

void Shields::InstantCharge()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func927::func;
	return execfunc(this);
}

namespace _func928
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Shields::Jump", typeid(void (Shields::*)()), "57565383ec208b5c24308d74241c891c24", argdata, 1, 6, &func);
}

void Shields::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func928::func;
	return execfunc(this);
}

namespace _func929
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Shields::OnLoop", typeid(void (Shields::*)()), "5557565383ec3c8b5c24508d74242c891c24e8????????8d44242a", argdata, 1, 6, &func);
}

void Shields::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func929::func;
	return execfunc(this);
}

namespace _func930
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Shields::AddSuperShield", typeid(void (Shields::*)(Point )), "57ba05000000565383ec108b5c24208b7424248b7c2428", argdata, 2, 6, &func);
}

void Shields::AddSuperShield(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func930::func;
	return execfunc(this, pos);
}

namespace _func931
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Shields::RenderBase", typeid(void (Shields::*)(float , float )), "5557565381ec8c0000008b9c24a00000008b83c4010000", argdata, 3, 6, &func);
}

void Shields::RenderBase(float alpha, float superShieldOverwrite)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, float alpha_arg, float superShieldOverwrite_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func931::func;
	return execfunc(this, alpha, superShieldOverwrite);
}

namespace _func932
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("Shields::CollisionTest", typeid(CollisionResponse (Shields::*)(float , float , Damage )), "565383ec148b5c24208b7424248d4304c70300000000c7442408000000cf", argdata, 5, 18, &func);
}

CollisionResponse Shields::CollisionTest(float x, float y, Damage damage)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(Shields *this_arg, float x_arg, float y_arg, Damage damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func932::func;
	return execfunc(this, x, y, damage);
}

GL_Color *Global_COLOR_GREEN;

namespace _var933
{
    static VariableDefinition varObj("Global_COLOR_GREEN", "!f30f101d(???????\?)f30f1025????????f30f1015", &Global_COLOR_GREEN);
}

namespace _func934
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetSelectedRoomId", typeid(int (Ship::*)(int , int , bool )), "57565383ec108b4424208b7424248b7c24288b5c242c8b40040fb6db890424e8????????895c242c897c2428897424248944242083c4105b5e5fe9????????9057", argdata, 4, 2, &func);
}

int Ship::GetSelectedRoomId(int x, int y, bool unk)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int x_arg, int y_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func934::func;
	return execfunc(this, x, y, unk);
}

namespace _func935
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Ship::LockdownRoom", typeid(void (Ship::*)(int , Pointf )), "5589e557565381ec2c0100008b45088b4004890424", argdata, 3, 6, &func);
}

void Ship::LockdownRoom(int roomId, Pointf pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, Pointf pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func935::func;
	return execfunc(this, roomId, pos);
}

namespace _func936
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::RoomLocked", typeid(bool (Ship::*)(int )), "538b4424088b5c240c8b90f40200008b88f8020000", argdata, 2, 2, &func);
}

bool Ship::RoomLocked(int roomId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func936::func;
	return execfunc(this, roomId);
}

namespace _func937
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Ship::DestroyedDone", typeid(bool (Ship::*)()), "8b54????0fb682a0010000", argdata, 1, 2, &func);
}

bool Ship::DestroyedDone()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func937::func;
	return execfunc(this);
}

namespace _func938
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::FullRoom", typeid(bool (Ship::*)(int , bool )), "538b4424088b54240c8b5c24108b48088b400c", argdata, 3, 2, &func);
}

bool Ship::FullRoom(int roomId, bool intruder)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func938::func;
	return execfunc(this, roomId, intruder);
}

namespace _func939
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::EmptySlots", typeid(int (Ship::*)(int )), "5557565331db83ec1c8b6c24308b4424348b5508", argdata, 2, 2, &func);
}

int Ship::EmptySlots(int roomId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func939::func;
	return execfunc(this, roomId);
}

namespace _func940
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetAvailableRoomSlot", typeid(int (Ship::*)(int , bool )), "0fb644240c8b542408894424088b4424048b40088b049089442404e9????????8b442404", argdata, 3, 2, &func);
}

int Ship::GetAvailableRoomSlot(int roomId, bool intruder)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func940::func;
	return execfunc(this, roomId, intruder);
}

namespace _func941
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderBreaches", typeid(void (Ship::*)()), "565331db83ec148b7424208b56208b462429d0", argdata, 1, 6, &func);
}

void Ship::OnRenderBreaches()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func941::func;
	return execfunc(this);
}

namespace _func942
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderWalls", typeid(void (Ship::*)(bool , bool )), "555731ff565383ec4c8b5c24600fb6442464", argdata, 3, 6, &func);
}

void Ship::OnRenderWalls(bool forceView, bool doorControlMode)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, bool forceView_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func942::func;
	return execfunc(this, forceView, doorControlMode);
}

namespace _func943
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnInit", typeid(void (Ship::*)(ShipBlueprint *)), "5589e557565381ecfc0101008b45088b5d0c", argdata, 2, 6, &func);
}

void Ship::OnInit(ShipBlueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, ShipBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func943::func;
	return execfunc(this, bp);
}

namespace _func944
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderSparks", typeid(void (Ship::*)()), "565331db83ec148b7424208b56088b460c29d0c1f80285c074??8db6000000008b049a83c301890424e8????????8b56088b460c29d0c1f80239c372??83c4145b5ec3908db6000000008dbf00000000565331db83ec14", argdata, 1, 6, &func);
}

void Ship::OnRenderSparks()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func944::func;
	return execfunc(this);
}

namespace _func945
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::SetRoomBlackout", typeid(void (Ship::*)(int , bool )), "0fb644240c8b542408894424088b4424048b40088b049089442404e9????????538b4424088b5c240c", argdata, 3, 6, &func);
}

void Ship::SetRoomBlackout(int roomId, bool blackout)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool blackout_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func945::func;
	return execfunc(this, roomId, blackout);
}

namespace _func946
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderBase", typeid(void (Ship::*)(bool )), "5557565383ec3c8b5c24508b6c24548b4304", argdata, 2, 6, &func);
}

void Ship::OnRenderBase(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func946::func;
	return execfunc(this, unk);
}

namespace _func947
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderFloor", typeid(void (Ship::*)(bool )), "565383ec248b5c24308b74243480bbf002000000", argdata, 2, 6, &func);
}

void Ship::OnRenderFloor(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func947::func;
	return execfunc(this, unk);
}

namespace _func948
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderJump", typeid(void (Ship::*)(float )), "5557565383ec5c8b5c24708b4304890424", argdata, 2, 6, &func);
}

void Ship::OnRenderJump(float progress)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func948::func;
	return execfunc(this, progress);
}

namespace _func949
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetShipCorner", typeid(Point (Ship::*)()), ".565383ec148b5c????8b74????8b4304", argdata, 2, 18, &func);
}

Point Ship::GetShipCorner()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func949::func;
	return execfunc(this);
}

namespace _func950
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetBaseEllipse", typeid(Globals::Ellipse (Ship::*)()), "565383ec248b7424348b5c24308b86a4010000", argdata, 2, 18, &func);
}

Globals::Ellipse Ship::GetBaseEllipse()
{
	typedef Globals::Ellipse __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func950::func;
	return execfunc(this);
}

namespace _func951
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::SetSelectedRoom", typeid(void (Ship::*)(int )), "57565331db83ec108b7c24208b7424248b57088b470c", argdata, 2, 6, &func);
}

void Ship::SetSelectedRoom(int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func951::func;
	return execfunc(this, roomId);
}

namespace _func952
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnLoop", typeid(void (Ship::*)(std::vector<float> &)), "5589e557565381ec8c0000008b45088b5d0c8db0d4020000", argdata, 2, 6, &func);
}

void Ship::OnLoop(std::vector<float> &oxygenLevels)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, std::vector<float> &oxygenLevels_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func952::func;
	return execfunc(this, oxygenLevels);
}

namespace _func953
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::BreachRandomHull", typeid(void (Ship::*)(int )), "5557565383ec5c8b7c24708b742474c7442440????????", argdata, 2, 6, &func);
}

void Ship::BreachRandomHull(int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func953::func;
	return execfunc(this, roomId);
}

namespace _func954
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetAvailableRoom", typeid(int (Ship::*)(int , bool )), "5589e557565383ec5c8b5510", argdata, 3, 2, &func);
}

int Ship::GetAvailableRoom(int preferred, bool intruder)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int preferred_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func954::func;
	return execfunc(this, preferred, intruder);
}

namespace _func955
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::BreachSpecificHull", typeid(bool (Ship::*)(int , int )), "5589e557565383ec4c8b450c8b7d10", argdata, 3, 2, &func);
}

bool Ship::BreachSpecificHull(int grid_x, int grid_y)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, int grid_x_arg, int grid_y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func955::func;
	return execfunc(this, grid_x, grid_y);
}

namespace _func956
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetHullBreaches", typeid(std::vector<Repairable*> (Ship::*)(bool )), "57565383ec208b7c24348b5c24308b4c2438", argdata, 3, 18, &func);
}

std::vector<Repairable*> Ship::GetHullBreaches(bool onlyDamaged)
{
	typedef std::vector<Repairable*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(Ship *this_arg, bool onlyDamaged_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func956::func;
	return execfunc(this, onlyDamaged);
}

namespace _noop957
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_0", "!39d07d0b(c6840d74fefeff01)");
}

namespace _noop958
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_1", "!39d07d03(c60101)");
}

namespace _noop959
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_2", "!89d37d03(c60101)");
}

namespace _noop960
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_3", "!39c27d0b(c6840d70fefeff01)");
}

namespace _noop961
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_4", "!39c27d03(c60101)");
}

namespace _noop962
{
    static NoOpDefinition noOpObj("Global__NOP__Ship_OnInit_5", "!89c37e03(c60101)");
}

namespace _func963
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::constructor", typeid(void (ShipAI::*)(bool )), "565383ec148b5c24208b7424248d4308", argdata, 2, 6, &func);
}

void ShipAI::constructor(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func963::func;
	return execfunc(this, unk);
}

namespace _func964
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), ".8b4424088b54240484c0", argdata, 2, 6, &func);
}

void ShipAI::SetStalemate(bool stalemate)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool stalemate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func964::func;
	return execfunc(this, stalemate);
}

namespace _func965
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::OnLoop", typeid(void (ShipAI::*)(bool )), "5589e557565383ec4c8b750c8b5d0889f084c0", argdata, 2, 6, &func);
}

void ShipAI::OnLoop(bool hostile)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func965::func;
	return execfunc(this, hostile);
}

namespace _func966
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::GetTeleportCommand", typeid(std::pair<int, int> (ShipAI::*)()), "565383ec148b7424248b5c24208b4604", argdata, 2, 18, &func);
}

std::pair<int, int> ShipAI::GetTeleportCommand()
{
	typedef std::pair<int, int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func966::func;
	return execfunc(this);
}

namespace _func967
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBlueprint::destructor", typeid(void (ShipBlueprint::*)()), "5557565383ec2c8b5c24408d7c241fc703????????", argdata, 1, 6, &func);
}

void ShipBlueprint::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func967::func;
	return execfunc(this);
}

namespace _func968
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(void (ShipBuilder::*)()), "5557565383ec2c8b6c2440c7442408010000008b85580f00008db578090000", argdata, 1, 6, &func);
}

void ShipBuilder::CheckTypes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func968::func;
	return execfunc(this);
}

namespace _func969
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseClick", typeid(void (ShipBuilder::*)(int , int )), "5557565383ec3c8b74245080beac15000000", argdata, 3, 6, &func);
}

void ShipBuilder::MouseClick(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func969::func;
	return execfunc(this, x, y);
}

namespace _func970
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(void (ShipBuilder::*)(int , int )), "5589e557565383ec2c8b5d088b45108b7d0c", argdata, 3, 6, &func);
}

void ShipBuilder::SwitchShip(int shipType, int shipVariant)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int shipType_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func970::func;
	return execfunc(this, shipType, shipVariant);
}

namespace _func971
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::CreateEquipmentBoxes", typeid(void (ShipBuilder::*)()), "5557565383ec5c8b5c24708b8b340e0000", argdata, 1, 6, &func);
}

void ShipBuilder::CreateEquipmentBoxes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func971::func;
	return execfunc(this);
}

namespace _func972
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::CreateSystemBoxes", typeid(void (ShipBuilder::*)()), "5557565383ec3c8b6c24508b8dc80e0000", argdata, 1, 6, &func);
}

void ShipBuilder::CreateSystemBoxes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func972::func;
	return execfunc(this);
}

namespace _func973
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SetupShipAchievements", typeid(void (ShipBuilder::*)()), "5589e557565383ec4c8b75088d7dd88d5db8", argdata, 1, 6, &func);
}

void ShipBuilder::SetupShipAchievements()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func973::func;
	return execfunc(this);
}

namespace _func974
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::ClearShipAchievements", typeid(void (ShipBuilder::*)()), "8b4424048b9058170000c78064170000ffffffff", argdata, 1, 6, &func);
}

void ShipBuilder::ClearShipAchievements()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func974::func;
	return execfunc(this);
}

namespace _func975
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(void (ShipBuilder::*)(int )), "5383ec188b5c24208b0385c0", argdata, 2, 6, &func);
}

void ShipBuilder::SwapType(int variant)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func975::func;
	return execfunc(this, variant);
}

namespace _func976
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipNext", typeid(void (ShipBuilder::*)()), "575631f65383ec108b7c24208b8700170000", argdata, 1, 6, &func);
}

void ShipBuilder::CycleShipNext()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func976::func;
	return execfunc(this);
}

namespace _func977
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::CycleShipPrevious", typeid(void (ShipBuilder::*)()), "5756be020000005383ec108b7c24208b8700170000", argdata, 1, 6, &func);
}

void ShipBuilder::CycleShipPrevious()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func977::func;
	return execfunc(this);
}

namespace _func978
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(void (ShipBuilder::*)()), "5589e557565381ec2c0300008b4508c6808c17000000", argdata, 1, 6, &func);
}

void ShipBuilder::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func978::func;
	return execfunc(this);
}

namespace _func979
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::OnRender", typeid(void (ShipBuilder::*)()), "5589e557565381ecbc0000008b5d0880bb4410000000", argdata, 1, 6, &func);
}

void ShipBuilder::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func979::func;
	return execfunc(this);
}

namespace _func980
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::OnLoop", typeid(void (ShipBuilder::*)()), "5589e557565383ec5c8b5d08c70424????????", argdata, 1, 6, &func);
}

void ShipBuilder::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func980::func;
	return execfunc(this);
}

namespace _func981
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::constructor", typeid(void (ShipBuilder::*)()), "565383ec348b5c24408d74242c8d430c", argdata, 1, 6, &func);
}

void ShipBuilder::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func981::func;
	return execfunc(this);
}

namespace _func982
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseMove", typeid(void (ShipBuilder::*)(int , int )), "5589e557565381ecac0000008b7d088d873c0e0000", argdata, 3, 6, &func);
}

void ShipBuilder::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func982::func;
	return execfunc(this, x, y);
}

namespace _func983
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::OnKeyDown", typeid(void (ShipBuilder::*)(SDLKey )), "5557565383ec1c8b7424308b44243480be4410000000", argdata, 2, 6, &func);
}

void ShipBuilder::OnKeyDown(SDLKey key)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func983::func;
	return execfunc(this, key);
}

namespace _func984
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::GetShip", typeid(ShipManager *(ShipBuilder::*)()), "5531c089e556", argdata, 1, 2, &func);
}

ShipManager *ShipBuilder::GetShip()
{
	typedef ShipManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func984::func;
	return execfunc(this);
}

namespace _func985
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipButton::constructor", typeid(void (ShipButton::*)(int , int )), "5589e557565381ecbc0100008b5d088d??????????", argdata, 3, 6, &func);
}

void ShipButton::constructor(int shipType, int shipVariant)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipButton *this_arg, int shipType_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func985::func;
	return execfunc(this, shipType, shipVariant);
}

namespace _func986
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipButton::OnInit", typeid(void (ShipButton::*)(const std::string &, Point )), "5383ec188b5c24208b5424288b44242c807b7000", argdata, 3, 6, &func);
}

void ShipButton::OnInit(const std::string &imgName, Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipButton *this_arg, const std::string &imgName_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func986::func;
	return execfunc(this, imgName, pos);
}

namespace _func987
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipButton::MouseMove", typeid(void (ShipButton::*)(int , int )), "5557565383ec2c8b5c24408b742444807b7000", argdata, 3, 6, &func);
}

void ShipButton::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipButton *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func987::func;
	return execfunc(this, x, y);
}

namespace _func988
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipButton::OnRender", typeid(void (ShipButton::*)()), "5589e557565383ec7c8b5d08807b7000", argdata, 1, 6, &func);
}

void ShipButton::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func988::func;
	return execfunc(this);
}

namespace _func989
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipEvent::constructor", typeid(void (ShipEvent::*)(const ShipEvent &)), "5531ed57565331db83ec1c8b7c24348b7424300fb607", argdata, 2, 6, &func);
}

void ShipEvent::constructor(const ShipEvent &event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipEvent *this_arg, const ShipEvent &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func989::func;
	return execfunc(this, event);
}

namespace _func990
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::CreateShip", typeid(ShipManager *(*)(const std::string &, int , ShipEvent &)), "5589e557565381ec1c0300008b4510", argdata, 3, 2, &func);
}

ShipManager *ShipGenerator::CreateShip(const std::string &name, int sector, ShipEvent &event)
{
	typedef ShipManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg, int sector_arg, ShipEvent &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func990::func;
	return execfunc(name, sector, event);
}

namespace _func991
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GenerateSystemMaxes", typeid(std::vector<int> (*)(const ShipBlueprint &, int )), "5557565331db83ec3c8b4424548b7c2450", argdata, 3, 18, &func);
}

std::vector<int> ShipGenerator::GenerateSystemMaxes(const ShipBlueprint &ship, int level)
{
	typedef std::vector<int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(const ShipBlueprint &ship_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func991::func;
	return execfunc(ship, level);
}

namespace _func992
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::UpgradeSystem", typeid(bool (*)(ShipManager *, std::vector<int> &, unsigned int )), "5589e557565383ec4c8b4510894424048b4508890424", argdata, 3, 2, &func);
}

bool ShipGenerator::UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, unsigned int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func992::func;
	return execfunc(ship, systemMaxes, sysId);
}

namespace _func993
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "5589e557565383ec4c8b45088b7d10c745b800000000", argdata, 5, 18, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func993::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func994
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades2", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "5589e55789cf565383ec5c8945acc70000000000c7400400000000c7400800000000", argdata, 5, 18, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades2(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func994::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func995
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades0", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), ".5589e55789cf565383ec5c8945acc70000000000c7400400000000c7400800000000", argdata, 5, 18, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades0(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func995::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func996
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102, 0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades1", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), ".5589e55789cf565383ec5c8945acc70000000000c7400400000000c7400800000000", argdata, 5, 18, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades1(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((regparm(3))) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func996::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func997
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleWeaponList", typeid(std::vector<WeaponBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int )), "5589e557565383ec5c8b450c890424", argdata, 5, 18, &func);
}

std::vector<WeaponBlueprint*> ShipGenerator::GetPossibleWeaponList(ShipManager *ship, const std::string &weaponList, int scrap, unsigned int flags)
{
	typedef std::vector<WeaponBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &weaponList_arg, int scrap_arg, unsigned int flags_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func997::func;
	return execfunc(ship, weaponList, scrap, flags);
}

namespace _func998
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleDroneList", typeid(std::vector<DroneBlueprint*> (*)(ShipManager *, const std::string &, int , unsigned int , bool )), "5589e557565383ec7c8b451c89459c8845a48b450c890424", argdata, 6, 18, &func);
}

std::vector<DroneBlueprint*> ShipGenerator::GetPossibleDroneList(ShipManager *ship, const std::string &droneList, int scrap, unsigned int flags, bool repeat)
{
	typedef std::vector<DroneBlueprint*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &droneList_arg, int scrap_arg, unsigned int flags_arg, bool repeat_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func998::func;
	return execfunc(ship, droneList, scrap, flags, repeat);
}

namespace _func999
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleCrewList", typeid(std::vector<CrewBlueprint> (*)(ShipManager *, const std::string &, unsigned int )), "5589e557565381ecfc0000008b4508c70000000000c7400400000000c7400800000000", argdata, 4, 18, &func);
}

std::vector<CrewBlueprint> ShipGenerator::GetPossibleCrewList(ShipManager *ship, const std::string &crewList, unsigned int flags)
{
	typedef std::vector<CrewBlueprint> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, const std::string &crewList_arg, unsigned int flags_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func999::func;
	return execfunc(ship, crewList, flags);
}

namespace _func1000
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetShipInfo", typeid(ShipGraph *(*)(int )), "575381ec84000000a1????????", argdata, 1, 2, &func);
}

ShipGraph *ShipGraph::GetShipInfo(int shipId)
{
	typedef ShipGraph *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1000::func;
	return execfunc(shipId);
}

namespace _func1001
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotWorldPosition", typeid(Point (ShipGraph::*)(int , int )), "5589e5565383ec208b550c8b4d14", argdata, 4, 18, &func);
}

Point ShipGraph::GetSlotWorldPosition(int slotId, int roomId)
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1001::func;
	return execfunc(this, slotId, roomId);
}

namespace _func1002
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotRenderPosition", typeid(Point (ShipGraph::*)(int , int , bool )), "5589e557565383ec4c8b7d0c8b75148b4518", argdata, 5, 18, &func);
}

Point ShipGraph::GetSlotRenderPosition(int slotId, int roomId, bool intruder)
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int slotId_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1002::func;
	return execfunc(this, slotId, roomId, intruder);
}

namespace _func1003
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), "538b4424088b4c240c8b58188b501c", argdata, 2, 2, &func);
}

int ShipGraph::DoorCount(int roomId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1003::func;
	return execfunc(this, roomId);
}

namespace _func1004
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(std::vector<Door*> (ShipGraph::*)(int )), "5557565331db83ec1c8b7424308b7c2434c70600000000", argdata, 3, 18, &func);
}

std::vector<Door*> ShipGraph::GetDoors(int roomId)
{
	typedef std::vector<Door*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1004::func;
	return execfunc(this, roomId);
}

namespace _func1005
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::IsRoomConnected", typeid(bool (ShipGraph::*)(int , int )), "5557bf01000000565383ec2c8b5c24443b5c24488b742440", argdata, 3, 2, &func);
}

bool ShipGraph::IsRoomConnected(int room1, int room2)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room1_arg, int room2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1005::func;
	return execfunc(this, room1, room2);
}

namespace _func1006
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(int , int , int , int )), "5589e557565383ec6c8b45108d5dd8", argdata, 5, 2, &func);
}

Door *ShipGraph::ConnectingDoor(int x1, int y1, int x2, int y2)
{
	typedef Door *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x1_arg, int y1_arg, int x2_arg, int y2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1006::func;
	return execfunc(this, x1, y1, x2, y2);
}

namespace _func1007
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquares", typeid(int (ShipGraph::*)(int , int , int , int )), "5531ed57565383ec7c6b84249800000023", argdata, 5, 2, &func);
}

int ShipGraph::ConnectedGridSquares(int x1, int y1, int x2, int y2)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x1_arg, int y1_arg, int x2_arg, int y2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1007::func;
	return execfunc(this, x1, y1, x2, y2);
}

namespace _func1008
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectedGridSquaresPoint", typeid(int (ShipGraph::*)(Point , Point )), "5531ed57565383ec7c6b84249800000023", argdata, 3, 2, &func);
}

int ShipGraph::ConnectedGridSquaresPoint(Point p1, Point p2)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1008::func;
	return execfunc(this, p1, p2);
}

namespace _func1009
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(Point , Point )), "5589e557565383ec6c8b45108d5dd8", argdata, 3, 2, &func);
}

Door *ShipGraph::ConnectingDoor(Point p1, Point p2)
{
	typedef Door *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1009::func;
	return execfunc(this, p1, p2);
}

namespace _func1010
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), "8b4424048b5424088b008b0490", argdata, 2, 2, &func);
}

int ShipGraph::GetNumSlots(int room)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1010::func;
	return execfunc(this, room);
}

namespace _func1011
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::PopClosestDoor", typeid(int (ShipGraph::*)(std::vector<int> &, std::vector<float> &)), "5557565331db83ec2c8b4424448b38", argdata, 3, 2, &func);
}

int ShipGraph::PopClosestDoor(std::vector<int> &doors, std::vector<float> &distances)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, std::vector<int> &doors_arg, std::vector<float> &distances_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1011::func;
	return execfunc(this, doors, distances);
}

namespace _func1012
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::Dijkstra", typeid(Path (ShipGraph::*)(Point , Point , int )), "5589e557565381ec8c0000008b45188b750c8b7d14", argdata, 5, 18, &func);
}

Path ShipGraph::Dijkstra(Point start, Point goal, int shipId)
{
	typedef Path __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point start_arg, Point goal_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1012::func;
	return execfunc(this, start, goal, shipId);
}

namespace _func1013
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(Path (ShipGraph::*)(Point , Point , int )), "5589e557565383ec5c8b45188b5d0c", argdata, 5, 18, &func);
}

Path ShipGraph::FindPath(Point p1, Point p2, int shipId)
{
	typedef Path __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1013::func;
	return execfunc(this, p1, p2, shipId);
}

namespace _func1014
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldAngle", typeid(float (ShipGraph::*)(float )), "83ec048b442408f30f1044240cf30f584034", argdata, 2, 2, &func);
}

float ShipGraph::ConvertToWorldAngle(float ang)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, float ang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1014::func;
	return execfunc(this, ang);
}

namespace _func1015
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalAngle", typeid(float (ShipGraph::*)(float )), "83ec048b442408f30f1044240cf30f5c4034", argdata, 2, 2, &func);
}

float ShipGraph::ConvertToLocalAngle(float ang)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, float ang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1015::func;
	return execfunc(this, ang);
}

namespace _func1016
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToWorldPosition", typeid(Pointf (ShipGraph::*)(Pointf )), "5589e5565383ec208b5d0c8b7508", argdata, 3, 18, &func);
}

Pointf ShipGraph::ConvertToWorldPosition(Pointf local)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Pointf local_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1016::func;
	return execfunc(this, local);
}

namespace _func1017
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ConvertToLocalPosition", typeid(Pointf (ShipGraph::*)(Pointf , bool )), "5589e5565383ec208b450c807d1800", argdata, 4, 18, &func);
}

Pointf ShipGraph::ConvertToLocalPosition(Pointf world, bool past)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Pointf world_arg, bool past_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1017::func;
	return execfunc(this, world, past);
}

namespace _func1018
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(void (ShipGraph::*)()), "5589e557565383ec3c8b7d088b4508", argdata, 1, 6, &func);
}

void ShipGraph::ComputeCenter()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1018::func;
	return execfunc(this);
}

namespace _func1019
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::ContainsPoint", typeid(bool (ShipGraph::*)(int , int )), "538b54240831c08b4c240c8b5a44", argdata, 3, 2, &func);
}

bool ShipGraph::ContainsPoint(int x, int y)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1019::func;
	return execfunc(this, x, y);
}

namespace _func1020
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), "555731ff565383ec1c8b7424300fb65c243c", argdata, 4, 2, &func);
}

int ShipGraph::GetSelectedRoom(int x, int y, bool unk)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1020::func;
	return execfunc(this, x, y, unk);
}

namespace _func1021
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), "8b5424048b42042b02", argdata, 1, 2, &func);
}

int ShipGraph::RoomCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1021::func;
	return execfunc(this);
}

namespace _func1022
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomShape", typeid(Globals::Rect (ShipGraph::*)(int )), "5589e557565383ec1c8b550c8b4508", argdata, 3, 18, &func);
}

Globals::Rect ShipGraph::GetRoomShape(int room)
{
	typedef Globals::Rect __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1022::func;
	return execfunc(this, room);
}

namespace _func1023
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomOxygen", typeid(float (ShipGraph::*)(int )), "5383ec048b15????????8b4c24108b44240c85c978??8b18", argdata, 2, 2, &func);
}

float ShipGraph::GetRoomOxygen(int room)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1023::func;
	return execfunc(this, room);
}

namespace _func1024
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), "538b4c240cb8010000008b54240885c9", argdata, 2, 2, &func);
}

bool ShipGraph::GetRoomBlackedOut(int room)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1024::func;
	return execfunc(this, room);
}

namespace _func1025
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipGraph::Restart", typeid(void (*)()), ".5557565383ec3c8b2d", argdata, 0, 6, &func);
}

void ShipGraph::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1025::func;
	return execfunc();
}

namespace _func1026
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetClosestSlot", typeid(Slot (ShipGraph::*)(Point , int , bool )), "5589e5575631f65389f381ecac0000008b45108b7d0c", argdata, 5, 18, &func);
}

Slot ShipGraph::GetClosestSlot(Point pos, int shipId, bool intruder)
{
	typedef Slot __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point pos_arg, int shipId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1026::func;
	return execfunc(this, pos, shipId, intruder);
}

namespace _func1027
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::AddAugmentation", typeid(char (ShipInfo::*)(const std::string &)), "5531c089e557565383ec6c8b5508837a3002", argdata, 2, 2, &func);
}

char ShipInfo::AddAugmentation(const std::string &augment)
{
	typedef char __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1027::func;
	return execfunc(this, augment);
}

namespace _func1028
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::HasAugmentation", typeid(bool (ShipInfo::*)(const std::string &)), "5589e557565383ec5c8b450883c00489c78945b8", argdata, 2, 2, &func);
}

bool ShipInfo::HasAugmentation(const std::string &augment)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1028::func;
	return execfunc(this, augment);
}

namespace _func1029
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipInfo::GetAugmentationValue", typeid(float (ShipInfo::*)(const std::string &)), ".5589e557565383ec6c8b450c894424048d45c8890424", argdata, 2, 2, &func);
}

float ShipInfo::GetAugmentationValue(const std::string &augment)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipInfo *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1029::func;
	return execfunc(this, augment);
}

namespace _func1030
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::constructor", typeid(int (ShipManager::*)(int )), "5557565381ec9c0000008bb424b00000008b9c24b4000000", argdata, 2, 2, &func);
}

int ShipManager::constructor(int shipId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1030::func;
	return execfunc(this, shipId);
}

namespace _func1031
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddInitialCrew", typeid(void (ShipManager::*)(std::vector<CrewBlueprint> &)), "5589e557565381ecfc0000008b7d088d9d38ffffff", argdata, 2, 6, &func);
}

void ShipManager::AddInitialCrew(std::vector<CrewBlueprint> &blueprints)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, std::vector<CrewBlueprint> &blueprints_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1031::func;
	return execfunc(this, blueprints);
}

namespace _func1032
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), "5383ec188b5c24208b93000400008b420483f8ff74??8b4b188b0c818b818001000085c07e??80b9840100000074??83f80174??31c0", argdata, 1, 2, &func);
}

int ShipManager::GetDodgeFactor()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1032::func;
	return execfunc(this);
}

namespace _func1033
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnRender", typeid(void (ShipManager::*)(bool , bool )), "5589e557565381ecdc0000008b5d0c8b4510", argdata, 3, 6, &func);
}

void ShipManager::OnRender(bool showInterior, bool doorControlMode)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool showInterior_arg, bool doorControlMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1033::func;
	return execfunc(this, showInterior, doorControlMode);
}

namespace _func1034
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrew", typeid(int (ShipManager::*)(bool )), "5557565383ec1c8b7c24300fb6442434", argdata, 2, 2, &func);
}

int ShipManager::CountCrew(bool boarders)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool boarders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1034::func;
	return execfunc(this, boarders);
}

namespace _func1035
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::TeleportCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(int , bool )), "5557565331db83ec1c0fb644243c", argdata, 4, 18, &func);
}

std::vector<CrewMember*> ShipManager::TeleportCrew(int roomId, bool intruders)
{
	typedef std::vector<CrewMember*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1035::func;
	return execfunc(this, roomId, intruders);
}

namespace _func1036
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::OnInit", typeid(int (ShipManager::*)(ShipBlueprint *, int )), "5589e557565383ec6c8b7d088b450c8b7510", argdata, 3, 2, &func);
}

int ShipManager::OnInit(ShipBlueprint *bp, int shipLevel)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, ShipBlueprint *bp_arg, int shipLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1036::func;
	return execfunc(this, bp, shipLevel);
}

namespace _func1037
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(bool (ShipManager::*)(int )), "8b44240883f81174??8b5424048b9200040000", argdata, 2, 2, &func);
}

bool ShipManager::HasSystem(int systemId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1037::func;
	return execfunc(this, systemId);
}

namespace _func1038
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemRoom", typeid(int (ShipManager::*)(int )), ".8b54????8b4c????8b82000400008b048883f8ff74??8b52188b04828b108944????8b4258ffe0", argdata, 2, 2, &func);
}

int ShipManager::SystemRoom(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1038::func;
	return execfunc(this, systemId);
}

namespace _func1039
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), "5557565331db83ec1c8b6c24308b7424348b55188b451c", argdata, 2, 2, &func);
}

ShipSystem *ShipManager::GetSystemInRoom(int roomId)
{
	typedef ShipSystem *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1039::func;
	return execfunc(this, roomId);
}

namespace _func1040
{
    static void *func = 0;
	static short argdata[] = {0x100};
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(void (ShipManager::*)()), "5589e5575689c65381ec1c010000", argdata, 1, 6, &func);
}

void ShipManager::OnLoop()
{
	typedef void __attribute__((regparm(1))) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1040::func;
	return execfunc(this);
}

namespace _func1041
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLimit", typeid(void (ShipManager::*)(int , int )), "5383ec188b4424248b5424208b5c242883f811", argdata, 3, 6, &func);
}

void ShipManager::SetSystemPowerLimit(int systemId, int limit)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int limit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1041::func;
	return execfunc(this, systemId, limit);
}

namespace _func1042
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemPowerLoss", typeid(void (ShipManager::*)(int , int )), ".5383ec188b4424248b5424208b5c242883f811", argdata, 3, 6, &func);
}

void ShipManager::SetSystemPowerLoss(int systemId, int powerLoss)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int powerLoss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1042::func;
	return execfunc(this, systemId, powerLoss);
}

namespace _func1043
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetSystemDividePower", typeid(void (ShipManager::*)(int , int )), ".5383ec188b4424248b5424208b5c242883f811", argdata, 3, 6, &func);
}

void ShipManager::SetSystemDividePower(int systemId, int amount)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1043::func;
	return execfunc(this, systemId, amount);
}

namespace _func1044
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemAvailablePower", typeid(int (ShipManager::*)(int )), ".57565383ec108b74????8b54????8b86000400008b1c9083fbff74??", argdata, 2, 2, &func);
}

int ShipManager::GetSystemAvailablePower(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1044::func;
	return execfunc(this, systemId);
}

namespace _func1045
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemDamage", typeid(int (ShipManager::*)(int )), ".8b54????8b4c????8b82000400008b048883f8ff74??8b52188b14828b82f0000000", argdata, 2, 2, &func);
}

int ShipManager::GetSystemDamage(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1045::func;
	return execfunc(this, systemId);
}

namespace _func1046
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(int (ShipManager::*)()), "5589e557565383ec4c8b5d088b83c4040000", argdata, 1, 2, &func);
}

int ShipManager::CreateSystems()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1046::func;
	return execfunc(this);
}

namespace _func1047
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddSystem", typeid(int (ShipManager::*)(int )), "5589e557565381ecdc0000008b45088d98c0040000", argdata, 2, 2, &func);
}

int ShipManager::AddSystem(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1047::func;
	return execfunc(this, systemId);
}

namespace _func1048
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::UpdateCrewMembers", typeid(void (ShipManager::*)()), "5589e557565331db81ecfc0000008b7d088b57188b471c", argdata, 1, 6, &func);
}

void ShipManager::UpdateCrewMembers()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1048::func;
	return execfunc(this);
}

namespace _func1049
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::PowerDrone", typeid(bool (ShipManager::*)(Drone *, int , bool , bool )), ".5557565383ec1c8b7424308b5c24348b7c243c8b", argdata, 5, 2, &func);
}

bool ShipManager::PowerDrone(Drone *drone, int roomId, bool userDriven, bool force)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Drone *drone_arg, int roomId_arg, bool userDriven_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1049::func;
	return execfunc(this, drone, roomId, userDriven, force);
}

namespace _func1050
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(void (ShipManager::*)()), "5589e557565381ec9c0000008b7d088d4770", argdata, 1, 6, &func);
}

void ShipManager::UpdateEnvironment()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1050::func;
	return execfunc(this);
}

namespace _func1051
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromBlueprint", typeid(CrewMember *(ShipManager::*)(CrewBlueprint *, int , bool , int , bool )), "5589e557565383ec6c8b4514c7442404????????8b7508", argdata, 6, 2, &func);
}

CrewMember *ShipManager::AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewBlueprint *bp_arg, int slot_arg, bool init_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1051::func;
	return execfunc(this, bp, slot, init, roomId, intruder);
}

namespace _func1052
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMemberFromString", typeid(CrewMember *(ShipManager::*)(const std::string &, const std::string &, bool , int , bool , bool )), "5589e557565381ec6c0100008b75088b4d1c8b45148b5604", argdata, 7, 2, &func);
}

CrewMember *ShipManager::AddCrewMemberFromString(const std::string &name, const std::string &race, bool intruder, int roomId, bool init, bool male)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const std::string &name_arg, const std::string &race_arg, bool intruder_arg, int roomId_arg, bool init_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1052::func;
	return execfunc(this, name, race, intruder, roomId, init, male);
}

namespace _func1053
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetOxygenPercentage", typeid(int (ShipManager::*)()), "8b4424048b9000040000837a08ff74??8b4024f30f1005????????", argdata, 1, 2, &func);
}

int ShipManager::GetOxygenPercentage()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1053::func;
	return execfunc(this);
}

namespace _func1054
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetOxygenLevel", typeid(float (ShipManager::*)(int )), ".8b44????8b9000040000837a08ff74??8b40248944????e9????????", argdata, 2, 2, &func);
}

float ShipManager::GetOxygenLevel(int roomId)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1054::func;
	return execfunc(this, roomId);
}

namespace _func1055
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetOxygenLevels", typeid(std::vector<float> (ShipManager::*)()), ".5557565383ec1c8b44????8b5c????8b9000040000837a08ff75??c70300000000", argdata, 2, 18, &func);
}

std::vector<float> ShipManager::GetOxygenLevels()
{
	typedef std::vector<float> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1055::func;
	return execfunc(this);
}

namespace _func1056
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(bool (ShipManager::*)(CrewMember *, Damage )), "5557565383ec1c807c246600", argdata, 3, 2, &func);
}

bool ShipManager::DamageCrew(CrewMember *crew, Damage dmg)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1056::func;
	return execfunc(this, crew, dmg);
}

namespace _func1057
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::RemoveItem", typeid(void (ShipManager::*)(const std::string &)), "5557565383ec3c8b442454894424048d44242c890424", argdata, 2, 6, &func);
}

void ShipManager::RemoveItem(const std::string &name)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1057::func;
	return execfunc(this, name);
}

namespace _func1058
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageArea", typeid(bool (ShipManager::*)(Pointf , Damage , bool )), "5589e557565381eccc0000008b45148b5d08", argdata, 4, 2, &func);
}

bool ShipManager::DamageArea(Pointf location, Damage dmg, bool forceHit)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf location_arg, Damage dmg_arg, bool forceHit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1058::func;
	return execfunc(this, location, dmg, forceHit);
}

namespace _func1059
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x2ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageBeam", typeid(bool (ShipManager::*)(Pointf , Pointf , Damage )), "5589e557565381ecdc0000008b7d088b5d0c8b7510", argdata, 4, 2, &func);
}

bool ShipManager::DamageBeam(Pointf location1, Pointf location2, Damage dmg)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf location1_arg, Pointf location2_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1059::func;
	return execfunc(this, location1, location2, dmg);
}

namespace _func1060
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SelectRandomCrew", typeid(CrewBlueprint (ShipManager::*)(int , const std::string &)), "5589e557565383ec6c8b45108b7d14", argdata, 4, 18, &func);
}

CrewBlueprint ShipManager::SelectRandomCrew(int seed, const std::string &racePref)
{
	typedef CrewBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int seed_arg, const std::string &racePref_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1060::func;
	return execfunc(this, seed, racePref);
}

namespace _func1061
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::ClearStatusAll", typeid(void (ShipManager::*)()), "565331db83ec148b7424208b56188b461c29d0c1f80285c074??8db6000000008b049a83c301", argdata, 1, 6, &func);
}

void ShipManager::ClearStatusAll()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1061::func;
	return execfunc(this);
}

namespace _func1062
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(void (ShipManager::*)()), "5557565383ec7c8bbc24900000008b87ec050000", argdata, 1, 6, &func);
}

void ShipManager::PrepareSuperDrones()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1062::func;
	return execfunc(this);
}

namespace _func1063
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::JumpLeave", typeid(void (ShipManager::*)()), "5631c05383ec248b742430", argdata, 1, 6, &func);
}

void ShipManager::JumpLeave()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1063::func;
	return execfunc(this);
}

namespace _func1064
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(void (ShipManager::*)(int , bool )), "5557565383ec3c8b7424548b5c24508b442458", argdata, 3, 6, &func);
}

void ShipManager::ModifyScrapCount(int scrap, bool income)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int scrap_arg, bool income_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1064::func;
	return execfunc(this, scrap, income);
}

namespace _func1065
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyMissileCount", typeid(void (ShipManager::*)(int )), "8b4424048b4c24088b9000040000837a0cff", argdata, 2, 6, &func);
}

void ShipManager::ModifyMissileCount(int missiles)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int missiles_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1065::func;
	return execfunc(this, missiles);
}

namespace _func1066
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetMissileCount", typeid(int (ShipManager::*)()), "8b4424048b9000040000837a0cff74108b40488b", argdata, 1, 2, &func);
}

int ShipManager::GetMissileCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1066::func;
	return execfunc(this);
}

namespace _func1067
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyDroneCount", typeid(void (ShipManager::*)(int )), "8b4424048b4c24088b9000040000837a10ff", argdata, 2, 6, &func);
}

void ShipManager::ModifyDroneCount(int drones)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int drones_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1067::func;
	return execfunc(this, drones);
}

namespace _func1068
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DoSensorsProvide", typeid(bool (ShipManager::*)(int )), "5383ec188b5424208b82000400008b401c", argdata, 2, 2, &func);
}

bool ShipManager::DoSensorsProvide(int vision)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int vision_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1068::func;
	return execfunc(this, vision);
}

namespace _func1069
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), "5331c083ec188b5c24208b5304c70424????????85d2??????89442404e8????????b901000000", argdata, 1, 2, &func);
}

bool ShipManager::IsCrewFull()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1069::func;
	return execfunc(this);
}

namespace _func1070
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), "5331c083ec188b5c24208b5304c70424????????85d2??????89442404e8????????837b0401", argdata, 1, 2, &func);
}

bool ShipManager::IsCrewOverFull()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1070::func;
	return execfunc(this);
}

namespace _func1071
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(CrewDrone *(ShipManager::*)(const DroneBlueprint *)), "565383ec248b5424348b5c24308b4240", argdata, 2, 2, &func);
}

CrewDrone *ShipManager::CreateCrewDrone(const DroneBlueprint *bp)
{
	typedef CrewDrone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1071::func;
	return execfunc(this, bp);
}

namespace _func1072
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(SpaceDrone *(ShipManager::*)(const DroneBlueprint *)), "5589e557565383ec7c8b750c8b5d08c745b800000000", argdata, 2, 2, &func);
}

SpaceDrone *ShipManager::CreateSpaceDrone(const DroneBlueprint *bp)
{
	typedef SpaceDrone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1072::func;
	return execfunc(this, bp);
}

namespace _func1073
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (ShipManager::*)(CrewMember *, int )), "83ec1c8b442428c744240c00000000c7442408ffffffff", argdata, 3, 2, &func);
}

bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int roomId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1073::func;
	return execfunc(this, crew, roomId);
}

namespace _func1074
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemRoom", typeid(int (ShipManager::*)(int )), "8b4424088b54240483f8ff74??8b8a000400008b048183f8ff74??8b52188b048285c074??8b1089442404", argdata, 2, 2, &func);
}

int ShipManager::GetSystemRoom(int sysId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1074::func;
	return execfunc(this, sysId);
}

namespace _func1075
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(std::vector<ProjectileFactory*> (ShipManager::*)()), "5557565383ec1c8b4424348b5c24308b9000040000837a0cff", argdata, 2, 18, &func);
}

std::vector<ProjectileFactory*> ShipManager::GetWeaponList()
{
	typedef std::vector<ProjectileFactory*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1075::func;
	return execfunc(this);
}

namespace _func1076
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(Drone *(ShipManager::*)(const DroneBlueprint *, int )), "57565383ec208b5c24308b7c24348b8300040000", argdata, 3, 2, &func);
}

Drone *ShipManager::AddDrone(const DroneBlueprint *bp, int slot)
{
	typedef Drone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1076::func;
	return execfunc(this, bp, slot);
}

namespace _func1077
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::Restart", typeid(void (ShipManager::*)()), "5557565383ec2c8b6c24408b450485c0", argdata, 1, 6, &func);
}

void ShipManager::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1077::func;
	return execfunc(this);
}

namespace _func1078
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), "8b5424048b4c24088b82000400008b048883f8ff74??8b52188b048289442404e9????????8d7600b8ffffffff", argdata, 2, 2, &func);
}

int ShipManager::GetSystemPower(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1078::func;
	return execfunc(this, systemId);
}

namespace _func1079
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountCrewShipId", typeid(int (ShipManager::*)(int , int )), "5557565383ec1c8b4424308b50648b406889c129d1c1f90285c90f84????????", argdata, 3, 2, &func);
}

int ShipManager::CountCrewShipId(int roomId, int shipId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1079::func;
	return execfunc(this, roomId, shipId);
}

namespace _func1080
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), "8b4424088b54240483f8ff74??8b8a000400008b048183f8ff74??8b52188b0482c38db60000000031c0", argdata, 2, 2, &func);
}

ShipSystem *ShipManager::GetSystem(int systemId)
{
	typedef ShipSystem *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1080::func;
	return execfunc(this, systemId);
}

namespace _func1081
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::DoorsFunction", typeid(bool (ShipManager::*)()), ".5383ec188b5c24208b83000400008b4020", argdata, 1, 2, &func);
}

bool ShipManager::DoorsFunction()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1081::func;
	return execfunc(this);
}

namespace _func1082
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemLocked", typeid(bool (ShipManager::*)(int )), ".8b548b4c8b82000400008b048883f8ff748b52188b04828944e9", argdata, 2, 2, &func);
}

bool ShipManager::SystemLocked(int systemId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1082::func;
	return execfunc(this, systemId);
}

namespace _func1083
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportShip", typeid(void (ShipManager::*)(int )), "5589e557565381ec1c0100008b45088b7d0c0594040000", argdata, 2, 6, &func);
}

void ShipManager::ExportShip(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1083::func;
	return execfunc(this, file);
}

namespace _func1084
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::destructor", typeid(void (ShipManager::*)()), ".5557565383ec1c8b7c2430", argdata, 1, 6, &func);
}

void ShipManager::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1084::func;
	return execfunc(this);
}

namespace _func1085
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::destructor2", typeid(void (ShipManager::*)()), ".5383ec188b5c2420891c24", argdata, 1, 6, &func);
}

void ShipManager::destructor2()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1085::func;
	return execfunc(this);
}

namespace _func1086
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportShip", typeid(void (ShipManager::*)(int )), "5589e557565381ec7c0200008b7d0c8d8588feffff", argdata, 2, 6, &func);
}

void ShipManager::ImportShip(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1086::func;
	return execfunc(this, file);
}

namespace _func1087
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::CheckVision", typeid(void (ShipManager::*)()), "5557565383ec4c8b7c24608b870004000083781cff", argdata, 1, 6, &func);
}

void ShipManager::CheckVision()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1087::func;
	return execfunc(this);
}

namespace _func1088
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked", typeid(int (ShipManager::*)(int )), "56538b5424108b4c240c83fa118b8100040000", argdata, 2, 2, &func);
}

int ShipManager::IsSystemHacked(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1088::func;
	return execfunc(this, systemId);
}

namespace _func1089
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::SaveCrewPositions", typeid(void (ShipManager::*)()), ".5383ec288d????108944????c744????00000000c704??????????", argdata, 1, 6, &func);
}

void ShipManager::SaveCrewPositions()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1089::func;
	return execfunc(this);
}

namespace _func1090
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSelectedCrewPoint", typeid(CrewMember *(ShipManager::*)(int , int , bool )), "5589e557565383ec3c8b7d080fb645148b4f64", argdata, 4, 2, &func);
}

CrewMember *ShipManager::GetSelectedCrewPoint(int x, int y, bool intruder)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1090::func;
	return execfunc(this, x, y, intruder);
}

namespace _func1091
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::RenderWeapons", typeid(void (ShipManager::*)()), "5589e557565383ec6c8b75088d45b0890424", argdata, 1, 6, &func);
}

void ShipManager::RenderWeapons()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1091::func;
	return execfunc(this);
}

namespace _func1092
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ClearStatusSystem", typeid(void (ShipManager::*)(int )), "83ec1c8b4424248b54242083f811", argdata, 2, 6, &func);
}

void ShipManager::ClearStatusSystem(int system)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1092::func;
	return execfunc(this, system);
}

namespace _func1093
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(void (ShipManager::*)()), "a1????????8b54240483f801c7820c0400001e000000", argdata, 1, 6, &func);
}

void ShipManager::ResetScrapLevel()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1093::func;
	return execfunc(this);
}

namespace _func1094
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::JumpArrive", typeid(void (ShipManager::*)()), "565383ec248b7424308b86f4030000c786c403000000000000", argdata, 1, 6, &func);
}

void ShipManager::JumpArrive()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1094::func;
	return execfunc(this);
}

namespace _func1095
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::CheckSpreadDamage", typeid(void (ShipManager::*)()), "5589e557565383ec5c8b7d08c745b000000000", argdata, 1, 6, &func);
}

void ShipManager::CheckSpreadDamage()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1095::func;
	return execfunc(this);
}

namespace _func1096
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemHealth", typeid(int (ShipManager::*)(int )), "8b54????8b4c????8b82000400008b048883f8ff74??8b52188b04828b80ec000000", argdata, 2, 2, &func);
}

int ShipManager::GetSystemHealth(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1096::func;
	return execfunc(this, systemId);
}

namespace _func1097
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IncreaseSystemPower", typeid(bool (ShipManager::*)(int )), ".83ec1c8b4c????8b54????8b81000400008b149031c083faff74??c744????00000000c744????01000000", argdata, 2, 2, &func);
}

bool ShipManager::IncreaseSystemPower(int systemId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1097::func;
	return execfunc(this, systemId);
}

namespace _func1098
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ForceIncreaseSystemPower", typeid(bool (ShipManager::*)(int )), ".8b44????8b54????83f8ff74??8b8a000400008b048183f8ff74??8b52188b048285c074??8b10c744????010000008944????8b8288000000", argdata, 2, 2, &func);
}

bool ShipManager::ForceIncreaseSystemPower(int sys)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1098::func;
	return execfunc(this, sys);
}

namespace _func1099
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ForceDecreaseSystemPower", typeid(bool (ShipManager::*)(int )), ".8b4424088b54240483f8ff74??8b8a000400008b048183f8ff74??8b52188b048285c074??8b10c744240801000000894424048b8284000000", argdata, 2, 2, &func);
}

bool ShipManager::ForceDecreaseSystemPower(int sys)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1099::func;
	return execfunc(this, sys);
}

namespace _func1100
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetShieldPower", typeid(ShieldPower (ShipManager::*)()), "8b5424088b4424048b524485d2", argdata, 2, 18, &func);
}

ShieldPower ShipManager::GetShieldPower()
{
	typedef ShieldPower __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1100::func;
	return execfunc(this);
}

namespace _func1101
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::CloneHealing", typeid(void (ShipManager::*)()), "5589c557565383ec1c", argdata, 1, 6, &func);
}

void ShipManager::CloneHealing()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1101::func;
	return execfunc(this);
}

namespace _func1102
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked2", typeid(int (ShipManager::*)(int )), ".5683fa115389c18b800004000074??8b1c9031c083fbff75??", argdata, 2, 2, &func);
}

int ShipManager::IsSystemHacked2(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1102::func;
	return execfunc(this, systemId);
}

namespace _func1103
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddWeapon", typeid(int (ShipManager::*)(const WeaponBlueprint *, int )), "538b4424088b9000040000837a0cff", argdata, 3, 2, &func);
}

int ShipManager::AddWeapon(const WeaponBlueprint *bp, int slot)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const WeaponBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1103::func;
	return execfunc(this, bp, slot);
}

namespace _func1104
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddEquipmentFromList", typeid(void (ShipManager::*)(std::vector<std::string> *)), "5557565331db83ec3c8b4424548d74242c", argdata, 2, 6, &func);
}

void ShipManager::AddEquipmentFromList(std::vector<std::string> *equipmentList)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, std::vector<std::string> *equipmentList_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1104::func;
	return execfunc(this, equipmentList);
}

namespace _func1105
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::RenderChargeBars", typeid(void (ShipManager::*)()), "5589e557565383ec4c8b5d088b730485f6", argdata, 1, 6, &func);
}

void ShipManager::RenderChargeBars()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1105::func;
	return execfunc(this);
}

namespace _func1106
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ExportBattleState", typeid(void (ShipManager::*)(int )), "5557565383ec2c8b7c24408b7424448b8700040000", argdata, 2, 6, &func);
}

void ShipManager::ExportBattleState(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1106::func;
	return execfunc(this, file);
}

namespace _func1107
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ImportBattleState", typeid(void (ShipManager::*)(int )), "5557565383ec3c8b7424508b5c24548b8600040000", argdata, 2, 6, &func);
}

void ShipManager::ImportBattleState(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1107::func;
	return execfunc(this, file);
}

namespace _func1108
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemFunctions", typeid(bool (ShipManager::*)(int )), "8b5424048b4c24088b82000400008b048883f8ff74??8b52188b04828b10894424048b422c", argdata, 2, 2, &func);
}

bool ShipManager::SystemFunctions(int systemId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1108::func;
	return execfunc(this, systemId);
}

namespace _func1109
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanFitSystem", typeid(bool (ShipManager::*)(int )), "57565383ec108b4424248b7c242083f805", argdata, 2, 2, &func);
}

bool ShipManager::CanFitSystem(int systemId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1109::func;
	return execfunc(this, systemId);
}

namespace _func1110
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanFitSubsystem", typeid(bool (ShipManager::*)(int )), "57565383ec108b7c24208b57188b471c", argdata, 2, 2, &func);
}

bool ShipManager::CanFitSubsystem(int systemId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1110::func;
	return execfunc(this, systemId);
}

namespace _func1111
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::DamageHull", typeid(int (ShipManager::*)(int , bool )), "565383ec148b5c24208b7424288b03891c24", argdata, 3, 2, &func);
}

int ShipManager::DamageHull(int dmg, bool force)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int dmg_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1111::func;
	return execfunc(this, dmg, force);
}

namespace _func1112
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageSystem", typeid(void (ShipManager::*)(int , Damage )), "5589e557565383ec6c8b45248b7d088b5d10", argdata, 3, 6, &func);
}

void ShipManager::DamageSystem(int systemId, Damage damage)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, Damage damage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1112::func;
	return execfunc(this, systemId, damage);
}

namespace _func1113
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::StartFire", typeid(void (ShipManager::*)(int )), "83ec1c8b442424c74424080200000089442404", argdata, 2, 6, &func);
}

void ShipManager::StartFire(int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1113::func;
	return execfunc(this, roomId);
}

namespace _func1114
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::FindCrew", typeid(CrewMember *(ShipManager::*)(const CrewBlueprint *)), "5557565383ec3c8d44242089442404c744240c00000000", argdata, 2, 2, &func);
}

CrewMember *ShipManager::FindCrew(const CrewBlueprint *bp)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const CrewBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1114::func;
	return execfunc(this, bp);
}

namespace _func1115
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetDodged", typeid(bool (ShipManager::*)()), "57565383ec208b5c2430807b1000", argdata, 1, 2, &func);
}

bool ShipManager::GetDodged()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1115::func;
	return execfunc(this);
}

namespace _func1116
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperBarrage", typeid(void (ShipManager::*)()), "5589e557565383ec7c8b7d088b87c0030000", argdata, 1, 6, &func);
}

void ShipManager::PrepareSuperBarrage()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1116::func;
	return execfunc(this);
}

namespace _func1117
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetTooltip", typeid(std::string (ShipManager::*)(int , int )), "5589e5575631f65383ec3c8b7d0c", argdata, 4, 18, &func);
}

std::string ShipManager::GetTooltip(int x, int y)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1117::func;
	return execfunc(this, x, y);
}

namespace _func1118
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::RestoreCrewPositions", typeid(bool (ShipManager::*)()), "5589e557565383ec6c8d45a8", argdata, 1, 2, &func);
}

bool ShipManager::RestoreCrewPositions()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1118::func;
	return execfunc(this);
}

namespace _func1119
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetCrewmember", typeid(CrewMember *(ShipManager::*)(int , bool )), "555731ff565331db83ec1c8b7424308b4e688b4664", argdata, 3, 2, &func);
}

CrewMember *ShipManager::GetCrewmember(int slot, bool present)
{
	typedef CrewMember *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int slot_arg, bool present_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1119::func;
	return execfunc(this, slot, present);
}

namespace _func1120
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CanUpgrade", typeid(int (ShipManager::*)(int , int )), "5589e55383ec148b550c8b4d0883fa11", argdata, 3, 2, &func);
}

int ShipManager::CanUpgrade(int systemId, int amount)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1120::func;
	return execfunc(this, systemId, amount);
}

namespace _func1121
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SaveToBlueprint", typeid(ShipBlueprint (ShipManager::*)(bool )), "5589e557565383ec5c8b45108b5d08", argdata, 3, 18, &func);
}

ShipBlueprint ShipManager::SaveToBlueprint(bool overwrite)
{
	typedef ShipBlueprint __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool overwrite_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1121::func;
	return execfunc(this, overwrite);
}

namespace _func1122
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("ShipManager::CheckCrystalAugment", typeid(void (ShipManager::*)(Pointf )), "5589e557565331db83ec7c8d45c88d75d8", argdata, 2, 6, &func);
}

void ShipManager::CheckCrystalAugment(Pointf pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1122::func;
	return execfunc(this, pos);
}

namespace _func1123
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CollisionMoving", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), "5589e557565381ec1c0100008b7d548b75188b5d1c", argdata, 6, 18, &func);
}

CollisionResponse ShipManager::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1123::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1124
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerMax", typeid(int (ShipManager::*)(int )), "8b5424048b4c24088b82000400008b048883f8ff74??8b52188b04828b4040", argdata, 2, 2, &func);
}

int ShipManager::GetSystemPowerMax(int systemId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1124::func;
	return execfunc(this, systemId);
}

namespace _func1125
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetDroneList", typeid(std::vector<Drone*> (ShipManager::*)()), "5557565383ec1c8b4424348b5c24308b9000040000837a10ff", argdata, 2, 18, &func);
}

std::vector<Drone*> ShipManager::GetDroneList()
{
	typedef std::vector<Drone*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1125::func;
	return execfunc(this);
}

namespace _func1126
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetDroneCount", typeid(int (ShipManager::*)()), "8b4424048b9000040000837a10ff74??8b404c8b80a4010000", argdata, 1, 2, &func);
}

int ShipManager::GetDroneCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1126::func;
	return execfunc(this);
}

namespace _func1127
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::InstantPowerShields", typeid(void (ShipManager::*)()), "5383ec188b5c24208b83000400008b00", argdata, 1, 6, &func);
}

void ShipManager::InstantPowerShields()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1127::func;
	return execfunc(this);
}

namespace _func1128
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::SetDestroyed", typeid(void (ShipManager::*)()), "565331db83ec148b7424208b56188b461cc686d103000001", argdata, 1, 6, &func);
}

void ShipManager::SetDestroyed()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1128::func;
	return execfunc(this);
}

namespace _func1129
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetFireCount", typeid(int (ShipManager::*)(int )), "8b44240483c07089442404", argdata, 2, 2, &func);
}

int ShipManager::GetFireCount(int roomId)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1129::func;
	return execfunc(this, roomId);
}

namespace _func1130
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(void (ShipManager::*)(CrewMember *, int )), "5383ec188b5c24208b4304894424048b442424890424", argdata, 3, 6, &func);
}

void ShipManager::AddCrewMember(CrewMember *crew, int roomId)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1130::func;
	return execfunc(this, crew, roomId);
}

namespace _func1131
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetLeavingCrew", typeid(std::vector<CrewMember*> (ShipManager::*)(bool )), "5557565331db83ec1c0fb6442438", argdata, 3, 18, &func);
}

std::vector<CrewMember*> ShipManager::GetLeavingCrew(bool intruders)
{
	typedef std::vector<CrewMember*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool intruders_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1131::func;
	return execfunc(this, intruders);
}

namespace _func1132
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::UpgradeSystem", typeid(void (ShipManager::*)(int , int )), "5589e557565383ec1c8b450c8b75088b5d10", argdata, 3, 6, &func);
}

void ShipManager::UpgradeSystem(int id, int amount)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int id_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1132::func;
	return execfunc(this, id, amount);
}

namespace _func1133
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CollisionShield", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), "5589e557565381ecec0000008b45148b5d0c", argdata, 6, 18, &func);
}

CollisionResponse ShipManager::CollisionShield(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1133::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1134
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsCloaked", typeid(bool (ShipManager::*)()), "8b4424048b9000040000837a28ff", argdata, 1, 2, &func);
}

bool ShipManager::IsCloaked()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1134::func;
	return execfunc(this);
}

namespace _func1135
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::CountPlayerCrew", typeid(int (ShipManager::*)()), "5557565383ec1c8b4424308b50648b406889c129d1c1f90285c9747e", argdata, 1, 2, &func);
}

int ShipManager::CountPlayerCrew()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1135::func;
	return execfunc(this);
}

namespace _func1136
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::Wait", typeid(void (ShipManager::*)()), "565383ec148b5c24208b8300", argdata, 1, 6, &func);
}

void ShipManager::Wait()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1136::func;
	return execfunc(this);
}

namespace _func1137
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateArmory", typeid(void (ShipManager::*)()), "5589e557565383ec4c8b5d088b8300040000", argdata, 1, 6, &func);
}

void ShipManager::CreateArmory()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1137::func;
	return execfunc(this);
}

namespace _func1138
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateDrone", typeid(Drone *(ShipManager::*)(DroneBlueprint *)), "57565383ec208b7c24348b5c24308b4740", argdata, 2, 2, &func);
}

Drone *ShipManager::CreateDrone(DroneBlueprint *drone)
{
	typedef Drone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *this_arg, DroneBlueprint *drone_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1138::func;
	return execfunc(this, drone);
}

namespace _func1139
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(const std::string &)), "5589e557565383ec6c8b450c894424048d45c8890424e8????????8b45088b400485c00f94??0fb6c06bc0348945a8a1????????0145a88b55a8", argdata, 2, 2, &func);
}

int ShipObject::HasAugmentation(const std::string &augment)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1139::func;
	return execfunc(this, augment);
}

namespace _func1140
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(const std::string &)), "5589e557565383ec7c8b450c894424048d45b8890424", argdata, 2, 2, &func);
}

float ShipObject::GetAugmentationValue(const std::string &augment)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1140::func;
	return execfunc(this, augment);
}

namespace _func1141
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::RemoveAugmentation", typeid(void (ShipObject::*)(const std::string &)), ".5589e557565383ec7c8b450c894424048d45b8890424", argdata, 2, 6, &func);
}

void ShipObject::RemoveAugmentation(const std::string &augment)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1141::func;
	return execfunc(this, augment);
}

namespace _func1142
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasEquipment", typeid(int (ShipObject::*)(const std::string &)), "5589e557565383ec7c8b5d0c8d45c8", argdata, 2, 2, &func);
}

int ShipObject::HasEquipment(const std::string &equip)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1142::func;
	return execfunc(this, equip);
}

namespace _func1143
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationList", typeid(std::vector<std::string> (ShipObject::*)()), "5557565383ec1c8b4424348b5c24308b4004", argdata, 2, 18, &func);
}

std::vector<std::string> ShipObject::GetAugmentationList()
{
	typedef std::vector<std::string> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1143::func;
	return execfunc(this);
}

namespace _func1144
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::AddAugmentation", typeid(bool (ShipObject::*)(const std::string &)), "5589e557565381ec8c0000008b450c894424048d45b8890424", argdata, 2, 2, &func);
}

bool ShipObject::AddAugmentation(const std::string &augment)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1144::func;
	return execfunc(this, augment);
}

namespace _func1145
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::RemoveEquipment", typeid(void (ShipObject::*)(const std::string &, bool )), ".5589e557565381ec8c0000008b????89????8b????8944????", argdata, 3, 6, &func);
}

void ShipObject::RemoveEquipment(const std::string &blueName, bool completely)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &blueName_arg, bool completely_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1145::func;
	return execfunc(this, blueName, completely);
}

namespace _func1146
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), "8b4424048b400485c00f94??0fb6c06bc034", argdata, 1, 2, &func);
}

int ShipObject::GetAugmentationCount()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1146::func;
	return execfunc(this);
}

namespace _func1147
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipObject::ClearShipInfo", typeid(void (ShipObject::*)()), "5331db83ec188b4424208b400485c0", argdata, 1, 6, &func);
}

void ShipObject::ClearShipInfo()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1147::func;
	return execfunc(this);
}

ShipInfo **Global_ShipObject_ShipInfoList;

namespace _var1148
{
    static VariableDefinition varObj("Global_ShipObject_ShipInfoList", "!6bc0340305(???????\?)8b4030c3", &Global_ShipObject_ShipInfoList);
}

namespace _func1149
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102};
	static FunctionDefinition funcObj("ShipSelect::SelectShip", typeid(void (ShipSelect::*)(int )), "5589e557565389c381ec8c010000", argdata, 2, 6, &func);
}

void ShipSelect::SelectShip(int shipType)
{
	typedef void __attribute__((regparm(2))) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1149::func;
	return execfunc(this, shipType);
}

namespace _func1150
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::constructor", typeid(void (ShipSelect::*)()), "565383ec248b5c24308d74241fc74424086e000000", argdata, 1, 6, &func);
}

void ShipSelect::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1150::func;
	return execfunc(this);
}

namespace _func1151
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::ClearShipButtons", typeid(void (ShipSelect::*)()), "565383ec148b7424208b4e208b561c89c829d083f8037e??31db8db600000000", argdata, 1, 6, &func);
}

void ShipSelect::ClearShipButtons()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1151::func;
	return execfunc(this);
}

namespace _func1152
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::MouseMove", typeid(void (ShipSelect::*)(int , int )), "5589e557565381ecac0000008b450880b84404000000", argdata, 3, 6, &func);
}

void ShipSelect::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1152::func;
	return execfunc(this, x, y);
}

namespace _func1153
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::OnLoop", typeid(void (ShipSelect::*)()), "5589e557565381ecac0000008b5d0880bb4404000000", argdata, 1, 6, &func);
}

void ShipSelect::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1153::func;
	return execfunc(this);
}

namespace _func1154
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::KeyDown", typeid(int (ShipSelect::*)(SDLKey )), "8b442404054004000089442404", argdata, 2, 2, &func);
}

int ShipSelect::KeyDown(SDLKey key)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1154::func;
	return execfunc(this, key);
}

namespace _func1155
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::MouseClick", typeid(void (ShipSelect::*)()), "5383ec188b5c242080bb4404000000", argdata, 1, 6, &func);
}

void ShipSelect::MouseClick()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1155::func;
	return execfunc(this);
}

namespace _func1156
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::PreSelectShip", typeid(void (ShipSelect::*)(int )), "5383ec188b5424248b5c242085d2", argdata, 2, 6, &func);
}

void ShipSelect::PreSelectShip(int shipType)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int shipType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1156::func;
	return execfunc(this, shipType);
}

namespace _func1157
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::Close", typeid(void (ShipSelect::*)()), "!8b442404c64034000540040000", argdata, 1, 6, &func);
}

void ShipSelect::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1157::func;
	return execfunc(this);
}

namespace _func1158
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::GetSelectedShip", typeid(int (ShipSelect::*)()), ".8b4424048b4038", argdata, 1, 2, &func);
}

int ShipSelect::GetSelectedShip()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1158::func;
	return execfunc(this);
}

namespace _func1159
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSelect::Open", typeid(void (ShipSelect::*)(int , int )), "5589e557565381ec8c0100008b4508833d????????02", argdata, 3, 6, &func);
}

void ShipSelect::Open(int currentId, int currentType)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg, int currentId_arg, int currentType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1159::func;
	return execfunc(this, currentId, currentType);
}

namespace _func1160
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSelect::OnRender", typeid(void (ShipSelect::*)()), "5589e557565383ec5c8b5d0880bb4404000000", argdata, 1, 6, &func);
}

void ShipSelect::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1160::func;
	return execfunc(this);
}

namespace _func1161
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), "5589e557565381ec8c0000008b5d08807d0c00", argdata, 2, 6, &func);
}

void ShipStatus::RenderHealth(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1161::func;
	return execfunc(this, unk);
}

namespace _func1162
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), "5557565381ec2c0100008bac24400100008d9c2400010000", argdata, 3, 6, &func);
}

void ShipStatus::OnInit(Point unk, float unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, Point unk_arg, float unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1162::func;
	return execfunc(this, unk, unk2);
}

namespace _func1163
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), "5589e557565381ecfc0100008b7d08807d0c008b470c890424", argdata, 2, 6, &func);
}

void ShipStatus::RenderEvadeOxygen(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1163::func;
	return execfunc(this, unk);
}

namespace _func1164
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(void (ShipStatus::*)()), "5589e557565381ec8c0000008b5d08e8????????c744240800000000", argdata, 1, 6, &func);
}

void ShipStatus::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1164::func;
	return execfunc(this);
}

namespace _func1165
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102};
	static FunctionDefinition funcObj("ShipStatus::RenderShields", typeid(void (ShipStatus::*)(bool )), "5589e55789c7565383ec5c", argdata, 2, 6, &func);
}

void ShipStatus::RenderShields(bool renderText)
{
	typedef void __attribute__((regparm(2))) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1165::func;
	return execfunc(this, renderText);
}

namespace _func1166
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipStatus::OnLoop", typeid(void (ShipStatus::*)()), "5557565331db83ec3c8b7424508b96100100008b861401000029d0c1f802", argdata, 1, 6, &func);
}

void ShipStatus::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1166::func;
	return execfunc(this);
}

namespace _func1167
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetHackingLevel", typeid(void (ShipSystem::*)(int )), "8b54????8b44????899080010000", argdata, 2, 6, &func);
}

void ShipSystem::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1167::func;
	return execfunc(this, hackingLevel);
}

namespace _func1168
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::DamageOverTime", typeid(bool (ShipSystem::*)(float )), "565383ec14c70424????????8b5c2420", argdata, 2, 2, &func);
}

bool ShipSystem::DamageOverTime(float unk)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, float unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1168::func;
	return execfunc(this, unk);
}

namespace _func1169
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::CheckForRepower", typeid(void (ShipSystem::*)()), "5557565383ec1c8b5c24308b432c", argdata, 1, 6, &func);
}

void ShipSystem::CheckForRepower()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1169::func;
	return execfunc(this);
}

namespace _func1170
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::NameToSystemId", typeid(int (*)(const std::string &)), ".5383ec188b5c2420c7442404????????891c24e8????????85c075??83c4185b", argdata, 1, 2, &func);
}

int ShipSystem::NameToSystemId(const std::string &name)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1170::func;
	return execfunc(name);
}

namespace _func1171
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), "8b5424048b423485c0", argdata, 1, 2, &func);
}

int ShipSystem::IsMannedBoost()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1171::func;
	return execfunc(this);
}

namespace _func1172
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(std::string (*)(int )), "5383ec288b4424348b5c243083f811", argdata, 2, 18, &func);
}

std::string ShipSystem::SystemIdToName(int systemId)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1172::func;
	return execfunc(systemId);
}

namespace _func1173
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(void (ShipSystem::*)()), "565383ec148b7424208b8614010000", argdata, 1, 6, &func);
}

void ShipSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1173::func;
	return execfunc(this);
}

namespace _func1174
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::Ioned", typeid(bool (ShipSystem::*)(int )), "555756538b5424148b8214010000", argdata, 2, 2, &func);
}

bool ShipSystem::Ioned(int num)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int num_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1174::func;
	return execfunc(this, num);
}

namespace _func1175
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerLoss", typeid(int (ShipSystem::*)(int )), "5383ec188b5c24208b44242489830c010000", argdata, 2, 2, &func);
}

int ShipSystem::SetPowerLoss(int power)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int power_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1175::func;
	return execfunc(this, power);
}

namespace _func1176
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::constructor", typeid(void (ShipSystem::*)(int , int , int , int )), "5589e557565381ec9c0100008b75088b45148dbdf8feffff", argdata, 5, 6, &func);
}

void ShipSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int systemId_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1176::func;
	return execfunc(this, systemId, roomId, shipId, startingPower);
}

namespace _func1177
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), "8b54240431c08b8a0801000083f907", argdata, 1, 2, &func);
}

int ShipSystem::GetPowerCap()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1177::func;
	return execfunc(this);
}

namespace _func1178
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::BlockedBoosted", typeid(bool (ShipSystem::*)(bool )), ".5383ec18807c242400", argdata, 2, 2, &func);
}

bool ShipSystem::BlockedBoosted(bool countLimit)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool countLimit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1178::func;
	return execfunc(this, countLimit);
}

namespace _func1179
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetPowerCap", typeid(void (ShipSystem::*)(int )), "5383ec188b5c24208b442424898308010000", argdata, 2, 6, &func);
}

void ShipSystem::SetPowerCap(int cap)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int cap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1179::func;
	return execfunc(this, cap);
}

namespace _func1180
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LockSystem", typeid(void (ShipSystem::*)(int )), "8b5424088b44240483fa00", argdata, 2, 6, &func);
}

void ShipSystem::LockSystem(int lock)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1180::func;
	return execfunc(this, lock);
}

namespace _func1181
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::ForceDecreasePower", typeid(bool (ShipSystem::*)(int )), "5557565383ec2c8b6c24408b5c2444", argdata, 2, 2, &func);
}

bool ShipSystem::ForceDecreasePower(int powerLoss)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int powerLoss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1181::func;
	return execfunc(this, powerLoss);
}

namespace _func1182
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), "8b54240431c98b423485c0", argdata, 1, 2, &func);
}

int ShipSystem::GetEffectivePower()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1182::func;
	return execfunc(this);
}

namespace _func1183
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetMaxPower", typeid(int (ShipSystem::*)()), "538b5424088b4a408b82ec000000", argdata, 1, 2, &func);
}

int ShipSystem::GetMaxPower()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1183::func;
	return execfunc(this);
}

namespace _func1184
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetBonusPower", typeid(void (ShipSystem::*)(int , int )), "57565383ec108b5c24208b7424248b7c242880bb0401000000", argdata, 3, 6, &func);
}

void ShipSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1184::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func1185
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::CheckMaxPower", typeid(void (ShipSystem::*)()), "5557565383ec2c8b7c244080bf0401000000", argdata, 1, 6, &func);
}

void ShipSystem::CheckMaxPower()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1185::func;
	return execfunc(this);
}

namespace _func1186
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::PartialDamage", typeid(bool (ShipSystem::*)(float )), "565383ec14c70424????????8b5c2420", argdata, 2, 2, &func);
}

bool ShipSystem::PartialDamage(float amount)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, float amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1186::func;
	return execfunc(this, amount);
}

namespace _func1187
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IsSubsystem", typeid(bool (*)(int )), "8b44240483f80c", argdata, 1, 2, &func);
}

bool ShipSystem::IsSubsystem(int systemType)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1187::func;
	return execfunc(systemType);
}

namespace _func1188
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::ClearStatus", typeid(void (ShipSystem::*)()), "8b44240483b80801000007", argdata, 1, 6, &func);
}

void ShipSystem::ClearStatus()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1188::func;
	return execfunc(this);
}

namespace _func1189
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLevelDescription", typeid(std::string (*)(int , int , bool )), "5589e557565381ec3c0100008b450c8b7510", argdata, 4, 18, &func);
}

std::string ShipSystem::GetLevelDescription(int systemId, int level, bool tooltip)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg, int level_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1189::func;
	return execfunc(systemId, level, tooltip);
}

namespace _func1190
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::AddLock", typeid(void (ShipSystem::*)(int )), "538b5424088b4c240c8b8214010000", argdata, 2, 6, &func);
}

void ShipSystem::AddLock(int lock)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1190::func;
	return execfunc(this, lock);
}

namespace _func1191
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IonDamage", typeid(void (ShipSystem::*)(int )), ".565383ec148b74????", argdata, 2, 6, &func);
}

void ShipSystem::IonDamage(int amount)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1191::func;
	return execfunc(this, amount);
}

namespace _func1192
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLocked", typeid(bool (ShipSystem::*)()), "8b4424048b901401000083faff", argdata, 1, 2, &func);
}

bool ShipSystem::GetLocked()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1192::func;
	return execfunc(this);
}

namespace _func1193
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::StopHacking", typeid(void (ShipSystem::*)()), ".83ec1c8b4424208b10c6808401000000", argdata, 1, 6, &func);
}

void ShipSystem::StopHacking()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1193::func;
	return execfunc(this);
}

namespace _func1194
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SaveState", typeid(void (ShipSystem::*)(int )), "565383ec148b7424208b5c24248b8608010000", argdata, 2, 6, &func);
}

void ShipSystem::SaveState(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1194::func;
	return execfunc(this, file);
}

namespace _func1195
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LoadState", typeid(void (ShipSystem::*)(int )), "565383ec148b7424248b5c2420893424e8????????898308010000", argdata, 2, 6, &func);
}

void ShipSystem::LoadState(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1195::func;
	return execfunc(this, file);
}

namespace _func1196
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::UpgradeSystem", typeid(bool (ShipSystem::*)(int )), "565383ec148b5c24208b7424248b03891c24ff5010", argdata, 2, 2, &func);
}

bool ShipSystem::UpgradeSystem(int amount)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1196::func;
	return execfunc(this, amount);
}

namespace _func1197
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IncreasePower", typeid(bool (ShipSystem::*)(int , bool )), "565383ec148b5c24208b7424288b8314010000", argdata, 3, 2, &func);
}

bool ShipSystem::IncreasePower(int amount, bool force)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1197::func;
	return execfunc(this, amount, force);
}

namespace _func1198
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::DecreasePower", typeid(bool (ShipSystem::*)(bool )), "565383ec148b5c24208b7424240fb68304010000", argdata, 2, 2, &func);
}

bool ShipSystem::DecreasePower(bool force)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1198::func;
	return execfunc(this, force);
}

namespace _func1199
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::PartialRepair", typeid(bool (ShipSystem::*)(float , bool )), "5631c05383ec148b5c24208b7424288b93f0000000", argdata, 3, 2, &func);
}

bool ShipSystem::PartialRepair(float speed, bool autoRepair)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, float speed_arg, bool autoRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1199::func;
	return execfunc(this, speed, autoRepair);
}

namespace _func1200
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxes", typeid(int (ShipSystem::*)(int , int , int , int , int , int , bool )), "5557565381ec8c0000008bac24a00000000fb68424bc000000", argdata, 8, 2, &func);
}

int ShipSystem::RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int heightMod_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1200::func;
	return execfunc(this, x, y, width, height, gap, heightMod, flash);
}

namespace _func1201
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RawDecreasePower", typeid(bool (ShipSystem::*)()), ".565383ec148b5c????8b430c8b73448904??e8????????", argdata, 1, 2, &func);
}

bool ShipSystem::RawDecreasePower()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1201::func;
	return execfunc(this);
}

namespace _func1202
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::AddDamage", typeid(void (ShipSystem::*)(int )), "56538b44240c8b88f00000008b90ec000000", argdata, 2, 6, &func);
}

void ShipSystem::AddDamage(int amount)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1202::func;
	return execfunc(this, amount);
}

namespace _func1203
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ShipSystem::destructor", typeid(void (ShipSystem::*)()), "57bf05000000565383ec208b7424308b464c89f3", argdata, 1, 6, &func);
}

void ShipSystem::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1203::func;
	return execfunc(this);
}

namespace _func1204
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxesPlain", typeid(int (*)(int , int , int , int , int , int , int , int )), "55b84000", argdata, 8, 2, &func);
}

int ShipSystem::RenderPowerBoxesPlain(int x, int y, int width, int height, int gap, int current, int temp, int max)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int current_arg, int temp_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1204::func;
	return execfunc(x, y, width, height, gap, current, temp, max);
}

namespace _func1205
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderSystemSymbol", typeid(void (ShipSystem::*)(bool , int )), "5589e557565383ec3c8b75108b5d0885", argdata, 3, 6, &func);
}

void ShipSystem::RenderSystemSymbol(bool forPowerUI, int forceColor)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool forPowerUI_arg, int forceColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1205::func;
	return execfunc(this, forPowerUI, forceColor);
}

namespace _func1206
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLockTimer", typeid(TimerHelper (ShipSystem::*)()), "8b5424088b4424048b8a1801", argdata, 2, 18, &func);
}

TimerHelper ShipSystem::GetLockTimer()
{
	typedef TimerHelper __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1206::func;
	return execfunc(this);
}

GL_Primitive **ShipSystem__lockBlue;

namespace _var1207
{
    static VariableDefinition varObj("ShipSystem__lockBlue", "!8b3d(???????\?)84d28b8580010000", &ShipSystem__lockBlue);
}

GL_Primitive **ShipSystem__fireImage;

namespace _var1208
{
    static VariableDefinition varObj("ShipSystem__fireImage", "!.a1(???????\?)890424", &ShipSystem__fireImage);
}

GL_Primitive **ShipSystem__lockHack;

namespace _var1209
{
    static VariableDefinition varObj("ShipSystem__lockHack", "!.a1(???????\?)890424", &ShipSystem__lockHack);
}

GL_Primitive **ShipSystem__manningBarIon;

namespace _var1210
{
    static VariableDefinition varObj("ShipSystem__manningBarIon", "!.84c0a1(???????\?)0f4405(???????\?)", &ShipSystem__manningBarIon);
}

GL_Primitive **ShipSystem__manningBarOff;

namespace _var1211
{
    static VariableDefinition varObj("ShipSystem__manningBarOff", "", &ShipSystem__manningBarOff);
}

GL_Primitive **ShipSystem__lockWhite;

namespace _var1212
{
    static VariableDefinition varObj("ShipSystem__lockWhite", "!.8b3d(???????\?)b9ff000000", &ShipSystem__lockWhite);
}

GL_Primitive **ShipSystem__sabotageImage;

namespace _var1213
{
    static VariableDefinition varObj("ShipSystem__sabotageImage", "!.a1(???????\?)890424", &ShipSystem__sabotageImage);
}

GL_Primitive **ShipSystem__manningOutline;

namespace _var1214
{
    static VariableDefinition varObj("ShipSystem__manningOutline", "!.a1(???????\?)bef0ffffffbb10000000", &ShipSystem__manningOutline);
}

GL_Primitive **ShipSystem__manningBarOn;

namespace _var1215
{
    static VariableDefinition varObj("ShipSystem__manningBarOn", "!.0f85????????a1(???????\?)e9", &ShipSystem__manningBarOn);
}

GL_Primitive **ShipSystem__manningWhite;

namespace _var1216
{
    static VariableDefinition varObj("ShipSystem__manningWhite", "!.a1(???????\?)bef0ffffffbb10000000", &ShipSystem__manningWhite);
}

GL_Primitive **ShipSystem__manningGreen;

namespace _var1217
{
    static VariableDefinition varObj("ShipSystem__manningGreen", "!.a1(???????\?)bee8ffffffbb18000000", &ShipSystem__manningGreen);
}

GL_Primitive **ShipSystem__manningYellow;

namespace _var1218
{
    static VariableDefinition varObj("ShipSystem__manningYellow", "!.a1(???????\?)bee8ffffffbb18000000", &ShipSystem__manningYellow);
}

GL_Primitive **ShipSystem__glowBlue;

namespace _var1219
{
    static VariableDefinition varObj("ShipSystem__glowBlue", "!.f30f116c2404e8????????a1(???????\?)890424", &ShipSystem__glowBlue);
}

GL_Primitive **ShipSystem__glowRed;

namespace _var1220
{
    static VariableDefinition varObj("ShipSystem__glowRed", "!.f30f116c2404e8????????a1(???????\?)890424", &ShipSystem__glowRed);
}

GL_Primitive **ShipSystem__glowWhite;

namespace _var1221
{
    static VariableDefinition varObj("ShipSystem__glowWhite", "!.8b153c114a08c7865801000000000000", &ShipSystem__glowWhite);
}

namespace _func1222
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(const std::string &, float , bool )), "5589e557565383ec7c8b45148b5508", argdata, 4, 2, &func);
}

int SoundControl::PlaySoundMix(const std::string &soundName, float volume, bool loop)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &soundName_arg, float volume_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1222::func;
	return execfunc(this, soundName, volume, loop);
}

namespace _func1223
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::StopPlaylist", typeid(void (SoundControl::*)(int )), "5557565383ec2c8b742440803e00", argdata, 2, 6, &func);
}

void SoundControl::StopPlaylist(int fadeOut)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SoundControl *this_arg, int fadeOut_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1223::func;
	return execfunc(this, fadeOut);
}

namespace _func1224
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::StartPlaylist", typeid(void (SoundControl::*)(std::vector<std::string> &)), "5557565383ec3c8b442450803800", argdata, 2, 6, &func);
}

void SoundControl::StartPlaylist(std::vector<std::string> &playlist)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SoundControl *this_arg, std::vector<std::string> &playlist_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1224::func;
	return execfunc(this, playlist);
}

namespace _func1225
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::UpdateSoundLoop", typeid(void (SoundControl::*)(const std::string &, float )), "5589e557565383ec??8b????8038??74??8b????8b008b78f4", argdata, 3, 6, &func);
}

void SoundControl::UpdateSoundLoop(const std::string &loopId, float count)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &loopId_arg, float count_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1225::func;
	return execfunc(this, loopId, count);
}

namespace _func1226
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::StopChannel", typeid(void (SoundControl::*)(int , float )), "5589e5565383ec408b5d08f30f104510803b000f84", argdata, 3, 6, &func);
}

void SoundControl::StopChannel(int channel, float fade)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SoundControl *this_arg, int channel_arg, float fade_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1226::func;
	return execfunc(this, channel, fade);
}

SoundControl *Global_SoundControl_Sounds;

namespace _var1227
{
    static VariableDefinition varObj("Global_SoundControl_Sounds", "!e8????????897c240889742404c70424(???????\?)e8", &Global_SoundControl_Sounds);
}

namespace _func1228
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::UpdateAimingAngle", typeid(float (SpaceDrone::*)(Pointf , float , float )), "5589e5565383ec408b5d088b450c8b5510f30f105d14", argdata, 4, 2, &func);
}

float SpaceDrone::UpdateAimingAngle(Pointf location, float percentage, float forceDesired)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Pointf location_arg, float percentage_arg, float forceDesired_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1228::func;
	return execfunc(this, location, percentage, forceDesired);
}

namespace _func1229
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetDeployed", typeid(void (SpaceDrone::*)(bool )), "565383ec148b5c24208b7424248b03891c24ff503084c074??", argdata, 2, 6, &func);
}

void SpaceDrone::SetDeployed(bool deployed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, bool deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1229::func;
	return execfunc(this, deployed);
}

namespace _func1230
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetMovementTarget", typeid(void (SpaceDrone::*)(Targetable *)), "565383ec148b7424248b5c242085f674??8b06", argdata, 2, 6, &func);
}

void SpaceDrone::SetMovementTarget(Targetable *target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Targetable *target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1230::func;
	return execfunc(this, target);
}

namespace _func1231
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::CollisionMoving", typeid(CollisionResponse (SpaceDrone::*)(Pointf , Pointf , Damage , bool )), "5557565383ec2c8b5c24408b6c24448b74246c8d4304", argdata, 6, 18, &func);
}

CollisionResponse SpaceDrone::CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1231::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func1232
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::GetNextProjectile", typeid(Projectile *(SpaceDrone::*)()), "5589e557565383ec7c8b5d088b03891c24", argdata, 1, 2, &func);
}

Projectile *SpaceDrone::GetNextProjectile()
{
	typedef Projectile *__attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1232::func;
	return execfunc(this);
}

namespace _func1233
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::constructor", typeid(void (SpaceDrone::*)(int , int , DroneBlueprint *)), "5589e557565381ecdc0000008b7d088b75148b55", argdata, 4, 6, &func);
}

void SpaceDrone::constructor(int iShipId, int selfId, DroneBlueprint *blueprint)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, int iShipId_arg, int selfId_arg, DroneBlueprint *blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1233::func;
	return execfunc(this, iShipId, selfId, blueprint);
}

namespace _func1234
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::destructor", typeid(void (SpaceDrone::*)()), "5557565383ec2c8b7424408d86fc0100", argdata, 1, 6, &func);
}

void SpaceDrone::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1234::func;
	return execfunc(this);
}

namespace _func1235
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::constructor", typeid(void (SpaceManager::*)()), "57565383ec108b5c24208d430cc70300000000", argdata, 1, 6, &func);
}

void SpaceManager::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1235::func;
	return execfunc(this);
}

namespace _func1236
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(int (SpaceManager::*)()), "8b5424040fb68274030000", argdata, 1, 2, &func);
}

int SpaceManager::GetScreenShake()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1236::func;
	return execfunc(this);
}

namespace _func1237
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(void (SpaceManager::*)(int )), "57565383ec108b7424208b7c24240fb68674020000", argdata, 2, 6, &func);
}

void SpaceManager::SaveSpace(int fileHelper)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1237::func;
	return execfunc(this, fileHelper);
}

namespace _func1238
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBeacon", typeid(ImageDesc (SpaceManager::*)()), "8b5424088b4424048b8ad4020000", argdata, 2, 18, &func);
}

ImageDesc SpaceManager::SwitchBeacon()
{
	typedef ImageDesc __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1238::func;
	return execfunc(this);
}

namespace _func1239
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchPlanet", typeid(ImageDesc (SpaceManager::*)(const std::string &)), "5589e557565381ec8c0000008b4510c7442404????????", argdata, 3, 18, &func);
}

ImageDesc SpaceManager::SwitchPlanet(const std::string &name)
{
	typedef ImageDesc __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1239::func;
	return execfunc(this, name);
}

namespace _func1240
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::UpdatePlanetImage", typeid(void (SpaceManager::*)()), "565383ec548b5c24608b83bc000000", argdata, 1, 6, &func);
}

void SpaceManager::UpdatePlanetImage()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1240::func;
	return execfunc(this);
}

namespace _func1241
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x7ff, 0x7ff, 0x7ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchImages", typeid(void (SpaceManager::*)(ImageDesc , ImageDesc , ImageDesc )), "565383ec548b5c24608b5424688b842480000000", argdata, 4, 6, &func);
}

void SpaceManager::SwitchImages(ImageDesc planet, ImageDesc unk1, ImageDesc unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, ImageDesc planet_arg, ImageDesc unk1_arg, ImageDesc unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1241::func;
	return execfunc(this, planet, unk1, unk2);
}

namespace _func1242
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SwitchBackground", typeid(ImageDesc (SpaceManager::*)(const std::string &)), "5589e557565383ec3c8b450c8b7d08", argdata, 3, 18, &func);
}

ImageDesc SpaceManager::SwitchBackground(const std::string &name)
{
	typedef ImageDesc __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1242::func;
	return execfunc(this, name);
}

namespace _func1243
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(void (SpaceManager::*)(int , bool )), "5383ec280fb64424388d5c241c", argdata, 3, 6, &func);
}

void SpaceManager::StartAsteroids(int shieldCount, bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int shieldCount_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1243::func;
	return execfunc(this, shieldCount, unk);
}

namespace _func1244
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), "5589e557565381ec9c0000008b5d088b4510", argdata, 3, 6, &func);
}

void SpaceManager::SetPlanetaryDefense(char state, int target)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, char state_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1244::func;
	return execfunc(this, state, target);
}

namespace _func1245
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(void (SpaceManager::*)(bool )), "5557565383ec2c8b7424408d7c241a8b4424448d9ea4020000888675020000", argdata, 2, 6, &func);
}

void SpaceManager::SetPulsarLevel(bool pulsarLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool pulsarLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1245::func;
	return execfunc(this, pulsarLevel);
}

namespace _func1246
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::DangerousEnvironment", typeid(bool (SpaceManager::*)()), "8b5424040fb68a8402000084c9", argdata, 1, 2, &func);
}

bool SpaceManager::DangerousEnvironment()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1246::func;
	return execfunc(this);
}

namespace _func1247
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::MouseMove", typeid(void (SpaceManager::*)(int , int , int )), "5531ed57565383ec1c8b7424308b7c24348b5c243c", argdata, 4, 6, &func);
}

void SpaceManager::MouseMove(int x, int y, int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int x_arg, int y_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1247::func;
	return execfunc(this, x, y, unk);
}

namespace _func1248
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetSelectedDrone", typeid(SpaceDrone *(SpaceManager::*)(int , int , int )), "5557565383ec1c8b6c24308b74243c8b85a8000000", argdata, 4, 2, &func);
}

SpaceDrone *SpaceManager::GetSelectedDrone(int x, int y, int unk)
{
	typedef SpaceDrone *__attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int x_arg, int y_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1248::func;
	return execfunc(this, x, y, unk);
}

namespace _func1249
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), "5383ec18a1????????8b542420", argdata, 1, 2, &func);
}

float SpaceManager::GetFlashOpacity()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1249::func;
	return execfunc(this);
}

namespace _func1250
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::GetColorTint", typeid(GL_Color (SpaceManager::*)()), "8b5424088b4424040f2805????????80ba4c03000000", argdata, 2, 18, &func);
}

GL_Color SpaceManager::GetColorTint()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1250::func;
	return execfunc(this);
}

namespace _func1251
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderBackground", typeid(void (SpaceManager::*)()), "565383ec448b7424500f2805????????", argdata, 1, 6, &func);
}

void SpaceManager::OnRenderBackground()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1251::func;
	return execfunc(this);
}

namespace _func1252
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderFleet", typeid(void (SpaceManager::*)()), "57565383ec508b7c2460", argdata, 1, 6, &func);
}

void SpaceManager::OnRenderFleet()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1252::func;
	return execfunc(this);
}

namespace _func1253
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(void (SpaceManager::*)()), "5557565383ec6c8b9c24800000000f2805????????", argdata, 1, 6, &func);
}

void SpaceManager::OnRenderForeground()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1253::func;
	return execfunc(this);
}

namespace _func1254
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(void (SpaceManager::*)(int )), "5557565383ec3c8b4424548b7c245085c0", argdata, 2, 6, &func);
}

void SpaceManager::SetDangerZone(int fleetType)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fleetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1254::func;
	return execfunc(this, fleetType);
}

namespace _func1255
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderAsteroids", typeid(void (SpaceManager::*)(int , float )), "57565383ec308b7c24408b74244480bf9400000000", argdata, 3, 6, &func);
}

void SpaceManager::OnRenderAsteroids(int fieldLayers, float unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fieldLayers_arg, float unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1255::func;
	return execfunc(this, fieldLayers, unk2);
}

namespace _func1256
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnRenderProjectiles", typeid(void (SpaceManager::*)(int , int )), "5557565383ec4c8b7c24688b4424648b5c2460", argdata, 3, 6, &func);
}

void SpaceManager::OnRenderProjectiles(int iShipId, int layerCommand)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int iShipId_arg, int layerCommand_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1256::func;
	return execfunc(this, iShipId, layerCommand);
}

namespace _func1257
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(void (SpaceManager::*)()), "5589e557565383ec5c8b75088d5de4", argdata, 1, 6, &func);
}

void SpaceManager::OnInit()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1257::func;
	return execfunc(this);
}

namespace _func1258
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::Restart", typeid(void (SpaceManager::*)()), ".57565383ec108b7424208b168b4604", argdata, 1, 6, &func);
}

void SpaceManager::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1258::func;
	return execfunc(this);
}

namespace _func1259
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), "8b442404c6807402000000c6807502000000", argdata, 1, 6, &func);
}

void SpaceManager::ClearEnvironment()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1259::func;
	return execfunc(this);
}

namespace _func1260
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::Clear", typeid(void (SpaceManager::*)()), "57565383ec108b5c24208b839c000000", argdata, 1, 6, &func);
}

void SpaceManager::Clear()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1260::func;
	return execfunc(this);
}

namespace _func1261
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::ClearProjectiles", typeid(void (SpaceManager::*)()), ".57565383ec108b7424208b168b4604", argdata, 1, 6, &func);
}

void SpaceManager::ClearProjectiles()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1261::func;
	return execfunc(this);
}

namespace _func1262
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::UpdateProjectile", typeid(void (SpaceManager::*)(Projectile *)), "555731ff565383ec1c8b5c24348b7424308b03", argdata, 2, 6, &func);
}

void SpaceManager::UpdateProjectile(Projectile *proj)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1262::func;
	return execfunc(this, proj);
}

namespace _func1263
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::TransferProjectile", typeid(void (SpaceManager::*)(Projectile *)), "565383ec148b5c24248b038b7370", argdata, 2, 6, &func);
}

void SpaceManager::TransferProjectile(Projectile *proj)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1263::func;
	return execfunc(this, proj);
}

namespace _func1264
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddShip", typeid(void (SpaceManager::*)(ShipManager *)), "5589e557565383ec2c8b5d088b83a00000003b83a4000000", argdata, 2, 6, &func);
}

void SpaceManager::AddShip(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1264::func;
	return execfunc(this, ship);
}

namespace _func1265
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::AddProjectile", typeid(void (SpaceManager::*)(Projectile *)), "83ec1c8b4424208b50043b5008", argdata, 2, 6, &func);
}

void SpaceManager::AddProjectile(Projectile *proj)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, Projectile *proj_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1265::func;
	return execfunc(this, proj);
}

namespace _func1266
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(void (SpaceManager::*)(int )), "5589e557565383ec3c8b450c8b7508890424", argdata, 2, 6, &func);
}

void SpaceManager::LoadSpace(int fileHelper)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1266::func;
	return execfunc(this, fileHelper);
}

namespace _func1267
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::UpdatePDS", typeid(void (SpaceManager::*)()), "5589e5575631f65381ec0c010000", argdata, 1, 6, &func);
}

void SpaceManager::UpdatePDS()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1267::func;
	return execfunc(this);
}

namespace _func1268
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnLoopNebulas", typeid(void (SpaceManager::*)()), "5557565331db81ec8c0000008b8424a00000008bbc24a0000000", argdata, 1, 6, &func);
}

void SpaceManager::OnLoopNebulas()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1268::func;
	return execfunc(this);
}

namespace _func1269
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(void (SpaceManager::*)()), "5589e557565383ec6c8b75088d860c030000890424", argdata, 1, 6, &func);
}

void SpaceManager::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1269::func;
	return execfunc(this);
}

namespace _func1270
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)(bool )), "5557565381ec9c0000008b9c24b00000008b8424b4000000", argdata, 2, 6, &func);
}

void SpaceManager::SetNebula(bool state)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1270::func;
	return execfunc(this, state);
}

namespace _func1271
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)(bool )), "5383ec288b4424308d5c241cc6802a03000001", argdata, 2, 6, &func);
}

void SpaceManager::SetStorm(bool state)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1271::func;
	return execfunc(this, state);
}

namespace _func1272
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(void (SpaceManager::*)(bool )), "5557565383ec2c8b7424408d7c241a8b4424448d9ea4020000888674020000", argdata, 2, 6, &func);
}

void SpaceManager::SetFireLevel(bool state)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1272::func;
	return execfunc(this, state);
}

namespace _func1273
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("SpaceStatus::OnInit", typeid(void (SpaceStatus::*)(SpaceManager *, Point )), "55575631f65383ec7c8b9c24????????", argdata, 3, 6, &func);
}

void SpaceStatus::OnInit(SpaceManager *space, Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, SpaceManager *space_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1273::func;
	return execfunc(this, space, pos);
}

namespace _func1274
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceStatus::RenderWarningText", typeid(void (SpaceStatus::*)(int , int )), "5589e557565381ec9c0000008b55088b", argdata, 3, 6, &func);
}

void SpaceStatus::RenderWarningText(int effect, int textOffset)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int effect_arg, int textOffset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1274::func;
	return execfunc(this, effect, textOffset);
}

namespace _func1275
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SpaceStatus::OnRender", typeid(void (SpaceStatus::*)()), "57565383ec208b5c24308b432c890424", argdata, 1, 6, &func);
}

void SpaceStatus::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1275::func;
	return execfunc(this);
}

namespace _func1276
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceStatus::MouseMove", typeid(void (SpaceStatus::*)(int , int )), "57565383ec208b5c24308b7424348b43", argdata, 3, 6, &func);
}

void SpaceStatus::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1276::func;
	return execfunc(this, mX, mY);
}

namespace _func1277
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("StarMap::SetPosition", typeid(void (StarMap::*)(Point )), "8b4c24048b4424088b54240c89415c", argdata, 2, 6, &func);
}

void StarMap::SetPosition(Point unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1277::func;
	return execfunc(this, unk0);
}

namespace _func1278
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::KeyDown", typeid(void (StarMap::*)(int )), "56538b74240c80be8406000000", argdata, 2, 6, &func);
}

void StarMap::KeyDown(int unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1278::func;
	return execfunc(this, unk0);
}

namespace _func1279
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::GetNextDangerMove", typeid(int (StarMap::*)()), "5631c0538b54240c83ba800000003b", argdata, 1, 2, &func);
}

int StarMap::GetNextDangerMove()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1279::func;
	return execfunc(this);
}

namespace _func1280
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::Open", typeid(void (StarMap::*)()), "5383ec188b5c2420807b040074??83c418", argdata, 1, 6, &func);
}

void StarMap::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1280::func;
	return execfunc(this);
}

namespace _func1281
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::Close", typeid(void (StarMap::*)()), "565383ec248b74243080be3406000000", argdata, 1, 6, &func);
}

void StarMap::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1281::func;
	return execfunc(this);
}

namespace _func1282
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetOpen", typeid(void (StarMap::*)(bool )), "8b442404807c2408008b1075??", argdata, 2, 6, &func);
}

void StarMap::SetOpen(bool unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1282::func;
	return execfunc(this, unk0);
}

namespace _func1283
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::InitMapTitle", typeid(void (StarMap::*)()), "5589e557565381ec8c0000008b45088d75d88d5dcc", argdata, 1, 6, &func);
}

void StarMap::InitMapTitle()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1283::func;
	return execfunc(this);
}

namespace _func1284
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::InitNoFuelText", typeid(void (StarMap::*)()), "5557565383ec5c8b6c24708d5c24408d7c243f8b8568040000", argdata, 1, 6, &func);
}

void StarMap::InitNoFuelText()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1284::func;
	return execfunc(this);
}

namespace _func1285
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::InitBossMessageBox", typeid(void (StarMap::*)()), "5589e557565383ec3c8b5d088bb3cc050000", argdata, 1, 6, &func);
}

void StarMap::InitBossMessageBox()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1285::func;
	return execfunc(this);
}

namespace _func1286
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::OnLanguageChange", typeid(void (StarMap::*)()), "5383ec188b5c2420891c24e8????????891c24e8????????895c2420", argdata, 1, 6, &func);
}

void StarMap::OnLanguageChange()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1286::func;
	return execfunc(this);
}

namespace _func1287
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::GetRandomSectorChoice", typeid(int (StarMap::*)()), "83ec0c803d????????0075??e8????????89c1", argdata, 1, 2, &func);
}

int StarMap::GetRandomSectorChoice()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1287::func;
	return execfunc(this);
}

namespace _func1288
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::NeighboringSector", typeid(bool (StarMap::*)(int )), "5631c0538b5c24108b4c240c85db", argdata, 2, 2, &func);
}

bool StarMap::NeighboringSector(int potentialSector)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int potentialSector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1288::func;
	return execfunc(this, potentialSector);
}

namespace _func1289
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetSelectedSector", typeid(void (StarMap::*)(int , int , int )), "5557565383ec2c8b6c24408b5424488b4424448b5c244c", argdata, 4, 6, &func);
}

void StarMap::GetSelectedSector(int unk0, int unk1, int unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg, int unk1_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1289::func;
	return execfunc(this, unk0, unk1, unk2);
}

namespace _func1290
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::StartSecretSector", typeid(void (StarMap::*)()), "5383ec288b4424308d5c241c8b9080060000", argdata, 1, 6, &func);
}

void StarMap::StartSecretSector()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1290::func;
	return execfunc(this);
}

namespace _func1291
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ReachSector", typeid(void (StarMap::*)(Sector *)), "5557565383ec5c8b7c24748b442474", argdata, 2, 6, &func);
}

void StarMap::ReachSector(Sector *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1291::func;
	return execfunc(this, unk0);
}

namespace _func1292
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::UpdateSectorMap", typeid(void (StarMap::*)(Sector *)), "5756538b7c24148b74241085ff", argdata, 2, 6, &func);
}

void StarMap::UpdateSectorMap(Sector *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1292::func;
	return execfunc(this, unk0);
}

namespace _func1293
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SaveGame", typeid(void (StarMap::*)(int )), "5557565383ec3c8b6c24508b5c24548b857c060000", argdata, 2, 6, &func);
}

void StarMap::SaveGame(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1293::func;
	return execfunc(this, file);
}

namespace _func1294
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::InitStatistics", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000f3c38db4", argdata, 1, 6, &func);
}

void StarMap::InitStatistics()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1294::func;
	return execfunc(this);
}

namespace _func1295
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::PrintStatistics", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc2700000000f3c38db4", argdata, 1, 6, &func);
}

void StarMap::PrintStatistics()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1295::func;
	return execfunc(this);
}

namespace _func1296
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::AnalyzeMap", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc27000000008b442404", argdata, 1, 6, &func);
}

void StarMap::AnalyzeMap()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1296::func;
	return execfunc(this);
}

namespace _func1297
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ModifyPursuit", typeid(void (StarMap::*)(int )), "8b4424048b542408019020040000", argdata, 2, 6, &func);
}

void StarMap::ModifyPursuit(int unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1297::func;
	return execfunc(this, unk0);
}

namespace _func1298
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::AtBeacon", typeid(void (StarMap::*)()), "8b4424048b40500fb64014", argdata, 1, 6, &func);
}

void StarMap::AtBeacon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1298::func;
	return execfunc(this);
}

namespace _func1299
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::GetWaitLocation", typeid(void (StarMap::*)()), "8b44240480787c00", argdata, 1, 6, &func);
}

void StarMap::GetWaitLocation()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1299::func;
	return execfunc(this);
}

namespace _func1300
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::StartBeacon", typeid(void (StarMap::*)()), "5631c0538b54240c8b8a18040000", argdata, 1, 6, &func);
}

void StarMap::StartBeacon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1300::func;
	return execfunc(this);
}

namespace _func1301
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationsConnected", typeid(bool (StarMap::*)(Location *, Location *)), "538b44240c8b5c24108b48088b500c", argdata, 3, 2, &func);
}

bool StarMap::LocationsConnected(Location *unk0, Location *unk1)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg, Location *unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1301::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1302
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PointToGrid", typeid(Point (StarMap::*)(float , float )), "5383ec18f30f1005????????f30f104c242c", argdata, 4, 18, &func);
}

Point StarMap::PointToGrid(float x, float y)
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, float x_arg, float y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1302::func;
	return execfunc(this, x, y);
}

namespace _func1303
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::TravelToLocation", typeid(void (StarMap::*)(Location *)), "538b44240c8b54240880787c00", argdata, 2, 6, &func);
}

void StarMap::TravelToLocation(Location *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1303::func;
	return execfunc(this, unk0);
}

namespace _func1304
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::ForceExitBeacon", typeid(void (StarMap::*)()), "8b4424048b4050c6401401", argdata, 1, 6, &func);
}

void StarMap::ForceExitBeacon()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1304::func;
	return execfunc(this);
}

namespace _func1305
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::OnRenderFogEffect", typeid(void (StarMap::*)()), ".f3c38db426000000008dbc27000000005631c0", argdata, 1, 6, &func);
}

void StarMap::OnRenderFogEffect()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1305::func;
	return execfunc(this);
}

namespace _func1306
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasBoss", typeid(void (StarMap::*)(Location *)), "5631c0538b54240c8b742410", argdata, 2, 6, &func);
}

void StarMap::LocationHasBoss(Location *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1306::func;
	return execfunc(this, unk0);
}

namespace _func1307
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasStore", typeid(void (StarMap::*)(Location *)), "56538b5424108b4c240c8b422085c0", argdata, 2, 6, &func);
}

void StarMap::LocationHasStore(Location *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1307::func;
	return execfunc(this, unk0);
}

namespace _func1308
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LocationHasShip", typeid(void (StarMap::*)(Location *)), "8b4424088b402085c0", argdata, 2, 6, &func);
}

void StarMap::LocationHasShip(Location *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1308::func;
	return execfunc(this, unk0);
}

namespace _func1309
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::AdvanceWorldLevel", typeid(void (StarMap::*)()), "5557565383ec5c8b7424708b8618040000", argdata, 1, 6, &func);
}

void StarMap::AdvanceWorldLevel()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1309::func;
	return execfunc(this);
}

namespace _func1310
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::ReverseBossPath", typeid(void (StarMap::*)()), "56538b5c240c8b8bc4070000", argdata, 1, 6, &func);
}

void StarMap::ReverseBossPath()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1310::func;
	return execfunc(this);
}

namespace _func1311
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::ForceBossJump", typeid(void (StarMap::*)()), "5756538b5c241080bbbc07000000", argdata, 1, 6, &func);
}

void StarMap::ForceBossJump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1311::func;
	return execfunc(this);
}

namespace _func1312
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::ClearBoss", typeid(void (StarMap::*)()), "565331db83ec148b7424208b56208b4624c686cc07000000", argdata, 1, 6, &func);
}

void StarMap::ClearBoss()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1312::func;
	return execfunc(this);
}

namespace _func1313
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), "8b5424088b4424048990f4080000", argdata, 2, 6, &func);
}

void StarMap::SetBossStage(int stage)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int stage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1313::func;
	return execfunc(this, stage);
}

namespace _func1314
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::CheckGameOver", typeid(void (StarMap::*)()), "8b54240431c083bab807000004", argdata, 1, 6, &func);
}

void StarMap::CheckGameOver()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1314::func;
	return execfunc(this);
}

namespace _func1315
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetPotentialSectorChoiceName", typeid(std::string (StarMap::*)()), ".5589e557565383ec3c8b????8b????8b8628090000", argdata, 2, 18, &func);
}

std::string StarMap::GetPotentialSectorChoiceName()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1315::func;
	return execfunc(this);
}

namespace _func1316
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::RenderLabels", typeid(void (StarMap::*)()), "5589e557565381eccc0000008b7508e8????????", argdata, 1, 6, &func);
}

void StarMap::RenderLabels()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1316::func;
	return execfunc(this);
}

namespace _func1317
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::DeleteMap", typeid(void (StarMap::*)()), "5557565383ec2c8b7424408bbee8080000", argdata, 1, 6, &func);
}

void StarMap::DeleteMap()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1317::func;
	return execfunc(this);
}

namespace _func1318
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseClick", typeid(void (StarMap::*)(int , int )), "5557565383ec2c8b5c244080bb3005000000", argdata, 3, 6, &func);
}

void StarMap::MouseClick(int unk0, int unk1)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg, int unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1318::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1319
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::AddSectorColumn", typeid(void (StarMap::*)()), "5589e557565381ecdc0000008b75088b9ee4070000", argdata, 1, 6, &func);
}

void StarMap::AddSectorColumn()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1319::func;
	return execfunc(this);
}

namespace _func1320
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::PushSectorColumn", typeid(void (StarMap::*)()), "5557565331db83ec1c8b7c24308b8f74060000", argdata, 1, 6, &func);
}

void StarMap::PushSectorColumn()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1320::func;
	return execfunc(this);
}

namespace _func1321
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SelectNewSector", typeid(void (StarMap::*)(int )), "57565383ec108b7424208b442424", argdata, 2, 6, &func);
}

void StarMap::SelectNewSector(int unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1321::func;
	return execfunc(this, unk0);
}

namespace _func1322
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateSectorMap", typeid(void (StarMap::*)()), "5589e557565381ecbc0000008b5d088b8b74060000", argdata, 1, 6, &func);
}

void StarMap::GenerateSectorMap()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1322::func;
	return execfunc(this);
}

namespace _func1323
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::constructor", typeid(void (StarMap::*)()), "5589e557565381ec7c0100008b7d088d9d28ffffff", argdata, 1, 6, &func);
}

void StarMap::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1323::func;
	return execfunc(this);
}

namespace _func1324
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("StarMap::RenderSectorName", typeid(void (StarMap::*)(Sector *, GL_Color )), "5589e557565381ec2c0100008b450c80787000", argdata, 3, 6, &func);
}

void StarMap::RenderSectorName(Sector *unk0, GL_Color unk1)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg, GL_Color unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1324::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1325
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::UpdateDangerZone", typeid(void (StarMap::*)()), "565383ec448b5c245080bb3406000000", argdata, 1, 6, &func);
}

void StarMap::UpdateDangerZone()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1325::func;
	return execfunc(this);
}

namespace _func1326
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::GetNewLocation", typeid(Location *(StarMap::*)()), "5731c0565383ec108b7c2420807f7c00", argdata, 1, 2, &func);
}

Location *StarMap::GetNewLocation()
{
	typedef Location *__attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1326::func;
	return execfunc(this);
}

namespace _func1327
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::OnLoop", typeid(void (StarMap::*)()), ".5589e557565383ec3c8b7d08807f0400", argdata, 1, 6, &func);
}

void StarMap::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1327::func;
	return execfunc(this);
}

namespace _func1328
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateEvents", typeid(void (StarMap::*)(bool )), "5557565381ecdc0000008b8424f400000089442420", argdata, 2, 6, &func);
}

void StarMap::GenerateEvents(bool tutorial)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool tutorial_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1328::func;
	return execfunc(this, tutorial);
}

namespace _func1329
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddConnections", typeid(void (StarMap::*)(Location *)), "5589e557565383ec5c8b7d088d870c090000", argdata, 2, 6, &func);
}

void StarMap::AddConnections(Location *unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1329::func;
	return execfunc(this, unk0);
}

namespace _func1330
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::MapConnected", typeid(void (StarMap::*)()), "5383ec188b5c24208b831009000089442404", argdata, 1, 6, &func);
}

void StarMap::MapConnected()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1330::func;
	return execfunc(this);
}

namespace _func1331
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("StarMap::ConnectLocations", typeid(void (StarMap::*)(Point , Point )), "5589e557565383ec3c8b75088d45e48d7d0c", argdata, 3, 6, &func);
}

void StarMap::ConnectLocations(Point unk0, Point unk1)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg, Point unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1331::func;
	return execfunc(this, unk0, unk1);
}

namespace _func1332
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("StarMap::PopulateGrid", typeid(void (StarMap::*)(Point )), "5589e557565383ec6c8b5d088d4d0c", argdata, 2, 6, &func);
}

void StarMap::PopulateGrid(Point unk0)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1332::func;
	return execfunc(this, unk0);
}

namespace _func1333
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PopClosestLoc", typeid(Location *(StarMap::*)(std::vector<Location*> &, std::map<Location*, int> &)), "5589e557565383ec5c8b750c8b46048b3e", argdata, 3, 2, &func);
}

Location *StarMap::PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map)
{
	typedef Location *__attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, std::vector<Location*> &vec_arg, std::map<Location*, int> &map_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1333::func;
	return execfunc(this, vec, map);
}

namespace _func1334
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddQuest", typeid(bool (StarMap::*)(const std::string &, bool )), "5557565383ec6c0fb68424880000008bb42480000000", argdata, 3, 2, &func);
}

bool StarMap::AddQuest(const std::string &questEvent, bool force)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, const std::string &questEvent_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1334::func;
	return execfunc(this, questEvent, force);
}

namespace _func1335
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateMap", typeid(Location *(StarMap::*)(bool , bool )), "5589e557565381ecfc0000008b5d0c807d1000", argdata, 3, 2, &func);
}

Location *StarMap::GenerateMap(bool tutorial, bool seed)
{
	typedef Location *__attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool tutorial_arg, bool seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1335::func;
	return execfunc(this, tutorial, seed);
}

namespace _func1336
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::NewGame", typeid(Location *(StarMap::*)(bool )), "5589e557565383ec6c8b7d088b450c8b8f64060000", argdata, 2, 2, &func);
}

Location *StarMap::NewGame(bool unk0)
{
	typedef Location *__attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, bool unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1336::func;
	return execfunc(this, unk0);
}

namespace _func1337
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::Dijkstra", typeid(std::vector<Location*> (StarMap::*)(Location *, Location *, bool )), "5589e557565381ecdc0000008b45088b7518", argdata, 5, 18, &func);
}

std::vector<Location*> StarMap::Dijkstra(Location *start, Location *finish, bool include_unknown)
{
	typedef std::vector<Location*> __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *start_arg, Location *finish_arg, bool include_unknown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1337::func;
	return execfunc(this, start, finish, include_unknown);
}

namespace _func1338
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseMove", typeid(void (StarMap::*)(int , int )), "5589e557565381ec8c0000008b45088b5d0c8b7510", argdata, 3, 6, &func);
}

void StarMap::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1338::func;
	return execfunc(this, x, y);
}

namespace _func1339
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::OnTouch", typeid(void (StarMap::*)(TouchAction , int , int , int , int , int )), "5589e557565381ec8c0000008b750880be6006000000", argdata, 7, 6, &func);
}

void StarMap::OnTouch(TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, TouchAction unk0_arg, int unk1_arg, int unk2_arg, int unk3_arg, int unk4_arg, int unk5_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1339::func;
	return execfunc(this, unk0, unk1, unk2, unk3, unk4, unk5);
}

namespace _func1340
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::LoadGame", typeid(Location *(StarMap::*)(int )), "5589e557565381ecac0200008b450c8b5d08", argdata, 2, 2, &func);
}

Location *StarMap::LoadGame(int fileHelper)
{
	typedef Location *__attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1340::func;
	return execfunc(this, fileHelper);
}

namespace _func1341
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::RenderLeftInsetButton", typeid(void (StarMap::*)(float , float , bool )), "5589e5565383ec708b75148b5d08", argdata, 4, 6, &func);
}

void StarMap::RenderLeftInsetButton(float unk0, float unk1, bool unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, float unk0_arg, float unk1_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1341::func;
	return execfunc(this, unk0, unk1, unk2);
}

namespace _func1342
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StarMap::RenderDistressButtons", typeid(void (StarMap::*)()), "5589e557565381eccc0000008b5d088d45b7", argdata, 1, 6, &func);
}

void StarMap::RenderDistressButtons()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1342::func;
	return execfunc(this);
}

namespace _func1343
{
    static void *func = 0;
	static short argdata[] = {0x100};
	static FunctionDefinition funcObj("StarMap::OnRender", typeid(void (StarMap::*)()), "5589e55789c7565381ec7c01000080b88406000000", argdata, 1, 6, &func);
}

void StarMap::OnRender()
{
	typedef void __attribute__((regparm(1))) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1343::func;
	return execfunc(this);
}

namespace _func1344
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::DrawConnection", typeid(void (StarMap::*)(const Pointf &, const Pointf &, const GL_Color *)), "5589e557565381ec9c0000008b450c8b5d148b50048b00", argdata, 4, 6, &func);
}

void StarMap::DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color *color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, const Pointf &pos1_arg, const Pointf &pos2_arg, const GL_Color *color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1344::func;
	return execfunc(this, pos1, pos2, color);
}

namespace _func1345
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::TurnIntoFleetLocation", typeid(void (StarMap::*)(Location *)), "5589e557565383ec5c8b5d0c8b4320", argdata, 2, 6, &func);
}

void StarMap::TurnIntoFleetLocation(Location *loc)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1345::func;
	return execfunc(this, loc);
}

namespace _func1346
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetLocationText", typeid(std::string (StarMap::*)(const Location *)), "5589e557565383ec3c8b45088b5d0c", argdata, 3, 18, &func);
}

std::string StarMap::GetLocationText(const Location *loc)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, const Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1346::func;
	return execfunc(this, loc);
}

namespace _func1347
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetupNoFuel", typeid(void (StarMap::*)(int , const std::string &)), "5589e557565381ec9c0000008b7d08837d0cff", argdata, 3, 6, &func);
}

void StarMap::SetupNoFuel(int seed, const std::string &forceEscape)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, int seed_arg, const std::string &forceEscape_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1347::func;
	return execfunc(this, seed, forceEscape);
}

namespace _func1348
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GenerateNebulas", typeid(void (StarMap::*)(const std::vector<std::string> &)), "5589e557565381ecbc0000008b450c8b5004", argdata, 2, 6, &func);
}

void StarMap::GenerateNebulas(const std::vector<std::string> &names)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StarMap *this_arg, const std::vector<std::string> &names_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1348::func;
	return execfunc(this, names);
}

namespace _func1349
{
    static void *func = 0;
	static short argdata[] = {0x100};
	static FunctionDefinition funcObj("StarMap::UpdateBoss", typeid(void (StarMap::*)()), "5557565389c383ec2c8b80b40700008b93c0070000", argdata, 1, 6, &func);
}

void StarMap::UpdateBoss()
{
	typedef void __attribute__((regparm(1))) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1349::func;
	return execfunc(this);
}

namespace _func1350
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StatusEffect::GetNebulaEffect", typeid(StatusEffect (*)()), "5383ec18803d????????008b5c242074??660f6f05????????660f7f05????????a1????????c70302000000", argdata, 1, 18, &func);
}

StatusEffect StatusEffect::GetNebulaEffect()
{
	typedef StatusEffect __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1350::func;
	return execfunc();
}

namespace _func1351
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::OnInit", typeid(void (Store::*)(ShipManager *, Equipment *, int )), "5557565383ec1c8b5c24308b4424348b7c24388b6c243c", argdata, 4, 6, &func);
}

void Store::OnInit(ShipManager *shopper, Equipment *equip, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *shopper_arg, Equipment *equip_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1351::func;
	return execfunc(this, shopper, equip, worldLevel);
}

namespace _func1352
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::CreateStoreBoxes", typeid(void (Store::*)(int , Equipment *)), "5589e557565383ec7c8b750c8b7d08", argdata, 3, 6, &func);
}

void Store::CreateStoreBoxes(int type, Equipment *equip)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int type_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1352::func;
	return execfunc(this, type, equip);
}

namespace _func1353
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::KeyDown", typeid(bool (Store::*)(SDLKey )), "5383ec188b5c24208b542424", argdata, 2, 2, &func);
}

bool Store::KeyDown(SDLKey key)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1353::func;
	return execfunc(this, key);
}

namespace _func1354
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::OnLoop", typeid(void (Store::*)()), "565331db83ec148b7424208b9660030000", argdata, 1, 6, &func);
}

void Store::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1354::func;
	return execfunc(this);
}

namespace _func1355
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::Close", typeid(void (Store::*)()), "5383ec188b5c24208b839c040000", argdata, 1, 6, &func);
}

void Store::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1355::func;
	return execfunc(this);
}

namespace _func1356
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::MouseMove", typeid(void (Store::*)(int , int )), "5589e557565381ec2c0100008b5d088b450c8b7d10", argdata, 3, 6, &func);
}

void Store::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1356::func;
	return execfunc(this, x, y);
}

namespace _func1357
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::constructor", typeid(void (Store::*)()), "5557565383ec2c8b5c24408d7c241f891c24", argdata, 1, 6, &func);
}

void Store::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1357::func;
	return execfunc(this);
}

namespace _func1358
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::SaveStore", typeid(void (Store::*)(int )), "5557565383ec1c8b5c24308b7424348b8384040000", argdata, 2, 6, &func);
}

void Store::SaveStore(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1358::func;
	return execfunc(this, file);
}

namespace _func1359
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::RelinkShip", typeid(void (Store::*)(ShipManager *, Equipment *)), "5557565331db83ec1c8b6c24308b7424348b7c24388b9560030000", argdata, 3, 6, &func);
}

void Store::RelinkShip(ShipManager *ship, Equipment *equip)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *ship_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1359::func;
	return execfunc(this, ship, equip);
}

namespace _func1360
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::HasType", typeid(bool (Store::*)(int )), "8b5424048b442408398288040000", argdata, 2, 2, &func);
}

bool Store::HasType(int type)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1360::func;
	return execfunc(this, type);
}

namespace _func1361
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::Clear", typeid(void (Store::*)()), "565383ec148b7424208b8e64030000", argdata, 1, 6, &func);
}

void Store::Clear()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1361::func;
	return execfunc(this);
}

namespace _func1362
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Store::InitHeading", typeid(void (Store::*)(int , Point )), "5557565383ec4c8d5c24388b742460", argdata, 3, 6, &func);
}

void Store::InitHeading(int index, Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int index_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1362::func;
	return execfunc(this, index, pos);
}

namespace _func1363
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Store::DrawBuySellTabText", typeid(void (*)()), "5589e557565383ec4c8d45db8d5de4", argdata, 0, 6, &func);
}

void Store::DrawBuySellTabText()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1363::func;
	return execfunc();
}

namespace _func1364
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::MouseClick", typeid(void (Store::*)(int , int )), "5589e557565383ec4c8b45108b5d0889442408", argdata, 3, 6, &func);
}

void Store::MouseClick(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1364::func;
	return execfunc(this, x, y);
}

namespace _func1365
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::OnRender", typeid(void (Store::*)()), "5589e557565381ec8c0100008b5d08", argdata, 1, 6, &func);
}

void Store::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1365::func;
	return execfunc(this);
}

namespace _func1366
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::SetPositions", typeid(void (Store::*)()), "555731ff565381ec8c0000008b9c24a00000008d742470", argdata, 1, 6, &func);
}

void Store::SetPositions()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1366::func;
	return execfunc(this);
}

namespace _func1367
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::LoadStore", typeid(void (Store::*)(int , int )), "5589e557565383ec7c8b7d088b8f64030000", argdata, 3, 6, &func);
}

void Store::LoadStore(int file, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, int file_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1367::func;
	return execfunc(this, file, worldLevel);
}

namespace _func1368
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Store::SetPosition", typeid(void (Store::*)(Point )), "5383ec188b5c24208b4424248b542428891c24", argdata, 2, 6, &func);
}

void Store::SetPosition(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1368::func;
	return execfunc(this, pos);
}

namespace _func1369
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Store::destructor", typeid(void (Store::*)()), "55575631f65383ec2c8b5c24408b8b64030000", argdata, 1, 6, &func);
}

void Store::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1369::func;
	return execfunc(this);
}

namespace _func1370
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::MouseClick", typeid(void (StoreBox::*)(int , int )), "8b44240480785000", argdata, 3, 6, &func);
}

void StoreBox::MouseClick(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1370::func;
	return execfunc(this, x, y);
}

namespace _func1371
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StoreBox::Activate", typeid(void (StoreBox::*)()), "5383ec288b4424308b90c0000000", argdata, 1, 6, &func);
}

void StoreBox::Activate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1371::func;
	return execfunc(this);
}

namespace _func1372
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::InitBlueprint", typeid(void (StoreBox::*)(Blueprint *)), "57565383ec208b7424348d7c241c", argdata, 2, 6, &func);
}

void StoreBox::InitBlueprint(Blueprint *bp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg, Blueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1372::func;
	return execfunc(this, bp);
}

namespace _func1373
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StoreBox::constructor", typeid(void (StoreBox::*)(const std::string &, ShipManager *, Equipment *)), "5557565383ec3c8b5c24508d742428", argdata, 4, 6, &func);
}

void StoreBox::constructor(const std::string &buttonImage, ShipManager *shopper, Equipment *equip)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg, const std::string &buttonImage_arg, ShipManager *shopper_arg, Equipment *equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1373::func;
	return execfunc(this, buttonImage, shopper, equip);
}

namespace _func1374
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("StoreBox::SetPosition", typeid(void (StoreBox::*)(Point )), "565383ec248b4424308d70108b40108b580c8b442438", argdata, 2, 6, &func);
}

void StoreBox::SetPosition(Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1374::func;
	return execfunc(this, pos);
}

namespace _func1375
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StoreBox::OnRender", typeid(void (StoreBox::*)()), "5589e557565381ec7c0300008b5d0880bbcc00000000", argdata, 1, 6, &func);
}

void StoreBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1375::func;
	return execfunc(this);
}

namespace _func1376
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StoreBox::OnLoop", typeid(void (StoreBox::*)()), "5331c083ec188b5c24208b93b800000085d2", argdata, 1, 6, &func);
}

void StoreBox::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1376::func;
	return execfunc(this);
}

namespace _func1377
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("StoreBox::Purchase", typeid(void (StoreBox::*)()), ".5557565383ec2c8d74241c8b5c24408d7c241a", argdata, 1, 6, &func);
}

void StoreBox::Purchase()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1377::func;
	return execfunc(this);
}

namespace _func1378
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SuperShieldDrone::constructor", typeid(void (SuperShieldDrone::*)(int , int , DroneBlueprint *)), "5557565383ec??8b44????8d????1c8b5c????8d????1a8944????", argdata, 4, 6, &func);
}

void SuperShieldDrone::constructor(int iShipId, int selfId, DroneBlueprint *blueprint)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SuperShieldDrone *this_arg, int iShipId_arg, int selfId_arg, DroneBlueprint *blueprint_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1378::func;
	return execfunc(this, iShipId, selfId, blueprint);
}

namespace _func1379
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SuperShieldDrone::OnLoop", typeid(void (SuperShieldDrone::*)()), "565383ec348b5c2440891c24e8bffcff", argdata, 1, 6, &func);
}

void SuperShieldDrone::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SuperShieldDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1379::func;
	return execfunc(this);
}

namespace _func1380
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::OnRender", typeid(void (SystemBox::*)(bool )), "55b90100000089e557565383ec7c8b5d088b750c", argdata, 2, 6, &func);
}

void SystemBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1380::func;
	return execfunc(this, ignoreStatus);
}

namespace _func1381
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::constructor", typeid(void (SystemBox::*)(Point , ShipSystem *, bool )), "5557565381ec3c0100008b9c24500100008d6c2470", argdata, 4, 6, &func);
}

void SystemBox::constructor(Point pos, ShipSystem *sys, bool playerUI)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, bool playerUI_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1381::func;
	return execfunc(this, pos, sys, playerUI);
}

namespace _func1382
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::MouseMove", typeid(void (SystemBox::*)(int , int )), "5589e557565383ec2c8b5d088b750c", argdata, 3, 6, &func);
}

void SystemBox::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1382::func;
	return execfunc(this, x, y);
}

namespace _func1383
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::MouseClick", typeid(bool (SystemBox::*)(bool )), "57565331db83ec208b7424308b7c24348b464c", argdata, 2, 2, &func);
}

bool SystemBox::MouseClick(bool shift)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemBox *this_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1383::func;
	return execfunc(this, shift);
}

namespace _func1384
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::KeyDown", typeid(void (SystemBox::*)(SDLKey , bool )), "5589e557565383ec3c8b45108b7d088d5de0", argdata, 3, 6, &func);
}

void SystemBox::KeyDown(SDLKey key, bool shift)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemBox *this_arg, SDLKey key_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1384::func;
	return execfunc(this, key, shift);
}

namespace _func1385
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SystemBox::destructor", typeid(void (SystemBox::*)()), "5653bb0100000083ec248b74????c706????????8d74??00", argdata, 1, 6, &func);
}

void SystemBox::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1385::func;
	return execfunc(this);
}

namespace _func1386
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SystemControl::CreateSystemBoxes", typeid(void (SystemControl::*)()), "5557565383ec5c8d7424408b5c2470c744240800000000", argdata, 1, 6, &func);
}

void SystemControl::CreateSystemBoxes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1386::func;
	return execfunc(this);
}

namespace _func1387
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemControl::GetSystemBox", typeid(SystemBox *(SystemControl::*)(int )), "5557565331db83ec1c8b6c24308b7424348b55088b450c29d0c1f80285c0751aeb468db6000000008b550883c3018b450c29d0c1f80239c373??8b049a8d3c9d000000008b404c8b10890424ff525039f075??8b45088b043883c41c", argdata, 2, 2, &func);
}

SystemBox *SystemControl::GetSystemBox(int systemId)
{
	typedef SystemBox *__attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemControl *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1387::func;
	return execfunc(this, systemId);
}

namespace _func1388
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SystemControl::RenderPowerBar", typeid(void (SystemControl::*)()), "5589e557565383ec4c8b7d088d45e08b0f890424894c2404", argdata, 1, 6, &func);
}

void SystemControl::RenderPowerBar()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1388::func;
	return execfunc(this);
}

namespace _func1389
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemControl::GetPowerBars", typeid(SystemControl::PowerBars *(*)(int , int , int , bool )), "5557565381ec9c0000008b8424b00000008b9c24b40000008b9424bc000000", argdata, 4, 2, &func);
}

SystemControl::PowerBars *SystemControl::GetPowerBars(int width, int height, int gap, bool useShieldGap)
{
	typedef SystemControl::PowerBars *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int width_arg, int height_arg, int gap_arg, bool useShieldGap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1389::func;
	return execfunc(width, height, gap, useShieldGap);
}

Point *Global_SystemControl_weapon_position;

namespace _var1390
{
    static VariableDefinition varObj("Global_SystemControl_weapon_position", "!a3(???????\?)8915????????e8????????8b5424448b4424408b4b0c8915????????8b5308a3(???????\?)", &Global_SystemControl_weapon_position);
}

Point *Global_SystemControl_drone_position;

namespace _var1391
{
    static VariableDefinition varObj("Global_SystemControl_drone_position", "", &Global_SystemControl_drone_position);
}

namespace _func1392
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemCustomBox::constructor", typeid(void (SystemCustomBox::*)(Point , ShipSystem *, ShipManager *)), "5557565383ec5c8b5c24708b7424788b6c24748b44247c", argdata, 4, 6, &func);
}

void SystemCustomBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemCustomBox *this_arg, Point pos_arg, ShipSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1392::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func1393
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::SetExtraData", typeid(void (SystemStoreBox::*)(int )), "57565383ec208b5c24308b442434837b0404", argdata, 2, 6, &func);
}

void SystemStoreBox::SetExtraData(int droneChoice)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, int droneChoice_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1393::func;
	return execfunc(this, droneChoice);
}

namespace _func1394
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::GetConfirmText", typeid(TextString (SystemStoreBox::*)()), ".5383ec188b44????8b5c????05e80000008944????891c??", argdata, 2, 18, &func);
}

TextString SystemStoreBox::GetConfirmText()
{
	typedef TextString __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1394::func;
	return execfunc(this);
}

namespace _func1395
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::constructor", typeid(void (SystemStoreBox::*)(ShipManager *, Equipment *, int )), "5589e557565383ec6c8b75148b7d088d46fa", argdata, 4, 6, &func);
}

void SystemStoreBox::constructor(ShipManager *shopper, Equipment *equip, int sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, ShipManager *shopper_arg, Equipment *equip_arg, int sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1395::func;
	return execfunc(this, shopper, equip, sys);
}

namespace _func1396
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::CanHold", typeid(bool (SystemStoreBox::*)()), "5383ec188b5c24208b83c000000085c0", argdata, 1, 2, &func);
}

bool SystemStoreBox::CanHold()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1396::func;
	return execfunc(this);
}

namespace _func1397
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::MouseMove", typeid(void (SystemStoreBox::*)(int , int )), "5589e557565383ec3c8b5d088b750c8b7d108b83b8000000", argdata, 3, 6, &func);
}

void SystemStoreBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1397::func;
	return execfunc(this, mX, mY);
}

namespace _func1398
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::Activate", typeid(void (SystemStoreBox::*)()), "5383ec288b5c24308b93c00000008b8398000000", argdata, 1, 6, &func);
}

void SystemStoreBox::Activate()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1398::func;
	return execfunc(this);
}

namespace _func1399
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("SystemStoreBox::Purchase", typeid(void (SystemStoreBox::*)()), "5557565383ec3c8b5c24508d74242c891c24e8????????8b4304", argdata, 1, 6, &func);
}

void SystemStoreBox::Purchase()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1399::func;
	return execfunc(this);
}

namespace _func1400
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TabbedWindow::Close", typeid(void (TabbedWindow::*)()), "!5383ec188b5c24208b53408b43288b04908b10", argdata, 1, 6, &func);
}

void TabbedWindow::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1400::func;
	return execfunc(this);
}

namespace _func1401
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TabbedWindow::SetTab", typeid(void (TabbedWindow::*)(unsigned int )), ".5557565383ec4c8b7424608d", argdata, 2, 6, &func);
}

void TabbedWindow::SetTab(unsigned int tab)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg, unsigned int tab_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1401::func;
	return execfunc(this, tab);
}

namespace _func1402
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TabbedWindow::AddWindow", typeid(void (TabbedWindow::*)(const std::string &, Button *, FocusWindow *)), ".565383ec248b4c243c", argdata, 4, 6, &func);
}

void TabbedWindow::AddWindow(const std::string &name, Button *button, FocusWindow *window)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg, const std::string &name_arg, Button *button_arg, FocusWindow *window_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1402::func;
	return execfunc(this, name, button, window);
}

namespace _func1403
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TabbedWindow::OnRender", typeid(void (TabbedWindow::*)()), "!.57565383ec208b742430e8", argdata, 1, 6, &func);
}

void TabbedWindow::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1403::func;
	return execfunc(this);
}

namespace _func1404
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TabbedWindow::MouseMove", typeid(void (TabbedWindow::*)(int , int )), ".5557565383ec1c8b6c24308b7424348b7c24388b", argdata, 3, 6, &func);
}

void TabbedWindow::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1404::func;
	return execfunc(this, mX, mY);
}

namespace _func1405
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportBox::constructor", typeid(void (TeleportBox::*)(Point , TeleportSystem *)), "5557565383ec7c8bbc24900000008d6c24508b842494000000", argdata, 3, 6, &func);
}

void TeleportBox::constructor(Point pos, TeleportSystem *sys)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportBox *this_arg, Point pos_arg, TeleportSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1405::func;
	return execfunc(this, pos, sys);
}

namespace _func1406
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::SetHackingLevel", typeid(void (TeleportSystem::*)(int )), "565383ec148b7424248b5c242083fe017e??83bb80010000017e??89b38001000083c4145b5ec3??c783980100000000c842", argdata, 2, 6, &func);
}

void TeleportSystem::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1406::func;
	return execfunc(this, hackingLevel);
}

namespace _func1407
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::OnRenderFloor", typeid(void (TeleportSystem::*)()), ".5557565383ec6c", argdata, 1, 6, &func);
}

void TeleportSystem::OnRenderFloor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1407::func;
	return execfunc(this);
}

namespace _func1408
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::constructor", typeid(void (TeleportSystem::*)(int , int , int , int )), "565383ec248b4424408b5c24308b74243889442410", argdata, 5, 6, &func);
}

void TeleportSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int systemId_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1408::func;
	return execfunc(this, systemId, roomId, shipId, startingPower);
}

namespace _func1409
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::GetChargedPercent", typeid(float (TeleportSystem::*)()), "83ec048b442408f30f108098010000", argdata, 1, 2, &func);
}

float TeleportSystem::GetChargedPercent()
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1409::func;
	return execfunc(this);
}

namespace _func1410
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::Charged", typeid(bool (TeleportSystem::*)()), ".5383ec188b5c2420891c24e8????????84c0", argdata, 1, 2, &func);
}

bool TeleportSystem::Charged()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1410::func;
	return execfunc(this);
}

namespace _func1411
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::ClearCrewLocations", typeid(void (TeleportSystem::*)()), "5557565383ec1c8b5c24308bbbbc010000c783b801000000000000", argdata, 1, 6, &func);
}

void TeleportSystem::ClearCrewLocations()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1411::func;
	return execfunc(this);
}

namespace _func1412
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::UpdateCrewLocation", typeid(void (TeleportSystem::*)(int )), "538b5424088b4c240c8b82a4010000", argdata, 2, 6, &func);
}

void TeleportSystem::UpdateCrewLocation(int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1412::func;
	return execfunc(this, unk);
}

namespace _func1413
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::SetArmed", typeid(void (TeleportSystem::*)(int )), ".57565383ec208b4424348b5c243083f801", argdata, 2, 6, &func);
}

void TeleportSystem::SetArmed(int armed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int armed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1413::func;
	return execfunc(this, armed);
}

namespace _func1414
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::ForceReady", typeid(void (TeleportSystem::*)()), "83ec1c8b442420c780980100000000c842", argdata, 1, 6, &func);
}

void TeleportSystem::ForceReady()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1414::func;
	return execfunc(this);
}

namespace _func1415
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::CanSend", typeid(bool (TeleportSystem::*)()), "57565383ec208b5c24308b4b0c", argdata, 1, 2, &func);
}

bool TeleportSystem::CanSend()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1415::func;
	return execfunc(this);
}

namespace _func1416
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::CanReceive", typeid(bool (TeleportSystem::*)()), "565383ec148b5c24208b74242480bb9d01000000", argdata, 1, 2, &func);
}

bool TeleportSystem::CanReceive()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1416::func;
	return execfunc(this);
}

namespace _func1417
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::InitiateTeleport", typeid(void (TeleportSystem::*)()), "5383ec288b5c2430891c24", argdata, 1, 6, &func);
}

void TeleportSystem::InitiateTeleport()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1417::func;
	return execfunc(this);
}

namespace _func1418
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::OnLoop", typeid(void (TeleportSystem::*)()), "57565383ec308b5c2440891c24e8????????8b03891c24ff502c84c0", argdata, 1, 6, &func);
}

void TeleportSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1418::func;
	return execfunc(this);
}

namespace _func1419
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::Jump", typeid(void (TeleportSystem::*)()), "5383ec188b5c2420891c24e8????????c7839801000000000000", argdata, 1, 6, &func);
}

void TeleportSystem::Jump()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1419::func;
	return execfunc(this);
}

namespace _func1420
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::ResetPrimitives", typeid(void (TextButton::*)()), "565331db83ec148b7424208b449e48", argdata, 1, 6, &func);
}

void TextButton::ResetPrimitives()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1420::func;
	return execfunc(this);
}

namespace _func1421
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), "5589e5565383ec408b5d0880bbc800000000", argdata, 1, 2, &func);
}

int TextButton::GetIdealButtonWidth()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1421::func;
	return execfunc(this);
}

namespace _func1422
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::OnInit", typeid(void (TextButton::*)(Point , Point , int , TextString *, int )), "5589e557565383ec6c8b450c8b5d088b7520", argdata, 6, 6, &func);
}

void TextButton::OnInit(Point pos, Point size, int cornerInset, TextString *buttonLabel, int font)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, Point pos_arg, Point size_arg, int cornerInset_arg, TextString *buttonLabel_arg, int font_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1422::func;
	return execfunc(this, pos, size, cornerInset, buttonLabel, font);
}

namespace _func1423
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), "5589e557565383ec6c8b5d0880bbb400000000", argdata, 1, 6, &func);
}

void TextButton::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1423::func;
	return execfunc(this);
}

namespace _func1424
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "565383ec248b5c24308b4348", argdata, 1, 6, &func);
}

void TextButton::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1424::func;
	return execfunc(this);
}

namespace _func1425
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::GetSize", typeid(Point (TextButton::*)()), "5557565383ec2c8b5c24448b74244080bbb400000000", argdata, 2, 18, &func);
}

Point TextButton::GetSize()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1425::func;
	return execfunc(this);
}

namespace _func1426
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::OnInitRect", typeid(void (TextButton::*)(Globals::Rect &, int , TextString &, int )), "5557565383ec4c8b7424648b5c24608b7c246c", argdata, 5, 6, &func);
}

void TextButton::OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, Globals::Rect &rect_arg, int cornerInset_arg, TextString &buttonLabel_arg, int font_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1426::func;
	return execfunc(this, rect, cornerInset, buttonLabel, font);
}

namespace _func1427
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::SetBaseImage", typeid(void (TextButton::*)(const std::string &, Point , int )), "5557565383ec1c8b4424348b5c24308b742438", argdata, 4, 6, &func);
}

void TextButton::SetBaseImage(const std::string &name, Point pos, int autoWidthMin)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, const std::string &name_arg, Point pos_arg, int autoWidthMin_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1427::func;
	return execfunc(this, name, pos, autoWidthMin);
}

namespace _func1428
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::SetAutoWidth", typeid(void (TextButton::*)(bool , bool , int , int )), "538b4c240c8b4424088b5424188b5c2410", argdata, 5, 6, &func);
}

void TextButton::SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, bool autoWidth_arg, bool autoRightAlign_arg, int margin_arg, int min_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1428::func;
	return execfunc(this, autoWidth, autoRightAlign, margin, min);
}

namespace _func1429
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::UpdateAutoWidth", typeid(void (TextButton::*)()), ".5557565383ec2c8b5c244080bbb400000000", argdata, 1, 6, &func);
}

void TextButton::UpdateAutoWidth()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1429::func;
	return execfunc(this);
}

namespace _func1430
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::constructor", typeid(void (TextButton::*)()), "565383ec348b5c24408d4304c703????????8d7324890424", argdata, 1, 6, &func);
}

void TextButton::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1430::func;
	return execfunc(this);
}

namespace _func1431
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetInactiveColor", typeid(void (TextButton::*)(GL_Color )), ".!8b44240480786400", argdata, 2, 6, &func);
}

void TextButton::SetInactiveColor(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1431::func;
	return execfunc(this, color);
}

namespace _func1432
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetActiveColor", typeid(void (TextButton::*)(GL_Color )), ".!8b44240480786400", argdata, 2, 6, &func);
}

void TextButton::SetActiveColor(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1432::func;
	return execfunc(this, color);
}

namespace _func1433
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetSelectedColor", typeid(void (TextButton::*)(GL_Color )), ".!8b44240480786400", argdata, 2, 6, &func);
}

void TextButton::SetSelectedColor(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1433::func;
	return execfunc(this, color);
}

namespace _func1434
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff};
	static FunctionDefinition funcObj("TextButton::SetTextColor", typeid(void (TextButton::*)(GL_Color )), ".8b44240480786400", argdata, 2, 6, &func);
}

void TextButton::SetTextColor(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1434::func;
	return execfunc(this, color);
}

namespace _func1435
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextButton::InitPrimitives", typeid(void (TextButton::*)()), "5557565381eccc0000008bb424e0000000807e6400", argdata, 1, 6, &func);
}

void TextButton::InitPrimitives()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1435::func;
	return execfunc(this);
}

namespace _func1436
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::constructor", typeid(void (TextInput::*)(int , TextInput::AllowedCharType , const std::string &)), "57565383ec108b5c24208b44242c8b7424248b7c2428", argdata, 4, 6, &func);
}

void TextInput::constructor(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string &prompt)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg, int maxChars_arg, TextInput::AllowedCharType allowedCharType_arg, const std::string &prompt_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1436::func;
	return execfunc(this, maxChars, allowedCharType, prompt);
}

namespace _func1437
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("TextInput::OnRender", typeid(void (TextInput::*)(int , Point )), ".5589e557565383ec7c8b5d088b45108d75d0", argdata, 3, 6, &func);
}

void TextInput::OnRender(int font, Point pos)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg, int font_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1437::func;
	return execfunc(this, font, pos);
}

namespace _func1438
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextInput::OnLoop", typeid(void (TextInput::*)()), ".!5383ec188b4424208b501c395020", argdata, 1, 6, &func);
}

void TextInput::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1438::func;
	return execfunc(this);
}

namespace _func1439
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::OnTextEvent", typeid(void (TextInput::*)(CEvent::TextEvent )), ".57565383ec108b5c24208b442424807b2400", argdata, 2, 6, &func);
}

void TextInput::OnTextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1439::func;
	return execfunc(this, event);
}

namespace _func1440
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextInput::GetActive", typeid(bool (TextInput::*)()), ".8b4424040fb64024", argdata, 1, 2, &func);
}

bool TextInput::GetActive()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1440::func;
	return execfunc(this);
}

namespace _func1441
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::GetText", typeid(std::string (TextInput::*)()), ".5589e55383ec148b5d088b450c", argdata, 2, 18, &func);
}

std::string TextInput::GetText()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1441::func;
	return execfunc(this);
}

namespace _func1442
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextInput::Start", typeid(void (TextInput::*)()), ".5589e5565383ec208b5d088b43082b4304", argdata, 1, 6, &func);
}

void TextInput::Start()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1442::func;
	return execfunc(this);
}

namespace _func1443
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TextInput::Stop", typeid(void (TextInput::*)()), ".!8b442404c6402400", argdata, 1, 6, &func);
}

void TextInput::Stop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1443::func;
	return execfunc(this);
}

namespace _func1444
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::SetText", typeid(int (TextInput::*)(const std::string &)), ".57565383ec308b7424408d5c2410", argdata, 2, 2, &func);
}

int TextInput::SetText(const std::string &text)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1444::func;
	return execfunc(this, text);
}

namespace _func1445
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextInput::OnTextInput", typeid(void (TextInput::*)(int )), ".5589e557565383ec5c8b5d08807b2400", argdata, 2, 6, &func);
}

void TextInput::OnTextInput(int asciiChar)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextInput *this_arg, int asciiChar_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1445::func;
	return execfunc(this, asciiChar);
}

namespace _func1446
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string (TextLibrary::*)(const std::string &, const std::string &)), "5589e557565383ec5c8b450c83c01c89c2", argdata, 4, 18, &func);
}

std::string TextLibrary::GetText(const std::string &name, const std::string &lang)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextLibrary *this_arg, const std::string &name_arg, const std::string &lang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1446::func;
	return execfunc(this, name, lang);
}

namespace _func1447
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextString::GetText", typeid(std::string (TextString::*)()), "5589e55383ec148b450c8b5d0880780400", argdata, 2, 18, &func);
}

std::string TextString::GetText()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(TextString *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1447::func;
	return execfunc(this);
}

namespace _func1448
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(void (TimerHelper::*)(int )), "565383ec048b4424148b5c241083f8ffc6431101", argdata, 2, 6, &func);
}

void TimerHelper::Start(int goal)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, int goal_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1448::func;
	return execfunc(this, goal);
}

namespace _func1449
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), ".8b4424040fb64011", argdata, 1, 2, &func);
}

bool TimerHelper::Running()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1449::func;
	return execfunc(this);
}

namespace _func1450
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), ".8b4424048b54240c8910", argdata, 3, 6, &func);
}

void TimerHelper::ResetMinMax(int min, int max)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, int min_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1450::func;
	return execfunc(this, min, max);
}

namespace _func1451
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), ".8b442404f30f104c2408", argdata, 2, 6, &func);
}

void TimerHelper::SetMaxTime(float max)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, float max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1451::func;
	return execfunc(this, max);
}

namespace _func1452
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Stop", typeid(void (TimerHelper::*)()), ".8b442404c6401100", argdata, 1, 6, &func);
}

void TimerHelper::Stop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1452::func;
	return execfunc(this);
}

namespace _func1453
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), ".5383ec188b5c2420807b1100", argdata, 1, 6, &func);
}

void TimerHelper::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1453::func;
	return execfunc(this);
}

namespace _func1454
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), ".57565383ec108b5c24200fb6431184c0", argdata, 1, 2, &func);
}

bool TimerHelper::Done()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1454::func;
	return execfunc(this);
}

namespace _func1455
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::constructor", typeid(void (TutorialManager::*)()), "5383ec188b5c24208d4304c60300890424", argdata, 1, 6, &func);
}

void TutorialManager::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1455::func;
	return execfunc(this);
}

namespace _func1456
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::Running", typeid(bool (TutorialManager::*)()), ".8b4424040fb600", argdata, 1, 2, &func);
}

bool TutorialManager::Running()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1456::func;
	return execfunc(this);
}

namespace _func1457
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::AllowJumping", typeid(bool (TutorialManager::*)()), ".565383ec348b7424408d4424", argdata, 1, 2, &func);
}

bool TutorialManager::AllowJumping()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1457::func;
	return execfunc(this);
}

namespace _func1458
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::AllowUpgrades", typeid(bool (TutorialManager::*)()), ".5756be010000005383ec30", argdata, 1, 2, &func);
}

bool TutorialManager::AllowUpgrades()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1458::func;
	return execfunc(this);
}

namespace _func1459
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::MouseMove", typeid(void (TutorialManager::*)(int , int )), ".5589e557565383ec5c8b450880380075??8d65", argdata, 3, 6, &func);
}

void TutorialManager::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1459::func;
	return execfunc(this, mX, mY);
}

namespace _func1460
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::MouseClick", typeid(bool (TutorialManager::*)()), ".5589e557565383ec5c8b45080fb60084c074", argdata, 1, 2, &func);
}

bool TutorialManager::MouseClick()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1460::func;
	return execfunc(this);
}

namespace _func1461
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnLoop", typeid(void (TutorialManager::*)()), ".5589e557565383ec6c8b7d08803f", argdata, 1, 6, &func);
}

void TutorialManager::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1461::func;
	return execfunc(this);
}

namespace _func1462
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::LoadTutorial", typeid(void (TutorialManager::*)()), ".5589e557565381ec4c010100", argdata, 1, 6, &func);
}

void TutorialManager::LoadTutorial()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1462::func;
	return execfunc(this);
}

namespace _func1463
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnInit", typeid(void (TutorialManager::*)(ShipManager *, CommandGui *, CrewControl *, Upgrades *, CombatControl *, SystemControl *, TabbedWindow *)), ".5557565383ec4c8b5c24608d7424308b44247c8d7c2424", argdata, 8, 6, &func);
}

void TutorialManager::OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg, ShipManager *ship_arg, CommandGui *gui_arg, CrewControl *crewControl_arg, Upgrades *upgradesScreen_arg, CombatControl *combatControl_arg, SystemControl *sysControl_arg, TabbedWindow *unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1463::func;
	return execfunc(this, ship, gui, crewControl, upgradesScreen, combatControl, sysControl, unk);
}

namespace _func1464
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnRender", typeid(void (TutorialManager::*)()), ".5589e557565381ecac0000008b45088038", argdata, 1, 6, &func);
}

void TutorialManager::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1464::func;
	return execfunc(this);
}

TutorialManager *Global_TutorialManager_Tutorial;

namespace _var1465
{
    static VariableDefinition varObj("Global_TutorialManager_Tutorial", "!c70424(???????\?)e8????????84c075??8383c800000001", &Global_TutorialManager_Tutorial);
}

namespace _func1466
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), "5557565383ec2c8b6c24408b4424508b4c244c", argdata, 4, 6, &func);
}

void UnlockArrow::constructor(Point pos, int unk1, int unk2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg, Point pos_arg, int unk1_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1466::func;
	return execfunc(this, pos, unk1, unk2);
}

namespace _func1467
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::MouseMove", typeid(bool (UnlockArrow::*)(int , int )), ".8b542404837a0403", argdata, 3, 2, &func);
}

bool UnlockArrow::MouseMove(int x, int y)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1467::func;
	return execfunc(this, x, y);
}

namespace _func1468
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::OnRender", typeid(void (UnlockArrow::*)()), ".57565383ec508b5c24608b0385c0", argdata, 1, 6, &func);
}

void UnlockArrow::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1468::func;
	return execfunc(this);
}

namespace _func1469
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::constructorEmpty", typeid(void (UpgradeBox::*)(Point , bool )), "5557565383ec5c8b5c24708b7424748b7c24788b6c247c", argdata, 3, 6, &func);
}

void UpgradeBox::constructorEmpty(Point pos, bool subsystem)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, Point pos_arg, bool subsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1469::func;
	return execfunc(this, pos, subsystem);
}

namespace _func1470
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::constructorSystem", typeid(void (UpgradeBox::*)(ShipManager *, ShipSystem *, Point , bool )), "5589e557565383ec5c8b45148b75088b7d10", argdata, 5, 6, &func);
}

void UpgradeBox::constructorSystem(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, ShipManager *ship_arg, ShipSystem *sys_arg, Point pos_arg, bool subsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1470::func;
	return execfunc(this, ship, sys, pos, subsystem);
}

namespace _func1471
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::destructor", typeid(void (UpgradeBox::*)()), "5383ec288b5c24308b83fc000000890424", argdata, 1, 6, &func);
}

void UpgradeBox::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1471::func;
	return execfunc(this);
}

namespace _func1472
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::OnRender", typeid(void (UpgradeBox::*)()), "5589e557565381ec3c0100008b5d0880bbf900000000", argdata, 1, 6, &func);
}

void UpgradeBox::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1472::func;
	return execfunc(this);
}

namespace _func1473
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::MouseMove", typeid(void (UpgradeBox::*)(int , int )), "83ec1c8b4424208b1085d2", argdata, 3, 6, &func);
}

void UpgradeBox::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1473::func;
	return execfunc(this, mX, mY);
}

namespace _func1474
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::MouseClick", typeid(void (UpgradeBox::*)(int , int )), "5383ec288b5c24308b0385c0", argdata, 3, 6, &func);
}

void UpgradeBox::MouseClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1474::func;
	return execfunc(this, mX, mY);
}

namespace _func1475
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::MouseRightClick", typeid(void (UpgradeBox::*)(int , int )), ".565383ec248b5c24308b0385c0", argdata, 3, 6, &func);
}

void UpgradeBox::MouseRightClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1475::func;
	return execfunc(this, mX, mY);
}

namespace _func1476
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::Undo", typeid(void (UpgradeBox::*)()), "565383ec148b5c24208b431485c0", argdata, 1, 6, &func);
}

void UpgradeBox::Undo()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1476::func;
	return execfunc(this);
}

namespace _func1477
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::Accept", typeid(void (UpgradeBox::*)()), ".565383ec248b5c24308b0385c0", argdata, 1, 6, &func);
}

void UpgradeBox::Accept()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1477::func;
	return execfunc(this);
}

namespace _func1478
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::OnInit", typeid(void (Upgrades::*)(ShipManager *)), "5557565381eccc0000008b9c24e00000008db424a0000000", argdata, 2, 6, &func);
}

void Upgrades::OnInit(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1478::func;
	return execfunc(this, ship);
}

namespace _func1479
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Upgrades::Open", typeid(void (Upgrades::*)()), ".5383ec188b5c2420891c24e8????????8b432c", argdata, 1, 6, &func);
}

void Upgrades::Open()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1479::func;
	return execfunc(this);
}

namespace _func1480
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Upgrades::ClearUpgradeBoxes", typeid(void (Upgrades::*)()), "5557565383ec2c8b5c24408b4b248b532089c829d083f803", argdata, 1, 6, &func);
}

void Upgrades::ClearUpgradeBoxes()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1480::func;
	return execfunc(this);
}

namespace _func1481
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::MouseMove", typeid(void (Upgrades::*)(int , int )), "5557565331db83ec1c8b6c24308b7424348b7c2438892c24", argdata, 3, 6, &func);
}

void Upgrades::MouseMove(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1481::func;
	return execfunc(this, mX, mY);
}

namespace _func1482
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Upgrades::OnLoop", typeid(void (Upgrades::*)()), "5589e557565383ec6c8b7d08807f0400", argdata, 1, 6, &func);
}

void Upgrades::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1482::func;
	return execfunc(this);
}

namespace _func1483
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::MouseClick", typeid(void (Upgrades::*)(int , int )), "5589e557565331db83ec3c8b75088b450c8b7d10", argdata, 3, 6, &func);
}

void Upgrades::MouseClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1483::func;
	return execfunc(this, mX, mY);
}

namespace _func1484
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::MouseRightClick", typeid(void (Upgrades::*)(int , int )), "55575631f65383ec2c8b7c24408b6f24", argdata, 3, 6, &func);
}

void Upgrades::MouseRightClick(int mX, int mY)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1484::func;
	return execfunc(this, mX, mY);
}

namespace _func1485
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Upgrades::Close", typeid(void (Upgrades::*)()), ".5589e557565383ec3c8b7d08807f0400", argdata, 1, 6, &func);
}

void Upgrades::Close()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1485::func;
	return execfunc(this);
}

namespace _func1486
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Upgrades::OnRender", typeid(void (Upgrades::*)()), "5589e557565383ec7c8b5d080f2805????????", argdata, 1, 6, &func);
}

void Upgrades::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1486::func;
	return execfunc(this);
}

namespace _func1487
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Upgrades::ConfirmUpgrades", typeid(void (Upgrades::*)()), "5589e5575631f65383ec3c8b7d088b4f248b4720", argdata, 1, 6, &func);
}

void Upgrades::ConfirmUpgrades()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1487::func;
	return execfunc(this);
}

namespace _func1488
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WarningMessage::Start", typeid(void (WarningMessage::*)()), "5383ec188b5c2420807b1400", argdata, 1, 6, &func);
}

void WarningMessage::Start()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1488::func;
	return execfunc(this);
}

namespace _func1489
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WarningMessage::OnRender", typeid(void (WarningMessage::*)()), "5383ec188b5c2420807b1600", argdata, 1, 6, &func);
}

void WarningMessage::OnRender()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1489::func;
	return execfunc(this);
}

namespace _func1490
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::RenderWithAlpha", typeid(void (WarningMessage::*)(float )), "5589e557565383ec7c8b5d08807b2800", argdata, 2, 6, &func);
}

void WarningMessage::RenderWithAlpha(float alpha)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1490::func;
	return execfunc(this, alpha);
}

namespace _func1491
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WarningMessage::constructor", typeid(void (WarningMessage::*)()), "560f57c05383ec248b5c24308d74241ff30f1144240c", argdata, 1, 6, &func);
}

void WarningMessage::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1491::func;
	return execfunc(this);
}

namespace _func1492
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::InitImage", typeid(void (WarningMessage::*)(const std::string &, Point , float , bool )), "5557565383ec1c8b5c24308b7c24388b6c243c8b442434", argdata, 5, 6, &func);
}

void WarningMessage::InitImage(const std::string &imageName, Point position, float time, bool flash)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &imageName_arg, Point position_arg, float time_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1492::func;
	return execfunc(this, imageName, position, time, flash);
}

namespace _func1493
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x2ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::InitText", typeid(void (WarningMessage::*)(const TextString &, Point , float , GL_Color , bool , bool )), "5557565383ec1c8b5c24308b4424388b7424348b54243c8b6c2454", argdata, 7, 6, &func);
}

void WarningMessage::InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, Point position_arg, float time_arg, GL_Color textColor_arg, bool centerText_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1493::func;
	return execfunc(this, text, position, time, textColor, centerText, flash);
}

namespace _func1494
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WarningMessage::OnLoop", typeid(void (WarningMessage::*)()), "565383ec148b5c24208d7304893424", argdata, 1, 6, &func);
}

void WarningMessage::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1494::func;
	return execfunc(this);
}

namespace _func1495
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetImage", typeid(void (WarningMessage::*)(const std::string &)), ".5557565383ec1c8b5c24308b742434807b2800", argdata, 2, 6, &func);
}

void WarningMessage::SetImage(const std::string &imageName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &imageName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1495::func;
	return execfunc(this, imageName);
}

namespace _func1496
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &)), ".5557565383ec1c8b5c24308b742434807b2800", argdata, 2, 6, &func);
}

void WarningMessage::SetText(const TextString &text)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1496::func;
	return execfunc(this, text);
}

namespace _func1497
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("WarningMessage::SetText", typeid(void (WarningMessage::*)(const TextString &, GL_Color )), ".5557565383ec1c8b5c24308b742434807b2800", argdata, 3, 6, &func);
}

void WarningMessage::SetText(const TextString &text, GL_Color textColor)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, GL_Color textColor_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1497::func;
	return execfunc(this, text, textColor);
}

namespace _func1498
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff};
	static FunctionDefinition funcObj("WarningMessage::SetPosition", typeid(void (WarningMessage::*)(Point )), "8b4424048b5424088b4c240c80782800", argdata, 2, 6, &func);
}

void WarningMessage::SetPosition(Point position)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1498::func;
	return execfunc(this, position);
}

namespace _func1499
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetLoop", typeid(void (WarningMessage::*)(bool )), "83ec1c0fb6442424c744240800000000", argdata, 2, 6, &func);
}

void WarningMessage::SetLoop(bool loop)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1499::func;
	return execfunc(this, loop);
}

namespace _func1500
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetSound", typeid(void (WarningMessage::*)(const std::string &)), "8b442404058c00000089442404", argdata, 2, 6, &func);
}

void WarningMessage::SetSound(const std::string &sound)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1500::func;
	return execfunc(this, sound);
}

namespace _func1501
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SaveState", typeid(void (WeaponAnimation::*)(int )), "565383ec148b74????8b5c????8974????891c????????????8d", argdata, 2, 6, &func);
}

void WeaponAnimation::SaveState(int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1501::func;
	return execfunc(this, fd);
}

namespace _func1502
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::StartFire", typeid(bool (WeaponAnimation::*)()), "5383ec188b5c24200fb68391000000", argdata, 1, 2, &func);
}

bool WeaponAnimation::StartFire()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1502::func;
	return execfunc(this);
}

namespace _func1503
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SetFireTime", typeid(void (WeaponAnimation::*)(float )), "8b442404f30f104424088b5004", argdata, 2, 6, &func);
}

void WeaponAnimation::SetFireTime(float time)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1503::func;
	return execfunc(this, time);
}

namespace _func1504
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::GetSlide", typeid(Pointf (WeaponAnimation::*)()), "565383ec148b5c2424c74424", argdata, 2, 18, &func);
}

Pointf WeaponAnimation::GetSlide()
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1504::func;
	return execfunc(this);
}

namespace _func1505
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::Update", typeid(void (WeaponAnimation::*)()), "5557565383ec2c8b5c24408b7b5880bb9100000000", argdata, 1, 6, &func);
}

void WeaponAnimation::Update()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1505::func;
	return execfunc(this);
}

namespace _func1506
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::OnRender", typeid(void (WeaponAnimation::*)(float )), "5589e557565383ec7c8b????e8????????", argdata, 2, 6, &func);
}

void WeaponAnimation::OnRender(float alpha)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1506::func;
	return execfunc(this, alpha);
}

namespace _func1507
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::RenderChargeBar", typeid(void (WeaponAnimation::*)(float )), "5589e557565383ec6c8b5d08e8????????8b8b", argdata, 2, 6, &func);
}

void WeaponAnimation::RenderChargeBar(float alpha)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1507::func;
	return execfunc(this, alpha);
}

namespace _func1508
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponBlueprint::__DO_NOT_HOOK", typeid(void (WeaponBlueprint::*)()), "565383ec248b5c24308d74241f8d4304c703????????89742408890424", argdata, 0, 4, &func);
}

namespace _func1509
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponBlueprint::__DO_NOT_HOOK2", typeid(void (WeaponBlueprint::*)()), ".565383ec248b5c24308d74241f8d4304c703????????89742408890424", argdata, 0, 4, &func);
}

namespace _func1510
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponBlueprint::__DO_NOT_HOOK3", typeid(void (WeaponBlueprint::*)()), ".565383ec248b5c24308d74241f8d4304c703????????89742408890424", argdata, 0, 4, &func);
}

namespace _func1511
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::constructor", typeid(void (WeaponBlueprint::*)()), ".565383ec248b5c24308d74241f8d4304c703????????89742408890424", argdata, 1, 6, &func);
}

void WeaponBlueprint::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1511::func;
	return execfunc(this);
}

namespace _func1512
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::destructor", typeid(void (WeaponBlueprint::*)()), ".5557565383ec2c8b7c24408d74241f", argdata, 1, 6, &func);
}

void WeaponBlueprint::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1512::func;
	return execfunc(this);
}

namespace _func1513
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDescription", typeid(std::string (WeaponBlueprint::*)(bool )), "5589e557565381ecac0000008b4510898564ffffff", argdata, 3, 18, &func);
}

std::string WeaponBlueprint::GetDescription(bool tooltip)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1513::func;
	return execfunc(this, tooltip);
}

namespace _func1514
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::RenderIcon", typeid(void (WeaponBlueprint::*)(float )), "8b442404c7442404????????05cc00000089442408", argdata, 2, 6, &func);
}

void WeaponBlueprint::RenderIcon(float scale)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg, float scale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1514::func;
	return execfunc(this, scale);
}

namespace _func1515
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDimensions", typeid(Point (WeaponBlueprint::*)()), "5589e557565381ec9c030000", argdata, 2, 18, &func);
}

Point WeaponBlueprint::GetDimensions()
{
	typedef Point __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1515::func;
	return execfunc(this);
}

namespace _func1516
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBox::RenderBox", typeid(void (WeaponBox::*)(bool , bool )), "5589e557565381ec2c0200000fb64510", argdata, 3, 6, &func);
}

void WeaponBox::RenderBox(bool dragging, bool flashPowerBox)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBox *this_arg, bool dragging_arg, bool flashPowerBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1516::func;
	return execfunc(this, dragging, flashPowerBox);
}

namespace _func1517
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponBox::GenerateTooltip", typeid(std::string (WeaponBox::*)()), "5589e557565383ec2c8b750c8b5d088b06", argdata, 2, 18, &func);
}

std::string WeaponBox::GenerateTooltip()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1517::func;
	return execfunc(this);
}

namespace _func1518
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponControl::RenderWarnings", typeid(void (WeaponControl::*)()), "!5383ec188b5c????e8????????c744????00000000f30f2a4320f30f1144????f30f2a431cf30f1104??e8????????8d83a0010000", argdata, 1, 6, &func);
}

void WeaponControl::RenderWarnings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1518::func;
	return execfunc(this);
}

namespace _func1519
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::HolderLabel", typeid(TextString (WeaponControl::*)()), ".565383ec248b5c24308d44241a8d74241c", argdata, 2, 18, &func);
}

TextString WeaponControl::HolderLabel()
{
	typedef TextString __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1519::func;
	return execfunc(this);
}

namespace _func1520
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::ArmamentHotkey", typeid(SDLKey (WeaponControl::*)(unsigned int )), ".5557565381ec0c0100008d7424748934248d7c2448", argdata, 2, 2, &func);
}

SDLKey WeaponControl::ArmamentHotkey(unsigned int i)
{
	typedef SDLKey __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, unsigned int i_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1520::func;
	return execfunc(this, i);
}

namespace _func1521
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SelectArmament", typeid(void (WeaponControl::*)(unsigned int )), ".5589e557565383ec4c8b????8b????", argdata, 2, 6, &func);
}

void WeaponControl::SelectArmament(unsigned int armamentSlot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, unsigned int armamentSlot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1521::func;
	return execfunc(this, armamentSlot);
}

namespace _func1522
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponControl::constructor", typeid(void (WeaponControl::*)()), ".5557565381ecfc0100008b9c2410020000c744240403000000", argdata, 1, 6, &func);
}

void WeaponControl::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1522::func;
	return execfunc(this);
}

namespace _func1523
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::RenderBeamAiming", typeid(void (*)(Pointf , Pointf , bool )), ".5557565383ec6c8bb42480000000", argdata, 3, 6, &func);
}

void WeaponControl::RenderBeamAiming(Pointf one, Pointf two, bool bAutoFire)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf one_arg, Pointf two_arg, bool bAutoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1523::func;
	return execfunc(one, two, bAutoFire);
}

namespace _func1524
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponControl::RenderAiming", typeid(void (WeaponControl::*)()), ".55575631f65383ec4c", argdata, 1, 6, &func);
}

void WeaponControl::RenderAiming()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1524::func;
	return execfunc(this);
}

namespace _func1525
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponControl::RenderSelfAiming", typeid(void (WeaponControl::*)()), ".55575631f65383ec2c", argdata, 1, 6, &func);
}

void WeaponControl::RenderSelfAiming()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1525::func;
	return execfunc(this);
}

namespace _func1526
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SetAutofiring", typeid(void (WeaponControl::*)(bool , bool )), ".57565383ec508b4424648b7424608b7c2468", argdata, 3, 6, &func);
}

void WeaponControl::SetAutofiring(bool on, bool simple)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool on_arg, bool simple_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1526::func;
	return execfunc(this, on, simple);
}

namespace _func1527
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::Fire", typeid(void (WeaponControl::*)(std::vector<Pointf> &, int , bool )), "5557565383ec2c8b7424408b6c24448b54244c", argdata, 4, 6, &func);
}

void WeaponControl::Fire(std::vector<Pointf> &points, int target, bool autoFire)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, std::vector<Pointf> &points_arg, int target_arg, bool autoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1527::func;
	return execfunc(this, points, target, autoFire);
}

namespace _func1528
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponControl::OnLoop", typeid(void (WeaponControl::*)()), ".!5589e557565381ec8c0000008b????c744????03000000", argdata, 1, 6, &func);
}

void WeaponControl::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1528::func;
	return execfunc(this);
}

namespace _func1529
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponControl::OnLanguageChange", typeid(void (WeaponControl::*)()), ".5589e557565381ec9c0000008b5d08891c24", argdata, 1, 6, &func);
}

void WeaponControl::OnLanguageChange()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1529::func;
	return execfunc(this);
}

namespace _func1530
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::OnRender", typeid(void (WeaponControl::*)(bool )), ".565383ec248b5c2430c744240403000000", argdata, 2, 6, &func);
}

void WeaponControl::OnRender(bool unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1530::func;
	return execfunc(this, unk);
}

namespace _func1531
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LButton", typeid(bool (WeaponControl::*)(int , int , bool )), "565383ec148b5424208b4c24248b5c24288b74242c", argdata, 4, 2, &func);
}

bool WeaponControl::LButton(int x, int y, bool holdingShift)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg, bool holdingShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1531::func;
	return execfunc(this, x, y, holdingShift);
}

namespace _func1532
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::MouseMove", typeid(void (WeaponControl::*)(int , int )), "57565383ec108b5c24208b7424248b7c2428891c2489742404", argdata, 3, 6, &func);
}

void WeaponControl::MouseMove(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1532::func;
	return execfunc(this, x, y);
}

namespace _func1533
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LinkShip", typeid(void (WeaponControl::*)(ShipManager *)), "5383ec488b5c24508b442454891c2489442404", argdata, 2, 6, &func);
}

void WeaponControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1533::func;
	return execfunc(this, ship);
}

namespace _func1534
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::KeyDown", typeid(bool (WeaponControl::*)(SDLKey )), "57bf01000000565383ec308b5c24408b742444", argdata, 2, 2, &func);
}

bool WeaponControl::KeyDown(SDLKey key)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1534::func;
	return execfunc(this, key);
}

namespace _func1535
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponEquipBox::constructor", typeid(void (WeaponEquipBox::*)(Point , WeaponSystem *, int )), "565383ec548b0d????????8b5c24608d74243c8b4424688b542464894b088b0d????????8943388943408b442470895334894b0c8b0d????????89533c894360", argdata, 4, 6, &func);
}

void WeaponEquipBox::constructor(Point location, WeaponSystem *sys, int slot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponEquipBox *this_arg, Point location_arg, WeaponSystem *sys_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1535::func;
	return execfunc(this, location, sys, slot);
}

namespace _func1536
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DroneEquipBox::constructor", typeid(void (DroneEquipBox::*)(Point , DroneSystem *, int )), ".565383ec548b0d????????8b5c24608d74243c8b4424688b542464894b088b0d????????8943388943408b442470895334894b0c8b0d????????89533c894360", argdata, 4, 6, &func);
}

void DroneEquipBox::constructor(Point location, DroneSystem *sys, int slot)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(DroneEquipBox *this_arg, Point location_arg, DroneSystem *sys_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1536::func;
	return execfunc(this, location, sys, slot);
}

namespace _func1537
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("WeaponStoreBox::__DO_NOT_HOOK", typeid(void (WeaponStoreBox::*)()), "5557565383ec2c8d44241a8b5c24408d7c241c8b74244c89442408", argdata, 0, 4, &func);
}

namespace _func1538
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponStoreBox::constructor", typeid(void (WeaponStoreBox::*)(ShipManager *, Equipment *, const WeaponBlueprint *)), ".5557565383ec2c8d44241a8b5c24408d7c241c8b74244c89442408", argdata, 4, 6, &func);
}

void WeaponStoreBox::constructor(ShipManager *ship, Equipment *equip, const WeaponBlueprint *weaponBp)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponStoreBox *this_arg, ShipManager *ship_arg, Equipment *equip_arg, const WeaponBlueprint *weaponBp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1538::func;
	return execfunc(this, ship, equip, weaponBp);
}

namespace _func1539
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::ForceIncreasePower", typeid(bool (WeaponSystem::*)(int )), "5557565331db83ec1c8b7c????8b8fa4010000", argdata, 2, 2, &func);
}

bool WeaponSystem::ForceIncreasePower(int amount)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1539::func;
	return execfunc(this, amount);
}

namespace _func1540
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::RemoveWeapon", typeid(ProjectileFactory *(WeaponSystem::*)(int )), ".5531c057565383ec2c8b7c24448b5c244085ff", argdata, 2, 2, &func);
}

ProjectileFactory *WeaponSystem::RemoveWeapon(int slot)
{
	typedef ProjectileFactory *__attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1540::func;
	return execfunc(this, slot);
}

namespace _func1541
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::SetBonusPower", typeid(void (WeaponSystem::*)(int , int )), ".565383ec148b5c24208b742424891c24e8????????", argdata, 3, 6, &func);
}

void WeaponSystem::SetBonusPower(int amount, int permanentPower)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, int amount_arg, int permanentPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1541::func;
	return execfunc(this, amount, permanentPower);
}

namespace _func1542
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::OnLoop", typeid(void (WeaponSystem::*)()), ".5557565383ec3c8b6c2450892c24e8????????8b8da0010000", argdata, 1, 6, &func);
}

void WeaponSystem::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1542::func;
	return execfunc(this);
}

namespace _func1543
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::PowerWeapon", typeid(bool (WeaponSystem::*)(ProjectileFactory *, bool , bool )), ".5557565383ec1c8b74????8b5c????8b6c????8b7c????", argdata, 4, 2, &func);
}

bool WeaponSystem::PowerWeapon(ProjectileFactory *weapon, bool userDriven, bool force)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, ProjectileFactory *weapon_arg, bool userDriven_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1543::func;
	return execfunc(this, weapon, userDriven, force);
}

namespace _func1544
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystem::DePowerWeapon", typeid(bool (WeaponSystem::*)(ProjectileFactory *, bool )), ".5557565383ec1c8b74????8b5c????8b44????", argdata, 3, 2, &func);
}

bool WeaponSystem::DePowerWeapon(ProjectileFactory *weapon, bool userDriven)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystem *this_arg, ProjectileFactory *weapon_arg, bool userDriven_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1544::func;
	return execfunc(this, weapon, userDriven);
}

namespace _func1545
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystemBox::constructor", typeid(void (WeaponSystemBox::*)(Point , ShipSystem *, WeaponControl *)), "5383ec288b44243c8b5c24308b542438c7442410010000008944240c8b442434891c248954240889442404e8????????8b442440c703????????8983b00100008d83b4010000", argdata, 4, 6, &func);
}

void WeaponSystemBox::constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WeaponSystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, WeaponControl *weapCtrl_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1545::func;
	return execfunc(this, pos, sys, weapCtrl);
}

namespace _func1546
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::Draw", typeid(void (WindowFrame::*)(int , int )), "57565383ec108b7c24288b5c24208b742424", argdata, 3, 6, &func);
}

void WindowFrame::Draw(int x, int y)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1546::func;
	return execfunc(this, x, y);
}

namespace _func1547
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::DrawMask", typeid(void (WindowFrame::*)(int )), "83ec1c8b442424c70424010000008944240889442404", argdata, 2, 6, &func);
}

void WindowFrame::DrawMask(int unk)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1547::func;
	return execfunc(this, unk);
}

namespace _func1548
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::constructor", typeid(void (WindowFrame::*)(int , int , int , int )), "5557565381ecbc0000008b8424d00000008dbc24a0000000660f6eb424e0000000", argdata, 5, 6, &func);
}

void WindowFrame::constructor(int x, int y, int w, int h)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int x_arg, int y_arg, int w_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1548::func;
	return execfunc(this, x, y, w, h);
}

namespace _func1549
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WindowFrame::destructor", typeid(void (WindowFrame::*)()), "5383ec188b5c24208b4310890424", argdata, 1, 6, &func);
}

void WindowFrame::destructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WindowFrame *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1549::func;
	return execfunc(this);
}

namespace _func1550
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(void (WorldManager::*)()), "565383ec248b5c24308d74241f8d4308c70300000000", argdata, 1, 6, &func);
}

void WorldManager::constructor()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1550::func;
	return execfunc(this);
}

namespace _func1551
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), "57565383ec108b5c24208d7308893424", argdata, 1, 2, &func);
}

int WorldManager::OnInit()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1551::func;
	return execfunc(this);
}

namespace _func1552
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(CompleteShip *(WorldManager::*)(ShipEvent *, bool )), "5557565381ec1c02000080bc243802000000", argdata, 3, 2, &func);
}

CompleteShip *WorldManager::CreateShip(ShipEvent *shipEvent, bool boss)
{
	typedef CompleteShip *__attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipEvent *shipEvent_arg, bool boss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1552::func;
	return execfunc(this, shipEvent, boss);
}

namespace _func1553
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(void (WorldManager::*)(Location *)), "5589e557565381ec7c0200008b75088b7d0cc686c20e000000", argdata, 2, 6, &func);
}

void WorldManager::CreateLocation(Location *loc)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1553::func;
	return execfunc(this, loc);
}

namespace _func1554
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::ClearLocation", typeid(void (WorldManager::*)()), ".5589e557565381ec9c0100008b7508", argdata, 1, 6, &func);
}

void WorldManager::ClearLocation()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1554::func;
	return execfunc(this);
}

namespace _func1555
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::SaveGame", typeid(void (WorldManager::*)()), "5589e557565383ec2c8b5d088b83cc0c0000890424", argdata, 1, 6, &func);
}

void WorldManager::SaveGame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1555::func;
	return execfunc(this);
}

namespace _func1556
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(void (WorldManager::*)(LocationEvent *)), "5589e55789d7565389c381ec0c020000", argdata, 2, 6, &func);
}

void WorldManager::CreateChoiceBox(LocationEvent *event)
{
	typedef void __attribute__((regparm(2))) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1556::func;
	return execfunc(this, event);
}

namespace _func1557
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox0", typeid(void (WorldManager::*)(LocationEvent *)), "565383ec148b5c24208b7424248b038b48088b01", argdata, 2, 6, &func);
}

void WorldManager::CreateChoiceBox0(LocationEvent *event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1557::func;
	return execfunc(this, event);
}

namespace _func1558
{
    static void *func = 0;
	static short argdata[] = {0x100, 0x102};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(void (WorldManager::*)(LocationEvent *)), "5589e55789d7565381ec1c020000", argdata, 2, 6, &func);
}

void WorldManager::UpdateLocation(LocationEvent *event)
{
	typedef void __attribute__((regparm(2))) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1558::func;
	return execfunc(this, event);
}

namespace _func1559
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation0", typeid(void (WorldManager::*)(LocationEvent *)), ".565383ec148b5c24208b7424248b038b48088b01", argdata, 2, 6, &func);
}

void WorldManager::UpdateLocation0(LocationEvent *event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1559::func;
	return execfunc(this, event);
}

namespace _func1560
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(LocationEvent *(WorldManager::*)(LocationEvent *)), "5589e557565381ecbc0100008b7d0c8b75088b87dc010000", argdata, 2, 2, &func);
}

LocationEvent *WorldManager::ModifyResources(LocationEvent *event)
{
	typedef LocationEvent *__attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1560::func;
	return execfunc(this, event);
}

namespace _func1561
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(void (WorldManager::*)(int , int )), "5383ec188b4424248b5c24208b54242883f801", argdata, 3, 6, &func);
}

void WorldManager::ModifyEnvironment(int envFlag, int envTarget)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, int envFlag_arg, int envTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1561::func;
	return execfunc(this, envFlag, envTarget);
}

namespace _func1562
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(void (WorldManager::*)(std::vector<StatusEffect> &)), "5557565383ec3c8b5c24548b7c2450", argdata, 2, 6, &func);
}

void WorldManager::CheckStatusEffects(std::vector<StatusEffect> &vec)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, std::vector<StatusEffect> &vec_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1562::func;
	return execfunc(this, vec);
}

namespace _func1563
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyStatusEffect", typeid(void (WorldManager::*)(StatusEffect , ShipManager *, int )), "5557565383ec5c8b4424748bb424880000008b6c24708bbc248400000089442434", argdata, 4, 6, &func);
}

void WorldManager::ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, StatusEffect effect_arg, ShipManager *target_arg, int targetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1563::func;
	return execfunc(this, effect, target, targetType);
}

namespace _func1564
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(void (WorldManager::*)(ShipManager *)), "5589e557565383ec3c8b5d088b750c8b0385c0", argdata, 2, 6, &func);
}

void WorldManager::StartGame(ShipManager *ship)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1564::func;
	return execfunc(this, ship);
}

namespace _func1565
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(void (WorldManager::*)()), "5383ec188b5c2420891c24e8????????e8????????e8????????", argdata, 1, 6, &func);
}

void WorldManager::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1565::func;
	return execfunc(this);
}

namespace _func1566
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::LoadGame", typeid(void (WorldManager::*)(const std::string &)), "5589e557565381ec3c0100008b7508c78508ffffff00000000", argdata, 2, 6, &func);
}

void WorldManager::LoadGame(const std::string &fileName)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1566::func;
	return execfunc(this, fileName);
}

namespace _func1567
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(void (WorldManager::*)()), "5589e557565381ecac0000008b7508c744240400000000", argdata, 1, 6, &func);
}

void WorldManager::OnLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1567::func;
	return execfunc(this);
}

namespace _func1568
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::PauseLoop", typeid(void (WorldManager::*)()), "5589e557565383ec4c8b75088b068b10", argdata, 1, 6, &func);
}

void WorldManager::PauseLoop()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1568::func;
	return execfunc(this);
}

namespace _func1569
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(void (WorldManager::*)()), "57565383ec208b7424308d5c241c8d7c241b8b068b4008", argdata, 1, 6, &func);
}

void WorldManager::CreateNewGame()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1569::func;
	return execfunc(this);
}

namespace _func1570
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), "5383ec188b5c24208d4308890424", argdata, 1, 2, &func);
}

bool WorldManager::HostileEnvironment()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1570::func;
	return execfunc(this);
}

namespace _func1571
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::AddBoarders", typeid(bool (WorldManager::*)(BoardingEvent &)), "5557565383ec2c8b7424408b5c24448b068b5008", argdata, 2, 2, &func);
}

bool WorldManager::AddBoarders(BoardingEvent &boardingEvent)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, BoardingEvent &boardingEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1571::func;
	return execfunc(this, boardingEvent);
}

namespace _func1572
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateStore", typeid(void (WorldManager::*)(LocationEvent *)), "565383ec148b7424248b5c24208b86d4020000", argdata, 2, 6, &func);
}

void WorldManager::CreateStore(LocationEvent *event)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1572::func;
	return execfunc(this, event);
}

namespace _func1573
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckRequirements", typeid(bool (WorldManager::*)(LocationEvent *, bool )), "5557565383ec3c8b5c245485db", argdata, 3, 2, &func);
}

bool WorldManager::CheckRequirements(LocationEvent *event, bool hidden)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg, bool hidden_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1573::func;
	return execfunc(this, event, hidden);
}

namespace _func1574
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::font_data::init", typeid(void (freetype::font_data::*)(const void *, int , unsigned int , bool )), "5383ec288b44243c8b5c24300fb7d0c1e810", argdata, 5, 6, &func);
}

void freetype::font_data::init(const void *buffer, int bufferSize, unsigned int h, bool glow)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(freetype::font_data *this_arg, const void *buffer_arg, int bufferSize_arg, unsigned int h_arg, bool glow_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1574::func;
	return execfunc(this, buffer, bufferSize, h, glow);
}

namespace _func1575
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::font_data::init_bitmap", typeid(void (freetype::font_data::*)(const void *, int , int , int )), ".57565383ec208b44????", argdata, 5, 6, &func);
}

void freetype::font_data::init_bitmap(const void *buffer, int bufferSize, int size, int h)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(freetype::font_data *this_arg, const void *buffer_arg, int bufferSize_arg, int size_arg, int h_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1575::func;
	return execfunc(this, buffer, bufferSize, size, h);
}

namespace _func1576
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("freetype::font_data::clean", typeid(void (freetype::font_data::*)()), "!.8b4424048b400489442404", argdata, 1, 6, &func);
}

void freetype::font_data::clean()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(freetype::font_data *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1576::func;
	return execfunc(this);
}

namespace _func1577
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_measurePrintLines", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".5589e5565383ec208b5d088d45f289442408", argdata, 6, 18, &func);
}

Pointf freetype::easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1577::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1578
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_measureWidth", typeid(int (*)(int , const std::string &)), "5589e5565383ec308d45f289442408", argdata, 2, 2, &func);
}

int freetype::easy_measureWidth(int fontSize, const std::string &text)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1578::func;
	return execfunc(fontSize, text);
}

namespace _func1579
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_print", typeid(Pointf (*)(int , float , float , const std::string &)), ".5589e5565383ec308b5d088d45f289442408", argdata, 5, 18, &func);
}

Pointf freetype::easy_print(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1579::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1580
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printRightAlign", typeid(Pointf (*)(int , float , float , const std::string &)), ".5589e5565383ec308b5d088d45f289442408", argdata, 5, 18, &func);
}

Pointf freetype::easy_printRightAlign(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1580::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1581
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printNewlinesCentered", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".5589e5565383ec308b5d088d45f289442408", argdata, 6, 18, &func);
}

Pointf freetype::easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1581::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1582
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoNewlines", typeid(Pointf (*)(int , float , float , int , const std::string &)), ".5589e5565383ec308b5d088d45f289442408", argdata, 6, 18, &func);
}

Pointf freetype::easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, int line_length_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1582::func;
	return execfunc(fontSize, x, y, line_length, text);
}

namespace _func1583
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printCenter", typeid(Pointf (*)(int , float , float , const std::string &)), ".5589e5565383ec308b5d088d45f289442408", argdata, 5, 18, &func);
}

Pointf freetype::easy_printCenter(int fontSize, float x, float y, const std::string &text)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontSize_arg, float x_arg, float y_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1583::func;
	return execfunc(fontSize, x, y, text);
}

namespace _func1584
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("freetype::easy_printAutoShrink", typeid(void (*)(int , float , float , int , bool , const std::string &)), "5589e557565383ec6c8b7d088b75188b4514", argdata, 6, 6, &func);
}

void freetype::easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int fontId_arg, float x_arg, float y_arg, int maxWidth_arg, bool centered_arg, const std::string &text_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1584::func;
	return execfunc(fontId, x, y, maxWidth, centered, text);
}

namespace _func1585
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_height", typeid(float (*)(int , float )), ".57565383ec208b4c2430f30f1044243485c9", argdata, 2, 2, &func);
}

float __stdcall font_height(int font_id, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int font_id_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1585::func;
	return execfunc(font_id, size);
}

namespace _func1586
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_baseline", typeid(float (*)(int , float )), ".57565383ec208b4c2430f30f1044243485c9", argdata, 2, 2, &func);
}

float __stdcall font_baseline(int font_id, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int font_id_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1586::func;
	return execfunc(font_id, size);
}

float *Global_freetype_sil_freetype_outline;

namespace _var1587
{
    static VariableDefinition varObj("Global_freetype_sil_freetype_outline", "!.f30f5905(???????\?)c744240801000000f30f2dc0", &Global_freetype_sil_freetype_outline);
}

