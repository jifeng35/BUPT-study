//
// Created by lee on 2021/5/23.
//
#ifndef UNTITLED1_ALGRAPH_H
#define UNTITLED1_ALGRAPH_H
#endif //UNTITLED1_ALGRAPH_H
#include"exp.h"
const int MAXSIZE = 10;
struct ArcNode{
    int adjvex;//数据域:邻接顶点下标
    ArcNode *nextarc;//指针域:指向下一条弧接点
};
struct VertexNode{
    char vertex;//数据域:顶点信息
    ArcNode *firstarc;//指针域:指向第一条弧
};
template<class T>class ALGraph{
public:
    ALGraph(ifstream &fin);
    void DFS(int v){
        cout<<adjlist[v].vertex;
        visited[v]=1;
        ArcNode*p=adjlist[v].firstarc;
        while(p){
            int j=p->adjvex;
            if(visited[j]==0)
                DFS(j);
            p=p->nextarc;
        }
        reset();
    }
    void BFS(int v){
        int queue[MAXSIZE];
        int f=0,r=0;
        cout<<adjlist[v].vertex;
        visited[v]=1;
        queue[++r]=v;
        while(f!=r){
            v=queue[++f];
            ArcNode*p=adjlist[v].firstarc;
            while(p){
                int j=p->adjvex;
                if(visited[j]==0)
                {
                    cout<<adjlist[j].vertex;
                    visited[j]=1;queue[++r]=j;
                }
                p=p->nextarc;
            }
        }
        reset();
    }
    void reset(){
        for(int i=0;i<MAXSIZE;i++){
            visited[i]=false;
        }
    }
    ~ALGraph();
private:
    VertexNode adjlist[MAXSIZE];//接点
    int vNum,arcNum;//顶点数目和弧数目
    bool visited[MAXSIZE];
};