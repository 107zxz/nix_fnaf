#include <raylib.h>

enum GameState {
    GS_TITLE,
    GS_LOBBY
};

void loadAssets() {

}

void drawGS(int s) {
    switch (s) {
        case GS_TITLE:
        ClearBackground(WHITE);
        break;

        case GS_LOBBY:
        ClearBackground(BLACK);
        break;
    }
}


int main() {
    InitWindow(640, 480, "Hello");

    SetTargetFPS(60);

    int gs = GS_TITLE;

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_F))
            gs = gs == GS_LOBBY ? GS_TITLE : GS_LOBBY;

        BeginDrawing();

        drawGS(gs);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
