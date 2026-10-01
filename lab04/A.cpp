/*
Problem A: Mountains Binary Search Tree
First, we build the BST from the given numbers in the exact order.
Input
9 4
7 10 12 8 5 6 2 1 4
LLL
LRR
RL
RR
Output
YES
NO
YES
YES
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int v; Node *l, *r;
    Node(int x) : v(x), l(0), r(0) {}
};

void insert(Node*& root, int x) {
    if (!root) { root = new Node(x); return; }
    if (x <= root->v) insert(root->l, x);
    else insert(root->r, x);
}

bool path(Node* root, string s) {
    for (char c : s) {
        if (!root) return false;
        root = c == 'L' ? root->l : root->r;
    }
    return root != nullptr;
}

int main() {
    int n, m; cin >> n >> m;
    Node* root = 0;

    while (n--) { int x; cin >> x; insert(root, x); }

    while (m--) {
        string s; cin >> s;
        cout << (path(root, s) ? "YES\n" : "NO\n");
    }
}
