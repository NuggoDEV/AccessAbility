#include "UI/UIManager.hpp"

#include "ModConfig.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DEFINE_TYPE(AccessAbility::UI, UIManager);

namespace AccessAbility::UI
{
    SafePtr<UIManager> UIManager::instance;
    UIManager *UIManager::get_instance()
    {
        if (!instance)
            instance = UIManager::New_ctor();
        return instance.ptr();
    }

    void UIManager::ctor()
    {

    }

    bool UIManager::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void UIManager::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }

    bool UIManager::get_LeftSaberToggle() { return getModConfig().LeftSaberToggle.GetValue(); }
    void UIManager::set_LeftSaberToggle(bool value) { getModConfig().LeftSaberToggle.SetValue(value); }

    bool UIManager::get_RightSaberToggle() { return getModConfig().RightSaberToggle.GetValue(); }
    void UIManager::set_RightSaberToggle(bool value) { getModConfig().RightSaberToggle.SetValue(value); }

    bool UIManager::get_YeetCrouchWalls() { return getModConfig().YeetCrouchWalls.GetValue(); }
    void UIManager::set_YeetCrouchWalls(bool value) { getModConfig().YeetCrouchWalls.SetValue(value); }

    bool UIManager::get_YeetBombs() { return getModConfig().YeetBombs.GetValue(); }
    void UIManager::set_YeetBombs(bool value) { getModConfig().YeetBombs.SetValue(value); }

    bool UIManager::get_SeatedMode() { return getModConfig().SeatedMode.GetValue(); }
    void UIManager::set_SeatedMode(bool value) { getModConfig().SeatedMode.SetValue(value); }

}