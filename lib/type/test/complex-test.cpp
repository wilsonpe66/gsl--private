#include <gsl/constant/machine.h>
#include <gsl/constant/math.h>
#include <gsl/type/complex.h>
#include <gtest/gtest.h>

#include <iostream>

using gsl::constant::math::PI;

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
  if (diff >= e) {
    std::cout << "\tdiff=" << diff << ", testValue=" << testValue
              << ", expectedValue=" << expectedValue << ", e=" << e << "\n";
  }
  return diff < e;
}
#define EXPECT_EQ_DBL(a, b) EXPECT_TRUE(abs((a) - (b)) < 1e-15L)

constexpr double angle_in_rads(auto img, auto real) {
  using gsl::constant::math::PI;
  using gsl::constant::math::PI_2;
  if (real == 0 && img == 0) return 0;

  return atan2(img, real);
}

#define EXPECT_STATUS_RECT(v, real_exp, img_exp)      \
  {                                                   \
    const double img_v = (img_exp);                   \
    const double real_v = (real_exp);                 \
    const double n = img_v * img_v + real_v * real_v; \
    EXPECT_EQ_DBL(v.real(), real_v);                  \
    EXPECT_EQ_DBL(v.img(), img_v);                    \
    EXPECT_EQ_DBL(v.norm(), n);                       \
    EXPECT_EQ_DBL(v.dist(), sqrt(n));                 \
  }

#define EXPECT_STATUS_POLAR(v, real_exp, img_exp)                         \
  {                                                                       \
    const double img_vp = (img_exp);                                      \
    const double real_vp = (real_exp);                                    \
    EXPECT_STATUS_RECT(v, real_vp, img_vp);                               \
    EXPECT_EQ_REL_DBL(v.angle_in_rads(), angle_in_rads(img_vp, real_vp)); \
  }

TEST(GSLTypeComplex, ConstantsTest) {
  {
    const auto v = complex::ONE;
    EXPECT_STATUS_POLAR(v, 1, 0);
  }

  {
    const auto v = complex::NEG_ONE;
    EXPECT_STATUS_POLAR(v, -1, 0);
  }

  {
    const auto v = complex::ZERO;
    EXPECT_STATUS_POLAR(v, 0, 0);
  }

  {
    const auto v = complex::I;
    EXPECT_STATUS_POLAR(v, 0, 1);
  }
}
TEST(GSLTypeComplex, DefaultConstructorsTest) {
  {
    const complex v;
    EXPECT_STATUS_POLAR(v, 0, 0);
  }
}

TEST(GSLTypeComplex, ComplexRectConstructorsTest) {
  {
    const complex v{-2};
    EXPECT_STATUS_POLAR(v, -2, 0);
  }

  {
    const complex v{complex::rect, -2};
    EXPECT_STATUS_POLAR(v, -2, 0);
  }

  {
    const complex v{-2, 3};
    EXPECT_STATUS_POLAR(v, -2, 3);
  }

  {
    const complex v{complex::rect, -2, 3};
    EXPECT_STATUS_RECT(v, -2, 3);
  }

  {
    const complex v{1, 0};
    EXPECT_STATUS_RECT(v, 1, 0);
  }

  {
    const complex v{complex::rect, 1, 0};
    EXPECT_STATUS_RECT(v, 1, 0);
  }

  {
    const complex v{0, 1};
    EXPECT_STATUS_RECT(v, 0, 1);
  }

  {
    const complex v{complex::rect, 0, 1};
    EXPECT_STATUS_RECT(v, 0, 1);
  }
}
TEST(GSLTypeComplex, ComplexPolarConstructorsTest) {
  {
    const complex v{complex::polar, 2, 0};
    EXPECT_STATUS_POLAR(v, 2, 0);
  }

  {
    const complex v{complex::polar, 2, PI / 2};
    EXPECT_STATUS_POLAR(v, 0, 2);
  }

  {
    const complex v{complex::polar, 2, PI};
    EXPECT_STATUS_POLAR(v, -2, 0);
  }

  {
    const complex v{complex::polar, 2, 3 * PI / 2};
    EXPECT_STATUS_POLAR(v, 0, -2);
  }

  {
    const complex v{complex::polar, 2, -PI / 2};
    EXPECT_STATUS_POLAR(v, 0, -2);
  }

  {
    const complex v{complex::polar, 2, PI / 4};
    EXPECT_STATUS_POLAR(v, 2 / sqrt(2), 2 / sqrt(2));
  }

  {
    const complex v{complex::polar, 2, 3 * PI / 4};
    EXPECT_STATUS_POLAR(v, -2 / sqrt(2), 2 / sqrt(2));
  }

  {
    const complex v{complex::polar, 2, 5 * PI / 4};
    EXPECT_STATUS_POLAR(v, -2 / sqrt(2), -2 / sqrt(2));
  }

  {
    const complex v{complex::polar, 2, 7 * PI / 4};
    EXPECT_STATUS_POLAR(v, 2 / sqrt(2), -2 / sqrt(2));
  }

  {
    const complex v{complex::polar, 2, -PI / 4};
    EXPECT_STATUS_POLAR(v, 2 / sqrt(2), -2 / sqrt(2));
  }

  {
    for (size_t i = 0; i < 10; i++) {
      const double r = (i - 5.0) * 0.3;
      const double t = 2.0 * PI * i / 5;
      const double x = r * cos(t), y = r * sin(t);
      const complex v{complex::polar, r, t};
      EXPECT_STATUS_POLAR(v, x, y);
    }
  }
}

TEST(GSLTypeComplex, CopyConstructorsTest) {
  {
    const complex v{-2, 3};
    const auto v2 = v;
    EXPECT_STATUS_RECT(v2, -2, 3);
  }
}

TEST(GSLTypeComplex, SetRealConstructorsTest) {
  {
    const complex v{-2, 3};
    auto v2 = v;
    v2.real() = 66;
    EXPECT_STATUS_RECT(v2, 66, 3);
  }
}

TEST(GSLTypeComplex, SetImgConstructorsTest) {
  {
    const complex v{-2, 3};
    auto v2 = v;
    v2.img() = 66;
    EXPECT_STATUS_RECT(v2, -2, 66);
  }
}

TEST(GSLTypeComplex, AngleTestTest) {
  {
    const complex v{8388608, -8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), -gsl::constant::math::PI / 4);
  }

  {
    const complex v{8388608, 8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), gsl::constant::math::PI / 4);
  }

  {
    const complex v{-8388608, -8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), -3 * gsl::constant::math::PI / 4);
  }

  {
    const complex v{-8388608, 8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), 3 * gsl::constant::math::PI / 4);
  }

  {
    const complex v{0, -8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), -gsl::constant::math::PI / 2);
  }

  {
    const complex v{0, 8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), gsl::constant::math::PI / 2);
  }

  {
    const complex v{-8388608, 0};
    EXPECT_EQ_DBL(v.angle_in_rads(), gsl::constant::math::PI);
  }

  {
    const complex v{8388608, 0};
    EXPECT_EQ_DBL(v.angle_in_rads(), 0);
  }

  {
    const complex v{1e-17, -8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), -gsl::constant::math::PI / 2);
  }

  {
    const complex v{1e-17, 8388608};
    EXPECT_EQ_DBL(v.angle_in_rads(), gsl::constant::math::PI / 2);
  }

  {
    const complex v{-8388608, 1e-17};
    EXPECT_EQ_DBL(v.angle_in_rads(), gsl::constant::math::PI);
  }

  {
    const complex v{8388608, 1e-17};
    EXPECT_EQ_DBL(v.angle_in_rads(), 0);
  }
}

TEST(GSLTypeComplex, ComplexCongugateTest) {
  {
    const complex v{-2, 3};
    const auto v2 = v.congugate();
    EXPECT_STATUS_RECT(v2, -2, -3);
  }

  {
    const complex v{1, 0};
    const auto v2 = v.congugate();
    EXPECT_STATUS_RECT(v2, 1, 0);
  }

  {
    const complex v{0, 1};
    const auto v2 = v.congugate();
    EXPECT_STATUS_RECT(v2, 0, -1);
  }
}

TEST(GSLTypeComplex, ComplexNegative) {
  {
    const complex v{-2, 3};
    const auto v2 = v.neg();
    EXPECT_STATUS_RECT(v2, 2, -3);
  }

  {
    const complex v{1, 0};
    const auto v2 = v.neg();
    EXPECT_STATUS_RECT(v2, -1, 0);
  }

  {
    const complex v{0, 1};
    const auto v2 = v.neg();
    EXPECT_STATUS_RECT(v2, 0, -1);
  }

  {
    const complex v{-2, 3};
    const auto v2 = -v;
    EXPECT_STATUS_RECT(v2, 2, -3);
  }

  {
    const complex v{1, 0};
    const auto v2 = -v;
    EXPECT_STATUS_RECT(v2, -1, 0);
  }

  {
    const complex v{0, 1};
    const auto v2 = -v;
    EXPECT_STATUS_RECT(v2, 0, -1);
  }
}

TEST(GSLTypeComplex, ComplexInverse) {
  {
    const complex v{-2, 3};
    const auto v2 = v.inverse();
    EXPECT_STATUS_RECT(v2, -2.0 / 13, -3.0 / 13);
  }

  {
    const complex v{1, 0};
    const auto v2 = v.inverse();
    EXPECT_STATUS_RECT(v2, 1, 0);
  }

  {
    const complex v{0, 1};
    const auto v2 = v.inverse();
    EXPECT_STATUS_RECT(v2, 0, -1);
  }
}

TEST(GSLTypeComplex, ComplexPlusTest) {
  {
    const complex v{4, 9};
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v + v2), 9, 20);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v + v2), 1, 1);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), 1, 0);
  }

  {
    const complex v{-1, 0};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), -1, 0);
  }

  {
    const complex v{0, 1};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), 0, 1);
  }

  {
    const complex v{0, -1};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), 0, -1);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v + v2), 9, 11);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v + v2), 1, 1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), 1, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), -1, 0);
  }

  {
    const double v = 0;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v + v2), 0, 0);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v2 + v), 9, 11);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v2 + v), 1, 1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 + v), 1, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 + v), -1, 0);
  }

  {
    const double v = 0;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 + v), 0, 0);
  }
}

TEST(GSLTypeComplex, ComplexMinusTest) {
  {
    const complex v{4, 9};
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v - v2), -1, -2);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v - v2), 1, -1);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), 1, 0);
  }

  {
    const complex v{-1, 0};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), -1, 0);
  }

  {
    const complex v{0, 1};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), 0, 1);
  }

  {
    const complex v{0, -1};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), 0, -1);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v - v2), -1, -11);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v - v2), 1, -1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), 1, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), -1, 0);
  }

  {
    const double v = 0;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v - v2), 0, 0);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v2 - v), 1, 11);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v2 - v), -1, 1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 - v), -1, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 - v), 1, 0);
  }

  {
    const double v = 0;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 - v), 0, 0);
  }
}

TEST(GSLTypeComplex, ComplexMultTest) {
  {
    const complex v{4, 9};
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v * v2), -79, 89);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v * v2), 0, 1);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const complex v{-1, 0};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const complex v{0, 1};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const complex v{0, -1};
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v * v2), 20, 44);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v * v2), 0, 1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const double v = 0;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v * v2), 0, 0);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v2 * v), 20, 44);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v2 * v), 0, 1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 * v), 0, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 * v), 0, 0);
  }

  {
    const double v = 0;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 * v), 0, 0);
  }
}
TEST(GSLTypeComplex, ComplexDivTest) {
  {
    const complex v{4, 9};
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v / v2), 119 / 146.0, 1 / 146.0);
  }

  {
    const complex v{1, 0};
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v / v2), 0, -1);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v / v2), 20 / 146.0, -44 / 146.0);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v / v2), 0, -1);
  }

  {
    const double v = 4;
    const complex v2{5, 11};
    EXPECT_STATUS_RECT((v2 / v), 5.0 / 4, 11.0 / 4);
  }

  {
    const double v = 1;
    const complex v2{0, 1};
    EXPECT_STATUS_RECT((v2 / v), 0, 1);
  }

  {
    const double v = 1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 / v), 0, 0);
  }

  {
    const double v = -1;
    const complex v2{0, 0};
    EXPECT_STATUS_RECT((v2 / v), 0, 0);
  }
}

TEST(GSLTypeComplex, ComplexDistTest) {
  {
    const complex v{0, 1};
    const complex v2{1, 0};
    EXPECT_EQ_DBL(dist(v, v2), sqrt(2));
  }

  {
    const complex v{1, 1};
    const complex v2{1, 0};
    EXPECT_EQ_DBL(dist(v, v2), 1);
  }

  {
    const complex v{-1, 1};
    const complex v2{1, 0};
    EXPECT_EQ_DBL(dist(v, v2), sqrt(5));
  }
}