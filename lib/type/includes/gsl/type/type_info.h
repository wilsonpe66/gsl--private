#pragma once

#include <gsl/gsl_machine.h>
#include <gsl/type/complex.h>

namespace gsl::type {

template <typename T>
struct type_info {};

template <>
struct type_info<complex_long_double> {
  using ELEMENT_TYPE = complex_long_double;
  using SHORT = complex_long_double;
  using SHORT_REAL = long double;
  using ATOMIC = SHORT_REAL;
  using ATOMIC_IO = ATOMIC;
  static constexpr auto uses_long_double = true;
  static constexpr auto multiplicity = 2;
  static constexpr auto is_using_floating_point = true;
  static constexpr auto input_format = "%Lg";
  static constexpr auto output_format = "%Lg";
  static constexpr ELEMENT_TYPE ZERO = ELEMENT_TYPE::ZERO;
  static constexpr ELEMENT_TYPE ONE = ELEMENT_TYPE::ONE;
  static constexpr auto BASE_EPSILON = GSL_DBL_EPSILON;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<complex> {
  using ELEMENT_TYPE = complex;
  using SHORT = complex;
  using SHORT_REAL = double;
  using ATOMIC = SHORT_REAL;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 2;
  static constexpr auto is_using_floating_point = true;
  static constexpr auto input_format = "%lg";
  static constexpr auto output_format = "%lg";
  static constexpr ELEMENT_TYPE ZERO = ELEMENT_TYPE::ZERO;
  static constexpr ELEMENT_TYPE ONE = ELEMENT_TYPE::ONE;
  static constexpr auto BASE_EPSILON = GSL_DBL_EPSILON;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<complex_float> {
  using ELEMENT_TYPE = complex_float;
  using SHORT = complex_float;
  using SHORT_REAL = float;
  using ATOMIC = SHORT_REAL;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 2;
  static constexpr auto is_using_floating_point = true;
  static constexpr auto input_format = "%g";
  static constexpr auto output_format = "%g";
  static constexpr ELEMENT_TYPE ZERO = ELEMENT_TYPE::ZERO;
  static constexpr ELEMENT_TYPE ONE = ELEMENT_TYPE::ONE;
  static constexpr auto BASE_EPSILON = GSL_FLT_EPSILON;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<long double> {
  using ELEMENT_TYPE = long double;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = true;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = true;
  static constexpr auto input_format = "%Lg";
  static constexpr auto output_format = "%Lg";
  static constexpr ELEMENT_TYPE ZERO = 0.0L;
  static constexpr ELEMENT_TYPE ONE = 1.0L;
  static constexpr auto BASE_EPSILON = GSL_DBL_EPSILON;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<double> {
  using ELEMENT_TYPE = double;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = true;
  static constexpr auto input_format = "%lg";
  static constexpr auto output_format = "%lg";
  static constexpr ELEMENT_TYPE ZERO = 0.0;
  static constexpr ELEMENT_TYPE ONE = 1.0;
  static constexpr auto BASE_EPSILON = GSL_DBL_EPSILON;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<float> {
  using ELEMENT_TYPE = float;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = true;
  static constexpr auto input_format = "%g";
  static constexpr auto output_format = "%g";
  static constexpr ELEMENT_TYPE ZERO = 0.0F;
  static constexpr ELEMENT_TYPE ONE = 1.0F;
  static constexpr auto BASE_EPSILON = GSL_FLT_EPSILON;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<unsigned long> {
  using ELEMENT_TYPE = unsigned long;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%lu";
  static constexpr auto output_format = "%lu";
  static constexpr auto ZERO = 0UL;
  static constexpr auto ONE = 1UL;
  static constexpr auto is_unsigned = true;
};

template <>
struct type_info<long> {
  using ELEMENT_TYPE = long;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%ld";
  static constexpr auto output_format = "%ld";
  static constexpr auto ZERO = 0L;
  static constexpr auto ONE = 1L;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<unsigned int> {
  using ELEMENT_TYPE = unsigned int;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%u";
  static constexpr auto output_format = "%u";
  static constexpr auto ZERO = 0U;
  static constexpr auto ONE = 1U;
  static constexpr auto is_unsigned = true;
};

template <>
struct type_info<int> {
  using ELEMENT_TYPE = int;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto MULTILICITY = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%d";
  static constexpr auto output_format = "%d";
  static constexpr auto ZERO = 0;
  static constexpr auto ONE = 1;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<short> {
  using ELEMENT_TYPE = short;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto MULTILICITY = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%d";
  static constexpr auto output_format = "%d";
  static constexpr auto ZERO = 0;
  static constexpr auto ONE = 1;
  static constexpr auto is_unsigned = false;
};

template <>
struct type_info<unsigned short> {
  using ELEMENT_TYPE = unsigned short;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = ATOMIC;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%u";
  static constexpr auto output_format = "%u";
  static constexpr auto ZERO = 0U;
  static constexpr auto ONE = 1U;
  static constexpr auto is_unsigned = true;
};

template <>
struct type_info<unsigned char> {
  using ELEMENT_TYPE = unsigned char;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = unsigned int;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%u";
  static constexpr auto output_format = "%u";
  static constexpr auto ZERO = 0U;
  static constexpr auto ONE = 1U;
  static constexpr auto is_unsigned = true;
};

template <>
struct type_info<char> {
  using ELEMENT_TYPE = char;
  using SHORT = ELEMENT_TYPE;
  using ATOMIC = ELEMENT_TYPE;
  using ATOMIC_IO = int;

  static constexpr auto uses_long_double = false;
  static constexpr auto multiplicity = 1;
  static constexpr auto is_using_floating_point = false;
  static constexpr auto input_format = "%d";
  static constexpr auto output_format = "%d";
  static constexpr auto ZERO = 0;
  static constexpr auto ONE = 1;
  static constexpr auto is_unsigned = false;
};

}  // namespace gsl::type
