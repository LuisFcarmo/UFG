#include "../include/geometry.h"
#include "../include/libraries.h"

/**
 * @brief Create a block
 *
 * @param x Horizontal position
 * @param y Vertical position
 * @param side Size of block side
 * @param color Block color array (rgb)
 * @return Block
 */
Block create_block(float x, float y, float side, const float *color) {
    Block block;

    set_block(&block, x, y, side, color);

    return block;
}

/**
 * @brief Set attributes of a block
 *
 * @param block Block to be setted
 * @param x Horizontal position
 * @param y Vertical position
 * @param side Size of block side
 * @param color Block color array (rgb)
 * @return Block
 */
void set_block(Block *block, float x, float y, float side, const float *color) {
    set_block_side(block, side);
    set_block_position(block, x, y);
    set_block_color(block, color);
}

/**
 * @brief Set block position
 *
 * @param block Block to be setted
 * @param x Horizontal position
 * @param y Vertical position
 */
void set_block_position(Block *block, float x, float y) {
    float side = block->side;

    float positions[4][2] = {
        {x, y},                //
        {x + side, y},         //
        {x + side, y - side},  //
        {x, y - side}          //
    };

    for (int index = 0; index < 4; index++) {
        block->vertices[index].x = positions[index][0];
        block->vertices[index].y = positions[index][1];
    }
}

/**
 * @brief Set block color
 *
 * @param block Block to be setted
 * @param color Block color array
 */
void set_block_color(Block *block, const float *color) {
    for (int index = 0; index < 4; index++) {
        block->vertices[index].r = color[0];
        block->vertices[index].g = color[1];
        block->vertices[index].b = color[2];
    }
}

/**
 * @brief Set block side
 *
 * @param block Block to be setted
 * @param side Size of block side
 */
void set_block_side(Block *block, float side) {  //
    block->side = side;
}
