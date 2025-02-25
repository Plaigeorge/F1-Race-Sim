#ifndef TEAMS_H
#define TEAMS_H

#define MAX_TEAMS 10

typedef struct {
    char name[50];
    int id;
    float car_performance;
    float engine_power;
    float aerodynamics;
} Team;

void load_team_data(void);
Team* get_team(int index);
Team* get_all_teams(void);
int get_team_count(void);

#endif // TEAMS_H
