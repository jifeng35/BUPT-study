//
// Created by lee on 2021/5/19.
//
#include"algraph.h"
template<class T>ALGraph<T>::ALGraph(ifstream &fin){
    fin>>vNum;
    fin>>arcNum;
    for(int k=0;k<vNum;k++){
        fin>>adjlist[k].vertex;
        adjlist[k].firstarc=NULL;
    }
    for(int k=0;k<arcNum;k++){
        int i,j;
        fin>>i>>j;
        ArcNode*s=new ArcNode;
        s->adjvex =j;
        s->nextarc=adjlist[i].firstarc;
        adjlist[i].firstarc=s;
    }
    for(int i=0;i<MAXSIZE;i++){
        visited[i]=false;
    }
}
int main()
{
    cout<<1<<endl;
}