#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
using namespace std;
typedef int KeyType;            /*�ؼ�������*/
typedef struct{
    KeyType key;                /*�ؼ�����*/
//    OtherType other;          /*���������ʾ������*/
}DataType;                      /*����Ԫ������*/
typedef struct{
    DataType *data;             /*����Ԫ�ػ�ַ*/
    int length;                 /*��ǰ˳�����*/
}SeqList;                       /*˳�������*/
/*��ʼ��˳���*/
void Init_SeqList(SeqList *SL,int n)
{
    SL->data=new DataType[n+1];
    /*�࿪��1���洢��Ԫ��0λ�����ڼ����ڻ���*/
    if(SL->data==nullptr)
    {
        cout<<"�ڴ����ʧ��."<<endl;
        exit(-1);
    }
    SL->length=0;
}
/*����˳���*/
void Create_SeqList(SeqList *SL,KeyType key[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        SL->data[i+1].key=key[i];
    }
    SL->length=n;
}
/*���˳���*/
void Display_SeqList(SeqList *SL)
{
    int i;
    cout<<"λ�ã� ";
    for(i=1;i<=SL->length;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Ԫ�أ� ";
    for(i=1;i<=SL->length;i++)
    {
        cout<<SL->data[i].key<<" ";
    }
    cout<<endl;
}
#endif // SEQLIST_H
