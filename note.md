__attribute__((__type_visibility__("default"))):
    set the visibility to be default, linkable from other library. Someone may
    set their class to be hidden. This attribute is compiler-specific, i.e. gcc.

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


TODO:
    void reserve(size_type __n) -> __split_buffer
    void shrink_to_fit() -> __split_buffer

NEXT:
    void push_back()

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
