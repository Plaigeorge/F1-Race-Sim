# F1-Race-Sim
# Formula 1 Race Simulation

## Overview
This project is a simulation of a Formula 1 race featuring 20 cars from 10 fictional teams. Each team has unique performance stats, and drivers can make optimal race choices based on car and weather information.

## Project Structure
The project is organized into several directories:

- **src/**: Contains the source code for the simulation.
  - **simulation/**: Manages race logic, track characteristics, physics calculations, and timing.
  - **teams/**: Handles team data and car performance metrics.
  - **drivers/**: Implements driver AI and race strategy development.
  - **weather/**: Manages weather conditions affecting the race.
  - **utils/**: Provides utility functions for random number generation and logging.

- **include/**: Contains header files for the various modules in the simulation.

- **data/**: Contains JSON files with data for teams, drivers, tracks, and weather patterns.

- **tests/**: Contains unit tests for various components of the simulation.

- **Makefile**: Contains build instructions for compiling the project.

## Features
- Simulates a full Formula 1 race with 20 cars from 10 teams.
- Each team has specific car performance stats that affect race outcomes.
- Drivers can make strategic decisions based on real-time car and weather data.
- Includes a logging system to track events and decisions during the race.

## Setup Instructions
1. Clone the repository:
   ```
   git clone <repository-url>
   cd formula1-simulation
   ```

2. Build the project using the Makefile:
   ```
   make
   ```

3. Run the simulation:
   ```
   ./bin/simulation
   ```

## Usage
- The simulation will load team, driver, track, and weather data from the JSON files in the `data/` directory.
- Users can observe the race dynamics, including lap times, pit strategies, and weather impacts on performance.
