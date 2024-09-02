#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <string>

struct X {
    long x;
    explicit X (long x): x{x} {std::cout << "construct X with " << x << std::endl; }
};

std::ostream& operator<<(std::ostream& os, X x) {
    os << x.x;
    return os;
}

int main() {
    std::unordered_map<int, std::string> v {{1, "qwe"}, {2, "ew"}};
    for (auto& [key, value]: v) {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }

    std::unordered_map<int, std::unique_ptr<long>> _map;
    _map.insert({1, std::make_unique<long>(13L)});
    for (auto& [key, value]: _map) {
        std::cout << "key: " << key << ", *value: " << *value << std::endl;
    }

    std::cout << "\n######################### move started #########################" << std::endl;
    auto p = std::make_unique<long>(14L);
    _map.try_emplace(2, std::move(p));
    for (auto& [key, value]: _map) {
        std::cout << "key: " << key << ", *value: " << *value << std::endl;
    }
    std::cout << p << std::endl;

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
    std::cout << "q: " << q << ", *q: " << *q << std::endl;

    _map.insert({1, std::move(q)});
    for (auto& [key, value]: _map) {
        std::cout << "key: " << key << ", *value: " << *value << std::endl;
    }
    std::cout << "q: " << q << std::endl;


    std::cout << "\n######################### X started #########################" << std::endl;
    std::unordered_map<int, X> x_map;
    x_map.insert({1, X(10L)});
    for (auto& [key, value]: x_map) {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }

    x_map.emplace(1, 13L);
    for (auto& [key, value]: x_map) {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }

    x_map.try_emplace(1, 13L);
    for (auto& [key, value]: x_map) {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }
}

