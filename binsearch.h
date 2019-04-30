#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <iostream>
using namespace std;
#include "seqsearch.h"

class BinSearch
{
public:
    BinSearch(KeyType key[],int n) {
        SL=new SeqList();
        Init_SeqList(n);
        Create_SeqList(key,n);
        cout<<"有序表:"<<endl;
        Display_SeqList();
    }
    /*折半查找，若找到，则返回该元素在数组中的下标，否则返回0*/
    int binSearch(KeyType kx){
        int low,mid,high,k=0;
        int midkey=0;
        low=1;
        high=SL->length;
        while (low<=high) {
            mid=(low+high)/2;
            midkey=SL->data[mid].key;
            if(kx<SL->data[mid].key)
                high=mid-1;
            else if (kx>SL->data[mid].key) {
                low=mid+1;
            }
            else {
                k=mid;      /*查找成功*/
                break;
            }
        }
        return k;
    }
private:
    /*初始化顺序表*/
    void Init_SeqList(int n)
    {
        SL->data=new DataType[n+1];
        /*多开辟1个存储单元，0位置不用*/
        if(SL->data==nullptr)
        {
            cout<<"内存分配失败."<<endl;
            exit(-1);
        }
        SL->length=0;
    }
    /*创建顺序表*/
    void Create_SeqList(KeyType key[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            SL->data[i+1].key=key[i];
        }
        SL->length=n;
    }
    /*输出顺序表*/
    void Display_SeqList()
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
private:
    SeqList *SL;
};
#endif // BINSEARCH_H
