#include <stdlib.h>
#include <string.h>
#include "bitree.h"

void bitree_init(BiTree *tree){
  tree->size=0;
  tree->root=NULL;
  return;
}

void bitree_destroy(BiTree *tree){
  bitree_rem_left(tree,NULL);
  memset(tree, 0, sizeof(BiTree));
  return;
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, int data){
  if(tree==NULL)
    return -1;
  if(node==NULL){
    if(tree->size==0){
      BiTreeNode *newN=(BiTreeNode *)malloc(sizeof(*newN));
      if(newN==NULL)
        return -1;
      newN->value=data;
      newN->left=NULL;
      newN->right=NULL;
      tree->root=newN;
      tree->size++;
      return 0;
    }
    else
      return -1;
  }
  BiTreeNode *newN=(BiTreeNode *)malloc(sizeof(*newN));
  if(newN==NULL)
    return -1;
  newN->value=data;
  newN->left=NULL;
  newN->right=NULL;
  node->left=newN;
  tree->size++;
  return 0;
  }

int bitree_ins_right(BiTree *tree, BiTreeNode *node, int data){
  if(tree==NULL)
    return -1;
  if(node==NULL){
    if(tree->size==0){
      BiTreeNode *newN=(BiTreeNode *)malloc(sizeof(*newN));
      if(newN==NULL)
        return -1;
      newN->value=data;
      newN->left=NULL;
      newN->right=NULL;
      tree->root=newN;
      tree->size++;
      return 0;
    }
    else
      return -1;
  }
  BiTreeNode *newN=(BiTreeNode *)malloc(sizeof(*newN));
  if(newN==NULL)
    return -1;
  newN->value=data;
  newN->left=NULL;
  newN->right=NULL;
  node->right=newN;
  tree->size++;
  return 0;
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node){
  BiTreeNode         **position;
  if(tree->size==0)
    return;
  if(node==NULL)
    position=&tree->root;
  else
    position=&node->left;
  if(*position!=NULL){
    bitree_rem_left(tree,*position);
    bitree_rem_right(tree,*position);
    free(&(*position)->value);
    free(*position);
    *position=NULL;
    tree->size--;
  }
  return;
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node){
  BiTreeNode         **position;
  if(tree->size==0)
    return;
  if(node==NULL)
    position=&tree->root;
  else
    position=&node->right;
  if(*position!=NULL){
    bitree_rem_left(tree,*position);
    bitree_rem_right(tree,*position);
    free(&(*position)->value);
    free(*position);
    *position=NULL;
    tree->size--;
  }
  return;
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, int value){
  bitree_init(merge); //Initialize merge tree
  if(bitree_ins_left(merge,NULL,value)==-1){
    bitree_destroy(merge);
    return -1;
  }
  merge->root->left=left->root;
  merge->root->right=right->root;
  merge->size=merge->size + right->size + left->size; //adjusting size
  left->root=NULL;
  left->size=0;
  right->root=NULL;
  right->size=0;
  return 0;
}
