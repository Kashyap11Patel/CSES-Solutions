/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

struct segTree {

    int Size = 1;
    vector<int> Min;
    int Neutral_Element = (int)1e9;

    void init(int n) {
        while (Size < n) Size *= 2;
        Min.assign(2 * Size, Neutral_Element);
    }

    void build(vector<int>& in, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)in.size())
                Min[x] = in[lx];
            return;
        }

        int m = (rx + lx) >> 1;
        build(in, 2 * x + 1, lx, m);
        build(in, 2 * x + 2, m, rx);
        Min[x] = min(Min[2 * x + 1], Min[2 * x + 2]);
    }

    void build(vector<int>& in) {
        build(in, 0, 0, Size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return Neutral_Element;
        if (lx >= l && rx <= r) return Min[x];

        int m = (rx + lx) >> 1;
        int m1 = query(l, r, 2 * x + 1, lx, m);
        int m2 = query(l, r, 2 * x + 2, m, rx);
        return min(m1, m2);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, Size);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, Q;
    cin >> n >> Q;

    vector<int> in(n);

    for (int &i : in) cin >> i;

    segTree st;
    st.init(n);
    st.build(in);

    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << st.query(a - 1, b) << '\n';
    }
    // TC : O(nlog(n))
    // SC : O(nlog(n))
}