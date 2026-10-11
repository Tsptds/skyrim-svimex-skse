#pragma once
#include "ModSettings.h"

namespace Config
{
    // Submerge level, 0.0 = fully surfaced
    inline float kResurfaceSubmergeThreshold = 0.90f;

    // 0.7+ starts swimming
    inline float kDiveSubmergeThreshold = 0.7f;

    // inline float kSurfaceZOffset = -89.6f; // 128 * 0.7, 0.7 is submerge level
    // inline float kSurfaceZOffset = -102.4f;  // 128 * 0.8
    inline float kSurfaceClampSubmergeLevel = 0.8f;

    inline float kSurfaceLerpSpeed = 32.0f;
    inline float kSubmergeSpeed = 30.0f;

    inline bool IsDivingSkipUpdate = false;

    inline float GetSurfaceZOffset() { return -128.f * kSurfaceClampSubmergeLevel; }
}
