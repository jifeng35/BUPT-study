#include"exp.h"
struct treenode
{
    char val;
    treenode* left;
    treenode* right;
};
class tree
{
public:
    tree()
    {
        root = new treenode;
        root = NULL;
        //root->left = nullptr;
        //root->right = nullptr;
    }
    tree(string s)
    {
        int pos = -1;
        root = new treenode;
        create(s, pos,root);
    }
    void create (string s,int &pos,treenode *&root)
    {
        ++pos;
        root = new treenode;
        if (pos == s.size())
        {
            root=NULL;
            return;
        }
        else
        {
            if (pos>s.size()-1||s[pos] == '*')
            {
                root = NULL;
                return;
            }
            else
            {
                root->val = s[pos];
                create(s, pos,root->left);
                create(s, pos,root->right);
            }
        }


    }
    ~tree()
    {
        delete root;
        cout<<"The binary tree you have just built has been ruined!"<<endl;
    }
    int Max_Depth(treenode* ptr)//返回最大深度
    {
        if (!ptr)
            return 0;
        int left = Max_Depth(ptr->left);
        int right = Max_Depth(ptr->right);
        return max(left, right) + 1;
    }
    void Preorder_Traversal()//前序遍历
    {
        if (!root)
        {
            cout << "Your tree is empty!" << endl;
            return;
        }
        stack<treenode*> temp;
        temp.push(root);
        vector<char> res;
        treenode* p = root;
        while (!temp.empty())
        {
            p = temp.top();
            temp.pop();
            res.emplace_back(p->val);
            if (p->right)temp.push(p->right);
            if (p->left)temp.push(p->left);
        }
        print(res);
    }
    void Inorder_Traversal()//中序遍历
    {
        if (!root)
        {
            cout << "Your tree is empty!" << endl;
            return;
        }
        stack<treenode*> temp;
        temp.push(root);
        vector<char> res;
        treenode* p = root;
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
    void Postorder_Traversal()//后序遍历
    {
        if (!root)
        {
            cout << "Your tree is empty!" << endl;
            return;
        }
        stack<treenode*> temp1;
        stack<treenode*> temp2;
        temp1.push(root);
        vector<char> res;
        treenode* p = root;
        while (!temp1.empty())
        {
            p = temp1.top();
            temp1.pop();
            temp2.push(p);
            if (p->left)temp1.push(p->left);
            if (p->right)temp1.push(p->right);
        }
        while(!temp2.empty())
        {
            res.emplace_back(temp2.top()->val);
            temp2.pop();
        }
        print(res);
    }
    void Level_Traversal()
    {

    }
    void print(vector<char> a)
    {
        for (vector<char>::iterator it = a.begin(); it != a.end(); it++)
        {
            cout << *it << " ";
        }
        cout<<endl;
    }
    treenode* Get_Root()
    {
        return root;
    }
private:
    treenode* root;
};
int main()
{
    tree test("12*3");
    cout<<"The result of Preorder Traversal is:"<<endl;
    test.Preorder_Traversal();//前序遍历
    cout<<"The result of Inorder Traversal is:"<<endl;
    test.Inorder_Traversal();//中序遍历
    cout<<"The result of Postorder Traversal is:"<<endl;
    test.Postorder_Traversal();//后序遍历
    cout<<"The binary tree's maximum depth is "<<test.Max_Depth(test.Get_Root())<<endl;
    //int a[1] = {  };
}
//
// Created by lee on 2021/5/12.
//

