#include "Hooks.h"
#include "Swimming.h"

namespace Hooks
{
    struct PlayerUpdateHook {
            static void thunk(RE::Character *a_this, float a_delta)
            {
                func(a_this, a_delta);
                if (a_this)
                {
                    Swimming::OnUpdate(a_this);
                }
            }

            static inline REL::Relocation<decltype(thunk)> func;

            static constexpr std::size_t kUpdateVFuncIndex = 0xAD;

            static void Install()
            {
                REL::Relocation<std::uintptr_t> vtbl{RE::VTABLE_PlayerCharacter[0]};
                func = vtbl.write_vfunc(kUpdateVFuncIndex, thunk);
            }
    };

    // struct SwimUpdateHook {
    //         static void thunk(RE::Character *a_this, float a_delta)
    //         {
    //             func(a_this, a_delta);
    //             if (a_this)
    //             {
    //                 Swimming::OnUpdate(a_this);
    //             }
    //         }

    //         static inline REL::Relocation<decltype(thunk)> func;

    //         static constexpr std::size_t kUpdateVFuncIndex = 0xAD;

    //         static void Install()
    //         {
    //             REL::Relocation<std::uintptr_t> vtbl{RE::VTABLE_PlayerCharacter[0]};
    //             func = vtbl.write_vfunc(kUpdateVFuncIndex, thunk);
    //         }
    // };

    void Install()
    {
        PlayerUpdateHook::Install();
        // SwimUpdateHook::Install();
        INFO("Update hooks installed");
    }
}