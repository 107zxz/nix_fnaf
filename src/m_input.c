#include "m_input.h"

Vector2 m_input_mousePos;

void m_input_update() {
    Vector2 mPos = GetMousePosition();

    m_input_mousePos = (Vector2){
        mPos.x / GetScreenWidth(),
        mPos.y / GetScreenHeight()
    };
}