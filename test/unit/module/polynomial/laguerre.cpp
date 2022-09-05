//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#include "test.hpp"
#include <eve/module/complex.hpp>
#include <flx/differential/math.hpp>

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL("Check return types of eve::laguerre", flx::test::simd::ieee_reals)
<typename T>(tts::type<T>)
{
  using v_t = eve::element_type_t<T>;
  TTS_EXPR_IS( flx::diff(eve::laguerre)(T())  , T  );
  TTS_EXPR_IS( flx::diff(eve::laguerre)(v_t()), v_t);
};

//==================================================================================================
// Tests for eve::laguerre
//==================================================================================================
TTS_CASE_WITH("Check behavior of eve::laguerre(eve::wide)",
              flx::test::simd::ieee_reals,
              tts::generate(tts::randoms(eve::valmin, eve::valmax)
                           )
              )
<typename T>(T const& a0)
{
  using eve::laguerre;
  using eve::detail::map;
  using e_t = eve::element_type_t<T>;
  using c_t = eve::complex<e_t>;

  auto eps = eve::eps(eve::as<e_t>());
  auto dlaguerre = [&](auto e) { return eve::imag(laguerre(c_t(e,eps)))/eps; };
  TTS_ULP_EQUAL(flx::diff_1st(eve::laguerre)(a0), map(dlaguerre, a0), 0.5);
};
