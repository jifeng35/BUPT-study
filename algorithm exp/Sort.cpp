//
// Created by lee on 2021/6/2.
//
#include"Sort.h"
const int MAX=5000;
int main(){
    my_sort test;
    vector<int> a(MAX,0);
    srand(time(NULL));
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand();
    }
    //test.print(a);
    test.Bubble(a);
    test.Quick(a);
    test.Heap(a);
    test.print_time();
}