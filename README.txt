Welcome to Income Tax Calculator, a C++ program designed to calculate the amount of tax owed based on the user's income and marital status. 
The program applies different income thresholds and tax rates for single and married individuals, then displays the calculated tax amount. 

Example: 

Enter your marital status (single or married): single
Enter your income: 50000
Tax owed: [calculated tax amount]

The exact amount displayed depends on the income thresholds and tax rates defined in the program.

Installation: 

A C++ compiler, such as:

GCC / G++
Clang
Microsoft Visual C++ (MSVC)

A C++ compatible IDE or terminal environment.

Examples include:

Visual Studio
Visual Studio Code
CLion
Command Prompt or Terminal

Clone the Repository:
git clone https://github.com/3N16MV/TaxCalculator

Navigate to the project directory:

cd TaxCalculator

Compile the program:

Using G++:

g++ TaxCalculator.cpp -o TaxCalculator

Run the program:

On Windows:

TaxCalculator.exe

On Linux or macOS:

./TaxCalculator

The program prompts the user to enter their marital status and income. It then:

1. Determines whether the user selected single or married filing status.

2. Compares the user's income with the thresholds for the selected status.

3. Applies the corresponding tax rate.

4. Calculates and displays the total tax owed.

Single and married individuals are evaluated separately because each filing status has its own income thresholds and tax calculations.

Contributions

Contributions to improve TaxCalculator are welcome. Feel free to submit pull requests or open issues with suggestions for improvements.

License

This project is released under the MIT License. See the LICENSE file for details.

Support

For questions or issues, please open a GitHub issue in the repository.