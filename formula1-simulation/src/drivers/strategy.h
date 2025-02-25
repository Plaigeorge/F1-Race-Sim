#ifndef STRATEGY_H
#define STRATEGY_H

// Tire types
typedef enum {
    SOFT,
    MEDIUM,
    HARD,
    INTERMEDIATE,
    WET
} TireType;

// Strategy structure
typedef struct {
    int num_pit_stops;
    int* pit_lap; // Array of laps to pit
    TireType* tire_choices; // Tire compound for each stint
    float fuel_load; // Initial fuel load in kg
} Strategy;

// Function prototypes
void initialize_strategy(Strategy* strategy, void* driver, void* track, void* weather);
void update_strategy(Strategy* strategy, void* race_conditions);
void cleanup_strategy(Strategy* strategy);

#endif // STRATEGY_H
