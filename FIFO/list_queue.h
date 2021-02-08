//20181041 kim solang
//
//final
#include "list.h"

template <class T>
class ListQueue {
    LinkedList<T> list;

public:
    ListQueue()= default;
    ~ListQueue()= default;

    T& front() {
        return list.front();
    }

    void pop() {
        list.pop_front();
    }

    bool empty() {
        return list.size() == 0;
    }

    int size() {
        return list.size();
    }

    void push(T& val) {
        list.push_back(val);
    }

};
