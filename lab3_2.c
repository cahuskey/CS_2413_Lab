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

void inorder(struct TreeNode* root, int* result, int* index) 
{
    if (root == NULL) return;

    inorder(root->left, result, index);
    result[(*index)++] = root->val;
    inorder(root->right, result, index);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* result = (int*)malloc(200 * sizeof(int)); // Fixed size
    *returnSize = 0;

    inorder(root, result, returnSize);
    return result;
}


int main() 
{
    
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
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
