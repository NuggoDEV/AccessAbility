#pragma once
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML/Components/TextGradientUpdater.hpp"
#include "bsml/shared/BSML/Tags/TextTag.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CLASS_CODEGEN(AccessAbility::UI, UIManager, Il2CppObject,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);

    DECLARE_BSML_PROPERTY(bool, ModToggle);
    DECLARE_BSML_PROPERTY(bool, LeftSaberToggle);
    DECLARE_BSML_PROPERTY(bool, RightSaberToggle);
    DECLARE_BSML_PROPERTY(bool, YeetCrouchWalls);
    DECLARE_BSML_PROPERTY(bool, YeetBombs);
    DECLARE_BSML_PROPERTY(bool, SeatedMode);

    DECLARE_CTOR(ctor);
    public:
        static UIManager *get_instance();
    private:
        static SafePtr<UIManager> instance;
)