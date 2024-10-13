#include <iostream>
#include <windows.h>

using namespace std;



int main() {


    SetConsoleCP(1251); // Кодова сторінка для вводу
    SetConsoleOutputCP(1251); // Кодова сторінка для виводу
    std::cout << "Привіт, світе!" << std::endl;
  


    double num1, num2;
    char operation;

    cout << "Введіть перше число: ";
    cin >> num1;

    cout << "Введіть операцію (+, -, *, /): ";
    cin >> operation;

    cout << "Введіть друге число: ";
    cin >> num2;

    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Помилка: ділення на нуль" << endl;
            } else {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Невірна операція" << endl;
    }

    return 0;
}