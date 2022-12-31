#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/NoteData.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/NoteVisualModifierType.hpp"
#include "GlobalNamespace/ColorType.hpp"
#include "GlobalNamespace/BeatmapObjectData.hpp"

#include "GlobalNamespace/SliderController.hpp"
#include "GlobalNamespace/SliderData.hpp"
#include "GlobalNamespace/IReadonlyBeatmapData.hpp"
#include "GlobalNamespace/BeatmapDataTransformHelper.hpp"
#include "GlobalNamespace/EnvironmentEffectsFilterPreset.hpp"
#include "GlobalNamespace/EnvironmentIntensityReductionOptions.hpp"
#include "GlobalNamespace/MainSettingsModelSO.hpp"
#include "GlobalNamespace/SliderMeshController.hpp"
#include "GlobalNamespace/BeatmapObjectSpawnController.hpp"
#include "GlobalNamespace/BeatmapObjectsInstaller.hpp"
#include "GlobalNamespace/BeatmapObjectManager.hpp"
#include "GlobalNamespace/BeatmapObjectSpawnMovementData.hpp"

#include "GlobalNamespace/BeatLine.hpp"
#include "GlobalNamespace/BeatmapDataItem.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

SliderMeshController sliderMeshController;
SliderController sliderController;
SliderData sliderData;

MAKE_AUTO_HOOK_MATCH(NoteController_Init, &NoteController::Init, void, NoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity, float endRotation, float uniformScale, bool rotateTowardsPlayer, bool useRandomRotation)
{
    NoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity, endRotation, uniformScale, rotateTowardsPlayer, useRandomRotation);

    if (self->noteData->colorType == ColorType::ColorA && getModConfig().LeftSaberToggle.GetValue() && getModConfig().ModToggle.GetValue())
    {

        self->Dissolve(0.001f);
        self->NoteDidStartDissolving();
        self->SendNoteWasMissedEvent();
    }
    else if (self->noteData->colorType == ColorType::ColorB && getModConfig().RightSaberToggle.GetValue() && getModConfig().ModToggle.GetValue())
    {
        self->Dissolve(0.001f);
        self->NoteDidStartDissolving();
        self->SendNoteWasMissedEvent();
    }
}