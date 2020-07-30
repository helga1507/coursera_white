#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int res = -2;

    cin >> str;

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] != 'f')
            continue;

        res++;

        if (res == 0) {
            res = i;
            break;
        }
    }

    cout << res << endl;

    return 0;
}
