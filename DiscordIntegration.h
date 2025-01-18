#pragma once

#ifndef SKIPDISCORD

#include "Global.h"
#include "discord_rpc.h"
#include <rapidxml.hpp>
#include <algorithm>

class DiscordHandler
{
public:
    DiscordHandler()
    {
    }

    bool vanilla = true;

    void ParseDiscordNode(rapidxml::xml_node<char> *node);

    void SetState(const std::string& state);
    void SetDetails(const std::string& details);
    void SetSmallImageText(const std::string& text);
    void SetLargeImageText(const std::string& text);
    void SetSmallImageKey(const std::string& key);
    void SetLargeImageKey(const std::string& key);
    void StartTime();
    void StopTime();

    void Initialize();
    void Shutdown();
    void UpdatePresence();

    bool ValidMiniship(std::string img)
    {
        return std::find(miniships.begin(), miniships.end(), img) != miniships.end();
    }

    bool Enabled()
    {
        return initialized;
    }

    static DiscordHandler* GetInstance()
    {
        return &_instance;
    }

private:
    bool initialized;


    std::string state;
    std::string details;
    std::string smallImageText;
    std::string largeImageText;
    std::string smallImageKey;
    std::string largeImageKey = "big_icon";
    std::string appId = "728949575586545695";
    int64_t startTimestamp;

    std::string lastState;
    std::string lastDetails;
    std::string lastSmallImageText;
    std::string lastLargeImageText;
    std::string lastSmallImageKey;
    std::string lastLargeImageKey;
    int64_t lastTime;

    std::vector<std::string> miniships = std::vector<std::string>();

    static DiscordHandler _instance;


};
#endif