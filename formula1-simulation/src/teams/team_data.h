#ifndef TEAM_DATA_H
#define TEAM_DATA_H

// Team structure
typedef struct {
    char name[64];
    int id;
    float budget;
    float development_rate;
    int num_drivers;
    void* drivers; // Array of driver pointers
    void* car; // Car performance data
} Team;

// Function prototypes
void load_team_data(void);
Team* get_team_by_id(int id);
Team* get_team_by_name(const char* name);

#endif // TEAM_DATA_H
