#include "r_hud.h"
#include "s_cage.h"
#include <raylib.h>
#include <stdio.h>

void r_hud_debug_cage() {

    char status_text[50];

    sprintf(status_text, "Depth: %.4f\n\nThrottle: %.4f", s_cage_depth, s_cage_throttle);

    DrawText(status_text, 15, 15, 32, WHITE);
}

void r_hud_status_message(char* message) {
    DrawText(message, 15, 15, 32, WHITE);
}