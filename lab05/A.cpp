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
/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<long long> a;
    void heapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;
        if(l < a.size() && a[l] < a[s]) s = l;
        if(r < a.size() && a[r] < a[s]) s = r;
        if(s != i) { swap(a[i], a[s]); heapify(s); }
    }
    void push(long long x) {
        a.push_back(x);
        int i = a.size() - 1;
        while(i > 0) {
            int p = (i - 1) / 2;
            if(a[p] <= a[i]) break;
            swap(a[p], a[i]);
            i = p;
        }
    }
    long long pop() {
        long long x = a[0];
        a[0] = a.back();
        a.pop_back();
        if(!a.empty()) heapify(0);
        return x;
    }
    int size() { return a.size(); }
};
int main() {
    int n; cin >> n;
    Heap h;
    while(n--) {long long x; cin >> x; h.push(x);}
    long long ans = 0;
    while(h.size() > 1) {
        long long x = h.pop();
        long long y = h.pop();
        long long sum = x + y;
        ans += sum;
        h.push(sum);
    }
    cout << ans;
}
