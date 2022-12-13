#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/NoteVisualModifierType.hpp"
#include "GlobalNamespace/ColorType.hpp"

#include "GlobalNamespace/SliderController.hpp"
#include "GlobalNamespace/SliderData.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(NoteController_Init, &NoteController::Init, void, NoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity, float endRotation, float uniformScale, bool rotateTowardsPlayer, bool useRandomRotation)
{
    NoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity, endRotation, uniformScale, rotateTowardsPlayer, useRandomRotation);

    if (self->noteData->colorType == ColorType::ColorA && getModConfig().LeftSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
    {
        self->get_gameObject()->SetActive(false);
        //Object::Destroy(self);
    }
    else if (self->noteData->colorType == ColorType::ColorB && getModConfig().RightSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
    {
        self->get_gameObject()->SetActive(false);
        //Object::Destroy(self);
    }
}


// Don't work sadge
MAKE_AUTO_HOOK_MATCH(SliderController_Init, &SliderController::Init, void, SliderController *self, SliderController::LengthType lengthType, SliderData *sliderData, float worldRotation, Vector3 headNoteJumpStartPos, Vector3 tailNoteJumpStartPos, Vector3 headNoteJumpEndPos, Vector3 tailNoteJumpEndPos, float jumpDuration, float startNoteJumpGravity, float endNoteJumpGravity, float noteUniformScale)
{
    SliderController_Init(self, lengthType, sliderData, worldRotation, headNoteJumpStartPos, tailNoteJumpStartPos, headNoteJumpEndPos, tailNoteJumpEndPos, jumpDuration, startNoteJumpGravity, endNoteJumpGravity, noteUniformScale);

    if (self->sliderData->colorType == ColorType::ColorA && getModConfig().LeftSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
    
       self->get_gameObject()->SetActive(false);
    
    else if (self->sliderData->colorType == ColorType::ColorB && getModConfig().RightSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
    {
       self->get_gameObject()->SetActive(false);
    }
}