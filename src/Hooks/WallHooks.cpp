#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"
#include "GlobalNamespace/NoteLineLayer.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(ObstacleController_Init, &ObstacleController::Init, void, ObstacleController *self, ObstacleData *obstacleData, float worldRotation, Vector3 startPos, Vector3 midPos, Vector3 endPos, float moveDuration1, float moveDuration2, float singleLineWidth, float height)
{
    ObstacleController_Init(self, obstacleData, worldRotation, startPos, midPos, endPos, moveDuration1, moveDuration2, singleLineWidth, height);

    //NoteLineLayer *b;
//
    //if (b->Base && getModConfig().DisableCrouch.GetValue())
    //{
    //    //Object::Destroy(self);
    //    self->get_gameObject()->SetActive(false);
    //}
    //else
    //{
    //    self->get_gameObject()->SetActive(true);
    //}

}

//bool hasActivated = false;

MAKE_AUTO_HOOK_MATCH(ObstacleController_Update, &ObstacleController::ManualUpdate, void, ObstacleController *self)
{
    ObstacleController_Update(self);

    NoteLineLayer *b;
    ObstacleData *obstacleLayer;

    if (obstacleLayer->get_lineLayer() == 0 && getModConfig().DisableCrouch.GetValue() /*&& !hasActivated*/)
    {
        //Object::Destroy(self);
        self->get_gameObject()->SetActive(false);
    }
    else
    {
        self->get_gameObject()->SetActive(true);
    }
}