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
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    int currSum = head->val;
    int maxSum = head->val;

    Node* curr = head->next;

    while (curr) {
        currSum = max(curr->val, currSum + curr->val);
        maxSum = max(maxSum, currSum);
        curr = curr->next;
    }

    cout << maxSum << '\n';
}
