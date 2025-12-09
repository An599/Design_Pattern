#include "Observer.h"
#include <thread>
#include <chrono>

int main() {
    NotificationManager manager;

    ConsoleObserver obs1("A");
    ConsoleObserver obs2("B");

    manager.subscribe(&obs1);
    manager.subscribe(&obs2);

    std::thread worker([&]() {
        manager.notify("Update #1");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        manager.notify("Update #2");
        });

    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    manager.unsubscribe(&obs2);

    worker.join();
    return 0;
}
