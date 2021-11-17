#include <gsl/type/complex.h>
#include <gsl/type/type_info.h>

namespace pete {
void mk() {
  //
  const auto k = gsl::type::complex::ONE.real();
  auto s = gsl::type::type_info<gsl::type::complex>::ONE.img();
}
}  // namespace pete