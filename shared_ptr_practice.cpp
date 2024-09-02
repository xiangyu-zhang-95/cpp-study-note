#include <cassert>

#include <memory>
#include <iostream>
#include <vector>

struct MyCntrl {
    void* vptr;
    long shared_owner;
    long shared_weak;
    int* ptr;
};

struct MySharedPtr {
    int* ptr_data;
    MyCntrl* ptr_contrl;
};



int main() {
    int val = 103;
    int n = 100, m = 120;

    int* raw = new int(val);
    std::shared_ptr<int> p1 {raw};

    std::vector<std::shared_ptr<int>> v_shared_ptr;
    std::vector<std::weak_ptr<int>> v_weak_ptr;

    for (int i = 0; i < n; i++) {
        v_shared_ptr.push_back(std::shared_ptr<int>(p1));
    }
    for (int i = 0; i < m; i++) {
        v_weak_ptr.push_back(std::weak_ptr<int>(p1));
    }

    MySharedPtr my_shared_ptr;
    std::memcpy(&my_shared_ptr, &p1, sizeof(p1));
    
    assert(my_shared_ptr.ptr_data == raw);
    assert(my_shared_ptr.ptr_data == my_shared_ptr.ptr_contrl->ptr);
    
    assert(*(my_shared_ptr.ptr_data) == val);

    assert(my_shared_ptr.ptr_contrl->shared_owner == n);
    assert(my_shared_ptr.ptr_contrl->shared_weak == m);

}