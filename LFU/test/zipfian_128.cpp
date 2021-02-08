#include <iostream>
#include <fstream>
#include "lfu.h"

int* make_array(const char* file_name, const int requests) {
    int* array = new int[requests];
    std::ifstream in;
    in.open(file_name);

    for (int i = 0; i < requests; ++i) {
        in >> array[i];
    }
    std::cout << array[requests - 1] << std::endl;

    return array;
}

int main(void) {
    const int requests = 1000000; // number of cache requests
    const int items = 200;        // number of items subject to requests
    const int cache_size = 128;

    LFU<int> lfu(cache_size);
    int* zipfian_array = make_array("zipfian_1000000.txt", requests);

    for (int i = 0; i < requests; ++i) {
        lfu.touch(zipfian_array[i]);
    }

    std::cout << "lfu: " << lfu.getMisses() << '\n';

    delete[] zipfian_array;

    return 0;
}

