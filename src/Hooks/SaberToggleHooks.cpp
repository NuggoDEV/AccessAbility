#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/GameNoteController.hpp"
#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/NoteVisualModifierType.hpp"
#include "GlobalNamespace/ColorType.hpp"
#include "GlobalNamespace/BeatEffectSpawner.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;


MAKE_AUTO_HOOK_MATCH(NoteController_Init, &NoteController::Init, void, NoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity, float endRotation, float uniformScale, bool rotateTowardsPlayer, bool useRandomRotation)
{
    NoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity, endRotation, uniformScale, rotateTowardsPlayer, useRandomRotation);
    
    if (self->noteData->colorType == ColorType::ColorA)
    {
        GameObject::Destroy(self->get_gameObject());
    }
}