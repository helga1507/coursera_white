#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;

    cin >> n;

    map<vector<string>, int> stops_buses;
    vector<string> output_str;

    for (int i = 0; i < n; i++) {
        int k;

        cin >> k;

        vector<string> stops(k);

        for (auto& s : stops)
            cin >> s;

        if (stops_buses.count(stops) != 0) {
            output_str.emplace_back("Already exists for " + to_string(stops_buses[stops]));

            continue;
        }

        unsigned int next_number_bus = stops_buses.size() + 1;
        stops_buses[stops] = next_number_bus;
        output_str.emplace_back("New bus " + to_string(stops_buses[stops]));
    }

    for (const auto& str: output_str)
        cout << str << endl;

    return 0;
}
