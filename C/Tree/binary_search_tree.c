#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct BstNode 
{
  int data;
  struct BstNode *left;
  struct BstNode *right;
};

struct BstNode* get_new_node(int data) {
   struct BstNode *temp = (struct BstNode*)malloc(sizeof(struct BstNode));
   temp->data = data;
   temp->left = temp->right = NULL;
   return temp;
}

struct BstNode* add_node(struct BstNode *root, int data) {
   struct BstNode *node = NULL;
   if(root == NULL) {
      root = get_new_node(data);
   } else if(data <= root->data) {
      root->left = add_node(root->left, data);
   } else {
      root->right = add_node(root->right, data);
   } 
   return root;
}

void search(struct BstNode *root, int data) {
  struct BstNode *temp = root;
  
  if(temp == NULL)
     return;

  if(data == temp->data){
     printf("Data found\n");
     return;
  }
    
  if(data <= temp->data) {
     search(temp->left, data);
  } else {
     search(temp->right, data);
  } 
}

/* in order traversal */
void tree_display(struct BstNode *root) {
  struct BstNode *temp = root; 
  if(root == NULL) {
      return;
   } 
 
  if(temp->left != NULL) {
      tree_display(temp->left);
      printf(" %d", temp->data);
      tree_display(temp->right);
   } else {
      printf(" %d", temp->data);
      tree_display(temp->right);
   }
}

int tree_height(struct BstNode *root) {
  int left, right, max = 0;
  if(root == NULL)
     return -1;
  left = tree_height(root->left);
  right = tree_height(root->right);
  if (left > right) 
     max = left + 1;
  else 
     max = right + 1; 
  return max;
}

int main(){
 struct BstNode *root = NULL;

  root = add_node(root, 10);
  root = add_node(root, 5);
  root = add_node(root, 15);
  root = add_node(root, 1);

  tree_display(root);
  printf("\nTree height=%d\n", tree_height(root));
  
 // search(root, 5);
  search(root, 115);

 return 0;
}
