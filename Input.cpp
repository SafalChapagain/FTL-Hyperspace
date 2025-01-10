#include "Global.h"
#include "CustomCommandGui.h"
#include "CustomCrewManifest.h"
#include "ShipZoom.h"
#include "ScrollingChoiceBox.h"
#include "RedesignedTooltips.h"

static void OnScrollWheel(float direction)
{
    CApp *cApp = G_->GetCApp();

    if (!cApp->langChooser.bOpen)
    {
        if (!cApp->menu.bOpen)
        {
            if (ScrollingTooltip::OnScrollWheel(direction))
            {

            }
            else if (ScrollingChoiceBox::OnScrollWheel(direction))
            {

            }
            else if (cApp->gui->crewScreen.bOpen)
            {
                CustomCrewManifest::GetInstance()->OnScrollWheel(direction);
            }
            else
            {
                CustomCommandGui::GetInstance()->OnScrollWheel(direction);
            }
        }
    }
}

HOOK_METHOD(CEvent, OnEvent, (const InputEvent* inputEvent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CEvent::OnEvent -> Begin (Input.cpp)\n")
    if (inputEvent->type == InputEventType::INPUT_EVENT_MOUSE)
    {
        MouseInputEvent *mEvent = (MouseInputEvent*)(&inputEvent->event);

        if (mEvent->scroll != 0.f)
        {
            OnScrollWheel(mEvent->scroll);
        }
    }

    super(inputEvent);
}
