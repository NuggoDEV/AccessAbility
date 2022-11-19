#include "main.hpp"
#include "ModConfig.hpp"
#include "UI/AccessAbilityUI.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(AccessAbility::UI, AccessAbilityUI);

void AccessAbility::UI::AccessAbilityUI::DidActivate(bool firstActivation)
{
    if (firstActivation)
    {
        auto container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        BeatSaberUI::CreateToggle(container->get_transform(), "Enabled", getModConfig().Enabled.GetValue(), [](bool value)
        {
            getModConfig().Enabled.SetValue(value);
        });


        BeatSaberUI::CreateToggle(container->get_transform(), "Left Saber Enabled", getModConfig().LeftSaberToggle.GetValue(), [](bool value)
        {
            getModConfig().LeftSaberToggle.SetValue(value);
        });

        BeatSaberUI::CreateToggle(container->get_transform(), "Right Saber Enabled", getModConfig().RightSaberToggle.GetValue(), [](bool value)
        {
            getModConfig().RightSaberToggle.SetValue(value);
        });
    }
}