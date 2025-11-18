#pragma once

#include "ATMHandler.h"
#include <iostream>

class TenD_Handler : public ATMHandler
{
private:

public:
	TenD_Handler(ATMHandler* next = nullptr) : ATMHandler(next) {}
	~TenD_Handler() {};
	void handlerRequest(int money)
	{
		if (money % 10 == 0)
		{
			std::cout << "Count of 10 dollars for giving requested money " << money/10 << std::endl;

		}
		else
		{
			std::cout << "Can t withdraw given amount" <<  std::endl;
		}
	}
};
