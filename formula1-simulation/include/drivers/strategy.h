#ifndef STRATEGY_H
#define STRATEGY_H

typedef struct {
    int tireType; // 0: Soft, 1: Medium, 2: Hard
    int pitStopLap; // Lap number for pit stop
    float fuelLoad; // Fuel load in liters
} RaceStrategy;

void developRaceStrategy(RaceStrategy *strategy, int currentLap, float weatherCondition);
void optimizePitStopTiming(RaceStrategy *strategy, float tireWear, float trackCondition);
void adjustFuelLoad(RaceStrategy *strategy, float remainingLaps);

#endif // STRATEGY_H