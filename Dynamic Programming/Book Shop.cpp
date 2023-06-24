/** Kashyap Patel **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    //Problem is similliar to the knapsack problem
    //dp[i][j] = maximum number pages at the ith book and jth price

    int cost[n], pages[n];
    for (int &i : cost) cin >> i;
    for (int &i : pages) cin >> i;

    int knapsack[x + 1] = {0};

    for (int book = 0; book < n; book++)
        for (int price = x; price >= cost[book]; price--)
            knapsack[price] = max(knapsack[price - cost[book]] + pages[book], knapsack[price]);

    cout << knapsack[x] << ' ';

    // TC : O(n * x)
    // SC : O(x)
}