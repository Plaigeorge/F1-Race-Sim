#include "patterns.h"
#include "weather.h"
#include "../logger/logger.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h> // For abs function

// Define log levels if not already defined
#ifndef LOG_INFO
#define LOG_INFO 1
#endif

// Track the current pattern
static WeatherPattern currentPattern = PATTERN_STABLE;
static bool patternsInitialized = false;

// Internal pattern variables
static int nextChangePoint = -1;
static WeatherCondition targetCondition = WEATHER_SUNNY;

// Initialize available weather patterns
void load_weather_patterns(void) {
    if (patternsInitialized) {
        return;
    }
    
    // Initialize weather system first
    init_weather();
    
    // Set a random pattern by default
    srand((unsigned int)time(NULL));
    set_weather_pattern((WeatherPattern)(rand() % 4));
    
    patternsInitialized = true;
    log_message(LOG_INFO, "Weather patterns loaded successfully");
}

// Set a specific weather pattern
void set_weather_pattern(WeatherPattern pattern) {
    currentPattern = pattern;
    
    // Reset pattern-specific variables
    nextChangePoint = -1;
    targetCondition = WEATHER_SUNNY;
    
    // Log the selected pattern
    const char* patternNames[] = {
        "Stable", "Gradual Change", "Sudden Change", "Variable"
    };
    
    log_message(LOG_INFO, "Weather pattern set to: %s", patternNames[pattern]);
}

// Get the current active pattern
WeatherPattern get_current_pattern(void) {
    return currentPattern;
}

// Simulate weather based on the current pattern for a specific lap
void simulate_pattern_for_lap(int currentLap, int totalLaps) {
    // Make sure patterns are initialized
    if (!patternsInitialized) {
        load_weather_patterns();
    }
    
    // Handle different patterns
    switch (currentPattern) {
        case PATTERN_STABLE:
            // In stable pattern, weather rarely changes (2% chance)
            if (rand() % 100 < 2) {
                update_weather(currentLap, totalLaps);
            }
            break;
            
        case PATTERN_GRADUAL_CHANGE:
            // In gradual pattern, determine change points if not set
            if (nextChangePoint == -1) {
                // Set a change point around mid-race
                nextChangePoint = totalLaps / 2 + (rand() % (totalLaps / 4)) - (totalLaps / 8);
                targetCondition = (WeatherCondition)(rand() % 5);
                
                log_message(LOG_INFO, "Weather will gradually change around lap %d", nextChangePoint);
            }
            
            // Apply gradual changes as we approach the change point
            if (abs(currentLap - nextChangePoint) < 5) {
                update_weather(currentLap, totalLaps);
            }
            else if (rand() % 100 < 5) {
                // Small chance of change otherwise
                update_weather(currentLap, totalLaps);
            }
            break;
            
        case PATTERN_SUDDEN_CHANGE:
            // In sudden pattern, determine change point if not set
            if (nextChangePoint == -1) {
                // Random change point in the race
                nextChangePoint = (rand() % (totalLaps - 5)) + 3;
                targetCondition = (WeatherCondition)(rand() % 5);
                
                log_message(LOG_INFO, "Weather may suddenly change around lap %d", nextChangePoint);
            }
            
            // When we reach the change point, force a weather update
            if (currentLap == nextChangePoint) {
                log_message(LOG_INFO, "Sudden weather change occurring now!");
                
                // Get current weather, modify it, and then apply it
                WeatherData weather = get_current_weather();
                weather.condition = targetCondition;
                
                // Instead of directly modifying the weather.condition, just call update_weather
                // which will have a chance to change the weather naturally
                update_weather(currentLap, totalLaps);
            } 
            else if (rand() % 100 < 3) {
                // Small chance of change otherwise
                update_weather(currentLap, totalLaps);
            }
            break;
            
        case PATTERN_VARIABLE:
            // Variable pattern has higher chance of weather changes
            if (rand() % 100 < 15) {
                update_weather(currentLap, totalLaps);
            }
            break;
    }
}
