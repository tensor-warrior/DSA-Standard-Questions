// Print nodes at k distance from the root node.
// It's same as printing the kth level of the tree.

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

void nodes_at_k_distance(Node *node, int k) {
    if(node == nullptr)
        return;

    if(k == 0) {
        cout << node->data << " ";
    }
    else {
        nodes_at_k_distance(node->left, k-1);
        nodes_at_k_distance(node->right, k-1);
    }
}

int main(void) {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    nodes_at_k_distance(root, 2);
    cout << endl;

    return 0;
}