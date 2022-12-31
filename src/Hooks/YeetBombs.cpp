#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"


#include "GlobalNamespace/BombNoteController.hpp"
#include "GlobalNamespace/NoteData.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;


MAKE_AUTO_HOOK_MATCH(BombNoteController_Init, &BombNoteController::Init, void, BombNoteController *self, NoteData *noteData, float worldRotation, Vector3 moveStartPos, Vector3 moveEndPos, Vector3 jumpEndPos, float moveDuration, float jumpDuration, float jumpGravity)
{
    BombNoteController_Init(self, noteData, worldRotation, moveStartPos, moveEndPos, jumpEndPos, moveDuration, jumpDuration, jumpGravity);

    if (getModConfig().ModToggle.GetValue() && getModConfig().YeetBombs.GetValue())
    {
        self->get_gameObject()->SetActive(false);
    }
}