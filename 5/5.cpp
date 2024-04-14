
#include <iostream>
#include <stack>

using namespace std;

bool isTrue(string str) {
    stack<char> s; // Создаем стек

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } // Определяем последовательность
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            } // Если последовательно не совпадает возвращаем false

            char top = s.top();
            s.pop(); 

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string str;
    cin >> str;

    if (isTrue(str)) {
        cout << "The string is true" << endl;
    }
    else {
        cout << "The string is false" << endl;
    }

}
