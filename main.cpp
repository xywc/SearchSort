#include "seqsearch.h"

int main()
{
    KeyType key[]={9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82};
    KeyType kx;
    int n=16,i;
    SeqSearch seqsearch(key,n);
    cout<<endl<<"请输入要查找的关键码：";
    cin>> kx;
    cout<<"带监视哨顺序查找"<<endl;
    i=seqsearch.Seq_Search1(kx);
//    cout<<"不带监视哨顺序查找"<<endl;
//    i=seqsearch.Seq_Search2(kx);
    if(i>0){
        cout<<"找到了，"<<kx<<"是第"<<i<<"个数据元素"<<endl;
    }
    else {
        cout<<"没找到，没有该关键码数据元素."<<endl;
    }
    return 0;
}
