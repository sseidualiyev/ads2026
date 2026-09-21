/*
Problem C: find node and print subtree nodes
*/
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    // Walk down the tree to find the correct empty leaf
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

    // Traverse downwards like a standard binary search
    while (current != nullptr) {
        if (current->val == x) return current;     // Target found!
        else if (x < current->val) current = current->left;  // Search left
        else current = current->right; // Search right
    }
    return nullptr; // Dead end, value does not exist
}

// 4. PREORDER TRAVERSAL (NLR: Node, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Step 1: Process the current NODE
    cout << root->val << " ";
    // Step 2: Recursively traverse the LEFT branch
    preorder(root->left);
    // Step 3: Recursively traverse the RIGHT branch
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    // Phase 1: Build the tree
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    // Phase 2: Find the target subtree
    int target;
    cin >> target;
    Node* targetNode = find(root, target);

    // Phase 3: Print the preorder traversal starting from the target
    // Note: Always safe-guard against printing from a null pointer
    if (targetNode != nullptr) {
        preorder(targetNode);
        cout << "\n";
    }
    return 0;
}
