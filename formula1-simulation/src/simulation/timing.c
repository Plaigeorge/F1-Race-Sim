#include <stdio.h>
#include <stdlib.h>
#include "timing.h"

typedef struct {
    int lap_time; // Time taken for the lap in seconds
    int total_time; // Total time for the race in seconds
} RaceTiming;

RaceTiming race_timing;

void start_timing() {
    race_timing.lap_time = 0;
    race_timing.total_time = 0;
}

void update_lap_time(int lap_time) {
    race_timing.lap_time = lap_time;
    race_timing.total_time += lap_time;
}

int get_lap_time() {
    return race_timing.lap_time;
}

int get_total_time() {
    return race_timing.total_time;
}

void display_timing() {
    printf("Current Lap Time: %d seconds\n", race_timing.lap_time);
    printf("Total Race Time: %d seconds\n", race_timing.total_time);
}