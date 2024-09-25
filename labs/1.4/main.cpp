/*
Name: Maiboroda Artur
Group: 121
lab 4

*/

#include <iostream>
using namespace std;

// Опис Змінних 

int main () {
    unsigned short us = 612;
    int i = -805;
    float f = 14.4328;
    double d = -30.22e100;


    // Опис вказівників
    unsigned short *pus =  nullptr;
    int *pi =  nullptr;
    float *pf =  nullptr;
    double *pd =  nullptr;


     // Нетипізований вказівник (void*)
     void *pv =  nullptr;

     // 4. Ініціювання вказівних змінних адресами
    pus = &us;
    pi = &i;
    pf = &f;
    pd = &d;

      // Ініціалізація значень через розіменування
      *pus = 200;
      *pi = -200;
      *pf = 3.14;
      *pd = 2.7123;

      // Визначення розміру змінних
      cout << "Size of unsigned short: " <<sizeof(us) << "bytes" <<endl;
      cout << "Size of int: " << sizeof(i) << "bytes" << endl; 
      cout << "Size of float: " << sizeof(f) << "bytes" << endl;
      cout << "Size of double: " << sizeof(d) << "bytes" << endl;
      cout << "Size of pointer: " << sizeof(pus) << " bytes" << endl;


      // Використання нетипізованого вказівника (з явним приведенням типів)
     pv = pus;
    cout << "Value of us through void pointer: " << *(unsigned short*)pv << endl;

      return 0;
}

