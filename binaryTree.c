#include "binaryTree.h"

Node* createNode(int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insertNode(Node* root, Node* toInsert) {
  if (root == NULL || toInsert == NULL) return;

  if (toInsert->data >= root->data) {
    if (root->right != NULL) {
      insertNode(root->right, toInsert);
    } else {
      root->right = toInsert;
    }
  } else if (toInsert->data < root->data) {
    if (root->left != NULL) {
      insertNode(root->left, toInsert);
    } else {
      root->left = toInsert;
    }
  }
}

void printPostorder(Node* root) {
  if (root == NULL) return;

  printPostorder(root->left);
  printPostorder(root->right);
  printf("%d", root->data);
}

void printPreorder(Node* root) {
  if (root == NULL) return;

  printf("%d", root->data);
  printPreorder(root->left);
  printPreorder(root->right);
}

void printInorder(Node* root) {
  if (root == NULL) return;

  printInorder(root->left);
  printf("%d", root->data);
  printInorder(root->right);
}

int size(Node* root){
  if(root == NULL) return 0;

  int num = 1;
  num += size(root->left);
  num += size(root->right);

  return num;
}

void freeTree(Node* root){
  if(root == NULL) return;

  freeTree(root->left);
  freeTree(root->right);

  free(root);
}
