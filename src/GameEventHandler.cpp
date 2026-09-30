#include "GameEventHandler.h"
#include "Hooks.h"
#include "Config.h"
#include "InputHandler.h"

namespace this_plugin
{
    void GameEventHandler::onLoad() { INFO("onLoad()"); }

    void GameEventHandler::onPostLoad() { INFO("onPostLoad()"); }

    void GameEventHandler::onPostPostLoad() { INFO("onPostPostLoad()"); }

    void GameEventHandler::onInputLoaded() { INFO("onInputLoaded()"); }

    void GameEventHandler::onDataLoaded()
    {
        // INFO("onDataLoaded()");
        Hooks::Install();
        InputHandler::Register();
    }

    void GameEventHandler::onNewGame() { INFO("onNewGame()"); }

    void GameEventHandler::onPreLoadGame() { INFO("onPreLoadGame()"); }

    void GameEventHandler::onPostLoadGame() { INFO("onPostLoadGame()"); }

    void GameEventHandler::onSaveGame() { INFO("onSaveGame()"); }

    void GameEventHandler::onDeleteGame() { INFO("onDeleteGame()"); }
}