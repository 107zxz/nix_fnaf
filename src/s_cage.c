#include "s_cage.h"
#include <raylib.h>

float s_cage_throttle = 0.0;
float s_cage_depth = 0.0;

Vector4 s_cage_tint_fg = { 0 };
Vector4 s_cage_tint_bg = { 0 };

void s_cage_update() {
    s_cage_tint_fg = ColorNormalize(ColorFromHSV(s_cage_depth, 0.6f, 0.9f));
    s_cage_tint_bg = ColorNormalize(ColorFromHSV(s_cage_depth, 0.6f, 0.7f));
}