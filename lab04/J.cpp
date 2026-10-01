/*
Problem J: K-th element in Binary Search Tree
BST and Inorder traversal. Find the K-th smallest element in sorted array.
Input
7 3
20 8 22 4 12 10 14
Output
10
Input
7 5
20 8 22 4 12 10 14
Output
14
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int v; Node *l, *r;
    Node(int x) : v(x), l(0), r(0) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->v) root->l = insert(root->l, x);
    else root->r = insert(root->r, x);
    return root;
}

void kth(Node* root, int k, int& cnt, int& ans) {
    if (!root) return;
    kth(root->l, k, cnt, ans);
    if (++cnt == k) {
        ans = root->v;
        return;
    }
    kth(root->r, k, cnt, ans);
}

int main() {
    int n, k; cin >> n >> k;
    if (k > n) { cout << -1; return 0; }
    Node* root = 0;
    while (n--) {
        int x; cin >> x;
        root = insert(root, x);
    }
    int cnt = 0, ans = -1;
    kth(root, k, cnt, ans);
    cout << ans;
}
