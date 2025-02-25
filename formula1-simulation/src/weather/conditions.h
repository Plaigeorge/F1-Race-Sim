#ifndef CONDITIONS_H
#define CONDITIONS_H

typedef struct {
    int rain;           // 0: dry, 1-10: intensity of rain
    float temperature;  // Track temperature in Celsius
    float humidity;     // Humidity percentage
    int wind_speed;     // Wind speed in km/h
    int wind_direction; // 0-359 degrees
} WeatherCondition;

// Get current weather impact on lap times
float get_weather_impact(void);

// Update weather conditions during race
void update_weather_conditions(void);

// Initialize weather system
void initialize_weather(void);

#endif // CONDITIONS_H
