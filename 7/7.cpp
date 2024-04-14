#include <iostream>
using namespace std;

class Node { // Создаем ноду
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class List { // Создаем линейный однонаправленный список из целых числе
public:
    Node* head;

    List() : head(nullptr) {}

    void append(int data) { // Добавляем элементы в список
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void insertAfterMod2(int value, int insertValue) { // Вставляем в список число после каждого элемента, по модулю меньшего 2.
 
        Node* current = head;
        while (current != nullptr) {
            if (abs(current->data) < 2) {
                Node* new_node = new Node(insertValue);
                new_node->next = current->next;
                current->next = new_node;
                current = new_node->next;
            }
            else {
                current = current->next;
            }
        }
    }

    void print() { // Вывод
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

    }
};

int main() {
    List my_list;
    my_list.append(1);
    my_list.append(-2);
    my_list.append(3);
    my_list.append(-1);
    my_list.append(0);


    my_list.print();

    my_list.insertAfterMod2(15, 15);

    my_list.display();


}
