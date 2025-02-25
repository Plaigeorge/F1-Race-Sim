#ifndef DRIVER_AI_H
#define DRIVER_AI_H

// Driver AI structure
typedef struct {
    int id;
    char name[64];
    float skill; // 1-10 scale
    float aggression; // 1-10 scale
    float consistency; // 1-10 scale
    float adaptability; // 1-10 scale, how well they adapt to changing conditions
    float wet_skill; // 1-10 scale, performance in wet conditions
    float tire_management; // 1-10 scale
    float team_id;
} Driver;

// Function prototypes
void load_driver_data(void);
Driver* get_driver_by_id(int id);
Driver* get_driver_by_name(const char* name);
float get_driver_performance(Driver* driver, void* car, void* track, void* weather);

#endif // DRIVER_AI_H
