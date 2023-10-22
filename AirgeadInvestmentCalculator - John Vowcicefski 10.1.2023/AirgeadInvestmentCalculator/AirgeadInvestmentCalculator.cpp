#include <iostream>
#include <iomanip> // For setting precision and setw

class InvestmentCalculator {
private:
    double initialInvestment; // The starting amount of the investment
    double monthlyDeposit;    // The amount contributed to the investment each month
    double annualInterest;    // Annual interest rate
    int numberOfYears;        // The number of years the investment has to grow

    // Function to calculate monthly compounded interest
    double calculateInterest(double openingAmount, double depositedAmount, double rate) {
        return (openingAmount + depositedAmount) * (rate / 100) / 12; // Monthly compounded interest
    }

public:
    // Constructor to initialize member variables
    InvestmentCalculator() : initialInvestment(0), monthlyDeposit(0), annualInterest(0), numberOfYears(0) {}

    // Function to display input prompt and read user input
    void displayInputPrompt() {
        std::cout << "Initial Investment Amount: $";
        std::cin >> initialInvestment;
        std::cout << "Monthly Deposit: $";
        std::cin >> monthlyDeposit;
        std::cout << "Annual Interest: %";
        std::cin >> annualInterest;
        std::cout << "Number of Years: ";
        std::cin >> numberOfYears;
        std::cout << "\nPress any key to continue...";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::cin.get();    // Wait for user to press a key
    }

    // Function to display investment report
    void displayInvestmentReport() {
        std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
        std::cout << "\n\nBalance and Interest Without Additional Monthly Deposits\n";
        std::cout << "====================================================\n";
        std::cout << std::left << std::setw(10) << "Year" << std::setw(20) << "Year End Balance" << "Year End Earned Interest\n";

        double amount = initialInvestment;
        for (int i = 1; i <= numberOfYears; ++i) {
            double yearInterest = 0;
            for (int j = 0; j < 12; ++j) { // Loop over each month in a year
                double interest = calculateInterest(amount, 0, annualInterest); // Calculate interest for the month
                amount += interest; // Add interest to the amount
                yearInterest += interest; // Accumulate interest for the year
            }
            std::cout << std::left << std::setw(10) << i << "$" << std::setw(19) << amount << "$" << yearInterest << "\n"; // Display year-end balance and interest
        }

        std::cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
        std::cout << "====================================================\n";
        std::cout << std::left << std::setw(10) << "Year" << std::setw(20) << "Year End Balance" << "Year End Earned Interest\n";

        amount = initialInvestment;
        for (int i = 1; i <= numberOfYears; ++i) {
            double yearInterest = 0;
            for (int j = 0; j < 12; ++j) { // Loop over each month in a year
                double interest = calculateInterest(amount, monthlyDeposit, annualInterest); // Calculate interest for the month
                amount += monthlyDeposit + interest; // Add monthly deposit and interest to the amount
                yearInterest += interest; // Accumulate interest for the year
            }
            std::cout << std::left << std::setw(10) << i << "$" << std::setw(19) << amount << "$" << yearInterest << "\n"; // Display year-end balance and interest
        }
    }

    // Function to run the calculator
    void runCalculator() {
        displayInputPrompt(); // Display input prompt and read user input
        displayInvestmentReport(); // Display investment report
    }
};

int main() {
    InvestmentCalculator calculator; // Create an object of InvestmentCalculator
    calculator.runCalculator(); // Run the calculator
    return 0;
}
