/*
Problem G: Killua and Hunter exam
diameter of the tree (find the maximum distance between any two vertices).
Input
9
11 5 3 2 1 7 9 8 13
Output
7
Input
5
1 2 4 3 5
Output
4
Input
7
4 2 6 5 1 3 7
Output
5
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int v; Node *l, *r;
    Node(int x) : v(x), l(0), r(0) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->v) root->l = insert(root->l, x);
    else if (x > root->v) root->r = insert(root->r, x);
    return root;
}

int height(Node* root, int& ans) {
    if (!root) return 0;
    int l = height(root->l, ans);
    int r = height(root->r, ans);
    ans = max(ans, l + 1 + r);
    return 1 + max(l, r);
}

int main() {
    int n; cin >> n;
    Node* root = 0;

    while (n--) {
        int x; cin >> x;
        root = insert(root, x);
    }

    int ans = 0;
    height(root, ans);
    cout << ans;
}
