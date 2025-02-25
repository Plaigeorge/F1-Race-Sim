#include "car_performance.h"

#define NUM_TEAMS 10
#define NUM_CARS_PER_TEAM 2

typedef struct {
    char name[50];
    float aerodynamics;
    float power_unit_performance;
    float mechanical_setup;
} CarPerformance;

CarPerformance car_performances[NUM_TEAMS][NUM_CARS_PER_TEAM] = {
    {{"Red Phoenix", 1.2, 1.5, 1.1}, {"Red Phoenix II", 1.3, 1.4, 1.2}},
    {{"Blue Thunder", 1.1, 1.6, 1.3}, {"Blue Thunder II", 1.2, 1.5, 1.4}},
    {{"Green Lightning", 1.3, 1.3, 1.2}, {"Green Lightning II", 1.4, 1.2, 1.3}},
    {{"Yellow Comet", 1.0, 1.7, 1.0}, {"Yellow Comet II", 1.1, 1.6, 1.1}},
    {{"Black Panther", 1.4, 1.4, 1.5}, {"Black Panther II", 1.5, 1.3, 1.4}},
    {{"White Falcon", 1.2, 1.5, 1.2}, {"White Falcon II", 1.3, 1.4, 1.3}},
    {{"Silver Arrow", 1.5, 1.2, 1.4}, {"Silver Arrow II", 1.6, 1.1, 1.5}},
    {{"Orange Blaze", 1.3, 1.4, 1.3}, {"Orange Blaze II", 1.4, 1.3, 1.4}},
    {{"Purple Star", 1.1, 1.6, 1.2}, {"Purple Star II", 1.2, 1.5, 1.3}},
    {{"Pink Rocket", 1.0, 1.8, 1.1}, {"Pink Rocket II", 1.1, 1.7, 1.2}}
};

void print_car_performance() {
    for (int i = 0; i < NUM_TEAMS; i++) {
        for (int j = 0; j < NUM_CARS_PER_TEAM; j++) {
            printf("Team: %s, Car: %s, Aerodynamics: %.2f, Power Unit Performance: %.2f, Mechanical Setup: %.2f\n",
                   car_performances[i][j].name, 
                   car_performances[i][j].name, 
                   car_performances[i][j].aerodynamics, 
                   car_performances[i][j].power_unit_performance, 
                   car_performances[i][j].mechanical_setup);
        }
    }
}