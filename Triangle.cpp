#include "Triangle.h"
#include "Board.h"

void Triangle::draw() const
{
    return;
}
void Triangle::draw(int x, int y, int height, char filling, char color, Board& board)
    {
        if (height <= 0 || x <= 0 || x >= board.getBOARD_WIDTH() || y <= 0 || y >= board.getBOARD_HEIGHT()) return;
        if (filling == 'f') {
            for (int i = 0; i < height; ++i) {
                int leftMost = x - i;
                int rightMost = x + i;
                int posY = y + i;
                if (posY < board.getBOARD_HEIGHT()) {
                    if (leftMost >= 0 && leftMost < board.getBOARD_WIDTH())
                        board.grid[posY][leftMost] = color;
                    if (rightMost >= 0 && rightMost < board.getBOARD_WIDTH() && leftMost != rightMost)
                        board.grid[posY][rightMost] = color;
                }
            }
            for (int j = 0; j < 2 * height - 1; ++j) {
                int baseX = x - height + 1 + j;
                int baseY = y + height - 1;
                if (baseX >= 0 && baseX < board.getBOARD_WIDTH() && baseY < board.getBOARD_HEIGHT())
                    board.grid[baseY][baseX] = color;
            }
        }
        else if (filling == 'w') {
            for (int i = 0; i < height; ++i) {
                int startX = x - i;
                int endX = x + i;
                int posY = y + i;
                if (posY < board.getBOARD_HEIGHT() && posY >= 0) {
                    for (int j = startX; j <= endX; ++j) {
                        if (j >= 0 && j < board.getBOARD_WIDTH())
                            board.grid[posY][j] = color;
                    }
                }
            }
        }
    }

void Triangle::find(int x, int y, int height, char filling, char color, Board& board, int a, int b, int id){
    if (filling == 'f') {
        for (int i = 0; i < height; ++i) {
            int leftMost = x - i;
            int rightMost = x + i;
            int posY = y + i;
            if (posY < board.getBOARD_HEIGHT()) {
                if (leftMost >= 0 && leftMost < board.getBOARD_WIDTH()) {
                    if (posY == a && leftMost == b) {
                        board.addToCoords(id);
                        return;
                    }
                }
                if (rightMost >= 0 && rightMost < board.getBOARD_WIDTH() && leftMost != rightMost) {
                    if (posY == a && rightMost == b) {
                        board.addToCoords(id);
                        return;
                    }
                }
            }
        }
        for (int j = 0; j < 2 * height - 1; ++j) {
            int baseX = x - height + 1 + j;
            int baseY = y + height - 1;
            if (baseX >= 0 && baseX < board.getBOARD_WIDTH() && baseY < board.getBOARD_HEIGHT()) {
                if (baseY == a && baseX == b) {
                    board.addToCoords(id);
                    return;
                }
            }
        }
    }
    else if (filling == 'w') {
        for (int i = 0; i < height; ++i) {
            int startX = x - i;
            int endX = x + i;
            int posY = y + i;
            if (posY < board.getBOARD_HEIGHT() && posY >= 0) {
                for (int j = startX; j <= endX; ++j) {
                    if (j >= 0 && j < board.getBOARD_WIDTH()) {
                        if (posY == a && j == b) {
                            board.addToCoords(id);
                            return;
                        }
                    }
                }
            }
        }
    }
}
