// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Marek Kurdej
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DETAIL_LITERALS_HPP
#define BOOST_UNITS_DETAIL_LITERALS_HPP

#include <boost/units/config.hpp>

#ifndef BOOST_NO_CXX11_USER_DEFINED_LITERALS

#include <boost/units/make_scaled_unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/scale.hpp>

#define BOOST_UNITS_DEFINE_LITERAL(namespace_, suffix_, dimension_)  \
namespace boost { namespace units {                         \
namespace namespace_ { namespace literals {                 \
                                                            \
quantity<dimension_, long long>                             \
operator"" suffix_(unsigned long long value)                \
{                                                           \
    typedef quantity<dimension_, long long> type;           \
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

#define BOOST_UNITS_DEFINE_SCALED_LITERAL(namespace_, suffix_, dimension_, exponent_)    \
    BOOST_UNITS_DEFINE_LITERAL(                             \
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

#else // BOOST_NO_CXX11_USER_DEFINED_LITERALS

#define BOOST_UNITS_DEFINE_LITERAL(namespace_, suffix_, dimension_) /**/
#define BOOST_UNITS_DEFINE_SCALED_LITERAL(namespace_, suffix_, dimension_, exponent_) /**/

#endif // BOOST_NO_CXX11_USER_DEFINED_LITERALS

#endif // BOOST_UNITS_DETAIL_LITERALS_HPP
