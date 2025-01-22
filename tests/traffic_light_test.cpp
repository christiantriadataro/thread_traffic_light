#include "gtest/gtest.h"
#include "traffic_light.h"
#include <thread>

// Helper function to run a TrafficLight instance in its own thread
void runTrafficLight(TrafficLight& trafficLight, void (TrafficLight::*func)()) {
    std::thread trafficLightObj(func, &trafficLight);
    if (trafficLightObj.joinable()) {
        trafficLightObj.join();
    }
}

// Test Case 1: Simulate a Single Traffic Light
TEST(TrafficLightTest, SingleTrafficLight) {
    TrafficLight North("North", 5);
    ASSERT_NO_THROW(runTrafficLight(North, &TrafficLight::RedToGreen));
}

// Test Case 2: Simulate Two Differentiated Traffic Lights
TEST(TrafficLightTest, TwoDifferentTrafficLights) {
    TrafficLight North("North", 5);
    TrafficLight South("South", 5);

    std::thread t1(&TrafficLight::RedToGreen, &North);
    std::thread t2(&TrafficLight::GreenToRed, &South);

    if (t1.joinable()) {
        t1.join();
    }
    if (t2.joinable()) {
        t2.join();
    }
}

// Test Case 3: Simulate Three Traffic Lights
TEST(TrafficLightTest, ThreeTrafficLights) {
    TrafficLight North("North", 5);
    TrafficLight South("South", 5);
    TrafficLight East("East", 5);

    std::thread t1(&TrafficLight::RedToGreen, &North);
    std::thread t2(&TrafficLight::GreenToRed, &South);
    std::thread t3(&TrafficLight::RedToGreen, &East);

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    if (t3.joinable()) t3.join();
}

// Test Case 4: Simulate Four Perpendicular Traffic Lights
TEST(TrafficLightTest, FourPerpendicularTrafficLights) {
    TrafficLight North("North", 5);
    TrafficLight South("South", 5);
    TrafficLight East("East", 5);
    TrafficLight West("West", 5);

    std::thread t1(&TrafficLight::RedToGreen, &North);
    std::thread t2(&TrafficLight::RedToGreen, &South);
    std::thread t3(&TrafficLight::GreenToRed, &East);
    std::thread t4(&TrafficLight::GreenToRed, &West);

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    if (t3.joinable()) t3.join();
    if (t4.joinable()) t4.join();
}
