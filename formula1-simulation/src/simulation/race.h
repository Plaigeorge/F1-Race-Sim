#ifndef RACE_H
#define RACE_H

// Race structure to hold race state
typedef struct {
    int lap_count;
    int total_laps;
    int cars_count;
    void* cars; // Will be defined in implementation
    void* track; // Reference to track
    void* weather; // Current weather conditions
    int race_status; // 0 = not started, 1 = in progress, 2 = finished
} Race;

// Function prototypes
void initialize_race(Race* race);
void start_race(Race* race);
void cleanup_race(Race* race);

#endif // RACE_H
