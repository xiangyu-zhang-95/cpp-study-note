#include <ios>
#include <memory>
#include <iostream>
#include <type_traits>

template <class _Tp>
struct my_delete {
    long val = 16;
    my_delete() noexcept = default;
    void operator()(_Tp* __ptr) const _NOEXCEPT {
        std::cout << "my_delete of type " << typeid(_Tp).name() << " at " << __ptr << " with value " << *__ptr << std::endl;
        delete __ptr;
    }
};



template<class T, bool tag=!std::is_pointer<T>::value>
struct foo {
    using type_arg = double;
};


template<class T>
struct foo<T, true> {
    using type_arg = T;
};




int main() {
    std::unique_ptr<int, my_delete<int>> ptr{new int{5}};

    using ptr_type = decltype(ptr);

    std::cout << std::boolalpha;
    std::cout << std::is_same<ptr_type::deleter_type, my_delete<int>>::value << std::endl;
    std::cout << std::is_same<ptr_type::element_type, int>::value << std::endl;
    std::cout << std::is_same<ptr_type::pointer, int*>::value << std::endl;

    std::cout << !std::__libcpp_is_final<int*>::value << std::endl;

    std::cout << std::is_same<foo<int*, true>::type_arg, int*>::value << std::endl;
    std::cout << std::is_same<foo<int, true>::type_arg, int>::value << std::endl;

    std::cout << std::is_same<foo<int>::type_arg, int>::value << std::endl;
    std::cout << std::is_same<foo<int*>::type_arg, double>::value << std::endl;

    std::cout << sizeof(ptr) << std::endl;
    std::cout << sizeof(int*) << std::endl;

}