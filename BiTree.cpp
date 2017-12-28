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
 * func����ʼ����
 * @param T ��
 * @return ״̬��
 */
Status InitBiTree(BiTree **T){
    if(*T) {
        cout << "�������Ѿ����ڣ�"<<endl;
    }
    *T = (BiTree * )malloc(sizeof(BiTree)); //����ռ�
    (*T)->root = NULL;
    return OK;
}

/**
 * func:������
 * @param n �ڵ�ָ��
 * @return ״̬��
 */
Status DestroyTreeNode(node * n){
    //�ݹ����ٶ������ڵ㣬����������
    // �������Һ��ӣ�������ٸ��ڵ�
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
 * func ���ɶ�����
 * @param T ������
 * @return ���������ڵ�
 */
node * CreateBiTreeRec();
Status CreateBiTree(BiTree *T){
    if(T==NULL) return ERROR; //�жϴ���Ĳ����Ƿ�Ϸ�
    char c;int key;
    cout<<"������ڵ�keyֵ��cֵ,��keyֵΪ0ʱ��ʾ��ָ�루����ǰ��������룩"<<endl;
    cin >>key; //����keyֵ
    cin.get();
    if(key == 0){ //���keyΪ0����ô��������
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
    T->root->lchild = CreateBiTreeRec(); //�ݹ�ش�������
    T->root->rchild = CreateBiTreeRec();//�ݹ�ش����Һ���
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
 * func:������
 * @param T ��ָ��
 * @return ״̬��
 */
Status ClearBiTree(BiTree *T){
    if(T==NULL)return ERROR;
    DestroyTreeNode(T->root);
    T->root = NULL;
    return OK;
}

/**
 * func:�ж����Ƿ�Ϊ��
 * @param T
 * @return
 */
int BiTreeEmpty(BiTree *T){
    if(T==NULL) return TRUE;
    int flag = (T->root == NULL?TRUE:FALSE); //���Ϊ������������ֱ�ӷ���TRUE
    return flag;
}


/**
 * func:���������
 * @param n �ڵ�
 * @return ���
 */
//˼·��
/**
 * һ��������ȿ��Զ���Ϊ����������������������ֵ+1,���У��������Ϊ0
 */
int nodeDepth(node * n){
    if(n){
        int count1,count2;
        count1 = 1+nodeDepth(n->lchild); //�������ӵ����+1
        count2 = 1+nodeDepth(n->rchild);//�����Һ��ӵ����+1
        return (count1>count2?count1:count2);//�������ߵ����ֵ
    }
    return 0;
}
int BiTreeDepth(BiTree *T){
    if(T==NULL) return 0;//��������������������Ϊ0
    return nodeDepth(T->root);//�ݹ����������
}

/**
 * func:�����ĸ��ڵ�
 * @param T
 * @return
 */
node * Root(BiTree *T){
    if(T==NULL) return NULL;
    return T->root;
}
/**
 * func ��ȡֵ
 * @param BiTree ������
 * @param key �ؼ�ֵ
 * @return
 */
node * nodeValue(node * n,int key);
char Value(BiTree *T,int key){
    if(T==NULL) return ERROR; //�ж�����
    return nodeValue(T->root,key)->data.c; //�ݹ��ȡ�����ҵĽڵ�
}
node * nodeValue(node * n,int key){
    if(n){
        if(n->data.key==key) return n; //����ҵ���ֱ�ӷ���keyֵ
        else{
            node * cl = nodeValue(n->lchild,key); //����ݹ��������
            node * cr = nodeValue(n->rchild,key);//�ݹ�����Һ���
            return cl==NULL ? cr:cl; //���������Ĳ��ҽ��
        }
    }
    else{
        return NULL;
    }
}


/**
 * func ��ֵ�����e��T�У���value��ֵΪT
 * @param root ���ڵ�
 * @param e ����ֵ�ڵ�
 * @return ״̬��
 */
node * isInTree(node * root,int key);
Status Assign(BiTree *T,int key,char value){
    if(T==NULL) return ERROR;
    node * N = isInTree(T->root,key);
    if(!N) return ERROR; //���e���������ϣ��򷵻ش�����
    else{
        N->data.c = value;
        return OK;
    }
}
//���ؽڵ�e�Ƿ���root��
node * isInTree(node * root,int key){
    if(!root) return NULL;//������ڵ�Ϊ�գ������������
    if(root->data.key==key) return root;//������ڵ��ǣ��򷵻�TRUE
    //������ڵ���ҽڵ�
    node * l = isInTree(root->lchild,key);//�ݹ��������
    node * r = isInTree(root->rchild,key);//�ݹ�����Һ���
    return l==NULL?r:l; //���ز��ҽ��
}

/**
 * func:���˫�׽ڵ�
 * @param T ����
 * @param e ��e�ĸ��ڵ�
 * @return e�ĸ��ڵ�
 */
node * ParentRec(node * root,int key);
node * Parent(BiTree *T, int key){
    if(T==NULL) return NULL;
    if(T->root->data.key==key) return NULL;
    node * l = ParentRec(T->root->lchild,key);  //��ȡ�����ӵ�˫�׽ڵ�
    node * r = ParentRec(T->root->rchild,key);  //��ȡ�Һ��ӵ�˫�׽ڵ�
    return l?l:r;
}
//�ݹ��ȡ���ӵ�˫�׽ڵ�
node * ParentRec(node * root,int key){
    if(root){
        //����ҵ����򷵻��ҵ��Ľڵ�
        if(root->lchild&&root->lchild->data.key==key||root->rchild&&root->rchild->data.key==key){
            return root;
        }
        else{//�������������µݹ�����
            node * l = ParentRec(root->lchild,key);
            node * r = ParentRec(root->rchild,key);
            return l?l:r;
        }
    }
    return NULL;
}

/**
 * func:�������
 * @param T ��
 * @param key �ڵ�ؼ�ֵ
 * @return �ڵ�e������
 */
node * LeftChildRec(node * root, int key);
node * LeftChild(BiTree *T,int key){
    if(T==NULL) return NULL;
    return LeftChildRec(T->root,key);
}

node * LeftChildRec(node * root,int key){
    if(root){
        if(root->data.key == key){ //�ҵ������
            return root->lchild;
        }
        else{
            //û�ҵ������ݹ�����²���
            node * l = LeftChildRec(root->lchild,key);
            node * r = LeftChildRec(root->rchild,key);
            return l?l:r;
        }
    }
    return NULL;
}

/**
 * func:���ؽڵ�e���Һ���
 * @param T ��
 * @param e �ڵ�������
 * @return �ڵ�e���Һ���
 */
node * RightChildRec(node * root,int key);
node * RightChild(BiTree *T, int key){
    if(T==NULL) return NULL;
    return RightChildRec(T->root,key);
}
node * RightChildRec(node * root,int key){
    if(root){
        if(root->data.key == key){
            return root->rchild;//���ҵ������
        }
        else{//�ݹ����
            node * l = RightChildRec(root->lchild,key);
            node * r = RightChildRec(root->rchild,key);
            return l?l:r;
        }
    }
    return NULL;
}

/**
 * func:����e���ֵ�
 * @param T����
 * @param e��e�ڵ�
 * @return ������e���Һ���
 */
node * LeftSiblingRec(node * root,int key);
node * LeftSibling(BiTree *T,int key){
    if(T==NULL) return NULL;
    return LeftSiblingRec(T->root, key);
}
node * LeftSiblingRec(node * root,int key){
    if(root){
        //���������������򲻴������ֵ�
        if(root->lchild&&root->lchild->data.key==key) return NULL;
        //������Һ��Ӳ����ҵ����򷵻�����
        if(root->rchild&&root->rchild->data.key==key) return root->lchild;
        //���û�в��ҵ�������������������
        node * l = LeftSiblingRec(root->lchild,key);
        node * r = LeftSiblingRec(root->rchild,key);
        return l?l:r;
    }
    return NULL;
}


/**
 * func:�������ֵ�
 * @param T����
 * @param e��e�ڵ�
 * @return ������e������
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
 * func:����LRΪ0��1������cΪT��p��ָ�ڵ�������������p��ָ�ڵ��ԭ��������������Ϊc��������
 * ��ʼ������������T���ڣ�pָ��T��ĳ���ڵ㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ��
 * @param T ��
 * @param LR
 * @param c
 * @return
 */
Status InsertChild(BiTree *T,node *p ,int LR,node * c){
    if(T==NULL) return  ERROR;
    //�жϴ������Ϣ�Ƿ���ȷ
    if(!p) return ERROR;
    if(!c) return ERROR;
    if(c->rchild!=NULL) return ERROR;
    if(LR==1){//�����������
        c->rchild = p->lchild;
        p->lchild = c;
    }
    else{//����
        c->rchild = p->rchild;
        p->rchild = c;
    }
    return OK;
}



/**
 * func:ɾ�����ӽڵ�
 * @param T
 * @param p
 * @param LR
 * @return
 */
Status DeleteChild(BiTree *T,node * p,int LR){
    if(T==NULL) return ERROR;
    if(!p) return ERROR;
    if(LR==1){//���ɾ������
        DestroyTreeNode(p->lchild);
        p->lchild = NULL;
    }
    else{//����
        DestroyTreeNode(p->rchild);
        p->rchild = NULL;
    }
    return OK;
}

/**
 * func:ǰ�����
 * @param T ����
 * @param Visit �����ʺ���
 * @return ״̬��
 */
Status PreTraverseRec(node * root,void * Visit);
Status PreOrderTraverse(BiTree *T,void * Visit){
    if(T==NULL) return ERROR;
    return PreTraverseRec(T->root,Visit);
}
//�ݹ����
Status PreTraverseRec(node * root,void * Visit){
    Status (*vst)(node*) = (Status (*)(node *)) Visit;
    if(root){
        if(!vst(root)) return ERROR; //�ȱ������ڵ㣬�ٱ�����������
        PreTraverseRec(root->lchild,(void*)vst);
        PreTraverseRec(root->rchild,(void*)vst);
    }
}

/**
 * func:�������
 * @param T ����
 * @param Visit �����ʺ���
 * @return ״̬��
 */
Status InTraverseRec(node * root,void * Visit);
Status InOrderTraverse(BiTree *T,void * Visit){
    if(T==NULL) return ERROR;
    return InTraverseRec(T->root,Visit);
}
//�ݹ����
Status InTraverseRec(node * root,void * Visit){
    Status (*vst)(node*) = (Status (*)(node *)) Visit;
    if(root){
        InTraverseRec(root->lchild,(void*)vst); //����������
        if(!vst(root)) return ERROR; //���ʸ��ڵ�
        InTraverseRec(root->rchild,(void*)vst);//����������
    }
}

/**
 * func:�������
 * @param T ����
 * @param Visit �����ʺ���
 * @return ״̬��
 */
Status PostTraverseRec(node * root,void * Visit);
Status PostOrderTraverse(BiTree *T,void * Visit){
    if(T==NULL) return ERROR;
    return PostTraverseRec(T->root,Visit);
}
//�ݹ����
Status PostTraverseRec(node * root,void * Visit){
    Status (*vst)(node*) = (Status (*)(node *)) Visit;
    if(root){
        PostTraverseRec(root->lchild,(void*)vst);//����������
        PostTraverseRec(root->rchild,(void*)vst);//����������
        if(!vst(root)) return ERROR;//�������ڵ�
    }
}


/**
 * func���������
 * @param T
 * @param Visit
 * @return
 */
Status LevelOrderTraverse(BiTree *T,void * Visit){
    std::queue <node *>Q; //������C++�Ķ���
    Status (*vst)(node * ) = (Status(*)(node *)) Visit; //�������ʺ���
    Q.push(T->root);node * self = NULL; //�����ڵ������
    while(!Q.empty()){
        self = Q.front();Q.pop(); //������
        //���������ӷ��뵽������
        if(self->lchild) Q.push(self->lchild);
        if(self->rchild) Q.push(self->rchild);
        //���ʸýڵ�
        if(!vst(self)) return ERROR;
    }
    return OK;
}


//visit����
void visitNode(node * N){
    printf("Key Ϊ ��%d , CֵΪ%c \n",N->data.key,N->data.c);
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
    //�������ݺʹ������ǳ����ƣ�ֻ���������������ļ�����
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
    fprintf(fp,"%d %c ",T->root->data.key,T->root->data.c); //д�뵽�ļ�
    SaveDataRec(T->root->lchild,fp);//�ݹ�����
    SaveDataRec(T->root->rchild,fp);//�ݹ�����
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

































