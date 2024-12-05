#include "m_resc.h"
#include <stdio.h>


/// Textures
Image blankImage;

Texture2D M_RESC_TEX_BLANK;
Texture2D M_RESC_TEX_CAVEWALLS;
Texture2D M_RESC_TEX_DIVINGCAGE;
Texture2D M_RESC_TEX_NOTEBOOK;

void load_textures() {
    // Blank image for shader shenanigans
    blankImage = GenImageColor(1280, 960, BLANK);
    M_RESC_TEX_BLANK = LoadTextureFromImage(blankImage);
    M_RESC_TEX_CAVEWALLS = LoadTexture("assets/textures/cave4t.png");
    M_RESC_TEX_DIVINGCAGE = LoadTexture("assets/textures/cage3.png");
    M_RESC_TEX_NOTEBOOK = LoadTexture("assets/textures/notebook.png");
}

void unload_textures() {
    UnloadTexture(M_RESC_TEX_BLANK);
    UnloadImage(blankImage);
    UnloadTexture(M_RESC_TEX_CAVEWALLS);
    UnloadTexture(M_RESC_TEX_DIVINGCAGE);
    UnloadTexture(M_RESC_TEX_NOTEBOOK);
}

/// Shaders
Shader M_RESC_SHADER_CAVEWALLS;
Shader M_RESC_SHADER_DIVINGCAGE;
Shader M_RESC_SHADER_NOTEBOOK;

void load_shaders() {
    M_RESC_SHADER_CAVEWALLS = LoadShader(0, "assets/shaders/cavewalls.frag");
    M_RESC_SHADER_DIVINGCAGE = LoadShader(0, "assets/shaders/cage.frag");
    M_RESC_SHADER_NOTEBOOK = LoadShader(0, "assets/shaders/notebook.frag");
}

void unload_shaders() {
    UnloadShader(M_RESC_SHADER_CAVEWALLS);
    UnloadShader(M_RESC_SHADER_DIVINGCAGE);
    UnloadShader(M_RESC_SHADER_NOTEBOOK);
}

void m_resc_load() {
    load_textures();
    load_shaders();
}

void m_resc_unload() {
    unload_textures();
    unload_shaders();
}
