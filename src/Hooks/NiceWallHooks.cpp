#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/GameNoteController.hpp"
#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"
#include "GlobalNamespace/GameEnergyCounter.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Vector3.hpp"
using namespace UnityEngine;

//MAKE_AUTO_HOOK_MATCH(ObstacleController_Update, &ObstacleController::Update, void, ObstacleController *self)
//{
//    ObstacleController_Update(self);
//
//    auto b = self->obstacleData->lineLayer;
//
//    if (b == 1)
//    {
//        self->get_gameObject()->SetActive(false);
//    }
//    else
//    {
//        self->get_gameObject()->SetActive(true);
//    }
//}

MAKE_AUTO_HOOK_MATCH(abc, &GameEnergyCounter::ProcessEnergyChange, void, GameEnergyCounter *self, float energyChange)
{
    abc(self, energyChange);
}