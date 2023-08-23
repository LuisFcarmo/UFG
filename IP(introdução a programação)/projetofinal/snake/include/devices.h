#include "libraries.h"
#include "settings.h"

#ifndef DEVICES_H
#define DEVICES_H

#define NOTHING 0

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

#define ENTER 5
#define ESCAPE 6
#define SPACE 7
#define BACKSPACE 8

#define COMMA 9
#define PERIOD 10

#define KEY_1 11
#define KEY_2 12
#define KEY_3 13
#define KEY_4 14
#define KEY_5 15
#define KEY_6 16
#define KEY_7 17

typedef struct {
    GLFWwindow *data;
} Window;

typedef struct {
    int last;
    int current;
} KeyEvent;

Window create_window(Settings *);
void delete_window(Window *);
int window_available(Window *);
void window_title(Window *, Settings *);
void window_color(const float *);
void clear_window(void);
void update_window(Window *);
void reshape_window(Window *);
void centralize_window(Window *);
int verify_key(Window *, int);
void update_key(Window *);
void clear_key(void);

#endif
