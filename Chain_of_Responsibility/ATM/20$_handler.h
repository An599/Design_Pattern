#pragma once

#include "ATMHandler.h"
#include <iostream>

class TwentyD_Handler : public ATMHandler
{
private:

public:
	TwentyD_Handler(ATMHandler* next = nullptr) : ATMHandler(next) {}
	~TwentyD_Handler() {};
	void handlerRequest(int money)
	{
		if (money % 20 == 0)
		{
			std::cout << "ATM returned " << money / 20 << " tinmes 20$ to handle request . " << std::endl;

		}
		else
		{
			int n_of_20 = money / 20;
			std::cout << "Count of 20 dollars for giving requested money " << n_of_20 << std::endl;
			money -= n_of_20 * 20;
			ATMHandler::handlerRequest(money);
		}
	}
};
