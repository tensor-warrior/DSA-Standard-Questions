// Size of a binary tree is the total number of nodes in it.

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

int size_of_tree(Node *node) {
    if(node == nullptr)
        return 0;
    else
        return 1 + size_of_tree(node->left) + size_of_tree(node->right);
}

int main(void) {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left= new Node(6);
    root->right->right = new Node(7);

    int res = size_of_tree(root);
    cout << res << endl;

    return 0;
}