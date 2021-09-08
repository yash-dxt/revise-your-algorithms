

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
// po: Preorder array
// l -> left, r -> right.

int currIndex; // 0 as it is pre order traversal.
Node *preOrderInorderToTree(int in[], int po[], int l, int r)
{
    if (l > r)
        return NULL;
    int elem = po[currIndex++];
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

    curr->left = preOrderInorderToTree(in, po, l, x - 1);
    curr->right = preOrderInorderToTree(in, po, x + 1, r);

    return curr;
}
