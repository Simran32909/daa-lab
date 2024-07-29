#include <bits/stdc++.h>
using namespace std;

void printSolution(const vector<int>& solution) {
    int n;
    n = solution.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (solution[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& solution, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int prevCol = solution[i];
        if (prevCol == col ||
            prevCol - col == i - row ||
            prevCol - col == row - i) {
            return false;
            }
    }
    return true;
}

bool solveNQueens(vector<int>& solution, int row) {
    int n = solution.size();
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(solution, row, col)) {
            solution[row] = col;
            if (solveNQueens(solution, row + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> solution(n, -1);

    if (solveNQueens(solution, 0)) {
        printSolution(solution);
    } else {
        cout << "NO" << endl;
    }

    return 0;
}