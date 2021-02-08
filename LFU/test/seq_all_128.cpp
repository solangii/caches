#include <iostream>
#include "lfu.h"

int main(void) {
    const int requests = 1000000; // number of cache requests
    const int items = 200;        // number of items subject to requests
    const int cache_size = 128;

    LFU<int> lfu(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number = i % items;

        lfu.touch(number);
    }

    std::cout << "lfu: " << lfu.getMisses() << '\n';

    return 0;
}
