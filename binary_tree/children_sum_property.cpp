// Check if every node in a tree is sum of it's child nodes
// This is called child sum property

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

bool children_sum_property(Node *node) {
    if(node == nullptr)
        return true;

    if((node->left == nullptr) && (node->right == nullptr))
        return true;

    int sum = 0;
    
    if(node->left != nullptr)
        sum += node->left->data;

    if(node->right != nullptr)
        sum == node->right->data;

    return (node->data == sum) && (children_sum_property(node->left)) && (children_sum_property(node->right));
}

int main(void) {
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(2);

    bool res = children_sum_property(root);

    cout << boolalpha;
    cout << res << endl;

    return 0;
}