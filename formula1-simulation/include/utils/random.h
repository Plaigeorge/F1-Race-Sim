#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <time.h>

// Initializes the random number generator
void init_random();

// Generates a random integer between min and max (inclusive)
int random_int(int min, int max);

// Generates a random float between min and max
float random_float(float min, float max);

#endif // RANDOM_H