#include <iostream>
#include <vector>
#include <string>

using namespace std;

void do_add(vector<vector<string>>& tasks) {
    int day;
    string task;

    cin >> day >> task;

    tasks[day-1].push_back(task);
}

void do_dump (vector<vector<string>>& tasks, vector<vector<string>>& output_tasks) {
    int day;
    vector<string> output_tasks_on_day;


    cin >> day;

    for (const auto& task : tasks[day-1])
        output_tasks_on_day.push_back(task);

    output_tasks.push_back(output_tasks_on_day);
}

void do_next (int& current_month, const vector<int>& days_in_month, vector<vector<string>>& tasks) {
    vector<string> last_tasks;
    int next_month = current_month == 11 ? 0 : current_month + 1;
    int diff = days_in_month[next_month] - days_in_month[current_month];

    if (diff < 0) {
        unsigned int last_task_i = tasks.size() - 1;

        for (int i = diff + 1; i <= 0; i++) {
            if (tasks[last_task_i + i].empty())
                continue;

            for (const auto& t : tasks[last_task_i + i]) {
                last_tasks.push_back(t);
            }
        }
    }

    current_month = next_month;

    tasks.resize(days_in_month[current_month]);

    if (last_tasks.empty())
        return;

    unsigned int last_task_i = tasks.size() - 1;
    tasks[last_task_i].insert(tasks[last_task_i].end(), last_tasks.begin(), last_tasks.end());
}

int main() {
    int n;
    int current_month = 0;
    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> tasks(31);
    vector<vector<string>> output_tasks;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string act;

        cin >> act;

        if (act == "ADD")
            do_add(tasks);
        else if (act == "DUMP")
            do_dump(tasks, output_tasks);
        else if (act == "NEXT")
            do_next(current_month, days_in_month, tasks);
    }

    for (const auto& task_on_day : output_tasks) {
        cout << task_on_day.size() << " ";

        for(const auto& task : task_on_day)
            cout << task << " ";

        cout << endl;
    }

    return 0;
}
