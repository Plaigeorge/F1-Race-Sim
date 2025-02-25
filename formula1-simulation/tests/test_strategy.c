#include <stdio.h>
#include <assert.h>
#include "drivers/strategy.h"
#include "weather/conditions.h"

void test_optimal_pit_stop_timing() {
    RaceStrategy strategy;
    WeatherConditions weather;

    // Test case: Clear weather, optimal tire choice
    weather.temperature = 25; // degrees Celsius
    weather.precipitation = 0; // no rain
    strategy.current_tires = SOFT;
    strategy.lap_time = 90; // seconds

    // Simulate pit stop decision
    int pit_stop_lap = decide_pit_stop(&strategy, &weather);
    assert(pit_stop_lap == 15); // Expected optimal lap for pit stop

    // Test case: Rainy weather, switch to intermediate tires
    weather.precipitation = 1; // rain
    strategy.current_tires = HARD;

    // Simulate pit stop decision
    pit_stop_lap = decide_pit_stop(&strategy, &weather);
    assert(pit_stop_lap == 10); // Expected optimal lap for pit stop

    // Test case: Extreme weather, switch to wet tires
    weather.precipitation = 2; // heavy rain
    strategy.current_tires = INTERMEDIATE;

    // Simulate pit stop decision
    pit_stop_lap = decide_pit_stop(&strategy, &weather);
    assert(pit_stop_lap == 5); // Expected optimal lap for pit stop
}

void test_tire_management() {
    RaceStrategy strategy;

    // Test case: Tire wear management
    strategy.current_tires = SOFT;
    strategy.tire_wear = 80; // percent worn

    // Simulate tire management decision
    int tire_change = manage_tires(&strategy);
    assert(tire_change == 1); // Expected to change tires

    // Test case: Fresh tires
    strategy.tire_wear = 20; // percent worn
    tire_change = manage_tires(&strategy);
    assert(tire_change == 0); // Expected to keep current tires
}

int main() {
    test_optimal_pit_stop_timing();
    test_tire_management();
    printf("All tests passed!\n");
    return 0;
}