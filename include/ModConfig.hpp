#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(Enabled, bool, "Enabled", false);
    CONFIG_VALUE(LeftSaberToggle, bool, "Left Saber Enabled", false);
    CONFIG_VALUE(RightSaberToggle, bool, "Right Saber Enabled", false);
    CONFIG_VALUE(YeetCrouchWalls, bool, "Disable Crouch Walls", false);
    CONFIG_VALUE(YeetBombs, bool, "Yeets Bombs", false);
    CONFIG_VALUE(CrippleMode, bool, "Cripple Mode", false);
    CONFIG_VALUE(HeightPreCrippleMode, float, "Height Before Cripple Mode Invaded", 0.0f);
)