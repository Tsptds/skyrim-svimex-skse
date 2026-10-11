#pragma once
#include "REX/REX/INI.h"

namespace ModSettings{
    inline REX::INI::SettingStore g_settingStore;
    inline REX::INI::F32 surfaceClampLevel{"MCM","fClampSubmergeLevel", 0.8f} ;


    inline void ReadINI() {
        const auto ini = REX::INI::SettingStore::GetSingleton();
        ini->Init("Data/SKSE/Plugins/Svimex.ini", "Data/SKSE/Plugins/SvimexCustom.ini");
        ini->Load();
    }
}