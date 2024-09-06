#include <stdlib.h>
#include <stdio.h>

#include "../include/devices.h"
#include "../include/libraries.h"
#include "../include/object.h"
#include "../include/settings.h"
#include "../include/snake.h"

/**
 * @brief Create and initialize a snake
 *
 * @param settings Settings
 * @param x Column position
 * @param y Line position
 * @return Snake
 */
Snake create_snake(Settings *settings, int x, int y) {
    int amount = settings->amount;

    float step = 2.0 / settings->amount;

    Snake snake;

    snake.direction = NOTHING;
    snake.size = 1;
    snake.capacity = amount * amount;
    snake.velocity = 5;

    snake.color[0] = 0.9;
    snake.color[1] = 0.9;
    snake.color[2] = 0.9;

    snake.body = NULL;

    while (snake.body == NULL) {
        snake.body = (Object *)malloc(snake.capacity * sizeof(Object));
    }

    snake.body[0] = create_object(settings, x, y, step, snake.color);

    return snake;
}

/**
 * @brief Delete snake
 *
 * @param snake Snake
 */
void delete_snake(Snake *snake) {
    if (snake->body) {
        for (int index = 0; index < snake->size; index++) {
            delete_object(&(snake->body[index]));
        }

        free(snake->body);
    }
}

/**
 * @brief Draw snake
 *
 * @param snake Snake
 */
void draw_snake(Snake *snake) {
    for (int index = 0; index < snake->size; index++) {
        draw_object(&(snake->body[index]));
    }
}

/**
 * @brief Update snake position
 *
 * @param snake Snake
 * @param settings Settings
 */
void run_snake(Snake *snake, Settings *settings) {
    static int count = 0;

    if (count % snake->velocity == 0) {
        int size = snake->size;
        int direction = snake->direction;

        int x, y;

        for (int index = size - 1; index >= 1; index--) {
            x = snake->body[index - 1].x;
            y = snake->body[index - 1].y;

            set_object_position(&(snake->body[index]), settings, x, y);
        }

        x = snake->body[0].x;
        y = snake->body[0].y;

        switch (direction) {
            case UP:
                y -= 1;
                break;
            case DOWN:
                y += 1;
                break;
            case LEFT:
                x -= 1;
                break;
            case RIGHT:
                x += 1;
                break;
        }

        if (!settings->collision) {
            if (x == -1) {
                x = settings->amount - 1;
            }
            if (y == -1) {
                y = settings->amount - 1;
            }
            if (x == settings->amount) {
                x = 0;
            }
            if (y == settings->amount) {
                y = 0;
            }
        }

        set_object_position(&(snake->body[0]), settings, x, y);
    }

    count = (count + 1) % snake->velocity;
}

/**
 * @brief Update snake direction
 *
 * @param snake Snake
 * @param direction Direction
 */
void update_direction(Snake *snake, Window *window) {
    static int directions[2][2] = {
        {LEFT, RIGHT},
        {UP, DOWN}
    };

    if (snake->size < 3) {
        for (int direction = LEFT; direction <= DOWN; direction++) {
            if (verify_key(window, direction)) {
                snake->direction = direction;
                
            }
        }
    } else {
        for (int index = 0; index < 2; index++) {
            if (verify_key(window, directions[index][0]) && snake->direction != directions[index][1]) {
                snake->direction = directions[index][0];
            }
            if (verify_key(window, directions[index][1]) && snake->direction != directions[index][0]) {
                snake->direction = directions[index][1];
            }
        }
    }
}

/**
 * @brief Growth snake in one block
 *
 * @param snake Snake
 * @param settings Settings
 */
void growth_snake(Snake *snake, Settings *settings) {
    int size = snake->size;

    if (size == snake->capacity) {
        return;
    }

    int x = snake->body[size - 1].x;
    int y = snake->body[size - 1].y;

    float side = snake->body[0].side;

    snake->body[size] = create_object(settings, x, y, side, snake->color);

    snake->size++;
}

/**
 * @brief Verify whether snake eat a fruit
 *
 * @param snake Snake
 * @param fruit Fruit
 */
int eat_fruit(Snake *snake, Object *fruit) {
    int x_snake = snake->body[0].x;
    int y_snake = snake->body[0].y;

    int x_fruit = fruit->x;
    int y_fruit = fruit->y;

    if (x_snake == x_fruit && y_snake == y_fruit) {
        return true;
    }

    return false;
}

/**
 * @brief Verify snake collision
 *
 * @param snake Snake
 */
int verify_snake(Snake *snake, Settings *settings) {
    if (snake->size == snake->capacity) {
        return true;
    }

    int x_snake = snake->body[0].x;
    int y_snake = snake->body[0].y;

    if (settings->collision) {
        if (x_snake == -1 || x_snake == settings->amount) {
            return true;
        }
        if (y_snake == -1 || y_snake == settings->amount) {
            return true;
        }
    }

    for (int index = 2; index < snake->size; index++) {
        int x = snake->body[index].x;
        int y = snake->body[index].y;

        if (x == x_snake && y == y_snake) {
            return true;
        }
    }

    return false;
}