#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>
#include <numeric>

// define the color
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define GRAY "\033[38;5;8m"


using namespace std;

// const string STATIC = "../wordle/static.txt";
const string TARGETGREEN = "../wordle/targetgreen.txt";
const string TARGETYELLOW = "../wordle/targetyellow.txt";
const string TARGETGRAY = "../wordle/targetgray.txt";

//这是一个 无限刷新的 function
string greenWords() {
        string line;
        vector<string> words;
        ifstream inFile(TARGETGREEN, ios::in);
        if(inFile.is_open()) {
            while(getline(inFile,line)) {
                words.push_back(line);
            }
        inFile.close();
        }  
    string result = accumulate(words.begin(), words.end(), string(""));
    return result;  
};


//这是一个 无限刷新的 function
string yellowWords() {
        string line;
        vector<string> words;
        ifstream inFile(TARGETYELLOW, ios::in);
        if(inFile.is_open()) {
            while(getline(inFile,line)) {
                words.push_back(line);
            }
        inFile.close();
        }  
    string result = accumulate(words.begin(), words.end(), string(""));
    return result;  
};

//这是一个 无限刷新的 function
string grayWords() {
        string line;
        vector<string> words;
        ifstream inFile(TARGETGRAY, ios::in);
        if(inFile.is_open()) {
            while(getline(inFile,line)) {
                words.push_back(line);
            }
        inFile.close();
        }  
    string result = accumulate(words.begin(), words.end(), string(""));
    return result;  
};



int main(int argc, char* argv[]) {
    const string alphabetTop = "qwertyuiop";
    const string alphabetMid = "asdfghjkl";
    const string alphabetBottom = "zxcvbnm";

    while (true) {

    // Clear the screen
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    string green = greenWords();
    string yellow = yellowWords();
    string gray = grayWords();

    cout << "please reload the keyboard until the initial keyboard have no color on it" << endl;
    cout << "(use ./app on terminal to reload, It might need to reload a couple time)" << endl;
    cout << "then u can enjoy the game my brother :D" << endl;
    cout << "\n";

    for (int i = 0; i < 10; i++) {
        bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetTop[i]) {
            cout << GREEN << " --- " << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetTop[i]) {
            cout << YELLOW << " --- " << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetTop[i]) {
            cout << GRAY << " --- " << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " --- ";
    }
    }
    cout << "\n";

    for (int i = 0; i < 10; i++) {
        bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetTop[i]) {
            cout << GREEN << "| " << alphabetTop[i] << " |" << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetTop[i]) {
            cout << YELLOW << "| " << alphabetTop[i] << " |" << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetTop[i]) {
            cout << GRAY << "| " << alphabetTop[i] << " |" << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "| " << alphabetTop[i] << " |";
    }
    }
    cout << "\n";

    for (int i = 0; i < 10; i++) {
    bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetTop[i]) {
            cout << GREEN << " --- " << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetTop[i]) {
            cout << YELLOW << " --- " << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetTop[i]) {
            cout << GRAY << " --- " << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " --- ";
    }
    }
    cout << "\n";

    cout << "  ";
    for (int i = 0; i < 9; i++) {
    bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetMid[i]) {
            cout << GREEN << " --- " << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetMid[i]) {
            cout << YELLOW << " --- " << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetMid[i]) {
            cout << GRAY << " --- " << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " --- ";
    }
    }
    cout << "\n";

    cout << "  ";
    for (int i = 0; i < 9; i++) {
        bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetMid[i]) {
            cout << GREEN << "| " << alphabetMid[i] << " |" << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetMid[i]) {
            cout << YELLOW << "| " << alphabetMid[i] << " |" << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetMid[i]) {
            cout << GRAY << "| " << alphabetMid[i] << " |" << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "| " << alphabetMid[i] << " |";
    }
    }
    cout << "\n";

    cout << "  ";
    for (int i = 0; i < 9; i++) {
    bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetMid[i]) {
            cout << GREEN << " --- " << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetMid[i]) {
            cout << YELLOW << " --- " << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetMid[i]) {
            cout << GRAY << " --- " << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " --- ";
    }
    }
    cout << "\n";

    cout << "        ";
    for (int i = 0; i < 7; i++) {
    bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetBottom[i]) {
            cout << GREEN << " --- " << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetBottom[i]) {
            cout << YELLOW << " --- " << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetBottom[i]) {
            cout << GRAY << " --- " << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " --- ";
    }
    }
    cout << "\n";

    cout << "        ";
    for (int i = 0; i < 7; i++) {
        bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetBottom[i]) {
            cout << GREEN << "| " << alphabetBottom[i] << " |" << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetBottom[i]) {
            cout << YELLOW << "| " << alphabetBottom[i] << " |" << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetBottom[i]) {
            cout << GRAY << "| " << alphabetBottom[i] << " |" << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "| " << alphabetBottom[i] << " |";
    }
    }
    cout << "\n";

    cout << "        ";
    for (int i = 0; i < 7; i++) {
    bool found = false;
    for (int j = 0; j < 30; j++) {
        if (green[j] == alphabetBottom[i]) {
            cout << GREEN << " --- " << RESET;
            found = true;
            break;
        } else if (yellow[j] == alphabetBottom[i]) {
            cout << YELLOW << " --- " << RESET;
            found = true;
            break;
        } else if (gray[j] == alphabetBottom[i]) {
            cout << GRAY << " --- " << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " --- ";
    }
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";

    cout << "if u dont want the keyboard just ^C to stop it" << endl;;
    
    this_thread::sleep_for(chrono::seconds(1));
}
return 0;
}   