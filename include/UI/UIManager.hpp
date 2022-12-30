#pragma once
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML/Components/TextGradientUpdater.hpp"
#include "bsml/shared/BSML/Tags/TextTag.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(AccessAbility::UI, UIManager, Il2CppObject,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);

    DECLARE_INSTANCE_METHOD(void, ScoringTextEnabled, bool isEnabled);
    DECLARE_INSTANCE_METHOD(void, CheckScoreSub);

    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, ScoreTextE);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, ScoreTextD);

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