#pragma once

#include <gsl/math/complex.h>

#define FN(x) "gsl::math::" #x, gsl::math::x

#define FN2(x) #x, x
#define ARG(x, y) x, y
#define RES(x, y) x, y