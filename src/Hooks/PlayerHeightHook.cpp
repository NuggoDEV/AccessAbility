#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/LevelSelectionFlowCoordinator.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"

#include "GlobalNamespace/StandardLevelScenesTransitionSetupDataSO.hpp"
#include "GlobalNamespace/IDifficultyBeatmap.hpp"
#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/OverrideEnvironmentSettings.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
#include "GlobalNamespace/PracticeSettings.hpp"
#include "GlobalNamespace/BeatmapDataCache.hpp"
using namespace GlobalNamespace;

float oldPlayerHeight;

MAKE_AUTO_HOOK_MATCH(fesg, &StandardLevelScenesTransitionSetupDataSO::Init, void, StandardLevelScenesTransitionSetupDataSO *self,
StringW gameMode, IDifficultyBeatmap *difficultyBeatmap, IPreviewBeatmapLevel *previewBeatmapLevel, OverrideEnvironmentSettings *overrideEnvironmentSettings,
ColorScheme *overrideColorScheme, GameplayModifiers *gameplayModifiers, PlayerSpecificSettings *playerSpecificSettings, PracticeSettings *practiceSettings,
StringW backButtonText, bool useTestNoteCutSoundEffects, bool startPaused, BeatmapDataCache *beatmapDataCache)
{
    fesg(self, gameMode, difficultyBeatmap, previewBeatmapLevel, overrideEnvironmentSettings, overrideColorScheme,
    gameplayModifiers, playerSpecificSettings, practiceSettings, backButtonText, useTestNoteCutSoundEffects, startPaused, beatmapDataCache);

    oldPlayerHeight = playerSpecificSettings->get_playerHeight();

    if (getModConfig().SeatedMode.GetValue())
        playerSpecificSettings->playerHeight = 1.3f;
}


MAKE_AUTO_HOOK_MATCH(LevelSelectionFlowCoordinator_DidActivate, &LevelSelectionFlowCoordinator::DidActivate, void, LevelSelectionFlowCoordinator *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    LevelSelectionFlowCoordinator_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;
    auto playerSpecificSettings = playerData->playerSpecificSettings;

    if (getModConfig().SeatedMode.GetValue())
        playerSpecificSettings->playerHeight = oldPlayerHeight;
}