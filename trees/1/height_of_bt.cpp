#include <iostream>
#include <algorithm>

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

int heightOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSize = heightOfBinaryTree(root->left);
    int rightSize = heightOfBinaryTree(root->right);

    return 1 + max(leftSize, rightSize);
}
