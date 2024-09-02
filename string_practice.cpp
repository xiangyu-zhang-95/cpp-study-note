#include <cstring>

#include <string>
#include <iostream>


int main() {
    std::cout << sizeof(wchar_t) << std::endl;
    std::cout << sizeof(char) << std::endl;
    std::string s;
    std::mbstate_t s_t;

    std::cout << sizeof(std::string::size_type) << std::endl;

    int x = 0x1ul;
    std::cout << x << std::endl;

    return 0;
}