/* ---------------------------------------------------------------------------
** Author: Alexis Lariviere
** File: TaxCalculator.cpp
** Description: This program calculates the tax owed based on the user's income and marital status. It applies different tax rates for single and married individuals, with specific income thresholds for each category.
** Date: 08/09/2026
** -------------------------------------------------------------------------*/

#include <iostream>
#include <cctype>
#include <iomanip>
#include <limits>

using namespace std;

// Constants for tax rates
const double RATE1 = 0.10;
const double RATE2 = 0.25;

// Constants for income limits based on marital status
const double RATE1_SINGLE_LIMIT = 32000;
const double RATE1_MARRIED_LIMIT = 64000;

// Calculates tax using the appropriate first-bracket income limit.
double calculateTax(double income, char maritalStatus) {
    double tax = 0.0;

    if (maritalStatus == 'S' || maritalStatus == 's') {
        if (income <= RATE1_SINGLE_LIMIT) {
            tax = income * RATE1;
        } else {
            tax = RATE1_SINGLE_LIMIT * RATE1 + (income - RATE1_SINGLE_LIMIT) * RATE2;
        }
    } else if (maritalStatus == 'M' || maritalStatus == 'm') {
        if (income <= RATE1_MARRIED_LIMIT) {
            tax = income * RATE1;
        } else {
            tax = RATE1_MARRIED_LIMIT * RATE1 + (income - RATE1_MARRIED_LIMIT) * RATE2;
        }
    }

    return tax;
}

// Validates the marital status input to ensure it is either 'S' or 'M'.
char getMaritalStatus() {
    char maritalStatus;
    while (true) {
        cout << "Enter marital status (S for single, M for married): ";
        cin >> maritalStatus;
        maritalStatus = toupper(maritalStatus);
        if (maritalStatus == 'S' || maritalStatus == 'M') {
            return maritalStatus;
        } else {
            cout << "Invalid input. Please enter 'S' for single or 'M' for married." << endl;
        }
    }
}

double getIncome() {
    double income;
    while (true) {
        cout << "Enter your income: ";
        cin >> income;
        if (cin.fail() || income < 0) {
            cout << "Invalid input. Please enter a non-negative number for income." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return income;
        }
    }
}

double getTaxOwed(double income, char maritalStatus) {
    return calculateTax(income, maritalStatus);
}

int main() {
    char maritalStatus = getMaritalStatus();
    double income = getIncome();
    double taxOwed = getTaxOwed(income, maritalStatus);

    cout << fixed << setprecision(2);
    cout << "Based on an income of $" << income << " and marital status '" << maritalStatus << "', the tax owed is: $" << taxOwed << endl;

    double taxRate = income == 0 ? 0.0 : (taxOwed / income) * 100;
    cout << "The effective tax rate is: " << taxRate << "%" << endl;

    cout << "Tax owed: $" << taxOwed << endl;
    cout << "Effective tax rate: " << taxRate << "%" << endl;
    cout << "-----------\n";
    cout << "Filing Status: " << (maritalStatus == 'S' ? "Single" : "Married") << endl;
    cout << "Income: $" << income << endl;
    cout << "Tax Owed: $" << taxOwed << endl;
    cout << "After-tax income: $" << (income - taxOwed) << endl;
    cout << "Effective Tax Rate: " << taxRate << "%" << endl;

    return 0;
}
