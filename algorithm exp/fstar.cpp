//
// Created by lee on 2021/5/24.
//

#include "fstar.h"
int main()
{
    int n=5;
    int m=7;
    vector<int> test01={1,2, 2,3, 3,4, 1,3, 4,1, 1,5, 4,5};
    FStar test(n,m,test01);
    test.DFS(1);
    test.BFS(1);
}