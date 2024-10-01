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

    return 0;
}