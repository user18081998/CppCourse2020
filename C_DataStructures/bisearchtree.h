#ifndef BI_SEARCH_TREE
#define BI_SEARCH_TREE

#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
struct Node{
  int value;
  Node *left;
  Node *right;
};

typedef struct BisTree BisTree;
struct BisTree{
  int size;
  Node* root;
};

void bistree_init(BisTree *tree);
void bistree_destroy(BisTree *tree);
int bistree_insert(BisTree *tree, const int value);
int bistree_remove(BisTree *tree, const int value);
int bistree_lookup(const BisTree *tree, int value);
#define bistree_size(tree) (tree->size)
#endif
