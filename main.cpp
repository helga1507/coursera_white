#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

char ToLower (char x) {
    return tolower(x);
}

int main() {
    int n;

    cin >> n;

    vector<string> strs(n);

    for (auto& s: strs)
        cin >> s;

    sort(strs.begin(), strs.end(), [] (string a, string b) {
        transform(a.begin(), a.end(), a.begin(), ToLower);
        transform(b.begin(), b.end(), b.begin(), ToLower);

        return a < b;
    });

    for (const auto& s: strs)
        cout << s << " ";

    return 0;
}
