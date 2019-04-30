#ifndef SEQSEARCH_H
#define SEQSEARCH_H
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

class SeqSearch
{
public:
    SeqSearch(KeyType key[],int n){
        SL=new SeqList();
        Init_SeqList(n);
        Create_SeqList(key,n);
        cout<<"˳���:"<<endl;
        Display_SeqList();
    }
    ~SeqSearch(){
        delete SL;
    }
    /*��������˳����ң����ҵ����򷵻ظ�Ԫ���������е��±꣬���򷵻�0*/
    int Seq_Search1(KeyType kx)
    {
        int i;
        SL->data[0].key=kx;     /*��ż�����*/
        i=SL->length;
        while (kx!=SL->data[i].key) {
            i--;
        }
        return (i);
    }
    /*����������˳����ң����ҵ����򷵻ظ�Ԫ���������е��±꣬���򷵻�0*/
    int Seq_Search2(KeyType kx)
    {
        int i=1;
        while (i<=SL->length && kx!=SL->data[i].key) {
            i++;
        }
        if(i>SL->length)
            return (0);
        else
            return (i);
    }
private:
    /*��ʼ��˳���*/
    void Init_SeqList(int n)
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
    void Create_SeqList(KeyType key[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            SL->data[i+1].key=key[i];
        }
        SL->length=n;
    }
    /*���˳���*/
    void Display_SeqList()
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
private:
    SeqList *SL;
};

#endif // SEQSEARCH_H
