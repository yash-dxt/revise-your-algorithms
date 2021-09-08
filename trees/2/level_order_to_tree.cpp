// This works only when it is mentioned a tree is balanced.
// Line 32 is to be optimized.

//Node of a binary tree.

#include <queue>

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
    }
};

Node *bstFromLevelOrder(int arr[], int size)
{
    if (size == 0)
        return NULL;
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);

    int i = 1;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (i < size)
        {
            Node *left = new Node(arr[i++]);
            q.push(left);
            curr->left = left;
        }
        if (i < size)
        {
            Node *right = new Node(arr[i++]);
            q.push(right);
            curr->right = right;
        }
    }

    return root;
}