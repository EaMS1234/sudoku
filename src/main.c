#include "raylib.h"

int main()
{
    InitWindow(490, 490, "Sudoku");
    SetTargetFPS(60);

    int sudoku_table[9][9];  // represents the number in each position of the board

    // Initializes the table with zeroes
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku_table[i][j] = 0;
        }
    }

    char label[] = "0";  // Placeholder variable used for drawing the numbers on the board

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (IsCursorHidden())
        {
            // TODO: use arrow keys to navigate the game

            // Goes back to "mouse mode"
            if (GetMouseDelta().x != 0 && GetMouseDelta().y != 0)
            {
                ShowCursor();
            }
        }
        else
        {
            // TODO: if a key is used, it should disable the mouse input
            if(IsKeyDown(KEY_SPACE))
            {
                HideCursor();
            }
        }

        // Draws the board on the screen
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (!IsCursorHidden())
                {
                    // Draws a box behind around the number the mouse is over
                    if (GetMouseX() <= (85 + (45 * i))
                        && GetMouseX() >= (45 + (45 * i))
                        && GetMouseY() <= (85 + (45 * j))
                        && GetMouseY() >= (45 + (45 * j)))
                    {
                        DrawRectangle(45 + (45 * i), 45 + (45 * j), 40, 40, BLUE);
                    }
                }

                label[0] = (char) (48 + sudoku_table[i][j]);
                DrawText(label, 58 + (45 * i), 55 + (45 * j), 24, BLACK);
            }
        }

        DrawRectangle(176, 42, 3, 405, DARKGRAY);
        DrawRectangle(311, 42, 3, 405, DARKGRAY);
        DrawRectangle(42, 176, 405, 3, DARKGRAY);
        DrawRectangle(42, 311, 405, 3, DARKGRAY);

        // DrawLine(245, 0, 245, 490, RED);
        // DrawLine(0, 245, 490, 245, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
