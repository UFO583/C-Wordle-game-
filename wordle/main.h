#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

// define the color
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

using namespace std;

//define the files name
const int MAX_ATTEMPTS = 5;
const string WORDS_FILE = "words.txt";
const string ALLOWED_FILE = "allowed.txt";
const string STATIC = "static.txt";
const string TIMESPLAY = "timesPlay.txt";

const string TARGETGREEN = "targetgreen.txt";
const string TARGETYELLOW = "targetyellow.txt";
const string TARGETGRAY = "targetgray.txt";

const string SUMMARY = "summary.txt";

// Define the game statistics struct
struct Summary {
    int totalPlays;
    double averageAttempts;
    double winPercentage;
    int currentStreak;
    int longestStreak;
};

void saveSummary(const string& filename, const Summary& summary) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << summary.totalPlays << "\n";
        outFile << summary.averageAttempts << "\n";
        outFile << summary.winPercentage << "\n";
        outFile << summary.currentStreak << "\n";
        outFile << summary.longestStreak << "\n";
        outFile.close();
    } else {
        cout << "Error: Unable to write to file." << endl;
    }
}

Summary loadSummary(const string& filename) {
    Summary summary = {0, 0.0, 0.0, 0, 0};
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> summary.totalPlays;
        inFile >> summary.averageAttempts;
        inFile >> summary.winPercentage;
        inFile >> summary.currentStreak;
        inFile >> summary.longestStreak;
        inFile.close();
    } else {
        cout << "Error: Unable to read from file." << endl;
    }
    return summary;
}

void recordData (const string& filename, string& word, string s, int& attempt) {
    // 先打开 txt 文件 调成 append 模式
    ofstream appFile(filename, ios::app);
    //先把传过来的 word 变成大写
    for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }

    string str_num = to_string(attempt);
    // 把所有传入进来的string给 append到里面去
    if(appFile.is_open()) {
        appFile << word << s << " " << str_num << endl;
    };
    // 关闭
    appFile.close();
}

void recordWord(const string& filename, const string& target) {
    // 先打开 txt 文件 调成 append 模式
    ofstream appFile(filename, ios::app);
    // 把所有传入进来的string给 append到里面去
    if(appFile.is_open()) {
        appFile << target;
    };
    // 关闭
    appFile.close();
}

// Print the word when I cin the word
void printWordle(const string& word, const string& guess) {
    // 现在我想的是 每一个 --- 都要 用 for 循环来做 然后控制颜色 只要不加上 \n 就行了

    for (int i = 0; i < 5; i++) {
        if(guess[i] == word[i]) {
            cout << GREEN << " --- " << RESET;
        } else if(count(word.begin(), word.end(), guess[i]) > 0) {
            cout << YELLOW << " --- " << RESET;
        } else {
            cout << " --- ";
        }
    }
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        if(guess[i] == word[i]) {
            cout << GREEN << "| " << guess[i] << " |" << RESET;
            // 先打开 txt 文件 调成 append 模式
            ofstream appFile(TARGETGREEN, ios::app);
            // 把所有传入进来的string给 append到里面去
            if(appFile.is_open()) {
                appFile << guess[i];
            };
            // 关闭
            appFile.close();
        } else if(count(word.begin(), word.end(), guess[i]) > 0) {
            cout << YELLOW << "| " << guess[i] << " |" << RESET;
            // 先打开 txt 文件 调成 append 模式
            ofstream appFile(TARGETYELLOW, ios::app);
            // 把所有传入进来的string给 append到里面去
            if(appFile.is_open()) {
                appFile << guess[i];
            };
            // 关闭
        } else {
            cout << "| " << guess[i] << " |";
            // 先打开 txt 文件 调成 append 模式
            ofstream appFile(TARGETGRAY, ios::app);
            // 把所有传入进来的string给 append到里面去
            if(appFile.is_open()) {
                appFile << guess[i];
            };
            // 关闭
        }
    }
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        if(guess[i] == word[i]) {
            cout << GREEN << " --- " << RESET;
        } else if(count(word.begin(), word.end(), guess[i]) > 0) {
            cout << YELLOW << " --- " << RESET;
        } else {
            cout << " --- ";
        }
    }
    cout << "\n";
}

//To get a random word from the words.txt
vector<string> loadWords(const string& filename) {
    // Load the list of words from the file
    vector<string> words;

    //open the file and make a ifstream object
    ifstream inFile(filename);

    //create a string for each word we read then put it into the vector
    string line;
    if(inFile.is_open()) {
        while (getline(inFile, line)) {
            words.push_back(line);
        };
    };
    inFile.close();
    return words;
}

//To get the words that the player is allow to put in as guess
vector<string> loadAllowedWords(const string& filename) {
    // Load the list of allowed words from the file
    vector<string> allowedWords;
    ifstream inFile(filename);
    string line;
    if(inFile.is_open()) {
        while (getline(inFile, line)) {
            allowedWords.push_back(line);
        };
    };
    inFile.close();
    return allowedWords;
}

string getRandomWord(const vector<string>& words) {
    // Pick a random word from the list
    int index = rand() % words.size();
    return words[index];
}

bool isGuessValid(const string& guess, const vector<string>& allowedWords) {
    // Check if the guess is a valid 5 letter word
    if (guess.size() != 5) {
        return false;
    }
    if (find(allowedWords.begin(), allowedWords.end(), guess) == allowedWords.end()) {
        return false;
    }
    return true;
}

bool isGuessCorrect(const string& guess, const string& word) {
    // Check if the guess is correct
    if (guess == word) {
        return true;
    }
    return false;
}

void clearData(const string& filename) {
    // 打开 example.txt 文件并截断旧内容
    ofstream ofs(filename, ios::out);
    
    if (ofs.is_open()) {
        // 文件打开成功，清除所有内容
        ofs << "";
        ofs.close();
    }
}

void backtoMain() {
    // cin.ignore(); // Ignore the newline character from the previous input
    // cin.get(); // Wait for the user to press enter
    system("./app");
    // Clear the screen
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

vector<string> readStatic(const string& filename) {
        string line;
        vector<string> words;
        ifstream inFile(filename, ios::in);
        if(inFile.is_open()) {
            while(getline(inFile,line)) {
                words.push_back(line);
            }
        inFile.close();
        }  
    return words;  
};


void playWordle() {
    // Load the list of words and allowed words
    vector<string> words = loadWords(WORDS_FILE);
    vector<string> allowedWords = loadAllowedWords(ALLOWED_FILE);

    // Initialize random number generator
    srand(time(NULL));

    // Pick a random word for the game
    string word = getRandomWord(words);

    // Initialize game variables
    int attempts = 0;
    string guess;

    // Start the game loop
    while (attempts < MAX_ATTEMPTS) {
        // Prompt the user for a guess
        cout << "\nEnter guess: ";
        cin >> guess;

        // Validate the guess
        if (!isGuessValid(guess, allowedWords)) {
            cout << "Try again. Please enter a valid 5-letter word my brother.\n";
            continue;
        }

        // Increase the number of attempts
        attempts++;
        
        // Print the Wordle
        printWordle(word, guess);

        cout << word << endl;

        // Check if the guess is correct
        if (isGuessCorrect(guess, word)) {
            // clearData(STATIC);
            //这里部分是为了 summary 的下部分的
            recordData(STATIC, word, "YES", attempts);
            //这个部分是为了keyboard的
            clearData(TARGETGREEN);
            clearData(TARGETGRAY);
            clearData(TARGETYELLOW);
            //这一块也是为了 summary 上部分的
            Summary summary = loadSummary("summary.txt");
            summary.totalPlays++;
            summary.averageAttempts = ((summary.averageAttempts * (summary.totalPlays - 1)) + attempts) / summary.totalPlays;
            summary.currentStreak++;
            summary.winPercentage = static_cast<double>(summary.currentStreak) / summary.totalPlays * 100;
            if(summary.currentStreak > summary.longestStreak) {
                summary.longestStreak = summary.currentStreak;
            }
            saveSummary("summary.txt", summary);

            cout << "\nCongratulations! You guessed the Wordle in " << attempts << " attempts.\n";
            cout << "Press [Q] to continue";
            backtoMain();
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        // clearData(STATIC);
        recordData(STATIC, word, "NO", attempts);
        clearData(TARGETGREEN);
        clearData(TARGETGRAY);
        clearData(TARGETYELLOW);
        cout << "\nThe Word was: " << word << endl;
        cout << "Better luck next time!" << endl;
        cout << "Press [Enter] to continue";
        Summary summary = loadSummary("summary.txt");
        summary.totalPlays++;
        summary.averageAttempts = ((summary.averageAttempts * (summary.totalPlays - 1)) + attempts) / summary.totalPlays;
        summary.winPercentage = static_cast<double>(summary.currentStreak) / summary.totalPlays * 100;
        summary.currentStreak = 0;
        saveSummary("summary.txt", summary);
        backtoMain();
    }
}

//This is for the summary
void printStatistics() {
    Summary summary = loadSummary("summary.txt");
    cout << "==========================\n";
    cout << "    STATISTICS SUMMARY\n";
    cout << "==========================\n";
    cout << "Times Played:      " << summary.totalPlays << "\n";
    cout << "Average Attempts:  " << summary.averageAttempts << "\n";
    cout << "Win Percentage:    " << summary.winPercentage << "%\n";
    cout << "Current Streak:    " << summary.currentStreak << "\n";
    cout << "Longest Streak:    " << summary.longestStreak << "\n\n";

    cout << "\n";
    cout << "\n";

    cout << "--------------------------\n";
    cout << "WORD     ATTEMPTS      WIN\n";
    cout << "--------------------------\n";

    //这里就是读取历史记录的 目标单词然后放在 summary 那里
    vector<string> words = readStatic(STATIC);
    string word; 
    string bo;
    string attempts;
    for(auto ele : words) {
        word = ele.substr(0, 5);
        bo = ele.substr(5, 3);
        // Get the last word
        attempts = ele.back();
        cout << word << "           " << attempts << "      " << bo << "\n";
    }

    cout << "\n";
    cout << "\n";
    cout << "Press [enter] to continue";
    cin.ignore(); // Ignore the newline character from the previous input
    cin.get(); // Wait for the user to press enter

    // Clear the screen
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
};

void clearStatistics() {
    clearData(SUMMARY);
    clearData(STATIC);
}


#endif