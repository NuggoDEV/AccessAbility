#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(Enabled, bool, "Enabled", false);
    CONFIG_VALUE(LeftSaberToggle, bool, "Left Saber Enabled", false);
    CONFIG_VALUE(RightSaberToggle, bool, "Right Saber Enabled", false);
    CONFIG_VALUE(DisableCrouch, bool, "Disable Crouch Walls", false);
    CONFIG_VALUE(NiceWalls, bool, "Makes Walls Nice", false);
    CONFIG_VALUE(YeetSliders, bool, "Removes Sliders", false);
)