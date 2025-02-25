#ifndef PATTERNS_H
#define PATTERNS_H

typedef enum {
    WEATHER_SUNNY,
    WEATHER_CLOUDY,
    WEATHER_LIGHT_RAIN,
    WEATHER_HEAVY_RAIN
} WeatherCondition;

// Load weather patterns data from configuration
void load_weather_patterns(void);

// Get a weather pattern by index
int get_weather_pattern(int index);

// Get random weather event based on current pattern
void generate_weather_event(void);

// Determine weather condition for a specific lap
// based on the current track's weather variability
WeatherCondition get_weather_for_lap(int lap);

// Get a string representation of a weather condition
const char* get_weather_condition_name(WeatherCondition condition);

#endif // PATTERNS_H
