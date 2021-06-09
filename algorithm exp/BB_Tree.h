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
    int L_BF;//左平衡因子
    int R_BF;//右平衡因子
};
class BB_Tree{
public:
    BB_Tree(vector<int> a);
    void Level_Traversal();
    void Inorder_Traversal(BB_Node*ptr,vector<char> a);
    void search(int val);
    void check();
    void erase(int val);
    void erase(BB_Tree&tree,int val,char useless);
    bool judge_BF(BB_Node*ptr);
    int get_BF(BB_Node*ptr);
    void revolve(BB_Node*ptr);
    int Max_Depth(BB_Node*ptr);
    void insert(BB_Node **ptr,int val);
    void Insert(BB_Node **ptr,int val);
    BB_Node*find_parent(BB_Node*ptr);
    void Update_BF();
    BB_Node*get_root();
    void Inorder_Traversal();
    BB_Node*root;
    vector<int> temp;
};
template<class T>
void print(vector<T> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
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
    if(!ptr)
        return 0;
    else if(ptr->left&&ptr->right)
        return Max_Depth(ptr->left)- Max_Depth(ptr->right);//左子树最大深度-右子树最大深度
    else if(ptr->right)
        return - Max_Depth(ptr->right);
    else if(ptr->left)
        return Max_Depth(ptr->left);
    else
        return 0;
}
BB_Tree::BB_Tree(vector<int> a){
    root=NULL;
    temp=a;
    for(int i=0;i<a.size();i++){
        Insert(&root,a[i]);
    }
    Update_BF();
    check();
}
void BB_Tree::revolve(BB_Node *ptr){
    BB_Node *ptr_p=find_parent(ptr);
    if(ptr->L_BF==0||ptr->R_BF==0){
        switch (ptr->BF) {
            case 2:
                //ll型调整
                if (ptr->left->left) {
                    ptr->left->right = ptr;
                    if (ptr_p) {//说明ptr不为根节点
                        if (ptr_p->val > ptr->val) {
                            ptr_p->left = ptr->left;
                        } else {
                            ptr_p->right = ptr->left;
                        }
                    } else {
                        root = ptr->left;
                    }
                    ptr->left = NULL;
                }
                    //lr型调整
                else if (ptr->left->right) {
                    ptr->left->right->right = ptr;
                    ptr->left->right->left = ptr->left;
                    //将新的"根节点"连需要连的节点
                    if (ptr_p) {
                        if (ptr_p->val > ptr->val) {
                            ptr_p->left = ptr->left->right;
                        } else {
                            ptr_p->right = ptr->left->right;
                        }
                    }//将原父节点指向新的局部根节点
                    else {
                        root = ptr->left->right;
                    }
                    ptr->left->right = NULL; //将原"根节点"的左孩子的右指针清空
                    ptr->left = NULL;//将原"根节点"的左指针清空
                }
                break;
            case -2:
                //rr型调整
                if (ptr->right->right) {
                    ptr->right->left = ptr;
                    if (ptr_p) {
                        if (ptr_p->val > ptr->val) {
                            ptr_p->left = ptr->right;
                        } else {
                            ptr_p->right = ptr->right;
                        }
                    } else {
                        root = ptr->right;
                    }
                    ptr->right = NULL;
                }
                    //rl型调整
                else if (ptr->right->left) {
                    ptr->right->left->left = ptr;
                    ptr->right->left->right = ptr->right;
                    if (ptr_p) {
                        if (ptr_p->val > ptr->val) {
                            ptr_p->left = ptr->right->left;
                        } else {
                            ptr_p->right = ptr->right->left;
                        }
                    } else {
                        root = ptr->right->left;
                    }
                    ptr->right->left = NULL;
                    ptr->right = NULL;
                }
                break;
        }
    }
    else if(ptr->L_BF==1){
        int t1=root->val;
        int t2=root->left->val;
        root=root->right;
        insert(&root,t1);
        insert(&root,t2);
        Update_BF();
        revolve(root->left);
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
        (*ptr)->L_BF=Max_Depth((*ptr)->left);
        (*ptr)->R_BF=Max_Depth((*ptr)->right);
    }
    else if(val>(*ptr)->val){
        insert(&(*ptr)->right,val);
    }
    else if(val<(*ptr)->val){
        insert(&(*ptr)->left,val);
    }
}
void BB_Tree::Insert(BB_Node **ptr,int val){//一次只能通过旋转纠正一个错误
    insert(ptr,val);
    Update_BF();
    stack<BB_Node *>temp;
    temp.push(*ptr);
    BB_Node *p=*ptr;
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
void BB_Tree::Inorder_Traversal(){//中序遍历
    if (!root)
    {
        cout << "Your tree is empty!" << endl;
        return;
    }
    stack<BB_Node*> temp;
    temp.push(root);
    vector<int> res;
    BB_Node* p = root;
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
void BB_Tree::Update_BF(){
    if(!root)
        return;
    stack<BB_Node*> temp;
    temp.push(root);
    BB_Node*ptr=root;
    while(!temp.empty()){
        ptr=temp.top();
        ptr->BF= get_BF(ptr);
        (ptr)->L_BF=Max_Depth((ptr)->left);
        (ptr)->R_BF=Max_Depth((ptr)->right);
        temp.pop();
        if(ptr->right)temp.push(ptr->right);
        if(ptr->left)temp.push(ptr->left);
    }
}
void BB_Tree::Level_Traversal(){
    //cout<<root->val<<endl;
    queue<BB_Node*> temp;
    vector<vector<int>> res;
    vector<int> res1;
    temp.push(root);
    BB_Node* p=root;
    int count=0;
    while(!temp.empty())
    {
        queue<BB_Node *> next_level;
        while(!temp.empty())
        {
            p = temp.front();
            temp.pop();
            res1.push_back(p->val);
            if (p->left)
                next_level.push(p->left);
            if (p->right)
                next_level.push(p->right);
        }
        temp=next_level;
        res.push_back(res1);
        res1.clear();
    }
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            if(j==0)
            {
                cout<<"Line"<<i+1<<": ";
            }
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
void BB_Tree::search(int val){
    BB_Node*p=root;
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
void BB_Tree::Inorder_Traversal(BB_Node*ptr,vector<char> a){
    if (!ptr)
    {
        cout << "Your tree is empty!" << endl;
        return;
    }
    stack<BB_Node*> temp;
    temp.push(ptr);
    vector<int> res;
    BB_Node* p = ptr;
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
    BB_Node **ptr1=&(root);
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
void BB_Tree::erase(int val) {
    BB_Node*p=root;
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
        Update_BF();
        check();
        cout<<"Erase is complete!\t\tThe result is showed as follows: "<<endl;
        Level_Traversal();
    }
    else{
        cout<<"The number you wanna erase is not exist!"<<endl;
    }
}
void BB_Tree::check(){
    stack<BB_Node *>temp;
    temp.push(root);
    BB_Node *p=root;
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
void BB_Tree::erase(BB_Tree&tree,int val,char useless){
    for(int i=0;i<temp.size();i++){
        if(temp[i]==val)
            temp.erase(temp.begin()+i);
    }
    tree=BB_Tree(temp);
}
