#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)){

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            s[i] -= 32;
        } else if(s[i]=='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){continue;}
        else { {
            s[i] = tolower(s[i]);
        }
    }
    }

    cout << s << '\n';
}
    return 0;
}
