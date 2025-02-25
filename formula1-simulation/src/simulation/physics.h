#ifndef PHYSICS_H
#define PHYSICS_H

// Physics calculation functions
float calculate_lap_time(void* car, void* driver, void* track, void* weather);
float calculate_tire_wear(float driving_style, float track_abrasiveness, float temperature);
float calculate_fuel_consumption(float driving_style, float engine_efficiency);
float calculate_corner_speed(void* car, float corner_severity, float driver_skill);
float calculate_straight_speed(void* car, float straight_length, float driver_skill);

#endif // PHYSICS_H
