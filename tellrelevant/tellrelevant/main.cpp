#include <iostream>
using namespace std;

int search(string, string);
int main() {
    string sentence1 ;
    string sentence2 ;
    int sentence1num, sentence2num;
    string keyword;
    
    cout << "Enter a sentence 1:\n";
    getline(cin, sentence1);
    cout << "Enter a sentence2:\n";
    getline(cin, sentence2);
    cout << "Enter a keyword:\n";
    cin >> keyword;
    sentence1num = search(sentence1, keyword);
    sentence2num = search(sentence2, keyword);
    if ((sentence1num == 0)&&(sentence2num == 0)) {
        cout << "I didn't find it.\n";
    }
    else if (sentence1num > sentence2num) {
        cout << "The sentence 1 is more relevant.\n";
        cout << sentence1 << endl;
    }
    else if (sentence1num < sentence2num){
        cout << "The sentence 2 is more relevant.\n";
        cout << sentence2 << endl;
    }
    else
        cout << "They are relevant equaaly.\n";
}

int search(string sen, string key){
    int count = 0;
    bool found = false;
    
    for (int i = 0; i < sen.length(); i++) {
        if (sen[i] == key[0]) {
            for (int k = 0; k < key.length(); k++) {
                if (sen[i+k] == key[k]){
                    found = true;
                }
                else
                    found = false;
            }
            if (found)
                count++;
        }
    }
    return count;
}
