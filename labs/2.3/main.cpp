#include <iostream>
#include <vector>
#include <stdexcept>
#include <ctime>

using namespace std;

struct Stack {
    vector<double> data;
    int maxSize = 10;

    void push(double value) {
        if (data.size() >= maxSize) {
            throw overflow_error("Stack overflow: неможливо додати елемент, стек переповнений");
        }
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw underflow_error("Stack underflow: неможливо видалити елемент, стек порожній");
        }
        data.pop_back();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            throw underflow_error("Queue underflow: неможливо видалити елемент, черга порожня");
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

    //Векторний стек з дійсними числами
int main() {
    srand(time(0));

    Stack myStack;
    double elements[10] = {1.5, 2.3, 4.8, 3.0, 5.6, 7.2, 8.1, 6.4, 9.9, 0.1};

    int N = rand() % 10;
    cout << "Додаємо " << N << " елементів у стек." << endl;
    for (int i = 0; i < N; ++i) {
        try {
            myStack.push(elements[i]);
            cout << "Додано до стека: " << elements[i] << endl;
        } catch (const overflow_error &e) {
            cerr << e.what() << endl;
        }
    }

    int M = rand() % 16;
    cout << "Видаляємо " << M << " елементів зі стека." << endl;
    for (int i = 0; i < M; ++i) {
        try {
            myStack.pop();
            cout << "Елемент видалено зі стека." << endl;
        } catch (const underflow_error &e) {
            cerr << e.what() << endl;
            break;
        }
    }

    //Зв'язана черга з цілими числами
    Queue myQueue;
    int queueElements[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    N = rand() % 10;
    cout << "\nДодаємо " << N << " елементів у чергу." << endl;
    for (int i = 0; i < N; ++i) {
        myQueue.enqueue(queueElements[i]);
        cout << "Додано до черги: " << queueElements[i] << endl;
    }

    M = rand() % 16;
    cout << "Видаляємо " << M << " елементів з черги." << endl;
    for (int i = 0; i < M; ++i) {
        try {
            myQueue.dequeue();
            cout << "Елемент видалено з черги." << endl;
        } catch (const underflow_error &e) {
            cerr << e.what() << endl;
            break;
        }
    }

    return 0;
}
