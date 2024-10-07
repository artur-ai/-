/*
Name: Maiboroda Artur
Group: 121
prac 1.6
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread> // Для пауз
#include <chrono> // Для задержек

using namespace std;

char getRandomToy() {
    char toys[] = {'@', '$', '%', '#'}; // Варианты игрушек
    return toys[rand() % 4];            // Возвращаем случайную игрушку
}

void drawTree(int n, ofstream &outfile, bool garlandOn) {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Рисуем уровни ялинки
    for (int i = 1; i <= n; ++i) {
        // Отступы слева для формирования треугольной формы
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
            outfile << " ";
        }
        // Звезды и игрушки
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (rand() % 5 == 0) { // 20% шанс для появления игрушки
                char toy = getRandomToy();
                if (garlandOn) {
                    cout << toy;
                    outfile << toy;
                } else {
                    cout << "*";
                    outfile << "*";
                }
            } else {
                cout << "*";
                outfile << "*";
            }
        }
        cout << endl;
        outfile << endl;
    }

    // Рисуем ствол ялинки
    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= n - 2; ++j) {
            cout << " ";
            outfile << " ";
        }
        cout << "###" << endl;
        outfile << "###" << endl;
    }
}

int main() {
    int n;
    cout << "Введите количество уровней ялинки: ";
    cin >> n;

    // Открываем файл для записи
    ofstream outfile("yalynka.txt");

    // Основной цикл для мигания гірлянды
    for (int i = 0; i < 10; ++i) { // 10 итераций мигания гірлянды
        system("clear"); // Очищаем консоль (на Windows используйте "cls")
        bool garlandOn = (i % 2 == 0); // Переключаем состояние гирлянды (вкл/выкл)

        drawTree(n, outfile, garlandOn);

        // Пауза для "мигания" гирлянды
        this_thread::sleep_for(chrono::milliseconds(500)); // 0.5 секунды паузы
    }

    // Закрываем файл
    outfile.close();

    return 0;
}
