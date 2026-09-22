#include "Hooks.h"
namespace this_plugin {
    void Hooks::install() {
        QuitGameHook::install();
    }

    void Hooks::quitGame() {
        INFO("Game quitting");
    }
}
