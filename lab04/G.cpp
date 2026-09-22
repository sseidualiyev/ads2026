/*
Problem G: diameter of the tree (find the maximum distance between any two vertices).
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>

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
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->val) {
        root->right = insert(root->right, value);
    }
    // Equal values are ignored
    return root;
}

int getHeight(Node* root, int& answer) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left, answer);
    int rightHeight = getHeight(root->right, answer);
    // Longest path passing through this node
    int currentDistance = leftHeight + 1 + rightHeight;

    answer = max(answer, currentDistance);
    // Height of this subtree
    return 1 + max(leftHeight, rightHeight);
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

    int answer = 0;

    getHeight(root, answer);

    cout << answer << '\n';

    return 0;
}
