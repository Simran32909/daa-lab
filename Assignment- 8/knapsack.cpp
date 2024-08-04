#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int weight;
    int profit;
    Item(int w, int p) : weight(w), profit(p) {}
};

int knapsackDP(const vector<Item>& items, int W, vector<bool>& selected) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = W;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[i - 1] = true;
            w -= items[i - 1].weight;
        } else {
            selected[i - 1] = false;
        }
    }

    return dp[n][W];
}

void knapsackBranchBound(vector<Item>& items, int W, int index, int currentWeight, int currentProfit,
                         int& maxProfit, vector<bool>& bestSelection, vector<bool>& currentSelection) {
    if (index >= items.size()) {
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            bestSelection = currentSelection;
        }
        return;
    }

    if (currentWeight + items[index].weight <= W) {
        currentSelection[index] = true;
        knapsackBranchBound(items, W, index + 1, currentWeight + items[index].weight,
                            currentProfit + items[index].profit, maxProfit, bestSelection, currentSelection);
    }

    currentSelection[index] = false;
    knapsackBranchBound(items, W, index + 1, currentWeight, currentProfit, maxProfit, bestSelection, currentSelection);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        int weight, profit;
        cout << "Enter weight of element " << i + 1 << ": ";
        cin >> weight;
        cout << "Enter profit of element " << i + 1 << ": ";
        cin >> profit;
        items.push_back(Item(weight, profit));
    }

    int W;
    cout << "Enter the maximum weight limit: ";
    cin >> W;

    vector<bool> selected(n, false);
    int maxProfitDP = knapsackDP(items, W, selected);

    cout << "Dynamic Programming Approach:\n";
    cout << "Elements selected: ";
    for (int i = 0; i < n; ++i) {
        if (selected[i]) {
            cout << "Element " << i + 1 << " ";
        }
    }
    cout << "\nProfit achieved: Rs " << maxProfitDP << endl;

    vector<bool> bestSelection(n, false);
    vector<bool> currentSelection(n, false);
    int maxProfitBB = 0;

    knapsackBranchBound(items, W, 0, 0, 0, maxProfitBB, bestSelection, currentSelection);

    cout << "Branch and Bound Approach:\n";
    cout << "Elements selected: ";
    for (int i = 0; i < n; ++i) {
        if (bestSelection[i]) {
            cout << "Element " << i + 1 << " ";
        }
    }
    cout << "\nProfit achieved: Rs " << maxProfitBB << endl;

    return 0;
}