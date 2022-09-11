#include <cstdlib>
#include <ctime>

#include "mapModel.h"
#include "snake.h"

MapModel::MapModel(unsigned length, unsigned width) : length(length), width(width) {
    srand(time(0));
    field = new Cell *[width];

    for (int i = 0; i < width; i++) {
        field[i] = new Cell[length];
        for (int j = 0; j < length; j++) {
            field[i][j] = EMPTY;
            if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {
                field[i][j] = WALL;
            }
        }
    }
}

// MapModel::~MapModel() {
//     for(int i = 0; i < width; i++) {
//         delete[] field[i];
//     }
//     delete[] field;
// }

void MapModel::put_snake(Snake s) {
    auto it = s.snake.begin();

    while (it != s.snake.end()) {
        Position d = *it;
        field[d.get_x()][d.get_y()] = SNAKE;
        it++;
    }
}

void MapModel::generate_fruit() {
    bool fruit_created = false;
    while (!fruit_created) {
        unsigned x = rand() % (length - 2) + 1; // чтобы было меньше итераций цикла, из-за отсутствия WALL
        unsigned y = rand() % (width - 2) + 1;
        if (check_cell(x, y) == EMPTY) {
            field[x][y] = FRUIT;
            fruit_created = true;
        }
    }
}

unsigned MapModel::get_width() {
    return width;
}

unsigned MapModel::get_length() {
    return length;
}

void MapModel::clear_cell(unsigned x, unsigned y) {
    field[x][y] = EMPTY;
}

Cell MapModel::check_cell(unsigned x, unsigned y) {
    return field[x][y];
}