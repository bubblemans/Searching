//This is written by Hung Yeh Lin
#include <iostream>

using namespace std;

int main() {
    string sentence = "I am Hung Yeh Lin. How are you?";
    string keyword;
    bool found = false;
    
    cout << "Enter a keyword:\n";
    cin >> keyword;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == keyword[0]) {
            for (int k = 0; k < keyword.length(); k++) {
                if (sentence[i+k] == keyword[k]){
                    found = true;
                }
                else
                    found = false;
            }
            if (found){
                cout << "I found it.\n";
                break;
            }
            else
                cout <<"I didn't find it.\n";
        }
    }
}
