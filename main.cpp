#include "binsearch.h"
int main()
{
    KeyType key[]={9,12,14,22,35,38,42,44,47,48,58,60,77,78,80,82};
    KeyType kx;
    int n=16,i;

    //顺序查找-----------------------------------------------------
//    SeqSearch seqsearch(key,n);
//    cout<<endl<<"请输入要查找的关键码：";
//    cin>> kx;
//    cout<<"带监视哨顺序查找"<<endl;
//    i=seqsearch.Seq_Search1(kx);
//    cout<<"不带监视哨顺序查找"<<endl;
//    i=seqsearch.Seq_Search2(kx);

    //折半查找-----------------------------------------------------
    BinSearch binsearch(key,n);
    cout<<"折半查找"<<endl;
    cout<<"请输入要查找的关键码：";
    cin>> kx;
    i=binsearch.binSearch(kx);


    if(i>0){
        cout<<"找到了，"<<kx<<"是第"<<i<<"个数据元素"<<endl;
    }
    else {
        cout<<"没找到，没有该关键码数据元素."<<endl;
    }

    return 0;
}
