#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "IShape.h"
class Board;

class Rectangle : public IShape
{
public:
    void draw() const override;
    void draw(int x, int y, int height, int width, char filling, char color, Board& board);
    void find(int x, int y, int height, int width, char filling, char color, Board& board, int a, int b, int id);
};

#endif //RECTANGLE_H
