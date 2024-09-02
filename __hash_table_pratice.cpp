#include <__hash_table>
#include <cassert>
#include <cstring>
#include <iostream>
#include <sys/_types/_size_t.h>
#include <type_traits>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <unordered_set>

using namespace std;

template <class _Tp, class _Hash, class _Equal, class _Alloc>
class __my_hash_table
{
public:
    typedef _Tp    value_type;
    typedef _Hash  hasher;
    typedef _Equal key_equal;
    typedef _Alloc allocator_type;

public:
    typedef allocator_traits<allocator_type> __alloc_traits;
    typedef typename
      __make_hash_node_types<value_type, typename __alloc_traits::void_pointer>::type
                                                                     _NodeTypes;

public:

    typedef typename _NodeTypes::__node_value_type           __node_value_type;
    typedef typename _NodeTypes::__container_value_type      __container_value_type;
    typedef typename _NodeTypes::key_type                    key_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef typename __alloc_traits::size_type       size_type;
    typedef typename _NodeTypes::difference_type     difference_type;

public:
    typedef typename _NodeTypes::__node_type __node;
    typedef typename __rebind_alloc_helper<__alloc_traits, __node>::type __node_allocator;
    typedef allocator_traits<__node_allocator>       __node_traits;
    typedef typename _NodeTypes::__void_pointer      __void_pointer;
    typedef typename _NodeTypes::__node_pointer      __node_pointer;
    typedef typename _NodeTypes::__node_pointer      __node_const_pointer;
    typedef typename _NodeTypes::__node_base_type    __first_node;
    typedef typename _NodeTypes::__node_base_pointer __node_base_pointer;
    typedef typename _NodeTypes::__next_pointer      __next_pointer;

public:
    // check for sane allocator pointer rebinding semantics. Rebinding the
    // allocator for a new pointer type should be exactly the same as rebinding
    // the pointer using 'pointer_traits'.
    static_assert((is_same<__node_pointer, typename __node_traits::pointer>::value),
                  "Allocator does not rebind pointers in a sane manner.");
    typedef typename __rebind_alloc_helper<__node_traits, __first_node>::type
        __node_base_allocator;
    typedef allocator_traits<__node_base_allocator> __node_base_traits;
    static_assert((is_same<__node_base_pointer, typename __node_base_traits::pointer>::value),
                 "Allocator does not rebind pointers in a sane manner.");


public:
    typedef typename __rebind_alloc_helper<__node_traits, __next_pointer>::type __pointer_allocator;
    typedef __bucket_list_deallocator<__pointer_allocator> __bucket_list_deleter;
    typedef unique_ptr<__next_pointer[], __bucket_list_deleter> __bucket_list;
    typedef allocator_traits<__pointer_allocator>          __pointer_alloc_traits;
    typedef typename __bucket_list_deleter::pointer       __node_pointer_pointer;


    // --- Member data begin ---
    __bucket_list                                         __bucket_list_;
    __compressed_pair<__first_node, __node_allocator>     __p1_;
    __compressed_pair<size_type, hasher>                  __p2_;
    __compressed_pair<float, key_equal>                   __p3_;
    // --- Member data end ---

};


struct my_unordered_set {
    void* ptr;
    long deleter_size;
    void* hash_node_base_next_ptr;
    long count;
    float load;
};

struct X { };

int main() {
    using ht_type = __my_hash_table<long, hash<long>, equal_to<long>, allocator<long>>;
    // std::cout << typeid(ht_type::__alloc_traits).name() << std::endl;
    std::cout << boolalpha;

    std::cout << std::is_same<ht_type::__alloc_traits::void_pointer, void*>::value << " ";
    std::cout << std::is_same<ht_type::_NodeTypes, __make_hash_node_types<long, void*>::type>::value << " ";
    std::cout << std::is_same<__rebind_pointer<void*, X>::type, X*>::value << " ";
    std::cout << std::is_same<
                    ht_type::_NodeTypes, 
                    __hash_node_types<__hash_node<long, void*>*>
                >::value << " ";
    
    __hash_node<long, void*> v;
    std::cout << std::is_same<decltype(v.__hash_), size_t>::value << " ";
    std::cout << std::is_same<decltype(v.__value_), long>::value << " ";
    std::cout << std::is_same<
                    decltype(v.__next_), 
                    __hash_node_base<
                        __hash_node<long, void*>* 
                    >*
                >::value << " ";
    std::cout << std::is_same<
                    __hash_node_types<__hash_node<long, void*>*>::__node_value_type,
                    long
                >::value << " ";
    std::cout << std::is_same<ht_type::pointer, long*>::value << " ";
    std::cout << std::is_same<
                    ht_type::__node_allocator, 
                    std::allocator<__hash_node<long, void*> >
                >::value << " ";
    std::cout << std::is_same<
                    ht_type::__pointer_allocator, 
                    std::allocator<__hash_node_base<
                        __hash_node<long, void*>* 
                    >*>
                >::value << " ";
    std::cout << std::is_same<
                    ht_type::size_type,
                    size_t
                >::value << " ";
    std::cout << std::is_same<
                    ht_type::__next_pointer, 
                    __hash_node_base<__hash_node<long, void*> *> *
                >::value << " ";
    std::cout << std::is_same<
                    ht_type::__first_node, 
                    __hash_node_base<__hash_node<long, void*> *>
                >::value << " ";
    std::cout << std::is_same<
                    allocator<long>,
                    decltype(std::unordered_set<long>().get_allocator())>::value << " ";
    std::cout << std::is_same<
                    ht_type::__node_pointer,
                    __hash_node<long, void*>*
                    >::value << " ";
    
    // TODO: how __bucket_list_deleter manages point[] array
    std::cout << std::endl;

    assert(sizeof(ht_type::__bucket_list) == 16);
    assert(sizeof(ht_type::__p1_) == 8);
    assert(sizeof(ht_type::__p2_) == 8);
    assert(sizeof(ht_type::__p3_) == 4);


    unordered_set<long> s_l(50);
    s_l.insert(10L); s_l.insert(20L); s_l.insert(30L);
    s_l.insert(40L); s_l.insert(50L); s_l.insert(60L);

    my_unordered_set my_s_l;
    assert(sizeof(my_s_l) == sizeof(s_l));
    assert(sizeof(my_s_l) == 40);
    memcpy(&my_s_l, &s_l, sizeof(s_l));

    std::cout << "ptr: " << my_s_l.ptr;
    std::cout << ", deleter_size: " << my_s_l.deleter_size;
    std::cout << ", hash_node_base_next_ptr: "; 
    std::cout << my_s_l.hash_node_base_next_ptr;
    std::cout << ", count: " << my_s_l.count;
    std::cout << ", load:  " << my_s_l.load << std::endl;
    


    unordered_set<long> empty_set;
    my_unordered_set my_empty_set;
    memcpy(&my_empty_set, &empty_set, sizeof(empty_set));

    std::cout << "ptr: " << my_empty_set.ptr;
    std::cout << ", deleter_size: " << my_empty_set.deleter_size;
    std::cout << ", hash_node_base_next_ptr: "; 
    std::cout << my_empty_set.hash_node_base_next_ptr;
    std::cout << ", count: " << my_empty_set.count;
    std::cout << ", load:  " << my_empty_set.load << std::endl;
    










    std::cout << std::endl;
}