#ifndef MINES_INITIALIZER_H
#define MINES_INITIALIZER_H

#include <stdint.h>

#define EXPLOSION_PROBABILITY 4

/*
 * Inits the map with 1s and 0s.
 * 1 means the field contains an explosive.
 * 0 means the field is empty.
 */
void init_map(uint8_t **map, uint8_t x, uint8_t y);

#endif