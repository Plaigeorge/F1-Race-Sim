#ifndef PHYSICS_H
#define PHYSICS_H

typedef struct {
    float speed;          // Current speed of the car in km/h
    float acceleration;   // Acceleration of the car in m/s^2
    float handling;       // Handling characteristic of the car
    float tireGrip;       // Tire grip level
} CarPhysics;

void updateCarPhysics(CarPhysics *car, float throttle, float brake, float steering, float deltaTime);
float calculateLapTime(CarPhysics *car, float trackLength, float weatherFactor);
void applyWeatherEffects(CarPhysics *car, float weatherCondition);

#endif // PHYSICS_H