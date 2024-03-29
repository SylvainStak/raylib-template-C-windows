#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int main(void) {
    int scr_w = 800;
    int scr_h = 450;
    Vector2 ball = { scr_w/2, scr_h/2 };
    Vector2 speed = { 100, 100 };
    float radius = 25;
    Color color = GREEN;

    InitWindow(scr_w, scr_h, "raylib-dev");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        ball.x += speed.x * dt;
        ball.y += speed.y * dt;
        if (ball.x + radius > scr_w || ball.x - radius < 0) speed.x = -speed.x;
        if (ball.y + radius > scr_h || ball.y - radius < 0) speed.y = -speed.y;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(ball.x, ball.y, radius, color);
        GuiSlider((Rectangle) {150, 10, 100, 20}, "10", "50", &radius, 10.f, 50.f);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
