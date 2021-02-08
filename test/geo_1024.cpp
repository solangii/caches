#include <iostream>
#include <random>
#include "lfu.h"

int main(void) {
    // source: http://www.cplusplus.com/reference/random/geometric_distribution/
    const int requests = 1000000; // number of cache requests
    const int items = 10000;      // number of items subject to requests
    const int cache_size = 1024;

    std::default_random_engine generator;
    std::geometric_distribution<int> distribution(5.0 / items);

    LFU<int> lfu(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number;
        do {
            number = distribution(generator);
        } while (number >= items);

        lfu.touch(number);
    }

    std::cout << "lfu: " << lfu.getMisses() << '\n';

    return 0;
}
