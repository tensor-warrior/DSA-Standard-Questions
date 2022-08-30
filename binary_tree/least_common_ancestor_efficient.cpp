/*
Given a binary tree and two nodes, we are required to find their least common ancestor.

The efficient solution:
1. Requires one traversal and Theta(n) extra space for the recursive traversal.
2. Assume that both n1 and n2 exist in the tree. Does not give correct result when only
   one of (n1 or n2) exits.

In efficient solution, we do normal recursive traversal and for each node have four cases:
1. If it is same n1 or n2 we return that node as the LCA.
2. If one of its subtree contains n1 and other contains n2 we return the current node as LCA
   because such a coondition happens only when a node is LCA.
3. If one its subtree contains both n1 and n2 then LCA must be present in this subtree only.
   Thus, we apply LCA on this subtree and return it's result.
4. If none of its subtrees contain any of n1 and n2 then the LCA is surely not present in
   any of its subtrees so we return NULL.
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// This returns the LCA node or nullptr under the assumption that LCA is present
Node* lca(Node *node, int n1, int n2) {
    if(node == nullptr)
        return nullptr;

    if(node->data == n1 || node->data == n2) // Case 1 and also helpful for Case 2
        return node;

    Node *lca1 = lca(node->left, n1, n2);
    Node *lca2 = lca(node->right, n1, n2);

    if(lca1 != nullptr && lca2 != nullptr) // Case 2
        return node;

    if(lca1 != nullptr) // Case 3 for left subtree
        return lca1;
    else // Case 3 for right subtree and Case 4 for both subtrees
        return lca2;
}

int main(void) {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    root->right->left->left = new Node(70);
    root->right->right->left = new Node(80);
    root->right->right->right = new Node(90);
    root->right->right->right->right = new Node(40);

    int n1 = 30, n2 = 60;
    Node *res = lca(root, n1, n2);

    cout << res->data << endl;

    return 0;
}