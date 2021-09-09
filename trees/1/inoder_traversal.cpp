#include <iostream>
#include <stack>

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

void InOrderTraversalRecursive(Node *root)
{
    if (root == NULL)
        return;
    InOrderTraversalRecursive(root->left);
    cout << root->data;
    InOrderTraversalRecursive(root->right);
}

void InOrderIterative(Node *root)
{
    Node *curr = root;
    stack<Node *> s;

    while (!s.empty() || curr != NULL)
    {

        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << (curr->data);

        curr = curr->right;
    }
}