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

ObstacleData obstacleData;


MAKE_AUTO_HOOK_MATCH(BDOABT_ShouldUseBeatmapDataItem, &BeatmapDataObstaclesAndBombsTransform::ShouldUseBeatmapDataItem, bool, BeatmapDataItem *beatmapDataItem, GameplayModifiers::EnabledObstacleType enabledObstaclesType, bool noBombs)
{
    BDOABT_ShouldUseBeatmapDataItem(beatmapDataItem, enabledObstaclesType, noBombs);

    if (obstacleData.height != 2)
    {
        getLogger().info("Height isn't equal to 3");
        return false;
    }
    else
    {
        return true;
    }

    return obstacleData.height;
}


//MAKE_AUTO_HOOK_MATCH(fjglv, &ObstacleController::Update, void, ObstacleController *self)
//{
//    fjglv(self);
//
//    if (obstacleData.height != 2)
//    {
//        getLogger().info("Height isn't equal to 3");
//        self->set_enabled(true);
//
//        Object::Destroy(self->get);
//        obstacleData.
//    }
//}

MAKE_AUTO_HOOK_MATCH(avcsdf, &ObstacleController::Init, void, ObstacleController *self, ObstacleData *obstacleData, float worldRotation, Vector3 startPos, Vector3 midPos, Vector3 endPos, float move1Duration, float move2Duration, float singleLineWidth, float height)
{
    avcsdf(self, obstacleData, worldRotation, startPos, midPos, endPos, move1Duration, move2Duration, singleLineWidth, height);

    if (getModConfig().Enabled.GetValue() && getModConfig().DisableCrouch.GetValue() && obstacleData->lineLayer != 0)
    {
        self->get_gameObject()->SetActive(false);
    }
}

//class a
//{
//    
//    
//    if (NoteLineLayer::Base)
//    {
//        getLogger().info("Enabled Walls");
//        self->set_enabled(true);
//    }
//    else
//    {
//        getLogger().info("Disabled Walls");
//        self->set_enabled(false);
//    }
//    a(self);
//}