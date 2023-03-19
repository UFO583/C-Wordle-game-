#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

// 在这里放置 howtoplay.h 文件的内容
#include <iostream>

using namespace std;

void printHowToPlay() {
    // Display How to Play
    cout << "=============================================\n";
    cout << "                 HOW TO PLAY\n";
    cout << "=============================================\n";
    cout << "Guess the Wordle in 6 tries.\n\n";

    cout << "HOW TO PLAY:\n";
    cout << "- Each guess must be a valid 5 letter word.\n";
    cout << "- The color of the tiles will change to show\n";
    cout << "  you how close your guess was to the word.\n\n";

    cout << GREEN << " ---\t" << RESET <<" ---\t ---\t ---\t ---\n";
    cout << "\033[32m| W |\t\033[0m| E |\t| A |\t| R |\t| Y |\n";
    cout << GREEN << " ---\t" << RESET <<" ---\t ---\t ---\t ---\n";

    cout << "W is in the word and in the correct spot.\n";
    cout << "\n";
    cout << " ---\t" << YELLOW << " ---\t" << RESET <<" ---\t ---\t ---\n";
    cout << "| P |\t" << YELLOW << "| I |\t" << RESET << "| L |\t| L |\t| S |\n";
    cout << " ---\t" << YELLOW << " ---\t" << RESET <<" ---\t ---\t ---\n";

    cout << "I is in the word but in the wrong spot.\n";
    cout << "\n";
    cout << " ---\t ---\t ---\t ---\t ---\n";
    cout << "| V |\t| A |\t| G |\t| U |\t| E |\n";
    cout << " ---\t ---\t ---\t ---\t ---\n";

    cout << "U is not in the word in any spot.\n";
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
}

#endif // HOWTOPLAY_H



// void recordSummary(const int attempts ) {
//     string line;
//     vector<string> words;
//     ifstream inFile(TIMESPLAY, ios::in);
//         if(inFile.is_open()) {
//             while(getline(inFile,line)) {
//                 words.push_back(line);
//             }
//         }
//     inFile.close();

//     // make everything number
//     vector<int> num_vec;
//     for (const auto& str : words) {
//         int num = stof(str);
//         num_vec.push_back(num);
//     }

//     // make every ele puls one or do whatever is should do
//     num_vec[0] = num_vec[0]++;
//     num_vec[1] = ((num_vec[1] * (num_vec[0] - 1)) + attempts) / num_vec[0];
//     num_vec[2] = (static_cast<double>(num_vec[0] - num_vec[3]) / num_vec[0]) * 100.0;
//     num_vec[3] = 0;

//     vector<string> str_vec;
    
//     for (const auto& num : num_vec) {
//         string str = to_string(num);
//         str_vec.push_back(str);
//     }

//     ofstream outFile(TIMESPLAY, ios::out);
//     if (outFile.is_open()) {
//         outFile << str_vec[0] << endl;
//         outFile << str_vec[1] << endl;
//         outFile << str_vec[2] << endl;
//         outFile << str_vec[3] << endl;
//     }
// }