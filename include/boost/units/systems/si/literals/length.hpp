// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Marek Kurdej
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEMS_SI_LITERALS_LENGTH_HPP
#define BOOST_UNITS_SYSTEMS_SI_LITERALS_LENGTH_HPP

#include <boost/units/detail/literals.hpp>
#include <boost/units/systems/si/length.hpp>

BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _ym, si::length, -24)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _zm, si::length, -21)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _am, si::length, -18)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _fm, si::length, -15)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _pm, si::length, -12)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _nm, si::length,  -9)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _um, si::length,  -6)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _mm, si::length,  -3)
BOOST_UNITS_DEFINE_LITERAL(si, _m, si::length)        // 0
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _km,  si::length,  3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Mm,  si::length,  6)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Gm,  si::length,  9)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Tm,  si::length, 12)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Pm,  si::length, 15)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Em,  si::length, 18)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Zm,  si::length, 21)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Ym,  si::length, 24)

#endif // BOOST_UNITS_SYSTEMS_SI_LITERALS_LENGTH_HPP
