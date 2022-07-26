
#pragma once

#include <functional>
#include <utility>

namespace combinators {

/////////////////
// combinators //
/////////////////

// B (The Bluebird)
auto _b = [](auto f, auto g) { return [=](auto&& x) { return f(g(std::forward<decltype(x)>(x))); }; };

// Phi (The Phoenix)
auto _phi = [](auto f, auto g, auto h) {
    return [=](auto&& x) { return g(f(std::forward<decltype(x)>(x)), h(std::forward<decltype(x)>(x))); };
};

// Psi (The Psi Bird)
auto _psi = [](auto f, auto g) {
    return [=](auto&& x, auto&& y) { return f(g(std::forward<decltype(x)>(x)), g(std::forward<decltype(y)>(y))); };
};

/////////////////////////////////////////////
// more convenient binary/unary operations //
/////////////////////////////////////////////

auto _eq    = [](auto x) { return [x](auto y) { return x == y; }; };
auto _eq_   = std::equal_to{};
auto _lt    = [](auto x) { return [x](auto y) { return x > y; }; };
auto lt_    = [](auto x) { return [x](auto y) { return y < x; }; };
auto _lt_   = std::less{};
auto _plus  = [](auto x) { return [x](auto y) { return x + y; }; };
auto _plus_ = std::plus{};
auto _mul   = [](auto x) { return [x](auto y) { return x * y; }; };
auto _mul_  = std::multiplies{};
auto _sub   = [](auto x) { return [x](auto y) { return x - y; }; };
auto sub_   = [](auto x) { return [x](auto y) { return y - x; }; };
auto _sub_  = std::minus{};
auto _or_   = std::logical_or{};
auto _and_  = std::logical_and{};

}  // namespace combinators
