/*
Problem C: Standard problem about soccer
Topic: Greedy Algorithm + Max-Heap (Priority Queue)
If a row has k free seats, the next ticket costs k. After selling it, that row has k-1 seats, so its next ticket costs k-1.
Input
3 10
6 8 9
Output
67
Input
1 2
5
Output
9
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<long long> q;
    while (n--) {
        long long x;
        cin >> x;
        q.push(x);
    }
    long long ans = 0;
    while (m--) {
        long long x = q.top(); q.pop();
        ans += x;
        if (x > 1) q.push(x - 1);
    }
    cout << ans;
}
