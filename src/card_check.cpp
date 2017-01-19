#include "card_check.hpp"
//#include <cctype>
#include <algorithm>
#include <iostream>

const char* IssuerStat::name[] = {
  "Unknown",
  "JCB",
  "Diner's Club",
  "American Express",
  "Visa",
  "MasterCard",
  "Discover",
  "Union Pay"
};


CardCheck::CardCheck()
: number("")
, issuer(Unknown)
, digits(digitsLength,0)
{

}

CardCheck::CardCheck(const std::string &str)
: number("")
, issuer(Unknown)
, digits(digitsLength,0)
{
  //std::cout << "constructor str: " << str << std::endl;
  setNumber(str);
}

void CardCheck::setNumber(const std::string &str)
{
  //std::cout << "setNumber: " << str << std::endl;
  number = str;
  removeWhiteSpaces();
  //std::cout << "setNumber number: " << number << std::endl;
}

std::string CardCheck::getIssuer(void)
{
  idIssuer();
  return std::string(IssuerStat::name[issuer]);
}

void CardCheck::removeWhiteSpaces(void)
{
  //std::cout << "removeWhiteSpaces " << std::endl;
  /*
  using std::begin; using std::end;
  number.erase(std::remove_if(
      begin(number), end(number),
      [l = std::locale{}](auto ch) { return std::isspace(ch, l); }
  ), end(number));
  */
  number.erase(std::remove_if(std::begin(number), std::end(number), isspace), end(number));
}

void CardCheck::computeDigits(void)
{
  //std::cout << "computeDigits. number " << number << std::endl;
  long i;
  long stop = (digitsLength-1) < number.length() ? (digitsLength-1) : number.length();
  //std::cout << "stop: " << stop << std::endl;
  //std::cout << "digits.length: " << digits.size() << std::endl;
  digits[0] = 0; // first element is not used
	for (i = 1; i <= stop; i++) {
    //std::cout << i;
    //std::cout << " " << number.substr(0,i) << std::endl;
		digits[i] = std::stoi(number.substr(0, i));
	}
	// padding
	while (i < digits.size()) {
		digits[i++] = 0;
	}

/*
  std::cout << "digits" << std::endl;
  for (i = 0; i < digits.size(); i++)
    std::cout << i << " " << digits[i] << std::endl;
*/
}

/**
 * References:
 * http://stackoverflow.com/questions/174730/what-is-the-best-way-to-validate-a-credit-card-in-php
 * https://en.wikipedia.org/wiki/Payment_card_number#Issuer_identification_number_.28IIN.29
 */
void CardCheck::idIssuer(void)
{
  //std::cout << "idIssuer()" << std::endl;
  computeDigits();
/*
  std::cout << "CardCheck::idIssuer(void) digits" << std::endl;
  for (int i = 0; i < digits.size(); i++)
    std::cout << i << " " << digits[i] << std::endl;
*/
  switch (digits[1]) {
		case 2:
			if ((digits[4]>=2221) && (digits[4]<=2720)) {
				issuer = MasterCard;
			} else {
				issuer = Unknown;
			}
			break;
		case 3:
			switch (digits[2]) {
				case 30:
					switch (digits[3]) {
						case 300:
						case 301:
						case 302:
						case 303:
						case 304:
						case 305:
						case 309:
							issuer = DinersClub;
              break;
						default:
              issuer = Unknown;
              break;
					}
					break;
				case 34:
				case 37:
					issuer = Amex;
					break;
				case 36:
				case 38:
				case 39:
					issuer = DinersClub;
					break;
				case 35:
					if ((digits[4] >= 3528) && (digits[4] <= 3589)) {
						issuer = JCB;
					} else {
						issuer = Unknown;
					}
					break;
				default:
          issuer = Unknown;
          break;
			}
			break;
		case 4:
			issuer = Visa;
			break;
		case 5:
			switch (digits[2]) {
				case 51:
				case 52:
				case 53:
				case 54:
				case 55:
					issuer = MasterCard;
					break;
				default:
          issuer = Unknown;
          break;
			}
			break;
		case 6:
			switch (digits[2]) {
				case 60:
					if (digits[4]==6011) {
						issuer = Discover;
					} else {
						issuer = Unknown;
					}
					break;
				case 62:
					if ((digits[6]>=622126) && (digits[6]<=622925)) {
						issuer = Discover;
					} else {
						issuer = UnionPay;
					}
					break;
				case 64:
					if ((digits[3]>=644)&&(digits[3]<=649)) {
						issuer = Discover;
					} else {
						issuer = Unknown;
					}
					break;
				case 65:
					issuer = Discover;
					break;
				default:
          issuer = Unknown;
          break;
			}
			break;
		default:
      issuer = Unknown;
      break;
	}
}

bool CardCheck::testLuhn(void) const
{
  return(confirm(number.c_str()));
}

bool CardCheck::testLuhn(const std::string &str)
{
  setNumber(str);
  return testLuhn();
}

bool CardCheck::testLength(void) const
{
  bool passed = false;
  int length = number.length();

  switch(issuer) {
    case JCB:
      if (length == 16)
        passed = true;
      break;
    case DinersClub:
      if (length == 14)
        passed = true;
      break;
    case Amex:
      if (length == 15)
        passed = true;
      break;
    case Visa:
      if ((length == 13) || (length == 16))
        passed = true;
      break;
    case MasterCard:
      if ((length == 14) || (length == 16))
        passed = true;
      break;
    case Discover:
      if (length == 16)
        passed = true;
      break;
    case UnionPay:
      if ((length >= 16) && (length <= 19))
        passed = true;
      break;
    default:
      passed = false;
      break;
  }
  return passed;
}

int CardCheck::toInt(const char c) const
{
    return c-'0';
}

/**
 Luhn Algorithm
 Taken from: http://rosettacode.org/wiki/Luhn_test_of_credit_card_numbers#C.2B.2B
 Available under GNU Free Documentation License 1.2 unless otherwise noted.
 License: http://www.gnu.org/licenses/fdl-1.2.html
 */
bool CardCheck::confirm(const char *id) const
{
    bool is_odd_dgt = true;
    int s = 0;
    const char *cp;

    for(cp=id; *cp; cp++);
    while(cp > id) {
        --cp;
        int k = toInt(*cp);
        if (is_odd_dgt) {
            s += k;
        }
        else {
            s += (k!=9)? (2*k)%9 : 9;
        }
	      is_odd_dgt = !is_odd_dgt;
    }
    return 0 == s%10;
}
