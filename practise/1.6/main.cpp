#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

// Функція для додавання кольору до символу
string colorize(char c, const string& colorCode) {
    return "\033[" + colorCode + "m" + c + "\033[0m";
}

// Функція для отримання випадкової іграшки
char getRandomToy() {
    string toys = "@$%#";
    return toys[rand() % toys.size()];
}

// Функція для відображення ялинки
void drawTree(int n, ofstream &outfile, bool garlandOn, vector<string>& colors) {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    // Очищення консолі
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    int maxWidth = 2 * n - 1; // Максимальна ширина ялинки

    for (int i = 1; i <= n; ++i) {
        // Виведення пробілів для вирівнювання трикутників
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
            outfile << " ";
        }

        // Виведення зірочок та іграшок
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (rand() % 5 == 0 && garlandOn) { // Випадково визначаємо, чи буде гірлянда
                string randomColor = colors[rand() % colors.size()]; // Випадковий колір
                char toy = getRandomToy(); // Випадкова іграшка
                cout << colorize(toy, randomColor); // Виведення кольорової іграшки
                outfile << toy; // Запис в файл (без кольору, так як файл не підтримує кольори)
            } else {
                cout << "*"; // Виведення зірочки
                outfile << "*"; // Запис в файл
            }
        }

        cout << endl;
        outfile << endl;
    }

    // Виведення стовбура
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n - 2; ++j) {
            cout << " ";
            outfile << " ";
        }
        cout << "###" << endl;
        outfile << "###" << endl;
    }
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int n;
    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    int numFlashes = 20; // Кількість разів, коли гірлянди будуть мигати

    // Ініціалізація кольорів (вектор без списку ініціалізації)
    vector<string> colors;
    colors.push_back("31"); // Червоний
    colors.push_back("32"); // Зелений
    colors.push_back("33"); // Жовтий
    colors.push_back("34"); // Синій
    colors.push_back("35"); // Пурпуровий
    colors.push_back("36"); // Блакитний

    ofstream outfile("tree_output.txt"); // Відкриття файлу для запису

    // Створення ефекту миготіння гірлянд
    for (int i = 0; i < numFlashes; ++i) {
        bool garlandOn = (i % 2 == 0); // Включення та виключення гірлянд
        drawTree(n, outfile, garlandOn, colors); // Виведення ялинки з поточним станом гірлянд
        this_thread::sleep_for(chrono::milliseconds(500)); // Затримка перед наступним оновленням
    }

    outfile.close(); // Закриття файлу після завершення запису

    return 0;
}
