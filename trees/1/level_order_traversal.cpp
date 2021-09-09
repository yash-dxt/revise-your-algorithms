#include <iostream>
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

void levelOrderTraversalLineByLine(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int n = q.size();

        for (int i = 0; i < n; i++)
        {

            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }
}
