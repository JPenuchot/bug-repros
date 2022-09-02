// Clang only: std::variant can't hold non-trivially destructible types

#include <type_traits>
#include <variant>
#include <vector>

struct trivial_t {
  constexpr ~trivial_t() = default;
};

struct non_trivial_t {
  constexpr ~non_trivial_t() {}
};

// Check for (non-)trivial destructibility
static_assert(std::is_trivially_destructible<trivial_t>{});
static_assert(!std::is_trivially_destructible<non_trivial_t>{});

constexpr bool foo() {
  // This compiles just fine
  std::variant<trivial_t> ok;

  // These two next lines should compile but they don't
  std::variant<non_trivial_t> not_ok;
  std::variant<std::vector<int>> not_ok_either;

  return true;
}

int main() { constexpr bool val = foo(); }
