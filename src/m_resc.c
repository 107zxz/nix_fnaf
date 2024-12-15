#include "m_resc.h"
#include <stdio.h>


/// Textures
Image blankImage;

Texture2D M_RESC_TEX_BLANK;
Texture2D M_RESC_TEX_CAVEWALLS;
Texture2D M_RESC_TEX_DIVINGCAGE;

Texture2D M_RESC_TEX_NOTEBOOK;
Texture2D M_RESC_TEX_WRITING_DEBUG;
Texture2D M_RESC_TEX_EXTINGUISHER;
Texture2D M_RESC_TEX_CRANK;

Texture2D M_RESC_TEX_GEN_ARROW;

void load_textures() {
    // Blank image for shader shenanigans
    blankImage = GenImageColor(1280, 960, BLANK);
    M_RESC_TEX_BLANK = LoadTextureFromImage(blankImage);
    M_RESC_TEX_CAVEWALLS = LoadTexture("assets/textures/cave4t.png");
    M_RESC_TEX_DIVINGCAGE = LoadTexture("assets/textures/cage3.png");
    M_RESC_TEX_NOTEBOOK = LoadTexture("assets/textures/notebook.png");
    M_RESC_TEX_WRITING_DEBUG = LoadTexture("assets/textures/note_tutorial.png");
    M_RESC_TEX_EXTINGUISHER = LoadTexture("assets/textures/extinguisher.png");
    M_RESC_TEX_CRANK = LoadTexture("assets/textures/crank.png");
    M_RESC_TEX_GEN_ARROW = LoadTexture("assets/textures/arrow.png");
}

void unload_textures() {
    UnloadTexture(M_RESC_TEX_BLANK);
    UnloadImage(blankImage);
    UnloadTexture(M_RESC_TEX_CAVEWALLS);
    UnloadTexture(M_RESC_TEX_DIVINGCAGE);
    UnloadTexture(M_RESC_TEX_NOTEBOOK);
    UnloadTexture(M_RESC_TEX_WRITING_DEBUG);
    UnloadTexture(M_RESC_TEX_EXTINGUISHER);
    UnloadTexture(M_RESC_TEX_CRANK);
    UnloadTexture(M_RESC_TEX_GEN_ARROW);
}

/// Shaders
Shader M_RESC_SHADER_CAVEWALLS;
Shader M_RESC_SHADER_DIVINGCAGE;
Shader M_RESC_SHADER_NOTEBOOK;
Shader M_RESC_SHADER_EXTINGUISHER;
Shader M_RESC_SHADER_CRANK;

void load_shaders() {
    M_RESC_SHADER_CAVEWALLS = LoadShader(0, "assets/shaders/cavewalls.frag");
    M_RESC_SHADER_DIVINGCAGE = LoadShader(0, "assets/shaders/cage.frag");
    M_RESC_SHADER_NOTEBOOK = LoadShader(0, "assets/shaders/notebook.frag");
    M_RESC_SHADER_EXTINGUISHER = LoadShader(0, "assets/shaders/extinguisher.frag");
    M_RESC_SHADER_CRANK = LoadShader(0, "assets/shaders/crank.frag");
}

void unload_shaders() {
    UnloadShader(M_RESC_SHADER_CAVEWALLS);
    UnloadShader(M_RESC_SHADER_DIVINGCAGE);
    UnloadShader(M_RESC_SHADER_NOTEBOOK);
    UnloadShader(M_RESC_SHADER_EXTINGUISHER);
    UnloadShader(M_RESC_SHADER_CRANK);
}

void m_resc_load() {
    load_textures();
    load_shaders();
}

void m_resc_unload() {
    unload_textures();
    unload_shaders();
}
