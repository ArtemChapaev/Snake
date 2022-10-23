#include "settings.h"

Term::RGB rgb_parser(std::string &string) {
    std::istringstream input(string);
    std::string r, g, b;
    getline(input, r, ',');
    getline(input, g, ',');
    getline(input, b, ',');

    return {static_cast<uint8_t>(stoi(r)), static_cast<uint8_t>(stoi(g)), static_cast<uint8_t>(stoi(b))};
}

int parser(Settings &settings, std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }

    std::string var, map_length, map_width, speed, solid_wall, score, bonus_apples, view_mode, reset_length, key_up,
            key_down, key_left, key_right, teleport, key_pause, key_enter, snake_color, empty_color, wall_color, teleport_color,
            bonus_color, antibonus_color, speed_bonus_color, speed_antibonus_color;

    while (!file.eof()) {

        getline(file, var, '=');
        if (var == "map_length") getline(file, map_length);
        if (var == "map_width") getline(file, map_width);
        if (var == "speed") getline(file, speed);
        if (var == "solid_wall") getline(file, solid_wall);
        if (var == "score") getline(file, score);
        if (var == "bonus_apples") getline(file, bonus_apples);
        if (var == "teleport") getline(file, teleport);
        if (var == "view_mode") getline(file, view_mode);
        if (var == "reset_length") getline(file, reset_length);
        if (var == "key_up") getline(file, key_up);
        if (var == "key_down") getline(file, key_down);
        if (var == "key_left") getline(file, key_left);
        if (var == "key_right") getline(file, key_right);
        if (var == "key_pause") getline(file, key_pause);
        if (var == "key_enter") getline(file, key_enter);
        if (var == "snake_color") getline(file, snake_color);
        if (var == "empty_color") getline(file, empty_color);
        if (var == "wall_color") getline(file, wall_color);
        if (var == "teleport_color") getline(file, teleport_color);
        if (var == "bonus_color") getline(file, bonus_color);
        if (var == "antibonus_color") getline(file, antibonus_color);
        if (var == "speed_bonus_color") getline(file, speed_bonus_color);
        if (var == "speed_antibonus_color") getline(file, speed_antibonus_color);
    }

    settings.map_length = stoi(map_length);
    settings.map_width = stoi(map_width);
    settings.speed = stof(speed);
    settings.solid_wall = stoi(solid_wall);
    settings.score = stoi(score);
    settings.bonus_apples = stoi(bonus_apples);
    settings.teleport = stoi(teleport);
    settings.view_mode = stoi(view_mode);
    settings.reset_length = stoi(reset_length);
    settings.key_up = stoi(key_up);
    settings.key_down = stoi(key_down);
    settings.key_left = stoi(key_left);
    settings.key_right = stoi(key_right);
    settings.key_pause = stoi(key_pause);
    settings.key_enter = stoi(key_enter);
    settings.snake_color = rgb_parser(snake_color);
    settings.empty_color = rgb_parser(empty_color);
    settings.wall_color = rgb_parser(wall_color);
    settings.teleport_color = rgb_parser(teleport_color);
    settings.bonus_color = rgb_parser(bonus_color);
    settings.antibonus_color = rgb_parser(antibonus_color);
    settings.speed_bonus_color = rgb_parser(speed_bonus_color);
    settings.speed_antibonus_color = rgb_parser(speed_antibonus_color);

    file.close();
    return 0;
}