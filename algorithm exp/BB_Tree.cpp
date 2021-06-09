//
// Created by lee on 2021/6/7.
//

#include "BB_Tree.h"
int main(){
    vector<int> a={1,2,3,4,5,6,7};
    BB_Tree test(a);
    test.Level_Traversal();//改旋转函数
    test.search(4);
    test.erase(test,4,'a');
    test.Level_Traversal();//改旋转函数
}