#include <iostream>
#include "Queue.h"

int main()
{
    Queue<int> q;
    q.push(10);
    q.push(15);
    q.push(20);
    std::cout << "Queue's front " << q.front() << std::endl;
    q.pop();
    std::cout << "Queue's front after doing first pop" << q.front() << std::endl;
    std::cout << "Queue's front " << q.back() << std::endl;
    std::cout << "Queue's state " << std::boolalpha << q.empty() << std::endl;
    q.clear();
    std::cout << "Queue's state after calling clear function" << std::boolalpha << q.empty() << std::endl;
}
