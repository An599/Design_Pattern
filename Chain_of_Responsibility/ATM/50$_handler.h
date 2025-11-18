#pragma once

#include "ATMHandler.h"
#include <iostream>

class FiftyD_Handler : public ATMHandler
{
private:

public:
	FiftyD_Handler(ATMHandler* next = nullptr) : ATMHandler(next) {}
	~FiftyD_Handler() {};
	void handlerRequest(int money)
	{
		if (money % 50 == 0)
		{
			std::cout << "ATM returned " << money / 50 << " tinmes 50$ to handle request . " << std::endl;

		}
		else
		{
			int n_of_50 = money / 50;
			std::cout << "Count of 50 dollars for giving requested money " << n_of_50 << std::endl;
			money -= n_of_50 * 50;
			ATMHandler::handlerRequest(money);
		}
	}
};
