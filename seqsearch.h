#ifndef SEQSEARCH_H
#define SEQSEARCH_H
#include "seqlist.h"
class SeqSearch
{
public:
    SeqSearch(KeyType key[],int n){
        SL=new SeqList();
        Init_SeqList(SL,n);
        Create_SeqList(SL,key,n);
        cout<<"顺序表:"<<endl;
        Display_SeqList(SL);
    }
    ~SeqSearch(){
        delete SL;
    }
    /*带监视哨顺序查找，若找到，则返回该元素在数组中的下标，否则返回0*/
    int Seq_Search1(KeyType kx)
    {
        int i;
        SL->data[0].key=kx;     /*存放监视哨*/
        i=SL->length;
        while (kx!=SL->data[i].key) {
            i--;
        }
        return (i);
    }
    /*不带监视哨顺序查找，若找到，则返回该元素在数组中的下标，否则返回0*/
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
    SeqList *SL;
};

#endif // SEQSEARCH_H
