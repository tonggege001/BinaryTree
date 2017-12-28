//
// Created by tonggege on 17-11-10.
//
#include <cstdio>
#include "BasicConst.h"
#ifndef BITREE_BITREE_H
#define BITREE_BITREE_H

#endif //BITREE_BITREE_H

typedef struct ElemType{
    int key;//关键值
    char c;//字符
}ElemType;//基础数据类型

typedef struct BiTree{
    struct node * root;
    int numNode;//节点数
}BiTree;

typedef struct node{
    ElemType data;//数据域
    struct node * lchild;
    struct node * rchild;
}node;
Status InitBiTree(BiTree **T);
Status DestroyTreeNode(node * n);

Status DestroyBiTree(BiTree **T);
node * CreateBiTreeRec();
Status CreateBiTree(BiTree *T);
node * CreateBiTreeRec();
Status ClearBiTree(BiTree *T);
int BiTreeEmpty(BiTree *T);
int nodeDepth(node * n);
int BiTreeDepth(BiTree *T);
node * Root(BiTree *T);

char Value(BiTree *T,int key);

node * isInTree(node * root,int key);
Status Assign(BiTree *T,int key,char value);
//返回节点e是否在root中
node * isInTree(node * root,int key);

node * ParentRec(node * root,int key);
node * Parent(BiTree *T, int key);
//递归获取孩子的双亲节点
node * ParentRec(node * root,int key);

node * LeftChildRec(node * root, int key);
node * LeftChild(BiTree *T,int key);

node * LeftChildRec(node * root,int key);

node * RightChildRec(node * root,int key);
node * RightChild(BiTree *T, int key);
node * RightChildRec(node * root,int key);

node * LeftSiblingRec(node * root,int key);
node * LeftSibling(BiTree *T,int key);
node * LeftSiblingRec(node * root,int key);


node * RightSiblingRec(node * root,int key);
node * RightSibling(BiTree *T,int key);
node * RightSiblingRec(node * root,int key);

Status InsertChild(BiTree *T,node *p ,int LR,node * c);
node * nodeValue(node * n,int key);

Status DeleteChild(BiTree *T,node * p,int LR);

Status PreTraverseRec(node * root,void * Visit);
Status PreOrderTraverse(BiTree *T,void * Visit);
//递归遍历
Status PreTraverseRec(node * root,void * Visit);

Status InTraverseRec(node * root,void * Visit);
Status InOrderTraverse(BiTree *T,void * Visit);
//递归遍历
Status InTraverseRec(node * root,void * Visit);

Status PostTraverseRec(node * root,void * Visit);
Status PostOrderTraverse(BiTree *T,void * Visit);
//递归遍历
Status PostTraverseRec(node * root,void * Visit);

Status LevelOrderTraverse(BiTree *T,void * Visit);
void visitNode(node * N);
Status ChangeTree(BiTree * tree[], BiTree ** T, int num);

node * LoadDataRec(FILE * fp);
Status SaveDataRec(node * root,FILE * fp);
Status SaveData(BiTree * T);
Status LoadData(BiTree * T);







