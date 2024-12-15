#include "i_equipment.h"
#include "m_resc.h"
#include "s_cage.h"
#include <raymath.h>
#include <stdio.h>
#include <raylib.h>
#include "m_input.h"


float extiguisher_raiseProgress = 0.0;
bool extinguisher_use_was_hovered = false;

void i_equipment_extinguisher_update() {

    if (
        m_input_mousePos.y > 0.66 &&
        m_input_mousePos.x > 0.73 &&
        m_input_mousePos.x < 0.95
    )
        extiguisher_raiseProgress += GetFrameTime() * 2;
    else
        extiguisher_raiseProgress -= GetFrameTime() * 2;

    extiguisher_raiseProgress = Clamp(extiguisher_raiseProgress, 0.0, 0.1);

    if (m_input_mousePos.y < 0.66 && extiguisher_raiseProgress > 0.05) {
        printf("AAAAA\n");
        fflush(stdout);
    }

}

void i_equipment_extinguisher_draw() {

    BeginShaderMode(M_RESC_SHADER_EXTINGUISHER);
        SetShaderValueTexture(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "texture1"), M_RESC_TEX_EXTINGUISHER);
        SetShaderValueTexture(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "arrowtex"), M_RESC_TEX_GEN_ARROW);
        SetShaderValue(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        SetShaderValue(M_RESC_SHADER_EXTINGUISHER, GetShaderLocation(M_RESC_SHADER_EXTINGUISHER, "raisestate"), &extiguisher_raiseProgress, SHADER_UNIFORM_FLOAT);

        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();
}

void i_equipment_crank_update() {
    if (
        m_input_mousePos.x > 0.04 &&
        m_input_mousePos.x < 0.27 &&
        m_input_mousePos.y > 0.60 &&
        m_input_mousePos.y < 0.85
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

Texture2D notebook_pages[3];
int notebook_page;
float notebook_raiseProgress = 0.0;
bool notebook_arrow_was_hovered = false;

void i_equipment_notebook_setup_temp() {
    notebook_pages[0] = M_RESC_TEX_WRITING_DEBUG;
    notebook_pages[1] = M_RESC_TEX_CAVEWALLS;
    notebook_pages[2] = M_RESC_TEX_CRANK;
    notebook_page = 0;
}

void i_equipment_notebook_update() {
    if (
        m_input_mousePos.y > 0.85 &&
        m_input_mousePos.x > 0.3 &&
        m_input_mousePos.x < 0.7
    )
        notebook_raiseProgress += GetFrameTime() * 10;
    else
        notebook_raiseProgress -= GetFrameTime() * 10;

    notebook_raiseProgress = Clamp(notebook_raiseProgress, 0.0, 0.666);

    // Page buttons
    if (
        m_input_mousePos.x < 0.44 ||
        m_input_mousePos.x > 0.59
    ) {
        if (!notebook_arrow_was_hovered && notebook_raiseProgress > 0.4) {
            int diff = m_input_mousePos.x < 0.51 ? -1 : 1;
            notebook_page = (notebook_page + diff);
            if (notebook_page > 2) notebook_page = 2;
            if (notebook_page < 0) notebook_page = 0;
        }
        notebook_arrow_was_hovered = true;
    } else {
        notebook_arrow_was_hovered = false;
    }


}

void i_equipment_notebook_draw() {
    BeginShaderMode(M_RESC_SHADER_NOTEBOOK);
        SetShaderValueTexture(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "texture1"), M_RESC_TEX_NOTEBOOK);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "time"), &s_cage_depth, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "raisestate"), &notebook_raiseProgress, SHADER_UNIFORM_FLOAT);
        SetShaderValue(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "tint"), &s_cage_tint_fg, SHADER_UNIFORM_VEC4);
        SetShaderValueTexture(M_RESC_SHADER_NOTEBOOK, GetShaderLocation(M_RESC_SHADER_NOTEBOOK, "writing"), notebook_pages[notebook_page]);

        DrawTexture(M_RESC_TEX_BLANK, 0, 0, WHITE);
    EndShaderMode();
}

