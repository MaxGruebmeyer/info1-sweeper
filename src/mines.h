#ifndef MINES_H
#define MINES_H

#include <stdint.h>

/*
 * Inits the passed map of the specified size.
 * Also saves x, y and especially the map locally.
 * Once you free the map calling any method of this file
 * will result in undefined behaviour!
 *
 * Needs to be called before calling any other method.
 * Not calling it beforehand results in undefined behaviour!
 *
 * Note that if the map is not exactly the size of x*y
 * calling this method leads to undefined behaviour!
 */
void init(uint8_t **map, const uint8_t x, const uint8_t y);

/*
 * Flags the field at the specified position.
 * Returns 1 (true) if the field could be flagged.
 * Returns 0 (false) if the field could not be flagged (e.g. the position is outside the map)
 */
uint8_t flag(const uint8_t x, const uint8_t y);

/*
 * Unflags the field at the specified position.
 * Returns 1 (true) if the field could be unflagged.
 * Returns 0 (false) if the field could not be unflagged (e.g. the position is outside the map)
 */
uint8_t unflag(const uint8_t x, const uint8_t y);

/*
 * Opens the field at the specified position
 * and writes 1 into result if the field was explosive or 0 if not.
 * Sets result to NULL if the field was outside the bounds of the map
 * or the field was flagged (and could therefore not be opened).
 */
void open(uint8_t *result, const uint8_t x, const uint8_t y);

#endif
