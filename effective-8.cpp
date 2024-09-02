#include <iostream>
#include <type_traits>

enum class A {

};

int main() {
    int* p = nullptr;
    std::underlying_type_t<A> c;
}