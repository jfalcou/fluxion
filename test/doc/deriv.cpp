#include <flx/flx.hpp>
#include <eve/module/core.hpp>
#include <eve/module/math.hpp>
#include <array>
#include <iostream>

using wide_ft = eve::wide<float, eve::fixed<4>>;

int main()
{
  auto f = [](auto x, auto y,  auto z){
   return eve::fma(x, y, z); };

  {
    float x = 3;
    float y = 1;
    float z = 5;
    auto g = flx::gradient(f, x, y, z);
    std::cout << "---- simd" << '\n'
              << "<- x                                   = " << x << '\n'
              << "<- y                                   = " << y << '\n'
              << "<- z                                   = " << z << '\n';

 std::cout << "gradient of f is : {";
 for(int i=0; i < 2 ; ++i)
    {
      std::cout << g[i] << ", ";
    }
    std::cout << g[2] << "}" << '\n'   ;
  }
  {
    auto f = [](auto x, auto y,  auto z){return eve::fma(x, y, z); };
    wide_ft x = {3, 4, 5, 6};
    wide_ft y = {1, 2, 3, 4};
    wide_ft z = {5, 6, 7, 8};
    std::array<wide_ft, 3> g = flx::gradient(f, x, y, z);
    std::cout << "---- simd" << '\n'
              << "<- x                                   = " << x << '\n'
              << "<- y                                   = " << y << '\n'
              << "<- z                                   = " << z << '\n';

    std::cout << "gradient of f is : {";
    for(int i=0; i < 2 ; ++i)
    {
      std::cout << g[i] << ", ";
    }
    std::cout << g[2] << "}" << '\n'   ;
    return 0;
  }
}