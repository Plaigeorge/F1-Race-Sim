#ifndef RACE_H
#define RACE_H

#include "track.h"
#include "timing.h"
#include "car_performance.h"
#include "driver_ai.h"
#include "conditions.h"

#define MAX_CARS 20
#define MAX_TEAMS 10

typedef struct {
    char team_name[50];
    char driver_name[50];
    CarPerformance performance;
    int position;
    float lap_time;
} Car;

typedef struct {
    Car cars[MAX_CARS];
    int total_laps;
    Track track;
    WeatherConditions weather;
    Timing race_timing;
} Race;

void initialize_race(Race *race, const char *track_data, const char *weather_data);
void start_race(Race *race);
void update_lap_times(Race *race);
void determine_winner(Race *race);
void make_driver_decisions(Race *race);

#endif // RACE_H