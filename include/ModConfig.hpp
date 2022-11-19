#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(Enabled, bool, "Enabled", false);
    CONFIG_VALUE(LeftSaberToggle, bool, "Left Saber Enabled", true);
    CONFIG_VALUE(RightSaberToggle, bool, "Right Saber Enabled", true);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(Enabled);
        CONFIG_INIT_VALUE(LeftSaberToggle);
        CONFIG_INIT_VALUE(RightSaberToggle);
    )
)