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

void printAtLevelK(Node *root, int level, int k = 0)
{
    if (root == NULL)
        return;
    if (level == k)
    {
        cout << root->data;
        return;
    }
    printAtLevelK(root->left, level, k + 1);
    printAtLevelK(root->right, level, k + 1);
}