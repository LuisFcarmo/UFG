#include <stdio.h>

#include "../include/geometry.h"
#include "../include/libraries.h"
#include "../include/object.h"
#include "../include/settings.h"

const int INDICES[6] = {0, 1, 2, 2, 3, 0};

/**
 * @brief Create object with given values
 *
 * @param settings Settings
 * @param x Horizontal position
 * @param y Vertical position
 * @param side Block side size
 * @param color Object color array
 */
Object create_object(Settings *settings, int x, int y, float side, const float *color) {
    Object object;

    set_object(&object, settings, x, y, side, color);
    configure_object(&object);

    return object;
}

/**
 * @brief Get object attribute
 *
 * @param object Object
 * @param letter Object attribute
 * @return Object attribute
 */
int get_object(Object *object, char letter) {
    if (letter == 'x') {
        return object->x;
    }
    if (letter == 'y') {
        return object->y;
    }

    printf("Attribute absent in ´get_object(char)´!\n");

    return 0;
}

/**
 * @brief Set object position
 *
 * @param object Object
 * @param settings Settings
 * @param x Horizontal position
 * @param y Vertical position
 */
void set_object_position(Object *object, Settings *settings, int x, int y) {  //
    set_object(object, settings, x, y, object->side, object->color);
}

/**
 * @brief Set object color
 *
 * @param object Object
 * @param settings Settings
 * @param color Object color array
 */
void set_object_color(Object *object, Settings *settings,
                      const float *color) {  //
    set_object(object, settings, object->x, object->y, object->side, color);
}

/**
 * @brief Set object side
 *
 * @param object Object
 * @param settings Settings
 */
void set_object_side(Object *object, Settings *settings, float side) {  //
    set_object(object, settings, object->x, object->y, side, object->color);
}

/**
 * @brief Set object values
 *
 * @param object Object
 * @param settings Settings
 * @param x Horizontal position
 * @param y Vertical position
 * @param side Block side size
 * @param color Object color
 */
void set_object(Object *object, Settings *settings, int x, int y, float side, const float *color) {
    object->x = x;
    object->y = y;

    object->color[0] = color[0];
    object->color[1] = color[1];
    object->color[2] = color[2];

    float dx = +(2.0 * x / (float)settings->amount - 1.0);
    float dy = -(2.0 * y / (float)settings->amount - 1.0);

    set_block(&(object->square), dx, dy, side, color);

    for (int index = 0; index < 4; index++) {
        object->data[5 * index + 0] = object->square.vertices[index].x;
        object->data[5 * index + 1] = object->square.vertices[index].y;
        object->data[5 * index + 2] = object->square.vertices[index].r;
        object->data[5 * index + 3] = object->square.vertices[index].g;
        object->data[5 * index + 4] = object->square.vertices[index].b;
    }

    object->side = side;
}

/**
 * @brief Configure object to render
 *
 * @param object Object
 */
void configure_object(Object *object) {
    int vertex;
    int fragment;

    const char *vertex_source =
        "                                           \n\
		#version 420 core                           \n\
                                                    \n\
		in vec2 position;                           \n\
		in vec3 color;                              \n\
                                                    \n\
		out vec4 middleColor;                       \n\
                                                    \n\
		void main()                                 \n\
		{                                           \n\
			gl_Position = vec4(position, 0.0, 1.0); \n\
			middleColor = vec4(color, 1.0);         \n\
		}                                           \n\
	";

    const char *fragment_source =
        "                           \n\
		#version 420 core           \n\
                                    \n\
		in vec4 middleColor;        \n\
		out vec4 outColor;          \n\
                                    \n\
		void main()                 \n\
		{                           \n\
			outColor = middleColor; \n\
		}                           \n\
	";

    // Vertex Shader
    {
        int status;
        char log[512];

        vertex = glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(vertex, 1, &vertex_source, NULL);
        glCompileShader(vertex);

        glGetShaderiv(vertex, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderInfoLog(vertex, 512, NULL, log);

            printf("%s\n", log);
        }
    }

    // Fragment Shader
    {
        int status;
        char log[512];

        fragment = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(fragment, 1, &fragment_source, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderInfoLog(fragment, 512, NULL, log);

            printf("%s\n", log);
        }
    }

    // Link Shaders
    {
        int status;
        char log[512];

        object->program = glCreateProgram();

        glAttachShader(object->program, vertex);
        glAttachShader(object->program, fragment);

        glLinkProgram(object->program);
        glUseProgram(object->program);

        glGetProgramiv(object->program, GL_LINK_STATUS, &status);

        if (status == GL_FALSE) {
            glGetProgramInfoLog(object->program, 512, NULL, log);

            printf("%s\n", log);
        }
    }

    // Vertex Data and Attributes
    glGenVertexArrays(1, &object->array);
    glBindVertexArray(object->array);

    glGenBuffers(1, &object->buffer);

    glBindBuffer(GL_ARRAY_BUFFER, object->buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(object->data), object->data, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &object->element);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->element);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_DYNAMIC_DRAW);

    int position = glGetAttribLocation(object->program, "position");
    glEnableVertexAttribArray(position);
    glVertexAttribPointer(position, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(0 * sizeof(float)));

    int color = glGetAttribLocation(object->program, "color");
    glEnableVertexAttribArray(color);
    glVertexAttribPointer(color, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(2 * sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

/**
 * @brief Draw object in screen
 *
 * @param object Object
 */
void draw_object(Object *object) {
    glUseProgram(object->program);
    glBindVertexArray(object->array);
    glBindBuffer(GL_ARRAY_BUFFER, object->buffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(object->data), object->data);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

/**
 * @brief Delete shaders, buffers and programs in object
 *
 * @param object Object
 */
void delete_object(Object *object) {
    glDeleteBuffers(1, &object->buffer);
    glDeleteBuffers(1, &object->element);
    glDeleteProgram(object->program);
}
