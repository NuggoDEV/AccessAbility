#pragma once

#include "main.hpp"

#include "custom-types/shared/macros.hpp"
#include "UnityEngine/MonoBehaviour.hpp"

DECLARE_CLASS_CODEGEN(AccessAbility::UI, AccessAbilityUI, UnityEngine::MonoBehaviour,

    DECLARE_INSTANCE_METHOD(void, DidActivate, bool firstActivation);
)