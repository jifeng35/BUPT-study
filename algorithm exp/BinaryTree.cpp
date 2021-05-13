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
        //treenode*ptr=root;
        root = new treenode;
        if (pos == s.size())
        {
            //cout << "Create complete" << endl;
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
    void search(char s)
    {
        if(root->val==s)
            cout<<"The char you wanna search is in the root node!"<<endl;
        else
        {
            stack<treenode*> temp;
            temp.push(root);
            treenode*p =root;
            vector<int> res;
            while(!temp.empty())
            {
                p=temp.top();
                temp.pop();
                if(p->val==s)
                {
                    cout<<"root's ";
                    for(int i=0;i<res.size();i++)
                    {
                        if(res[i])
                            cout<<"right ";
                        else
                            cout<<"left ";
                    }
                    cout<<endl;
                }
                else if(p->left) { temp.push(p->left);res.emplace_back(0); }
                else if(p->right){ temp.push(p->right);res.emplace_back(1); }
            }
        }
    }
    int maxdepth(treenode* ptr)//返回最大深度
    {
        if (!ptr)
            return 0;
        int left = maxdepth(ptr->left);
        int right = maxdepth(ptr->right);
        return max(left, right) + 1;
    }
    void preordertraversal(treenode* ptr)//前序遍历
    {
        if (!ptr)
        {
            cout << "Your tree is empty!" << endl;
            return;
        }
        stack<treenode*> temp;
        temp.push(ptr);
        vector<char> res;
        treenode* p = ptr;
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
    void inordertraversal(treenode* ptr)//中序遍历
    {
        if (!ptr)
        {
            cout << "Your tree is empty!" << endl;
            return;
        }
        stack<treenode*> temp;
        temp.push(ptr);
        vector<char> res;
        treenode* p = ptr;
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
    void postordertraversal(treenode* ptr)//后序遍历
    {
        if (!ptr)
        {
            cout << "Your tree is empty!" << endl;
            return;
        }
        stack<treenode*> temp1;
        stack<treenode*> temp2;
        temp1.push(ptr);
        vector<char> res;
        treenode* p = ptr;
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
    void print(vector<char> a)
    {
        for (vector<char>::iterator it = a.begin(); it != a.end(); it++)
        {
            cout << *it << " ";
        }
        cout<<endl;
    }
    treenode* root;
};
int main()
{
    tree test("12*3");
    //cout << test.root->val<<endl;
    cout<<"The result of preordertraversal is:"<<endl;
    test.preordertraversal(test.root);//前序遍历
    cout<<"The result of inordertraversal is:"<<endl;
    test.inordertraversal(test.root);//中序遍历
    cout<<"The result of postordertraversal is:"<<endl;
    test.postordertraversal(test.root);//后序遍历
    cout<<"The binary tree's maximum depth is "<<test.maxdepth(test.root)<<endl;
    test.search('3');
    //int a[1] = {  };
}
//
// Created by lee on 2021/5/12.
//

