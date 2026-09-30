/*
Problem B: Rock Game
Topic: Max-Heap (Priority Queue) + Simulation
The problem explicitly requires taking the two heaviest rocks every turn, so use a max-heap.
Input
6
2 7 4 1 8 1
Output
1
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> q;
    while (n--) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        if (a != b) q.push(a - b);
    }
    cout << (q.empty() ? 0 : q.top());
}
