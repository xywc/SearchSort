#include "binsearch.h"
int main()
{
    KeyType key[]={9,12,14,22,35,38,42,44,47,48,58,60,77,78,80,82};
    KeyType kx;
    int n=16,i;

    //˳�����-----------------------------------------------------
//    SeqSearch seqsearch(key,n);
//    cout<<endl<<"������Ҫ���ҵĹؼ��룺";
//    cin>> kx;
//    cout<<"��������˳�����"<<endl;
//    i=seqsearch.Seq_Search1(kx);
//    cout<<"����������˳�����"<<endl;
//    i=seqsearch.Seq_Search2(kx);

    //�۰����-----------------------------------------------------
    BinSearch binsearch(key,n);
    cout<<"�۰����"<<endl;
    cout<<"������Ҫ���ҵĹؼ��룺";
    cin>> kx;
    i=binsearch.binSearch(kx);


    if(i>0){
        cout<<"�ҵ��ˣ�"<<kx<<"�ǵ�"<<i<<"������Ԫ��"<<endl;
    }
    else {
        cout<<"û�ҵ���û�иùؼ�������Ԫ��."<<endl;
    }

    return 0;
}
