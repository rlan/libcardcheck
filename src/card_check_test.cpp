#define BOOST_TEST_MODULE card_check_test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include "card_check.hpp"

namespace bdata = boost::unit_test::data;


BOOST_AUTO_TEST_SUITE( suite_luhn )

BOOST_AUTO_TEST_CASE( luhn )
{
  CardCheck cc;
  BOOST_TEST(cc.testLuhn("378282246310005"));
  BOOST_TEST(cc.testLuhn("371449635398431"));
  BOOST_TEST(cc.testLuhn("378734493671000"));
  BOOST_TEST(cc.testLuhn("30569309025904"));
  BOOST_TEST(cc.testLuhn("38520000023237"));
  BOOST_TEST(cc.testLuhn("6011111111111117"));
  BOOST_TEST(cc.testLuhn("6011000990139424"));
  BOOST_TEST(cc.testLuhn("3530111333300000"));
  BOOST_TEST(cc.testLuhn("3566002020360505"));
  BOOST_TEST(cc.testLuhn("5555555555554444"));
  BOOST_TEST(cc.testLuhn("5105105105105100"));
  BOOST_TEST(cc.testLuhn("4111111111111111"));
  BOOST_TEST(cc.testLuhn("4012888888881881"));
  BOOST_TEST(cc.testLuhn("4222222222222"));
}

BOOST_AUTO_TEST_SUITE_END()






BOOST_AUTO_TEST_SUITE( suite_jcb )

BOOST_DATA_TEST_CASE( jcb_issuer1, bdata::xrange(3528,3589) )
{
  CardCheck cc(std::to_string(sample));
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[JCB]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_amex )

BOOST_AUTO_TEST_CASE( amex_issuer1 )
{
  CardCheck cc;
  cc.setNumber("34");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Amex]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("37");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Amex]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_visa )

BOOST_AUTO_TEST_CASE( visa_issuer1 )
{
  CardCheck cc;
  cc.setNumber("4");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Visa]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_mastercard )

BOOST_DATA_TEST_CASE( mastercard_issuer1, bdata::xrange(2221,2720) )
{
  CardCheck cc(std::to_string(sample));
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[MasterCard]);
  BOOST_TEST(!cc.testLength());
}

BOOST_DATA_TEST_CASE( mastercard_issuer2, bdata::xrange(51,55) )
{
  CardCheck cc(std::to_string(sample));
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[MasterCard]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_dinersclub )

BOOST_DATA_TEST_CASE( dinersclub_issuer1, bdata::xrange(300,305) )
{
  CardCheck cc(std::to_string(sample));
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[DinersClub]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_CASE( dinersclub_issuer2 )
{
  CardCheck cc;
  cc.setNumber("36");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[DinersClub]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("38");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[DinersClub]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_discover )

BOOST_DATA_TEST_CASE( discover_issuer1, bdata::xrange(622126,622925) )
{
  CardCheck cc(std::to_string(sample));
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Discover]);
  BOOST_TEST(!cc.testLength());
}

BOOST_DATA_TEST_CASE( discover_issuer2, bdata::xrange(644,649) )
{
  CardCheck cc(std::to_string(sample));
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Discover]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_CASE( discover_issuer3 )
{
  CardCheck cc;
  cc.setNumber("6011");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Discover]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("65");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Discover]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_unionpay )

BOOST_AUTO_TEST_CASE( unionpay_issuer1 )
{
  CardCheck cc;
  cc.setNumber("62");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[UnionPay]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("622125");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[UnionPay]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()





BOOST_AUTO_TEST_SUITE( suite_corner )

BOOST_AUTO_TEST_CASE( corner_issuer1 )
{
  CardCheck cc;
  cc.setNumber("0");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("1");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("2");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("3");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("4");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Visa]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("5");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("6");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("7");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("8");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("9");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());

  cc.setNumber("63");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
  cc.setNumber("306");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());
}

BOOST_AUTO_TEST_SUITE_END()






/** test from paypal test credit card numbers
 https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
 */
BOOST_AUTO_TEST_SUITE( suite_paypal )

BOOST_AUTO_TEST_CASE( paypal_issuer1 )
{
  CardCheck cc;

  // Amex
  cc.setNumber("378282246310005");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Amex]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("371449635398431");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Amex]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("378734493671000");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Amex]);
  BOOST_TEST(cc.testLength());

  // Bankcard, not supported
  cc.setNumber("5610591081018250");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());

  // Diner's Club
  cc.setNumber("30569309025904");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[DinersClub]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("38520000023237");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[DinersClub]);
  BOOST_TEST(cc.testLength());

  // Discover Card
  cc.setNumber("6011111111111117");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Discover]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("6011000990139424");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Discover]);
  BOOST_TEST(cc.testLength());

  // JCB
  cc.setNumber("3530111333300000");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[JCB]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("3566002020360505");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[JCB]);
  BOOST_TEST(cc.testLength());

  // MasterCard
  cc.setNumber("5555555555554444");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[MasterCard]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("5105105105105100");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[MasterCard]);
  BOOST_TEST(cc.testLength());

  // Visa
  cc.setNumber("4111111111111111");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Visa]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("4012888888881881");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Visa]);
  BOOST_TEST(cc.testLength());
  cc.setNumber("4222222222222");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Visa]);
  BOOST_TEST(cc.testLength());

  // Dankort (PBS), not supported
  cc.setNumber("76009244561");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  cc.setNumber("5019717010103742");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());

  // Switch/Solo (Paymentech), not supported
  cc.setNumber("6331101999990016");
  BOOST_TEST(cc.getIssuer() == IssuerStat::name[Unknown]);
  BOOST_TEST(!cc.testLength());

}

BOOST_AUTO_TEST_SUITE_END()
