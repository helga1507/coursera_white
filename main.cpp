#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> numbers(n);

    for (auto& num : numbers)
        cin >> num;

    sort(numbers.begin(), numbers.end(), [] (int& a, int& b) {return abs(a) < abs(b);});

    for (const auto& num : numbers)
        cout << num << " ";

    return 0;
}
