/*
Problem E: given BST, find vertices on each level and find maximum. USE BFS and queue.
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> left(n + 1, 0);
    vector<int> right(n + 1, 0);

    // Build the tree
    for (int i = 0; i < n - 1; i++) {
        int parent, child, side;
        cin >> parent >> child >> side;

        if (side == 0) {
            left[parent] = child;
        } else {
            right[parent] = child;
        }
    }

    queue<int> q;
    q.push(1);

    int maxWidth = 0;

    while (!q.empty()) {
        // Number of vertices on the current level
        int levelSize = q.size();

        // Update maximum width
        if (levelSize > maxWidth) {
            maxWidth = levelSize;
        }

        // Process the current level
        for (int i = 0; i < levelSize; i++) {
            int current = q.front();
            q.pop();

            if (left[current] != 0) {
                q.push(left[current]);
            }

            if (right[current] != 0) {
                q.push(right[current]);
            }
        }
    }

    cout << maxWidth << '\n';

    return 0;
}
