#include "main.hpp"
#include "ModConfig.hpp"
#include "UI/AccessAbilityUI.hpp"
using namespace AccessAbility::UI;

#include "bs-utils/shared/utils.hpp"

#include "GlobalNamespace/PlayerDataFileManagerSO.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
using namespace GlobalNamespace;

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/RectOffset.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;

static ModInfo modInfo;

DEFINE_TYPE(AccessAbility::UI, AccessAbilityUI);

// Taken from Speecil's mod, Pause Remapper: https://github.com/speecil/PauseRemapper/blob/main/src/UI/GameplaySettingsView.cpp#L25
#define SetPreferredSize(identifier, width, height)                                         \
    auto layout##identifier = identifier->get_gameObject()->GetComponent<LayoutElement*>(); \
    if (!layout##identifier)                                                                \
        layout##identifier = identifier->get_gameObject()->AddComponent<LayoutElement*>();  \
    layout##identifier->set_preferredWidth(width);                                          \
    layout##identifier->set_preferredHeight(height);                                        \
    auto fitter##identifier = identifier->GetComponent<ContentSizeFitter*>();               \
    fitter##identifier->set_verticalFit(ContentSizeFitter::FitMode::PreferredSize);         \
    fitter##identifier->set_horizontalFit(ContentSizeFitter::FitMode::PreferredSize)


TMPro::TextMeshProUGUI *scoreSub;

void AccessAbilityUI::DidActivate(bool firstActivation)
{
    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;
    auto playerHeight = playerData->playerSpecificSettings;

    if (playerHeight->automaticPlayerHeight == true)
        playerHeight->automaticPlayerHeight = false;

    if (firstActivation)
    {
        

        auto container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        container->get_rectTransform()->set_anchoredPosition({0, 0});
        container->set_padding(RectOffset::New_ctor(2, 2, 2, 2));
        container->set_spacing(1.0f);
        SetPreferredSize(container, 70.0f, 60.0f);

        

        auto enable = BeatSaberUI::CreateToggle(container->get_transform(), "Enabled", getModConfig().Enabled.GetValue(), [](bool value)
        {   getModConfig().Enabled.SetValue(value);    });
        BeatSaberUI::AddHoverHint(enable->get_gameObject(), "Enables or disables the mod.");

        auto leftSaber = BeatSaberUI::CreateToggle(container->get_transform(), "Disable Left Saber", getModConfig().LeftSaberToggle.GetValue(), [](bool value)
        {   getModConfig().LeftSaberToggle.SetValue(value);    });
        BeatSaberUI::AddHoverHint(leftSaber->get_gameObject(), "Removes all notes that use the left saber.");

        auto rightSaber = BeatSaberUI::CreateToggle(container->get_transform(), "Disable Right Saber", getModConfig().RightSaberToggle.GetValue(), [](bool value)
        {   getModConfig().RightSaberToggle.SetValue(value);    });
        BeatSaberUI::AddHoverHint(rightSaber->get_gameObject(), "Removes all notes that use the right saber.");

        auto crouchWalls = BeatSaberUI::CreateToggle(container->get_transform(), "Yeet Crouch Walls", getModConfig().YeetCrouchWalls.GetValue(), [&](bool value)
        {   getModConfig().YeetCrouchWalls.SetValue(value);   });
        BeatSaberUI::AddHoverHint(crouchWalls->get_gameObject(), "Yeets walls that require you to crouch.");

        auto bombs = BeatSaberUI::CreateToggle(container->get_transform(), "Yeet Bombs", getModConfig().YeetBombs.GetValue(), [](bool value)
        {   getModConfig().YeetBombs.SetValue(value);   });
        BeatSaberUI::AddHoverHint(bombs->get_gameObject(), "Yeets all bombs because who likes them.");

        auto cripple = BeatSaberUI::CreateToggle(container->get_transform(), "Cripple Mode", getModConfig().CrippleMode.GetValue(), [playerHeight](bool value)
        {



            if (value == true)
            {
                getModConfig().HeightPreCrippleMode.SetValue(playerHeight->get_playerHeight());
                
                playerHeight->playerHeight = 1.3f;
                getModConfig().CrippleMode.SetValue(value);
            }
            else
            {
                playerHeight->playerHeight = getModConfig().HeightPreCrippleMode.GetValue();
            }
        });
        BeatSaberUI::AddHoverHint(cripple->get_gameObject(), "Disables automatic player height and sets player height to 1.3m. Also recommended to change Y axis in room settings to something in the minus range.");

        scoreSub = BeatSaberUI::CreateText(container->get_transform(), "");
        scoreSub->set_fontSize(4.0f);
        scoreSub->set_alignment(TMPro::TextAlignmentOptions::Center);

    }
}

void AccessAbilityUI::Update()
{
    if (bs_utils::Submission::getEnabled() == true)
    {
        if (!getModConfig().Enabled.GetValue())
            bs_utils::Submission::enable(ModInf());
        else if (getModConfig().Enabled.GetValue() and getModConfig().LeftSaberToggle.GetValue() or getModConfig().RightSaberToggle.GetValue() or getModConfig().YeetCrouchWalls.GetValue() or getModConfig().YeetBombs.GetValue())
        {
            bs_utils::Submission::disable(ModInf());
        }
        else if (getModConfig().Enabled.GetValue())
            bs_utils::Submission::enable(ModInf());
    }

    if (bs_utils::Submission::getEnabled() == false)
    {
        scoreSub->set_text("Score Submission: Disabled");
        scoreSub->set_color(Color::get_red());
    }
    else
    {
        scoreSub->set_text("Score Submission: Enabled");
        scoreSub->set_color(Color::get_green());
    }
}