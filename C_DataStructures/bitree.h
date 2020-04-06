#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>

typedef struct BiTreeNode BiTreeNode;
struct BiTreeNode{
  int value;
  BiTreeNode *left;
  BiTreeNode *right;
};

typedef struct BiTree BiTree;
struct BiTree{
  int size;
  BiTreeNode *root;
};

void bitree_init(BiTree *tree);
void bitree_destroy(BiTree *tree);
int bitree_ins_left(BiTree *tree, BiTreeNode *node, int data);
int bitree_ins_right(BiTree *tree, BiTreeNode *node, int data);
void bitree_rem_left(BiTree *tree, BiTreeNode *node);
void bitree_rem_right(BiTree *tree, BiTreeNode *node);
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, int value);
#define bitree_size(tree) (tree->size)
#define bitree_root(tree) (tree->node)
#define bitree_is_eob(node) ((node) == NULL)
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
#define bitree_data(node) ((node)->data)
#define bitree_left(node) ((node)->left)
#define bitree_right(node) ((node)->right)
#endif
