#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string first_name;
    string last_name;
    unsigned int b_day;
    unsigned int b_month;
    unsigned int b_year;
};

string GetName (const Student& student) {
    return student.first_name + " " + student.last_name;
}

string GetBDay (const Student& student) {
    return to_string(student.b_day) + "." + to_string(student.b_month) + "." + to_string(student.b_year);
}

int main() {
    vector<Student> students;
    vector<string> output;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        Student std;

        cin >> std.first_name;
        cin >> std.last_name;
        cin >> std.b_day;
        cin >> std.b_month;
        cin >> std.b_year;

        students.emplace_back(std);
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        string act;
        int num;

        cin >> act >> num;

        if (num > students.size() || num < 1) {
            output.emplace_back("bad request");

            continue;
        }

        if (act == "name")
            output.emplace_back(GetName(students[num-1]));
        else if (act == "date")
            output.emplace_back(GetBDay(students[num-1]));
        else
            output.emplace_back("bad request");
    }

    for (const auto& str : output)
        cout << str << endl;

    return 0;
}
