#include "r_hud.h"
#include "s_cage.h"
#include <raylib.h>
#include <stdio.h>

void r_hud_debug_cage() {

    char status_text[20];

    sprintf(status_text, "Depth: %.2f\nThrottle: %.2f", s_cage_depth, s_cage_throttle);

    DrawText(status_text, 15, 15, 32, WHITE);
}