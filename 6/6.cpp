#include <iostream>
using namespace std;

class Node { // Создаем ноду
public:
    double data;
    Node* next;

    Node(double data) : data(data), next(nullptr) {}
};

class List { // создаем список
public:
    Node* head;

    List() : head(nullptr) {}

    void append(double data) { // Добавляем элементы 
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

    int countElementsGreaterThan7() { // Считаем элементы больше 7 
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (current->data > 7) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    List my_list;
    my_list.append(5);
    my_list.append(10);
    my_list.append(3);
    my_list.append(8);
    my_list.append(12);

    int count = my_list.countElementsGreaterThan7();
    cout << count << endl;
}
