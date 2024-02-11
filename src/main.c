#include <raylib.h>

int main() {
    InitWindow(1024, 768, "Space Invaders");
    SetTargetFPS(60);

    Texture2D spritesheet = LoadTexture("assets/texture.png");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        int spriteWidth = spritesheet.width / 2;
        int spriteHeight = spritesheet.height;
        int scaledSpriteWidth = spriteWidth * (int)(1024/spriteWidth/2);
        int scaledSpriteHeight = spriteHeight * (int)(768/spriteHeight/2);
        int posX = (int)((1024 - scaledSpriteWidth) / 2);
        int posY = (int)((768 - scaledSpriteHeight) / 2);

        DrawTexturePro(spritesheet,
            (Rectangle){27, 0, spriteWidth, spriteHeight},
            (Rectangle){posX, posY, scaledSpriteWidth, scaledSpriteHeight},
            (Vector2){0, 0},
            0,
            WHITE);

        EndDrawing();
    }

    UnloadTexture(spritesheet);
    CloseWindow();

    return 0;
}
