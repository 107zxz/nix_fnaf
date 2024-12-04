#include <raylib.h>
#include "src/m_resc.h"
#include "src/s_cage.h"
#include "src/r_hud.h"

int main() {
    InitWindow(1280, 960, "Hello");

    SetTargetFPS(60);

    m_resc_load();

    float zeroTime = 0;

    while (!WindowShouldClose()) {

        float totalTime = GetTime();

        if (IsKeyDown(KEY_W))
            s_cage_throttle -= GetFrameTime();
        if (IsKeyDown(KEY_S))
            s_cage_throttle += GetFrameTime();

        BeginDrawing();

            BeginShaderMode(G_RESC_SHADER_CAVEWALLS);
                SetShaderValueTexture(G_RESC_SHADER_CAVEWALLS, 0, R_TEX_CAVEWALLS);
                SetShaderValue(G_RESC_SHADER_CAVEWALLS, GetShaderLocation(G_RESC_SHADER_CAVEWALLS, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
                DrawTexture(G_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

            BeginShaderMode(G_RESC_SHADER_DIVINGCAGE);
                SetShaderValueTexture(G_RESC_SHADER_DIVINGCAGE, 0, G_RESC_TEX_DIVINGCAGE);
                SetShaderValue(G_RESC_SHADER_DIVINGCAGE, GetShaderLocation(G_RESC_SHADER_DIVINGCAGE, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
                DrawTexture(G_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

            r_hud_debug_cage();

        EndDrawing();
    }

    m_resc_unload();

    CloseWindow();

    return 0;
}
