#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(Enabled, bool, "Enabled", false);
    CONFIG_VALUE(LeftSaberToggle, bool, "Left Saber Enabled", true);
    CONFIG_VALUE(RightSaberToggle, bool, "Right Saber Enabled", true);
    CONFIG_VALUE(DisableCrouch, bool, "Disable Crouch Walls", false);
    CONFIG_VALUE(DisableWalls, bool, "Disable Walls", false);
    CONFIG_VALUE(ConvertSliders, bool, "Convert Sliders", false);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(Enabled);
        CONFIG_INIT_VALUE(LeftSaberToggle);
        CONFIG_INIT_VALUE(RightSaberToggle);
        CONFIG_INIT_VALUE(DisableCrouch);
        CONFIG_INIT_VALUE(DisableWalls);
        CONFIG_INIT_VALUE(ConvertSliders);
    )
)
// Gotta fix stuff now >:(

// Nah just gonna downgrade Config-Utils for now lol