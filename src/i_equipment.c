#include "i_equipment.h"
#include "m_resc.h"
#include "s_cage.h"
#include <raymath.h>
#include <stdio.h>
#include <raylib.h>


typedef enum I_Equipment_Raisestate {
    I_EQUIPMENT_RAISED,
    I_EQUIPMENT_LOWERED
} I_Equipment_Raisestate;

I_Equipment_Raisestate extiguisher_raiseState = I_EQUIPMENT_LOWERED;
float extiguisher_raiseProgress = 0.0;


void i_equipment_extinguisher_update() {

    if (
        GetMousePosition().y / GetScreenHeight() > 0.60 &&
        GetMousePosition().x / GetScreenWidth() > 0.73 &&
        GetMousePosition().x / GetScreenWidth() < 0.95
    )
        extiguisher_raiseState = I_EQUIPMENT_RAISED;
    else
        extiguisher_raiseState = I_EQUIPMENT_LOWERED;

    extiguisher_raiseProgress += GetFrameTime() * (extiguisher_raiseState ? -2 : 2);
    extiguisher_raiseProgress = Clamp(extiguisher_raiseProgress, 0.0, 0.1);

}

void i_equipment_extinguisher_draw() {

    BeginShaderMode(M_RESC_SHADER_EXTINGUISHER);
        SetShaderValueTexture(M_RESC_SHADER_EXTINGUISHER, 0, M_RESC_TEX_EXTINGUISHER);
        SetShaderValue(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        SetShaderValue(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "raisestate"), &extiguisher_raiseProgress, SHADER_UNIFORM_FLOAT);

        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();
}

void i_equipment_crank_update() {
    float mouseX, mouseY;
        {
            Vector2 mPos = GetMousePosition();
            mouseX = mPos.x / GetScreenWidth();
            mouseY = mPos.y / GetScreenHeight();
        }

        if (
            mouseX > 0.04 &&
            mouseX < 0.27 &&
            mouseY > 0.64 &&
            mouseY < 0.85
        )
            s_cage_throttle += GetFrameTime();
        else
            s_cage_throttle *= 0.9;
}

void i_equipment_crank_draw() {
    BeginShaderMode(M_RESC_SHADER_CRANK);
        SetShaderValueTexture(M_RESC_SHADER_CRANK, 0, M_RESC_TEX_CRANK);
        SetShaderValue(M_RESC_SHADER_CRANK, GetShaderLocation(M_RESC_SHADER_CRANK, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_CRANK, GetShaderLocation(M_RESC_SHADER_CRANK, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        // SetShaderValue(M_RESC_SHADER_CRANK, GetShaderLocation(M_RESC_SHADER_CRANK, "raisestate"), &extiguisher_raiseProgress, SHADER_UNIFORM_FLOAT);

        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();
}

I_Equipment_Raisestate notebook_raiseState = I_EQUIPMENT_LOWERED;
float notebook_raiseProgress = 0.0;

void i_equipment_notebook_update() {
    if (
        GetMousePosition().y / GetScreenHeight() > 0.85 &&
        GetMousePosition().x / GetScreenWidth() > 0.3 &&
        GetMousePosition().x / GetScreenWidth() < 0.7
    )
        notebook_raiseState = I_EQUIPMENT_RAISED;
    else
        notebook_raiseState = I_EQUIPMENT_LOWERED;

    notebook_raiseProgress += GetFrameTime() * (notebook_raiseState ? -10 : 10);
    notebook_raiseProgress = Clamp(notebook_raiseProgress, 0.0, 0.666);
}

void i_equipment_notebook_draw() {
    BeginShaderMode(M_RESC_SHADER_NOTEBOOK);
        SetShaderValueTexture(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "texture1"), M_RESC_TEX_NOTEBOOK);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "raisestate"), &notebook_raiseProgress, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        SetShaderValueTexture(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "writing"), M_RESC_TEX_WRITING_DEBUG);

        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();
}

