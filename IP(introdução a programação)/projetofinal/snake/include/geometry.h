#include "libraries.h"

#ifndef GEOMETRY_H
#define GEOMETRY_H

/**
 * @struct Vertex
 * @brief Emulate a vertex
 */
typedef struct {
    float x, y;
    float r, g, b;
} Vertex;

/**
 * @struct Block
 * @brief Emulate a block with vertices
 */
typedef struct {
    Vertex vertices[4];
    float side;
} Block;

Block create_block(float x, float y, float side, const float *color);

void set_block(Block *block, float x, float y, float side, const float *color);
void set_block_position(Block *block, float x, float y);
void set_block_color(Block *block, const float *color);
void set_block_side(Block *block, float side);

#endif
