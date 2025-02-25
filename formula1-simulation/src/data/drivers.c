#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../logger/logger.h"
#include "drivers.h"

static Driver drivers[MAX_DRIVERS];
static int driver_count = 0;

void load_driver_data() {
    // Hardcoded example data - would normally load from file
    
    // Mercedes drivers
    strcpy(drivers[0].name, "Lewis Hamilton");
    drivers[0].team_index = 0;
    drivers[0].skill_rating = 97;
    drivers[0].aggression = 85;
    drivers[0].consistency = 94;
    drivers[0].wet_weather_skill = 96;
    
    strcpy(drivers[1].name, "George Russell");
    drivers[1].team_index = 0;
    drivers[1].skill_rating = 92;
    drivers[1].aggression = 83;
    drivers[1].consistency = 88;
    drivers[1].wet_weather_skill = 86;
    
    // Red Bull drivers
    strcpy(drivers[2].name, "Max Verstappen");
    drivers[2].team_index = 1;
    drivers[2].skill_rating = 97;
    drivers[2].aggression = 95;
    drivers[2].consistency = 90;
    drivers[2].wet_weather_skill = 95;
    
    strcpy(drivers[3].name, "Sergio Perez");
    drivers[3].team_index = 1;
    drivers[3].skill_rating = 89;
    drivers[3].aggression = 80;
    drivers[3].consistency = 83;
    drivers[3].wet_weather_skill = 85;
    
    // Ferrari drivers
    strcpy(drivers[4].name, "Charles Leclerc");
    drivers[4].team_index = 2;
    drivers[4].skill_rating = 94;
    drivers[4].aggression = 85;
    drivers[4].consistency = 87;
    drivers[4].wet_weather_skill = 88;
    
    strcpy(drivers[5].name, "Carlos Sainz");
    drivers[5].team_index = 2;
    drivers[5].skill_rating = 91;
    drivers[5].aggression = 82;
    drivers[5].consistency = 88;
    drivers[5].wet_weather_skill = 84;
    
    // Add more drivers for other teams
    // ...
    
    driver_count = 6;  // Update this based on how many drivers you actually added
    
    log_info("Driver data loaded successfully");
    printf("Loaded %d drivers.\n", driver_count);
}

Driver* get_driver(int index) {
    if (index < 0 || index >= driver_count) {
        log_error("Attempted to access invalid driver index");
        return NULL;
    }
    return &drivers[index];
}

Driver* get_all_drivers() {
    return drivers;
}

int get_driver_count() {
    return driver_count;
}

Driver* get_team_drivers(int team_id, int* count) {
    static Driver team_drivers[2]; // Assume max 2 drivers per team
    *count = 0;
    
    for (int i = 0; i < driver_count; i++) {
        if (drivers[i].team_id == team_id) {
            team_drivers[*count] = drivers[i];
            (*count)++;
            if (*count >= 2) break; // Only consider up to 2 drivers per team
        }
    }
    
    return team_drivers;
}
