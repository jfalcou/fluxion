//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#pragma once
#include <flx/derivative/decorator.hpp>
#include <eve/module/math.hpp>

namespace eve::detail
{
  template<value T>
  EVE_FORCEINLINE constexpr T log_abs_(EVE_SUPPORTS(cpu_)
                                     , flx::derivative_type<1> const &
                                     , T x) noexcept
  {
    return rec(x);
  }
}
