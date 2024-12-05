#pragma once

#include <raylib.h>

#define S_CAGE_THROTTLE_MAX 25.0
#define S_CAGE_THROTTLE_MIN 0.0

extern float s_cage_throttle;
extern float s_cage_depth;

extern Vector4 s_cage_tint_fg;
extern Vector4 s_cage_tint_bg;

void s_cage_update();