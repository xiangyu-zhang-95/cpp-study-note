#include <ios>
#include <type_traits>
#include <iostream>

void void_f();
int  int_f();

void foo();

int main() {
    auto v = std::integral_constant<int, 12>()();
    int w = std::integral_constant<int, 12>();
    std::cout << std::boolalpha;
    std::cout << v << std::endl;
    std::cout << w << std::endl;

    std::cout << std::is_void<decltype(void_f())>::value << std::endl;
    std::cout << !std::is_void<decltype(int_f())>::value << std::endl;

    std::cout << std::is_function<decltype(foo)>::value << std::endl;
    std::cout << !std::is_function<decltype(&foo)>::value << std::endl;
    std::cout << !std::is_function<decltype(*(&foo))>::value << std::endl;

    auto lambda = [](){};
    std::cout << !std::is_function<decltype(lambda)>::value << std::endl;

    std::cout << std::is_object<int>::value << std::endl;
    std::cout << std::is_object<int*>::value << std::endl;
    std::cout << !std::is_object<int&>::value << std::endl;

    int  x = 12;
    int& xr = x;
    std::cout << !std::is_same<decltype(x), decltype(xr)>::value << std::endl;

    std::cout << std::is_const<const int>::value << std::endl;
    std::cout << std::is_const<typename std::remove_reference<const int&>::type>::value << std::endl;
    std::cout << !std::is_const<const int&>::value << std::endl;
    
    int x1 = 0; double x2 = 2.3;
    std::cout << std::is_same<decltype(x1, x2), double>::value << std::endl;


}


// template specialization
// is_same, is_constant

// sfinae -> substitution failure is not an error
// is_class, is_function

// zero-base optimization
// is_empty

// move v.s. copy
