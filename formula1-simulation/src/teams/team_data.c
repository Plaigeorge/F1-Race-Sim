#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team_data.h"

#define MAX_TEAMS 10
#define MAX_CARS_PER_TEAM 2
#define TEAM_NAME_LENGTH 50

typedef struct {
    char name[TEAM_NAME_LENGTH];
    int speed; // Performance metric
    int reliability; // Performance metric
    int aerodynamics; // Performance metric
} Team;

static Team teams[MAX_TEAMS];
static int team_count = 0;

void load_team_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open team data file");
        return;
    }

    while (fscanf(file, "%49s %d %d %d", teams[team_count].name, 
                  &teams[team_count].speed, 
                  &teams[team_count].reliability, 
                  &teams[team_count].aerodynamics) == 4) {
        team_count++;
        if (team_count >= MAX_TEAMS) {
            break;
        }
    }

    fclose(file);
}

void print_team_data() {
    for (int i = 0; i < team_count; i++) {
        printf("Team: %s, Speed: %d, Reliability: %d, Aerodynamics: %d\n",
               teams[i].name, teams[i].speed, teams[i].reliability, teams[i].aerodynamics);
    }
}

int get_team_count() {
    return team_count;
}

const Team* get_team(int index) {
    if (index < 0 || index >= team_count) {
        return NULL;
    }
    return &teams[index];
}