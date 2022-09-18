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
  template<int N, typename T0, typename T1, typename... Ts>
  auto minabs_(EVE_SUPPORTS(cpu_), flx::derivative_type<N>
           , T0 arg0, T1 arg1, Ts... args) noexcept
  {
    return minmaxabs_kernel<N>(eve::minabs, eve::sign, arg0, arg1, args...);
  }
}