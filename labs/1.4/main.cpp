/*
Name: Maiboroda Artur
Group: 121
lab 4

*/

#include <iostream>
#include <stdio.h>

// Опис Змінних 

int main () {
    unsigned short us = 612;
    int i = -805;
    float f = 14.4328;
    double d = -30.22e100;


    // Опис вказівників
    unsigned short *pus = &us;
    int *pi = &i;
    float *pf = &f;
    double *pd = &d;


     // Нетипізований вказівник (void*)
     void *pv = &pus; // Вказує на вказівник на unsigned short


      // Ініціалізація значень через розіменування
      *pus = 200;
      *pi = -200;
      *pf = 3.14;
      *pd = 2.7123;

      // Визначення розміру змінних
      printf("Size of unsigned short: %zu bytes/n", sizeof (us));
      printf("Size of int: %zu bytes/n",sizeof (i));
      printf("Size of float: %zu bytes/n", sizeof (f));
      printf("Size of double: %zu bytes/n", sizeof (d));

      // Використання нетипізованого вказівника (з явним приведенням типів)
      printf("Value of us through void pointer: %d/n", *(unsigned short*)pv );

      return 0;
}

