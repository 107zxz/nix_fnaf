#include <raylib.h>

int main() {
    InitWindow(1280, 960, "Hello");

    SetTargetFPS(60);

    Shader caveShader = LoadShader(0, "assets/shaders/invert.frag");
    Shader cageShader = LoadShader(0, "assets/shaders/cage.frag");


    Texture2D porn = LoadTexture("assets/textures/cave2.png");
    Texture2D cage = LoadTexture("assets/textures/cageG.png");

    Image blankImage = GenImageColor(1280, 960, BLANK);
    Texture2D blankTexture = LoadTextureFromImage(blankImage);

    float zeroTime = 0;

    while (!WindowShouldClose()) {

        float totalTime = GetTime();

        BeginDrawing();

            BeginShaderMode(caveShader);
                SetShaderValueTexture(caveShader, 0, porn);
                SetShaderValue(caveShader, GetShaderLocation(caveShader, "time"), &totalTime, SHADER_UNIFORM_FLOAT);
                DrawTexture(blankTexture, 0, 0, WHITE);
            EndShaderMode();

            BeginShaderMode(cageShader);
                SetShaderValueTexture(cageShader, 0, cage);
                SetShaderValue(cageShader, GetShaderLocation(cageShader, "time"), &totalTime, SHADER_UNIFORM_FLOAT);
                DrawTexture(blankTexture, 0, 0, WHITE);
            EndShaderMode();

        EndDrawing();
    }

    UnloadTexture(porn);
    UnloadTexture(cage);
    UnloadShader(caveShader);
    UnloadShader(cageShader);
    UnloadImage(blankImage);
    UnloadTexture(blankTexture);

    CloseWindow();

    return 0;
}
