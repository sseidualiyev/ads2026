/*
Problem A: Optimizing program
Topic: Greedy algorithm + Min-Heap (Priority Queue)
The key idea is: always merge the two smallest arrays first. This minimizes how many times large arrays contribute to the total cost.
Input
4
6 5 3 9
Output
45
Input
10
42 18 63 26 19 15 11 29 26 24
Output
869
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    while (n--) {
        long long x;
        cin >> x;
        q.push(x);
    }
    long long ans = 0;
    while (q.size() > 1) {
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans;
}
