// DFS: Recursive Postorder traversal -> left, right, root

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

void postorder_traversal_recursive(Node *node) {
    if(node == nullptr)
        return;

    postorder_traversal_recursive(node->left);
    postorder_traversal_recursive(node->right);
    cout << node->data << " ";
}

int main(void) {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    postorder_traversal_recursive(root);
    cout << endl;

    return 0;
}