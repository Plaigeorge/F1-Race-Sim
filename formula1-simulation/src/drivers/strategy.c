#include <stdio.h>
#include <stdlib.h>
#include "strategy.h"
#include "../teams/car_performance.h"
#include "../weather/conditions.h"

#define MAX_LAPS 100
#define PIT_STOP_TIME 20 // seconds

typedef struct {
    int lap_count;
    int tire_wear;
    int fuel_level;
    int position;
} DriverStatus;

void evaluatePitStop(DriverStatus *driver, CarPerformance *car, WeatherConditions *weather) {
    if (driver->tire_wear > 70 || driver->fuel_level < 15) {
        printf("Driver at position %d should consider a pit stop.\n", driver->position);
    }
}

void chooseTires(DriverStatus *driver, WeatherConditions *weather) {
    if (weather->precipitation > 0) {
        printf("Driver at position %d should switch to wet tires.\n", driver->position);
    } else {
        printf("Driver at position %d should use slick tires.\n", driver->position);
    }
}

void developRaceStrategy(DriverStatus *driver, CarPerformance *car, WeatherConditions *weather) {
    evaluatePitStop(driver, car, weather);
    chooseTires(driver, weather);
}

void simulateLap(DriverStatus *driver, CarPerformance *car, WeatherConditions *weather) {
    driver->lap_count++;
    driver->tire_wear += rand() % 5; // Simulate tire wear
    driver->fuel_level -= rand() % 3; // Simulate fuel consumption

    developRaceStrategy(driver, car, weather);
}

void runRace(DriverStatus drivers[], CarPerformance cars[], WeatherConditions *weather, int num_drivers) {
    for (int lap = 0; lap < MAX_LAPS; lap++) {
        for (int i = 0; i < num_drivers; i++) {
            simulateLap(&drivers[i], &cars[i], weather);
        }
    }
}