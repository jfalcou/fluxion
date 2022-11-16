//==================================================================================================
/*
  EVE - Expressive Vector Engine
  Copyright : EVE Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#pragma once
#include <type_traits>

namespace flx
{
  template<typename Tag> struct is_derivable    : std::true_type {};
  template<typename Tag> struct has_derivation  : std::true_type {};

  template<typename Tag>
  inline constexpr auto is_derivable_v =  is_derivable<Tag>::value;

  template<typename Tag>
  inline constexpr auto has_derivation_v =  has_derivation<Tag>::value;

  // List of non-derivable functions
  namespace tag
  {
    struct val_;
    struct der_;
    struct var_;
    struct gradient_;
    struct differential_;
    struct horner_;
    struct newton_;
    struct agm_;

    struct all_;
    struct any_;
    struct reduce_;
    struct count_true__;
    struct bit_and_;
    struct bit_andnot_;
    struct bit_cast_;
    struct bit_ceil_;
    struct bit_floor_;
    struct bit_mask_;
    struct bit_notand_;
    struct bit_not_;
    struct bit_notor_;
    struct bitofsign_;
    struct bit_or_;
    struct bit_ornot_;
    struct bit_select_;
    struct bit_shl_;
    struct bit_shr_;
    struct bit_width_;
    struct bit_xor_;
    struct exponent_;
    struct gather_;
    struct has_single_bit_;
    struct hi_;
    struct if_else_;
    struct is_denormal_;
    struct is_equal_;
    struct is_not_equal_;
    struct is_less_;
    struct is_less_equal_;
    struct is_lessgreater_;
    struct is_greater_;
    struct is_greater_equal_;
    struct is_ordered_;
    struct is_unordered_;
    struct is_not_less_;
    struct is_not_less_equal_;
    struct is_not_greater_;
    struct is_not_greater_equal_;
    struct is_eqz_;
    struct is_even_;
    struct is_infinite_;
    struct is_finite_;
    struct is_flint_;
    struct is_lez_;
    struct is_ltz_;
    struct is_gez_;
    struct is_gtz_;
    struct is_nez_;
    struct is_negative_;
    struct is_nlez_;
    struct is_nltz_;
    struct is_ngez_;
    struct is_ngtz_;
    struct is_normal_;
    struct is_not_denormal_;
    struct is_not_finite_;
    struct is_not_flint_;
    struct is_not_infinite_;
    struct is_nan_;
    struct is_not_nan_;
    struct is_odd_;
    struct is_positive_;
    struct is_pow2_;
    struct lo_;
    struct lohi_;
    struct lookup_;
    struct maximum_;
    struct minimum_;
    struct next_;
    struct nextafter_;
    struct none_;
    struct prev_;
    struct popcount_;
    struct rotl_;
    struct rotr_;
    struct rshl__;
    struct rshr_;
    struct scan_;
    struct shl__;
    struct shr_;
    struct significants_;
  }

  template<> struct is_derivable<tag::val_>                   : std::false_type {};
  template<> struct is_derivable<tag::der_>                   : std::false_type {};
  template<> struct is_derivable<tag::var_>                   : std::false_type {};
  template<> struct is_derivable<eve::tag::if_else_>               : std::false_type {};
  template<> struct is_derivable<tag::gradient_>              : std::false_type {};
  template<> struct is_derivable<tag::differential_>          : std::false_type {};
  template<> struct has_derivation<tag::val_>                 : std::false_type {};
  template<> struct has_derivation<tag::der_>                 : std::false_type {};
  template<> struct has_derivation<tag::var_>                 : std::false_type {};
  template<> struct has_derivation<eve::tag::if_else_>             : std::false_type {};
  template<> struct has_derivation<eve::tag::agm_>                 : std::false_type {};

  template<> struct is_derivable<eve::tag::all_>                   : std::false_type {};
  template<> struct is_derivable<eve::tag::any_>                   : std::false_type {};
  template<> struct is_derivable<eve::tag::count_true_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::epsilon_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::exponent_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::gather_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::hi_>                    : std::false_type {};
  template<> struct is_derivable<eve::tag::is_denormal_>           : std::false_type {};
  template<> struct is_derivable<eve::tag::is_equal_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_equal_>          : std::false_type {};
  template<> struct is_derivable<eve::tag::is_less_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::is_less_equal_>         : std::false_type {};
  template<> struct is_derivable<eve::tag::is_lessgreater_>        : std::false_type {};
  template<> struct is_derivable<eve::tag::is_greater_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::is_greater_equal_>      : std::false_type {};
  template<> struct is_derivable<eve::tag::is_ordered_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::is_unordered_>          : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_less_>           : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_less_equal_>     : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_greater_>        : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_greater_equal_>  : std::false_type {};
  template<> struct is_derivable<eve::tag::is_eqz_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_even_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::is_infinite_>           : std::false_type {};
  template<> struct is_derivable<eve::tag::is_finite_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::is_flint_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::is_lez_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_ltz_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_gez_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_gtz_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_nez_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_negative_>           : std::false_type {};
  template<> struct is_derivable<eve::tag::is_nlez_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::is_nltz_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::is_ngez_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::is_ngtz_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::is_normal_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_denormal_>       : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_finite_>         : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_flint_>          : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_infinite_>       : std::false_type {};
  template<> struct is_derivable<eve::tag::is_nan_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_not_nan_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::is_odd_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::is_positive_>           : std::false_type {};
  template<> struct is_derivable<eve::tag::is_pow2_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::lo_>                    : std::false_type {};
  template<> struct is_derivable<eve::tag::lohi_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::lookup_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::maximum_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::minimum_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_and_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_andnot_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_cast_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_ceil_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_floor_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_mask_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_notand_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_not_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_notor_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::bitofsign_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_or_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_ornot_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_select_>            : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_shr_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_width_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::bit_xor_>               : std::false_type {};
  template<> struct is_derivable<eve::tag::next_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::nextafter_>             : std::false_type {};
  template<> struct is_derivable<eve::tag::none_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::popcount_>              : std::false_type {};
  template<> struct is_derivable<eve::tag::prev_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::reduce_>                : std::false_type {};
  template<> struct is_derivable<eve::tag::rotl_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::rotr_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::rshl_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::rshr_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::scan_>                  : std::false_type {};
  template<> struct is_derivable<eve::tag::shl_>                   : std::false_type {};
  template<> struct is_derivable<eve::tag::shr_>                   : std::false_type {};
  template<> struct is_derivable<eve::tag::significants_>          : std::false_type {};

}