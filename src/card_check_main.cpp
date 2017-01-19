#include <iostream>
#include "card_check.hpp"

int main(void) {
  CardCheck cc;
  std::string str = "378282246310005";
  cc.setNumber(str);
  std::cout << "Card number: " << str << std::endl
            << "Issuer: " << cc.getIssuer() << std::endl
            << "test Luhn: " << cc.testLuhn() << std::endl
            << "test length: " << cc.testLength() << std::endl;
	return(0);
}
