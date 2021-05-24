//
// Created by lee on 2021/5/24.
//

#ifndef UNTITLED1_FSTAR_H
#define UNTITLED1_FSTAR_H

#endif //UNTITLED1_FSTAR_H
#include"exp.h"
const int MaxNum = 100;

struct Edge{
    int to;//终点
    int next;//同起点的一条边上的编号
}Edge[MaxNum];
class FStar{
private:
    int head[MaxNum];//表示以i为节点的第一条边在边集数组的编号
    int NNode,NEdge,Count;
    vector<bool> visited;
public:
    FStar(int n,int m,vector<int> temp){
        NNode = n;
        NEdge = m;
        Count=0;
        reset();
        for(int i=0;i<=n;i++)
            head[i]=-1;
        if(temp.empty())
            return;
        else{
            for(int i=0;i<temp.size();i+=2)
            {
                Add_Edge(temp[i],temp[i+1]);
            }
        }
    }
    void reset()
    {
        visited=vector<bool>(NNode+1,false);;
    }
    void Add_Edge(int f,int s){
        Edge[Count].to=s;
        Edge[Count].next=head[f];
        head[f]=Count++;
    }
    void DFS(int i){
        //0为未经访问,1为经过访问
        cout<<"以"<<i<<"为起点的DFS结果如下"<<endl;
        dfs(i);
        reset();
        cout<<endl;
    }
    void dfs(int i){
        cout << i << " ";
        visited[i] = true;
        for (int j = head[i]; j != -1; j = Edge[j].next)
        {
            int next = Edge[j].to;
            if (!visited[next])
                dfs(next);
        }
    }
    void BFS(int i){
        cout<<"以"<<i<<"为起点的BFS结果如下"<<endl;
        bfs(i);
        reset();
        cout<<endl;
    }
    void bfs(int i){
        queue<int> temp;
        temp.push(i);
        while (!temp.empty())
        {
            int node = temp.front();
            temp.pop();
            cout << node << " ";
            visited[node] = true;
            for (int j = head[node]; j != -1; j = Edge[j].next)
            { // i 是边的编号
                if (!visited[Edge[j].to])
                    temp.push(Edge[j].to);
            }
        }
    }
    ~FStar(){
        cout<<"图已由编译器自动回收内存"<<endl;
    }
};