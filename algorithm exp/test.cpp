//
// Created by lee on 2021/5/14.
//
#include"exp.h"
int main()
{
    map<char,int> test;
    test['b']=1;
    test['a']=1;
    for(map<char,int>::iterator it = test.begin(); it != test.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    test.erase('a');cout<<"After Delete"<<endl;
    for(map<char,int>::iterator it = test.begin(); it != test.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    test.insert(pair<char,int>( '*',1));
    for(map<char,int>::iterator it = test.begin(); it != test.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    map<char,int>::iterator it = test.begin();
    cout<<it->first<<" "<<it->second<<endl;
    it++;
    cout<<it->first<<" "<<it->second<<endl;
    if(test.find('!')==test.end())
        cout<<endl;
    //cout<<test.size();
}

