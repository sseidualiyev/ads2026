/*
Problem J: BST and Inorder traversal. Find the K-th smallest element in sorted array.
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

void kthSmallest(Node* root, int k, int& count, int& answer) {
    if (root == nullptr) return;
    // Visit smaller values first
    kthSmallest(root->left, k, count, answer);
    // Visit current node
    count++;
    if (count == k) {
        answer = root->val;
        return;
    }
    // Visit larger values
    kthSmallest(root->right, k, count, answer);
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << -1 << '\n';
        return 0;
    }

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int count = 0;
    int answer = -1;

    kthSmallest(root, k, count, answer);

    cout << answer << '\n';

    return 0;
}
