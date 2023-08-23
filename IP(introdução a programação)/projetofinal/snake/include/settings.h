#include "libraries.h"

#ifndef SETTINGS_H
#define SETTINGS_H

#define false 0
#define true 1

typedef struct {
    int width;
    int height;
    int amount;
    int color;
    int grid;
    int collision;
    int level;
    int score;
    int time;

    char title[100];
} Settings;

void set_colors(float back, float fore);
Settings create_settings(int amount, int color);

extern const float COLORS[7][3];

extern float BACK[7][3];
extern float FORE[7][3];

#endif
