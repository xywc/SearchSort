#ifndef SWAPSORT_H
#define SWAPSORT_H

#include "seqlist.h"

class SwapSort
{
public:
    SwapSort(KeyType key[],int n) {
        SL=new SeqList();
        Init_SeqList(SL,n);
        Create_SeqList(SL,key,n);
    }
    void Bubble_Sort(){
        cout<<"排序前："<<endl;
        Display_SeqList(SL);
        //Bubble_Sort2();
        Quick_Sort();
        cout<<"排序后："<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
private:
    /*冒泡排序*/
    void Bubble_Sort1(){
        DataType temp;
        int i,j;
        for (i=1;i<=SL->length-1;i++) {
            for (j=1;j<=SL->length-i;j++) {
                if(SL->data[j].key>SL->data[j+1].key){
                    /*将本趟检测中最大关键字数据元素后移*/
                    temp=SL->data[j];
                    SL->data[j]=SL->data[j+1];
                    SL->data[j+1]=temp;
                }
            }

        }
    }
    /*改进的冒泡排序*/
    void Bubble_Sort2(){
        DataType temp;
        int i,j,flag;
        for (i=1;i<=SL->length-1;i++) {
            flag=1;    /*flag=1表示假设本趟检测中不会交换数据，即顺序表已排好序*/
            for (j=1;j<=SL->length-i;j++) {
                if(SL->data[j].key>SL->data[j+1].key){
                    /*将本趟检测中最大关键字数据元素后移*/
                    temp=SL->data[j];
                    SL->data[j]=SL->data[j+1];
                    SL->data[j+1]=temp;
                    flag=0; /*本趟检测中交换了数据，修改flag=0,即顺序表未排好序*/
                }
            }
        }
    }

    /*一趟快速排序，交换顺序表SL中子表SL->[low..high]的记录，使支点数据元素到位，并返回其所在位置，此时，在它之前
     * （后）的数据元素的关键字均不大（小）于它的关键字*/
    int Partition(SeqList *SL,int low,int high){
        KeyType pivotkey;
        SL->data[0]=SL->data[low];
        /*以子表的第一个数据元素作为支点数据元素，暂存入SL->data[0]*/
        pivotkey = SL->data[low].key;   /*取支点数据元素关键字*/
        while(low<high){    /*从表的两端交替地向中间扫描*/
            while(low<high && SL->data[high].key>=pivotkey)
                high--;
            SL->data[low]=SL->data[high];   /*将比支点数据元素关键字小的交换到低端*/
            while (low<high && SL->data[low].key<=pivotkey) {
                low++;
            }
            SL->data[high]=SL->data[low];   /*将比支点数据元素关键字大的交换到高端*/
        }
        SL->data[low]=SL->data[0];
        return low;
    }
    /*递归地快速排序，对顺序表SL的子序列SL->[low..high]进行快速排序*/
    void QSort(SeqList *SL,int low,int high){
        int pivotloc;
        if(low<high){
            pivotloc=Partition(SL,low,high);
            cout<<endl;
            Display_SeqList(SL);
            QSort(SL,low,pivotloc-1);
            QSort(SL,pivotloc+1,high);
        }
    }
    void Quick_Sort()
    {
        QSort(SL,1,SL->length);
    }

};
#endif // SWAPSORT_H
