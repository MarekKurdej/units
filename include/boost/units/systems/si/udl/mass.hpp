// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Marek Kurdej
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP_INCLUDED
#define BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP_INCLUDED

#include <boost/units/config.hpp>

#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/prefixes.hpp>

// #define BOOST_UNITS_UDL_DEFINE_SCALED(suffix, dimension, unit, prefix)

#define BOOST_UNITS_UDL_DEFINE(suffix, dimension, unit) \
namespace boost { namespace units { namespace udl { \
\
quantity<dimension, unsigned long long> \
operator"" suffix(unsigned long long value) \
{ \
    return (value) * (unit); \
} \
\
quantity<dimension, long double> \
operator"" suffix(long double value) \
{ \
   return (value) * (unit); \
} \
\
}}} // namespace boost::units::udl

// BOOST_UNITS_UDL_DEFINE(_g, si::mass, si::milli * si::kilogram)
// BOOST_UNITS_UDL_DEFINE_SCALED(_g, si::mass, si::kilogram, si::milli)
// BOOST_UNITS_UDL_DEFINE(_kg, si::mass, si::kilogram)

//    return quantity<dimension, unsigned long long>::from_value(value);
//    return quantity<dimension, long double>::from_value(value);
//    return value * unit();

namespace boost {
namespace units {
namespace si {
namespace udl {

// quantity<
    // make_scaled_unit<si::mass, scale<10, static_rational<-3> > >::type,
    // // make_scaled_unit<dimension, scale<10, static_rational<-3> > >::type,
    // unsigned long long
// >
// typename multiply_typeof_helper< quantity<si::mass, unsigned long long>, si::mass >::type
// operator"" _g(unsigned long long value)
// {
    // // typedef typename multiply_typeof_helper< quantity<unsigned long long, si::kilogram_instance_t>, si::milli >::type type;
    // return value * si::milli * si::kilogram;
    // // return type::from_value(value);
// }

quantity<si::mass, unsigned long long>
operator"" _kg(unsigned long long value)
{
    return value * si::kilogram;
}

quantity<si::mass, long double>
operator"" _kg(long double value)
{
    return value * si::kilogram;
}

} // namespace udl
} // namespace si
} // namespace units
} // namespace boost

#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS

#endif // BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP_INCLUDED
