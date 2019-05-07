#include "binsearch.h"
#include "seqsearch.h"
#include "indexsearch.h"
#include "bitree.h"
#include "hashsearch.h"

#include "insertionsort.h"
#include "selectionsort.h"
int main()
{
    //KeyType key[]={9,12,14,22,35,38,42,44,47,48,58,60,77,78,80,82};
    KeyType key[]={9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82};
    KeyType kx;
    int n=16,i;

    //˳�����-----------------------------------------------------
//    SeqSearch seqsearch(key,n);
//    cout<<endl<<"������Ҫ���ҵĹؼ��룺";
//    cin>> kx;
//    cout<<"��������˳�����"<<endl;
//    i=seqsearch.Seq_Search1(kx);
//    cout<<"����������˳�����"<<endl;
    //i=seqsearch.Seq_Search2(kx);

    //�۰����-----------------------------------------------------
//    BinSearch binsearch(key,n);
//    cout<<"�۰����"<<endl;
//    cout<<"������Ҫ���ҵĹؼ��룺";
//    cin>> kx;
//    i=binsearch.binSearch(kx);

    //��������-----------------------------------------------------
//    IndexType index[]={{22,1,4},{44,5,4},{60,9,4},{82,13,4}};
//    IndexSearch indexsearch(key,index,n);
//    cout<<"������Ҫ���ҵĹؼ��룺";
//    cin>> kx;
//    i=indexsearch.indexSearch(kx);
//    if(i>0){
//        cout<<"�ҵ��ˣ�"<<kx<<"�ǵ�"<<i<<"������Ԫ��"<<endl;
//    }
//    else {
//        cout<<"û�ҵ���û�иùؼ�������Ԫ��."<<endl;
//    }

    //����������-----------------------------------------------------
//    BiTree bitree(key,16);
//    cout<<"������Ҫɾ���Ľ��Ԫ�أ�";
//    cin>> kx;
//    int flag=bitree.Delete_BST(kx);
//    if(flag==1)
//    {
//        cout<<"��ɾ��."<<endl;
//    }
//    else {
//        cout<<"û�иý�㣬����ɾ��."<<endl;
//    }

    //��ϣ����-----------------------------------------------------
//    int p,c=0;
//    DataType data;
//    HashSearch hashsearch(key,n);
//    cout<<"��ϣ��"<<endl;
//    hashsearch.Display_HashList();
//    cout<<"������Ҫ���ҵĹؼ��룺";
//    cin>> kx;
//    i=hashsearch.Search_HashList(kx,&p,&c);
//    if(i==1){
//        cout<<"�ҵ��ˣ�����Ԫ��"<<kx<<"�洢��λ��"<<p<<",��ͻ����"<<c<<endl;
//    }
//    else {
//        cout<<"û�ҵ���û�иùؼ�������Ԫ��."<<endl;
//    }
//    cout<<"������Ҫɾ���Ĺؼ��룺";
//    cin>> kx;
//    i=hashsearch.Delete_HashList(kx,&data);
//    if(i==1){
//        cout<<"��ɾ��."<<endl;
//    }
//    else {
//        cout<<"û�иùؼ�������Ԫ�أ�����ɾ��."<<endl;
//    }
//    cout<<"��ϣ��"<<endl;
//    hashsearch.Display_HashList();

    //��������-----------------------------------------------------
//    InsertionSort insertionsort(key,n);
//    insertionsort.Insertion_Sort();

    //ѡ������-----------------------------------------------------
    SelectionSort selectionsort(key,n);
    selectionsort.Selection_Sort();
    return 0;
}
