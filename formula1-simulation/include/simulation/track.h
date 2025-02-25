#ifndef TRACK_H
#define TRACK_H

typedef struct {
    char name[50];
    float length; // in kilometers
    int numTurns;
    float elevationChange; // in meters
    char surfaceType[20]; // e.g., asphalt, gravel
} Track;

typedef struct {
    float temperature; // in degrees Celsius
    float humidity; // in percentage
    float windSpeed; // in km/h
    int precipitation; // 0: none, 1: light, 2: heavy
} WeatherConditions;

Track* createTrack(const char* name, float length, int numTurns, float elevationChange, const char* surfaceType);
void destroyTrack(Track* track);
WeatherConditions* createWeatherConditions(float temperature, float humidity, float windSpeed, int precipitation);
void destroyWeatherConditions(WeatherConditions* weather);

#endif // TRACK_H