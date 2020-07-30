#include <iostream>
#include <cmath>

using namespace std;

float get_discriminant(float a, float b, float c) {
    return pow(b, 2) - 4 * a * c;
}

float equation(float b, float c) {
    return -1 * c / b;
}

float quadratic_equation(float a, float b, float d, bool pos_sign) {
    float sign = pos_sign ? 1 : -1;

    return (-1 * b + sign * sqrt(d)) / (2 * a);
}

int main() {
    float a, b, c;

    cin >> a >> b >> c;

    if (a == 0 && b == 0)
        return 0;

    if (a == 0) {
        cout << equation(b, c);

        return 0;
    }

    float d = get_discriminant(a, b, c);

    if (d < 0)
        return 0;

    cout << quadratic_equation(a, b, d, true);

    if (d == 0) {
        return 0;
    }

    cout << " " << quadratic_equation(a, b, d, false) << endl;

    return 0;
}
