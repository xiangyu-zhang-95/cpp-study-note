#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_set>

int main() {
    std::unordered_set<long> s{1, 2, 3, 4};
    auto it = s.begin();
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    s.rehash(100);
    for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (; it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}
