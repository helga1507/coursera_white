#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}

    ReversibleString(string str) {
        this->main_str = str;
    }

    string ToString() const {
        return this->main_str;
    }

    void Reverse () {
        reverse(this->main_str.begin(), this->main_str.end());
    }

private:
    string main_str;

};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
