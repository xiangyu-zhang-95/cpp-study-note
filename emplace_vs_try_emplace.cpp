#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <string>


int main() {

    std::unordered_map<int, std::unique_ptr<long>> _map;
    _map.insert({1, std::make_unique<long>(13L)});
    for (auto& [key, value]: _map) {
        std::cout << "key: " << key << ", *value: " << *value << std::endl;
    }

    auto q = std::make_unique<long>(15L);
    _map.try_emplace(1, std::move(q));
    for (auto& [key, value]: _map) {
        std::cout << "key: " << key << ", *value: " << *value << std::endl;
    }
    std::cout << "q: " << q << ", *q: " << *q << std::endl;

    _map.emplace(1, std::move(q));
    for (auto& [key, value]: _map) {
        std::cout << "key: " << key << ", *value: " << *value << std::endl;
    }
    std::cout << "q: " << q << std::endl;

}
