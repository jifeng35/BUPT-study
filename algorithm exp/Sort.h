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
    void print(vector<int> a);
    void print_time();
private:
    double Bubble_Time;
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
    cout<<"Bubble_Sort Time is "<<Bubble_Time<<"s"<<endl;
}