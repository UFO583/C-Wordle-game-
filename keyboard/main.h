#ifndef MAIN_H
#define MAIN_H

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
string greenWords(const string& filename) {
        string line;
        vector<string> words;
        ifstream inFile(filename, ios::in);
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
string yellowWords(const string& filename) {
        string line;
        vector<string> words;
        ifstream inFile(filename, ios::in);
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
string grayWords(const string& filename) {
        string line;
        vector<string> words;
        ifstream inFile(filename, ios::in);
        if(inFile.is_open()) {
            while(getline(inFile,line)) {
                words.push_back(line);
            }
        inFile.close();
        }  
    string result = accumulate(words.begin(), words.end(), string(""));
    return result;  
};




#endif