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

