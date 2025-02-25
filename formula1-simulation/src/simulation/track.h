#ifndef TRACK_H
#define TRACK_H

// Track structure
typedef struct {
    char name[64];
    float length; // in kilometers
    int num_corners;
    float* corner_severity; // Array of values from 1-10 indicating corner difficulty
    float* straight_lengths; // Array of straight lengths in meters
    int drs_zones;
    float grip_level; // Base grip level of the track
} Track;

// Function prototypes
void load_track_data(void);
Track* get_current_track(void);

#endif // TRACK_H
