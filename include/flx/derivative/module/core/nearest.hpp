//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#pragma once
#include <flx/derivative/decorator.hpp>
#include <eve/module/core.hpp>

namespace eve::detail
{

  template<floating_ordered_value T>
  EVE_FORCEINLINE constexpr T nearest_(EVE_SUPPORTS(cpu_)
                                      , flx::derivative_type<1> const &
                                      , T x) noexcept
  {
    return zero(as(x));
  }
}
