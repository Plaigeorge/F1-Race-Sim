#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

void log_message(LogLevel level, const char *message);
void log_race_event(const char *event);
void log_driver_decision(const char *driver_name, const char *decision);
void log_weather_update(const char *update);

#endif // LOGGER_H