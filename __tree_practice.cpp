#include <__tree>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

template <class _Tp, class _Compare, class _Allocator>
class __my_tree
{
public:
    typedef _Tp                                      value_type;
    typedef _Compare                                 value_compare;
    typedef _Allocator                               allocator_type;

public:
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __make_tree_node_types<value_type,
        typename __alloc_traits::void_pointer>::type
                                                    _NodeTypes;
    typedef typename _NodeTypes::key_type           key_type;

public:
    typedef typename _NodeTypes::__node_value_type      __node_value_type;
    typedef typename _NodeTypes::__container_value_type __container_value_type;

    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef typename __alloc_traits::size_type       size_type;
    typedef typename __alloc_traits::difference_type difference_type;

public:
    typedef typename _NodeTypes::__void_pointer        __void_pointer;

    typedef typename _NodeTypes::__node_type           __node;
    typedef typename _NodeTypes::__node_pointer        __node_pointer;

    typedef typename _NodeTypes::__node_base_type      __node_base;
    typedef typename _NodeTypes::__node_base_pointer   __node_base_pointer;

    typedef typename _NodeTypes::__end_node_type       __end_node_t;
    typedef typename _NodeTypes::__end_node_pointer    __end_node_ptr;

    typedef typename _NodeTypes::__parent_pointer      __parent_pointer;
    typedef typename _NodeTypes::__iter_pointer        __iter_pointer;

    typedef typename __rebind_alloc_helper<__alloc_traits, __node>::type __node_allocator;
    typedef allocator_traits<__node_allocator>         __node_traits;

};



int main() {
    using tree_type = __my_tree<long, less<long>, allocator<long>>;

    cout << boolalpha;
    cout << is_same_v<tree_type::value_type, long> << " ";
    cout << is_same_v<tree_type::value_compare, less<long>> << " ";
    cout << is_same_v<tree_type::allocator_type, allocator<long>> << " ";
    cout << is_same_v<tree_type::__alloc_traits, 
                      allocator_traits<allocator<long>>> << " ";
    cout << is_same_v<
                    tree_type::_NodeTypes, 
                    __tree_node_types<__tree_node<long, void*> *>
                > << " ";
    cout << is_empty_v<tree_type::_NodeTypes> << " ";
    cout << is_same_v<tree_type::key_type, long> << " ";
    cout << is_same_v<tree_type::__node_value_type, long> << " ";
    cout << is_same_v<tree_type::__container_value_type, long> << " ";
    cout << is_same_v<tree_type::pointer, long*> << " ";
    cout << is_same_v<tree_type::const_pointer, const long*> << " ";
    cout << is_same_v<tree_type::size_type, size_t> << " ";
    cout << is_same_v<tree_type::__void_pointer, void*> << " ";
    cout << is_same_v<tree_type::__node, __tree_node<long, void*>> << " ";
    cout << is_same_v<tree_type::__node_pointer, __tree_node<long, void*>*> << " ";
    cout << is_same_v<tree_type::__node_base, __tree_node_base<void*>> << " ";
    cout << is_same_v<tree_type::__node_base_pointer, __tree_node_base<void*>*> << " ";
    cout << is_same_v<
                        tree_type::__end_node_t, 
                        __tree_end_node<__tree_node_base<void*> *> 
                    > << " ";
    cout << is_same_v<
                        tree_type::__end_node_ptr, 
                        __tree_end_node<__tree_node_base<void*> *> *
                    > << " ";
    cout << is_same_v<tree_type::__parent_pointer, tree_type::__end_node_ptr> << " ";
    cout << is_same_v<tree_type::__node_allocator, allocator<__tree_node<long, void*>>> << " ";
    cout << is_same_v<tree_type::__iter_pointer, tree_type::__end_node_ptr> << " ";
    cout << is_same_v<__tree_node_base_types<void*>::__end_node_type, 
                        __tree_end_node<__tree_node_base<void*> *>
                    > << " ";
    cout << is_same_v<__tree_node_base_types<void*>::__node_base_pointer, 
                        __tree_node_base<void*> *
                    > << " ";
    cout << is_same_v<__tree_node_base_types<void*>::__parent_pointer, 
                        __tree_end_node<__tree_node_base<void*> *>*
                    > << " ";
    







    cout << endl;

}