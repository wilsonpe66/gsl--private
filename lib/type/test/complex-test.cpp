#include <gsl/type/complex.h>
#include <gtest/gtest.h>

#include <iostream>

using gsl::type::complex;

constexpr auto PI = 3.1415926535897932384626433832795L;

#define MESSAGE(v) std::cout << "MESSAGE: " << #v << " => " << (v) << "\n";
#define EXPECT_EQ_DBL(a, b) EXPECT_TRUE(abs((a) - (b)) < 1e-15)

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

#define EXPECT_STATUS_POLAR(v, real_exp, img_exp)             \
  {                                                           \
    const double img_vp = (img_exp);                          \
    const double real_vp = (real_exp);                        \
    EXPECT_STATUS_RECT(v, real_vp, img_vp);                   \
    EXPECT_EQ_DBL(v.angle_in_rads(), atan2(img_vp, real_vp)); \
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