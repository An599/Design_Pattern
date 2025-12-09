#include "Observer.h"
#include <iostream>

void NotificationManager::subscribe(IObserver* obs) 
{
    std::lock_guard<std::mutex> lock(mtx);
    observers.push_back(obs);
}

void NotificationManager::unsubscribe(IObserver* obs) 
{
    std::lock_guard<std::mutex> lock(mtx);
    observers.erase(
        std::remove(observers.begin(), observers.end(), obs),
        observers.end()
    );
}

void NotificationManager::notify(const std::string& msg) 
{
    std::lock_guard<std::mutex> lock(mtx);
    for (auto* obs : observers)
        obs->onNotify(msg);
}

ConsoleObserver::ConsoleObserver(const std::string& name) : name(name) {}

void ConsoleObserver::onNotify(const std::string& message) 
{
    std::cout << "[Observer " << name << "] received: " << message << std::endl;
}
