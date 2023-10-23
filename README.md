Investment Calculator


Overview:

The Investment Calculator is a simple C++ program designed to calculate and display the growth of an investment over a specified number of years. The program takes into account the initial investment amount, monthly deposits, annual interest rate, and the number of years the investment will grow. It provides two reports: one without additional monthly deposits and one with monthly deposits.



Features:

User Input: The program prompts the user to enter the initial investment amount, monthly deposit, annual interest rate, and the number of years.
Interest Calculation: The program calculates the monthly compounded interest for the investment.


Investment Reports: The program displays two reports:

Balance and interest without additional monthly deposits.
Balance and interest with additional monthly deposits.
Compilation & Execution


To compile and run the program, follow these steps:

Ensure you have a C++ compiler installed (e.g., g++).
Navigate to the directory containing the source code.


Compile the program:

g++ -o investment_calculator main.cpp

Run the compiled program:


investment_calculator:

Usage:

When prompted, enter the initial investment amount.
Enter the monthly deposit amount.
Provide the annual interest rate (in percentage).
Specify the number of years for the investment.
The program will then display the investment reports.


Code Structure:

Class InvestmentCalculator: Represents the main functionality of the investment calculator.


Private Members:
initialInvestment: The starting amount of the investment.
monthlyDeposit: The amount contributed to the investment each month.
annualInterest: Annual interest rate.
numberOfYears: The number of years the investment has to grow.
calculateInterest(): Function to calculate monthly compounded interest.
Public Members:
displayInputPrompt(): Function to display input prompt and read user input.
displayInvestmentReport(): Function to display investment report.
runCalculator(): Function to run the calculator.
Main Function: Creates an instance of InvestmentCalculator and runs the calculator.
