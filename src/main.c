#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Hello, World!");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawText("Hello, World!", 0, 0, 24, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
