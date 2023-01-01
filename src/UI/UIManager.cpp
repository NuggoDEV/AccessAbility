#include "main.hpp"
#include "UI/UIManager.hpp"

#include "ModConfig.hpp"
#include "bs-utils/shared/utils.hpp"

#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/WaitForSeconds.hpp"
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
    void UIManager::ctor() { }



    void UIManager::ScoringTextEnabled()
    {
        if (bs_utils::Submission::getEnabled())
        {
            ScoreTextE->SetActive(true);
            ScoreTextD->SetActive(false);
        }
        else
        {
            ScoreTextE->SetActive(false);
            ScoreTextD->SetActive(true);
        }
    }


    void UIManager::ScoreSubmissionChecker()
    {
        if (!getModConfig().ModToggle.GetValue())
            bs_utils::Submission::enable(ModInf());
        else if (getModConfig().LeftSaberToggle.GetValue() || getModConfig().RightSaberToggle.GetValue() || getModConfig().YeetCrouchWalls.GetValue() || getModConfig().YeetBombs.GetValue())
            bs_utils::Submission::disable(ModInf());
        else if (getModConfig().ModToggle.GetValue() && !getModConfig().LeftSaberToggle.GetValue() || !getModConfig().RightSaberToggle.GetValue() || !getModConfig().YeetCrouchWalls.GetValue() || !getModConfig().YeetBombs.GetValue())
            bs_utils::Submission::enable(ModInf());

        ScoringTextEnabled();
    }

    void UIManager::RefreshScoreSub()
    {
        getModConfig().Save();
        ScoreSubmissionChecker();
    }

    
    void UIManager::PostParse()
    {
        ScoreSubmissionChecker();
    }

    bool UIManager::get_ModToggle() { return getModConfig().ModToggle.GetValue(); }
    void UIManager::set_ModToggle(bool value) { getModConfig().ModToggle.SetValue(value, false); }

    bool UIManager::get_LeftSaberToggle() { return getModConfig().LeftSaberToggle.GetValue(); }
    void UIManager::set_LeftSaberToggle(bool value) { getModConfig().LeftSaberToggle.SetValue(value, false); }

    bool UIManager::get_RightSaberToggle() { return getModConfig().RightSaberToggle.GetValue(); }
    void UIManager::set_RightSaberToggle(bool value) { getModConfig().RightSaberToggle.SetValue(value, false);}

    bool UIManager::get_YeetCrouchWalls() { return getModConfig().YeetCrouchWalls.GetValue(); }
    void UIManager::set_YeetCrouchWalls(bool value) { getModConfig().YeetCrouchWalls.SetValue(value, false); }

    bool UIManager::get_YeetBombs() { return getModConfig().YeetBombs.GetValue(); }
    void UIManager::set_YeetBombs(bool value) { getModConfig().YeetBombs.SetValue(value, false); }

    bool UIManager::get_SeatedMode() { return getModConfig().SeatedMode.GetValue(); }
    void UIManager::set_SeatedMode(bool value) { getModConfig().SeatedMode.SetValue(value); }

}