#ifndef BITREE_H
#define BITREE_H
#include "seqlist.h"
typedef struct BiTNode{
    DataType data;                      /*������Ԫ��*/
    struct BiTNode *lchild,*rchild;     /*���������Һ���ָ��*/
}BiTNode,*Bitree;                       /*������������͡�����������*/
class BiTree
{
public:
    BiTree(KeyType kx[],int n) {
        Init_BiTree();
        Create_BiTree(kx,n);
        cout<<"����������BST"<<endl;
        Display_BiTree(*BST);
        cout<<endl;
    }
    /*�ڶ���������BST��ɾ���ؼ���Ϊkx�Ľ��*/
    int Delete_BST(KeyType kx)
    {
        BiTNode *p,*q,*r,*s,**f;
        int flag=0;
        if(Search_BST(&p,&q,kx)==1){
            flag=1;         /*���ҳɹ�����ɾ���ɹ���־*/
            if(p==q)        /*��ɾ���Ϊ�����*/
                f=BST;      /*fָ������*/
            else {          /*��ɾ���Ϊ�Ǹ����*/
                if(kx<p->data.key)
                    /*fָ���ɾ���ĸ�����ָ���ɾ����ָ����*/
                    f=&(p->lchild);
                else {
                    f=&(p->rchild);
                }
            }
            if(q->rchild==nullptr){
                /*����ɾ������������������������滻��ɾ���*/
                r=q->lchild;    /*����ɾ�����Ҷ�ӽ��Ҳɾ��*/
                (*f)=r;
                free(q);
            }
            else if (q->lchild==nullptr) {
                /*����ɾ������������������������滻��ɾ���*/
                r=q->rchild;
                (*f)=r;
                free(q);
            }
            else {      /*��������������������*/
                r=q;
                s=q->lchild;
                while (s->rchild) {     /*���������ϲ��Ҵ�ɾ����ǰ��*/
                    r=s;
                    s=s->rchild;
                }
                (*f)->data=s->data;     /*�滻��ɾ���*/
                if(r!=q)    /*��ɾ����������������*/
                    r->rchild=s->lchild;    /*�ؽ���ɾ����ǰ����������*/
                else {      /*��ɾ����������������*/
                    r->lchild=s->lchild;    /*�ؽ���ɾ����ǰ����������*/
                }
                free(s);
            }
        }
        cout<<"����������BST"<<endl;
        Display_BiTree(*BST);
        return flag;
    }

private:
    Bitree *BST;
private:
    /*��ʼ��������һ�ÿն�����*/
    void Init_BiTree()
    {
        BST=new Bitree();
    }
    /*�Թ������ʽ���������*/
    void Display_BiTree(Bitree BST)
    {
        if(BST!=nullptr){
            cout<<BST->data.key;
            if(BST->lchild !=nullptr || BST->rchild!=nullptr){
                cout<<"(";
                Display_BiTree(BST->lchild);
                if(BST->rchild!=nullptr)
                    cout<<",";
                Display_BiTree(BST->rchild);
                cout<<")";
            }
        }
    }
    /*�ڶ����������ϲ��ҹؼ���Ϊkx��Ԫ�أ����ҵ����򷵻�1����qָ��ý�㣬pָ���丸��㣻���򷵻�0����pָ�����ʧ�ܵ����һ�����*/
    int Search_BST(BiTNode **p,BiTNode **q,KeyType kx)
    {
        int flag=0;
        *q=*BST;
        while((*q)!=nullptr){           /*�Ӹ���㿪ʼ����*/
            if(kx>(*q)->data.key){
                /*kx���ڵ�ǰ���*q��Ԫ�عؼ���*/
                *p=*q;
                *q=(*q)->rchild;        /*����ǰ���*q���Һ�����Ϊ�¸�*/
            }
            else if (kx<(*q)->data.key) {
                /*kxС�ڵ�ǰ���*q�Ĺؼ���*/
                *p=*q;
                *q=(*q)->lchild;        /*����ǰ���*q��������Ϊ�¸�*/
            }
            else                        /*���ҳɹ�������*/
            {
                flag=1;
                break;
            }
        }
        return flag;
    }
    /*�ڶ���������BST�ϲ���ؼ���Ϊkx�Ľ��*/
    int Insert_BST(KeyType kx)
    {
        BiTNode *p,*q,*s;
        int flag=0;
        p=*BST;
        if(Search_BST(&p,&q,kx)==0)
        /*��BSTΪ���������ϲ���*/
        {
            s=new BiTNode[sizeof (BiTNode)];
            if(s==nullptr){
                cout<<"�ڴ����ʧ��"<<endl;
                exit(-1);
            }
            s->data.key=kx;
            s->lchild=nullptr;
            s->rchild=nullptr;
            flag=1;
            if(p==nullptr)
                *BST=s;
            else {
                if(kx>p->data.key){
                    p->rchild=s;
                }
                else {
                    p->lchild=s;
                }
            }
        }
        return flag;

    }
    /*��������������*/
    void Create_BiTree(KeyType kx[],int n)
    {
        int i;
        for (i=0;i<n;i++) {
            Insert_BST(kx[i]);
        }
    }
};
#endif // BITREE_H
