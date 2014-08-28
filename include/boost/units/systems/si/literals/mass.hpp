// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Marek Kurdej
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEMS_SI_LITERALS_MASS_HPP
#define BOOST_UNITS_SYSTEMS_SI_LITERALS_MASS_HPP

#include <boost/units/detail/literals.hpp>
#include <boost/units/systems/si/mass.hpp>

// mass unit, kilogram is special, because base unit is already scaled
// since 1 kg = 10^3 g, so exponent - 3
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _yg, si::mass, -24 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _zg, si::mass, -21 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _ag, si::mass, -18 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _fg, si::mass, -15 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _pg, si::mass, -12 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _ng, si::mass,  -9 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _ug, si::mass,  -6 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _mg, si::mass,  -3 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _g,  si::mass,   0 - 3)
BOOST_UNITS_DEFINE_LITERAL(si, _kg, si::mass)       // 3 - 3
// no Mg, Gg, ... literals, tonnes (t) instead
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _t,   si::mass,  6 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _kt,  si::mass,  9 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Mt,  si::mass, 12 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Gt,  si::mass, 15 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Tt,  si::mass, 18 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Pt,  si::mass, 21 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Et,  si::mass, 24 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Zt,  si::mass, 27 - 3)
BOOST_UNITS_DEFINE_SCALED_LITERAL(si, _Yt,  si::mass, 30 - 3)

#endif // BOOST_UNITS_SYSTEMS_SI_LITERALS_MASS_HPP
