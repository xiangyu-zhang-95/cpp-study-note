#include <ios>
#include <set>
#include <iostream>
#include <type_traits>

int main() {
    std::cout << sizeof(std::set<long>) << std::endl;
    std::cout << std::boolalpha;
    std::cout << std::is_same<size_t, unsigned long>::value << std::endl;
    std::cout << std::is_same<long unsigned int, unsigned long>::value << std::endl;
}