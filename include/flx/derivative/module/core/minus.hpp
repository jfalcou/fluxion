//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#pragma once
#include <flx/derivative/derivative.hpp>
#include <eve/module/core.hpp>

namespace eve::detail
{
  template<floating_real_value T, unsigned_value N>
  EVE_FORCEINLINE constexpr T minus_(EVE_SUPPORTS(cpu_)
                                   , flx::derivative_type<1> const &
                                   , T x
                                   , N n) noexcept
  {
    if constexpr( has_native_abi_v<T> )
    {
      return if_else(is_eqz(n), minus(x), if_else((n == one(as(n))), mone(as(x)), zero));
    }
    else
      return apply_over(flx::derivative_1st(minus), x, n);
  }

  template<floating_real_value T>
  EVE_FORCEINLINE constexpr T minus_(EVE_SUPPORTS(cpu_)
                                    , flx::derivative_type<1> const &
                                    , T x) noexcept
  {

    return mone(as(x));
  }
}