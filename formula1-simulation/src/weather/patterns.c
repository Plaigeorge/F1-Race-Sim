#include "patterns.h"
#include "../data/tracks.h"
#include "../logger/logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int weather_seed;

void load_weather_patterns() {
    // Initialize the random seed for weather simulation
    weather_seed = (int)time(NULL);
    srand(weather_seed);
    
    log_info("Weather patterns initialized");
    printf("Weather system ready.\n");
}

WeatherCondition get_weather_for_lap(int lap) {
    Track* track = get_selected_track();
    if (!track) {
        // Default to sunny if no track is selected
        return WEATHER_SUNNY;
    }
    
    // Use a combination of the lap number, the track's weather variability,
    // and the random seed to determine the weather
    int random_factor = (lap + weather_seed) % 100;
    int threshold = track->weather_variability * 10;
    
    if (random_factor < 60) {
        // Most laps are sunny or cloudy
        return (random_factor < 30) ? WEATHER_SUNNY : WEATHER_CLOUDY;
    } else if (random_factor < 60 + threshold) {
        // Higher weather variability increases chances of light rain
        return WEATHER_LIGHT_RAIN;
    } else if (random_factor < 60 + threshold + (threshold / 2)) {
        // Even higher weather variability might lead to heavy rain
        return WEATHER_HEAVY_RAIN;
    }
    
    return WEATHER_SUNNY;
}

const char* get_weather_condition_name(WeatherCondition condition) {
    switch (condition) {
        case WEATHER_SUNNY:
            return "Sunny";
        case WEATHER_CLOUDY:
            return "Cloudy";
        case WEATHER_LIGHT_RAIN:
            return "Light Rain";
        case WEATHER_HEAVY_RAIN:
            return "Heavy Rain";
        default:
            return "Unknown";
    }
}
