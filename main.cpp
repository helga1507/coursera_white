#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> vec;

    for (int i = v.size() - 1; i >= 0; i--)
        vec.push_back(v[i]);

    return vec;
}

int main() {
    vector<int> a_vec = {1, 5, 3, 4, 2, 9, 6};

    vector<int> b_vec = Reversed(a_vec);

    for (auto b : b_vec)
        cout << b  << " ";

    return 0;
}
