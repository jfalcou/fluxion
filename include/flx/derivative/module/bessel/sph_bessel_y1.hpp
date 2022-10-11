//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#pragma once
#include <flx/derivative/derivative.hpp>
#include <eve/module/bessel.hpp>

namespace eve::detail
{

  template<floating_real_value T>
  EVE_FORCEINLINE constexpr T sph_bessel_y1_(EVE_SUPPORTS(cpu_)
                                  , flx::derivative_type<1> const &
                                  , T const &x) noexcept
  {
    return flx::derivative_2nd(sph_bessel_yn)(1u, x);
  }
}
