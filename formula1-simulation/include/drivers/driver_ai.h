#ifndef DRIVER_AI_H
#define DRIVER_AI_H

#include "car_performance.h"
#include "strategy.h"
#include "weather/conditions.h"

typedef struct {
    char name[50];
    int skill_level; // Skill level of the driver (1-10)
    int aggression;   // Aggressiveness of the driver (1-10)
    int consistency;  // Consistency of the driver (1-10)
} Driver;

typedef struct {
    Driver driver;
    CarPerformance performance;
    RaceStrategy strategy;
} DriverAI;

// Function to initialize the driver AI
void init_driver_ai(DriverAI *driver_ai, const char *name, int skill_level, int aggression, int consistency);

// Function for the driver AI to make a decision based on current conditions
void make_decision(DriverAI *driver_ai, WeatherConditions *weather, int lap_time, int position);

// Function to update the driver's strategy based on race conditions
void update_strategy(DriverAI *driver_ai, WeatherConditions *weather, int lap_count);

#endif // DRIVER_AI_H