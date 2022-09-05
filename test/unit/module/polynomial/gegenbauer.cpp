//================================================================================================== //!
// Fluxion - Post-Modern Automatic Derivation                                                        //!
// Copyright : Fluxion Project Contributors                                                          //!
// SPDX-License-Identifier: BSL-1.0                                                                  //!
//================================================================================================== //!
#include "test.hpp"
#include <flx/differential/polynomial.hpp>
#include <boost/math/special_functions/gegenbauer.hpp>

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL("Check return types of eve::gegenbauer", flx::test::simd::ieee_reals)
<typename T>(tts::type<T>)
{
  using v_t = eve::element_type_t<T>;
  using wi_t = eve::as_integer_t<T>;
  using i_t  = eve::as_integer_t<v_t>;
  TTS_EXPR_IS( flx::diff(eve::gegenbauer)(i_t(), T(), T())  , T);
  TTS_EXPR_IS( flx::diff(eve::gegenbauer)(wi_t(), T(), T())  , T);
  TTS_EXPR_IS( flx::diff(eve::gegenbauer)(i_t(), T(), v_t())  , T);
  TTS_EXPR_IS( flx::diff( eve::gegenbauer)(wi_t(), T(), v_t())  , T);
};

//==================================================================================================
// Tests for eve::gegenbauer
//==================================================================================================
TTS_CASE_WITH( "Check behavior of gegenbauer diff on wide"
             , flx::test::simd::ieee_reals
             , tts::generate(tts::between(0.0, 1.0)
                            , tts::as_integer(tts::ramp(0))
                       )
        )
  <typename T, typename I>(T const& a0,I const & i0)
{
   using v_t = eve::element_type_t<T>;
  v_t l = v_t(-3)/v_t(8);
   auto flx__gegenbauerv  =  [l](auto n, auto x) { return flx::diff( eve::gegenbauer)(n, l, x); };
  for(unsigned int n=0; n < 5; ++n)
  {
    auto boost_gegenbauer =  [&](auto i, auto) { return boost::math::gegenbauer_derivative(n, l, a0.get(i), 1u); };
    TTS_ULP_EQUAL(flx__gegenbauerv(n, a0), T(boost_gegenbauer), 256);
  }
  auto boost_gegenbauerv =  [&](auto i, auto) { return boost::math::gegenbauer_derivative(i0.get(i), l, a0.get(i), 1u); };
  TTS_ULP_EQUAL(flx__gegenbauerv(i0    , a0), T(boost_gegenbauerv), 256);
  for(unsigned int j=0; j < eve::cardinal_v<T>; ++j)
  {
    auto boost_gegenbauer2 =  [&](auto i, auto) { return boost::math::gegenbauer_derivative(i0.get(i), l, a0.get(j), 1u); };
    TTS_ULP_EQUAL(flx__gegenbauerv(i0 , a0.get(j)), T(boost_gegenbauer2), 256);
  }
  for(unsigned int j=0; j < eve::cardinal_v<T>; ++j)
  {
    for(unsigned int n=0; n < eve::cardinal_v<T>; ++n)
    {
      TTS_ULP_EQUAL(flx__gegenbauerv(i0.get(j) , a0.get(n)), v_t(boost::math::gegenbauer_derivative(i0.get(j), l, a0.get(n), 1u)), 256);
    }
 }
};
