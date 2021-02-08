#include <iostream>
#include <random>
#include "lfu.h"

int main(void) {
    // source: http://www.cplusplus.com/reference/random/uniform_int_distribution/
    const int requests = 1000000; // number of cache requests
    const int items = 10000;      // number of items subject to requests
    const int cache_size = 16;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, items - 1);

    LFU<int> lfu(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number = distribution(generator);
        lfu.touch(number);
    }

    std::cout << "lfu: " << lfu.getMisses() << '\n';

    return 0;
}
