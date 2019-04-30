#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
using namespace std;
typedef int KeyType;            /*关键码类型*/
typedef struct{
    KeyType key;                /*关键码项*/
//    OtherType other;          /*其他数据项，示例不用*/
}DataType;                      /*数据元素类型*/
typedef struct{
    DataType *data;             /*数据元素基址*/
    int length;                 /*当前顺序表长度*/
}SeqList;                       /*顺序表类型*/
/*初始化顺序表*/
void Init_SeqList(SeqList *SL,int n)
{
    SL->data=new DataType[n+1];
    /*多开辟1个存储单元，0位置用于监视哨或不用*/
    if(SL->data==nullptr)
    {
        cout<<"内存分配失败."<<endl;
        exit(-1);
    }
    SL->length=0;
}
/*创建顺序表*/
void Create_SeqList(SeqList *SL,KeyType key[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        SL->data[i+1].key=key[i];
    }
    SL->length=n;
}
/*输出顺序表*/
void Display_SeqList(SeqList *SL)
{
    int i;
    cout<<"位置： ";
    for(i=1;i<=SL->length;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"元素： ";
    for(i=1;i<=SL->length;i++)
    {
        cout<<SL->data[i].key<<" ";
    }
    cout<<endl;
}
#endif // SEQLIST_H
