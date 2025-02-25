#ifndef RACE_H
#define RACE_H

/**
 * Initialize the race with default settings and participating drivers
 */
void initialize_race(void);

/**
 * Start the race simulation and process all laps until finish
 */
void start_race(void);

/**
 * Clean up resources used by the race simulation
 */
void cleanup_race(void);

#endif /* RACE_H */
