// Print left view of a tree recursively

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

int max_level = 0;
void left_view(Node *node, int level) {
    if(node == nullptr)
        return;

    if(max_level < level) {
        cout << node->data << " ";
        max_level = level;
    }

    left_view(node->left, level+1);
    left_view(node->right, level+1);
}

int main(void) {
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->left->right = new Node(8);

    left_view(root, 1);
    cout << endl;

    return 0;
}