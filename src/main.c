#include <raylib.h>

int main() {
    int scr_w = 1024;
    int scr_h = scr_w/(4/3.f);

    InitWindow(scr_w, scr_h, "Raylib Template");
    SetTargetFPS(60);

    Texture2D spritesheet = LoadTexture("assets/texture.png");
    int w = spritesheet.width / 2;
    int h = spritesheet.height;
    int scl_w = w * scr_w / w / 2;
    int scl_h = h * scr_h / h / 2;
    int x = (scr_w - scl_w) / 2;
    int y = (scr_h - scl_h) / 2;
    int frame = 0;
    int n_sprite = 0;
    float frame_delay = 1.f;

    while (!WindowShouldClose()) {
        if (++frame * GetFrameTime() > frame_delay) {
            frame = 0;
            n_sprite++;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        DrawTexturePro(spritesheet, (Rectangle){n_sprite % 2 * w, 0, w, h}, (Rectangle){x, y, scl_w, scl_h}, (Vector2){0, 0}, 0, WHITE);
        EndDrawing();
    }

    UnloadTexture(spritesheet);
    CloseWindow();

    return 0;
}
