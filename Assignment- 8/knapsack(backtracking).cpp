#include <bits/stdc++.h>
using namespace std;

void knapsack(int W, const vector<int>& weights, const vector<int>& profits, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + profits[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int w = W;
    vector<int> selectedItems;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            selectedItems.push_back(i);
            w -= weights[i-1];
        }
    }

    cout << "Elements selected: ";
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        if (i > 0) cout << " and ";
        cout << "Element " << selectedItems[i];
    }
    cout << endl;
    cout << "Profit achieved: Rs " << dp[n][W] << endl;
}

int main() {
    int n;
    cout << "Number of elements: ";
    cin >> n;

    vector<int> weights(n), profits(n);

    for (int i = 0; i < n; ++i) {
        cout << "Weight of element " << i + 1 << " (in Kg): ";
        cin >> weights[i];
        cout << "Profit of element " << i + 1 << " (in rupees): ";
        cin >> profits[i];
    }

    int W;
    cout << "Maximum weight limit W (in Kg): ";
    cin >> W;
    knapsack(W, weights, profits, n);
    return 0;
}