//
// Created by lee on 2021/6/2.
//
#include"Sort.h"
int main(){
    my_sort test;
    vector<int> a(10000,0);
    srand(time(NULL));
    for(int i=0;i<10000;i++)
    {
        a[i]=rand();
    }
    test.Bubble(a);
    test.print_time();
}