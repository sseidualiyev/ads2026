/*
Problem H: Greater Sum Tree. Use BST to calculate suffix sum.
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
    if (root == nullptr)
        return new Node(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void greaterSum(Node* root, long long& sum) {
    if (root == nullptr)
        return;

    // Larger values first
    greaterSum(root->right, sum);

    // Add current value
    sum += root->val;
    root->val = sum;

    // Smaller values afterwards
    greaterSum(root->left, sum);
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
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

    long long sum = 0;

    greaterSum(root, sum);

    inorder(root);

    cout << '\n';

    return 0;
}
