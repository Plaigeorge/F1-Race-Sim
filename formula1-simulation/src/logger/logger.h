#ifndef LOGGER_H
#define LOGGER_H

// Initialize the logging system
void init_logger(void);

// Log information messages
void log_info(const char* message);

// Log warning messages
void log_warning(const char* message);

// Log error messages
void log_error(const char* message);

#endif // LOGGER_H
