#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

//std::mutex car_mutex;
//int sharedData = 0;

class Car {
private:
    Car() {
        std::cout << " Private constructor of Class Car" << std::endl;
    }
    Car(const Car&) = delete;
    ~Car() {
        std::cout << " Private denstructor of Class Car" << std::endl;
    }
    static std::shared_ptr<Car> instance;
    static std::mutex car_mutex;
public:
    static std::shared_ptr<Car> getInstance() {
        std::lock_guard<std::mutex> lock(car_mutex);
        if (!instance) {
            instance = std::shared_ptr<Car>(new Car(), [](Car* c) {delete c;});
        }
        return instance;
    }
    void print() {
        std::cout << "Print funcion for Car obj" << std::endl;
    }
};

std::shared_ptr<Car> Car::instance = nullptr;
std::mutex Car::car_mutex;

void threadFunc() {
    auto s = Car::getInstance();
}


int main()
{
    std::thread t1(threadFunc);
    std::thread t2(threadFunc);
    t1.join();
    t2.join();
    //Car* c1 = Car::getInstance();

    //Car* c2 = Car::getInstance();
    return 0;
}
