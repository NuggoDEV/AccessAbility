#include "main.hpp"

#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "bs-utils/shared/utils.hpp"

#include "GlobalNamespace/MainMenuViewController.hpp"
using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    if (!getModConfig().Enabled.GetValue())
        bs_utils::Submission::enable(ModInf());
    else if (getModConfig().Enabled.GetValue() and getModConfig().LeftSaberToggle.GetValue() or getModConfig().RightSaberToggle.GetValue() or getModConfig().YeetCrouchWalls.GetValue() or getModConfig().YeetBombs.GetValue())
    {
        bs_utils::Submission::disable(ModInf());
    }
    else if (getModConfig().Enabled.GetValue())
        bs_utils::Submission::enable(ModInf());
}