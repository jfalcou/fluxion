/**
  EVE - Expressive Vector Engine
  Copyright : EVE Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include "test.hpp"
#include <algorithm>
#include <eve/module/core.hpp>
#include <eve/module/ad.hpp>

//==================================================================================================
// Tests for eve::maxmag
//==================================================================================================
EVE_TEST( "Check behavior of eve::maxmag(eve::wide)"
        , eve::test::simd::ieee_reals
        , eve::test::generate ( eve::test::randoms(-10, +10)
                              , eve::test::randoms(-10, +10)
                              , eve::test::randoms(-10, +10)
                              , eve::test::logicals(0,3)
                              )
        )
<typename T, typename M>(T const& a0, T const& a1, T const& a2, M const& mask)
{
  using eve::detail::map;
  using eve::var;
  using eve::val;
  using eve::der;
  using eve::diff_1st;
  using eve::diff_2nd;
  using eve::diff_3rd;

  auto vda0 = var(a0);
  auto vda1 = var(a1);
  auto vda2 = var(a2);
  TTS_EQUAL(val(eve::maxmag(vda0, a1, a2))  , eve::maxmag(a0, a1, a2));
  TTS_EQUAL(val(eve::maxmag(a0, vda1, a2))  , eve::maxmag(a0, a1, a2));
  TTS_EQUAL(val(eve::maxmag(a0, a1, vda2))  , eve::maxmag(a0, a1, a2));
  TTS_EQUAL(der(eve::maxmag(vda0, a1, a2))  , diff_1st(eve::maxmag)(a0, a1, a2));
  TTS_EQUAL(der(eve::maxmag(a0, vda1, a2))  , diff_2nd(eve::maxmag)(a0, a1, a2));
  TTS_EQUAL(der(eve::maxmag(a0, a1, vda2))  , diff_3rd(eve::maxmag)(a0, a1, a2));

  TTS_EQUAL(val(eve::maxmag[mask](vda0, a1, a2))  , eve::maxmag[mask](a0, a1, a2));
  TTS_EQUAL(val(eve::maxmag[mask](a0, vda1, a2))  , eve::maxmag[mask](a0, a1, a2));
  TTS_EQUAL(val(eve::maxmag[mask](a0, a1, vda2))  , eve::maxmag[mask](a0, a1, a2));
  TTS_EQUAL(der(eve::maxmag[mask](vda0, a1, a2))  , eve::if_else(mask, diff_1st(eve::maxmag)(a0, a1, a2), eve::one));
  TTS_EQUAL(der(eve::maxmag[mask](a0, vda1, a2))  , eve::if_else(mask, diff_2nd(eve::maxmag)(a0, a1, a2), eve::zero));
  TTS_EQUAL(der(eve::maxmag[mask](a0, a1, vda2))  , eve::if_else(mask, diff_3rd(eve::maxmag)(a0, a1, a2), eve::zero));
};