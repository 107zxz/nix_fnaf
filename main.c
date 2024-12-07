#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include <stdio.h>
#include "src/m_resc.h"
#include "src/s_cage.h"
#include "src/r_hud.h"
#include "src/i_equipment.h"
#include "src/m_input.h"

int main() {
    InitWindow(1280, 960, "Hello");

    SetTargetFPS(60);

    m_resc_load();

    i_equipment_notebook_setup_temp();

    while (!WindowShouldClose()) {

        // Color tmp
        m_input_update();
        s_cage_update();

        BeginDrawing();

            // Background Layer
            BeginShaderMode(M_RESC_SHADER_CAVEWALLS);
                SetShaderValueTexture(M_RESC_SHADER_CAVEWALLS, 0, M_RESC_TEX_CAVEWALLS);
                SetShaderValue(M_RESC_SHADER_CAVEWALLS, GetShaderLocation(M_RESC_SHADER_CAVEWALLS, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
                SetShaderValue(M_RESC_SHADER_CAVEWALLS, GetShaderLocation(M_RESC_SHADER_CAVEWALLS, "tint"), &s_cage_tint_bg, SHADER_UNIFORM_VEC4);
                SetShaderValue(M_RESC_SHADER_CAVEWALLS, GetShaderLocation(M_RESC_SHADER_DIVINGCAGE, "mouse"), &m_input_mousePos, SHADER_UNIFORM_VEC2);
                DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

            // Steady Layer
            s_cage_draw();

            r_hud_debug_cage();

            // DrawFPS(15, 15);

            // r_hud_status_message("Something is gnawing at the cage's ropes...");

        EndDrawing();
    }

    m_resc_unload();

    CloseWindow();

    return 0;
}
