#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/GameNoteController.hpp"
#include "GlobalNamespace/BeatmapDataTransformHelper.hpp"
#include "GlobalNamespace/IReadonlyBeatmapData.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/EnvironmentEffectsFilterPreset.hpp"
#include "GlobalNamespace/EnvironmentIntensityReductionOptions.hpp"
#include "GlobalNamespace/MainSettingsModelSO.hpp"

#include "GlobalNamespace/SliderController.hpp"
#include "GlobalNamespace/SliderData.hpp"

#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/NoteVisualModifierType.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(WorkDumbHook, &BeatmapDataTransformHelper::CreateTransformedBeatmapData, IReadonlyBeatmapData, GlobalNamespace::IReadonlyBeatmapData* beatmapData, GlobalNamespace::IPreviewBeatmapLevel* beatmapLevel, GlobalNamespace::GameplayModifiers* gameplayModifiers, bool leftHanded, GlobalNamespace::EnvironmentEffectsFilterPreset environmentEffectsFilterPreset, GlobalNamespace::EnvironmentIntensityReductionOptions* environmentIntensityReductionOptions, GlobalNamespace::MainSettingsModelSO* mainSettingsModel)
{
    WorkDumbHook(beatmapData, beatmapLevel, gameplayModifiers, leftHanded, environmentEffectsFilterPreset, environmentIntensityReductionOptions, mainSettingsModel);
}


















//MAKE_AUTO_HOOK_MATCH(CSH_NoteController_Init, &NoteController::Init, void, NoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity, float endRotation, float uniformScale, bool rotateTowardsPlayer, bool useRandomRotation)
//{
//    CSH_NoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity, endRotation, uniformScale, rotateTowardsPlayer, useRandomRotation);
//
//    if (getModConfig().YeetSliders.GetValue())
//    {
//        self->get_gameObject()->SetActive(false);
//    }
//}

//MAKE_AUTO_HOOK_MATCH(a, &SliderController::Init, void, SliderController *self, SliderController::LengthType lengthType, SliderData *sliderData, float worldRotation, Vector3 headNoteJumpStartPos, Vector3 tailNoteJumpStartPos, Vector3 headNoteJumpEndPos, Vector3 tailNoteJumpEndPos, float jumpDuration, float startNoteJumpGravity, float endNoteJumpGravity, float noteUniformScale)
//{
//    a(self, lengthType, sliderData, worldRotation, headNoteJumpStartPos, tailNoteJumpStartPos, headNoteJumpEndPos, tailNoteJumpEndPos, jumpDuration, startNoteJumpGravity, endNoteJumpGravity, noteUniformScale);
//
//    if (getModConfig().YeetSliders.GetValue())
//    {
//        //self->get_gameObject()->SetActive(false);
//    }
//}

