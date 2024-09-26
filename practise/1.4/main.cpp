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

/*Знаходження суми всіх парних чисел на 
проміжку від 0 до N.*/
 int sum_even_numbers(int N) {
    int sum = 0;
    for ( int i = 0; i<= N; i += 2) {
        sum += i;
    }
    return sum;
 }

 /* Знаходження добутку перших n елементів 
прогресії.*/

double product_arithmetic_progression(double a1, double d, int n) {
    double product = 1;
    for (int i = 1; i <= n; ++i) {
        product *= a1 + (i - 1) * d;
    }
    return product;
}

/* Протабулювати (знайти значення) функції 
f (x) = cos x
на проміжку від 0 до π з кроком h=0.01*/

int main() {
    int N = 5;
    cout << "Сума чисел від 1 до " << N << ": " << sum_numbers(N) << endl;


    N = 5;
    cout << "Факторіал числа " << N << ": " << factorial(N) << endl;


    N = 10;
    cout << "Сума парних чисел від 0 до " << N << ": " << sum_even_numbers(N) << endl;


    double a1 = 2, d = 3, n = 5;
    cout << "Добуток перших " << n << " елементів арифметичної прогресії з a1 " << a1 << " i d = " <<  product_arithmetic_progression(a1, d, n) << endl;

    double start = 0, end = M_PI, step = 0.01;
    cout << "Таблиця значеннь функції cos(x) на проміжку від 0 до π з кроком 0.01: " << endl;
    void tabulate_cos(double start, double end, double step);


    return 0;
}