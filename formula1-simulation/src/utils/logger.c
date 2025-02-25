#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

void log_event(const char *event) {
    FILE *log_file = fopen("race_log.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }
    
    time_t now;
    time(&now);
    fprintf(log_file, "[%s] %s\n", ctime(&now), event);
    
    fclose(log_file);
}

void log_performance(const char *driver_name, const char *team_name, float lap_time) {
    FILE *log_file = fopen("performance_log.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening performance log file!\n");
        return;
    }
    
    time_t now;
    time(&now);
    fprintf(log_file, "[%s] %s from %s completed a lap in %.2f seconds\n", ctime(&now), driver_name, team_name, lap_time);
    
    fclose(log_file);
}