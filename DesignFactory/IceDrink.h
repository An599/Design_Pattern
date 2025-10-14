#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>

class IceDrink
{
public:
	virtual void prepare(float volume) = 0;
};

class Juice : public IceDrink
{
public:
	void prepare(float volume) override
	{
		std::cout << "Prepare juice at " << volume << " degree\n" << std::endl;
	}
};

class IceCoffee : public IceDrink
{
public:
	void prepare(float volume) override
	{
		std::cout << "Prepare ice coffee at " << volume << " degree\n" << std::endl;
	}
};

class IceDrinkFactory 
{
public:
	virtual std::unique_ptr<IceDrink> make() const = 0;
};

class IceCoffeeFactory : public IceDrinkFactory 
{
public:
	std::unique_ptr<IceDrink> make() const override
	{
		return std::make_unique<IceCoffee>();
	}
};

class JuiceFactory : public IceDrinkFactory
{
public:
	std::unique_ptr<IceDrink> make() const override
	{
		return std::make_unique<Juice>();
	}
};
