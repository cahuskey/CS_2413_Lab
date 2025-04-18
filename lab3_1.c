#include <stdio.h>
#include <stdlib.h>


struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int val) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void preorder(struct TreeNode* root, int* result, int* index) 
{
    if (root == NULL) return;

    result[(*index)++] = root->val;      
    preorder(root->left, result, index); 
    preorder(root->right, result, index); 
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* result = (int*)malloc(200 * sizeof(int)); 
    *returnSize = 0;

    preorder(root, result, returnSize);
    return result;
}


int main() 
{
   
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize;
    int* result = preorderTraversal(root, &returnSize);

    printf("Preorder Traversal: ");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
