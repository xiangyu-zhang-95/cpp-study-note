#include <iostream>
#include <functional>
#include <type_traits>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

struct X {
    X(int v): x{v} {}
    void process(int y) {
        cout << "process with x = " << x << " and y = " << y << endl;
    }
    int x;
};

int add(int a, int b) {
    return a + b;
}


int main() {
    // function m_fail  = std::bind(&X::process, _1, 42);
    function<void(X)> m_succeed  = std::bind(&X::process, _1, 42);
    m_succeed(X(12));

    // std::is_same<class Tp, class Up>decltype(std::bind(&X::process, _1, 42));

    auto d = std::bind(&X::process, _1, 42);

    // decltype(d()) t;

    // function p = add;
    // std::cout << p(1, 3) << std::endl;

    std::enable_if<true, int> tt;
    std::is_arithmetic<int> ttt;

    std::vector<int> v(12, 7);
    auto it = std::back_insert_iterator<vector<int>>(v);
    auto it_s = v.rbegin();

    std::cout << sizeof(it_s) << std::endl;

    // std::is_convertible<class T1, class T2> t;

    std::is_reference<int&> qwe;
    // std::function v = add;

    // std::nth_element(v.begin(), &v[7], v.end());



}


template<class T>
auto test_returnable(int) -> decltype(
    void(static_cast<T(*)()>(nullptr)), std::true_type{}
);


// std::copyable<int>