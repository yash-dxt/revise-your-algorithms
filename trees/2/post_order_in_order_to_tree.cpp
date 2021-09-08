

#include <vector>

using namespace std;

//Node of a binary tree.
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

// in : Inorder array
// po: Postorder array
// l -> left, r -> right.

int currIndex; // Size of array - 1 --> Post order has the first element at the last.
Node *postOrderInorderToTree(int in[], int po[], int l, int r)
{
    if (l > r)
        return NULL;
    int elem = po[currIndex--];
    Node *curr = new Node(elem);

    int x;
    for (int i = l; i < r; i++)
    {
        if (in[i] == elem)
        {
            x = i;
            break;
        }
    }

    curr->right = postOrderInorderToTree(in, po, x + 1, r);
    curr->left = postOrderInorderToTree(in, po, l, x - 1);

    return curr;
}
