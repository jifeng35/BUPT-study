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
            multimap<int,char> t=get_time(s);
            multimap<int,char>::iterator it =t.begin();
            while(t.size()>1)
            {
                it =t.begin();
                if (it->second != '*' && (++it)->second != '*') {
                    Creat_NewTree(t);
                } else {
                    Insert_Node(t);
                }
            }
        }
        int exist(multimap<int,char> t)
        {
            return t.count('*');
        }
        void Creat_NewTree(multimap<int,char> &s)
        {
            Huffman_Node*ptr=new Huffman_Node;
            ptr->left=new Huffman_Node;
            ptr->right=new Huffman_Node;
            ptr->left->right=ptr->left->left=ptr->right->left=ptr->right->right=NULL;
            multimap<int,char>::iterator it =s.begin();
            ptr->right->Heavy_Weight=it->first;
            ptr->right->data=it->second;
            it++;
            ptr->left->Heavy_Weight=it->first;
            ptr->left->data=it->second;
            ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            s.erase(ptr->right->Heavy_Weight);
            s.erase(ptr->left->Heavy_Weight);
            s.insert(pair<int,char>(ptr->Heavy_Weight,'*'));
            if(!exist(s))
            root=ptr;
            else
                root2=ptr;
        }
        void Insert_Node(multimap<int,char> &s)
        {
            Huffman_Node*ptr=new Huffman_Node;
            multimap<int,char>::iterator it =s.begin();
            if(it->second=='*'&&(++it)->second!='*') {
                it--;
                ptr->right = new Huffman_Node;
                ptr->right->data = it->second;
                ptr->right->Heavy_Weight=it->first;
                ptr->right->left=ptr->right->right=NULL;
                ptr->left= root;
                ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            }
            else if((it--)->second!='*'&&it->second=='*')
            {
                it++;
                ptr->left = new Huffman_Node;
                ptr->left->data = it->second;
                ptr->left->Heavy_Weight=it->first;
                ptr->left->right=ptr->left->left=NULL;
                ptr->right= root;
                ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            }
            else{
                ptr->left=root;
                ptr->right=root2;
                ptr->Heavy_Weight=root->Heavy_Weight+root2->Heavy_Weight;
            };
            root=ptr;
        }
        multimap<int,char> get_time(string s)
        {
           map<char,int> temp;
           multimap<int,char> res;
           for(char t:s)
           {
                   temp[t]++;
           }
           for(map<char,int>::iterator it=temp.begin();it!=temp.end();it++)
           {
               res.insert(pair<int,char>(it->second,it->first));
           }
           return res;
        }
        Huffman_Node* Get_Root()
        {
            return root;
        }
private:
    Huffman_Node*root;
    Huffman_Node*root2;
};
int main()
{
    HuffMan test("we will we will r u");
    Huffman_Node* ptr=test.Get_Root();
}

