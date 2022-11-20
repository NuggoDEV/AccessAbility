#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(ObstacleController_Init, &ObstacleController::Init, void, ObstacleController *self, ObstacleData *obstacleData, float worldRotation, Vector3 startPos, Vector3 midPos, Vector3 endPos, float moveDuration1, float moveDuration2, float singleLineWidth, float height)
{
    ObstacleController_Init(self, obstacleData, worldRotation, startPos, midPos, endPos, moveDuration1, moveDuration2, singleLineWidth, height);


    //if (getModConfig().DisableWalls.GetValue() && getModConfig().Enabled.GetValue())
    //{
    //    self->get_gameObject()->SetActive(false);
    //}
    //else
    //{
    //    self->get_gameObject()->SetActive(true);
    //}
}
