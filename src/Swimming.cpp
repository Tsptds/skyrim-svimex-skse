#include "Swimming.h"

#include "Config.h"

namespace Swimming
{
    bool IsSwimming(RE::Actor *a_actor)
    {
        if (!a_actor) return false;

        auto as = a_actor->AsActorState();
        return as && as->IsSwimming();
    }

    void ToggleDive(RE::Actor *a_actor)
    {
        auto *cell = a_actor->GetParentCell();
        if (!cell) return;

        const RE::NiPoint3 pos = a_actor->GetPosition();

        // Early Depth check
        const float submerge = a_actor->GetSubmergeLevel(pos.z, cell);
        if (submerge <= Config::kResurfaceSubmergeThreshold) return;

        g_isUnderwater = true;
        // INFO("Dive toggled -> underwater={}", g_isUnderwater);
    }

    void OnUpdate(RE::Actor *a_actor)
    {
        using st = RE::hkpCharacterStateType;
        using cf = RE::CHARACTER_FLAGS;

        if (!a_actor || a_actor->IsAnimationDriven())
        {
            g_isUnderwater = false;
            return;
        }

        bool enterState;
        a_actor->GetGraphVariableBool("bSvimex_InEnterState", enterState);

        // if (a_actor->IsAllowRotation() && !enterState)
        // {
        //     g_isUnderwater = false;
        //     return;
        // }

        auto *ctrl = a_actor->GetCharController();
        if (!ctrl) return;

        if (ctrl->flags.any(cf::kNoSim))
        {
            g_isUnderwater = false;
            return;
        }

        auto *cell = a_actor->GetParentCell();
        if (!cell) return;

        const RE::NiPoint3 pos = a_actor->GetPosition();
        const float submerge = a_actor->GetSubmergeLevel(pos.z, cell);

        if (Config::IsDivingSkipUpdate)
        {
            // bool enterState;
            // a_actor->GetGraphVariableBool("bSvimex_InEnterState", enterState);

            if (!enterState) Config::IsDivingSkipUpdate = false;

            return;
        }

        if (submerge <= 0)
        {
            return;
        }

        // Depth check, submerge: 0-1
        if (g_isUnderwater && submerge <= Config::kResurfaceSubmergeThreshold)
        {
            g_isUnderwater = false;
            // INFO("Auto-resurface at submerge={:.2f}", submerge);
        }

        bool wantSubmerge;
        a_actor->GetGraphVariableBool("bSvimex_WantSubmerge", wantSubmerge);
        if (g_isUnderwater && !wantSubmerge) return;

        // Drifting - floating fix, water inertia compatibility
        if (ctrl->flags.any(cf::kSupport, cf::kHasPotentialSupportManifold))
        {
            if (submerge < Config::kDiveSubmergeThreshold + 0.1f) return;
        }
        else
        {
            // if (submerge >= 0.2)
            // {
            //     using st = RE::hkpCharacterStateType;
            //     if (ctrl->context.currentState == st::kInAir)
            //     {
            //         g_isUnderwater = true;
            //         return;
            //     }
            // }

            if (ctrl->context.currentState == st::kInAir && ctrl->wantState == st::kSwimming)
            {
                g_isUnderwater = true;
                Config::IsDivingSkipUpdate = true;
                return;
            }
        }

        if (!IsSwimming(a_actor)) return;

        float waterZ;
        if (cell->GetWaterHeight(pos, waterZ))
        {
            const float targetZ = waterZ + Config::kSurfaceZOffset;
            const float signedDiff = targetZ - pos.z;  // diff to supposed swimming Z, not water surface
            {
                // Submerge start
                // bool wantSubmerge;
                // if (a_actor->GetGraphVariableBool("bSvimex_WantSubmerge", wantSubmerge) && wantSubmerge)
                if (wantSubmerge)
                {
                    const float alpha = 1.0f - std::exp(-Config::kSurfaceLerpSpeed * RE::GetSecondsSinceLastFrame());
                    RE::hkVector4 hkPos;
                    ctrl->GetPositionImpl(hkPos, false);
                    const float stepZ = alpha;
                    hkPos.quad.m128_f32[2] -= stepZ * RE::bhkWorld::GetWorldScale();

                    ctrl->SetPositionImpl(hkPos, false, false);

                    if (submerge >= 1.0f) g_isUnderwater = true;

                    return;
                }
            }

            const float alpha = 1.0f - std::exp(-Config::kSurfaceLerpSpeed * RE::GetSecondsSinceLastFrame());
            const float easedZ = pos.z + signedDiff * alpha;

            // RE::hkVector4 vel;
            // ctrl->GetLinearVelocityImpl(vel);
            // vel.quad.m128_f32[2] = 5;
            // ctrl->SetLinearVelocityImpl(vel);

            RE::hkVector4 hkPos;
            ctrl->GetPositionImpl(hkPos, false);
            hkPos.quad.m128_f32[2] = easedZ / 69.99125f;
            ctrl->SetPositionImpl(hkPos, true, false);
        }
    }
}