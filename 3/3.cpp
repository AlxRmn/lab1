
#include <iostream>
#include <string>
using namespace std;

struct Node { // Создаем ноду
    string data;
    Node* next;
};

class Stack { // Создаем стек
private:
    Node* top;
    int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(const string& value) { // Добавление элементов в стек
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() { // Удаление элементов из стека
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void print() { // Вывод 
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int countTwoCharStrings() { // Находим количество строк в сткек, состоящих из двух элементов
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            if (current->data.length() == 2) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    Stack stack;

    stack.push("abc");
    stack.push("fx");
    stack.push("glc");
    stack.push("hi");
    stack.push("gogo");

    stack.print();

    stack.pop();
    stack.push("the end");
    stack.print();

    cout << stack.countTwoCharStrings() << endl;

}