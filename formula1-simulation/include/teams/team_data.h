#ifndef TEAM_DATA_H
#define TEAM_DATA_H

#include <stdint.h>

#define MAX_TEAMS 10
#define MAX_DRIVERS_PER_TEAM 2

typedef struct {
    char name[50];
    uint8_t speed;          // Speed performance rating (1-100)
    uint8_t handling;       // Handling performance rating (1-100)
    uint8_t reliability;    // Reliability performance rating (1-100)
} CarPerformance;

typedef struct {
    char name[50];
    CarPerformance car;
} Driver;

typedef struct {
    char teamName[50];
    Driver drivers[MAX_DRIVERS_PER_TEAM];
    uint8_t numDrivers;
} Team;

void loadTeamData(const char* filename);
Team* getTeamData(uint8_t teamIndex);
uint8_t getTotalTeams();

#endif // TEAM_DATA_H