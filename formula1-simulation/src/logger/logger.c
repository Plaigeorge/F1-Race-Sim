#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "logger.h"

#define LOG_FILE "race_simulation.log"

static FILE* log_file = NULL;

void init_logger() {
    log_file = fopen(LOG_FILE, "w");
    if (log_file == NULL) {
        printf("Warning: Could not open log file. Logging disabled.\n");
        return;
    }
    
    time_t current_time = time(NULL);
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    
    fprintf(log_file, "[%s] Formula 1 Simulation started\n", time_str);
    fflush(log_file);
    
    printf("Logging initialized.\n");
}

void log_info(const char* message) {
    if (log_file == NULL) return;
    
    time_t current_time = time(NULL);
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    
    fprintf(log_file, "[%s] INFO: %s\n", time_str, message);
    fflush(log_file);
}

void log_warning(const char* message) {
    if (log_file == NULL) return;
    
    time_t current_time = time(NULL);
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    
    fprintf(log_file, "[%s] WARNING: %s\n", time_str, message);
    fflush(log_file);
}

void log_error(const char* message) {
    if (log_file == NULL) return;
    
    time_t current_time = time(NULL);
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    
    fprintf(log_file, "[%s] ERROR: %s\n", time_str, message);
    fflush(log_file);
}
