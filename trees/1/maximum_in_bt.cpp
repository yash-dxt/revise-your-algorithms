#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int maxInBinaryTree(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    int res = root->data;
    int left = maxInBinaryTree(root->left);
    int right = maxInBinaryTree(root->right);
    if (left > res)
    {
        res = left;
    }
    if (right > res)
    {
        res = right;
    }
    return res;
}