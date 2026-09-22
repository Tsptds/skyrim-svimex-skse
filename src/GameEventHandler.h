#pragma once
#include "SkseMessagingListener.h"

namespace this_plugin {
    class GameEventHandler : public SkseMessagingListener<GameEventHandler> {
        private:
            GameEventHandler() {
                registerListener();
            };
            GameEventHandler(GameEventHandler &) = delete;
            GameEventHandler &operator=(GameEventHandler &&) = delete;
            void operator=(GameEventHandler &) = delete;

        public:
            [[nodiscard]] static GameEventHandler &getInstance() {
                static GameEventHandler instance;
                return instance;
            }

            void onLoad() override;
            void onPostLoad() override;
            void onPostPostLoad() override;
            void onInputLoaded() override;
            void onDataLoaded() override;
            void onNewGame() override;
            void onPreLoadGame() override;
            void onPostLoadGame() override;
            void onSaveGame() override;
            void onDeleteGame() override;
    };
}
