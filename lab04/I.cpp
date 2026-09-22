/*
Problem I: find leaves in bst (nodes which have no children).
*/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);

    if (value < root->val) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);

    return root;
}

int countLeaves(Node* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr) return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << countLeaves(root) << '\n';

    return 0;
}
