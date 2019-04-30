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
        cout<<"˳���:"<<endl;
        Display_SeqList(SL);
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
    SeqList *SL;
};

#endif // SEQSEARCH_H
