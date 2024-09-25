/*
Student: Maiboroda Artur
Group: 121
prac: 1.4
*/

#include <iostream>
#include <cmath>
using namespace std;


// Функція для обчислення суми чисел від 1 до N
int sum_numbers(int N) {
    int sum = 0;
    for (int i = 1; i <= 5; ++i) {
        sum += i;
    }
    return sum;
}

// Функція для обчислення факторіалу числа N

int factorial(int N ) {
    int fact = 1;
    for (int i = 2; i <= N; ++i) {
        fact *= i;
    }
    return fact;
}