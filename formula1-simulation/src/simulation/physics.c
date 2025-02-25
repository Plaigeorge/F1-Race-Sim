#include "physics.h"
#include <math.h>

#define MAX_CARS 20

typedef struct {
    float speed;          // Current speed of the car
    float acceleration;   // Current acceleration of the car
    float handling;       // Handling characteristic of the car
    float tireGrip;       // Tire grip level
} Car;

Car cars[MAX_CARS];

void updateCarPhysics(int carIndex, float deltaTime) {
    if (carIndex < 0 || carIndex >= MAX_CARS) return;

    // Update speed based on acceleration and time
    cars[carIndex].speed += cars[carIndex].acceleration * deltaTime;

    // Ensure speed does not go negative
    if (cars[carIndex].speed < 0) {
        cars[carIndex].speed = 0;
    }

    // Simulate handling effects on speed
    cars[carIndex].speed *= cars[carIndex].tireGrip;

    // Limit maximum speed (for example, 350 km/h)
    if (cars[carIndex].speed > 350.0f) {
        cars[carIndex].speed = 350.0f;
    }
}

void setCarPerformance(int carIndex, float speed, float acceleration, float handling, float tireGrip) {
    if (carIndex < 0 || carIndex >= MAX_CARS) return;

    cars[carIndex].speed = speed;
    cars[carIndex].acceleration = acceleration;
    cars[carIndex].handling = handling;
    cars[carIndex].tireGrip = tireGrip;
}

float calculateLapTime(int carIndex, float trackLength) {
    if (carIndex < 0 || carIndex >= MAX_CARS) return -1.0f;

    // Simple lap time calculation based on speed and track length
    return trackLength / cars[carIndex].speed * 3600.0f; // Convert to seconds
}