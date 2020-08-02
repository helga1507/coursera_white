#include <iostream>

using namespace std;

int Factorial (int a) {
    if (a < 0)
        return 1;

    int sum = 1;

    for (int i = 1; i <= a; i++) {
        sum *= i;
    }

    return sum;
}

int main() {
    int a;

    cin >> a;

    cout << Factorial(a) << endl;

    return 0;
}
