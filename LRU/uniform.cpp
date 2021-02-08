#include <iostream>
#include "lru.h"
#include "rand.h"

int main(void) {
    // source: http://www.cplusplus.com/reference/random/uniform_int_distribution/
    const int requests = 1000000; // number of cache requests
    const int items = 10000;      // number of items subject to requests
    const int cache_size = 100;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, items - 1);

    LRU lru(cache_size);
    Rand rand(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number = distribution(generator);
        lru.touch(number);
        rand.touch(number);
    }

    std::cout << "lru: " << lru.get_misses() << '\n';
    std::cout << "rand: " << rand.get_misses() << '\n';

    return 0;
}
