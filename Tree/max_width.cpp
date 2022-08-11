// Find the maximum width of a binary tree. Width of a level is the
// total number of nodes at that level.

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

int max_width(Node *node) {
    if(node == nullptr)
        return 0;

    queue<Node*> nodes;
    nodes.push(node);

    int res = -1;
    while(nodes.empty() == false) {
        int n = nodes.size();
        res = max(res, n);

        for(int i {}; i < n; i++) {
            node = nodes.front();
            nodes.pop();

            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
        }
    }

    return res;
}

int main(void) {
    Node *root = nullptr;

    int res = max_width(root);
    cout << res << endl;

    return 0;
}