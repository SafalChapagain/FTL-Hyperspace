#pragma once
#include "FTLGame.h"

class CustomEquipment
{
public:
    void OnInit(ShipManager *ship);
    void SetPosition(Point p);
    void OnRender();
    void MouseMove(int mX, int mY);
    void MouseClick(int mX, int mY);

    void OnScrollWheel(float direction);
    void AddOverCapacityItem(const EquipmentBoxItem &item);

    CustomEquipment(Equipment *equipment)
    {
        orig = equipment;
    }

    ~CustomEquipment()
    {
        delete augLeftButton;
        delete augRightButton;
        delete cargoLeftButton;
        delete cargoRightButton;
        delete overCapacityLeftButton;
        delete overCapacityRightButton;
    }

    std::vector<std::pair<EquipmentBoxItem, bool>> overCapacityItems; // second is true if item is augment
    int currentAugPage = 0;
    int currentCargoPage = 0;
    int currentOverCapacityPage = 0;
    
private:
    Equipment *orig = nullptr;

    Button *augLeftButton = nullptr;
    Button *augRightButton = nullptr;
    int augNumber = 3;
    int maxAugPage = 0;

    Button *cargoLeftButton = nullptr;
    Button *cargoRightButton = nullptr;
    int cargoNumber = 4;
    int maxCargoPage = 0;

    Button *overCapacityLeftButton = nullptr;
    Button *overCapacityRightButton = nullptr;
};

struct Equipment_Extend
{
    Equipment *orig = nullptr;
    CustomEquipment *customEquipment = nullptr;

    ~Equipment_Extend()
    {
        delete customEquipment;
    }

};

Equipment_Extend* Get_Equipment_Extend(Equipment* c);

#define EQ_EX Get_Equipment_Extend
