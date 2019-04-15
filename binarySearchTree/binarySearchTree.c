#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} node;

node *newNode(int item)
{
  node *bst_node = (node *)malloc(sizeof(node));
  bst_node->value = item;
  bst_node->left = NULL;
  bst_node->right = NULL;
  return bst_node;
}

void printInOrder(node *root)
{
  if (root != NULL)
  {
    printInOrder(root->left);
    printf("%d \n", root->value);
    printInOrder(root->right);
  }
}

node *insert(node *node, int item)
{
  if (node == NULL)
  {
    return newNode(item);
  }

  if (item < node->value)
  {
    node->left = insert(node->left, item);
  }
  else
  {
    node->right = insert(node->right, item);
  }

  return node;
}

int main(int argc, char *argv[])
{
  node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printInOrder(root);

  return 0;
}