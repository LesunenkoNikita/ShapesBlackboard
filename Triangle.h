#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "IShape.h"
class Board;

class Triangle : public IShape
{
public:
    void draw() const override;
    void draw(int x, int y, int height, char filling, char color, Board& board);
    void find(int x, int y, int height, char filling, char color, Board& board, int a, int b, int id);
};

#endif //TRIANGLE_H
