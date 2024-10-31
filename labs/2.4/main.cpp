#include <iostream>
#include <cmath>

using namespace std;

double calculateFunction(double x) {
    if (x >= 0) {
        // Обчислення для x >= 0
        return pow(x, 2) + 4 * pow(x, x) + 2;
    } else {
        // Обчислення для x < 0
        double product = 1;
        for (int i = 1; i <= 4; ++i) {
            product *= (x + pow(x, i - 1));
        }
        return 4 * product;
    }
}

int main() {
    double x_start = -5;
    double x_end = 4;
    double h = 0.25;

    cout << "x\t\ty" << endl;
    cout << "------------------------" << endl;

    for (double x = x_start; x <= x_end; x += h) {
        double y = calculateFunction(x);
        cout << x << "\t\t" << y << endl;
    }

    return 0;
}
