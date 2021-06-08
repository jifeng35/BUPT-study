//
// Created by lee on 2021/6/6.
//

#include "Binary_Search_Tree.h"
int main(){
    vector<int> a{45,24, 53, 12, 37, 93};
    BS_Tree test(a);
    test.Inorder_Traversal();
    test.search(12);
    test.erase(45);
    test.insert(test.get_root(),10);
    test.insert(test.get_root(),55);
    test.Inorder_Traversal();
}