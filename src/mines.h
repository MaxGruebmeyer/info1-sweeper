#ifndef MINES_H
#define MINES_H

#include <stdint.h>

/* TODO (GM): Support non-quadratic fields as well! */
#define FIELD_SIZE 3
#define EXPLOSION_PROBABILITY 4

void init();
void flag(const uint8_t x, const uint8_t y);
void unflag(const uint8_t x, const uint8_t y);
uint8_t open(const uint8_t x, const uint8_t y);

#endif
