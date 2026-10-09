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
    int q, k;
    cin >> q >> k;
    priority_queue<long long, vector<long long>, greater<long long>> qq;
    long long sum = 0;
    while (q--) {
        string s;
        cin >> s;
        if (s == "insert") {
            long long x;
            cin >> x;
            if (qq.size() < k) {
                qq.push(x);
                sum += x;
            } else if (x > qq.top()) {
                sum += x - qq.top();
                qq.pop();
                qq.push(x);
            }
        } else {
            cout << sum << '\n';
        }
    }
}
/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        if(s != i) {swap(a[s], a[i]); heapify(s);}
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
    int q, k; cin >> q >> k;
    heap h;
    long long sum = 0;
    while(q--) {
        string cmd; cin >> cmd;
        if(cmd == "insert") {
            long long x; cin >> x;
            h.push(x);
            sum += x;
            if(h.size() > k) sum -= h.pop();
        } else cout << sum << '\n';
    }
}
