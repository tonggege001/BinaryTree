//
// Created by tonggege on 17-11-14.
//

#include <stdio.h>
#include "BiTree.h"



BiTree * tree[10];
int current;
int main(void){
    BiTree * T = NULL;  int op=1;
    int key;current = 1;
    char c;
    ElemType e;
    ElemType e2;
    node * Node = NULL;node * Node2 = NULL;
    while(op){
        //  system("cls");
        printf("\n\n");
        printf("                  Menu for Binary Tree \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitTree          11. LeftChild\n");
        printf("    	  2. DestroyBiTree     12. RightChild\n");
        printf("    	  3. CreateBiTree      13. LeftSibling\n");
        printf("    	  4. ClearBiTree       14. RightSibling\n");
        printf("    	  5. BiTreeEmpty       15. InsertChild\n");
        printf("    	  6. BiTreeDepth       16. DeleteChild\n");
        printf("    	  7.Root               17.PreOrderTraverse\n");
        printf("    	  8. Value             18. InOrderTraverse   \n");
        printf("          9.Assign             19.PostOrderTraverse\n");
        printf("          10.Parent            20.LevelOrderTraverse\n");
        printf("          21.ChangeTree        22.SaveData\n");
        printf("          23.LoadData          0.Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~20]:");
        fflush(stdin);
        scanf("%d",&op);
        switch(op){
            case 1:
                if(InitBiTree(&T)==OK) printf("二叉树创建成功！\n");
                else printf("二叉树创建失败！\n");
                break;
            case 2:
                if(DestroyBiTree(&T)==OK){
                    T = NULL;
                    printf("二叉树销毁成功！\n");
                }
                else{
                    printf("销毁二叉树失败！");
                }
                break;
            case 3:
                CreateBiTree(T)==OK?printf("\n二叉树创建成功！\n"):printf("二叉树创建失败！\n");
                break;
            case 4:
                ClearBiTree(T)==ERROR?printf("\n二叉树清除错误\n"):printf("\n二叉树清除成功\n");
                break;
            case 5:
                BiTreeEmpty(T)==TRUE?printf("二叉树为空\n"):printf("二叉树不为空\n");
                break;
            case 6:
                printf("二叉树的深度为%d",BiTreeDepth(T));
                break;
            case 7:
                Node = Root(T);
                printf("根节点的key值为：%d, c值为%c",Node->data.key,Node->data.c);
                break;
            case 8:
                printf("请输入关键字key：\n");
                scanf("%d",&key);
                if(c=Value(T,key)) printf("c值为%c",c);
                else printf("未知错误！\n");
                break;
            case 9:
                printf("请输入关键字key和被赋值c：\n");
                scanf("%d",&key);getchar();
                scanf("%c",&c);
                if(Assign(T,key,c)==ERROR) printf("赋值错误\n");
                else printf("赋值成功\n");
                break;
            case 10:
                printf("请输入关键字：\n");
                scanf("%d",&key);
                Node = Parent(T,key);
                if(!Node) printf("未知错误");
                else{
                    printf("key值为%d的结点的双亲结点的key值为：%d，c值为：%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 11:
                printf("请输入关键字：\n");
                scanf("%d",&key);
                Node = LeftChild(T,key);
                if(!Node) printf("未知错误");
                else{
                    printf("key值为%d的结点的左孩子结点的key值为：%d，c值为：%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 12:
                printf("请输入关键字：\n");
                scanf("%d",&key);
                Node = RightChild(T,key);
                if(!Node) printf("未知错误");
                else{
                    printf("key值为%d的结点的右孩子结点的key值为：%d，c值为：%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 13:
                printf("请输入关键字：\n");
                scanf("%d",&key);
                Node = LeftSibling(T,key);
                if(!Node) printf("未知错误");
                else{
                    printf("key值为%d的结点的右兄弟结点的key值为：%d，c值为：%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 14:
                printf("请输入关键字：\n");
                scanf("%d",&key);
                Node = RightSibling(T,key);
                if(!Node) printf("未知错误");
                else{
                    printf("key值为%d的结点的右兄弟结点的key值为：%d，c值为：%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 15:
                printf("请输入插入到树上的某个结点的key值：");
                scanf("%d",&key);
                Node = nodeValue(T->root,key);
                if(!Node){
                    printf("插入错误");
                    break;
                }
                printf("请输入产生的新节点的key值和value值：\n");
                scanf("%d",&key);getchar();scanf("%c",&c);
                Node2 = (node *)malloc(sizeof(node));
                Node2->data.c = c;
                Node2->data.key = key;
                Node2->lchild = NULL;
                Node2->rchild = NULL;
                printf("请输入插入左子树还是右子树？1\\0\n");
                scanf("%d",&key);
                if(InsertChild(T,Node,key,Node2)) printf("插入成功\n");
                else printf("插入失败\n");
                break;
            case 16:
                printf("请删除需要删除的结点的key值：\n");
                scanf("%d",&key);
                Node = nodeValue(T->root,key);
                printf("请输入左子树还是右子树？1\\0\n");
                scanf("%d",&key);
                if(DeleteChild(T,Node,key)) printf("删除成功\n");
                else printf("删除失败\n");
                break;
            case 17:
                if(!PreOrderTraverse(T,(void *)(&visitNode))) printf("遍历错误");
                break;
            case 18:
                if(!InOrderTraverse(T,(void *)(&visitNode))) printf("遍历错误");
                break;
            case 19:
                if(!PostOrderTraverse(T,(void *)(&visitNode))) printf("遍历错误");
                break;
            case 20:
                if(!LevelOrderTraverse(T,(void *)(&visitNode))) printf("遍历错误");
                break;
            case 21:
                printf("请输入切换的编号：\n");
                scanf("%d",&key);
                ChangeTree(tree,&T,key) ? (printf("成功切换到第%d棵树",key),current = key):printf("切换失败");
                break;
            case 22:
                SaveData(T)==OK?printf("存盘成功\n"):printf("存盘失败\n");
                break;
            case 23:
                LoadData(T)==OK?printf("加载成功\n"):printf("加载失败\n");
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()

