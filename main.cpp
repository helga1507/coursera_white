#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void GetLine (fstream& input, char separator, bool is_last_column = false) {
    string line;

    getline(input, line, separator);

    cout << setw(10);
    cout << line;

    if (!is_last_column)
        cout << " ";
}

int main() {
    fstream input("../input.txt");

    if (input.is_open()) {
        int n, k;

        input >> n >> k;
        input.ignore(1);

        for (int i = 0; i < n; i++) {
            string line;

            for (int j = 0; j < k - 1; j++)
                GetLine(input, ',');

            GetLine(input, '\n', true);

            if (i != n - 1)
                cout << endl;
        }
    }
    
    return 0;
}
