/*

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
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void countTriangles(Node* root, int& answer) {
    if (root == nullptr) {
        return;
    }

    // Current node has both children
    if (root->left != nullptr && root->right != nullptr) {
        answer++;
    }

    countTriangles(root->left, answer);
    countTriangles(root->right, answer);
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

    countTriangles(root, answer);

    cout << answer << '\n';

    return 0;
}
