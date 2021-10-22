#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    // a)
    string word1, word2, word3;
    cout << "Enter word 1: ";
    cin >> word1;
    cout << "Enter word 2: ";
    cin >> word2;
    cout << "Enter word 3: ";
    cin >> word3;

    // b)
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << sentence << endl << endl;

    // c)
    cout << "Length word 1: " << word1.length() << endl;
    cout << "Length word 2: " << word2.length() << endl; 
    cout << "Length word 3: " << word3.length() << endl;
    cout << "Length sentence: " << sentence.length() << endl << endl;

    // d)
    string sentence2 = sentence;

    // e)
    for(int i = 0; i < sentence.length(); i++) {
        if(i >= 9 && i < 12) {
            sentence2[i] = 'x';
        }
    }
    cout << "Sentence: " << sentence << endl;
    cout << "Sentence2: " << sentence2 << endl << endl;

    // f)
    char sentence_start[6]{};
    sentence.copy(sentence_start, 5);
    cout << "Sentence: " << sentence << endl;
    cout << "Sentence_start: " << sentence_start << endl << endl;

    // g)
    char tempG[6]{};
    bool containsHello = false;
    for(int i = 0; i <= sentence.length() - 5; i++) {
        sentence.copy(tempG, 5, i);
        if(strcmp(tempG, "hallo") == 0) {
            containsHello = true;
            break;
        }
    }
    cout << "Sentence contains 'hello': " 
        << boolalpha << containsHello << endl;

    // h)
    char tempH[3]{};
    vector<int> positions = {};
    for(int i = 0; i <= sentence.length() - 2; i++) {
        sentence.copy(tempH, 2, i);
        if(strcmp(tempH, "er") == 0) {
            positions.push_back(i + 1);
        }
    }
    cout << "Found 'er' at positions: ";
    for (int n : positions) {
        std::cout << n << ", ";
    }
}