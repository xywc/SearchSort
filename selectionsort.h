#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "seqlist.h"
typedef SeqList HeapType;       /*�����ͣ�����˳���洢*/
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
        cout<<"����ǰ��"<<endl;
        Display_SeqList(SL);
        //Selection_Sort2();
        HeapSort();
        cout<<"�����"<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
    HeapType *H;
private:
    /*��ѡ������*/
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
    /*�Ľ��ļ�ѡ������*/
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
    /*ɸѡ�����ѵĵ�����H->[s..m]�е�����Ԫ�صĹؼ��ֳ�H->[s]�������ѵĶ��壬������
     * ���Ե�s�����Ϊ������������ɸѡ��ʹ���Ϊ�󶥶�*/
    void HeapAdjust(int s,int m){
        DataType temp;
        int i;
        temp=H->data[s];            /*��H->data[s]�ݴ���temp*/
        for (i=s*2;i<=m;i=2*i) {    /*���Źؼ��ֽϴ�ĺ��ӽ������ɸѡ*/
            if(i<m && H->data[i].key<H->data[i+1].key)  /*�������ӽ��*/
                i++;                /*iΪ�ؼ��ֽϴ�����±�*/
            if(temp.key < H->data[i].key){
                H->data[s]=H->data[i];  /*��H->data[i]������˫�׽��λ��*/
                s=i;
            }
            else{
                break;
            }
        }
        H->data[s]=temp;
    }
    /*������*/
    void HeapSort(){
        DataType temp;
        int i;
        /*���ɴ󶥶�*/
        for (i=H->length/2;i>=1;i--) {  /*�����һ����Ҷ�ӽ�㿪ʼ��Ҷ�����Ȼ���õ�������һ����Ҷ�ӽ��*/
            HeapAdjust(i,H->length);    /*H->length/2�����������ң��������Ͻ��е�����*/
        }
        for (i=H->length;i>=2;i--) {
            temp=H->data[1];        /*���Ѷ�����뻹δ���������������һ����㽻��*/
            H->data[1]=H->data[i];
            H->data[i]=temp;
            HeapAdjust(1,i-1);      /*���µ�����δ����������Ϊ�󶥶�*/
        }
    }

};
#endif // SELECTIONSORT_H
