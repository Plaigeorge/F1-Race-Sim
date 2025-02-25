#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../logger/logger.h"
#include "tracks.h"

static Track tracks[MAX_TRACKS];
static int track_count = 0;
static int selected_track_index = -1;

void load_track_data() {
    // Silverstone
    strcpy(tracks[0].name, "Silverstone Circuit");
    tracks[0].length = 5.891f;
    tracks[0].num_corners = 18;
    strcpy(tracks[0].location, "United Kingdom");
    tracks[0].avg_lap_time = 90.0f;
    
    // Monaco
    strcpy(tracks[1].name, "Circuit de Monaco");
    tracks[1].length = 3.337f;
    tracks[1].num_corners = 19;
    strcpy(tracks[1].location, "Monaco");
    tracks[1].avg_lap_time = 75.0f;
    
    // Spa
    strcpy(tracks[2].name, "Circuit de Spa-Francorchamps");
    tracks[2].length = 7.004f;
    tracks[2].num_corners = 20;
    strcpy(tracks[2].location, "Belgium");
    tracks[2].avg_lap_time = 105.0f;
    
    // Monza
    strcpy(tracks[3].name, "Autodromo Nazionale Monza");
    tracks[3].length = 5.793f;
    tracks[3].num_corners = 11;
    strcpy(tracks[3].location, "Italy");
    tracks[3].avg_lap_time = 82.0f;
    
    track_count = 4; // Update based on actual tracks added
    
    // Default to first track
    selected_track_index = 0;
    
    log_info("Track data loaded successfully");
    printf("Loaded %d tracks\n", track_count);
}

Track* get_track(int index) {
    if (index < 0 || index >= track_count) {
        log_error("Attempted to access invalid track index");
        return NULL;
    }
    return &tracks[index];
}

int get_track_count() {
    return track_count;
}

void select_track(int index) {
    if (index < 0 || index >= track_count) {
        log_error("Attempted to select invalid track index");
        return;
    }
    selected_track_index = index;
    char log_message[100];
    snprintf(log_message, sizeof(log_message), "Selected track: %s", tracks[index].name);
    log_info(log_message);
}

Track* get_selected_track() {
    if (selected_track_index < 0 || selected_track_index >= track_count) {
        log_error("No valid track selected");
        return NULL;
    }
    return &tracks[selected_track_index];
}

Track* get_all_tracks() {
    return tracks;
}

Track* get_random_track() {
    if (track_count == 0) return NULL;
    
    int random_index = rand() % track_count;
    return &tracks[random_index];
}
