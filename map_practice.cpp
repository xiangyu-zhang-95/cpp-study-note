#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <type_traits>

int main() {
    std::cout << sizeof(std::map<long, long>::value_compare) << std::endl;
    // std::cout << typeid(std::ptrdiff_t).name() << std::endl;
    std::cout << std::boolalpha;
    std::cout << std::is_same<std::ptrdiff_t, long>::value << std::endl;

    std::cout << std::is_same_v<
                    decltype(std::map<long, bool>().get_allocator()), 
                    std::allocator<std::pair<const long, bool>>> << std::endl;

}