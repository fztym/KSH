#include <iostream>
#include <string>
#include "LRU.h"

auto main() -> int
{
    LRU<std::string, int> cache;
    cache.put("A", 2);
    cache.put("B", 1);
    std::cout << cache.get("A") << '\n';
    return 0;
}