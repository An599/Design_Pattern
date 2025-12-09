#include "State.h"
#include <iostream>

int main() {
    TrafficLight light(std::make_unique<RedState>());

    std::cout << "Traffic Light starting in state: " << light.currentStateName() << std::endl;
    light.run(8);

    return 0;
}
