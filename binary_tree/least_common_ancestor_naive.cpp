// Given a binary tree and two nodes, we are required to find their least common ancestor
// The idea here is to find the path of both the nodes and then the last common element is the LCA.
// This solution traverses the tree three time and is Theta(n) in space and time.

#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

bool find_path(Node *root, vector<Node*> &p, int n) {
    if(root == NULL)
        return false;

    p.push_back(root);
    if(root->key == n)
        return true;

    if(find_path(root->left, p, n) || find_path(root->right, p, n))
        return true;

    p.pop_back();
    return false;
}

Node *lca(Node *root, int n1, int n2) {
    vector<Node*> path1, path2;

    if(find_path(root, path1, n1) == false|| find_path(root, path2, n2) == false)
        return nullptr;

    for(int i = 0; i < path1.size()-1 && i < path2.size()-1; i++)
        if(path1[i+1] != path2[i+1])
            return path1[i];

    return nullptr;
}

int main() {
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);

	int n1 = 20, n2 = 50;

	Node *ans = lca(root, n1, n2);
	cout << ans->key << endl;

    return 0;
}