//20181041 kim solang
//
//final
#include "list.h"

template <class T>
class ListStack {
    LinkedList<T> list;

public:
    ListStack()= default;
    ~ListStack()= default;

    T& top() {
        return list.back();
    }

    void pop() {
        list.pop_back();
    }

    bool empty() {
        return list.size() == 0;
    }

    int size() {
        return list.size();
    }

    void push(T& item) {
        list.push_back(item);
    }

};
