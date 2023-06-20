/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    long long val;

    Node() {
        val = 0;
    }

    Node(long long v) {
        val = v;
    }

    void merge(Node &a, Node &b) {
        val = a.val + b.val;
    }
};

struct segTree {

    int Size = 1;
    vector<Node> tree;

    void init(int n) {
        while (Size < n) Size *= 2;
        tree.assign(2 * Size, Node());
    }

    void build(vector<int>& in, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)in.size())
                tree[x] = Node(in[lx]);
            return;
        }

        int m = (rx + lx) >> 1;
        build(in, 2 * x + 1, lx, m);
        build(in, 2 * x + 2, m, rx);
        tree[x].merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int>& in) {
        build(in, 0, 0, Size);
    }

    void set(int idx, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = Node(v);
            return ;
        }

        int m = (lx + rx) >> 1;
        if (idx < m)
            set(idx, v, 2 * x + 1, lx, m);
        else
            set(idx, v, 2 * x + 2, m, rx);
        tree[x].merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int idx, int v) {
        set(idx, v, 0, 0, Size);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return Node();
        if (lx >= l && rx <= r) return tree[x];

        int m = (rx + lx) >> 1;
        Node ans;
        Node m1 = query(l, r, 2 * x + 1, lx, m);
        Node m2 = query(l, r, 2 * x + 2, m, rx);
        ans.merge(m1, m2);
        return ans;
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, Size).val;
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
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            st.set(a - 1, b);
        else
            cout << st.query(a - 1, b) << '\n';
    }
    // TC : O(nlog(n))
    // SC : O(nlog(n))
}