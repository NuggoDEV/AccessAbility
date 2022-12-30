#include "main.hpp"
#include "UI/UIManager.hpp"

#include "ModConfig.hpp"
#include "bs-utils/shared/utils.hpp"

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



    void UIManager::ScoringTextEnabled(bool isEnabled)
    {
        
        
    }

    void UIManager::CheckScoreSub()
    {
        if (!bs_utils::Submission::getEnabled())
        {
            ScoreTextE->SetActive(false);
            ScoreTextD->SetActive(true);
        }
        else
        {
            ScoreTextE->SetActive(true);
            ScoreTextD->SetActive(false);
        }
        //if (getModConfig().ModToggle.GetValue() and getModConfig().LeftSaberToggle.GetValue() or getModConfig().RightSaberToggle.GetValue() or getModConfig().YeetCrouchWalls.GetValue() or getModConfig().YeetBombs.GetValue())
        //{
        //    bs_utils::Submission::disable(ModInf());
        //    ScoreTextE->SetActive(false);
        //    ScoreTextD->SetActive(true);
        //}
        //else
        //{
        //    bs_utils::Submission::enable(ModInf());
        //    ScoreTextE->SetActive(true);
        //    ScoreTextD->SetActive(false);
        //}
    }


    bool UIManager::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void UIManager::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value); }

    bool UIManager::get_LeftSaberToggle() { return getModConfig().LeftSaberToggle.GetValue(); }
    void UIManager::set_LeftSaberToggle(bool value) 
    { 
        getModConfig().LeftSaberToggle.SetValue(value); 
        if (getModConfig().ModToggle.GetValue() && value)
            bs_utils::Submission::disable(ModInf());
        else
            bs_utils::Submission::enable(ModInf());
    }

    bool UIManager::get_RightSaberToggle() { return getModConfig().RightSaberToggle.GetValue(); }
    void UIManager::set_RightSaberToggle(bool value) 
    { 
        getModConfig().RightSaberToggle.SetValue(value);
        if (getModConfig().ModToggle.GetValue() && value)
            bs_utils::Submission::disable(ModInf());
        else
            bs_utils::Submission::enable(ModInf());
    }

    bool UIManager::get_YeetCrouchWalls() { return getModConfig().YeetCrouchWalls.GetValue(); }
    void UIManager::set_YeetCrouchWalls(bool value) 
    { 
        getModConfig().YeetCrouchWalls.SetValue(value);
        if (getModConfig().ModToggle.GetValue() && value)
            bs_utils::Submission::disable(ModInf());
        else
            bs_utils::Submission::enable(ModInf());
    }

    bool UIManager::get_YeetBombs() { return getModConfig().YeetBombs.GetValue(); }
    void UIManager::set_YeetBombs(bool value) 
    { 
        getModConfig().YeetBombs.SetValue(value);
        if (getModConfig().ModToggle.GetValue() && value)
            bs_utils::Submission::disable(ModInf());
        else
            bs_utils::Submission::enable(ModInf());
    }

    bool UIManager::get_SeatedMode() { return getModConfig().SeatedMode.GetValue(); }
    void UIManager::set_SeatedMode(bool value) { getModConfig().SeatedMode.SetValue(value); }

}