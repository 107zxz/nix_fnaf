#pragma once

#include <raylib.h>

void m_resc_load();
void m_resc_unload();

/// Textures
extern Texture2D M_RESC_TEX_BLANK;
extern Texture2D M_RESC_TEX_CAVEWALLS;
extern Texture2D M_RESC_TEX_DIVINGCAGE;

extern Texture2D M_RESC_TEX_NOTEBOOK;

/// Shaders
extern Shader M_RESC_SHADER_CAVEWALLS;
extern Shader M_RESC_SHADER_DIVINGCAGE;
extern Shader M_RESC_SHADER_NOTEBOOK;