// Convert a tree into a doubly linkedlist in an inorder fashion.

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

Node *prev_node = nullptr;
Node* tree_to_dll(Node *node) {
    if(node == nullptr)
        return nullptr;

    Node *head = tree_to_dll(node->left);
    if(prev_node == nullptr) {
        head = node;
    }
    else {
        node->left = prev_node;
        prev_node->right = node;
    }

    prev_node = node;
    tree_to_dll(node->right);

    return head;
}

int main(void) {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    Node *head = tree_to_dll(root);

    Node *node = head;
    do {
        cout << node->data << " ";
        node = node->right;
    } while(node != nullptr);

    return 0;
}