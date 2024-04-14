#include <iostream>
#include <queue>
using namespace std;

queue <double> q; // Создаем очередь

int negativeElem() { // Считаем количество отрицательных чисел
    int countNegative = 0;
    while (!q.empty()) {
        if (q.front() < 0) {
            countNegative++;
        }
        q.pop();
    }
    return countNegative;
} 

int main() {
    q.push(-5.5);
    q.push(2.3);
    q.push(-1.8);
    q.push(4.9);
    q.push(-3.2);

    cout << "Negative elements: " << negativeElem() << endl;
}
