/* complex/complex_math.h
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2004 Jorma Olavi T�htinen, Brian
 * Gough
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */

#pragma once

#include <gsl/constant/machine.h>
#include <gsl/constant/math.h>
#include <gsl/type/complex.h>

#include <cmath>

namespace gsl::math {

// template <typename T=double>
using gsl::type::complex;
using gsl::type::complex_base;

constexpr auto COMPLEX_ONE = complex::ONE;
constexpr auto COMPLEX_ZERO = complex::ZERO;
constexpr auto COMPLEX_NEGONE = complex::NEG_ONE;

/* Properties of complex numbers */

template <typename T = double>
constexpr auto arg(const complex_base<T> &z) {
  return z.angle_in_rads();
} /* return arg(z), -pi< arg(z) <=+pi */

template <typename T = double>
constexpr auto abs(const complex_base<T> &z) {
  return z.dist();
} /* return |z|   */

template <typename T = double>
constexpr auto abs2(const complex_base<T> &z) {
  return z.norm();
} /* return |z|^2 */

template <typename T = double>
constexpr auto logabs(const complex_base<T> &z) {
  return log(z.dist());
} /* return log|z| */

/* Complex arithmetic operators */

template <typename T = double>
constexpr auto add(const complex_base<T> &a, const complex_base<T> &b) {
  return a + b;
} /* r=a+b */

template <typename T = double>
constexpr auto sub(const complex_base<T> &a, const complex_base<T> &b) {
  return a - b;
} /* r=a-b */

template <typename T = double>
constexpr auto mul(const complex_base<T> &a, const complex_base<T> &b) {
  return a * b;
} /* r=a*b */

template <typename T = double>
constexpr auto div(const complex_base<T> &a, const complex_base<T> &b) {
  return a / b;
} /* r=a/b */

template <typename T = double>
constexpr auto add_real(const complex_base<T> &a, const T &b) {
  return a + b;
} /* r=a+b */

template <typename T = double>
constexpr auto sub_real(const complex_base<T> &a, const T &b) {
  return a - b;
} /* r=a-b */

template <typename T = double>
constexpr auto mul_real(const complex_base<T> &a, const T &b) {
  return a * b;
} /* r=a*b */

template <typename T = double>
constexpr auto div_real(const complex_base<T> &a, const T &b) {
  return a / b;
} /* r=a/b */

template <typename T = double>
constexpr auto add_imag(const complex_base<T> &a, const T &b) {
  return a + complex_base<T>{0, b};
} /* r=a+b */

template <typename T = double>
constexpr auto sub_imag(const complex_base<T> &a, const T &b) {
  return a + complex_base<T>{0, -b};
} /* r=a-b */

template <typename T = double>
constexpr auto mul_imag(const complex_base<T> &a, const T &b) {
  return a * complex_base<T>{0, b};
} /* r=a*b */

template <typename T = double>
constexpr auto div_imag(const complex_base<T> &a, const T &b) {
  return a / complex_base<T>{0, b};
} /* r=a/b */

template <typename T = double>
constexpr auto conjugate(const complex_base<T> &z) {
  return z.congugate();
} /* r=conj(z) */

template <typename T = double>
constexpr auto inverse(const complex_base<T> &z) {
  return z.inverse();
} /* r=1/z */

template <typename T = double>
constexpr auto negative(const complex_base<T> &z) {
  return z.neg();
} /* r=-z */

/* Elementary Complex Functions */

template <typename T, typename K = complex_base<T>>
constexpr auto sqrt(const K &v) {
  return K(K::polar, ::sqrt(v.dist()), v.angle_in_rads() / 2.0);
}

template <typename T, typename K = complex_base<T>>
constexpr auto sqrt_real(const K &v) {
  return sqrt(v.real());
} /* r=sqrt(x) (x<0 ok) */

template <typename T, typename K = complex_base<T>>
constexpr auto pow(const K &v, const K &exponent) {
  // return K(K::polar, pow(v.dist(), exponent), exponent * v.angle_in_rads());
  const auto m = v.dist();
  const auto r = v.angle_in_rads();

  return K{
      K::polar,                                            //
      pow(m, exponent.real()) * exp(-r * exponent.img()),  //
      exponent.real() * r + exponent.img() * ln(m)         //
  };
} /* r=a^b  */

template <typename T, typename K = complex_base<T>>
constexpr auto pow_real(const K &v, T exponent) {
  return K(K::polar, pow(v.dist(), exponent), exponent * v.angle_in_rads());
} /* r=a^b  */

template <typename T, typename K = complex_base<T>>
constexpr auto exp(const K &a) {
  return K{K::polar, ::exp(a.real()), a.img()};
} /* r=exp(a) */

template <typename T, typename K = complex_base<T>>
auto log(const K &z) {
  return K{::log(z.dist()), z.angle_in_rads()};
} /* r=log(z) (base e) */

template <typename T, typename K = complex_base<T>>
auto log10(const K &z) {
  using gsl::constant::math::LN10;
  return K{::log(z.dist()) / LN10, z.angle_in_rads() / LN10};
} /* r=log10(z) (base 10) */

template <typename T, typename K = complex_base<T>>
constexpr auto log_b(const K &a, const K &b) {
  return K{0};

} /* r=log_b(a) (base=b) */

/* Complex Trigonometric Functions */

template <typename T, typename K = complex_base<T>>
constexpr auto sin(const K &a) {
  return K{::sin(a.real()) * ::cosh(a.img()),
           ::cos(a.real()) * ::sinh(a.img())};
} /* r=sin(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto cos(const K &a) {
  return K{::cos(a.real()) * ::cosh(a.img()),
           -::sin(a.real()) * ::sinh(a.img())};
} /* r=cos(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto sec(const K &a) {
  return 1 / sin<T>(a);
} /* r=sec(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto csc(const K &a) {
  return 1 / cos<T>(a);
} /* r=csc(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto tan(const K &a) {
  return sin<T>(a) / cos<T>(a);
} /* r=tan(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto cot(const K &a) {
  return cos<T>(a) / sin<T>(a);
} /* r=cot(a) */

/* Inverse Complex Trigonometric Functions */

template <typename T, typename K = complex_base<T>>
constexpr auto arcsin(const K &a) {
  return K::NEG_I * log<T>(a * K::I + (1 - a * a).sqrt());
} /* r=arcsin(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arcsin_real(double a) {
  return K{};
} /* r=arcsin(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccos(const K &a) {
  return K::NEG_I * log<T>(a + K::I * (1 - a * a).sqrt());
} /* r=arccos(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccos_real(double a) {
  return K{};
} /* r=arccos(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arcsec(const K &a) {
  return K{};
} /* r=arcsec(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arcsec_real(double a) {
  return K{};
} /* r=arcsec(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccsc(const K &a) {
  return K{};
} /* r=arccsc(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccsc_real(double a) {
  return K{};
} /* r=arccsc(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arctan(const K &a) {
  return K::NEG_I * log<T>((K::I - a) / (K::I + a)) / 2;
} /* r=arctan(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccot(const K &a) {
  return K::NEG_I * log<T>((K::I + a) / (K::I - a)) / 2;
} /* r=arccot(a) */

/* Complex Hyperbolic Functions */

template <typename T, typename K = complex_base<T>>
constexpr auto sinh(const K &a) {
  return K::NEG_I * sin<T>(a * K::I);
} /* r=sinh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto cosh(const K &a) {
  return cos<T>(a * K::I);
} /* r=coshh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto sech(const K &a) {
  return 1 / sinh<T>(a);
} /* r=sech(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto csch(const K &a) {
  return 1 / cosh<T>(a);
} /* r=csch(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto tanh(const K &a) {
  return sinh<T>(a) / cosh<T>(a);
} /* r=tanh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto coth(const K &a) {
  return cosh<T>(a) / sinh<T>(a);
} /* r=coth(a) */

/* Inverse Complex Hyperbolic Functions */

template <typename T, typename K = complex_base<T>>
constexpr auto arcsinh(const K &a) {
  return log<T>(a + (a * a + 1).sqrt());
} /* r=arcsinh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccosh(const K &a) {
  return log<T>(a + (a * a - 1).sqrt());
} /* r=arccosh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccosh_real(double a) {
  return K{};
} /* r=arccosh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arcsech(const K &a) {
  return K{};
} /* r=arcsech(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccsch(const K &a) {
  return K{};
} /* r=arccsch(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arctanh(const K &a) {
  return log<T>((1 + a) / (1 - a)) / 2;
} /* r=arctanh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arctanh_real(double a) {
  return K{};
} /* r=arctanh(a) */

template <typename T, typename K = complex_base<T>>
constexpr auto arccoth(const K &a) {
  return K{};
} /* r=arccoth(a) */

}  // namespace gsl::math