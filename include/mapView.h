#pragma once

#include <iostream>

#include "graphics.h"
#include "mapModel.h"

class MapView {
// Class for map display
public:
    MapView(MapModel &map, Settings);
    ~MapView();

    void print();
    void print_walls();
private:
    MapModel &map;
    Graphics *graphics;
};
