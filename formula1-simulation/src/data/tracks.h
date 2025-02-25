#ifndef TRACKS_H
#define TRACKS_H

#define MAX_TRACKS 25

typedef struct {
    char name[50];
    float length;      // in kilometers
    int num_corners;
    char location[50];
    float avg_lap_time;  // expected lap time in seconds
} Track;

void load_track_data(void);
Track* get_track(int index);
Track* get_all_tracks(void);
int get_track_count(void);

#endif // TRACKS_H
