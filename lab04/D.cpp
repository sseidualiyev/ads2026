/*
Problem D: BST level/depth Level-Order Traversal BFS
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// 1. NODE STRUCTURE
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
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node* current = root;
    // Walk down to find the correct empty leaf position
    while (true) {
        if (value < current->val) {
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

    // Edge case: If the tree is completely empty
    if (root == nullptr) {
        cout << 0 << "\n";
        return 0;
    }

    // Phase 2: BFS (Level-Order Traversal)
    queue<Node*> q;
    q.push(root);

    vector<long long> sums;

    // Process the tree level by level
    while (!q.empty()) {
        // Snapshot the number of nodes currently in the queue
        // This exact number is the size of the CURRENT level
        int levelSize = q.size();
        long long levelSum = 0; // Use long long to prevent overflow

        // Only loop exactly 'levelSize' times to process just this level
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            levelSum += current->val; // Accumulate the sum for this level

            // Add the NEXT level's children to the back of the queue
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        // Store the completed level sum
        sums.push_back(levelSum);
    }

    // Phase 3: Print Results
    // The number of elements in the vector is exactly the number of levels
    cout << sums.size() << '\n';

    for (long long sum : sums) {
        cout << sum << ' ';
    }
    cout << '\n';

    return 0;
}
