#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> binary;

    cin >> n;

    do {
        binary.push_back(n % 2);
        n /= 2;
    } while (n);

    reverse(binary.begin(), binary.end());

    for (auto i : binary)
        cout << i;

    return 0;
}
