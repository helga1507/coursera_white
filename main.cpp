#include <iostream>
#include <vector>

using namespace std;

class FunctionPart {
public:
    FunctionPart (char& new_operation, double& new_value) {
        this->operation = new_operation;
        this->value = new_value;
    }

    double Apply (const double& val) const {
        if (this->operation == '+')
            return val + this->value;
        else if (this->operation == '-')
            return val - this->value;
        else if (this->operation == '*')
            return val * this->value;
        else if (this->operation == '/')
            return val / this->value;

        return this->value;
    }

    void Invert () {
        if (this->operation == '+')
            this->operation = '-';
        else if (this->operation == '-')
            this->operation = '+';
        else if (this->operation == '*')
            this->operation = '/';
        else if (this->operation == '/')
            this->operation = '*';
    };

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value){
        parts.push_back({ operation, value });
    };

    double Apply (double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }

        return value;
    };

    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }

        reverse(parts.begin(), parts.end());
    };

private:
    vector<FunctionPart> parts;
};