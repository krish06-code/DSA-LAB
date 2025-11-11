#include <bits/stdc++.h>
using namespace std;

string concat(string st1, string st2) {
    st1.append(st2);
    return st1;
}

string reverse(string st1) {
    reverse(st1.begin(), st1.end());
    return st1;
}

string delete_vowels(string st1) {
    string st2;
    for (char ch : st1) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
        else st2 += ch;
    }
    return st2;
}

string sort(string st1) {
    sort(st1.begin(), st1.end());
    return st1;
}

char upp_to_low(char ch) {
    return tolower(ch);
}

int main() {
    string test1 = "Krish sareen";
    string test2 = " hello";
    string test3 = "hello";
    string test4 = "this";
    char test5 = 'A';

    cout << concat(test1, test2) << endl;
    cout << reverse(test2) << endl;
    cout << delete_vowels(test3) << endl;
    cout << sort(test4) << endl;
    cout << upp_to_low(test5) << endl;

    return 0;
}