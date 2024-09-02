#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>
#include <list>
#include <vector>
#include <functional>
#include <deque>

template<typename T, std::size_t N>
int length(std::array<T, N> a) {
    return a.size();
}

int add(int a, int b) {
    return a + b;
}

int main() {
    // int a = 12;
    // std::cout << a << std::endl;

    std::array<int, 3> a1{ {1, 2, 3} };
    std::array<int, 4> a2{ {1, 2, 3, 4} };
    std::array<int, 10> a3{ {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };

    std::cout << length(a1) << std::endl;
    std::cout << length(a2);
    std::cout << length(a3);

    // std::sort();
    // a1.begin();
    std::vector<int>({1, 2, 3}).begin();

    std::for_each(a1.begin(), a1.end(), [](int a) {std::cout << a << std::endl;});

    auto f = add;
    // std::cout << f(a1) << f(a2) << f(a3) << std::endl;

    auto lambda = [](int a, int b) {return a + b;};
    auto g = lambda;
    std::cout << g(1, 5) << std::endl;

    std::copy(a1.begin(), a2.begin(), a3.end());

    std::deque<int> dq{1, 2, 3, 4, 5};

    // std::distance(dq.begin(), dq.end());
    std::cout << sizeof(dq.begin()) << std::endl;


    return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <functional>

// int add(int a, int b) {
//     return a + b;
// }

// struct cmp {
//     long x;
//     long y;
//     long z;
//     long w;
//     long h;
//     bool operator()(int p, int q) {
//         return p < q;
//     }
// };

// int main() {
//     auto lambda = [](int, int) {return 0;};
//     std::function f = lambda;
//     std::cout << sizeof(lambda) << std::endl;
//     std::cout << sizeof(f) << std::endl;

//     std::function g = add;
//     // std::cout << sizeof(add) << std::endl;
//     std::cout << sizeof(g) << std::endl;

//     std::function c = cmp();
//     std::cout << sizeof(cmp) << std::endl;
//     std::cout << sizeof(c) << std::endl;
// }