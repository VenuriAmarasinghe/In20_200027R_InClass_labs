#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//creates a new node
struct node *newNode(int item){ 
   struct node *t = (struct node *)malloc(sizeof(struct node));
   t->key = item;
   t->left = NULL;
   t->right = NULL;
   return t;
}

//finds the minimum value node in the tree
struct node* minNode(struct node* node)
{
    struct node*t = node; 
    while (t && t->left != NULL)
        t = t->left;
    return t;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key <<" ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insertNode(node->left, key);
      else 
         node->right = insertNode(node->right, key);
   return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) // if the tree is empty
        return root;

    if (key < root->key) // if the key to be deleted is smaller than the root's key, then it lies in left subtree
        root->left = deleteNode(root->left, key);
        
    else if (key > root->key) // if the key to be deleted is greater than the root's key, then it lies in right subtree
        root->right = deleteNode(root->right, key);

    else {// if key is same as root's key, then this is the node to be deleted
        if (root->left == NULL and root->right == NULL)
            return NULL;
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}