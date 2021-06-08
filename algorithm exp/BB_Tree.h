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
    int BF;//平衡因子
};
class BB_Tree{
public:
    BB_Tree(vector<int> a);
    void search(int val);
    bool judge_BF(BB_Node*ptr);
    int get_BF(BB_Node*ptr);
    void revolve(BB_Node*ptr);
    int Max_Depth(BB_Node*ptr);
    void insert(BB_Node **ptr,int val);
    void Insert(BB_Node *ptr,int val);
    BB_Node*find_parent(BB_Node*ptr);
    BB_Node*get_root();
private:
    BB_Node*root;
};
BB_Node*BB_Tree::get_root(){
    return root;
}
int BB_Tree::Max_Depth(BB_Node*ptr){
    if(!ptr)
        return 0;
    int right= Max_Depth(ptr->right);
    int left=Max_Depth(ptr->left);
    return max(left,right)+1;
}
bool BB_Tree::judge_BF(BB_Node *ptr) {
    if(ptr->BF<=1&&ptr->BF>=-1)
        return true;
    else
        return false;
}
int BB_Tree::get_BF(BB_Node *ptr){
    return Max_Depth(ptr->left)- Max_Depth(ptr->right);//左子树最大深度-右子树最大深度
}
BB_Tree::BB_Tree(vector<int> a){
    for(int i=0;i<a.size();i++){
        Insert(get_root(),a[i]);
    }
}
void BB_Tree::revolve(BB_Node *ptr){
    BB_Node *ptr_p=find_parent(ptr);
    switch(ptr->BF) {
        case 2:
            //ll型调整
            if(ptr->left->left){
                ptr->left->right=ptr;
                if(ptr_p){//说明ptr不为根节点
                    if(ptr_p->val>ptr->val){
                        ptr_p->left=ptr->left;
                    }
                    else{
                        ptr_p->right=ptr->left;
                    }
                }
                else{
                    root=ptr->left;
                }
                ptr->left=NULL;
            }
            //lr型调整
            else if(ptr->left->right){
                ptr->left->right->right=ptr;
                ptr->left->right->left=ptr->left;
                //将新的"根节点"连需要连的节点
                if(ptr_p){
                    if(ptr_p->val>ptr->val){
                        ptr_p->left=ptr->left->right;
                    }
                    else{
                        ptr_p->right=ptr->left->right;
                    }
                }//将原父节点指向新的局部根节点
                else{
                    root=ptr->left->right;
                }
                ptr->left->right=NULL; //将原"根节点"的左孩子的右指针清空
                ptr->left=NULL;//将原"根节点"的左指针清空

            }
            break;
        case -2:
            //rr型调整
            if(ptr->right->right){

            }
            //rl型调整
            else if(ptr->right->left){

            }
            break;
    }

}
void BB_Tree::insert(BB_Node **ptr,int val){
    if(*ptr==NULL){
        BB_Node *temp=new BB_Node;
        temp->val=val;
        temp->right=NULL;
        temp->left=NULL;
        *ptr=temp;
        (*ptr)->BF=get_BF(*ptr);
    }
    else if(val>(*ptr)->val){
        insert(&(*ptr)->right,val);
    }
    else if(val<(*ptr)->val){
        insert(&(*ptr)->left,val);
    }
}
void BB_Tree::Insert(BB_Node *ptr,int val){//一次只能通过旋转纠正一个错误
    insert(&ptr,val);
    stack<BB_Node *>temp;
    temp.push(ptr);
    BB_Node *p=ptr;
    BB_Node *te=NULL;
    int Max=0;
    while(!temp.empty()){
        p=temp.top();
        if(!judge_BF(p)){
            if(Max<=abs(p->BF)) { Max = abs(p->BF); te=p;}
        }
        temp.pop();
        if(p->right)temp.push(p->right);
        if (p->left)temp.push(p->left);
    }
    if(te)
        revolve(te);
    else
        return;
}
BB_Node*BB_Tree::find_parent(BB_Node *ptr) {//此处假定*ptr一定存在于树中,若传入指针为根节点,则返回NULL
    if(ptr==root)
        return NULL;
    BB_Node *p=root;
    int val=ptr->val;
    vector<char> a;
    bool change;
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
    if(change){
        p=root;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]=='r')
                p=p->right;
            else
                p=p->left;
        }
        return p;
    }
}
