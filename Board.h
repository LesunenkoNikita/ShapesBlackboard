#ifndef BOARD_H
#define BOARD_H
using namespace std;
#include <vector>
#include <string>
#include <variant>
class Triangle;
class Rectangle;

class Board
{
public:
    Board();
    void drawBoard(Triangle& triangle, Rectangle& rectangle);
    void addToShapes(string type, int x, int y, int height, char filling, char color);
    void addToShapes(string type, int x, int y, int height, int width, char filling, char color);
    vector<vector<variant<string, int, char>>> getShapes();
    int getBOARD_WIDTH() const;
    int getBOARD_HEIGHT() const;
    void undo();
    void clear();
    int findByCoords(Triangle& triangle, Rectangle& rectangle, int x, int y);
    void addToCoords(int id);
    void remove(int id);
    void edit(int id, int x, int y, int height, char filling, char color);
    void edit(int id, int x, int y, int height, int width, char filling, char color);
    void paint(int id, char color);
    void move(int id, int x, int y);
    vector<vector<char>> grid;
private:
    static const int BOARD_WIDTH = 80;
    static const int BOARD_HEIGHT = 25;
    int id = 0;
    vector<vector<variant<string, int, char>>> shapes;
    vector<int> coords;
};

#endif //BOARD_H
