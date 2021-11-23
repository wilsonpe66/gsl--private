/* complex/test.cpp
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Brian Gough
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

//#include <config.h>
#include <gsl/constant/math.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/math/complex.h>
#include <gsl/type/complex.h>
#include <gtest/gtest.h>

#include <array>
#include <cstdio>
#include <cstdlib>
#include <string_view>

// using gsl::constant::machine::DBL_EPSILON;
using gsl::math::abs;
using gsl::type::complex;

#define MESSAGE(v) std::cout << "MESSAGE: " << #v << " => " << (v) << "\n"
bool EXPECT_EQ_REL_DBL(const auto& testValue, const auto& expectedValue,
                       const double e = 1e-14) {
  if (testValue == expectedValue) {
    EXPECT_EQ(testValue, expectedValue);
    return true;
  }

  const auto diff = abs(1 - testValue / expectedValue);
  EXPECT_TRUE(diff < e);
  return diff < e;
}

#include "complex-data/results1.h"

TEST(GSLMathComplex, RealValuedFunctions) {
  for (const auto& function_to_test : list) {
    for (const auto& test : function_to_test.tests) {
      const auto f = function_to_test.func(test.arg);
      std::cout.precision(20);
      if (!EXPECT_EQ_REL_DBL(f, test.expected)) {
        std::cout << "testing " << function_to_test.name << " arg: " << test.arg
                  << " -> result: " << f << " ?? " << test.expected << "\n";
      }
    }
  }
}

#include "complex-data/results.h"

TEST(GSLMathComplex, RealValuedFunctions2) {
  for (const auto& function_to_test : listz) {
    for (const auto& test : function_to_test.tests) {
      const auto f = function_to_test.func(test.arg);
      std::cout.precision(20);
      if (!EXPECT_EQ_REL_DBL(f, test.expected)) {
        std::cout << "testing " << function_to_test.name << " arg: " << test.arg
                  << " -> result: " << f << " ?? " << test.expected << "\n";
      }
    }
  }
}

#include "complex-data/base.h"

struct freal {
  std::string_view name;
  complex (*f)(double x);
  double x;
  double fx;
  double fy;
};

// freal listreal[] = {
// #include "complex-data/results-real.h"
//     {"", 0, 0, 0, 0}};

// int main() {
//   gsl_ieee_env_setup();

//   {
//     size_t i = 0;

//     while (listz[i].f) {
//       struct fz t = listz[i];
//       const complex z = complex(t.x, t.y);
//       const complex fz = (t.f)(z);
//       const double fx = fz.real(), fy = fz.img();

// #ifdef DEBUG
//       std::cout << "x = " << t.x << "\n";
//       std::cout << "y = " << t.y << "\n";

//       std::cout << "fx = " << fx << "\n";
//       std::cout << "fy = " << fy << "\n";

//       std::cout << "ex = " << t.fx << "\n";
//       std::cout << "ey = " << t.fy << "\n";
// #endif

//       gsl_test_rel(fx, t.fx, 10 * DBL_EPSILON, "%s real part at (%g,%g)",
//                    t.name, t.x, t.y);
//       gsl_test_rel(fy, t.fy, 10 * DBL_EPSILON, "%s imag part at (%g,%g)",
//                    t.name, t.x, t.y);
//       i++;
//     }
//   }

//   {
//     size_t i = 0;

//     while (listreal[i].f) {
//       const freal t = listreal[i];
//       const complex fz = (t.f)(t.x);
//       const double fx = fz.real(), fy = fz.img();

// #ifdef DEBUG
//       std::cout << "x = " << t.x << "\n";

//       std::cout << "fx = " << fx << "\n";
//       std::cout << "fy = " << fy << "\n";

//       std::cout << "ex = " << t.fx << "\n";
//       std::cout << "ey = " << t.fy << "\n";
// #endif

//       gsl_test_rel(fx, t.fx, 10 * DBL_EPSILON, "%s real part at (%g,0)",
//       t.name,
//                    t.x);
//       gsl_test_rel(fy, t.fy, 10 * DBL_EPSILON, "%s imag part at (%g,0)",
//       t.name,
//                    t.x);
//       i++;
//     }
//   }

//   exit(gsl_test_summary());
// }
