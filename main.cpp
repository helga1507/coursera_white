#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct FullName {
    string first_name = "";
    string last_name = "";
};

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
        int current_year = full_name_of_year.rbegin()->first;
        FullName current_name = { "", "" };

        for (const auto& [key, value] : full_name_of_year) {
            if (key > year)
                break;

            if (!value.first_name.empty())
                current_name.first_name = value.first_name;

            if (!value.last_name.empty())
                current_name.last_name = value.last_name;
        }

        return PrintFullName(current_name);
    }

private:
    map<int, FullName> full_name_of_year;

    string PrintFullName (const FullName& name) {
        if (name.last_name.empty() && name.first_name.empty())
            return "Incognito";

        if (name.last_name.empty())
            return name.first_name + " with unknown last name";

        if (name.first_name.empty())
            return name.last_name + " with unknown first name";

        return name.first_name + " " + name.last_name;
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
