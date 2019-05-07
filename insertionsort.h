#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "seqlist.h"

class InsertionSort
{
public:
    InsertionSort(KeyType key[],int n) {
        SL=new SeqList();
        Init_SeqList(SL,n);
        Create_SeqList(SL,key,n);
    }
    void Insertion_Sort(){
        cout<<"排序前："<<endl;
        Display_SeqList(SL);
        //BInsertion_Sort();
        ShellInsertion_Sort();
        cout<<"排序后："<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
private:
    /*直接插入排序*/
    void SInsertion_Sort(){
        int i,j,k;
        for (i=2;i<SL->length;i++) {
            if(SL->data[i].key<SL->data[i-1].key)
            {
                SL->data[0]=SL->data[i];    /*待插入元素暂存入SL->data[0]*/
                j=i-1;                      /*查找插入位置*/
                while (SL->data[0].key <SL->data[j].key) {
                    j--;
                }
                for (k=i-1;k>j;k--) {       /*j+1为插入位置*/
                    SL->data[k+1]=SL->data[k];  /*后移元素，留出插入位置*/
                }
                SL->data[j+1]=SL->data[0];      /*待插入元素插入到正确位置*/
            }
        }
    }

    /*折半插入排序*/
    void BInsertion_Sort(){
        int i,k;
        int low,mid,high;
        for (i=2;i<SL->length;i++) {
            if(SL->data[i].key<SL->data[i-1].key)
            {
                SL->data[0]=SL->data[i];        /*待插入元素暂存入SL->data[0]*/
                low=1;                          /*设置初始查找区间*/
                high=i-1;
                while (low<=high) {             /*表空测试*/
                    mid=(low+high)/2;           /*计算中间位置*/
                    if(SL->data[0].key<SL->data[mid].key)
                        high=mid-1;             /*插入位置在左半区间*/
                    else {
                        low=mid+1;              /*插入位置在右半区间*/
                    }
                }
                for (k=i-1;k>high;k--) {       /*high+1为插入位置*/
                    SL->data[k+1]=SL->data[k];  /*后移元素，留出插入位置*/
                }
                SL->data[high+1]=SL->data[0];      /*待插入元素插入到正确位置*/
            }
        }
    }

    /*一趟希尔插入排序*/
    void ShellInsertion(int dk){
        int p,i,j,k;
        for (p=1;p<=dk;p++) {
            for (i=p+dk;i<SL->length;i=i+dk) {
                if(SL->data[i].key<SL->data[i-dk].key){
                    SL->data[0]=SL->data[i];        /*待插入元素暂存入SL->data[0]*/
                    j=i-dk;
                    while (j>0 && SL->data[0].key <SL->data[j].key) {
                        j=j-dk;
                    }
                    for (k=i-dk;k>j;k=k-dk) {       /*j+dk为插入位置*/
                        SL->data[k+dk]=SL->data[k];  /*后移元素，留出插入位置*/
                    }
                    SL->data[j+dk]=SL->data[0];      /*待插入元素插入到正确位置*/
                }
            }
        }
    }

    /*希尔插入排序*/
    void ShellInsertion_Sort()
    {
        int dlta[]={5,3,1};
        int t=3;
        int i;
        for (i=0;i<t;i++) {
            ShellInsertion(dlta[i]);
        }
    }
};
#endif // INSERTIONSORT_H
