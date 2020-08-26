#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int GreatestCommonDivisor (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    return a + b;
}

class Rational {
public:
    Rational() {
        this->numerator = 0;
        this->denominator = 1;
    };

    Rational(int num, int denom) {
        this->numerator = num;
        this->denominator = denom;

        int gcd_num = GreatestCommonDivisor(abs(this->numerator), abs(this->denominator));

        this->numerator = this->numerator / gcd_num;
        this->denominator = this->denominator / gcd_num;

        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }

        if (this->numerator == 0)
            this->denominator = 1;

        if (this->denominator == 0)
            throw runtime_error("Invalid argument");
    };

    int Numerator() const {
        return this->numerator;
    };
    int Denominator() const {
        return this->denominator;
    };

private:
    int numerator, denominator;
};

Rational operator+ (const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
    int denom = lhs.Denominator() * rhs.Numerator();

    if (denom == 0)
        throw runtime_error("Division by zero");

    return {lhs.Numerator() * rhs.Denominator(), denom};
}

bool operator== (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

bool operator< (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;;
}

ostream& operator<< (ostream& stream, const Rational& num) {
    stream << num.Numerator() << "/" << num.Denominator();

    return stream;
}

istream& operator>> (istream& stream, Rational& num) {
    int a, b;
    stream >> a;
    stream.ignore(numeric_limits<streamsize>::max(), '/');
    stream >> b;

    if (stream)
        num = Rational(a, b);
    else
        throw runtime_error("Invalid argument");

    return stream;
};

int main() {
    Rational rat1, rat2;
    char act;

    try {
        cin >> rat1 >> act >> rat2;

        switch (act) {
            case '+' :
                cout << rat1 + rat2;
                break;
            case '-' :
                cout << rat1 - rat2;
                break;
            case '/' :
                cout << rat1 / rat2;
                break;
            case '*' :
                cout << rat1 * rat2;
                break;
        }
    } catch (runtime_error& ex) {
        cout << ex.what();
    }

    return 0;
}