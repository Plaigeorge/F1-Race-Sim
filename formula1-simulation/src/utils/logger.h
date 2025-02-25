#ifndef LOGGER_H
#define LOGGER_H

// Log levels
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

// Function prototypes
void init_logger(void);
void log_message(LogLevel level, const char* format, ...);
void close_logger(void);

#endif // LOGGER_H
