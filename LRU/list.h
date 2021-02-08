#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
struct Node {
    Node* prev;
    Node* next;
    T item;

    Node(T val = T()) {
        prev = nullptr;
        next = nullptr;
        item = val;
    }
};

template <class T>
class LinkedList {
    // Dummy nodes: Textbook 2.11
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        // Constructor
        head = new Node<T>;
        tail = new Node<T>;

        head->prev = nullptr;
        head->next = tail;

        tail->prev = head;
        tail->next = nullptr;
    }

    ~LinkedList() {
        // Destructor
        clear();
        delete head;
        delete tail;
    }

    int size() const {
        // Return the number of elements in list.
        int count = 0;
        for (auto* curr = head->next; curr != tail; curr = curr->next) {
            count += 1;
        }

        return count;
    }

    bool empty() {
        // Return true if no elements are in list and false otherwise.
        return head->next == tail;
    }

    T& front() {
        // Return the front (first) element.
        // Note the return type.
        // It is REFERENCE (not value) of the ITEM (not Node).
        return head->next->item;
    }

    T& back() {
        // Return the back (last) element.
        // Same note as in front().
        return tail->prev->item;
    }

    Node<T>* backpointer(){
        //my implement
        //return the pointer of last element
        return tail->prev;
    }

    Node<T>* insert(Node<T>* node_before, T val) {
        // Create a node with val. Insert it after node_before.
        // i.e. node_before -> new node -> node_before->next
        // CHANGED: It now returns the pointer to newly inserted node.
        auto* new_node = new Node<T>(val);
        new_node->prev = node_before;
        new_node->next = node_before->next;

        node_before->next->prev = new_node;
        node_before->next = new_node;

        return new_node;
    }

    void erase(Node<T>* target) {
        // Remove one node from the list.
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
    }

    Node<T>* push_front(T val) {
        // Create a node with val. Add it to the front of the list.
        return insert(head, val);
    }

    void pop_front() {
        // Remove the front node.
        Node<T>* target = head->next;
        erase(target);
    }

    Node<T>* push_back(T val) {
        // Create a node with val. Add it to the back of the list.
        return insert(tail->prev, val);
    }

    void pop_back() {
        // Remove the back node.
        Node<T>* target = tail->prev;
        erase(target);
    }

    void clear() {
        // Remove all nodes in list.
        while (!empty()) {
            pop_front();
        }
    }

    Node<T>* find(T val) {
        // Return the pointer of first node with the item val.
        for (Node<T>* curr = head->next; curr != tail; curr = curr->next) {
            if (curr->item == val) {
                return curr;
            }
        }

        // NEW REQUIREMENT: return nullptr when not found.
        return nullptr;
    }

    void print(void) const {
        // Print the node info
        for (auto* curr = head->next; curr != tail; curr = curr->next) {
            std::cout << curr->item << ' ';
        }
        std::cout << std::endl;
    }
};

#endif
