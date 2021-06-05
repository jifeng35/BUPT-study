//
// Created by lee on 2021/6/5.
//

#ifndef UNTITLED1_GREEDY_H
#define UNTITLED1_GREEDY_H

#endif //UNTITLED1_GREEDY_H
#include"exp.h"
const int MacNum=3;
class Solution{
public:
    void greedy_algorithm(vector<int> a);
    void print_result(vector<vector<int>> a);
    void update(vector<int>&time,vector<vector<int>> temp,int &Max);
    int find_min(vector<int>time);
};
void Solution::greedy_algorithm(vector<int> a) {
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int Max_Time=0;
        vector<vector<int>> temp(MacNum);
        vector<int> time(MacNum,0);
        for(int i=0;i<a.size();i++){
            for(int j=0;j<temp.size();j++){
                if(time[j]+a[i]>Max_Time) {
                    temp[find_min(time)].emplace_back(a[i]);
                    break;
                }
                else {
                    temp[j].emplace_back(a[i]);
                    break;
                }
            }
            update(time,temp,Max_Time);
        }
        print_result(temp);
}
void Solution::update(vector<int>&time,vector<vector<int>> temp,int &Max){
    int Mx=0;
    for(int i=0;i<time.size();i++)
    {
        time[i]=0;
        for(int j=0;j<temp[i].size();j++){
            time[i]+=temp[i][j];
            if(Mx<time[i])
                Mx=time[i];
        }
    }
    Max=Mx;
}
void Solution::print_result(vector<vector<int>> a){
    for(int i=0;i<a.size();i++){
        int total=0;
        cout<<"Machine "<<i+1<<"\'s missions are: "<<endl;
        for(int j=0;j<a[i].size();j++){
            total+=a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        cout<<"The total time is"<<total<<endl;
    }
}
int Solution::find_min(vector<int> time) {
    int min_pos=0;
    int Min=time[0];
    for(int i=1;i<time.size();i++){
        if(Min>time[i]){
            Min=time[i];
            min_pos=i;
        }
    }
    return min_pos;
}