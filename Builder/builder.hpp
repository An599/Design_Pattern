#pragma once
#include <iostream>
#include <string>

class House
{
private:
    bool hasGarden;
    bool hasPool;
    int rooms;

public:
    House(bool garden, bool pool, int roomCount)
        : hasGarden(garden), hasPool(pool), rooms(roomCount) {
    }

    void show() const
    {
        std::cout << "House details: " <<std::endl;
        std::cout << "  Rooms: " << rooms << std::endl;
        std::cout << "  Garden: " << (hasGarden ? "Yes" : "No") << std::endl;
        std::cout << "  Swimming Pool: " << (hasPool ? "Yes" : "No") << std::endl;
    }
};

class HouseBuilder
{
private:
    bool hasGarden = false;
    bool hasPool = false;
    int rooms = 1;

public:
    HouseBuilder& withGarden()
    {
        hasGarden = true;
        return *this;
    }

    HouseBuilder& withPool()
    {
        hasPool = true;
        return *this;
    }

    HouseBuilder& withRooms(int count)
    {
        rooms = count;
        return *this;
    }

    House build() const
    {
        return House(hasGarden, hasPool, rooms);
    }
};
