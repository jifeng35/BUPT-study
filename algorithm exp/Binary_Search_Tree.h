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
    BS_Tree(vector<int> a){
        root=NULL;
        BS_Node **ptr=&(root);
        for(int i=0;i<a.size();i++){
            insert(ptr,a[i]);
        }
    }
    void createBSTree();
    void Inorder_Traversal();
    void search(int val);
    void erase(int val);
    template<class T>
    void print(vector<T> a);
    void insert(BS_Node**ptr,int val);
    //BS_Node * find_pos(int val);
    ~BS_Tree();
private:
    BS_Node*root;
};
void BS_Tree::createBSTree(){

}
void BS_Tree::erase(int val) {

}
void BS_Tree::search(int val){
    BS_Node*p=root;
    bool change=false;
    vector<char> a;
    do{
        change=false;
        if (p->val == val) {
            change=true;
            break;
        }
        else if (p->val > val) {
            a.emplace_back('l');
            if(p->left) { p = p->left;change=true; }
        } else if (p->val < val) {
            a.emplace_back('r');
            if(p->right) { p = p->right;change=true; }
        }
    }while(change);
    if(change) {
        cout << "it's on root's ";
        print(a);
    }
    else{
        cout<<"The number you have just found is not exist!"<<endl;
    }
}
void BS_Tree::insert(BS_Node**ptr,int val){
    if(*ptr==NULL){
        BS_Node*temp=new BS_Node;
        temp->left=NULL;
        temp->right=NULL;
        temp->val=val;
        *ptr=temp;
            return;
        }
    else if(val>(*ptr)->val){
        insert(&(*ptr)->right,val);
    }
    else if(val<(*ptr)->val)
    {
        insert(&(*ptr)->left,val);
    }
}
//BS_Node *BS_Tree::find_pos(int val){}
BS_Tree::~BS_Tree(){

}
void BS_Tree::Inorder_Traversal(){//中序遍历
    if (!root)
    {
        cout << "Your tree is empty!" << endl;
        return;
    }
    stack<BS_Node*> temp;
    temp.push(root);
    vector<int> res;
    BS_Node* p = root;
    while (!temp.empty())
    {
        while ((p)&&(p->left))
        {
            p = p->left;
            temp.push(p);
        }
        p = temp.top();
        temp.pop();
        res.emplace_back(p->val);
        p = p->right;
        if(p)
            temp.push(p);
    }
    print(res);
}
template<class T>
void BS_Tree::print(vector<T> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}