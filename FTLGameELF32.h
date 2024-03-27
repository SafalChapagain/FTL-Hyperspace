#pragma once

#pragma warning( disable : 4722 )

#define LIBZHL_API 

#ifdef SWIG
    #define LIBZHL_INTERFACE
    #define __stdcall
    #define LIBZHL_PLACEHOLDER {(void)0;}
    #define __attribute__(x)
#elif defined(_WIN32)
    #define LIBZHL_INTERFACE __declspec(novtable)
    __declspec(noreturn) inline void __cdecl __NOP() {}
    #define LIBZHL_PLACEHOLDER {__NOP();}
#elif defined(__linux__)
    #define LIBZHL_INTERFACE
    #define LIBZHL_PLACEHOLDER {\
        _Pragma("GCC diagnostic push") \
        _Pragma("GCC diagnostic ignored \"-Wreturn-type\"") \
        (void)0; } \
        _Pragma("GCC diagnostic pop")
    #define __stdcall
#endif


#include "zhl.h"
#include "rapidxml.hpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <stdarg.h>
#include <unordered_map>
#include <math.h>
#include <queue>
#include "SigScan.h"
#include <unistd.h>
#undef LoadImage

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

struct CAchievement;
struct RandomAmount;
struct Point;

typedef std::pair<int, int> std_pair_int_int;
typedef std::pair<float, float> std_pair_float_float;
typedef std::pair<std::string, int> std_pair_std_string_int;
typedef std::pair<std::string, RandomAmount> std_pair_std_string_RandomAmount;
typedef std::pair<std::string, std::string> std_pair_std_string_std_string;
typedef std::pair<CAchievement*, Point> std_pair_CAchievement_ptr_Point;
typedef std::map<std::string, std::string> std_map_std_string_std_string;
typedef std::map<std::string, int> std_map_std_string_int;
typedef std::map<std::string, bool> std_map_std_string_bool;

    #ifdef STEAM_1_6_13_BUILD
        #define STEAM1613OPTIONSSCREENADDITIONS_TYPE Steam1613OptionsScreenStructAdditions
        #define STEAM1613OPTIONSSCREENADDITONS_NAME steamAdditions
    #else
        #define STEAM1613OPTIONSSCREENADDITIONS_TYPE
        #define STEAM1613OPTIONSSCREENADDITONS_NAME
    #endif


struct CAchievement;

struct CachedImage;

struct CachedPrimitive;
struct GL_Color;
struct GL_Primitive;

struct CachedPrimitive
{
	~CachedPrimitive()
	{
		this->destructor();
	}

	LIBZHL_API void OnRender(const GL_Color &color);
	LIBZHL_API void destructor();
	
	void *vptr;
	GL_Primitive *primitive;
};

struct GL_Texture;

struct CachedImage : CachedPrimitive
{
	enum Centered
	{
	  CENTERED = 0x0,
	};
	
	CachedImage(const std::string& path, int x, int y)
	{
		constructor1(path, x, y);
	}
	
	CachedImage(const std::string& path, Centered centered)
	{
		constructor2(path, centered);
	}

	CachedImage()
	{
		
	}
	
	CachedImage(const CachedImage &other)
	{
		constructor_copy(other);
	}

	LIBZHL_API void CreatePrimitive();
	LIBZHL_API void SetImagePath(const std::string &imagePath);
	LIBZHL_API void SetMirrored(bool _mirrored);
	LIBZHL_API void SetPosition(int x, int y);
	LIBZHL_API void SetRotation(float _rotation);
	LIBZHL_API void SetScale(float wScale, float hScale);
	LIBZHL_API void constructor1(const std::string &path, int x, int y);
	LIBZHL_API void constructor2(const std::string &path, CachedImage::Centered centered);
	LIBZHL_API void constructor_copy(const CachedImage &other);
	LIBZHL_API void destructor();
	
	std::string imageName;
	GL_Texture *texture;
	int x;
	int y;
	float wScale;
	float hScale;
	float x_start;
	float y_start;
	float x_size;
	float y_size;
	float rotation;
	bool mirrored;
};

struct Point
{
	Point(int xx, int yy) : x(xx), y(yy)  { }
	Point() { }
	
	friend bool operator==(const Point &a, const Point &b) {return a.x==b.x && a.y==b.y;}
	friend bool operator!=(const Point &a, const Point &b) {return a.x!=b.x || a.y!=b.y;}

	LIBZHL_API int Distance(Point other);
	LIBZHL_API int RelativeDistance(Point other);
	
	int x;
	int y;
};

struct TextLibrary;

struct TextLibrary
{
	std::string GetText(const std::string& name)
	{
		return TextLibrary::GetText(name, currentLanguage);
	}

	void SetLanguage(const std::string &language)
	{
		currentLanguage = language;
	}

	LIBZHL_API std::string GetText(const std::string &name, const std::string &lang);
	
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std_map_std_string_std_string> languageDictionaries;
	std::string currentLanguage;
};

struct TextString;

struct TextString
{
	TextString()
	{
		isLiteral = true;
	}

	LIBZHL_API std::string GetText();
	
	std::string data;
	bool isLiteral;
	uint8_t gap_ex[3];
};

struct CAchievement
{
	CAchievement()
	{
		this->constructor();
	}

	LIBZHL_API void OnRender(Point pos, int selected, bool showNew);
	LIBZHL_API void constructor();
	
	std::string name_id;
	std::pair<int, int> progress;
	bool unlocked;
	int8_t gap_ex_custom;
	TextString name;
	TextString description;
	TextString header;
	bool newAchievement;
	bool multiDifficulty;
	int difficulty;
	std::string ship;
	int shipDifficulties[3];
	int dimension;
	CachedImage icon;
	CachedImage miniIcon;
	CachedImage miniIconLocked;
	CachedImage lockImage;
	CachedImage dotOn;
	CachedImage dotOff;
	GL_Primitive *outline;
	GL_Primitive *mini_outline;
	GL_Primitive *lockOverlay;
};

struct RandomAmount
{
	int min;
	int max;
	float chanceNone;
};
	
enum TouchAction
{
  TOUCH_DOWN = 0x1,
  TOUCH_MOVE = 0x2,
  TOUCH_UP = 0x3,
  TOUCH_CANCEL = 0x4,
};

enum InputEventType
{
  INPUT_EVENT_JOYSTICK = 0x1,
  INPUT_EVENT_KEYBOARD = 0x2,
  INPUT_EVENT_MEMORY = 0x3,
  INPUT_EVENT_MOUSE = 0x4,
  INPUT_EVENT_TEXT = 0x5,
  INPUT_EVENT_TOUCH = 0x6,
};

enum InputEventDetail
{
  INPUT_JOYSTICK_CONNECTED = 0x1,
  INPUT_JOYSTICK_DISCONNECTED = 0x2,
  INPUT_JOYSTICK_BUTTON_DOWN = 0x3,
  INPUT_JOYSTICK_BUTTON_UP = 0x4,
  INPUT_JOYSTICK_DPAD_CHANGE = 0x5,
  INPUT_JOYSTICK_STICK_CHANGE = 0x6,
  INPUT_KEYBOARD_KEY_DOWN = 0x7,
  INPUT_KEYBOARD_KEY_UP = 0x8,
  INPUT_KEYBOARD_SYSTEM_KEY_DOWN = 0x9,
  INPUT_KEYBOARD_SYSTEM_KEY_UP = 0xA,
  INPUT_MEMORY_LOW = 0xB,
  INPUT_MOUSE_MOVE = 0xC,
  INPUT_MOUSE_LMB_DOWN = 0xD,
  INPUT_MOUSE_LMB_UP = 0xE,
  INPUT_MOUSE_MMB_DOWN = 0xF,    // TODO: Move this into an abstraction layer and import the file?
  INPUT_MOUSE_MMB_UP = 0x10,
  INPUT_MOUSE_RMB_DOWN = 0x11,
  INPUT_MOUSE_RMB_UP = 0x12,
  INPUT_MOUSE_SCROLL_H = 0x13,
  INPUT_MOUSE_SCROLL_V = 0x14,
  INPUT_TEXT_INPUT = 0x15,
  INPUT_TEXT_DONE = 0x16,
  INPUT_TEXT_CANCELLED = 0x17,
  INPUT_TEXT_CLEAR = 0x18,
  INPUT_TEXT_BACKSPACE = 0x19,
  INPUT_TEXT_DELETE = 0x1A,
  INPUT_TEXT_CURSOR_LEFT = 0x1B,
  INPUT_TEXT_CURSOR_RIGHT = 0x1C,
  INPUT_TEXT_CURSOR_HOME = 0x1D,
  INPUT_TEXT_CURSOR_END = 0x1E,
  INPUT_TOUCH_DOWN = 0x1F,
  INPUT_TOUCH_MOVE = 0x20,
  INPUT_TOUCH_UP = 0x21,
  INPUT_TOUCH_CANCEL = 0x22,
};

enum DeleteType
{
  BUFFER = 0x1,
  FRAMEBUFFER = 0x2,
  PROGRAM = 0x3,
  PROGRAM_PIPELINE = 0x4,
  RENDERBUFFER = 0x5,
  SHADER = 0x6,
  TEXTURE = 0x7,
  VERTEX_ARRAY = 0x8,
};

enum FontAlignment
{
  FONT_ALIGN_LEFT = 0x0,
  FONT_ALIGN_CENTER = 0x1,
  FONT_ALIGN_RIGHT = 0x2,
};

enum FramebufferColorType
{
  FBCOLOR_RGB8 = 0x1,
  FBCOLOR_RGBA8 = 0x2,
};

enum GL_StencilMode
{
  STENCIL_IGNORE = 0x0,
  STENCIL_SET = 0x1,
  STENCIL_USE = 0x2,
};

enum ResourceType
{
  RES_UNUSED = 0x0,
  RES_UNKNOWN = 0x1,
  RES_DATA = 0x2,
  RES_TEXTURE = 0x3,
  RES_FONT = 0x4,
  RES_SOUND = 0x5,
  RES_FILE = 0x6,
};


enum SDLKey
{
  SDLK_UNKNOWN = 0x0,
  SDLK_0 = 0x30,
  SDLK_1 = 0x31,
  SDLK_2 = 0x32,
  SDLK_3 = 0x33,
  SDLK_4 = 0x34,
  SDLK_5 = 0x35,
  SDLK_6 = 0x36,
  SDLK_7 = 0x37,
  SDLK_8 = 0x38,
  SDLK_9 = 0x39,
  SDLK_AT = 0x40,
  SDLK_AMPERSAND = 0x26,
  SDLK_ASTERISK = 0x2A,
  SDLK_BACKQUOTE = 0x60,
  SDLK_BACKSLASH = 0x5C,
  SDLK_BACKSPACE = 0x8,
  SDLK_BREAK = 0x13E,
  SDLK_CAPSLOCK = 0x12D,
  SDLK_CARET = 0x5E,
  SDLK_CLEAR = 0xC,
  SDLK_COLON = 0x3A,
  SDLK_COMMA = 0x2C,
  SDLK_COMPOSE = 0x13A,
  SDLK_DELETE = 0x7F,
  SDLK_DOLLAR = 0x24,
  SDLK_DOWN = 0x112,
  SDLK_END = 0x117,
  SDLK_EQUALS = 0x3D,
  SDLK_ESCAPE = 0x1B,
  SDLK_EURO = 0x141,
  SDLK_EXCLAIM = 0x21,
  SDLK_F1 = 0x11A,
  SDLK_F10 = 0x123,
  SDLK_F11 = 0x124,
  SDLK_F12 = 0x125,
  SDLK_F13 = 0x126,
  SDLK_F14 = 0x127,
  SDLK_F15 = 0x128,
  SDLK_F2 = 0x11B,
  SDLK_F3 = 0x11C,
  SDLK_F4 = 0x11D,
  SDLK_F5 = 0x11E,
  SDLK_F6 = 0x11F,
  SDLK_F7 = 0x120,
  SDLK_F8 = 0x121,
  SDLK_F9 = 0x122,
  SDLK_GREATER = 0x3E,
  SDLK_HASH = 0x24,
  SDLK_HELP = 0x13B,
  SDLK_HOME = 0x116,
  SDLK_INSERT = 0x115,
  SDLK_KP0 = 0x100,
  SDLK_KP1 = 0x101,
  SDLK_KP2 = 0x102,
  SDLK_KP3 = 0x103,
  SDLK_KP4 = 0x104,
  SDLK_KP5 = 0x105,
  SDLK_KP6 = 0x106,
  SDLK_KP7 = 0x107,
  SDLK_KP8 = 0x108,
  SDLK_KP9 = 0x109,
  SDLK_KP_PERIOD = 0x10A,
  SDLK_KP_DIVIDE = 0x10B,
  SDLK_KP_MULTIPLY = 0x10C,
  SDLK_KP_MINUS = 0x10D,
  SDLK_KP_PLUS = 0x10E,
  SDLK_KP_ENTER = 0x10F,
  SDLK_KP_EQUALS = 0x110,
  SDLK_LALT = 0x134,
  SDLK_LCTRL = 0x132,
  SDLK_LEFT = 0x114,
  SDLK_LEFTBRACKET = 0x5B,
  SDLK_LEFTPAREN = 0x28,
  SDLK_LESS = 0x3C,
  SDLK_LMETA = 0x136,
  SDLK_LSHIFT = 0x130,
  SDLK_LSUPER = 0x137,
  SDLK_MENU = 0x13F,
  SDLK_MINUS = 0x2D,
  SDLK_MODE = 0x139,
  SDLK_NUMLOCK = 0x12C,
  SDLK_PAGEDOWN = 0x119,
  SDLK_PAGEUP = 0x118,
  SDLK_PAUSE = 0x13,
  SDLK_PERIOD = 0x2E,
  SDLK_PLUS = 0x2B,
  SDLK_POWER = 0x140,
  SDLK_PRINTSCREEN = 0x13C,
  SDLK_QUESTION = 0x3F,
  SDLK_QUOTEDBL = 0x22,
  SDLK_QUOTE = 0x27,
  SDLK_RALT = 0x133,
  SDLK_RCTRL = 0x131,
  SDLK_RETURN = 0xD,
  SDLK_RIGHT = 0x113,
  SDLK_RIGHTBRACKET = 0x5D,
  SDLK_RIGHTPAREN = 0x29,
  SDLK_RMETA = 0x135,
  SDLK_RSHIFT = 0x12F,
  SDLK_RSUPER = 0x138,
  SDLK_SCROLLOCK = 0x12E,
  SDLK_SEMICOLON = 0x3B,
  SDLK_SLASH = 0x2F,
  SDLK_SPACE = 0x20,
  SDLK_SYSREQ = 0x13D,
  SDLK_TAB = 0x9,
  SDLK_UNDERSCORE = 0x5F,
  SDLK_UNDO = 0x142,
  SDLK_UP = 0x111,
  SDLK_a = 0x61,
  SDLK_b = 0x62,
  SDLK_c = 0x63,
  SDLK_d = 0x64,
  SDLK_e = 0x65,
  SDLK_f = 0x66,
  SDLK_g = 0x67,
  SDLK_h = 0x68,
  SDLK_i = 0x69,
  SDLK_j = 0x6A,
  SDLK_k = 0x6B,
  SDLK_l = 0x6C,
  SDLK_m = 0x6D,
  SDLK_n = 0x6E,
  SDLK_o = 0x6F,
  SDLK_p = 0x70,
  SDLK_q = 0x71,
  SDLK_r = 0x72,
  SDLK_s = 0x73,
  SDLK_t = 0x74,
  SDLK_u = 0x75,
  SDLK_v = 0x76,
  SDLK_w = 0x77,
  SDLK_x = 0x78,
  SDLK_y = 0x79,
  SDLK_z = 0x7A,
  SDLK_LAST = 0x143,
};

enum ShaderType
{
  SHADER_TYPE_VERTEX = 0x0,
  SHADER_TYPE_FRAGMENT = 0x1,
};

enum GraphicsPrimitiveType
{
  GRAPHICS_PRIMITIVE_POINTS = 0x1,
  GRAPHICS_PRIMITIVE_LINES = 0x2,
  GRAPHICS_PRIMITIVE_LINE_STRIP = 0x3,
  GRAPHICS_PRIMITIVE_TRIANGLES = 0x4,
  GRAPHICS_PRIMITIVE_TRIANGLE_STRIP = 0x5,
  GRAPHICS_PRIMITIVE_QUADS = 0x6,
  GRAPHICS_PRIMITIVE_QUAD_STRIP = 0x7,
};

enum GraphicsTextureColorType
{
  GRAPHICS_TEXCOLOR_NONE = 0x0,
  GRAPHICS_TEXCOLOR_RGBA = 0x1,
  GRAPHICS_TEXCOLOR_A = 0x2,
  GRAPHICS_TEXCOLOR_L = 0x3,
};

enum GraphicsComparisonType
{
  GRAPHICS_COMPARISON_FALSE = 0x0,
  GRAPHICS_COMPARISON_TRUE = 0x1,
  GRAPHICS_COMPARISON_EQUAL = 0x2,
  GRAPHICS_COMPARISON_NOT_EQUAL = 0x3,
  GRAPHICS_COMPARISON_LESS = 0x4,
  GRAPHICS_COMPARISON_LESS_EQUAL = 0x5,
  GRAPHICS_COMPARISON_GREATER_EQUAL = 0x6,
  GRAPHICS_COMPARISON_GREATER = 0x7,
};

typedef char *ShaderSourceCallback(GraphicsPrimitiveType, int, int, GraphicsTextureColorType, int, int, int, int, int, GraphicsComparisonType);

static void* GetBaseAddress()
{
  return SigScan::GetBaseAddress();
}


struct AchievementTracker;

struct AnimationTracker;

struct LIBZHL_INTERFACE AnimationTracker
{
	AnimationTracker()
	{
	
	}

	virtual ~AnimationTracker() {}
	LIBZHL_API virtual void Update();
	LIBZHL_API float GetAlphaLevel(bool reverse);
	LIBZHL_API float Progress(float speed);
	LIBZHL_API void SetLoop(bool loop, float loopDelay);
	LIBZHL_API void SetProgress(float time);
	LIBZHL_API void Start(float time);
	LIBZHL_API void StartReverse(float time);
	LIBZHL_API void Stop(bool resetTime);
	
	float time;
	bool loop;
	float current_time;
	bool running;
	bool reverse;
	bool done;
	float loopDelay;
	float currentDelay;
};

struct AchievementTracker
{
	LIBZHL_API void CheckShipAchievements(int shipId, bool hidePopups);
	LIBZHL_API bool GetFlag(const std::string &flagName);
	LIBZHL_API std::vector<CAchievement*> GetShipAchievements(const std::string &ship);
	LIBZHL_API int GetShipMarker(const std::string &baseName, const std::string &thisName);
	LIBZHL_API void LoadAchievementDescriptions();
	LIBZHL_API void LoadProfile(int file, int version);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void ResetFlags();
	LIBZHL_API void SaveProfile(int file);
	LIBZHL_API void SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer);
	LIBZHL_API void SetFlag(const std::string &flagName);
	LIBZHL_API void SetSectorEight();
	LIBZHL_API void SetTooltip(CAchievement *ach);
	LIBZHL_API void SetVictoryAchievement();
	LIBZHL_API void UnlockShip(int shipId, int shipType);
	
	std::vector<CAchievement*> recentlyUnlocked;
	std::vector<std::vector<CAchievement*>> shipUnlocks;
	std::vector<CAchievement*> achievements;
	std::map<std::string, int> gameFlags;
	AnimationTracker achievementPopup;
	GL_Primitive *popupBox;
	GL_Primitive *achievementBox[2];
	GL_Primitive *achievementOverlay[2];
	std::string currentShip;
};

struct Algae
{
};

struct AnaerobicAlien
{
};

struct AnaerobicAnimation
{
};

struct Animation;

struct AnimationDescriptor
{
	int numFrames;
	int imageWidth;
	int imageHeight;
	int stripStartY;
	int stripStartX;
	int frameWidth;
	int frameHeight;
};

struct GL_Color
{
	GL_Color(float rr, float gg, float bb, float aa) : r(rr), g(gg), b(bb), a(aa)
	{
		
	}
	
	static GL_Color FromHSV(float fH, float fS, float fV, float fA)
	{
		float fR, fB, fG;
		float fC = fV * fS; // Chroma
		float fHPrime = fmod(fH / 60.0, 6);
		float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
		float fM = fV - fC;
		
		if (0 <= fHPrime && fHPrime < 1) 
		{
			fR = fC;
			fG = fX;
			fB = 0;
		} 
		else if(1 <= fHPrime && fHPrime < 2) 
		{
			fR = fX;
			fG = fC;
			fB = 0;
		} 
		else if(2 <= fHPrime && fHPrime < 3) 
		{
			fR = 0;
			fG = fC;
			fB = fX;
		} 
		else if(3 <= fHPrime && fHPrime < 4) 
		{
			fR = 0;
			fG = fX;
			fB = fC;
		} 
		else if(4 <= fHPrime && fHPrime < 5) 
		{
			fR = fX;
			fG = 0;
			fB = fC;
		} 
		else if(5 <= fHPrime && fHPrime < 6) 
		{
			fR = fC;
			fG = 0;
			fB = fX;
		} 
		else 
		{
			fR = 0;
			fG = 0;
			fB = 0;
		}
		  
		fR += fM;
		fG += fM;
		fB += fM;
		
		return GL_Color(fR, fB, fG, fA);
	}
	
	GL_Color() {}

	float r;
	float g;
	float b;
	float a;
};

struct Pointf
{
	Pointf() : x(0.f), y(0.f) {}
	Pointf(float _x, float _y) : x(_x), y(_y) {}
	
	Pointf operator+(const Pointf& other)
	{
		return Pointf(x + other.x, y + other.y);
	}
	
	Pointf operator-(const Pointf& other)
	{		
		return Pointf(x - other.x, y - other.y);
	}
	
	Pointf operator/(float amount)
	{		
		return Pointf(x / amount, y / amount);
	}
	
	Pointf operator*(float amount)
	{		
		return Pointf(x * amount, y * amount);
	}


	LIBZHL_API Pointf Normalize();
	LIBZHL_API float RelativeDistance(Pointf other);
	LIBZHL_API void constructor(float x, float y);
	
	float x;
	float y;
};

struct Animation
{
	Animation()
	{
	}
	Animation(const std::string& _image, int _length, float _time, Pointf _position, int _imageWidth, int _imageHeight, int _stripStartX, int _numFrames)
	{
		this->constructor(_image, _length, _time, _position, _imageWidth, _imageHeight, _stripStartX, _numFrames);
	}

	LIBZHL_API void AddSoundQueue(int frame, const std::string &sound);
	LIBZHL_API bool Done();
	LIBZHL_API void LoadState(int fd);
	LIBZHL_API void OnRender(float opacity, GL_Color color, bool mirror);
	LIBZHL_API int RandomStart();
	LIBZHL_API void SaveState(int fd);
	LIBZHL_API void SetAnimationId(GL_Texture *tex);
	LIBZHL_API void SetCurrentFrame(int frame);
	LIBZHL_API void SetProgress(float progress);
	LIBZHL_API void Start(bool reset);
	LIBZHL_API void StartReverse(bool reset);
	LIBZHL_API void Update();
	LIBZHL_API void constructor(const std::string &_image, int _length, float _time, Pointf _position, int _imageWidth, int _imageHeight, int _stripStartX, int _numFrames);
	LIBZHL_API void destructor();
	
	GL_Texture *animationStrip;
	AnimationDescriptor info;
	AnimationTracker tracker;
	Pointf position;
	std::string soundForward;
	std::string soundReverse;
	bool randomizeFrames;
	float fScale;
	float fYStretch;
	int currentFrame;
	bool bAlwaysMirror;
	std::vector<std::vector<std::string>> soundQueue;
	float fadeOut;
	float startFadeOut;
	std::string animName;
	int mask_x_pos;
	int mask_x_size;
	int mask_y_pos;
	int mask_y_size;
	GL_Primitive *primitive;
	GL_Primitive *mirroredPrimitive;
};

struct AnimationControl;

struct AnimationSheet
{
	int w;
	int h;
	int frameHeight;
	int frameWidth;
	GL_Texture *imageId;
};

struct WeaponAnimation;

struct WeaponMount
{
	Point position;
	bool mirror;
	bool rotate;
	int slide;
	int gib;
};

struct WeaponAnimation
{
	LIBZHL_API Pointf GetSlide();
	LIBZHL_API void SetFireTime(float time);
	LIBZHL_API bool StartFire();
	LIBZHL_API void Update();
	
	Animation anim;
	bool bFireShot;
	bool bFiring;
	float fChargeLevel;
	int iChargedFrame;
	int iFireFrame;
	bool bMirrored;
	bool bRotation;
	Point fireLocation;
	bool bPowered;
	Point mountPoint;
	Point renderPoint;
	Point fireMountVector;
	AnimationTracker slideTracker;
	int slideDirection;
	CachedImage iChargeImage;
	Animation explosionAnim;
	WeaponMount mount;
	float fDelayChargeTime;
	Animation boostAnim;
	int boostLevel;
	bool bShowCharge;
	float fActualChargeLevel;
	int iChargeOffset;
	int iChargeLevels;
	int currentOffset;
	CachedImage chargeBox;
	CachedImage chargeBar;
	int iHackLevel;
	Animation hackSparks;
	bool playerShip;
};

struct AnimationControl
{
	LIBZHL_API Animation GetAnimation(const std::string &animName);
	
	std::map<std::string, AnimationSheet> animSheets;
	std::map<std::string, Animation> animations;
	std::map<std::string, WeaponAnimation> weapAnimations;
};

struct ArmamentBox;

struct GenericButton;

struct Globals
{
	struct Ellipse
	{
		Point center;
		float a;
		float b;
	};
	
	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};
	
	LIBZHL_API static float __stdcall AimAhead(Pointf delta, Pointf vr, float muzzleV);
	LIBZHL_API static Pointf __stdcall GetNextPoint(Pointf current, float mag_speed, Pointf dest);
	LIBZHL_API static Pointf __stdcall GetNextPoint(Pointf current, float mag_speed, float heading);
	LIBZHL_API static int __stdcall GetNextSpaceId();
	
};

struct TouchTooltip;

struct LIBZHL_INTERFACE ArmamentBox
{
	virtual ~ArmamentBox() {}
	virtual bool Empty() LIBZHL_PLACEHOLDER
	virtual std::string Name() LIBZHL_PLACEHOLDER
	virtual bool Powered() LIBZHL_PLACEHOLDER
	virtual void SetDefaultAutofire(bool val) LIBZHL_PLACEHOLDER
	virtual int RealRequiredPower() LIBZHL_PLACEHOLDER
	virtual int GetBonusPower() LIBZHL_PLACEHOLDER
	virtual std::string GetType() LIBZHL_PLACEHOLDER
	virtual GL_Color StatusColor() LIBZHL_PLACEHOLDER
	virtual std::string GenerateTooltip() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void RenderTouchTooltip(int spaceToTop) LIBZHL_PLACEHOLDER
	virtual void OnRender(bool dragging, bool flashPowerBox) LIBZHL_PLACEHOLDER
	virtual void RenderBox(bool dragging, bool flashPowerBox) LIBZHL_PLACEHOLDER
	virtual void RenderLabels() LIBZHL_PLACEHOLDER
	virtual void RenderIcon(Point &p) LIBZHL_PLACEHOLDER
	std::vector<GL_Primitive*> background;
	GL_Primitive *emptyBackground;
	GL_Primitive *hoverHighlight;
	GL_Primitive *outline;
	GL_Primitive *emptyOutline;
	GL_Primitive *powerBarGlow[4];
	GL_Primitive *iconBackground;
	GL_Primitive *iconInsetBackground;
	GL_Primitive *icon;
	GL_Primitive *iconDoubleSize;
	std::string iconName;
	std::string iconBackgroundName;
	Point lastIconPos;
	Point location;
	int xOffset;
	Point largeIconOffset;
	Point nameOffset;
	int nameWidth;
	bool mouseHover;
	bool touchHover;
	bool touchHighlight;
	bool selected;
	int hotKey;
	int activeTouch;
	TouchTooltip *touchTooltip;
	Animation hackAnimation;
	GL_Primitive *touchButtonBorder;
	Globals::Rect touchButtonBorderRect;
	float touchButtonSlidePos;
	std::vector<GenericButton*> touchButtons;
	Globals::Rect touchButtonHitbox;
	GL_Color iconColor;
	bool droneVariation;
	bool bIoned;
};

struct ArmamentControl;
struct CommandGui;

struct ShipManager;

struct LIBZHL_INTERFACE ArmamentControl
{
	virtual ~ArmamentControl() {}
	virtual void OnLanguageChange() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender(bool front) LIBZHL_PLACEHOLDER
	virtual void RenderTouchTooltips() LIBZHL_PLACEHOLDER
	virtual void RenderLabels() LIBZHL_PLACEHOLDER
	virtual void RenderWarnings() LIBZHL_PLACEHOLDER
	virtual void RenderDragging() LIBZHL_PLACEHOLDER
	virtual bool IsDragging() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual void OnCleanup() LIBZHL_PLACEHOLDER
	virtual void Close() LIBZHL_PLACEHOLDER
	virtual void SetOpen(bool open) LIBZHL_PLACEHOLDER
	virtual bool LButton(int mX, int mY, bool shift) LIBZHL_PLACEHOLDER
	virtual bool LButtonUp(int mX, int mY, bool shift) LIBZHL_PLACEHOLDER
	virtual void RButton(int mX, int mY, bool shift) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int mX, int mY) LIBZHL_PLACEHOLDER
	virtual bool OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool KeyDown(SDLKey key);
	LIBZHL_API virtual void LinkShip(ShipManager *ship);
	virtual ArmamentBox *CreateArmamentBox(Point loc) LIBZHL_PLACEHOLDER
	virtual int NumArmamentSlots() LIBZHL_PLACEHOLDER
	virtual Point ArmamentBoxOrigin() LIBZHL_PLACEHOLDER
	virtual TextString HolderLabel() LIBZHL_PLACEHOLDER
	virtual SDLKey ArmamentHotkey(unsigned int i) LIBZHL_PLACEHOLDER
	virtual void SelectArmament(unsigned int i) LIBZHL_PLACEHOLDER
	virtual void DeselectArmament(unsigned int i) LIBZHL_PLACEHOLDER
	virtual void SwapArmaments(unsigned int a, unsigned int b) LIBZHL_PLACEHOLDER
	LIBZHL_API void CreateHolderTab();
	LIBZHL_API bool Dragging();
	LIBZHL_API void SetPosition(Point loc);
	
	int systemId;
	CommandGui *gui;
	ShipManager *shipManager;
	std::vector<ArmamentBox*> boxes;
	Point location;
	Globals::Rect touchHitBox;
	GL_Texture *holderImage;
	GL_Primitive *holder;
	GL_Primitive *holderTab;
	std::vector<GL_Primitive*> smallBoxHolder;
	std::vector<Animation> smallBoxHackAnim;
	int smallBoxHolderTop;
	bool bOpen;
	Point lastMouse;
	Point currentMouse;
	int draggingBox;
	int draggingTouch;
	bool bDragging;
	int iLastSwapSlot;
	bool bTutorialFlash;
	int iFlashSlot;
	int activeTouch;
};

struct ArtilleryBox;
struct ArtillerySystem;

struct CooldownSystemBox;

struct ShipSystem;

struct SystemBox;

struct TapBoxFrame
{
	Point location;
	bool useWideBox;
	int boxHeight;
	std::vector<int> buttonHeights;
	std::vector<GL_Primitive*> primitives;
	Globals::Rect hitBox;
};

struct WarningMessage;

struct WarningMessage
{
	WarningMessage()
	{
		this->constructor();
	}

	LIBZHL_API void InitImage(const std::string &imageName, Point position, float time, bool flash);
	LIBZHL_API void InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void RenderWithAlpha(float alpha);
	LIBZHL_API void SetImage(const std::string &imageName);
	LIBZHL_API void SetLoop(bool loop);
	LIBZHL_API void SetPosition(Point position);
	LIBZHL_API void SetSound(const std::string &sound);
	LIBZHL_API void SetText(const TextString &text, GL_Color textColor);
	LIBZHL_API void SetText(const TextString &text);
	LIBZHL_API void Start();
	LIBZHL_API void constructor();
	
	void *vptr;
	AnimationTracker tracker;
	Point position;
	bool isImage;
	TextString text;
	bool centerText;
	GL_Color textColor;
	bool useWarningLine;
	CachedImage image;
	std::string imageName;
	bool flash;
	std::string sound;
	AnimationTracker flashTracker;
};

struct LIBZHL_INTERFACE SystemBox
{
	SystemBox() { }
	
	SystemBox(Point pos, ShipSystem *sys, bool playerUI)
	{
		this->constructor(pos, sys, playerUI);
	}

	virtual ~SystemBox() {}
	virtual void destroy() LIBZHL_PLACEHOLDER
	virtual bool HasButton() LIBZHL_PLACEHOLDER
	virtual int GetCooldownBarHeight() LIBZHL_PLACEHOLDER
	virtual int GetHeightModifier() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnRender(bool ignoreStatus);
	virtual bool GetMouseHover() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseMove(int x, int y);
	LIBZHL_API virtual bool MouseClick(bool shift);
	virtual int MouseRightClick(bool unk) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void CancelTouch() LIBZHL_PLACEHOLDER
	virtual void CloseTapBox() LIBZHL_PLACEHOLDER
	virtual void IsTouchTooltipOpen() LIBZHL_PLACEHOLDER
	virtual void IsTouchTooltipActive() LIBZHL_PLACEHOLDER
	virtual void CloseTouchTooltip(bool unk) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void KeyDown(SDLKey key, bool shift);
	LIBZHL_API void constructor(Point pos, ShipSystem *sys, bool playerUI);
	
	Point location;
	GL_Primitive *timerCircle[10];
	GL_Primitive *timerLines;
	GL_Primitive *timerStencil;
	int lastTimerStencilCount;
	GL_Primitive *brokenIcon;
	GL_Primitive *lockIcon;
	GL_Primitive *hackIcon;
	ShipSystem *pSystem;
	bool bShowPower;
	float powerAlpha;
	bool mouseHover;
	int activeTouch;
	Point touchInitialOffset;
	bool tapped;
	bool draggingPower;
	int dragInitialPower;
	float lastDragSpeed;
	int lastDragY;
	double lastDragTime;
	WarningMessage warning;
	int topPower;
	Globals::Rect hitBox;
	int hitBoxTop;
	bool hitBoxTopWasSet;
	GL_Texture *wireImage;
	bool bSimplePower;
	bool bPlayerUI;
	bool useLargeTapIcon;
	Point largeTapIconOffset;
	std::vector<int> tapButtonHeights;
	int tapButtonOffsetY;
	int cooldownOffsetY;
	float keyPressed;
	TouchTooltip *touchTooltip;
	TapBoxFrame tapBoxFrame;
	bool lockedOpen;
};

struct CooldownSystemBox : SystemBox
{
	CooldownSystemBox(Point pos, ShipSystem *sys, bool roundDown)
	{
		this->constructor(pos, sys, roundDown);
	}
	
	CooldownSystemBox() { }

	LIBZHL_API void OnRender(bool ignoreStatus);
	LIBZHL_API void constructor(Point pos, ShipSystem *sys, bool roundDown);
	
	GL_Primitive *box[5];
	GL_Texture *bar[5];
	Point boxPosition;
	bool roundDown;
	GL_Primitive *barPrimitive;
	int lastBarHeight;
	int lastBarTop;
};

struct ArtilleryBox : CooldownSystemBox
{
	ArtilleryBox(Point pos, ArtillerySystem* sys)
	{
		this->constructor(pos, sys);
	}

	LIBZHL_API void OnRender(bool ignoreStatus);
	LIBZHL_API void constructor(Point pos, ArtillerySystem *sys);
	
	ArtillerySystem *artSystem;
	Point buttonOffset;
};

struct ProjectileFactory;

struct CachedRect;

struct CachedRect : CachedPrimitive
{
	LIBZHL_API void SetPosition(int x, int y);
	LIBZHL_API void SetSize(int w, int h);
	
	int x;
	int y;
	int w;
	int h;
};

struct CachedRectOutline : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
	int thickness;
};

struct ShipObject;

struct ShipObject
{
	int HS_HasEquipment(const std::string& equip);
	int HasItem(const std::string& equip);
	int HasCargo(const std::string& equip);
	void CheckCargo(const std::string& equip, int& ret);

	LIBZHL_API bool AddAugmentation(const std::string &augment);
	LIBZHL_API void ClearShipInfo();
	LIBZHL_API int GetAugmentationCount();
	LIBZHL_API std::vector<std::string> GetAugmentationList();
	LIBZHL_API float GetAugmentationValue(const std::string &augment);
	LIBZHL_API int HasAugmentation(const std::string &augment);
	LIBZHL_API int HasEquipment(const std::string &equip);
	LIBZHL_API void RemoveAugmentation(const std::string &augment);
	
	void *vptr;
	int iShipId;
};

struct TimerHelper;

struct TimerHelper
{
	TimerHelper(bool isLoop=false) : loop(isLoop) { }
	
	void Start(float goal); // float overload

	LIBZHL_API bool Done();
	LIBZHL_API void ResetMinMax(int min, int max);
	LIBZHL_API bool Running();
	LIBZHL_API void SetMaxTime(float max);
	LIBZHL_API void Start(int goal);
	LIBZHL_API void Stop();
	LIBZHL_API void Update();
	
	int maxTime;
	int minTime;
	float currTime;
	float currGoal;
	bool loop;
	bool running;
};

struct WeaponBlueprint;

struct LIBZHL_INTERFACE ShipSystem
{
	ShipSystem() { }
	
	ShipSystem(int systemId, int roomId, int shipId, int startingPower)
	{
		this->constructor(systemId, roomId, shipId, startingPower);
	}

	virtual ~ShipSystem() {}
	virtual void SetSelected(int selectedState) LIBZHL_PLACEHOLDER
	virtual int GetSelected() LIBZHL_PLACEHOLDER
	virtual bool CompletelyDestroyed() LIBZHL_PLACEHOLDER
	virtual std::string *GetName() LIBZHL_PLACEHOLDER
	virtual void SetName(std::string &name) LIBZHL_PLACEHOLDER
	virtual void Repair() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool PartialRepair(float speed, bool autoRepair);
	LIBZHL_API virtual bool PartialDamage(float amount);
	virtual bool NeedsRepairing() LIBZHL_PLACEHOLDER
	virtual bool Functioning() LIBZHL_PLACEHOLDER
	virtual bool CanBeSabotaged() LIBZHL_PLACEHOLDER
	virtual float GetDamage() LIBZHL_PLACEHOLDER
	virtual void *GetLocation() LIBZHL_PLACEHOLDER
	virtual void *GetGridLocation() LIBZHL_PLACEHOLDER
	virtual void SetDamage(float damage) LIBZHL_PLACEHOLDER
	virtual void SetMaxDamage(float maxDamage) LIBZHL_PLACEHOLDER
	virtual void SetLocation(Point pos) LIBZHL_PLACEHOLDER
	virtual void OnRenderHighlight() LIBZHL_PLACEHOLDER
	virtual int GetId() LIBZHL_PLACEHOLDER
	virtual bool IsRoomBased() LIBZHL_PLACEHOLDER
	virtual int GetRoomId() LIBZHL_PLACEHOLDER
	virtual bool Ioned() LIBZHL_PLACEHOLDER
	virtual void SetRoomId() LIBZHL_PLACEHOLDER
	virtual void SetHackingLevel(int level) LIBZHL_PLACEHOLDER
	virtual void ForceBatteryPower(int power) LIBZHL_PLACEHOLDER
	virtual void RemoveBatteryPower() LIBZHL_PLACEHOLDER
	virtual WeaponBlueprint *GetWeaponInfo() LIBZHL_PLACEHOLDER
	virtual std::string *GetOverrideTooltip() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void CheckMaxPower();
	LIBZHL_API virtual void SetBonusPower(int amount, int permanentPower);
	LIBZHL_API virtual void AddDamage(int amount);
	LIBZHL_API virtual bool ForceDecreasePower(int powerLoss);
	virtual bool ForceIncreasePower(int power) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void StopHacking();
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual void OnRenderFloor() LIBZHL_PLACEHOLDER
	virtual void OnRenderEffects() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnLoop();
	virtual bool GetNeedsPower() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool Clickable() LIBZHL_PLACEHOLDER
	virtual bool Powered() LIBZHL_PLACEHOLDER
	virtual void ShipDestroyed() LIBZHL_PLACEHOLDER
	LIBZHL_API void AddLock(int lock);
	LIBZHL_API bool BlockedBoosted(bool countLimit);
	LIBZHL_API void CheckForRepower();
	LIBZHL_API void ClearStatus();
	LIBZHL_API bool DamageOverTime(float unk);
	LIBZHL_API bool DecreasePower(bool force);
	LIBZHL_API int GetEffectivePower();
	LIBZHL_API static std::string __stdcall GetLevelDescription(int systemId, int level, bool tooltip);
	LIBZHL_API TimerHelper GetLockTimer();
	LIBZHL_API bool GetLocked();
	LIBZHL_API int GetMaxPower();
	LIBZHL_API int GetPowerCap();
	LIBZHL_API bool IncreasePower(int amount, bool force);
	LIBZHL_API bool Ioned(int num);
	LIBZHL_API int IsMannedBoost();
	LIBZHL_API static bool __stdcall IsSubsystem(int systemType);
	LIBZHL_API void LoadState(int file);
	LIBZHL_API void LockSystem(int lock);
	LIBZHL_API static int __stdcall NameToSystemId(const std::string &name);
	LIBZHL_API int RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash);
	LIBZHL_API static int __stdcall RenderPowerBoxesPlain(int x, int y, int width, int height, int gap, int current, int temp, int max);
	LIBZHL_API void RenderSystemSymbol(bool forPowerUI, int forceColor);
	LIBZHL_API void SaveState(int file);
	LIBZHL_API void SetPowerCap(int cap);
	LIBZHL_API int SetPowerLoss(int power);
	LIBZHL_API static std::string __stdcall SystemIdToName(int systemId);
	LIBZHL_API bool UpgradeSystem(int amount);
	LIBZHL_API void constructor(int systemId, int roomId, int shipId, int startingPower);
	LIBZHL_API void destructor();
	
	int selectedState;
	ShipObject _shipObj;
	float fDamage;
	Point pLoc;
	float fMaxDamage;
	std::string name;
	int roomId;
	int iRepairCount;
	int iSystemType;
	bool bNeedsManned;
	bool bManned;
	uint8_t gap_ex_1[2];
	int iActiveManned;
	bool bBoostable;
	uint8_t gap_ex_2[2];
	std::pair<int, int> powerState;
	int iRequiredPower;
	GL_Texture *imageIcon;
	GL_Primitive *iconPrimitive;
	GL_Primitive *iconBorderPrimitive;
	GL_Primitive *iconPrimitives[20];
	CachedRect partialDamageRect;
	CachedRectOutline lockOutline;
	Globals::Rect roomShape;
	bool bOnFire;
	bool bBreached;
	std::pair<int, int> healthState;
	float fDamageOverTime;
	float fRepairOverTime;
	bool damagedLastFrame;
	bool repairedLastFrame;
	int originalPower;
	bool bNeedsPower;
	int iTempPowerCap;
	int iTempPowerLoss;
	int iTempDividePower;
	int iLockCount;
	TimerHelper lockTimer;
	bool bExploded;
	bool bOccupied;
	bool bFriendlies;
	std::string interiorImageName;
	GL_Primitive *interiorImage;
	GL_Primitive *interiorImageOn;
	GL_Primitive *interiorImageManned;
	GL_Primitive *interiorImageMannedFancy;
	int lastUserPower;
	int iBonusPower;
	int iLastBonusPower;
	Pointf location;
	int bpCost;
	AnimationTracker flashTracker;
	int maxLevel;
	int iBatteryPower;
	int iHackEffect;
	bool bUnderAttack;
	bool bLevelBoostable;
	bool bTriggerIon;
	std::vector<Animation> damagingEffects;
	int computerLevel;
};

struct Targetable;

struct ArtillerySystem : ShipSystem
{
	LIBZHL_API void Jump();
	LIBZHL_API void OnLoop();
	
	ProjectileFactory *projectileFactory;
	Targetable *target;
	bool bCloaked;
};

struct Asteroid;

struct Collideable;

struct CollisionResponse
{
	int collision_type;
	Pointf point;
	int damage;
	int superDamage;
};

struct Damage
{
	inline Damage()
	{
		iDamage = 0;
		iShieldPiercing = 0;
		fireChance = 0;
		breachChance = 0;
		stunChance = 0;
		iIonDamage = 0;
		iSystemDamage = 0;
		iPersDamage = 0;
		bHullBuster = 0;
		ownerId = -1;
		selfId = -1;
		bLockdown = false;
		crystalShard = false;
		bFriendlyFire = true;
		iStun = 0;
	};
	

	int iDamage;
	int iShieldPiercing;
	int fireChance;
	int breachChance;
	int stunChance;
	int iIonDamage;
	int iSystemDamage;
	int iPersDamage;
	bool bHullBuster;
	int ownerId;
	int selfId;
	bool bLockdown;
	bool crystalShard;
	bool bFriendlyFire;
	int iStun;
};

struct LIBZHL_INTERFACE Collideable
{
	virtual ~Collideable() {}
	virtual CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace) LIBZHL_PLACEHOLDER
	virtual bool DamageBeam(Pointf current, Pointf last, Damage damage) LIBZHL_PLACEHOLDER
	virtual bool DamageArea(Pointf location, Damage damage, bool forceHit) LIBZHL_PLACEHOLDER
	virtual bool DamageShield(Pointf location, Damage damage, bool forceHit) LIBZHL_PLACEHOLDER
	virtual bool GetDodged() LIBZHL_PLACEHOLDER
	virtual Pointf GetSuperShield() LIBZHL_PLACEHOLDER
	virtual void SetTempVision(Pointf location) LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual bool ValidTargetLocation(Pointf location) LIBZHL_PLACEHOLDER
};

struct Projectile;

struct ShieldPower
{
	int first;
	int second;
	std::pair<int, int> super;
};

struct LIBZHL_INTERFACE Targetable
{
	virtual ~Targetable() {}
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool unk) LIBZHL_PLACEHOLDER
	virtual std::vector<Pointf> GetAllTargettingPoints() LIBZHL_PLACEHOLDER
	virtual Globals::Ellipse GetShieldShape() LIBZHL_PLACEHOLDER
	virtual ShieldPower GetShieldPower() LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual bool IsCloaked() LIBZHL_PLACEHOLDER
	virtual void DamageTarget(Pointf pos, Damage damage) LIBZHL_PLACEHOLDER
	virtual bool GetIsDying() LIBZHL_PLACEHOLDER
	virtual bool GetIsJumping() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual Globals::Rect GetShape() LIBZHL_PLACEHOLDER
	int type;
	bool hostile;
	bool targeted;
};

struct LIBZHL_INTERFACE Projectile : Collideable
{
	void HS_OnUpdate();
	void HS_CollisionCheck(Collideable *other);

	virtual void SetWeaponAnimation(WeaponAnimation &animation) LIBZHL_PLACEHOLDER
	virtual void OnRenderSpecific(int spaceId) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void CollisionCheck(Collideable *other);
	LIBZHL_API virtual void OnUpdate();
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool valuable) LIBZHL_PLACEHOLDER
	virtual void ComputeHeading() LIBZHL_PLACEHOLDER
	virtual void SetDestinationSpace(int space) LIBZHL_PLACEHOLDER
	virtual void EnterDestinationSpace() LIBZHL_PLACEHOLDER
	virtual bool Dead() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool ValidTarget();
	virtual void Kill() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual void SetDamage(Damage damage) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual int ForceRenderLayer();
	virtual void SetSpin(float spin) LIBZHL_PLACEHOLDER
	virtual void SaveProjectile(int fd) LIBZHL_PLACEHOLDER
	virtual void LoadProjectile(int fd) LIBZHL_PLACEHOLDER
	virtual int GetType() LIBZHL_PLACEHOLDER
	virtual void SetMovingTarget(Targetable *target) LIBZHL_PLACEHOLDER
	LIBZHL_API CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace);
	LIBZHL_API void Initialize(const WeaponBlueprint &bp);
	LIBZHL_API static Pointf __stdcall RandomSidePoint(int side);
	LIBZHL_API void constructor(Pointf position, int ownerId, int targetId, Pointf target);
	LIBZHL_API void destructor();
	
	Targetable _targetable;
	Pointf position;
	Pointf last_position;
	float speed_magnitude;
	Pointf target;
	float heading;
	int ownerId;
	unsigned int selfId;
	Damage damage;
	float lifespan;
	int destinationSpace;
	int currentSpace;
	int targetId;
	bool dead;
	uint8_t gap_ex_1[2];
	Animation death_animation;
	Animation flight_animation;
	Pointf speed;
	bool missed;
	bool hitTarget;
	uint8_t gap_ex_2[2];
	std::string hitSolidSound;
	std::string hitShieldSound;
	std::string missSound;
	float entryAngle;
	bool startedDeath;
	bool passedTarget;
	bool bBroadcastTarget;
	AnimationTracker flashTracker;
	GL_Color color;
};

struct Asteroid : Projectile
{
	Asteroid(Pointf pos, int destinationSpace)
	{
		this->constructor(pos, destinationSpace);
	}

	LIBZHL_API void OnUpdate();
	LIBZHL_API void constructor(Pointf pos, int destinationSpace);
	
	GL_Texture *imageId;
	float angle;
};

struct AsteroidGenerator;

struct AsteroidGenerator
{
	LIBZHL_API Projectile *GetNextAsteroid();
	LIBZHL_API void GetNextState();
	LIBZHL_API float Initialize(int numberOfShips, int shieldCount, bool defense);
	LIBZHL_API void LoadAsteroids(void *file);
	LIBZHL_API void OnLoop();
	LIBZHL_API bool SaveAsteroids(void *file);
	LIBZHL_API void SetNumShips(int ships);
	LIBZHL_API void UpdateState();
	LIBZHL_API void constructor();
	
	std::queue<Projectile*> asteroidQueue;
	RandomAmount spawnRate[3];
	RandomAmount stateLength[3];
	int numberOfShips;
	int iState;
	int currentSpace;
	int iNextDirection;
	float fStateTimer;
	float timer;
	bool bRunning;
	int initShields;
};

struct Blueprint;

struct Description;

struct Description
{
	LIBZHL_API Description &copy_assign_1(const Description &other);
	LIBZHL_API Description &copy_assign_2(Description &other);
	LIBZHL_API void destructor();
	
	TextString title;
	TextString shortTitle;
	TextString description;
	int cost;
	int rarity;
	int baseRarity;
	int bp;
	bool locked;
	TextString tooltip;
	std::string tip;
};

struct LIBZHL_INTERFACE Blueprint
{
	virtual ~Blueprint() {}
	virtual void RenderIcon(float unk) LIBZHL_PLACEHOLDER
	virtual std::string GetNameLong() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual std::string GetNameShort();
	virtual int GetType() LIBZHL_PLACEHOLDER
	LIBZHL_API void destructor();
	
	std::string name;
	Description desc;
	int type;
};

struct AugmentBlueprint : Blueprint
{
	float value;
	bool stacking;
};

struct AugmentEquipBox;

struct DroneSystem;
struct EquipmentBox;

struct AugmentBlueprint;
struct CrewMember;
struct Drone;

struct EquipmentBoxItem
{
	ProjectileFactory *pWeapon;
	Drone *pDrone;
	CrewMember *pCrew;
	const AugmentBlueprint *augment;
};

struct InfoBox;

struct WeaponSystem;

struct LIBZHL_INTERFACE EquipmentBox
{
	bool IsEmpty()
	{
		return !item.pWeapon && !item.pDrone && (!item.augment || item.augment->name.empty()) && !item.pCrew;
	}

	virtual ~EquipmentBox() {}
	LIBZHL_API virtual void SetPosition(Point pos);
	LIBZHL_API virtual void OnRender(bool isEmpty);
	LIBZHL_API virtual void RenderLabels(bool unk);
	virtual void RenderIcon(bool empty) LIBZHL_PLACEHOLDER
	virtual void SetShipManager(ShipManager *ship) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseMove(int x, int y);
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void UpdateBoxImage(bool unk);
	LIBZHL_API virtual void Restart();
	LIBZHL_API virtual void AddItem(EquipmentBoxItem item);
	virtual void RemoveItem() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool CanHoldWeapon();
	LIBZHL_API virtual bool CanHoldDrone();
	virtual char CanHoldAugment() LIBZHL_PLACEHOLDER
	virtual void CheckContents() LIBZHL_PLACEHOLDER
	virtual int GetType(bool unk) LIBZHL_PLACEHOLDER
	virtual char IsCargoBox() LIBZHL_PLACEHOLDER
	virtual char CanHoldCrew() LIBZHL_PLACEHOLDER
	virtual char CanDoJob() LIBZHL_PLACEHOLDER
	LIBZHL_API Blueprint *GetBlueprint();
	LIBZHL_API int GetItemValue();
	LIBZHL_API virtual int GetType();
	LIBZHL_API void SetBlueprint(InfoBox *infoBox, bool detailedBox);
	LIBZHL_API void constructor(Point pos, int slot);
	LIBZHL_API virtual void destructor();
	
	GL_Primitive *blocked_overlay;
	GL_Color overlayColor;
	std::string imageName;
	GL_Primitive *empty;
	GL_Primitive *full;
	GL_Primitive *selected_empty;
	GL_Primitive *selected_full;
	WeaponSystem *weaponSys;
	DroneSystem *droneSys;
	Point location;
	Globals::Rect hitBox;
	EquipmentBoxItem item;
	bool bMouseHovering;
	bool bGlow;
	bool bBlocked;
	int slot;
	bool bLocked;
	int value;
	bool bPermanentLock;
	bool blockDetailed;
};

struct AugmentEquipBox : EquipmentBox
{
	LIBZHL_API void CheckContents();
	LIBZHL_API void RemoveItem();
	LIBZHL_API void RenderIcon();
	
	ShipManager *ship;
};

struct AugmentStoreBox;

struct Button;

struct GL_ColorTexVertex
{
	float x;
	float y;
	float u;
	float v;
	float r;
	float g;
	float b;
	float a;
};

struct GL_Line
{
	GL_Line(float x1, float y1, float x2, float y2)
	{
		start = Pointf(x1, y1);
		end = Pointf(x2, y2);
	}
	
	GL_Line(Pointf _start, Pointf _end) : start(_start), end(_end)
	{
	}		

	Pointf start;
	Pointf end;
};

struct GL_TexVertex
{
	float x;
	float y;
	float u;
	float v;
};

struct CSurface
{
	/*
	static void GL_ApplyShader(int pipeline)
	{
		shader_pipeline_apply(pipeline);
	}
	
	static void GL_DestroyShader(int pipeline)
	{
		shader_pipeline_destroy(pipeline);
	}
	
	static int GL_CreateShaderPipeline(int vertex_shader, int fragment_shader)
	{
		return shader_pipeline_create(vertex_shader, fragment_shader);
	}
	
	static int GL_CreateShader(ShaderType type, const char* source)
	{
		return shader_create_from_source(type, source, -1);
	}
	*/
	

	LIBZHL_API static void __stdcall AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2);
	LIBZHL_API static void __stdcall FinishFrame();
	LIBZHL_API static bool __stdcall GL_BlitImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror);
	LIBZHL_API static bool __stdcall GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror);
	LIBZHL_API static void __stdcall GL_BlitMultiColorImage(GL_Texture *tex, const std::vector<GL_ColorTexVertex> &texVertices, bool antialias);
	LIBZHL_API static void __stdcall GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias);
	LIBZHL_API static bool __stdcall GL_BlitPixelImage(GL_Texture *tex, float x, float y, float x2, float y2, float rotation, GL_Color color, bool mirror);
	LIBZHL_API static bool __stdcall GL_BlitPixelImageWide(GL_Texture *tex, float x, float y, int x2, int y2, float opacity, GL_Color color, bool mirror);
	LIBZHL_API static void __stdcall GL_ClearAll();
	LIBZHL_API static void __stdcall GL_ClearColor();
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiLinePrimitive(std::vector<GL_Line> &vec, GL_Color color, float thickness);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiRectPrimitive(std::vector<Globals::Rect> &vec, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreatePiePartialPrimitive(int x, int y, float radius, float deg1, float deg2, float thickness, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreatePixelImagePrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool unk);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color);
	LIBZHL_API static void __stdcall GL_DestroyPrimitive(GL_Primitive *primitive);
	LIBZHL_API static bool __stdcall GL_DisableBlend();
	LIBZHL_API static bool __stdcall GL_DrawCircle(int x, int y, float radius, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawLine(float x1, float y1, float x2, float y2, float lineWidth, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth);
	LIBZHL_API static bool __stdcall GL_DrawShield(int x, int y, float a1, float b1, int angle1, int angle2, GL_Color color, float thickness);
	LIBZHL_API static bool __stdcall GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color);
	LIBZHL_API static bool __stdcall GL_EnableBlend();
	LIBZHL_API static void __stdcall GL_ForceAntialias(bool on);
	LIBZHL_API static GL_Color __stdcall GL_GetColor();
	LIBZHL_API static int __stdcall GL_LoadIdentity();
	LIBZHL_API static int __stdcall GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6);
	LIBZHL_API static int __stdcall GL_PopMatrix();
	LIBZHL_API static void __stdcall GL_PopScissor();
	LIBZHL_API static void __stdcall GL_PopStencilMode();
	LIBZHL_API static int __stdcall GL_PushMatrix();
	LIBZHL_API static void __stdcall GL_PushStencilMode();
	LIBZHL_API static void __stdcall GL_RemoveColorTint();
	LIBZHL_API static void __stdcall GL_RenderPrimitive(GL_Primitive *primitive);
	LIBZHL_API static void __stdcall GL_RenderPrimitiveWithAlpha(GL_Primitive *primitive, float alpha);
	LIBZHL_API static void __stdcall GL_RenderPrimitiveWithColor(GL_Primitive *primitive, GL_Color color);
	LIBZHL_API static void __stdcall GL_Rotate(float angle, float x, float y, float z = 1.f);
	LIBZHL_API static void __stdcall GL_Rotate2(float angle, float x, float y, float z = 1.f);
	LIBZHL_API static void __stdcall GL_Scale(float x, float y, float z);
	LIBZHL_API static int __stdcall GL_SetColor(GL_Color color);
	LIBZHL_API static void __stdcall GL_SetColorTint(GL_Color color);
	LIBZHL_API static void __stdcall GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask);
	LIBZHL_API static bool __stdcall GL_Translate(float x, float y, float z = 0.f);
	LIBZHL_API static GL_Color __stdcall GetColorTint();
	LIBZHL_API static bool __stdcall IsFrameBufferSupported();
	LIBZHL_API static int __stdcall SetViewPort(int left, int bottom, int h, int w);
	LIBZHL_API static void __stdcall StartFrame();
	
};

struct LIBZHL_INTERFACE GenericButton
{
	virtual ~GenericButton() {}
	virtual void Reset() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetLocation(Point pos);
	virtual void SetHitBox(Globals::Rect rect) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetActive(bool active);
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseMove(int x, int y, bool silent);
	LIBZHL_API virtual void OnClick();
	LIBZHL_API virtual void OnRightClick();
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void ResetPrimitives();
	
	Point position;
	Globals::Rect hitbox;
	bool allowAnyTouch;
	bool touchSelectable;
	bool bRenderOff;
	bool bRenderSelected;
	bool bFlashing;
	AnimationTracker flashing;
	bool bActive;
	bool bHover;
	bool bActivated;
	bool bSelected;
	int activeTouch;
};

struct Button : GenericButton
{
	Button()
	{
		this->constructor();
	}
	
	~Button()
	{
		CSurface::GL_DestroyPrimitive(primitives[0]);
		CSurface::GL_DestroyPrimitive(primitives[1]);
		CSurface::GL_DestroyPrimitive(primitives[2]);
	}

	LIBZHL_API void OnInit(const std::string &img, Point pos);
	LIBZHL_API void OnRender();
	LIBZHL_API void SetActiveImage(GL_Texture *texture);
	LIBZHL_API void SetImageBase(const std::string &imageBase);
	LIBZHL_API void SetInactiveImage(GL_Texture *texture);
	LIBZHL_API void SetLocation(const Point pos);
	LIBZHL_API void constructor();
	
	GL_Texture *images[3];
	GL_Primitive *primitives[3];
	Point imageSize;
	bool bMirror;
};

struct Equipment;

struct StoreBox;

struct LIBZHL_INTERFACE StoreBox
{
	StoreBox()
	{
	}
	
	StoreBox(const std::string& buttonImage, ShipManager *shopper, Equipment *ship)
	{
		this->constructor(buttonImage, shopper, ship);
	}
	
	void SetPosition(int x, int y)
	{
		SetPosition(Point(x, y));
	}

	virtual ~StoreBox() {}
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual void OnRender();
	virtual void MouseMove(int, int) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseClick(int x, int y);
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void Activate();
	LIBZHL_API virtual void Purchase();
	virtual int SetInfoBox(InfoBox&, int) LIBZHL_PLACEHOLDER
	virtual bool CanHold() LIBZHL_PLACEHOLDER
	virtual bool RequiresConfirm() LIBZHL_PLACEHOLDER
	virtual void Confirm(bool) LIBZHL_PLACEHOLDER
	virtual TextString GetConfirmText() LIBZHL_PLACEHOLDER
	virtual int GetExtraData() LIBZHL_PLACEHOLDER
	virtual void SetExtraData(int) LIBZHL_PLACEHOLDER
	LIBZHL_API void InitBlueprint(Blueprint *bp);
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void constructor(const std::string &buttonImage, ShipManager *shopper, Equipment *equip);
	
	int itemId;
	int itemBox;
	std::string buttonImage;
	Button button;
	GL_Primitive *symbol;
	Description desc;
	int count;
	int cost_position;
	ShipManager *shopper;
	Equipment *equipScreen;
	Blueprint *pBlueprint;
	bool bEquipmentBox;
	float fIconScale;
	Point pushIcon;
};

struct AugmentStoreBox : StoreBox
{
	AugmentStoreBox(ShipManager *_ship, const AugmentBlueprint* _bp)
	{
		this->constructor(_ship, _bp);
	}
	
	AugmentStoreBox()
	{
		StoreBox::constructor("storeUI/store_weapons", nullptr, nullptr);
	}

	LIBZHL_API void constructor(ShipManager *ship, const AugmentBlueprint *bp);
	
	AugmentBlueprint *blueprint;
};

struct BatteryBox;
struct BatterySystem;

struct BatteryBox : CooldownSystemBox
{
	BatteryBox(Point pos, BatterySystem* sys)
	{
		this->constructor(pos, sys);
	}

	LIBZHL_API void constructor(Point pos, BatterySystem *sys);
	
	BatterySystem *batterySystem;
	Button batteryButton;
	Point buttonOffset;
};

struct BatterySystem : ShipSystem
{
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
};

struct CrewAnimation;
struct CrewDrone;

struct BoardingGoal
{
	float fHealthLimit;
	int causedDamage;
	int targetsDestroyed;
	int target;
	int damageType;
};

struct CrewLaser : Projectile
{
	CrewLaser(const CrewLaser&) = delete; // doesn't work, make compiler fail if we try

	int r;
	int g;
	int b;
};

struct Particle
{
	float position_x;
	float position_y;
	float speed_x;
	float speed_y;
	float acceleration_x;
	float acceleration_y;
	float lifespan;
	bool alive;
};

struct ParticleEmitter
{
	Particle particles[64];
	float birthRate;
	float birthCounter;
	float lifespan;
	float speedMag;
	float position_x;
	float position_y;
	float max_dx;
	float min_dx;
	float max_dy;
	float min_dy;
	int image_x;
	int image_y;
	GL_Primitive *primitive;
	float emitAngle;
	bool randAngle;
	bool running;
	float maxAlpha;
	float minSize;
	float maxSize;
	int currentCount;
};

struct LIBZHL_INTERFACE CrewAnimation
{
	CrewAnimation()
	{
	}

	CrewAnimation(int _shipId, const std::string& _race, Pointf _unk, char _hostile)
	{
		this->constructor(_shipId, _race, _unk, _hostile);
	}

	bool _HS_CustomDeath();


	virtual ~CrewAnimation() {}
	LIBZHL_API virtual void OnRender(float scale, int selectedState, bool outlineOnly);
	LIBZHL_API virtual void OnRenderProps();
	LIBZHL_API virtual void OnUpdateEffects();
	virtual void UpdateFiring() LIBZHL_PLACEHOLDER
	virtual void UpdateShooting() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool FireShot();
	LIBZHL_API virtual int GetFiringFrame();
	LIBZHL_API virtual std::string GetShootingSound();
	LIBZHL_API virtual std::string GetDeathSound();
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool CustomDeath() LIBZHL_PLACEHOLDER
	LIBZHL_API void OnInit(const std::string &name, Pointf position, bool enemy);
	LIBZHL_API void OnUpdate(Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire);
	LIBZHL_API void RenderIcon(bool border);
	LIBZHL_API void SetupStrips();
	LIBZHL_API void constructor(int shipId, const std::string &race, Pointf unk, bool hostile);
	LIBZHL_API void destructor();
	
	int iShipId;
	std::vector<std::vector<Animation>> anims;
	GL_Texture *baseStrip;
	GL_Texture *colorStrip;
	std::vector<GL_Texture*> layerStrips;
	Pointf lastPosition;
	int direction;
	int sub_direction;
	int status;
	int moveDirection;
	ParticleEmitter smokeEmitter;
	bool bSharedSpot;
	uint8_t gap_ex_1[2];
	std::vector<CrewLaser> shots;
	TimerHelper shootTimer;
	TimerHelper punchTimer;
	Pointf target;
	float fDamageDone;
	bool bPlayer;
	bool bFrozen;
	bool bDrone;
	bool bGhost;
	bool bExactShooting;
	Animation projectile;
	bool bTyping;
	std::string race;
	int currentShip;
	bool bMale;
	bool colorblind;
	uint8_t gap_ex_2[2];
	std::vector<GL_Color> layerColors;
	int forcedAnimation;
	int forcedDirection;
	GL_Color projectileColor;
	bool bStunned;
	bool bDoorTarget;
	bool uniqueBool1;
	bool uniqueBool2;
};

struct CrewBlueprint;

struct CrewBlueprint : Blueprint
{

	LIBZHL_API GL_Color GetCurrentSkillColor(int skill);
	LIBZHL_API std::string GetNameShort();
	LIBZHL_API void RandomSkills(int worldLevel);
	LIBZHL_API void RenderIcon(float opacity);
	LIBZHL_API void RenderSkill(int x, int y, int length, int height, int skill);
	LIBZHL_API void destructor();
	
	TextString crewName;
	TextString crewNameLong;
	std::vector<TextString> powers;
	bool male;
	std::vector<std_pair_int_int> skillLevel;
	std::vector<std::vector<GL_Color>> colorLayers;
	std::vector<int> colorChoices;
};

struct CrewTarget;

struct CrewTask
{
	int taskId;
	int room;
	int system;
};

struct Door;

struct Path
{
	Point start;
	std::vector<Door*> doors;
	Point finish;
	float distance;
};

struct Repairable;

struct SCrewStats
{
	std::vector<int> stat;
	std::string species;
	std::string name;
	bool male;
};

struct Ship;

struct Slot
{
	int roomId;
	int slotId;
	Point worldLocation;
};

struct LIBZHL_INTERFACE CrewMember
{
	CrewMember()
	{

	}

	CrewMember(CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation)
	{

		this->constructor(bp, shipId, enemy, animation);
	}
	
	ShipObject* GetShipObject()
	{
		return (ShipObject*)(this);
	}

	int GetPowerOwner();

	bool _HS_ValidTarget(int shipId);
	bool _HS_GetControllable();
	bool _HS_CanSuffocate();
	bool _HS_CanFight();
	bool _HS_CanRepair();
	bool _HS_CanSabotage();
	bool _HS_CanMan();
    bool _HS_CanTeleport();
	bool _HS_CanBurn();
	int _HS_GetMaxHealth();
	float _HS_GetMoveSpeedMultiplier();
	float _HS_GetRepairSpeed();
	float _HS_GetDamageMultiplier();
	bool _HS_ProvidesPower();
	float _HS_FireRepairMultiplier();
	bool _HS_IsTelepathic();
	float _HS_GetSuffocationModifier();
	bool _HS_IsAnaerobic();
	bool _HS_HasSpecialPower();
	std::pair<float, float> _HS_GetPowerCooldown();
	bool _HS_PowerReady();
	void _HS_ResetPower();
	void _HS_ActivatePower();


	virtual ~CrewMember() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual float PositionShift();
	LIBZHL_API virtual bool InsideRoom(int roomId);
	LIBZHL_API virtual bool ApplyDamage(float damage);
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void Jump();
	LIBZHL_API virtual bool GetIntruder();
	LIBZHL_API virtual void SaveState(int fileHelper);
	LIBZHL_API virtual void LoadState(int fileHelper);
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual void OnRender(bool outlineOnly);
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetOutOfGame();
	LIBZHL_API virtual bool Functional();
	LIBZHL_API virtual bool CountForVictory();
	LIBZHL_API virtual bool GetControllable();
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual bool CanRepair();
	LIBZHL_API virtual bool CanSabotage();
	LIBZHL_API virtual bool CanMan();
	LIBZHL_API virtual bool CanTeleport();
	LIBZHL_API virtual bool CanHeal();
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	virtual bool ShipDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual std::string GetUniqueRepairing();
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string GetSpecies() LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual Damage GetRoomDamage();
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void UpdateRepair();
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	LIBZHL_API bool AtFinalGoal();
	LIBZHL_API bool AtGoal();
	LIBZHL_API bool BadAtCombat();
	LIBZHL_API void CheckFighting();
	LIBZHL_API void CheckForTeleport();
	LIBZHL_API bool CheckRoomPath(int roomId);
	LIBZHL_API void CheckSkills();
	LIBZHL_API void Cleanup();
	LIBZHL_API void ClearPath();
	LIBZHL_API void ClearPosition();
	LIBZHL_API void ClearTask();
	LIBZHL_API void Clone();
	LIBZHL_API void CloseDoorBehind(Door *door);
	LIBZHL_API bool ContainsPoint(int x, int y);
	LIBZHL_API void CycleColorLayer(int unk);
	LIBZHL_API bool DirectModifyHealth(float health);
	LIBZHL_API void EmptySlot();
	LIBZHL_API Slot FindSlot(int unk1, int roomId, bool unk2);
	LIBZHL_API void ForceMindControl(bool force);
	LIBZHL_API Point GetFinalGoal();
	LIBZHL_API int GetIntegerHealth();
	LIBZHL_API Point GetLocation();
	LIBZHL_API std::string GetLongName();
	LIBZHL_API float GetMoveSpeed();
	LIBZHL_API std::string GetName();
	LIBZHL_API bool GetNewGoal();
	LIBZHL_API Point GetNextGoal();
	LIBZHL_API int GetRepairingId();
	LIBZHL_API bool GetResisted();
	LIBZHL_API Slot GetSavedPosition();
	LIBZHL_API static int __stdcall GetSkillFromSystem(int systemId);
	LIBZHL_API int GetSkillLevel(int skillId);
	LIBZHL_API float GetSkillModifier(int skillId);
	LIBZHL_API std::pair<int, int> GetSkillProgress(int skillId);
	LIBZHL_API static std::string __stdcall GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen);
	LIBZHL_API std::string GetTooltip();
	LIBZHL_API void IncreaseSkill(int skillId);
	LIBZHL_API void InitializeSkills();
	LIBZHL_API bool IsBusy();
	LIBZHL_API bool IsManningArtillery();
	LIBZHL_API void Kill(bool noClone);
	LIBZHL_API void MasterSkill(int skillId);
	LIBZHL_API void ModifyHealth(float health);
	LIBZHL_API bool MoveToRoom(int roomId, int slotId, bool forceMove);
	LIBZHL_API bool NeedFrozenLocation();
	LIBZHL_API bool NeedsSlot();
	LIBZHL_API bool OnInit();
	LIBZHL_API void OnRenderHealth();
	LIBZHL_API void OnRenderPath();
	LIBZHL_API void RenderSkillUpAnimation(Point pos);
	LIBZHL_API bool Repairing();
	LIBZHL_API bool RepairingFire();
	LIBZHL_API bool RepairingSystem();
	LIBZHL_API void Restart();
	LIBZHL_API bool RestorePosition();
	LIBZHL_API bool Sabotaging();
	LIBZHL_API void SavePosition();
	LIBZHL_API Pointf SelectSabotageTarget();
	LIBZHL_API void SetCloneReady(bool cloneReady);
	LIBZHL_API void SetCurrentShip(int shipId);
	LIBZHL_API void SetCurrentSystem(ShipSystem *sys);
	LIBZHL_API void SetCurrentTarget(CrewTarget *target, bool unk);
	LIBZHL_API void SetDamageBoost(float damageBoost);
	LIBZHL_API void SetDeathNumber(int deathNum);
	LIBZHL_API void SetFrozen(bool frozen);
	LIBZHL_API void SetFrozenLocation(bool frozenLocation);
	LIBZHL_API void SetHealthBoost(int healthBoost);
	LIBZHL_API void SetMedbay(float health);
	LIBZHL_API void SetMindControl(bool controlled);
	LIBZHL_API void SetName(TextString *name, bool force);
	LIBZHL_API bool SetPath(Path *path);
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void SetResisted(bool resisted);
	LIBZHL_API void SetRoom(int roomId);
	LIBZHL_API void SetRoomPath(int slotId, int roomId);
	LIBZHL_API void SetSavePosition(Slot position);
	LIBZHL_API void SetSex(bool male);
	LIBZHL_API void SetSkillProgress(int skillId, int skillLevel);
	LIBZHL_API void SetTask(CrewTask task);
	LIBZHL_API void StartRepair(Repairable *toRepair);
	LIBZHL_API void StartTeleport();
	LIBZHL_API void StartTeleportArrive();
	LIBZHL_API void StopRepairing();
	LIBZHL_API void UpdateHealth();
	LIBZHL_API void UpdateMovement();
	LIBZHL_API bool WithinRect(int x, int y, int w, int h);
	LIBZHL_API void constructor(CrewBlueprint &blueprint, int shipId, bool intruder, CrewAnimation *animation);
	LIBZHL_API void destructor();
	
	int iShipId;
	float x;
	float y;
	float size;
	float scale;
	float goal_x;
	float goal_y;
	int width;
	int height;
	std::pair<float, float> health;
	float speed_x;
	float speed_y;
	Path path;
	bool new_path;
	float x_destination;
	float y_destination;
	Door *last_door;
	Repairable *currentRepair;
	bool bSuffocating;
	int moveGoal;
	int selectionState;
	int iRoomId;
	int iManningId;
	int iRepairId;
	int iStackId;
	Slot currentSlot;
	bool intruder;
	bool bFighting;
	bool bSharedSpot;
	CrewAnimation *crewAnim;
	GL_Texture *selectionImage;
	CachedImage healthBox;
	CachedImage healthBoxRed;
	CachedRect healthBar;
	float fMedbay;
	float lastDamageTimer;
	float lastHealthChange;
	int currentShipId;
	AnimationTracker flashHealthTracker;
	Pointf currentTarget;
	CrewTarget *crewTarget;
	BoardingGoal boardingGoal;
	bool bFrozen;
	bool bFrozenLocation;
	CrewTask task;
	std::string type;
	Ship *ship;
	Slot finalGoal;
	Door *blockingDoor;
	bool bOutOfGame;
	std::string species;
	bool bDead;
	uint8_t gap_ex_1[2];
	int iOnFire;
	bool bActiveManning;
	ShipSystem *currentSystem;
	int usingSkill;
	CrewBlueprint blueprint;
	Animation healing;
	Animation stunned;
	AnimationTracker levelUp;
	int lastLevelUp;
	SCrewStats stats;
	std::vector<std::vector<bool>> skillsEarned;
	bool clone_ready;
	bool bMindControlled;
	int iDeathNumber;
	Animation mindControlled;
	Animation stunIcon;
	std::vector<std::vector<AnimationTracker>> skillUp;
	int healthBoost;
	float fMindDamageBoost;
	float fCloneDying;
	bool bResisted;
	uint8_t gap_ex_2[2];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
};

struct DroneBlueprint;

struct Slot;

struct LIBZHL_INTERFACE Drone
{
	virtual ~Drone() {}
	virtual void OnInit() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnDestroy() LIBZHL_PLACEHOLDER
	virtual void SetPowered(bool _powered) LIBZHL_PLACEHOLDER
	virtual void SetInstantPowered() LIBZHL_PLACEHOLDER
	virtual bool GetPowered() LIBZHL_PLACEHOLDER
	virtual void SetCurrentShip(int shipId) LIBZHL_PLACEHOLDER
	virtual void SetDeployed(bool _deployed) LIBZHL_PLACEHOLDER
	virtual void SetDestroyed(bool dead, bool setTimer) LIBZHL_PLACEHOLDER
	virtual void SetHacked(int level) LIBZHL_PLACEHOLDER
	virtual bool GetDeployed() LIBZHL_PLACEHOLDER
	virtual bool NeedsRoom() LIBZHL_PLACEHOLDER
	virtual void SetSlot(int room, int slot) LIBZHL_PLACEHOLDER
	virtual bool Destroyed() LIBZHL_PLACEHOLDER
	virtual Point GetWorldLocation() LIBZHL_PLACEHOLDER
	virtual void SetWorldLocation(Point point) LIBZHL_PLACEHOLDER
	virtual Slot *GetDroneSlot(Drone *drone) LIBZHL_PLACEHOLDER
	virtual int GetDroneHealth() LIBZHL_PLACEHOLDER
	virtual int GetRequiredPower() LIBZHL_PLACEHOLDER
	virtual void RenderIcon() LIBZHL_PLACEHOLDER
	virtual std::string *GetName(Drone *drone) LIBZHL_PLACEHOLDER
	virtual bool CanBeDeployed() LIBZHL_PLACEHOLDER
	virtual bool RecallOnJump() LIBZHL_PLACEHOLDER
	virtual bool CanBeRecovered() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fh) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fh) LIBZHL_PLACEHOLDER
	virtual void BlowUp(bool silent) LIBZHL_PLACEHOLDER
	virtual bool GetStunned() LIBZHL_PLACEHOLDER
	int iShipId;
	int selfId;
	bool powered;
	int powerRequired;
	bool deployed;
	int type;
	const DroneBlueprint *blueprint;
	bool bDead;
	int iBonusPower;
	bool poweredAtLocation;
	float destroyedTimer;
	int iHackLevel;
	float hackTime;
};

struct DroneBlueprint : Blueprint
{
	LIBZHL_API void RenderIcon(float scale);
	
	std::string typeName;
	int level;
	int targetType;
	int power;
	float cooldown;
	int speed;
	int dodge;
	std::string weaponBlueprint;
	std::string droneImage;
	std::string combatIcon;
};

struct CrewDrone : CrewMember
{
	virtual ~CrewDrone()
	{
		this->destructor();
	}

	CrewDrone()
	{
	}

	CrewDrone(const std::string& type, const std::string& name, int shipId, const DroneBlueprint* blueprint, CrewAnimation *anim)
	{
		this->constructor(type, name, shipId, blueprint, anim);
	}

	inline std::string& GetRace();

	bool _HS_ValidTarget(int shipId);
	bool _HS_GetControllable();
	bool _HS_CanFight();
	bool _HS_CanRepair();
	bool _HS_CanSabotage();
	bool _HS_CanMan();
	bool _HS_CanSuffocate();
	bool _HS_CanBurn();
	float _HS_GetMoveSpeedMultiplier();
	float _HS_GetRepairSpeed();
	int _HS_GetMaxHealth();
	float _HS_GetDamageMultiplier();
	bool _HS_ProvidesPower();
	float _HS_GetFireRepairMultiplier();
	bool _HS_IsTelepathic();
	float _HS_GetSuffocationModifier();
	bool _HS_IsAnaerobic();
	int _HS_BlockRoom();


	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual bool ProvidesVision();
	LIBZHL_API void SetCurrentShip(int shipId);
	LIBZHL_API void constructor(const std::string &type, const std::string &name, int shipId, const DroneBlueprint *blueprint, CrewAnimation *anim);
	LIBZHL_API void destructor();
	
	Drone _drone;
	int droneRoom;
	Animation powerUp;
	Animation powerDown;
	GL_Texture *lightLayer;
	GL_Texture *baseLayer;
};

struct BattleDrone : CrewDrone
{
};

struct BeamWeapon;

struct BeamWeapon : Projectile
{
	BeamWeapon(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float _heading = 0.0f)
	{
		this->constructor(_position, _ownerId, _targetId, _target, _target2, _length, _targetable, _heading);
	}

	LIBZHL_API void CollisionCheck(Collideable *other);
	LIBZHL_API void OnRenderSpecific(int spaceId);
	LIBZHL_API void OnUpdate();
	LIBZHL_API void constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading);
	
	Pointf sub_end;
	Pointf sub_start;
	Pointf shield_end;
	Pointf final_end;
	Pointf target2;
	Pointf target1;
	float lifespan;
	float length;
	float dh;
	CollisionResponse last_collision;
	int soundChannel;
	std::vector<Animation> contactAnimations;
	float animationTimer;
	int lastDamage;
	Targetable *movingTarget;
	float start_heading;
	float timer;
	WeaponAnimation *weapAnimation;
	bool piercedShield;
	bool oneSpace;
	bool bDamageSuperShield;
	int movingTargetId;
	bool checkedCollision;
	std::vector<Animation> smokeAnims;
	Pointf lastSmokeAnim;
};

struct BlueprintManager;

struct EffectsBlueprint
{
	EffectsBlueprint& operator=(const EffectsBlueprint& other)
	{
		launchSounds = other.launchSounds;
		hitShipSounds = other.hitShipSounds;
		hitShieldSounds = other.hitShieldSounds;
		missSounds = other.missSounds;
		image = other.image;
		return *this;
	}

	std::vector<std::string> launchSounds;
	std::vector<std::string> hitShipSounds;
	std::vector<std::string> hitShieldSounds;
	std::vector<std::string> missSounds;
	std::string image;
};

struct ItemBlueprint : Blueprint
{
};

struct ShipBlueprint;

struct ShipBlueprint : Blueprint
{


	struct SystemTemplate
	{
		int systemId;
		int powerLevel;
		std::vector<int> location;
		int bp;
		int maxPower;
		std::string image;
		int slot;
		int direction;
		std::vector<std::string> weapon;
	};
	
	LIBZHL_API void destructor();
	
	Description desc;
	std::string blueprintName;
	TextString name;
	TextString shipClass;
	std::string layoutFile;
	std::string imgFile;
	std::string cloakFile;
	std::string shieldFile;
	std::string floorFile;
	std::map<int, SystemTemplate> systemInfo;
	std::vector<int> systems;
	int droneCount;
	int originalDroneCount;
	int droneSlots;
	std::string loadDrones;
	std::vector<std::string> drones;
	std::vector<std::string> augments;
	int weaponCount;
	int originalWeaponCount;
	int weaponSlots;
	std::string loadWeapons;
	std::vector<std::string> weapons;
	int missiles;
	int drone_count;
	int health;
	int originalCrewCount;
	std::vector<std::string> defaultCrew;
	std::vector<CrewBlueprint> customCrew;
	int maxPower;
	int boardingAI;
	int bp_count;
	int maxCrew;
	int maxSector;
	int minSector;
	TextString unlock;
};

struct SystemBlueprint : Blueprint
{
	int maxPower;
	int startPower;
	std::vector<int> upgradeCosts;
};

struct WeaponBlueprint : Blueprint
{
	WeaponBlueprint()
	{
		this->constructor();
	}

	struct BoostPower
	{
		int type;
		float amount;
		int count;
	};
	
	struct MiniProjectile
	{
		std::string image;
		bool fake;
	};
	
	LIBZHL_API std::string GetDescription(bool tooltip);
	LIBZHL_API void RenderIcon(float scale);
	LIBZHL_API void constructor();
	LIBZHL_API void destructor();
	
	std::string typeName;
	Damage damage;
	int shots;
	int missiles;
	float cooldown;
	int power;
	int length;
	float speed;
	int miniCount;
	EffectsBlueprint effects;
	std::string weaponArt;
	std::string combatIcon;
	std::string explosion;
	int radius;
	std::vector<MiniProjectile> miniProjectiles;
	BoostPower boostPower;
	int drone_targetable;
	int spin;
	int chargeLevels;
	TextString flavorType;
	GL_Color color;
};

struct BlueprintManager
{

	LIBZHL_API AugmentBlueprint *GetAugmentBlueprint(const std::string &name);
	LIBZHL_API float GetAugmentValue(const std::string &name);
	LIBZHL_API std::vector<std::string> GetBlueprintList(const std::string &name);
	LIBZHL_API CrewBlueprint GetCrewBlueprint(const std::string &name);
	LIBZHL_API std::string GetCrewName(bool *isMale_ret);
	LIBZHL_API DroneBlueprint *GetDroneBlueprint(const std::string &name);
	LIBZHL_API ItemBlueprint *GetItemBlueprint(const std::string &name);
	LIBZHL_API std::vector<AugmentBlueprint*> GetRandomAugment(int count, bool demo_lock);
	LIBZHL_API std::vector<DroneBlueprint*> GetRandomDrone(int count, bool demo_lock);
	LIBZHL_API std::vector<WeaponBlueprint*> GetRandomWeapon(int count, bool demo_lock);
	LIBZHL_API ShipBlueprint *GetShipBlueprint(const std::string &name, int sector);
	LIBZHL_API static GL_Texture *__stdcall GetSkillIcon(int skill, bool outline);
	LIBZHL_API SystemBlueprint *GetSystemBlueprint(const std::string &name);
	LIBZHL_API std::string GetUnusedCrewName(bool *isMale_ret);
	LIBZHL_API WeaponBlueprint *GetWeaponBlueprint(const std::string &name);
	LIBZHL_API Description ProcessDescription(rapidxml::xml_node<char> *node);
	LIBZHL_API DroneBlueprint ProcessDroneBlueprint(rapidxml::xml_node<char> *node);
	LIBZHL_API EffectsBlueprint ProcessEffectsBlueprint(rapidxml::xml_node<char> *node);
	LIBZHL_API ShipBlueprint ProcessShipBlueprint(rapidxml::xml_node<char> *node);
	LIBZHL_API WeaponBlueprint ProcessWeaponBlueprint(rapidxml::xml_node<char> *node);
	
	int rarityTotal;
	std::map<std::string, ShipBlueprint> shipBlueprints;
	std::map<std::string, WeaponBlueprint> weaponBlueprints;
	std::map<std::string, DroneBlueprint> droneBlueprints;
	std::map<std::string, AugmentBlueprint> augmentBlueprints;
	std::map<std::string, CrewBlueprint> crewBlueprints;
	std::map<std::string, bool> nameList;
	std::map<std::string, std::string> shortNames;
	std::map<std::string, std_map_std_string_bool> languageNameLists;
	std::map<std::string, ItemBlueprint> itemBlueprints;
	std::map<std::string, SystemBlueprint> systemBlueprints;
	std::map<std::string, std::vector<std::string>> blueprintLists;
	std::vector<std::string> currentNames;
};

struct BoarderDrone : CrewDrone
{
	BoarderDrone() 
	{
	}

	BoarderDrone(const std::string& _type, const std::string& _name, int _shipId, const DroneBlueprint* _blueprint, CrewAnimation *_anim)
	{
		this->constructor(_type, _name, _shipId, _blueprint, _anim);
	}

};

struct BoarderDrone;
struct BoarderPodDrone;

struct DamageMessage;

struct SpaceDrone;

struct LIBZHL_INTERFACE SpaceDrone : Drone
{
	virtual void PickDestination() LIBZHL_PLACEHOLDER
	virtual void PickTarget() LIBZHL_PLACEHOLDER
	virtual bool HasTarget() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual float GetWeaponCooldown() LIBZHL_PLACEHOLDER
	virtual void RandomizeStartingPosition() LIBZHL_PLACEHOLDER
	virtual bool HideUnderOwner() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual Projectile *GetNextProjectile();
	LIBZHL_API virtual void SetMovementTarget(Targetable *target);
	virtual void SetWeaponTarget(Targetable *target) LIBZHL_PLACEHOLDER
	virtual bool ValidTargetObject(Targetable *target) LIBZHL_PLACEHOLDER
	virtual void OnRender(int space) LIBZHL_PLACEHOLDER
	virtual void RenderDrone() LIBZHL_PLACEHOLDER
	virtual std::string *GetTooltip(SpaceDrone *drone) LIBZHL_PLACEHOLDER
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual void SetCurrentLocation(Pointf pos) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int mX, int mY) LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool unk) LIBZHL_PLACEHOLDER
	virtual Globals::Ellipse *GetShieldShape(SpaceDrone *drone) LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace);
	virtual bool DamageBeam(Pointf pos1, Pointf pos2, Damage damage) LIBZHL_PLACEHOLDER
	virtual bool DamageArea(Pointf pos, Damage damage, bool unk) LIBZHL_PLACEHOLDER
	virtual BoarderDrone *GetBoardingDrone() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetDeployed(bool deployed);
	LIBZHL_API float UpdateAimingAngle(Pointf location, float percentage, float forceDesired);
	LIBZHL_API void constructor(int iShipId, int selfId, DroneBlueprint *blueprint);
	LIBZHL_API void destructor();
	
	Targetable _targetable;
	Collideable _collideable;
	int currentSpace;
	int destinationSpace;
	Pointf currentLocation;
	Pointf lastLocation;
	Pointf destinationLocation;
	Pointf pointTarget;
	Animation explosion;
	Targetable *weaponTarget;
	Pointf targetLocation;
	Pointf targetSpeed;
	Targetable *movementTarget;
	Pointf speedVector;
	bool poweredLastFrame;
	bool deployedLastFrame;
	bool bFire;
	float pause;
	float additionalPause;
	float weaponCooldown;
	float current_angle;
	float aimingAngle;
	float lastAimingAngle;
	float desiredAimingAngle;
	DamageMessage *message;
	Animation weapon_animation;
	const WeaponBlueprint *weaponBlueprint;
	int lifespan;
	bool bLoadedPosition;
	bool bDisrupted;
	float hackAngle;
	float ionStun;
	Pointf beamCurrentTarget;
	Pointf beamFinalTarget;
	float beamSpeed;
	Animation hackSparks;
};

struct BoarderPodDrone : SpaceDrone
{
	BoarderPodDrone(int _iShipId, int _selfId, const DroneBlueprint& _bp)
	{
		this->constructor(_iShipId, _selfId, _bp);
	}

	LIBZHL_API bool CanBeDeployed();
	LIBZHL_API CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace);
	LIBZHL_API void SetDeployed(bool _deployed);
	LIBZHL_API void SetMovementTarget(Targetable *target);
	LIBZHL_API void constructor(int _iShipId, int _selfId, const DroneBlueprint &_bp);
	
	GL_Texture *baseSheet;
	GL_Texture *colorSheet;
	Pointf startingPosition;
	Animation droneImage;
	CachedImage flame;
	BoarderDrone *boarderDrone;
	bool bDeliveredDrone;
	bool diedInSpace;
};

struct BoardingEvent
{
	std::string type;
	int min;
	int max;
	int amount;
	bool breach;
};

struct BombProjectile;

struct BombProjectile : Projectile
{
	BombProjectile(Pointf _position, int _ownerId, int _targetId, Pointf _target)
	{
		this->constructor(_position, _ownerId, _targetId, _target);
	}

	LIBZHL_API void CollisionCheck(Collideable *other);
	LIBZHL_API void OnUpdate();
	LIBZHL_API void constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target);
	
	bool bMissed;
	DamageMessage *missMessage;
	float explosiveDelay;
	bool bSuperShield;
	bool superShieldBypass;
};

struct BossShip;

struct CompleteShip;

struct CombatAI;

struct CombatAI
{
	LIBZHL_API void OnLoop();
	LIBZHL_API void UpdateMindControl(bool unk);
	
	ShipManager *target;
	std::vector<ProjectileFactory*> weapons;
	std::vector<SpaceDrone*> drones;
	int stance;
	std::vector<int> system_targets;
	bool bFiringWhileCloaked;
	ShipManager *self;
};

struct CrewAI;

struct CrewAI
{
	LIBZHL_API void AssignCrewmembers();
	LIBZHL_API void CheckForHealing();
	LIBZHL_API void CheckForProblems();
	LIBZHL_API int DangerRating(int roomId, int crewId);
	LIBZHL_API void OnLoop();
	LIBZHL_API int PrioritizeIntruderRoom(CrewMember *crew, int roomId, int target);
	LIBZHL_API int PrioritizeTask(CrewTask task, int crewId);
	LIBZHL_API void UpdateCrewMember(int crewId);
	LIBZHL_API void UpdateDrones();
	LIBZHL_API void UpdateIntruders();
	
	ShipManager *ship;
	bool bAIon;
	bool bAirlockRequested;
	bool bMedbayRequested;
	bool bHurtCrew;
	bool bCalmShip;
	std::vector<CrewMember*> crewList;
	std::vector<CrewMember*> intruderList;
	std::vector<Repairable*> hullBreaches;
	std::vector<CrewTask> desiredTaskList;
	std::vector<CrewTask> bonusTaskList;
	std::vector<bool> breachedRooms;
	int iTeleportRequest;
	bool bUrgentTeleport;
	int startingCrewCount;
	bool bMultiracialCrew;
	bool bOverrideRace;
};

struct PowerProfile
{
};

struct ShipAI;

struct ShipAI
{
	LIBZHL_API std::pair<int, int> GetTeleportCommand();
	LIBZHL_API void OnLoop(bool hostile);
	LIBZHL_API void SetStalemate(bool stalemate);
	LIBZHL_API void constructor(bool unk);
	
	ShipManager *ship;
	ShipManager *target;
	CrewAI crewAI;
	CombatAI combatAI;
	bool playerShip;
	bool surrendered;
	bool escaping;
	bool destroyed;
	int surrenderThreshold;
	int escapeThreshold;
	float escapeTimer;
	int lastMaxPower;
	std::map<std::string, PowerProfile> powerProfiles;
	int boardingProfile;
	int iTeleportRequest;
	int iTeleportTarget;
	int brokenSystems;
	int boardingAi;
	int iCrewNeeded;
	bool bStalemateTrigger;
	char field_ED[3];
	float fStalemateTimer;
	int lastHealth;
	bool bBoss;
	char field_F9[3];
	int iTimesTeleported;
};

struct SpaceManager;

struct LIBZHL_INTERFACE CompleteShip
{
	void CheckTeleportMovement();

	virtual ~CompleteShip() {}
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual void PauseLoop();
	virtual bool IsBoss() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void Restart();
	virtual bool IncomingFire() LIBZHL_PLACEHOLDER
	LIBZHL_API void AddBoarders(int amount, const std::string &race, bool unk2);
	LIBZHL_API CrewMember *AddCrewMember(const CrewBlueprint *blueprint, bool hostile);
	LIBZHL_API CrewMember *AddCrewMember1(const std::string &race, const std::string &name, bool hostile);
	LIBZHL_API CrewMember *AddCrewMember2(CrewMember *member, int unk);
	LIBZHL_API Drone *AddDrone(const DroneBlueprint *blueprint, int unk);
	LIBZHL_API int CountCrew(bool boarders);
	LIBZHL_API bool DeadCrew();
	LIBZHL_API std::vector<CrewMember*> GetTeleportingParty();
	LIBZHL_API void InitiateTeleport(int targetRoom, int command);
	LIBZHL_API void Jump();
	LIBZHL_API void KillRandomCrew();
	LIBZHL_API void LoadState(int unk);
	LIBZHL_API void OnInit(const ShipBlueprint *blueprint, int unk);
	LIBZHL_API void OnRender();
	LIBZHL_API void OnRenderShip(bool unk1, bool unk2);
	LIBZHL_API void OnRenderSpace();
	LIBZHL_API void SaveState(int unk);
	LIBZHL_API void SetEnemyShip(CompleteShip *other);
	LIBZHL_API void SetShip(ShipManager *ship);
	LIBZHL_API std::vector<CrewMember*> TeleportCrew(int roomId, bool intruders);
	LIBZHL_API void constructor(SpaceManager *space, bool unk, int unk2);
	
	int iShipId;
	ShipManager *shipManager;
	SpaceManager *spaceManager;
	CompleteShip *enemyShip;
	bool bPlayerShip;
	ShipAI shipAI;
	std::vector<CrewMember*> arrivingParty;
	std::vector<CrewMember*> leavingParty;
	int teleTargetRoom;
};

struct LocationEvent;

struct BossShip : CompleteShip
{
	LIBZHL_API void ClearLocation();
	LIBZHL_API bool Defeated();
	LIBZHL_API LocationEvent *GetEvent();
	LIBZHL_API LocationEvent *GetSubEvent();
	LIBZHL_API bool IncomingFire();
	LIBZHL_API void LoadBoss(int file);
	LIBZHL_API void OnLoop();
	LIBZHL_API void Restart();
	LIBZHL_API void SaveBoss(int file);
	LIBZHL_API void StartStage();
	LIBZHL_API void constructor(SpaceManager *space);
	
	int currentStage;
	TimerHelper powerTimer;
	int powerCount;
	std::vector<int> crewCounts;
	bool bDeathBegan;
	int nextStage;
};

struct CApp;

struct CEvent;
struct InputEvent;

struct CEvent
{
	enum TextEvent
	{
	  TEXT_CONFIRM = 0x0,
	  TEXT_CANCEL = 0x1,
	  TEXT_CLEAR = 0x2,
	  TEXT_BACKSPACE = 0x3,
	  TEXT_DELETE = 0x4,
	  TEXT_LEFT = 0x5,
	  TEXT_RIGHT = 0x6,
	  TEXT_HOME = 0x7,
	  TEXT_END = 0x8,
	};

	LIBZHL_API void OnEvent(const InputEvent *event);
	
	void *vptr;
};

struct GL_FrameBuffer;

struct FocusWindow;

struct FocusWindow
{
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	
	void *vptr;
	bool bOpen;
	bool bFullFocus;
	uint8_t gap_ex_fw[2];
	Point close;
	bool bCloseButtonSelected;
	Point position;
};

struct LanguageChooser;
struct TextButton;

struct LanguageChooser : FocusWindow
{
	LIBZHL_API void OnRender();
	
	std::vector<TextButton*> buttons;
	int iChoice;
};

struct ChoiceBox;

struct ResourceEvent
{
	int missiles;
	int fuel;
	int drones;
	int scrap;
	int crew;
	bool traitor;
	bool cloneable;
	TextString cloneText;
	std::string crewType;
	const WeaponBlueprint *weapon;
	const DroneBlueprint *drone;
	const AugmentBlueprint *augment;
	CrewBlueprint crewBlue;
	int systemId;
	int weaponCount;
	int droneCount;
	bool steal;
	bool intruders;
	int fleetDelay;
	int hullDamage;
	int upgradeAmount;
	int upgradeId;
	int upgradeSuccessFlag;
	std::string removeItem;
};

struct ChoiceText
{
	ChoiceText(int _type, const std::string& _text, ResourceEvent _rewards) : 
	type(_type), text(_text), rewards(_rewards)
	{
	}

	int type;
	std::string text;
	ResourceEvent rewards;
};

struct WindowFrame;

struct ChoiceBox : FocusWindow
{
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnRender();
	
	GL_Texture *textBox;
	WindowFrame *box;
	std::string mainText;
	std::vector<ChoiceText> choices;
	unsigned int columnSize;
	std::vector<Globals::Rect> choiceBoxes;
	int potentialChoice;
	int selectedChoice;
	int fontSize;
	bool centered;
	int gap_size;
	float openTime;
	ResourceEvent rewards;
	GL_Color currentTextColor;
	Pointf lastChoice;
};

struct ConfirmWindow;

struct TextButton : GenericButton
{
	TextButton()
	{
		this->constructor();
	}
	
	~TextButton()
	{
		CSurface::GL_DestroyPrimitive(primitives[0]);
		CSurface::GL_DestroyPrimitive(primitives[1]);
		CSurface::GL_DestroyPrimitive(primitives[2]);
		CSurface::GL_DestroyPrimitive(basePrimitive);
	}

	LIBZHL_API int GetIdealButtonWidth();
	LIBZHL_API Point GetSize();
	LIBZHL_API void InitPrimitives();
	LIBZHL_API void OnInit(Point pos, Point size, int cornerInset, TextString *buttonLabel, int font);
	LIBZHL_API void OnInitRect(Globals::Rect &rect, int cornerInset, TextString &buttonLabel, int font);
	LIBZHL_API void OnRender();
	LIBZHL_API void ResetPrimitives();
	LIBZHL_API void SetActiveColor(GL_Color color);
	LIBZHL_API void SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min);
	LIBZHL_API void SetBaseImage(const std::string &name, Point pos, int autoWidthMin);
	LIBZHL_API void SetInactiveColor(GL_Color color);
	LIBZHL_API void SetSelectedColor(GL_Color color);
	LIBZHL_API void SetTextColor(GL_Color color);
	LIBZHL_API void UpdateAutoWidth();
	LIBZHL_API void constructor();
	LIBZHL_API void destructor();
	
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
	bool autoShrink;
};

struct ConfirmWindow : FocusWindow
{
	ConfirmWindow()
	{
		this->constructor();
	}

	LIBZHL_API void Close();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnRender();
	LIBZHL_API void Open();
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_);
	LIBZHL_API void constructor();
	
	TextString text;
	int textHeight;
	int minWidth;
	int windowWidth;
	TextString yesText;
	TextString noText;
	bool autoCenter;
	GL_Texture *windowImage;
	GL_Primitive *window;
	TextButton yesButton;
	TextButton noButton;
	bool result;
};

struct CreditScreen;

struct CreditScreen
{
	LIBZHL_API bool Done();
	LIBZHL_API void OnRender();
	LIBZHL_API void Start(const std::string &shipName, const std::vector<std::string> &crewNames);
	LIBZHL_API void constructor();
	
	float scroll;
	std::string shipName;
	std::string crewString;
	float pausing;
	GL_Texture *bg;
	std::vector<std::string> creditNames;
	int lastValidCredit;
	int touchesDown;
	double touchDownTime;
	float skipMessageTimer;
	char gap5C[3];
	char _unk;
};

struct MainMenu;

struct ControlButton;

struct ControlButton
{
	LIBZHL_API void OnRender();
	
	Globals::Rect rect;
	std::string value;
	TextString desc;
	std::string key;
	int state;
	int descLength;
};

struct ControlsScreen;

struct ControlsScreen
{
	LIBZHL_API void OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	
	std::vector<ControlButton> buttons[4];
	int selectedButton;
	TextButton defaultButton;
	ConfirmWindow resetDialog;
	Button pageButtons[4];
	int currentPage;
	WindowFrame *customBox;
};

struct OptionsScreen;

struct SlideBar
{
	Globals::Rect box;
	bool hovering;
	bool holding;
	Globals::Rect marker;
	Point mouseStart;
	Point rectStart;
	std::pair<int, int> minMax;
};

struct OptionsScreen : ChoiceBox
{
    struct Steam1613OptionsScreenStructAdditions {
        bool showSyncAchievements;
        TextButton syncAchievementsButton;
    };

	LIBZHL_API void OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void Open(bool mainMenu);
	
	Point position;
	Point wipeProfilePosition;
	SlideBar soundVolume;
	SlideBar musicVolume;
	bool bCustomizeControls;
	ControlsScreen controls;
	TextButton closeButton;
	TextButton wipeProfileButton;
	STEAM1613OPTIONSSCREENADDITIONS_TYPE STEAM1613OPTIONSSCREENADDITONS_NAME;
	int choiceFullscreen;
	int choiceVSync;
	int choiceFrameLimit;
	int choiceLowend;
	int choiceColorblind;
	int choiceLanguage;
	int choiceDialogKeys;
	int choiceShowPaths;
	int choiceAchievementPopups;
	int choiceAutoPause;
	int choiceTouchAutoPause;
	int choiceControls;
	int lastFullScreen;
	bool isSoundTouch;
	bool isMusicTouch;
	LanguageChooser langChooser;
	bool showWipeButton;
	ConfirmWindow wipeProfileDialog;
	ChoiceBox restartRequiredDialog;
};

struct CrewCustomizeBox;

struct ItemBlueprint;

struct SystemBlueprint;

struct InfoBox
{
	InfoBox()
	{
		this->constructor();
	}

	enum ExpandDir
	{
	  EXPAND_UP = -1,
	  EXPAND_NONE = 0,
	  EXPAND_DOWN = 1,
	};


	LIBZHL_API int CalcBoxHeight();
	LIBZHL_API void Clear();
	LIBZHL_API bool IsEmpty();
	LIBZHL_API void OnRender();
	LIBZHL_API void SetBlueprint(const ItemBlueprint *bp);
	LIBZHL_API void SetBlueprintAugment(const AugmentBlueprint *bp);
	LIBZHL_API void SetBlueprintCrew(const CrewBlueprint *bp, int yShift, bool detailedCrew);
	LIBZHL_API void SetBlueprintDrone(const DroneBlueprint *bp, int status, bool hasDroneSystem, int yShift);
	LIBZHL_API void SetBlueprintWeapon(const WeaponBlueprint *bp, int status, bool hasWeaponSystem, int yShift);
	LIBZHL_API void SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir);
	LIBZHL_API void SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth);
	LIBZHL_API void SetSystemId(int systemId, int maxPower, int currentLevel, int upgrade, int yShift, int forceSystemWidth);
	LIBZHL_API void SetText(const std::string &title, const std::string &text, int width, int height, InfoBox::ExpandDir dir);
	LIBZHL_API void constructor();
	
	Point location;
	const SystemBlueprint *blueprint;
	Description desc;
	int tempUpgrade;
	int powerLevel;
	int maxPower;
	int systemId;
	int systemWidth;
	int yShift;
	Point descBoxSize;
	const CrewBlueprint *pCrewBlueprint;
	std::string warning;
	bool bDetailed;
	std::string additionalTip;
	std::string additionalWarning;
	WindowFrame *primaryBox;
	int primaryBoxOffset;
	WindowFrame *secondaryBox;
	std::string droneBlueprint;
};

struct ShipAchievementInfo
{
	CAchievement *achievement;
	Point position;
	int dimension;
};

struct ShipBuilder;

struct ShipButton;
struct ShipSelect;

struct UnlockArrow;

struct UnlockArrow
{
	LIBZHL_API bool MouseMove(int x, int y);
	LIBZHL_API void OnRender();
	LIBZHL_API void constructor(Point pos, int unk1, int unk2);
	
	int direction;
	int status;
	Globals::Rect shape;
};

struct ShipSelect
{
	LIBZHL_API void ClearShipButtons();
	LIBZHL_API void Close();
	LIBZHL_API int GetSelectedShip();
	LIBZHL_API int KeyDown(SDLKey key);
	LIBZHL_API void MouseClick();
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void Open(int currentId, int currentType);
	LIBZHL_API void PreSelectShip(int shipType);
	LIBZHL_API void SelectShip(int shipType);
	LIBZHL_API void constructor();
	
	Point position;
	Point titlePos;
	std::vector<GL_Primitive*> shipListBase;
	std::vector<ShipButton*> shipButtons;
	std::vector<UnlockArrow> arrows;
	bool bOpen;
	int selectedShip;
	InfoBox infoBox;
	int currentType;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	TextButton confirm;
	bool bConfirmed;
	int activeTouch;
	ChoiceBox tutorial;
	int tutorialPage;
};

struct SystemCustomBox;

struct TextInput;

struct TextInput
{
	enum AllowedCharType
	{
	  ALLOW_ASCII = 0x0,
	  ALLOW_LANGUAGE = 0x1,
	  ALLOW_ANY = 0x2,
	};
	
	TextInput()
	{
	}

	TextInput(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string& prompt)
	{
		this->constructor(maxChars, allowedCharType, prompt);
	};

	LIBZHL_API bool GetActive();
	LIBZHL_API std::string GetText();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender(int font, Point pos);
	LIBZHL_API void OnTextEvent(CEvent::TextEvent event);
	LIBZHL_API void OnTextInput(int asciiChar);
	LIBZHL_API int SetText(const std::string &text);
	LIBZHL_API void Start();
	LIBZHL_API void Stop();
	LIBZHL_API void constructor(int maxChars, TextInput::AllowedCharType allowedCharType, const std::string &prompt);
	
	std::string prompt;
	std::vector<int> text;
	std::vector<int> oldText;
	int pos;
	int lastPos;
	bool bActive;
	int allowedChars;
	int maxChars;
	TimerHelper blinker;
};

struct ShipBuilder
{
	LIBZHL_API void CheckTypes();
	LIBZHL_API void ClearShipAchievements();
	LIBZHL_API void CreateEquipmentBoxes();
	LIBZHL_API void CreateSystemBoxes();
	LIBZHL_API void CycleShipNext();
	LIBZHL_API void CycleShipPrevious();
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnKeyDown(SDLKey key);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void Open();
	LIBZHL_API void SetupShipAchievements();
	LIBZHL_API void SwapType(int variant);
	LIBZHL_API void SwitchShip(int shipType, int shipVariant);
	LIBZHL_API void constructor();
	
	ShipManager *currentShip;
	GL_Primitive *nameBoxPrimitive;
	GL_Primitive *enableAdvancedPrimitive;
	Button resetButton;
	Button clearButton;
	TextButton startButton;
	TextButton backButton;
	TextButton renameButton;
	Button leftButton;
	Button rightButton;
	TextButton listButton;
	TextButton showButton;
	TextButton easyButton;
	TextButton normalButton;
	TextButton hardButton;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	Point typeALoc;
	Point typeBLoc;
	Point typeCLoc;
	TextButton randomButton;
	TextButton advancedOffButton;
	TextButton advancedOnButton;
	std::vector<GenericButton*> buttons;
	std::vector<Animation> animations;
	std::vector<CrewCustomizeBox*> vCrewBoxes;
	bool bOpen;
	GL_Primitive *baseImage;
	GL_Primitive *shipSelectBox;
	GL_Primitive *shipAchBox;
	GL_Primitive *shipEquipBox;
	GL_Primitive *startButtonBox;
	GL_Primitive *advancedButtonBox;
	int typeAOffset;
	int typeBOffset;
	int typeCOffset;
	int shipAchPadding;
	int advancedTitleOffset;
	std::vector<EquipmentBox*> vEquipmentBoxes;
	InfoBox infoBox;
	std::vector<SystemCustomBox*> sysBoxes;
	int shoppingId;
	int currentSlot;
	int currentBox;
	bool bDone;
	const ShipBlueprint *ships[30];
	int currentShipId;
	int storeIds[4];
	bool bRenaming;
	std::string currentName;
	bool bShowRooms;
	bool bCustomizingCrew;
	Animation walkingMan;
	Pointf walkingManPos;
	ShipSelect shipSelect;
	ChoiceBox introScreen;
	bool bShowedIntro;
	int currentType;
	TextInput nameInput;
	int activeTouch;
	bool activeTouchIsShip;
	bool shipDragActive;
	bool shipDragVertical;
	Point shipDragOffset;
	std::vector<ShipAchievementInfo> shipAchievements;
	int selectedAch;
	GL_Texture *arrow;
	WindowFrame *descBox;
	AnimationTracker tracker;
	bool encourageShipList;
};

struct MainMenu
{
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API bool Open();
	LIBZHL_API void constructor();
	
	bool bOpen;
	int activeTouch;
	GL_Texture *background;
	GL_Texture *glowy;
	AnimationTracker glowTracker;
	Button continueButton;
	Button startButton;
	Button helpButton;
	Button statButton;
	Button optionsButton;
	Button creditsButton;
	Button quitButton;
	std::vector<Button*> buttons;
	int finalChoice;
	ShipBuilder shipBuilder;
	bool bScoreScreen;
	OptionsScreen optionScreen;
	bool bSelectSave;
	ConfirmWindow confirmNewGame;
	ChoiceBox changelog;
	bool bCreditScreen;
	CreditScreen credits;
	bool bChangedLogin;
	std::vector<CrewMember*> testCrew;
	bool bChangedScreen;
	char gap34A4[3];
	std::string error;
};

struct WorldManager;

struct CApp : CEvent
{
	LIBZHL_API void GenInputEvents();
	LIBZHL_API void OnCleanup();
	LIBZHL_API int OnExecute();
	LIBZHL_API void OnExit();
	LIBZHL_API int OnInit();
	LIBZHL_API void OnInputBlur();
	LIBZHL_API void OnInputFocus();
	LIBZHL_API void OnKeyDown(SDLKey key);
	LIBZHL_API void OnKeyUp(SDLKey key);
	LIBZHL_API void OnLButtonDown(int x, int y);
	LIBZHL_API void OnLButtonUp(int x, int y);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnMButtonDown(int x, int y);
	LIBZHL_API void OnMouseMove(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB);
	LIBZHL_API void OnRButtonDown(int x, int y);
	LIBZHL_API void OnRButtonUp(int x, int y);
	LIBZHL_API void OnRender();
	LIBZHL_API void OnRequestExit();
	LIBZHL_API void OnResume();
	LIBZHL_API void OnSuspend();
	LIBZHL_API void OnTextEvent(CEvent::TextEvent textEvent);
	LIBZHL_API void OnTextInput(int ch);
	LIBZHL_API void ParseArgs(int argc, const char **argv);
	LIBZHL_API int SetupWindow();
	LIBZHL_API Point TranslateMouse(int x, int y);
	LIBZHL_API void UpdateFullScreen();
	LIBZHL_API void UpdateWindowSettings();
	LIBZHL_API void constructor();
	
	bool Running;
	bool shift_held;
	CommandGui *gui;
	WorldManager *world;
	MainMenu menu;
	LanguageChooser langChooser;
	int screen_x;
	int screen_y;
	int modifier_x;
	int modifier_y;
	bool fullScreenLastState;
	bool minimized;
	bool minLastState;
	bool focus;
	bool focusLastState;
	bool steamOverlay;
	bool steamOverlayLastState;
	bool rendering;
	bool gameLogic;
	float mouseModifier_x;
	float mouseModifier_y;
	GL_FrameBuffer *framebuffer;
	bool fboSupport;
	int x_bar;
	int y_bar;
	bool lCtrl;
	bool useFrameBuffer;
	bool manualResolutionError;
	int manualResErrorX;
	int manualResErrorY;
	bool nativeFullScreenError;
	bool fbStretchError;
	char __NULL[2];
	std::string lastLanguage;
	char inputFocus;
};

struct CFPS;

struct CFPS
{
	LIBZHL_API float GetSpeedFactor();
	LIBZHL_API void OnLoop();
	
	float RunningTime;
	double OldTime;
	double LastTime;
	float SpeedFactor;
	int NumFrames;
	int Frames;
	int speedLevel;
};

struct ChoiceReq
{
	std::string object;
	int min_level;
	int max_level;
	int max_group;
	bool blue;
};

struct CloakingBox;
struct CloakingSystem;

struct CloakingBox : CooldownSystemBox
{
	CloakingBox(Point pos, CloakingSystem* sys)
	{
		this->constructor(pos, sys);
	}

	LIBZHL_API void constructor(Point pos, CloakingSystem *sys);
	
	std::vector<Button*> buttons;
	Button *currentButton;
	CloakingSystem *cloakSystem;
	Point buttonOffset;
};

struct CloakingSystem : ShipSystem
{
	LIBZHL_API void FiredWeapon();
	LIBZHL_API void OnLoop();
	
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
	AnimationTracker glowTracker;
	GL_Primitive *glowImage;
};

struct CloneBox;
struct CloneSystem;

struct CloneBox : CooldownSystemBox
{
	CloneBox(Point pos, CloneSystem* sys)
	{
		this->constructor(pos, sys);
	}

	LIBZHL_API void constructor(Point pos, CloneSystem *sys);
	
	CloneSystem *cloneSys;
	GL_Texture *pipe[3];
	GL_Texture *boxBottom;
	GL_Texture *boxMiddle;
	GL_Texture *boxTop;
	GL_Texture *boxSolo;
	GL_Texture *boxFill;
	WarningMessage *dyingCrewWarning;
};

struct CloneSystem : ShipSystem
{
	LIBZHL_API void OnLoop();
	
	float fTimeToClone;
	CrewMember *clone;
	float fTimeGoal;
	float fDeathTime;
	GL_Texture *bottom;
	GL_Texture *top;
	GL_Texture *gas;
	int slot;
	Animation *currentCloneAnimation;
	std::map<std::string, Animation> cloneAnimations;
};

struct CombatControl;

struct DroneControl;

struct DroneControl : ArmamentControl
{
	LIBZHL_API SDLKey ArmamentHotkey(unsigned int i);
	LIBZHL_API TextString HolderLabel();
	LIBZHL_API void OnLoop();
	
	WarningMessage droneMessage;
	WarningMessage noTargetMessage;
	WarningMessage systemMessage;
};

struct HandAnimation
{
	GL_Texture *hand;
	Point start;
	Point finish;
	Pointf location;
	bool bRunning;
	float pause;
};

struct WeaponControl;

struct WeaponControl : ArmamentControl
{
	void RenderAimingNew(bool player);
	inline GL_Primitive *GetAimingPrimitive(ProjectileFactory *weapon, int i);

	LIBZHL_API SDLKey ArmamentHotkey(unsigned int i);
	LIBZHL_API void Fire(std::vector<Pointf> &points, int target, bool autoFire);
	LIBZHL_API TextString HolderLabel();
	LIBZHL_API bool KeyDown(SDLKey key);
	LIBZHL_API bool LButton(int x, int y, bool holdingShift);
	LIBZHL_API void LinkShip(ShipManager *ship);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void OnRender(bool unk);
	LIBZHL_API void RenderAiming();
	LIBZHL_API static void __stdcall RenderBeamAiming(Pointf one, Pointf two, bool bAutoFire);
	LIBZHL_API void RenderSelfAiming();
	LIBZHL_API void SetAutofiring(bool on, bool simple);
	LIBZHL_API void constructor();
	
	Targetable *currentTarget;
	ProjectileFactory *armedWeapon;
	bool autoFiring;
	TextButton autoFireButton;
	GL_Primitive *autoFireBase;
	GL_Primitive *targetIcon[4];
	GL_Primitive *targetIconYellow[4];
	Pointf autoFireFocus;
	WarningMessage missileMessage;
	WarningMessage systemMessage;
	int armedSlot;
};

struct CombatControl
{
	LIBZHL_API void AddEnemyShip(CompleteShip *ship);
	LIBZHL_API char CanTargetSelf();
	LIBZHL_API void Clear();
	LIBZHL_API char CurrentTargetIsBoss();
	LIBZHL_API void DisarmAll();
	LIBZHL_API void DisarmTeleporter();
	LIBZHL_API void DrawHostileBox(GL_Color color, int stencilBit);
	LIBZHL_API std::string GetCrewTooltip(int x, int y);
	LIBZHL_API ShipManager *GetCurrentTarget();
	LIBZHL_API std::pair<int, int> GetTeleportationCommand();
	LIBZHL_API void KeyDown(SDLKey key);
	LIBZHL_API void MouseClick(int mX, int mY, bool shift);
	LIBZHL_API bool MouseMove(int mX, int mY);
	LIBZHL_API bool MouseRClick(int x, int y);
	LIBZHL_API void OnInit(Point pos);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRenderCombat();
	LIBZHL_API void OnRenderSelfAiming();
	LIBZHL_API void RenderShipStatus(Pointf pos, GL_Color color);
	LIBZHL_API void RenderTarget();
	LIBZHL_API bool SelectTarget();
	LIBZHL_API void SetMouseCursor();
	LIBZHL_API void UpdateAiming();
	LIBZHL_API bool UpdateTarget();
	LIBZHL_API bool WeaponsArmed();
	LIBZHL_API void constructor();
	
	CommandGui *gui;
	ShipManager *shipManager;
	Point playerShipPosition;
	SpaceManager *space;
	WeaponControl weapControl;
	DroneControl droneControl;
	std::vector<SystemBox*> sysBoxes;
	std::vector<CompleteShip*> enemyShips;
	CompleteShip *currentTarget;
	SpaceDrone *currentDrone;
	Point position;
	int selectedRoom;
	int selectedSelfRoom;
	Point targetPosition;
	Point boxPosition;
	WindowFrame *hostileBoxFrame;
	CachedImage healthMask;
	CachedImage shieldCircleCharged[5];
	CachedImage shieldCircleUncharged[5];
	CachedImage shieldCircleHacked[5];
	CachedImage shieldCircleHackedCharged[5];
	CachedImage shieldChargeBox;
	CachedImage superShieldBox5;
	CachedImage superShieldBox12;
	bool open;
	float shipIconSize;
	Pointf potentialAiming;
	std::vector<Pointf> aimingPoints;
	Pointf lastMouse;
	bool mouseDown;
	bool isAimingTouch;
	bool movingBeam;
	Point beamMoveLast;
	bool invalidBeamTouch;
	Point screenReposition;
	std::pair<int, int> teleportCommand;
	int iTeleportArmed;
	CachedImage teleportTarget_send;
	CachedImage teleportTarget_return;
	CachedImage hackTarget;
	CachedImage mindTarget;
	AnimationTracker ftl_timer;
	WarningMessage ftlWarning;
	AnimationTracker hacking_timer;
	std::vector<std::string> hackingMessages;
	bool boss_visual;
	bool bTeachingBeam;
	WindowFrame *tipBox;
	HandAnimation hand;
};

struct CombatDrone;

struct CombatDrone : SpaceDrone
{
	CombatDrone(int shipId, int self, const DroneBlueprint* bp)
	{
		this->constructor(shipId, self, bp);
	}

	LIBZHL_API void PickTarget();
	LIBZHL_API void SetWeaponTarget(Targetable *target);
	LIBZHL_API void constructor(int iShipId, int selfId, const DroneBlueprint *bp);
	
	Pointf lastDestination;
	float progressToDestination;
	float heading;
	float oldHeading;
	CachedImage drone_image_off;
	CachedImage drone_image_charging;
	CachedImage drone_image_on;
	CachedImage engine_image;
};

struct CrewBox;
struct CrewControl;

struct CrewControl
{
	LIBZHL_API void ClearCrewBoxes();
	LIBZHL_API void ClearDeadCrew(std::vector<CrewMember*> *crew);
	LIBZHL_API void KeyDown(SDLKey key);
	LIBZHL_API void LButton(int mX, int mY, int wX, int wY, bool shiftHeld);
	LIBZHL_API void LinkShip(ShipManager *ship);
	LIBZHL_API void MouseMove(int mX, int mY, int wX, int wY);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void RButton(int mX, int mY, bool shiftHeld);
	LIBZHL_API void SelectCrew(bool keep_current);
	LIBZHL_API void SelectPotentialCrew(CrewMember *crew, bool allowTeleportLeaving);
	LIBZHL_API void UpdateCrewBoxes();
	
	ShipManager *shipManager;
	std::vector<CrewMember*> selectedCrew;
	std::vector<CrewMember*> potentialSelectedCrew;
	Door *selectedDoor;
	Repairable *selectedRepair;
	Point selectedGrid;
	int selectedRoom;
	bool selectedPlayerShip;
	Point availablePosition;
	std::vector<CrewBox*> crewBoxes;
	Point firstMouse;
	Point currentMouse;
	Point worldFirstMouse;
	Point worldCurrentMouse;
	bool mouseDown;
	bool bUpdated;
	int activeTouch;
	char selectingCrew;
	char selectingCrewOnPlayerShip;
	double selectingCrewStartTime;
	bool doorControlMode;
	bool doorControlOpen;
	bool doorControlOpenSet;
	CombatControl *combatControl;
	unsigned int selectedCrewBox;
	AnimationTracker crewMessage;
	std::string message;
	Button saveStations;
	Button returnStations;
	GL_Primitive *saveStationsBase;
	GL_Primitive *returnStationsBase;
	int stationsLastY;
};

struct CrewEquipBox;
struct CrewManifest;

struct DropBox;

struct DropBox
{
	LIBZHL_API int GetHeight();
	LIBZHL_API void OnRender();
	
	Point position;
	bool isSellBox;
	GL_Texture *boxImage[2];
	int selectedImage;
	TextString titleText;
	TextString bodyText;
	int bodySpace;
	TextString lowerText;
	TextString sellText;
	std::string sellCostText;
	int textWidth;
	int insertHeight;
	int titleInsert;
};

struct CrewManifest : FocusWindow
{
	void _HS_MouseUp(int mX, int mY);

	LIBZHL_API void Close();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnInit(ShipManager *ship);
	LIBZHL_API void OnKeyDown(SDLKey key);
	LIBZHL_API void OnKeyUp(SDLKey key);
	LIBZHL_API void OnRender();
	LIBZHL_API void OnTextEvent(CEvent::TextEvent event);
	LIBZHL_API void OnTextInput(SDLKey key);
	LIBZHL_API void Update();
	LIBZHL_API void constructor();
	
	GL_Primitive *box;
	DropBox overBox;
	ShipManager *shipManager;
	std::vector<CrewEquipBox*> crewBoxes;
	InfoBox infoBox;
	int confirmingDelete;
	ConfirmWindow deleteDialog;
};

struct Equipment : FocusWindow
{
	LIBZHL_API void AddAugment(AugmentBlueprint *bp, bool unk1, bool unk2);
	LIBZHL_API void AddDrone(DroneBlueprint *bp, bool unk1, bool unk2);
	LIBZHL_API void AddToCargo(std::string &name);
	LIBZHL_API void AddWeapon(WeaponBlueprint *bp, bool unk1, bool unk2);
	LIBZHL_API void Close();
	LIBZHL_API std::vector<std::string> GetCargoHold();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseUp(int mX, int mY);
	LIBZHL_API void OnInit(ShipManager *ship);
	LIBZHL_API void OnLoop();
	LIBZHL_API void Open();
	
	GL_Texture *box;
	GL_Texture *storeBox;
	DropBox overBox;
	DropBox overAugImage;
	DropBox sellBox;
	bool bSellingItem;
	ShipManager *shipManager;
	std::vector<EquipmentBox*> vEquipmentBoxes;
	std::vector<ProjectileFactory*> weaponsTrashList;
	EquipmentBox *overcapacityBox;
	AugmentEquipBox *overAugBox;
	int selectedEquipBox;
	int draggingEquipBox;
	int potentialDraggingBox;
	bool bDragging;
	Point firstMouse;
	Point currentMouse;
	Point dragBoxCenter;
	Point dragBoxOffset;
	InfoBox infoBox;
	std::string sellCostText;
	bool bOverCapacity;
	bool bOverAugCapacity;
	bool bStoreMode;
	int cargoId;
	Point infoBoxLoc;
};

struct FTLButton;

struct TextButton0 : GenericButton
{
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	unsigned char gap65[3];
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	unsigned char gapB5[3];
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	unsigned char gapC1[3];
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
	bool autoShrink;
};

struct FTLButton : TextButton0
{
	LIBZHL_API void MouseMove(int mX, int mY, bool silent);
	LIBZHL_API void OnRender();
	
	bool autoShrinkText;
	bool ready;
	float ftl_blink;
	float ftl_blink_dx;
	float pullout;
	ShipManager *ship;
	GL_Primitive *baseImage;
	GL_Primitive *baseImageRed;
	GL_Primitive *pulloutBase;
	GL_Primitive *pulloutBaseRed;
	GL_Primitive *pilotOn;
	GL_Primitive *pilotOff1;
	GL_Primitive *pilotOff2;
	GL_Primitive *enginesOn;
	GL_Primitive *enginesOff1;
	GL_Primitive *enginesOff2;
	GL_Texture *FTL_loadingbars;
	GL_Texture *FTL_loadingbars_off;
	GL_Primitive *loadingBars;
	GL_Primitive *loadingBarsOff;
	int lastBarsWidth;
	WarningMessage *enginesDown;
	bool bOutOfFuel;
	bool bBossFight;
	bool bHoverRaw;
	bool bHoverPilot;
	bool bHoverEngine;
};

struct GameOver;

struct GameOver : FocusWindow
{
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void OpenText(const std::string &text);
	
	std::vector<TextButton*> buttons;
	GL_Primitive *box;
	int boxWidth;
	int command;
	std::vector<int> commands;
	bool bShowStats;
	Point position;
	std::string gameoverText;
	bool bVictory;
	float openedTimer;
	CreditScreen credits;
	bool bShowingCredits;
};

struct InputBox;

struct InputBox : FocusWindow
{
	LIBZHL_API void StartInput();
	LIBZHL_API void TextEvent(CEvent::TextEvent event);
	
	WindowFrame *textBox;
	std::string mainText;
	bool bDone;
	bool bInvertCaps;
	std::string inputText;
	std::vector<std::string> lastInputs;
	int lastInputIndex;
};

struct Location;

struct MenuScreen;

struct MenuScreen : FocusWindow
{
	LIBZHL_API void OnRender();
	LIBZHL_API void Open();
	LIBZHL_API void constructor();
	
	GL_Texture *mainImage;
	GL_Primitive *menuPrimitive;
	int menuWidth;
	std::vector<TextButton*> buttons;
	int command;
	std::vector<int> commands;
	Point position;
	ConfirmWindow confirmDialog;
	int tempCommand;
	GenericButton *saveQuit;
	bool bShowControls;
	Point statusPosition;
	GL_Texture *difficultyBox;
	int difficultyWidth;
	std::string difficultyLabel;
	std::string difficultyText;
	GL_Texture *dlcBox;
	int dlcWidth;
	std::string dlcLabel;
	std::string dlcText;
	GL_Texture *achBox;
	GL_Primitive *achBoxPrimitive;
	int achWidth;
	std::string achLabel;
	std::vector<ShipAchievementInfo> shipAchievements;
	int selectedAch;
	InfoBox info;
};

struct ResourceEvent;

struct ShipStatus;
struct WarningWithLines;

struct ShipStatus
{
	LIBZHL_API void OnInit(Point unk, float unk2);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void RenderEvadeOxygen(bool unk);
	LIBZHL_API void RenderHealth(bool unk);
	LIBZHL_API void RenderShields(bool renderText);
	
	Point location;
	float size;
	ShipManager *ship;
	CombatControl *combat;
	GL_Primitive *hullBox;
	GL_Primitive *hullBox_Red;
	GL_Primitive *shieldBox_On;
	GL_Primitive *shieldBox_Off;
	GL_Primitive *shieldBox_Red;
	GL_Primitive *shieldCircleCharged[4];
	GL_Primitive *shieldCircleUncharged[4];
	GL_Primitive *shieldCircleHacked[4];
	GL_Primitive *shieldCircleHackedCharged[4];
	GL_Primitive *energyShieldBox;
	GL_Primitive *energyShieldBar[5];
	GL_Texture *hullLabel;
	GL_Texture *hullLabel_Red;
	GL_Primitive *shieldBoxPurple;
	GL_Primitive *oxygenPurple;
	GL_Primitive *evadePurple;
	GL_Primitive *evadeOxygenBox;
	GL_Primitive *evadeOxygenBox_topRed;
	GL_Primitive *evadeOxygenBox_bottomRed;
	GL_Primitive *evadeOxygenBox_bothRed;
	GL_Primitive *fuelIcon;
	GL_Primitive *missilesIcon;
	GL_Primitive *dronesIcon;
	GL_Primitive *scrapIcon;
	GL_Primitive *fuelIcon_red;
	GL_Primitive *missilesIcon_red;
	GL_Primitive *dronesIcon_red;
	GL_Primitive *scrapIcon_red;
	GL_Primitive *healthMask;
	GL_Texture *healthMaskTexture;
	int lastHealth;
	Globals::Ellipse baseShield;
	int currentHover;
	Point evadeOxygenBoxLocation;
	int lastFuel;
	int lastDrones;
	int lastScrap;
	int lastMissiles;
	int lastHull;
	WarningWithLines *hullMessage;
	WarningMessage *shieldMessage;
	WarningMessage *oxygenMessage;
	WarningMessage *boardingMessage;
	std::vector<DamageMessage*> resourceMessages;
	AnimationTracker noMoneyTracker;
	AnimationTracker flashTracker;
	bool bBossFight;
	bool bEnemyShip;
	Point noShipShift;
	Point intruderShift;
	Point energyShieldPos;
	Point intruderPos;
};

struct SpaceStatus;

struct SpaceStatus
{
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnInit(SpaceManager *space, Point pos);
	LIBZHL_API void OnRender();
	LIBZHL_API void RenderWarningText(int effect, int textOffset);
	
	GL_Primitive *warningImages[10];
	WarningMessage *warningMessage;
	WarningMessage *incomingFire;
	Globals::Rect hitbox;
	Globals::Rect hitbox2;
	int currentEffect;
	int currentEffect2;
	SpaceManager *space;
	Point position;
	int touchedTooltip;
};

struct StarMap;
struct Store;

struct SystemControl;

struct SystemControl
{
	struct PowerBars
	{
		GL_Primitive *normal[30];
		GL_Primitive *tiny[30];
		GL_Primitive *empty[30];
		GL_Primitive *damaged[30];
	};
	
	LIBZHL_API void CreateSystemBoxes();
	LIBZHL_API static SystemControl::PowerBars *__stdcall GetPowerBars(int width, int height, int gap, bool useShieldGap);
	LIBZHL_API SystemBox *GetSystemBox(int systemId);
	LIBZHL_API void RenderPowerBar();
	
	ShipManager *shipManager;
	CombatControl *combatControl;
	std::vector<SystemBox*> sysBoxes;
	Globals::Rect SystemPower;
	bool bSystemPowerHover;
	Point position;
	Point systemPowerPosition;
	Point subSystemPosition;
	GL_Primitive *wiresImage;
	GL_Primitive *wiresMask;
	GL_Primitive *noButton;
	GL_Primitive *button;
	GL_Primitive *noButton_cap;
	GL_Primitive *button_cap;
	GL_Primitive *drone;
	GL_Primitive *drone3;
	GL_Primitive *drone2;
	GL_Primitive *sub_box;
	int sub_spacing;
	WarningMessage *notEnoughPower;
	AnimationTracker flashBatteryPower;
	AnimationTracker flashTracker;
};

struct TabbedWindow;

struct TabbedWindow : FocusWindow
{
	LIBZHL_API void Close();
	
	std::vector<Button*> buttons;
	std::vector<FocusWindow*> windows;
	std::vector<std::string> names;
	unsigned int currentTab;
	int buttonType;
	TextButton doneButton;
	Point move;
	bool bBlockClose;
	bool bTutorialMode;
	bool bWindowLock;
};

struct ReactorButton;

struct ReactorButton : Button
{
	LIBZHL_API void Accept();
	LIBZHL_API void OnClick();
	LIBZHL_API void OnRender();
	LIBZHL_API void OnRightClick();
	
	int tempUpgrade;
	ShipManager *ship;
	bool selected;
};

struct UpgradeBox;
struct Upgrades;

struct Upgrades : FocusWindow
{
	LIBZHL_API void ClearUpgradeBoxes();
	LIBZHL_API void Close();
	LIBZHL_API void ConfirmUpgrades();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void MouseRightClick(int mX, int mY);
	LIBZHL_API void OnInit(ShipManager *ship);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	
	GL_Texture *box;
	std::vector<UpgradeBox*> vUpgradeBoxes;
	ShipManager *shipManager;
	TextButton undoButton;
	ReactorButton reactorButton;
	InfoBox infoBox;
	Point infoBoxLoc;
	int systemCount;
	int forceSystemInfoWidth;
};

struct CommandGui
{
	LIBZHL_API void AddEnemyShip(CompleteShip *ship);
	LIBZHL_API void CheckGameover();
	LIBZHL_API Store *CreateNewStore(int sectorNumber);
	LIBZHL_API Point GetWorldCoordinates(Point point, bool fromTarget);
	LIBZHL_API bool IsGameOver();
	LIBZHL_API void KeyDown(SDLKey key, bool shiftHeld);
	LIBZHL_API void LButtonDown(int mX, int mY, bool shiftHeld);
	LIBZHL_API void LButtonUp(int mX, int mY, bool shiftHeld);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void NewLocation(const std::string &mainText, std::vector<ChoiceText> *choices, ResourceEvent &resources, bool testingEvents);
	LIBZHL_API void OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void RenderPlayerShip(Point &shipCenter, float jumpScale);
	LIBZHL_API void RenderStatic();
	LIBZHL_API void RunCommand(std::string &command);
	LIBZHL_API void Victory();
	LIBZHL_API void constructor();
	
	ShipStatus shipStatus;
	CrewControl crewControl;
	SystemControl sysControl;
	CombatControl combatControl;
	FTLButton ftlButton;
	SpaceStatus spaceStatus;
	StarMap *starMap;
	CompleteShip *shipComplete;
	std::vector<FocusWindow*> focusWindows;
	Point pauseTextLoc;
	GL_Primitive *pauseImage;
	GL_Primitive *pauseImage2;
	GL_Primitive *pauseImageAuto;
	GL_Primitive *pauseCrewImage;
	GL_Primitive *pauseDoorsImage;
	GL_Primitive *pauseHackingImage;
	GL_Primitive *pauseMindImage;
	GL_Primitive *pauseRoomImage;
	GL_Primitive *pauseTargetImage;
	GL_Primitive *pauseTargetBeamImage;
	GL_Primitive *pauseTeleportLeaveImage;
	GL_Primitive *pauseTeleportArriveImage;
	GL_Primitive *flareImage;
	Point shipPosition;
	std::string locationText;
	std::string loadEvent;
	int loadSector;
	ChoiceBox choiceBox;
	bool gameover;
	bool alreadyWon;
	bool outOfFuel;
	MenuScreen menuBox;
	GameOver gameOverScreen;
	OptionsScreen optionsBox;
	bool bPaused;
	bool bAutoPaused;
	bool menu_pause;
	bool event_pause;
	bool touch_pause;
	int touchPauseReason;
	InputBox inputBox;
	float fShakeTimer;
	TabbedWindow shipScreens;
	TabbedWindow storeScreens;
	Upgrades upgradeScreen;
	CrewManifest crewScreen;
	Equipment equipScreen;
	Location *newLocation;
	SpaceManager *space;
	Button upgradeButton;
	WarningMessage upgradeWarning;
	TextButton storeButton;
	Button optionsButton;
	const float pause_anim_time;
	float pause_animation;
	std::vector<Store*> storeTrash;
	TimerHelper flickerTimer;
	TimerHelper showTimer;
	bool bHideUI;
	CompleteShip *enemyShip;
	bool waitLocation;
	bool lastLocationWait;
	bool dangerLocation;
	std::vector<int> commandKey;
	bool jumpComplete;
	int mapId;
	ConfirmWindow leaveCrewDialog;
	bool secretSector;
	int activeTouch;
	bool activeTouchIsButton;
	bool activeTouchIsCrewBox;
	bool activeTouchIsShip;
	bool activeTouchIsNull;
	std::vector<int> extraTouches;
	bool bTutorialWasRunning;
	bool focusAteMouse;
	bool choiceBoxOpen;
	int systemDetailsWidth;
	ChoiceBox writeErrorDialog;
	bool suppressWriteError;
};

struct CrewBox
{
	CrewBox(Point pos_, CrewMember *crew_, int number_)
	{
		this->constructor(pos_, crew_, number_);
	}
	
	void DestroyCustom();
	
	~CrewBox()
	{
		// redefined to avoid double destroy
		DestroyCustom();
		CSurface::GL_DestroyPrimitive(boxBackground);
		CSurface::GL_DestroyPrimitive(boxOutline);
		CSurface::GL_DestroyPrimitive(skillBoxBackground);
		CSurface::GL_DestroyPrimitive(skillBoxOutline);
		CSurface::GL_DestroyPrimitive(cooldownBar);
		CSurface::GL_DestroyPrimitive(healthBar);
	}

	LIBZHL_API CrewMember *GetSelected(int mouseX, int mouseY);
	LIBZHL_API bool MouseClick();
	LIBZHL_API void OnLoop(bool selected);
	LIBZHL_API void OnRender();
	LIBZHL_API void OnRenderSkillLevel();
	LIBZHL_API void RenderCloneDying();
	LIBZHL_API void RenderIcon();
	LIBZHL_API void RenderLabels();
	LIBZHL_API void constructor(Point pos, CrewMember *crew, int number);
	LIBZHL_API void destructor();
	
	Globals::Rect box;
	Globals::Rect skillBox;
	CrewMember *pCrew;
	bool mouseHover;
	uint8_t gap_ex_1[2];
	TextButton powerButton;
	int number;
	bool bSelectable;
	uint8_t gap_ex_2[2];
	AnimationTracker flashHealthTracker;
	GL_Primitive *boxBackground;
	GL_Primitive *boxOutline;
	GL_Primitive *skillBoxBackground;
	GL_Primitive *skillBoxOutline;
	GL_Primitive *cooldownBar;
	CachedImage healthWarning;
	int lastCooldownHeight;
	GL_Primitive *healthBar;
	int lastHealthWidth;
	Animation mindControlled;
	Animation stunned;
	bool hideExtra;
	std::string sTooltip;
};

struct CrewEquipBox : EquipmentBox
{
	CrewEquipBox(Point pos_, ShipManager *ship_, int slot_)
	{
		this->constructor(pos_, ship_, slot_);
	}

	LIBZHL_API void CloseRename();
	LIBZHL_API bool GetConfirmDelete();
	LIBZHL_API void MouseClick();
	LIBZHL_API void OnRender(bool unk);
	LIBZHL_API void OnTextEvent(CEvent::TextEvent event);
	LIBZHL_API void OnTextInput(SDLKey key);
	LIBZHL_API void RemoveItem();
	LIBZHL_API void RenderLabels(bool dragging, bool isNew);
	LIBZHL_API void constructor(Point pos, ShipManager *ship, int slot);
	
	ShipManager *ship;
	bool bDead;
	TextButton deleteButton;
	TextButton renameButton;
	bool bShowDelete;
	bool bShowRename;
	bool bQuickRenaming;
	TextInput nameInput;
	GL_Primitive *box;
	GL_Primitive *box_on;
	bool bConfirmDelete;
};

struct CrewCustomizeBox : CrewEquipBox
{
	LIBZHL_API void CheckContents();
	
	TextButton customizeButton;
	bool bCustomizing;
	Point customizeLocation;
	TextButton acceptButton;
	TextButton bigRenameButton;
	Button leftButton;
	Button rightButton;
	bool bRenaming;
	bool haveCustomizeTouch;
	bool customizeActivated;
	GL_Primitive *box;
	GL_Primitive *box_on;
	GL_Texture *bigBox;
};

struct CrewDesc
{
	std::string type;
	float prop;
	int amount;
};

struct BattleDrone;
struct CrewMemberFactory;
struct RepairDrone;

struct CrewMemberFactory
{
	void SwapCrewMembers(CrewMember *_first, CrewMember *_second);
	void MoveCrewMemberToEnd(CrewMember *crew);
	void MoveCrewMemberBefore(CrewMember *crew, CrewMember *other);
	void MoveCrewMemberAfter(CrewMember *crew, CrewMember *other);
	void MoveCrewMemberToSpot(CrewMember *crew, CrewMember *other);
	
	float GetCrewCapacityUsed();

	LIBZHL_API int CountCloneReadyCrew(bool player);
	LIBZHL_API BattleDrone *CreateBattleDrone(int shipId, const DroneBlueprint *bp);
	LIBZHL_API BoarderDrone *CreateBoarderDrone(int shipId, const DroneBlueprint *bp);
	LIBZHL_API CrewMember *CreateCrewMember(CrewBlueprint *bp, int shipId, bool intruder);
	LIBZHL_API RepairDrone *CreateRepairDrone(int shipId, const DroneBlueprint *bp);
	LIBZHL_API void GetCloneReadyList(std::vector<CrewMember*> &vec, bool player);
	LIBZHL_API int GetCrewCount(bool enemy);
	LIBZHL_API void GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2);
	LIBZHL_API std::vector<std::string> GetCrewNames();
	LIBZHL_API void GetCrewPortraitList(std::vector<CrewMember*> *vec, int teamId);
	LIBZHL_API int GetEnemyCloneCount();
	LIBZHL_API int GetEnemyCrewCount();
	LIBZHL_API int GetPlayerCrewCount();
	LIBZHL_API std::pair<std::string, bool> GetRandomFriendlyName(const std::string &race);
	LIBZHL_API static bool __stdcall IsRace(const std::string &species);
	LIBZHL_API void OnLoop();
	LIBZHL_API void RemoveExcessCrew();
	LIBZHL_API void Restart();
	LIBZHL_API void destructor();
	
	int playerCrew;
	int enemyCrew;
	int enemyCloneCount;
	std::vector<CrewMember*> crewMembers;
	std::vector<CrewMember*> lostMembers;
};

struct CrewStatTracker
{
	int max;
	std::string name;
	std::string species;
	bool male;
	std::string title_id;
	bool newStat;
};

struct CrewStoreBox;

struct CrewStoreBox : StoreBox
{
	CrewStoreBox(ShipManager *_ship, int _worldLevel, const std::string& _type)
	{
		this->constructor(_ship, _worldLevel, _type);
	}
	
	CrewStoreBox()
	{
		StoreBox::constructor("storeUI/store_buy_crew", nullptr, nullptr);
	}

	LIBZHL_API bool CanHold();
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void Purchase();
	LIBZHL_API void constructor(ShipManager *ship, int worldLevel, const std::string &type);
	
	std::string name;
	Animation crewPortrait;
	CrewBlueprint blueprint;
};

struct LIBZHL_INTERFACE CrewTarget
{
	ShipObject* GetShipObject()
	{
		return (ShipObject*)(this);
	}

	virtual ~CrewTarget() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	int iShipId;
};

struct CrystalAlien : CrewMember
{
	std::pair<float, float> powerCooldown;
};

struct CrystalAnimation
{
};

struct DamageMessage
{

	enum MessageType
	{
	  MISS = 0x0,
	  RESIST = 0x1,
	};

	DamageMessage(float length, Pointf pos, MessageType type)
	{
		constructor(length, pos, type);
	}
	
	DamageMessage(float length, int amount, Pointf pos, bool unk)
	{
		constructor2(length, amount, pos, unk);
	}

	LIBZHL_API void constructor(float length, Pointf pos, DamageMessage::MessageType type);
	LIBZHL_API void constructor2(float length, int amount, Pointf pos, bool unk);
	
	AnimationTracker tracker;
	Pointf position;
	GL_Color color;
	bool bFloatDown;
	std::vector<GL_Primitive*> primitives;
};

struct DebugHelper
{
};

struct DefenseDrone;

struct DefenseDrone : SpaceDrone
{
	LIBZHL_API std::string GetTooltip();
	LIBZHL_API void OnLoop();
	LIBZHL_API void PickTarget();
	LIBZHL_API void SetWeaponTarget(Targetable *target);
	LIBZHL_API bool ValidTargetObject(Targetable *target);
	
	int currentTargetId;
	int shotAtTargetId;
	float currentSpeed;
	CachedImage drone_image;
	CachedImage gun_image_off;
	CachedImage gun_image_charging;
	CachedImage gun_image_on;
	CachedImage engine_image;
	int currentTargetType;
};

struct DistressButton : TextButton
{
	TextString labels[2];
	bool state;
};

struct Selectable
{
	void *vptr;
	int selectedState;
};

struct Room;

struct Room : Selectable
{
	Point GetIntoRoom(Point pos)
	{
		int posX = pos.x;
		int posY = pos.y;
		
		int rectY = this->rect.y;
		int rectH = this->rect.h;
		
		int rectX = this->rect.x;
		int rectW = this->rect.w;
		
		//printf("%d %d %d %d %d %d\n", posX, posY, rectX, rectW, rectY, rectH);
		
		if (rectY + rectH - posY > 15 && posY - rectY > 15)
		{
			if (rectW + rectX - posX > 15 && posX - rectX > 15)
			{
				return Point(-1, -1);
			}
		}
		
		
		
		
		Point center = Point(rectX + rectW / 2, rectY + rectH / 2);
		
		Point toGrid = Point((posX + 2 * (center.x > posX) - 1) / 35, (posY + 2 * (center.y > posY) - 1) / 35);
		Point fromGrid = Point(toGrid.x * 35, toGrid.y * 35);
		
		return Point(fromGrid.x + 17, fromGrid.y + 17);
	}

	Globals::Rect GetRect() 
	{
		return this->rect;
	}

	LIBZHL_API void FillSlot(int slot, bool intruder);
	LIBZHL_API bool Full(bool intruder);
	LIBZHL_API int GetEmptySlot(bool intruder);
	LIBZHL_API int GetEmptySlots(bool intruder);
	LIBZHL_API void OnRenderFloor(float alpha, bool experimental);
	LIBZHL_API void OnRenderWalls(float alpha);
	LIBZHL_API void constructor(int iShipId, int x, int y, int w, int h, int roomId);
	LIBZHL_API void destructor();
	
	ShipObject _shipObject;
	Globals::Rect rect;
	int iRoomId;
	bool bBlackedOut;
	uint8_t gap_ex_1[2];
	std::vector<int> filledSlots;
	std::vector<std::vector<bool>> slots;
	bool bWarningLight;
	uint8_t gap_ex_2[2];
	AnimationTracker lightTracker;
	int iFireCount;
	std::vector<Animation> fires;
	int primarySlot;
	int primaryDirection;
	float lastO2;
	GL_Primitive *floorPrimitive;
	GL_Primitive *blackoutPrimitive;
	GL_Primitive *highlightPrimitive;
	GL_Primitive *highlightPrimitive2;
	GL_Primitive *o2LowPrimitive;
	GL_Primitive *computerPrimitive;
	GL_Primitive *computerGlowPrimitive;
	GL_Primitive *computerGlowYellowPrimitive;
	GL_Primitive *lightPrimitive;
	GL_Primitive *lightGlowPrimitive;
	Animation stunSparks;
	Animation consoleSparks;
	bool bStunning;
	float fHacked;
	int currentSparkRotation;
	std::vector<Animation> sparks;
	float sparkTimer;
	int sparkCount;
	int iHackLevel;
	Animation roomTapped;
};

struct ShipGraph;

struct ShipGraph
{
    // TODO: This looks like it was re-implemented because they were unsure at the time how to hook it, we can totally hook it now like we do for GetSlotRenderPosition
	static Point TranslateFromGrid(int xx, int yy)
	{
		return Point(xx * 35, yy * 35);
	}
	
	// TODO: This looks like it was re-implemented because they were unsure at the time how to hook it, we can totally hook it now like we do for GetSlotRenderPosition
	static Point TranslateToGrid(int xx, int yy)
	{
		return Point(xx / 35, yy / 35);
	}
	
	// TODO: This looks like it was re-implemented because they were unsure at the time how to hook it, we can totally hook it now like we do for GetSlotRenderPosition
	Point GetIntoRoom(int roomId, Point pos)
	{
		Point ret;
		if (roomId >= 0 && roomId < this->rooms.size())
		{
			auto room = this->rooms[roomId];
			ret = room->GetIntoRoom(pos);
		}
		else
		{
			ret = Point(-1, -1);
		}
		
		return ret;
	}
	
	// TODO: This looks like it was re-implemented because they were unsure at the time how to hook it, we can totally hook it now like we do for GetSlotRenderPosition
	Pointf GetRoomCenter(int roomId) 
	{
		auto rooms = this->rooms;
		float xx = -1;
		float yy = -1;
		
		for (auto const& x: rooms)
		{
			if (roomId == x->iRoomId)
			{
				auto rect = x->GetRect();
				
				xx = rect.x + rect.w / 2;
				yy = rect.y + rect.h / 2;
				break;
			}
		}
		
		return Pointf(xx, yy);
	}
	

	LIBZHL_API void ComputeCenter();
	LIBZHL_API int ConnectedGridSquares(int x1, int y1, int x2, int y2);
	LIBZHL_API int ConnectedGridSquaresPoint(Point p1, Point p2);
	LIBZHL_API Door *ConnectingDoor(int x1, int y1, int x2, int y2);
	LIBZHL_API Door *ConnectingDoor(Point p1, Point p2);
	LIBZHL_API bool ContainsPoint(int x, int y);
	LIBZHL_API float ConvertToLocalAngle(float ang);
	LIBZHL_API Pointf ConvertToLocalPosition(Pointf world, bool past);
	LIBZHL_API float ConvertToWorldAngle(float ang);
	LIBZHL_API Pointf ConvertToWorldPosition(Pointf local);
	LIBZHL_API Path Dijkstra(Point start, Point goal, int shipId);
	LIBZHL_API int DoorCount(int roomId);
	LIBZHL_API Path FindPath(Point p1, Point p2, int shipId);
	LIBZHL_API Slot GetClosestSlot(Point pos, int shipId, bool intruder);
	LIBZHL_API std::vector<Door*> GetDoors(int roomId);
	LIBZHL_API int GetNumSlots(int room);
	LIBZHL_API bool GetRoomBlackedOut(int room);
	LIBZHL_API float GetRoomOxygen(int room);
	LIBZHL_API Globals::Rect GetRoomShape(int room);
	LIBZHL_API int GetSelectedRoom(int x, int y, bool unk);
	LIBZHL_API static ShipGraph *__stdcall GetShipInfo(int shipId);
	LIBZHL_API Point GetSlotRenderPosition(int slotId, int roomId, bool intruder);
	LIBZHL_API Point GetSlotWorldPosition(int slotId, int roomId);
	LIBZHL_API bool IsRoomConnected(int room1, int room2);
	LIBZHL_API int PopClosestDoor(std::vector<int> &doors, std::vector<float> &distances);
	LIBZHL_API int RoomCount();
	
	std::vector<Room*> rooms;
	std::vector<Door*> doors;
	std::vector<int> doorCounts;
	Point center;
	Pointf worldPosition;
	float worldHeading;
	Pointf lastWorldPosition;
	float lastWorldHeading;
	Globals::Rect shipBox;
	std::string shipName;
};

struct Door : CrewTarget
{
public:
	Point GetCenterPoint()
	{
		Point ret = Point(this->x, this->y);
		return ret;
	}
	Point GetEntryWay(int room)
	{
		Point pos1 = Point(this->x, this->y);
		Point pos2;

		if (this->bVertical)
		{
			pos2 = Point(pos1.x + 17, pos1.y);
			pos1 = Point(this->x - 17, pos1.y);
		}
		else
		{
			pos2 = Point(this->x, pos1.y + 17);
			pos1 = Point(this->x, this->y - 18);
		}

		auto shipInfo = ShipGraph::GetShipInfo(this->iShipId);

		if (room == shipInfo->GetSelectedRoom(pos2.x, pos2.y, false))
		{
			return pos2;
		}
		else
		{
			return pos1;
		}
	}

	LIBZHL_API bool ApplyDamage(float amount);
	LIBZHL_API void FakeClose();
	LIBZHL_API void FakeOpen();
	LIBZHL_API Point GetPosition();
	LIBZHL_API bool IsSealed(int shipId);
	LIBZHL_API void OnLoop();
	
	Selectable _selectable;
	int iRoom1;
	int iRoom2;
	bool bOpen;
	int iBlast;
	bool bFakeOpen;
	int width;
	int height;
	GL_Primitive *outlinePrimitive;
	GL_Primitive *highlightPrimitive;
	Animation doorAnim;
	Animation doorAnimLarge;
	int iDoorId;
	int baseHealth;
	int health;
	AnimationTracker forcedOpen;
	AnimationTracker gotHit;
	int doorLevel;
	bool bIoned;
	float fakeOpenTimer;
	AnimationTracker lockedDown;
	float lastbase;
	int iHacked;
	int x;
	int y;
	bool bVertical;
};

struct DoorBox;

struct DoorBox : SystemBox
{
	DoorBox(Point pos, ShipSystem* sys, ShipManager *ship)
	{
		this->constructor(pos, sys, ship);
	}

	LIBZHL_API void constructor(Point pos, ShipSystem *sys, ShipManager *ship);
	
	GL_Texture *box;
	Button openDoors;
	Button closeDoors;
	ShipManager *ship;
	Point buttonOffset;
};

struct DroneBox
{
};

struct DroneEquipBox : EquipmentBox
{
};

struct DroneStoreBox;

struct DroneStoreBox : StoreBox
{
	DroneStoreBox(ShipManager *_ship, Equipment *_equip, const DroneBlueprint* _bp)
	{
		this->constructor(_ship, _equip, _bp);
	}
	
	DroneStoreBox()
	{
		StoreBox::constructor("storeUI/store_buy_drones", nullptr, nullptr);
		this->bEquipmentBox = true;
	}

	LIBZHL_API void constructor(ShipManager *ship, Equipment *equip, const DroneBlueprint *bp);
	
	DroneBlueprint *blueprint;
};

struct DroneSystem : ShipSystem
{
	LIBZHL_API bool DePowerDrone(Drone *drone, bool unk);
	LIBZHL_API void OnLoop();
	LIBZHL_API void RemoveDrone(int slot);
	LIBZHL_API virtual void SetBonusPower(int amount, int permanentPower);
	LIBZHL_API static int __stdcall StringToDrone(std::string &name);
	LIBZHL_API void UpdateBonusPower();
	
	std::vector<Drone*> drones;
	int drone_count;
	int drone_start;
	Targetable *targetShip;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct EnergyAlien;

struct LIBZHL_INTERFACE EnergyAlien
{
	virtual ~EnergyAlien() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	virtual void Jump() LIBZHL_PLACEHOLDER
	virtual bool GetIntruder() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fileHelper) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnLoop();
	virtual void OnRender(bool unk) LIBZHL_PLACEHOLDER
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	virtual void SetOutOfGame() LIBZHL_PLACEHOLDER
	virtual bool Functional() LIBZHL_PLACEHOLDER
	virtual bool CountForVictory() LIBZHL_PLACEHOLDER
	virtual bool GetControllable() LIBZHL_PLACEHOLDER
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	virtual bool CanRepair() LIBZHL_PLACEHOLDER
	virtual bool CanSabotage() LIBZHL_PLACEHOLDER
	virtual bool CanMan() LIBZHL_PLACEHOLDER
	virtual bool CanTeleport() LIBZHL_PLACEHOLDER
	virtual bool CanHeal() LIBZHL_PLACEHOLDER
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	virtual bool ShipDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	virtual std::string GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string GetSpecies() LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual Damage GetRoomDamage();
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	virtual void UpdateRepair() LIBZHL_PLACEHOLDER
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	
	int iShipId;
	float x;
	float y;
	float size;
	float scale;
	float goal_x;
	float goal_y;
	int width;
	int height;
	std::pair<float, float> health;
	float speed_x;
	float speed_y;
	Path path;
	bool new_path;
	float x_destination;
	float y_destination;
	Door *last_door;
	Repairable *currentRepair;
	bool bSuffocating;
	int moveGoal;
	int selectionState;
	int iRoomId;
	int iManningId;
	int iRepairId;
	int iStackId;
	Slot currentSlot;
	bool intruder;
	bool bFighting;
	bool bSharedSpot;
	CrewAnimation *crewAnim;
	GL_Texture *selectionImage;
	CachedImage healthBox;
	CachedImage healthBoxRed;
	CachedRect healthBar;
	float fMedbay;
	float lastDamageTimer;
	float lastHealthChange;
	int currentShipId;
	AnimationTracker flashHealthTracker;
	Pointf currentTarget;
	CrewTarget *crewTarget;
	BoardingGoal boardingGoal;
	bool bFrozen;
	bool bFrozenLocation;
	CrewTask task;
	std::string type;
	Ship *ship;
	Slot finalGoal;
	Door *blockingDoor;
	bool bOutOfGame;
	std::string species;
	bool bDead;
	uint8_t gap_ex_1[2];
	int iOnFire;
	bool bActiveManning;
	ShipSystem *currentSystem;
	int usingSkill;
	CrewBlueprint blueprint;
	Animation healing;
	Animation stunned;
	AnimationTracker levelUp;
	int lastLevelUp;
	SCrewStats stats;
	std::vector<std::vector<bool>> skillsEarned;
	bool clone_ready;
	bool bMindControlled;
	int iDeathNumber;
	Animation mindControlled;
	Animation stunIcon;
	std::vector<std::vector<AnimationTracker>> skillUp;
	int healthBoost;
	float fMindDamageBoost;
	float fCloneDying;
	bool bResisted;
	uint8_t gap_ex_2[2];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
	bool bTriggerExplosion;
	bool bExploded;
};

struct EnergyAnimation
{
};

struct EngiAlien
{
};

struct EngiAnimation
{
};

struct EngineSystem
{
};

struct EventDamage
{
	int system;
	int amount;
	int effect;
};

struct EventGenerator;
struct EventTemplate;

struct EventText
{
	TextString text;
	std::string planet;
	std::string back;
};

struct ShipEvent;

struct ShipEvent
{
	LIBZHL_API void constructor(const ShipEvent &event);
	
	bool present;
	std::string name;
	std::string blueprint;
	std::string auto_blueprint;
	std::vector<std::string> blueprintList;
	ShipBlueprint actualBlueprint;
	bool hostile;
	std::string surrender;
	std::string escape;
	std::string destroyed;
	std::string deadCrew;
	std::string gotaway;
	int escapeTimer;
	RandomAmount surrenderThreshold;
	RandomAmount escapeThreshold;
	std::vector<CrewDesc> crewOverride;
	std::vector<std::string> weaponOverride;
	int weaponOverCount;
	std::vector<std::string> droneOverride;
	int droneOverCount;
	int shipSeed;
};

struct StatusEffect
{
	LIBZHL_API static StatusEffect __stdcall GetNebulaEffect();
	
	int type;
	int system;
	int amount;
	int target;
};

struct LocationEvent
{
	LocationEvent()
	{
		this->constructor();
	}

	struct Choice
	{
		LocationEvent *event;
		TextString text;
		ChoiceReq requirement;
		bool hiddenReward;
	};
	
	LIBZHL_API void ClearEvent(bool force);
	LIBZHL_API void constructor();
	
	TextString text;
	ShipEvent ship;
	ResourceEvent stuff;
	int environment;
	int environmentTarget;
	bool store;
	bool gap_ex_cleared;
	int fleetPosition;
	bool beacon;
	bool reveal_map;
	bool distressBeacon;
	bool repair;
	int modifyPursuit;
	Store *pStore;
	std::vector<EventDamage> damage;
	std::string quest;
	std::vector<StatusEffect> statusEffects;
	std::vector<std_pair_std_string_std_string> nameDefinitions;
	std::string spaceImage;
	std::string planetImage;
	std::string eventName;
	ResourceEvent reward;
	BoardingEvent boarders;
	std::vector<Choice> choices;
	int unlockShip;
	TextString unlockShipText;
	bool secretSector;
};

struct Sector;

struct SectorDescription
{
	std::vector<std_pair_std_string_RandomAmount> eventCounts;
	std::vector<std_pair_std_string_int> rarities;
	bool unique;
	std::vector<TextString> names;
	std::vector<TextString> shortNames;
	std::vector<std::string> musicTracks;
	std::string type;
	TextString name;
	TextString shortName;
	int minSector;
	bool used;
	std::string firstEvent;
};

struct Sector
{
	int type;
	bool visited;
	bool reachable;
	std::vector<Sector*> neighbors;
	Point location;
	int level;
	SectorDescription description;
};

struct EventGenerator
{
    SectorDescription GetSectorDescriptionCustom(const std::string& type, int level);

	void ClearUsedEvent(const std::string& name)
	{
		auto it = usedEvents.find(name);
		if (it != usedEvents.end())
		{
			events[name] = it->second;
			usedEvents.erase(it);
		}
	}
	
	void ClearUsedEvent(LocationEvent *locEvent)
	{
		if (locEvent)
		{
			ClearUsedEvent(locEvent->eventName);
			for (auto& choice : locEvent->choices)
			{
				ClearUsedEvent(choice.event);
			}
		}
	}

	LIBZHL_API LocationEvent *CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique);
	LIBZHL_API LocationEvent *GetBaseEvent(const std::string &name, int worldLevel, char ignoreUnique, int seed);
	LIBZHL_API std::string GetImageFromList(const std::string &listName);
	LIBZHL_API SectorDescription GetSectorDescription(const std::string &type, int level);
	LIBZHL_API ShipEvent GetShipEvent(const std::string &event);
	LIBZHL_API SectorDescription GetSpecificSector(const std::string &name);
	
	std::vector<std::string> baseEvents;
	std::unordered_map<std::string, SectorDescription> sectors;
	std::unordered_map<std::string, std::vector<std::string>> baseSectors;
	std::unordered_map<std::string, std::vector<std::string>> eventLists;
	std::unordered_map<std::string, EventTemplate*> events;
	std::unordered_map<std::string, EventTemplate*> usedEvents;
	std::unordered_map<std::string, std::vector<EventText>> textLists;
	std::unordered_map<std::string, std::vector<EventText>> usedTextLists;
	std::unordered_map<std::string, std::vector<std::string>> shipTemplateLists;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
	std::unordered_map<std::string, std::vector<std::string>> imageLists;
	std::vector<LocationEvent*> trashList;
	std::unordered_map<std::string, ResourceEvent> resourcesCollected;
	std::unordered_map<std::string, int> eventTypesCreated;
	int shipsCreated;
	bool shiplessEvent;
	bool creatingShipEvent;
	int forceRandomIndex;
};

struct EventSystem;

struct EventSystem
{
	LIBZHL_API void AddEvent(int id);
	LIBZHL_API bool PollEvent(int id);
	
	std::vector<int> lastEvents;
	std::vector<int> newEvents;
};

struct ResourcesTemplate
{
	RandomAmount fuel;
	RandomAmount drones;
	RandomAmount missiles;
	RandomAmount scrap;
	RandomAmount items;
	int crew;
	std::string crewType;
	TextString crewName;
	bool cloneable;
	TextString cloneText;
	std::vector<std_pair_int_int> crewSkills;
	std::string weapon;
	std::string drone;
	std::string augment;
	std::string system;
	bool steal;
	int upgradeAmount;
	int upgradeId;
	std::string removeItem;
};

struct RewardDesc
{
	std::string reward;
	int level;
};

struct ShipTemplate
{
	std::string shipEventName;
	bool hostile;
};

struct EventTemplate
{
	struct ChoiceTemplate
	{
		TextString text;
		bool loadText;
		std::string eventName;
		bool hiddenReward;
		ChoiceReq requirement;
	};
	
	ResourcesTemplate resources;
	RewardDesc reward;
	TextString text;
	bool loadText;
	bool unique;
	ShipTemplate shipTemplate;
	std::string eventName;
	std::vector<EventDamage> damage;
	int environmentFlag;
	int environmentTarget;
	bool store;
	bool repair;
	bool reveal_map;
	std::vector<StatusEffect> statusEffects;
	bool distressBeacon;
	BoardingEvent boarders;
	int modifyPursuit;
	std::vector<ChoiceTemplate> choices;
	std::vector<std_pair_std_string_std_string> nameDefinitions;
	std::string imageBackground;
	std::string imagePlanet;
	std::string quest;
	TextString unlockShipText;
	int unlockShip;
	int fleet;
	bool secretSector;
};

struct EventsParser;

struct EventsParser
{
	static bool ParseBoolean(const std::string& str)
	{
		return str == "true" || str == "TRUE" || str == "True";
	}

	LIBZHL_API void AddAllEvents();
	LIBZHL_API void AddEvents(EventGenerator &generator, char *file, const std::string &fileName);
	LIBZHL_API void ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator);
	LIBZHL_API std::string ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName);
	LIBZHL_API std::vector<std::string> ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName);
	LIBZHL_API ResourcesTemplate ProcessModifyItem(ResourcesTemplate &resources, rapidxml::xml_node<char> *node, const std::string &unk);
	LIBZHL_API ShipTemplate ProcessShipEvent(rapidxml::xml_node<char> *node);
	LIBZHL_API RandomAmount PullMinMax(rapidxml::xml_node<char> *node, const std::string &name);
	
	std::unordered_map<std::string, EventTemplate*> eventTemplates;
	std::vector<EventTemplate*> trashList;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
};

struct ExplosionAnimation;

struct GL_Texture
{
	int id_;
	int width_;
	int height_;
	bool isLogical_;
	float u_base_;
	float v_base_;
	float u_size_;
	float v_size_;
};

struct ExplosionAnimation : AnimationTracker
{
	LIBZHL_API void OnInit(rapidxml::xml_node<char> *node, const std::string &name, Point glowOffset);
	
	ShipObject shipObj;
	std::vector<Animation> explosions;
	std::vector<GL_Texture> pieces;
	std::vector<std::string> pieceNames;
	std::vector<float> rotationSpeed;
	std::vector<float> rotation;
	std::vector<std_pair_float_float> rotationSpeedMinMax;
	std::vector<Pointf> movementVector;
	std::vector<Pointf> position;
	std::vector<Pointf> startingPosition;
	float explosionTimer;
	float soundTimer;
	bool bFinalBoom;
	bool bJumpOut;
	std::vector<WeaponAnimation> weaponAnims;
	Point pos;
};

struct FileHelper
{
	static int fileLength(int fd)
	{
        FILE* fp = fdopen(dup(fd), "r"); // Duplicate file descriptor & then open the stream so that we can fclose correctly later on
        rewind(fp); // TODO: Not sure if we have to rewind before but could it hurt?
        fseek(fp, 0, SEEK_END);
        int lengthOfFile = ftell(fp);
        rewind(fp); // Rewind since the file index is shared and lets not screw with other people using the file descriptor that was opened by `open` in FTL's code
        fclose(fp);
        return lengthOfFile;
	}

	LIBZHL_API static void __stdcall closeBinaryFile(int file);
	LIBZHL_API static int __stdcall createBinaryFile(const std::string &fileName);
	LIBZHL_API static int __stdcall createSaveFile();
	LIBZHL_API static int __stdcall createStatsFile();
	LIBZHL_API static void __stdcall deleteAllSaveFiles();
	LIBZHL_API static void __stdcall deleteFile(const std::string &fileName);
	LIBZHL_API static void __stdcall deleteSaveFile();
	LIBZHL_API static bool __stdcall fileExists(const std::string &fileName);
	LIBZHL_API static int __stdcall getPosition(int file);
	LIBZHL_API static std::string __stdcall getResourceFile();
	LIBZHL_API static std::string __stdcall getSaveFile();
	LIBZHL_API static std::string __stdcall getUserFolder();
	LIBZHL_API static void __stdcall initFileHelper();
	LIBZHL_API static int __stdcall readBinaryFile(const std::string &fileName);
	LIBZHL_API static char *__stdcall readBuffer(int file, int len, bool nullTerminate);
	LIBZHL_API static void __stdcall readData(int file, void *data, int len);
	LIBZHL_API static float __stdcall readFloat(int file);
	LIBZHL_API static int __stdcall readInteger(int file);
	LIBZHL_API static int __stdcall readSaveFile();
	LIBZHL_API static int __stdcall readStatsFile();
	LIBZHL_API static std::string __stdcall readString(int file);
	LIBZHL_API static void __stdcall renameFile(const std::string &fileName, const std::string &newName);
	LIBZHL_API static bool __stdcall saveFileExists();
	LIBZHL_API static bool __stdcall seekPosition(int file, int pos);
	LIBZHL_API static bool __stdcall writeData(int file, void *data, int len);
	LIBZHL_API static bool __stdcall writeFloat(int file, float data);
	LIBZHL_API static bool __stdcall writeInt(int file, int data);
	LIBZHL_API static bool __stdcall writeString(int file, const std::string &data);
	
};

struct Fire;

struct Repairable : Selectable
{
	ShipObject shipObj;
	float fDamage;
	Point pLoc;
	float fMaxDamage;
	std::string name;
	int roomId;
	int iRepairCount;
};

struct Spreadable : Repairable
{
	std::string soundName;
};

struct Fire : Spreadable
{
	LIBZHL_API void OnLoop();
	LIBZHL_API void UpdateDeathTimer(int connectedFires);
	LIBZHL_API void UpdateStartTimer(int doorLevel);
	
	float fDeathTimer;
	float fStartTimer;
	float fOxygen;
	Animation fireAnimation;
	Animation smokeAnimation;
	bool bWasOnFire;
};

struct GL_FrameBuffer
{
};

struct GL_Primitive
{
	int type;
	float lineWidth;
	bool hasTexture;
	GL_Texture *texture;
	bool textureAntialias;
	bool hasColor;
	GL_Color color;
	int id;
};

struct Ghost
{
};

struct HackBox;
struct HackingSystem;

struct HackBox : CooldownSystemBox
{
	HackBox(Point pos, HackingSystem* sys, ShipManager *ship)
	{
		this->constructor(pos, sys, ship);
	}

	LIBZHL_API void constructor(Point pos, HackingSystem *sys, ShipManager *ship);
	
	HackingSystem *hackSys;
	std::vector<Button*> buttons;
	Button *currentButton;
	Point buttonOffset;
	GL_Texture *box;
	GL_Texture *box2;
	Button hackButton;
	Button overlayButton;
	ShipManager *shipManager;
	AnimationTracker flashTracker;
	WarningMessage *superShieldWarning;
};

struct HackingDrone;

struct HackingDrone : SpaceDrone
{
	LIBZHL_API CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace);
	LIBZHL_API void OnLoop();
	LIBZHL_API void SetMovementTarget(Targetable *target);
	
	Pointf startingPosition;
	GL_Texture *droneImage_on;
	GL_Texture *droneImage_off;
	GL_Texture *lightImage;
	Pointf finalDestination;
	bool arrived;
	bool finishedSetup;
	AnimationTracker flashTracker;
	Animation flying;
	Animation extending;
	Animation explosion;
	int prefRoom;
};

struct HackingSystem : ShipSystem
{
	LIBZHL_API void BlowHackingDrone();
	LIBZHL_API void OnLoop();
	LIBZHL_API bool SoundLoop();
	
	bool bHacking;
	HackingDrone drone;
	bool bBlocked;
	bool bArmed;
	ShipSystem *currentSystem;
	std::pair<float, float> effectTimer;
	bool bCanHack;
	ShipSystem *queuedSystem;
	int spendDrone;
};

struct HotkeyDesc
{
	std::string name;
	int key;
};

struct ImageDesc
{
	GL_Texture *tex;
	int resId;
	int w;
	int h;
	int x;
	int y;
	int rot;
};

struct InputEventUnion
{
	char eventData[20];
};

struct InputEvent
{
	InputEventType type;
	InputEventDetail detail;
	double timestamp;
	InputEventUnion event;
};

struct IonDrone;

struct IonDrone : BoarderDrone
{
	LIBZHL_API Damage GetRoomDamage();
	
	int lastRoom;
};

struct IonDroneAnimation;

struct IonDroneAnimation : CrewAnimation
{
	IonDroneAnimation(int _shipId, Pointf _position, bool _hostile)
	{
		this->constructor(_shipId, _position, _hostile);
	}

	LIBZHL_API void constructor(int iShipId, Pointf position, bool enemy);
	
	Animation ionExplosion;
	Animation ionAnimation;
	Animation doorAnimations[4];
	Animation ionGlow;
	float ionEffect;
	bool damagedDoor;
};

struct ItemStoreBox;

struct ItemStoreBox : StoreBox
{
	ItemStoreBox(ShipManager *_ship, const std::string& _resourceName)
	{
		this->constructor(_ship, _resourceName);
	}

	LIBZHL_API void constructor(ShipManager *ship, const std::string &resourceName);
	
	ItemBlueprint *blueprint;
};

struct JoystickInputEvent
{
	int device;
	int index;
	float x;
	float y;
};

struct KeyboardInputEvent
{
	int key;
	int system_key;
	unsigned int modifiers;
	char is_repeat;
};

struct LaserBlast;

struct LaserBlast : Projectile
{
	LaserBlast(Pointf _position, int _ownerId, int _targetId, Pointf _target);

	LIBZHL_API void OnInit();
	LIBZHL_API void OnUpdate();
	
	Targetable *movingTarget;
	float spinAngle;
	float spinSpeed;
};

struct Location
{
	Pointf loc;
	std::vector<Location*> connectedLocations;
	bool beacon;
	bool known;
	int visited;
	bool dangerZone;
	bool newSector;
	bool nebula;
	bool boss;
	LocationEvent *event;
	ImageDesc planet;
	ImageDesc space;
	ImageDesc beaconImage;
	GL_Texture *imageId;
	bool questLoc;
	AnimationTracker flashTracker;
	bool fleetChanging;
	std::string planetImage;
	std::string spaceImage;
};

struct LockdownShard;

struct LockdownShard
{
	LIBZHL_API void Update();
	
	Animation shard;
	Pointf position;
	Pointf goal;
	float speed;
	bool bArrived;
	bool bDone;
	float lifeTime;
	bool superFreeze;
	int lockingRoom;
};

struct MantisAlien
{
};

struct MantisAnimation;

struct MantisAnimation : CrewAnimation
{


	LIBZHL_API bool FireShot();
	LIBZHL_API std::string GetDeathSound();
	LIBZHL_API std::string GetShootingSound();
	
};

struct MedbaySystem
{
};

struct MemoryInputEvent
{
	int64_t used_bytes;
	int64_t free_bytes;
};

struct MindBox;
struct MindSystem;

struct MindBox : CooldownSystemBox
{
	MindBox(Point pos, MindSystem* sys)
	{
		this->constructor(pos, sys);
	}

	LIBZHL_API void constructor(Point pos, MindSystem *sys);
	
	MindSystem *mindSystem;
	Button mindControl;
	Point buttonOffset;
	WarningMessage *superShieldWarning;
};

struct MindSystem : ShipSystem
{
	LIBZHL_API void InitiateMindControl();
	LIBZHL_API void OnLoop();
	LIBZHL_API void ReleaseCrew();
	LIBZHL_API void SetArmed(int armed);
	
	std::pair<float, float> controlTimer;
	bool bCanUse;
	int iArmed;
	std::vector<CrewMember*> controlledCrew;
	bool bSuperShields;
	bool bBlocked;
	int iQueuedTarget;
	int iQueuedShip;
	std::vector<CrewMember*> queuedCrew;
};

struct Missile;

struct Missile : Projectile
{
	Missile(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading)
	{
		this->constructor(_position, _ownerId, _targetId, _target, _heading);
	}

	LIBZHL_API void constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, float _heading);
	
};

struct Moddable
{
};

struct MouseControl;

struct MouseControl
{
	LIBZHL_API void InstantTooltip();
	LIBZHL_API void LoadTooltip(const std::string &tooltipName);
	LIBZHL_API Point MeasureTooltip(int unk);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void QueueStaticTooltip(Point pos);
	LIBZHL_API void RenderTooltip(Point tooltipPoint, bool staticPos);
	LIBZHL_API void Reset();
	LIBZHL_API void ResetArmed();
	LIBZHL_API void SetDoor(int state);
	LIBZHL_API void SetTooltip(const std::string &tooltip);
	LIBZHL_API void SetTooltipTitle(const std::string &tooltip);
	
	Point position;
	Point lastPosition;
	int aiming_required;
	int iTeleporting;
	int iMindControlling;
	bool bSellingStuff;
	bool valid;
	bool newHover;
	bool lastValid;
	int animateDoor;
	GL_Texture *validPointer;
	GL_Texture *invalidPointer;
	GL_Texture *selling;
	Animation openDoor;
	std::string tooltip;
	float tooltipTimer;
	bool bMoving;
	bool bHideMouse;
	GL_Texture *lastIcon;
	GL_Texture *lastAddition;
	bool bForceTooltip;
	std::string tooltipTitle;
	std::string lastTooltipText;
	int iHacking;
	int overrideTooltipWidth;
	Point staticTooltip;
};

struct MouseInputEvent
{
	float x;
	float y;
	float scroll;
};

struct NebulaCloud
{
	Point pos;
	float currAlpha;
	float currScale;
	float deltaAlpha;
	float deltaScale;
	float newTrigger;
	bool newCloud;
	bool bLightning;
	AnimationTracker lightningFlash;
	float flashTimer;
	float lightningRotation;
};

struct OuterHull : Repairable
{
	Animation breach;
	Animation heal;
};

struct OxygenSystem;

struct OxygenSystem : ShipSystem
{
	LIBZHL_API void ComputeAirLoss(int roomId, float value, bool unk);
	LIBZHL_API void EmptyOxygen(int roomId);
	LIBZHL_API float GetRefillSpeed();
	LIBZHL_API void ModifyRoomOxygen(int roomId, float value);
	LIBZHL_API void UpdateAirlock(int roomId, int unk);
	LIBZHL_API void UpdateBreach(int roomId, int hasBreach, bool unk3);
	LIBZHL_API void constructor(int numRooms, int roomId, int shipId, int startingPower);
	
	float max_oxygen;
	std::vector<float> oxygenLevels;
	float fTotalOxygen;
	bool bLeakingO2;
};

struct PDSFire;

struct PDSFire : LaserBlast
{
	PDSFire(Point pos, int destinationSpace, Pointf destination) : LaserBlast(Pointf(pos.x, pos.y), 0, destinationSpace, destination)
	{
		this->constructor(pos, destinationSpace, destination);
	}

	LIBZHL_API void CollisionCheck(Collideable *other);
	LIBZHL_API void OnUpdate();
	LIBZHL_API void constructor(Point pos, int destinationSpace, Pointf destination);
	
	Pointf startPoint;
	bool passedTarget;
	float currentScale;
	bool missed;
	Animation explosionAnimation;
};

struct PackageModuleInfo;

struct PackageModuleInfo
{
	char *prefix;
	void **init;
	void **cleanup;
	void **list_files_start;
	void **list_files_next;
	void **file_info;
	void **decompress_get_stack_size;
	void **decompress_init;
	void **decompress;
	void *module_data;
	PackageModuleInfo *next;
	size_t prefixlen;
};

struct PowerManager;

struct PowerManager
{
	int GetAvailablePower()
	{
		return currentPower.second - currentPower.first;
	}
	
	int GetMaxPower()
	{
		int ret = currentPower.second - (iTempPowerLoss + iHacked);
		return ret > iTempPowerCap ? iTempPowerCap : ret;
	}

	LIBZHL_API static PowerManager *__stdcall GetPowerManager(int iShipId);
	
	std::pair<int, int> currentPower;
	int over_powered;
	float fFuel;
	bool failedPowerup;
	int iTempPowerCap;
	int iTempPowerLoss;
	int iTempDividePower;
	int iHacked;
	std::pair<int, int> batteryPower;
};

struct ProjectileFactory : ShipObject
{
	LIBZHL_API void ClearAiming();
	LIBZHL_API void ClearProjectiles();
	LIBZHL_API void Fire(std::vector<Pointf> &points, int target);
	LIBZHL_API bool FireNextShot();
	LIBZHL_API void ForceCoolup();
	LIBZHL_API Projectile *GetProjectile();
	LIBZHL_API bool IsChargedGoal();
	LIBZHL_API static Projectile *__stdcall LoadProjectile(int fd);
	LIBZHL_API int NumTargetsRequired();
	LIBZHL_API void OnRender(float alpha, bool forceVisual);
	LIBZHL_API void RenderChargeBar(float unk);
	LIBZHL_API static void __stdcall SaveProjectile(Projectile *p, int fd);
	LIBZHL_API void SelectChargeGoal();
	LIBZHL_API void SetCooldownModifier(float mod);
	LIBZHL_API void SetCurrentShip(Targetable *ship);
	LIBZHL_API void SetHacked(int hacked);
	LIBZHL_API int SpendMissiles();
	LIBZHL_API static int __stdcall StringToWeapon(const std::string &str);
	LIBZHL_API void Update();
	LIBZHL_API void constructor(const WeaponBlueprint *bp, int shipId);
	LIBZHL_API void destructor();
	
	std::pair<float, float> cooldown;
	std::pair<float, float> subCooldown;
	float baseCooldown;
	const WeaponBlueprint *blueprint;
	Point localPosition;
	Animation flight_animation;
	bool autoFiring;
	bool fireWhenReady;
	bool powered;
	int requiredPower;
	std::vector<Pointf> targets;
	std::vector<Pointf> lastTargets;
	int targetId;
	int iAmmo;
	std::string name;
	int numShots;
	float currentFiringAngle;
	float currentEntryAngle;
	Targetable *currentShipTarget;
	CloakingSystem *cloakingSystem;
	WeaponAnimation weaponVisual;
	WeaponMount mount;
	std::vector<Projectile*> queuedProjectiles;
	int iBonusPower;
	bool bFiredOnce;
	int iSpendMissile;
	float cooldownModifier;
	int shotsFiredAtTarget;
	int radius;
	int boostLevel;
	int lastProjectileId;
	int chargeLevel;
	int iHackLevel;
	int goalChargeLevel;
	bool isArtillery;
};

struct RepairAnimation : CrewAnimation
{
	RepairAnimation(int _shipId, const std::string& _race, Pointf _unk, bool _hostile);

};

struct RepairDrone : CrewDrone
{
};

struct RepairStoreBox;

struct RepairStoreBox : StoreBox
{
	RepairStoreBox(ShipManager *_ship, bool _repairAll, int _price)
	{
		this->constructor(_ship, _repairAll, _price);
	}

	LIBZHL_API void constructor(ShipManager *ship, bool repairAll, int price);
	
	bool repairAll;
	int repairCost;
	TextString buttonText;
};

struct ResourceControl;

struct ResourceManager;

struct freetype
{

	struct font_data
	{
		LIBZHL_API void clean();
		LIBZHL_API void init(const void *buffer, int bufferSize, unsigned int h, bool glow);
		
		float h;
		int font;
		float fontsize;
		float baseline;
		float lineHeight;
	};
	
	LIBZHL_API static Pointf __stdcall easy_measurePrintLines(int fontSize, float x, float y, int line_length, const std::string &text);
	LIBZHL_API static int __stdcall easy_measureWidth(int fontSize, const std::string &text);
	LIBZHL_API static Pointf __stdcall easy_print(int fontSize, float x, float y, const std::string &text);
	LIBZHL_API static Pointf __stdcall easy_printAutoNewlines(int fontSize, float x, float y, int line_length, const std::string &text);
	LIBZHL_API static void __stdcall easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string &text);
	LIBZHL_API static Pointf __stdcall easy_printCenter(int fontSize, float x, float y, const std::string &text);
	LIBZHL_API static Pointf __stdcall easy_printNewlinesCentered(int fontSize, float x, float y, int line_length, const std::string &text);
	LIBZHL_API static Pointf __stdcall easy_printRightAlign(int fontSize, float x, float y, const std::string &text);
	
};

struct ResourceControl
{	
	enum ImageSwappingMode
	{
	  SWAP_NONE = 0x0,
	  SWAP_SHIP_SETS = 0x1,
	  SWAP_DYNAMIC_SHIPS = 0x2,
	};

	struct DynamicImageInfo
	{
		std::string name;
		int resid;
	};
	
	struct LogicalTexInfo
	{
		std::string physName;
		int x;
		int y;
		int w;
		int h;
	};
	
	LIBZHL_API GL_Primitive *CreateImagePrimitive(GL_Texture *tex, int unk1, int unk2, int unk3, GL_Color color, float alpha, bool mirror);
	LIBZHL_API GL_Primitive *CreateImagePrimitiveString(const std::string &tex, int x, int y, int rotation, GL_Color color, float alpha, bool mirror);
	LIBZHL_API freetype::font_data &GetFontData(int size, bool ignoreLanguage);
	LIBZHL_API ImageDesc GetImageData(GL_Texture *tex);
	LIBZHL_API GL_Texture *GetImageId(const std::string &dir);
	LIBZHL_API bool ImageExists(const std::string &name);
	LIBZHL_API char *LoadFile(const std::string &fileName);
	LIBZHL_API char *LoadFromResourceFile(const std::string &fileName, std::size_t &fileSize, const std::string *unused_resourceFile);
	LIBZHL_API void OnInit(int imageSwappingMode);
	LIBZHL_API bool PreloadResources(bool unk);
	LIBZHL_API int RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror);
	LIBZHL_API int RenderImageString(std::string &tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror);
	LIBZHL_API void RenderLoadingBar(float initialProgress, float finalProgress);
	LIBZHL_API void constructor();
	
	std::unordered_map<std::string, GL_Texture*> images;
	std::unordered_map<int, freetype::font_data> fonts;
	std::unordered_map<GL_Texture*, ImageDesc> imageData;
	std::pair<int, int> preLoadProgress;
	std::string nextImageLoaded;
	int imageSwappingMode;
	std::vector<std::string> playerShipImages;
	std::vector<std::string> hangarShipImages;
	std::vector<std::string> enemyShipImages;
	std::vector<DynamicImageInfo> dynamicImages;
	int dynamicLoadMark;
	std::unordered_map<std::string, LogicalTexInfo> atlasData;
	ResourceManager *resmgr;
	PackageModuleInfo *package;
	GL_Texture *loading_box;
	GL_Texture *loading_bar;
	int screenWidth;
	int screenHeight;
	int renderPointX;
	int renderPointY;
	GL_FrameBuffer *frameBuffer;
	int fbViewportX;
	int fbViewportY;
	int fbViewportW;
	int fbViewportH;
};

struct ResourceManager
{
};

struct RockAlien
{
};

struct RockAnimation;

struct RockAnimation : CrewAnimation
{
    RockAnimation(const std::string& subRace, int shipId, Pointf position, bool enemy) : CrewAnimation(shipId, subRace, position, enemy)
	{
		this->constructor(subRace, shipId, position, enemy);
	}

	LIBZHL_API std::string GetDeathSound();
	LIBZHL_API std::string GetShootingSound();
	LIBZHL_API void constructor(const std::string &subRace, int iShipId, Pointf position, bool enemy);
	
};

struct ScoreKeeper;

struct StatTracker
{
	int max;
	int total;
	int current;
	std::string desc_id;
	int sector;
};

struct TopScore
{
	TopScore()
	{
	}

	std::string name;
	std::string blueprint;
	GL_Texture *image;
	int sector;
	int score;
	bool victory;
	int difficulty;
	bool advancedContent;
};

struct ScoreKeeper
{

	LIBZHL_API void AddScrapCollected(int scrap);
	LIBZHL_API int AddTopScoreList(TopScore &score, std::vector<TopScore> &topScoreList);
	LIBZHL_API void AddTopScoreType(TopScore &topScore, int type);
	LIBZHL_API void CheckTypes();
	LIBZHL_API void CycleLeft();
	LIBZHL_API void CycleRight();
	LIBZHL_API std::string GetShipBlueprint(int index);
	LIBZHL_API std::pair<int, int> GetShipId(const std::string &blueprintName);
	LIBZHL_API bool GetShipUnlocked(int shipId, int shipVariant);
	LIBZHL_API bool KeyDown(SDLKey key);
	LIBZHL_API void LoadGame(int fd);
	LIBZHL_API void LoadVersionFour(int file, int version);
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnInit();
	LIBZHL_API void OnRender(bool lastPlaythrough);
	LIBZHL_API void Open(bool fromGameOver);
	LIBZHL_API void RenderTopScores(const std::vector<TopScore> &topScoreList, Point position, int newHighScore);
	LIBZHL_API void Save(bool newHighScore);
	LIBZHL_API void SaveGame(int fd);
	LIBZHL_API void SaveScores(int file, std::vector<TopScore> &topScores);
	LIBZHL_API void SetSector(int sector);
	LIBZHL_API void SetVictory(bool victory);
	LIBZHL_API void SetupTopShip(int variant);
	LIBZHL_API void UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup);
	LIBZHL_API void WipeProfile(bool permanent);
	LIBZHL_API void constructor();
	
	StatTracker stats[4];
	CrewStatTracker crewStats[5];
	int gamesPlayed;
	int victories;
	TopScore currentScore;
	std::vector<std::vector<bool>> unlocked;
	bool firstRun;
	std::vector<TopScore> topScores;
	std::vector<std::vector<std::vector<TopScore>>> shipScores;
	bool bSavedScore;
	int newestHighScore;
	int newestShipBest;
	int newestShipType;
	int newestShipLayout;
	std::vector<std_pair_CAchievement_ptr_Point> achievements;
	std::vector<std_pair_CAchievement_ptr_Point> shipAchievements;
	GL_Texture *rightBox[2];
	GL_Texture *leftBox[2];
	Button rightButtons[2];
	Button leftButtons[2];
	bool activatedRight;
	bool activatedLeft;
	GL_Texture *lockIcon;
	InfoBox infoBox;
	TextButton closeButton;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	Button leftButton;
	Button rightButton;
	TextButton listButton;
	std::vector<GenericButton*> buttons;
	int selectedShip;
	int selectedLayout;
	int selectedAch;
	int selectedShipAch;
	ShipSelect shipSelect;
	int activeTouch;
	bool forceUnlockAll;
	bool gotCloseEvent;
	int loadingGameVersion;
	Point shipListCenter;
	Point typeALoc;
	Point typeBLoc;
	Point typeCLoc;
};

struct Scroller
{
	GL_Texture *imageId;
	int size_x;
	int size_y;
	int image_x;
	int image_y;
	float fSpeed;
	float current_x;
	bool bInitialized;
};

struct SettingValues
{
	int fullscreen;
	int currentFullscreen;
	int lastFullscreen;
	int sound;
	int music;
	int difficulty;
	bool commandConsole;
	bool altPause;
	bool touchAutoPause;
	bool lowend;
	bool fbError;
	std::string language;
	bool languageSet;
	Point screenResolution;
	int dialogKeys;
	bool logging;
	bool bShowChangelog;
	int loadingSaveVersion;
	bool achPopups;
	bool vsync;
	bool frameLimit;
	bool manualResolution;
	bool manualWindowed;
	bool manualStretched;
	bool showPaths;
	bool swapTextureType;
	bool colorblind;
	std::array<std::vector<HotkeyDesc>, 4> hotkeys;
	bool holdingModifier;
	bool bDlcEnabled;
	int openedList;
	bool beamTutorial;
};

struct Settings
{
	LIBZHL_API static char __stdcall GetCommandConsole();
	LIBZHL_API static bool __stdcall GetDlcEnabled();
	LIBZHL_API static SDLKey __stdcall GetHotkey(const std::string &hotkeyName);
	LIBZHL_API static std::string __stdcall GetHotkeyName(const std::string &name);
	LIBZHL_API static void __stdcall LoadSettings();
	LIBZHL_API static void __stdcall ResetHotkeys();
	LIBZHL_API static void __stdcall SaveSettings();
	LIBZHL_API static void __stdcall SetHotkey(const std::string &hotkeyName, SDLKey key);
	
};

struct Shields;

struct Shields : ShipSystem
{
	Shields(int roomId, int shipId, int startingPower, const std::string& shieldFile)
	{
		this->constructor(roomId, shipId, startingPower, shieldFile);
	}

	struct Shield
	{
		float charger;
		ShieldPower power;
		float superTimer;
	};
	
	struct ShieldAnimation
	{
		Pointf location;
		float current_size;
		float end_size;
		float current_thickness;
		float end_thickness;
		float length;
		float dx;
		int side;
		int ownerId;
		int damage;
	};
	
	LIBZHL_API void AddSuperShield(Point pos);
	LIBZHL_API CollisionResponse CollisionReal(float x, float y, Damage damage, bool force);
	LIBZHL_API CollisionResponse CollisionTest(float x, float y, Damage damage);
	LIBZHL_API void InstantCharge();
	LIBZHL_API void Jump();
	LIBZHL_API void OnLoop();
	LIBZHL_API void RenderBase(float alpha, float superShieldOverwrite);
	LIBZHL_API void SetBaseEllipse(Globals::Ellipse ellipse);
	LIBZHL_API void constructor(int roomId, int shipId, int startingPower, const std::string &shieldFile);
	
	float ellipseRatio;
	Point center;
	Globals::Ellipse baseShield;
	int iHighlightedSide;
	float debug_x;
	float debug_y;
	Shield shields;
	bool shields_shutdown;
	std::vector<ShieldAnimation> shieldHits;
	AnimationTracker shieldsDown;
	bool superShieldDown;
	Pointf shieldsDownPoint;
	AnimationTracker shieldsUp;
	GL_Texture *shieldImage;
	GL_Primitive *shieldPrimitive;
	std::string shieldImageName;
	bool bEnemyPresent;
	std::vector<DamageMessage*> damMessages;
	bool bBarrierMode;
	float lastHitTimer;
	float chargeTime;
	int lastHitShieldLevel;
	AnimationTracker superShieldUp;
	Point superUpLoc;
	bool bExcessChargeHack;
};

struct OuterHull;

struct Ship : ShipObject
{
	//Pointf GetRoomCenter(int room)
	//{
	//	auto graph = ShipGraph::GetShipInfo(this->iShipId);
	//	return graph->GetRoomCenter(room);
	//}

	void RenderEngineAnimation(bool showEngines, float alpha);
	
	enum DoorStateType
	{
	  DOOR_CLOSED = 0x0,
	  DOOR_OPEN = 0x1,
	  DOOR_OPEN_FORCED = 0x2,
	  DOOR_HIT = 0x3,
	  DOOR_ANIMATING = 0x4,
	};


	struct DoorState
	{
		DoorStateType state;
		bool hacked;
		int level;
	};
	
	LIBZHL_API void AddDoorVertices(Door *door, std::vector<GL_ColorTexVertex> *vertices);
	LIBZHL_API void BreachRandomHull(int roomId);
	LIBZHL_API bool BreachSpecificHull(int grid_x, int grid_y);
	LIBZHL_API void ChoosePrimarySlot(int roomId);
	LIBZHL_API void ClearImages();
	LIBZHL_API void ClearPrimarySlot(int roomId);
	LIBZHL_API std::pair<int, int> ContainsHullBreach(int roomId);
	LIBZHL_API Path DFS(int startRoom, Path *lastPath);
	LIBZHL_API int DamageHull(int amount);
	LIBZHL_API bool DestroyedDone();
	LIBZHL_API bool EmptyRoom(int id, bool intruder);
	LIBZHL_API void EmptyRoomSlot(int slotId, int roomId, bool intruder);
	LIBZHL_API void EmptySlots(int roomId);
	LIBZHL_API void FillRoomSlot(int slotId, int roomId, bool intruder);
	LIBZHL_API void FindOuterWalls();
	LIBZHL_API bool FullRoom(int id, bool intruder);
	LIBZHL_API int GetAvailableRoom(bool intruder);
	LIBZHL_API int GetAvailableRoomSlot(int id, bool intruder);
	LIBZHL_API Globals::Ellipse GetBaseEllipse();
	LIBZHL_API float GetCloakAlpha_private(bool complete);
	LIBZHL_API float GetCloakAlpha_public(bool complete);
	LIBZHL_API std::vector<const Door*> GetDoorListConst();
	LIBZHL_API Repairable *GetHullBreach(Point world);
	LIBZHL_API std::vector<Repairable*> GetHullBreaches(bool onlyDamaged);
	LIBZHL_API int GetHullDamageCount();
	LIBZHL_API int GetPrimaryDirection(int roomId);
	LIBZHL_API int GetPrimarySlot(int roomId);
	LIBZHL_API std::vector<Door*> GetRoomAirlocks(int roomId);
	LIBZHL_API bool GetRoomBlackout(int roomId);
	LIBZHL_API Pointf GetRoomCenter(int roomId);
	LIBZHL_API std::vector<const Room*> GetRoomListConst();
	LIBZHL_API Globals::Rect GetRoomRect(int id);
	LIBZHL_API Door *GetSelectedDoor(int x, int y, float doorScale);
	LIBZHL_API int GetSelectedRoomId(int x, int y, bool bIncludeWalls);
	LIBZHL_API int GetSelectedRoomId(Point p, bool bIncludeWalls);
	LIBZHL_API Point GetShipCorner();
	LIBZHL_API Repairable *GetSpecificHull(int grid_x, int grid_y);
	LIBZHL_API WeaponMount GetWeaponMount(int val);
	LIBZHL_API void HideInterior();
	LIBZHL_API void HighlightRoom(int roomId);
	LIBZHL_API bool Import(std::string *shipName);
	LIBZHL_API int IsOuterWall(int grid_x, int grid_y);
	LIBZHL_API bool IsPrimarySlotFilled(int roomId);
	LIBZHL_API bool IsSlotFilled(int slotId, int roomId, bool intruder);
	LIBZHL_API void LoadCloakImage();
	LIBZHL_API void LoadImages();
	LIBZHL_API void LoadState(int fd);
	LIBZHL_API void LockdownRoom(int roomId, Pointf position);
	LIBZHL_API void ManipulateAllDoors(bool open);
	LIBZHL_API void ManipulateDoors(int roomid, bool open);
	LIBZHL_API void OnCleanup();
	LIBZHL_API bool OnInit(ShipBlueprint *blueprint);
	LIBZHL_API void OnLoop(std::vector<float> &oxygenLevels);
	LIBZHL_API void OnRenderBase(bool enginesWorking);
	LIBZHL_API void OnRenderBlackout();
	LIBZHL_API void OnRenderBreaches();
	LIBZHL_API void OnRenderExplosion();
	LIBZHL_API void OnRenderFire(bool forceView);
	LIBZHL_API void OnRenderFloor(bool forceView);
	LIBZHL_API void OnRenderFloorEffects(bool forceView);
	LIBZHL_API void OnRenderHighlight();
	LIBZHL_API void OnRenderJump(float progress);
	LIBZHL_API void OnRenderSimple(float alpha);
	LIBZHL_API void OnRenderSparks();
	LIBZHL_API void OnRenderSystem(int roomId, int computerLevel);
	LIBZHL_API void OnRenderWalls(bool forceView, bool doorControlMode);
	LIBZHL_API void PauseLoop();
	LIBZHL_API void ProjectileStrike(int roomId, float damage);
	LIBZHL_API void RemoveRoom(int room);
	LIBZHL_API void ResetDoorHealth();
	LIBZHL_API void Restart();
	LIBZHL_API void RoomHacked(int roomId, float hackTime);
	LIBZHL_API bool RoomLocked(int roomId);
	LIBZHL_API void SaveState(int fd);
	LIBZHL_API void SetBlastDoors(int val);
	LIBZHL_API void SetCloaked(bool value);
	LIBZHL_API void SetDestroyed(bool animation, bool bossAnimation);
	LIBZHL_API void SetFireCount(int roomId, int fireId);
	LIBZHL_API void SetHackLevel(int roomId, int hackLevel);
	LIBZHL_API void SetIonedDoors(bool val);
	LIBZHL_API void SetPrimaryDirection(int dir, int roomId);
	LIBZHL_API void SetPrimarySlot(int slotId, int roomId);
	LIBZHL_API void SetRoomBlackout(int roomId, bool blackout);
	LIBZHL_API void SetRoomWarning(int roomId, bool warning);
	LIBZHL_API void SetSelectedRoom(int roomId);
	LIBZHL_API void SetWeaponAnimations(std::vector<WeaponAnimation*> *anims);
	LIBZHL_API void TapRoom(int roomId);
	LIBZHL_API void TriggerSparks(int room);
	LIBZHL_API bool UpdateDoorState(int index, Door *door);
	LIBZHL_API void UpdateDoorsPrimitive(bool doorControlMode);
	LIBZHL_API void constructor(int shipId);
	LIBZHL_API void destructor();
	LIBZHL_API void destructor_delete();
	
	std::vector<Room*> vRoomList;
	std::vector<Door*> vDoorList;
	std::vector<OuterHull*> vOuterWalls;
	std::vector<Door*> vOuterAirlocks;
	std::pair<int, int> hullIntegrity;
	std::vector<WeaponMount> weaponMounts;
	std::string floorImageName;
	ImageDesc shipFloor;
	GL_Primitive *floorPrimitive;
	std::string shipImageName;
	ImageDesc shipImage;
	Point glowOffset;
	GL_Primitive *shipImagePrimitive;
	std::string cloakImageName;
	ImageDesc shipImageCloak;
	GL_Primitive *cloakPrimitive;
	GL_Primitive *gridPrimitive;
	GL_Primitive *wallsPrimitive;
	GL_Primitive *doorsPrimitive;
	std::vector<DoorState> doorState;
	bool lastDoorControlMode;
	GL_Texture *thrustersImage;
	GL_Texture *jumpGlare;
	int vertical_shift;
	int horizontal_shift;
	std::string shipName;
	ExplosionAnimation explosion;
	bool bDestroyed;
	Globals::Ellipse baseEllipse;
	Animation engineAnim[2];
	AnimationTracker cloakingTracker;
	bool bCloaked;
	bool bExperiment;
	bool bShowEngines;
	std::vector<LockdownShard> lockdowns;
};

struct ShipButton : Button
{
	ShipButton(int x, int y)
	{
		this->constructor(x, y);
	}

	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnInit(const std::string &imgName, Point pos);
	LIBZHL_API void OnRender();
	LIBZHL_API void constructor(int shipType, int shipVariant);
	
	GL_Texture *iShipImage;
	bool bShipLocked;
	bool bLayoutLocked;
	bool bNoExist;
	std::vector<CAchievement*> achievements;
	int iSelectedAch;
	bool bSelected;
};

struct ShipGenerator
{
	LIBZHL_API static ShipManager *__stdcall CreateShip(const std::string &name, int sector, ShipEvent &event);
	LIBZHL_API static std::vector<int> __stdcall GenerateSystemMaxes(const ShipBlueprint &ship, int level);
	LIBZHL_API static std::vector<CrewBlueprint> __stdcall GetPossibleCrewList(ShipManager *ship, const std::string &crewList, unsigned int flags);
	LIBZHL_API static std::vector<DroneBlueprint*> __stdcall GetPossibleDroneList(ShipManager *ship, const std::string &droneList, int scrap, unsigned int flags, bool repeat);
	LIBZHL_API static std::vector<int> __stdcall GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type);
	LIBZHL_API static std::vector<int> __stdcall GetPossibleSystemUpgrades0(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type);
	LIBZHL_API static std::vector<int> __stdcall GetPossibleSystemUpgrades1(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type);
	LIBZHL_API static std::vector<int> __stdcall GetPossibleSystemUpgrades2(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type);
	LIBZHL_API static std::vector<WeaponBlueprint*> __stdcall GetPossibleWeaponList(ShipManager *ship, const std::string &weaponList, int scrap, unsigned int flags);
	LIBZHL_API static bool __stdcall UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId);
	
};

struct ShipInfo;

struct ShipInfo
{
	LIBZHL_API char AddAugmentation(const std::string &augment);
	LIBZHL_API float GetAugmentationValue(const std::string &augment);
	LIBZHL_API bool HasAugmentation(const std::string &augment);
	
	std::map<std::string, int> augList;
	std::map<std::string, int> equipList;
	int augCount;
};

struct EngineSystem;
struct MedbaySystem;
struct ParticleEmitter;

struct Spreader_Fire : ShipObject
{
	int count;
	std::vector<int> roomCount;
	std::vector<std::vector<Fire>> grid;
};

struct TeleportSystem;

struct ShipManager : ShipObject
{
	ShipManager(int shipId) 
	{
		this->constructor(shipId);
	}
	
	Pointf GetRandomRoomCenter()
	{
		auto rng = rand();
		auto graph = ShipGraph::GetShipInfo(this->iShipId);
		auto rooms = graph->rooms.size();
		return this->ship.GetRoomCenter(rng % rooms);
	}
	
	Pointf GetRoomCenter(int roomId)
	{
		return ship.GetRoomCenter(roomId);
	}
	
	~ShipManager()
	{
		this->destructor2();
	}
	
	std::pair<int, int> GetAvailablePower()
	{
		PowerManager *powerMan = PowerManager::GetPowerManager(iShipId);
		
		return std::pair<int, int>(powerMan->currentPower.second, powerMan->currentPower.second - powerMan->currentPower.first);
	}


	LIBZHL_API void AddCrewMember(CrewMember *crew, int roomId);
	LIBZHL_API CrewMember *AddCrewMemberFromBlueprint(CrewBlueprint *bp, int slot, bool init, int roomId, bool intruder);
	LIBZHL_API CrewMember *AddCrewMemberFromString(const std::string &name, const std::string &race, bool intruder, int roomId, bool init, bool male);
	LIBZHL_API Drone *AddDrone(const DroneBlueprint *bp, int slot);
	LIBZHL_API void AddEquipmentFromList(std::vector<std::string> *equipmentList);
	LIBZHL_API void AddInitialCrew(std::vector<CrewBlueprint> &blueprints);
	LIBZHL_API int AddSystem(int systemId);
	LIBZHL_API int AddWeapon(const WeaponBlueprint *bp, int slot);
	LIBZHL_API bool CanFitSubsystem(int systemId);
	LIBZHL_API bool CanFitSystem(int systemId);
	LIBZHL_API int CanUpgrade(int systemId, int amount);
	LIBZHL_API void CheckCrystalAugment(Pointf pos);
	LIBZHL_API void CheckSpreadDamage();
	LIBZHL_API void CheckVision();
	LIBZHL_API void ClearStatusAll();
	LIBZHL_API void ClearStatusSystem(int system);
	LIBZHL_API CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace);
	LIBZHL_API CollisionResponse CollisionShield(Pointf start, Pointf finish, Damage damage, bool raytrace);
	LIBZHL_API bool CommandCrewMoveRoom(CrewMember *crew, int roomId);
	LIBZHL_API int CountCrew(bool boarders);
	LIBZHL_API int CountCrewShipId(int roomId, int shipId);
	LIBZHL_API int CountPlayerCrew();
	LIBZHL_API CrewDrone *CreateCrewDrone(const DroneBlueprint *bp);
	LIBZHL_API SpaceDrone *CreateSpaceDrone(const DroneBlueprint *bp);
	LIBZHL_API int CreateSystems();
	LIBZHL_API bool DamageArea(Pointf location, Damage dmg, bool forceHit);
	LIBZHL_API bool DamageBeam(Pointf location1, Pointf location2, Damage dmg);
	LIBZHL_API bool DamageCrew(CrewMember *crew, Damage dmg);
	LIBZHL_API int DamageHull(int dmg, bool force);
	LIBZHL_API void DamageSystem(int systemId, Damage damage);
	LIBZHL_API bool DoSensorsProvide(int vision);
	LIBZHL_API bool DoorsFunction();
	LIBZHL_API void ExportBattleState(int file);
	LIBZHL_API void ExportShip(int file);
	LIBZHL_API CrewMember *FindCrew(const CrewBlueprint *bp);
	LIBZHL_API bool ForceDecreaseSystemPower(int sys);
	LIBZHL_API CrewMember *GetCrewmember(int slot, bool present);
	LIBZHL_API int GetDodgeFactor();
	LIBZHL_API bool GetDodged();
	LIBZHL_API int GetDroneCount();
	LIBZHL_API std::vector<Drone*> GetDroneList();
	LIBZHL_API int GetFireCount(int roomId);
	LIBZHL_API std::vector<CrewMember*> GetLeavingCrew(bool intruders);
	LIBZHL_API int GetMissileCount();
	LIBZHL_API int GetOxygenPercentage();
	LIBZHL_API CrewMember *GetSelectedCrewPoint(int x, int y, bool intruder);
	LIBZHL_API ShieldPower GetShieldPower();
	LIBZHL_API ShipSystem *GetSystem(int systemId);
	LIBZHL_API ShipSystem *GetSystemInRoom(int roomId);
	LIBZHL_API int GetSystemPower(int systemId);
	LIBZHL_API int GetSystemPowerMax(int systemId);
	LIBZHL_API int GetSystemRoom(int sysId);
	LIBZHL_API std::string GetTooltip(int x, int y);
	LIBZHL_API std::vector<ProjectileFactory*> GetWeaponList();
	LIBZHL_API bool HasSystem(int systemId);
	LIBZHL_API void ImportBattleState(int file);
	LIBZHL_API void ImportShip(int file);
	LIBZHL_API void InstantPowerShields();
	LIBZHL_API bool IsCloaked();
	LIBZHL_API bool IsCrewFull();
	LIBZHL_API bool IsCrewOverFull();
	LIBZHL_API int IsSystemHacked(int systemId);
	LIBZHL_API void JumpArrive();
	LIBZHL_API void JumpLeave();
	LIBZHL_API void ModifyDroneCount(int drones);
	LIBZHL_API void ModifyMissileCount(int missiles);
	LIBZHL_API void ModifyScrapCount(int scrap, bool income);
	LIBZHL_API int OnInit(ShipBlueprint *bp, int shipLevel);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender(bool showInterior, bool doorControlMode);
	LIBZHL_API bool PowerDrone(Drone *drone, int roomId, bool userDriven, bool force);
	LIBZHL_API void PrepareSuperBarrage();
	LIBZHL_API void PrepareSuperDrones();
	LIBZHL_API void RemoveItem(const std::string &name);
	LIBZHL_API void RenderChargeBars();
	LIBZHL_API void RenderWeapons();
	LIBZHL_API void ResetScrapLevel();
	LIBZHL_API void Restart();
	LIBZHL_API bool RestoreCrewPositions();
	LIBZHL_API ShipBlueprint SaveToBlueprint(bool unk);
	LIBZHL_API CrewBlueprint SelectRandomCrew(int seed, const std::string &racePref);
	LIBZHL_API void SetDestroyed();
	LIBZHL_API void SetSystemPowerLoss(int systemId, int powerLoss);
	LIBZHL_API void StartFire(int roomId);
	LIBZHL_API bool SystemFunctions(int systemId);
	LIBZHL_API std::vector<CrewMember*> TeleportCrew(int roomId, bool intruders);
	LIBZHL_API void UpdateCrewMembers();
	LIBZHL_API void UpdateEnvironment();
	LIBZHL_API void UpgradeSystem(int id, int amount);
	LIBZHL_API void Wait();
	LIBZHL_API int constructor(int shipId);
	LIBZHL_API void destructor();
	LIBZHL_API void destructor2();
	
	Targetable _targetable;
	Collideable _collideable;
	std::vector<ShipSystem*> vSystemList;
	OxygenSystem *oxygenSystem;
	TeleportSystem *teleportSystem;
	CloakingSystem *cloakSystem;
	BatterySystem *batterySystem;
	MindSystem *mindSystem;
	CloneSystem *cloneSystem;
	HackingSystem *hackingSystem;
	bool showNetwork;
	bool addedSystem;
	uint8_t gap_ex_1[2];
	Shields *shieldSystem;
	WeaponSystem *weaponSystem;
	DroneSystem *droneSystem;
	EngineSystem *engineSystem;
	MedbaySystem *medbaySystem;
	std::vector<ArtillerySystem*> artillerySystems;
	std::vector<CrewMember*> vCrewList;
	Spreader_Fire fireSpreader;
	Ship ship;
	char statusMessages[40];
	bool bGameOver;
	ShipManager *current_target;
	std::pair<float, float> jump_timer;
	int fuel_count;
	bool hostile_ship;
	bool bDestroyed;
	int iLastDamage;
	AnimationTracker jumpAnimation;
	std::vector<DamageMessage*> damMessages;
	std::vector<int> systemKey;
	int currentScrap;
	bool bJumping;
	bool bAutomated;
	uint8_t gap_ex_2[2];
	int shipLevel;
	ShipBlueprint myBlueprint;
	bool lastEngineStatus;
	bool lastJumpReady;
	bool bContainsPlayerCrew;
	int iIntruderCount;
	std::vector<std::vector<int>> crewCounts;
	int tempDroneCount;
	int tempMissileCount;
	std::vector<Animation> explosions;
	std::vector<bool> tempVision;
	bool bHighlightCrew;
	std::vector<Drone*> droneTrash;
	std::vector<SpaceDrone*> spaceDrones;
	std::vector<SpaceDrone*> newDroneArrivals;
	int bpCount;
	int iCustomizeMode;
	bool bShowRoom;
	std::vector<Projectile*> superBarrage;
	bool bInvincible;
	std::vector<SpaceDrone*> superDrones;
	GL_Primitive *highlight;
	int failedDodgeCounter;
	std::vector<float> hitByBeam;
	bool enemyDamagedUncloaked;
	int damageCloaked;
	std::map<int, int> killedByBeam;
	int minBeaconHealth;
	std::vector<ParticleEmitter*> fireExtinguishers;
	bool bWasSafe;
};

struct ShipRepair
{
};

struct ShipRepairDrone
{
};

struct SlugAlien
{
};

struct SlugAnimation
{
};

struct SoundControl;

struct SoundControl
{
	LIBZHL_API int PlaySoundMix(const std::string &soundName, float volume, bool loop);
	LIBZHL_API void StartPlaylist(std::vector<std::string> &playlist);
	LIBZHL_API void StopPlaylist(int fadeOut);
	LIBZHL_API void UpdateSoundLoop(const std::string &loopId, float count);
	
};

struct SpaceManager
{
	LaserBlast* CreateLaserBlast(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading);
	Asteroid* CreateAsteroid(Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading);
	Missile* CreateMissile(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading);
	BombProjectile* CreateBomb(WeaponBlueprint *weapon, int ownerId, Pointf target, int targetSpace);
	BeamWeapon* CreateBeam(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target1, Pointf target2, int targetSpace, int length, float heading);
	LaserBlast* CreateBurstProjectile(WeaponBlueprint *weapon, const std::string &image, bool fake, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading);
	PDSFire* CreatePDSFire(WeaponBlueprint *weapon, Point position, Pointf target, int targetSpace, bool smoke);

	struct FleetShip
	{
		GL_Texture *image;
		Point location;
	};
	
	LIBZHL_API void AddProjectile(Projectile *proj);
	LIBZHL_API void AddShip(ShipManager *ship);
	LIBZHL_API void Clear();
	LIBZHL_API void ClearEnvironment();
	LIBZHL_API void ClearProjectiles();
	LIBZHL_API bool DangerousEnvironment();
	LIBZHL_API GL_Color GetColorTint();
	LIBZHL_API float GetFlashOpacity();
	LIBZHL_API int GetScreenShake();
	LIBZHL_API SpaceDrone *GetSelectedDrone(int x, int y, int unk);
	LIBZHL_API void LoadSpace(int fileHelper);
	LIBZHL_API void MouseMove(int x, int y, int unk);
	LIBZHL_API void OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnLoopNebulas();
	LIBZHL_API void OnRenderAsteroids(int fieldLayers, float unk2);
	LIBZHL_API void OnRenderBackground();
	LIBZHL_API void OnRenderFleet();
	LIBZHL_API void OnRenderForeground();
	LIBZHL_API void OnRenderProjectiles(int iShipId, int layerCommand);
	LIBZHL_API void Restart();
	LIBZHL_API void SaveSpace(int fileHelper);
	LIBZHL_API void SetDangerZone(int fleetType);
	LIBZHL_API void SetFireLevel(bool state);
	LIBZHL_API void SetNebula(bool state);
	LIBZHL_API void SetPlanetaryDefense(char state, int target);
	LIBZHL_API void SetPulsarLevel(bool pulsarLevel);
	LIBZHL_API void SetStorm(bool state);
	LIBZHL_API void StartAsteroids(int shieldCount, bool unk);
	LIBZHL_API ImageDesc SwitchBackground(const std::string &name);
	LIBZHL_API ImageDesc SwitchBeacon();
	LIBZHL_API void SwitchImages(ImageDesc planet, ImageDesc unk1, ImageDesc unk2);
	LIBZHL_API ImageDesc SwitchPlanet(const std::string &name);
	LIBZHL_API void TransferProjectile(Projectile *proj);
	LIBZHL_API void UpdatePDS();
	LIBZHL_API void UpdatePlanetImage();
	LIBZHL_API void UpdateProjectile(Projectile *proj);
	LIBZHL_API void constructor();
	
	std::vector<Projectile*> projectiles;
	AsteroidGenerator asteroidGenerator;
	std::vector<ShipManager*> ships;
	std::vector<SpaceDrone*> drones;
	bool dangerZone;
	GL_Texture *currentBack;
	ImageDesc currentPlanet;
	CachedImage planetImage;
	ImageDesc fleetShip;
	GL_Texture *shipIds[8];
	FleetShip fleetShips[9];
	Scroller asteroidScroller[3];
	GL_Texture *sunImage;
	GL_Texture *sunGlow;
	AnimationTracker sunGlow1;
	AnimationTracker sunGlow2;
	AnimationTracker sunGlow3;
	bool sunLevel;
	bool pulsarLevel;
	GL_Texture *pulsarFront;
	GL_Texture *pulsarBack;
	GL_Texture *lowendPulsar;
	bool bPDS;
	int envTarget;
	Point shipPosition;
	float randomPDSTimer;
	std::vector<Projectile*> pdsQueue;
	TimerHelper flashTimer;
	AnimationTracker flashTracker;
	ImageDesc currentBeacon;
	ImageDesc currentBeaconFlash;
	AnimationTracker beaconTracker;
	bool flashSound;
	bool bNebula;
	bool bStorm;
	std::vector<NebulaCloud> nebulaClouds;
	GL_Texture *lowendNebula;
	GL_Texture *lowendStorm;
	GL_Texture *lowendSun;
	GL_Texture *lowendAsteroids;
	float shipHealth;
	bool gamePaused;
	TimerHelper pdsFireTimer;
	int pdsCountdown;
	std::vector<Animation> pdsSmokeAnims;
	bool queueScreenShake;
	bool playerShipInFront;
};

struct WindowFrame
{
	WindowFrame(int _x, int _y, int _w, int _h) 
	{
		this->constructor(_x, _y, _w, _h);
	}
	
	~WindowFrame()
	{
		this->destructor();
	}


	LIBZHL_API void Draw(int x, int y);
	LIBZHL_API void DrawMask(int unk);
	LIBZHL_API void constructor(int x, int y, int w, int h);
	LIBZHL_API void destructor();
	
	Globals::Rect rect;
	GL_Primitive *outline;
	GL_Primitive *mask;
	GL_Primitive *pattern;
};

struct StarMap : FocusWindow
{
	

	struct NebulaInfo
	{
		GL_Primitive *primitive;
		int x;
		int y;
		int w;
		int h;
	};
	
	LIBZHL_API void AddConnections(Location *unk0);
	LIBZHL_API bool AddQuest(const std::string &questEvent, bool force);
	LIBZHL_API void AddSectorColumn();
	LIBZHL_API void AdvanceWorldLevel();
	LIBZHL_API void AnalyzeMap();
	LIBZHL_API void AtBeacon();
	LIBZHL_API void CheckGameOver();
	LIBZHL_API void ClearBoss();
	LIBZHL_API void Close();
	LIBZHL_API void ConnectLocations(Point unk0, Point unk1);
	LIBZHL_API void DeleteMap();
	LIBZHL_API std::vector<Location*> Dijkstra(Location *start, Location *finish, bool include_unknown);
	LIBZHL_API void DrawConnection(const Pointf &pos1, const Pointf &pos2, const GL_Color *color);
	LIBZHL_API void ForceBossJump();
	LIBZHL_API void ForceExitBeacon();
	LIBZHL_API void GenerateEvents(bool tutorial);
	LIBZHL_API Location *GenerateMap(bool tutorial, bool seed);
	LIBZHL_API void GenerateNebulas(const std::vector<std::string> &names);
	LIBZHL_API void GenerateSectorMap();
	LIBZHL_API std::string GetLocationText(const Location *loc);
	LIBZHL_API Location *GetNewLocation();
	LIBZHL_API int GetNextDangerMove();
	LIBZHL_API int GetRandomSectorChoice();
	LIBZHL_API void GetSelectedSector(int unk0, int unk1, int unk2);
	LIBZHL_API void GetWaitLocation();
	LIBZHL_API void InitBossMessageBox();
	LIBZHL_API void InitMapTitle();
	LIBZHL_API void InitNoFuelText();
	LIBZHL_API void InitStatistics();
	LIBZHL_API void KeyDown(int unk0);
	LIBZHL_API Location *LoadGame(int fileHelper);
	LIBZHL_API void LocationHasBoss(Location *unk0);
	LIBZHL_API void LocationHasShip(Location *unk0);
	LIBZHL_API void LocationHasStore(Location *unk0);
	LIBZHL_API bool LocationsConnected(Location *unk0, Location *unk1);
	LIBZHL_API void MapConnected();
	LIBZHL_API void ModifyPursuit(int unk0);
	LIBZHL_API void MouseClick(int unk0, int unk1);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void NeighboringSector(int unk0);
	LIBZHL_API Location *NewGame(bool unk0);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void OnRenderFogEffect();
	LIBZHL_API void OnTouch(TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5);
	LIBZHL_API void Open();
	LIBZHL_API Point PointToGrid(float x, float y);
	LIBZHL_API Location *PopClosestLoc(std::vector<Location*> &vec, std::map<Location*, int> &map);
	LIBZHL_API void PopulateGrid(Point unk0);
	LIBZHL_API void PrintStatistics();
	LIBZHL_API void PushSectorColumn();
	LIBZHL_API void ReachSector(Sector *unk0);
	LIBZHL_API void RenderDistressButtons();
	LIBZHL_API void RenderLabels();
	LIBZHL_API void RenderLeftInsetButton(float unk0, float unk1, bool unk2);
	LIBZHL_API void RenderSectorName(Sector *unk0, GL_Color unk1);
	LIBZHL_API void ReverseBossPath();
	LIBZHL_API void SaveGame(int file);
	LIBZHL_API void SelectNewSector(int unk0);
	LIBZHL_API void SetBossStage(int stage);
	LIBZHL_API void SetOpen(bool unk0);
	LIBZHL_API void SetPosition(Point unk0);
	LIBZHL_API void SetupNoFuel(int seed, const std::string &forceEscape);
	LIBZHL_API void StartBeacon();
	LIBZHL_API void StartSecretSector();
	LIBZHL_API void TravelToLocation(Location *unk0);
	LIBZHL_API void TurnIntoFleetLocation(Location *loc);
	LIBZHL_API void UpdateBoss();
	LIBZHL_API void UpdateDangerZone();
	LIBZHL_API void UpdateSectorMap(Sector *unk0);
	LIBZHL_API void constructor();
	
	float visual_size;
	std::vector<Location*> locations;
	std::map<Point, Location*> locations_grid;
	std::vector<Location*> temp_path;
	Location *currentLoc;
	Location *potentialLoc;
	Location *hoverLoc;
	Point position;
	int iPopulatedTiles;
	int iLocationCount;
	int iEmptyTiles;
	bool bInitializedDisplay;
	Pointf translation;
	bool readyToTravel;
	Point dangerZone;
	float dangerZoneRadius;
	float shipRotation[2];
	TextButton endButton;
	TextButton waitButton;
	DistressButton distressButton;
	TextButton jumpButton;
	int worldLevel;
	bool bMapRevealed;
	int pursuitDelay;
	int sectorNameFont;
	WindowFrame mapBorder;
	GL_Primitive *mapBorderTitle;
	GL_Primitive *mapBorderTitleMask;
	GL_Texture *mapBorderSector;
	GL_Texture *mapInsetTextLeft;
	GL_Texture *mapInsetTextMiddle;
	GL_Texture *mapInsetTextRight;
	GL_Texture *mapInsetTextJump;
	GL_Texture *mapInsetWaitDistress;
	GL_Primitive *redLight;
	GL_Primitive *fuelMessage;
	GL_Primitive *waitingMessage;
	GL_Primitive *unexplored;
	GL_Primitive *explored;
	GL_Primitive *danger;
	GL_Primitive *warning;
	GL_Primitive *yellow_warning;
	GL_Primitive *warning_circle;
	GL_Primitive *nebula_circle;
	GL_Texture *boxGreen[3];
	GL_Texture *boxPurple[3];
	GL_Texture *boxWhite[3];
	GL_Primitive *ship;
	GL_Primitive *shipNoFuel;
	GL_Primitive *bossShip;
	GL_Primitive *dangerZoneEdge;
	GL_Texture *dangerZoneTile;
	GL_Primitive *dangerZoneAdvance;
	GL_Primitive *targetBox;
	GL_Primitive *sectorTargetBox_green;
	GL_Primitive *sectorTargetBox_yellow;
	AnimationTracker targetBoxTimer;
	TextButton closeButton;
	WindowFrame *descBox;
	GL_Primitive *shadow;
	GL_Primitive *warning_shadow;
	GL_Primitive *fuelOverlay;
	GL_Primitive *dangerFlash;
	GL_Primitive *mapsBottom[3];
	GL_Texture *dottedLine;
	GL_Texture *cross;
	GL_Texture *boss_jumps_box;
	std::vector<ImageDesc> smallNebula;
	std::vector<ImageDesc> largeNebula;
	std::vector<NebulaInfo> currentNebulas;
	ShipManager *shipManager;
	bool outOfFuel;
	AnimationTracker waiting;
	int dangerWaitStart;
	AnimationTracker distressAnim;
	bool bTutorialGenerated;
	std::vector<std::string> delayedQuests;
	std::vector<Sector*> sectors;
	Sector *currentSector;
	Sector *secretSector;
	bool bChoosingNewSector;
	bool bSecretSector;
	Location dummyNewSector;
	int mapsAnalyzed;
	int locationsCreated;
	int shipsCreated;
	std::map<std::string, int> scrapCollected;
	std::map<std::string, int> dronesCollected;
	std::map<std::string, int> fuelCollected;
	std::map<std::string, int> weaponFound;
	std::map<std::string, int> droneFound;
	int bossLoc;
	int arrivedAtBase;
	bool reversedPath;
	bool bossJumping;
	std::vector<Location*> boss_path;
	bool bossLevel;
	bool boss_wait;
	Pointf bossPosition;
	std::string forceSectorChoice;
	bool bEnemyShip;
	bool bNebulaMap;
	bool bInfiniteMode;
	std::vector<Sector*> lastSectors;
	TextButton closeSectorButton;
	int sectorMapSeed;
	int currentSectorSeed;
	int fuelEventSeed;
	std::string lastEscapeEvent;
	bool waitedLast;
	std::vector<Store*> storeTrash;
	std::vector<std_pair_std_string_int> addedQuests;
	int bossStage;
	TextString bossMessage;
	WarningMessage *bossJumpingWarning;
	bool crystalAlienFound;
	std::map<Location*, bool> foundMap;
	Point sectorMapOffset;
	int potentialSectorChoice;
	int finalSectorChoice;
	std::vector<Globals::Rect> sectorHitBoxes;
};

struct Store : FocusWindow
{
	Store()
	{
		this->constructor();
	}

	LIBZHL_API void Clear();
	LIBZHL_API void Close();
	LIBZHL_API void CreateStoreBoxes(int type, Equipment *equip);
	LIBZHL_API static void __stdcall DrawBuySellTabText();
	LIBZHL_API bool HasType(int type);
	LIBZHL_API void InitHeading(int index, Point pos);
	LIBZHL_API bool KeyDown(SDLKey key);
	LIBZHL_API void LoadStore(int file, int worldLevel);
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnInit(ShipManager *shopper, Equipment *equip, int worldLevel);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void RelinkShip(ShipManager *ship, Equipment *equip);
	LIBZHL_API void SaveStore(int file);
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void SetPositions();
	LIBZHL_API void constructor();
	LIBZHL_API void destructor();
	
	GL_Texture *box;
	TextString headingTitle[4];
	Button page1;
	Button page2;
	ConfirmWindow confirmDialog;
	Button *currentButton;
	Description currentDescription;
	std::string unavailable;
	std::vector<StoreBox*> vStoreBoxes;
	std::vector<StoreBox*> vItemBoxes;
	ShipManager *shopper;
	int selectedWeapon;
	int selectedDrone;
	InfoBox infoBox;
	Point infoBoxLoc;
	Button exitButton;
	int worldLevel;
	int sectionCount;
	int types[4];
	bool bShowPage2;
	uint8_t gap_ex_2[2];
	StoreBox *confirmBuy;
	int forceSystemInfoWidth;
};

struct SuperShieldDrone;

struct SuperShieldDrone : DefenseDrone
{
	SuperShieldDrone(int iShipId, int selfId, DroneBlueprint *blueprint)
	{
		this->constructor(iShipId, selfId, blueprint);
	}

	LIBZHL_API void OnLoop();
	LIBZHL_API void constructor(int iShipId, int selfId, DroneBlueprint *blueprint);
	
	Shields *shieldSystem;
	CachedImage drone_image_on;
	CachedImage drone_image_off;
	CachedImage drone_image_glow;
	float glowAnimation;
};

struct SystemCustomBox : SystemBox
{
	SystemCustomBox(Point pos, ShipSystem *sys, ShipManager *ship)
	{
		this->constructor(pos, sys, ship);
	}

	LIBZHL_API void constructor(Point pos, ShipSystem *sys, ShipManager *ship);
	
	ShipManager *shipManager;
	Button button;
};

struct SystemStoreBox;

struct SystemStoreBox : StoreBox
{
	SystemStoreBox(ShipManager *_shopper, Equipment *_equip, int _sys)
	{
		this->constructor(_shopper, _equip, _sys);
	}

	LIBZHL_API void Activate();
	LIBZHL_API bool CanHold();
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void Purchase();
	LIBZHL_API void SetExtraData(int droneChoice);
	LIBZHL_API void constructor(ShipManager *shopper, Equipment *equip, int sys);
	
	SystemBlueprint *blueprint;
	int type;
	bool bConfirming;
	std::string confirmString;
	std::string freeBlueprint;
	int droneChoice;
};

struct TeleportBox;

struct TeleportBox : SystemBox
{
	TeleportBox(Point pos, TeleportSystem* sys)
	{
		this->constructor(pos, sys);
	}

	LIBZHL_API void constructor(Point pos, TeleportSystem *sys);
	
	GL_Texture *box;
	Button teleportLeave;
	Button teleportArrive;
	TeleportSystem *teleSystem;
	Point buttonOffset;
	WarningMessage superShieldWarning;
};

struct TeleportSystem : ShipSystem
{
	LIBZHL_API bool CanReceive();
	LIBZHL_API bool CanSend();
	LIBZHL_API bool Charged();
	LIBZHL_API void ClearCrewLocations();
	LIBZHL_API void ForceReady();
	LIBZHL_API float GetChargedPercent();
	LIBZHL_API void InitiateTeleport();
	LIBZHL_API void Jump();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRenderFloor();
	LIBZHL_API void SetArmed(int armed);
	LIBZHL_API void SetHackingLevel(int hackingLevel);
	LIBZHL_API void UpdateCrewLocation(int unk);
	LIBZHL_API void constructor(int systemId, int roomId, int shipId, int startingPower);
	
	float chargeLevel;
	bool bCanSend;
	bool bCanReceive;
	int iArmed;
	std::vector<bool> crewSlots;
	int iPreparedCrew;
	int iNumSlots;
	bool bSuperShields;
};

struct TextInputEvent
{
	int32_t ch;
};

struct ToggleButton
{
};

struct TouchInputEvent
{
	unsigned int id;
	float x;
	float y;
	float initial_x;
	float initial_y;
};

struct TouchTooltip
{
};

struct TutorialManager;

struct TutorialManager
{
	LIBZHL_API void OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk);
	LIBZHL_API bool Running();
	LIBZHL_API void constructor();
	
};

struct UpgradeBox
{
	UpgradeBox()
	{
	}
	
	UpgradeBox(Point pos, bool subsystem)
	{
		this->constructorEmpty(pos, subsystem);
	}
	
	UpgradeBox(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem)
	{
		this->constructorSystem(ship, sys, pos, subsystem);
	}
	
	~UpgradeBox()
	{
		this->destructor();
	}

	LIBZHL_API void Accept();
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void MouseRightClick(int mX, int mY);
	LIBZHL_API void OnRender();
	LIBZHL_API void Undo();
	LIBZHL_API void constructorEmpty(Point pos, bool subsystem);
	LIBZHL_API void constructorSystem(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem);
	LIBZHL_API void destructor();
	
	ShipSystem *system;
	ShipManager *ship;
	const SystemBlueprint *blueprint;
	Point location;
	int tempUpgrade;
	Button *currentButton;
	std::string buttonBaseName;
	Button maxButton;
	Button boxButton;
	bool subsystem;
	bool isDummy;
	GL_Primitive *dummyBox;
};

struct WarningWithLines : WarningMessage
{
	GL_Primitive *linePrimitive;
	Point textOrigin;
	TextString topText;
	TextString bottomText;
	int topTextLimit;
	int bottomTextLimit;
};

struct WeaponBox;

struct WeaponBox : ArmamentBox
{

	LIBZHL_API std::string GenerateTooltip();
	LIBZHL_API void RenderBox(bool dragging, bool flashPowerBox);
	
	ProjectileFactory *pWeapon;
	bool armed;
	bool armedForAutofire;
	float cooldownMax;
	float cooldownModifier;
	Point cooldownPoint;
	int cooldownWidth;
	int cooldownHeight;
	std::vector<GL_Primitive*> cooldownBox;
	GL_Primitive *cooldownBar;
	std::vector<CachedImage> chargeIcons;
	bool defaultAutofire;
	bool wasCharged;
};

struct WeaponEquipBox : EquipmentBox
{
};

struct WeaponStoreBox;

struct WeaponStoreBox : StoreBox
{
	WeaponStoreBox(ShipManager *_ship, Equipment *_equip, const WeaponBlueprint *_bp)
	{
		this->constructor(_ship, _equip, _bp);
	}
	
	WeaponStoreBox()
	{
		StoreBox::constructor("storeUI/store_buy_weapons", nullptr, nullptr);
		this->bEquipmentBox = true;
	}

	LIBZHL_API void constructor(ShipManager *ship, Equipment *equip, const WeaponBlueprint *weaponBp);
	
	WeaponBlueprint *blueprint;
};

struct WeaponSystem : ShipSystem
{
	LIBZHL_API void OnLoop();
	LIBZHL_API void RemoveWeapon(int slot);
	LIBZHL_API virtual void SetBonusPower(int amount, int permanentPower);
	
	Pointf target;
	std::vector<ProjectileFactory*> weapons;
	std::vector<ProjectileFactory*> weaponsTrashList;
	float shot_timer;
	int shot_count;
	int missile_count;
	int missile_start;
	CloakingSystem *cloakingSystem;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct WeaponSystemBox;

struct WeaponSystemBox : SystemBox
{
	WeaponSystemBox(Point pos, ShipSystem* sys, WeaponControl *weapCtrl)
	{
		this->constructor(pos, sys, weapCtrl);
	}

	LIBZHL_API void constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl);
	
	WeaponControl *weapControl;
	TextButton autofireButton;
	Point buttonOffset;
	TouchTooltip *autofireTouchTooltip;
	bool touchTipWasOpen;
	bool autofireTipWasOpen;
};

struct BoardingEvent;

struct WorldManager
{
	LIBZHL_API bool AddBoarders(BoardingEvent &boardingEvent);
	LIBZHL_API bool CheckRequirements(LocationEvent *event, bool hidden);
	LIBZHL_API void CheckStatusEffects(std::vector<StatusEffect> &vec);
	LIBZHL_API void ClearLocation();
	LIBZHL_API void CreateChoiceBox(LocationEvent *event);
	LIBZHL_API void CreateChoiceBox0(LocationEvent *event);
	LIBZHL_API void CreateLocation(Location *loc);
	LIBZHL_API void CreateNewGame();
	LIBZHL_API CompleteShip *CreateShip(ShipEvent *shipEvent, bool boss);
	LIBZHL_API void CreateStore(LocationEvent *event);
	LIBZHL_API bool HostileEnvironment();
	LIBZHL_API void LoadGame(const std::string &fileName);
	LIBZHL_API void ModifyEnvironment(int envFlag, int envTarget);
	LIBZHL_API LocationEvent *ModifyResources(LocationEvent *event);
	LIBZHL_API void ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType);
	LIBZHL_API int OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void PauseLoop();
	LIBZHL_API void Restart();
	LIBZHL_API void SaveGame();
	LIBZHL_API void StartGame(ShipManager *ship);
	LIBZHL_API void UpdateLocation(LocationEvent *event);
	LIBZHL_API void UpdateLocation0(LocationEvent *event);
	LIBZHL_API void constructor();
	
	CompleteShip *playerShip;
	BossShip *bossShip;
	SpaceManager space;
	int currentDifficulty;
	std::vector<CompleteShip*> ships;
	StarMap starMap;
	CommandGui *commandGui;
	LocationEvent *baseLocationEvent;
	LocationEvent *lastLocationEvent;
	ShipEvent currentShipEvent;
	std::vector<StatusEffect> currentEffects;
	std::string startingText;
	Location *newLocation;
	bool bStartedGame;
	bool bLoadingGame;
	bool vAutoSaved;
	bool bExtraChoice;
	std::vector<int> choiceHistory;
	std::string generatedEvent;
	TextString lastMainText;
	int playerCrewCount;
	int killedCrew;
	int playerHull;
	std::vector<int> blueRaceChoices;
	int lastSelectedCrewSeed;
	bool testingBlueprints;
	std::vector<LocationEvent::Choice> originalChoiceList;
};

struct RewardDesc;

LIBZHL_API void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel);
LIBZHL_API void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel);
LIBZHL_API float __stdcall font_baseline(int font_id, float size);
LIBZHL_API float __stdcall font_height(int font_id, float size);
LIBZHL_API float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size);
LIBZHL_API float __stdcall getSkillBonus(int skill, int level);
LIBZHL_API void __stdcall graphics_clear(float r, float g, float b, float a, float depth, unsigned int stencil);
LIBZHL_API int __stdcall random32();
LIBZHL_API void __stdcall srandom32(unsigned int seed);
LIBZHL_API void __stdcall sys_graphics_set_window_title(char *title);

extern LIBZHL_API AchievementTracker *Global_AchievementTracker_Tracker;
extern LIBZHL_API AnimationControl *Global_AnimationControl_Animations;
extern LIBZHL_API BlueprintManager *Global_BlueprintManager_Blueprints;
extern LIBZHL_API CFPS *Global_CFPS_FPSControl;
extern LIBZHL_API CrewMemberFactory *Global_CrewMemberFactory_Factory;
extern LIBZHL_API EventGenerator *Global_EventGenerator_Generator;
extern LIBZHL_API EventSystem *Global_EventSystem_EventManager;
extern LIBZHL_API EventsParser *Global_EventsParser_Parser;
extern LIBZHL_API TextLibrary *Global_Globals_Library;
extern LIBZHL_API int *Globals_GetNextSpaceId_id;
extern LIBZHL_API bool *Globals_RNG;
extern LIBZHL_API FILE *ftl_log_logfile;
extern LIBZHL_API GL_Color *Global_InfoBox_detailsBarOn;
extern LIBZHL_API GL_Color *Global_InfoBox_detailsBarOff;
extern LIBZHL_API std::vector<std::string> *Global_OptionsScreen_languageList;
extern LIBZHL_API void **VTable_LaserBlast;
extern LIBZHL_API void **VTable_Targetable_LaserBlast;
extern LIBZHL_API MouseControl *Global_MouseControl_Mouse;
extern LIBZHL_API void **VTable_OuterHull;
extern LIBZHL_API void **VTable_RepairAnimation;
extern LIBZHL_API ResourceControl *Global_ResourceControl_GlobalResources;
extern LIBZHL_API ScoreKeeper *Global_ScoreKeeper_Keeper;
extern LIBZHL_API SettingValues *Global_Settings_Settings;
extern LIBZHL_API GL_Color *Global_COLOR_GREEN;
extern LIBZHL_API ShipInfo **Global_ShipObject_ShipInfoList;
extern LIBZHL_API GL_Primitive **ShipSystem__lockBlue;
extern LIBZHL_API GL_Primitive **ShipSystem__fireImage;
extern LIBZHL_API GL_Primitive **ShipSystem__lockHack;
extern LIBZHL_API GL_Primitive **ShipSystem__manningBarIon;
extern LIBZHL_API GL_Primitive **ShipSystem__manningBarOff;
extern LIBZHL_API GL_Primitive **ShipSystem__lockWhite;
extern LIBZHL_API GL_Primitive **ShipSystem__sabotageImage;
extern LIBZHL_API GL_Primitive **ShipSystem__manningOutline;
extern LIBZHL_API GL_Primitive **ShipSystem__manningBarOn;
extern LIBZHL_API GL_Primitive **ShipSystem__manningWhite;
extern LIBZHL_API GL_Primitive **ShipSystem__manningGreen;
extern LIBZHL_API GL_Primitive **ShipSystem__manningYellow;
extern LIBZHL_API GL_Primitive **ShipSystem__glowBlue;
extern LIBZHL_API GL_Primitive **ShipSystem__glowRed;
extern LIBZHL_API GL_Primitive **ShipSystem__glowWhite;
extern LIBZHL_API SoundControl *Global_SoundControl_Sounds;
extern LIBZHL_API Point *Global_SystemControl_weapon_position;
extern LIBZHL_API Point *Global_SystemControl_drone_position;
extern LIBZHL_API TutorialManager *Global_TutorialManager_Tutorial;
extern LIBZHL_API float *Global_freetype_sil_freetype_outline;


