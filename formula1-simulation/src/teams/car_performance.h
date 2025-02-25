#ifndef CAR_PERFORMANCE_H
#define CAR_PERFORMANCE_H

// Car performance structure
typedef struct {
    float engine_power; // 1-10 scale
    float aero_efficiency; // 1-10 scale
    float chassis_performance; // 1-10 scale
    float tire_management; // 1-10 scale
    float reliability; // 1-10 scale, chance of technical issues
    float energy_recovery; // 1-10 scale, ERS efficiency
    float fuel_efficiency; // 1-10 scale
} CarPerformance;

// Function prototypes
void initialize_car_performance(CarPerformance* car, int team_id);
void update_car_development(CarPerformance* car, float development_points);

#endif // CAR_PERFORMANCE_H
