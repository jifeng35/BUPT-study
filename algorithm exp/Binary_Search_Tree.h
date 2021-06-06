//
// Created by lee on 2021/6/6.
//

#ifndef UNTITLED1_BINARY_SEARCH_TREE_H
#define UNTITLED1_BINARY_SEARCH_TREE_H

#endif //UNTITLED1_BINARY_SEARCH_TREE_H
#include"exp.h"
struct BS_Node{
    int val;
    BS_Node *parent;
    BS_Node *left;
    BS_Node *right;
};
class BS_Tree{
public:
    BS_Tree();
    void createBSTree();
    void search(int val);
    void erase(int val);
    void insert(int val);
    BS_Node * find_pos(int val);
    ~BS_Tree();
private:
    BS_Node*root;
};
BS_Tree::BS_Tree(){

}
void BS_Tree::createBSTree(){

}
void BS_Tree::erase(int val) {

}
void BS_Tree::search(int val){

}
void BS_Tree::insert(int val){

}
BS_Node *BS_Tree::find_pos(int val){

}
BS_Tree::~BS_Tree(){

}