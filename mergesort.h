#ifndef MERGESORT_H
#define MERGESORT_H
#include "seqlist.h"
class MergeSort
{
public:
    MergeSort(KeyType key[],int n) {
        SL=new SeqList();
        Init_SeqList(SL,n);
        Create_SeqList(SL,key,n);
    }
    /*�鲢���򣬶�˳���SL��������*/
    void Merge_Sort()
    {
        cout<<"����ǰ��"<<endl;
        Display_SeqList(SL);
        MSort(SL,SL,1,SL->length);
        cout<<"�����"<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
private:
    /*�鲢���������SL1->data[low..mid]��SL1->data[mid+1..high]�鲢Ϊ�����SL2->data[low..high]*/
    void Merge(SeqList *SL1,SeqList *SL2,int low,int mid,int high){
        int i,j,k;
        i=low;
        j=mid+1;
        k=i;
        while (i<=mid && j<=high) {
            if(SL1->data[i].key<SL1->data[j].key){
                SL2->data[k]=SL1->data[i];
                i++;
            }
            else {
                SL2->data[k]=SL1->data[j];
                j++;
            }
            k++;
        }
        while (i<=mid) {
            SL2->data[k]=SL1->data[i];
            i++;
            k++;
        }
        while (j<=high) {
            SL2->data[k]=SL1->data[j];
            j++;
            k++;
        }
    }
    /*��SL1->data[low..high]�鲢����ΪSL2->data[low..high]*/
    void MSort(SeqList *SL1,SeqList *SL2,int low,int high){
        SeqList SLtemp;
        int mid;
        Init_SeqList(&SLtemp,SL1->length);
        if(low==high)
            SL2->data[low]=SL1->data[low];
        else {
            mid=(low+high)/2;               /*��SL1->data[low..high]ƽ��ΪSL1->data[low..mid]��SL1->data[mid+1..high]*/
            MSort(SL1,&SLtemp,low,mid);     /*�ݹ�ؽ�SL->data[low..mid]�鲢Ϊ�����SLtemp->data[low..mid]*/         
            MSort(SL1,&SLtemp,mid+1,high);  /*�ݹ�ؽ�SL->data[mid+1..high]�鲢Ϊ�����SLtemp->data[low..mid]*/
            Merge(&SLtemp,SL2,low,mid,high);/*��SLtemp->data[low..mid]��SLtemp->data[mid+1..high]�鲢��SL2->data[low..high]*/
        }
    }

};
#endif // MERGESORT_H
