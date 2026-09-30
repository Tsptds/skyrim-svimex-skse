#pragma once

namespace InputHandler
{
    class Listener : public RE::BSTEventSink<RE::InputEvent *> {
        public:
            static Listener *GetSingleton();

            RE::BSEventNotifyControl ProcessEvent(RE::InputEvent *const *a_event, RE::BSTEventSource<RE::InputEvent *> *a_source) override;

        private:
            Listener() = default;
            Listener(const Listener &) = delete;
            Listener(Listener &&) = delete;
            ~Listener() override = default;

            Listener &operator=(const Listener &) = delete;
            Listener &operator=(Listener &&) = delete;
    };

    void Register();
}