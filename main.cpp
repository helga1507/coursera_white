#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;

    cin >> n;

    set<string> uniq_strings;

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        uniq_strings.insert(s);
    }

    cout << uniq_strings.size() << endl;

    return 0;
}
