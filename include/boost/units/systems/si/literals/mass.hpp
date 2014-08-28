// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Marek Kurdej
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP
#define BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP

#include <boost/units/config.hpp>

#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/prefixes.hpp>

#define BOOST_UNITS_DEFINE_HELPER(namespace_, suffix, dimension, exponent)          \
namespace boost { namespace units { namespace namespace_ { namespace literals {     \
                                                            \
quantity<                                                   \
    make_scaled_unit<dimension, scale<10, static_rational<exponent> > >::type,      \
    unsigned long long                                      \
>                                                           \
operator"" suffix(unsigned long long value)                 \
{                                                           \
    typedef quantity<                                       \
        make_scaled_unit<dimension, scale<10, static_rational<exponent> > >::type,  \
        unsigned long long                                  \
    > type;                                                 \
    return type::from_value(value);                         \
}                                                           \
                                                            \
quantity<                                                   \
    make_scaled_unit<dimension, scale<10, static_rational<exponent> > >::type,      \
    long double                                             \
>                                                           \
operator"" suffix(long double value)                        \
{                                                           \
    typedef quantity<                                       \
        make_scaled_unit<dimension, scale<10, static_rational<exponent> > >::type,  \
        long double                                         \
    > type;                                                 \
    return type::from_value(value);                         \
}                                                           \
                                                            \
}}}} // namespace boost::units::namespace_::literals

// BOOST_UNITS_DEFINE_HELPER(si, _ng, si::mass, -12)
// BOOST_UNITS_DEFINE_HELPER(si, _ug, si::mass, -9)
// BOOST_UNITS_DEFINE_HELPER(si, _mg, si::mass, -6)
// BOOST_UNITS_DEFINE_HELPER(si, _g,  si::mass, -3)
// BOOST_UNITS_DEFINE_HELPER(si, _kg, si::mass, 0)

#undef BOOST_UNITS_DEFINE_HELPER

namespace boost {
namespace units {
namespace si {
namespace literals {

// _g
quantity<
    make_scaled_unit<si::mass, scale<10, static_rational<-3> > >::type,
    unsigned long long
>
operator"" _g(unsigned long long value)
{
    typedef quantity<
        make_scaled_unit<si::mass, scale<10, static_rational<-3> > >::type,
        unsigned long long
    > type;
    return type::from_value(value);
}

quantity<
    make_scaled_unit<si::mass, scale<10, static_rational<-3> > >::type,
    long double
>
operator"" _g(long double value)
{
    typedef quantity<
        make_scaled_unit<si::mass, scale<10, static_rational<-3> > >::type,
        long double
    > type;
    return type::from_value(value);
}

// _kg
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

} // namespace literals
} // namespace si
} // namespace units
} // namespace boost

#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS

#endif // BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP
