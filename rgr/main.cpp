#include <iostream>
#include <string>
#include <cctype>

bool isValid(const std::string& str) {
    int i = 0;
    int len = str.length();

    if (str[i] != '(') return false;
    i++;

    if (i >= len || str[i] < '5' || str[i] > '9') return false;
    while (i < len && str[i] >= '5' && str[i] <= '9') i++;

    if (i >= len || (str[i] != '%' && str[i] != '*')) return false;
    i++;

    if (i >= len || str[i] < 'A' || str[i] > 'Z') return false;
    while (i < len && str[i] >= 'A' && str[i] <= 'Z') i++;

    if (i >= len || str[i] != ')') return false;
    i++;

    return i == len;
}

int main() {
    std::string input;
    std::cout << "Введіть ланцюжок: ";
    std::cin >> input;

    if (isValid(input)) {
        std::cout << "Ланцюжок належить мові L(V)" << std::endl;
    } else {
        std::cout << "Ланцюжок не належить мові L(V)" << std::endl;
    }

    return 0;
}
