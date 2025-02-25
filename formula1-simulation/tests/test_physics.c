#include <stdio.h>
#include <assert.h>
#include "simulation/physics.h"

void test_car_acceleration() {
    Car car;
    car.power = 1000; // in horsepower
    car.weight = 1500; // in kg
    double expected_acceleration = car.power / car.weight; // Simplified physics formula
    double actual_acceleration = calculate_acceleration(&car);
    assert(actual_acceleration == expected_acceleration);
    printf("test_car_acceleration passed.\n");
}

void test_car_handling() {
    Car car;
    car.downforce = 200; // in Newtons
    car.weight = 1500; // in kg
    double expected_handling = car.downforce / car.weight; // Simplified handling formula
    double actual_handling = calculate_handling(&car);
    assert(actual_handling == expected_handling);
    printf("test_car_handling passed.\n");
}

void test_tire_grip() {
    Tire tire;
    tire.coef_friction = 1.2; // Coefficient of friction
    double speed = 50; // in m/s
    double expected_grip = tire.coef_friction * speed; // Simplified grip formula
    double actual_grip = calculate_grip(&tire, speed);
    assert(actual_grip == expected_grip);
    printf("test_tire_grip passed.\n");
}

int main() {
    test_car_acceleration();
    test_car_handling();
    test_tire_grip();
    return 0;
}