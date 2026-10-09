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
        if(l < a.size() && a[l] > a[s]) s = l;
        if(r < a.size() && a[r] > a[s]) s = r;
        if(s != i) {swap(a[i], a[s]); heapify(s);}
    }
    void push(long long x) {
        a.push_back(x);
        int i = a.size() - 1;
        while(i > 0) {
            int p = (i - 1) / 2;
            if(a[p] >= a[i]) break;
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
    int n, m; cin >> n >> m;
    heap h;
    while(n--) {long long x; cin >> x; h.push(x);}
    long long ans = 0;
    while(m--) {
        long long x = h.pop();
        ans += x;
        if(x > 1) h.push(x-1);
    }
    cout << ans;
}
