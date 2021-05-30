//
// Created by lee on 2021/5/18.
//
#include"exp.h"
struct Node{
    int weight;
    int right;
    int left;
    int mother;
};
struct H_Code{
    char data;
    string code;
};
class Huffman
{
private:
    Node*root;
    H_Code* list;
    int N;
    void code(int i,string New_Code);
public:
    void Create(vector<int> t,int n,vector<char> name);
    void Create_Code_Table();
    void Encode(string s,string &d);
    void Decode(string s,string &d);
    //~Huffman();
};
void Huffman::Create(vector<int> t,int n,vector<char> name){
    N=n;
    list= new H_Code[N];
    root=new Node[2*N-1];
    for(int i=0;i<N;i++) {
        root[i].weight = t[i];
        root[i].left = root[i].right = root[i].mother = -1;
        list[i].data=name[i];
       }
    int x=0;
    int y=1;
        for(int i=n;i<2*N-1;i++){
            root[x].mother=root[y].mother=i;
            root[i].weight=root[x].weight+root[y].weight;
            root[i].left=x;
            root[i].right=y;
            root[i].mother=-1;
            x+=2;
            y+=2;
        }
    }
void Huffman::code(int i,string New_Code)
{
    if(root[i].left==-1){
        list[i].code=New_Code;
        return;
    }
    code(root[i].left,New_Code+"0");
    code(root[i].right,New_Code+"1");
}
void Huffman::Create_Code_Table() {
    code(2*N-2,"");
}
void Huffman::Decode(string s,string &d){
    int i=0;
    while(i!=s.size()){
        int parent =2*N-2;
        while(root[parent].left!=-1)
        {
            if(s[i]=='0')
                parent=root[parent].left;
            else
                parent=root[parent].right;
            i++;
        }
        d+=list[parent].data;
    }
}
void Huffman::Encode(string s,string &d)
{
    H_Code*ptr=list;
    int i=0;
    while(i!=s.size())
    {
        if(s[i]==ptr->data)
        {
            for(char t:ptr->code)
            {
                d.push_back(t);
            }
            i++;
            ptr=list;
        }
        else{
            ptr++;
        }
    }
}
multimap<int,char> get_time(string s)
{
    map<char,int> temp;
    multimap<int,char> res;
    for(int i=0;i<s.size();i++)
    {
        temp[s[i]]++;
    }
    for(map<char,int>::iterator it=temp.begin();it!=temp.end();it++)
    {
        res.insert(pair<int,char>(it->second,it->first));
    }
    return res;
}
string _2jz(int a)
{
    string temp;
    while(a!=0)
    {
        a/=2;
        temp.push_back(a%2+48);
    }
    temp.push_back(48);
    return temp;
}
int main(){
    //cout<<"please input:"<<endl;
    string s;
    //cin>>noskipws;
    //cin>>s;
    s="I love data Structure, I love Computer.I will try my best to study data Structure.";
    multimap<int,char> temp;
    temp=get_time(s);
    vector<int> temp1;
    vector<char> temp2;
    int i=0;
    for(multimap<int,char>::iterator it=temp.begin();it!=temp.end();it++,i++)
    {
        temp1.push_back(it->first);
        temp2.push_back(it->second);
    }
    Huffman test;
    test.Create(temp1,temp.size(),temp2);
    test.Create_Code_Table();
    string d1;
    test.Encode(s,d1);
    cout<<d1<<endl<<"Code by huffman the size is "<<d1.size()<<endl;
    int size=0;
    for(char t:s){
        cout<<_2jz(int(t));
        size+=(_2jz(int(t))).size();
    }
    cout<<endl<<"Code by ascii the size is "<<size<<endl;
    cout<<"The compression ratio is "<<float(d1.size()*100)/float(size)<<"%"<<endl;
    s.clear();
    test.Decode(d1,s);
    cout<<s<<endl;
    //test

}

