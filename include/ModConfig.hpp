#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(Enabled, bool, "Enabled", false);
    CONFIG_VALUE(LeftSaberToggle, bool, "Left Saber Enabled", true);
    CONFIG_VALUE(RightSaberToggle, bool, "Right Saber Enabled", true);
    CONFIG_VALUE(DisableCrouch, bool, "Disable Crouch Walls", false);
    CONFIG_VALUE(DisableWalls, bool, "Disable Walls", false);
    CONFIG_VALUE(YeetSliders, bool, "Removes Sliders", false);
)