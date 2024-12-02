#include <iostream>
#include <iomanip>  // For formatting a double-precision number.
#include <string>
using namespace std;

// Prototype for the extractNumeric function
double extractNumeric(const string& str);

int main() {
    string input;
    
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

double extractNumeric(const string& str) {
    int length = str.length();
    bool hasDecimal = false;
    bool hasDigits = false;
    size_t i = 0;

    // Check for optional sign
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    double value = 0.0;
    double fractionFactor = 0.1;
    bool isFraction = false;

    // Iterate through each character
    for (; i < length; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            hasDigits = true;
            if (!isFraction) {
                value = value * 10 + (str[i] - '0');
            } else {
                value += (str[i] - '0') * fractionFactor;
                fractionFactor /= 10;
            }
        } else if (str[i] == '.' && !hasDecimal) {
            hasDecimal = true;
            isFraction = true;
        } else {
            // Invalid character
            return -999999.99;
        }
    }

    return hasDigits ? value : -999999.99;
}
