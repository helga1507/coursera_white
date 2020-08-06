#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Bus {
    int index;
    string name;
};

bool compareByName (const Bus& a, const Bus& b) {
    return a.name < b.name;
}

string _findBusesForStopByIndex (
        const unsigned int& i_stop,
        map<int, vector<int>>& buses_stops,
        vector<Bus>& buses_list,
        vector<string>& stops_list,
        const int& except = -1
    ) {
    string str;

    for (const auto& bus_stops: buses_stops) {
        if (bus_stops.first == except)
            continue;

        auto iterator_stop_in_buses = find(bus_stops.second.begin(), bus_stops.second.end(), i_stop);

        if (iterator_stop_in_buses != bus_stops.second.end())
            str += buses_list[bus_stops.first].name + " ";
    }

    return str;
}

string _findBusesForStopByName (const string& stop_name, map<int, vector<int>>& buses_stops, vector<Bus>& buses_list, vector<string>& stops_list) {
    auto iterator_stop = find(stops_list.begin(), stops_list.end(), stop_name);

    if (iterator_stop == stops_list.end())
        return "";

    unsigned int i_stop = distance(stops_list.begin(), iterator_stop);

    return _findBusesForStopByIndex(i_stop, buses_stops, buses_list, stops_list);
}

void newBus (map<int, vector<int>>& buses_stops, vector<Bus>& buses_list, vector<string>& stops_list) {
    int n_bus = buses_list.size();
    string bus;
    int n;

    cin >> bus >> n;

    buses_list.push_back({n_bus, bus});

    for (int i = 0; i < n; i++) {
        string stop;
        unsigned int i_stop = stops_list.size();

        cin >> stop;

        auto iterator_stop = find(stops_list.begin(), stops_list.end(), stop);

        if (iterator_stop == stops_list.end())
            stops_list.push_back(stop);
        else
            i_stop = distance(stops_list.begin(), iterator_stop);

        buses_stops[n_bus].push_back(i_stop);
    }
}

void busesForStop (map<int, vector<int>>& buses_stops, vector<Bus>& buses_list, vector<string>& stops_list, vector<string>& output_str) {
    string stop;

    cin >> stop;

    string str = _findBusesForStopByName(stop, buses_stops, buses_list, stops_list);

    if (str.empty())
        str = "No stop";

    output_str.emplace_back(str);
}

void stopsForBus (map<int, vector<int>>& buses_stops, vector<Bus>& buses_list, vector<string>& stops_list, vector<string>& output_str) {
    string bus;

    cin >> bus;

    auto iterator_bus = find_if(buses_list.begin(), buses_list.end(), [bus] (const Bus& a) { return a.name == bus; });

    if (iterator_bus == buses_list.end()) {
        output_str.emplace_back("No bus");

        return;
    }

    int i_bus = distance(buses_list.begin(), iterator_bus);

    for (const auto& i_stop : buses_stops[i_bus]) {
        string str = _findBusesForStopByIndex(i_stop, buses_stops, buses_list, stops_list, i_bus);

        if (str.empty())
            str = "no interchange";

        output_str.emplace_back("Stop " + stops_list[i_stop] + ": " + str);
    }
}

void allBuses (map<int, vector<int>>& buses_stops, vector<Bus>& buses_list, vector<string>& stops_list, vector<string>& output_str) {
    if (buses_list.empty()) {
        output_str.emplace_back("No buses");

        return;
    }

    vector<Bus> sort_buses_list = buses_list;

    sort(sort_buses_list.begin(), sort_buses_list.end(), compareByName);

    for (const auto& bus : sort_buses_list) {
        string str = "Bus " + bus.name + ": ";

        for (const auto& i_stop : buses_stops[bus.index])
            str += stops_list[i_stop] + " ";

        output_str.emplace_back(str);
    }

}

int main() {
    int n;

    cin >> n;

    map<int, vector<int>> buses_stops;
    vector<string> stops, output_str;
    vector<Bus> buses;

    for (int i = 0; i < n; i++) {
        string act;

        cin >> act;

        if (act == "NEW_BUS")
            newBus(buses_stops, buses, stops);
        else if (act == "BUSES_FOR_STOP")
            busesForStop(buses_stops, buses, stops, output_str);
        else if (act == "STOPS_FOR_BUS")
            stopsForBus(buses_stops, buses, stops, output_str);
        else if (act == "ALL_BUSES")
            allBuses(buses_stops, buses, stops, output_str);
    }

    for (const auto& str : output_str)
        cout << str << endl;

    return 0;
}
