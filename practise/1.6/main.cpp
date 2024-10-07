#include <iostream>
#include <cstdlib>  // Для генерації випадкових чисел
#include <ctime>    // Для ініціалізації рандомізації


using namespace std;

// Функція для перевірки, чи повинна бути іграшка на місці
bool isToy() {
    return rand() % 5 == 0; // 20% ймовірність, що буде іграшка
}

// Функція для отримання символу іграшки
char getToy() {
    char toys[] = {'@', '$', '%', '#'};
    return toys[rand() % 4]; // Випадковий символ іграшки
}

// Функція для виводу ялинки
void drawTree(int n, bool toggle) {
    int maxWidth = n * 2 + 1;  // Максимальна ширина ялинки

    for (int level = 1; level <= n; ++level) {
        for (int row = 1; row <= level + 1; ++row) {
            int stars = row * 2 - 1;  // Кількість зірочок у рядку
            int spaces = (maxWidth - stars) / 2;

            // Виведення пробілів перед зірочками
            for (int s = 0; s < spaces; ++s)
                cout << " ";

            // Виведення рядка з зірочок та іграшок
            for (int st = 0; st < stars; ++st) {
                if (isToy()) {
                    // Якщо toggle включений, іграшка буде з кольором
                    if (toggle) {
                        cout << "\033[1;31m" << getToy() << "\033[0m"; // Червоний колір
                    } else {
                        cout << "\033[1;32m" << getToy() << "\033[0m"; // Зелений колір
                    }
                } else {
                    cout << "*";  // Виведення зірочки
                }
            }

            cout << endl;
        }
    }

    // Виведення стовбура ялинки
    for (int i = 0; i < 2; ++i) {
        for (int s = 0; s < (maxWidth - 3) / 2; ++s)
            cout << " ";
        cout << "###" << endl;
    }
}

int main() {
    srand(time(0));  // Ініціалізуємо рандомізацію

    int n;
    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    bool toggle = true;  // Для чергування кольорів гірлянд

    // Симуляція миготіння ялинки
    for (int i = 0; i < 10; ++i) {
        system("cls");  // Очищення екрану для оновлення ялинки
        drawTree(n, toggle);  // Малюємо ялинку з відповідним кольором
        toggle = !toggle;  // Змінюємо стан миготіння
       
    }

    return 0;
}
