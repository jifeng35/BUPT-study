//
// Created by lee on 2021/6/3.
//

#include "exp.h"
#include"Sort.h"
int main(){
    vector<int> test1={1,2,3,4,5,6,7,8,9};
    test1.insert(test1.begin()+1,0);//x.begin()+i,插入结束的元素就在x[i]上
    my_sort test;
    test.print(test1);
    test1.erase(test1.begin()+1);//x.begin()+i,删除的元素就在x[i]上
    test.print(test1);
    cout<<"\'";
}