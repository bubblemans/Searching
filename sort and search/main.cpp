#include <iostream>
using namespace std;

void sorting(string, string []);
int search(string[], string, int);
int main(){
    string sentence1;
    string sentence2;
    string keyword;
    cout << "Enter a sentence 1:\n";
    getline(cin, sentence1);
    cout << "Enter a sentence2:\n";
    getline(cin, sentence2);
    cout << "Enter a keyword:\n";
    cin >> keyword;
    
    int count1 = 1;
    string space = " ";
    for (int i = 0; i < sentence1.length(); i++) {
        if (sentence1[i] == space[0])
            count1++;
    }
    string saver1[count1];
    
    int count2 = 1;
    for (int i = 0; i < sentence2.length(); i++) {
        if (sentence2[i] == space[0])
            count2++;
    }
    string saver2[count2];
    int sen1rele, sen2rele;
    sorting(sentence1, saver1);
    sorting(sentence2, saver2);
    sen1rele = search(saver1, keyword, count1);
    sen2rele = search(saver2, keyword, count2);
    if ((sen1rele == 0)&&(sen2rele == 0)) {
        cout << "I didn't find it.\n";
    }
    else if (sen1rele > sen2rele) {
        cout << "The sentence 1 is more relevant.\n";
    }
    else if (sen1rele < sen2rele){
        cout << "The sentence 2 is more relevant.\n";
    }
    else
        cout << "They are relevant equally.\n";
    
}

void sorting(string sentence, string saver[]) {
    //string sentence;
    string space = " ";
    string dot = ".";
    string comma = ",";
    string exclamation = "!";
    string questionmark = "?";
    int count = 1;
    
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == space[0])
            count++;
    }
    
    int spaceIndex[count - 1];
    int index = 0;
    
    for (int i = 0; i < sentence.length(); ++i)
    {
        if (sentence[i] == space[0])
        {
            spaceIndex[index] = i;
            index++;
        }
    }
    
    //string saver[count];
    int saverIndex = 0;
    int sentenceIndex = 0;
    while(sentence[sentenceIndex] != '\0')
    {
        saver[saverIndex] += sentence[sentenceIndex];
        sentenceIndex++;
        if (sentence[sentenceIndex] == space[0])
        {
            saverIndex++;
            sentenceIndex++;
        }
        if ((sentence[sentenceIndex] == dot[0])||(sentence[sentenceIndex] == comma[0])||(sentence[sentenceIndex] == exclamation[0])||(sentence[sentenceIndex] == questionmark[0]))
        {
            saverIndex++;
            sentenceIndex++;
            if (sentence[sentenceIndex] == '\0') {
                break;
            }
            else
                sentenceIndex++;
        }
    }
}

int search(string sen[], string key, int size){
    int count = 0;
    bool found = false;
    
    for (int i = 0; i < size; i++) {
        if (sen[i] == key) {
            found = true;
            count++;    
        }
    }
    return count;
}
/*
int main(){
    string sen[5] = {"I", "am", "Alvin.", "And", "you?"};
    string key = "am";
    for (int i = 0; i < 5; i++) {
        cout << i << endl;
        if (sen[i] == key) {
            cout << "true\n";
        }
    }
}
 */
