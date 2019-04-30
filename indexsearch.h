#ifndef INDEXSEARCH_H
#define INDEXSEARCH_H
#include "seqlist.h"
typedef  struct{
    KeyType key;            /*����������ӱ�ؼ������ֵ*/
    int start;              /*�����ӱ��1��Ԫ��λ��*/
    int length;             /*�����ӱ���*/
}IndexType;                 /*����������*/
typedef struct{
    IndexType *idx;         /*�������ַ*/
    int length;             /*��ǰ��������*/
}IdxList;

class IndexSearch
{
public:
    IndexSearch(KeyType key[],IndexType index[],int n) {
        SL=new SeqList();
        IdxL=new IdxList();
        Init_SeqList(SL,n);
        Init_IdxList(4);
        Create_SeqList(SL,key,n);
        Create_IdxList(index,4);
        cout<<"˳���"<<endl;
        Display_SeqList(SL);
        cout<<"������"<<endl;
        Display_IdxList();
    }

    ~IndexSearch(){
        delete (SL);
        delete (IdxL);
    }
    /*��������*/
    int indexSearch(KeyType kx){
        int start,length,i,j;
        i=1;                /*˳�����������Ҳ���Բ����۰���ҷ�*/
        while (i<=IdxL->length && kx>IdxL->idx[i].key) {
            i++;
        }
        if(i>IdxL->length)
            return 0;
        else {
            start=IdxL->idx[i].start;
            length=IdxL->idx[i].length;
            j=start;
            while (j<=start+length-1 && kx!=SL->data[j].key) {
                j++;
            }
            if(j>start+length-1)
                return 0;
            else {
                return j;
            }
        }
    }
private:
    /*��ʼ��������*/
    void Init_IdxList(int n)
    {
        IdxL->idx=new IndexType[n+1];
        /*�࿪��1���洢��Ԫ��0λ�ò���*/
        if(IdxL->idx==nullptr)
        {
            cout<<"�ڴ����ʧ��."<<endl;
            exit(-1);
        }
        IdxL->length=0;
    }
    /*����������*/
    void Create_IdxList(IndexType index[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            IdxL->idx[i+1].key=index[i].key;
            IdxL->idx[i+1].start=index[i].start;
            IdxL->idx[i+1].length=index[i].length;
        }
        IdxL->length=n;
    }
    /*���������*/
    void Display_IdxList()
    {
        int i;
        cout<<"������ ��ʼλ�� �����ӱ���"<<endl;
        for(i=1;i<=IdxL->length;i++)
        {
            cout<<IdxL->idx[i].key<<" ";
            cout<<IdxL->idx[i].start<<" ";
            cout<<IdxL->idx[i].length<<endl;
        }
        cout<<endl;
    }
private:
    SeqList *SL;
    IdxList *IdxL;
};
#endif // INDEXSEARCH_H
