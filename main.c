#include "binaryTree.h"

int main(int argc, char* argv[]) {
  //Read in the file
  FILE* fp = NULL;
  fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("Error: file name invalid or not entered\nProgram terminating\n");
    return 0;
  }
  fseek(fp, 0, SEEK_END);
  int fileEnd = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char rootStr[10];
  int num;
  fgets(rootStr, 10, fp);
  num = atoi(rootStr);

  Node* root = createNode(num);

  while(ftell(fp) != fileEnd){
    char tempStr[10];
    fgets(tempStr, 10, fp);
    num = atoi(tempStr);
    Node* n = createNode(num);
    insert(root, n);
  }

  printPostorder(root);
  printf("\n");
  printInorder(root);
  printf("\n");
  printPreorder(root);

  int numNodes = size(root);
  printf("\nNumber of nodes: %d\n", numNodes);

  freeTree(root);
  fclose(fp);
  return 0;
}
