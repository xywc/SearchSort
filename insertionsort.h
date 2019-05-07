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
        cout<<"����ǰ��"<<endl;
        Display_SeqList(SL);
        //BInsertion_Sort();
        ShellInsertion_Sort();
        cout<<"�����"<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
private:
    /*ֱ�Ӳ�������*/
    void SInsertion_Sort(){
        int i,j,k;
        for (i=2;i<SL->length;i++) {
            if(SL->data[i].key<SL->data[i-1].key)
            {
                SL->data[0]=SL->data[i];    /*������Ԫ���ݴ���SL->data[0]*/
                j=i-1;                      /*���Ҳ���λ��*/
                while (SL->data[0].key <SL->data[j].key) {
                    j--;
                }
                for (k=i-1;k>j;k--) {       /*j+1Ϊ����λ��*/
                    SL->data[k+1]=SL->data[k];  /*����Ԫ�أ���������λ��*/
                }
                SL->data[j+1]=SL->data[0];      /*������Ԫ�ز��뵽��ȷλ��*/
            }
        }
    }

    /*�۰��������*/
    void BInsertion_Sort(){
        int i,k;
        int low,mid,high;
        for (i=2;i<SL->length;i++) {
            if(SL->data[i].key<SL->data[i-1].key)
            {
                SL->data[0]=SL->data[i];        /*������Ԫ���ݴ���SL->data[0]*/
                low=1;                          /*���ó�ʼ��������*/
                high=i-1;
                while (low<=high) {             /*��ղ���*/
                    mid=(low+high)/2;           /*�����м�λ��*/
                    if(SL->data[0].key<SL->data[mid].key)
                        high=mid-1;             /*����λ�����������*/
                    else {
                        low=mid+1;              /*����λ�����Ұ�����*/
                    }
                }
                for (k=i-1;k>high;k--) {       /*high+1Ϊ����λ��*/
                    SL->data[k+1]=SL->data[k];  /*����Ԫ�أ���������λ��*/
                }
                SL->data[high+1]=SL->data[0];      /*������Ԫ�ز��뵽��ȷλ��*/
            }
        }
    }

    /*һ��ϣ����������*/
    void ShellInsertion(int dk){
        int p,i,j,k;
        for (p=1;p<=dk;p++) {
            for (i=p+dk;i<SL->length;i=i+dk) {
                if(SL->data[i].key<SL->data[i-dk].key){
                    SL->data[0]=SL->data[i];        /*������Ԫ���ݴ���SL->data[0]*/
                    j=i-dk;
                    while (j>0 && SL->data[0].key <SL->data[j].key) {
                        j=j-dk;
                    }
                    for (k=i-dk;k>j;k=k-dk) {       /*j+dkΪ����λ��*/
                        SL->data[k+dk]=SL->data[k];  /*����Ԫ�أ���������λ��*/
                    }
                    SL->data[j+dk]=SL->data[0];      /*������Ԫ�ز��뵽��ȷλ��*/
                }
            }
        }
    }

    /*ϣ����������*/
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
