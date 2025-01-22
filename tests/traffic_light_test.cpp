#include "gtest/gtest.h"
#include "traffic_light.h"
#include <thread>

// Helper function to run a TrafficLight instance in its own thread
void runTrafficLight(TrafficLight& trafficLight, void (TrafficLight::*func)()) {
    std::thread lightThread(func, &trafficLight);
    if (lightThread.joinable()) {
        lightThread.join();
    }
}

// Test Case 1: Simulate a Single Traffic Light
TEST(TrafficLightTest, SingleTrafficLight) {
    TrafficLight light("Single Light", 5);
    ASSERT_NO_THROW(runTrafficLight(light, &TrafficLight::RedToGreen));
}

// Test Case 2: Simulate Two Differentiated Traffic Lights
TEST(TrafficLightTest, TwoDifferentTrafficLights) {
    TrafficLight light1("Light One", 5); // Green initially
    TrafficLight light2("Light Two", 5); // Red initially

    std::thread thread1(&TrafficLight::RedToGreen, &light1);
    std::thread thread2(&TrafficLight::GreenToRed, &light2);

    if (thread1.joinable()) thread1.join();
    if (thread2.joinable()) thread2.join();
}

// Test Case 3: Simulate Three Traffic Lights (Two Perpendicular and One Different)
TEST(TrafficLightTest, ThreeTrafficLights) {
    TrafficLight lightA("North-South", 5); // Same direction
    TrafficLight lightB("East-West", 5); // Perpendicular
    TrafficLight lightC("Pedestrian Crossing", 3); // Independent

    std::thread threadA(&TrafficLight::RedToGreen, &lightA);
    std::thread threadB(&TrafficLight::GreenToRed, &lightB);
    std::thread threadC(&TrafficLight::RedToGreen, &lightC);

    if (threadA.joinable()) threadA.join();
    if (threadB.joinable()) threadB.join();
    if (threadC.joinable()) threadC.join();
}

// Test Case 4: Simulate Four Perpendicular Traffic Lights
TEST(TrafficLightTest, FourPerpendicularTrafficLights) {
    TrafficLight north("North", 5);
    TrafficLight south("South", 5);
    TrafficLight east("East", 5);
    TrafficLight west("West", 5);

    std::thread northThread(&TrafficLight::RedToGreen, &north);
    std::thread southThread(&TrafficLight::RedToGreen, &south);
    std::thread eastThread(&TrafficLight::GreenToRed, &east);
    std::thread westThread(&TrafficLight::GreenToRed, &west);

    if (northThread.joinable()) northThread.join();
    if (southThread.joinable()) southThread.join();
    if (eastThread.joinable()) eastThread.join();
    if (westThread.joinable()) westThread.join();
}
