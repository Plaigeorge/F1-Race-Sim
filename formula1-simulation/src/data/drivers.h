#ifndef DRIVERS_H
#define DRIVERS_H

#define MAX_DRIVERS 20

typedef struct {
    char name[50];
    int team_index;
    int team_id;
    float skill_rating;
    float aggression;
    float consistency;
    float wet_weather_skill;
} Driver;

// Load driver data from configuration
void load_driver_data(void);

// Get driver by index
Driver* get_driver(int index);

// Get all drivers
Driver* get_all_drivers(void);

// Get number of drivers
int get_driver_count(void);

// Get drivers by team ID
Driver* get_team_drivers(int team_id, int* count);

#endif // DRIVERS_H
