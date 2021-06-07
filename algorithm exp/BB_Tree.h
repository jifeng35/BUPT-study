//
// Created by lee on 2021/6/7.
//

#ifndef UNTITLED1_BB_TREE_H
#define UNTITLED1_BB_TREE_H

#endif //UNTITLED1_BB_TREE_H
#include"exp.h"
struct BB_Node{
    int val;
    BB_Node*left,*right;
};
class BB_Tree{
public:
    BB_Tree(vector<int> a);
    void search(int val);
    void insert();
private:
    BB_Node*root;
};