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
        left = right = NULL;
    }
};

int level = -1;
void printLeftView(Node *root, int curr = 0)
{
    if (root == NULL)
        return;

    if (curr > level)
    {
        level++;
        cout << root->data << " ";
    }

    printLeftView(root->left, curr + 1);
    printLeftView(root->right, curr + 1);
}

void printLeftViewIterative(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}