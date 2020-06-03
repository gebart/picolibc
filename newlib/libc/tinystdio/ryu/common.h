// Copyright 2018 Ulf Adams
//
// The contents of this file may be used under the terms of the Apache License,
// Version 2.0.
//
//    (See accompanying file LICENSE-Apache or copy at
//     http://www.apache.org/licenses/LICENSE-2.0)
//
// Alternatively, the contents of this file may be used under the terms of
// the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE-Boost or copy at
//     https://www.boost.org/LICENSE_1_0.txt)
//
// Unless required by applicable law or agreed to in writing, this software
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.
#ifndef RYU_COMMON_H
#define RYU_COMMON_H

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define assert(x)
//#include <assert.h>

#if defined(_M_IX86) || defined(_M_ARM)
#define RYU_32_BIT_PLATFORM
#endif

// Returns e == 0 ? 1 : [log_2(5^e)]; requires 0 <= e <= 3528.
int32_t __log2pow5(const int32_t e);

#define log2pow5(e) __log2pow5(e)

// Returns e == 0 ? 1 : ceil(log_2(5^e)); requires 0 <= e <= 3528.
int32_t __ceil_log2pow5(const int32_t e);

#define ceil_log2pow5(e) __ceil_log2pow5(e)

// Returns e == 0 ? 1 : ceil(log_2(5^e)); requires 0 <= e <= 3528.
int32_t __pow5bits(const int32_t e);

#define pow5bits(e) __pow5bits(e)

// Returns floor(log_10(2^e)); requires 0 <= e <= 1650.
uint32_t __log10Pow2(const int32_t e);

#define log10Pow2(e) __log10Pow2(e)

// Returns floor(log_10(5^e)); requires 0 <= e <= 2620.
uint32_t __log10Pow5(const int32_t e);

#define log10Pow5(e) __log10Pow5(e)

static inline uint32_t float_to_bits(const float f) {
  uint32_t bits = 0;
  memcpy(&bits, &f, sizeof(float));
  return bits;
}

static inline uint64_t double_to_bits(const double d) {
  uint64_t bits = 0;
  memcpy(&bits, &d, sizeof(double));
  return bits;
}

// These tables are generated by PrintDoubleLookupTable.
#define DOUBLE_POW5_INV_BITCOUNT 125
#define DOUBLE_POW5_BITCOUNT 125

void __double_computePow5(const uint32_t i, uint64_t* const result);

void __double_computeInvPow5(const uint32_t i, uint64_t* const result);

#endif // RYU_COMMON_H
