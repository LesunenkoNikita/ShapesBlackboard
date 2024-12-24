#include "Rectangle.h"
#include "Board.h"

void Rectangle::draw() const
{
    return;
}

void Rectangle::draw(int x, int y, int height, int width, char filling, char color, Board &board)
{
    if (height <= 0 || width <= 0 || x <= 0 || x >= board.getBOARD_WIDTH() || y <= 0 || y >= board.getBOARD_HEIGHT()) return;
    int posX = 0;
    int posY = 0;
    if (filling == 'f') {
        for (int i = 0; i < width; i++)
        {
            posX = x + i;
            posY = y;
            if (posX >= 0 && posX < board.getBOARD_WIDTH())
                board.grid[posY][posX] = color;
            if (posY-height+1 >= 0)
            {
                board.grid[posY-height+1][posX] = color;
            }
        }
        for (int i = 1; i < height-1; i++)
        {
            posX = x;
            posY = y - i;
            if (posY >= 0)
            {
                board.grid[posY][posX] = color;
            }
            if (posX+width-1 < board.getBOARD_WIDTH())
            {
                board.grid[posY][posX+width-1] = color;
            }
        }
    }
    else if (filling == 'w') {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int posX = x + j;
                int posY = y - i;
                if (posX >= 0 && posY >= 0 && posX < board.getBOARD_WIDTH() && posY < board.getBOARD_HEIGHT()) {
                    board.grid[posY][posX] = color;
                }
            }
        }

    }
}

void Rectangle::find(int x, int y, int height, int width, char filling, char color, Board& board, int a, int b, int id) {
    int posX = 0;
    int posY = 0;
    if (filling == 'f') {
        for (int i = 0; i < width; i++)
        {
            posX = x + i;
            posY = y;
            if (posX >= 0 && posX < board.getBOARD_WIDTH()) {
                if (posY == a && posX == b) {
                    board.addToCoords(id);
                    return;
                }
            }
            if (posY-height+1 >= 0)
            {
                if (posY-height+1 == a && posX == b) {
                    board.addToCoords(id);
                    return;
                }
            }
        }
        for (int i = 1; i < height-1; i++)
        {
            posX = x;
            posY = y - i;
            if (posY >= 0)
            {
                if (posY == a && posX == b) {
                    board.addToCoords(id);
                    return;
                }
            }
            if (posX+width-1 < board.getBOARD_WIDTH())
            {
                if (posY == a && posX+width-1 == b) {
                    board.addToCoords(id);
                    return;
                }
            }
        }
    }
    else if (filling == 'w') {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int posX = x + j;
                int posY = y - i;
                if (posX >= 0 && posY >= 0 && posX < board.getBOARD_WIDTH() && posY < board.getBOARD_HEIGHT()) {
                    if (posY == a && posX == b) {
                        board.addToCoords(id);
                        return;
                    }
                }
            }
        }

    }
}