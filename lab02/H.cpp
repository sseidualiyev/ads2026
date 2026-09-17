/*
Problem H: Ragnarok
Input format
The first line contains one integer n — the number of days in the chronicle.
The second line contains n integers a1,an — the days in the order they are stored in the list, from its head to its tail.

Output format
Print one integer — the largest sum over all non-empty runs of consecutive days.
Examples
Input
5
1 2 -1 4 5
Output
11
Input
3
-1 -1 -1
Output
-1
Input
10
5 1 2 -10 5 3 9 -5 10 10
Output
32
Notes
In the first example the best run is the whole chronicle: 1+2-1+4+5 = 11.
In the second example every day is bad, so the best you can do is take a single day: -1. Note that the run must be non-empty — the answer is never 0 here.
In the third example the best run is 5+3+9-5+10+10 = 32.
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm> // Required for std::max
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int main() {
    int n, val;
    if (!(cin >> n) || n <= 0) return 0;

    // PHASE 1: Build the linked list
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    // PHASE 2: Core Logic - Kadane's Algorithm
    int currSum = head->val;
    int maxSum = head->val;
    Node* curr = head->next;

    while (curr != nullptr) {
        // 1. Should we add to the existing sum, or start fresh from the current node?
        currSum = max(curr->val, currSum + curr->val); 
        
        // 2. Is this new sum the biggest we've seen so far?
        maxSum = max(maxSum, currSum);                 
        
        curr = curr->next;
    }

    // PHASE 3: Print result and clean up memory
    cout << maxSum << "\n";

    curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp; // Free memory to prevent leaks
    }

    return 0;
}
