#include <iostream>
#include <valarray>
#include <cstddef>
using namespace std;

int main() {
    string sentence;
    string space = " ";
    string dot = ".";
    string comma = ",";
    string exclamation = "!";
    string questionmark = "?";
    int count = 1;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);
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

    string saver[count];
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
    for (int i = 0; i < count; ++i)
    {
    	cout << saver[i] << endl;
    }
}
