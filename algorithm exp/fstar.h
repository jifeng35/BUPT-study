//
// Created by lee on 2021/5/24.
//

#ifndef UNTITLED1_FSTAR_H
#define UNTITLED1_FSTAR_H

#endif //UNTITLED1_FSTAR_H
#include"exp.h"
const int MaxNum = 100;
int num;
struct Edge{
    int to;//终点
    int next;//同起点的一条边上的编号
    int weight;//权重
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
            for(int i=0;i<temp.size();i+=3)
            {
                Add_Edge(temp[i],temp[i+1],temp[i+2]);
                Add_Edge(temp[i+1],temp[i],temp[i+2]);
            }
        }
    }
    int Prim()
    {
        reset();//reset visited数组
        int ans=0;
        int dis[MaxNum];//距离数组,用于与权重进行比较
        int now = 1;//起始位置,可进行更改
        for(int i=2;i<=NNode;i++) dis[i] = 0x3f3f3f3f; // 初始化距离为最大
        for(int i=head[1];i!=-1;i=Edge[i].next) // 从1顶点开始
            dis[Edge[i].to] = min(Edge[i].weight,dis[Edge[i].to]); // 找边权最小点
        while(num < NNode-1){
            int minn = 0x3f3f3f3f;
            visited[now] = 1; // 第一个点已经确定，标记一下
            for(int i=1;i<=NNode;i++){
                if(minn > dis[i] && !visited[i]){
                    minn = dis[i];
                    now = i;
                }
            }
            ans += minn;
            num++; // 边加进去
            for(int i=head[now];i!=-1;i=Edge[i].next){ // 当前起点为now
                if(dis[Edge[i].to]>Edge[i].weight && !visited[Edge[i].to]) {
                    dis[Edge[i].to] = Edge[i].weight;
                }
            }
        }
        return ans;
    }
    void reset()
    {
        visited=vector<bool>(MaxNum,false);;
    }
    void Add_Edge(int f,int s,int w){
        Edge[Count].to=s;
        Edge[Count].next=head[f];
        Edge[Count].weight=w;
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
            if(!visited[node])
            cout << node << " ";
            visited[node] = true;
            for (int j = head[node]; j != -1; j = Edge[j].next)
            { // i 是边的编号
                if (!visited[Edge[j].to])
                    temp.push(Edge[j].to);
            }
        }
    }
    void PAINT(vector<int> &ArrColor){
        reset();
        int NumColor = 0;
        for (int i = 1; i < ArrColor.size(); i++){
            paint(ArrColor, i, NumColor);
            cout <<"The Node which is containing "<< i << " is painted by " << char('A' + ArrColor[i]) << endl;
        }
    }
    void paint(vector<int> &ArrColor, int j, int &NumColor){
        if (visited[j])
            return;
        visited[j]=true;
        vector<bool> color_use(NumColor,false);
        for (int i=head[j];i!=-1;i=Edge[i].next){
            int next_node=Edge[i].to;
            if (visited[next_node])
                color_use[ArrColor[next_node]] = true; //将这种颜色标记为true
        }
        bool add=true;
        for (int i=0;i<NumColor;i++){
            if (color_use[i]==false){// 如果没有被占用
                ArrColor[j]=i;add=false;break;
            }
        }
        if (add == true){
            ArrColor[j]=NumColor; // 将第一种颜色标号为0
            NumColor+=1;
        }
    }
    ~FStar(){
        cout<<"图已由编译器自动回收内存";
    }
};