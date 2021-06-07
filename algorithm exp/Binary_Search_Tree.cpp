//
// Created by lee on 2021/6/6.
//

#include "Binary_Search_Tree.h"
int main(){
    vector<int> a{45,24, 53, 12, 97, 93};
    BS_Tree test(a);
    test.Inorder_Traversal();
    test.search(12);
    test.insert(test.get_root(),11);
    test.insert(test.get_root(),95);
    test.insert(test.get_root(),40);
    test.insert(test.get_root(),50);
    test.Inorder_Traversal();
    test.erase(11);
}