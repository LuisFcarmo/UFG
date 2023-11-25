#include "Worldbacterium.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct _bacterium {
    int key;
    int power;
    int life;
};
struct  _world {
    Bacterium x;
    int rows;
    int coluns;
    bool status;
};


world **New_world(unsigned int rows, unsigned int coluns) {
    world **World;
    World = (world**) (malloc(sizeof(world*)*rows));
    for (int i = 0; i < rows; i++) {
        World[i] = (world*) (malloc(sizeof(world)*coluns));
    }
    //restart World
    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < coluns; k++) {
            World[i][k].status = false;
            World[i][k].x.key = 0;
            World[i][k].x.life = 0;
            World[i][k].x.power = 0;
        }
    }
    World[0][0].coluns = coluns;
    World[0][0].rows = rows;
    return World;
};

void Show_world(world ***w) {
    world **World = *w;
    for (int i = 0; i < World[0][0].rows; i++) {
        for (int k = 0; k < World[0][0].coluns; k++) {
            printf("\n\n\n\n\n\nme mama nobru, me mama\n\n\n\n\n\n\n\n\n");
            printf("%d", World[i][k].status);
        }
        printf("\n");
    }
};