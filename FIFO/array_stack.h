//20181041 kim solang
//
//final
template <class T>
class ArrayStack {
    T* _array;
    int length;
    int allsize;

public:
    explicit ArrayStack() {
        int INIT=128;

        allsize = INIT;
        length =0;

        _array = new T[INIT];
    }

    ~ArrayStack() {
        delete[] _array;
        length=0;
    }

    T& top() {
        return _array[length-1];
    }

    void pop() {
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
        if(this->length >= this->allsize){
            resizing();
        }

        _array[length]=item;
        length++;
    }
    
};