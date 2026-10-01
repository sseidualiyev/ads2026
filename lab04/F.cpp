/*
Problem F: Triangle search binary tree. 
Need to find the smallest triangle (node with both children )
Input
3
2 3 1
Output
1
Input
3
1 2 3
Output
0
Input
16
13 9 3 7 6 16 1 11 12 10 4 2 14 5 8 15
Output
5
*/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

int count(Node* root) {
    if (!root) return 0;
    return (root->l && root->r) + count(root->l) + count(root->r);
}

int main() {
    int n; cin >> n;
    Node* root = 0;
    while (n--) {
        int x; cin >> x;
        root = insert(root, x);
    }
    cout << count(root);
}
