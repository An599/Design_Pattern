#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>

class HotDrink
{
public:
	virtual void prepare(float volume) = 0;
};

class Tea : public HotDrink
{
public:
	void prepare(float volume) override
	{
		std::cout << "Prepare tea at " << volume << " degree\n" << std::endl;
	}
};

class Coffee : public HotDrink
{
public:
	void prepare(float volume) override
	{
		std::cout << "Prepare coffee at " << volume << " degree\n" << std::endl;
	}
};

class HotDrinkFactory {
public:
	virtual std::unique_ptr<HotDrink> make() const = 0;
};

class CoffeeFactory : public HotDrinkFactory
{
public:
	std::unique_ptr<HotDrink> make() const override
	{
		return std::make_unique<Coffee>();
	}
};

class TeaFactory : public HotDrinkFactory
{
public:
	std::unique_ptr<HotDrink> make() const override
	{
		return std::make_unique<Tea>();
	}
};
