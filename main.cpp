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
        printf("    ��ѡ����Ĳ���[0~20]:");
        fflush(stdin);
        scanf("%d",&op);
        switch(op){
            case 1:
                if(InitBiTree(&T)==OK) printf("�����������ɹ���\n");
                else printf("����������ʧ�ܣ�\n");
                break;
            case 2:
                if(DestroyBiTree(&T)==OK){
                    T = NULL;
                    printf("���������ٳɹ���\n");
                }
                else{
                    printf("���ٶ�����ʧ�ܣ�");
                }
                break;
            case 3:
                CreateBiTree(T)==OK?printf("\n�����������ɹ���\n"):printf("����������ʧ�ܣ�\n");
                break;
            case 4:
                ClearBiTree(T)==ERROR?printf("\n�������������\n"):printf("\n����������ɹ�\n");
                break;
            case 5:
                BiTreeEmpty(T)==TRUE?printf("������Ϊ��\n"):printf("��������Ϊ��\n");
                break;
            case 6:
                printf("�����������Ϊ%d",BiTreeDepth(T));
                break;
            case 7:
                Node = Root(T);
                printf("���ڵ��keyֵΪ��%d, cֵΪ%c",Node->data.key,Node->data.c);
                break;
            case 8:
                printf("������ؼ���key��\n");
                scanf("%d",&key);
                if(c=Value(T,key)) printf("cֵΪ%c",c);
                else printf("δ֪����\n");
                break;
            case 9:
                printf("������ؼ���key�ͱ���ֵc��\n");
                scanf("%d",&key);getchar();
                scanf("%c",&c);
                if(Assign(T,key,c)==ERROR) printf("��ֵ����\n");
                else printf("��ֵ�ɹ�\n");
                break;
            case 10:
                printf("������ؼ��֣�\n");
                scanf("%d",&key);
                Node = Parent(T,key);
                if(!Node) printf("δ֪����");
                else{
                    printf("keyֵΪ%d�Ľ���˫�׽���keyֵΪ��%d��cֵΪ��%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 11:
                printf("������ؼ��֣�\n");
                scanf("%d",&key);
                Node = LeftChild(T,key);
                if(!Node) printf("δ֪����");
                else{
                    printf("keyֵΪ%d�Ľ������ӽ���keyֵΪ��%d��cֵΪ��%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 12:
                printf("������ؼ��֣�\n");
                scanf("%d",&key);
                Node = RightChild(T,key);
                if(!Node) printf("δ֪����");
                else{
                    printf("keyֵΪ%d�Ľ����Һ��ӽ���keyֵΪ��%d��cֵΪ��%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 13:
                printf("������ؼ��֣�\n");
                scanf("%d",&key);
                Node = LeftSibling(T,key);
                if(!Node) printf("δ֪����");
                else{
                    printf("keyֵΪ%d�Ľ������ֵܽ���keyֵΪ��%d��cֵΪ��%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 14:
                printf("������ؼ��֣�\n");
                scanf("%d",&key);
                Node = RightSibling(T,key);
                if(!Node) printf("δ֪����");
                else{
                    printf("keyֵΪ%d�Ľ������ֵܽ���keyֵΪ��%d��cֵΪ��%c",key,Node->data.key,Node->data.c);
                }
                break;
            case 15:
                printf("��������뵽���ϵ�ĳ������keyֵ��");
                scanf("%d",&key);
                Node = nodeValue(T->root,key);
                if(!Node){
                    printf("�������");
                    break;
                }
                printf("������������½ڵ��keyֵ��valueֵ��\n");
                scanf("%d",&key);getchar();scanf("%c",&c);
                Node2 = (node *)malloc(sizeof(node));
                Node2->data.c = c;
                Node2->data.key = key;
                Node2->lchild = NULL;
                Node2->rchild = NULL;
                printf("���������������������������1\\0\n");
                scanf("%d",&key);
                if(InsertChild(T,Node,key,Node2)) printf("����ɹ�\n");
                else printf("����ʧ��\n");
                break;
            case 16:
                printf("��ɾ����Ҫɾ���Ľ���keyֵ��\n");
                scanf("%d",&key);
                Node = nodeValue(T->root,key);
                printf("������������������������1\\0\n");
                scanf("%d",&key);
                if(DeleteChild(T,Node,key)) printf("ɾ���ɹ�\n");
                else printf("ɾ��ʧ��\n");
                break;
            case 17:
                if(!PreOrderTraverse(T,(void *)(&visitNode))) printf("��������");
                break;
            case 18:
                if(!InOrderTraverse(T,(void *)(&visitNode))) printf("��������");
                break;
            case 19:
                if(!PostOrderTraverse(T,(void *)(&visitNode))) printf("��������");
                break;
            case 20:
                if(!LevelOrderTraverse(T,(void *)(&visitNode))) printf("��������");
                break;
            case 21:
                printf("�������л��ı�ţ�\n");
                scanf("%d",&key);
                ChangeTree(tree,&T,key) ? (printf("�ɹ��л�����%d����",key),current = key):printf("�л�ʧ��");
                break;
            case 22:
                SaveData(T)==OK?printf("���̳ɹ�\n"):printf("����ʧ��\n");
                break;
            case 23:
                LoadData(T)==OK?printf("���سɹ�\n"):printf("����ʧ��\n");
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

