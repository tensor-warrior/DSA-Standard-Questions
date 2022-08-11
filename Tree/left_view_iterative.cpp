// Print left view of a tree iteratively

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

void left_view(Node *node) {
    if(node == nullptr)
        return;

    queue<Node*> nodes;
    nodes.push(node);

    while(nodes.empty() == false) {
        int n = nodes.size();

        for(int i {}; i < n; i++) {
            node = nodes.front();
            nodes.pop();

            if(i == 0)
                cout << node->data << " ";

            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
        }
    }
}

int main(void) {
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->left->right = new Node(8);

    left_view(root);
    cout << endl;

    return 0;
}