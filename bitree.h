#ifndef BITREE_H
#define BITREE_H
#include "seqlist.h"
typedef struct BiTNode{
    DataType data;                      /*二叉树元素*/
    struct BiTNode *lchild,*rchild;     /*二叉树左右孩子指针*/
}BiTNode,*Bitree;                       /*二叉树结点类型、二叉树类型*/
class BiTree
{
public:
    BiTree(KeyType kx[],int n) {
        Init_BiTree();
        Create_BiTree(kx,n);
        cout<<"二叉排序树BST"<<endl;
        Display_BiTree(*BST);
        cout<<endl;
    }
    /*在二叉排序树BST上删除关键码为kx的结点*/
    int Delete_BST(KeyType kx)
    {
        BiTNode *p,*q,*r,*s,**f;
        int flag=0;
        if(Search_BST(&p,&q,kx)==1){
            flag=1;         /*查找成功，置删除成功标志*/
            if(p==q)        /*待删结点为根结点*/
                f=BST;      /*f指向跟结点*/
            else {          /*待删结点为非跟结点*/
                if(kx<p->data.key)
                    /*f指向待删结点的父结点的指向待删结点的指针域*/
                    f=&(p->lchild);
                else {
                    f=&(p->rchild);
                }
            }
            if(q->rchild==nullptr){
                /*若待删结点无右子树，则以左子树替换待删结点*/
                r=q->lchild;    /*若待删结点是叶子结点也删除*/
                (*f)=r;
                free(q);
            }
            else if (q->lchild==nullptr) {
                /*若待删结点无左子树，则以右子树替换待删结点*/
                r=q->rchild;
                (*f)=r;
                free(q);
            }
            else {      /*既有左子树又有右子树*/
                r=q;
                s=q->lchild;
                while (s->rchild) {     /*在右子树上查找待删结点的前驱*/
                    r=s;
                    s=s->rchild;
                }
                (*f)->data=s->data;     /*替换待删结点*/
                if(r!=q)    /*待删结点的左孩子有右子树*/
                    r->rchild=s->lchild;    /*重建待删结点的前驱的左子树*/
                else {      /*待删结点的左孩子无右子树*/
                    r->lchild=s->lchild;    /*重建待删结点的前驱的左子树*/
                }
                free(s);
            }
        }
        cout<<"二叉排序树BST"<<endl;
        Display_BiTree(*BST);
        return flag;
    }

private:
    Bitree *BST;
private:
    /*初始化，构造一棵空二叉树*/
    void Init_BiTree()
    {
        BST=new Bitree();
    }
    /*以广义表形式输出二叉树*/
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
    /*在二叉排序树上查找关键码为kx的元素，若找到，则返回1，且q指向该结点，p指向其父结点；否则返回0，且p指向查找失败的最后一个结点*/
    int Search_BST(BiTNode **p,BiTNode **q,KeyType kx)
    {
        int flag=0;
        *q=*BST;
        while((*q)!=nullptr){           /*从根结点开始查找*/
            if(kx>(*q)->data.key){
                /*kx大于当前结点*q的元素关键码*/
                *p=*q;
                *q=(*q)->rchild;        /*将当前结点*q的右孩子置为新根*/
            }
            else if (kx<(*q)->data.key) {
                /*kx小于当前结点*q的关键码*/
                *p=*q;
                *q=(*q)->lchild;        /*将当前结点*q的左孩子置为新根*/
            }
            else                        /*查找成功，返回*/
            {
                flag=1;
                break;
            }
        }
        return flag;
    }
    /*在二叉排序树BST上插入关键码为kx的结点*/
    int Insert_BST(KeyType kx)
    {
        BiTNode *p,*q,*s;
        int flag=0;
        p=*BST;
        if(Search_BST(&p,&q,kx)==0)
        /*在BST为根的子树上查找*/
        {
            s=new BiTNode[sizeof (BiTNode)];
            if(s==nullptr){
                cout<<"内存分配失败"<<endl;
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
    /*创建二叉排序树*/
    void Create_BiTree(KeyType kx[],int n)
    {
        int i;
        for (i=0;i<n;i++) {
            Insert_BST(kx[i]);
        }
    }
};
#endif // BITREE_H
