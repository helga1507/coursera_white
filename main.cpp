#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrom (string str) {
    if (str == "")
        return true;

    string copy_str = str;
    reverse(copy_str.begin(), copy_str.end());

    return str == copy_str;
}

int main() {
    string a;

    cin >> a;

    cout << IsPalindrom(a) << endl;

    return 0;
}
