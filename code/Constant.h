#ifndef CONSTANT_H
#define CONSTANT_H

#include <cmath>

///@file Constant.h Collection of constants.


namespace BugTrap
{

  /**
     @brief Collection of constants.
     @tparam T type constant.
  */
  template <typename T>
  struct Constant
  {
    /**
     * @brief The number \f$\pi\f$.
     * @return \f$\pi\f$.
     */
    static
    constexpr T pi() { return static_cast<T>(std::acos(-1)); }
  };
}

#endif // CONSTANT_H
