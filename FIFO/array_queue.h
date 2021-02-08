template <class T>
class ArrayQueue {
    T* _array;
    int length;
    int allsize;
    int first;
    int last;

public:
    ArrayQueue() {
        int INIT=128;

        allsize = INIT;
        length =0;
        first=0;
        last=0;

        _array = new T[INIT];
    }

    ~ArrayQueue() {
        delete[] _array;
        length=0;
    }

    T& front() {
        return _array[first];
    }

    void pop() {
        first++;
        length--;
    }


    bool empty() {
        return this->size() == 0;
    }


    int size() {
        return this->length;
    }

    void resizing(){

        T* new_array = new T[allsize*2];

        for(int i=0; i<allsize;i++){
            new_array[i] = _array[i];
        }

        allsize = allsize*2;
        delete[] _array;
        _array = new_array;

    }

    void push(T& item) {
        if (this->last >= this->allsize){
            resizing();
        }
        _array[last]=item;
        length++;
        last++;

    }

};
