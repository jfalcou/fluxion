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
// Tests for flx::radindeg
//==================================================================================================
TTS_CASE_WITH( "Check behavior of flx::radindeg(eve::wide)"
        , flx::test::simd::ieee_reals
        , tts::generate ( tts::randoms(-1, +1)
                              )
        )
<typename T>(T const& a0)
{
  using flx::var;
  using flx::val;
  using flx::der;
  using flx::derivative;

  auto vda0 = var(a0);
  TTS_EQUAL(val(eve::radindeg(vda0))      , eve::radindeg(a0));
  TTS_EQUAL(der(eve::radindeg(vda0))      , derivative(eve::radindeg)(a0));
};
