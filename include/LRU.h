#ifndef LRU_H
#define LRU_H

#include <list>
#include <unordered_map>
#include <stdexcept>

template <typename KeyType, typename ValueType>
class LRU
{
public:
    LRU(size_t cap = 128) : capacity(cap) {}
    LRU(const LRU &other) : cacheList(other.cacheList), capacity(other.capacity)
    {
        cacheMap.clear();
        cacheMap.reserve(other.cacheMap.size());
        for (auto it = cacheList.begin(); it != cacheList.end(); ++it)
        {
            cacheMap.emplace(it->first, it);
        }
    }
    LRU &operator=(const LRU &other)
    {
        if (this != &other)
        {
            cacheList = other.cacheList;
            cacheMap.clear();
            cacheMap.reserve(other.cacheMap.size());
            for (auto it = cacheList.begin(); it != cacheList.end(); ++it)
            {
                cacheMap.emplace(it->first, it);
            }
            capacity = other.capacity;
        }
        return *this;
    }
    LRU(LRU &&other) : cacheList(std::move(other.cacheList)), cacheMap(std::move(other.cacheMap)), capacity(other.capacity) {}
    LRU &operator=(LRU &&other)
    {
        if (this != &other)
        {
            cacheList = std::move(other.cacheList);
            cacheMap = std::move(other.cacheMap);
            capacity = other.capacity;
        }
        return *this;
    }
    void put(const KeyType &key, const ValueType &value)
    {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end())
        {
            it->second->value = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }
        cacheList.push_front({key, value});
        cacheMap.emplace(key, cacheList.begin());

        if (cacheMap.size() > capacity)
        {
            auto dummyKey = cacheList.back().key;
            cacheMap.erase(dummyKey);
            cacheList.pop_back();
        }
    }
    const ValueType &get(const KeyType &key)
    {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end())
        {
            throw std::out_of_range("Key not found!");
        }
        auto &value = it->second->value;
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        // don't need to modify cacheMap[key] as the iterator does not change
        return value;
    }

private:
    struct Node
    {
        KeyType key;
        ValueType value;
    };
    using ListIterator = typename std::list<Node>::iterator;
    std::list<Node> cacheList;
    std::unordered_map<KeyType, ListIterator> cacheMap;
    size_t capacity;
};

#endif // LRU_H