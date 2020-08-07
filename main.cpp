#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void addToSynonyms(map<string, set<string>>& synonyms) {
    string key, value;

    cin >> key >> value;

    synonyms[key].insert(value);
}

void countSynonym(const map<string, set<string>>& synonyms, vector<string>& output_strings) {
    string str;

    cin >> str;

    set<string> synonyms_for_str;

    if (synonyms.count(str) != 0)
        synonyms_for_str = synonyms.at(str);

    for (const auto& [key, value] : synonyms) {
        if (key == str || synonyms_for_str.find(key) != synonyms_for_str.end())
            continue;

        for (const auto& syn : value) {
            if (syn == str)
                synonyms_for_str.insert(key);
        }
    }

    output_strings.emplace_back(to_string(synonyms_for_str.size()));
}

void checkSynonyms(const map<string, set<string>>& synonyms, vector<string>& output_strings) {
    string str1, str2;
    bool is_find = false;

    cin >> str1 >> str2;

    for (const auto& [key, value] : synonyms) {
        string looked_str;

        if (str1 == key)
            looked_str = str2;
        else if (str2 == key)
            looked_str = str1;
        else
            continue;

        if (value.find(looked_str) != value.end()) {
            is_find = true;

            break;
        }
    }

    string answer = is_find ? "YES" : "NO";

    output_strings.emplace_back(answer);
}

int main() {
    int n;
    map<string, set<string>> synonyms;
    vector<string> output_strings;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string act;

        cin >> act;

        if (act == "ADD")
            addToSynonyms(synonyms);
        else if (act == "COUNT")
            countSynonym(synonyms, output_strings);
        else if (act == "CHECK")
            checkSynonyms(synonyms, output_strings);
    }

    for (const auto& str : output_strings)
        cout << str << endl;

    return 0;
}
