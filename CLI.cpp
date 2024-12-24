#include "CLI.h"
#include <iostream>
#include <string>
#include "Board.h"
#include <sstream>
#include "IShape.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

CLI::CLI(Board& board) {
    Triangle triangle;
    Rectangle rectangle;
    int idOfSelected;
    while (1) {
        cout << "Enter the command: ";
        string command;
        getline(cin, command);
        if (command == "draw") {
            board.drawBoard(triangle, rectangle);
        }
        else if (command == "list") {
            for (const auto& shape : board.getShapes()) {
                cout << "->";
                for (const auto& element : shape) {
                    visit([](auto& arg) { cout << arg << " "; }, element);
                }
                cout << endl;
            }
        }
        else if (command == "shapes") {
            cout << "All available shapes:" << endl;
            cout<< "triangle coordinates height w(for whole filled figure) or f(for frame) color(color is optional)" << endl;
            cout << "rectangle coordinates height width w(for whole filled figure) or f(for frame) color(color is optional)" << endl;
        }
        else if (command.compare(0, 3, "add") == 0) {
            if (command.compare(4, 8, "triangle") == 0) {
                istringstream iss(command);
                string command;
                string shape;
                int a, b, c;
                char filling;
                iss >> command >> shape >> a >> b >> c >> filling;
                char color;
                if (iss >> color) {
                    board.addToShapes(shape, a, b, c, filling, color);
                }
                else {
                    board.addToShapes(shape, a, b, c, filling, '*');
                }
            }
            else if (command.compare(4, 9, "rectangle") == 0) {
                istringstream iss(command);
                string shape;
                string command;
                int a, b, c, d;
                char filling;
                iss >> command >> shape >> a >> b >> c >> d >> filling;
                char color;
                if (iss >> color) {
                    board.addToShapes(shape, a, b, c, d, filling, color);
                }
                else {
                    board.addToShapes(shape, a, b, c, d, filling, '*');
                }
            }
            else {
                cout << "Invalid shape." << endl;
            }
        }
        else if (command == "undo") {
            board.undo();
        }
        else if (command == "clear") {
            board.clear();
        }
        else if (command.compare(0, 6, "select") == 0) {
            istringstream iss(command);
            string select;
            int a, b;
            iss >>select >> a;
            if (iss >> b) {
                idOfSelected = board.findByCoords(triangle, rectangle, a, b);
            }
            else {
                idOfSelected = a;
            }
            cout << "Figure with id " << idOfSelected << " selected" << endl;
        }
        else if (command == "remove") {
            board.remove(idOfSelected);
            cout << "Selected figure deleted" << endl;
        }
        else if (command.compare(0, 5, "paint") == 0) {
            istringstream iss(command);
            string command;
            char color;
            iss >> command >> color;
            board.paint(idOfSelected, color);
            cout << "Selected figure repainted" << endl;
        }
        else if (command.compare(0, 4, "move") == 0) {
            istringstream iss(command);
            string command;
            int x, y;;
            iss >> command >> x >> y;
            board.move(idOfSelected, x, y);
            cout << "Selected figure moved" << endl;
        }
        else if (command.compare(0, 4, "edit") == 0) {
            istringstream iss(command);
            string command;
            string figure;
            int x, y, height;
            iss >> command >> figure;
            if (figure == "rectangle") {
                int width;
                char filling, color;
                iss >> x >> y >> height >>width >> filling >> color;
                board.edit(idOfSelected, x, y, height, width, filling, color);
            }
            else if (figure == "triangle") {
                char filling, color;
                iss >> x >> y >> height >> filling >> color;
                board.edit(idOfSelected, x, y, height, filling, color);
            }
        }
    }
}
