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
    BS_Tree(vector<int> a);
    void Inorder_Traversal();
    void Inorder_Traversal(BS_Node*ptr,vector<char> a);
    void search(int val);
    void erase(int val);
    template<class T>
    void print(vector<T> a);
    void insert(BS_Node**ptr,int val);
    BS_Node** get_root();
    ~BS_Tree();
private:
    BS_Node*root;
};
BS_Tree::BS_Tree(vector<int> a){
        root=NULL;
    BS_Node **ptr=&(root);
        for(int i=0;i<a.size();i++){
            insert(ptr,a[i]);
        }
}
void BS_Tree::erase(int val) {
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
        if((!p->left)&&!p->right){
            p=root;
            for(int i=0;i<a.size()-1;i++){
                if(a[i]=='r')
                    p=p->right;
                else
                    p=p->left;
            }
            if(a[a.size()-1]=='r') { p->right = NULL; }
            else { p->left = NULL; }
        }
        else if(p->right&&p->left){
            Inorder_Traversal(p,a);
        }
        else if(!p->left||!p->right){
            if(!p->left){
                p=root;
                for(int i=0;i<a.size()-1;i++){
                    if(a[i]=='r')
                        p=p->right;
                    else
                        p=p->left;
                }//要删除节点的父节点
                p->right=p->right->right;
            }
            else{
                p=root;
                for(int i=0;i<a.size()-1;i++){
                    if(a[i]=='r')
                        p=p->right;
                    else
                        p=p->left;
                }//要删除节点的父节点
                p->left=p->left->left;
                }
        }
        cout<<"Erase is complete!\t\tThe result is showed as follows: "<<endl;
        Inorder_Traversal();
    }
    else{
        cout<<"The number you wanna erase is not exist!"<<endl;
    }
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
BS_Node** BS_Tree::get_root(){
    return &root;
}
void BS_Tree::Inorder_Traversal(BS_Node*ptr,vector<char> a){
    if (!ptr)
    {
        cout << "Your tree is empty!" << endl;
        return;
    }
    stack<BS_Node*> temp;
    temp.push(ptr);
    vector<int> res;
    BS_Node* p = ptr;
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
    BS_Node **ptr1=&(root);
    if(ptr==root){
        root=NULL;
    }
    else{
        ptr=root;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]=='r')
                p=p->right;
            else
                p=p->left;
        }//要删除节点的父节点
        if(a[a.size()-1]=='l')
            p->left=NULL;
        else
            p->right=NULL;
    }
    for(int i=0;i<res.size();i++){
        if(res[i]!=ptr->val)
        insert(ptr1,res[i]);
    }
}//从给定点开始的中序遍历,并插入到数组中