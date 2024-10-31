#include <iostream>
using namespace std;

struct Node {
    int data;         
    Node* next;      
};

inline int processValue(int value) {
    return value * 2;
}

Node* createFirstList(int numElements) {
    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < numElements; ++i) {
        int value;
        cout << "Введіть значення для елемента " << (i + 1) << ": ";
        cin >> value;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

Node* createSecondList(Node* firstListHead) {
    Node* secondListHead = nullptr;
    Node* current = nullptr;

    Node* temp = firstListHead;
    while (temp) {
        int processedValue = processValue(temp->data);

        Node* newNode = new Node;
        newNode->data = processedValue;
        newNode->next = nullptr;

        if (!secondListHead) {
            secondListHead = newNode;
            current = secondListHead;
        } else {
            current->next = newNode;
            current = newNode;
        }

        temp = temp->next;
    }

    return secondListHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int numElements;
    cout << "Введіть кількість елементів для першого списку: ";
    cin >> numElements;

    Node* firstList = createFirstList(numElements);
    cout << "Перший список: ";
    printList(firstList);

    Node* secondList = createSecondList(firstList);
    cout << "Другий список (оброблені значення): ";
    printList(secondList);

    while (firstList) {
        Node* temp = firstList;
        firstList = firstList->next;
        delete temp;
    }

    while (secondList) {
        Node* temp = secondList;
        secondList = secondList->next;
        delete temp;
    }

    return 0;
}
