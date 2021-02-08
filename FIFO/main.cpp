#include <iostream>
#include "list.h"
#include "array_queue.h"
#include "array_stack.h"
#include "list_queue.h"
#include "list_stack.h"

int main() {
    // Step 1: Linked List
    LinkedList<int> l;

    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }

    while (!l.empty()) {
        std::cout << l.front() << ' ';
        l.pop_front();
    }
    std::cout << '\n';

    LinkedList<double> double_list;

    double_list.push_back(2.3);
    double_list.push_back(4.1);
    double_list.insert(double_list.find(2.3), 3.7);
    double_list.insert(double_list.find(2.3), 3.1);
    double_list.insert(double_list.find(4.1), 4.3);
    double_list.erase(double_list.find(4.1));

    std::cout << double_list.size() << '\n';

    while (!double_list.empty()) {
        std::cout << double_list.back() << ' ';
        double_list.pop_back();
    }

    //output 
    /*
0 1 2 3 4 5 6 7 8 9 
4
4.3 3.7 3.1 2.3 
    */

    // Step 2: Queues
    ArrayQueue<int> aq;
    ListQueue<int> lq;
    for (int i = 0; i < 100; ++i) {
        int num = 7 * i % 10 + (13 * i % 10) * 10;
        aq.push(num);
        lq.push(num);
    }

    while (!lq.empty()) {
        if (aq.empty()) {
            std::cout << "array queue empty when list queue is not\n";
        }

        if (lq.front() != aq.front()) {
            std::cout << "different in queues\n";
            return 0;
        }

        lq.pop();
        aq.pop();
    }

    if (!aq.empty()) {
        std::cout << "list stack empty when array stack is not\n";
    }

    // Step 3: Stacks
    ArrayStack<int> as;
    ListStack<int> ls;
    for (int i = 0; i < 100; ++i) {
        int num = 7 * i % 10 + (13 * i % 10) * 10;
        as.push(num);
        ls.push(num);
    }

    while (!ls.empty()) {
        if (as.empty()) {
            std::cout << "array stack empty when list stack is not\n";
        }

        if (ls.top() != as.top()) {
            std::cout << "different in stacks\n";
            return 0;
        }

        ls.pop();
        as.pop();
    }

    if (!as.empty()) {
        std::cout << "list stack empty when array stack is not\n";
    }

    return 0;
}
