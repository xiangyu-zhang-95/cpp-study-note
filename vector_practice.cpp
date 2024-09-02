#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

struct MyVector {
    long* begin;
    long* end;
    long* end_cap;
};

// kaitai -- thx

int main() {
    int n = 5, val = 13;
    std::vector<long> v(n, val);
    assert(sizeof(v) == 24);

    MyVector my_vector;
    std::memmove(&my_vector, &v, sizeof(v));

    assert(my_vector.end == my_vector.end_cap);
    assert((my_vector.end - my_vector.begin) == n); // (char* - char* ) == (long* - long*)

    for (long* begin = my_vector.begin; begin != my_vector.end; begin++) {
        assert(*begin == val);
    }

}