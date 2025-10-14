#pragma once

#include "HotDrink.h"
#include "IceDrink.h"

#include <memory>

class DrinkFactory
{
public:
	DrinkFactory()
	{
		hotfactories["coffee"] = std::make_unique<CoffeeFactory>();
		hotfactories["tea"] = std::make_unique<TeaFactory>();
		icefactories["juice"] = std::make_unique<JuiceFactory>();
		icefactories["ice coffee"] = std::make_unique<IceCoffeeFactory>();
	}
	std::unique_ptr<HotDrink> makeHotDrink(const std::string& name)
	{
		if (hotfactories.find(name) != hotfactories.end())
			return hotfactories[name]->make();
		return nullptr;
	}
	std::unique_ptr<IceDrink> makeColdDrink(const std::string& name)
	{
		if (icefactories.find(name) != icefactories.end())
			return icefactories[name]->make();
		return nullptr;
	}
private:
	std::unordered_map <std::string, std::unique_ptr<HotDrinkFactory>> hotfactories;
	std::unordered_map <std::string, std::unique_ptr<IceDrinkFactory>> icefactories;
};
