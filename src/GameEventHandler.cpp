#include "GameEventHandler.h"
#include "Hooks.h"

namespace this_plugin {
    void GameEventHandler::onLoad() {
        INFO("onLoad()");
        Hooks::install();
    }

    void GameEventHandler::onPostLoad() {
        INFO("onPostLoad()");
    }

    void GameEventHandler::onPostPostLoad() {
        INFO("onPostPostLoad()");
    }

    void GameEventHandler::onInputLoaded() {
        INFO("onInputLoaded()");
    }

    void GameEventHandler::onDataLoaded() {
        INFO("onDataLoaded()");
    }

    void GameEventHandler::onNewGame() {
        INFO("onNewGame()");
    }

    void GameEventHandler::onPreLoadGame() {
        INFO("onPreLoadGame()");
    }

    void GameEventHandler::onPostLoadGame() {
        INFO("onPostLoadGame()");
    }

    void GameEventHandler::onSaveGame() {
        INFO("onSaveGame()");
    }

    void GameEventHandler::onDeleteGame() {
        INFO("onDeleteGame()");
    }
}