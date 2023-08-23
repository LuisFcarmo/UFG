#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

#include "../include/devices.h"
#include "../include/functions.h"
#include "../include/geometry.h"
#include "../include/grid.h"
#include "../include/libraries.h"
#include "../include/object.h"
#include "../include/settings.h"
#include "../include/snake.h"

/**
 * @brief Wait milliseconds
 *
 * @param time time
 */
void wait(Window *window, int time) {
    int steps = 0.1 * time;

    if (steps < 1) {
        steps = 1;
    }

    for (int step = 0; step < steps && window_available(window); step++) {
#if __linux__
        usleep(10000);
#elif _WIN32
        Sleep(10);
#endif
    }
}

/**
 * @brief Generate a random integer number in a range
 *
 * @param begin Range begin
 * @param end Range end
 * @return Random integer between begin and end
 */
int random_number(int begin, int end) {  //
    return begin + rand() % (end - begin + 1);
}

/**
 * @brief Run opening animation to game
 *
 * @param window Window
 * @param settings Settings
 */
void opening_game(Window *window, Settings *settings) {
    srandom(time(NULL));

    set_colors(0.8, 1.0);

    printf("\nTeclas do Jogo");
    printf("\nW, A, S, D e Setas: Movimento da cobra");
    printf("\n1 a 7: Muda a cor de fundo");
    printf("\n\",\" e \".\": Aumenta e diminui a dificuldade do jogo");
    printf("\nEscape: Retorna para a tela de configuracao ou finaliza o jogo");
    printf("\nBackspace: Ativa ou Desativa a colisao com as bordas");
    printf("\nEspace: Ativa ou Desativa as guias");
    printf("\nEnter: Inicia o jogo");
    printf("\n");

    settings->color = random_number(0, 6);

    int size = 60;
    float side = 2.0 / settings->amount;

    Object text[60];

    int lines[60] = {
        10, 10, 10, 11, 12, 12, 12, 13, 14, 14, 14,              // S
        14, 13, 12, 11, 10, 11, 12, 12, 13, 13, 14, 12, 11, 10,  // N
        14, 13, 12, 11, 10, 10, 10, 11, 12, 12, 13, 14,          // A
        14, 13, 12, 11, 10, 12, 12, 11, 11, 10, 13, 13, 14,      // K
        10, 10, 10, 11, 12, 12, 13, 14, 14, 14                   // E
    };
    int columns[60] = {
        4,  3,  2,  2,  2,  3,  4,  4,  4,  3,  2,              // S
        6,  6,  6,  6,  6,  7,  7,  8,  8,  9,  9,  9,  9,  9,  // N
        11, 11, 11, 11, 11, 12, 13, 13, 13, 12, 13, 13,         // A
        15, 15, 15, 15, 15, 16, 17, 17, 18, 18, 17, 18, 18,     // K
        22, 21, 20, 20, 20, 21, 20, 20, 21, 22                  // E
    };

    float color[3] = {0.9, 0.9, 0.9};

    window_color(FORE[settings->color]);

    for (int index = 0; index < size; index++) {
        text[index] = create_object(settings, columns[index], lines[index], side, BACK[settings->color]);
    }

    for (int length = 0; length < size; length++) {
        wait(window, 40);

        clear_window();

        for (int index = 0; index <= length; index++) {
            set_object_color(&text[index], settings, color);
        }

        for (int index = 0; index < size; index++) {
            draw_object(&text[index]);
        }

        update_window(window);
    }

    for (int index = 0; index < size; index++) {
        delete_object(&text[index]);
    }

    wait(window, 1000);
}

/**
 * @brief Update settings
 *
 * @param settings Settings
 * @param window Window
 * @param snake Snake
 * @param fruit Fruit
 * @param base Background base
 * @param grid Grid
 * @return Condition to exit settings
 */
int update_settings(Settings *settings, Window *window, Snake *snake, Object *fruit, Object *base, Grid *grid) {
    update_key(window);

    static int keys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7};

    static char levels[5][10] = {"Facil", "Medio", "Dificil", "Insano", "Intakavel"};

    int start = false;

    if (verify_key(window, SPACE)) {
        settings->grid = !(settings->grid);
    }
    if (verify_key(window, BACKSPACE)) {
        settings->collision = !(settings->collision);
    }

    if (verify_key(window, PERIOD)) {
        settings->level++;

        if (settings->level == 5) {
            settings->level = 0;
        }
    }

    if (verify_key(window, COMMA)) {
        settings->level--;

        if (settings->level == -1) {
            settings->level = 4;
        }
    }

    for (int key = 0; key < 7; key++) {
        if (verify_key(window, keys[key])) {
            settings->color = key;
        }
    }

    if (verify_key(window, ENTER)) {
        start = true;
    }

    window_color(BACK[settings->color]);

    set_object_color(base, settings, FORE[settings->color]);
    set_object_color(fruit, settings, BACK[settings->color]);

    set_grid_color(grid, settings);

    if (settings->collision) {
        sprintf(settings->title, "Snake - Dificuldade: %s - Borda: Ativada", levels[settings->level]);
    } else {
        sprintf(settings->title, "Snake - Dificuldade: %s - Borda: Desativada", levels[settings->level]);
    }

    window_title(window, settings);

    snake->velocity = 5 - settings->level;

    return start;
}

/**
 * @brief Spawn a fruit in a valid position
 *
 * @param settings Settings
 * @param snake Snake
 * @param fruit Fruit
 */
void spawn_fruit(Settings *settings, Snake *snake, Object *fruit) {
    int size = snake->size;

    int x_snake, y_snake;
    int x_fruit, y_fruit;

    while (true) {
        int index;

        x_fruit = random_number(0, settings->amount - 1);
        y_fruit = random_number(0, settings->amount - 1);

        for (index = 0; index < size; index++) {
            x_snake = snake->body[index].x;
            y_snake = snake->body[index].y;

            if (x_fruit == x_snake && y_fruit == y_snake) {
                break;
            }
        }

        if (index == size) {
            break;
        }
    }

    set_object_position(fruit, settings, x_fruit, y_fruit);
}

/**
 * @brief Initialize variables in program
 *
 * @param settings Settings
 * @param snake Snake
 * @param fruit Fruit
 * @param base Background base
 * @param grid Grid
 */
void initialize_game(Settings *settings, Snake *snake, Object *fruit, Object *base, Grid *grid) {
    int color = random_number(0, 6);
    int amount = settings->amount / 2;

    float side = 2.0 / settings->amount;

    window_color(BACK[color]);

    *snake = create_snake(settings, amount, amount);
    *fruit = create_object(settings, 0, 0, side, BACK[color]);
    *base = create_object(settings, 0, 0, 2.0, FORE[color]);
    *grid = create_grid(settings);

    spawn_fruit(settings, snake, fruit);
    clear_key();
}

/**
 * @brief Update variables and game state
 *
 * @param window Window
 * @param settings Settings
 * @param snake Snake
 * @param fruit Fruit
 * @param base Background base
 * @param grid Grid
 * @return Condition to restart game
 */
int update_game(Window *window, Settings *settings, Snake *snake, Object *fruit, Object *base) {
    update_direction(snake, window);

    update_key(window);

    return verify_key(window, ESCAPE);
}

/**
 * @brief Render game
 *
 * @param window Window
 * @param settings Settings
 * @param snake Snake
 * @param fruit Fruit
 * @param base Background base
 * @param grid Grid
 */
void render_game(Window *window, Settings *settings, Snake *snake, Object *fruit, Object *base, Grid *grid) {
    clear_window();

    draw_object(base);

    if (settings->grid) {
        draw_grid(grid);
    }

    draw_object(fruit);
    draw_snake(snake);

    update_window(window);

#if _WIN32
    wait(window, 10);
#endif
}

/**
 * @brief Finish game
 *
 * @param settings Settings
 * @param snake Snake
 * @param fruit Fruit
 * @param base Background base
 * @param grid Grid
 */
void finish_game(Settings *settings, Snake *snake, Object *fruit, Object *base, Grid *grid) {
    delete_object(base);
    delete_object(fruit);
    delete_snake(snake);
    delete_grid(grid);
}

/**
 * @brief Print score in window title
 *
 * @param window Window
 * @param settings Settings
 * @param snake Snake
 */
void print_score(Window *window, Settings *settings, Snake *snake) {
    sprintf(settings->title, "Snake - Pontos: %d", snake->size - 1);
    window_title(window, settings);
}

/**
 * @brief Run game
 */
void run_game(void) {
    Settings settings = create_settings(25, 0);

    Window window = create_window(&settings);

    Snake snake;
    Object fruit;
    Object base;
    Grid grid;

    opening_game(&window, &settings);

    while (window_available(&window)) {
        initialize_game(&settings, &snake, &fruit, &base, &grid);

        // Settings
        while (window_available(&window)) {
            if (update_settings(&settings, &window, &snake, &fruit, &base, &grid)) {
                break;
            }

            render_game(&window, &settings, &snake, &fruit, &base, &grid);
        }

        // Run Game
        while (window_available(&window)) {
            run_snake(&snake, &settings);

            if (update_game(&window, &settings, &snake, &fruit, &base)) {
                break;
            }

            render_game(&window, &settings, &snake, &fruit, &base, &grid);

            if (eat_fruit(&snake, &fruit)) {
                growth_snake(&snake, &settings);
                spawn_fruit(&settings, &snake, &fruit);
            }

            print_score(&window, &settings, &snake);

            if (verify_snake(&snake, &settings)) {
                break;
            }
        }

        wait(&window, settings.time);

        finish_game(&settings, &snake, &fruit, &base, &grid);
    }

    delete_window(&window);
}
