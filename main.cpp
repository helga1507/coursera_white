#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& vec) {
    if (!vec.size())
        return;

    unsigned int last_i = vec.size() - 1;

    for (int i = 0; i <= last_i / 2; i++) {
        int temp = vec[i];
        vec[i] = vec[last_i - i];
        vec[last_i - i] = temp;
    }
}

int main() {
    vector<int> a_vec = {1, 5, 3, 4, 2, 9, 6};

    Reverse(a_vec);

    for (auto a : a_vec)
        cout << a  << " ";

    return 0;
}
