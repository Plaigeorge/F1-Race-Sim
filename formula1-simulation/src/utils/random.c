#include <stdlib.h>
#include <time.h>

void initialize_random() {
    srand(time(NULL));
}

int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double get_random_double(double min, double max) {
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}