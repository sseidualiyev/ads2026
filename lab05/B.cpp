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
/*
----------------------------------------------------------------------------------------------------------------------------------------------------------
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
        if(s != i) {swap(a[s], a[i]); heapify(s);}
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
    int n; cin >> n;
    heap h;
    while(n--) {long long x; cin >> x; h.push(x);}
    while(h.size() > 1) {
        long long x = h.pop();
        long long y = h.pop();
        if(x != y) h.push(x - y);
    }
    if(h.size() == 1) cout << h.pop();
    else cout << 0;
}
