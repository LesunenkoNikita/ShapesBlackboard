#include "Board.h"
using namespace std;
#include <variant>
#include <vector>
#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"

Board::Board() : grid(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' ')) {}
void Board::drawBoard(Triangle& triangle, Rectangle& rectangle)
{
    grid = vector<vector<char>>(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' '));
    for (const auto& shape : shapes) {
        if (shape.size() == 7) {
            triangle.draw(get<int>(shape[2]), get<int>(shape[3]), get<int>(shape[4]), get<char>(shape[5]), get<char>(shape[6]), *this);
        } else if (shape.size() == 8) {
            rectangle.draw(get<int>(shape[2]), get<int>(shape[3]), get<int>(shape[4]), get<int>(shape[5]), get<char>(shape[6]), get<char>(shape[7]), *this);
        }
    }
    for (auto& row : grid) {
        for (char c : row) {
            cout << c;
        }
        cout << "\n";
    }
}

void Board::addToShapes(string type, int x, int y, int height, char filling, char color)
{
    shapes.push_back({id, type, x, y, height, filling, color});
    id++;
}
void Board::addToShapes(string type, int x, int y, int height, int width, char filling, char color)
{
    shapes.push_back({id, type, x, y, height, width, filling, color});
    id++;
}
int Board::getBOARD_WIDTH() const
{
    return BOARD_WIDTH;
}
int Board::getBOARD_HEIGHT() const
{
    return BOARD_HEIGHT;
}
vector<vector<variant<string, int, char> > > Board::getShapes() {
    return shapes;
}
void Board::undo() {
    shapes.pop_back();
}
void Board::clear() {
    shapes.clear();
}
int Board::findByCoords(Triangle& triangle, Rectangle& rectangle, int x, int y) {
    grid = vector<vector<char>>(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' '));
    for (const auto& shape : shapes) {
        if (shape.size() == 7) {
            triangle.find(get<int>(shape[2]), get<int>(shape[3]), get<int>(shape[4]), get<char>(shape[5]), get<char>(shape[6]), *this, x, y, get<int>(shape[0]));
        } else if (shape.size() == 8) {
            rectangle.find(get<int>(shape[2]), get<int>(shape[3]), get<int>(shape[4]), get<int>(shape[5]), get<char>(shape[6]), get<char>(shape[7]), *this, x, y, get<int>(shape[0]));
        }
    }
    return coords.back();
}

void Board::addToCoords(int id) {
    coords.push_back(id);
}

void Board::remove(int id) {
    for (const auto& shape : shapes) {
        if (get<int>(shape[0]) == id) {
            int idx = &shape - &shapes[0];
            shapes.erase(shapes.begin() + idx);
        }
    }
}
void Board::edit(int id, int x, int y, int height, char filling, char color) {
    for (auto& shape : shapes) {
        if (get<int>(shape[0]) == id) {
            shape[2] = x;
            shape[3] = y;
            shape[4] = height;
            shape[5] = filling;
            shape[6] = color;
            break;
        }
    }
}
void Board::edit(int id, int x, int y, int height, int width, char filling, char color) {
    for (auto& shape : shapes) {
        shape[2] = x;
        shape[3] = y;
        shape[4] = height;
        shape[5] = width;
        shape[6] = filling;
        shape[7] = color;
        break;
    }
}
void Board::paint(int id, char color) {
    for (auto& shape : shapes) {
        if (get<int>(shape[0]) == id) {
            if (get<string>(shape[1]) == "triangle") {
                shape[6] = color;
                break;
            }
            else if (get<string>(shape[1]) == "rectangle") {
                shape[7] = color;
                break;
            }
        }
    }
}
void Board::move(int id, int x, int y) {
    for (auto& shape : shapes) {
        if (get<int>(shape[0]) == id) {
            shape[2] = x;
            shape[3] = y;
            break;
        }
    }
}


