#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <iostream>
using namespace std;
#include "seqlist.h"

class BinSearch
{
public:
    BinSearch(KeyType key[],int n) {
        SL=new SeqList();
        Init_SeqList(SL,n);
        Create_SeqList(SL,key,n);
        cout<<"�����:"<<endl;
        Display_SeqList(SL);
    }
    /*�۰���ң����ҵ����򷵻ظ�Ԫ���������е��±꣬���򷵻�0*/
    int binSearch(KeyType kx){
        int low,mid,high,k=0;
        int midkey=0;
        low=1;
        high=SL->length;
        while (low<=high) {
            mid=low+(high-low)/2;
            midkey=SL->data[mid].key;
            if(kx<SL->data[mid].key)
                high=mid-1;
            else if (kx>SL->data[mid].key) {
                low=mid+1;
            }
            else {
                k=mid;      /*���ҳɹ�*/
                break;
            }
        }
        return k;
    }
private:
    SeqList *SL;
};
#endif // BINSEARCH_H
