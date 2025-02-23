#include "CustomAchievements.h"
#include "CustomScoreKeeper.h"
#include "CustomShipSelect.h"
#include "ShipUnlocks.h"
#include "SaveFile.h"
#include "CustomEvents.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

CustomScoreKeeper* CustomScoreKeeper::instance = new CustomScoreKeeper();

std::unordered_map<std::string, int> metaVariables = std::unordered_map<std::string, int>();

void CustomScoreKeeper::AddTopScore(TopScore& topScore, int type = 0)
{
    auto scoreKeeper = G_->GetScoreKeeper();

    std::string blueprintName = topScore.blueprint;

    auto bp = G_->GetBlueprints()->GetShipBlueprint(blueprintName, -1);

    if (bp)
    {
        topScore.image = G_->GetResources()->GetImageId("customizeUI/miniship_" + bp->imgFile + ".png");
    }


    if (customShipScores.find(topScore.blueprint) == customShipScores.end())
    {
        customShipScores[topScore.blueprint] = std::vector<TopScore>();
    }

    if (type == 0 || type == 1)
    {
        scoreKeeper->newestHighScore = scoreKeeper->AddTopScoreList(topScore, scoreKeeper->topScores);
    }
    if (type == 0 || type == 2)
    {
        scoreKeeper->newestShipBest = scoreKeeper->AddTopScoreList(topScore, customShipScores[topScore.blueprint]);

        if (scoreKeeper->newestShipBest != -1)
        {
            int id = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(topScore.blueprint);

            if (id == -1) scoreKeeper->newestShipType = -1;
            else
            {
                scoreKeeper->newestShipType = 100 + id;
            }

            int shipLayout = 0;

            if (boost::ends_with(topScore.blueprint, "_2"))
            {
                shipLayout = 1;
            }
            else if (boost::ends_with(topScore.blueprint, "_3"))
            {
                shipLayout = 2;
            }

            scoreKeeper->newestShipLayout = shipLayout;
        }
    }

    if (customShipScores[topScore.blueprint].size() > 4)
    {
        customShipScores[topScore.blueprint].resize(4);
    }
}

std::vector<TopScore> CustomScoreKeeper::GetTopScores(const std::string& shipName, int variant)
{
    std::string blueprintName = shipName;

    if (variant == 1)
    {
        blueprintName.append("_2");
    }
    if (variant == 2)
    {
        blueprintName.append("_3");
    }

    if (customShipScores.find(shipName) != customShipScores.end())
    {
        return customShipScores[shipName];
    }
    else
    {
        return std::vector<TopScore>();
    }
}

void CustomScoreKeeper::LoadShipScores(int file)
{
    int shipScoreLen = FileHelper::readInteger(file);

    for (int i = 0; i < shipScoreLen; i++)
    {
        std::string shipBlueprint = FileHelper::readString(file);
        customShipScores[shipBlueprint] = std::vector<TopScore>();
        int numShipScores = FileHelper::readInteger(file);

        for (int j = 0; j < numShipScores; j++)
        {
            TopScore score = TopScore();

            score.name = FileHelper::readString(file);
            score.blueprint = FileHelper::readString(file);
            score.sector = FileHelper::readInteger(file);
            score.score = FileHelper::readInteger(file);
            score.victory = FileHelper::readInteger(file);
            score.difficulty = FileHelper::readInteger(file);
            score.advancedContent = FileHelper::readInteger(file);

            AddTopScore(score, 2);
        }
    }
}

void CustomScoreKeeper::SaveShipScores(int file)
{
    int shipScoreLen = customShipScores.size();

    FileHelper::writeInt(file, shipScoreLen);

    for (auto i : customShipScores)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second.size());

        for (auto score : i.second)
        {
            FileHelper::writeString(file, score.name);
            FileHelper::writeString(file, score.blueprint);
            FileHelper::writeInt(file, score.sector);
            FileHelper::writeInt(file, score.score  );
            FileHelper::writeInt(file, score.victory);
            FileHelper::writeInt(file, score.difficulty);
            FileHelper::writeInt(file, score.advancedContent);
        }
    }
}

void CustomScoreKeeper::LoadMetaVars(int file)
{
    metaVariables.clear();
    int n = FileHelper::readInteger(file);
    for (int i=0; i<n; ++i)
    {
        std::string varName = FileHelper::readString(file);
        int varValue = FileHelper::readInteger(file);
        if (varValue != 0 || metaVariables.count(varName))
        {
            metaVariables[varName] = varValue;
            CustomAchievementTracker::instance->UpdateVariableAchievements(varName, varValue, false);
        }
    }
}

void CustomScoreKeeper::SaveMetaVars(int file)
{
    FileHelper::writeInt(file, metaVariables.size());
    for (auto& i : metaVariables)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second);
    }
}

void CustomScoreKeeper::WipeProfile()
{
    customShipScores.clear();
}

HOOK_METHOD_PRIORITY(ScoreKeeper, CycleLeft, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ScoreKeeper::CycleLeft -> Begin (CustomScoreKeeper.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();
    
    int prevShipId = customSel->CycleShipPrevious(selectedShip, selectedLayout);
    if (selectedShip >= 100 && prevShipId < 100) customSel->SwitchPage(0);
    selectedShip = prevShipId;
    SetupTopShip(selectedLayout);
}

HOOK_METHOD_PRIORITY(ScoreKeeper, CycleRight, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ScoreKeeper::CycleRight -> Begin (CustomScoreKeeper.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();
    
    int nextShipId = customSel->CycleShipNext(selectedShip, selectedLayout);
    if (selectedShip >= 100 && nextShipId < 100) customSel->SwitchPage(0);
    selectedShip = nextShipId;
    SetupTopShip(selectedLayout);
}

HOOK_METHOD(ScoreKeeper, SetupTopShip, (int variant) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::SetupTopShip -> Begin (CustomScoreKeeper.cpp)\n")
    if (selectedShip >= 100)
    {
        shipAchievements.clear();

        std::vector<CAchievement*> customShipAchievements = CustomAchievementTracker::instance->GetShipAchievementsCustom(selectedShip, variant, false);

        int numAch = std::min(int(customShipAchievements.size()),3);

        Point p(515-35*numAch,118);

        for (int i=0; i<numAch; ++i)
        {
            shipAchievements.push_back(std::make_pair(customShipAchievements[i],p));
            p.x += 70;
        }

        selectedLayout = variant;

        CheckTypes();
        return;
    }

    super(variant);
}



HOOK_METHOD(ScoreKeeper, AddTopScoreType, (TopScore& topScore, int type) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::AddTopScoreType -> Begin (CustomScoreKeeper.cpp)\n")
    if (CustomShipSelect::GetInstance()->IsCustomShip(topScore.blueprint))
    {
        CustomScoreKeeper::instance->AddTopScore(topScore, type);
        return;
    }

    super(topScore, type);
}

HOOK_METHOD(ScoreKeeper, CheckTypes, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::CheckTypes -> Begin (CustomScoreKeeper.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (selectedShip >= 100)
    {
        ShipButtonDefinition def = customSel->GetShipButtonDefinition(selectedShip - 100);

        if (!def.typeA || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name))
        {
            typeA.bActive = false;
            typeA.bRenderOff = true;
            typeA.bRenderSelected = false;
        }
        else
        {
            typeA.SetActive(selectedLayout != 0);
            typeA.bRenderOff = false;
            typeA.bRenderSelected = selectedLayout == 0;
        }

        if (!def.typeB || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_2"))
        {
            typeB.bActive = false;
            typeB.bRenderOff = true;
            typeB.bRenderSelected = false;
        }
        else
        {
            typeB.SetActive(selectedLayout != 1);
            typeB.bRenderOff = false;
            typeB.bRenderSelected = selectedLayout == 1;
        }

        if (!def.typeC || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_3"))
        {
            typeC.bActive = false;
            typeC.bRenderOff = true;
            typeC.bRenderSelected = false;
        }
        else
        {
            typeC.SetActive(selectedLayout != 2);
            typeC.bRenderOff = false;
            typeC.bRenderSelected = selectedLayout == 2;
        }

        Point typeAPos(typeALoc.x, typeALoc.y);
        typeA.SetLocation(typeAPos);

        Point typeBPos(typeBLoc.x, typeBLoc.y);
        typeB.SetLocation(typeBPos);

        Point typeCPos(typeCLoc.x, typeCLoc.y);
        typeC.SetLocation(typeCPos);
    }
    else
    {
        super();
    }

    bool buttonsActive = customSel->CountUnlockedShips(selectedLayout) + (customSel->hideFirstPage ? 0 : CountUnlockedShips(selectedLayout)) > 1;
    leftButton.SetActive(buttonsActive);
    rightButton.SetActive(buttonsActive);
}

HOOK_METHOD(ScoreKeeper, MouseClick, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::MouseClick -> Begin (CustomScoreKeeper.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (shipSelect.bOpen)
    {
        shipSelect.MouseClick();
        if (shipSelect.selectedShip != -1)
        {
            selectedShip = shipSelect.selectedShip;
            SetupTopShip(shipSelect.currentType);
            shipSelect.Close();
        }
    }
    else
    {
        gotCloseEvent = closeButton.bActive && closeButton.bHover;
        if (rightButtons[activatedRight].bActive && rightButtons[activatedRight].bHover)
        {
            activatedRight = !activatedRight;
        }
        if (leftButtons[activatedLeft].bActive && leftButtons[activatedLeft].bHover)
        {
            activatedLeft = !activatedLeft;
        }

        if (activatedLeft)
        {
            if (leftButton.bActive && leftButton.bHover)
            {
                CycleLeft();
            }
            if (rightButton.bActive && rightButton.bHover)
            {
                CycleRight();
            }

            if (listButton.bActive && listButton.bHover)
            {
                shipSelect.Open(selectedShip, selectedLayout);
            }
            else if (typeA.bActive && typeA.bHover)
            {
                selectedLayout = 0;
                CheckTypes();
            }
            else if (typeB.bActive && typeB.bHover)
            {
                selectedLayout = 1;
                CheckTypes();
            }
            else if (typeC.bActive && typeC.bHover)
            {
                selectedLayout = 2;
                CheckTypes();
            }
        }
    }

    if (customSel->IsOpen() && !customSel->FirstPage())
    {
        if (customSel->GetSelectedId() != -1)
        {
            selectedShip = customSel->GetSelectedId();
            SetupTopShip(shipSelect.currentType);
            shipSelect.Close();
            CheckTypes();
        }
    }
}

HOOK_METHOD(ScoreKeeper, WipeProfile, (bool permanent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::WipeProfile -> Begin (CustomScoreKeeper.cpp)\n")
    CustomScoreKeeper::instance->WipeProfile();
    CustomAchievementTracker::instance->WipeProfile();

    metaVariables.clear();

    int tempQuestSeed = Global::questSeed;
    Global::questSeed = random32();
    VariableModifier::ApplyVariables(CustomEventsParser::GetInstance()->initialMetaVars, nullptr);
    Global::questSeed = tempQuestSeed;

    super(permanent);
}


HOOK_METHOD(AchievementTracker, LoadProfile, (int file, int version) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadProfile -> Begin (CustomScoreKeeper.cpp)\n")
    super(file, version);

    if (CustomShipUnlocks::instance->loadVersion == SaveFileHandler::version)
    {
        CustomShipUnlocks::instance->LoadCurrent(file); // VersionTwo
        CustomAchievementTracker::instance->LoadCurrent(file); // VersionThree
        CustomScoreKeeper::instance->LoadShipScores(file);
        CustomScoreKeeper::instance->LoadMetaVars(file);
    }
    else if (CustomShipUnlocks::instance->loadVersion == 2)
    {
        CustomShipUnlocks::instance->LoadVersionTwo(file);
        CustomScoreKeeper::instance->LoadShipScores(file);
    }
    else if (CustomShipUnlocks::instance->loadVersion == 1)
    {
        CustomShipUnlocks::instance->LoadVersionOne(file);
        CustomScoreKeeper::instance->LoadShipScores(file);
    }
}

HOOK_METHOD(AchievementTracker, SaveProfile, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::SaveProfile -> Begin (CustomScoreKeeper.cpp)\n")
    super(file);

    CustomShipUnlocks::instance->Save(file);
    CustomAchievementTracker::instance->Save(file);
    CustomScoreKeeper::instance->SaveShipScores(file);
    CustomScoreKeeper::instance->SaveMetaVars(file);
}

HOOK_METHOD(ScoreKeeper, Open, (bool fromGameOver) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::Open -> Begin (CustomScoreKeeper.cpp)\n")
    super(fromGameOver);

    CustomAchievementTracker::instance->OnInitStats();

    if (newestShipType != -1 && fromGameOver)
    {
        selectedLayout = newestShipLayout;
    }

    if (newestShipType == -1 || !fromGameOver)
    {
        auto customSel = CustomShipSelect::GetInstance();

        customSel->OnInit(&shipSelect);

        if (customSel->hideFirstPage)
        {
            int id = customSel->GetShipButtonIdFromName(customSel->customShipOrder[0]);

            if (id == -1) selectedShip = -1;
            else
            {
                selectedShip = id + 100;
            }

            SetupTopShip(0);
        }
    }


    CheckTypes();
}

HOOK_METHOD(ScoreKeeper, OnRender, (bool lastPlaythrough) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::OnRender -> Begin (CustomScoreKeeper.cpp)\n")
    bool isCustomShip = selectedShip >= 100;

    if (shipSelect.bOpen)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);

        shipSelect.OnLoop();
    }

    G_->GetResources()->RenderImage(leftBox[activatedLeft], 0, 0, 0, COLOR_WHITE, 1.f, false);
    if (!activatedRight || CustomScoreKeeper::instance->currentAchievementPage == 0 ||
        !CustomAchievementTracker::instance->RenderBackgroundPage(CustomScoreKeeper::instance->currentAchievementPage, Point(645, 0)))
    {
        G_->GetResources()->RenderImage(rightBox[activatedRight], 645, 0, 0, COLOR_WHITE, 1.f, false);
    }

    leftButtons[activatedLeft].OnRender();
    rightButtons[activatedRight].OnRender();

    std::string topScoresText = G_->GetTextLibrary()->GetText("stats_topscores");
    std::string shipBestText = G_->GetTextLibrary()->GetText("stats_shipbest");
    std::string statsText = G_->GetTextLibrary()->GetText("stats_stats");
    std::string achievementsText = G_->GetTextLibrary()->GetText("stats_achievements");

    int font = 64;
    int yBase = 0;

    while (freetype::easy_measurePrintLines(64, 0, 0, 999, topScoresText).x > 254.f
        || freetype::easy_measurePrintLines(64, 0, 0, 999, shipBestText).x > 218.f
        || freetype::easy_measurePrintLines(64, 0, 0, 999, statsText).x > 134.f
        || freetype::easy_measurePrintLines(64, 0, 0, 999, achievementsText).x > 324.f)
    {
        yBase += 4;
        font -= 1;
        if (yBase == 8)
        {
            font = 62;
            break;
        }
    }

    if (freetype::easy_measurePrintLines(font, 0, 0, 999, statsText).x > 134.f)
    {
        yBase += 3;
    }

    int yPos = yBase + 46;

    CSurface::GL_SetColor(GL_Color(25.f / 255.f, 49.f / 255.f, 51.f / 255.f, 1.f));

    freetype::easy_printCenter(font, 188, yPos, topScoresText);
    freetype::easy_printCenter(font, 477, yPos, shipBestText);
    freetype::easy_printCenter(font, 753, yPos, statsText);
    freetype::easy_printCenter(font, 1023, yPos, achievementsText);

    CSurface::GL_SetColor(COLOR_WHITE);

    Point pos1 = Point(112, 88);
    Point pos2 = Point(112, 88);
    Point pos3 = Point(700, 150);
    Point pos4 = Point(705, 100);

    leftButton.SetLocation(Point(shipListCenter.x - listButton.GetSize().x / 2 - 37, shipListCenter.y));
    listButton.SetLocation(Point(shipListCenter.x - listButton.GetSize().x / 2 - 37 + leftButton.imageSize.x + 5, shipListCenter.y));
    rightButton.SetLocation(Point(shipListCenter.x - listButton.GetSize().x / 2 - 37 + leftButton.imageSize.x + 5 + listButton.GetSize().x + 5, shipListCenter.y));

    if (!activatedLeft)
    {
        RenderTopScores(topScores, pos1, newestHighScore);
    }
    else
    {
        std::string shipName = GetShipBlueprint(selectedShip);
        std::string shipBlueprintName = shipName;

        if (selectedLayout == 1)
        {
            shipBlueprintName.append("_2");
        }
        if (selectedLayout == 2)
        {
            shipBlueprintName.append("_3");
        }

        auto shipBlueprint = G_->GetBlueprints()->GetShipBlueprint(shipBlueprintName, -1);

        freetype::easy_printCenter(24, pos2.x + 105, pos2.y + 3, shipBlueprint->shipClass.GetText());

        int shipBest = -1;
        if (newestShipType == selectedShip && newestShipLayout == selectedLayout)
        {
            shipBest = newestShipBest;
        }

        if (isCustomShip)
        {
            RenderTopScores(CustomScoreKeeper::instance->GetTopScores(shipBlueprintName, selectedLayout), Point(pos2.x, pos2.y + 116), shipBest);
        }
        else if (selectedShip != -1)
        {
            RenderTopScores(shipScores[selectedShip][selectedLayout], Point(pos2.x, pos2.y + 116), shipBest);
        }

        for (auto i : buttons)
        {
            i->OnRender();
        }

        for (int i = 0; i < shipAchievements.size(); i++)
        {
            auto item = shipAchievements[i];
            item.first->OnRender(item.second, selectedShipAch == i, true);
        }
    }


    if (activatedRight)
    {
        if (CustomScoreKeeper::instance->currentAchievementPage == 0)
        {
            CSurface::GL_SetColor(COLOR_WHITE);
            freetype::easy_print(24, pos4.x, pos4.y, G_->GetTextLibrary()->GetText("progression_heading"));
            freetype::easy_print(24, pos4.x, pos4.y + 160, G_->GetTextLibrary()->GetText("distance_heading"));
            freetype::easy_print(24, pos4.x, pos4.y + 330, G_->GetTextLibrary()->GetText("skill_heading"));

            for (int i = 0; i < achievements.size(); i++)
            {
                auto item = achievements[i];
                item.first->OnRender(item.second, selectedAch == i, true);
            }
        }
        else
        {
            CustomAchievementTracker::instance->RenderPage(CustomScoreKeeper::instance->currentAchievementPage, Point(645, 0));
        }
        int numCustomPages = CustomAchievementTracker::instance->CountCustomAchievementPages();
        if (numCustomPages)
        {
            CustomAchievementTracker::instance->achievementButtonLeft->OnRender();
            CustomAchievementTracker::instance->achievementButtonRight->OnRender();

            CSurface::GL_SetColor(CustomAchievementTracker::instance->achievementPagesBoxTextColor);
            freetype::easy_printRightAlign(24, 1150, 84, boost::str(boost::format("%1%/%2%") % (CustomScoreKeeper::instance->currentAchievementPage+1) % (numCustomPages+1)));
        }
    }
    else
    {
        CSurface::GL_SetColor(COLOR_WHITE);
        freetype::easy_print(24, pos3.x - 5, pos3.y - 50, G_->GetTextLibrary()->GetText("records_heading"));

        int statsYPos = pos3.y;

        for (auto i : stats)
        {
            if (lastPlaythrough && i.current == i.max)
            {
                CSurface::GL_SetColor(COLOR_YELLOW);
            }

            std::string scoreText = G_->GetTextLibrary()->GetText("most_" + i.desc_id);
            freetype::easy_print(13, pos3.x, statsYPos, scoreText);
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.max));

            CSurface::GL_SetColor(COLOR_WHITE);

            statsYPos += 20;
        }

        statsYPos -= 20;

        freetype::easy_print(24, pos3.x - 5, statsYPos + 30, G_->GetTextLibrary()->GetText("crew_heading"));

        statsYPos += 75;
        int crewStatsLimit = statsYPos + 180;

        for (auto i : crewStats)
        {
            if (i.newStat)
            {
                CSurface::GL_SetColor(COLOR_YELLOW);
            }
            else
            {
                CSurface::GL_SetColor(COLOR_WHITE);
            }

            std::string scoreText = G_->GetTextLibrary()->GetText("most_" + i.title_id);
            freetype::easy_print(13, pos3.x, statsYPos, scoreText);
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.max));

            if (!i.name.empty())
            {
                Pointf endPos = freetype::easy_printCenter(13, pos3.x + 365, statsYPos, i.name);

                CSurface::GL_SetColor(COLOR_WHITE);
                CrewBlueprint crewBp = G_->GetBlueprints()->GetCrewBlueprint(i.species);

                crewBp.male = i.male;
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(endPos.x - 30.f, statsYPos + 8, 0);

                crewBp.RenderIcon(1.f);
                CSurface::GL_PopMatrix();

            }

            if (statsYPos + 21 == crewStatsLimit)
            {
                break;
            }
            statsYPos += 21;
        }

        std::string statsPrefix = "";
        CSurface::GL_SetColor(COLOR_WHITE);

        if (lastPlaythrough)
        {
            freetype::easy_print(24, pos3.x - 5, statsYPos + 5, G_->GetTextLibrary()->GetText("stats_heading"));
        }
        else
        {
            freetype::easy_print(24, pos3.x - 5, statsYPos + 5, G_->GetTextLibrary()->GetText("total_heading"));

            statsPrefix = "total_";
        }

        statsYPos += 55;

        for (auto i : stats)
        {
            std::string scoreText = G_->GetTextLibrary()->GetText(statsPrefix + i.desc_id);
            freetype::easy_print(13, pos3.x, statsYPos, scoreText);
            if (lastPlaythrough)
            {
                freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.current));
            }
            else
            {
                freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(i.total));
            }

            statsYPos += 20;
        }


        statsYPos += 20;

        if (lastPlaythrough)
        {
            freetype::easy_print(13, pos3.x, statsYPos, G_->GetTextLibrary()->GetText("final_score"));
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(currentScore.score));
        }
        else
        {
            freetype::easy_print(13, pos3.x, statsYPos, G_->GetTextLibrary()->GetText("total_games"));
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(gamesPlayed));

            statsYPos += 20;

            freetype::easy_print(13, pos3.x, statsYPos, G_->GetTextLibrary()->GetText("total_victories"));
            freetype::easy_printCenter(13, pos3.x + 465, statsYPos, std::to_string(victories));
        }
    }

    if (!infoBox.IsEmpty())
    {
        infoBox.OnRender();
    }

    closeButton.OnRender();
    CSurface::GL_RemoveColorTint();
    if (shipSelect.bOpen)
    {
        shipSelect.OnRender();
    }
}

HOOK_METHOD(ScoreKeeper, KeyDown, (SDLKey key) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::KeyDown -> Begin (CustomScoreKeeper.cpp)\n")
    if (key == SDLKey::SDLK_UP
        || key == SDLKey::SDLK_LEFT
        || key == SDLKey::SDLK_RIGHT
        || key == SDLKey::SDLK_DOWN)
    {
        return true;
    }

    if (key == SDLKey::SDLK_ESCAPE && CustomShipSelect::GetInstance()->IsOpen())
    {
        super(key);

        return true;
    }

    return super(key);
}

HOOK_METHOD(ScoreKeeper, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::MouseMove -> Begin (CustomScoreKeeper.cpp)\n")
    if (shipSelect.bOpen)
    {
        shipSelect.MouseMove(mX, mY);
        return;
    }
    closeButton.MouseMove(mX, mY, false);
    rightButtons[activatedRight].MouseMove(mX, mY, false);
    leftButtons[activatedLeft].MouseMove(mX, mY, false);
    rightButtons[!activatedRight].MouseMove(-1, -1, false);
    leftButtons[!activatedLeft].MouseMove(-1, -1, false);

    selectedAch = -1;
    selectedShipAch = -1;
    if (activatedRight)
    {
        if (CustomScoreKeeper::instance->currentAchievementPage == 0)
        {
            for (int i=0; i<achievements.size(); ++i)
            {
                std_pair_CAchievement_ptr_Point &ach = achievements[i];
                if (mX > ach.second.x && mX < ach.second.x+64 && mY > ach.second.y && mY < ach.second.y+64)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach.first);
                    selectedAch = i;
                }
            }
        }
        else
        {
            CustomAchievementTracker::instance->MouseMove(CustomScoreKeeper::instance->currentAchievementPage, mX-645, mY);
        }
        if (CustomAchievementTracker::instance->HasCustomAchievementPage())
        {
            CustomAchievementTracker::instance->achievementButtonLeft->MouseMove(mX, mY, false);
            CustomAchievementTracker::instance->achievementButtonRight->MouseMove(mX, mY, false);
        }
    }
    if (activatedLeft)
    {
        for (GenericButton *button : buttons)
        {
            button->MouseMove(mX, mY, false);
        }
        for (int i=0; i<shipAchievements.size(); ++i)
        {
            std_pair_CAchievement_ptr_Point &ach = shipAchievements[i];
            if (mX > ach.second.x && mX < ach.second.x+64 && mY > ach.second.y && mY < ach.second.y+64)
            {
                G_->GetAchievementTracker()->SetTooltip(ach.first);
                selectedShipAch = i;
            }
        }
    }
}

HOOK_METHOD(ScoreKeeper, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::MouseClick -> Begin (CustomScoreKeeper.cpp)\n")
    super(mX, mY);

    if (!shipSelect.bOpen)
    {
        if (CustomAchievementTracker::instance->achievementButtonLeft->bActive && CustomAchievementTracker::instance->achievementButtonLeft->bHover)
        {
            CustomScoreKeeper::instance->currentAchievementPage = CustomAchievementTracker::instance->PrevPage(CustomScoreKeeper::instance->currentAchievementPage);
        }
        if (CustomAchievementTracker::instance->achievementButtonRight->bActive && CustomAchievementTracker::instance->achievementButtonRight->bHover)
        {
            CustomScoreKeeper::instance->currentAchievementPage = CustomAchievementTracker::instance->NextPage(CustomScoreKeeper::instance->currentAchievementPage);
        }
    }
}
