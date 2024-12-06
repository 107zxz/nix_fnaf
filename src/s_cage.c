#include "s_cage.h"
#include <raylib.h>
#include <raymath.h>
#include "m_resc.h"
#include "i_equipment.h"

float s_cage_throttle = 0.0;
float s_cage_depth = 0.0;

Vector4 s_cage_tint_fg = { 0 };
Vector4 s_cage_tint_bg = { 0 };

void s_cage_update() {
    s_cage_tint_fg = ColorNormalize(ColorFromHSV(s_cage_depth, 0.6f, 0.9f));
    s_cage_tint_bg = ColorNormalize(ColorFromHSV(s_cage_depth, 0.6f, 0.7f));

    s_cage_throttle = Clamp(s_cage_throttle, S_CAGE_THROTTLE_MIN, S_CAGE_THROTTLE_MAX);
    s_cage_depth += s_cage_throttle * GetFrameTime();

    i_equipment_extinguisher_update();
    i_equipment_crank_update();
    i_equipment_notebook_update();
}

void s_cage_draw() {
    BeginShaderMode(M_RESC_SHADER_DIVINGCAGE);
        SetShaderValueTexture(M_RESC_SHADER_DIVINGCAGE, 0, M_RESC_TEX_DIVINGCAGE);
        SetShaderValue(M_RESC_SHADER_DIVINGCAGE, GetShaderLocation(M_RESC_SHADER_DIVINGCAGE, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_DIVINGCAGE, GetShaderLocation(M_RESC_SHADER_DIVINGCAGE, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();

    i_equipment_extinguisher_draw();
    i_equipment_crank_draw();
    i_equipment_notebook_draw();
}