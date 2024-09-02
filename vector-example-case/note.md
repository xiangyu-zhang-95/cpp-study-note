__attribute__((__type_visibility__("default"))):
    set the visibility to be default, linkable from other library. Someone may
    set their class to be hidden. This attribute is compiler-specific, i.e. gcc.

universal reference, perfect forwarding
```
    template<typename T> void func(T&& param) {
        // Perfect forwarding.
        // when passed into another_func, param's l/r-value category is reserved
        another_func(std::forward<T>(param)); 
    }

    int x = 10;
    func(x);         // T is deduced as int&, so param is int& && = int&
    func(20);        // T is deduced as int, so param is int&&
```

forward v.s. move
    move turn everything into rvalue reference, forward keep its value catergory
    src here:
        /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include/c++/v1/__utility/move.h
        /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include/c++/v1/__utility/forward.h

allocator<Tp>:
    provide handy destructor for Tp* p.
    Imagine you are going to delete an array of n + 1 Tp object starts from Tp* p1
    then what you should do is to 
        1. allocator<Tp>::destroy(p1), ...allocator<Tp>::destroy(p1 + n) 
            i.e. p1->~Tp, ...., (p1 + n)->~Tp
        2. allocator<Tp>::deallocate(p1, n + 1), i.e. delete p1

__compressed_pair:
    __compressed_pair_elem<Tp>: 
        private inherit + empty base class Tp -> zero memory overhead

vector:
    pointer __begin_ = nullptr;
    pointer __end_ = nullptr;
    __compressed_pair<pointer, allocator_type> __end_cap_ =
        __compressed_pair<pointer, allocator_type>(nullptr, __default_init_tag());
    
    allocator_type& __alloc();
    pointer& __end_cap();
    vector(_InputIterator __first, _InputIterator __last, ...)
        distinguish vector<int>(1, 3) and vector<int>(int*, int*)

Implementation details:
    __split_buffer for resizing the vector cap, pay attention to its destructor.
    _ConstructTransaction for construct a new elem at the end, pay attention to 
        its destructor.

Question:
    1. assign(_ForwardIterator __first, _ForwardIterator __last) may be
        incorrect. You need to call destructor on eveything before making assignment.
        vector& operator=(const vector& __x);
            vector<vector<int>> v;
            vector<int> v1 {1, 2, 3};
            v.push_back(v1);

            vector<vector<int>> w;
            vector<int> w1 {2, 3, 4};
            w.push_back(w1);
            
            # makes a call to 
            # assign(_ForwardIterator __first, _ForwardIterator __last), 
            # which does not clear v[0], and leaks memory?
            v = w; 
    
    1 solution:
        copy assignment would deal with memory inside _VSTD::copy
