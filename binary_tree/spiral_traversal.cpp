/*
Perform a spiral traversal on a binary tree. In spiral traversal, the first level
prints from left to right, second level prints from right to left, third prints from
right to left and so on until all the levels of tree are traversed.

Steps to perform a spiral traversal:
1. Create two stacks - s1 and s2 - and push the root node in s1.
2. While any of the two stacks is not empty:
    a. While s1 is not empty
        -> Take out a node and print it.
        -> Push children of the taken out node in s2 (left first and then right)
    b. While s2 is not empty
        -> Take out a node and print it.
        -> Push children of the taken out node into s1 in reverse order (first right and then left)
*/

#include<iostream>
#include<stack>
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

void spiral_traversal(Node *node) {
    if(node == nullptr)
        return;

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(node);

    while(!s1.empty() || !s2.empty()) {
        while(!s1.empty()) {
            node = s1.top();
            s1.pop();

            cout << node->data << " ";

            if(node->left)
                s2.push(node->left);
            if(node->right)
                s2.push(node->right);
        }

        while(!s2.empty()) {
            node = s2.top();
            s2.pop();

            cout << node->data << " ";

            if(node->right)
                s1.push(node->right);
            if(node->left)
                s1.push(node->left);
        }
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

    spiral_traversal(root);
    
    return 0;
}