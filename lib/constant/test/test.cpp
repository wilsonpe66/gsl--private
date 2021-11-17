/* const/test.cpp
 *
 * Copyright (C) 2003 Brian Gough
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

#include <gsl/constant/cgs.h>
#include <gsl/constant/cgsm.h>
#include <gsl/constant/mks.h>
#include <gsl/constant/mksa.h>
#include <gsl/constant/num.h>
#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>

#define MESSAGE(v) std::cout << "MESSAGE: " << #v << " => " << (v) << "\n";
#define EXPECT_EQ_REL_DBLE(a, b, e) \
  { EXPECT_TRUE(abs(1 - (a) / (b)) < (e)); }

#define EXPECT_EQ_REL_DBL(testValue, expectedValue) \
  EXPECT_EQ_REL_DBLE((testValue), (expectedValue), 1e-10)

TEST(GSLContant, ConstantsSpeedOfLightMKSTest) {
  const auto c = gsl::constant::mks::SPEED_OF_LIGHT;
  const auto eps = gsl::constant::mks::VACUUM_PERMITTIVITY;
  const auto mu = gsl::constant::mks::VACUUM_PERMEABILITY;

  EXPECT_EQ_REL_DBL(c, 1.0 / sqrt(eps * mu));
}

TEST(GSLContant, ConstantsLightYearCGSTest) {
  const auto ly = gsl::constant::cgs::LIGHT_YEAR;
  const auto c = gsl::constant::cgs::SPEED_OF_LIGHT;
  const auto y = 365.2425 * gsl::constant::cgs::DAY;

  EXPECT_EQ_REL_DBL(ly, c * y);
}

TEST(GSLContant, ConstantsSpeedOfLightMKSATest) {
  const auto c = gsl::constant::mksa::SPEED_OF_LIGHT;
  const auto eps = gsl::constant::mksa::VACUUM_PERMITTIVITY;
  const auto mu = gsl::constant::mksa::VACUUM_PERMEABILITY;

  EXPECT_EQ_REL_DBL(c, 1.0 / sqrt(eps * mu));
}

TEST(GSLContant, ConstantsLightYearCGSMTest) {
  const auto ly = gsl::constant::cgsm::LIGHT_YEAR;
  const auto c = gsl::constant::cgsm::SPEED_OF_LIGHT;
  const auto y = 365.2425 * gsl::constant::cgsm::DAY;

  EXPECT_EQ_REL_DBL(ly, c * y);
}

TEST(GSLContant, ConstantsWEIGTHSTest) {
  const double micro = gsl::constant::num::MICRO;
  const double mega = gsl::constant::num::MEGA;
  const double kilo = gsl::constant::num::KILO;

  EXPECT_EQ_REL_DBL(mega / kilo, 1 / (micro * kilo));
}

TEST(GSLContant, ConstantsDebyeESUTest) {
  const auto d = gsl::constant::mksa::DEBYE;
  const auto c = gsl::constant::mksa::SPEED_OF_LIGHT;
  const auto desu = d * c * 1000.0;

  EXPECT_EQ_REL_DBL(desu, 1e-18);
}

TEST(GSLContant, ConstantsStefanBoltzmannConstantTest) {
  const auto k = gsl::constant::mksa::BOLTZMANN;
  const auto c = gsl::constant::mksa::SPEED_OF_LIGHT;
  const auto h = gsl::constant::mksa::PLANCKS_CONSTANT_H;
  const auto s =
      2 * pow(M_PI, 5.0) * pow(k, 4.0) / (15 * pow(c, 2.0) * pow(h, 3.0));
  const auto sigma = gsl::constant::mksa::STEFAN_BOLTZMANN_CONSTANT;

  EXPECT_EQ_REL_DBL(s, sigma);
}
