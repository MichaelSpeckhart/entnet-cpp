#pragma once

#ifndef COMPLEX_TYPES_H
#define COMPLEX_TYPES_H

#include <complex>
#include <type_traits>


/// @brief Typedefing complex types
typedef std::complex<double> complex_double;
typedef std::complex<float> complex_float;
typedef std::complex<int> complex_int;

/// @brief 
/// @tparam _Tp 
template <typename _Tp>
struct is_complex : std::false_type {};

template <typename _Tp>
struct is_complex<std::complex<_Tp>> : std::false_type {};

template <typename _Tp>
constexpr bool is_complex_v = is_complex<_Tp>::value;



#endif