#include "main.hpp"
#include "ModConfig.hpp"
#include "UI/AccessAbilityUI.hpp"

#include "bs-utils/shared/utils.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
using namespace GlobalNamespace;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/RectOffset.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;

static ModInfo modInfo;

DEFINE_TYPE(AccessAbility::UI, AccessAbilityUI);

#define SetPreferredSize(identifier, width, height)                                         \
    auto layout##identifier = identifier->get_gameObject()->GetComponent<LayoutElement*>(); \
    if (!layout##identifier)                                                                \
        layout##identifier = identifier->get_gameObject()->AddComponent<LayoutElement*>();  \
    layout##identifier->set_preferredWidth(width);                                          \
    layout##identifier->set_preferredHeight(height);                                        \
    auto fitter##identifier = identifier->GetComponent<ContentSizeFitter*>();               \
    fitter##identifier->set_verticalFit(ContentSizeFitter::FitMode::PreferredSize);         \
    fitter##identifier->set_horizontalFit(ContentSizeFitter::FitMode::PreferredSize)

void AccessAbility::UI::AccessAbilityUI::DidActivate(bool firstActivation)
{
    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;

    if (firstActivation)
    {
        auto container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        container->get_rectTransform()->set_anchoredPosition({0, 0});
        container->set_padding(RectOffset::New_ctor(2, 2, 2, 2));
        container->set_spacing(1.0f);
        SetPreferredSize(container, 70.0f, 60.0f);

        BeatSaberUI::CreateToggle(container->get_transform(), "Enabled", getModConfig().Enabled.GetValue(), [](bool value)
        {
            getModConfig().Enabled.SetValue(value);
        });


        BeatSaberUI::CreateToggle(container->get_transform(), "Left Saber Enabled", getModConfig().LeftSaberToggle.GetValue(), [](bool value)
        {
            getModConfig().LeftSaberToggle.SetValue(value);

            value ? bs_utils::Submission::enable(modInfo) : bs_utils::Submission::disable(modInfo);
        });

        BeatSaberUI::CreateToggle(container->get_transform(), "Right Saber Enabled", getModConfig().RightSaberToggle.GetValue(), [](bool value)
        {
            getModConfig().RightSaberToggle.SetValue(value);

            value ? bs_utils::Submission::enable(modInfo) : bs_utils::Submission::disable(modInfo);
        });

        BeatSaberUI::CreateToggle(container->get_transform(), "", getModConfig().DisableWalls.GetValue(), [&](bool value)
        {
            playerData->gameplayModifiers->enabledObstacleType = value;
        });

    }
}