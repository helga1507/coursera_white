#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct FullName {
    string first_name = "";
    string last_name = "";
};

string JoinReverse (const vector<string>& v_str) {
    if (v_str.empty())
        return "";

    string joined_str = v_str.back();

    if (v_str.size() != 1) {
        joined_str += " (";

        for (unsigned int i = v_str.size()-2; i > 0; i--)
            joined_str += v_str[i] + ", ";

//        for (auto it = v_str.rbegin(); it < v_str.rend() - 1; it++)
//            joined_str += *it + ", ";

        joined_str += v_str[0] + ")";
    }

    return joined_str;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        if (full_name_of_year.count(year) == 0)
            full_name_of_year[year] = { first_name, "" };
        else
            full_name_of_year[year].first_name = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (full_name_of_year.count(year) == 0)
            full_name_of_year[year] = { "", last_name };
        else
            full_name_of_year[year].last_name = last_name;
    }

    string GetFullName(int year) {
        FullName current_name = { "", "" };

        for (const auto& [key, value] : full_name_of_year) {
            if (key > year)
                break;

            if (!value.first_name.empty())
                current_name.first_name = value.first_name;

            if (!value.last_name.empty())
                current_name.last_name = value.last_name;
        }

        return PrintFullName({ current_name.first_name }, { current_name.last_name });
    }

    string GetFullNameWithHistory(int year) {
        vector<string> first_names, last_names;

        for (const auto& [key, value] : full_name_of_year) {
            if (key > year)
                break;

            if (!value.first_name.empty() && (first_names.empty() || value.first_name != first_names.back()))
                first_names.emplace_back(value.first_name);

            if (!value.last_name.empty() && (last_names.empty() || value.last_name != last_names.back()))
                last_names.emplace_back(value.last_name);
        }

        return PrintFullName(first_names, last_names);
    }

private:
    map<int, FullName> full_name_of_year;

    string PrintFullName (const vector<string>& first_names = {}, const vector<string>& last_names = {}) {
        bool is_empty_first_name = first_names.empty() || (first_names.size() == 1 && first_names[0].empty());
        bool is_empty_last_name = last_names.empty() || (last_names.size() == 1 && last_names[0].empty());

        if (is_empty_first_name && is_empty_last_name)
            return "Incognito";

        string history_first_names = JoinReverse(first_names), history_last_names = JoinReverse(last_names);

        if (is_empty_last_name)
            return history_first_names + " with unknown last name";

        if (is_empty_first_name)
            return history_last_names + " with unknown first name";

        return history_first_names + " " + history_last_names;
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
