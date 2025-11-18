#pragma once

class ATMHandler
{
protected:
	ATMHandler* m_next;
public:
	ATMHandler(ATMHandler* next = nullptr) : m_next(next) {}
	virtual ~ATMHandler() = default;
	virtual void handlerRequest(int money) = 0;
};

void ATMHandler::handlerRequest(int money)
{
	if (m_next)
		m_next->handlerRequest(money);
}
