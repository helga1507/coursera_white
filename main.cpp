#include <iostream>
#include <vector>
#include <map>

using namespace std;

void changeCapital (map<string, string>& countries, string& output_string) {
    string country_name, new_capital;

    cin >> country_name >> new_capital;

    if (countries.count(country_name) == 0)
        output_string = "Introduce new country " + country_name + " with capital " + new_capital;
    else if (countries[country_name] == new_capital)
        output_string = "Country " + country_name + " hasn't changed its capital";
    else
        output_string = "Country "+country_name+" has changed its capital from "+countries[country_name]+" to "+new_capital;

    countries[country_name] = new_capital;
}

void renameCountry (map<string, string>& countries, string& output_string) {
    string new_country_name, old_country_name, str;

    cin >> old_country_name >> new_country_name;

    bool incorrect = countries.count(new_country_name) != 0 ||
            countries.count(old_country_name) == 0 ||
            old_country_name == new_country_name;

    if (incorrect) {
        output_string = "Incorrect rename, skip";

        return;
    }

    output_string = "Country "+old_country_name+" with capital "+countries[old_country_name]+" has been renamed to "+new_country_name;
    countries[new_country_name] = countries[old_country_name];
    countries.erase(old_country_name);
}

void aboutCountry (map<string, string>& countries, string& output_string) {
    string country_name;

    cin >> country_name;

    if (countries.count(country_name) == 0) {
        output_string = "Country " + country_name + " doesn't exist";

        return;
    }

    output_string = "Country "+country_name+" has capital " +countries[country_name];
}

void dump (map<string, string>& countries, string& output_string) {
    if (countries.empty()) {
        output_string = "There are no countries in the world";

        return;
    }

    for (const auto& country : countries)
        output_string += country.first + "/" + country.second + " ";
}

int main() {
    int n;

    cin >> n;

    vector<string> output_strings(n);
    map<string, string> countries;

    for (int i = 0; i < n; i++) {
        string act;

        cin >> act;

        if (act == "CHANGE_CAPITAL")
            changeCapital(countries, output_strings[i]);
        else if (act == "RENAME")
            renameCountry(countries, output_strings[i]);
        else if (act == "ABOUT")
            aboutCountry(countries, output_strings[i]);
        else if (act == "DUMP")
            dump(countries, output_strings[i]);
    }

    for (const auto& str : output_strings)
        cout << str << endl;

    return 0;
}
