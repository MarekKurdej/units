// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Marek Kurdej
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief test_udl.cpp

\details
Test user-defined literals operators.

Output:
@verbatim
@endverbatim
**/

#include <boost/units/systems/si/literals.hpp>

#include <boost/config.hpp>
#include <boost/regex.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/si/dimensionless.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <sstream>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

namespace bu = boost::units;
namespace si = boost::units::si;

static const double E_ = 2.718281828459045235360287471352662497757;

#ifndef BOOST_NO_CWCHAR

#define BOOST_UNITS_TEST_OUTPUT(v, expected)                \
{                                                           \
    std::ostringstream ss;                                  \
    ss FORMATTERS << v;                                     \
    BOOST_CHECK_EQUAL(ss.str(), expected);                  \
}                                                           \
{                                                           \
    std::wostringstream ss;                                 \
    ss FORMATTERS << v;                                     \
    BOOST_CHECK(ss.str() == BOOST_PP_CAT(L, expected));     \
}

#define BOOST_UNITS_TEST_OUTPUT_REGEX(v, expected)          \
{                                                           \
    std::ostringstream ss;                                  \
    ss FORMATTERS << v;                                     \
    boost::regex r(expected);                               \
    BOOST_CHECK_MESSAGE(boost::regex_match(ss.str(), r),    \
        ss.str() + " does not match " + expected);          \
}                                                           \
{                                                           \
    std::wostringstream ss;                                 \
    ss FORMATTERS << v;                                     \
    boost::wregex r(BOOST_PP_CAT(L, expected));             \
    BOOST_CHECK(boost::regex_match(ss.str(), r));           \
}

#else

#define BOOST_UNITS_TEST_OUTPUT(v, expected)                \
{                                                           \
    std::ostringstream ss;                                  \
    ss FORMATTERS << v;                                     \
    BOOST_CHECK_EQUAL(ss.str(), expected);                  \
}

#define BOOST_UNITS_TEST_OUTPUT_REGEX(v, expected)          \
{                                                           \
    std::ostringstream ss;                                  \
    ss FORMATTERS << v;                                     \
    boost::regex r(expected);                               \
    BOOST_CHECK_MESSAGE(boost::regex_match(ss.str(), r),    \
        ss.str() + " does not match " + expected);          \
}

#endif

using namespace si::literals; // bring literals into scope
#define FORMATTERS /**/

BOOST_AUTO_TEST_CASE(test_literals_value)
{
#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS
    const bu::quantity<si::dimensionless> two(2);

    // mass
    const bu::quantity<si::mass, long double> E1ld = 1.234_kg; 
    BOOST_CHECK_CLOSE(E1ld.value(), static_cast<long double>(1.234), 1e9);

    const bu::quantity<si::mass, unsigned long long> E1ull = 345_kg; 
    BOOST_CHECK(E1ull.value() == 345);
    
    const bu::quantity<si::mass, long long> E1ll = -345_kg;
    BOOST_CHECK(E1ll.value() == -345);

    BOOST_CHECK((123_kg + 10_kg).value() == 133);
    BOOST_CHECK(123_kg + 10_kg == 133_kg);
    BOOST_CHECK(123_kg - 10_kg == 113_kg);

    BOOST_CHECK((124_kg * two).value() == 248);
    // BOOST_CHECK(124_kg * (2*bu::dimensionless()) == 248_kg);

    const bu::quantity<si::mass> E2 = 13_kg; 
    // const bu::quantity<si::mass> E3 = 1.3_kg; 
    BOOST_CHECK(E2.value() == 13);
    
    BOOST_CHECK(23_kg == 23 * si::kilogram);
    BOOST_CHECK(1.125_kg == 1.125 * si::kilogram);

    BOOST_CHECK(2.5_kg == 2.0 * si::kilogram + 0.5 * si::kilogram);
    // int * int
    BOOST_CHECK(5_kg * 12_kg == (5 * si::kilogram) * (12 * si::kilogram));
    BOOST_CHECK(5_kg * 12_kg == 60 * si::kilogram * si::kilogram);
    // double * double
    BOOST_CHECK(23.0_kg * 1.5_kg == (23.0 * si::kilogram) * (1.5 * si::kilogram));
    BOOST_CHECK(23.0_kg * 1.5_kg == 34.5 * si::kilogram * si::kilogram);
    // int * double
    BOOST_CHECK(23_kg * 1.5_kg == (23 * si::kilogram) * (1.5 * si::kilogram));
    BOOST_CHECK(23_kg * 1.5_kg == 34.5 * si::kilogram * si::kilogram);
    
    BOOST_CHECK(15_g == 15 * si::milli * si::kilogram);
    BOOST_CHECK(1.25_g == 1.25 * si::milli * si::kilogram);
    BOOST_CHECK(5_g + 12_g == 17 * si::milli * si::kilogram);
#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS
}

BOOST_AUTO_TEST_CASE(test_literals_output_kg)
{
#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS
    // int * int
    BOOST_UNITS_TEST_OUTPUT((23 * si::kilogram) * (2 * si::kilogram), "46 kg^2");
    BOOST_UNITS_TEST_OUTPUT((23_kg) * (2 * si::kilogram), "46 kg^2");
    BOOST_UNITS_TEST_OUTPUT((23 * si::kilogram) * (2_kg), "46 kg^2");
    BOOST_UNITS_TEST_OUTPUT((23_kg) * (2_kg), "46 kg^2");

    // double * double
    BOOST_UNITS_TEST_OUTPUT((23.0 * si::kilogram) * (1.5 * si::kilogram), "34.5 kg^2");
    // BOOST_UNITS_TEST_OUTPUT((23.0_kg) * (1.5 * si::kilogram), "34.5 kg^2"); // FIXME
    // BOOST_UNITS_TEST_OUTPUT((23.0 * si::kilogram) * (1.5_kg), "34.5 kg^2"); // FIXME
    // BOOST_UNITS_TEST_OUTPUT((23.0_kg) * (1.5_kg), "34.5 kg^2"); // FIXME

    // int * double
    BOOST_UNITS_TEST_OUTPUT((23 * si::kilogram) * (1.5 * si::kilogram), "34.5 kg^2");
    BOOST_UNITS_TEST_OUTPUT((23_kg) * (1.5 * si::kilogram), "34.5 kg^2");
    // BOOST_UNITS_TEST_OUTPUT((23 * si::kilogram) * (1.5_kg), "34.5 kg^2"); // FIXME
    // BOOST_UNITS_TEST_OUTPUT((23_kg) * (1.5_kg), "34.5 kg^2"); // FIXME
#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS
}

BOOST_AUTO_TEST_CASE(test_literals_output_g)
{
#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS
    // int * int
    BOOST_UNITS_TEST_OUTPUT(35_g, "35 g");
    BOOST_UNITS_TEST_OUTPUT(35_g + 5_g, "40 g");
    // BOOST_UNITS_TEST_OUTPUT(34.5_g, "34.5 g"); // FIXME
    BOOST_UNITS_TEST_OUTPUT(23_g * 2_g, "46 u(kg^2)");
    // BOOST_UNITS_TEST_OUTPUT(23.0_g * 1.5_g, "34.5 u(kg^2)"); // FIXME
#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS
}

BOOST_AUTO_TEST_CASE(test_literals_output_mg)
{
#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS
    // int * int
    BOOST_UNITS_TEST_OUTPUT(35_mg, "35 mg");
    BOOST_UNITS_TEST_OUTPUT(35_mg + 5_mg, "40 mg");
    // BOOST_UNITS_TEST_OUTPUT(34.5_mg, "34.5 mg"); // FIXME
    BOOST_UNITS_TEST_OUTPUT(23_mg * 2_mg, "46 p(kg^2)");
    // BOOST_UNITS_TEST_OUTPUT(23.0_mg * 1.5_mg, "34.5 p(kg^2)"); // FIXME
#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS
}

#undef FORMATTERS
