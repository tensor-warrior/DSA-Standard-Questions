// We need to find the node with the largest value

#include<iostream>
#include<climits>
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

int max_in_tree(Node *node) {
    if(node == nullptr)
        return INT_MIN;
    else
        return max(node->data, max(max_in_tree(node->left), max_in_tree(node->right)));
}

int main(void) {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int res = max_in_tree(root);
    cout << res << endl;

    return 0;
}