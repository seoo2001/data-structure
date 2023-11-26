#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max(a,b) ( (a>b) ? a : b )
#define N 10
typedef int element;

typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* makeNode(element data) {
    //TreeNode*를 반환
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    node->key = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preOrder(TreeNode* root) {
    if (root != NULL)
    {
        preOrder(root->left);      //L
        printf("[%d] ", root->key);//V
        preOrder(root->right);      //R
    }
}

TreeNode* insertNode(TreeNode* root, element key) {
    if (root == NULL) return makeNode(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}

int get_height(TreeNode* node) {     
    int height = 0;
    if(node != NULL) {
        height = 1 + max(get_height(node->left), get_height(node->right));
        return height;
    }
}

int get_leaf_count(TreeNode* node) {
    int count = 0;
    if (node!=NULL) {
        if (node->left == NULL && node->right == NULL) return 1;           
        else {
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
        }
        return count;
    }
}

TreeNode* minValueNode(TreeNode *node) {
    TreeNode* current = node;
    while (current->left!=NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode *root, element key) {
    if (root == NULL) return makeNode(key);
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if(root->left==NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right==NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        } else {
            TreeNode *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}


int main(void) {
    TreeNode* root = NULL;
    srand(time(NULL));

//    for (int i = 0; i < 15; i++) root = insertNode(root, rand() % 50);
    root = insertNode(root, 35);
    root = insertNode(root, 68);
    root = insertNode(root, 99);
    root = insertNode(root, 18);
    root = insertNode(root,  7);
    root = insertNode(root,  3);
    root = insertNode(root, 12);
    root = insertNode(root, 26);
    root = insertNode(root, 22);
    root = insertNode(root, 30);

    preOrder(root); printf("\n");
    root = deleteNode(root, 30); preOrder(root); printf("\n");
    root = deleteNode(root, 22); preOrder(root); printf("\n");

   return 0;
}