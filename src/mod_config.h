#ifndef MOD_CONFIG_H
#define MOD_CONFIG_H

#include "common.h"
#include "recompconfig.h"

// Shared config accessors for the enhanced mod's submods.
//
// Toggle options are declared as Enum "On"/"Off" in mod.toml, so option index 0
// means "On". Fade rates are transition speeds: the per-frame RGBA step is
// (colorDiff * rate) / 255, so a higher rate means fewer frames = faster fade.

// --- Submod on/off toggles ---------------------------------------------------

static inline bool config_enabled(const char* key) {
    return recomp_get_config_u32(key) == 0;
}

// --- Map fade controls -------------------------------------------------------

static inline s16 fade_config_rate(const char* key) {
    double rate = recomp_get_config_double(key);

    if (rate < 1.0) {
        return 1;
    }

    if (rate > 60.0) {
        return 60;
    }

    return (s16)rate;
}

static inline s16 fade_in_rate(void) {
    return fade_config_rate("fade_in_rate");
}

static inline s16 fade_out_rate(void) {
    return fade_config_rate("fade_out_rate");
}

static inline bool fade_unblock_movement(void) {
    return config_enabled("unblock_movement");
}

#endif
