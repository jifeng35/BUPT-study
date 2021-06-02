//
// Created by lee on 2021/6/2.
//

#ifndef UNTITLED1_SORT_H
#define UNTITLED1_SORT_H

#endif //UNTITLED1_SORT_H
#include "exp.h"
class my_sort{
public:
    void Bubble(int a[],int len){
        for(int i=0;i<len-1;++i){
            bool no_swap=true;
            for(int j=0;j<len-i-1;++j){
                if(a[j]>a[j+1]) {
                    a[j] = a[j] + a[j + 1];
                    a[j + 1] = a[j] - a[j + 1];
                    a[j] = a[j] - a[j + 1];
                    no_swap=false;
                }
            }
            if(no_swap)break;
        }
        print(a,len);
    }
    void print(int a[],int len){
        for(int i=0;i<len;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};