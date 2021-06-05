//
// Created by lee on 2021/6/2.
//
#ifndef UNTITLED1_SORT_H
#define UNTITLED1_SORT_H
#endif //UNTITLED1_SORT_H
#include "exp.h"
const int MAX=10000;//生成数据的多少
const int BN=1000;//水桶的个数
const bool print_or_not=0;//是否打印排序结果
class my_sort{
public:
    void Bubble(vector<int> a);
    void bubble(vector<int> &a);
    void Quick(vector<int> a);
    void quick(vector<int> &a,int low,int high);
    void Heap(vector<int> a);
    void heap(vector<int> &a);
    void print(vector<int> a);
    void my_swap(int &a,int &b);
    void make_tree(vector<int> &a,int time);
    void sink(vector<int> &a,int time);
    void Insert(vector<int> a);
    void insert(vector<int> &a);
    void Shell(vector<int> a);
    void shell(vector<int> &a);
    void bucket(vector<int>&a);
    void bucket(vector<int>&a,char useless);
    void Bucket(vector<int>a);
    void counting(vector<int> &a);
    void Counting(vector<int> a);
    void Radix(vector<int> a);
    void radix(vector<int> &a);
    void select(vector<int>&a);
    void Select(vector<int> a);
    void print_time();
private:
    double Bubble_Time;
    double Quick_Time;
    double Heap_Time;
    double Select_Time;
    double Shell_Time;
    double Bucket_Time;
    double Counting_Time;
    double Radix_Time;
    double Insert_Time;
};
void my_sort::my_swap(int&a,int&b){
    if(a==b)
        return;
    a=a+b;
    b=a-b;
    a=a-b;
}
void my_sort::bubble(vector<int> &a){
   int note=a.size();
        while(note>1){
            int temp=0;
        for (int j = 0; j < note-1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                temp = j + 1;
            }
        }
        note=temp;
    }
}
void my_sort::print(vector<int> a){
    for(int i=0;i<a.size();++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void my_sort::Bubble(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    bubble(b);
    clock_t e_time=clock();
    Bubble_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
    print(b);
}
void my_sort::print_time(){
    if(Bubble_Time!=-9.2559631349317831E+61)
    cout<<"Bubble_Sort Time is "<<Bubble_Time<<"s\t\t\t";
    if(Quick_Time!=-9.2559631349317831E+61)
    cout<<"Quick_Sort Time is "<<Quick_Time<<"s"<<endl;
    if(Heap_Time!=-9.2559631349317831E+61)
        cout<<"Heap_Sort Time is "<<Heap_Time<<"s\t\t\t";
    if(Select_Time!=-9.2559631349317831E+61)
        cout<<"Select_Sort Time is "<<Select_Time<<"s"<<endl;
    if(Shell_Time!=-9.2559631349317831E+61)
        cout<<"Shell_Sort Time is "<<Shell_Time<<"s\t\t\t";
    if(Bucket_Time!=-9.2559631349317831E+61)
        cout<<"Bucket_Sort Time is "<<Bucket_Time<<"s"<<endl;
    if(Counting_Time!=-9.2559631349317831E+61)
        cout<<"Counting_Sort Time is "<<Counting_Time<<"s\t\t\t";
    if(Radix_Time!=-9.2559631349317831E+61)
        cout<<"Radix_Sort Time is "<<Radix_Time<<"s"<<endl;
    if( Insert_Time!=-9.2559631349317831E+61)
        cout<<"Insert_Sort Time is "<< Insert_Time<<"s\t\t\t";
}
void my_sort::quick(vector<int> &a,int low,int high){
    if(low>=high){
        return;
    }
    int left=low;
    int right=high;
    int key=a[left];
    while(right>left){
            while(left<right&&a[right]>=key)
                --right;
            a[left]=a[right];
            while(left<right&&a[left]<=key)
                ++left;
            a[right]=a[left];
    }
    a[left]=key;
    quick(a,low,left-1);
    quick(a,left+1,high);
}
void my_sort::Quick(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    quick(b,0,b.size()-1);
    clock_t e_time=clock();
    Quick_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
    print(b);
}
void my_sort::Heap(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    heap(b);
    clock_t e_time=clock();
    Heap_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
    print(b);
}
void my_sort::heap(vector<int> &a){
    int time=0;
    make_tree(a, time);
    while(time<a.size()){
        time++;
        swap(a[0],a[a.size()-time]);//此时根节点(第一个数组内元素)为最大数,将其与数组末尾swap,不再访问最后一个元素
        sink(a,time);
    }
}
void my_sort::make_tree(vector<int> &a,int time) {
    bool temp =true;//使用数组构建伪二叉树,顺序为层序遍历,构建完全二叉树
    do{
        temp=true;//指示数组是否发生变化
        for (int i = 0; i < a.size()-time && (2 * i + 1) < a.size()-time; i++) {
            if ((2 * i + 2) < a.size()-time) {
                if (a[2 * i + 1] > a[2 * i + 2]) {
                    if (a[2 * i + 1]> a[i]) {
                        swap(a[2 * i + 1],a[i]);
                        temp=false;
                    }
                }
                else {
                    if (a[2 * i + 2] > a[i]) {
                        swap(a[2 * i + 2],a[i]);
                        temp=false;
                    }
                }
            }
            else {
                if (a[2 * i + 1] > a[i]) {
                    swap(a[2 * i + 1],a[i]);
                    temp=false;
                }
            }
        }
    }while(!temp);
}
void my_sort::sink(vector<int> &a,int time){
    bool temp =true;//使用数组构建伪二叉树,顺序为层序遍历,构建完全二叉树
    do{
        for (int i = 0; i < a.size()-time && (2 * i + 1) < a.size()-time;) {
            int temp=i;
            if ((2 * i + 2) < a.size()-time) {
                if (a[2 * i + 1] > a[2 * i + 2]) {
                    if (a[2 * i + 1] > a[i]) {
                        swap(a[2 * i + 1], a[i]);
                        temp = false;
                        i=2*i+1;
                    }
                } else {
                    if (a[2 * i + 2] > a[i]) {
                        swap(a[2 * i + 2], a[i]);
                        temp = false;
                        i=2*i+2;
                    }
                }
            } else {
                if (a[2 * i + 1] > a[i]) {
                    swap(a[2 * i + 1], a[i]);
                    temp = false;
                    i=2*i+1;
                }
            }
            if(temp==i)
                break;
        }
    }while(!temp);
}
void my_sort::Insert(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    select(b);
    clock_t e_time=clock();
    Select_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
    print(b);
}
void my_sort::insert(vector<int> &a){
    if(a[0]>a[1])
        swap(a[0],a[1]);
    for(int i=2;i<a.size();i++)
    {
        for(int j=i-1;j>=0;) {
            if(a[i]<a[0])
            {
                a.insert(a.begin(),a[i]);
                a.erase(a.begin()+1+i);
                break;
            }
            else if (a[i] < a[j]) {
                j--;
            }
            else{
                a.insert(a.begin()+j+1,a[i]);
                a.erase(a.begin()+i+1);
                break;
            }
        }
    }
}
void my_sort::Shell(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    shell(b);
    clock_t e_time=clock();
    Shell_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
    print(b);
}
void my_sort::shell(vector<int>&a){
    int gap=a.size()/2;
    bool temp=false;
    do{
        temp=false;
        for(int i=0;(i+gap)<a.size();i++)
        {
            if(a[i]>a[i+gap]) {
                swap(a[i], a[i + gap]);
                temp=true;
            }
        }
        if(!temp)
            gap=gap/2;
    }while(gap);
}
void my_sort::Bucket(vector<int>a){
    vector<int> b=a;
    clock_t s_time=clock();
    bucket(b,'a');
    clock_t e_time=clock();
    Bucket_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
    print(b);
}
void my_sort::bucket(vector<int>&a){
    int max=0,min=a[0];
    for(int i=0;i<a.size();i++){
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    vector<int> a1;vector<int> a2;vector<int> a3;vector<int> a4;vector<int> a5;
    for(int i=0;i<a.size();i++){
        if(a[i]<(min+(max-min)*1/5)) {
            if(a1.empty()||a[i]>a1[a1.size()-1]) { a1.push_back(a[i]); }
            else{
                for (int i1 = 0; i1 < a1.size(); i1++) {
                    if (a1[i1] > a[i]) {
                        a1.insert(a1.begin() + i1, a[i]);
                        break;
                    }
                }
            }
        }
        else if(a[i]<(min+(max-min)*2/5)) {
            if(a2.empty()||a[i]>a2[a2.size()-1]) { a2.push_back(a[i]); }
            else{
                for (int i1 = 0; i1 < a2.size(); i1++) {
                    if (a2[i1] > a[i]) {
                        a2.insert(a2.begin() + i1, a[i]);
                        break;
                    }
                }
            }
        }
        else if(a[i]<(min+(max-min)*3/5)) {
            if(a3.empty()||a[i]>a3[a3.size()-1]) { a3.push_back(a[i]); }
            else{
                for (int i1 = 0; i1 < a3.size(); i1++) {
                    if (a3[i1] > a[i]) {
                        a3.insert(a3.begin() + i1, a[i]);
                        break;
                    }
                }
            }
        }
        else if(a[i]<(min+(max-min)*4/5)) {
            if(a4.empty()||a[i]>a4[a4.size()-1]) { a4.push_back(a[i]); }
            else{
                for (int i1 = 0; i1 < a4.size(); i1++) {
                    if (a4[i1] > a[i]) {
                        a4.insert(a4.begin() + i1, a[i]);
                        break;
                    }
                }
            }
        }
        else if(a[i]<=max) {
            if(a5.empty()||a[i]>a5[a5.size()-1]) { a5.emplace_back(a[i]); }
            else{
                for (int i1 = 0; i1 < a5.size(); i1++) {
                    if (a5[i1] > a[i]) {
                        a5.insert(a5.begin() + i1, a[i]);
                        break;
                    }
                }
            }
        }
    }
    a.clear();
    for(int i=0;i<a1.size();i++){
        a.emplace_back(a1[i]);
    }
    for(int i=0;i<a2.size();i++){
        a.emplace_back(a2[i]);
    }
    for(int i=0;i<a3.size();i++){
        a.emplace_back(a3[i]);
    }
    for(int i=0;i<a4.size();i++){
        a.emplace_back(a4[i]);
    }
    for(int i=0;i<a5.size();i++){
        a.emplace_back(a5[i]);
    }
}
void my_sort::bucket(vector<int>&a,char useless){
    int max=0,min=a[0];
    for(int i=0;i<a.size();i++){
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    vector<vector<int>> a1(BN+100);
    for(int ai=0;ai<a.size();ai++){
        int i= (a[ai]-min)/((max-min)/BN);
        if(a[ai]==max)
            a1[BN].emplace_back(max);
                else if (a1[i].empty() || a[ai] > a1[i][a1[i].size() - 1])a1[i].emplace_back(a[ai]);
                else {
                    for (int i1 = 0; i1 < a1[i].size(); i1++) {
                        if (a1[i][i1] > a[ai]) {
                            a1[i].insert(a1[i].begin() + i1, a[ai]);
                            break;
                        }
                    }
                }
            }
    a.clear();
    for(int i=0;i<a1.size();i++){
        if(!a1[i].empty()) {
            for (int j = 0; j < a1[i].size(); j++) {
                a.emplace_back(a1[i][j]);
            }
        }
    }
}
void my_sort::counting(vector<int> &a){
    int max=0,min=a[0];
    for(int i=0;i<a.size();i++){
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
   vector<int> temp(max-min+1,0);
    for(int i=0;i<a.size();i++){
        temp[a[i]-min]++;
    }
    int num=0;
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i];j++)
            a[num++]=i+min;
        }
    }
void my_sort::Counting(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    counting(b);
    clock_t e_time=clock();
    Counting_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
        print(b);
}
void my_sort::radix(vector<int> &a){
    int time=1;
    int len=a.size();
    while(time<100000){
        vector<vector<int>> temp(10);
        for (int i = 0; i < len; i++) {
            temp[(a[i] / time) % 10].emplace_back(a[i]);
        }
        time*=10;
        a.clear();
        for (int j = 0; j < temp.size(); j++) {
            if(!temp[j].empty())
            for (int i = 0; i < temp[j].size(); i++) {
                a.emplace_back(temp[j][i]);
            }
        }
        temp.clear();
    }
}
void my_sort::Radix(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    radix(b);
    clock_t e_time=clock();
    Radix_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    if(print_or_not)
        print(b);
}
void my_sort::select(vector<int> &a){
    for(int j=0;j<a.size();j++){
        int min=a[j];
        int temp=j;
        for (int i = j; i < a.size(); i++) {
            if(min>a[i]) {
                min = a[i];
                temp = i;
            }
        }
        swap(a[temp],a[j]);
    }
}
void my_sort::Select(vector<int> a){
    vector<int> b=a;
    clock_t s_time=clock();
    select(b);
    clock_t e_time=clock();
    Select_Time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    //if(print_or_not)
        print(b);
}
