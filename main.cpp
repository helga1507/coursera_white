#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrom (string str) {
    if (str == "")
        return true;

    string copy_str = str;
    reverse(copy_str.begin(), copy_str.end());

    return str == copy_str;
}

vector<string> PalindromFilter (vector<string> words, int minLength) {
    vector<string> filtered_words;

    for (auto word : words) {
        if (word.length() < minLength || !IsPalindrom(word))
            continue;

        filtered_words.push_back(word);
    }

    return filtered_words;
}

int main() {
    vector<string> a_vector = {"weew", "bro", "code"};
    int length = 4;

    vector<string> filter_a = PalindromFilter(a_vector, length);

    for (auto a : filter_a)
        cout << a << " ";

    return 0;
}
