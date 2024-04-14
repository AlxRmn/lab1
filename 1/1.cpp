#include <iostream>
#include <vector>
using namespace std;

vector <int> stack; // Созадем стек

void push(int elem) {
    stack.push_back(elem);
} // Добавляем элементы в стек

int top() {
    int* v1 = &stack.back();
    return *v1;
} // Вывод указателя на вершину

int main() {
    int n = 5;
    push(1);
    push(4);
    push(7);
    push(100);
    push(2);

    cout << top();
}

