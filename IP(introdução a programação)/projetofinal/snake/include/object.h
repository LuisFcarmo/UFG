#include "geometry.h"
#include "libraries.h"
#include "settings.h"

#ifndef OBJECT_H
#define OBJECT_H

extern const int INDICES[6];

/**
 * @struct Object
 *
 * @brief A Object in game, a renderable square
 */
typedef struct {
    Block square;

    float side;
    float color[3];

    float data[20];

    unsigned int array;
    unsigned int buffer;
    unsigned int element;

    int program;

    int x;
    int y;
} Object;

Object create_object(Settings *settings, int x, int y, float side, const float *color);
void delete_object(Object *object);

int get_object(Object *object, char letter);
void set_object(Object *object, Settings *settings, int x, int y, float side, const float *color);
void set_object_position(Object *object, Settings *settings, int x, int y);
void set_object_color(Object *object, Settings *settings, const float *color);
void set_object_side(Object *object, Settings *settings, float side);
void configure_object(Object *object);
void draw_object(Object *object);

#endif
