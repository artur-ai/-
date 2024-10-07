#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

string colorize(char c, const string& colorCode) {
    return "\033[" + colorCode + "m" + c + "\033[0m";
}

char getRandomToy() {
    string toys = "@$%#*";
    return toys[rand() % toys.size()];
}

void drawTree(int n, ofstream &outfile, bool garlandOn, const string& colorCode) {
    srand(time(0));

    // Очищення консолі
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
            outfile << " ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (rand() % 5 == 0 && garlandOn) {
                cout << colorize(getRandomToy(), colorCode);
                outfile << colorize(getRandomToy(), colorCode);
            } else {
                cout << "*";
                outfile << "*";
            }
        }
        cout << endl;
        outfile << endl;
    }

    // Стовбур
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
    int n, numFlashes;
    string color = "32"; // Зелений колір (можна змінити)

    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    cout << "Введіть кількість мигань гірлянди: ";
    cin >> numFlashes;

    // ... (перевірка вводу)

    ofstream outfile("yalynka.txt");

    for (int i = 0; i < numFlashes; ++i) {
        bool garlandOn = (i % 2 == 0);
        drawTree(n, outfile, garlandOn, color);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    outfile.close();
    return 0;
}