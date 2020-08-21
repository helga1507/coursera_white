#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    fstream input("../input.txt");

    if (input) {
        double num;

        cout << fixed << setprecision(3);

        while (input >> num) {
            cout << num << endl;
        }
    }

    return 0;
}
