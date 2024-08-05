#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
    int index;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

void knapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (items[i-1].weight <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - items[i-1].weight] + items[i-1].profit);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int w = W;
    vector<int> selectedItems;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            selectedItems.push_back(items[i-1].index);
            w -= items[i-1].weight;
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

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Weight of element " << i + 1 << " (in Kg): ";
        cin >> items[i].weight;
        cout << "Profit of element " << i + 1 << " (in rupees): ";
        cin >> items[i].profit;
        items[i].index = i + 1;
    }

    int W;
    cout << "Maximum weight limit W (in Kg): ";
    cin >> W;

    knapsack(W, items);

    return 0;
}