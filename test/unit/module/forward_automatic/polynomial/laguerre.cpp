//==================================================================================================
/**
  EVE - Expressive Vector Engine
  Copyright : EVE Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include "test.hpp"
#include <eve/module/core.hpp>
#include <flx/flx.hpp>

//==================================================================================================
// Tests for flx::laguerre
//==================================================================================================
TTS_CASE_WITH( "Check behavior of flx::laguerre(eve::wide)"
             , flx::test::simd::ieee_reals
             , tts::generate ( tts::randoms(-10, +10)
                             )
             )
<typename T>(T const& a0)
{
  using flx::var;
  using flx::val;
  using flx::der;
  using flx::derivative_2nd;

  auto vda0 = var(a0);

  TTS_ULP_EQUAL(val(eve::laguerre(T(3), vda0))      , eve::laguerre(T(3), a0), 0.5);
  TTS_ULP_EQUAL(der(eve::laguerre(T(3), vda0))      , derivative_2nd(eve::laguerre)(T(3), a0), 0.5);
};
