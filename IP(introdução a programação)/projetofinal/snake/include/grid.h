#include "../include/object.h"
#include "../include/settings.h"

#ifndef GRID_H
#define GRID_H

typedef struct {
    int lines;
    int columns;

    float percent;
    float color[3];

    Object **data;
} Grid;

Grid create_grid(Settings *settings);
void delete_grid(Grid *grid);
void draw_grid(Grid *grid);
void set_grid_color(Grid *grid, Settings *settings);

#endif
