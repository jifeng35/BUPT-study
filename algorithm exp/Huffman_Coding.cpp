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
            map<int,char> t=get_time(s);
           if()
        }
        void Creat_NewTree(map<int,char> &s)
        {//所含有字符的总数,s这个字符串应为N*("字符"+"权重")构成
            Huffman_Node*ptr=new Huffman_Node;
            ptr->left=new Huffman_Node;
            ptr->right=new Huffman_Node;
            ptr->left->right=ptr->left->left=ptr->right->left=ptr->right->right=NULL;
            map<int,char>::iterator it =s.begin();
            ptr->right->Heavy_Weight=it->first;
            ptr->right->Heavy_Weight=it->second;
            s.erase(it->first);
            ptr->left->Heavy_Weight=it->first;
            ptr->left->Heavy_Weight=it->second;
            ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            s.insert(pair<int,char>(ptr->Heavy_Weight,'*'));
            root=ptr;
        }
        void Insert_Node(map<int,char> &s)
        {
            Huffman_Node*ptr=new Huffman_Node;
            map<int,char>::iterator it =s.begin();
            if(it->second=='*') {
                ptr->right = new Huffman_Node;
                ptr->right->data = s[s.size() - 4];
                ptr->right->Heavy_Weight=int(s[s.size()-3]);
                ptr->right->left=ptr->right->right=NULL;
                ptr->left= root;
                ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            }
                else if((it++)->second=='*')
            {
                ptr->left = new Huffman_Node;
                ptr->left->data = s[s.size() - 2];
                ptr->left->Heavy_Weight=int(s[s.size()-1]);
                ptr->left->right=ptr->left->left=NULL;
                ptr->right= root;
                ptr->Heavy_Weight= ptr->left->Heavy_Weight+ ptr->right->Heavy_Weight;
            }
            root=ptr;
        }
        map<int,char> get_time(string s)
        {
           map<char,int> temp;
           map<int,char> res;
           for(char t:s)
           {
                   temp[t]++;
           }
           for(map<char,int>::iterator it=temp.begin();it!=temp.end();it++)
           {
               res[it->second]=it->first;
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
int main()
{
    HuffMan test("we will we will r u");
    Huffman_Node* ptr=test.Get_Root();
}

