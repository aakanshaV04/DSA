#include <stdio.h>
#include <stdlib.h>
struct node {
   int data;
   struct node *leftChild, *rightChild;
};
struct node* newNode(int data){
   struct node* Node = (struct node*)malloc(sizeof(struct node));
   Node->data = data;
   Node->leftChild = Node->rightChild = NULL;
   return (Node);
}
struct node* rightRotate(struct node *x){
   struct node *y = x->leftChild;
   x->leftChild = y->rightChild;
   y->rightChild = x;
   return y;
}
struct node* leftRotate(struct node *x){
   struct node *y = x->rightChild;
   x->rightChild = y->leftChild;
   y->leftChild = x;
   return y;
}
struct node* splay(struct node *root, int data){
   if (root == NULL || root->data == data)
      return root;
   if (root->data > data) {
      if (root->leftChild == NULL) return root;
      if (root->leftChild->data > data) {
         root->leftChild->leftChild = splay(root->leftChild->leftChild, data);
         root = rightRotate(root);
      } else if (root->leftChild->data < data) {
         root->leftChild->rightChild = splay(root->leftChild->rightChild, data);
         if (root->leftChild->rightChild != NULL)
            root->leftChild = leftRotate(root->leftChild);
      }
      return (root->leftChild == NULL)? root: rightRotate(root);
   } else {
      if (root->rightChild == NULL) return root;
      if (root->rightChild->data > data) {
         root->rightChild->leftChild = splay(root->rightChild->leftChild, data);
         if (root->rightChild->leftChild != NULL)
            root->rightChild = rightRotate(root->rightChild);
      } else if (root->rightChild->data < data) {
         root->rightChild->rightChild = splay(root->rightChild->rightChild, data);
         root = leftRotate(root);
      }
      return (root->rightChild == NULL)? root: leftRotate(root);
   }
}
struct node* insert(struct node *root, int k){
   if (root == NULL) return newNode(k);
   root = splay(root, k);
   if (root->data == k) return root;
   struct node *newnode = newNode(k);
   if (root->data > k) {
      newnode->rightChild = root;
      newnode->leftChild = root->leftChild;
      root->leftChild = NULL;
   } else {
      newnode->leftChild = root;
      newnode->rightChild = root->rightChild;
      root->rightChild = NULL;
   }
   return newnode;
}
struct node* deletenode(struct node* root, int data){
   struct node* temp;
   if (root == NULL)
      return NULL;
   root = splay(root, data);
   if (data != root->data)
      return root;
   if (!root->leftChild) {
      temp = root;
      root = root->rightChild;
   } else {
      temp = root;
      root = splay(root->leftChild, data);
      root->rightChild = temp->rightChild;
   }
   free(temp);
   return root;
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->leftChild);
        int rheight = height(node->rightChild);
 
        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->leftChild, level - 1);
        printCurrentLevel(root->rightChild, level - 1);
    }
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
        printCurrentLevel(root, i);
        printf("\n");
    }
}


int main(){
   struct node* root = newNode(34);
   root = insert(root,15);
   root = insert(root,40);
   root = insert(root,12);
   root = insert(root,14);
   root = insert(root,59);
   printf("The Splay tree is \n");
   printLevelOrder(root);
   root = deletenode(root, 40);
   printf("\nThe Splay tree after deletion is \n");
   printLevelOrder(root);
   return 0;
}
