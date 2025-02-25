#ifndef CONDITIONS_H
#define CONDITIONS_H

typedef enum {
    SUNNY,
    CLOUDY,
    RAINY,
    FOGGY,
    SNOWY
} WeatherType;

typedef struct {
    WeatherType type;
    float temperature; // in degrees Celsius
    float humidity;    // in percentage
    float windSpeed;   // in km/h
} WeatherConditions;

void initializeWeather(WeatherConditions *conditions);
void updateWeather(WeatherConditions *conditions);
void applyWeatherEffects(WeatherConditions *conditions, float *carPerformance);

#endif // CONDITIONS_H