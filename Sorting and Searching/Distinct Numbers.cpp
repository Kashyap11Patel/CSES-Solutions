/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

// here we use set for the store distinct numbers

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    set<int> s;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << (int)s.size() << endl;

    // TC : O(nlogn)
    // SC : O(n)
}
