#ifndef LIB_TRAFFIC_LIGHT_H
#define LIB_TRAFFIC_LIGHT_H

#include <string>
#include <map>
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

class TrafficLight {
private:
    string name;
    int duration;

public:
    static HANDLE hConsole;
    explicit TrafficLight(string name, int duration = 5);
    void RedToGreen();
    void GreenToRed();

private:
    void changeColor(int COLOR);
    void displayStationName();
    static void displayTrafficLight(string CURRENTLIGHT, int DURATION);
    static void timer();
    void iterate(string CURRENTLIGHT);
};

#endif // LIB_TRAFFIC_LIGHT_H