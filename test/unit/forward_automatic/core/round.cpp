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
// Tests for flx::round
//==================================================================================================
TTS_CASE_WITH( "Check behavior of flx::round(eve::wide)"
        , flx::test::simd::ieee_reals
        , tts::generate ( tts::randoms(-10, +10)
                              , tts::logicals(0,3)
                              )
        )
<typename T, typename M>(T const& a0, M const& /*maaask*/)
{
  using eve::detail::map;
  using flx::var;
  using flx::val;
  using flx::der;
  using flx::derivative;

  auto vda0 = var(a0);
  TTS_EQUAL(val(eve::round(vda0))      , eve::round(a0));
//   TTS_EQUAL(val(eve::round[mask](vda0)), eve::round[ mask ](a0)); 
  TTS_EQUAL(der(eve::round(vda0))      , derivative(eve::round)(a0));
//   TTS_EQUAL(der(eve::round[mask](vda0)), eve::if_else( mask , derivative(eve::round)(a0), eve::one)); 
};
