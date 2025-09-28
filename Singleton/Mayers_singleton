#include <iostream>

class Singleton {
private:
    Singleton() {
        std::cout << "Singleton created"<<std::endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance; 
        return instance;
    }

    void print() {
        std::cout << "Print function for singleton obj"<<std::endl;
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.print();
    Singleton& s2 = Singleton::getInstance();
    if (&s1 == &s2) {
        std::cout << "Both are the same instance" <<std::endl;
    }
}
