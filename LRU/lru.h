#ifndef LRU_H
#define LRU_H

#include <iostream>
#include "bst.h"
#include "list.h"

struct LRU_Unit {
    int value;
    TreeNode<int, Node<LRU_Unit>*>* tn;

    LRU_Unit(int val = int(), TreeNode<int, Node<LRU_Unit>*>* _tn = nullptr) {
        value = val;
        tn = _tn;
    }

    bool operator==(const LRU_Unit&data)const {
        return value == data.value;

    }


};

std::ostream& operator<< (std::ostream& os, const LRU_Unit& unit){
    std::cout<<unit.value;
    return os;
}

class LRU {
    BinarySearchTree<int, Node<LRU_Unit>*> bst;
    LinkedList<LRU_Unit> list;
    int size;
    int misses;
    // You may add private helper functions if you need them
    int cur_size;

public:
    LRU(int _size) {
        this->size = _size;
        this->misses = 0;

        this->cur_size=0;
        // Constructor
    }

    ~LRU() {
        list.clear();
        bst.clear();
        // Destructor
    }

    bool exists(int data) {
        return list.find(data) != nullptr;
        // Return true if data exists in the cache
        // Return false otherwise
    }

    int status() const {
        return list.size();
        // Return number of elements in cache
    }

    bool touch(int data) {
        if(exists(data)){ //data가 cache에 있는 경우
            //todo 위치를 옮겨야한다.
            //search and remove target data
            list.erase(list.find(data));

            //가장 최근 위치에 재 삽입 + tn 수정.
            list.push_back(data)->item.tn = bst.search(data);

            //tree node val 수정
            bst.search(data)->val = list.backpointer();

            return true;
        }
        else{
            if(cur_size == size){
                //가장 오래된 data delete
                list.pop_front();
                bst.remove(bst.search(data));

                //push data and update tn
                list.push_back(data)->item.tn = bst.search(data);
                bst.insert(data,list.backpointer());

                //update member variable
                misses++;
                return false;
            }
            else{ //cursize < size 
                //push data and update tn
                list.push_back(data)->item.tn = bst.search(data);
                bst.insert(data,list.backpointer());

                //update member variable
                cur_size++;
                misses++;
                return false;
            }
            //data 추가.
        }
        // The data is being accessed
        // Return true on hit, false on miss
        // i.e. return true if it existed, and false when it was not
    }

    int get_misses() {
        return misses;
        // Return the number of cache misses until now
    }

    void print() const {
        bst.print();
        list.print();
    }
};

#endif