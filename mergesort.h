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
    /*归并排序，对顺序表SL进行排序*/
    void Merge_Sort()
    {
        cout<<"排序前："<<endl;
        Display_SeqList(SL);
        MSort(SL,SL,1,SL->length);
        cout<<"排序后："<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
private:
    /*归并，将有序的SL1->data[low..mid]和SL1->data[mid+1..high]归并为有序的SL2->data[low..high]*/
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
    /*将SL1->data[low..high]归并排序为SL2->data[low..high]*/
    void MSort(SeqList *SL1,SeqList *SL2,int low,int high){
        SeqList SLtemp;
        int mid;
        Init_SeqList(&SLtemp,SL1->length);
        if(low==high)
            SL2->data[low]=SL1->data[low];
        else {
            mid=(low+high)/2;               /*将SL1->data[low..high]平分为SL1->data[low..mid]和SL1->data[mid+1..high]*/
            MSort(SL1,&SLtemp,low,mid);     /*递归地将SL->data[low..mid]归并为有序的SLtemp->data[low..mid]*/         
            MSort(SL1,&SLtemp,mid+1,high);  /*递归地将SL->data[mid+1..high]归并为有序的SLtemp->data[low..mid]*/
            Merge(&SLtemp,SL2,low,mid,high);/*将SLtemp->data[low..mid]和SLtemp->data[mid+1..high]归并到SL2->data[low..high]*/
        }
    }

};
#endif // MERGESORT_H
