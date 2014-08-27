// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "test_header.hpp"
#include <boost/units/systems/si/length.hpp>

namespace bu = boost::units;

int test_main(int,char *[])
{
    bu::quantity<bu::si::length, int> q1 = -13 * bu::si::meter;
    bu::quantity<bu::si::length, int> q2 = 10 * bu::si::meter;

    // quantity % scalar
    BOOST_CHECK((q1 % 10).value() == -3);
    BOOST_CHECK((q2 % 7).value() == 3);
    BOOST_CHECK(q1 % 10 == -3 * bu::si::meter);
    BOOST_CHECK(q2 % 7 == 3 * bu::si::meter);

    q1 = -13 * bu::si::meter;
    q2 = 10 * bu::si::meter;
    // quantity %= scalar
    q1 %= 10;
    q2 %= 7;
    BOOST_CHECK(q1.value() == -3);
    BOOST_CHECK(q2 == 3 * bu::si::meter);

    q1 = -13 * bu::si::meter;
    q2 = 3 * bu::si::meter;
    // ++quantity
    BOOST_CHECK((++q1).value() == -12);
    BOOST_CHECK(++q2 == 4 * bu::si::meter);

    q1 = -13 * bu::si::meter;
    q2 = 3 * bu::si::meter;
    // --quantity
    BOOST_CHECK((--q1).value() == -14);
    BOOST_CHECK(--q2 == 2 * bu::si::meter);

    q1 = -13 * bu::si::meter;
    q2 = 3 * bu::si::meter;
    // quantity++
    BOOST_CHECK((q1++).value() == -13);
    BOOST_CHECK(q1.value() == -12);
    BOOST_CHECK(q2++ == 3 * bu::si::meter);
    BOOST_CHECK(q2 == 4 * bu::si::meter);

    q1 = -13 * bu::si::meter;
    q2 = 3 * bu::si::meter;
    // quantity--
    BOOST_CHECK((q1--).value() == -13);
    BOOST_CHECK(q1.value() == -14);
    BOOST_CHECK(q2-- == 3 * bu::si::meter);
    BOOST_CHECK(q2 == 2 * bu::si::meter);

    return 0;
}
