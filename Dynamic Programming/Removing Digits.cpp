/** Kashyap Patel **/

#include<iostream>
#include<vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // steps[number] = total number of steps required to make number equal to 0

    vector<int> steps(n + 1, n + 1);
    steps[0] = 0;

    for (int number = 1; number <= n; number++) {

        int last_dig;
        int currNumber = number;

        while (currNumber) {
            last_dig = currNumber % 10;
            currNumber /= 10;
            if (last_dig)
                steps[number] = min(steps[number], steps[number - last_dig]);
        }

        steps[number]++;

    }

    cout << steps[n];

    // TC : O(n)
    // SC : O(n)
}