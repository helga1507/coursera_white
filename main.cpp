#include <iostream>

using namespace std;

int main() {
    float n, a, b, x, y, price;

    cin >> n >> a >> b >> x >> y;

    if (n > b) {
        price = n - n * (y / 100);
    } else if (n > a) {
        price = n - n * (x / 100);
    } else {
        price = n;
    }

    cout << price << endl;

    return 0;
}
