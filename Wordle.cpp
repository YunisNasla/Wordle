
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {

    vector<string> words;

    words.push_back("chair");
    words.push_back("tiger");
    words.push_back("house");
    words.push_back("smile");
    words.push_back("bread");

    int randomIndex;
    string userGuess;
    bool guessedCorrectly = false;

    srand(time(nullptr));
    randomIndex = int(rand() % 5);
    string randWord = words[randomIndex];

    cout << endl << "Key:" << endl << "If a guessed letter is in the correct position, It will just print it out. Ex: a"
         << endl
         << "If a guessed letter appears in the word but is not in the right position, It will just print it out between parentheses. Ex: (a)"
         << endl << "If a guessed letter does not appear anywhere in the word, It will print out between curly braces. Ex: {a}"
         << endl << "You have 6 attempts to guess the 5-letter word." << endl << endl;


    for (int i = 1; i <= 6; i++) {
        cout << "Attempt " << i << " (MUST BE 5 LETTERS LONG AND IN LOWERCASE): ";
        cin >> userGuess;
        if(userGuess.length() != 5){
            cout << "Invalid Input. You must enter a 5 letter word." << endl;
            i--;
            continue;
        }

        string feedback = "";

        for (int i = 0; i < 5; i++) {
            if (userGuess[i] == randWord[i]) {
                feedback += userGuess[i];
            } else {
                bool found = false;
                for (int j = 0; j < 5; j++) {
                    if (i != j && userGuess[i] == randWord[j]) {
                        feedback += "(" + string(1, userGuess[i]) + ")";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    feedback += "{" + string(1, userGuess[i]) + "}";
                }

            }
        }

        cout << "Feedback: " << feedback << endl;

        if (userGuess == randWord) {
            guessedCorrectly = true;
            break;
        }
    }


    if (guessedCorrectly) {
        cout << "Congratulations! You guessed the word correctly: " << randWord << endl;
    } else {
        cout << "Sorry, you did not guess the word. The correct word was: " << randWord << endl;
    }


}





