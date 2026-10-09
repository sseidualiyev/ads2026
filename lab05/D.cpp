/*
Problem D: Experiment with Mixtures
Topic: Min-Heap (Priority Queue) + Greedy Simulation
This is essentially the same pattern as Problem A, but instead of minimizing a total cost,
we repeatedly combine the two smallest densities until the smallest one reaches the target.
Input
3 10
1 1 1
Output
-1
Input
6 7
1 2 3 9 10 12
Output
2
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    while (n--) {
        long long x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.top() < k) {
        if (q.size() < 2) {
            cout << -1;
            return 0;
        }
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        q.push(a + 2 * b);
        ans++;
    }
    cout << ans;
}
/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;

struct heap {
    vector<long long> a;
    void heapify(int i) {
        int l = 2 * i + 1, r = 2 * i + 2;
        int s = i;
        if(l < a.size() && a[l] < a[s]) s = l;
        if(r < a.size() && a[r] < a[s]) s = r;
        if(s != i) {swap(a[i], a[s]); heapify(s);}
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
    int size() {return a.size();}
};
int main() {
    int n;
    long long k;
    cin >> n >> k;
    heap h;
    while(n--) {long long x; cin >> x; h.push(x);}
    int ans = 0;
    while(h.size() > 0 && h.a[0] < k) {
        if(h.size() < 2) {
            cout << -1; return 0;
        }
        long long a = h.pop();
        long long b = h.pop();
        h.push(a + 2 * b);
        ans++;
    }
    cout << ans;
}
