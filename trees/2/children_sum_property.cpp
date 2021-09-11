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

bool childrenSumProperty(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL || root->right == NULL)
        return true;

    int sum = 0;

    if (root->left != NULL)
        sum += root->left->data;
    if (root->right != NULL)
        sum += root->right->data;

    return sum == root->data && childrenSumProperty(root->left) && childrenSumProperty(root->right);
}