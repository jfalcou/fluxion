//==================================================================================================
/*
  Fluxion - Post-Modern Automatic Derivation
  Copyright : Fluxion Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include "test.hpp"
#include <flx/flx.hpp>

//==================================================================================================
// Tests for flx::add
//==================================================================================================
TTS_CASE_WITH("Check behavior of flx::add(eve::wide) for real values",
              flx::test::simd::ieee_reals,
              tts::generate(tts::randoms(-10, +10),
                            tts::randoms(-10, +10),
                            tts::randoms(-10, +10),
                            tts::logicals(0, 3)))
<typename T, typename M>(T const& a0, T const& a1, T const& a2, M const& )
{
  std::cout << a0 << std::endl;
  std::cout << a1 << std::endl;
  std::cout << a2 << std::endl;

  using eve::detail::map;
  using flx::der;
  using flx::val;
  using flx::var;

  auto vda0 = var(a0);
  auto vda1 = var(a1);

  TTS_EQUAL(val(eve::add(vda0, a1))   , eve::add(a0, a1));
  TTS_EQUAL(der(eve::add(vda0, a1))   , eve::one(eve::as(a0)));
  TTS_EQUAL(val(eve::add(a0, vda1))   , eve::add(a0, a1));
  TTS_EQUAL(der(eve::add(a0, vda1))   , eve::one(eve::as(a1)));
  TTS_EQUAL(val(eve::add(vda0, vda1)) , eve::add(a0, a1));
  TTS_EQUAL(der(eve::add(vda0, vda1)) , T(2));

  //  mix with  scalars
  using e_t = eve::element_type_t<T>;
  e_t b0(1);
  e_t b1(3);
  auto vdb0 = var(b0);
  TTS_EQUAL(val(eve::add(vdb0, a1))   , eve::add(b0, a1));
  TTS_EQUAL(der(eve::add(vdb0, a1))   , eve::one(eve::as(a1)));
  TTS_EQUAL(val(eve::add(vdb0, b1))   , eve::add(b0, b1));
  TTS_EQUAL(der(eve::add(vdb0, b1))   , eve::one(eve::as(b1)));

  TTS_EQUAL(val(eve::add(b0, vda1))   , eve::add(b0, a1));
  TTS_EQUAL(val(eve::add(b0, vda1))   , eve::add(b0, a1));
  TTS_EQUAL(der(eve::add(vdb0, vda1))   , T(2));
  TTS_EQUAL(der(eve::add(vdb0, vda1))   , T(2));

  //  mix with  complex
  using z_t = eve::as_complex_t<T>;
  z_t za(a0, a1);
  z_t zb(a1, a2);
  auto vdza = var(za);
  auto vdzb = var(zb);
  std::cout << vdza << std::endl;
  std::cout << vdzb << std::endl;
  TTS_EQUAL(val(eve::add(vdza, vdzb)) , eve::add(za, zb));
  TTS_EQUAL(der(eve::add(vdza, vdzb)) , z_t(2));

  auto vda2 = var(a2);
   TTS_EQUAL(val(eve::add(vdza, vda2)) , eve::add(za, a2));
   TTS_EQUAL(der(eve::add(vdza, vda2)) , z_t(2));
    TTS_EQUAL(val(eve::add(vdza, zb)) , eve::add(za, zb));
    TTS_EQUAL(der(eve::add(vdza, zb)) , z_t(1));
   TTS_EQUAL(val(eve::add(vdza, a2)) , eve::add(za, a2));
   TTS_EQUAL(der(eve::add(vdza, a2)) , z_t(1));

  //  mix with "scalar"  complex
  using sz_t = eve::as_complex_t<eve::element_type_t<T>>;
  sz_t sza(1, 2);
  sz_t szb(3, 4);
  auto vdsza = var(sza);
  auto vdszb = var(szb);
  TTS_EQUAL(val(eve::add(vdsza, vdszb)) , eve::add(sza, szb));
  TTS_EQUAL(der(eve::add(vdsza, vdszb)) , sz_t(2));
//      TTS_EQUAL(val(eve::add(vdsza, vda2)) , eve::add(sza, a2));
//      TTS_EQUAL(der(eve::add(vdsza, vda2)) , z_t(2));
//      TTS_EQUAL(val(eve::add(vdsza, a2)) , eve::add(sza, a2));
//      TTS_EQUAL(der(eve::add(vdsza, a2)) , z_t(1));

  // operator +
  TTS_EQUAL(val(vda0+a1)              , eve::add(a0, a1));
  TTS_EQUAL(der(vda0+a1)              , eve::one(eve::as(a0)));
  TTS_EQUAL(val(a0+vda1)              , eve::add(a0, a1));
  TTS_EQUAL(der(a0+vda1)              , eve::one(eve::as(a1)));
    std::cout << "vda0            " << vda0 << std::endl;
    std::cout << "vda1            " << vda1 << std::endl;
    std::cout << "add(vda0, vda1) "<< eve::add(vda0, vda1) << std::endl;
    std::cout << "vda0+vda1       " << vda0+vda1 << std::endl;
    TTS_EQUAL(val(vda0+vda1)            , eve::add(a0, a1));
    TTS_EQUAL(der(vda0+vda1)            , T(2));

  vda0 += vda1;
  std::cout << "vda0 += vda1    " << vda0 << std::endl;
  TTS_EQUAL(val(vda0), a0 + a1);
  TTS_EQUAL(der(vda0), T(2));
  std::cout << "avant vda1 " << vda1 << std::endl;
  vda1 += a0;
  std::cout << "apres vda1 " << vda1 << std::endl;
  std::cout << "vda1 += a0    " << vda1 << std::endl;
  TTS_EQUAL(val(vda1), a1 + a0);
  TTS_EQUAL(der(vda1), T(1));

  {
    auto vda0 = var(a0);
    auto vda1 = var(a1);
    auto vda2 = var(a2);
    TTS_EQUAL(val(eve::add(vda0, a1, a2))      , eve::add(a0, a1, a2));
    TTS_EQUAL(der(eve::add(vda0, a1, a2))      , flx::derivative_1st(eve::add)(a0, a1, a2));
    TTS_EQUAL(val(eve::add(a0, vda1, a2))      , eve::add(a0, a1, a2));
    TTS_EQUAL(der(eve::add(a0, vda1, a2))      , flx::derivative_2nd(eve::add)(a0, a1, a2));
    TTS_EQUAL(val(eve::add(a0, a1, vda2))      , eve::add(a0, a1, a2));
    TTS_EQUAL(der(eve::add(a0, a1, vda2))      , flx::derivative_3rd(eve::add)(a0, a1, a2));
  }
 };
