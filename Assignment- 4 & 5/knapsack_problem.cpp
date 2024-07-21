#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
    int index;
};

bool cmp(struct Item a, struct Item b) {
    double r1 =  a.profit / a.weight;
    double r2 =  b.profit / b.weight;
    return r1 > r2;
}

void fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    int n = items.size();
    vector<double> fractions(n, 0.0);
    double totalProfit = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            fractions[i] = 1.0;
            totalProfit += items[i].profit;
            remainingWeight -= items[i].weight;
        } else {
            fractions[i] = remainingWeight / items[i].weight;
            totalProfit += items[i].profit * fractions[i];
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Element " << items[i].index << ": " << fractions[i] << endl;
    }

    cout << "Profit: " << totalProfit << endl;
}

int main() {
    int W, n;
    cout << "Enter maximum weight: ";
    cin >> W;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter weights of elements: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
        items[i].index = i + 1;
    }

    cout << "Enter profits of elements: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit;
    }

    fractionalKnapsack(W, items);

    return 0;
}