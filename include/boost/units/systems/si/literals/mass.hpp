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

#define BOOST_UNITS_DEFINE_HELPER(namespace_, suffix_, dimension_)  \
namespace boost { namespace units {                         \
namespace namespace_ { namespace literals {                 \
                                                            \
quantity<dimension_, unsigned long long>                    \
operator"" suffix_(unsigned long long value)                \
{                                                           \
    typedef quantity<dimension_, unsigned long long> type;  \
    return type::from_value(value);                         \
}                                                           \
                                                            \
quantity<dimension_, long double>                           \
operator"" suffix_(long double value)                       \
{                                                           \
    typedef quantity<dimension_, long double> type;         \
    return type::from_value(value);                         \
}                                                           \
                                                            \
}}}} // namespace boost::units::namespace_::literals

#define BOOST_UNITS_DEFINE_HELPER_SCALED(namespace_, suffix_, dimension_, exponent_)    \
    BOOST_UNITS_DEFINE_HELPER(                              \
        namespace_,                                         \
        suffix_,                                            \
        make_scaled_unit<                                   \
            dimension_ BOOST_PP_COMMA()                     \
            scale<                                          \
                10 BOOST_PP_COMMA()                         \
                static_rational<exponent_>                  \
            >                                               \
        >::type                                             \
    )

// mass unit - kilogram - is special - base unit is already scaled as 10^3
BOOST_UNITS_DEFINE_HELPER_SCALED(si, _ng, si::mass, -9 - 3)
BOOST_UNITS_DEFINE_HELPER_SCALED(si, _ug, si::mass, -6 - 3)
BOOST_UNITS_DEFINE_HELPER_SCALED(si, _mg, si::mass, -3 - 3)
BOOST_UNITS_DEFINE_HELPER_SCALED(si, _g,  si::mass,  0 - 3)
BOOST_UNITS_DEFINE_HELPER(si, _kg, si::mass)

#undef BOOST_UNITS_DEFINE_HELPER
#undef BOOST_UNITS_DEFINE_HELPER_SCALED

#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS

#endif // BOOST_UNITS_SYSTEMS_SI_UDL_MASS_HPP
