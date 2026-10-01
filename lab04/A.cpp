/*
Problem A: Mountains Binary Search Tree
1. What the problem is asking
First, we build the BST from the given numbers in the exact order.
For the example:
7 10 12 8 5 6 2 1 4
Because equal values go to the left, insertion works like:
smaller → left
greater → right
equal → left
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
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

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node* current = root;
    
    while (true) {
        if (value <= current->val) { 
            if (current->left == nullptr) {
                current->left = new Node(value);
                break; 
            }
            current = current->left;
            
        } else {                     
            if (current->right == nullptr) {
                current->right = new Node(value);
                break;
            }
            current = current->right;
        }
    }
}

bool checkPath(Node* root, const string& path) {
    Node* current = root;

    for (char direction : path) {
        if (current == nullptr) return false;
        if (direction == 'L') current = current->left;
        else if (direction == 'R') current = current->right;
    }
    return current != nullptr;
}

int main() {
    int n, m;
    cin >> n >> m; 

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }
    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;
        if (checkPath(root, path)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
