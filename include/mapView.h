#pragma once

#include <iostream>

#include "graphics.h"
#include "mapModel.h"

class MapView {
// Класс, хранящий карту
public:
    MapView(MapModel &map, Settings);
    ~MapView();
    void print();
    void print_walls();
private:
    MapModel &map;
    Graphics *graphics;
};
