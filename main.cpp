// #include "../lib/traffic_light.h"
// #include <thread>
//
// int main() {
//     TrafficLight North("North");
//     TrafficLight South("South");
//     TrafficLight East("East");
//     TrafficLight West("West");
//
//     thread NorthThread(&TrafficLight::RedToGreen, &North);
//     thread SouthThread(&TrafficLight::GreenToRed, &South);
//     thread EastThread(&TrafficLight::RedToGreen, &East);
//     thread WestThread(&TrafficLight::GreenToRed, &West);
//
//     if (NorthThread.joinable()) {
//         NorthThread.join();
//     }
//     if (SouthThread.joinable()) {
//         SouthThread.join();
//     }
//     if (EastThread.joinable()) {
//         EastThread.join();
//     }
//     if (WestThread.joinable()) {
//         WestThread.join();
//     }
//
//     this_thread::sleep_for(chrono::seconds(2));
//     return 0;
// }
// #include <gtest/gtest.h>

#include "../tests/googletests/googletest/include/gtest/gtest.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
