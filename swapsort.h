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
        cout<<"����ǰ��"<<endl;
        Display_SeqList(SL);
        //Bubble_Sort2();
        Quick_Sort();
        cout<<"�����"<<endl;
        Display_SeqList(SL);
    }
private:
    SeqList *SL;
private:
    /*ð������*/
    void Bubble_Sort1(){
        DataType temp;
        int i,j;
        for (i=1;i<=SL->length-1;i++) {
            for (j=1;j<=SL->length-i;j++) {
                if(SL->data[j].key>SL->data[j+1].key){
                    /*�����˼�������ؼ�������Ԫ�غ���*/
                    temp=SL->data[j];
                    SL->data[j]=SL->data[j+1];
                    SL->data[j+1]=temp;
                }
            }

        }
    }
    /*�Ľ���ð������*/
    void Bubble_Sort2(){
        DataType temp;
        int i,j,flag;
        for (i=1;i<=SL->length-1;i++) {
            flag=1;    /*flag=1��ʾ���豾�˼���в��ύ�����ݣ���˳������ź���*/
            for (j=1;j<=SL->length-i;j++) {
                if(SL->data[j].key>SL->data[j+1].key){
                    /*�����˼�������ؼ�������Ԫ�غ���*/
                    temp=SL->data[j];
                    SL->data[j]=SL->data[j+1];
                    SL->data[j+1]=temp;
                    flag=0; /*���˼���н��������ݣ��޸�flag=0,��˳���δ�ź���*/
                }
            }
        }
    }

    /*һ�˿������򣬽���˳���SL���ӱ�SL->[low..high]�ļ�¼��ʹ֧������Ԫ�ص�λ��������������λ�ã���ʱ������֮ǰ
     * ���󣩵�����Ԫ�صĹؼ��־�����С�������Ĺؼ���*/
    int Partition(SeqList *SL,int low,int high){
        KeyType pivotkey;
        SL->data[0]=SL->data[low];
        /*���ӱ�ĵ�һ������Ԫ����Ϊ֧������Ԫ�أ��ݴ���SL->data[0]*/
        pivotkey = SL->data[low].key;   /*ȡ֧������Ԫ�عؼ���*/
        while(low<high){    /*�ӱ�����˽�������м�ɨ��*/
            while(low<high && SL->data[high].key>=pivotkey)
                high--;
            SL->data[low]=SL->data[high];   /*����֧������Ԫ�عؼ���С�Ľ������Ͷ�*/
            while (low<high && SL->data[low].key<=pivotkey) {
                low++;
            }
            SL->data[high]=SL->data[low];   /*����֧������Ԫ�عؼ��ִ�Ľ������߶�*/
        }
        SL->data[low]=SL->data[0];
        return low;
    }
    /*�ݹ�ؿ������򣬶�˳���SL��������SL->[low..high]���п�������*/
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
