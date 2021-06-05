//
// Created by lee on 2021/6/2.
//
#include"Sort.h"

int main(){
    my_sort test;
    vector<int> a(MAX,0);
    srand(time(NULL));
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand();
    }
    vector<int> b=a;//b为顺序
    test.quick(b,0,b.size()-1);
    vector<int> c=b;//c为逆序
    reverse(c.begin(),c.end());
    //test.print(a);
    cout<<"以下为随机数据的结果:"<<endl;
    test.Bubble(a);//冒泡排序
    test.Quick(a);//快速排序
    test.Heap(a);//堆排序
    test.Select(a);//选择排序
    test.Shell(a);//希尔排序
    test.Bucket(a);//桶排序
    test.Counting(a);//计数排序
    test.Radix(a);//基数排序
    test.Insert(a);//插入排序
    test.Merge(a);
    test.print_time();
    cout<<"以下为顺序数据的结果:"<<endl;
    test.Bubble(b);//冒泡排序
    test.Quick(b);//快速排序
    test.Heap(b);//堆排序
    test.Select(b);//选择排序
    test.Shell(b);//希尔排序
    test.Bucket(b);//桶排序
    test.Counting(b);//计数排序
    test.Radix(b);//基数排序
    test.Insert(b);//插入排序
    test.Merge(b);
    test.print_time();
    cout<<"以下为逆序数据的结果:"<<endl;
    test.Bubble(c);//冒泡排序
    test.Quick(c);//快速排序
    test.Heap(c);//堆排序
    test.Select(c);//选择排序
    test.Shell(c);//希尔排序
    test.Bucket(c);//桶排序
    test.Counting(c);//计数排序
    test.Radix(c);//基数排序
    test.Insert(c);//插入排序
    test.Merge(c);
    test.print_time();
}