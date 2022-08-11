// Check If a tree is balanced or not. A tree is balanced if the difference
// between heights of left and right subtrees of any node is less or equal to 1.

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

int check_balanced_tree(Node *node) {
    if(node == nullptr)
        return 0;

    int lh = check_balanced_tree(node->left);
    if(lh == -1)
        return -1;

    int rh = check_balanced_tree(node->right);
    if(rh == -1)
        return -1;

    if(abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main(void) {
    Node *root = new Node(30);
    root->left = new Node(40);
    root->right = new Node(80);
    root->left->left = new Node(50);
    root->left->right = new Node(70);
    root->right->left = new Node(5);
    root->left->right->left = new Node(20);
    root->left->right->right = new Node(10);

    int res = check_balanced_tree(root);
    if(res >= 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}