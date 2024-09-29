/*
Student: Maiboroda Artur
Group: 121
lab 1.5 
*/


#include <iostream>

using namespace std;

int main() {
    bool bVar1 = true;
    bool bVar2 = false;
    const int CONSTA = 49;
    int nB = -65;
    int nE = 2;
    int nC;
    int* pnC = &nC;

    *pnC = 23;
    int resultR = (nB + nE);
    int resultL = nB * nE;
    bool bRez = ((CONSTA ^ ~nB) - *pnC) >= (1 * (nE << sizeof(short)));

    cout << "Логічна змінна 1: " << bVar1 << endl;
    cout << "Логічна змінна 2: " << bVar2 << endl;
    cout << "Константа CONSTA: " << CONSTA << endl;
    cout << "Результат R-expression: " << resultR << endl;
    cout << "Результат L-expression: " << resultL << endl;
    cout << "Результат expression bRez: " << bRez << endl;

    return 0;
}