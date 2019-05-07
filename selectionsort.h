#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "seqlist.h"
typedef SeqList HeapType;       /*堆类型，采用顺序表存储*/
class SelectionSort
{
public:
    SelectionSort(KeyType key[],int n) {
        SL=new SeqList();
        H=new HeapType();
        Init_SeqList(SL,n);
        Create_SeqList(SL,key,n);
        H=SL;
    }
    void Selection_Sort(){
        cout<<"排序前："<<endl;
        Display_SeqList(SL);
        //Selection_Sort2();
        HeapSort();
        cout<<"排序后："<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
    HeapType *H;
private:
    /*简单选择排序*/
    void Selection_Sort1(){
        DataType temp;
        int i,j;
        for (i=1;i<SL->length;i++) {
            for (j=i+1;j<=SL->length;j++) {
                if(SL->data[i].key>SL->data[j].key){
                    temp=SL->data[i];
                    SL->data[i]=SL->data[j];
                    SL->data[j]=temp;
                }
            }
        }
    }
    /*改进的简单选择排序*/
    void Selection_Sort2(){
        DataType temp;
        int i,j,k;
        for (i=1;i<SL->length;i++) {
            k=i;
            for (j=i+1;j<=SL->length;j++)
                if(SL->data[k].key>SL->data[j].key)
                    k=j;
            temp=SL->data[i];
            SL->data[i]=SL->data[k];
            SL->data[k]=temp;
        }
    }
    /*筛选，即堆的调整，H->[s..m]中的数据元素的关键字除H->[s]外均满足堆的定义，本函数
     * 将对第s个结点为跟的子树进行筛选，使其成为大顶堆*/
    void HeapAdjust(int s,int m){
        DataType temp;
        int i;
        temp=H->data[s];            /*将H->data[s]暂存入temp*/
        for (i=s*2;i<=m;i=2*i) {    /*沿着关键字较大的孩子结点向下筛选*/
            if(i<m && H->data[i].key<H->data[i+1].key)  /*两个孩子结点*/
                i++;                /*i为关键字较大结点的下标*/
            if(temp.key < H->data[i].key){
                H->data[s]=H->data[i];  /*将H->data[i]调整到双亲结点位置*/
                s=i;
            }
            else{
                break;
            }
        }
        H->data[s]=temp;
    }
    /*堆排序*/
    void HeapSort(){
        DataType temp;
        int i;
        /*建成大顶堆*/
        for (i=H->length/2;i>=1;i--) {  /*从最后一个非叶子结点开始（叶结点自然不用调整，第一个非叶子结点*/
            HeapAdjust(i,H->length);    /*H->length/2），从左至右，从下至上进行调整。*/
        }
        for (i=H->length;i>=2;i--) {
            temp=H->data[1];        /*将堆顶结点与还未排序子序列中最后一个结点交换*/
            H->data[1]=H->data[i];
            H->data[i]=temp;
            HeapAdjust(1,i-1);      /*重新调整还未排序子序列为大顶堆*/
        }
    }

};
#endif // SELECTIONSORT_H
