#include "ATMHandler.h"
#include "10$_handler.h"
#include "20$_handler.h"
#include "50$__handler.h"
#include <iostream>

int main()
{
    TenD_Handler* obj_ten = new TenD_Handler;
    TwentyD_Handler* obj_twenty = new  TwentyD_Handler(obj_ten);
    FiftyD_Handler* obj_fifty = new FiftyD_Handler(obj_twenty);
    ATMHandler* atm = obj_fifty;
    std::cout << "Withdrawing 530$ " << std::endl;
    atm->handlerRequest(530);
    std::cout << "Withdrawing 545$ " << std::endl;
    atm->handlerRequest(545);
}
