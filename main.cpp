#include "seqsearch.h"

int main()
{
    KeyType key[]={9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82};
    KeyType kx;
    int n=16,i;
    SeqSearch seqsearch(key,n);
    cout<<endl<<"������Ҫ���ҵĹؼ��룺";
    cin>> kx;
    cout<<"��������˳�����"<<endl;
    i=seqsearch.Seq_Search1(kx);
//    cout<<"����������˳�����"<<endl;
//    i=seqsearch.Seq_Search2(kx);
    if(i>0){
        cout<<"�ҵ��ˣ�"<<kx<<"�ǵ�"<<i<<"������Ԫ��"<<endl;
    }
    else {
        cout<<"û�ҵ���û�иùؼ�������Ԫ��."<<endl;
    }
    return 0;
}
