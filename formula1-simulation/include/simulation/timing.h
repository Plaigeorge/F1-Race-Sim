#ifndef TIMING_H
#define TIMING_H

typedef struct {
    float lap_time;       // Time taken for the lap in seconds
    float total_time;     // Total time elapsed in the race
    int lap_number;       // Current lap number
} LapTiming;

typedef struct {
    LapTiming lap_timings[100]; // Array to store lap timings for up to 100 laps
    int current_lap;            // Index of the current lap
} RaceTiming;

// Function to initialize race timing
void init_race_timing(RaceTiming *race_timing);

// Function to record a lap time
void record_lap_time(RaceTiming *race_timing, float lap_time);

// Function to get the total race time
float get_total_race_time(const RaceTiming *race_timing);

// Function to get the best lap time
float get_best_lap_time(const RaceTiming *race_timing);

#endif // TIMING_H