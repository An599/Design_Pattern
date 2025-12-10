#pragma once
#include <iostream>

class Waiter_Subsystem1
{
public:
    void writeOrder() 
    {
        std::cout << "Waiter writes client's order" << std::endl; 
    }
    void sendToKitchen() 
    {
        std::cout << "Send order to kitchen" << std::endl; 
    }
    void serveCustomer()
    {
        std::cout << "Customer is served!" << std::endl; 
    }
};

class Kitchen_Subsystem2
{
public:
    void prepareFood() 
    {
        std::cout << "Cook food" << std::endl; 
    }
    void callWaiter() 
    { 
        std::cout << "Call Waiter" << std::endl; 
    }
    void washDishes() 
    {
        std::cout << "Wash the dishes" << std::endl; 
    }
};



class Order_Facade
{
private:
    Waiter_Subsystem1 waiter;
    Kitchen_Subsystem2 kitchen;

public:
    void orderFood()
    {
        waiter.writeOrder();
        waiter.sendToKitchen();

        kitchen.prepareFood();
        kitchen.callWaiter();

        waiter.serveCustomer();

        kitchen.washDishes();
    }
};
