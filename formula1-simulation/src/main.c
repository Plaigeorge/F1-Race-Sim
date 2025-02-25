#include <stdio.h>
#include <stdlib.h>
#include "logger/logger.h"
#include "data/teams.h"
#include "data/drivers.h"
#include "data/tracks.h"
#include "weather/patterns.h"
#include "race/race.h"

int main() {
    printf("Formula 1 Race Simulation\n");
    printf("-------------------------\n");

    // Initialize components
    init_logger();
    load_team_data();
    load_driver_data();
    load_track_data();
    load_weather_patterns();

    // Set up and run race
    printf("\nStarting race simulation...\n");
    initialize_race();
    start_race();
    
    // Clean up
    cleanup_race();
    
    return 0;
}