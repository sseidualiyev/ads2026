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
// 1. NODE STRUCTURE: The BST Building Block
struct Node {
    int val;
    Node* left;
    Node* right;

    // Constructor: Initializes a new node with a value and null children
    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// 2. OPTIMIZED INSERT (Iterative)
// Passed 'root' by reference (Node*&) so modifications persist without returning it.
void insert(Node*& root, int value) {
    // Base Case: If the tree is entirely empty, initialize the root
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node* current = root;
    
    // Traverse down the tree until we find an empty leaf spot
    while (true) {
        if (value <= current->val) { 
            // RULE 1: Smaller or equal values go LEFT
            if (current->left == nullptr) {
                current->left = new Node(value);
                break; // Node safely inserted, exit the loop
            }
            current = current->left; // Move pointer down left
            
        } else {                     
            // RULE 2: Strictly greater values go RIGHT
            if (current->right == nullptr) {
                current->right = new Node(value);
                break; // Node safely inserted, exit the loop
            }
            current = current->right; // Move pointer down right
        }
    }
}

// 3. PATH VERIFIER
bool checkPath(Node* root, const string& path) {
    Node* current = root;

    for (char direction : path) {
        // If we hit a dead end before the string finishes, the path is invalid
        if (current == nullptr) {
            return false;
        }

        // Shift the pointer based on the character instruction
        if (direction == 'L') {
            current = current->left;
        } else if (direction == 'R') { // Explicit 'R' check adds safety
            current = current->right;
        }
    }

    // If the loop finishes and current is NOT null, the node exists
    return current != nullptr;
}

int main() {
    // OPTIMIZATION: Fast I/O for massive datasets
    // This disconnects C and C++ standard streams, making cin/cout much faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    // Good practice: ensure variables are successfully read before proceeding
    if (!(cin >> n >> m)) return 0; 

    Node* root = nullptr;

    // Phase 1: Build the Binary Search Tree
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x); // Root is modified directly because of Node*&
    }

    // Phase 2: Traverse and Verify Paths
    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;

        if (checkPath(root, path)) {
            cout << "YES\n"; // '\n' is significantly faster than 'endl'
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
