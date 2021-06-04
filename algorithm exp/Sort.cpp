//
// Created by lee on 2021/6/2.
//
#include"Sort.h"
const int MAX=15000;
int main(){
    my_sort test;
    vector<int> a(MAX,0);
    srand(time(NULL));
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand();
    }
    //test.print(a);
    test.Bubble(a);//冒泡排序
    test.Quick(a);//快速排序
    test.Heap(a);//堆排序
    test.Select(a);//选择排序
    test.Shell(a);//希尔排序
    test.print_time();
}