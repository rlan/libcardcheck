/**
 * Payment/card number checker.
 *
 * Given a payment number, identify
 *   - Issuer
 *   - Luhn checksum
 *   - Number length check
 */
#include <string>
#include <vector>

enum Issuer {
  Unknown,
  JCB,
  DinersClub,
  Amex,
  Visa,
  MasterCard,
  Discover,
  UnionPay
};

struct IssuerStat {
  static const char* name[];
};


class CardCheck {
public:
  CardCheck();
  CardCheck(const std::string &);

  void setNumber(const std::string &);
  std::string getIssuer(void);
  bool testLuhn(void) const;
  bool testLuhn(const std::string &);
  bool testLength(void) const;

private:
  void removeWhiteSpaces(void);
  void computeDigits(void);
  void idIssuer(void);

  // Luhn Tests
  int toInt(const char c) const;
  bool confirm(const char *id) const;

  std::string number;
  Issuer issuer;
  static const int digitsLength = 7;
  std::vector<int> digits;
};
