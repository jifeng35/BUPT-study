//
// Created by lee on 2021/5/13.
//
#include"exp.h"
struct  Huffman_Node{
    char data;
    Huffman_Node *left;//0
    Huffman_Node *right;//1
    int Heavy_Weight;
};
class HuffMan{
public:
        HuffMan(string s)
        {
            string t=get_time(s);
           while(s.size()==2&&s[0]=='*')
            {
                if (t[t.size() - 2] != '*' && t[t.size() - 4] != '*') {
                    Creat_NewTree(t);
                } else {
                    Insert_Node(t);
                }
            }
        }
        void Update(string &s)
        {

        }
        void Creat_NewTree(string &s)
        {//所含有字符的总数,s这个字符串应为N*("字符"+"权重")构成
            Huffman_Node*ptr=new Huffman_Node;
            ptr->left=new Huffman_Node;
            ptr->right=new Huffman_Node;
            ptr->left->right=ptr->left->left=ptr->right->left=ptr->right->right=NULL;
            ptr->left->data=s[s.size()-2];
            ptr->left->Heavy_Weight=int(s[s.size()-1]);
            s.pop_back();s.pop_back();
            ptr->right->data=s[s.size()-2];
            ptr->right->Heavy_Weight=int(s[s.size()-1]);
            ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            s.pop_back();s.pop_back();
            s.push_back('*');
            s.push_back(ptr->Heavy_Weight+48);
            root=ptr;
        }
        void Insert_Node(string &s)
        {
            Huffman_Node*ptr=new Huffman_Node;
            if(s[s.size()-2]=='*') {
                ptr->right = new Huffman_Node;
                ptr->right->data = s[s.size() - 4];
                ptr->right->Heavy_Weight=int(s[s.size()-3]);
                ptr->right->left=ptr->right->right=NULL;
                s.pop_back();s.pop_back();
                ptr->left= root;
                ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
                s.pop_back();s.pop_back();
                s.push_back('*');
                s.push_back(ptr->Heavy_Weight+48);
            }
                else if(s[s.size()-4]=='*')
            {
                ptr->left = new Huffman_Node;
                ptr->left->data = s[s.size() - 2];
                ptr->left->Heavy_Weight=int(s[s.size()-1]);
                ptr->left->right=ptr->left->left=NULL;
                s.pop_back();s.pop_back();
                ptr->right= root;
                ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
                s.pop_back();s.pop_back();
                s.push_back('*');
                s.push_back(ptr->Heavy_Weight+48);
            }
            root=ptr;
        }
        string get_time(string s)
        {
            vector<int> count(100,0);
            vector<char> container(100,'*');
            for(char t:s)
            {
                for(int i=0;i<100;i++)
                {
                    if(container[i]==t)
                    {
                        count[i]++;
                        break;
                    }
                    else if(container[i]=='*')
                    {
                        container[i]=t;
                        count[i]++;
                        break;
                    }
                }
            }
            vector<int> temp=count;
            string res;
            sort(temp.begin(),temp.end());
            reverse(temp.begin(),temp.end());
            while(!temp.empty())
            {
                for(int i=0;i<100;i++)
                {
                    if(temp[temp.size()-1]==count[i])
                    {
                        res.push_back(container[i]);
                        res.push_back(temp[temp.size()-1]+48);
                        temp.pop_back();
                    }
                }
            }
            return res;
        }
        Huffman_Node* Get_Root()
        {
            return root;
        }
private:
    Huffman_Node*root;
};

