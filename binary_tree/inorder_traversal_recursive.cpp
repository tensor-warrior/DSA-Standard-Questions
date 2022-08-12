// DFS: Recursive Inorder traversal -> left, root, right

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

void inorder_traversal_recursive(Node *node) {
    if(node == nullptr)
        return;

    inorder_traversal_recursive(node->left);
    cout << node->data << " ";
    inorder_traversal_recursive(node->right);
}

int main(void) {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    inorder_traversal_recursive(root);
    cout << endl;

    return 0;
}