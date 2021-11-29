#include <iostream>
using namespace std;

//  < = &lt;
//  > = &gt;
//  & = &amp;
string escape(const string &input) {
    string output;
    output.reserve(input.size());
    for(const char &c : input) {
        switch(c) {
            case '<':
                output += "&lt;";
                break;
            case '>':
                output += "&gt;";
                break;
            case '&':
                output += "&amp;";
                break;
            default:
                output += c;
                break;
        }
    }
    return output;
}

void escape(string &input) {
    for(size_t i = 0; i < input.size();) {
        switch(input[i]) {
            case '<':
                input[i] ='&';
                input.insert(i, "lt;");
                i += 4;
                break;
            case '>':
                input[i] ='&';
                input.insert(i, "gt;");
                i += 4;
                break;
            case '&':
                input[i] ='&';
                input.insert(i, "amp;");
                i += 5;
                break;
            default:
                i++;
                break;
        }
    }
}

int main() {
    cout << escape("Escape these symbols: <<&>>") << endl;
    string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;

    return 0;
}
