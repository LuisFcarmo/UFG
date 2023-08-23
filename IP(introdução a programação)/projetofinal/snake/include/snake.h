#include "../include/object.h"
#include "../include/settings.h"

#ifndef SNAKE_H
#define SNAKE_H

typedef struct {
    Object *body;

    int size;
    int capacity;
    int direction;
    int velocity;

    float color[3];
} Snake;

Snake create_snake(Settings *settings, int x, int y);
void draw_snake(Snake *snake);
void delete_snake(Snake *snake);
void run_snake(Snake *snake, Settings *settings);
void update_direction(Snake *snake, Window *window);
void growth_snake(Snake *snake, Settings *settings);
int eat_fruit(Snake *snake, Object *fruit);
int verify_snake(Snake *snake, Settings *settings);

#endif
