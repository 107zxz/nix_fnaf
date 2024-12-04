#include <raylib.h>
#include "src/m_resc.h"

int main() {
    InitWindow(1280, 960, "Hello");

    SetTargetFPS(60);

    m_resc_load();

    float zeroTime = 0;

    while (!WindowShouldClose()) {

        float totalTime = GetTime();

        BeginDrawing();

            BeginShaderMode(G_RESC_SHADER_CAVEWALLS);
                SetShaderValueTexture(G_RESC_SHADER_CAVEWALLS, 0, R_TEX_CAVEWALLS);
                SetShaderValue(G_RESC_SHADER_CAVEWALLS, GetShaderLocation(G_RESC_SHADER_CAVEWALLS, "time"), &totalTime, SHADER_UNIFORM_FLOAT);
                DrawTexture(G_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

            BeginShaderMode(G_RESC_SHADER_DIVINGCAGE);
                SetShaderValueTexture(G_RESC_SHADER_DIVINGCAGE, 0, G_RESC_TEX_DIVINGCAGE);
                SetShaderValue(G_RESC_SHADER_DIVINGCAGE, GetShaderLocation(G_RESC_SHADER_DIVINGCAGE, "time"), &totalTime, SHADER_UNIFORM_FLOAT);
                DrawTexture(G_RESC_TEX_BLANK, 0, 0, WHITE);
            EndShaderMode();

        EndDrawing();
    }

    m_resc_unload();

    CloseWindow();

    return 0;
}
