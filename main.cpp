#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get_worry(const vector<bool>& queue) {
    int n = 0;

    for (auto q : queue) {
        if (q)
            n++;
    }

    return n;
}

int main() {
    vector<bool> queue;
    vector<int> answer;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        int d;

        cin >> str;

        if (str == "WORRY_COUNT") {
            answer.push_back(get_worry(queue));
            continue;
        }

        cin >> d;

        if (str == "COME") {
            queue.resize(queue.size() + d, false);
            continue;
        }

        if (str == "WORRY") {
            queue[d] = true;
            continue;
        }

        if (str == "QUIET") {
            queue[d] = false;
            continue;
        }
    }

    for (auto a : answer)
        cout << a << endl;

    return 0;
}
