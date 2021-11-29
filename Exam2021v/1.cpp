#include <iostream>
#include <functional>

using namespace std;

int getAnswer() {
    return 42;
}

void getAnswer(int &answer) {
    answer = 42;
}

void getAnswer(int *&answer) {
    answer = new int(42);
}

void getAnswer(const function<void(int)> &callback) {
    callback(42);
}

int main() {
    cout << getAnswer() << endl;

    int answer1;
    getAnswer(answer1);
    cout << answer1 << endl;

    int *answer2;
    getAnswer(answer2);
    cout << *answer2 << endl;

    delete answer2;
    getAnswer([](int answer) {
        cout << answer << endl;
    });

    return 0;
}
