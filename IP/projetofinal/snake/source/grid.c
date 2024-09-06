#include <stdlib.h>

#include "../include/grid.h"
#include "../include/object.h"
#include "../include/settings.h"

/**
 * @brief Create a grid
 *
 * @param settings Settings
 * @return Grid
 */
Grid create_grid(Settings *settings) {
    float side = 2.0 / settings->amount;

    Grid grid;

    grid.lines = settings->amount;
    grid.columns = 1 + settings->amount / 2;

    grid.percent = 0.95;

    grid.data = NULL;

    while (grid.data == NULL) {
        grid.data = (Object **)malloc(grid.lines * sizeof(Object *));
    }

    for (int line = 0; line < grid.lines; line++) {
        grid.data[line] = NULL;

        while (grid.data[line] == NULL) {
            grid.data[line] = (Object *)malloc(grid.columns * sizeof(Object));
        }
    }

    for (int index = 0; index < 3; index++) {
        grid.color[index] = grid.percent * FORE[settings->color][index];
    }

    for (int line = 0; line < grid.lines; line++) {
        for (int column = 0; column < grid.columns; column++) {
            int x = 2 * column + line % 2;
            int y = line;

            grid.data[line][column] = create_object(settings, x, y, side, grid.color);
        }
    }

    return grid;
}

/**
 * @brief Delete a grid
 *
 * @param grid Grid
 */
void delete_grid(Grid *grid) {
    if (grid->data != NULL) {
        for (int line = 0; line < grid->lines; line++) {
            for (int column = 0; column < grid->columns; column++) {
                delete_object(&grid->data[line][column]);
            }
        }

        for (int line = 0; line < grid->lines; line++) {
            free(grid->data[line]);
        }

        free(grid->data);
    }
}

/**
 * @brief Draw grid
 *
 * @param grid Grid
 */
void draw_grid(Grid *grid) {
    for (int line = 0; line < grid->lines; line++) {
        for (int column = 0; column < grid->columns; column++) {
            draw_object(&grid->data[line][column]);
        }
    }
}

/**
 * @brief Set grid color
 *
 * @param grid Grid
 * @param settings Settings
 */
void set_grid_color(Grid *grid, Settings *settings) {
    for (int index = 0; index < 3; index++) {
        grid->color[index] = grid->percent * FORE[settings->color][index];
    }

    for (int line = 0; line < grid->lines; line++) {
        for (int column = 0; column < grid->columns; column++) {
            set_object_color(&grid->data[line][column], settings, grid->color);
        }
    }
}
