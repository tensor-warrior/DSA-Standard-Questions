// Construct a binary tree in inorder fashion. We can construct a binary
// tree only when inorder traversal is given and one more traversal is given.

// The logic is to use the preorder array for determining nodes and inorder
// array to determine what lies in the left and right subtrees to this node.

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

int pre_index = 0;
Node* construct_tree(int pre[], int in[], int in_start, int in_end) {
    if(in_start > in_end)
        return nullptr;

    Node *root = new Node(pre[pre_index]);
    pre_index++;

    int in_index = 0;
    for(int i = in_start; i <= in_end; i++) {
        if(root->data == in[i]) {
            in_index = i;
            break;
        }
    }

    root->left = construct_tree(pre, in, in_start, in_index-1);
    root->right = construct_tree(pre, in, in_index+1, in_end);

    return root;
}

void inorder(Node *node) {
    if(node == nullptr)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node *node) {
    if(node == nullptr)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main(void) {
    // convert in[] into hash for O(n) time
    // The current time complexity is O(n^2)
    int in[] = {40, 20, 50, 10, 30, 80, 70, 90};
    int pre[] = {10, 20, 40, 50, 30, 70, 80, 90};

    int n = sizeof(in)/sizeof(in[0]);

    Node *root = construct_tree(pre, in, 0, n-1);

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    return 0;
}