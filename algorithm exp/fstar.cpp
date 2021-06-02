//
// Created by lee on 2021/5/24.
//

#include "fstar.h"
int main()
{
    int n=4;
    int m=5;
    vector<int> test01={1,2,2, 1,3,2, 1,4,3, 2,3,4 ,3,4,3 };
    vector<int> test02(5,0);
    FStar test(n,m,test01);//此图为无向图
    test.DFS(2);
    test.BFS(1);
    cout<<test.Prim()<<endl;
    test.PAINT(test02);
}