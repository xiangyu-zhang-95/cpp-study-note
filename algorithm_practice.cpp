#include <algorithm>

#include <cassert>

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <numeric>
#include <memory>

int main() {
    std::deque<int> dq {1, 2, 3, 4, 5};
    assert(sizeof(dq.begin()) == 16);

    std::vector<int> v {1, 2, 3, 4, 5};
    assert(sizeof(v.begin()) == 8);

    std::swap(dq, dq);
    std::swap(v, v);

}