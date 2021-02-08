#include <iostream>
#include "new_lfu.h"

int main(void) {
    const int requests = 1000000; // number of cache requests
    const int items = 200;        // number of items subject to requests
    const int cache_size = 16;

    LFU<int> lfu(cache_size);

    for (int i = 0; i < requests; ++i) {
        int number = i % items;

        lfu.touch(number);
    }

    std::cout << "lfu: " << lfu.getMisses() << '\n';


    std::cout << "double test"<< '\n';
    LFU<double> lfu1(cache_size);
    for (int i = 0; i < requests; ++i) {
        double number = (i % items)*0.3;

        lfu1.touch(number);
    }
    std::cout << "lfu1: " << lfu1.getMisses() << '\n';


    LFU<char> lfu2(cache_size);
    for (int i = 0; i < requests; ++i) {
        char number = (i % items)*0.3;

        lfu2.touch(number);
    }
    std::cout << "lfu2: " << lfu2.getMisses() << '\n';



    return 0;
}
