//20181041 kim solang
//
//final
#ifndef LIST_H
#define LIST_H

template <class T>
class Node {
public:
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
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    LinkedList() {
        head = new Node<T>;
        tail = new Node<T>;

        head->prev = nullptr;
        head->next = tail;

        tail->prev = head;
        tail->next = nullptr;

        length=0;

    }

    ~LinkedList() {
        clear();
        delete head;
        delete tail;
        length=0;

    }

    int size() {
        return this->length;
    }

    bool empty() {
        return this->length == 0;
    }

    T& front() {
        return ((this->head)->next)->item;
    }

    T& back() {
        return ((this->tail)->prev)->item;
    }

    void insert(Node<T>* node_before, T val) {

        Node<T>* Newnode = new Node<T>(val);
        Node<T>* Temp;
        Temp = (node_before->next);

        Newnode->next = Temp;
        Newnode->prev = node_before;
        node_before->next = Newnode;
        Temp->prev = Newnode;

        this->length++;

    }

    void erase(Node<T>* target) {

        Node<T>* Nextnode = target->next;
        Node<T>* Beforenode = target->prev;

        Nextnode->prev = Beforenode;
        Beforenode->next = Nextnode;

        delete target;
        this->length--;
    }

    void push_front(T val) {
        insert(this->head, val);

    }

    void pop_front() {
        erase(head->next);
    }

    void push_back(T val) {
        Node<T>* Newnode = new Node<T>(val);
        Node<T>* Temp;

        Temp = tail->prev;

        tail->prev = Newnode;
        Newnode->next = tail;

        Newnode->prev = Temp;
        Temp->next = Newnode;

        this->length++;

    }

    void pop_back() {
        erase(tail->prev);
    }

    void clear() {
        Node<T>* target;
        Node<T>* Temp=head->next;

        while(head->next != tail){
            target = Temp;
            Temp=Temp->next;
            erase(target);
        }
    }

    Node<T>* find(T val) {
        Node<T>* Temp = head;
        for(int i=0; i<this->length; i++){
            Temp = Temp->next;
            if(Temp->item == val){
                break;
            }

        }
        return Temp;
    }


};

#endif