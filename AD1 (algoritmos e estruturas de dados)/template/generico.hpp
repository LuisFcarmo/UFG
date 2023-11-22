#include <iostream>
template<typename t>
struct FIFO_node {
    t data;
    struct FIFO_node <t> *next;
};

template <typename t>
struct  fifo {
    FIFO_node <t> *next;
    int size;
};



