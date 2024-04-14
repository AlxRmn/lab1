#include <iostream>
#include <string>
using namespace std;

class Node { // Создаем ноду
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue { // Создаем очередь
public:
    Node* front;
    Node* rear;

    Queue() {
        front = rear = nullptr;
    }

    void enqueue(string data) { // Добавление элемента в очередь
        Node* newNode = new Node(data);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue() { // Удаление элемента из очереди
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return "";
        }

        string data = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return data;
    }

    void printQueue() { // Вывод очереди
        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int countStringsStartingWith(char c) { // Количество строк начинающихся с f или t 
        int count = 0;
        Node* temp = front;

        while (temp != nullptr) {
            if (temp->data[0] == c) {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }
};

int main() {
    Queue queue;

    queue.enqueue("one");
    queue.enqueue("two");
    queue.enqueue("three");
    queue.enqueue("four");
    queue.enqueue("five");
    queue.enqueue("six");

    cout << "Queue: ";
    queue.printQueue();

    queue.dequeue();
    queue.dequeue();


    queue.printQueue();
    queue.enqueue("seven");
    queue.printQueue();

    int count = queue.countStringsStartingWith('f');
    cout << count << endl;

    count = queue.countStringsStartingWith('t');
    cout << count << endl;

    return 0;
}
