#include "raylib.h"

void draw_board(int table[9][9], Vector2 origin);

char label[] = "\0";

void draw_board(int table[9][9], Vector2 origin)
{
    // Draws the board on the screen
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!IsCursorHidden())
            {
                // Draws a box behind around the number the mouse is over
                if (GetMouseX() <= (origin.x + 43 + (45 * i))
                    && GetMouseX() >= (origin.x + 3 + (45 * i))
                    && GetMouseY() <= (origin.y + 43 + (45 * j))
                    && GetMouseY() >= (origin.y + 3 + (45 * j)))
                {
                    DrawRectangle((origin.x + 3) + (45 * i), (origin.y + 3) + (45 * j), 40, 40, BLUE);
                }
            }

            label[0] = (char)(48 + table[i][j]);
            DrawText(label, (origin.x + 16) + (45 * i), (origin.y + 13) + (45 * j), 24, BLACK);
        }
    }

    DrawRectangle((origin.x + 134), origin.y, 3, 405, DARKGRAY);
    DrawRectangle((origin.x + 269), origin.y, 3, 405, DARKGRAY);
    DrawRectangle(origin.x, (origin.y + 134), 405, 3, DARKGRAY);
    DrawRectangle(origin.x, (origin.y + 269), 405, 3, DARKGRAY);
}
