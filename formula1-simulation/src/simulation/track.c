#include <stdio.h>
#include "track.h"

typedef struct {
    char name[50];
    float length; // in kilometers
    int numCorners;
    char surface[20]; // e.g., asphalt, gravel
} Track;

Track tracks[10]; // Array to hold track data

void initializeTracks() {
    // Example track initialization
    snprintf(tracks[0].name, sizeof(tracks[0].name), "Silverstone Circuit");
    tracks[0].length = 5.891; // Length in km
    tracks[0].numCorners = 18;
    snprintf(tracks[0].surface, sizeof(tracks[0].surface), "asphalt");

    snprintf(tracks[1].name, sizeof(tracks[1].name), "Monaco Grand Prix");
    tracks[1].length = 3.337; // Length in km
    tracks[1].numCorners = 19;
    snprintf(tracks[1].surface, sizeof(tracks[1].surface), "asphalt");

    // Additional tracks can be initialized similarly
}

void printTrackInfo(int trackIndex) {
    if (trackIndex < 0 || trackIndex >= 10) {
        printf("Invalid track index.\n");
        return;
    }
    printf("Track Name: %s\n", tracks[trackIndex].name);
    printf("Length: %.3f km\n", tracks[trackIndex].length);
    printf("Number of Corners: %d\n", tracks[trackIndex].numCorners);
    printf("Surface Type: %s\n", tracks[trackIndex].surface);
}