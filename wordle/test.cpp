#include <igloo/igloo.h>
#include "main.h"

using namespace igloo;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>


Context(TestDataCollect){
    Spec(testLoadWords){
        vector<string> words = loadWords("./Test/word_test.txt");
        vector<string> fruits = {"apple", "banana", "orange", "mango"};
        Assert::That(words, Equals(fruits));    
    };

    Spec(testAllowedWords){
        vector<string> allowedWords = loadAllowedWords("./Test/word_test.txt");
        vector<string> fruits = {"apple", "banana", "orange", "mango"};
        Assert::That(allowedWords, Equals(fruits));    
    }

    Spec(testGetRandomWord){
        // Initialize random number generator
        srand(time(NULL));
        string randomWord = getRandomWord({"apple", "banana", "orange", "mango"});
        Assert::That(randomWord == "apple" || randomWord == "banana" || randomWord == "orange" || randomWord == "mango", Equals(true));     
    }

    Spec(testIsGuessValidForWords){
        vector<string> fruits = {"apple", "banan", "orang", "mango", "somet"};
        bool validOne = isGuessValid("apple", fruits);
        bool validTwo = isGuessValid("banan", fruits);
        bool validThree = isGuessValid("orang", fruits);
        bool validFour = isGuessValid("noe", fruits);
        bool validFive = isGuessValid("non", fruits);
        bool validSix = isGuessValid("nonono", fruits);

        Assert::That(validOne && validTwo && validThree, Equals(true));
        Assert::That(validFour && validFive && validSix, Equals(false));
    }

    Spec(testIsGuessCorrect){
        string word = "apple";
        string correctGuess = "apple";
        string wrongGuess = "shit";
        Assert::That(word == correctGuess, Equals(true));     
        Assert::That(word == wrongGuess, Equals(false));  
    }
};


int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}