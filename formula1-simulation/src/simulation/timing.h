#ifndef TIMING_H
#define TIMING_H

// Timing structure
typedef struct {
    float current_lap_time;
    float best_lap_time;
    float* lap_times; // Array of lap times
    int lap_count;
    float race_time;
    int position;
} Timing;

// Function prototypes
void initialize_timing(Timing* timing);
void update_timing(Timing* timing, float lap_time);
void cleanup_timing(Timing* timing);

#endif // TIMING_H
