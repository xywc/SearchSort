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
        cout<<"�����:"<<endl;
        Display_SeqList();
    }
    /*�۰���ң����ҵ����򷵻ظ�Ԫ���������е��±꣬���򷵻�0*/
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
                k=mid;      /*���ҳɹ�*/
                break;
            }
        }
        return k;
    }
private:
    /*��ʼ��˳���*/
    void Init_SeqList(int n)
    {
        SL->data=new DataType[n+1];
        /*�࿪��1���洢��Ԫ��0λ�ò���*/
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
#endif // BINSEARCH_H
