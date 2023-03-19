#include <igloo/igloo.h>
#include "main.h"

using namespace igloo;

Context(TestDataCollect){
    Spec(testGreenWords){
        string words = greenWords("test.txt");
        Assert::That(words, Equals("abcdefg"));    
    };

    Spec(testYellowWords){
        string words = yellowWords("test.txt");
        Assert::That(words, Equals("abcdefg"));    
    };

    Spec(testGrayWords){
        string words = grayWords("test.txt");
        Assert::That(words, Equals("abcdefg"));    
    };
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
