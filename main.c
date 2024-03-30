#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int main(void) {
    int scr_w = 800;
    int scr_h = 450;
    Vector2 pos = { scr_w/2.f, scr_h/2.f };
    Vector2 speed = { 300.f, 300.f };
    float radius = 25.f;

    InitWindow(scr_w, scr_h, "raylib-dev");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        pos.x += speed.x * dt;
        pos.y += speed.y * dt;
        if (pos.x + radius > scr_w || pos.x - radius < 0) speed.x = -speed.x;
        if (pos.y + radius > scr_h || pos.y - radius < 0) speed.y = -speed.y;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(pos.x, pos.y, radius, GREEN);
        GuiSlider((Rectangle) { 10, 10, 100, 20 }, NULL, NULL, &radius, 10, 50);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
