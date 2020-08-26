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
            throw invalid_argument("Denominator can't be 0");
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
        throw domain_error("Denominator can't be 0");

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

    return stream;
};

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}