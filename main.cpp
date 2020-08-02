#include <iostream>
#include <vector>

using namespace std;

int getAverage (const vector<int>& vec) {
    int average = 0;

    for (auto v : vec)
        average += v;

    return average / vec.size();
}

vector<int> getVectorBiggerAverage (const vector<int>& temperature) {
    vector<int> temp_bigger_average;

    int average = getAverage(temperature);
    int i = 0;

    for (const auto t : temperature) {
        if (t > average)
            temp_bigger_average.push_back(i);

        i++;
    }

    return temp_bigger_average;
}

vector<int> inputVector (int n) {
    vector<int> temperature(n);

    for (auto& t : temperature)
        cin >> t;

    return temperature;
}

int main() {
    int n;

    cin >> n;

    vector<int> temperature = inputVector(n);
    vector<int> temp_bigger_average = getVectorBiggerAverage(temperature);

    cout << temp_bigger_average.size() << endl;

    for (auto t : temp_bigger_average)
        cout << t << " ";

    return 0;
}
