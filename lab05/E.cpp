/*
Problem E: K-th sum
Topic: Min-Heap + Maintaining Top K Elements
You need the sum of the K largest inserted values, but you don't need to store everything.
Keep exactly the current K largest values in a min-heap:
If heap has fewer than k → insert.
Otherwise, if new value is larger than the smallest in the heap → replace it.
sum is always the answer.
Input
6 4
print
insert 9
insert 6
print
insert 10
print
Output
0
15
25
Input
7 2
insert 2
insert 6
insert 3
print
print
insert 1
print
Output
9
9
9
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long sum = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "insert") {
            long long x;
            cin >> x;
            if (q.size() < k) {
                q.push(x);
                sum += x;
            } else if (x > q.top()) {
                sum += x - q.top();
                q.pop();
                q.push(x);
            }
        } else {
            cout << sum << '\n';
        }
    }
}
