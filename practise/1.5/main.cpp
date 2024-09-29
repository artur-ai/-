/*
Stud: Maiboroda Artur
Group: 121
prac 1.5
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cout << "Введіть розмір послідовності: ";
    cin >> n;

    
    vector<int> A(n);

  
    cout << "Введіть елементи послідовності: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }


    int P;
    cout << "Введіть значення P: ";
    cin >> P;

    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == P) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Індекс першого входження P: " << index << endl;
    } else {
        cout << "Значення P не знайдено в послідовності." << endl;
    }

  
    int minPositive = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        if (A[i] > 0 && A[i] < minPositive) {
            minPositive = A[i];
        }
    }

    if (minPositive != numeric_limits<int>::max()) {
        cout << "Найменше додатне значення: " << minPositive << endl;
    } else {
        cout << "Немає додатних елементів у послідовності." << endl;
    }

    
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (A[i] < A[minIndex]) {
            minIndex = i;
        }
        if (A[i] > A[maxIndex]) {
            maxIndex = i;
        }
    }

    swap(A[minIndex], A[maxIndex]);
    cout << "Послідовність після заміни: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}