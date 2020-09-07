#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const char SEPARATOR_DATE = '-';
const string COMMAND_ADD = "Add";
const string COMMAND_DEL = "Del";
const string COMMAND_FIND = "Find";
const string COMMAND_PRINT = "Print";

class Date {
public:
    Date (int new_year, int new_month, int new_day) {
        if (new_month < 1 || new_month > 12)
            throw logic_error("Month value is invalid: " + to_string(month));

        if (day < 1 || day > 31)
            throw logic_error("Day value is invalid: " + to_string(day));

        this->year = new_year;
        this->month = new_month;
        this->day = new_day;
    }

    int GetYear() const {
        return this->year;
    };

    int GetMonth() const {
        return this->month;
    };

    int GetDay() const {
        return this->day;
    };

private:
    int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();

    if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();

    return lhs.GetDay() < rhs.GetDay();
};

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        this->events[date].insert(event);
    };

    bool DeleteEvent(const Date& date, const string& event) {
        if (this->events.count(date) == 0)
            return false;

        return this->events.at(date).erase(event) != 0;
    };

    int DeleteDate(const Date& date) {
        if (this->events.count(date) == 0)
            return 0;

        int n = this->events.at(date).size();
        this->events.erase(date);

        return n;
    };

    void Find(const Date& date) const {
        vector<string> v_str;

        if (this->events.count(date) == 0)
            return;

        for (const string& event : this->events.at(date))
            cout << event << endl;
    };

    void Print() const {
        for (const auto& [date, set_values] : this->events) {
            for (const auto& event : set_values) {
                cout << setw(4) << setfill('0') << date.GetYear() << "-" <<
                        setw(2) << setfill('0') << date.GetMonth() << "-" <<
                        setw(2) << setfill('0') << date.GetDay() << " " <<
                        event << endl;
            }
        }
    };

private:
    map<Date, set<string>> events;
};

Date parseDate (const string& str_date) {
    stringstream ss(str_date);
    string error_str;
    string trash_text;
    int year, month, day;
    char sep, sep2;

    ss >> year >> sep >> month >> sep2 >> day;

    if (!ss || sep != SEPARATOR_DATE || sep2 != SEPARATOR_DATE || ss.rdbuf()->in_avail() != 0)
        throw runtime_error("Wrong date format: " + str_date);

    return { year, month, day };
}

bool CheckCorrectCommand (const string& command) {
    return command == COMMAND_ADD || command == COMMAND_DEL || command == COMMAND_FIND || command == COMMAND_PRINT;
}

void FillCommandsData (stringstream& ss, string& command, Date& date, string& event) {
    string temp;

    istream& ist = getline(ss, command, ' ');

    if (ss.eof() || !CheckCorrectCommand(command))
        return;

    getline(ss, temp, ' ');

    date = parseDate(temp);

    if (ss.eof())
        return;

    getline(ss, event, ' ');
}

int main() {
    Database db;

    string command_line;
    while (getline(cin, command_line)) {
        stringstream ss(command_line);
        string command;
        Date date(0, 0, 0);
        string event;


        try {
            FillCommandsData(ss, command, date, event);

            if (command.empty())
                continue;

            if (command == COMMAND_ADD) {
                db.AddEvent(date, event);
            }
            else if (command == COMMAND_DEL && !event.empty()) {
                bool is_deleted = db.DeleteEvent(date, event);
                cout << (is_deleted ? "Deleted successfully" : "Event not found") << endl;
            }
            else if (command == COMMAND_DEL) {
                int n = db.DeleteDate(date);
                cout << "Deleted " << n << " events" << endl;
            }
            else if (command == COMMAND_FIND) {
                db.Find(date);
            }
            else if (command == COMMAND_PRINT) {
                db.Print();
            }
            else {
                throw runtime_error("Unknown command: " + command);
            }
        } catch (exception& err) {
            cout << err.what() << endl;
        }
    }

    return 0;
}