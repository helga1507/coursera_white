#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> BuildCharCounters(const string& str) {
    map<char, int> char_counter;

    for (const char& ch : str)
        char_counter[ch]++;

    return char_counter;
}

int main() {
    int n;

    cin >> n;

    vector<string> output_words(n);

    for (int i = 0; i < n; i++) {
        string str1, str2;

        cin >> str1 >> str2;

        output_words[i] = BuildCharCounters(str1) == BuildCharCounters(str2) ? "YES" : "NO";
    }

    for (const auto& word : output_words)
        cout << word << endl;

    return 0;
}
