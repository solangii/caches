#include <iostream>
#include "lru.h"
#include "rand.h"

int main(void) {
    const int requests = 1000000; // number of cache requests
    const int items = 200;        // number of items subject to requests
    const int cache_size = 100;

    LRU lru(cache_size);
    Rand rand(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number = i % items;

        lru.touch(number);
        rand.touch(number);
    }

    std::cout << "lru: " << lru.get_misses() << '\n';
    std::cout << "rand: " << rand.get_misses() << '\n';

    return 0;
}
