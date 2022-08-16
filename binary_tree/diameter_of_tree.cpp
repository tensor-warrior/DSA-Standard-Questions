/*
The diameter of a tree (sometimes called the width) is the number of nodes on
the longest path between two end nodes. To calculate it, we can find the value
of (1 + lh + rh) of every node and then the greatest among them will be the
diameter. Here lh is the height of left subtree with the given node and rh is
the height of the right subtree.

We can modify the height function to calculate the diameter at a given node and
keep track of it's value to efficiently find the diameter of tree in O(1) time and
O(1) auxillary space (not counting the recursion overhead).
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int res = 0; // this will store the diameter
int height(Node *node) {
    if(!node)
        return 0;

    int lh = height(node->left);
    int rh = height(node->right);

    res = max(res, 1 + lh + rh); // keeping track of diameter at each node

    return 1 + max(lh, rh);
}

int main(void) {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->right = new Node(80);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->right->right = new Node(90);
    root->left->left->left->left = new Node(60);
    root->left->right->right->right = new Node(18);

    height(root); // height of tree is discarded.
    cout << res << endl;

    return 0;
}