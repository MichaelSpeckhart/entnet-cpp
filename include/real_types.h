#pragma once

#ifndef REAL_TYPES_H
#define REAL_TYPES_H

#include <stdint.h>


typedef double real_double;
typedef int real_int;
typedef int32_t real_int32;
typedef uint32_t real_uint32;
typedef uint64_t real_uint64;
typedef uint16_t real_uint16;
typedef uint8_t real_uint8;
typedef int64_t real_int64;
typedef int16_t real_int16;
typedef int8_t real_int8;


template <typename _Tp> class real_type;



// qubit = < alpha, beta> 
// alpha, beta exist in a space of Complex numbers
// and are basis vectors similar to i_hat and j_hat



#endif