#include <bits/stdc++.h>
using namespace std;

float power(float x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    if (n % 2 == 0) {
        float halfPower = power(x, n / 2);
        cout << "Combine the results: " << x <<
"^" << n << " = " << x << "^" << n / 2
             << " * " << x << "^" << n / 2 << endl;
        return halfPower * halfPower;
    }
    else {
        float halfPower = power(x, n / 2);
        cout << "Combine the results: " << x << "^" << n << " = " << x << "^" << n / 2
             << " * " << x << "^" << n / 2 << " * " << x << endl;
        return halfPower * halfPower * x;
    }
}

int main() {
    float x;
    int n;

    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    float result = power(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
