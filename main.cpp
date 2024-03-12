#include <iostream>
#include <iomanip>
using namespace std;

string setupUnsolved(string);

char getGuess(string);

string updateUnsolved(string,string,char);

int main()
{
    string phrase;           
    char guess;              
    string prevGuesses = "";   
    int mistakesAllowed = 7;   
    string unsolved = "";     

    cout << "Enter phrase: ";
    getline(cin, phrase);
    unsolved = setupUnsolved(phrase);
    cout << "Phrase: " << unsolved << "\n";
    bool notWin = true;
    do
    {
        guess = getGuess(prevGuesses);
        prevGuesses += guess;
        cout << "Guessed so far: " << prevGuesses << endl;
        int indexOfGuess = phrase.find(guess);
        char upperGuess = guess - 32;
        if(tolower(upperGuess) == guess)
        {
            int indexOfUGuess = phrase.find(upperGuess);
            if(indexOfGuess >= 0 && indexOfGuess < phrase.size())
            {
                unsolved = updateUnsolved(phrase,unsolved,guess);
            }
            else if (indexOfUGuess >= 0 && indexOfUGuess < phrase.size())
            {
                unsolved = updateUnsolved(phrase,unsolved,upperGuess);
            }
            else
            {
                mistakesAllowed--;
            }
            cout << "Wrong guesses left: " << mistakesAllowed << endl;
            cout << unsolved << "\n\n";

            if(phrase == unsolved)
            {
                  notWin = false;
            }
        }
    }
    while(mistakesAllowed > 0 && notWin);

    if(notWin || phrase == unsolved)
    {
        cout << "Congratulations!! You won!\n";
    }
    else
    {
        cout << "You lost!\n";
    }
  
    return 0;
}

string setupUnsolved(string phrase)
{
    string unsolved = "";
    for(int i = 0; i < phrase.size(); i++)
    {
        if(phrase.at(i) == ' ')
        {
            unsolved += ' '; 
        }
        else if(isalpha(phrase.at(i)))
        {
            unsolved += '-';
        }
        else
        {
            unsolved += phrase.at(i);
        }
    }
    return unsolved;
}

char getGuess(string prevGuesses)
{
    char guess;
    cout << "Enter a guess: ";
    cin >> guess;
    bool repeat = false;
    do
    {
        for(int i =0; i < prevGuesses.size(); i++)
        {
            if(prevGuesses.at(i) == guess)
            {
                repeat = true;
            }
        }
        if(!isalpha(guess) || repeat || (guess < 'a'))
        {
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
            repeat = false;
            for(int i =0; i < prevGuesses.size(); i++)
            {
                if(prevGuesses.at(i) == guess)
                {
                    repeat = true;
                }
            }
        }
    }
    while(!isalpha(guess) || repeat || (guess < 'a'));
    return guess;
}

string updateUnsolved(string phrase, string unsolved, char guess)
{
    string updated = "";
    for(int i = 0; i < phrase.size(); i++)
    {
        if(phrase.at(i) == guess)
        {
            updated += guess;
        }
        else
        {
            updated += unsolved.at(i);
        }
    }
    return updated;
}