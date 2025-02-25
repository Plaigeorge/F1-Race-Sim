#ifndef CAR_PERFORMANCE_H
#define CAR_PERFORMANCE_H

typedef struct {
    char name[50];
    float aerodynamics; // Aerodynamic efficiency (0.0 to 1.0)
    float power_unit;   // Power unit performance (in horsepower)
    float mechanical_setup; // Mechanical setup performance (0.0 to 1.0)
    float tire_grip;    // Tire grip performance (0.0 to 1.0)
} CarPerformance;

void initialize_car_performance(CarPerformance *car, const char *name, float aerodynamics, float power_unit, float mechanical_setup, float tire_grip);
void display_car_performance(const CarPerformance *car);
float calculate_overall_performance(const CarPerformance *car);

#endif // CAR_PERFORMANCE_H