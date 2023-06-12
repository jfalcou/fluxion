/**
  EVE - Expressive Vector Engine
  Copyright : EVE Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include "test.hpp"
#include <algorithm>
#include <eve/module/core.hpp>
#include <flx/flx.hpp>

//==================================================================================================
// Tests for flx::mul
//==================================================================================================
TTS_CASE_WITH( "Check behavior of flx::mul(eve::wide)"
        , flx::test::simd::ieee_reals
        , tts::generate ( tts::randoms(-10, +10)
                              , tts::randoms(-10, +10)
                              , tts::randoms(-10, +10)
                              , tts::logicals(0,3)
                              )
        )
  <typename T, typename M>(T const& a0, T const& a1, T const&  , M const& )
{
  using eve::detail::map;
  using flx::var;
  using flx::val;
  using flx::der;
  using flx::derivative_1st;
  using flx::derivative_2nd;
  using flx::derivative_3rd;

  auto vda0 = var(a0);
  auto vda1 = var(a1);
  TTS_EQUAL(val(eve::mul(vda0, a1    ))      , eve::mul(a0, a1    ));
  TTS_EQUAL(val(eve::mul(vda0, vda1  ))      , eve::mul(a0, a1    ));
  TTS_EQUAL(der(eve::mul(vda0, a1    ))      , a1);
  TTS_EQUAL(der(eve::mul(a0, vda1    ))      , a0);
  TTS_EQUAL(der(eve::mul(vda0, vda1  ))      , a0+a1);

  TTS_EQUAL(val(vda0*a1)                     , eve::mul(a0, a1    ));
  TTS_EQUAL(val(vda0*vda1)                   , eve::mul(a0, a1    ));
  TTS_EQUAL(der(vda0*a1)                     , a1);
  TTS_EQUAL(der(a0*vda1)                     , a0);
  TTS_EQUAL(der(vda0*vda1)                   , a0+a1);

  vda0 *= vda1;
  std::cout << "vda0 *= vda1    " << vda0 << std::endl;
  TTS_EQUAL(val(vda0), a0 * a1);
  TTS_EQUAL(der(vda0), a0 + a1);
  std::cout << "avant vda1 " << vda1 << std::endl;
  vda1 *= a0;
  std::cout << "apres vda1 " << vda1 << std::endl;
  std::cout << "vda1 *= a0    " << vda1 << std::endl;
  TTS_EQUAL(val(vda1), a1 * a0);
  TTS_EQUAL(der(vda1), a0);

//  auto vda2 = var(a2);
//   TTS_EQUAL(val(eve::mul(vda0, a1, a2))      , eve::mul(a0, a1, a2));
//   TTS_EQUAL(der(eve::mul(vda0, a1, a2))      , derivative_1st(eve::mul)(a0, a1, a2));
//   TTS_EQUAL(val(eve::mul(a0, vda1, a2))      , eve::mul(a0, a1, a2));
//   TTS_EQUAL(der(eve::mul(a0, vda1, a2))      , derivative_2nd(eve::mul)(a0, a1, a2));
//   TTS_EQUAL(val(eve::mul(a0, a1, vda2))      , eve::mul(a0, a1, a2));
//   TTS_EQUAL(der(eve::mul(a0, a1, vda2))      , derivative_3rd(eve::mul)(a0, a1, a2));

//   TTS_EQUAL(val(eve::mul[mask](vda0, a1, a2)), eve::mul[mask](a0, a1, a2));
//   TTS_EQUAL(der(eve::mul[mask](vda0, a1, a2)), eve::if_else(mask, derivative_1st(eve::mul)(a0, a1, a2), eve::one));
//   TTS_EQUAL(val(eve::mul[mask](a0, vda1, a2)), eve::mul[mask](a0, a1, a2));
//   TTS_EQUAL(der(eve::mul[mask](a0, vda1, a2)), eve::if_else(mask, derivative_2nd(eve::mul)(a0, a1, a2), eve::zero));
//   TTS_EQUAL(val(eve::mul[mask](a0, a1, vda2)), eve::mul[mask](a0, a1, a2));
//   TTS_EQUAL(der(eve::mul[mask](a0, a1, vda2)), eve::if_else(mask, derivative_3rd(eve::mul)(a0, a1, a2), eve::zero));


};