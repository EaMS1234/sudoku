#include "raylib.h"

void draw_board(int table[9][9]);

char label[] = "0";  // Placeholder variable used for drawing the numbers on the board

void draw_board(int table[9][9])
{
    // Draws the board on the screen
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!IsCursorHidden())
            {
                // Draws a box behind around the number the mouse is over
                if (GetMouseX() <= (85 + (45 * i)) && GetMouseX() >= (45 + (45 * i)) && GetMouseY() <= (85 + (45 * j)) && GetMouseY() >= (45 + (45 * j)))
                {
                    DrawRectangle(45 + (45 * i), 45 + (45 * j), 40, 40, BLUE);
                }
            }

            label[0] = (char)(48 + table[i][j]);
            DrawText(label, 58 + (45 * i), 55 + (45 * j), 24, BLACK);
        }
    }

    DrawRectangle(176, 42, 3, 405, DARKGRAY);
    DrawRectangle(311, 42, 3, 405, DARKGRAY);
    DrawRectangle(42, 176, 405, 3, DARKGRAY);
    DrawRectangle(42, 311, 405, 3, DARKGRAY);
}
