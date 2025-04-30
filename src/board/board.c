#include "raylib.h"
#include <stdio.h>

void draw_board(int table[9][9], int initial[9][9], Vector2 origin);

// std is for moving and selecting numbers on the board.
// entry is for inputing numbers on the board.
enum state
{
    std = 0,
    entry = 1
};

char label[] = "\0";
Vector2 position = {.x = -1, .y = -1};

void draw_board(int table[9][9], int initial[9][9], Vector2 origin)
{
    // Key Inputs =========================================================
    if (position.x == -1)
    {
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT))
        {
            HideCursor();
            position.x = 4;
            position.y = 4;
        }
    }

    if (IsKeyPressed(KEY_LEFT) && position.x >= 1)
    {
        HideCursor();
        position.x--;
    }

    if (IsKeyPressed(KEY_RIGHT) && position.x <= 7 && position.x != -1)
    {
        HideCursor();
        position.x++;
    }

    if (IsKeyPressed(KEY_UP) && position.y >= 1)
    {
        HideCursor();
        position.y--;
    }

    if (IsKeyPressed(KEY_DOWN) && position.y <= 7 && position.y != -1)
    {
        HideCursor();
        position.y++;
    }

    int n = GetKeyPressed();

    // Only allows deleting/changing a number only if it is not part of the initial state
    if (n == KEY_BACKSPACE && initial[(int)position.x][(int)position.y] == 0)
    {
        table[(int)position.x][(int)position.y] = 0;
    }
    else if (n >= 49 && n <= 57 && initial[(int)position.x][(int)position.y] == 0)
    {
        table[(int)position.x][(int)position.y] = n - 48;
    }
    // Key inputs =========================================================

    // Draws the position rectangle before everything else
    // to prevent it from occluding other stuff. It's also outside
    // of the loops for this same reason.
    if (position.x != -1)
    {
        DrawRectangle((origin.x + 3) + (45 * position.x), (origin.y + 3) + (45 * position.y), 40, 40, SKYBLUE);
    }

    // Mouse inputs =======================================================
    if (GetMouseDelta().x != 0 && GetMouseDelta().y != 0)
    {
        ShowCursor();

        // Resets the position when mouse movement is detected.
        // This makes sure the position is correct in the next frame
        position.x = -1;
        position.y = -1;
    }
    // Mouse inputs =======================================================

    // Draws the board on the screen
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!IsCursorHidden())
            {
                // Draws a box behind around the number the mouse is over
                if (GetMouseX() <= (origin.x + 43 + (45 * i)) && GetMouseX() >= (origin.x + 3 + (45 * i)) && GetMouseY() <= (origin.y + 43 + (45 * j)) && GetMouseY() >= (origin.y + 3 + (45 * j)))
                {
                    position.x = i;
                    position.y = j;
                }
            }

            if (table[i][j] != 0)
            {
                // Verifies for repeated numbers
                if (table[i][j] == table[(int)position.x][(int)position.y] && (i != position.x || j != position.y))
                {
                    // Highlights the repeated numbers
                    DrawRectangle((origin.x + 3) + (45 * i), (origin.y + 3) + (45 * j), 40, 40, LIGHTGRAY);
                
                    // Marks the numbers which violate the rules
                    if ((position.x == i || position.y == j) || ((int)position.x / 3 == i / 3 && (int)position.y / 3 == j / 3))
                    {
                        DrawRectangle((origin.x + 3) + (45 * i), (origin.y + 3) + (45 * j), 40, 40, MAROON);
                    }
                }

                label[0] = (char)(48 + table[i][j]);
                DrawText(label, (origin.x + 16) + (45 * i), (origin.y + 13) + (45 * j), 24, (initial[i][j] != 0 ? BLACK : DARKGRAY));
            }
        }
    }

    // 3x3 big grid
    DrawRectangle((origin.x + 134), origin.y, 3, 405, DARKGRAY);
    DrawRectangle((origin.x + 269), origin.y, 3, 405, DARKGRAY);
    DrawRectangle(origin.x, (origin.y + 134), 405, 3, DARKGRAY);
    DrawRectangle(origin.x, (origin.y + 269), 405, 3, DARKGRAY);
}
