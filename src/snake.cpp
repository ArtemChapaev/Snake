#include <iostream>

#include "snake.h"

unsigned Position::get_x() { return x; }

unsigned Position::get_y() { return y; }

void Position::set_x(unsigned xx) { x = xx; }

void Position::set_y(unsigned yy) { y == yy; }

Snake::Snake(unsigned map_len, unsigned map_wid, float delay_coef) : length(SNAKE_LENGTH),
                                                                     direction(right), delay_coef(delay_coef) {
    unsigned y = map_wid * STANDART_FOR_Y;
    unsigned x = 0;

    if (map_len * STANDART_FOR_X >= SNAKE_LENGTH) {
        x = map_len * INDEX_FOR_X + SNAKE_LENGTH;
    } else {
        x = SNAKE_LENGTH;
    }

    for (int i = 0; i < SNAKE_LENGTH; ++i) {
        snake.emplace_back(x, y);
        --x;
    }
}

Position Snake::get_head() { return snake.front(); }

Position Snake::get_next() {
    Position head = get_head();

    if (direction == right) {
        return {head.get_x() + 1, head.get_y()};
    } else if (direction == left) {
        return {head.get_x() - 1, head.get_y()};
    } else if (direction == up) {
        return {head.get_x(), head.get_y() + 1};
    } else {
        return {head.get_x(), head.get_y() - 1};
    }
}

Direction Snake::get_direction() { return direction; }

void Snake::set_direction(Direction dir) { direction = dir; }

unsigned Snake::get_delay_coef() { return delay_coef; }

Position Snake::move() {
    Position pos_for_next = get_next();

    for (auto &s: snake) {
        auto temp = s;
        s = pos_for_next;
        pos_for_next = temp;
    }
    return pos_for_next; // pos of last tail
}

int Snake::increase_length(Position pos_for_tail) {
    snake.push_back(pos_for_tail);
    ++length;
    return 0;
}