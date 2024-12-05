#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "src/m_resc.h"
#include "src/s_cage.h"
#include "src/r_hud.h"
#include "src/i_notebook.h"

int main() {
    InitWindow(1280, 960, "Hello");

    SetTargetFPS(60);

    m_resc_load();

    while (!WindowShouldClose()) {

        // float totalTime = GetTime();

        // s_cage_throttle *= 0.99;

        if (IsKeyDown(KEY_W))
            s_cage_throttle -= GetFrameTime() * 5;
        if (IsKeyDown(KEY_S))
            s_cage_throttle += GetFrameTime() * 5;

        s_cage_throttle = Clamp(s_cage_throttle, S_CAGE_THROTTLE_MIN, S_CAGE_THROTTLE_MAX);
        s_cage_depth += s_cage_throttle * GetFrameTime();

        
        // Color tmp
        s_cage_update();
        i_notebook_update();
        

        BeginDrawing();

            // Background Layer
            BeginShaderMode(M_RESC_SHADER_CAVEWALLS);
                SetShaderValueTexture(M_RESC_SHADER_CAVEWALLS, 0, M_RESC_TEX_CAVEWALLS);
                SetShaderValue(M_RESC_SHADER_CAVEWALLS, GetShaderLocation(M_RESC_SHADER_CAVEWALLS, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
                SetShaderValue(M_RESC_SHADER_CAVEWALLS, GetShaderLocation(M_RESC_SHADER_CAVEWALLS, "tint"), &s_cage_tint_bg, SHADER_UNIFORM_VEC4);
                DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

            // Cage layer
            BeginShaderMode(M_RESC_SHADER_DIVINGCAGE);
                SetShaderValueTexture(M_RESC_SHADER_DIVINGCAGE, 0, M_RESC_TEX_DIVINGCAGE);
                SetShaderValue(M_RESC_SHADER_DIVINGCAGE, GetShaderLocation(M_RESC_SHADER_DIVINGCAGE, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
                SetShaderValue(M_RESC_SHADER_DIVINGCAGE, GetShaderLocation(M_RESC_SHADER_DIVINGCAGE, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
                DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

            // Steady Layer
            i_notebook_draw();

            r_hud_debug_cage();

            // r_hud_status_message("Something is gnawing at the cage's ropes...");

        EndDrawing();
    }

    m_resc_unload();

    CloseWindow();

    return 0;
}
