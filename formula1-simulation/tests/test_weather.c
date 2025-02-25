#include <stdio.h>
#include <assert.h>
#include "weather/conditions.h"

void test_weather_conditions() {
    WeatherConditions conditions;

    // Test default weather conditions
    init_weather_conditions(&conditions);
    assert(conditions.temperature == 20); // Default temperature
    assert(conditions.humidity == 50); // Default humidity
    assert(conditions.precipitation == 0); // Default precipitation

    // Test setting weather conditions
    set_weather_conditions(&conditions, 30, 70, 10);
    assert(conditions.temperature == 30);
    assert(conditions.humidity == 70);
    assert(conditions.precipitation == 10);

    // Test weather impact on performance
    float performance = calculate_performance_impact(&conditions);
    assert(performance < 1.0); // Assuming performance decreases with bad weather

    printf("All weather condition tests passed!\n");
}

int main() {
    test_weather_conditions();
    return 0;
}