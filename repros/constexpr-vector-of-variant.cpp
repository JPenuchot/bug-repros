#include <type_traits>
#include <variant>

struct trivially_destructible_t {
  constexpr ~trivially_destructible_t() = default;
};

struct non_trivially_destructible_t {
  constexpr ~non_trivially_destructible_t() {}
};

static_assert(std::is_trivially_destructible<trivially_destructible_t>{});
static_assert(!std::is_trivially_destructible<non_trivially_destructible_t>{});

constexpr bool foo() {
  std::variant<trivially_destructible_t> ok;
  std::variant<non_trivially_destructible_t> not_ok;
  return true;
}

int main() {
  constexpr bool val = foo();
  static_assert(val);
}
