#include <string.h>

#include "../include/libraries.h"
#include "../include/settings.h"

/**
 * @brief Create settings to game
 *
 * @param amount Amount blocks in base side
 * @param color Color game
 * @return Settings
 */
Settings create_settings(int amount, int color) {
    Settings settings;

    settings.amount = amount;
    settings.color = color;

    settings.width = 720;
    settings.height = 720;

    settings.grid = false;
    settings.collision = true;
    settings.level = 1;

    settings.score = 0;
    settings.time = 1000;

    strcpy(settings.title, "Snake");

    return settings;
}

/**
 * @brief Set background and foreground color brightness
 *
 * @param back Background color brightness
 * @param fore Foreground color brightness
 */
void set_colors(float back, float fore) {
    for (int color = 0; color < 7; color++) {
        for (int index = 0; index < 3; index++) {
            BACK[color][index] = COLORS[color][index] * back;
            FORE[color][index] = COLORS[color][index] * fore;

            if (BACK[color][index] < 0) {
                BACK[color][index] = 0;
            }
            if (BACK[color][index] > 1) {
                BACK[color][index] = 1;
            }

            if (FORE[color][index] < 0) {
                FORE[color][index] = 0;
            }
            if (FORE[color][index] > 1) {
                FORE[color][index] = 1;
            }
        }
    }
}

// Colors
const float COLORS[7][3] = {
    {0.96, 0.24, 0.30},  // red
    {0.00, 0.81, 0.90},  // blue
    {0.92, 0.81, 0.16},  // yellow
    {0.18, 0.85, 0.56},  // green
    {0.49, 0.08, 0.67},  // purple
    {0.96, 0.50, 0.20},  // orange
    {1.00, 0.38, 0.48}   // pink
};

float BACK[7][3];
float FORE[7][3];
