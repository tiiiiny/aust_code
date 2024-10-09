#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>

using namespace std;
 
typedef char ElemType;  //?????????????????????????

 
int LEAFCOUNT=0;
int NODECOUNT=0;
 
typedef struct BiTNode
{
    ///===============???????======================== 
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
 
void CreateBiTree(BiTree &T)//???????????????"#"???????
{   
    ///===============???????======================== 
    char ch;
    std::cin >> ch;
    if(ch == '#')   T = NULL;
    else{
        BiTree T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
 
void PreOrderTraverse(BiTree T)//???????
{
    ///===============???????======================== 
}
 
void InOrderTraverse(BiTree T)//???????
{
    ///===============???????======================== 
}
 
void PostOrderTraverse(BiTree T)//???????
{
    ///===============???????======================== 
}
 
int BTDepth(BiTree T)//????????????
{   
    ///===============???????======================== 
}
 
void Leaf(BiTree T)//??????????????, ?????????
{   
    ///===============???????======================== 
}
 
void NodeCount(BiTree T)//???????????????, ?????????
{   
    ///===============???????======================== 
}
 
int main()
{
    BiTree T=NULL;
    int select;
    while(scanf("%d",&select)!=EOF)
    {
 
        switch(select)
        {
            case 0: 
                return 0;
            case 1:
            getchar();
                CreateBiTree(T);
                break;
            case 2:
                if(T) {
                    PreOrderTraverse(T);                    
                    printf("\n");
                }
                break;
            case 3:
                if(T) {
                    InOrderTraverse(T);                 
                    printf("\n");
                }
                break;
            case 4:
                if(T) {
                    PostOrderTraverse(T);
                    printf("\n");
                }
                break;
            case 5:
                printf("%d\n",BTDepth(T));
                break;
            case 6:
                LEAFCOUNT=0;
                Leaf(T);
                printf("%d\n",LEAFCOUNT);
                break;
            case 7:
                NODECOUNT=0;
                NodeCount(T);
                printf("%d\n",NODECOUNT);
                break;
          }
    }
    return 0; 
}