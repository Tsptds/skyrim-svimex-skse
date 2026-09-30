#include "InputHandler.h"

#include "Swimming.h"

namespace InputHandler
{
    Listener *Listener::GetSingleton()
    {
        static Listener singleton;
        return &singleton;
    }

    RE::BSEventNotifyControl Listener::ProcessEvent(RE::InputEvent *const *a_event, RE::BSTEventSource<RE::InputEvent *> *)
    {
        if (!a_event)
        {
            return RE::BSEventNotifyControl::kContinue;
        }

        for (auto *event = *a_event; event; event = event->next)
        {
            const auto *button = event->AsButtonEvent();
            if (!button || !(button->IsDown() || button->IsHeld()))
            {
                continue;
            }

            if (button->QUserEvent() == "Sneak"sv)
            {
                auto pl = RE::PlayerCharacter::GetSingleton();
                if (auto st = pl->AsActorState(); st->IsSwimming())
                {
                    if (!Swimming::g_isUnderwater)
                    {
                        pl->NotifyAnimationGraph("Svimex_Submerge");
                        Swimming::ToggleDive(pl);
                    }
                }
            }
        }

        return RE::BSEventNotifyControl::kContinue;
    }

    void Register()
    {
        auto *deviceManager = RE::BSInputDeviceManager::GetSingleton();
        if (!deviceManager)
        {
            ERROR("BSInputDeviceManager unavailable, sneak listener not registered");
            return;
        }

        deviceManager->AddEventSink(Listener::GetSingleton());
        INFO("Input listener registered");
    }
}