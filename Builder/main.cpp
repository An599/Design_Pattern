#include "builder.hpp"
#include <iostream>
#include <string>

int main()
{
    House simpleHouse = HouseBuilder().withRooms(2).build();
    simpleHouse.show();


    House gardenHouse = HouseBuilder().withRooms(3).withGarden().build();
    gardenHouse.show();


    House luxuryHouse = HouseBuilder().withRooms(5).withGarden().withPool().build();
    luxuryHouse.show();

    int rooms;
    std::string garden_inp, pool_inp;
    bool garden, pool;
    std::cout << "Enter house's rooms count you want to build" << std::endl;
    do { std::cin >> rooms; } while (rooms < 1);

    std::cout << "Enter Yes if you want to build house with garden otherwise No" << std::endl;
    std::cin >> garden_inp;
    if (garden_inp == "Yes" || garden_inp == "yes")
        garden = true;
    else
        garden = false;

    std::cout << "Enter Yes if you want to build house with pool otherwise No" << std::endl;
    std::cin >> pool_inp;
    if (pool_inp == "Yes" || pool_inp == "yes")
        pool = true;
    else
        pool = false;

    if (pool and garden)
    {
        House inputHouse = HouseBuilder().withRooms(rooms).withGarden().withPool().build();
        inputHouse.show();
    }
    if (pool)
    {
        House inputHouse = HouseBuilder().withRooms(rooms).withPool().build();
        inputHouse.show();
    }
    if (garden)
    {
        House inputHouse = HouseBuilder().withRooms(rooms).withGarden().build();
        inputHouse.show();
    }
    else
    {
        House simpleHouse = HouseBuilder().withRooms(rooms).build();
        simpleHouse.show();
    }

    return 0;
}
