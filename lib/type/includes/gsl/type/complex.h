/* complex/gsl_complex.h
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman, Brian Gough
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

#include <array>
#include <cmath>
#include <iostream>

namespace gsl::type {
/* two consecutive built-in types as a complex number */

template <typename T>
class complex_base {
 private:
  struct polar_t {};
  struct rect_t {};

 public:
  using el_type = T;
  using self_type = complex_base<el_type>;
  using packed_type = std::array<el_type, 2>;
  using const_packed_type = const packed_type;

  constexpr static polar_t polar{};
  constexpr static rect_t rect{};

 private:
  packed_type data;

 public:
  constexpr complex_base() : data{0, 0} {}
  constexpr complex_base(polar_t, el_type mag, el_type rads)
      : data{mag * cos(rads), mag * sin(rads)} {}
  constexpr complex_base(rect_t, el_type r, el_type i) : data{r, i} {}
  constexpr complex_base(el_type r, el_type i) : data{r, i} {}
  constexpr complex_base(rect_t, el_type r) : data{r, 0} {}
  constexpr complex_base(el_type r) : data{r, 0} {}

  constexpr el_type real() const { return std::get<0>(data); }
  constexpr el_type img() const { return std::get<1>(data); }
  constexpr el_type& real() { return std::get<0>(data); }
  constexpr el_type& img() { return std::get<1>(data); }

  constexpr auto operator==(const self_type& rhs) const {
    return data == rhs.data;
  }

  constexpr el_type norm() const { return real() * real() + img() * img(); }

  constexpr el_type angle_in_rads() const { return atan2(img(), real()); }

  constexpr el_type dist() const { return sqrt(norm()); }

  constexpr self_type congugate() const { return self_type{real(), 0 - img()}; }

  constexpr self_type inverse() const { return congugate() / norm(); }

  constexpr self_type neg() const { return {0 - real(), 0 - img()}; }

  constexpr self_type operator+(const self_type& rhs) const {
    return {real() + rhs.real(), img() + rhs.img()};
  }

  constexpr self_type operator+(el_type rhs) const {
    return self_type{real() + rhs, img()};
  }
  friend constexpr self_type operator+(el_type lhs, const self_type& rhs) {
    return rhs.operator+(lhs);
  }

  constexpr self_type operator-(const self_type& rhs) const {
    return self_type{real() - rhs.real(), img() - rhs.img()};
  }

  constexpr self_type operator-(el_type rhs) const {
    return self_type{real() - rhs, img()};
  }

  friend constexpr self_type operator-(el_type lhs, const self_type& rhs) {
    return self_type{lhs - rhs.real(), 0 - rhs.img()};
  }

  constexpr self_type operator*(const self_type& rhs) const {
    return self_type{real() * rhs.real() - img() * rhs.img(),
                     real() * rhs.img() + img() * rhs.real()};
  }

  constexpr self_type operator*(el_type rhs) const {
    return self_type{rhs * real(), rhs * img()};
  }

  friend constexpr self_type operator*(el_type lhs, const self_type& rhs) {
    return rhs.operator*(lhs);
  }

  constexpr self_type operator/(const self_type& rhs) const {
    return this->operator*(rhs.inverse());
  }

  constexpr self_type operator/(el_type rhs) const {
    return self_type{real() / rhs, img() / rhs};
  }

  friend constexpr self_type operator/(el_type lhs, const self_type& rhs) {
    return lhs * rhs.inverse();
  }

  friend constexpr auto dist(const self_type& lhs, const self_type& rhs) {
    return (lhs - rhs).dist();
  }

  friend auto& operator<<(std::ostream& out, const self_type& v) {
    out << v.real();
    if (v.img() > 0) {
      out << "+" << v.img() << 'i';
    } else if (v.img() < 0) {
      out << v.img() << 'i';
    }
    return out;
  }

  constexpr static self_type ONE{1.0, 0};
  constexpr static self_type ZERO{0.0, 0};
  constexpr static self_type NEG_ONE{-1.0, 0};
  constexpr static self_type I{0, 1};
  constexpr static self_type NEG_I{0, -1};
};

using complex_long_double = complex_base<long double>;
using complex = complex_base<double>;
using complex_float = complex_base<float>;

}  // namespace gsl::type