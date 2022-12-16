#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/BeatmapDataObstaclesAndBombsTransform.hpp"
#include "GlobalNamespace/BeatmapDataItem.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"

#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"
#include "GlobalNamespace/NoteLineLayer.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(Crouch_ObstacleController_Init, &ObstacleController::Init, void, ObstacleController *self, ObstacleData *obstacleData, float worldRotation, Vector3 startPos, Vector3 midPos, Vector3 endPos, float move1Duration, float move2Duration, float singleLineWidth, float height)
{
    Crouch_ObstacleController_Init(self, obstacleData, worldRotation, startPos, midPos, endPos, move1Duration, move2Duration, singleLineWidth, height);

    if (getModConfig().Enabled.GetValue() && getModConfig().YeetCrouchWalls.GetValue() && obstacleData->lineLayer != 0)
    {
        self->get_gameObject()->SetActive(false);
    }
}