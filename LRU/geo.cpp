#include <iostream>
#include "lru.h"
#include "rand.h"

int main(void) {
    // source: http://www.cplusplus.com/reference/random/geometric_distribution/
    const int requests = 1000000; // number of cache requests
    const int items = 10000;      // number of items subject to requests
    const int cache_size = 100;

    std::default_random_engine generator;
    std::geometric_distribution<int> distribution(5.0 / items);

    LRU lru(cache_size);
    Rand rand(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number;
        do {
            number = distribution(generator);
        } while (number >= items);

        lru.touch(number);
        rand.touch(number);
    }

    std::cout << "lru: " << lru.get_misses() << '\n';
    std::cout << "rand: " << rand.get_misses() << '\n';

    return 0;
}
