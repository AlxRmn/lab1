#include <iostream> 

using namespace std;

struct Node { // Сооздание ноды
    float data;
    Node* next;
};

class LinkedList { // Создаем линейный однонаправленный спсиок 
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    void addNode(float value) { // Добавляем ноду
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    int countElementSeven() { // Определяем количество элементов больше 7
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

    LinkedList list;
    list.addNode(9.5);
    list.addNode(4.2);
    list.addNode(8.1);
    list.addNode(2.3);
    list.addNode(6.7);

    cout << list.countElementSeven() << endl;
}
