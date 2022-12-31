#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ModToggle, bool, "Mod Toggle", false);
    CONFIG_VALUE(LeftSaberToggle, bool, "Left Saber Enabled", false);
    CONFIG_VALUE(RightSaberToggle, bool, "Right Saber Enabled", false);
    CONFIG_VALUE(YeetCrouchWalls, bool, "Disable Crouch Walls", false);
    CONFIG_VALUE(YeetBombs, bool, "Yeets Bombs", false);
    CONFIG_VALUE(SeatedMode, bool, "Seated Mode", false);
    CONFIG_VALUE(HeightPreSeatedMode, float, "Height Before Seated Mode Invaded", 0.0f);
)