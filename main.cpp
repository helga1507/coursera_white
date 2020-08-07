#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    map<set<string>, int> stops_bus;
    vector<string> output_str;

    cin >> n;

    for (int i = 0; i < n; i++) {
        unsigned int last_number = stops_bus.size() + 1;
        int k;
        set<string> stops;

        cin >> k;

        for (int j = 0; j < k; j++) {
            string str;

            cin >> str;

            stops.insert(str);
        }

        if (stops_bus.find(stops) != stops_bus.end()) {
            output_str.emplace_back("Already exists for " + to_string(stops_bus[stops]));

            continue;
        }

        stops_bus[stops] = last_number;
        output_str.emplace_back("New bus " + to_string(last_number));
    }

    for (const auto& str: output_str)
        cout << str << endl;

    return 0;
}
