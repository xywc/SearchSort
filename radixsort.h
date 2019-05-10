#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <iostream>
using namespace std;
#define MAX_NUM_OF_KEY 8    /*�ؼ����������ֵ*/
#define RADIX 10            /*�ؼ��ֻ�����ʾ����ʮ���������Ļ���*/
#define MAX_SPACE 100       /*����������ô洢�ռ�*/
typedef char KeyType2;
typedef struct{
    KeyType2 keys[MAX_NUM_OF_KEY];   /*�ؼ���*/
    /*OtherType other*/             /*���������ʾ������*/
    int next;                       /*��̬����ָ�룬�洢��̽��λ��*/
}SLCell;                            /*��̬����Ľ������*/
typedef struct{
    SLCell r[MAX_SPACE];            /*��̬����Ŀ����ÿռ䣬r[0]Ϊͷ���*/
    int keynum;                     /*��ǰ�ؼ�������*/
    int recnum;                     /*��̬����ĵ�ǰ����*/
}SLList;                            /*��̬��������*/
typedef int ArrType[RADIX];         /*�ӱ���̬����ͷβָ����������*/
class RadixSort
{
public:
    RadixSort(int key[],int keynum,int recnum) {
        L=new SLList();
        Create_SLList(key,keynum,recnum);

    }
    /*��������*/
    void Radix_Sort()
    {
        cout<<"����ǰ��"<<endl;
        Display_SLList();
        int i;
        ArrType f,e;
        for (i=0;i<L->keynum;i++) {
            /*�����λ�������ζԸ��ؼ��ֽ��з�����ռ�*/
            Distribute(L->r,i,f,e); /*��i�˷���*/
            Collect(L->r,i,f,e);    /*ÿi���ռ�*/
        }
        cout<<"�����"<<endl;
        Display_SLList();
    }
private:
    SLList *L;
private:
    /*������̬����*/
    void Create_SLList(int key[],int keynum,int recnum)
    {
        char *s,c;
        int i,j,n,r;
        s=new char[keynum+1];
        if(s==nullptr){
            cout<<"�ڴ����ʧ��."<<endl;
            exit(-1);
        }
        L->keynum=keynum;
        L->recnum=recnum;
        for (i=0;i<recnum;i++) {
            n=key[i];
            for (j=0;j<keynum;j++) {
                /*������������ȡ1λ����ת��Ϊ�ַ��洢���ַ�����s��*/
                r=n%RADIX;
                n=n/RADIX;
                c=r+'0';    /*��ֵת��Ϊ�����ַ�*/
                s[keynum-1-j]=c;
            }
            for (j=0;j<keynum;j++) {
                /*���ַ�����s�е������ַ�������洢���ؼ�������*/
                L->r[i+1].keys[keynum-1-j]=s[j];
            }
        }
        for (i=0;i<recnum;i++) {    /*�γɾ�̬����*/
            L->r[i].next=i+1;
        }
        L->r[recnum].next=0;
    }

    /*�����̬����*/
    void Display_SLList(){
        int i,j;
        for (i=L->r[0].next;i;i=L->r[i].next) {
            for (j=L->keynum-1;j>=0;j--) {
                /*���ؼ������е������ַ����������*/
                cout<<L->r[i].keys[j]<<" ";
            }
            cout<<endl;
        }
    }

    /*�����㷨����̬����L��r���м�¼�Ѱ�[keys[0],...,keys[i-1])���򣬱��㷨��ÿi���ؼ���keys[i]����RADIX���ӱ�
     * ʹͬһ���ӱ��м�¼��keys[i]��ͬ��f[0..RADIX-1]��e[0..RADIX-1]�ֱ�ָ����ӱ��е�һ�������һ����¼*/
    void Distribute(SLCell r[],int i,ArrType f,ArrType e){
        int j,p;
        for (j=0;j<RADIX;j++) { /*��ʼ�����ӱ�*/
            f[j]=0;
            e[j]=0;
        }
        for (p=r[0].next;p!=0;p=r[p].next) {
            j=r[p].keys[i]-'0'; /*�������ַ�ת��Ϊ��ֵ*/
            if(f[j]==0)
                f[j]=p;
            else {
                r[e[j]].next=p;
            }
            e[j]=p;         /*��p��ָ�����뵽��j���ӱ�*/
        }
    }
    /*�ռ��㷨�����㷨��keys[i]��С����ؽ�f[0..RADIX-1]��ָ���ӱ��������ӳ�һ������e[0..RADIX-1]Ϊ���ӱ��βָ��*/
    void Collect(SLCell r[],int i,ArrType f,ArrType e){
        int j,t;
        j=0;
        while (j<RADIX && f[j]==0) {        /*���ҵ�һ���ǿ��ӱ�*/
            j++;
        }
        if(j<RADIX){
            r[0].next=f[j];     /*r[0].nextָ���1���ǿ��ӱ��е�1�����*/
            t=e[j];
            while (j<RADIX) {
                for (j=j+1;j<RADIX-1 && f[j]==0;j++) {  /*������һ���ǿ��ӱ�*/
                    ;
                }
                if(f[j]!=0 && j<=RADIX-1){
                    r[t].next=f[j];
                    t=e[j];
                }
            }
            r[t].next=0;        /*tָ�����һ���ǿ��ӱ��е����һ�����*/
        }
    }

};
#endif // RADIXSORT_H
