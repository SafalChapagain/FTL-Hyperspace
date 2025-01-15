#pragma once
#include "Global.h"

void ParseSystemsNode(rapidxml::xml_node<char>* node);
class CustomMindSystem
{
public:
    struct MindLevel
    {
        float damageBoost;
        float healthBoost;
        float duration;
        int lock;
        int count;
    };
    static void ParseSystemNode(rapidxml::xml_node<char>* node);
    static MindLevel& GetLevel(MindSystem* system);
    
private:
    static MindLevel defaultLevel;
    static std::vector<MindLevel> levels;
};

class CustomCloneSystem
{
public:
    struct CloneLevel
    {
        int jumpHP;
        int jumpHPPercent;
        int cloneHPPercent;
        int skillLossPercent;
        float cloneSpeed;
        float deathSpeed;
        int count; // Number of clones, unused for now, still here with the xml implementation for a later use
    };
    static void ParseSystemNode(rapidxml::xml_node<char>* node);
    static CloneLevel& GetLevel(CloneSystem* system, bool passive);
    
    static CloneLevel& GetLevel(int power);
private:
    static CloneLevel defaultLevel;
    static std::vector<CloneLevel> levels;
};
