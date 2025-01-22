#ifndef LIB_TRAFFIC_LIGHT_H
#define LIB_TRAFFIC_LIGHT_H

#include <string>
#include <windows.h>
#include <chrono>


using namespace std;

class TrafficLight {
private:
    string name;
    int duration;

public:
    TrafficLight(string name, int duration = 5);
    static HANDLE hConsole;
    void RedToGreen();
    void GreenToRed();

private:
    void changeColor(int COLOR);
    void displayStationName();
    static void displayTrafficLight(string CURRENTLIGHT, int DURATION);
    static void timer();
    void iterate(string CURRENTLIGHT);
    void display(string CURRENTLIGHT, int DURATION);
};

#endif // LIB_TRAFFIC_LIGHT_H