#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

string colorize(char c, const string& colorCode) {
    return "\033[" + colorCode + "m" + c + "\033[0m";
}

char getRandomToy() {
    string toys = "@$%#";
    return toys[rand() % toys.size()];
}

void drawTree(int n, ofstream &outfile, bool garlandOn, vector<string>& colors) {
    #ifdef _WIN32
    #else
    system("clear");
    #endif

    int maxWidth = 2 * n - 1; 

    for (int i = 1; i <= n; ++i) {
        
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
            outfile << " ";
        }

        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (rand() % 5 == 0 && garlandOn) { 
                string randomColor = colors[rand() % colors.size()];
                char toy = getRandomToy();
                cout << colorize(toy, randomColor);
                outfile << toy;
            } else {
                cout << "*";
                outfile << "*";
            }
        }
        cout << endl;
        outfile << endl;
    }

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
    srand(time(0));

    int n;
    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    vector<string> colors;
    colors.push_back("31");
    colors.push_back("32");
    colors.push_back("33");
    colors.push_back("34");
    colors.push_back("35");
    colors.push_back("36");

    ofstream outfile("tree_output.txt");

    while (true){
        drawTree(n, outfile, true, colors);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    outfile.close();

    return 0;
}