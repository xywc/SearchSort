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

    //顺序查找-----------------------------------------------------
//    SeqSearch seqsearch(key,n);
//    cout<<endl<<"请输入要查找的关键码：";
//    cin>> kx;
//    cout<<"带监视哨顺序查找"<<endl;
//    i=seqsearch.Seq_Search1(kx);
//    cout<<"不带监视哨顺序查找"<<endl;
    //i=seqsearch.Seq_Search2(kx);

    //折半查找-----------------------------------------------------
//    BinSearch binsearch(key,n);
//    cout<<"折半查找"<<endl;
//    cout<<"请输入要查找的关键码：";
//    cin>> kx;
//    i=binsearch.binSearch(kx);

    //索引查找-----------------------------------------------------
//    IndexType index[]={{22,1,4},{44,5,4},{60,9,4},{82,13,4}};
//    IndexSearch indexsearch(key,index,n);
//    cout<<"请输入要查找的关键码：";
//    cin>> kx;
//    i=indexsearch.indexSearch(kx);
//    if(i>0){
//        cout<<"找到了，"<<kx<<"是第"<<i<<"个数据元素"<<endl;
//    }
//    else {
//        cout<<"没找到，没有该关键码数据元素."<<endl;
//    }

    //二叉树查找-----------------------------------------------------
//    BiTree bitree(key,16);
//    cout<<"请输入要删除的结点元素：";
//    cin>> kx;
//    int flag=bitree.Delete_BST(kx);
//    if(flag==1)
//    {
//        cout<<"已删除."<<endl;
//    }
//    else {
//        cout<<"没有该结点，不能删除."<<endl;
//    }

    //哈希查找-----------------------------------------------------
//    int p,c=0;
//    DataType data;
//    HashSearch hashsearch(key,n);
//    cout<<"哈希表："<<endl;
//    hashsearch.Display_HashList();
//    cout<<"请输入要查找的关键码：";
//    cin>> kx;
//    i=hashsearch.Search_HashList(kx,&p,&c);
//    if(i==1){
//        cout<<"找到了，数据元素"<<kx<<"存储在位置"<<p<<",冲突次数"<<c<<endl;
//    }
//    else {
//        cout<<"没找到，没有该关键码数据元素."<<endl;
//    }
//    cout<<"请输入要删除的关键码：";
//    cin>> kx;
//    i=hashsearch.Delete_HashList(kx,&data);
//    if(i==1){
//        cout<<"已删除."<<endl;
//    }
//    else {
//        cout<<"没有该关键码数据元素，不能删除."<<endl;
//    }
//    cout<<"哈希表："<<endl;
//    hashsearch.Display_HashList();

    //插入排序-----------------------------------------------------
//    InsertionSort insertionsort(key,n);
//    insertionsort.Insertion_Sort();

    //选择排序-----------------------------------------------------
    SelectionSort selectionsort(key,n);
    selectionsort.Selection_Sort();
    return 0;
}
