#include <stdio.h>
#include <stdlib.h>
#include "race.h"
#include "track.h"
#include "timing.h"
#include "car_performance.h"
#include "driver_ai.h"
#include "conditions.h"

#define TOTAL_CARS 20
#define TOTAL_LAPS 50

typedef struct {
    int lap;
    int position;
    float lap_time;
} RaceData;

static RaceData race_data[TOTAL_CARS];

void initialize_race() {
    for (int i = 0; i < TOTAL_CARS; i++) {
        race_data[i].lap = 0;
        race_data[i].position = i + 1; // Initial position based on car number
        race_data[i].lap_time = 0.0f;
    }
}

void start_race() {
    printf("Race started!\n");
    for (int lap = 1; lap <= TOTAL_LAPS; lap++) {
        for (int i = 0; i < TOTAL_CARS; i++) {
            race_data[i].lap_time = simulate_lap(i); // Simulate lap time for each car
            race_data[i].lap++;
            printf("Car %d completed lap %d in %.2f seconds.\n", i + 1, race_data[i].lap, race_data[i].lap_time);
        }
        update_positions(); // Update positions based on lap times
    }
    determine_winner();
}

float simulate_lap(int car_index) {
    // Simulate lap time based on car performance and weather conditions
    float base_time = 90.0f; // Base lap time in seconds
    float performance_factor = get_car_performance(car_index);
    float weather_factor = get_weather_impact();
    return base_time * performance_factor * weather_factor;
}

void update_positions() {
    // Sort cars based on lap times to update positions
    // This is a simple bubble sort for demonstration purposes
    for (int i = 0; i < TOTAL_CARS - 1; i++) {
        for (int j = 0; j < TOTAL_CARS - i - 1; j++) {
            if (race_data[j].lap_time > race_data[j + 1].lap_time) {
                RaceData temp = race_data[j];
                race_data[j] = race_data[j + 1];
                race_data[j + 1] = temp;
            }
        }
    }
}

void determine_winner() {
    printf("Race finished!\n");
    printf("Winner: Car %d with a total time of %.2f seconds.\n", race_data[0].position, race_data[0].lap_time);
}