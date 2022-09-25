//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#pragma once
#include <flx/derivative/derivative.hpp>
#include <eve/module/math.hpp>

namespace eve::detail
{

  template<floating_real_value T>
  EVE_FORCEINLINE constexpr kumi::tuple<T, T>
  sincos_(EVE_SUPPORTS(cpu_), flx::derivative_type<1> const &, T x) noexcept
   {
    if constexpr( has_native_abi_v<T> )
    {
      return {zero(as(x)), zero(as(x))};
    }
    else
    {
      return apply_over2(flx::derivative(sincos), x);
    }
  }

}