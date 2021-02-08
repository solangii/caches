#ifndef LFU_H
#define LFU_H

#include "min_heap.h"

template <typename T>
struct CacheItem {
    int usedCount;  // The number of accesses after inserted to the cache.
    T item;

    explicit CacheItem(T _item = T(), int _usedCount = 0) {
        usedCount = _usedCount;
        item = _item;
    }

    bool operator == (const CacheItem<T> &other) const {
        return item == other.item;
    }
    bool operator < (const CacheItem<T> &other) const {
        return usedCount < other.usedCount;
    }
    bool operator > (const CacheItem<T> &other) const {
        return usedCount > other.usedCount;
    }
};

template <typename T>
class LFU {
    CacheItem<T>** cache;
    const int size;
    int misses;
    int cur_size;
    int hint_index;
    //I add two variable `int cur_size`, `int hint_index` as class member variable. `cur_size` means the number of data in cache. Also, `hint_index` is used at `touch()` as hint index of `make_heap()`.


public:
    LFU(int _size) : size(_size), misses(0), cur_size(0), hint_index(-1) {

        this->cache = new CacheItem<T>*[size];

        for(int i=0; i<this->size; i++){
            this->cache[i] = nullptr;
        }
        // Constructor - initialization member variable and pointer.
    }

    ~LFU() {
        for(int i=0; i<this->size; i++){
            if(this->cache[i] != nullptr){
                delete this->cache[i];
            }
        }
        delete[] this->cache;
        // Destructor - delete the pointer dynamic allocated.
    }
    CacheItem<T>* find(T _item){ // my implementation : if find item in cache, return cache ptr
        for(int i=0; i < this->size; i++){
            if(cache[i] != nullptr){
                if(cache[i]->item == _item){
                    this->hint_index = i;
                    return this->cache[i];
                }
            }
        }
        return nullptr;
    }

    bool exists(T item) {
        return find(item) != nullptr;
        // Return true if data exists in the cache
        // Return false otherwise
    }

    int status() const {
        return this->cur_size;
        // Return number of elements in cache
    }

    bool touch(T item) { // Return true on hit, false on miss. This function uses the `exists()` to check if the item exists in cache. If the item exists then check cache is full or not, and if the cache is full, delete the value that used to have a small number of access through `pop()` and insert a new value through `push`. (This is implemented through MinHeap.) If the cache is not full, just add a value through `push()`. If there exists an item in the cache already, add 1 more `used_count` of the corresponding `CacheItem` and reorder the heap.
        if(exists(item)){
            find(item)->usedCount++;
            MinHeap<CacheItem<T>*>::make_heap(cache,cur_size,hint_index);
            return true;
        }
        else{
            if(cur_size < size){
                CacheItem<T>* dataPtr = new CacheItem<T>;
                dataPtr->item = item;
                dataPtr->usedCount = 0;

                MinHeap<CacheItem<T>*>::push(cache,cur_size,dataPtr);

                this->misses++;
                this->cur_size++;

            }
            else{ //cur_size == size
                MinHeap<CacheItem<T>*>::pop(cache,cur_size);

                CacheItem<T>* temp = cache[cur_size-1];
                delete temp;
                cache[cur_size-1] = nullptr;
                this->cur_size--;


                CacheItem<T>* dataPtr = new CacheItem<T>;
                dataPtr->item = item;
                dataPtr->usedCount = 0;

                MinHeap<CacheItem<T>*>::push(cache,cur_size,dataPtr);

                this->misses++;
                this->cur_size++;


            }
            return false;
        }

        // The data is being accessed
        // Return true on hit, false on miss
        // i.e. return true if it existed, and false when it was not
    }

    int getMisses() {
        return this->misses;
        // Return the number of cache misses until now
    }
};
#endif