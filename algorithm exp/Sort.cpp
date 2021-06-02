//
// Created by lee on 2021/6/2.
//
#include"Sort.h"
const int MAX=10000;
int main(){
    my_sort test;
    vector<int> a(MAX,0);
    srand(time(NULL));
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand();
    }
    test.Bubble(a);
    test.Quick(a);
    test.print_time();
}