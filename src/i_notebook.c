#include "i_notebook.h"
#include "m_resc.h"
#include "s_cage.h"
#include <raylib.h>
#include <raymath.h>

typedef enum I_Notebook_Raisestate {
    I_NOTEBOOK_RAISED,
    I_NOTEBOOK_LOWERED
} I_Notebook_Raisestate;

I_Notebook_Raisestate raiseState = I_NOTEBOOK_LOWERED;
float raiseProgress = 0.0;

void i_notebook_draw() {
    BeginShaderMode(M_RESC_SHADER_NOTEBOOK);
        SetShaderValueTexture(M_RESC_SHADER_NOTEBOOK, 0, M_RESC_TEX_NOTEBOOK);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "raisestate"), &raiseProgress, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();
}

void i_notebook_update() {
    if (
        GetMousePosition().y / GetScreenHeight() > 0.8 &&
        GetMousePosition().x / GetScreenWidth() > 0.3 &&
        GetMousePosition().x / GetScreenWidth() < 0.7
    )
        raiseState = I_NOTEBOOK_RAISED;
    else
        raiseState = I_NOTEBOOK_LOWERED;

    raiseProgress += GetFrameTime() * (raiseState ? -10 : 10);
    raiseProgress = Clamp(raiseProgress, 0.0, 0.666);
}

