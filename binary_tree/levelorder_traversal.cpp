// BFS: Print every node of the tree level-wise.

#include<iostream>
#include<queue>
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

void levelorder_traversal(Node *node) {
    if(node == nullptr)
        return;

    queue<Node*> nodes;
    nodes.push(node);

    while(nodes.empty() == false) {
        node = nodes.front();
        nodes.pop();

        cout << node->data << " ";

        if(node->left != nullptr)
            nodes.push(node->left);
        if(node->right != nullptr)
            nodes.push(node->right);
    }
}

int main(void) {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left= new Node(6);
    root->right->right = new Node(7);

    levelorder_traversal(root);
    cout << endl;

    return 0;
}