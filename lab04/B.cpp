/*
Problem B: get subtree
The main concept is finding a node in a BST and then counting all nodes below it.
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

// 2. OPTIMIZED INSERT (Iterative)
void insert(Node*& root, int value) {
    // Base Case: First element becomes the root
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node* current = root;
    
    // Traverse until we find an empty leaf position
    while (true) {
        if (value < current->val) {
            // RULE 1: Strictly smaller values go LEFT
            if (current->left == nullptr) {
                current->left = new Node(value);
                break; 
            }
            current = current->left;
            
        } else {
            // RULE 2: Greater or equal values go RIGHT
            if (current->right == nullptr) {
                current->right = new Node(value);
                break;
            }
            current = current->right;
        }
    }
}

// 3. OPTIMIZED FIND (Iterative)
Node* find(Node* root, int x) {
    Node* current = root;

    // Keep walking down the tree as long as we haven't hit a dead end
    while (current != nullptr) {
        if (current->val == x) {
            return current;     // Target found!
        } else if (x < current->val) {
            current = current->left;  // Target must be in the left branch
        } else {
            current = current->right; // Target must be in the right branch
        }
    }

    return nullptr; // Dead end reached, value doesn't exist
}

// 4. SUBTREE SIZE (Recursive DFS)
int subtreeSize(Node* root) {
    // Base Case: An empty node contributes 0 to the size
    if (root == nullptr) {
        return 0;
    }

    // Current node (1) + total nodes on the left + total nodes on the right
    return 1 + subtreeSize(root->left) + subtreeSize(root->right);
}

int main() {

    int n;
    cin >> n;

    Node* root = nullptr;

    // Phase 1: Build the BST
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    // Phase 2: Locate the target node
    int x;
    cin >> x;
    Node* target = find(root, x);

    // Phase 3: Calculate and print the size of the subtree at the target
    // Note: If find() returned nullptr, subtreeSize(nullptr) safely returns 0
    cout << subtreeSize(target) << "\n";

    return 0;
}
