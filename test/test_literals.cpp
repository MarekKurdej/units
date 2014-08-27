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
#include "test_header.hpp"

#include <boost/units/systems/si/dimensionless.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/prefixes.hpp>

namespace bu = boost::units;
namespace si = boost::units::si;

static const double E_ = 2.718281828459045235360287471352662497757;

int test_main(int,char *[])
{
#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS
    using namespace si::literals; // bring literals into scope
    const bu::quantity<bu::dimensionless> two(2);

    // mass
    const bu::quantity<si::mass, long double> E1ld = 1.234_kg; 
    BOOST_UNITS_CHECK_CLOSE(E1ld.value(), static_cast<long double>(1.234));

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

    {
    auto mKK = (23.0 * si::kilogram) * (1.5 * si::kilogram);
    std::cout << "34.5 kg^2 KK = " << mKK << "\n";
    auto mKU = (23.0 * si::kilogram) * (1.5_kg);
    std::cout << "34.5 kg^2 KU = " << mKU << "\n"; // FIXME
    auto mUU = (23.0_kg) * (1.5_kg);
    std::cout << "34.5 kg^2 UU = " << mUU << "\n"; // FIXME
    }
    
    {
    auto mKK = (23 * si::kilogram) * (2 * si::kilogram);
    std::cout << "46 kg^2 KK = " << mKK << "\n";
    auto mKU = (23 * si::kilogram) * (2_kg);
    std::cout << "46 kg^2 KU = " << mKU << "\n";
    auto mUU = (23_kg) * (2_kg);
    std::cout << "46 kg^2 UU = " << mUU << "\n";
    }
    
    std::cout << "34.5 kg^2 KK = " << (23.0 * si::kilogram) * (1.5  * si::kilogram) << "\n";
    std::cout << "34.5 kg^2 KU = " << (23.0 * si::kilogram) * (1.5_kg) << "\n"; // FIXME
    std::cout << "34.5 kg^2 UU = " << (23.0_kg) * (1.5_kg) << "\n"; // FIXME

    std::cout << "34.5 kg^2 KK = " << (23 * si::kilogram) * (1.5  * si::kilogram) << "\n";
    std::cout << "34.5 kg^2 KU = " << (23 * si::kilogram) * (1.5_kg) << "\n"; // FIXME
    std::cout << "34.5 kg^2 UU = " << (23_kg) * (1.5_kg) << "\n"; // FIXME

    BOOST_CHECK(15_g == 15 * si::milli * si::kilogram);
    BOOST_CHECK(1.25_g == 1.25 * si::milli * si::kilogram);

    BOOST_CHECK(5_g + 12_g == 17 * si::milli * si::kilogram);

#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS
/*
    
    // static construct quantity from value_type
    const bu::quantity<bu::energy>      E(bu::quantity<bu::energy>::from_value(2.5));
    BOOST_CHECK(E.value() == 2.5);
    
    // quantity_cast
        
    // unit * scalar
    BOOST_CHECK(bu::joules*2.0 == bu::quantity<bu::energy>::from_value(2.0));
    
    // unit / scalar
    BOOST_CHECK(bu::joules/2.0 == bu::quantity<bu::energy>::from_value(0.5));
    
    // scalar * unit
    BOOST_CHECK(2.0*bu::joules == bu::quantity<bu::energy>::from_value(2.0));
    
    // scalar / unit
    BOOST_CHECK(2.0/bu::joules == bu::quantity<bu::inverse_energy>::from_value(2.0));

    //  quantity * scalar
    BOOST_CHECK(E*2.0 == bu::quantity<bu::energy>::from_value(5.0));

    //  quantity / scalar
    BOOST_CHECK(E/2.0 == bu::quantity<bu::energy>::from_value(1.25));
    
    // scalar * quantity
    BOOST_CHECK(2.0*E == bu::quantity<bu::energy>::from_value(5.0));

    // scalar / quantity
    BOOST_CHECK(2.0/E == bu::quantity<bu::inverse_energy>::from_value(0.8));

    const bu::quantity<bu::length>      L(1.0*bu::meters);
    const bu::quantity<bu::mass>        M(2.0*bu::kilograms);
    const bu::quantity<bu::time>        T(3.0*bu::seconds);
    const bu::quantity<bu::velocity>    V(bu::quantity<bu::velocity>::from_value(4.0));
    
    // unit * quantity
    BOOST_CHECK(bu::seconds*V == 4.0*bu::meters);
    
    // unit / quantity
    BOOST_CHECK(bu::meters/V == 0.25*bu::seconds);
    
    // quantity * unit
    BOOST_CHECK(V*bu::seconds == 4.0*bu::meters);
    
    // quantity / unit
    BOOST_CHECK(V/bu::meters == 4.0/bu::seconds);
    
    // +quantity
    BOOST_CHECK(+V == 4.0*bu::meters_per_second);
    
    // -quantity
    BOOST_CHECK(-V == -4.0*bu::meters_per_second);
    
    // quantity + quantity
    BOOST_CHECK(V+V == 8.0*bu::meters_per_second);
    
    // quantity - quantity
    BOOST_CHECK(V-V == 0.0*bu::meters_per_second);
    
    // quantity * quantity
    BOOST_CHECK(V*T == 12.0*bu::meters);
    
    // quantity / quantity
    BOOST_CHECK(L/V == 0.25*bu::seconds);
    
    const bu::quantity<bu::area>    A(2.0*bu::square_meters);
    const bu::quantity<bu::volume>  VL(1.0*bu::cubic_meters);
    
    // integer power of quantity
    BOOST_CHECK(2.0*bu::pow<2>(L) == A);
    
    // rational power of quantity
    BOOST_CHECK((bu::pow< bu::static_rational<2,3> >(VL) == 0.5*A));
    
    // integer root of quantity
    BOOST_CHECK(bu::root<2>(A) == std::sqrt(2.0)*L);
    
    // rational root of quantity
    BOOST_CHECK((bu::root< bu::static_rational<3,2> >(VL) == 0.5*A));
    
*/
    return 0;
}
