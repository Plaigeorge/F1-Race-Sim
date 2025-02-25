#include <stdio.h>
#include <stdlib.h>
#include "driver_ai.h"
#include "car_performance.h"
#include "conditions.h"

#define NUM_CARS 20

typedef struct {
    int car_id;
    float speed;
    float tire_condition;
    float fuel_level;
} Car;

typedef struct {
    Car cars[NUM_CARS];
} Race;

void make_decision(Race *race, int car_index, WeatherCondition weather) {
    Car *car = &race->cars[car_index];

    // Example decision-making based on car performance and weather
    if (weather.rain) {
        if (car->tire_condition < 0.5) {
            printf("Car %d: Switching to wet tires.\n", car->car_id);
        } else {
            printf("Car %d: Maintaining current tires.\n", car->car_id);
        }
    } else {
        if (car->fuel_level < 10.0) {
            printf("Car %d: Considering a pit stop for fuel.\n", car->car_id);
        } else {
            printf("Car %d: Continuing the race.\n", car->car_id);
        }
    }

    // Adjust speed based on tire condition
    if (car->tire_condition < 0.3) {
        car->speed *= 0.8; // Reduce speed if tires are worn
        printf("Car %d: Speed reduced due to tire condition.\n", car->car_id);
    }
}

void update_driver_ai(Race *race, WeatherCondition weather) {
    for (int i = 0; i < NUM_CARS; i++) {
        make_decision(race, i, weather);
    }
}