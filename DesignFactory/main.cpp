#include <iostream>
#include <memory>

#include "HotDrink.h"
#include "IceDrink.h"
#include "DrinkFactory.h"

int main()
{
	DrinkFactory factory;

	auto coffee = factory.makeHotDrink("coffee");
	coffee->prepare(100);

	auto tea = factory.makeHotDrink("tea");
	tea->prepare(90);

	auto juice = factory.makeColdDrink("juice");
	juice->prepare(10);

	auto iceCoffee = factory.makeColdDrink("ice coffee");
	iceCoffee->prepare(20);

	return 0;
}
