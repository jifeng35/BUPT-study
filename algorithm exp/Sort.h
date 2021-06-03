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
    void bubble(vector<int> a);
    void Quick(vector<int> a);
    void quick(vector<int> &a,int low,int high);
    void print(vector<int> a);
    void print_time();
private:
    double Bubble_Time;
    double Quick_Time;
};
void my_sort::bubble(vector<int> a){
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
    print(a);
}
void my_sort::print(vector<int> a){
    for(int i=0;i<a.size();++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void my_sort::Bubble(vector<int> a){
    clock_t s_time=clock();
    bubble(a);
    clock_t e_time=clock();
    Bubble_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
}
void my_sort::print_time(){
    if(Bubble_Time!=-9.2559631349317831E+61)
    cout<<"Bubble_Sort Time is "<<Bubble_Time<<"s"<<endl;
    if(Quick_Time!=-9.2559631349317831E+61)
    cout<<"Quick_Sort Time is "<<Quick_Time<<"s"<<endl;
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