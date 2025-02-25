#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conditions.h"
#include "../logger/logger.h"

typedef struct {
    float temperature; // in degrees Celsius
    float humidity;    // in percentage
    float precipitation; // in mm/h
    int rain; // in mm/h
    int wind_speed; // in km/h
    int wind_direction; // in degrees
} WeatherCondition;

static WeatherCondition current_weather;
static int is_initialized = 0;

void initialize_weather(void) {
    if (!is_initialized) {
        srand((unsigned int)time(NULL));
        // Default to dry conditions
        current_weather.rain = 0;
        current_weather.temperature = 25.0f;
        current_weather.humidity = 50.0f;
        current_weather.wind_speed = 5;
        current_weather.wind_direction = 180;
        
        is_initialized = 1;
    }
    
    log_info("Weather system initialized");
}

float get_weather_impact(void) {
    float impact = 1.0f;
    
    // Rain makes the track slower
    if (current_weather.rain > 0) {
        impact += (current_weather.rain * 0.02f); // Up to 20% slower in heavy rain
    }
    
    // Extreme temperatures affect performance
    if (current_weather.temperature < 15.0f || current_weather.temperature > 35.0f) {
        impact += 0.05f; // 5% slower in extreme temperatures
    }
    
    // Strong winds affect aerodynamics
    if (current_weather.wind_speed > 20) {
        impact += 0.03f; // 3% slower in strong winds
    }
    
    return impact;
}

void update_weather_conditions(void) {
    // 10% chance of weather changing each update
    if (rand() % 10 == 0) {
        int change_type = rand() % 4;
        
        switch (change_type) {
            case 0: // Change rain
                current_weather.rain = rand() % 11; // 0-10
                if (current_weather.rain > 0) {
                    log_info("Weather update: Rain has started");
                    printf("Weather change: It's starting to rain\n");
                } else {
                    log_info("Weather update: Track is now dry");
                    printf("Weather change: Track is drying\n");
                }
                break;
                
            case 1: // Change temperature
                current_weather.temperature = 15.0f + (rand() % 26); // 15-40°C
                log_info("Weather update: Temperature changed");
                printf("Weather change: Temperature is now %.1f°C\n", current_weather.temperature);
                break;
                
            case 2: // Change humidity
                current_weather.humidity = 30.0f + (rand() % 61); // 30-90%
                break;
                
            case 3: // Change wind
                current_weather.wind_speed = rand() % 41; // 0-40 km/h
                current_weather.wind_direction = rand() % 360; // 0-359 degrees
                if (current_weather.wind_speed > 20) {
                    log_info("Weather update: Strong winds");
                    printf("Weather change: Wind increasing to %d km/h\n", current_weather.wind_speed);
                }
                break;
        }
    }
}

void print_weather() {
    printf("Current Weather:\n");
    printf("Temperature: %.1f°C\n", current_weather.temperature);
    printf("Humidity: %.1f%%\n", current_weather.humidity);
    printf("Precipitation: %.1f mm/h\n", current_weather.precipitation);
}