#include <stdio.h>
#include <stdlib.h>

#include "../include/devices.h"
#include "../include/libraries.h"
#include "../include/settings.h"

KeyEvent key_event;

/**
 * @brief Create a Windows and initialize libraries
 *
 * @return Window
 */
Window create_window(Settings *settings) {
    if (!glfwInit()) {
        printf("Error: GLFW did not initialized!");

        exit(0);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    Window window = {glfwCreateWindow(settings->width, settings->height, settings->title, NULL, NULL)};

    if (window.data == NULL) {
        printf("Error: GLFW window did not created!");

        glfwTerminate();

        exit(0);
    }

    glfwMakeContextCurrent(window.data);

    GLenum status = glewInit();

#ifdef GLEW_ERROR_NO_GLX_DISPLAY
    GLboolean error = (status != GLEW_OK && status != GLEW_ERROR_NO_GLX_DISPLAY);
#else
    GLboolean error = (status != GLEW_OK);
#endif

    if (error) {
        printf("Error: %s\n", glewGetErrorString(status));

        glfwTerminate();

        exit(0);
    }

    centralize_window(&window);

    printf("Status: Using OpenGL %s\n", glGetString(GL_VERSION));
    printf("Status: Using GLEW   %s\n", glewGetString(GLEW_VERSION));
    printf("Status: Using GLFW   %s\n", glfwGetVersionString());

    return window;
}

/**
 * @brief Delete a window
 *
 * @param window Window
 */
void delete_window(Window *window) {
    glfwDestroyWindow(window->data);
    glfwTerminate();
}

/**
 * @brief Delete a window
 *
 * @param window Window
 */
int window_available(Window *window) {
    int value = glfwWindowShouldClose(window->data);

    return !value;
}

/**
 * @brief Set window title
 *
 * @param window Widow
 * @param title Title
 */
void window_title(Window *window, Settings *settings) {  //
    glfwSetWindowTitle(window->data, settings->title);
}

/**
 * @brief Change window background color
 *
 * @param color Color array (rgb)
 */
void window_color(const float *color) {  //
    glClearColor(color[0], color[1], color[2], 1.0);
}

/**
 * @brief Clear window content
 */
void clear_window(void) {  //
    glClear(GL_COLOR_BUFFER_BIT);
}

/**
 * @brief Update window content
 *
 * @param window Window reference
 */
void update_window(Window *window) {
    reshape_window(window);

    glfwSwapBuffers(window->data);
    glfwPollEvents();
}

/**
 * @brief Reshape view port in window
 *
 * @param window Game window
 */
void reshape_window(Window *window) {
    int width;
    int height;

    glfwGetFramebufferSize(window->data, &width, &height);

    float position = (width - height) / 2.0;

    if (height < width) {
        glViewport(position, 0, height, height);
    } else {
        glViewport(0, -position, width, width);
    }
}

/**
 * @brief Centralize window in screen
 *
 * @param window Game window
 */
void centralize_window(Window *window) {
    int width;
    int height;

    glfwGetFramebufferSize(window->data, &width, &height);

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);

    glfwSetWindowPos(window->data, (mode->width - width) / 2, (mode->height - height) / 2);
}

/**
 * @brief Clear key state
 */
void clear_key(void) {
    key_event.last = NOTHING;
    key_event.current = NOTHING;
}

/**
 * @brief Verify key
 *
 * @param window Game window
 * @param key Key to be verified
 * @return Verified state of key
 */
int verify_key(Window *window, int key) {
    int last = key_event.last;
    int current = key_event.current;

    return (current == key) && (last != key);
}

/**
 * @brief Verify key
 *
 * @param window Game window
 * @param key Key to be verified
 * @return Verified state of key
 */
void update_key(Window *window) {
    static int keymap[21][2] = {
        // LEFT
        {GLFW_KEY_LEFT, LEFT},
        {GLFW_KEY_A, LEFT},
        // RIGHT
        {GLFW_KEY_RIGHT, RIGHT},
        {GLFW_KEY_D, RIGHT},
        // UP
        {GLFW_KEY_UP, UP},
        {GLFW_KEY_W, UP},
        // DOWN
        {GLFW_KEY_DOWN, DOWN},
        {GLFW_KEY_S, DOWN},
        // ENTER
        {GLFW_KEY_ENTER, ENTER},
        // ESCAPE
        {GLFW_KEY_ESCAPE, ESCAPE},
        // SPACE
        {GLFW_KEY_SPACE, SPACE},
        // BACKSPACE
        {GLFW_KEY_BACKSPACE, BACKSPACE},
        // COMMA
        {GLFW_KEY_COMMA, COMMA},
        // PERIOD
        {GLFW_KEY_PERIOD, PERIOD},
        // NUMBER KEYS
        {GLFW_KEY_1, KEY_1},
        {GLFW_KEY_2, KEY_2},
        {GLFW_KEY_3, KEY_3},
        {GLFW_KEY_4, KEY_4},
        {GLFW_KEY_5, KEY_5},
        {GLFW_KEY_6, KEY_6},
        {GLFW_KEY_7, KEY_7},
    };

    key_event.last = key_event.current;

    key_event.current = NOTHING;

    for (int index = 0; index < 21; index++) {
        if (glfwGetKey(window->data, keymap[index][0]) == GLFW_PRESS) {
            key_event.current = keymap[index][1];
            break;
        }
    }
}