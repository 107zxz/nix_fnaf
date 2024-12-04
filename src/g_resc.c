#include "g_resc.h"
#include <stdio.h>


/// Textures
Image blankImage;

Texture2D G_RESC_TEX_BLANK;
Texture2D R_TEX_CAVEWALLS;
Texture2D G_RESC_TEX_DIVINGCAGE;

void load_textures() {
    // Blank image for shader shenanigans
    blankImage = GenImageColor(1280, 960, BLANK);
    G_RESC_TEX_BLANK = LoadTextureFromImage(blankImage);
    R_TEX_CAVEWALLS = LoadTexture("assets/textures/cave2.png");
    G_RESC_TEX_DIVINGCAGE = LoadTexture("assets/textures/cageG.png");
}

void unload_textures() {
    UnloadTexture(G_RESC_TEX_BLANK);
    UnloadImage(blankImage);
    UnloadTexture(R_TEX_CAVEWALLS);
    UnloadTexture(G_RESC_TEX_DIVINGCAGE);
}

/// Shaders
Shader G_RESC_SHADER_CAVEWALLS;
Shader G_RESC_SHADER_DIVINGCAGE;

void load_shaders() {
    G_RESC_SHADER_CAVEWALLS = LoadShader(0, "assets/shaders/invert.frag");
    G_RESC_SHADER_DIVINGCAGE = LoadShader(0, "assets/shaders/cage.frag");
}

void unload_shaders() {
    UnloadShader(G_RESC_SHADER_CAVEWALLS);
    UnloadShader(G_RESC_SHADER_DIVINGCAGE);
}

void g_resc_load() {
    load_textures();
    load_shaders();
}

void g_resc_unload() {
    unload_textures();
    unload_shaders();
}
