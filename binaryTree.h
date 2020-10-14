#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} Node;

Node* createNode(int value);
void insert(Node* root, Node* toInsert);
void printPostorder(Node* root);
void printPreorder(Node* root);
void printInorder(Node* root);
int size(Node* root);
void freeTree(Node* root);

#endif
