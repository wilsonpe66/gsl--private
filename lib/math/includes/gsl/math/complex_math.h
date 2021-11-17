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

#include <gsl/constant/math.h>
#include <gsl/type/complex.h>

namespace gsl::math {

template <typename T>
using gsl::type::complex_base<T>;

constexpr auto COMPLEX_ONE = complex.ONE;
constexpr auto COMPLEX_ZERO = complex::ZERO;
constexpr auto COMPLEX_NEGONE = complex::NEG_ONE;

// template <typename T, typename K = complex_base<T>>
// constexpr auto pow(const K& v, const K & exponent) {
//   return K(K::polar, pow(v.dist(), exponent), exponent * v.angle_in_rads());
// }

// __BEGIN_DECLS

// /* Complex numbers */

// gsl_complex gsl_complex_rect(double x, double y);      /* r= real+i*imag */
// gsl_complex gsl_complex_polar(double r, double theta); /* r= r e^(i theta) */

// #ifdef HAVE_INLINE
// extern inline gsl_complex gsl_complex_rect(double x,
//                                            double y) { /* return z = x + i y
//                                            */
//   gsl_complex z;
//   GSL_SET_COMPLEX(&z, x, y);
//   return z;
// }
// #endif

/* Properties of complex numbers */

template <typename T>
constexpr auto arg(const complex_base<T> &z) {
  return z.angle_in_rads();
} /* return arg(z), -pi< arg(z) <=+pi */

template <typename T>
constexpr auto abs(const complex_base<T> &z) {
  return z.dist();
} /* return |z|   */

template <typename T>
constexpr auto abs2(const complex_base<T> &z) {
  return z.norm();
} /* return |z|^2 */

template <typename T>
constexpr auto logabs(const complex_base<T> z) {
  return log(z.dist());
} /* return log|z| */

/* Complex arithmetic operators */

template <typename T>
constexpr auto add(const complex_base<T> &a, const complex_base<T> &b) {
  return a + b;
} /* r=a+b */

template <typename T>
constexpr auto sub(const complex_base<T> &a, const complex_base<T> &b) {
  return a - b;
} /* r=a-b */

template <typename T>
constexpr auto mul(const complex_base<T> &a, const complex_base<T> &b) {
  return a * b;
} /* r=a*b */

template <typename T>
constexpr auto div(const complex_base<T> &a, const complex_base<T> &b) {
  return a / b;
} /* r=a/b */

template <typename T>
constexpr auto add_real(const complex_base<T> &a, const T &b) {
  return a + b;
} /* r=a+b */

template <typename T>
constexpr auto sub_real(const complex_base<T> &a, const T &b) {
  return a - b;
} /* r=a-b */

template <typename T>
constexpr auto mul_real(const complex_base<T> &a, const T &b) {
  return a * b;
} /* r=a*b */

template <typename T>
constexpr auto div_real(const complex_base<T> &a, const T &b) {
  return a / b;
} /* r=a/b */

template <typename T>
constexpr auto add_imag(const complex_base<T> &a, const T &b) {
  return a + complex_base<T>{0, b};
} /* r=a+b */

template <typename T>
constexpr auto sub_imag(const complex_base<T> &a, const T &b) {
  return a + complex_base<T>{0, -b};
} /* r=a-b */

template <typename T>
constexpr auto mul_imag(const complex_base<T> &a, const T &b) {
  return a * complex_base<T>{0, b};
} /* r=a*b */

template <typename T>
constexpr auto div_imag(const complex_base<T> &a, const T &b) {
  return a / complex_base<T>{0, b};
} /* r=a/b */

template <typename T>
constexpr auto conjugate(const complex_base &z) {
  return z.congugate();
} /* r=conj(z) */

template <typename T>
constexpr auto conjugate(const complex_base &z) {
  return z.inverse();
} /* r=1/z */

template <typename T>
constexpr auto inverse(const complex_base &z) {
  return z.inverse();
} /* r=1/z */

template <typename T>
constexpr auto negative((const complex_base &z) {
  return z.neg();
} /* r=-z */

/* Elementary Complex Functions */


template <typename T, typename K = complex_base<T>>
constexpr auto sqrt(const K &v) {
  return K(K::polar, sqrt(v.dist()), v.angle_in_rads() / 2.0;);
}

template <typename T, typename K = complex_base<T>>
constexpr auto sqrt_real(const K &v) {
  return sqrt(v.real());
 } /* r=sqrt(x) (x<0 ok) */

template <typename T, typename K = complex_base<T>>
constexpr auto pow(const K &v, const K& exponent) {
  // return K(K::polar, pow(v.dist(), exponent), exponent * v.angle_in_rads());
  const auto m = v.dist();
  const auto r = v.angle_in_rads();

  return K{
      K::polar,                                     //
      pow(m, a) * exp(-r * exponent.img()),         //
      exponent.real() * r + exponent.img() * ln(m)  //
  };
} /* r=a^b  */

template <typename T, typename K = complex_base<T>>
constexpr auto pow_real(const K &v, T exponent) {
  return K(K::polar, pow_real(v.dist(), exponent),
           exponent * v.angle_in_rads());
} /* r=a^b  */

template <typename T, typename K = complex_base<T>>
constexpr auto pow_real(const K &v, T exponent) {
  return K(K::polar, pow_real(v.dist(), exponent),
           exponent * v.angle_in_rads());
} /* r=a^b  */

template <typename T, typename K = complex_base<T>>
constexpr auto exp(const K &a) {
  return K{K::polar, exp(a.real()), a.img()};
}   /* r=exp(a) */

template <typename T, typename K = complex_base<T>>
auto log(const K& z)
{
  return K{log(z.dist()), z.angle_in_rads()};
} /* r=log(z) (base e) */

  template <typename T, typename K = complex_base<T>>
auto log10(const K& z)
{
  using gsl::constant::math::LN10;
  return K{log(z.dist()) / LN10, z.angle_in_rads() / LN10};
} /* r=log10(z) (base 10) */

template<typename T, typename K=complex_base<T>>
constexpr auto log_b(const K &a,const K& b){
  return K{0};

} /* r=log_b(a) (base=b) */

/* Complex Trigonometric Functions */

template<typename T, typename K=complex_base<T>>
constexpr auto sin(const K& a){
  return K{};
} /* r=sin(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto cos(const K& a){
  return K{};
} /* r=cos(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto sec(const K& a){
  return K{};
} /* r=sec(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto csc(const K& a){
  return K{};
} /* r=csc(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto tan(const K& a){
  return K{};
} /* r=tan(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto cot(const K& a){
  return K{};
} /* r=cot(a) */

/* Inverse Complex Trigonometric Functions */

template<typename T, typename K=complex_base<T>>
constexpr auto arcsin(const K& a){
  return K{};
} /* r=arcsin(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arcsin_real(double a){
  return K{};
} /* r=arcsin(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccos(const K& a){
  return K{};
} /* r=arccos(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccos_real(double a){
  return K{};
} /* r=arccos(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arcsec(const K& a){
  return K{};
} /* r=arcsec(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arcsec_real(double a){
  return K{};
} /* r=arcsec(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccsc(const K& a){
  return K{};
} /* r=arccsc(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccsc_real(double a){
  return K{};
} /* r=arccsc(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arctan(const K& a){
  return K{};
} /* r=arctan(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccot(const K& a){
  return K{};
  } /* r=arccot(a) */

/* Complex Hyperbolic Functions */

template<typename T, typename K=complex_base<T>>
constexpr auto sinh(const K& a) {
  return K{};
} /* r=sinh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto cosh(const K& a) {
  return K{};
} /* r=coshh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto sech(const K& a) {
  return K{};
} /* r=sech(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto csch(const K& a) {
  return K{};
} /* r=csch(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto tanh(const K& a) {
  return K{};
} /* r=tanh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto coth(const K& a) {
  return K{};
} /* r=coth(a) */

/* Inverse Complex Hyperbolic Functions */

template<typename T, typename K=complex_base<T>>
constexpr auto arcsinh(const K& a) {
  return K{};
} /* r=arcsinh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccosh(const K& a) {
  return K{};
} /* r=arccosh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccosh_real(double a) {
  return K{};
} /* r=arccosh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arcsech(const K& a) {
  return K{};
} /* r=arcsech(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccsch(const K& a) {
  return K{};
} /* r=arccsch(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arctanh(const K& a) {
  return K{};
} /* r=arctanh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arctanh_real(double a) {
  return K{};
} /* r=arctanh(a) */

template<typename T, typename K=complex_base<T>>
constexpr auto arccoth(const K& a) {
  return K{};
} /* r=arccoth(a) */

}  // namespace gsl::math