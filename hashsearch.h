#ifndef HASHSEARCH_H
#define HASHSEARCH_H
#include "seqlist.h"
#define HASHSIZE 21         /*哈希表长度*/
#define M 13                /*除留余数法除数*/
typedef struct{
    DataType *data;         /*数据元素基址*/
    int *tag;               /*数据元素存储标志，0-空间，1-存储*/
    int *c;                 /*冲突次数，初值为0*/
    int count;              /*当前哈希表数据元素个数*/
    int length;             /*当前哈希表容量*/
}HashList;                  /*哈希表类型*/
class HashSearch
{
public:
    HashSearch(KeyType key[],int n) {
        HL=new HashList();
        Init_HashList(HASHSIZE);
        Create_HashList(key,n);
    }
    /*哈希查找，若查找成功，则返回1，并由*p返回其位置，*c返回其冲突次数，否则返回0*/
    int Search_HashList(KeyType key,int *p,int *c)
    {
        *p=Hash(key);
        while (HL->tag[*p]==1 && HL->data[*p].key !=key) {  /*冲突*/
            *p=(*p+1)%HASHSIZE;
            (*c)++;
        }
        if(HL->data[*p].key==key)
            return (1);
        else {
            return (0);
        }
    }

    /*在哈希表中删除一个数据元素，若删除万历，则返回1，并由*e返回其值，否则返回0*/
    int Delete_HashList(KeyType key,DataType *e){
        int p,c=0;
        if(Search_HashList(key,&p,&c)==1){
            *e=HL->data[p];
            HL->tag[p]=0;
            HL->c[p]=0;
            HL->count--;
            return (1);
        }
        else {
            cout<<"没有该关键码数据元素，不能删除."<<endl;
            return (0);
        }
    }
    /*输出哈希表*/
    void Display_HashList(){
        int i;
        cout<<"存储位置：";
        for (i=0;i<HL->length;i++) {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"数据元素:";
        for (i=0;i<HL->length;i++) {
            if(HL->tag[i]==1)
                cout<<HL->data[i].key<<" ";
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
        cout<<"存储标志：";
        for (i=0;i<HL->length;i++) {
            cout<<HL->tag[i]<<" ";
        }
        cout<<endl;
        cout<<"冲突次数：";
        for (i=0;i<HL->length;i++) {
            if(HL->tag[i]==1)
                cout<<HL->c[i]<<" ";
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
        cout<<"元素个数："<<HL->count<<endl;
        cout<<"哈希表容量："<<HL->length<<endl;
    }
private:
    HashList *HL;
private:
    /*初始化哈希表*/
    void Init_HashList(int n)
    {
        int i;
        HL->data=new DataType[n];
        if(HL->data==nullptr){
            cout<<"内存分配失败."<<endl;
            exit(-1);
        }
        HL->tag=new int[n];
        if(HL->tag==nullptr){
            cout<<"内存分配失败."<<endl;
            exit(-1);
        }
        for (i=0;i<n;i++) {
            HL->tag[i]=0;
        }
        HL->c=new int[n];
        if(HL->c==nullptr){
            cout<<"内存分配失败."<<endl;
            exit(-1);
        }
        for (i=0;i<n;i++) {
            HL->c[i]=0;
        }
        HL->count=0;
        HL->length=n;
    }
    /*哈希函数*/
    int Hash(KeyType key){
        int i;
        i=key % M;
        return i;
    }
    /*在哈希表中插入一个数据元素，若插入成功，则返回1，否则返回0*/
    int Insert_HashList(DataType e){
        int p,c=0;
        if(Search_HashList(e.key,&p,&c)==0){/*没找到*/
            HL->data[p]=e;
            HL->tag[p]=1;
            HL->c[p]=c;
            HL->count++;
            return (1);
        }
        else {
            cout<<"数据元素重复，不能插入."<<endl;
            return (0);
        }
    }

    /*创建哈希表*/
    void Create_HashList(KeyType key[],int n)
    {
        DataType data;
        int i;
        for (i=0;i<n;i++) {
            data.key=key[i];
            Insert_HashList(data);
        }
    }
};
#endif // HASHSEARCH_H
