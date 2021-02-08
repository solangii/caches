#ifndef RAND_H
#define RAND_H

#include <iostream>
#include <random>

class Rand {
    // Add member
    int** arr;
    int size;
    int misses;
    int num;

    std::default_random_engine gen;
    std::uniform_int_distribution<int>* dis;

    // You may add private helper functions if you need them

public:
    Rand(int _size) {
        this->size = _size;
        arr = new int*[size];
        this->misses = 0;
        this->num = 0;

        dis = new std::uniform_int_distribution<int>(0,size-1);

        for(int i=0; i<size; i++){
            arr[i] = nullptr;
        }

        //todo array 전부 nullptr로 초기
        // Constructor
    }

    ~Rand() {

        for(int i=0; i<size;i++){
            if(arr[i] != nullptr){
                delete arr[i];
            }
        }
        delete[] arr;
        delete dis;
        // Destructor
    }

    bool exists(int data) {
        for(int i = 0; i < size; i++){
            if(arr[i] != nullptr){
                int* temp = arr[i];

                if( *temp == data){
                    return true;
                }
            }

        }
        return false;
        // Return true if data exists in the cache
        // Return false otherwise
    }

    int status() {
        return this->num;
        // Return number of elements in cache
    }

    bool touch(int data) {
        if(this->exists(data)){
            return true;
        }
        else{
            int* dataPtr = new int;
            *dataPtr = data;

            int random_index = (*dis)(gen);

            if(num == size){
                //랜덤으로 하나를 삭제
                int* temp = arr[random_index];
                delete temp;
                arr[random_index] = nullptr;

                //그 자리에 새거 넣음
                arr[random_index] = dataPtr;

                this->misses++;

                return false;
            }
            else{
                //빈 자리에 새거 넣음
                arr[emptyindex()] = dataPtr;

                this->misses++;
                this->num++;

                return false;
            }
        }
        // The data is being accessed
        // Return true on hit, false on miss
        // i.e. return true if it existed, and false when it was not
    }

    int emptyindex(){
        int index;
        for(int i=0; i<size; i++){
            if(arr[i] == nullptr){
                index = i;
                break;
            }
        }
        return index;
    }

    int get_misses() {
        return this->misses;
        // Return the number of cache misses until now
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            if (arr[i] != nullptr) {
                std::cout << *arr[i] << ' ';
            }
        }
        std::cout << '\n';
    }
};

#endif