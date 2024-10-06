#include <iostream>

using namespace std;

int main() {
 
    char symbol1, symbol2;

    const char CONSTANT1 = 'A';
    const char CONSTANT2 = 'Z';

    char symbol3 = '1', symbol4 = 'p', symbol5 = '№';


    char symbol6 = 0x7a; // Літера 'z'
    char symbol7 = 0x3b; // Символ ';'
    char symbol8 = 0x9; // Символ табуляції


    cout << "Символьні змінні та константи:" << endl;
    cout << "symbol1: " << symbol1 << endl;
    cout << "symbol2: " << symbol2 << endl;
    cout << "CONSTANT1: "  << CONSTANT1 << endl;
    cout << "CONSTANT2: " << CONSTANT2 << endl;
    cout << "symbol3: " << symbol3 << endl;
    cout << "symbol4: " << symbol4 << endl;
    cout << "symbol5: " << symbol5 << endl;
    cout << "symbol6: " << symbol6 << endl;
    cout << "symbol7: " << symbol7 << endl;
    cout <<  "symbol8: " << symbol8 << endl;

    
    



     int intVar = 3841;
     float floatVar = 954.67;
     unsigned short ushortVar = 6429;


     double doubleVar;
     int intVar2;
     char charVar;

     // Неявнее приведення
     doubleVar = intVar;
     intVar2 = floatVar;
     charVar = ushortVar;

     cout << "Неявне приведення" << endl;
     cout << "doubleVar = " << doubleVar << endl;
     cout << "intVar2 = " << intVar2 << endl;
     cout << "charVar = " << charVar << endl;

     //Явне приведення
     doubleVar = (double)ushortVar;
     intVar2 = (int)floatVar;
     charVar = (char)intVar;

     cout << "Явне приведення:" << endl;
     cout << "doubleVar = " << doubleVar << endl;
     cout << "intVar2 = " << intVar2 << endl;
     cout << "charVar = " << charVar << endl;

     // Обхід суворої типізації (C-style cast)
     doubleVar = (double)intVar2;
     intVar2 = (int)doubleVar;
     charVar = (char)intVar2;

     cout << "C-style cast:" << endl;
     cout << "doubleVar = " << doubleVar << endl;
     cout << "intVar2 = " << intVar2 << endl;
     cout << "charVar = " << charVar << endl;

     return 0;
}





   
