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

int sizeOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSize = sizeOfBinaryTree(root->left);
    int rightSize = sizeOfBinaryTree(root->right);

    return leftSize + rightSize + 1;
}