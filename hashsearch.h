#ifndef HASHSEARCH_H
#define HASHSEARCH_H
#include "seqlist.h"
#define HASHSIZE 21         /*��ϣ����*/
#define M 13                /*��������������*/
typedef struct{
    DataType *data;         /*����Ԫ�ػ�ַ*/
    int *tag;               /*����Ԫ�ش洢��־��0-�ռ䣬1-�洢*/
    int *c;                 /*��ͻ��������ֵΪ0*/
    int count;              /*��ǰ��ϣ������Ԫ�ظ���*/
    int length;             /*��ǰ��ϣ������*/
}HashList;                  /*��ϣ������*/
class HashSearch
{
public:
    HashSearch(KeyType key[],int n) {
        HL=new HashList();
        Init_HashList(HASHSIZE);
        Create_HashList(key,n);
    }
    /*��ϣ���ң������ҳɹ����򷵻�1������*p������λ�ã�*c�������ͻ���������򷵻�0*/
    int Search_HashList(KeyType key,int *p,int *c)
    {
        *p=Hash(key);
        while (HL->tag[*p]==1 && HL->data[*p].key !=key) {  /*��ͻ*/
            *p=(*p+1)%HASHSIZE;
            (*c)++;
        }
        if(HL->data[*p].key==key)
            return (1);
        else {
            return (0);
        }
    }

    /*�ڹ�ϣ����ɾ��һ������Ԫ�أ���ɾ���������򷵻�1������*e������ֵ�����򷵻�0*/
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
            cout<<"û�иùؼ�������Ԫ�أ�����ɾ��."<<endl;
            return (0);
        }
    }
    /*�����ϣ��*/
    void Display_HashList(){
        int i;
        cout<<"�洢λ�ã�";
        for (i=0;i<HL->length;i++) {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"����Ԫ��:";
        for (i=0;i<HL->length;i++) {
            if(HL->tag[i]==1)
                cout<<HL->data[i].key<<" ";
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
        cout<<"�洢��־��";
        for (i=0;i<HL->length;i++) {
            cout<<HL->tag[i]<<" ";
        }
        cout<<endl;
        cout<<"��ͻ������";
        for (i=0;i<HL->length;i++) {
            if(HL->tag[i]==1)
                cout<<HL->c[i]<<" ";
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
        cout<<"Ԫ�ظ�����"<<HL->count<<endl;
        cout<<"��ϣ��������"<<HL->length<<endl;
    }
private:
    HashList *HL;
private:
    /*��ʼ����ϣ��*/
    void Init_HashList(int n)
    {
        int i;
        HL->data=new DataType[n];
        if(HL->data==nullptr){
            cout<<"�ڴ����ʧ��."<<endl;
            exit(-1);
        }
        HL->tag=new int[n];
        if(HL->tag==nullptr){
            cout<<"�ڴ����ʧ��."<<endl;
            exit(-1);
        }
        for (i=0;i<n;i++) {
            HL->tag[i]=0;
        }
        HL->c=new int[n];
        if(HL->c==nullptr){
            cout<<"�ڴ����ʧ��."<<endl;
            exit(-1);
        }
        for (i=0;i<n;i++) {
            HL->c[i]=0;
        }
        HL->count=0;
        HL->length=n;
    }
    /*��ϣ����*/
    int Hash(KeyType key){
        int i;
        i=key % M;
        return i;
    }
    /*�ڹ�ϣ���в���һ������Ԫ�أ�������ɹ����򷵻�1�����򷵻�0*/
    int Insert_HashList(DataType e){
        int p,c=0;
        if(Search_HashList(e.key,&p,&c)==0){/*û�ҵ�*/
            HL->data[p]=e;
            HL->tag[p]=1;
            HL->c[p]=c;
            HL->count++;
            return (1);
        }
        else {
            cout<<"����Ԫ���ظ������ܲ���."<<endl;
            return (0);
        }
    }

    /*������ϣ��*/
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
