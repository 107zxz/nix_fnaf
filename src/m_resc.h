#pragma once

#include <raylib.h>

void m_resc_load();
void m_resc_unload();

/// Textures
extern Texture2D G_RESC_TEX_BLANK;
extern Texture2D R_TEX_CAVEWALLS;
extern Texture2D G_RESC_TEX_DIVINGCAGE;

/// Shaders
extern Shader G_RESC_SHADER_CAVEWALLS;
extern Shader G_RESC_SHADER_DIVINGCAGE;