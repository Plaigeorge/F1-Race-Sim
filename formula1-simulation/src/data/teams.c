#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../logger/logger.h"
#include "teams.h"

static Team teams[MAX_TEAMS];
static int team_count = 0;

void load_team_data(void) {
    // Mercedes
    strcpy(teams[0].name, "Mercedes-AMG Petronas");
    teams[0].id = 0;
    teams[0].car_performance = 92.0f;
    teams[0].engine_power = 94.0f;
    teams[0].aerodynamics = 91.0f;
    
    // Red Bull
    strcpy(teams[1].name, "Red Bull Racing");
    teams[1].id = 1;
    teams[1].car_performance = 95.0f;
    teams[1].engine_power = 92.0f;
    teams[1].aerodynamics = 96.0f;
    
    // Ferrari
    strcpy(teams[2].name, "Scuderia Ferrari");
    teams[2].id = 2;
    teams[2].car_performance = 91.0f;
    teams[2].engine_power = 93.0f;
    teams[2].aerodynamics = 90.0f;
    
    // McLaren
    strcpy(teams[3].name, "McLaren F1 Team");
    teams[3].id = 3;
    teams[3].car_performance = 89.0f;
    teams[3].engine_power = 90.0f;
    teams[3].aerodynamics = 88.0f;
    
    // Aston Martin
    strcpy(teams[4].name, "Aston Martin F1 Team");
    teams[4].id = 4;
    teams[4].car_performance = 87.0f;
    teams[4].engine_power = 88.0f;
    teams[4].aerodynamics = 86.0f;
    
    team_count = 5; // Update based on actual teams added
    
    log_info("Team data loaded successfully");
    printf("Loaded %d teams\n", team_count);
}

Team* get_team(int index) {
    if (index < 0 || index >= team_count) {
        log_error("Attempted to access invalid team index");
        return NULL;
    }
    return &teams[index];
}

Team* get_all_teams(void) {
    return teams;
}

int get_team_count(void) {
    return team_count;
}
