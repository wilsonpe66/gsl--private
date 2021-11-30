/* gsl_math.h
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2004 Gerard Jungman, Brian Gough
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

namespace gsl::constant::math {

constexpr auto E = 2.71828182845904523536028747135; /* e */

constexpr auto LOG2E = 1.44269504088896340735992468100; /* log_2 (e) */

constexpr auto LOG10E = 0.43429448190325182765112891892; /* log_10 (e) */

constexpr auto SQRT2 = 1.41421356237309504880168872421; /* sqrt(2) */

constexpr auto SQRT1_2 = 0.70710678118654752440084436210; /* sqrt(1/2) */

constexpr auto SQRT3 = 1.73205080756887729352744634151; /* sqrt(3) */

constexpr auto PI = 3.14159265358979323846264338328; /* pi */

constexpr auto TAO = 2 * PI; /* 2pi */

constexpr auto PI_2 = 1.57079632679489661923132169164; /* pi/2 */

constexpr auto PI_4 = 0.78539816339744830961566084582; /* pi/4 */

constexpr auto SQRTPI = 1.77245385090551602729816748334; /* sqrt(pi) */

constexpr auto TWO_DIV_SQRTPI =
    1.12837916709551257389615890312; /* 2/sqrt(pi) */

constexpr auto ONE_DIV_PI = 0.31830988618379067153776752675; /* 1/pi */

constexpr auto TWO_DIV_PI = 0.63661977236758134307553505349; /* 2/pi */

constexpr auto LN10 = 2.30258509299404568401799145468; /* ln(10) */

constexpr auto LN2 = 0.69314718055994530941723212146; /* ln(2) */

constexpr auto LNPI = 1.14472988584940017414342735135; /* ln(pi) */

constexpr auto EULER = 0.57721566490153286060651209008; /* Euler constant */

}  // namespace gsl::constant::math