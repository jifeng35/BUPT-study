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
    int to;//�յ�
    int next;//ͬ����һ�����ϵı��
    int weight;//Ȩ��
}Edge[MaxNum];
class FStar{
private:
    int head[MaxNum];//��ʾ��iΪ�ڵ�ĵ�һ�����ڱ߼�����ı��
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
            }
        }
    }
    int Prim()
    {
        reset();//reset visited����
        int ans=0;
        int dis[MaxNum];//��������,������Ȩ�ؽ��бȽ�
        int now = 1;//��ʼλ��,�ɽ��и���
        for(int i=2;i<=NNode;i++) dis[i] = 0x3f3f3f3f; // ��ʼ������Ϊ���
        for(int i=head[1];i!=-1;i=Edge[i].next) // ��1���㿪ʼ
            dis[Edge[i].to] = min(Edge[i].weight,dis[Edge[i].to]); // �ұ�Ȩ��С��
        while(num < NNode-1){
            int minn = 0x3f3f3f3f;
            visited[now] = 1; // ��һ�����Ѿ�ȷ�������һ��
            for(int i=1;i<=NNode;i++){
                if(minn > dis[i] && !visited[i]){
                    minn = dis[i];
                    now = i;
                }
            }
            ans += minn;
            num++; // �߼ӽ�ȥ
            for(int i=head[now];i!=-1;i=Edge[i].next){ // ��ǰ���Ϊnow
                if(dis[Edge[i].to]>Edge[i].weight && !visited[Edge[i].to]) {
                    dis[Edge[i].to] = Edge[i].weight;
                }
            }
        }
        return ans;
    }
    void reset()
    {
        visited=vector<bool>(NNode+1,false);;
    }
    void Add_Edge(int f,int s,int w){
        Edge[Count].to=s;
        Edge[Count].next=head[f];
        Edge[Count].weight=w;
        head[f]=Count++;
    }
    void DFS(int i){
        //0Ϊδ������,1Ϊ��������
        cout<<"��"<<i<<"Ϊ����DFS�������"<<endl;
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
        cout<<"��"<<i<<"Ϊ����BFS�������"<<endl;
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
            { // i �Ǳߵı��
                if (!visited[Edge[j].to])
                    temp.push(Edge[j].to);
            }
        }
    }
    ~FStar(){
        cout<<"ͼ���ɱ������Զ������ڴ�"<<endl;
    }
};