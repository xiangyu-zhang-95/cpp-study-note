#include <functional>
#include <ios>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <memory>

#include <cassert>

#include <iostream>
#include <vector>



struct vector_int_hash {
    size_t operator()(const std::vector<int>& v) const {
        size_t res = 0;
        for (auto val: v) {
            res += (val > 0? val: -val);
        }
        return res;
    }
};

struct my_unordered_set {
    void* ptr;
    long deleter_size;
    void* hash_node_base_next_ptr;
    long count;
    float load;
};


int main() {

    std::unordered_set<std::vector<int>, vector_int_hash> s_v {10, vector_int_hash()};
    s_v.insert(std::vector<int>{1, 2, 3});
    s_v.insert(std::vector<int>{6});
    s_v.insert(std::vector<int>{-1, 2, 3});
    
    s_v.insert(std::vector<int>{7});

    s_v.insert(std::vector<int>{2, 2, 2});

    std::cout << "#####################################" << std::endl;
    for (const auto& v: s_v)  {
        for (auto val: v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "#####################################" << std::endl;
    std::cout << "bucket count :   " << s_v.bucket_count() << std::endl;
    std::cout << "max bkt-count: 0x" << std::hex << s_v.max_bucket_count() << std::endl;
    std::cout << "idx of {1, 2, 3}:" << s_v.bucket(std::vector<int>{1, 2, 3}) << std::endl;
    std::cout << "bucket_size of 6:" << s_v.bucket_size(s_v.bucket(std::vector<int>{1, 2, 3})) << std::endl;
    std::cout << "bucket_size of 7:" << s_v.bucket_size(7) << std::endl;
    std::cout << "#####################################" << std::endl;
    std::cout << std::dec;
    std::unordered_set<long> s_l;
    // s_l.insert(10L); s_l.insert(20L); s_l.insert(30L);
    std::cout << "sizeof(s_l): " << sizeof(s_l) << std::endl;

    using namespace std;
    std::cout << sizeof(unordered_set<long>) << std::endl;
    std::cout << "sizeof(s_l): " << sizeof(std::unordered_set<long>) << std::endl;
    


}