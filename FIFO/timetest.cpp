#include <iostream>
#include "list.h"
#include "array_queue.h"
#include "array_stack.h"
#include "list_queue.h"
#include "list_stack.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    // Queues
    ArrayQueue<int> aq;
    ListQueue<int> lq;

    clock_t start_ar, end_ar, start_li, end_li;
    double result_ar, result_li;

    start_ar = clock();
    for (int i=0; i<1000000; i++){
        int num = rand();
        aq.push(num);
    }
    end_ar = clock();
    result_ar = (double)(end_ar-start_ar);
    cout<<"array push runtime : "<<result_ar<<endl;

    start_li = clock();
    for (int i=0; i<1000000; i++){
        int num = rand();
        lq.push(num);
    }
    end_li = clock();
    result_li = (double)(end_li-start_li);
    cout<<"list push runtime : "<<result_li<<endl;

    start_ar = clock();
    for (int i=0; i<1000000; i++){
        aq.pop();
    }
    end_ar = clock();
    result_ar = (double)(end_ar-start_ar);
    cout<<"array pop runtime : "<<result_ar<<endl;

    start_li = clock();
    for (int i=0; i<1000000; i++){
        aq.pop();
    }
    end_li = clock();
    result_li = (double)(end_li-start_li);
    cout<<"list pop runtime : "<<result_li<<endl;



    return 0;
}
