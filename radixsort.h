#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <iostream>
using namespace std;
#define MAX_NUM_OF_KEY 8    /*关键字项数最大值*/
#define RADIX 10            /*关键字基数，示例是十进制整数的基数*/
#define MAX_SPACE 100       /*分配的最大可用存储空间*/
typedef char KeyType2;
typedef struct{
    KeyType2 keys[MAX_NUM_OF_KEY];   /*关键字*/
    /*OtherType other*/             /*其他数据项，示例不用*/
    int next;                       /*静态链表指针，存储后继结点位置*/
}SLCell;                            /*静态链表的结点类型*/
typedef struct{
    SLCell r[MAX_SPACE];            /*静态链表的可利用空间，r[0]为头结点*/
    int keynum;                     /*当前关键字项数*/
    int recnum;                     /*静态链表的当前长度*/
}SLList;                            /*静态链表类型*/
typedef int ArrType[RADIX];         /*子表（静态链表）头尾指针数组类型*/
class RadixSort
{
public:
    RadixSort(int key[],int keynum,int recnum) {
        L=new SLList();
        Create_SLList(key,keynum,recnum);

    }
    /*基数排序*/
    void Radix_Sort()
    {
        cout<<"排序前："<<endl;
        Display_SLList();
        int i;
        ArrType f,e;
        for (i=0;i<L->keynum;i++) {
            /*按最低位优先依次对各关键字进行分配和收集*/
            Distribute(L->r,i,f,e); /*第i趟分配*/
            Collect(L->r,i,f,e);    /*每i趟收集*/
        }
        cout<<"排序后："<<endl;
        Display_SLList();
    }
private:
    SLList *L;
private:
    /*创建静态链表*/
    void Create_SLList(int key[],int keynum,int recnum)
    {
        char *s,c;
        int i,j,n,r;
        s=new char[keynum+1];
        if(s==nullptr){
            cout<<"内存分配失败."<<endl;
            exit(-1);
        }
        L->keynum=keynum;
        L->recnum=recnum;
        for (i=0;i<recnum;i++) {
            n=key[i];
            for (j=0;j<keynum;j++) {
                /*从右向左依次取1位整数转换为字符存储到字符数组s中*/
                r=n%RADIX;
                n=n/RADIX;
                c=r+'0';    /*数值转换为数字字符*/
                s[keynum-1-j]=c;
            }
            for (j=0;j<keynum;j++) {
                /*将字符数组s中的数字字符按逆序存储到关键字项中*/
                L->r[i+1].keys[keynum-1-j]=s[j];
            }
        }
        for (i=0;i<recnum;i++) {    /*形成静态链表*/
            L->r[i].next=i+1;
        }
        L->r[recnum].next=0;
    }

    /*输出静态链表*/
    void Display_SLList(){
        int i,j;
        for (i=L->r[0].next;i;i=L->r[i].next) {
            for (j=L->keynum-1;j>=0;j--) {
                /*将关键字项中的数字字符按逆序输出*/
                cout<<L->r[i].keys[j]<<" ";
            }
            cout<<endl;
        }
    }

    /*分配算法，静态链表L的r域中记录已按[keys[0],...,keys[i-1])有序，本算法按每i个关键字keys[i]建立RADIX个子表，
     * 使同一个子表中记录的keys[i]相同，f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录*/
    void Distribute(SLCell r[],int i,ArrType f,ArrType e){
        int j,p;
        for (j=0;j<RADIX;j++) { /*初始化各子表*/
            f[j]=0;
            e[j]=0;
        }
        for (p=r[0].next;p!=0;p=r[p].next) {
            j=r[p].keys[i]-'0'; /*将数字字符转换为数值*/
            if(f[j]==0)
                f[j]=p;
            else {
                r[e[j]].next=p;
            }
            e[j]=p;         /*将p所指结点插入到第j个子表*/
        }
    }
    /*收集算法，本算法按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次连接成一个链表，e[0..RADIX-1]为各子表的尾指针*/
    void Collect(SLCell r[],int i,ArrType f,ArrType e){
        int j,t;
        j=0;
        while (j<RADIX && f[j]==0) {        /*查找第一个非空子表*/
            j++;
        }
        if(j<RADIX){
            r[0].next=f[j];     /*r[0].next指向第1个非空子表中第1个结点*/
            t=e[j];
            while (j<RADIX) {
                for (j=j+1;j<RADIX-1 && f[j]==0;j++) {  /*查找下一个非空子表*/
                    ;
                }
                if(f[j]!=0 && j<=RADIX-1){
                    r[t].next=f[j];
                    t=e[j];
                }
            }
            r[t].next=0;        /*t指向最后一个非空子表中的最后一个结点*/
        }
    }

};
#endif // RADIXSORT_H
