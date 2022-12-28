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

    if (self->noteData->colorType == ColorType::ColorA && getModConfig().LeftSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
    {

        self->Dissolve(0.001f);
        self->NoteDidStartDissolving();
        self->SendNoteWasMissedEvent();
        //self->DissolveCoroutine(0.001f);
        //self->get_gameObject()->SetActive(false);
        //Object::Destroy(self);
    }
    else if (self->noteData->colorType == ColorType::ColorB && getModConfig().RightSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
    {
        self->Dissolve(0.001f);
        self->NoteDidStartDissolving();
        self->SendNoteWasMissedEvent();
        //self->DissolveCoroutine(0.001f);
        //self->get_gameObject()->SetActive(false);
        //Object::Destroy(self);
    }
}









// Don't work sadge
//MAKE_AUTO_HOOK_MATCH(SliderController_Init, &SliderController::Init, void, SliderController *self, SliderController::LengthType lengthType, SliderData *sliderData, float worldRotation, Vector3 headNoteJumpStartPos, Vector3 tailNoteJumpStartPos, Vector3 headNoteJumpEndPos, Vector3 tailNoteJumpEndPos, float jumpDuration, float startNoteJumpGravity, float endNoteJumpGravity, float noteUniformScale)
//{
//    SliderController_Init(self, lengthType, sliderData, worldRotation, headNoteJumpStartPos, tailNoteJumpStartPos, headNoteJumpEndPos, tailNoteJumpEndPos, jumpDuration, startNoteJumpGravity, endNoteJumpGravity, noteUniformScale);
//    
//    //self->get_gameObject()->SetActive(false);
//
//    if (self->sliderData->colorType == ColorType::ColorA && getModConfig().LeftSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
//    {
//        getLogger().info("Disabling Left Arc");
//    }
//    else if (self->sliderData->colorType == ColorType::ColorB && getModConfig().RightSaberToggle.GetValue() && getModConfig().Enabled.GetValue())
//    {
//        getLogger().info("Disabling Right Arc");
//    }
//}



//MAKE_AUTO_HOOK_MATCH(BDTH_CTBD, &BeatmapDataTransformHelper::CreateTransformedBeatmapData, GlobalNamespace::IReadonlyBeatmapData*, ::GlobalNamespace::IReadonlyBeatmapData* beatmapData, ::GlobalNamespace::IPreviewBeatmapLevel* beatmapLevel, ::GlobalNamespace::GameplayModifiers* gameplayModifiers, bool leftHanded, ::GlobalNamespace::EnvironmentEffectsFilterPreset environmentEffectsFilterPreset, ::GlobalNamespace::EnvironmentIntensityReductionOptions* environmentIntensityReductionOptions, ::GlobalNamespace::MainSettingsModelSO* mainSettingsModel)
//{
//    auto result = BDTH_CTBD(beatmapData, beatmapLevel, gameplayModifiers, leftHanded, environmentEffectsFilterPreset, environmentIntensityReductionOptions, mainSettingsModel);
//
//    SliderData sliderData;
//
//    if (sliderData.sliderType == SliderData::Type::Normal)
//    {
//        
//
//        if (sliderData.colorType == ColorType::ColorA && getModConfig().LeftSaberToggle.GetValue())
//        {
//            sliderMeshController.get_gameObject()->set_active(false);
//            //sliderMeshController.set_enabled(false);
//            
//            //for(auto go : UnityEngine::Resources::FindObjectsOfTypeAll<UnityEngine::GameObject*>()) 
//            //    go->SetActive(false);
//        }//
//    }
//
//
//    return result;
//}


//MAKE_AUTO_HOOK_MATCH(bdsg, &::GlobalNamespace::BeatmapObjectManager::AddSpawnedSliderController, void, ::GlobalNamespace::BeatmapObjectManager *self, ::GlobalNamespace::SliderController *sliderController, ::GlobalNamespace::BeatmapObjectSpawnMovementData::SliderSpawnData sliderSpawnData, float rotation)
//{
//    bdsg(self, sliderController, sliderSpawnData, rotation);
//
//    BeatmapObjectSpawnController dsfgb;
//    
//    if (getModConfig().LeftSaberToggle.GetValue())
//        dsfgb.StopSpawning();
//}