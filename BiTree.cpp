//
// Created by tonggege on 17-11-10.
//

#include "BiTree.h"
#include <malloc.h>
#include<queue>
#include <iostream>
#include <cstdio>
#include <io.h>

using namespace std;
/**
 * func：初始化树
 * @param T 树
 * @return 状态码
 */
Status InitBiTree(BiTree **T){
    if(*T) {
        cout << "二叉树已经存在！"<<endl;
    }
    *T = (BiTree * )malloc(sizeof(BiTree)); //分配空间
    (*T)->root = NULL;
    return OK;
}

/**
 * func:销毁树
 * @param n 节点指针
 * @return 状态码
 */
Status DestroyTreeNode(node * n){
    //递归销毁二叉树节点，先销毁左孩子
    // 再销毁右孩子，最后销毁根节点
    if(n){
        DestroyTreeNode(n->lchild);
        DestroyTreeNode(n->rchild);
        free(n);
    }
    return OK;
}

Status DestroyBiTree(BiTree **T){
    if(!(*T)) return ERROR;
    DestroyTreeNode((*T)->root);
    free(*T);
    *T = NULL;
    return OK;
}

/**
 * func 生成二叉树
 * @param T 二叉树
 * @return 二叉树根节点
 */
node * CreateBiTreeRec();
Status CreateBiTree(BiTree *T){
    if(T==NULL) return ERROR; //判断传入的参数是否合法
    char c;int key;
    cout<<"请输入节点key值和c值,当key值为0时表示空指针（按照前序遍历输入）"<<endl;
    cin >>key; //输入key值
    cin.get();
    if(key == 0){ //如果key为0，那么结束输入
        T->root = NULL;
        return OK;
    }
    else{
        cin >> c;
        T->root = (node * )malloc(sizeof(node));
        T->root->data.key = key;
        T->root->data.c = c;
        T->root->lchild = NULL;
        T->root->rchild = NULL;
    }
    T->root->lchild = CreateBiTreeRec(); //递归地创造左孩子
    T->root->rchild = CreateBiTreeRec();//递归地创造右孩子
    return OK;

}
node * CreateBiTreeRec(){
    char c;int key;
    node * N = NULL;
    cin >> key;cin.get();
    if(key==0) return NULL;
    cin >> c;
    if(!(N = (node *)malloc(sizeof(node)))) return NULL;
    N->data.key = key;
    N->data.c = c;
    N->lchild = CreateBiTreeRec();
    N->rchild = CreateBiTreeRec();
    return N;
}

/**
 * func:销毁树
 * @param T 树指针
 * @return 状态码
 */
Status ClearBiTree(BiTree *T){
    if(T==NULL)return ERROR;
    DestroyTreeNode(T->root);
    T->root = NULL;
    return OK;
}

/**
 * func:判断树是否为空
 * @param T
 * @return
 */
int BiTreeEmpty(BiTree *T){
    if(T==NULL) return TRUE;
    int flag = (T->root == NULL?TRUE:FALSE); //如果为茶树不存在则直接返回TRUE
    return flag;
}


/**
 * func:求树的深度
 * @param n 节点
 * @return 深度
 */
//思路：
/**
 * 一棵树的深度可以定义为左子树和右子树的深度最大值+1,其中，空树深度为0
 */
int nodeDepth(node * n){
    if(n){
        int count1,count2;
        count1 = 1+nodeDepth(n->lchild); //计算左孩子地深度+1
        count2 = 1+nodeDepth(n->rchild);//计算右孩子的深度+1
        return (count1>count2?count1:count2);//返回两者的最大值
    }
    return 0;
}
int BiTreeDepth(BiTree *T){
    if(T==NULL) return 0;//如果二叉树不存在则深度为0
    return nodeDepth(T->root);//递归求数的深度
}

/**
 * func:求树的根节点
 * @param T
 * @return
 */
node * Root(BiTree *T){
    if(T==NULL) return NULL;
    return T->root;
}
/**
 * func 获取值
 * @param BiTree 二叉树
 * @param key 关键值
 * @return
 */
node * nodeValue(node * n,int key);
char Value(BiTree *T,int key){
    if(T==NULL) return ERROR; //判断条件
    return nodeValue(T->root,key)->data.c; //递归获取待查找的节点
}
node * nodeValue(node * n,int key){
    if(n){
        if(n->data.key==key) return n; //如果找到则直接返回key值
        else{
            node * cl = nodeValue(n->lchild,key); //否则递归查找左孩子
            node * cr = nodeValue(n->rchild,key);//递归查找右孩子
            return cl==NULL ? cr:cl; //返回两个的查找结果
        }
    }
    else{
        return NULL;
    }
}


/**
 * func 赋值，如果e在T中，则将value赋值为T
 * @param root 根节点
 * @param e 待赋值节点
 * @return 状态码
 */
node * isInTree(node * root,int key);
Status Assign(BiTree *T,int key,char value){
    if(T==NULL) return ERROR;
    node * N = isInTree(T->root,key);
    if(!N) return ERROR; //如果e不存在树上，则返回错误码
    else{
        N->data.c = value;
        return OK;
    }
}
//返回节点e是否在root中
node * isInTree(node * root,int key){
    if(!root) return NULL;//如果根节点为空，则不在这棵树上
    if(root->data.key==key) return root;//如果根节点是，则返回TRUE
    //返回左节点或右节点
    node * l = isInTree(root->lchild,key);//递归查找左孩子
    node * r = isInTree(root->rchild,key);//递归查找右孩子
    return l==NULL?r:l; //返回查找结果
}

/**
 * func:获得双亲节点
 * @param T ：树
 * @param e ：e的根节点
 * @return e的根节点
 */
node * ParentRec(node * root,int key);
node * Parent(BiTree *T, int key){
    if(T==NULL) return NULL;
    if(T->root->data.key==key) return NULL;
    node * l = ParentRec(T->root->lchild,key);  //获取做孩子的双亲节点
    node * r = ParentRec(T->root->rchild,key);  //获取右孩子的双亲节点
    return l?l:r;
}
//递归获取孩子的双亲节点
node * ParentRec(node * root,int key){
    if(root){
        //如果找到，则返回找到的节点
        if(root->lchild&&root->lchild->data.key==key||root->rchild&&root->rchild->data.key==key){
            return root;
        }
        else{//不相等则继续往下递归搜索
            node * l = ParentRec(root->lchild,key);
            node * r = ParentRec(root->rchild,key);
            return l?l:r;
        }
    }
    return NULL;
}

/**
 * func:获得左孩子
 * @param T 树
 * @param key 节点关键值
 * @return 节点e的左孩子
 */
node * LeftChildRec(node * root, int key);
node * LeftChild(BiTree *T,int key){
    if(T==NULL) return NULL;
    return LeftChildRec(T->root,key);
}

node * LeftChildRec(node * root,int key){
    if(root){
        if(root->data.key == key){ //找到的情况
            return root->lchild;
        }
        else{
            //没找到继续递归的向下查找
            node * l = LeftChildRec(root->lchild,key);
            node * r = LeftChildRec(root->rchild,key);
            return l?l:r;
        }
    }
    return NULL;
}

/**
 * func:返回节点e的右孩子
 * @param T 树
 * @param e 节点数据域
 * @return 节点e的右孩子
 */
node * RightChildRec(node * root,int key);
node * RightChild(BiTree *T, int key){
    if(T==NULL) return NULL;
    return RightChildRec(T->root,key);
}
node * RightChildRec(node * root,int key){
    if(root){
        if(root->data.key == key){
            return root->rchild;//查找到的情况
        }
        else{//递归查找
            node * l = RightChildRec(root->lchild,key);
            node * r = RightChildRec(root->rchild,key);
            return l?l:r;
        }
    }
    return NULL;
}

/**
 * func:返回e左兄弟
 * @param T：树
 * @param e：e节点
 * @return ：返回e的右孩子
 */
node * LeftSiblingRec(node * root,int key);
node * LeftSibling(BiTree *T,int key){
    if(T==NULL) return NULL;
    return LeftSiblingRec(T->root, key);
}
node * LeftSiblingRec(node * root,int key){
    if(root){
        //如果本身就是左孩子则不存在左兄弟
        if(root->lchild&&root->lchild->data.key==key) return NULL;
        //如果是右孩子并且找到，则返回左孩子
        if(root->rchild&&root->rchild->data.key==key) return root->lchild;
        //如果没有查找到，则继续向下深入查找
        node * l = LeftSiblingRec(root->lchild,key);
        node * r = LeftSiblingRec(root->rchild,key);
        return l?l:r;
    }
    return NULL;
}


/**
 * func:返回右兄弟
 * @param T：树
 * @param e：e节点
 * @return ：返回e的左孩子
 */
node * RightSiblingRec(node * root,int key);
node * RightSibling(BiTree *T,int key){
    if(T==NULL) return NULL;
    return RightSiblingRec(T->root,key);
}
node * RightSiblingRec(node * root,int key){
    if(root){
        if(root->lchild&&root->lchild->data.key==key) return root->rchild;
        if(root->rchild&&root->rchild->data.key==key) return NULL;
        node * l = RightSiblingRec(root->lchild,key);
        node * r = RightSiblingRec(root->rchild,key);
        return l?l:r;
    }
    return NULL;
}

/**
 * func:根据LR为0或1，插入c为T中p所指节点的左或右子树。p所指节点的原有左或右子树则成为c的右子树
 * 初始条件：二叉树T存在，p指向T中某个节点，LR为0或1，非空二叉树c与T不相交且右子树为空
 * @param T 树
 * @param LR
 * @param c
 * @return
 */
Status InsertChild(BiTree *T,node *p ,int LR,node * c){
    if(T==NULL) return  ERROR;
    //判断传入的信息是否正确
    if(!p) return ERROR;
    if(!c) return ERROR;
    if(c->rchild!=NULL) return ERROR;
    if(LR==1){//如果插入左孩子
        c->rchild = p->lchild;
        p->lchild = c;
    }
    else{//否则
        c->rchild = p->rchild;
        p->rchild = c;
    }
    return OK;
}



/**
 * func:删除孩子节点
 * @param T
 * @param p
 * @param LR
 * @return
 */
Status DeleteChild(BiTree *T,node * p,int LR){
    if(T==NULL) return ERROR;
    if(!p) return ERROR;
    if(LR==1){//如果删除左孩子
        DestroyTreeNode(p->lchild);
        p->lchild = NULL;
    }
    else{//否则
        DestroyTreeNode(p->rchild);
        p->rchild = NULL;
    }
    return OK;
}

/**
 * func:前序遍历
 * @param T ：树
 * @param Visit ：访问函数
 * @return 状态码
 */
Status PreTraverseRec(node * root,void * Visit);
Status PreOrderTraverse(BiTree *T,void * Visit){
    if(T==NULL) return ERROR;
    return PreTraverseRec(T->root,Visit);
}
//递归遍历
Status PreTraverseRec(node * root,void * Visit){
    Status (*vst)(node*) = (Status (*)(node *)) Visit;
    if(root){
        if(!vst(root)) return ERROR; //先遍历根节点，再遍历左右子树
        PreTraverseRec(root->lchild,(void*)vst);
        PreTraverseRec(root->rchild,(void*)vst);
    }
}

/**
 * func:中序遍历
 * @param T ：树
 * @param Visit ：访问函数
 * @return 状态码
 */
Status InTraverseRec(node * root,void * Visit);
Status InOrderTraverse(BiTree *T,void * Visit){
    if(T==NULL) return ERROR;
    return InTraverseRec(T->root,Visit);
}
//递归遍历
Status InTraverseRec(node * root,void * Visit){
    Status (*vst)(node*) = (Status (*)(node *)) Visit;
    if(root){
        InTraverseRec(root->lchild,(void*)vst); //遍历左子树
        if(!vst(root)) return ERROR; //访问根节点
        InTraverseRec(root->rchild,(void*)vst);//遍历右子树
    }
}

/**
 * func:后序遍历
 * @param T ：树
 * @param Visit ：访问函数
 * @return 状态码
 */
Status PostTraverseRec(node * root,void * Visit);
Status PostOrderTraverse(BiTree *T,void * Visit){
    if(T==NULL) return ERROR;
    return PostTraverseRec(T->root,Visit);
}
//递归遍历
Status PostTraverseRec(node * root,void * Visit){
    Status (*vst)(node*) = (Status (*)(node *)) Visit;
    if(root){
        PostTraverseRec(root->lchild,(void*)vst);//遍历左子树
        PostTraverseRec(root->rchild,(void*)vst);//遍历右子树
        if(!vst(root)) return ERROR;//遍历根节点
    }
}


/**
 * func：层序遍历
 * @param T
 * @param Visit
 * @return
 */
Status LevelOrderTraverse(BiTree *T,void * Visit){
    std::queue <node *>Q; //利用了C++的队列
    Status (*vst)(node * ) = (Status(*)(node *)) Visit; //声明访问函数
    Q.push(T->root);node * self = NULL; //将根节点如队列
    while(!Q.empty()){
        self = Q.front();Q.pop(); //出队列
        //将两个孩子放入到队列中
        if(self->lchild) Q.push(self->lchild);
        if(self->rchild) Q.push(self->rchild);
        //访问该节点
        if(!vst(self)) return ERROR;
    }
    return OK;
}


//visit函数
void visitNode(node * N){
    printf("Key 为 ：%d , C值为%c \n",N->data.key,N->data.c);
}


Status ChangeTree(BiTree * tree[], BiTree ** T, int num){
    if(!tree[num]) (*T) = tree[num];
    else return ERROR;
    return OK;
}

Status LoadData(BiTree * T){
    FILE * fp = fopen("file","r");
    int key;char c;int flag = 0;
    flag = fscanf(fp,"%d",&key);
    if(key==0||flag!=1){
        T->root = NULL;
        fclose(fp);
        return OK;
    }
    //加载数据和创造树非常类似，只是输入流换成了文件而已
    fscanf(fp," %c",&c);
    T->root = (node *)malloc(sizeof(node));
    T->root->data.key = key;
    T->root->data.c = c;
    T->root->lchild = LoadDataRec(fp);
    T->root->rchild = LoadDataRec(fp);
    fclose(fp);
    return OK;
}
node * LoadDataRec(FILE * fp){
    int key;
    fscanf(fp,"%d",&key);
    if(key == 0) return NULL;
    node * root = (node * )malloc(sizeof(node));
    root->data.key = key;
    fscanf(fp," %c",&root->data.c);
    root->lchild = LoadDataRec(fp);
    root->rchild = LoadDataRec(fp);
    return root;

}

Status SaveData(BiTree * T){
    if(T->root == NULL) return ERROR;
    FILE * fp = fopen("file","w");
    fprintf(fp,"%d %c ",T->root->data.key,T->root->data.c); //写入到文件
    SaveDataRec(T->root->lchild,fp);//递归向下
    SaveDataRec(T->root->rchild,fp);//递归向下
    fclose(fp);
    return OK;

}
Status SaveDataRec(node * root,FILE * fp){
    if(!root){
        fprintf(fp,"%d ",0);
        return OK;
    }
    else{
        fprintf(fp,"%d %c ",root->data.key,root->data.c);
        SaveDataRec(root->lchild,fp);
        SaveDataRec(root->rchild,fp);
    }
    return OK;
}

































