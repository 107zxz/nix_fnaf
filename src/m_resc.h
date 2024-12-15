#pragma once

#include <raylib.h>

void m_resc_load();
void m_resc_unload();

/// Textures
extern Texture2D M_RESC_TEX_BLANK;
extern Texture2D M_RESC_TEX_CAVEWALLS;
extern Texture2D M_RESC_TEX_DIVINGCAGE;

extern Texture2D M_RESC_TEX_NOTEBOOK;
extern Texture2D M_RESC_TEX_WRITING_DEBUG;
extern Texture2D M_RESC_TEX_EXTINGUISHER;
extern Texture2D M_RESC_TEX_CRANK;

extern Texture2D M_RESC_TEX_GEN_ARROW;

/// Shaders
extern Shader M_RESC_SHADER_CAVEWALLS;
extern Shader M_RESC_SHADER_DIVINGCAGE;
extern Shader M_RESC_SHADER_NOTEBOOK;
extern Shader M_RESC_SHADER_EXTINGUISHER;
extern Shader M_RESC_SHADER_CRANK;