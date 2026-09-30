#pragma once

#define nipoint_to_hkvector(a) Vec3_To_Vec4(a / 69.99125f)  // Scale from ni to havok
#define hkvector_to_nipoint(a) Vec4_To_Vec3(a * 69.99125f)  // Scale from havok to ni

namespace Swimming
{
    inline static RE::NiPoint3 Vec4_To_Vec3(RE::hkVector4 vec)
    {
        return {vec.quad.m128_f32[0], vec.quad.m128_f32[1], vec.quad.m128_f32[2]};
    }
    inline static RE::hkVector4 Vec3_To_Vec4(RE::NiPoint3 vec) { return {vec.x, vec.y, vec.z, 0}; }

    inline bool g_isUnderwater = false;

    void ToggleDive(RE::Actor *a_actor);

    void OnUpdate(RE::Actor *a_actor);

    bool IsSwimming(RE::Actor *a_actor);
}