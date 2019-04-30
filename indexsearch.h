#ifndef INDEXSEARCH_H
#define INDEXSEARCH_H
#include "seqlist.h"
typedef  struct{
    KeyType key;            /*索引项，索引子表关键码最大值*/
    int start;              /*索引子表第1个元素位置*/
    int length;             /*索引子表长度*/
}IndexType;                 /*索引项类型*/
typedef struct{
    IndexType *idx;         /*索引项基址*/
    int length;             /*当前索引表长度*/
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
        cout<<"顺序表："<<endl;
        Display_SeqList(SL);
        cout<<"索引表："<<endl;
        Display_IdxList();
    }

    ~IndexSearch(){
        delete (SL);
        delete (IdxL);
    }
    /*索引查找*/
    int indexSearch(KeyType kx){
        int start,length,i,j;
        i=1;                /*顺序查找索引表，也可以采用折半查找法*/
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
    /*初始化索引表*/
    void Init_IdxList(int n)
    {
        IdxL->idx=new IndexType[n+1];
        /*多开辟1个存储单元，0位置不用*/
        if(IdxL->idx==nullptr)
        {
            cout<<"内存分配失败."<<endl;
            exit(-1);
        }
        IdxL->length=0;
    }
    /*创建索引表*/
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
    /*输出索引表*/
    void Display_IdxList()
    {
        int i;
        cout<<"索引项 开始位置 索引子表长度"<<endl;
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
