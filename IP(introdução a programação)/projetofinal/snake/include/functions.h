#include "../include/devices.h"
#include "../include/grid.h"
#include "../include/object.h"
#include "../include/settings.h"
#include "../include/snake.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int random_number(int begin, int end);
void wait(Window *window, int time);
void opening_game(Window *window, Settings *settings);
int update_settings(Settings *settings, Window *window, Snake *snake, Object *fruit, Object *base, Grid *grid);
void spawn_fruit(Settings *settings, Snake *snake, Object *fruit);
void initialize_game(Settings *settings, Snake *snake, Object *fruit, Object *base, Grid *grid);
int update_game(Window *window, Settings *settings, Snake *snake, Object *fruit, Object *base);
void render_game(Window *window, Settings *settings, Snake *snake, Object *fruit, Object *base, Grid *grid);
void finish_game(Settings *settings, Snake *snake, Object *fruit, Object *base, Grid *grid);
void run_game(void);

#endif
