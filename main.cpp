#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SortedStrings {
private:
    vector<string> sorted_strings;

    void SortString() {
        sort(sorted_strings.begin(), sorted_strings.end());
    }

public:
    void AddString(const string& str) {
        sorted_strings.emplace_back(str);
        SortString();
    }

    vector<string> GetSortedStrings() {
        return sorted_strings;
    }
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
