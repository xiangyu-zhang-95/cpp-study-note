#include "assert.h"
#include <memory>
#include <type_traits>

struct MyClass {
  double doSomething() const { return 0.0; }
};

template <class Tp, class = std::__enable_if_t<std::is_void<Tp>::value>>
int foo_01() _NOEXCEPT {
  return 0;
}

template <class Tp, class = void,
          class = std::__enable_if_t<!std::is_void<Tp>::value> >
int foo_01() _NOEXCEPT {
  return 1;
}

int foo_02(void* p, int x) {
    return x;
}

int main() {
    // check is_void, notice a_01 & a_02 is resolved in compile time
    bool a_01 = std::is_void<int>::value;
    bool a_02 = std::is_void<void>::value;

    // allocator
    std::allocator<void> allo_01;
    std::allocator<int> allo_02;
    bool a_03 = (allo_01 == allo_02);
    assert(a_03);

    // decltype, declval
    // notice x is of type double in compile time
    decltype(std::declval<MyClass>().doSomething()) x;

    // enable_if usage
    int a_04 = foo_01<void>();
    int a_05 = foo_01<int>();
    assert(a_04 == 0);
    assert(a_05 == 1);

    // check int* could be converted to void* implicitly
    int a_06 = 12;
    int a_07 = foo_02(&a_06, 7);
    assert(a_07 == 7);
}