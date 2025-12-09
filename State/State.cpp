#include "State.h"
#include <iostream>
#include <thread>
#include <chrono>

TrafficLight::TrafficLight(std::unique_ptr<LightState> initialState) : state_(std::move(initialState)) {}

void TrafficLight::setState(std::unique_ptr<LightState> newState) 
{
    state_ = std::move(newState);
}
void TrafficLight::run(int cycles) {
    for (int i = 0; i < cycles; ++i) {
        state_->enter(*this);

        int seconds = state_->durationSeconds();
        for (int s = seconds; s > 0; --s) {
            std::cout << "  [" << state_->name() << "] " << s
                << "s remaining\r" << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << std::string(60, ' ') << "\r";

        state_->handle(*this);
    }
}

std::string TrafficLight::currentStateName() const 
{
    return state_ ? state_->name() : "<none>";
}

void RedState::enter(TrafficLight&) 
{
    std::cout << "\n>>> Entering RED" <<std::endl;
}
void RedState::handle(TrafficLight& light) 
{
    light.setState(std::make_unique<YellowAfterRed>());  
}
void YellowAfterRed::enter(TrafficLight&) 
{
    std::cout << ">>> Entering YELLOW (after RED)" << std::endl;
}
void YellowAfterRed::handle(TrafficLight& light) 
{
    light.setState(std::make_unique<GreenState>());        
}

void GreenState::enter(TrafficLight&) 
{
    std::cout << ">>> Entering GREEN" << std::endl;
}
void GreenState::handle(TrafficLight& light) 
{
    light.setState(std::make_unique<YellowAfterGreen>());  
}
void YellowAfterGreen::enter(TrafficLight&) 
{
    std::cout << ">>> Entering YELLOW (after GREEN)"<<std::endl;
}
void YellowAfterGreen::handle(TrafficLight& light) 
{
    light.setState(std::make_unique<RedState>());        
}
