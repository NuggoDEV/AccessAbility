#include "main.hpp"
static ModInfo modInfo;

#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "bs-utils/shared/utils.hpp"

#include "GlobalNamespace/MainMenuViewController.hpp"
using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    if (getModConfig().Enabled.GetValue() && getModConfig().LeftSaberToggle.GetValue() || getModConfig().RightSaberToggle.GetValue() || getModConfig().YeetBombs.GetValue() || getModConfig().YeetCrouchWalls.GetValue())
    {
        bs_utils::Submission::disable(modInfo);
    }
}