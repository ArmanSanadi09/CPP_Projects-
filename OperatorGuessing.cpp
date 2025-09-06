#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char getRandomOperator() {
    char ops[] = {'+', '-', '*', '/'};
    return ops[rand() % 4];
}

int main() {
    srand(time(0));
    int num1, num2, correctAnswer, userAnswer;
    char op;

    cout << "\n--- Operator Guessing Game ---\n";
    cout << "Rules:\n";
    cout << "1. I will give you an expression without an operator.\n";
    cout << "2. You must guess which operator (+, -, *, /) makes it correct.\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < 5; i++) { // 5 rounds
        num1 = rand() % 20 + 1;  // random numbers 1–20
        num2 = rand() % 20 + 1;
        op = getRandomOperator();

        // Calculate correct answer
        switch (op) {
            case '+': correctAnswer = num1 + num2; break;
            case '-': correctAnswer = num1 - num2; break;
            case '*': correctAnswer = num1 * num2; break;
            case '/': correctAnswer = num2 != 0 ? num1 / num2 : 0; break;
        }

        // Display question
        cout << "\nRound " << (i + 1) << ":\n";
        cout << "Expression: " << num1 << " ? " << num2 << " = " << correctAnswer << endl;
        cout << "Guess the operator (+, -, *, /): ";
        char userOp;
        cin >> userOp;

        if (userOp == op) {
            cout << "✅ Correct! The operator was " << op << ".\n";
        } else {
            cout << "❌ Wrong! The correct operator was " << op << ".\n";
        }
    }

    cout << "\nGame Over! Thanks for playing.\n";
    return 0;
}