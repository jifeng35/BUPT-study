//
// Created by lee on 2021/6/2.
//
#ifndef UNTITLED1_SORT_H
#define UNTITLED1_SORT_H
#endif //UNTITLED1_SORT_H
#include "exp.h"
class my_sort{
public:
    void Bubble(vector<int> a);
    void bubble(vector<int> &a);
    void Quick(vector<int> a);
    void quick(vector<int> &a,int low,int high);
    void Heap(vector<int> a);
    void heap(vector<int> &a);
    void print(vector<int> a);
    void swap(int &a,int &b);
    void make_tree(vector<int> &a,int time);
    void sink(vector<int> &a,int time);
    void Select(vector<int> a);
    void select(vector<int> &a);
    void Shell(vector<int> a);
    void shell(vector<int> &a);
    void print_time();
private:
    double Bubble_Time;
    double Quick_Time;
    double Heap_Time;
    double Select_Time;
    double Shell_Time;
};
void my_sort::swap(int&a,int&b){
    if(a==b)
        return;
    a=a+b;
    b=a-b;
    a=a-b;
}
void my_sort::bubble(vector<int> &a){
    for(int i=0;i<a.size()-1;++i){
        bool no_swap=true;
        for(int j=0;j<a.size()-i-1;++j){
            if(a[j]>a[j+1]) {
                a[j] = a[j] + a[j + 1];
                a[j + 1] = a[j] - a[j + 1];
                a[j] = a[j] - a[j + 1];
                no_swap=false;
            }
        }
        if(no_swap)break;
    }
}
void my_sort::print(vector<int> a){
    for(int i=0;i<a.size();++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void my_sort::Bubble(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    bubble(b);
    clock_t e_time=clock();
    Bubble_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    print(b);
}
void my_sort::print_time(){
    if(Bubble_Time!=-9.2559631349317831E+61)
    cout<<"Bubble_Sort Time is "<<Bubble_Time<<"s"<<endl;
    if(Quick_Time!=-9.2559631349317831E+61)
    cout<<"Quick_Sort Time is "<<Quick_Time<<"s"<<endl;
    if(Heap_Time!=-9.2559631349317831E+61)
        cout<<"Heap_Sort Time is "<<Heap_Time<<"s"<<endl;
    if(Select_Time!=-9.2559631349317831E+61)
        cout<<"Select_Time Time is "<<Select_Time<<"s"<<endl;
    if(Shell_Time!=-9.2559631349317831E+61)
        cout<<"Shell_Time Time is "<<Shell_Time<<"s"<<endl;
}
void my_sort::quick(vector<int> &a,int low,int high){
    if(low>=high){
        return;
    }
    int left=low;
    int right=high;
    int key=a[left];
    while(right>left){
            while(left<right&&a[right]>=key)
                --right;
            a[left]=a[right];
            while(left<right&&a[left]<=key)
                ++left;
            a[right]=a[left];
    }
    a[left]=key;
    quick(a,low,left-1);
    quick(a,left+1,high);
}
void my_sort::Quick(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    quick(b,0,b.size()-1);
    clock_t e_time=clock();
    Quick_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    print(b);
}
void my_sort::Heap(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    heap(b);
    clock_t e_time=clock();
    Heap_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    print(b);
}
void my_sort::heap(vector<int> &a){
    int time=0;
    make_tree(a, time);
    while(time<a.size()){
        time++;
        swap(a[0],a[a.size()-time]);//此时根节点(第一个数组内元素)为最大数,将其与数组末尾swap,不再访问最后一个元素
        sink(a,time);
    }
}
void my_sort::make_tree(vector<int> &a,int time) {
    bool temp =true;//使用数组构建伪二叉树,顺序为层序遍历,构建完全二叉树
    do{
        temp=true;//指示数组是否发生变化
        for (int i = 0; i < a.size()-time && (2 * i + 1) < a.size()-time; i++) {
            if ((2 * i + 2) < a.size()-time) {
                if (a[2 * i + 1] > a[2 * i + 2]) {
                    if (a[2 * i + 1]> a[i]) {
                        swap(a[2 * i + 1],a[i]);
                        temp=false;
                    }
                }
                else {
                    if (a[2 * i + 2] > a[i]) {
                        swap(a[2 * i + 2],a[i]);
                        temp=false;
                    }
                }
            }
            else {
                if (a[2 * i + 1] > a[i]) {
                    swap(a[2 * i + 1],a[i]);
                    temp=false;
                }
            }
        }
    }while(!temp);
}
void my_sort::sink(vector<int> &a,int time){
    bool temp =true;//使用数组构建伪二叉树,顺序为层序遍历,构建完全二叉树
    do{
        for (int i = 0; i < a.size()-time && (2 * i + 1) < a.size()-time;) {
            int temp=i;
            if ((2 * i + 2) < a.size()-time) {
                if (a[2 * i + 1] > a[2 * i + 2]) {
                    if (a[2 * i + 1] > a[i]) {
                        swap(a[2 * i + 1], a[i]);
                        temp = false;
                        i=2*i+1;
                    }
                } else {
                    if (a[2 * i + 2] > a[i]) {
                        swap(a[2 * i + 2], a[i]);
                        temp = false;
                        i=2*i+2;
                    }
                }
            } else {
                if (a[2 * i + 1] > a[i]) {
                    swap(a[2 * i + 1], a[i]);
                    temp = false;
                    i=2*i+1;
                }
            }
            if(temp==i)
                break;
        }
    }while(!temp);
}
void my_sort::Select(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    select(b);
    clock_t e_time=clock();
    Select_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    print(b);
}
void my_sort::select(vector<int> &a){
    if(a[0]>a[1])
        swap(a[0],a[1]);
    for(int i=2;i<a.size();i++)
    {
        for(int j=i-1;j>=0;) {
            if(a[i]<a[0])
            {
                a.insert(a.begin(),a[i]);
                a.erase(a.begin()+1+i);
                break;
            }
            else if (a[i] < a[j]) {
                j--;
            }
            else{
                a.insert(a.begin()+j+1,a[i]);
                a.erase(a.begin()+i+1);
                break;
            }
        }
    }
}
void my_sort::Shell(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    shell(b);
    clock_t e_time=clock();
    Shell_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    print(b);
}
void my_sort::shell(vector<int>&a){
    int gap=a.size()/2;
    bool temp=false;
    do{
        temp=false;
        for(int i=0;(i+gap)<a.size();i++)
        {
            if(a[i]>a[i+gap]) {
                swap(a[i], a[i + gap]);
                temp=true;
            }
        }
        if(!temp)
            gap=gap/2;
    }while(gap);
}