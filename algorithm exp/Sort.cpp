//
// Created by lee on 2021/6/2.
//
#include"Sort.h"

int main(){
    my_sort test;
    vector<int> a(MAX,0);
    srand(time(NULL));
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand();
    }
    vector<int> b=a;//bΪ˳��
    test.quick(b,0,b.size()-1);
    vector<int> c=b;//cΪ����
    reverse(c.begin(),c.end());
    //test.print(a);
    cout<<"����Ϊ������ݵĽ��:"<<endl;
    test.Bubble(a);//ð������
    test.Quick(a);//��������
    test.Heap(a);//������
    test.Select(a);//ѡ������
    test.Shell(a);//ϣ������
    test.Bucket(a);//Ͱ����
    test.Counting(a);//��������
    test.Radix(a);//��������
    test.Insert(a);//��������
    test.Merge(a);
    test.print_time();
    cout<<"����Ϊ˳�����ݵĽ��:"<<endl;
    test.Bubble(b);//ð������
    test.Quick(b);//��������
    test.Heap(b);//������
    test.Select(b);//ѡ������
    test.Shell(b);//ϣ������
    test.Bucket(b);//Ͱ����
    test.Counting(b);//��������
    test.Radix(b);//��������
    test.Insert(b);//��������
    test.Merge(b);
    test.print_time();
    cout<<"����Ϊ�������ݵĽ��:"<<endl;
    test.Bubble(c);//ð������
    test.Quick(c);//��������
    test.Heap(c);//������
    test.Select(c);//ѡ������
    test.Shell(c);//ϣ������
    test.Bucket(c);//Ͱ����
    test.Counting(c);//��������
    test.Radix(c);//��������
    test.Insert(c);//��������
    test.Merge(c);
    test.print_time();
}