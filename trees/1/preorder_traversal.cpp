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
        left = right = NULL;
    }
};

void PreOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PreOrderTraversalIt(Node *root)
{

    Node *curr = root;
    stack<Node *> s;

    while (!s.empty() || curr != NULL)
    {

        while (curr != NULL)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        curr = curr->right;
    }
}
