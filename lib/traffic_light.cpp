
#include "traffic_light.h"

// Initialization of static members, if any
HANDLE TrafficLight::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

map<string, string> LIGHTS = {
    {"RED", "RED"},
    {"YELLOW", "YELLOW"},
    {"GREEN", "GREEN"}
};

map<string, int> COLORS = {
    {"DEFAULT", 7},
    {"RED", 4},
    {"GREEN", 2},
    {"YELLOW", 6}
};

TrafficLight::TrafficLight(string name, int duration)
    : name(name), duration(duration) {
}

void TrafficLight::RedToGreen() {
    iterate("RED");
    iterate("YELLOW");
    iterate("GREEN");
    iterate("YELLOW");
}

void TrafficLight::GreenToRed() {
    iterate("GREEN");
    iterate("YELLOW");
    iterate("RED");
    iterate("YELLOW");
}

void TrafficLight::changeColor(int COLOR) {
    SetConsoleTextAttribute(this->hConsole, COLOR);
}

void TrafficLight::displayStationName() {
    cout << this->name << " Traffic Light: ";
}

void TrafficLight::displayTrafficLight(string CURRENTLIGHT, int DURATION) {
    cout << CURRENTLIGHT << " (" << DURATION << " sec/s)" << endl;
}

void TrafficLight::timer() {
    this_thread::sleep_for(chrono::milliseconds(800));
}

void TrafficLight::iterate(string CURRENTLIGHT) {
    const int DURATION = CURRENTLIGHT == LIGHTS["YELLOW"] ? 2 : this->duration;
    for (int i = DURATION; i >= 0; i--) {
        changeColor(COLORS["DEFAULT"]);
        displayStationName();
        changeColor(COLORS[CURRENTLIGHT]);
        displayTrafficLight(CURRENTLIGHT, i);
        timer();
    }
}